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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC3710FAE6AD13843ULL + 0xFD59970766778AE3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC11A29D57E610F4BULL + 0x9B4E46B8FAC6756FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBAAB3E9F3A937F19ULL + 0xBC95766C88810F59ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8017BBEE2E16AB49ULL + 0x8A3DD1698F6962F2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xEDC277AAABFDD06BULL + 0xDAB90D1EC91DD70AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8659D6B9A73069BFULL + 0xA2F9A8BA5F57E4F8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9C81731822BD5F9BULL + 0xCA8F6E43C8A5848CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA40DBB6B76C40627ULL + 0xA2306EBED9343851ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9E629C4E968D9D27ULL + 0xFE6E9EFB73D2A62FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA800AA295A960549ULL + 0xDD44964B3EA2C6F5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xEFAF9BCAEBFD4809ULL + 0x9E02D0D81537F1F4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8C4A60BC9180160BULL + 0xD6B1FAE39D73DA34ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEAFAB12B410C68C3ULL + 0xFCC5D6988E029A2BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB57799E3D0E56401ULL + 0xB02DD5E742026DCBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xAD99EFAEF0A8CF2DULL + 0xA27A6C6A1843D26AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDA9229B7777E3073ULL + 0xACB0DB3DD9513ADDULL);
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
            aIngress = RotL64(mSource[((aIndex + 2524U)) & S_BLOCK1], 10U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 440U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 777U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1217U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 26U) + RotL64(aIngress, 39U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 50U)) + 6318740973868639425U) + aNonceWordK;
            aOrbiterH = ((aWandererG + RotL64(aCross, 57U)) + 5487840061430920881U) + aNonceWordA;
            aOrbiterA = (aWandererC + RotL64(aScatter, 29U)) + 10258706763248072672U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 3U)) + 18356875269730338208U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 12883160282903147010U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 19U)) + 1010140474942697730U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 41U)) + 17733939421700898293U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 6U)) + 13693055887924981201U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 14574732452793385269U) + aNonceWordE;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 13U)) + 10832873941223609012U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 37U)) + 8212600587135328040U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5312744319781971178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6173741211706546923U;
            aOrbiterA = RotL64((aOrbiterA * 12854414066390848249U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3693249147883790810U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 18365859989736602556U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3348463719324104997U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10645056678337549771U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1175668356822251045U;
            aOrbiterJ = RotL64((aOrbiterJ * 6579675292775345579U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13556844570541823717U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4790355739411849736U;
            aOrbiterH = RotL64((aOrbiterH * 4083544011788850307U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14905575502272644116U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17047244574558476634U;
            aOrbiterK = RotL64((aOrbiterK * 2356386971503880047U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10161614295718414869U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13413914082651612468U;
            aOrbiterE = RotL64((aOrbiterE * 16224039093981079491U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6072693130156927774U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4333656233793103787U;
            aOrbiterD = RotL64((aOrbiterD * 9374745547133955709U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17209776289202130250U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 11752001118070361543U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4416523594812872339U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15367365111105608277U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8650687767097460704U;
            aOrbiterF = RotL64((aOrbiterF * 11430451559660578667U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 18074648514448405693U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10857586858462237581U;
            aOrbiterB = RotL64((aOrbiterB * 3722891011080095849U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17219932344278345591U) + aNonceWordL;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6318740973868639425U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8846295038878812229U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 48U) + aOrbiterK) + RotL64(aOrbiterJ, 10U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 23U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 27U)) + aOrbiterF) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 30U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterI, 43U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 37U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 50U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 7330U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6546U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8070U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((aIndex + 7889U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 5U)) + 12380376990224645149U) + aNonceWordL;
            aOrbiterH = (aWandererD + RotL64(aIngress, 39U)) + 18296928500297384014U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 3550626816361145100U;
            aOrbiterK = (aWandererE + RotL64(aCross, 47U)) + 2667792936946706027U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 12U)) + 12020969779370926953U) + aNonceWordE;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 737340727886903447U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 21U)) + 1681797651799760502U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 3U)) + 2956186342689489064U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 43U)) + 1876852870402977177U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aIngress, 54U)) + RotL64(aCarry, 23U)) + 6433205819353555071U;
            aOrbiterC = (aWandererG + RotL64(aCross, 51U)) + 9065076854974222998U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3254410578766789992U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2005081975473815576U;
            aOrbiterI = RotL64((aOrbiterI * 9947701153722014085U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15992999234834560419U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3458344156815120948U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 1668460113964608051U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17069783053664877727U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 1260234710193913099U;
            aOrbiterB = RotL64((aOrbiterB * 4561226779897414381U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3825186451876061335U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2905344294992827535U;
            aOrbiterD = RotL64((aOrbiterD * 2469896090698580795U), 51U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 18141402347899180617U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8760129857609925066U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2507999156108123047U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 594052473780678210U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13216719212966128379U;
            aOrbiterG = RotL64((aOrbiterG * 10691355329696722303U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10029948739466316169U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 11912428807431992996U;
            aOrbiterC = RotL64((aOrbiterC * 85016510811938307U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8735634019801417287U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12785916159063273545U;
            aOrbiterF = RotL64((aOrbiterF * 1161917531260663357U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 367752057919802452U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3961036242431041564U;
            aOrbiterA = RotL64((aOrbiterA * 16352646009782597315U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3858415336170090719U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14325258358254321551U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12080431158781060059U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 16872184337970977180U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 12380376990224645149U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16559121155413059221U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 39U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterK, 42U)) + aNonceWordH);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterE, 29U)) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aCross, 52U) + RotL64(aOrbiterK, 5U)) + aOrbiterD) + aNonceWordF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 51U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 13U));
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 58U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterE, 21U)) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 44U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 13602U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 13036U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 15975U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13821U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 57U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 6U)) + 17668251151213543491U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 16101602509895104517U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 47U)) + 9083915270773304935U) + aNonceWordF;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 37U)) + 12810720730318214811U) + aNonceWordB;
            aOrbiterB = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 18113428002071925621U) + aOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 13U)) + 1582208899354109878U;
            aOrbiterG = (aWandererB + RotL64(aIngress, 22U)) + 4180688104819188154U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 35U)) + 8954598189262820611U) + aNonceWordC;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + 15360094153175355879U) + aNonceWordJ;
            aOrbiterK = (aWandererK + RotL64(aCross, 19U)) + 8383954114668216260U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 15626783326234049197U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10609978564404958066U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17656516608997517984U;
            aOrbiterI = RotL64((aOrbiterI * 4590620354119899777U), 29U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 760077259110786536U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3597338735888033063U;
            aOrbiterC = RotL64((aOrbiterC * 6548831472863517621U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4431777844935985157U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10710423172154671296U;
            aOrbiterF = RotL64((aOrbiterF * 16267496318491473315U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10240882795242085185U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7826053487019825891U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 15053729937684375907U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9418883403715727353U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11507423614799075545U;
            aOrbiterJ = RotL64((aOrbiterJ * 16189463984557044693U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11545217316421066655U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 617921402135485341U;
            aOrbiterA = RotL64((aOrbiterA * 8182920764965471653U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14456933220749921009U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7990243583564535387U;
            aOrbiterH = RotL64((aOrbiterH * 5994900368027985469U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14023633125757654751U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11319146808574958827U;
            aOrbiterK = RotL64((aOrbiterK * 13676159969338309307U), 23U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 14161653180846538446U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17993503892528842342U;
            aOrbiterE = RotL64((aOrbiterE * 12184170842617942651U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10449311783872638478U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17210495321003036773U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 17591257107603354151U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14586515403314763393U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 17668251151213543491U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9367185933291003363U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterD, 28U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 57U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 13U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 19U)) + aOrbiterJ) + aNonceWordE) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 46U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterF, 53U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 58U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 17252U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16924U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17392U)) & S_BLOCK1], 5U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 20134U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 19920U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 12029393034357490020U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 5U)) + 4526754731580694987U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 47U)) + 17060419646421271853U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 50U)) + 4128488893837059683U) + aNonceWordN;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 12706894827547160110U) + aNonceWordD;
            aOrbiterA = (aWandererA + RotL64(aCross, 57U)) + 12506324593645825056U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 35U)) + 12581344490649250025U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 23U)) + 14357032418199130132U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 15341977701796331249U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aIngress, 41U)) + 7086602307544733241U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 60U)) + 12398300065276832486U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2499745046076601988U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7249361592814001829U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 14597139848072319685U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3254456186337366437U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3472973415969046680U;
            aOrbiterC = RotL64((aOrbiterC * 14583566953969168353U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 7905718972111691591U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15941413652144021522U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 3473779492962783565U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 10583964125960308762U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13659925272340853715U;
            aOrbiterI = RotL64((aOrbiterI * 16708294803316630743U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9487054537489454887U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13287757570441887517U;
            aOrbiterG = RotL64((aOrbiterG * 17351439045329892107U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15279245465808571942U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12424999114621745879U;
            aOrbiterE = RotL64((aOrbiterE * 2274918760256527137U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13915392738892970475U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13797668053788805126U;
            aOrbiterF = RotL64((aOrbiterF * 13752161103680525317U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14344766585550401077U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 13727554194373146727U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 17164450431362670223U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1332966642432651232U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 938583742533681467U;
            aOrbiterH = RotL64((aOrbiterH * 13323340043936037549U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5659239372701978244U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8501778564909302938U;
            aOrbiterB = RotL64((aOrbiterB * 15629932660749672503U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1698500835332753591U) + aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12029393034357490020U;
            aOrbiterD = RotL64((aOrbiterD * 18176507271635640153U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 53U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterC, 19U)) + aNonceWordG);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 10U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 12U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 23U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordK);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF) + aNonceWordO);
            aWandererA = aWandererA + (((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordI) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 34U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 25305U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 26641U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(pSnow[((aIndex + 24841U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22032U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25483U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24410U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 52U)) ^ (RotL64(aCross, 21U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 19U)) + 380024772508948442U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 14U)) + 7649029098162567210U) + aNonceWordC;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 11U)) + 5329304598870421851U) + aNonceWordJ;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 5U)) + 12306118665045151326U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + 960751560457324256U) + aNonceWordF;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 3244070254386191876U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aScatter, 27U)) + 15733408571609521746U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 17623448932647018544U;
            aOrbiterK = (aWandererK + RotL64(aCross, 51U)) + 8787759896149035829U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 14741681792348288162U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 47U)) + 8801731213568307302U) + aNonceWordL;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9872248187499779222U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15407371518644528235U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 1245102406469471673U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 4242060317152943062U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9942784962409917541U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 888649755587764533U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7296348796484458631U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15061417216070157797U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10349554676953256231U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3233185810644297433U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9241229457641024287U;
            aOrbiterA = RotL64((aOrbiterA * 2728237515724597517U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8464051359381554575U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3307872165699029375U;
            aOrbiterD = RotL64((aOrbiterD * 4859663401033023433U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5482617843966711997U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4442149210462943872U;
            aOrbiterK = RotL64((aOrbiterK * 8979352218576515647U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10591636597580147381U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14925122230279312217U;
            aOrbiterI = RotL64((aOrbiterI * 15038171961638724013U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 9772367878232735350U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15800661165607190092U;
            aOrbiterH = RotL64((aOrbiterH * 10493976952980533589U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1571665862499272194U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3162847040693387901U;
            aOrbiterB = RotL64((aOrbiterB * 2747235335326991399U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 4868791925868749848U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13134549226315884613U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 3551955270718495869U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7830447320021657240U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 380024772508948442U;
            aOrbiterF = RotL64((aOrbiterF * 5143324968958616357U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 38U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + aNonceWordN);
            aWandererD = aWandererD + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 60U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 48U) + aOrbiterB) + RotL64(aOrbiterF, 13U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterH, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterC, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterK, 20U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 27970U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((aIndex + 30654U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 32427U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31200U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29070U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 30731U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 38U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 12136097566601676613U) + aOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 58U)) + 7969431322248040056U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 10530676021510553889U) + aNonceWordF;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 35U)) + 8740777303075445264U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 37U)) + 13249434169895564739U;
            aOrbiterK = (aWandererC + RotL64(aCross, 41U)) + 15529577005925628472U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 23U)) + 344627093687331562U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 47U)) + 8824277416519988893U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 43U)) + 5636276438449709875U) + aNonceWordG;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 21U)) + 2079413361031851552U) + aNonceWordM;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 56U)) + RotL64(aCarry, 3U)) + 7807998179168655561U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13589392896232029112U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 10733011474804473996U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 361749145931578805U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15934162328347805968U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7573511217796245232U;
            aOrbiterB = RotL64((aOrbiterB * 10694563909931636155U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4828475187337891975U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13284974329890393113U;
            aOrbiterI = RotL64((aOrbiterI * 10831075817642374287U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13173869918669643112U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15841507674783398167U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15632933198136963277U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14168272451055700516U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 11134471485501999898U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 8019507184494591705U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2611858916687822610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17863271539727513641U;
            aOrbiterH = RotL64((aOrbiterH * 4987884722174985677U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8874401993454249066U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 5131480593493950665U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8585874663602346121U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9366563022381918996U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7890729519928340296U;
            aOrbiterA = RotL64((aOrbiterA * 11428572374057899517U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 131774386529223292U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4108356674478240148U;
            aOrbiterF = RotL64((aOrbiterF * 2492753294539081613U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7651738365157869789U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2745458108574051004U;
            aOrbiterK = RotL64((aOrbiterK * 2175955806036373729U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10492013124307434604U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12136097566601676613U;
            aOrbiterD = RotL64((aOrbiterD * 13128652803485742119U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 10U) + aOrbiterB) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 27U)) + aOrbiterC) + aNonceWordA);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 11U)) + aNonceWordP);
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + RotL64(aOrbiterF, 30U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 35U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 56U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xC318F307AB2BD23BULL + 0xDA2AC019BE5794D2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA2BE8EBE69A69CE7ULL + 0xB0970389EBE81C98ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB8F46FCF618BAC35ULL + 0xDD58E395CA008BF9ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC9B04AE3AAAAE67DULL + 0xFB7ABB50F8FFBD42ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9098F95254C47239ULL + 0xDC665B4E3EC8059BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x85FE58E557981617ULL + 0x9FA7C60115FCC072ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD2D8DE4506555DB9ULL + 0xE4626225A56911A3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE8A6BC93B6EC1F9FULL + 0x843F57C3E69D512AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC378A8914559E2C7ULL + 0xAD99DCEA3BC2F015ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9B5D6FF9D711FD75ULL + 0x812DF17F42EF40A6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x82BF4F284A5E47D7ULL + 0xB4EE8D4FD9073CC8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBABDC39953B20633ULL + 0x82AA3672485AF347ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xC1490FB1C9D3E1A7ULL + 0xBE63C0540D315EDDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEBE9A89E9DB950D7ULL + 0xADD934D194555697ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x82004D19F05F1D55ULL + 0xCC70DF031DE396C5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE582E8B0FD98CD2FULL + 0xF479CC0509301AE5ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 1619U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneB[((aIndex + 4572U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6378U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 1523U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 18U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 27U)) + 2617613537256538553U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 47U)) + 16642868916835132715U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 10860291124337073254U;
            aOrbiterJ = ((((aWandererI + RotL64(aPrevious, 20U)) + RotL64(aCarry, 3U)) + 6432511273906902472U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererK + RotL64(aCross, 51U)) + 7505375005848241910U) + aNonceWordF;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 11086616004678821329U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 37U)) + 3298830587569881951U) + aNonceWordC;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 56U)) + 9775143140064220979U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 13U)) + 4147601326580823120U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12245920269898100415U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8391940489176734499U;
            aOrbiterD = RotL64((aOrbiterD * 9119606167674098007U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17876893379544668477U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 18301882058180370541U;
            aOrbiterC = RotL64((aOrbiterC * 16680384667098921309U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6869225862715140102U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15404118372589259800U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5766851935950389915U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17757381020518233814U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17677969146092374455U;
            aOrbiterB = RotL64((aOrbiterB * 3469432916562405063U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15783378556632870114U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5792858258663697864U;
            aOrbiterG = RotL64((aOrbiterG * 12008981883482080427U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11737803388202260296U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16001927091970715330U;
            aOrbiterF = RotL64((aOrbiterF * 3062030309852922061U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1749586939123286632U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 6169421068855905938U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 12374789910763348695U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterD) + 10073586820719728062U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17744171227198661555U;
            aOrbiterK = RotL64((aOrbiterK * 10658375268803957647U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1149819647337612792U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7725598665625892006U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 15097586655234391559U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 20U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterA, 30U));
            aWandererD = aWandererD + ((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + RotL64(aCarry, 53U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 20U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8600U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 9250U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16289U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14837U)) & S_BLOCK1], 20U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11955U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 15920462086654025436U) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 5U)) + 487844076858004017U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 14502883786442630566U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 3787107318658233674U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 60U)) + 12548777544693755491U;
            aOrbiterB = (aWandererE + RotL64(aCross, 53U)) + 4907309444075181683U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 23U)) + 18342396700266492072U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 29U)) + 13503051997624242670U) + aNonceWordN;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 18U)) + 17845742460521374571U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8640887211877858169U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5273913123709097537U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 1661149444148461791U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 17756844173695563883U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6713055830729302951U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2832836748513174311U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5106468334224035972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10228769728713526172U;
            aOrbiterA = RotL64((aOrbiterA * 9760310686414358435U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 7687649520668883142U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7757480627354711605U;
            aOrbiterK = RotL64((aOrbiterK * 7222553727737349209U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 10876291698508634557U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8149278085586014186U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8577133863470695381U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15592893988925610485U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 8639028256640537165U;
            aOrbiterC = RotL64((aOrbiterC * 1880655276432963955U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 475660347892196219U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1903736092401853832U;
            aOrbiterJ = RotL64((aOrbiterJ * 8486318978769094799U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 12463250192809450953U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7253918448601703982U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 3821034106528009129U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5171661020093804486U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11627344933828324146U;
            aOrbiterE = RotL64((aOrbiterE * 5388047063152043277U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterJ, 6U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + RotL64(aCarry, 21U)) + aNonceWordL) + aWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterF, 56U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22844U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 19198U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 23607U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17815U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17053U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 23356U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 47U) + RotL64(aCross, 4U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((aWandererF + RotL64(aCross, 18U)) + 6521330037475130256U) + aNonceWordE;
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 12611880456055428940U) + aNonceWordP;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 12061611078130934708U) + aNonceWordI;
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 1558112410801116984U) + aNonceWordJ;
            aOrbiterA = (aWandererA + RotL64(aScatter, 41U)) + 10509115227850160786U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 22U)) + 4045915960688792066U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 29U)) + 1196541286513243082U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aIngress, 5U)) + 15564991032722373702U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 35U)) + 4897765238703641798U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12327429514907752733U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6189189797708711636U;
            aOrbiterG = RotL64((aOrbiterG * 9017615866338877651U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6374267075282018852U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1888758503831341439U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 74387714918264257U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14956857689299491800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14879361107223331957U;
            aOrbiterJ = RotL64((aOrbiterJ * 9166712966729591953U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16086885494838105042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8069724185844303923U;
            aOrbiterB = RotL64((aOrbiterB * 8878470736758734353U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10854345917959911439U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7078313614360332089U;
            aOrbiterK = RotL64((aOrbiterK * 9864025732292844871U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15083669236062255011U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 594879695916679116U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9852515479152735283U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6721466068234534523U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 475816724162626782U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4799725182757588407U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4341655358154605899U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 15477254302340298586U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13961520225881974201U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10179091913200895775U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6310490897546909571U;
            aOrbiterD = RotL64((aOrbiterD * 15080621088825477613U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 24U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 4U)) + aOrbiterG) + aNonceWordG);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterG, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 23U)) + aOrbiterK);
            aWandererG = aWandererG + ((((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 12U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 24613U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 26596U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27836U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32423U)) & S_BLOCK1], 58U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26020U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29198U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 34U)) + (RotL64(aCarry, 21U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 5088525177670191619U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 37U)) + 9966456257813932112U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 18U)) + 7707646574027146307U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 43U)) + 75480203757681173U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 27U)) + 384659134071835163U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 3158769775373307778U) + aNonceWordH;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 17360830943513941272U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 12U)) + 5317278822721604586U) + aNonceWordN;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 5U)) + 1371427105215954781U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3162710551223553423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5332921933853550756U;
            aOrbiterE = RotL64((aOrbiterE * 11709546145149357887U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10572462410297815854U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10234389605554817892U;
            aOrbiterD = RotL64((aOrbiterD * 2130374833440291193U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 13421365517991380605U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10186643614984034083U;
            aOrbiterG = RotL64((aOrbiterG * 8554471709467808453U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4742438973260817120U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 6081590345899008846U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 7069396301823124931U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15360092808493795340U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 12186413069553132646U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 3815981440611914267U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16756221656224451552U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12232880965861373143U;
            aOrbiterK = RotL64((aOrbiterK * 14196910735715726471U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10090954323470840557U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 15615770271463853537U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13544181592829027283U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 556029032505658411U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13311879111583579039U;
            aOrbiterH = RotL64((aOrbiterH * 3924744868168749003U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8646360871497847336U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 2064833941982069154U;
            aOrbiterB = RotL64((aOrbiterB * 10016546852137913163U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterF, 48U)) + aOrbiterH) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 57U)) + aOrbiterK) + aNonceWordO);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 27U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterB, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterE, 44U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCCC3B68AED0E336FULL + 0x9A54FBDB7EB2B3ECULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xEFA874A30FE6B185ULL + 0xA2B18FF6733112CDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xDE91AF5B6ACC8F15ULL + 0xFC328DA94977B72BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEDC465EC30CF92A9ULL + 0xC4D35D3EF16DB8BCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x95B8F16FBAECCEFBULL + 0xEB31D203B0BFD977ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD02331F15E7D6535ULL + 0x9986ECBA61D43405ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE1A6D67D561AF3DBULL + 0xC75D2D7B40BB110AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x982CDF357FC116EDULL + 0xF55C0749B857BAFCULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8E82EB1C099697ADULL + 0x8673AC6557C339E3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFFBD4B7A1CAC7501ULL + 0xD04BD643A075DD6AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB9FE545A6B7BBB1BULL + 0x9D632BF682A68646ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAFA0B548E84C02DDULL + 0x89B819B0F51E5BC3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB31F8C305E5490DBULL + 0x84FF992FD32F2986ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEE5975584E061F19ULL + 0x86CE6C4D79A4BBF1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBD0445B8DE2CE919ULL + 0xC9A4408631CD946FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCC03F48F17FF5F47ULL + 0x9515370E3BF99B9DULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3989U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 213U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2493U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4063U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7344U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 24U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (aWandererI + RotL64(aScatter, 27U)) + 380024772508948442U;
            aOrbiterC = ((((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 43U)) + 7649029098162567210U) + aOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 44U)) + 5329304598870421851U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 12306118665045151326U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 960751560457324256U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 3244070254386191876U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15733408571609521746U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11280008313548121407U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17623448932647018544U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8787759896149035829U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 7092515868845497573U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14741681792348288162U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8801731213568307302U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12127126999570616489U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9872248187499779222U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 15407371518644528235U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 1245102406469471673U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4242060317152943062U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9942784962409917541U;
            aOrbiterG = RotL64((aOrbiterG * 888649755587764533U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + aNonceWordD);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 50U) + RotL64(aOrbiterD, 30U)) + aOrbiterG) + RotL64(aCarry, 53U)) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9622U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 8668U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12527U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10197U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8992U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9053U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererG + RotL64(aCross, 37U)) + 13880995121909552664U) + aNonceWordP;
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 14534942818069300546U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 47U)) + 17745973100886007133U;
            aOrbiterC = ((((aWandererB + RotL64(aIngress, 20U)) + RotL64(aCarry, 23U)) + 2249805580771946872U) + aOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 4460116116396439410U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 3378683994078106878U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 3992996501048809123U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 13273544260537223797U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12057768808864451929U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4115362079047921130U;
            aOrbiterF = RotL64((aOrbiterF * 12263015903331031345U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15297384955502206698U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 17623548383481905636U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 7487278217901483685U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 3559213898000162417U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12311605719074507335U;
            aOrbiterC = RotL64((aOrbiterC * 3982199462062847697U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14807313864347885885U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11222085523291581822U;
            aOrbiterJ = RotL64((aOrbiterJ * 12580941911587215653U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 51U)) + aOrbiterG) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterG, 4U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 40U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 16904U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((aIndex + 16425U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 18147U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19455U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24503U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16897U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 11U)) + 1364174714924216027U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 57U)) + 13561796874229506613U) + aNonceWordC;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 47U)) + 11845572344206238305U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 21U)) + 15762708240326773763U) + aOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 23U)) + 1157119665207900473U) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6823546624372055260U) + aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14465564210523945121U;
            aOrbiterC = RotL64((aOrbiterC * 10957323253786161255U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 10667464548080807531U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13445737493224316575U;
            aOrbiterG = RotL64((aOrbiterG * 12137295000900795711U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3009837893785957665U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 2886920524111083752U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 15308180928967762543U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10886177449328249656U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15067759884678100433U;
            aOrbiterK = RotL64((aOrbiterK * 5724566815989860041U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 18307930462682331536U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8791864377579255801U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9265158882471421767U), 47U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 36U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterG, 14U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 44U) + aOrbiterK) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30130U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 29700U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 26982U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31998U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26040U)) & S_BLOCK1], 54U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26905U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28895U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 52U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 29U)) + 5721224134332887360U) + aNonceWordG;
            aOrbiterA = ((((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 5U)) + 6892749729775049095U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 3884839462099556836U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 4365431706830216193U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 51U)) + 15501528746571578773U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 4505911326320650606U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1865129050927879580U;
            aOrbiterI = RotL64((aOrbiterI * 9198152644404068721U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 2011737665969640369U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 611672935827062688U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 12873671551304596619U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 663547038310431047U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 5468932264754299556U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 11968657455484578525U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17920294117231191705U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 486058453837528110U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 8851102552244026737U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2789178451938129313U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 420772587981211184U;
            aOrbiterA = RotL64((aOrbiterA * 17402987842294006667U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 48U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aNonceWordN);
            aWandererH = aWandererH + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 50U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBD8DDA32B288FC0BULL + 0xEBB367088FA0AF94ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x953AD6B6722E7713ULL + 0xCA4FE8868311E4D6ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF7072074E249B977ULL + 0x82CE194CFF638435ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x89F2505655134339ULL + 0xD0B9DC1213098C4DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x987D7CFB9F3F77B1ULL + 0xFAF6B749095C9D5DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEE7CAB9DE37E3933ULL + 0xD807EF4B67190F62ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC09A91EDDA4381ADULL + 0xE34EB3F43669B5C9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x97462CA59892888FULL + 0x96132CAEBBF5A93AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC80D2A5D28A06399ULL + 0xD36CEA411924E2BAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF245DDAF18F2C993ULL + 0xAF0DD2EB807FC187ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE40A416E66E610BDULL + 0xC02C25463465E786ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9D3BC70B37031A57ULL + 0xEED330E7A2D1F899ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBF3059900216671DULL + 0x9351F4A9150250EAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8A0235FA777963B9ULL + 0xDD007C0831D9B866ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCA96F863F5B82CBBULL + 0x8797E3D88A4E6E49ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEEC9E275720EE789ULL + 0xA6333BD93B5E60FAULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aOperationLaneD, aWorkLaneA, aOperationLaneA, aFireLaneD, aWorkLaneB, aFireLaneB, aOperationLaneC, aWorkLaneC, aFireLaneA, aFireLaneC
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5272U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 6929U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2955U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2626U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6040U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 2251U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = ((aWandererK + RotL64(aIngress, 35U)) + 12027839670755583592U) + aNonceWordL;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 29U)) + 15380130703509859843U) + aNonceWordF;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 4590907433867798074U) + aOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 1754574023602519724U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 53U)) + 9832756659564903767U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 5035088494491470403U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 4U)) + 14199170923323644638U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8325619421264440438U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 969534320779067977U;
            aOrbiterJ = RotL64((aOrbiterJ * 17767548306355264705U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 270575869402913847U) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13344806516599578910U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10193544126281901579U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15143147951139409101U) + aNonceWordC;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14425582489214169238U;
            aOrbiterB = RotL64((aOrbiterB * 16893787086337916355U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13951127523239064584U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 14177925225918293579U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 13079514031864998485U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8258920744278218901U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7408161179397242453U;
            aOrbiterA = RotL64((aOrbiterA * 975737128100519169U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8581481606764773468U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10078416198417433133U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1102721083915858247U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 18299772198826189580U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 18304668908084397946U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10589455451200578687U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterG, 29U)) + aNonceWordG);
            aWandererH = aWandererH + (((RotL64(aCross, 12U) + aOrbiterG) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 42U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12803U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 15766U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13435U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13025U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9099U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 14228U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 18U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 11700815697312060726U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 11808423452327465441U) + aNonceWordK;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 8670503858631730886U) + aNonceWordP;
            aOrbiterE = (aWandererD + RotL64(aIngress, 41U)) + 2400061067991988544U;
            aOrbiterA = (aWandererC + RotL64(aCross, 23U)) + 16163118178366229686U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 51U)) + 3280178595904941068U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aWandererE + RotL64(aScatter, 4U)) + 3298683600817047727U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16321624053445183574U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6730229877611375225U;
            aOrbiterG = RotL64((aOrbiterG * 2022290495153519279U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10162830636713641322U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15646771327759599256U;
            aOrbiterH = RotL64((aOrbiterH * 15333053762177144775U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 14841751262270544102U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9545541117228834895U;
            aOrbiterD = RotL64((aOrbiterD * 11529769874752969377U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14676615635857599982U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1231768638470558855U;
            aOrbiterE = RotL64((aOrbiterE * 2716808508509014677U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1945905595345404833U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1406171421638586846U;
            aOrbiterA = RotL64((aOrbiterA * 4577864352425476233U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 1970292335806697198U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12309719390375013297U;
            aOrbiterC = RotL64((aOrbiterC * 16540660957923687327U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5352135521358954576U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15465675376193501658U;
            aOrbiterJ = RotL64((aOrbiterJ * 16385761112921041387U), 53U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 12U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 29U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 50U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterG) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererD = aWandererD + (((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 37U)) + aOrbiterE) + RotL64(aCarry, 29U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 50U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 20U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24556U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 22551U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23290U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21465U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17867U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23182U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 22U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererG + RotL64(aCross, 27U)) + 12775735908960052604U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 11791373812080296887U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 21U)) + 5537362877706057303U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 57U)) + 2023912048504189380U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 51U)) + 17668828109963766893U) + aNonceWordB;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 558908629933941224U) + aNonceWordI;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 38U)) + RotL64(aCarry, 53U)) + 1479633119685446888U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 15460320397843364063U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 10059749397555469054U;
            aOrbiterE = RotL64((aOrbiterE * 8671817118586065469U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9987633811929693924U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10087337844580228269U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13817142288940843815U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 4446204415503364254U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15106063243302192717U;
            aOrbiterK = RotL64((aOrbiterK * 13273756657334709803U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9430197906134676162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1226048679997253363U;
            aOrbiterI = RotL64((aOrbiterI * 14247538885252664127U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10611580584157624739U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3137391249289641509U;
            aOrbiterC = RotL64((aOrbiterC * 5462682413239873181U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9327201928815412810U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7890659377013147073U;
            aOrbiterG = RotL64((aOrbiterG * 13827717178378062047U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 10675114832750356941U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8804440385852327267U;
            aOrbiterF = RotL64((aOrbiterF * 8520671775587260601U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 57U)) + aOrbiterG) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterA) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterC, 34U));
            aWandererK = aWandererK + (((((RotL64(aCross, 28U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aNonceWordK) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterE, 43U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 28U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneC
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26878U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 29762U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31559U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32584U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27047U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 27034U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 43U)) + 5568146815535263910U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 7736084960873834666U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 57U)) + 1336413621817562093U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 36U)) + RotL64(aCarry, 21U)) + 5218462026934984692U) + aNonceWordD;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 21U)) + 7048890985969555935U) + aNonceWordI;
            aOrbiterD = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 13415955213864702118U) + aNonceWordG;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 13U)) + 5657023257021528548U) + aOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14338310943137497116U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 12305161641833950473U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11949964304435964395U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14514226578370459131U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12692904083266024340U;
            aOrbiterK = RotL64((aOrbiterK * 14800805065279908839U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11012959130001327964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7106471380403489078U;
            aOrbiterG = RotL64((aOrbiterG * 515626559384817223U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3718101961355280891U) + aNonceWordC;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 13364192077222322664U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 1411328915372590283U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6720867800318913440U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14497243926965866546U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 13595058589060114653U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5789056168233262435U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14438482587495779937U;
            aOrbiterF = RotL64((aOrbiterF * 10593535547917767263U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 313917798940179945U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 15241845511889502917U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 16483477103771326107U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + RotL64(aOrbiterA, 10U)) + aOrbiterG) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aNonceWordO);
            aWandererC = aWandererC + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDF485FEDE4E4B82DULL + 0xD628BE1CB78F68AAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB5C8D1D28A430E61ULL + 0xC0AF7AD9145B6D4FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9F26A9F7E73D0817ULL + 0xAA1DE691BDCBE230ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9187CFB17ED9FF37ULL + 0x98437FB843E39B34ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE4433BDC194BFAD7ULL + 0xA96F14BB2448F3FCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB6BCD31815E14205ULL + 0xB8359D61075EAF1EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF5F473E74FE2E7B7ULL + 0x844A6E9FDA362791ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB08A1DB0ACBB4869ULL + 0xA2D7729D256D6B51ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA19E22C726E4FB5FULL + 0xD4D6D8B2C3BA0EB8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB8ED2BC76A1AE4D5ULL + 0xB16FD4EDE14BB840ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xBAC1A30C51B533BDULL + 0xF7DD7DA463793460ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA16A6369ABB5772DULL + 0x8D1C8DC0FA39EC3EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEB739B1E8061A20BULL + 0xD8E50D51C2BFDF69ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD7DAF63D59B98805ULL + 0xBEB4EAE0CAF30B8BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x84A19C4840E5FAE3ULL + 0x9EF0F91CD8B5C6D2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEA6367C593207155ULL + 0x933DAFE09AA40476ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneA, aExpandLaneA, aOperationLaneD, aFireLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneB, aExpandLaneC, aFireLaneD, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2277U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 921U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4911U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8155U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4592U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 492U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 40U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererK + RotL64(aIngress, 19U)) + 9041099828460168106U) + aNonceWordD;
            aOrbiterG = ((((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 12883711604096848454U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 17420968786226443079U) + aOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aScatter, 3U)) + 3448213891716125104U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 51U)) + 11866455977445336560U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 28U)) + 4119356835384495905U) + aNonceWordN;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 2186212599698637068U) + aNonceWordM;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6506144898969301620U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12556800923644051626U;
            aOrbiterA = RotL64((aOrbiterA * 15961043406612913121U), 41U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 4075551535185182945U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17877694808492008749U;
            aOrbiterJ = RotL64((aOrbiterJ * 901315308379887473U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5553428900598223316U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14362304852277160675U;
            aOrbiterG = RotL64((aOrbiterG * 11415103199856419303U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9174200302876075831U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16110739511917638547U;
            aOrbiterB = RotL64((aOrbiterB * 7004356839428657949U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 10189881974519849402U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 2128076632642616677U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 8860453653433114929U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 18133523799074400083U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9916472958834153766U;
            aOrbiterF = RotL64((aOrbiterF * 3454601168808001733U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10274457562795569227U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14134814273275356425U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15912501063665343159U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterF) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 27U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterG, 44U)) + aOrbiterB) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13674U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((aIndex + 8776U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 16350U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12870U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12898U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 8929U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 26U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererD + RotL64(aScatter, 35U)) + 8506388683755208267U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 5U)) + 2179323259055019735U) + aNonceWordG;
            aOrbiterA = ((aWandererI + RotL64(aCross, 20U)) + 3345902531140983016U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aIngress, 13U)) + 17456139311481306584U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 14587864088462311164U) + aNonceWordF;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 13178947246650647057U;
            aOrbiterE = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 12866578138946916962U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 13098524333655118173U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 15451329483787541982U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13580376920467431451U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9494299579678389385U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15581954810375490643U;
            aOrbiterF = RotL64((aOrbiterF * 13670002280188424825U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4487042505730624892U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2774455928791636186U;
            aOrbiterK = RotL64((aOrbiterK * 15847933919136777451U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12435319582397755819U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10077180055177766823U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3924363471701748703U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10391963896910956455U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 6149237416725301794U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 10115917698918612823U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15673402771629639978U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14729117178956592426U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 9070464269215820531U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 14492001279368870240U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6278248084483259952U;
            aOrbiterJ = RotL64((aOrbiterJ * 16731228350971263873U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterF, 20U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterB, 53U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 51U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24576U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((aIndex + 20918U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17397U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22313U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18400U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16807U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 4U)) ^ (RotL64(aIngress, 21U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 13U)) + 11039986441331892533U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 6256024955965426119U) + aNonceWordG;
            aOrbiterE = (aWandererB + RotL64(aCross, 19U)) + 9857443189988995666U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 13U)) + 11900944813380998208U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 43U)) + 8422577734978875541U) + aNonceWordF;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 3100835100713928724U) + aNonceWordI;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 35U)) + 11871553509810206993U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17614749493763417027U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3638372131856199916U;
            aOrbiterE = RotL64((aOrbiterE * 480683274898147025U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6582275259281025770U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17016882418498941958U;
            aOrbiterI = RotL64((aOrbiterI * 4269869255230867823U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1747214688658984715U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9356088987044015278U;
            aOrbiterF = RotL64((aOrbiterF * 16221733545319753695U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 4056238112133473456U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16013150119949532998U;
            aOrbiterK = RotL64((aOrbiterK * 12913648646318115315U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 16076621211111834889U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9940824359571581765U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11624767861336495331U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15624084004784515753U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7630989544834680335U;
            aOrbiterB = RotL64((aOrbiterB * 12261063237156822067U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18003586430673313786U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1654118743290334161U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 1153250137357176071U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29993U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 32015U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 26813U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32015U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25233U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 30671U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 35U)) + 5088525177670191619U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 9966456257813932112U;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 27U)) + 7707646574027146307U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 47U)) + 75480203757681173U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 384659134071835163U) + aNonceWordJ;
            aOrbiterH = ((((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 29U)) + 3158769775373307778U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererB + RotL64(aScatter, 13U)) + 17360830943513941272U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5317278822721604586U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1371427105215954781U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 10956603063464438611U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 3162710551223553423U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5332921933853550756U;
            aOrbiterI = RotL64((aOrbiterI * 11709546145149357887U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10572462410297815854U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 10234389605554817892U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2130374833440291193U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13421365517991380605U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10186643614984034083U;
            aOrbiterG = RotL64((aOrbiterG * 8554471709467808453U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4742438973260817120U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 6081590345899008846U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7069396301823124931U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15360092808493795340U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12186413069553132646U;
            aOrbiterH = RotL64((aOrbiterH * 3815981440611914267U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16756221656224451552U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12232880965861373143U;
            aOrbiterC = RotL64((aOrbiterC * 14196910735715726471U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 23U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 4U)) + aOrbiterJ) + aNonceWordM);
            aWandererB = aWandererB + ((((RotL64(aCross, 56U) + RotL64(aOrbiterG, 29U)) + aOrbiterH) + aNonceWordC) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 51U)) + aOrbiterG) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA69B4055B6F48F3FULL + 0x84E3CEE3B813DC10ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD88C149D44F111C9ULL + 0xCFDC9611D310E217ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDE72C6F0446F25ADULL + 0xA2A08EDCC7E0FBE0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDB8884CB957DB685ULL + 0xC9BEE47971CD7C5DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9A17DA63F92198F5ULL + 0x8F7F56CFC8A94AF5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFB3D418FDA92CFADULL + 0xA0086492549A0312ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCE8F94FAAFB30BC9ULL + 0x8A13F672FADCB5CEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA8494A60B7F0E409ULL + 0xA6DFB3ECB6B8ECD3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xBC53B250A8894E61ULL + 0x9BBE410C0EFFCFEDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC55375E082267135ULL + 0x9CACB803753AF1CEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEA97ADDD07342125ULL + 0xC6BC1C6E2DFC549CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCF5CD217BA409AD1ULL + 0x836A5A318D4AA6CEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA9267C734BEF507BULL + 0xDAD8E6E50212499DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBDC6FCA6A289ABEBULL + 0xD5AA3870A188CD20ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD4B03D318EF48881ULL + 0xF8E09D8E94FD79ABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x844AA359C42A443FULL + 0x99A8B2331F786EC1ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aWorkLaneA, aOperationLaneA, aFireLaneC, aWorkLaneC, aOperationLaneB, aFireLaneB, aFireLaneD, aOperationLaneC, aWorkLaneB, aWorkLaneD
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3610U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 5715U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 817U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2567U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3524U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6573U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 10U) + RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 6U)) + 6243113109470883144U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 43U)) + 3891552123999605832U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 35U)) + 8758797898587019128U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 19U)) + 1005891374086408851U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 39U)) + 3713426782180050764U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 57U)) + 18358143862391573534U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 17504394029693712404U) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aCross, 37U)) + 5312729289027417014U) + aNonceWordJ;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 26U)) + RotL64(aCarry, 41U)) + 2560873623431186029U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aCross, 47U)) + 16309322822806704211U) + aNonceWordF;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 21U)) + 10195513918020652600U) + aNonceWordH;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2552116263258744287U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7732784879810980089U;
            aOrbiterG = RotL64((aOrbiterG * 15041929399477790999U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16499127570665381507U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10890036715535519036U;
            aOrbiterH = RotL64((aOrbiterH * 9065115450010475187U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16288944603478791554U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14542766121469312846U;
            aOrbiterB = RotL64((aOrbiterB * 8435383464425875209U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5973595239494084696U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 1820492719977197097U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 16164917159141304405U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 10489529555776381736U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6392552206958240484U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 11761477994533503307U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10163241948999404556U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16054678853554707148U;
            aOrbiterK = RotL64((aOrbiterK * 10570418210789350091U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3606021702108590330U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 16920568417324295852U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 5222656554577625385U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13889995689147406315U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7908387312354285092U;
            aOrbiterD = RotL64((aOrbiterD * 7995682580514280949U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14161911472715334589U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12386100977925313406U;
            aOrbiterE = RotL64((aOrbiterE * 17136336570895231639U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14408470657696841139U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7466281699619513012U;
            aOrbiterI = RotL64((aOrbiterI * 2706710684289882025U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11125044052260579351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6243113109470883144U;
            aOrbiterC = RotL64((aOrbiterC * 17390954549755941181U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 24U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterC) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + aNonceWordN);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterI, 5U));
            aWandererI = aWandererI + ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 44U)) + aOrbiterD) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aCross, 56U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aNonceWordI);
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterD, 42U)) + aNonceWordA) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11790U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 12929U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8762U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14713U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11806U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14316U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 56U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (aWandererE + RotL64(aScatter, 3U)) + 13854738573712660276U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 21U)) + 16835460633412286294U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 19U)) + 6785859293758091931U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 54U)) + 126317283127992659U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 7568963536291415413U;
            aOrbiterE = (((aWandererG + RotL64(aScatter, 11U)) + 12294016745653004819U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 27U)) + 18269588932920281147U) + aNonceWordA;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 52U)) + RotL64(aCarry, 13U)) + 5872406424994751026U) + aNonceWordE;
            aOrbiterJ = (aWandererA + RotL64(aCross, 39U)) + 7764434758831474129U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 37U)) + 4804168969415573371U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 13U)) + 959601763507651280U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9257644462479293048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14332699366894494579U;
            aOrbiterI = RotL64((aOrbiterI * 8829304078930625541U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10487012596470786004U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 612729229562321440U;
            aOrbiterE = RotL64((aOrbiterE * 11380387280507726003U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7845523921295625315U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12742115479740024747U;
            aOrbiterD = RotL64((aOrbiterD * 15578543510683986421U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10294667720904610944U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14369711143154904567U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13753005602288309379U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 10918344717497681894U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18136794828308636957U;
            aOrbiterB = RotL64((aOrbiterB * 17899418637978002409U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14378638206724886404U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7077588188450008059U;
            aOrbiterJ = RotL64((aOrbiterJ * 485375960462924335U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8941870012851971932U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15242087859620352399U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4963002810455992839U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10395280254030875387U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 6826595516076975980U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 6198886240333178001U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10407910809564430664U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6368255889263255730U;
            aOrbiterF = RotL64((aOrbiterF * 3809496492809859731U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6365669830464231626U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 596785214258266904U;
            aOrbiterA = RotL64((aOrbiterA * 6338109335634389561U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4807438574488830717U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13854738573712660276U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6954368463489446551U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 10U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 26U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 26U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + aNonceWordM);
            aWandererF = aWandererF + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterA, 39U)) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 13U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterC, 46U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneB
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aFireLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23090U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 17457U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 17813U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19701U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16865U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 23599U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 57U)) + 13053031069776604052U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 24U)) + 1331396630251085122U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 15879286043343942393U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 37U)) + 13590365633321406830U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 43U)) + 14569235423040242618U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 27U)) + 11397370636618371560U) + aNonceWordJ;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 11U)) + 3455933494593971847U;
            aOrbiterD = (aWandererE + RotL64(aCross, 19U)) + 1307153376443784593U;
            aOrbiterG = ((((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 10688618762584786871U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aWandererF + RotL64(aIngress, 54U)) + 17746248451153600096U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 8512568600755410158U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8950230550112591092U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17790968369472845496U;
            aOrbiterK = RotL64((aOrbiterK * 5104988920132008913U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12583323865381967534U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11243927099685293887U;
            aOrbiterB = RotL64((aOrbiterB * 12867003042486433971U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9690268715525781389U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7466066217365074653U;
            aOrbiterD = RotL64((aOrbiterD * 17565696765505320889U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 3673528673209875118U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14079103852360952255U;
            aOrbiterG = RotL64((aOrbiterG * 17449228863409999629U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6747836856132250630U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5027692924422297153U;
            aOrbiterE = RotL64((aOrbiterE * 2492421273167124437U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11370341866003395776U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14013204893442579282U;
            aOrbiterJ = RotL64((aOrbiterJ * 6602239957997240785U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3436953430697936790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6399073534839993637U;
            aOrbiterA = RotL64((aOrbiterA * 14186050072610021241U), 13U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 7054057507823631422U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5752085719673338095U;
            aOrbiterH = RotL64((aOrbiterH * 13252660162476029593U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10628323020010327594U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5029617362660411790U;
            aOrbiterC = RotL64((aOrbiterC * 7230663968894173433U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6816547880074551571U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6683840259024813282U;
            aOrbiterF = RotL64((aOrbiterF * 13145224557159574541U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5952768353050729617U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 13053031069776604052U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13710064584055068065U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aPrevious, 44U) + aOrbiterB) + RotL64(aOrbiterH, 19U)) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterA, 43U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterC) + RotL64(aOrbiterI, 46U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 23U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterG) + aNonceWordM);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterB, 27U));
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterJ, 14U)) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 18U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25218U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 30623U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 28596U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26187U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32709U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29206U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 5U)) + 11210042748013785976U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 4584747303233477454U) + aNonceWordO;
            aOrbiterI = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 8878765929792969517U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 12U)) + 2172232330280041122U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 8378937026022264016U;
            aOrbiterB = (aWandererC + RotL64(aCross, 47U)) + 8683007464695824208U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 21U)) + 9564352997357118134U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 58U)) + 11713878436769887528U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 8052917623074021077U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 23U)) + 7720597162792145185U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 41U)) + 2602847785328475621U) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 17813669222300509724U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8724263063156573013U;
            aOrbiterI = RotL64((aOrbiterI * 3632927017737834359U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6882429835961613492U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13213313479525717359U;
            aOrbiterB = RotL64((aOrbiterB * 2411431247725974895U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2401526093648669573U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3616448566579979749U;
            aOrbiterC = RotL64((aOrbiterC * 13323155103752121393U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 18268262471839710401U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5116424918948694752U;
            aOrbiterA = RotL64((aOrbiterA * 7641143782996332069U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11405305689555640431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12427591396711015574U;
            aOrbiterD = RotL64((aOrbiterD * 8112834135715541223U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16960781161508084626U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12382604781005282628U;
            aOrbiterK = RotL64((aOrbiterK * 17196168631120103115U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10054839091354729292U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4167641616532985407U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 919291747187787625U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14383737233143309039U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16258779988369405932U;
            aOrbiterG = RotL64((aOrbiterG * 8348773195366160215U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4777263172049970723U) + aNonceWordN;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 12498046021142146499U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 5941015011162130901U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 7435001955334177144U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4100235545173125433U;
            aOrbiterF = RotL64((aOrbiterF * 5046572784117638909U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1981704568071298614U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11210042748013785976U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17889749044418386565U), 27U);
            //
            aIngress = RotL64(aOrbiterE, 48U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (RotL64(aOrbiterD, 37U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterA, 58U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 40U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 44U)) + aOrbiterA) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterD, 51U));
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 18U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 24U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9965C67F84EECF55ULL + 0xB85248CC912CE935ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBAA983DE8F583B81ULL + 0x93E0920A167C141DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC8A4A64B1D5C9FD5ULL + 0xF0742B01C5928FE2ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF1161DECD4254153ULL + 0x93B9633496FBD810ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x80B35AC3CDDC70E9ULL + 0xBF968D7FF9337739ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8C292DEE7AB77FDBULL + 0xFCFC90D7FDF1CB7BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x91FA6ED14D584B01ULL + 0xFA71560C453A6BDEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA914A5F06BFDBDB3ULL + 0xD502FFDEB3975F40ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC15CF6D0CAE0ABC7ULL + 0x894D429333BAD2DFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8C75012A09BBCBBFULL + 0xAB30F4FB7654CCF3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC6969692C60186EBULL + 0x9EDF2F2E83AC99A7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x804427B9EC67ACF7ULL + 0x9FCD1F33D54FFE10ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD52EABA2F21489F5ULL + 0xA05062E55BCFCD71ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE2C30674D1A66467ULL + 0x8FC24A88D4A35ABEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFC6C770DD67FDFB5ULL + 0xF52185E2D1C409E8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD60A8CF566FC7657ULL + 0xBFD80165E96DF3CFULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aFireLaneA, aExpandLaneA, aFireLaneB, aWorkLaneD, aExpandLaneB, aWorkLaneB, aFireLaneD, aExpandLaneC, aWorkLaneC, aWorkLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8007U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 7711U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3751U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 442U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1886U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4204U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 11U)) + 11210042748013785976U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 48U)) + 4584747303233477454U) + aNonceWordL;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 8878765929792969517U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 43U)) + 2172232330280041122U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 19U)) + 8378937026022264016U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 19U)) + 8683007464695824208U) + aNonceWordK;
            aOrbiterI = (aWandererD + RotL64(aCross, 27U)) + 9564352997357118134U;
            aOrbiterE = ((((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 11713878436769887528U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererI + RotL64(aIngress, 35U)) + 8052917623074021077U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7720597162792145185U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 2602847785328475621U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14065077077207224525U), 51U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 17813669222300509724U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8724263063156573013U;
            aOrbiterF = RotL64((aOrbiterF * 3632927017737834359U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6882429835961613492U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13213313479525717359U;
            aOrbiterI = RotL64((aOrbiterI * 2411431247725974895U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2401526093648669573U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3616448566579979749U;
            aOrbiterD = RotL64((aOrbiterD * 13323155103752121393U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 18268262471839710401U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5116424918948694752U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 7641143782996332069U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11405305689555640431U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12427591396711015574U;
            aOrbiterE = RotL64((aOrbiterE * 8112834135715541223U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16960781161508084626U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12382604781005282628U;
            aOrbiterJ = RotL64((aOrbiterJ * 17196168631120103115U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10054839091354729292U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4167641616532985407U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 919291747187787625U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14383737233143309039U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16258779988369405932U;
            aOrbiterB = RotL64((aOrbiterB * 8348773195366160215U), 37U);
            //
            aIngress = RotL64(aOrbiterJ, 41U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 14U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 56U) + aOrbiterD) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 38U)) + aOrbiterF) + aNonceWordB) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 5U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + aNonceWordC);
            aWandererE = aWandererE + ((RotL64(aScatter, 42U) + aOrbiterE) + RotL64(aOrbiterI, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 34U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12471U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 11828U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 12920U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16114U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11317U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 15679U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 10U)) + 4476099022490972343U) + aNonceWordF;
            aOrbiterF = (aWandererG + RotL64(aIngress, 23U)) + 16836423700375760429U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 8850577488928703557U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 51U)) + 7091631824560042743U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aIngress, 40U)) + RotL64(aCarry, 51U)) + 12560498899956759494U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 7797973377112012161U;
            aOrbiterK = (aWandererF + RotL64(aCross, 57U)) + 6173820673874805794U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 29U)) + 10805025132310245348U) + aOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aWandererE + RotL64(aCross, 47U)) + 7139216143268029968U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8241544862261635722U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4735527016563596150U;
            aOrbiterJ = RotL64((aOrbiterJ * 6621354217673598381U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5166171126690294033U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11117641762075368393U;
            aOrbiterG = RotL64((aOrbiterG * 4980156869201219393U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6312932356458415421U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1304139291184508668U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 10085025354842771067U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 16745854428789531080U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1945983905747274355U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 2497187958708890337U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16069701876646548995U;
            aOrbiterH = RotL64((aOrbiterH * 16606039730973709495U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17242004368025978091U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12334315722243232121U;
            aOrbiterB = RotL64((aOrbiterB * 16528598396696346719U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8007042082518126895U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5665686359038811484U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 11289316305875751813U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3913477186958600592U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 16918984318564170343U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5128293326494417281U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10227611546502931418U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7187623463085447228U;
            aOrbiterK = RotL64((aOrbiterK * 8479839369622163181U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 46U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 57U)) + aNonceWordH) + aWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 3U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 12U)) + aOrbiterF) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + aNonceWordB);
            aWandererF = aWandererF + ((((RotL64(aScatter, 12U) + RotL64(aOrbiterB, 51U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneD
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21938U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((aIndex + 23487U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 23174U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16776U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19437U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 24520U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 12U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 28U)) + 9023059520606551446U) + aNonceWordK;
            aOrbiterK = (aWandererE + RotL64(aIngress, 5U)) + 662441755115638133U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 53U)) + 16957253361196144712U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 11U)) + 7840955025765308605U) + aNonceWordN;
            aOrbiterH = (aWandererD + RotL64(aIngress, 23U)) + 346855809270395799U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 60U)) + 16099139781586668343U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 3706457327118322098U) + aNonceWordB;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 12166825885547622870U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 51U)) + 7792658665720344200U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7128477606152986326U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11116533962780290084U;
            aOrbiterE = RotL64((aOrbiterE * 11993485572912492297U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10443889548568288532U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4402387036946561017U;
            aOrbiterK = RotL64((aOrbiterK * 9032964741841833277U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13002706161178447654U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 13929727277530310708U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 7005639090871200285U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10949073760696935106U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15405923432006783533U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 17989565878445202495U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 18096057968822208905U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3032155040484574973U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 448597307502544605U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17462076466907467134U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15471015427013701406U;
            aOrbiterH = RotL64((aOrbiterH * 6113474000571976139U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3549031751266594344U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14243218483842508113U;
            aOrbiterG = RotL64((aOrbiterG * 9041601306479302047U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 5803147589312920032U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5549470512227427855U;
            aOrbiterA = RotL64((aOrbiterA * 12592362489263862879U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10076661824293832189U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3196799148974716550U;
            aOrbiterI = RotL64((aOrbiterI * 8183276968961467775U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 46U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 40U)) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterE, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 18U) + aOrbiterA) + RotL64(aOrbiterB, 28U)) + aNonceWordH) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 20U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aWorkLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32131U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 30707U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31230U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25603U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32626U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 28041U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 47U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 39U)) + 9654059367478508868U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 54U)) + 6473006635864677427U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 6944184481315853243U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aScatter, 29U)) + 4061496421939102306U) + aNonceWordC;
            aOrbiterF = ((aWandererC + RotL64(aCross, 19U)) + 15791809275719085463U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 14050798802646323055U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 12072905924741758266U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 47U)) + 17639076509231343896U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 23U)) + 12195388285571234715U) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4325404419499496529U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5910567888204238382U;
            aOrbiterE = RotL64((aOrbiterE * 11503787177122206937U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13092940059929942699U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 13381962590820308761U;
            aOrbiterD = RotL64((aOrbiterD * 6345904465930943295U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 15622862439323440527U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14027151901132249793U;
            aOrbiterJ = RotL64((aOrbiterJ * 2273573821630510087U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4584410023907605157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15763755180625487157U;
            aOrbiterC = RotL64((aOrbiterC * 6755736130607297639U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17023059745666559199U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5298529579288492971U;
            aOrbiterH = RotL64((aOrbiterH * 2483562793328357721U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2870152867331654736U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 12017191100173748848U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9958191466506480519U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 15899529176182436062U) + aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16482713846343388735U;
            aOrbiterF = RotL64((aOrbiterF * 719465695044265601U), 57U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 12943393531812774449U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9881108254540483225U;
            aOrbiterI = RotL64((aOrbiterI * 8011108108007885059U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3532054586199716750U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7142230313294797435U;
            aOrbiterB = RotL64((aOrbiterB * 14154176174768868421U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 18U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterG) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 46U)) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 4U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aNonceWordI);
            aWandererB = aWandererB + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 51U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterE, 53U));
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterG, 6U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 23U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 26U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD1F00C9FC91FB0BFULL + 0xEC0E95BF52E1A5F6ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF9AC11F04BF6680DULL + 0xF7667675F7557FD5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC557D2F7A580253DULL + 0xE56D9C9F3D432C0AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCF4E8813C99AB289ULL + 0xC163542AB77C4801ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCD702A6C5E8A5D51ULL + 0x8E8005EF67FD5C18ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEA657FB4801960A1ULL + 0xF3325D7B4B20B7D0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAAEF64B86A1B0227ULL + 0xBBD26C8769B03C24ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x84DB0B21250ECAA9ULL + 0x97EA727A3A443411ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xECA4B74FD1392AB9ULL + 0x87613E6658C4E0EBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD55AF0C4E4A820F7ULL + 0xB96D47A28DBD48B9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF7145195531E7E27ULL + 0xEE1B2973287A9CB5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCAA86D0DC4AF84F5ULL + 0x88EFAE73205D369BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xED499A2A48CB4577ULL + 0xD3A2F0595584A66AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDF22551C76FCDAA5ULL + 0xE606FD95F09C2A10ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD1C78690CD6A3F79ULL + 0xCDD89B266DD5CDC8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF4CFC8C8404A425DULL + 0x9DA7B104D1763192ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aFireLaneC, aFireLaneB, aExpandLaneB, aOperationLaneD, aOperationLaneA, aExpandLaneC, aOperationLaneB, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneC
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 4836U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 1092U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1026U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6799U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3251U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 3121U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 15188686795415908074U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 4U)) + 17310049041983079779U) + aNonceWordG;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 27U)) + 8246925977992441471U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 8644260919918112781U) + aNonceWordO;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 13401663736874819483U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 19U)) + 7940358935238314973U) + aNonceWordC;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 37U)) + 13278990328548007839U) + aNonceWordB;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11346868298353840706U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2374077904806833579U;
            aOrbiterE = RotL64((aOrbiterE * 1765686942154321425U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6978903378645019166U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11951633297870965212U;
            aOrbiterC = RotL64((aOrbiterC * 12778236598654492185U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17398460995357409673U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1215437945597836770U;
            aOrbiterF = RotL64((aOrbiterF * 9322970054123481621U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 1878751468043972239U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5343002808239712390U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9884918450053276861U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15894599082080422550U;
            aOrbiterK = RotL64((aOrbiterK * 8359936745539546131U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13917339232771145459U) + aNonceWordH;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 18101134009493720683U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 15835859435306756387U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3830086372356903769U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15894394599564584010U;
            aOrbiterJ = RotL64((aOrbiterJ * 9513921913446609263U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 37U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterA, 11U)) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterE, 50U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 36U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10140U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 11585U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14695U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9144U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11310U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 14335U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCarry, 3U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 57U)) + 9107326720193244489U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 35U)) + 10868585484401664145U) + aNonceWordA;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + 13637736741437846622U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aCross, 11U)) + 6130725216183918844U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 20U)) + RotL64(aCarry, 13U)) + 2063834478521338187U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 8564870627911949158U) + aNonceWordP;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 35U)) + 6524015751064086390U) + aNonceWordL;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9874937766875388236U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14723718409522680894U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17379140128833323431U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 13767059954741528279U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6387608251033722169U;
            aOrbiterB = RotL64((aOrbiterB * 6601902195707980693U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 5391425980008431000U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11524218415655093779U;
            aOrbiterD = RotL64((aOrbiterD * 12508457981779189389U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 155510463350385905U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10554591788433641311U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5412084824127934293U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8662160162966241542U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5092555636369853727U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 433807340167635499U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7163345798448796101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 695089002178413267U;
            aOrbiterG = RotL64((aOrbiterG * 17302689458565434475U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5409173939213468972U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15349690077393827541U) ^ aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10984681254001609841U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK + (((((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 13U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + aNonceWordF);
            aWandererF = aWandererF + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 20U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneD
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19606U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 17917U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22603U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18724U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23104U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 16395U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 3199575576585871314U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 2533378188975571824U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 26U)) + 6819782112558312658U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 5U)) + 12690060987724798497U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 35U)) + 7088375139715629606U) + aNonceWordF;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 17785618677423695666U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 1714999280296491277U) + aNonceWordM;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17611338506932491624U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6475727359297421201U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 15133348244242438069U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2347744591204119530U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2739317903351401068U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 15435029315209475631U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8663535261373274338U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8205245127823536479U;
            aOrbiterJ = RotL64((aOrbiterJ * 13857005110466856439U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8916510616749754516U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3944805940148512932U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18082271583211389701U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14094751253118853302U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14094299829196076311U;
            aOrbiterB = RotL64((aOrbiterB * 6370012560657108493U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3940673811518673802U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 3015106523254484839U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9655401190755573379U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 15404103131982599922U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1828655763233900875U;
            aOrbiterD = RotL64((aOrbiterD * 13024358077740310049U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterB, 50U)) + aNonceWordB) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aIngress, 42U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + aNonceWordE);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 24U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30462U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 27916U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 31311U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25043U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 32427U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29624U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 54U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 21U)) + 3339283916456813609U) + aNonceWordA;
            aOrbiterG = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 11339086426180649584U) + aNonceWordL;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 16819191669329316585U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 8361916937762630725U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + 18031328374429899857U) + aNonceWordP;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 58U)) + 18261756894092897276U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 13U)) + 4250319792907645666U) + aNonceWordC;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1492411503643460886U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 17369549067879344180U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2947354306696216579U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7301713524358676722U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2985193736033012535U;
            aOrbiterA = RotL64((aOrbiterA * 7473297294949338265U), 5U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 14086975808140927408U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10390516547834639800U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11441293212275890819U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18205555540941493267U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterC = RotL64((aOrbiterC * 3009081009044782443U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9209505304067579944U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3522631966146762306U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3441982898533162599U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8811497120829041188U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14707301680850257294U;
            aOrbiterI = RotL64((aOrbiterI * 11383709499376464085U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10080595991787801029U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6822892187784299166U;
            aOrbiterF = RotL64((aOrbiterF * 7417016898027778287U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterH, 23U)) + aNonceWordK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 58U)) + aOrbiterA) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterC) + aNonceWordO);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 50U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + aNonceWordF) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterB, 5U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8FE32F254825AB0FULL + 0xC98ABFF2AB6FD83FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD0E755A7683969A5ULL + 0x8EB7E510DF06C388ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA6885B0A5B4F8F4BULL + 0xD18363448DEDAF1AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF00C3A28CC7B3B4FULL + 0xECEA81191225F633ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB7953638ED234F0BULL + 0xCD61A84406DA945BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x86AAF8C708FDC591ULL + 0xAA4324B5DEDCB325ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEB14538EBD234055ULL + 0x9D1CB82EB1F20AC8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8D1D9DC207969CA1ULL + 0x99C2CB7C3F287E60ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCA9FD0094252B2BDULL + 0x9A86174653A3E42AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAF2CC2C8F16BA205ULL + 0x92EFC23CBD4C143AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF895EEB6D8ECADB5ULL + 0x83836EA2F62EAC26ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x876F46F2FBD9F6FDULL + 0xB7975AE90AF2DCB5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8098F90A2807E59FULL + 0xDD33461C681C63F9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB01A76714821B073ULL + 0xF90DCD6096435F53ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB2C3D8559387D327ULL + 0x9D6E94F778DDF28DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAF44ED6C5C1942A7ULL + 0xBA7B2A00BBCF8B3AULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 672U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 935U)) & W_KEY1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1833U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 586U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 13U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 35U)) + 9914837590440975587U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 3U)) + 6706125076401958051U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 16570817772679258409U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 6843705658115186948U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 57U)) + 16099930446791572351U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 26U)) + RotL64(aCarry, 47U)) + 5420550009556030459U) + aNonceWordM;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 41U)) + 5729549069420177477U) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15590601126188675834U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13044027390998620029U;
            aOrbiterE = RotL64((aOrbiterE * 16845199115313444123U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11068338135659636772U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6584988841809544332U;
            aOrbiterD = RotL64((aOrbiterD * 1683336180438945439U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8516813219883915404U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 10647314042912492785U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15559481057047148785U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 201691689889605304U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15512161798401184003U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 11473219183982564709U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3883760518944464145U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 13861805129175491145U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 17194438894492581181U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12019138626550801486U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13030350224959652248U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11724200983306280107U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2643807255422544248U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4127143302485631794U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterE, 58U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 42U) + RotL64(aOrbiterA, 51U)) + aOrbiterD) + aNonceWordD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterD, 5U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 11U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5118U)) & S_BLOCK1], 52U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2938U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3766U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5156U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCross, 47U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 3105313968748067810U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 12U)) + 9977249451119627064U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 27U)) + 17941392803495349366U) + aNonceWordH;
            aOrbiterG = (aWandererE + RotL64(aIngress, 21U)) + 4279533326705471133U;
            aOrbiterC = ((((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 13983828966811580039U) + aPhaseEOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 53U)) + 3983490984234810378U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 308786542215259956U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8443607695364427037U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14939626441464340668U;
            aOrbiterD = RotL64((aOrbiterD * 16793255020331774983U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 9350693577306121110U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 1717071159396961752U;
            aOrbiterJ = RotL64((aOrbiterJ * 11062480662625054525U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15911765265202100610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 14898546272333182767U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2674900543810733067U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3560903518513465868U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 5367062725726860234U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 8521908836601319553U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15233321480618877327U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9288449812290126074U;
            aOrbiterH = RotL64((aOrbiterH * 6815298520404038519U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 5504840529511585676U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6825598386801620046U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 11666542445846250077U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6433024450721339470U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 97934156644929458U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 8630530773006923215U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aCross, 41U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 39U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 13U)) + aOrbiterA) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6404U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 5724U)) & W_KEY1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5882U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6444U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5474U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererI + RotL64(aScatter, 27U)) + 9471546960258473684U) + aNonceWordP;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 18050235435948942244U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 3005107102671544641U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 53U)) + 17898396434573801850U) + aNonceWordF;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 3U)) + 15071602525497771648U) + aNonceWordB;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 60U)) + 5780119462702672108U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 13301326224151025687U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18129323022260575961U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1199228670638790709U;
            aOrbiterI = RotL64((aOrbiterI * 1780426336211781025U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 1839199978088021020U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4999517042246790165U;
            aOrbiterF = RotL64((aOrbiterF * 4585813675677234577U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 8788607633376516299U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15143903839930468749U;
            aOrbiterG = RotL64((aOrbiterG * 12735914889325422675U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16674732686428431869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15908873150953195581U;
            aOrbiterA = RotL64((aOrbiterA * 18049755517524334107U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterF) + 11204775359756474667U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2525984309543939465U;
            aOrbiterE = RotL64((aOrbiterE * 3988529812023791571U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4566345170476825512U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14876612901557406267U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 9047956948845135339U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14926290877038883931U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12710203178186614846U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14841163494801662515U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 4U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 23U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + aNonceWordG) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterA, 4U)) + aNonceWordM) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterE) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9622U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 9068U)) & W_KEY1], 24U));
            aIngress ^= (RotL64(mSource[((aIndex + 8818U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10536U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8980U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8212U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 34U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 5041131702736607991U) + aNonceWordB;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 9295010428212681446U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 37U)) + RotL64(aCarry, 23U)) + 6235875895358766017U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 53U)) + 2622227802531866918U) + aNonceWordM;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 3U)) + 3888894734834524972U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 11U)) + 241682012014701753U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererC + RotL64(aCross, 60U)) + 15758000422451568079U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2061944548396976912U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 8177144990755754531U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 12702392689484397947U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 554978075608818497U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 250408260560714933U;
            aOrbiterA = RotL64((aOrbiterA * 1295379390497107727U), 27U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 8700027645880997552U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10026130047465480902U;
            aOrbiterG = RotL64((aOrbiterG * 12417270861933696623U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9785843014096326696U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 9998582683258411251U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13817734599383455151U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6647207154174092691U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1578528131687283531U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4957715980509035719U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4994885315786213197U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 5676683798126497011U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5072908311783966503U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5535039946192891515U;
            aOrbiterI = RotL64((aOrbiterI * 2989412783482309753U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 58U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 11U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + aNonceWordO);
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 13035U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 11202U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11347U)) & W_KEY1], 35U) ^ RotL64(mSource[((aIndex + 11654U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12545U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12425U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11998U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aPrevious, 36U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 7948891781097675369U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 29U)) + 13928362874228230226U) + aPhaseFOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 51U)) + 10776180542602258926U) + aNonceWordG;
            aOrbiterG = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 5735115172149470447U) + aNonceWordE;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 35U)) + 5353591822981766987U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 21U)) + 562301708107268570U) + aNonceWordI;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 42U)) + 10467810247578364868U) + aNonceWordD;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14541630141152308564U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2350076897065139429U;
            aOrbiterJ = RotL64((aOrbiterJ * 12222554362482034393U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17519109078651162228U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6061035173339902910U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 10021905773432907835U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15654836633731000065U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 13723521735153718904U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14459516479283070563U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2849680038315532197U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7671010488872356142U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11485114338165600777U;
            aOrbiterI = RotL64((aOrbiterI * 4162584865462407791U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8759060657343458985U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11009137869375286581U;
            aOrbiterA = RotL64((aOrbiterA * 8741417343929809115U), 53U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 15792999392743144135U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6180808423175992479U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13681230339693676907U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererK = aWandererK + ((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 37U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aNonceWordF) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13934U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16289U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14539U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14190U)) & W_KEY1], 57U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15927U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14560U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14343U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 13U)) + 5568146815535263910U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 7736084960873834666U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 27U)) + 1336413621817562093U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 5218462026934984692U) + aNonceWordE;
            aOrbiterK = (aWandererA + RotL64(aCross, 37U)) + 7048890985969555935U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 5U)) + 13415955213864702118U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + 5657023257021528548U) + aNonceWordN;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14338310943137497116U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12305161641833950473U;
            aOrbiterJ = RotL64((aOrbiterJ * 11949964304435964395U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14514226578370459131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12692904083266024340U;
            aOrbiterI = RotL64((aOrbiterI * 14800805065279908839U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11012959130001327964U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 7106471380403489078U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 515626559384817223U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 3718101961355280891U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13364192077222322664U;
            aOrbiterA = RotL64((aOrbiterA * 1411328915372590283U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6720867800318913440U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 14497243926965866546U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 13595058589060114653U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5789056168233262435U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14438482587495779937U;
            aOrbiterD = RotL64((aOrbiterD * 10593535547917767263U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 313917798940179945U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 15241845511889502917U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16483477103771326107U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 44U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 43U)) + aNonceWordB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterI, 12U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aScatter, 12U) + RotL64(aOrbiterH, 41U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterA, 27U)) + aNonceWordM) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18895U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 17984U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 17925U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18642U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18973U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17807U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 17267U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 48U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 21U)) + 785861751704720606U;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 15968088718435606299U) + aNonceWordP;
            aOrbiterE = (aWandererH + RotL64(aScatter, 5U)) + 1393976526590347151U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 17240750947292745884U) + aNonceWordJ;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 29U)) + 4921576136163183137U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 12U)) + RotL64(aCarry, 53U)) + 3334047873553153032U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 47U)) + 15086509978458408698U) + aPhaseGOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 892391205397581998U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2965686403183767521U;
            aOrbiterE = RotL64((aOrbiterE * 709160942482770225U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 14632215393655706170U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15740589515342377322U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15677716942904794913U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11131164813943086445U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6988080581278900960U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6412189142344044255U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16021254613117657178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6183615599897921154U;
            aOrbiterJ = RotL64((aOrbiterJ * 9976411093264211033U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 12533992547026652747U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3104325358982904219U;
            aOrbiterA = RotL64((aOrbiterA * 14977348108778147265U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3878525937957474644U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 2120435259884368445U;
            aOrbiterD = RotL64((aOrbiterD * 15964718652193073177U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14928658302694194856U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 9121310461310309348U;
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 60U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 48U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + aPhaseGWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 11U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 46U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19191U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 21227U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20117U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 19658U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20195U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19550U)) & W_KEY1], 3U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21030U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 20601U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (((aWandererD + RotL64(aIngress, 43U)) + 8604208734152026945U) + aPhaseGOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 5U)) + 1374329953253889829U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 5779278910548228339U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 58U)) + 17670451230882805140U) + aNonceWordK;
            aOrbiterI = (aWandererE + RotL64(aCross, 11U)) + 8193848740764866860U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 15801168428145650104U;
            aOrbiterA = ((((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 2584718176087499066U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14950366247822737997U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9779293225265670135U;
            aOrbiterC = RotL64((aOrbiterC * 11625969538497982117U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 8688968319288372383U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13665723186950342601U;
            aOrbiterI = RotL64((aOrbiterI * 292035540396910837U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9395428688359973510U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2152719218018108418U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 15271961483518392671U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1350324137411377992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8729317951386057921U;
            aOrbiterG = RotL64((aOrbiterG * 6008790836417785083U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6317310451893678411U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10175620379041384281U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 14079679617394330781U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1203082119358827708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 523869107818193101U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4629501113595689157U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4028324959540432983U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15447631947468213912U;
            aOrbiterE = RotL64((aOrbiterE * 6037306615787729185U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 34U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 53U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 27U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 28U)) + aPhaseGWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23186U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 22720U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22216U)) & W_KEY1], 12U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23307U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 24228U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22984U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21875U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneD[((aIndex + 23793U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 27U)) + 6068543441070417854U) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 2995980468193441856U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 12U)) + RotL64(aCarry, 57U)) + 18020277482171594003U) + aNonceWordK;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 41U)) + 4293807434721230702U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 51U)) + 7980599111583893156U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 43U)) + 8593141111851052016U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 37U)) + 5903487523900084325U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15112035513447930209U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9854037263057006439U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 396276470208637283U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16759760289688823193U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12622628933030601390U;
            aOrbiterG = RotL64((aOrbiterG * 2151912984825538321U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1264668857268123425U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16302812053619101593U;
            aOrbiterI = RotL64((aOrbiterI * 18291400055836111547U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16087995784896123610U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 7970269262800468363U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 14924752223305807461U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5331477046030959632U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16534913204255550893U;
            aOrbiterB = RotL64((aOrbiterB * 1013433634373673565U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11042821902537871209U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8069677512345031660U;
            aOrbiterJ = RotL64((aOrbiterJ * 13622218526054132397U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5737130058129936372U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 1076627182956662997U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14342191224014199929U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterA, 4U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + aPhaseGWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 12U) + aOrbiterK) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterG, 51U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + aPhaseGWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 20U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25195U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 25414U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26076U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 25264U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 27272U)) & W_KEY1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24723U)) & S_BLOCK1], 56U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25212U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24608U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 12U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 2915859148137000694U) + aNonceWordJ;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 29U)) + 210680583721444425U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 35U)) + 6668118118775650387U) + aNonceWordO;
            aOrbiterK = (aWandererD + RotL64(aCross, 5U)) + 15794200818099010989U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 21U)) + 6565076707062828369U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 16323164497808856719U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 19U)) + 7965435318816716560U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7390281030573369017U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2269738866911824875U;
            aOrbiterH = RotL64((aOrbiterH * 1198697877998135567U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9664014216039993873U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 18284857398028357633U;
            aOrbiterB = RotL64((aOrbiterB * 8402008251343393737U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 367667619795303009U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7935945060956274197U;
            aOrbiterI = RotL64((aOrbiterI * 5481786693511955209U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16683666162337789540U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10655658270998102390U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 15231596813382239841U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8307037916581540297U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3247742749860703524U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 15052136713218656641U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10446792483683818139U) + aNonceWordB;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 16374602929344972364U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 12599903932725787599U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2411334498322777183U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1093701164116833765U;
            aOrbiterC = RotL64((aOrbiterC * 13129220206835381729U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterE, 4U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aNonceWordK);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 50U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterE, 43U)) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererK, 39U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27553U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 28709U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29299U)) & W_KEY1], 35U) ^ RotL64(aFireLaneC[((aIndex + 29435U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27975U)) & W_KEY1], 46U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29942U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29423U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 27612U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 56U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 11698283336767769359U) + aNonceWordJ;
            aOrbiterA = (aWandererD + RotL64(aScatter, 21U)) + 13297826354831483872U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 15254999058287530795U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 5U)) + 17474166585085346567U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 60U)) + 15684783498452840289U) + aPhaseHOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aWandererG + RotL64(aCross, 47U)) + 5061229733465216486U) + aNonceWordE;
            aOrbiterC = ((((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 15370981279168377944U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17966672773619554092U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14685092893994491068U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 1627758964162892429U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 12798804186209406389U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2848444181474221574U;
            aOrbiterI = RotL64((aOrbiterI * 13730480364920876877U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8551142075919636146U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8833198159158950723U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7650289040764974737U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7351473160893666232U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14204899612487622222U;
            aOrbiterA = RotL64((aOrbiterA * 6317485031956448029U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7008985178526543258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13576796403863120356U;
            aOrbiterC = RotL64((aOrbiterC * 13745839827679114077U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5769784656937900699U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 14075925808204936705U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 5844894088757604713U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17818667502858010896U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16016922065572683130U;
            aOrbiterH = RotL64((aOrbiterH * 7525645833898085373U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 44U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterI, 37U)) + aNonceWordC);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 10U) + RotL64(aOrbiterB, 44U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterB, 11U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 39U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32510U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 31425U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31486U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30458U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32323U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31516U)) & W_KEY1], 58U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 26U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterK = (((aWandererD + RotL64(aCross, 19U)) + 17668251151213543491U) + aPhaseHOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 51U)) + 16101602509895104517U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aIngress, 5U)) + 9083915270773304935U) + aNonceWordI;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 27U)) + 12810720730318214811U) + aNonceWordJ;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 26U)) + RotL64(aCarry, 43U)) + 18113428002071925621U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 13U)) + 1582208899354109878U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 4180688104819188154U) + aNonceWordL;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8954598189262820611U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15360094153175355879U;
            aOrbiterA = RotL64((aOrbiterA * 8177798855402983685U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8383954114668216260U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15626783326234049197U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 15058420415480073793U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10609978564404958066U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17656516608997517984U;
            aOrbiterF = RotL64((aOrbiterF * 4590620354119899777U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 760077259110786536U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3597338735888033063U;
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4431777844935985157U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10710423172154671296U;
            aOrbiterI = RotL64((aOrbiterI * 16267496318491473315U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 10240882795242085185U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7826053487019825891U;
            aOrbiterK = RotL64((aOrbiterK * 15053729937684375907U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9418883403715727353U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 11507423614799075545U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16189463984557044693U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 30U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 11U)) + aOrbiterA);
            aWandererI = aWandererI + (((((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 39U)) + aOrbiterA) + RotL64(aCarry, 35U)) + aNonceWordH) + aPhaseHWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterD, 18U)) + aNonceWordO);
            aWandererD = aWandererD + ((((RotL64(aCross, 4U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + aNonceWordF) + aPhaseHWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 51U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x98D41E1A0EF4B7F9ULL + 0xA5C8628EC0B8E1FBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8A3AAF38CFAD77EDULL + 0xA88D995EF592F6A1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBEF19E33D040A593ULL + 0xCB3BC7F9F6CAD48CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x83F71F40C0ED3319ULL + 0xD7E1A6789DF9155AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBFF4CD8544CB3E0BULL + 0xB8643BA0C36BB6ABULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD9EB39A63D2B179FULL + 0x8C271264CE7F774FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDC93CD17D03DF05FULL + 0xBE6A4CCE02B60F4EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8A7876290AE4D261ULL + 0xD5F08B9EAD08DED6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF55CAE1543F35AF9ULL + 0xA83CD146E9C3452AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFCFF9AD4EEE0C12FULL + 0xD6743DD066F3B8E8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xBF7BF8B1EDB3EE75ULL + 0xD2998A8DBE045CB8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xEDC974CC6FEE4517ULL + 0xA21237A1BC3BEACFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x815650B09BF8E653ULL + 0xC5A170D614529ECFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEE4694D181B810B3ULL + 0xBFF7D4FB4AC55721ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x889E6A968638FC47ULL + 0xC1102DB401514848ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x950D31936060E77FULL + 0x9D148E8BC3C04525ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4296U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((aIndex + 104U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3246U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 839U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 1162U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 58U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 12046647397183218524U) + aNonceWordE;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 2760779375026461991U;
            aOrbiterH = (((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 5U)) + 13735454443176855650U) + aNonceWordM;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 29U)) + 4370377000586647724U) + aPhaseAOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (((aWandererC + RotL64(aCross, 19U)) + 14566322384189969094U) + aPhaseAOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5056565959818422786U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8795403810686579209U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11205867337479457471U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9625947666256011567U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1703669290934254701U;
            aOrbiterF = RotL64((aOrbiterF * 5763881345676123583U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6664070663184147951U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2104148316797553431U;
            aOrbiterE = RotL64((aOrbiterE * 12887842067180975983U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 1197910004222596145U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9922977170060903197U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 13047828062605568603U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 2048376210852567829U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12568990647075931409U;
            aOrbiterA = RotL64((aOrbiterA * 9860242601194210927U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 46U) + RotL64(aOrbiterA, 57U)) + aOrbiterF) + aNonceWordJ) + aPhaseAWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + aPhaseAWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterA, 36U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 4U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8325U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 10486U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10594U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9269U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 10558U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 40U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterI = ((aWandererE + RotL64(aScatter, 21U)) + 14499676118633326000U) + aNonceWordH;
            aOrbiterD = ((((aWandererB + RotL64(aCross, 6U)) + RotL64(aCarry, 41U)) + 17191273593018552288U) + aPhaseAOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 4085176294948097737U) + aNonceWordP;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 11112671474158908186U) + aNonceWordM;
            aOrbiterA = ((aWandererF + RotL64(aCross, 43U)) + 8745787969012266485U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 18074049663777707948U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 2543758649719164688U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 7153845562786344373U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4659584749412700523U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 974639159259871273U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 17918719351847605523U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 9211220687971081987U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 8567024626862182714U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7755874089832496393U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5803002132294840900U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11968489432878148467U;
            aOrbiterD = RotL64((aOrbiterD * 4501441062617123165U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9470807228394903442U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1692347973120388469U;
            aOrbiterI = RotL64((aOrbiterI * 17433393164156231575U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 44U)) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 38U) + RotL64(aOrbiterD, 13U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordA) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14981U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 11601U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16187U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12700U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15105U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11742U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 3U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = (((aWandererJ + RotL64(aCross, 13U)) + 7651355040951791298U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 13988210277931659312U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 23U)) + 9846849412579537783U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 12746719939495876158U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 30U)) + 11498066185182895284U) + aNonceWordN;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11101058955193080232U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15513734459555672046U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 6974281215677538561U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 15711108675349394643U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 4771231759949468556U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9806191054594333615U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11449258010811305256U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17036938391509986723U;
            aOrbiterK = RotL64((aOrbiterK * 7411466953205347639U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6999245666776654250U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 2106819066263369528U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 13005885810757743129U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 12716183358903477216U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16752724547046059889U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 11475905692393034141U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 54U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + aNonceWordB) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 56U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21550U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneA[((aIndex + 18946U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20119U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20478U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19109U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16634U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 29U) ^ RotL64(aIngress, 44U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 41U)) + 3970829908171131502U) + aPhaseAOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 7040283759419531991U;
            aOrbiterK = ((((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 11856292169397052901U) + aPhaseAOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 51U)) + 819598588791819022U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 20U)) + RotL64(aCarry, 5U)) + 2176451710970866848U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 6454704928613390494U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11792122387218053841U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17994898985794518565U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9254780213489752211U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16591812589999846482U;
            aOrbiterB = RotL64((aOrbiterB * 5425771603523423167U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1471246223935074832U) + aNonceWordA;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1424843083106386453U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 15020536982657410783U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1856469958050891629U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6331743690452052712U;
            aOrbiterC = RotL64((aOrbiterC * 15327924647897459645U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10351075711345476487U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9518585245330480185U;
            aOrbiterJ = RotL64((aOrbiterJ * 3792179827396760391U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + aNonceWordJ);
            aWandererI = aWandererI + (((((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 5U)) + aNonceWordB) + aPhaseAWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + aNonceWordM) + aPhaseAWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterK, 12U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 26167U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 24320U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 25440U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22092U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24586U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22475U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 52U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterG = ((aWandererF + RotL64(aCross, 58U)) + 1457104756581596530U) + aNonceWordL;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 6127240317844622874U) + aNonceWordF;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 43U)) + 16492290056044189421U) + aPhaseAOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 10963676850938416468U) + aNonceWordJ;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 4872917367399752405U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 15218882377875616148U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5934166612122118251U;
            aOrbiterC = RotL64((aOrbiterC * 10365045124180379919U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14215280930872003003U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11428034799044600979U;
            aOrbiterK = RotL64((aOrbiterK * 12162528943733976177U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5453003654321728726U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 14273775120265649389U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5139018128323795309U), 35U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 328723770018440271U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13032190719588211088U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13363368478932798315U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2386881543033598494U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1649501123340887116U;
            aOrbiterJ = RotL64((aOrbiterJ * 11148976582360499033U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + aNonceWordI);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aNonceWordD) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 30U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 28U)) + aOrbiterJ) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30505U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 31778U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27712U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28311U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28206U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30429U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 6U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 4259993311776766595U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 2857813330021126753U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (((aWandererA + RotL64(aCross, 4U)) + RotL64(aCarry, 51U)) + 1345396841329442896U) + aNonceWordI;
            aOrbiterD = (aWandererH + RotL64(aIngress, 53U)) + 320992148982301024U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 5619109532065293074U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 10380157329426706345U) + aNonceWordO;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12449831150625409695U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3354095240459774437U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7847096607042268396U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11707184096803214678U;
            aOrbiterA = RotL64((aOrbiterA * 1959476948106553973U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9893643746186827088U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 333687403830908774U;
            aOrbiterB = RotL64((aOrbiterB * 17911256836121454271U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13837360705077441580U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4367119682175710689U;
            aOrbiterD = RotL64((aOrbiterD * 10295744669174603401U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1193493435041306784U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15062951612027370606U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 2509383510565136549U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 39U);
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterJ) + aNonceWordC);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterF, 26U)) + aNonceWordK) + aPhaseAWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aNonceWordM);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAB1F2A27D55B2B59ULL + 0x891D805E9BE0BA8EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB8270C1840876939ULL + 0x9161486307938258ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x917865050AFF2387ULL + 0xF8088285EA92B591ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC3E922E62B8628CDULL + 0x8F9C47940BC38637ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCE9B0477D459E921ULL + 0x8442FC24CF34CACAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBD3C426641C9A757ULL + 0xED823EC2CD72F02BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC670E22B4A6D1785ULL + 0xB10228959DCBCB52ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC458DCE350A3542FULL + 0xE54B707B7284D054ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD10CC56B5B1E0AD5ULL + 0x96BF5234DA418B88ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBCF20D1CA947A66DULL + 0xEBDEBC1FC4D3E0BBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9AE4B4685B0F581FULL + 0xF20094909E2EDF63ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE8FAB6DC5A0E0DD7ULL + 0xED2E07E014522FE9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA477245925C0DA99ULL + 0x8DFACD3DFD46AEE4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBFDC5F6359367075ULL + 0x91208DC6D4F37AB3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xF3F7BDC590EE1E1BULL + 0x9D5600B15BEB51F5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x81E4648291AA50E1ULL + 0xFE56E4DD72E9B170ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aFireLaneB, aInvestLaneC, aFireLaneC, aExpandLaneC, aInvestLaneD, aExpandLaneD, aWorkLaneA, aExpandLaneA, aWorkLaneB, aFireLaneA, aWorkLaneC, aExpandLaneB
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2565U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 4099U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4459U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5309U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 2746U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3104U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 29U)) + 785861751704720606U) + aNonceWordO;
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 15968088718435606299U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 6U)) + 1393976526590347151U) + aNonceWordA;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 19U)) + 17240750947292745884U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 4921576136163183137U;
            aOrbiterJ = ((((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 3334047873553153032U) + aPhaseBOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererA + RotL64(aCross, 37U)) + RotL64(aCarry, 39U)) + 15086509978458408698U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 57U)) + 892391205397581998U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 10U)) + 2965686403183767521U) + aPhaseBOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14632215393655706170U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15740589515342377322U;
            aOrbiterK = RotL64((aOrbiterK * 15677716942904794913U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 11131164813943086445U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6988080581278900960U;
            aOrbiterG = RotL64((aOrbiterG * 6412189142344044255U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 16021254613117657178U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6183615599897921154U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 9976411093264211033U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12533992547026652747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3104325358982904219U;
            aOrbiterE = RotL64((aOrbiterE * 14977348108778147265U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3878525937957474644U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 2120435259884368445U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 15964718652193073177U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14928658302694194856U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9121310461310309348U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 17304439784647477491U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3715693239100476493U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 7336577492932262490U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11074754160002665253U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2312452827448455675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4322756069651934618U;
            aOrbiterJ = RotL64((aOrbiterJ * 6908893297397073539U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4962079617577705818U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5072727464750706525U;
            aOrbiterH = RotL64((aOrbiterH * 4947670001221089155U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterE, 48U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterG, 5U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 60U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererF = aWandererF + (((RotL64(aCross, 28U) + RotL64(aOrbiterA, 53U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterE, 27U)) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 37U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 14U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 39U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aFireLaneC
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9229U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 10232U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7615U)) & S_BLOCK1], 6U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 9415U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8696U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5721U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 10808U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 47U)) + 2225397913940961213U) + aNonceWordL;
            aOrbiterA = ((aWandererD + RotL64(aCross, 51U)) + 8342544893601343643U) + aNonceWordP;
            aOrbiterD = (aWandererF + RotL64(aIngress, 5U)) + 162922186381417187U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 11660218373710972210U) + aPhaseBOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aPrevious, 24U)) + 14909034764605802354U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 16776955237009701511U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 41U)) + 5834487809188925253U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 1498492772767040320U;
            aOrbiterJ = (((aWandererB + RotL64(aPrevious, 36U)) + 4161765458781579617U) + aPhaseBOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10511923076962447765U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8575954471692620021U;
            aOrbiterD = RotL64((aOrbiterD * 12526744988828982731U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6536325446331340573U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1790628986900286346U;
            aOrbiterA = RotL64((aOrbiterA * 5262997114200816715U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2623814807619278590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11676970995834706612U;
            aOrbiterH = RotL64((aOrbiterH * 10057461115132434901U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 13836786354224256591U) + aNonceWordG;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 6293096163612129260U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 8977954126326217153U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4271144764978661248U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15938494256992560202U;
            aOrbiterI = RotL64((aOrbiterI * 10004841288382726739U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11038155227307702976U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 12408749795071243930U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 5527720475032868855U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1673665849053496882U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12866353361497103629U;
            aOrbiterJ = RotL64((aOrbiterJ * 6041125499398924871U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10673935802381580966U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8946776538955520352U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12293084177712710021U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16294935203370452805U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4697759331563852212U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14407806317275373043U), 47U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 22U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterK, 19U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 60U)) + aNonceWordD) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterI);
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 56U)) + aOrbiterC) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 16293U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((aIndex + 14656U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 12377U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15257U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneC[((aIndex + 11950U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCarry, 19U) + RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 51U)) + 1393781663398437180U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 14U)) + 17414594746688585273U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 47U)) + 2823888497053071250U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 57U)) + 17032631958617884859U) + aNonceWordC;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 15222697630461125019U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 15737414920751551780U) + aNonceWordP;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 6U)) + 1357196111055783001U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 5315122321649251691U) + aNonceWordH;
            aOrbiterD = (aWandererD + RotL64(aScatter, 39U)) + 7893744655508595974U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16721939414324611738U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3444375866323610848U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 10874157227815775661U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1825716513674511632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15582066843912467318U;
            aOrbiterB = RotL64((aOrbiterB * 12765146555943757373U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 15673590949193923915U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13887365046280406413U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 3169061375011420121U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12730414371734709356U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4819112390640821927U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8782547948627685451U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3089925954422937464U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7180179304678622530U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 16118051565147747413U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17030269962085008657U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6675917351883004046U;
            aOrbiterD = RotL64((aOrbiterD * 14134335325316949687U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12572022803491077491U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2801421744689267375U;
            aOrbiterK = RotL64((aOrbiterK * 315045745990934023U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4335148696780313055U) + aNonceWordG;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12526298573395110141U;
            aOrbiterF = RotL64((aOrbiterF * 11276803410698178607U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6984239833558496091U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 12195433952105336808U;
            aOrbiterG = RotL64((aOrbiterG * 8642600547427664495U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 10U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterC, 30U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 58U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + aNonceWordD) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterB, 23U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + aNonceWordE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18080U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneC[((aIndex + 21364U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 16805U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19631U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneD[((aIndex + 21185U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 13U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 10038936806177516123U) + aNonceWordL;
            aOrbiterA = (aWandererC + RotL64(aCross, 3U)) + 1773168435195292638U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 10655711161526628072U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 42U)) + RotL64(aCarry, 57U)) + 14422295664639740437U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 23U)) + 4125228715513159576U) + aNonceWordA;
            aOrbiterI = (aWandererA + RotL64(aIngress, 51U)) + 3670449653158650845U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 11U)) + 17553727567180813057U) + aPhaseBOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 46U)) + 5111401772713882743U) + aPhaseBOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aCross, 35U)) + 7688573124662314413U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9438375825507814395U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14177477039902118886U;
            aOrbiterE = RotL64((aOrbiterE * 6467406626985022537U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16329942595859623928U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3990536794006836672U;
            aOrbiterJ = RotL64((aOrbiterJ * 579024714339065373U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5072881436583180756U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16789727877867289997U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 8766246302636197905U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17313956922306689438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11530878396329822041U;
            aOrbiterB = RotL64((aOrbiterB * 11356860047841383129U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterE) + 3612616532321160196U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4172189825359187763U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12938945495299393177U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8677279703778052804U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1912172980909479362U;
            aOrbiterI = RotL64((aOrbiterI * 10053289257955474143U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1460085850227494500U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12116763868122868147U;
            aOrbiterA = RotL64((aOrbiterA * 6076945628020280957U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17571840610366424432U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15581362592611080868U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1129054058044872003U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14434700039977611666U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4534294602623329152U;
            aOrbiterC = RotL64((aOrbiterC * 5860911553425182045U), 43U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 23U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterA, 50U));
            aWandererG = aWandererG + ((((RotL64(aCross, 52U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterC, 54U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 43U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23835U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneD[((aIndex + 26132U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22495U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24968U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 24529U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 14U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (aWandererI + RotL64(aPrevious, 23U)) + 9914837590440975587U;
            aOrbiterJ = ((((aWandererE + RotL64(aIngress, 38U)) + RotL64(aCarry, 51U)) + 6706125076401958051U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 16570817772679258409U) + aNonceWordG;
            aOrbiterF = (((aWandererK + RotL64(aCross, 19U)) + 6843705658115186948U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (aWandererA + RotL64(aScatter, 47U)) + 16099930446791572351U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 5420550009556030459U;
            aOrbiterI = (aWandererB + RotL64(aCross, 51U)) + 5729549069420177477U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 58U)) + 15590601126188675834U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 27U)) + 13044027390998620029U) + aNonceWordJ;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 11068338135659636772U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6584988841809544332U;
            aOrbiterC = RotL64((aOrbiterC * 1683336180438945439U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8516813219883915404U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10647314042912492785U;
            aOrbiterH = RotL64((aOrbiterH * 15559481057047148785U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 201691689889605304U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15512161798401184003U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11473219183982564709U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3883760518944464145U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13861805129175491145U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 17194438894492581181U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12019138626550801486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13030350224959652248U;
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 2643807255422544248U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4127143302485631794U;
            aOrbiterK = RotL64((aOrbiterK * 5441038881111578487U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14602951930809633069U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4555737199162278494U;
            aOrbiterF = RotL64((aOrbiterF * 12415825635220991865U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6343143902997169834U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10404783711336491985U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6235474458879439079U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7406959231434835393U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 6684368109277850196U;
            aOrbiterG = RotL64((aOrbiterG * 8760360417572331159U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterK) + aNonceWordD) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aNonceWordP) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 12U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 39U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + RotL64(aCarry, 5U)) + aNonceWordN);
            aWandererC = aWandererC ^ (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aScatter, 42U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 18U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28240U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 30545U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 32612U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30693U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 32614U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 35U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 5U)) + 13499155707765393469U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 41U)) + 3740324981823726185U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 23U)) + 5470765363949735652U) + aNonceWordD;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 39U)) + 3446436171274452326U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 1778929412631211933U) + aPhaseBOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 14666308799855220954U) + aNonceWordA;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 13U)) + 4548410236791175055U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 56U)) + 5829739767694190372U) + aNonceWordI;
            aOrbiterB = (aWandererA + RotL64(aCross, 27U)) + 14319231414903675748U;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 1513851750246111405U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1685620217748986019U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 9286548037413609445U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16284162182006054402U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6271539598462003309U;
            aOrbiterJ = RotL64((aOrbiterJ * 13923286694131331137U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12669312437565969473U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11894755313393001665U;
            aOrbiterI = RotL64((aOrbiterI * 12556759675372354075U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6315983824634946566U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17106616474222892782U;
            aOrbiterE = RotL64((aOrbiterE * 167205520766791073U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13350266700180455548U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4608846311203767162U;
            aOrbiterC = RotL64((aOrbiterC * 2504857468837437365U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14195866746143604365U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7917977448256795054U;
            aOrbiterD = RotL64((aOrbiterD * 5927771378657284557U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10707336923305131629U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17122696159336995392U;
            aOrbiterB = RotL64((aOrbiterB * 13953518568670659191U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5182322763573586116U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6503754948502556246U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14749002194140663519U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14907832047832987341U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6258064448676621346U;
            aOrbiterK = RotL64((aOrbiterK * 4407960312705621487U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 46U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 60U)) + aOrbiterE) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterB, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 37U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 52U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD) + aNonceWordB);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 29U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererH, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDC95C0E847B3FFAFULL + 0xCFDCFBAF4C43BAA0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB8DA3C6A6CFD52A5ULL + 0xA48E04E4475D50C4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8B551FF7C7478B53ULL + 0xBB49057BCA0BAA9DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE28999D18E4704B7ULL + 0xFE5B1F5A952C8766ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB01DA126B9AB7189ULL + 0x98899C58E809E5C7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF32B8BB0B279EC6BULL + 0xF2994F72B506FB05ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x827A0D58723C012BULL + 0xA31FD9D1D2C8439FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB8C185290377D931ULL + 0xB66A5E216AEC97A7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCC72DBC17D3EC527ULL + 0xDDCEEFCE23F628B7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF01C2B4FB935EC7DULL + 0xFC6C1EFC0B87738BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF0A6D20AF89159EFULL + 0xA244062B8CA8B4E9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCA3A63D9A5E29EEDULL + 0xDF0AEF539E85541DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCF8AE7FCB3DEE6A9ULL + 0xFFEAAFA06C3090A3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC42EF5B9C6B63835ULL + 0xDF20B63AFD986EDBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD5590653F99ED0ABULL + 0xC3A45504DF2ADA2FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD297E48790F509B1ULL + 0xE8C92C8340608660ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3548U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 4333U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 532U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1679U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5123U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 3530U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 77518479758428414U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 4832061802166300011U) + aNonceWordH;
            aOrbiterF = (aWandererE + RotL64(aScatter, 27U)) + 11695291171006574112U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 57U)) + 7467412817843260094U) + aPhaseDOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 5U)) + 17801484124471154757U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 5555455638503958639U) + aNonceWordN;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 46U)) + 5669470540733721606U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3042388456327784163U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2236734925228156691U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10076582424701705531U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14459720401528685450U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4814967631216658856U;
            aOrbiterJ = RotL64((aOrbiterJ * 18288097536171386643U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16950679344449075945U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6262238639302011050U;
            aOrbiterE = RotL64((aOrbiterE * 9942659897425088183U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3522256359074996724U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 12524717897707074242U;
            aOrbiterK = RotL64((aOrbiterK * 6787771338063891989U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13891759914865623828U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11910250571469028666U;
            aOrbiterI = RotL64((aOrbiterI * 12311343917878428995U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 2240189915640314069U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5365912986308810837U;
            aOrbiterG = RotL64((aOrbiterG * 15133972552032469957U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 9323732721344489753U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 13087326560957916553U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14659491687401151733U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterE, 12U)) + RotL64(aCarry, 5U)) + aNonceWordC) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aNonceWordO);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + aNonceWordE);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterE, 51U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterF) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8082U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 6944U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7166U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneC[((aIndex + 9589U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8054U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6829U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7554U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (aWandererC + RotL64(aPrevious, 53U)) + 5160910997561396461U;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 14920764751058512062U) + aNonceWordE;
            aOrbiterD = ((aWandererH + RotL64(aCross, 19U)) + 6080952401749660022U) + aNonceWordB;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 3U)) + 17667234330526298627U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererI + RotL64(aCross, 26U)) + 760630072638686756U) + aPhaseDOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 37U)) + 3504157162816997476U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 5U)) + 9489022223422585882U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 1149898536879968964U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10492284328940025310U;
            aOrbiterD = RotL64((aOrbiterD * 7893416766300156495U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13213275606286399312U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10557118912847180413U;
            aOrbiterF = RotL64((aOrbiterF * 10077877991284587845U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15618980209023994776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5268600749854045564U;
            aOrbiterC = RotL64((aOrbiterC * 3849660559223919613U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8011552687609649990U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3148133096349525066U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5245156554959620007U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12032847944237867285U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14999005703490824673U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 6631584955208646049U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5426735969392906710U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3593177531650386729U;
            aOrbiterE = RotL64((aOrbiterE * 12997284886192717043U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 1701444719333347373U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 15928731228196894960U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 1919318226904213433U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterE, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aNonceWordL);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 56U) + RotL64(aOrbiterI, 10U)) + aOrbiterA) + aNonceWordD) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterD, 57U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 3U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12727U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 11848U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13634U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 13241U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16012U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (aWandererK + RotL64(aPrevious, 51U)) + 5088525177670191619U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 58U)) + 9966456257813932112U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (((aWandererC + RotL64(aIngress, 37U)) + 7707646574027146307U) + aPhaseDOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 75480203757681173U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 384659134071835163U) + aNonceWordL;
            aOrbiterE = (aWandererI + RotL64(aIngress, 21U)) + 3158769775373307778U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 13U)) + 17360830943513941272U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5317278822721604586U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1371427105215954781U;
            aOrbiterK = RotL64((aOrbiterK * 10956603063464438611U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 3162710551223553423U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5332921933853550756U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 11709546145149357887U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10572462410297815854U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10234389605554817892U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 2130374833440291193U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13421365517991380605U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10186643614984034083U;
            aOrbiterC = RotL64((aOrbiterC * 8554471709467808453U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4742438973260817120U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6081590345899008846U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7069396301823124931U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15360092808493795340U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12186413069553132646U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 3815981440611914267U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16756221656224451552U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12232880965861373143U;
            aOrbiterE = RotL64((aOrbiterE * 14196910735715726471U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + aNonceWordN);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + aPhaseDWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 60U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20153U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneA[((aIndex + 20058U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18159U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19011U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18845U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 36U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterI = (((aWandererI + RotL64(aIngress, 30U)) + RotL64(aCarry, 5U)) + 1898718075389870739U) + aNonceWordM;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 11U)) + 5631794889237247403U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 57U)) + 18219714659484524607U) + aNonceWordI;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 15419581386225732921U) + aNonceWordO;
            aOrbiterA = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 53U)) + 9125575431710198210U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aScatter, 47U)) + 12205871520544965505U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 23U)) + 7617534300497343422U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18017579105368135814U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10693882161946020042U;
            aOrbiterC = RotL64((aOrbiterC * 2326507900303932855U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11669615701700895306U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11045110212889232165U;
            aOrbiterH = RotL64((aOrbiterH * 5965171269273719849U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 18019107802806469913U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12315940560472528716U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4505122470351404065U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 4899009736070044310U) + aNonceWordB;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17412253404253730364U;
            aOrbiterG = RotL64((aOrbiterG * 10791901166391946485U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4826286251927854181U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4523455921321845084U;
            aOrbiterA = RotL64((aOrbiterA * 14534103906736598099U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4132514462154182215U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 7164745605985109269U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14107325508977225261U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 6297434295807635654U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8813887638672996646U;
            aOrbiterI = RotL64((aOrbiterI * 17495632530773158201U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 12U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aNonceWordL) + aPhaseDWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterB, 20U));
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 47U)) + aOrbiterC) + aNonceWordD);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aNonceWordA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22784U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneB[((aIndex + 26754U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 24745U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23966U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneA[((aIndex + 22039U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 5U)) + 7893287783892523139U) + aNonceWordK;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 5U)) + 10257331997383491153U) + aNonceWordP;
            aOrbiterB = ((aWandererK + RotL64(aCross, 60U)) + 14562226733652231753U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 14320342577110737851U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 9816717579822880756U) + aNonceWordA;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 35U)) + 9558926960095881953U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 27U)) + 9230371862654338324U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6414274291252913420U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13868546184398350849U;
            aOrbiterB = RotL64((aOrbiterB * 1547986864837497409U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16940736952569949038U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2866957764814864371U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3554702178644797003U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7916721976073979724U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1602444214978842275U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 11072503711308122385U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9529061385251008037U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8402775110887376588U;
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterC) + 15003592180290390713U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14195681406520825751U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 11455000833788877217U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3263577002367714202U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 12019422062655581928U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 5002313835338447799U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8508638054582582917U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6536618106353552880U;
            aOrbiterH = RotL64((aOrbiterH * 6233964121117511885U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aNonceWordG);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterH) + aNonceWordI);
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterG, 26U)) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 34U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32086U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((aIndex + 30334U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30459U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28310U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29707U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 10U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererF + RotL64(aScatter, 23U)) + 8375305456876489425U) + aPhaseDOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 16193562952772453047U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 18088652458594816223U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 37U)) + 767344788620249944U) + aNonceWordG;
            aOrbiterC = (aWandererD + RotL64(aIngress, 11U)) + 7705194930396368752U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 3829736891311272834U) + aNonceWordD;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 44U)) + 9881681671347640061U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 1721196560190164264U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3002652618388454213U;
            aOrbiterD = RotL64((aOrbiterD * 15289749311593032657U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9811621464004005202U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5652598941069986530U;
            aOrbiterI = RotL64((aOrbiterI * 4797973356708091621U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 6250499348327316328U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16025054277615264530U;
            aOrbiterH = RotL64((aOrbiterH * 16446892258704281903U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13800298546867243172U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12256104592865905782U;
            aOrbiterE = RotL64((aOrbiterE * 16983140179497142713U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 17817225416918329229U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17738671327352776217U;
            aOrbiterJ = RotL64((aOrbiterJ * 393488251327705063U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6816031224188400541U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 16989563985059237014U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 8677884225771717797U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 16891524847268207549U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 1833508573940405571U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9709196587703979539U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 44U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 29U)) + aNonceWordF) + aPhaseDWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 51U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordP);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF10FAAFB91915631ULL + 0xAFBCFB3AB6EAE3C8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x91B8CE43B7464FF9ULL + 0xF530828423F766A3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE51E4B480BD30967ULL + 0x97B8C453885545BBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA4F3AB9B45286BFFULL + 0xF1492F1DCAA32AD6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC0F06E1629AB4E9BULL + 0xC954377F116F93A4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFE7F334D752BB375ULL + 0x8842E849AFB25249ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE1C8091E45C024A9ULL + 0x88F1C664838150E9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA04B95FBAC536839ULL + 0xF2E9949C44F7B85AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF3793FBCFD1FEC4DULL + 0xB30E438AE0820CBDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEF2199C9293DEEC9ULL + 0x8B047897E7AD7224ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x956799E2B53F574BULL + 0xDD2D3F20CE86B7B1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8C7570B1E4AC3F43ULL + 0xE65E87F4C6B74C3DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8AE4868D014B4285ULL + 0xF797E1780C8AD41AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB7A05352CB3BE67FULL + 0xB359EF26529159FBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB726377998A83361ULL + 0xFE9F78CF27495472ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC3DC091CD0DFDCA5ULL + 0xE70F646A2A7EFBB9ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 120U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 1093U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 3884U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3289U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 56U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 1027U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 56U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 57U)) + 3236820517816085022U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 741288875914097926U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 8417246926007729580U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 57U)) + 9715717805774537170U) + aNonceWordL;
            aOrbiterG = (aWandererF + RotL64(aIngress, 35U)) + 14360243844821619482U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 5U)) + 10760908100206775334U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 46U)) + 3434641779946167811U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 19U)) + 7885568822756234567U) + aPhaseEOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (aWandererG + RotL64(aIngress, 39U)) + 3041563437672051294U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 43U)) + 15761355327564963516U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aCross, 51U)) + 1158633562785937421U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9338581575871970653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9172038894262857354U;
            aOrbiterJ = RotL64((aOrbiterJ * 3110871165285625807U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14653924713599790081U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3854497592598563309U;
            aOrbiterH = RotL64((aOrbiterH * 11737111068815795303U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16286980180327600557U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5092583772591249756U;
            aOrbiterB = RotL64((aOrbiterB * 13955105624639442903U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4288397994175567333U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15584236478994873104U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 1860480595862755379U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5557463939827483792U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2659814275753280856U;
            aOrbiterC = RotL64((aOrbiterC * 17702430405693184643U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6941807963525063449U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2040598555191211307U;
            aOrbiterE = RotL64((aOrbiterE * 14750544987531722765U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 347572666231116258U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 779304821185302523U;
            aOrbiterK = RotL64((aOrbiterK * 14180254150318109855U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 10632524582873079742U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9761308771280517212U;
            aOrbiterA = RotL64((aOrbiterA * 13926235411726048921U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2097439707055737964U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2813977930321463948U;
            aOrbiterI = RotL64((aOrbiterI * 14983538728730662603U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6080592019313796689U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5396623654821376409U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 15478858835919398677U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 8460497459575045342U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3236820517816085022U;
            aOrbiterD = RotL64((aOrbiterD * 5530411244458067093U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterB, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 46U)) + aOrbiterK) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 29U)) + aOrbiterG) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterA, 39U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 18U) + RotL64(aOrbiterH, 53U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterF, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 12U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 8914U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneC[((aIndex + 7395U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 7883U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 6337U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8062U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 6968U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5842U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 5U)) + 9654059367478508868U) + aNonceWordF;
            aOrbiterA = (aWandererC + RotL64(aIngress, 35U)) + 6473006635864677427U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 53U)) + 6944184481315853243U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 11U)) + 4061496421939102306U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 23U)) + 15791809275719085463U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 18U)) + 14050798802646323055U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 3U)) + 12072905924741758266U;
            aOrbiterI = (((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 17639076509231343896U) + aNonceWordK;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 27U)) + 12195388285571234715U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 4325404419499496529U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 35U)) + 5910567888204238382U) + aNonceWordN;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13092940059929942699U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13381962590820308761U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6345904465930943295U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15622862439323440527U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14027151901132249793U;
            aOrbiterH = RotL64((aOrbiterH * 2273573821630510087U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4584410023907605157U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15763755180625487157U;
            aOrbiterI = RotL64((aOrbiterI * 6755736130607297639U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17023059745666559199U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 5298529579288492971U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 2483562793328357721U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2870152867331654736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12017191100173748848U;
            aOrbiterJ = RotL64((aOrbiterJ * 9958191466506480519U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15899529176182436062U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16482713846343388735U;
            aOrbiterC = RotL64((aOrbiterC * 719465695044265601U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12943393531812774449U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9881108254540483225U;
            aOrbiterE = RotL64((aOrbiterE * 8011108108007885059U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3532054586199716750U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7142230313294797435U;
            aOrbiterK = RotL64((aOrbiterK * 14154176174768868421U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 733958394016131587U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2060800099014517137U;
            aOrbiterA = RotL64((aOrbiterA * 12988885554457108631U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2278498033811574812U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15342071118593803929U;
            aOrbiterB = RotL64((aOrbiterB * 7842196613533603835U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12987212219357101955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9654059367478508868U;
            aOrbiterF = RotL64((aOrbiterF * 11796100167917742307U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 46U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterF, 24U)) + aPhaseEWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterI, 47U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 12U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 21U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13013U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneA[((aIndex + 13930U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13424U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15501U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneC[((aIndex + 14154U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 26U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 19U)) + 14008824488073394623U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 5U)) + 13317978415866411468U;
            aOrbiterI = (aWandererA + RotL64(aCross, 54U)) + 13209180141897453900U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 11870521586865233578U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 8052156380448047385U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 29U)) + 12158131176743680605U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 10U)) + 14674467487607719347U) + aNonceWordB;
            aOrbiterK = (aWandererG + RotL64(aIngress, 27U)) + 18055496790566231147U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 37U)) + 3838105585041578784U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 2839568255183054418U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 11933612922864258179U) + aNonceWordA;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6289849094151630580U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2640344350528492271U;
            aOrbiterI = RotL64((aOrbiterI * 16197726750829369365U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16306175266267657791U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3339898380394883600U;
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15017076663742800002U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8973064296077602496U;
            aOrbiterK = RotL64((aOrbiterK * 9309462227233615761U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17580319233338139859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14063208878807603874U;
            aOrbiterD = RotL64((aOrbiterD * 16601475239075164585U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13326130855721009942U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12843186026737544416U;
            aOrbiterF = RotL64((aOrbiterF * 4975848122837321619U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14102887715772847499U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14495942314329085733U;
            aOrbiterC = RotL64((aOrbiterC * 4236795312917583565U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11564857125101669667U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17435970784822000464U;
            aOrbiterB = RotL64((aOrbiterB * 1472691848852381173U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16561390130356833062U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 9952805588514363872U) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 3720874990001086597U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8246822023509690545U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 305480212301772662U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 4295787267516476485U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11729872285756639125U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9669174142543613799U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 9443240779947114779U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7653344907616923293U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14008824488073394623U;
            aOrbiterJ = RotL64((aOrbiterJ * 8362849599309360823U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 46U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 53U)) + aOrbiterB) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterC, 13U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterC, 60U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + aNonceWordG) + aPhaseEWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererB = aWandererB + (((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterC, 44U)) + RotL64(aCarry, 11U)) + aNonceWordK) + aPhaseEWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 42U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21203U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((aIndex + 21016U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16456U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20003U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21643U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 23U)) + 12131317914288566437U) + aNonceWordG;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 5672805657999385496U;
            aOrbiterA = (aWandererD + RotL64(aCross, 27U)) + 3581710244233124197U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 13U)) + 15251296040538489436U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 52U)) + 11295008604679904153U;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 47U)) + 2230897493419504490U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 47U)) + 7109600123297458999U;
            aOrbiterH = (aWandererC + RotL64(aCross, 5U)) + 13119156643107683803U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 50U)) + 14755160867807355250U) + aNonceWordB;
            aOrbiterE = ((aWandererG + RotL64(aCross, 23U)) + 16829363373287496832U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 19U)) + 16981122946707720883U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8806000776958603317U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16810923047720876014U;
            aOrbiterA = RotL64((aOrbiterA * 17872735050219539145U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8129657889554436328U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8653100378491974463U;
            aOrbiterC = RotL64((aOrbiterC * 11395283153912468661U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 17048985838727432415U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10892675550889823573U;
            aOrbiterJ = RotL64((aOrbiterJ * 976298937314081913U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 15960158965421254346U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12290011578634850001U;
            aOrbiterI = RotL64((aOrbiterI * 9280475585104357745U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 16265047040311479093U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10312956912303656248U;
            aOrbiterG = RotL64((aOrbiterG * 3012584393253845131U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16706890352221352779U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10630955894218491929U;
            aOrbiterK = RotL64((aOrbiterK * 12675937483456206355U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4009352551041162434U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3043810773683888556U;
            aOrbiterB = RotL64((aOrbiterB * 4328135390387997315U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1398071019814944785U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 16689766557488135301U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 8403881916549404871U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 15934647144489136524U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13521276033614992223U;
            aOrbiterF = RotL64((aOrbiterF * 18003640895553609933U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4281211055727414100U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11848150507497406421U;
            aOrbiterH = RotL64((aOrbiterH * 1107789990317433481U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12022829841608199449U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12131317914288566437U;
            aOrbiterD = RotL64((aOrbiterD * 13275753083882829973U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 34U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 60U)) + aOrbiterC) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aPhaseEWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 23U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 54U) + aOrbiterB) + RotL64(aOrbiterH, 21U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterI, 42U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterG, 13U)) + aNonceWordM);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterC, 51U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterE, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererH, 4U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22362U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((aIndex + 23847U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24494U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24570U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22358U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25583U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 7651355040951791298U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 44U)) + 13988210277931659312U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aScatter, 37U)) + 9846849412579537783U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 51U)) + 12746719939495876158U) + aNonceWordJ;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 11498066185182895284U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 10U)) + 11101058955193080232U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 15513734459555672046U) + aNonceWordE;
            aOrbiterI = (aWandererB + RotL64(aCross, 23U)) + 15711108675349394643U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 29U)) + 4771231759949468556U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 27U)) + 11449258010811305256U;
            aOrbiterB = (aWandererF + RotL64(aCross, 3U)) + 17036938391509986723U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6999245666776654250U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2106819066263369528U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 13005885810757743129U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12716183358903477216U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16752724547046059889U;
            aOrbiterH = RotL64((aOrbiterH * 11475905692393034141U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17623077680983093163U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6726003022297274986U;
            aOrbiterI = RotL64((aOrbiterI * 14709385877103232653U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2842410225096524740U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9235178377537910514U;
            aOrbiterF = RotL64((aOrbiterF * 11813751114775673845U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2619888019860844610U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 6295481948199619613U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15429161806953951205U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9724921158061115570U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4070976180958458679U;
            aOrbiterK = RotL64((aOrbiterK * 6080566609081811453U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5864247978960125554U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 7771249710071026757U;
            aOrbiterE = RotL64((aOrbiterE * 4787660062590737657U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15006900854988166845U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2755659268987119046U;
            aOrbiterG = RotL64((aOrbiterG * 8043939381186802359U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1922321482806966418U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13910818219761929659U;
            aOrbiterB = RotL64((aOrbiterB * 8895973123729951173U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 7540972911473176026U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5419023469522423893U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1380429266266313945U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2349651834739320824U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7651355040951791298U;
            aOrbiterD = RotL64((aOrbiterD * 3713776056028698433U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 26U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 39U)) + aOrbiterI) + aNonceWordA) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 24U)) + aOrbiterA) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterK) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 35U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 36U) + aOrbiterD) + RotL64(aOrbiterF, 5U));
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 18U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterH, 27U)) + aNonceWordH) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30416U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 32332U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 30671U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32263U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((aIndex + 31078U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 53U)) + 5171470532667965920U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 37U)) + 750549462358682403U) + aNonceWordC;
            aOrbiterC = ((aWandererF + RotL64(aCross, 23U)) + 3325689257577120525U) + aPhaseEOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 5U)) + 18031575461559790826U) + aNonceWordJ;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 39U)) + 13874739537012288677U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 11U)) + 4250029868785016865U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 53U)) + 8211158803112611161U) + aNonceWordF;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 14U)) + RotL64(aCarry, 11U)) + 1083939790236786027U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 21U)) + 3446525462376962464U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 43U)) + 6973817815000417325U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 15230876489676945543U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9359727659738755880U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8775170107816327654U;
            aOrbiterC = RotL64((aOrbiterC * 6910680458261008653U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11958941755525038545U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16966819714283167348U;
            aOrbiterH = RotL64((aOrbiterH * 16363457661846050749U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 14556087985619763243U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 17915047508377045221U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 6727635453185130109U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8578745677485367222U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7002181668717618866U;
            aOrbiterG = RotL64((aOrbiterG * 12329703532414955235U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3569939503066735457U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2956247934282522184U;
            aOrbiterF = RotL64((aOrbiterF * 9946650822131152531U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4285180013402474041U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5976239869535619811U;
            aOrbiterE = RotL64((aOrbiterE * 3458095419039067465U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2424524955161695463U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6849595426583763537U;
            aOrbiterI = RotL64((aOrbiterI * 12727902040238318101U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11414890686374886716U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5668287266836153445U;
            aOrbiterD = RotL64((aOrbiterD * 8011885266143066285U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9976985606260445887U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9223940029500676834U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8508023992488499955U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4480967907876921958U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5132766654502526597U;
            aOrbiterA = RotL64((aOrbiterA * 321625389942019245U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12921555132452983464U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5171470532667965920U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9710487797420618879U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 56U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterG) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterI, 4U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 23U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 40U)) + aPhaseEWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 21U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 51U));
            aWandererD = aWandererD + (((RotL64(aCross, 20U) + RotL64(aOrbiterF, 35U)) + aOrbiterB) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + RotL64(aWandererD, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA34F6366C8681963ULL + 0x8899285A0AB96803ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8B6688AA242E505FULL + 0x86A5625F43E6B263ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB7F6224EC54191E9ULL + 0xE254AF29E859D6E5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC827F995B3927FE3ULL + 0x9A773D9310CEC574ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8F1DCD720A8FFFFFULL + 0xBC1CD080DC89DEC1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x937A3AD3E1BB9127ULL + 0xEC7773E91AE21DFFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xABC8578B8E473C1FULL + 0xC41494371CF621DEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEC46E33860F061D1ULL + 0xD8CC0BFFCD071FC4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAE57A5C8E0886007ULL + 0xED1B0AC21F6B466BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xDDEA09A166D248F9ULL + 0xE52BAA7DF0A1DBD0ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA042EEA939D1E479ULL + 0xAB3109127D76DA27ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBD4238164DF911ABULL + 0xC14B9A372194DF4CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x84B9FA77F784FC0FULL + 0x92620E577B93D103ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDE9F2E59F0C3DBD9ULL + 0xD490F91CB5E7F31FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xBA6F3F53E958207BULL + 0xB1955AB3EA18D0A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA091A89EB0F0B043ULL + 0xDCD052BF7E835175ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aSnowLaneA, aOperationLaneC, aOperationLaneD, aWorkLaneC, aSnowLaneC, aInvestLaneD, aInvestLaneC, aSnowLaneD, aWorkLaneD, aExpandLaneA, aSnowLaneB, aExpandLaneB, aInvestLaneB, aExpandLaneC, aInvestLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aSnowLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aSnowLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3120U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 1721U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 811U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2964U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5137U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 5284U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 41U)) ^ (RotL64(aPrevious, 26U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 18U)) + 14686411261024919129U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 3U)) + 7514582233957632005U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 57U)) + 6520710480103365552U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aWandererB + RotL64(aIngress, 23U)) + 1983621978676188036U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 9003524602590749672U) + aPhaseFOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 27U)) + 6428568234045228995U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 8656552687136446989U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 38U)) + RotL64(aCarry, 37U)) + 16916248288415922490U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 43U)) + 9740237548002535784U) + aNonceWordJ;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 907561000814618339U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4751108900841197631U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4545395964730641957U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 167774899400732287U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11907484918310854962U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 7213139491146402985U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14910318613649863924U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 14882888155751455276U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 11394136445442060201U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16175942562693781908U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11022373758481651102U;
            aOrbiterB = RotL64((aOrbiterB * 6836331461393816027U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12548405399045031548U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10850926364556828443U;
            aOrbiterK = RotL64((aOrbiterK * 16231561687709867431U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13391684887911141790U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14648937281264822988U;
            aOrbiterJ = RotL64((aOrbiterJ * 6533299316940026059U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8298658887198526821U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13822977698661348891U;
            aOrbiterG = RotL64((aOrbiterG * 17769262972278410937U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7505646847564645719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3238749538197209166U;
            aOrbiterI = RotL64((aOrbiterI * 15394286542600778567U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15853506915123709257U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8426329899401071248U;
            aOrbiterE = RotL64((aOrbiterE * 1330397096577715113U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 23U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 40U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterI, 11U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 26U)) + aOrbiterI) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 43U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 36U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 21U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterD, 57U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 30U)) + aOrbiterG) + aNonceWordC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererB, 18U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 5631U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 10537U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8194U)) & S_BLOCK1], 23U) ^ RotL64(aInvestLaneD[((aIndex + 10040U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6176U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7360U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7957U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 57U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererH + RotL64(aScatter, 21U)) + 13333509828310369865U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 29U)) + 7645352517103840797U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 34U)) + 5310766306660062655U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + 5165635069832352932U) + aPhaseFOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 15684141764734281849U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 3327963374225061738U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 41U)) + 8625811794878848871U) + aNonceWordF;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 46U)) + 7598657468430485291U) + aNonceWordK;
            aOrbiterD = (((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 57U)) + 2881171216276746485U) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10237691227222918101U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6419254255884834497U;
            aOrbiterB = RotL64((aOrbiterB * 3816625473642865305U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4238455444646479956U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 14936613353493061492U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3544216916806292273U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15324699725208372627U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9506640480601832011U;
            aOrbiterG = RotL64((aOrbiterG * 12819564111348390227U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3709149613660215641U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1724290199312754307U;
            aOrbiterF = RotL64((aOrbiterF * 12597580418257897965U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13191172833570139194U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3686087945377837886U;
            aOrbiterE = RotL64((aOrbiterE * 10883609557429936283U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 10418330386245397022U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5383531313632347245U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2987755379396160073U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7414716553072652212U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11301761123966206201U;
            aOrbiterC = RotL64((aOrbiterC * 1546727321088592187U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8570229732236388847U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8773754460060264773U;
            aOrbiterH = RotL64((aOrbiterH * 3251360788932563495U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13636929800504199371U) + aNonceWordN;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 5486599841558573720U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 2867914211589815153U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 38U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterI, 41U));
            aWandererE = aWandererE + (((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterC, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 14U)) + aOrbiterH) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 47U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterB, 35U)) + aOrbiterF) + aNonceWordD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 42U) + RotL64(aOrbiterD, 60U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneD[((aIndex + 15924U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 15710U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 13947U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15588U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15076U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 11U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 4751694786009671052U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 56U)) + RotL64(aCarry, 51U)) + 16362725160370844224U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 13U)) + 6360885380915941057U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 5154536007972297036U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 29U)) + 9362540581874808253U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 39U)) + 13902493871525612934U) + aNonceWordN;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 23U)) + 10208452885367546542U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 35U)) + 3117030377279160998U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 60U)) + 17286247690414027870U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3930314320040949141U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7289525252391668404U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15452162299105112187U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3434167955466809185U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 17852573095128575663U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 1485660158767033425U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6137259687928853253U) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 13992510605237574698U) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 15346263295995333395U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6470556523400123474U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4333255670390099293U;
            aOrbiterH = RotL64((aOrbiterH * 11089933812030082647U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7700424876430257995U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16920736951239453071U;
            aOrbiterJ = RotL64((aOrbiterJ * 8920407493132380497U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 1635071690430295730U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9966700845966398620U;
            aOrbiterA = RotL64((aOrbiterA * 17210048121896546867U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 9833458070123027075U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1990346556486746432U;
            aOrbiterD = RotL64((aOrbiterD * 8704943923474148699U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13339523466436517327U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5018264760406215603U;
            aOrbiterF = RotL64((aOrbiterF * 2769197961801783627U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 123427497520755346U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4535841104215792886U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 1417676310539177131U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 50U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 12U) + aOrbiterJ) + RotL64(aOrbiterG, 43U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + aNonceWordJ);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterI, 47U)) + aNonceWordO) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 54U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterE, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 11U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 60U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aSnowLaneB
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aSnowLaneB forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17454U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((aIndex + 20507U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 18062U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17137U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 17845U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 53U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 14U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 6U)) + RotL64(aCarry, 27U)) + 15316464782468770057U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 35U)) + 6642872057476351588U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 47U)) + 660732654689529192U) + aNonceWordI;
            aOrbiterB = ((aWandererG + RotL64(aCross, 13U)) + 7235418086884000655U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 14784518476694580493U) + aNonceWordM;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 57U)) + 12222433977933449375U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 39U)) + 8573001207708329927U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 28U)) + RotL64(aCarry, 5U)) + 16035256260815013172U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 23U)) + 15767726974121910203U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17712217935322939971U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13488963456923357159U;
            aOrbiterJ = RotL64((aOrbiterJ * 16785285630840310405U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10222949131965611079U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 1495561412321657209U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9706305581868526265U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16156530750584361434U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 7773792489045606309U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10730624207715601393U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11544578291333360613U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3665587867634242865U;
            aOrbiterD = RotL64((aOrbiterD * 4840528190844842595U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 15248434984650998090U) + aNonceWordC;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15487979645426567581U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10868107809356766183U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6972347795052712690U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16074994810010431338U;
            aOrbiterG = RotL64((aOrbiterG * 1262655238856775853U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16851139687900415292U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14630026837021552812U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 9577900853521254603U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14236330619137368169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17778707026111136216U;
            aOrbiterK = RotL64((aOrbiterK * 16239561893843454747U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9390961969105999083U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1174881758316573228U;
            aOrbiterA = RotL64((aOrbiterA * 6602061268277529311U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 14U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 52U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererK, 44U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 34U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 22153U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneD[((aIndex + 24238U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 24113U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22357U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 24060U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 20U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 6521330037475130256U) + aNonceWordJ;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 54U)) + 12611880456055428940U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 12061611078130934708U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 27U)) + 1558112410801116984U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aCross, 39U)) + 10509115227850160786U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 60U)) + 4045915960688792066U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererD + RotL64(aScatter, 47U)) + 1196541286513243082U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 19U)) + 15564991032722373702U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 4897765238703641798U) + aNonceWordD;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12327429514907752733U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6189189797708711636U;
            aOrbiterH = RotL64((aOrbiterH * 9017615866338877651U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6374267075282018852U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1888758503831341439U;
            aOrbiterE = RotL64((aOrbiterE * 74387714918264257U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14956857689299491800U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14879361107223331957U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9166712966729591953U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16086885494838105042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8069724185844303923U;
            aOrbiterD = RotL64((aOrbiterD * 8878470736758734353U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10854345917959911439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7078313614360332089U;
            aOrbiterA = RotL64((aOrbiterA * 9864025732292844871U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15083669236062255011U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 594879695916679116U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 9852515479152735283U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6721466068234534523U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 475816724162626782U;
            aOrbiterG = RotL64((aOrbiterG * 4799725182757588407U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4341655358154605899U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15477254302340298586U;
            aOrbiterI = RotL64((aOrbiterI * 13961520225881974201U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10179091913200895775U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6310490897546909571U;
            aOrbiterK = RotL64((aOrbiterK * 15080621088825477613U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 22U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 54U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aNonceWordH) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterE) + aNonceWordC) + aPhaseFWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 58U)) + RotL64(aCarry, 23U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterD, 39U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 46U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 20U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32597U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 29918U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 31957U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29139U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 29135U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 48U)) + RotL64(aCarry, 21U)) + 8367680518550579791U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 11491674725611181241U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 19U)) + 16673861720782164214U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 9786610124108350855U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 23U)) + 5745080601557577637U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 3U)) + 1959402215131684684U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 11U)) + 6121650036079196522U) + aNonceWordG;
            aOrbiterC = (aWandererG + RotL64(aIngress, 27U)) + 12016309761037342392U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 60U)) + 5986936646177049603U) + aNonceWordI;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 1000367700904043468U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17425288243569101032U;
            aOrbiterJ = RotL64((aOrbiterJ * 2174614006719048535U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4856917474950325209U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16312111093223166419U;
            aOrbiterH = RotL64((aOrbiterH * 11046477664487805241U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 456110002032422270U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11393724374787795662U;
            aOrbiterK = RotL64((aOrbiterK * 1176984359123668389U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8378176867715697176U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 8086186452345234815U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8470349167474173245U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2528229938740192694U;
            aOrbiterD = RotL64((aOrbiterD * 8717790851266520943U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13247168811545753141U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8745293957516815264U;
            aOrbiterB = RotL64((aOrbiterB * 14270617180621072619U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6165915500564961987U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12015407798844173213U;
            aOrbiterA = RotL64((aOrbiterA * 3913451986559154153U), 47U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 545006684939922156U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16366753936267185001U;
            aOrbiterI = RotL64((aOrbiterI * 6495185976430013201U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 3097605623436091728U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15950167830259022926U;
            aOrbiterG = RotL64((aOrbiterG * 4415538963984293323U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 18U) + aOrbiterG) + RotL64(aOrbiterD, 44U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH + ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 57U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 50U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAEAB40C13BB46051ULL + 0x961E6CD1452EB953ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEC5241B2AA6ED96FULL + 0xBD20EC623011137FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8BA89E0329F095ABULL + 0xEED3953247C189B6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCF1050EEBABAEE6FULL + 0xC839A8BEEAA2924EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE5823366C6C46D05ULL + 0x9A1BA2564B227528ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE7B8494FA9118C59ULL + 0xE7A15990077E038FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xABD8020ED10AA8CDULL + 0xA8AD9BB82A04B2E3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB21E23746CFB7DB7ULL + 0x904A05AD53CB8500ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xADF81DEC83D2A18DULL + 0xB12AA9D8C4EF35A6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE17082ACF08F3B2FULL + 0x934B1B3CA7F46CE4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAF1FA8EC363A30A3ULL + 0xF6865903DBBC2A9EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF77822F0E24A3E1FULL + 0xB32ED674CE024E42ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEDCCA645905F7B9DULL + 0xE185A78B763BE756ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD80A8699D9DCA3D3ULL + 0xAC017B02816775EDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xA70E4C4F246F69E1ULL + 0xC1F727B8518D118AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8AA94089A05CD7EDULL + 0xC9934E0E5DE7D51CULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneB, aSnowLaneC, aSnowLaneD, aInvestLaneD, aWorkLaneA, aInvestLaneC, aFireLaneD, aWorkLaneB, aFireLaneC, aExpandLaneA, aInvestLaneB, aExpandLaneB, aFireLaneA, aExpandLaneC, aInvestLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneD
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 3470U)) & S_BLOCK1], 47U) ^ RotL64(aSnowLaneB[((aIndex + 2666U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 2298U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 1997U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 686U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 172U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 51U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 4476099022490972343U) + aPhaseHOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 16836423700375760429U) + aNonceWordJ;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 8850577488928703557U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 19U)) + 7091631824560042743U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 12560498899956759494U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 5U)) + 7797973377112012161U) + aNonceWordI;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 27U)) + 6173820673874805794U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10805025132310245348U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7139216143268029968U;
            aOrbiterF = RotL64((aOrbiterF * 8349754682635765573U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8241544862261635722U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4735527016563596150U;
            aOrbiterD = RotL64((aOrbiterD * 6621354217673598381U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5166171126690294033U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11117641762075368393U;
            aOrbiterA = RotL64((aOrbiterA * 4980156869201219393U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6312932356458415421U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1304139291184508668U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 90744653170922319U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10085025354842771067U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16745854428789531080U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 1945983905747274355U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2497187958708890337U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 16069701876646548995U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 16606039730973709495U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17242004368025978091U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12334315722243232121U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16528598396696346719U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 39U)) + aOrbiterE) + aNonceWordO);
            aWandererH = aWandererH + ((((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 56U)) + aOrbiterA) + aNonceWordB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterD, 29U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7864U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneC[((aIndex + 8834U)) & S_BLOCK1], 38U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 5907U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((aIndex + 8872U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8108U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6320U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 7073U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (aWandererC + RotL64(aScatter, 57U)) + 5131645209694953015U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 19U)) + 12070391048835379854U) + aPhaseHOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 19U)) + 2604295836242338724U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 14042039029284001596U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 41U)) + 8914654543854559327U) + aNonceWordN;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + 2185619407969359869U) + aNonceWordB;
            aOrbiterI = (aWandererG + RotL64(aIngress, 10U)) + 5187406295103352574U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8022832481290871217U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8783061916740573472U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3309891377744201773U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 10711028365596196301U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13387065038269133571U;
            aOrbiterF = RotL64((aOrbiterF * 12444578026365205255U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 11187001318931801582U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14191473173276034019U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2491253922434756431U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16207761776716426435U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9677408414452078760U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5487303383095129949U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 17812460332794370649U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7736423148554132028U;
            aOrbiterI = RotL64((aOrbiterI * 15588733747232852555U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17293203944059014763U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13487243633338010243U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9468688858740539095U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15979293016815060755U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17645215484691359547U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 1449450767288733995U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 28U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterI) + aNonceWordL);
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 58U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13598U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 11332U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12484U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11894U)) & S_BLOCK1], 27U) ^ RotL64(aSnowLaneC[((aIndex + 15287U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 51U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 38U)) + RotL64(aCarry, 23U)) + 9630214189402543339U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 4072576573737526819U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 23U)) + 15994787452709618869U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 57U)) + 6403240137132259482U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 29U)) + 10229266900170507720U) + aNonceWordP;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 11U)) + 5025294577989748989U) + aPhaseHOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 16696461238217956883U) + aPhaseHOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9878318855341719119U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 16086635438116177346U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5585682357395705671U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12295437783084203730U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 7681150419912842402U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 7289497379725191451U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2639104034287637448U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12298170009332243573U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 9397919591171238575U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3485932317267669626U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16569551670038752475U;
            aOrbiterB = RotL64((aOrbiterB * 8139802826402217631U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4448490103784103954U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14510534073046885941U;
            aOrbiterD = RotL64((aOrbiterD * 7777192047386438305U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4286195398675733451U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15790355933840266463U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 13342257823027075501U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6362891510370156055U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15121822034579983174U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7268045994574844937U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 43U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterB) + aNonceWordK) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterA, 34U)) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterD, 57U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18626U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((aIndex + 17258U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 20824U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20455U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 19087U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 41U)) + (RotL64(aCarry, 14U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 966899917801652720U) + aNonceWordL;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 10996327672320748649U) + aNonceWordK;
            aOrbiterK = (aWandererF + RotL64(aCross, 27U)) + 4188171566846621107U;
            aOrbiterC = ((((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 5886209243097387959U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererI + RotL64(aScatter, 43U)) + 14940428957136728111U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 12U)) + 179187285531914832U) + aPhaseHOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 57U)) + 6685351948936817752U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1894506461704029700U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4182760368636977082U;
            aOrbiterK = RotL64((aOrbiterK * 972988091869133921U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 12523318028514940790U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 5059306166973366892U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 2857409765717296483U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5890872367917643851U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 17747338389865221534U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5306740664798049267U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13906227834259884100U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7152105382899756368U;
            aOrbiterJ = RotL64((aOrbiterJ * 6772157117358310485U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17868101884759619240U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11758843266314148347U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 5919135169337501485U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13950566197090324859U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 17278105609930477854U;
            aOrbiterG = RotL64((aOrbiterG * 11431842718945107359U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9556785965646738355U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 841298436857932987U;
            aOrbiterC = RotL64((aOrbiterC * 15077843186688841797U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 19U)) + aNonceWordG) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterD, 13U)) + aNonceWordP);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterK, 26U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterK, 51U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aFireLaneA
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23143U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 22341U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 23952U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24782U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 21870U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 39U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = ((aWandererK + RotL64(aCross, 27U)) + 18255347001097480328U) + aNonceWordO;
            aOrbiterH = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 13679246790311505735U) + aPhaseHOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 3U)) + 10565839529765027116U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 14327172566224769901U;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 16239024612038195174U) + aNonceWordE;
            aOrbiterK = (aWandererF + RotL64(aCross, 44U)) + 13800012174212131890U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 37U)) + 13900288860157577583U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 4144386119777112740U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3154558262670631372U;
            aOrbiterJ = RotL64((aOrbiterJ * 13236911910092437063U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7456728543137614001U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 11709519851158935384U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 7016689518570071587U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15607438907832240304U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9276575329661725624U;
            aOrbiterE = RotL64((aOrbiterE * 8879744070762412745U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6459435969129449226U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6442382118416542275U;
            aOrbiterA = RotL64((aOrbiterA * 2921027306686588233U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12117432107282150865U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6831279293184793243U;
            aOrbiterG = RotL64((aOrbiterG * 2435360641135249073U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9520022957804572889U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8322178689474588679U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 1627707191467537115U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4162401591586869316U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8994015844714895961U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15421910378057951895U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 41U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aNonceWordF);
            aWandererC = aWandererC + ((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterK, 50U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + RotL64(aWandererJ, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31750U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 29969U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27891U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32060U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31955U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererD + RotL64(aCross, 29U)) + 16424657151168221875U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 21U)) + 17150123681886380361U) + aNonceWordP;
            aOrbiterC = (((aWandererA + RotL64(aScatter, 58U)) + RotL64(aCarry, 5U)) + 16041993588694572757U) + aNonceWordF;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 9871185846434828537U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 11227236398354430757U) + aNonceWordM;
            aOrbiterG = ((aWandererC + RotL64(aCross, 3U)) + 5399325217402192631U) + aNonceWordN;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 51U)) + 9248828789282890454U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9041370494203701062U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14944424084524970764U;
            aOrbiterC = RotL64((aOrbiterC * 10283363059424655079U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5481938174456671041U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14783648629543752715U;
            aOrbiterH = RotL64((aOrbiterH * 7260164783191886395U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12355573914530445723U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9863991559011968318U;
            aOrbiterB = RotL64((aOrbiterB * 8495251211794343179U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16149688605937250965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 106041828692026825U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 12199934305374582599U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8076098639554567792U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11155119311895580013U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1495180896564818647U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6847612160595917702U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16094377920388017367U;
            aOrbiterF = RotL64((aOrbiterF * 4875801863643206333U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13584719866672696684U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13446209321646234607U;
            aOrbiterD = RotL64((aOrbiterD * 9945349065094781529U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 37U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterC, 53U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + aNonceWordC) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 38U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 6U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 53U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 27U)) + aOrbiterC) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 19U);
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
    [[maybe_unused]] std::uint8_t *aFireLaneA = pWorkSpace->mFireLaneA;
    [[maybe_unused]] std::uint8_t *aFireLaneB = pWorkSpace->mFireLaneB;
    [[maybe_unused]] std::uint8_t *aFireLaneC = pWorkSpace->mFireLaneC;
    [[maybe_unused]] std::uint8_t *aFireLaneD = pWorkSpace->mFireLaneD;
    [[maybe_unused]] std::uint8_t *aInvestLaneA = pWorkSpace->mInvestLaneA;
    [[maybe_unused]] std::uint8_t *aInvestLaneB = pWorkSpace->mInvestLaneB;
    [[maybe_unused]] std::uint8_t *aKeyRowReadA = &(pWorkSpace->mKeyBoxA[H_KEY - 1][0]);
    [[maybe_unused]] std::uint8_t *aKeyRowReadB = &(pWorkSpace->mKeyBoxB[H_KEY - 1][0]);
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2284U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[((aIndex + 1196U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1909U)) & W_KEY1], 52U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2160U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 60U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 23U)) + 13854738573712660276U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aCross, 57U)) + 16835460633412286294U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 5U)) + 6785859293758091931U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 35U)) + 126317283127992659U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 7568963536291415413U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 12294016745653004819U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 11U)) + 18269588932920281147U) + aPhaseAOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 46U)) + 5872406424994751026U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 51U)) + 7764434758831474129U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4804168969415573371U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 959601763507651280U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4647396592804833217U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9257644462479293048U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14332699366894494579U;
            aOrbiterE = RotL64((aOrbiterE * 8829304078930625541U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10487012596470786004U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 612729229562321440U;
            aOrbiterJ = RotL64((aOrbiterJ * 11380387280507726003U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 7845523921295625315U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12742115479740024747U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15578543510683986421U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10294667720904610944U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14369711143154904567U;
            aOrbiterB = RotL64((aOrbiterB * 13753005602288309379U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10918344717497681894U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 18136794828308636957U;
            aOrbiterA = RotL64((aOrbiterA * 17899418637978002409U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14378638206724886404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7077588188450008059U;
            aOrbiterF = RotL64((aOrbiterF * 485375960462924335U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8941870012851971932U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15242087859620352399U;
            aOrbiterI = RotL64((aOrbiterI * 4963002810455992839U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10395280254030875387U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6826595516076975980U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6198886240333178001U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 22U);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 54U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 19U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterE, 41U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterD, 30U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterJ, 23U)) + aPhaseAWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4911U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4911U)) & W_KEY1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4356U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4310U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 51U)) + (RotL64(aPrevious, 6U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aIngress, 53U)) + 17711946802293254150U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 47U)) + 16652362590489569378U;
            aOrbiterK = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 6972810344198183097U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aScatter, 42U)) + 13117100889782940546U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 13199305696782626591U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 13U)) + 992156184392760945U;
            aOrbiterG = (aWandererA + RotL64(aCross, 13U)) + 13791265442074543880U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 58U)) + 17057087245252294859U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 27U)) + 13444195995883541046U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6723678233676059420U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7913379431208430475U;
            aOrbiterK = RotL64((aOrbiterK * 2295062944289127123U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4481887195529300665U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11892724101424384078U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3468639499716604111U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 7700902083270424194U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1888001433557140271U;
            aOrbiterF = RotL64((aOrbiterF * 8975562955027025349U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14996753906788986929U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 939004845422123765U;
            aOrbiterJ = RotL64((aOrbiterJ * 2507090308972292313U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11922230289291941807U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15681187459741147199U;
            aOrbiterE = RotL64((aOrbiterE * 10124947739653819101U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 9119043713532718155U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8327697433992362166U;
            aOrbiterG = RotL64((aOrbiterG * 11157657162184304567U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13630755116592440359U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 771252613886022889U;
            aOrbiterH = RotL64((aOrbiterH * 2958918915223536519U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8524239721467527770U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17732617735422435572U;
            aOrbiterD = RotL64((aOrbiterD * 13992947983987668631U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5265753270696005619U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 14456128349522985053U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5406509991740849617U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + RotL64(aCarry, 21U)) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 42U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterK, 5U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterE, 54U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF + (((RotL64(aCross, 26U) + RotL64(aOrbiterF, 35U)) + aOrbiterI) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7564U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 6756U)) & W_KEY1], 52U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7479U)) & W_KEY1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6086U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7328U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 37U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererE + RotL64(aCross, 57U)) + 9220392006207660113U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 43U)) + 11305018553489132882U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 4U)) + RotL64(aCarry, 47U)) + 5860373868073513684U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 53U)) + 12319586170883987589U;
            aOrbiterI = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 14072333614354649021U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aIngress, 13U)) + 9332158529453194608U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 3860569321145958686U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 39U)) + 8119005668901240093U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 20U)) + 13918259792880333239U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6938856216758228704U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3960905839118710604U;
            aOrbiterG = RotL64((aOrbiterG * 16203746868670689793U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6043879193734253929U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 15691425268831319195U;
            aOrbiterH = RotL64((aOrbiterH * 7189195135654636271U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14912209933584715274U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16180183395910618923U;
            aOrbiterF = RotL64((aOrbiterF * 3942858974766467849U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4966642362507707776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6962226782462822861U;
            aOrbiterI = RotL64((aOrbiterI * 3647802407741095419U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12409120845092026295U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2302946450253872465U;
            aOrbiterB = RotL64((aOrbiterB * 7099576330777297911U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16118304388937163838U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15968419034359049422U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11736207775827080165U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17098982091525008231U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10298979200690822062U;
            aOrbiterK = RotL64((aOrbiterK * 12620028874653521945U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 552826643694256437U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11786560990790695378U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11190309640069208311U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13730399230389329793U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17614226859252305432U;
            aOrbiterC = RotL64((aOrbiterC * 2640019643570222977U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 56U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterK, 50U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterG, 5U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 19U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterH, 56U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 46U) + aOrbiterH) + RotL64(aOrbiterE, 39U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 40U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 8630U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadB[((aIndex + 9630U)) & W_KEY1], 12U));
            aIngress ^= (RotL64(mSource[((aIndex + 9582U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 9090U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9488U)) & W_KEY1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 10189U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 5U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererA + RotL64(aPrevious, 13U)) + 11177787645248006236U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 29U)) + 3808340254579817169U) + aPhaseBOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aIngress, 43U)) + 828030667598518279U;
            aOrbiterE = (aWandererF + RotL64(aCross, 54U)) + 16177835921238398371U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 23U)) + 5518747735458708741U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 17346319082399995165U;
            aOrbiterD = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 6397156921893030937U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 37U)) + 15559381654710713582U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 13U)) + 940404446491415088U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8047166032048732645U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4688468645859470491U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14383536431614496369U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3710878044770337260U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 116343189456629220U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5637725064169289339U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 883908030159391659U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18058691521694880482U;
            aOrbiterE = RotL64((aOrbiterE * 3132200449123497619U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17521015077103586117U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 3668332225435714918U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12658899101297839881U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12229480388278883300U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16206524049491531816U;
            aOrbiterI = RotL64((aOrbiterI * 11122340196620859805U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5743265849441077466U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2812293020719282236U;
            aOrbiterF = RotL64((aOrbiterF * 8903956475200417109U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13718364781538837074U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 861529717259766236U;
            aOrbiterK = RotL64((aOrbiterK * 17019744777211266685U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4862687502126693872U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7722024283321020761U;
            aOrbiterA = RotL64((aOrbiterA * 18086944039541060829U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8205803118233399853U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 15130160926615050422U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1454552751453996765U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 14U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterK, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 23U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterE, 10U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 13050U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 12063U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12225U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 13522U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12493U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11567U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13540U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 3U)) + 13174219512651137892U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 24U)) + 2715455762789269341U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aScatter, 13U)) + 1338018183235594313U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 16566866551729552930U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 6901845297307236726U;
            aOrbiterC = (aWandererH + RotL64(aCross, 28U)) + 2476078302049201718U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 53U)) + 15531109473927052260U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 4087849380858572351U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 47U)) + 5167830630098599644U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 7275995452428627217U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14794340370010024117U;
            aOrbiterB = RotL64((aOrbiterB * 8779497557416568379U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8509217403041662849U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 2321522025240806996U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 113568101672878697U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5676672952755594051U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2304681269233504384U;
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8383399721062437300U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13181984036942227666U;
            aOrbiterJ = RotL64((aOrbiterJ * 1648761328771932069U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13602604532551684210U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 12725687663616352843U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4684699861686199753U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5831790822416009806U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4535048543735457407U;
            aOrbiterH = RotL64((aOrbiterH * 12076777878870257053U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10617608605149381858U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5244225377862618630U;
            aOrbiterE = RotL64((aOrbiterE * 15307177251167023999U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18229989093139888456U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9728120630096192811U;
            aOrbiterA = RotL64((aOrbiterA * 16052574428163231023U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1312233443099767304U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8043115602160128619U;
            aOrbiterK = RotL64((aOrbiterK * 9365756845731616963U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 42U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterD, 43U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 10U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterE, 30U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterC, 39U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 13U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15839U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13810U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13820U)) & W_KEY1], 54U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15618U)) & W_KEY1], 19U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15383U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14364U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15552U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 58U)) + RotL64(aCarry, 21U)) + 11410829607777684449U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 47U)) + 7502698839700975347U) + aPhaseBOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 43U)) + 13267685058252106173U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 39U)) + 238242706996630625U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 57U)) + 8184695499511454281U;
            aOrbiterE = (aWandererB + RotL64(aCross, 3U)) + 12767823220461985403U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 23U)) + 12293198423143850330U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 37U)) + 11149495229952495939U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 18U)) + 7556992689338382800U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 3431338808774134649U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16863099140844995099U;
            aOrbiterA = RotL64((aOrbiterA * 752376661101787919U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17872458049880677604U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16760153457252546974U;
            aOrbiterJ = RotL64((aOrbiterJ * 11225037229069712805U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3115544493537438408U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4359882942759752958U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 561477566995575801U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13387113067202396536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12955690074544490161U;
            aOrbiterI = RotL64((aOrbiterI * 12449941770827974511U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15614054443728226807U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1939441328066616114U;
            aOrbiterC = RotL64((aOrbiterC * 4484917074808974359U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4599016263007782537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9962305629016158048U;
            aOrbiterB = RotL64((aOrbiterB * 1496184427500037279U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8428467674122750557U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3938884087806393439U;
            aOrbiterK = RotL64((aOrbiterK * 12810531094050481761U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 6018636830758044658U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1510372000641305416U;
            aOrbiterD = RotL64((aOrbiterD * 9002834928626918247U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17592782466215337843U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8119921507606870360U;
            aOrbiterG = RotL64((aOrbiterG * 1299795061644535485U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterG, 18U));
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + aPhaseBWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterE, 36U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18309U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 18274U)) & W_KEY1], 3U));
            aIngress ^= (RotL64(mSource[((aIndex + 17804U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 18203U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16478U)) & W_KEY1], 11U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17786U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18630U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 12U)) + 16124889768301047791U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 29U)) + 11912338587186717280U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 39U)) + 8594012868813114354U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 18281043566156682815U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 19U)) + 16853106130200942302U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 35U)) + 2611212958619673086U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 3U)) + 18039472325066855180U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 43U)) + 14495785571345122046U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 47U)) + 4556063793412832418U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14896419970271244358U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 880028529183500036U;
            aOrbiterC = RotL64((aOrbiterC * 14228281807461251361U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 2379557167489415783U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11854373946064529806U;
            aOrbiterJ = RotL64((aOrbiterJ * 150755294320438887U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1487252775956449964U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12777924204511625545U;
            aOrbiterB = RotL64((aOrbiterB * 1366019527386994789U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15998631485222477969U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8864212892296191613U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 579242788050369815U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17069347835763226743U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7443008171694679791U;
            aOrbiterF = RotL64((aOrbiterF * 748894368884566607U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17334256152350782002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8986626119086556393U;
            aOrbiterE = RotL64((aOrbiterE * 2258172145924120235U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8528180968228358674U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12702290928064582589U;
            aOrbiterI = RotL64((aOrbiterI * 15673603224146737631U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7742438100860023610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3729687240959702198U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3756794766163746783U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 426129097367382096U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16782175452274911213U;
            aOrbiterD = RotL64((aOrbiterD * 1041477289638333659U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 56U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 39U)) + aOrbiterB) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterG, 18U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 51U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aCross, 10U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 35U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 22U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 11U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20977U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 21063U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21667U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 20039U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20559U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21191U)) & W_KEY1], 13U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21740U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 19427U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aIngress, 23U)) + 5960680319644404115U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 10U)) + 16050752633567034185U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 8447503223226854741U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 14176813813397917591U) + aPhaseCOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 51U)) + 10534915376130006644U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 6866224454375302514U;
            aOrbiterE = (aWandererA + RotL64(aCross, 19U)) + 16506374165041008396U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 4U)) + 7167814023968794098U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aIngress, 39U)) + 13870852197416596664U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 18064038854848993105U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9869630811507771691U;
            aOrbiterH = RotL64((aOrbiterH * 13723164383800461387U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 863613100452759380U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16597969741225436529U;
            aOrbiterG = RotL64((aOrbiterG * 2680793528887208903U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6575347108051310653U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17062262265485019063U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7601045488473620019U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7193399224636409133U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14146747818810433849U;
            aOrbiterJ = RotL64((aOrbiterJ * 5273185769989530041U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9441449106442431427U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 4303295336545399503U;
            aOrbiterE = RotL64((aOrbiterE * 8829695296836242587U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12604760768543193458U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15779327512379787715U;
            aOrbiterF = RotL64((aOrbiterF * 14000905201441272597U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15553000781122708728U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17162740616060079717U;
            aOrbiterB = RotL64((aOrbiterB * 9458662233556750239U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1032374679817715156U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16413393156165548232U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 549659738811935015U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14056855000013992045U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7399202019042538829U;
            aOrbiterK = RotL64((aOrbiterK * 6103508549612077695U), 23U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 56U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 58U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 39U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA + (((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 43U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 6U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 18U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24302U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 22102U)) & W_KEY1], 22U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 21868U)) & W_KEY1], 51U) ^ RotL64(aFireLaneC[((aIndex + 24080U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22305U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23596U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24226U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 22189U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 44U)) + (RotL64(aCross, 57U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 12690502671561165478U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 24U)) + RotL64(aCarry, 19U)) + 17519943923428102801U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 10705515807975331385U;
            aOrbiterI = (aWandererB + RotL64(aCross, 13U)) + 16586447272278538179U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 43U)) + 8006560996840971798U) + aPhaseCOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 29U)) + 12928600185788857701U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 5U)) + 14240723153798267172U) + aPhaseCOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 20U)) + 8636219177994872072U;
            aOrbiterK = (aWandererD + RotL64(aCross, 47U)) + 7586790235186467512U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1103807034179512424U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7547526530239498693U;
            aOrbiterH = RotL64((aOrbiterH * 3360295583636013509U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8380239679344786397U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5690809173787433519U;
            aOrbiterF = RotL64((aOrbiterF * 5354724308093372953U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8390902801141804609U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3507306189192059486U;
            aOrbiterC = RotL64((aOrbiterC * 18336280496510253103U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 6190745292098482871U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8065418693975056902U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6414621418430102589U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12111755051718111803U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7605877769709909297U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17525248694315944599U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5969794501112646237U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5127559299360591476U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4521563633438853069U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10593847754747739786U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4401750688524310121U;
            aOrbiterB = RotL64((aOrbiterB * 14265829318976633707U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6927893132508779499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4874009978647014479U;
            aOrbiterA = RotL64((aOrbiterA * 13340466017023540755U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13146693487138744677U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3298472134223595298U;
            aOrbiterI = RotL64((aOrbiterI * 2145005258008477281U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 14U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterI, 57U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterI, 10U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterC, 23U));
            aWandererD = aWandererD + ((RotL64(aIngress, 12U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 46U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25161U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 26944U)) & W_KEY1], 58U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24861U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26875U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24607U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26723U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25907U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneB[((aIndex + 25744U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 50U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 52U)) + 12222235191147985484U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 23U)) + 16367317014523328414U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 3511378091284703789U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 29U)) + 15247492830966725949U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 47U)) + 7745995913390407897U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 6463593307540108810U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 1101669311005268630U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 42U)) + RotL64(aCarry, 35U)) + 12988052764067518580U;
            aOrbiterI = (aWandererK + RotL64(aCross, 57U)) + 17717179747434679772U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11662190906682400416U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6563014073547628748U;
            aOrbiterH = RotL64((aOrbiterH * 16967910471722117761U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13099094932059419219U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16342730862261868847U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10988124108686164829U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16855346813127524624U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6570063128502306944U;
            aOrbiterF = RotL64((aOrbiterF * 4571570049463124831U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11328352033809240501U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11640986648833160901U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2895830492089678919U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2675226158571501666U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17700531248266458165U;
            aOrbiterE = RotL64((aOrbiterE * 2231403813970188657U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7729597396731910874U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15172374484412053756U;
            aOrbiterD = RotL64((aOrbiterD * 149009041406406517U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9178769489257842683U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9020154972097834926U;
            aOrbiterB = RotL64((aOrbiterB * 8910504667566521429U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 1317403761217790562U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 17151528554929201571U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3735945655450625203U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11621882033959669977U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10289504450815075623U;
            aOrbiterG = RotL64((aOrbiterG * 13365982786836243195U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aPrevious, 28U) + aOrbiterC) + RotL64(aOrbiterB, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 18U)) + aOrbiterB) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterG, 41U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 47U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 27U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 54U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29619U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneD[((aIndex + 27543U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29133U)) & W_KEY1], 52U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29294U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27882U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27692U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28860U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 29690U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 5U)) + (RotL64(aCarry, 22U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererJ + RotL64(aIngress, 58U)) + 3199575576585871314U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 47U)) + 2533378188975571824U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 6819782112558312658U) + aPhaseDOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 21U)) + 12690060987724798497U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 7088375139715629606U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererH + RotL64(aScatter, 5U)) + 17785618677423695666U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 1714999280296491277U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 12U)) + 17611338506932491624U;
            aOrbiterA = (aWandererD + RotL64(aCross, 35U)) + 6475727359297421201U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2347744591204119530U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2739317903351401068U;
            aOrbiterB = RotL64((aOrbiterB * 15435029315209475631U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8663535261373274338U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8205245127823536479U;
            aOrbiterH = RotL64((aOrbiterH * 13857005110466856439U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8916510616749754516U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3944805940148512932U;
            aOrbiterJ = RotL64((aOrbiterJ * 18082271583211389701U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14094751253118853302U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14094299829196076311U;
            aOrbiterK = RotL64((aOrbiterK * 6370012560657108493U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3940673811518673802U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3015106523254484839U;
            aOrbiterF = RotL64((aOrbiterF * 9655401190755573379U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 15404103131982599922U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1828655763233900875U;
            aOrbiterE = RotL64((aOrbiterE * 13024358077740310049U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1236981890899916502U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18208975564570342697U;
            aOrbiterC = RotL64((aOrbiterC * 4577109989465876801U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17882273895471449661U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16196010765612713713U;
            aOrbiterA = RotL64((aOrbiterA * 15624856645134182005U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14639250100311162559U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9139027997336903273U;
            aOrbiterI = RotL64((aOrbiterI * 1853126389565574293U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 6U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 27U)) + aPhaseDWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterB, 35U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterC, 43U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 20U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 39U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30064U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 31707U)) & W_KEY1], 28U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32356U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30111U)) & S_BLOCK1], 23U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31932U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31675U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 58U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 2672739400294801233U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 13U)) + 8475624545015101850U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 27U)) + 1252755112289831257U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 23U)) + 7938039507649183387U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 4U)) + RotL64(aCarry, 37U)) + 8167413146948861022U) + aPhaseDOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aScatter, 57U)) + 17712313989694374353U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 47U)) + 7637042279892596975U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 15770412950033467341U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 40U)) + 3951812021898608685U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 8656983621098246507U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17943342344730687317U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16495519451034883813U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3087677463651608668U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16493240011924342788U;
            aOrbiterD = RotL64((aOrbiterD * 16898479041530771871U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7750923317452683057U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2185924841611106546U;
            aOrbiterH = RotL64((aOrbiterH * 708072658250726381U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 14676868738946722416U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6849098251696302393U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2599806275837778069U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17817755047153606419U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9900465270314068757U;
            aOrbiterB = RotL64((aOrbiterB * 9267925873983176685U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11380000891112113701U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15930503831156546113U;
            aOrbiterF = RotL64((aOrbiterF * 14450535035065393845U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5439183530402949780U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3731802052051181843U;
            aOrbiterA = RotL64((aOrbiterA * 7739775058947333169U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14432344583247783600U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16192098795467501636U;
            aOrbiterE = RotL64((aOrbiterE * 6285466374319549047U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1523272672673940290U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7462092373525113574U;
            aOrbiterJ = RotL64((aOrbiterJ * 15067751170235540679U), 53U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 46U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 18U) + RotL64(aOrbiterF, 10U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterI) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterD, 14U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI + (((RotL64(aCross, 38U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 23U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2991U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 4948U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1519U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5396U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1110U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 30U)) + (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererK + RotL64(aScatter, 51U)) + 14823268998003220191U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 37U)) + 15295237288788213847U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 27U)) + 16434853402001133899U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 7555911304407871631U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 14977248264994834620U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 26U)) + 9707764144919392380U) + aPhaseEOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 3U)) + 1277304385464681529U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3089786220465849395U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3700503853358695085U;
            aOrbiterH = RotL64((aOrbiterH * 2079089949442685421U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3240054112993517371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16897532076915366859U;
            aOrbiterB = RotL64((aOrbiterB * 4120874717534309035U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18167359289798364307U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8870819278575769863U;
            aOrbiterE = RotL64((aOrbiterE * 9334066154398059075U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15363069206212330251U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14858164441499725158U;
            aOrbiterJ = RotL64((aOrbiterJ * 14931933411393847915U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5357144808788707522U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2910681277417754860U;
            aOrbiterF = RotL64((aOrbiterF * 13170868582159347059U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 9824408699018165151U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 368370224788793300U;
            aOrbiterK = RotL64((aOrbiterK * 14358982366258729959U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 7095398304588825115U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11418879758164313554U;
            aOrbiterA = RotL64((aOrbiterA * 5983520332639771791U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 20U)) + aOrbiterE) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aCross, 20U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 7169U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 10768U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 9004U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9987U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 8820U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 7893287783892523139U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 53U)) + 10257331997383491153U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 27U)) + 14562226733652231753U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 60U)) + 14320342577110737851U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 35U)) + 9816717579822880756U) + aPhaseEOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 41U)) + 9558926960095881953U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 41U)) + 9230371862654338324U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 6414274291252913420U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13868546184398350849U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1547986864837497409U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16940736952569949038U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2866957764814864371U;
            aOrbiterJ = RotL64((aOrbiterJ * 3554702178644797003U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7916721976073979724U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1602444214978842275U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11072503711308122385U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9529061385251008037U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8402775110887376588U;
            aOrbiterC = RotL64((aOrbiterC * 13980225144628227381U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15003592180290390713U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14195681406520825751U;
            aOrbiterG = RotL64((aOrbiterG * 11455000833788877217U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3263577002367714202U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12019422062655581928U;
            aOrbiterI = RotL64((aOrbiterI * 5002313835338447799U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8508638054582582917U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 6536618106353552880U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6233964121117511885U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterB, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK + ((((RotL64(aCross, 46U) + RotL64(aOrbiterF, 36U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15802U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 16295U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 11340U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12860U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15360U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 14170U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 42U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 21U)) + 17264605017518259932U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 15209184354580778643U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 57U)) + 3299527965014731384U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 42U)) + 16293096431816127821U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 41U)) + 11031983436878828337U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 9188018632448236358U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 11U)) + 13420816400363406556U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2485063384097917101U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3089135816938128264U;
            aOrbiterG = RotL64((aOrbiterG * 8813152992957361153U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10730544971770435788U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10431767565618874806U;
            aOrbiterC = RotL64((aOrbiterC * 4723078464590561545U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14883796491656899074U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 13465877783538483706U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14311686051108108503U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13322163435314643713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4950101626975919939U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2596253994220103666U;
            aOrbiterK = RotL64((aOrbiterK * 7181706961838582889U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17961706029559914243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10321902557977495175U;
            aOrbiterD = RotL64((aOrbiterD * 16189559888625084711U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18146616411403012772U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8414050129421955787U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14879448948196182863U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 21U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 4U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterA, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21765U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneC[((aIndex + 16757U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 19773U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 18887U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19137U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17320U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 57U)) + 11480359716598965890U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 6U)) + RotL64(aCarry, 27U)) + 15431182525482873419U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 11360504974812776707U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 9292576416573382769U;
            aOrbiterH = (aWandererI + RotL64(aCross, 51U)) + 1549257414531028975U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 35U)) + 5347769463033129317U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 21U)) + 17019199177478377234U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16558106007323125094U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3976182233825939422U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4392162052317572289U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2889047161195954395U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2241831345026962605U;
            aOrbiterB = RotL64((aOrbiterB * 5757458560979927857U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12850802412140579294U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13541744735436450160U;
            aOrbiterF = RotL64((aOrbiterF * 906089290000537439U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2085863085516538212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 2969034221711544086U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7768528124408400403U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6482666944512391472U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16969153556875844613U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9483462388353216219U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5161314086757363678U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7150282484670673211U;
            aOrbiterG = RotL64((aOrbiterG * 8522427002337918663U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 5465304381272305847U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2344610773390354017U;
            aOrbiterE = RotL64((aOrbiterE * 17010258514288089191U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterE, 48U)) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterK, 29U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterC, 57U)) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 52U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererK, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22115U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 25983U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25439U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24195U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22879U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 26831U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 50U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererB + RotL64(aCross, 11U)) + 2168513956284366370U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + 10290361969974613111U) + aPhaseEOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 15673836275828498050U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 29U)) + 16600540024145812236U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 38U)) + RotL64(aCarry, 35U)) + 9428052101528111892U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aPrevious, 19U)) + 12763657928312763377U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 10751286982008662485U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1708230173038057979U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4011389705422783816U;
            aOrbiterI = RotL64((aOrbiterI * 11692237130784795961U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 11704428328093077714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2055336619674699284U;
            aOrbiterK = RotL64((aOrbiterK * 6374289210096410907U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1870865272102705804U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3574214263751923179U;
            aOrbiterG = RotL64((aOrbiterG * 13132083406834413563U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 984611970726966186U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15207945449947643672U;
            aOrbiterB = RotL64((aOrbiterB * 9539470161576639981U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 4181398506373973169U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15222345431506025949U;
            aOrbiterD = RotL64((aOrbiterD * 6925143692628659467U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15023513452326240962U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14965669361708810699U;
            aOrbiterH = RotL64((aOrbiterH * 587008860996713147U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7985755518735406360U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 225592097619240187U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2313509354133400439U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 50U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 46U)) + aOrbiterF) + aPhaseEWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 27U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterF, 21U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29649U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 30699U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30418U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27351U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30033U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30821U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 785861751704720606U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 35U)) + 15968088718435606299U) + aPhaseEOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 1393976526590347151U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 41U)) + 17240750947292745884U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + 4921576136163183137U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 20U)) + RotL64(aCarry, 3U)) + 3334047873553153032U;
            aOrbiterC = (aWandererH + RotL64(aCross, 29U)) + 15086509978458408698U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 892391205397581998U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2965686403183767521U;
            aOrbiterH = RotL64((aOrbiterH * 709160942482770225U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14632215393655706170U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15740589515342377322U;
            aOrbiterJ = RotL64((aOrbiterJ * 15677716942904794913U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11131164813943086445U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6988080581278900960U;
            aOrbiterF = RotL64((aOrbiterF * 6412189142344044255U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16021254613117657178U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6183615599897921154U;
            aOrbiterC = RotL64((aOrbiterC * 9976411093264211033U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12533992547026652747U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3104325358982904219U;
            aOrbiterG = RotL64((aOrbiterG * 14977348108778147265U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3878525937957474644U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2120435259884368445U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15964718652193073177U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14928658302694194856U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9121310461310309348U;
            aOrbiterI = RotL64((aOrbiterI * 17304439784647477491U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 29U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererH = aWandererH + (((RotL64(aIngress, 52U) + aOrbiterC) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterG, 43U)) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aInvestLaneA, aExpandLaneA, aSnowLaneB, aExpandLaneC, aWorkLaneA, aInvestLaneB, aWorkLaneB, aInvestLaneD, aWorkLaneC, aExpandLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1701U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((aIndex + 3562U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2018U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3583U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 3543U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 4848U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 43U) ^ RotL64(aIngress, 6U)) + (RotL64(aPrevious, 21U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererG + RotL64(aScatter, 39U)) + 8767379393098711499U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 5U)) + 7168159491580816433U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 9879279829061883406U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 43U)) + 10537167136053399303U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 23U)) + 2839070018069188936U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 29U)) + 13844278063968429732U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 19U)) + 11278946626186474646U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 53U)) + 11798425216660557799U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 51U)) + 7618446090703335192U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 60U)) + 695423597006983660U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 3U)) + 14344728202803488813U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11656100506575697086U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10384358779985773937U;
            aOrbiterG = RotL64((aOrbiterG * 247494692039140973U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17585001605131977341U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9964478171465522911U;
            aOrbiterK = RotL64((aOrbiterK * 13484044854790175315U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2710943171829692624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17809072853457153057U;
            aOrbiterJ = RotL64((aOrbiterJ * 16341884203303271365U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 12814092033910687774U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 1743186323268668740U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11150822630624332557U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10750472346626754704U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15925901217078035356U;
            aOrbiterE = RotL64((aOrbiterE * 9276504171291801637U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2569102106359362359U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8868261301410769739U;
            aOrbiterA = RotL64((aOrbiterA * 3662495603133918101U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2143691008373582476U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10606616796243205921U;
            aOrbiterB = RotL64((aOrbiterB * 15794414817813485643U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16258070651850746855U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11720192793689633315U;
            aOrbiterI = RotL64((aOrbiterI * 14475623219460678021U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8230871037292355675U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16898650748046368353U;
            aOrbiterF = RotL64((aOrbiterF * 7368697435476300255U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9071122174426904737U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 4506737259011736474U;
            aOrbiterH = RotL64((aOrbiterH * 11903039808814842447U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4545409671845718259U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8767379393098711499U;
            aOrbiterC = RotL64((aOrbiterC * 1210632171306946669U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 21U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 37U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterB, 30U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 27U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 14U) + RotL64(aOrbiterH, 39U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + RotL64(aOrbiterD, 18U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 5596U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((aIndex + 6224U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9461U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneA[((aIndex + 7623U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8384U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10460U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6502U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 36U) + RotL64(aPrevious, 57U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererB + RotL64(aIngress, 29U)) + 13174219512651137892U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 2715455762789269341U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 13U)) + 1338018183235594313U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 60U)) + 16566866551729552930U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 37U)) + 6901845297307236726U;
            aOrbiterB = (aWandererD + RotL64(aCross, 19U)) + 2476078302049201718U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 15531109473927052260U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 39U)) + 4087849380858572351U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 11U)) + 5167830630098599644U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 54U)) + 7275995452428627217U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 37U)) + 14794340370010024117U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8509217403041662849U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2321522025240806996U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 113568101672878697U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5676672952755594051U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2304681269233504384U;
            aOrbiterB = RotL64((aOrbiterB * 15731441084605554497U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8383399721062437300U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13181984036942227666U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1648761328771932069U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13602604532551684210U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12725687663616352843U;
            aOrbiterE = RotL64((aOrbiterE * 4684699861686199753U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5831790822416009806U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4535048543735457407U;
            aOrbiterK = RotL64((aOrbiterK * 12076777878870257053U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10617608605149381858U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5244225377862618630U;
            aOrbiterA = RotL64((aOrbiterA * 15307177251167023999U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 18229989093139888456U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9728120630096192811U;
            aOrbiterG = RotL64((aOrbiterG * 16052574428163231023U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1312233443099767304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8043115602160128619U;
            aOrbiterJ = RotL64((aOrbiterJ * 9365756845731616963U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4679339316686216023U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 211799535650113758U;
            aOrbiterC = RotL64((aOrbiterC * 1478368466990144107U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13307123762743628190U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7093673238704478497U;
            aOrbiterD = RotL64((aOrbiterD * 13273906568866802561U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16396459072175632290U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13174219512651137892U;
            aOrbiterH = RotL64((aOrbiterH * 7581008806810219369U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 44U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterI, 12U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + RotL64(aOrbiterC, 29U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 28U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterF, 10U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15078U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 11864U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 13144U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11581U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 14438U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aCross, 44U)) + 17470880031634374199U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 757565846006937746U) + aPhaseFOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 11U)) + 9419282475801345674U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 47U)) + 2014248014107898196U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 53U)) + 15113928519446490441U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 37U)) + 7346126964886259935U;
            aOrbiterB = ((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 5594123113093162359U;
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 5659237263369402005U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 21U)) + 11565709683423969703U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 35U)) + 16782863743534856287U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 51U)) + 13499100900072115907U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11414447651044205242U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7545993795121430538U;
            aOrbiterF = RotL64((aOrbiterF * 10758488381206257261U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11778229237616454988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2544793391976514665U;
            aOrbiterK = RotL64((aOrbiterK * 4021060413798523299U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9972156716619459164U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17651030383827445664U;
            aOrbiterG = RotL64((aOrbiterG * 6742914240706775487U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 17439147296849134543U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10021926927948343656U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18139540407315440909U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9309867875882669289U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14951424455944346337U;
            aOrbiterE = RotL64((aOrbiterE * 10569523948169951309U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2166343974068770659U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11386993629011562026U;
            aOrbiterH = RotL64((aOrbiterH * 3091639433512536097U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5747849744680120960U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 4019290369160113026U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5567515306039646735U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3820540009554769592U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8210747198363020939U;
            aOrbiterC = RotL64((aOrbiterC * 16215133106542452509U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3006494852696036003U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2736305345451919450U;
            aOrbiterD = RotL64((aOrbiterD * 11993452696344358247U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6148431711118275178U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6986633012691940738U;
            aOrbiterJ = RotL64((aOrbiterJ * 15672039482523804893U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7837859154831245165U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17470880031634374199U;
            aOrbiterB = RotL64((aOrbiterB * 2153299273348512243U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 46U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 46U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 39U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aCross, 46U) + RotL64(aOrbiterI, 48U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 37U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 58U) + aOrbiterE) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 18193U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 17434U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16705U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19659U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20768U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 37U)) + 1557680213571812384U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 41U)) + 7387349725778021121U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 56U)) + 15379264067601586976U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 3730195724576043708U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 9637070085323827066U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 19U)) + 1170865717363676184U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aScatter, 53U)) + 2750833653175252030U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 39U)) + 15118992811225568305U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aPrevious, 3U)) + 4974092922102988451U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 29U)) + 10625719096296719514U;
            aOrbiterK = (aWandererI + RotL64(aCross, 14U)) + 855167122475471865U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11322911068958340262U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4334591909425429835U;
            aOrbiterE = RotL64((aOrbiterE * 10059025861172038183U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14263701737208936392U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 678723206735649084U;
            aOrbiterB = RotL64((aOrbiterB * 10823239851733632227U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15652053114252065230U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1705225940224061401U;
            aOrbiterJ = RotL64((aOrbiterJ * 3626023093533713579U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6826394665732900206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11902946775066981141U;
            aOrbiterG = RotL64((aOrbiterG * 18300629262162694137U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9802212958998591310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 14001358545610206524U;
            aOrbiterA = RotL64((aOrbiterA * 13172645840788327099U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4299184726135884309U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7288757011999872416U;
            aOrbiterF = RotL64((aOrbiterF * 16806027820468277393U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 233801262480580205U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14208660347238680268U;
            aOrbiterC = RotL64((aOrbiterC * 6299693448313154603U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9217797359740446104U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18165073197136050838U;
            aOrbiterI = RotL64((aOrbiterI * 11677479094709512887U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9101905235436427482U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2884224555227870272U;
            aOrbiterK = RotL64((aOrbiterK * 12085235281782370391U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13118509728421714433U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1385390888603164704U;
            aOrbiterH = RotL64((aOrbiterH * 6927424835779289199U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9621084561183039538U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1557680213571812384U;
            aOrbiterD = RotL64((aOrbiterD * 3202327770291862207U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 34U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterC, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterI, 53U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterJ, 58U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 21U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 43U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 23U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterA, 28U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 35U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 51U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22878U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneB[((aIndex + 27160U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 24775U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26917U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25181U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 19U)) + 1042610313571524121U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 37U)) + 3505725321008825582U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 43U)) + 12584654563843782991U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 21U)) + 6645399144515770935U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 11U)) + 3608978423753715584U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 29U)) + 8089198857670370983U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 54U)) + 15207251813516399879U;
            aOrbiterH = (aWandererD + RotL64(aCross, 23U)) + 9579268660105824516U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 43U)) + 16055044469473802812U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 583811872609805949U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 58U)) + 7027491967970873942U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 18256061823189677508U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 12708429127816136937U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12593886633108075321U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12169216645156306078U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12694325407567795065U;
            aOrbiterF = RotL64((aOrbiterF * 3711789483877261899U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16109994660203297503U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4234704064165718913U;
            aOrbiterH = RotL64((aOrbiterH * 730085881474787681U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14119541943554602878U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8777769004811352951U;
            aOrbiterK = RotL64((aOrbiterK * 2556957257736134223U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15642663488392549609U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11594468530833278624U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6639306656361601143U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7365350535791499871U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5965170981970155956U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1898702752753066851U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9115232101451815522U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9433983580038990072U;
            aOrbiterJ = RotL64((aOrbiterJ * 1951249217843992179U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8810565477444156140U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12081286530401844859U;
            aOrbiterB = RotL64((aOrbiterB * 1991383259486140229U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7498045374283306625U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13095973566401200720U;
            aOrbiterI = RotL64((aOrbiterI * 2657451581036351987U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18205793828042507364U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3339020890428651569U;
            aOrbiterA = RotL64((aOrbiterA * 10195916881103252701U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16957913958369950483U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1042610313571524121U;
            aOrbiterC = RotL64((aOrbiterC * 11206619213970727629U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterI, 26U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterF, 5U));
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 3U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 60U)) + aOrbiterF);
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 41U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 46U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererH, 26U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aExpandLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29935U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 29026U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31314U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28321U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((aIndex + 31391U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 39U)) + 11410829607777684449U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 43U)) + 7502698839700975347U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 41U)) + 13267685058252106173U;
            aOrbiterE = (aWandererI + RotL64(aCross, 22U)) + 238242706996630625U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 29U)) + 8184695499511454281U;
            aOrbiterB = (aWandererF + RotL64(aCross, 5U)) + 12767823220461985403U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 53U)) + 12293198423143850330U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 11149495229952495939U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 11U)) + 7556992689338382800U) + aPhaseFOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aScatter, 36U)) + RotL64(aCarry, 27U)) + 3431338808774134649U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 16863099140844995099U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17872458049880677604U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16760153457252546974U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11225037229069712805U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3115544493537438408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4359882942759752958U;
            aOrbiterJ = RotL64((aOrbiterJ * 561477566995575801U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13387113067202396536U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12955690074544490161U;
            aOrbiterK = RotL64((aOrbiterK * 12449941770827974511U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15614054443728226807U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1939441328066616114U;
            aOrbiterF = RotL64((aOrbiterF * 4484917074808974359U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4599016263007782537U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9962305629016158048U;
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8428467674122750557U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 3938884087806393439U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12810531094050481761U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6018636830758044658U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1510372000641305416U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9002834928626918247U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 17592782466215337843U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8119921507606870360U;
            aOrbiterG = RotL64((aOrbiterG * 1299795061644535485U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8753237702359236964U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12389957327067768090U;
            aOrbiterI = RotL64((aOrbiterI * 4586786761936601607U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17791633199762408683U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11606494383812053915U;
            aOrbiterE = RotL64((aOrbiterE * 13041480602055778521U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4418614662439151979U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11410829607777684449U;
            aOrbiterH = RotL64((aOrbiterH * 3342270212301058781U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 4U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterH, 37U));
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterB, 26U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 19U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 12U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterI, 5U));
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6289U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 4386U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4883U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 163U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4602U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5028U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererI + RotL64(aScatter, 54U)) + RotL64(aCarry, 13U)) + 3248574644570178787U) + aPhaseGOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 4506961512959200024U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 8423739774540738590U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 3U)) + 6593975869641735337U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 35U)) + 16441716090557369103U) + aPhaseGOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 7936601450453207914U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13333752583560167065U;
            aOrbiterE = RotL64((aOrbiterE * 5389149472324384311U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8013703284795432973U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2349852779887439236U;
            aOrbiterI = RotL64((aOrbiterI * 2422888500648100783U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5318539364763284138U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11450957608502944376U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1957880366707810635U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9058992558327552687U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 632095686920230926U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12460364388358520799U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14734218428913777098U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 16344357661370784442U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15049472842002138369U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 37U);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aPhaseGWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterH, 38U));
            aWandererE = aWandererE + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12386U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 15444U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12197U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11488U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14187U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11772U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 14157904117287696136U) + aPhaseGOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 7369512677371640676U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 8411250745902073798U) + aPhaseGOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 20U)) + 5002041814539710275U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 11U)) + 9538041410816283124U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5210700103927513061U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7600709399101287982U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6777896926889560889U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2366369466696580499U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5544575244203019109U;
            aOrbiterB = RotL64((aOrbiterB * 16231219246786333057U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 8710073749110329779U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15998211310115361630U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15275657696897688955U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15354357553877376422U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10657523549259276169U;
            aOrbiterC = RotL64((aOrbiterC * 13695239532898311073U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10405750198355464768U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3465819693133515142U;
            aOrbiterF = RotL64((aOrbiterF * 14678343718277562799U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 35U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 23U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 54U) + aOrbiterC) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19291U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((aIndex + 17312U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21395U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19636U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24463U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21981U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCross, 57U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 51U)) + 9471546960258473684U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 18050235435948942244U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 3005107102671544641U;
            aOrbiterB = (aWandererD + RotL64(aCross, 48U)) + 17898396434573801850U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 19U)) + 15071602525497771648U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 5780119462702672108U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13301326224151025687U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2868878978993219351U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18129323022260575961U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1199228670638790709U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1780426336211781025U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 1839199978088021020U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4999517042246790165U;
            aOrbiterB = RotL64((aOrbiterB * 4585813675677234577U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 8788607633376516299U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15143903839930468749U;
            aOrbiterI = RotL64((aOrbiterI * 12735914889325422675U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16674732686428431869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15908873150953195581U;
            aOrbiterD = RotL64((aOrbiterD * 18049755517524334107U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterE, 41U)) + aPhaseGWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 54U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 18U)) + aOrbiterE) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30594U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 25514U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30901U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26007U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27793U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 24988U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 48U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 12262991801139086177U) + aPhaseGOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 12U)) + 7963038771924890197U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 15540520327933568896U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 51U)) + 8745565892055020722U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 16619329199683755286U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10865705026433867260U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2743368697984518059U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2989232417816919375U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5556006271515473135U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5355833281353498588U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4190140212757841511U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8313616108963479829U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16657121016801866434U;
            aOrbiterC = RotL64((aOrbiterC * 331533349428472477U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16532226425013000833U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5800465874932467232U;
            aOrbiterA = RotL64((aOrbiterA * 5966395771690704577U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17882948163883121328U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15029375310296563175U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17021415832288477713U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterI, 37U)) + aPhaseGWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 23U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 46U)) + aOrbiterI) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterK, 3U));
            aWandererG = aWandererG + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5288U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((aIndex + 3900U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3516U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3460U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4832U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7496U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 21U)) ^ (RotL64(aIngress, 57U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aScatter, 29U)) + 4204560462077827182U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 6572370199668594039U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 5U)) + 15958999876732622825U;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 56U)) + RotL64(aCarry, 27U)) + 9969349486879280377U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 37U)) + 15450238998293956181U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9128619863683138259U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5691270563628979565U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2170424734274640859U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5901029710568933106U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10442738941988588834U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7386621444831603817U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3508116020325721993U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13221917083569767259U;
            aOrbiterE = RotL64((aOrbiterE * 6845108555710135357U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11627915460377128176U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17858261365514253433U;
            aOrbiterJ = RotL64((aOrbiterJ * 7535577636975884641U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4294837988806295989U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11242915481585070249U;
            aOrbiterG = RotL64((aOrbiterG * 17540688242763829319U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 42U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterC, 41U)) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8457U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 16019U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 9789U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11617U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9377U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15863U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 19U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 57U)) + 13442819395490639310U;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 8187292523194120936U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 50U)) + RotL64(aCarry, 27U)) + 11469697159823131388U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 3U)) + 13414083692375929653U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 11U)) + 11404010733687907517U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6783212827186218247U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8561131439340372614U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7426867125542470683U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6252609642004429113U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12804867444200448952U;
            aOrbiterA = RotL64((aOrbiterA * 3114688959081972615U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2739648749603690781U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14808861217017399752U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 373911885694012101U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17588866502571268888U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5882260142735642980U;
            aOrbiterG = RotL64((aOrbiterG * 7688252946143263869U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15493099088132862949U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5175647411532429582U;
            aOrbiterE = RotL64((aOrbiterE * 15226544495598541883U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 24U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererK = aWandererK + (((RotL64(aScatter, 52U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 38U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17314U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 23423U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16826U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17174U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18076U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 21017U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aIngress, 29U)) + (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 14008824488073394623U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 13317978415866411468U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 22U)) + 13209180141897453900U) + aPhaseHOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 11870521586865233578U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 13U)) + 8052156380448047385U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12158131176743680605U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14674467487607719347U;
            aOrbiterE = RotL64((aOrbiterE * 18372548574199176503U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18055496790566231147U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3838105585041578784U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1075709247574580091U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2839568255183054418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11933612922864258179U;
            aOrbiterH = RotL64((aOrbiterH * 7571964469321160347U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6289849094151630580U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2640344350528492271U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16197726750829369365U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16306175266267657791U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3339898380394883600U;
            aOrbiterJ = RotL64((aOrbiterJ * 7105436590182982373U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 38U) + aOrbiterH) + RotL64(aOrbiterE, 29U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 56U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 29U)) + aPhaseHWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 30U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29028U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 25029U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25707U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26529U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24995U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29991U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 10U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererA + RotL64(aPrevious, 37U)) + 13499155707765393469U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 3740324981823726185U) + aPhaseHOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 5470765363949735652U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 22U)) + RotL64(aCarry, 41U)) + 3446436171274452326U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 57U)) + 1778929412631211933U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 14666308799855220954U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4548410236791175055U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6822908616815218501U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5829739767694190372U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 14319231414903675748U;
            aOrbiterB = RotL64((aOrbiterB * 4966501102515775601U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1513851750246111405U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1685620217748986019U;
            aOrbiterI = RotL64((aOrbiterI * 9286548037413609445U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16284162182006054402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6271539598462003309U;
            aOrbiterH = RotL64((aOrbiterH * 13923286694131331137U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12669312437565969473U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11894755313393001665U;
            aOrbiterK = RotL64((aOrbiterK * 12556759675372354075U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 58U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 58U) + aOrbiterG) + RotL64(aOrbiterB, 60U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterG, 51U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterG, 11U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
