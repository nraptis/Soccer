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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x88F8594ACCAA95DFULL + 0x9930951B0EE32FE2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC8439F13A3DFE495ULL + 0x8BCE8421F45535CAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB77AE7CC50C7B977ULL + 0xD8FCF934A3A6DE3BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF3C9AA00E5C414C1ULL + 0xE5A4C26FA0C3D231ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB1778E6B0DFD8A45ULL + 0xA4F796C34DE448D1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA205D26AE39374BFULL + 0xFE5F8D8965A3E007ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFA8CA562CB0F6E77ULL + 0xA7A21FE5E787722FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC3BF963875EB38F3ULL + 0xEA16C2A4B78AF491ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x832194FA62FDBFD1ULL + 0x8B419C0AA5DF7CAAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFBD4DAB471253317ULL + 0xE00DE8A186207285ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB518FEC9B8C3A7A5ULL + 0xD6F4C3F2CABE1287ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB852BFF6FE5BE707ULL + 0xD04556EA327CADB1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD5B1CBB01A1CB40FULL + 0xEE432CC67126B6BBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC92B92D1ECB4C27FULL + 0xED9A7717286FBDE1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFC66885B26D7E077ULL + 0xD6F89F710C2A5063ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFB72E476C149DC61ULL + 0xDDBCC094ABB21F39ULL);
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
            aIngress = RotL64(mSource[((aIndex + 999U)) & S_BLOCK1], 43U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1694U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 3024U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 245U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aIngress, 51U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 6U)) + RotL64(aCarry, 53U)) + 4476099022490972343U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 16836423700375760429U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 57U)) + 8850577488928703557U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = ((((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 7091631824560042743U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (aWandererC + RotL64(aCross, 39U)) + 12560498899956759494U;
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 35U)) + 7797973377112012161U) + aNonceWordI;
            aOrbiterA = (aWandererH + RotL64(aScatter, 13U)) + 6173820673874805794U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 11U)) + 10805025132310245348U) + aNonceWordJ;
            aOrbiterJ = (aWandererI + RotL64(aCross, 21U)) + 7139216143268029968U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 29U)) + 8241544862261635722U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 54U)) + 4735527016563596150U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5166171126690294033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11117641762075368393U;
            aOrbiterI = RotL64((aOrbiterI * 4980156869201219393U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6312932356458415421U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 1304139291184508668U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 90744653170922319U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 10085025354842771067U) + aNonceWordE;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16745854428789531080U;
            aOrbiterD = RotL64((aOrbiterD * 1945983905747274355U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2497187958708890337U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16069701876646548995U;
            aOrbiterJ = RotL64((aOrbiterJ * 16606039730973709495U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17242004368025978091U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12334315722243232121U;
            aOrbiterK = RotL64((aOrbiterK * 16528598396696346719U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8007042082518126895U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5665686359038811484U;
            aOrbiterF = RotL64((aOrbiterF * 11289316305875751813U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3913477186958600592U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16918984318564170343U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5128293326494417281U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10227611546502931418U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7187623463085447228U;
            aOrbiterE = RotL64((aOrbiterE * 8479839369622163181U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16655159122037336519U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9844145011519243346U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16512883184116277583U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8660130685326542506U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 16192687259641294851U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2882649237163668499U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 15208432734447317310U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4476099022490972343U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 7447168142776253041U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 30U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 46U)) + aOrbiterG) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aScatter, 14U) + aOrbiterI) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterD, 53U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + aNonceWordM);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + aNonceWordO);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 41U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 6U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 39U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 10346U)) & S_BLOCK1], 37U) ^ RotL64(mSource[((aIndex + 10255U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7331U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((aIndex + 7164U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 18U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 4U)) + 12426357877879529292U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 12604900366173639176U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 47U)) + 13511119007338929401U) + aNonceWordC;
            aOrbiterI = (aWandererB + RotL64(aCross, 29U)) + 9878720081166788060U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 15463195409806395076U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 13U)) + 6407922778852833423U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 7690427254160734016U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 51U)) + 18030974031722143619U) + aNonceWordG;
            aOrbiterF = (aWandererC + RotL64(aScatter, 24U)) + 17983938038322737041U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 35U)) + 16605512170117753884U;
            aOrbiterD = (aWandererI + RotL64(aCross, 37U)) + 681802273302348322U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15550312921312083819U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17824154101711884508U;
            aOrbiterC = RotL64((aOrbiterC * 7358612830654795357U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1939207786756735430U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3132864634777826569U;
            aOrbiterH = RotL64((aOrbiterH * 13606281919426730325U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12822929773923954849U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16576106045887115660U;
            aOrbiterJ = RotL64((aOrbiterJ * 16370914370769903051U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2398825881649235260U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13700821892926092479U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 10830623703416956043U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2439833784883391606U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15870638514107637833U;
            aOrbiterB = RotL64((aOrbiterB * 3797380922767479287U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9165457123134229670U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8736642509192659417U;
            aOrbiterA = RotL64((aOrbiterA * 16219277537523484065U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9232719746484835693U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7826680628853322541U;
            aOrbiterD = RotL64((aOrbiterD * 12578050118133526187U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 14323652326982518782U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2254524512851399313U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4119339547645451149U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14459632243829356472U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8591197056749497716U;
            aOrbiterF = RotL64((aOrbiterF * 13053836520694721881U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17220196418897000411U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 7186579019945992185U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12406048515179065691U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7554005180895698880U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 12426357877879529292U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5090046967147694465U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 28U));
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterE, 35U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterK, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aCross, 40U) + RotL64(aOrbiterF, 30U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 21U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 12U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 16313U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 12694U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 14821U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15325U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 11700815697312060726U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 41U)) + 11808423452327465441U) + aNonceWordG;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 8670503858631730886U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 56U)) + 2400061067991988544U) + aNonceWordB;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 51U)) + 16163118178366229686U) + aNonceWordO;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 47U)) + 3280178595904941068U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 35U)) + 3298683600817047727U) + aOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 16321624053445183574U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 5U)) + 6730229877611375225U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 60U)) + 10162830636713641322U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 21U)) + 15646771327759599256U) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14841751262270544102U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 9545541117228834895U;
            aOrbiterJ = RotL64((aOrbiterJ * 11529769874752969377U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14676615635857599982U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1231768638470558855U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1945905595345404833U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1406171421638586846U;
            aOrbiterB = RotL64((aOrbiterB * 4577864352425476233U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 1970292335806697198U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12309719390375013297U;
            aOrbiterE = RotL64((aOrbiterE * 16540660957923687327U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5352135521358954576U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15465675376193501658U;
            aOrbiterF = RotL64((aOrbiterF * 16385761112921041387U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2842123638916600369U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3544764287036748668U;
            aOrbiterH = RotL64((aOrbiterH * 3360772950777850115U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 6038297172906492282U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10249342332287140970U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16701083081566042277U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1662076777040529446U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1949705569959740274U;
            aOrbiterK = RotL64((aOrbiterK * 11340691546658994529U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13934194245417822360U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5720408806425535958U;
            aOrbiterI = RotL64((aOrbiterI * 15237561081637415383U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 2209251362417210658U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 4917447930929521699U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17489570156694692569U), 41U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 14817115766683623486U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11700815697312060726U;
            aOrbiterG = RotL64((aOrbiterG * 16982411053956669181U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 14U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterB, 39U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + aNonceWordN);
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 29U));
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 46U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterF, 37U)) + aOrbiterH);
            aWandererB = aWandererB + (((((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 29U)) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 23U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aCross, 53U) + RotL64(aOrbiterF, 4U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + aNonceWordL);
            aWandererE = aWandererE + (((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 21U)) + aOrbiterB) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 52U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 16798U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 20576U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 17972U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17699U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 18152U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 21U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 39U)) + 15652862298542575895U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 16925323928418184554U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 11U)) + 4413861484961668394U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 41U)) + 2215946422098155969U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 48U)) + 14975185533513111110U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 3U)) + 9711613814905834552U;
            aOrbiterH = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 13154957291850149471U) + aNonceWordO;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 19U)) + 5058313016418534840U) + aNonceWordH;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 29U)) + 15011423472941211620U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aCross, 51U)) + 2030053257469580168U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 24U)) + 150530795186791193U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10878237472104183427U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11724672539469573109U;
            aOrbiterC = RotL64((aOrbiterC * 16158741837357985395U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9589700906445846956U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 1367381624958248949U;
            aOrbiterF = RotL64((aOrbiterF * 8459515089081211977U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12003215666757518106U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11232479330848006729U;
            aOrbiterK = RotL64((aOrbiterK * 10993290955464593033U), 39U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 13013910456628561621U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6092509838924105265U;
            aOrbiterE = RotL64((aOrbiterE * 805601154718006061U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11999225836250312801U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14421271973875748413U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9529010940887430157U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15536288285741825272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2071793889925436679U;
            aOrbiterI = RotL64((aOrbiterI * 1526376970151714589U), 53U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterE) + 5622386476463436967U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16147972771639168516U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 11826916832825159095U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4519892856053952290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 12059500374938843538U;
            aOrbiterA = RotL64((aOrbiterA * 14987533625537956299U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4547335128847992282U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15378473334472216418U;
            aOrbiterD = RotL64((aOrbiterD * 13907560285280544037U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14644123269581735633U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6434315615480805381U;
            aOrbiterB = RotL64((aOrbiterB * 4335857173941645355U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14241680137158382296U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15652862298542575895U;
            aOrbiterG = RotL64((aOrbiterG * 4190840063924551519U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 6U) + aOrbiterI) + RotL64(aOrbiterF, 46U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 39U)) + aOrbiterG) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aCross, 26U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + aNonceWordJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterE, 24U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 20U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 26622U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 22639U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(pSnow[((aIndex + 23944U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 25108U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26513U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22223U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 60U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererH + RotL64(aScatter, 41U)) + 5697928251815176134U;
            aOrbiterA = (aWandererC + RotL64(aCross, 21U)) + 337587740689259575U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 36U)) + 4927686903263973950U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 3742409032569801033U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 19U)) + 1608092659172197650U) + aNonceWordJ;
            aOrbiterB = (aWandererK + RotL64(aScatter, 23U)) + 15848744267145717509U;
            aOrbiterE = ((((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 15300174177963339253U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 11U)) + 14162868453323648628U) + aNonceWordO;
            aOrbiterG = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 12020167069983729869U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 54U)) + 16259538291658723956U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 3U)) + 8516686212464112245U) + aOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3722184575520553132U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5663609293306386784U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 14364218128780764749U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15265344442454471986U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3050323350098829515U;
            aOrbiterA = RotL64((aOrbiterA * 5890624677162388135U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1093356813820599238U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15167726103772238440U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5719466863561311069U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15170797965325981472U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17826286701992981628U;
            aOrbiterG = RotL64((aOrbiterG * 11186808881726573677U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 14710892030473425181U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 397194787697553904U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14368930300818752833U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1273724124862533034U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 13018397560392545616U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4644812473262395329U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9638716186445643730U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7255587739807843785U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 6055682981584011189U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9272350563697399628U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1040729335295009339U;
            aOrbiterH = RotL64((aOrbiterH * 17825687660830291443U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12128124729613601747U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2285238815562202219U;
            aOrbiterE = RotL64((aOrbiterE * 15398840993074390573U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6339113298619163493U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5911895708485037040U;
            aOrbiterF = RotL64((aOrbiterF * 3271006139923200439U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 7601399508218901328U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5697928251815176134U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 8184257916861355735U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterH, 54U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterF, 51U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + aOrbiterE) + RotL64(aOrbiterI, 46U));
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 31044U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((aIndex + 31359U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29543U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 29839U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29135U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 29314U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 51U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterB = ((aWandererJ + RotL64(aCross, 44U)) + 11521331427196538632U) + aNonceWordJ;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 16653824187682957632U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 37U)) + 11654676587350088289U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 8010313317412193584U;
            aOrbiterD = (aWandererB + RotL64(aCross, 23U)) + 1108775560502907471U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 29U)) + 243952321439823521U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 18U)) + 2324945800401240403U) + aNonceWordF;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 9257554497543369657U;
            aOrbiterC = (aWandererC + RotL64(aCross, 39U)) + 16701314607244592540U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 47U)) + 3900445848034341782U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 57U)) + 7652316487347103658U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14980368605272070578U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2001165460948764796U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8110980921827107649U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1911044015666991050U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11366207111147818339U;
            aOrbiterD = RotL64((aOrbiterD * 17234439040652553865U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16469329744002456607U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8062793687044950815U;
            aOrbiterK = RotL64((aOrbiterK * 5856142259851144369U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15364721421972807872U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8979915611483540231U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 10899377466171153383U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7654234623563110457U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1526832460342135008U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12766083052650723051U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1596625448797520938U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 15723912914858523080U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 6003857787643420337U), 37U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 7664226719746532168U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13767298788411473401U;
            aOrbiterI = RotL64((aOrbiterI * 15663266144965532019U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8371251860069346385U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 10143279934304029980U;
            aOrbiterF = RotL64((aOrbiterF * 12764966547132248131U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10034920090729616747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14450253491131954914U;
            aOrbiterH = RotL64((aOrbiterH * 15877567779079226909U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9450697155749555210U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14051719612902917300U;
            aOrbiterB = RotL64((aOrbiterB * 7659810299163085295U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 659383614060726993U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11521331427196538632U;
            aOrbiterA = RotL64((aOrbiterA * 1068009283450923005U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 44U) + RotL64(aOrbiterA, 23U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 34U)) + aOrbiterH) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aCross, 42U) + aOrbiterK) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aNonceWordP);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 57U)) + aOrbiterG) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 21U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD51D7166FF074C6FULL + 0xBF79E2A0FB906C4BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA97B4FC978C51579ULL + 0xF3AAFDC6B6E4DF5CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBFDB74F0A48DA5D9ULL + 0xD4E879AEAC0687A8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x864DD023EF89196BULL + 0xC7E8FD9E2D103201ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD883B79E4207120DULL + 0x9338A5220809CB01ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xABFC126A3217AA83ULL + 0x925EBEC3E6C77EE6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDAEC0F6EF560100DULL + 0x96C97A0810C7A4BDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE99BB252C50F230FULL + 0x8EB116DBDCDEBC4BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEE371613614D144DULL + 0xA04D19A7E742E0A9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDB8436898F21A735ULL + 0xD653F4B9FC1627DAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA1AB1FC6A7C33927ULL + 0xE3E9C12AB643D557ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8FFE865C9F3EC489ULL + 0xDEF6522272C927C4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB180673B24C9A341ULL + 0x9BFA4C11FB43AFEBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF93F034106D11F6BULL + 0xD69069E96F5C8CBAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8B0EFFBEDF5A87F3ULL + 0x968C7AF71021BBE3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xDA1F89390ECEEF93ULL + 0xD3FD2935C3636E2CULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 2964U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2665U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4625U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneD[((aIndex + 2433U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 44U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = ((aWandererJ + RotL64(aCross, 52U)) + RotL64(aCarry, 3U)) + 898812731947995389U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + 8677347622525527167U) + aNonceWordA;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 770321564027567654U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 21U)) + 11020474858081526395U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 26U)) + RotL64(aCarry, 57U)) + 17289793580414993470U;
            aOrbiterB = (aWandererG + RotL64(aCross, 43U)) + 10111912559295118444U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 3U)) + 8083622125544542011U;
            aOrbiterI = (((aWandererI + RotL64(aIngress, 37U)) + 7149858558922988240U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 47U)) + 5919683821379905699U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6860902846079238714U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 15083517836867542075U;
            aOrbiterJ = RotL64((aOrbiterJ * 4686657139237578325U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14852868368708376381U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9860233289028878323U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 13418143547952204667U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 772406119079116272U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 7971141501337627589U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 10168120622976358617U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8478568022896691911U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4027604850785607101U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4826627523578901467U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17199331557841535430U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7515957656979776361U;
            aOrbiterK = RotL64((aOrbiterK * 5468950152869656599U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 17138249294921502391U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16236812863923234668U;
            aOrbiterC = RotL64((aOrbiterC * 2925542836624164807U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16941524155859123682U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11240343728857342866U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7281012444214294659U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15163914964139858328U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6673576554415729652U;
            aOrbiterE = RotL64((aOrbiterE * 1558880328574736975U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5399050402101642989U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11806006719060024615U;
            aOrbiterA = RotL64((aOrbiterA * 15782156615926092159U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterG, 11U)) + aOrbiterI) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 58U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 41U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aNonceWordG) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterC, 18U)) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12959U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((aIndex + 10608U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 12981U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15696U)) & S_BLOCK1], 41U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12163U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 60U)) ^ (RotL64(aCross, 39U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (((aWandererF + RotL64(aScatter, 29U)) + 18087125778766689269U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererK + RotL64(aCross, 43U)) + 13710545066503235196U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 58U)) + 1701939704736254645U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 23U)) + 8064093611384019909U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 16623332751533885431U) + aNonceWordO;
            aOrbiterH = (aWandererE + RotL64(aScatter, 47U)) + 15590129153794910109U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 7413312683079107383U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 4186064478651458810U) + aNonceWordD;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 14U)) + 5501191643940735954U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11064645242200570835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13825922087298055833U;
            aOrbiterA = RotL64((aOrbiterA * 7529317892716108867U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 5944980709887369970U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8181136916070569646U;
            aOrbiterI = RotL64((aOrbiterI * 395183021205661827U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15442336949157292482U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 11580554435240641337U;
            aOrbiterG = RotL64((aOrbiterG * 6654637892858767739U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11240018128174598322U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 2027565596050777471U;
            aOrbiterC = RotL64((aOrbiterC * 18048186560314431815U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16425887196883725233U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16828683527588834095U;
            aOrbiterH = RotL64((aOrbiterH * 17746289103235902485U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9923829146479008804U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6669171007279929454U;
            aOrbiterB = RotL64((aOrbiterB * 681823450939955099U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3902430046523165149U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6739998149289590041U;
            aOrbiterJ = RotL64((aOrbiterJ * 2675037435528416821U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16014401255534234075U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14741857638680634564U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8723611021403369393U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5064807861673260054U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterD) ^ 968747317273200299U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterK = RotL64((aOrbiterK * 14122304002722582329U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterC, 18U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterH, 43U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + aNonceWordI) + aWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererA = aWandererA + ((RotL64(aCross, 18U) + aOrbiterH) + RotL64(aOrbiterB, 22U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterG, 37U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24146U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneD[((aIndex + 21150U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 20221U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19251U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 23232U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 20119U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 22U)) + 9654059367478508868U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 6473006635864677427U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 3U)) + 6944184481315853243U) + aNonceWordF;
            aOrbiterD = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 4061496421939102306U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 5U)) + 15791809275719085463U) + aNonceWordK;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 57U)) + 14050798802646323055U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aScatter, 47U)) + 12072905924741758266U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 18U)) + 17639076509231343896U) + aNonceWordE;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 41U)) + 12195388285571234715U) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4325404419499496529U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 5910567888204238382U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11503787177122206937U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13092940059929942699U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13381962590820308761U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6345904465930943295U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15622862439323440527U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14027151901132249793U;
            aOrbiterG = RotL64((aOrbiterG * 2273573821630510087U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4584410023907605157U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15763755180625487157U;
            aOrbiterD = RotL64((aOrbiterD * 6755736130607297639U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 17023059745666559199U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5298529579288492971U;
            aOrbiterI = RotL64((aOrbiterI * 2483562793328357721U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2870152867331654736U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12017191100173748848U;
            aOrbiterH = RotL64((aOrbiterH * 9958191466506480519U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15899529176182436062U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16482713846343388735U;
            aOrbiterJ = RotL64((aOrbiterJ * 719465695044265601U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12943393531812774449U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9881108254540483225U;
            aOrbiterK = RotL64((aOrbiterK * 8011108108007885059U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3532054586199716750U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7142230313294797435U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14154176174768868421U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 10U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 4U)) + aOrbiterH) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 57U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 47U));
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 42U) + aOrbiterE) + RotL64(aOrbiterC, 18U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterE, 23U)) + aNonceWordO) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25174U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 27477U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26239U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24592U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25188U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26942U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 39U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 4U)) + RotL64(aCarry, 51U)) + 5088525177670191619U) + aNonceWordG;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 29U)) + 9966456257813932112U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aCross, 35U)) + 7707646574027146307U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 11U)) + 75480203757681173U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 43U)) + 384659134071835163U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 51U)) + 3158769775373307778U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 18U)) + RotL64(aCarry, 13U)) + 17360830943513941272U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 27U)) + 5317278822721604586U) + aNonceWordO;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 39U)) + 1371427105215954781U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3162710551223553423U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 5332921933853550756U;
            aOrbiterB = RotL64((aOrbiterB * 11709546145149357887U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10572462410297815854U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 10234389605554817892U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 2130374833440291193U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13421365517991380605U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 10186643614984034083U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 8554471709467808453U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4742438973260817120U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6081590345899008846U;
            aOrbiterD = RotL64((aOrbiterD * 7069396301823124931U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15360092808493795340U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12186413069553132646U;
            aOrbiterA = RotL64((aOrbiterA * 3815981440611914267U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16756221656224451552U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12232880965861373143U;
            aOrbiterC = RotL64((aOrbiterC * 14196910735715726471U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10090954323470840557U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15615770271463853537U;
            aOrbiterG = RotL64((aOrbiterG * 13544181592829027283U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 556029032505658411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13311879111583579039U;
            aOrbiterI = RotL64((aOrbiterI * 3924744868168749003U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8646360871497847336U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2064833941982069154U;
            aOrbiterH = RotL64((aOrbiterH * 10016546852137913163U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 52U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterK, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 56U)) + aOrbiterB) + aNonceWordL);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + aNonceWordC);
            aWandererJ = aWandererJ + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 11U)) + aOrbiterD) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterB, 40U)) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterG) + aWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBD37B8391C1A962FULL + 0xBD96331E426E2E29ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF6F2BA2E959F3EF3ULL + 0xAA2D20013AAACB66ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x9F22754FD1CAF393ULL + 0xE396D1945ABBE349ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8AF578AE8F891669ULL + 0xC5BF40D01290ADB2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF219E67BD4E25211ULL + 0xB7D6186A17F775B5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCCB934A312EA702BULL + 0xDDA59CCD2C28B126ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAC589E68FF2F2D77ULL + 0xDB88ECB78F9B463DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x91A7A36AF7589D87ULL + 0xE699490418952FCFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x981A57870831C077ULL + 0xFBE20900399EEFF5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCDEFA5775C5CA959ULL + 0x9A1F6E60B9BD4FE9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE8EF3D630370971DULL + 0xA29DBB65C65936ECULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC6FAC32DBCB56277ULL + 0xECC68AD272023877ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB0B5FA19B527F985ULL + 0xA9B940494E95E072ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD9D8602FAB8CE6A7ULL + 0xC7CED83A2DCA469DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFCC942C1FD3C2C47ULL + 0xD42FDE290864E8E3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEC4D64111801B081ULL + 0xDEF552BCFEA2D0C7ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneC, aWorkLaneC, aFireLaneA
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1925U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 749U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4093U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5163U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 1407U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 9023059520606551446U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 662441755115638133U;
            aOrbiterK = ((((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 27U)) + 16957253361196144712U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 60U)) + 7840955025765308605U) + aNonceWordL;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 5U)) + 346855809270395799U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 16099139781586668343U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 3706457327118322098U;
            aOrbiterK = RotL64((aOrbiterK * 7810030620470889591U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12166825885547622870U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 7792658665720344200U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16305542632794270697U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7128477606152986326U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11116533962780290084U;
            aOrbiterI = RotL64((aOrbiterI * 11993485572912492297U), 3U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 10443889548568288532U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 4402387036946561017U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 9032964741841833277U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13002706161178447654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13929727277530310708U;
            aOrbiterH = RotL64((aOrbiterH * 7005639090871200285U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 20U)) + aOrbiterH) + aNonceWordC);
            aWandererH = aWandererH + (((((RotL64(aCross, 50U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 47U)) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9219U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 14076U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11261U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14087U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10604U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10507U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (((aWandererG + RotL64(aIngress, 4U)) + RotL64(aCarry, 39U)) + 13960289014350612206U) + aNonceWordE;
            aOrbiterI = ((((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 3483331015269589730U) + aOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 23U)) + 6873299241002444518U) + aNonceWordJ;
            aOrbiterA = (aWandererD + RotL64(aCross, 29U)) + 3562094007125534229U;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 37U)) + 11422367439932782705U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 532453428514259816U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 17810941465810193088U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 2830829128884590275U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11869759058631106331U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8837581071876177566U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15329827515970522213U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17185378327053837778U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7578253375676981500U;
            aOrbiterI = RotL64((aOrbiterI * 13371647568758721729U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17112646434432814442U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14949096407295697881U;
            aOrbiterC = RotL64((aOrbiterC * 14770977858283051753U), 5U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 4259590620758467836U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6534899413644542303U;
            aOrbiterA = RotL64((aOrbiterA * 7987609419215568661U), 39U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 4U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aNonceWordC) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + aNonceWordP) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17125U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneD[((aIndex + 21656U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 23360U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18615U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24432U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17751U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererC + RotL64(aIngress, 29U)) + 5721224134332887360U;
            aOrbiterG = (aWandererD + RotL64(aCross, 54U)) + 6892749729775049095U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 3884839462099556836U) + aNonceWordN;
            aOrbiterI = ((((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 4365431706830216193U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 19U)) + 15501528746571578773U) + aOrbiterAssignSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4505911326320650606U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1865129050927879580U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 9198152644404068721U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 2011737665969640369U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 611672935827062688U) ^ aOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12873671551304596619U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 663547038310431047U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5468932264754299556U) ^ aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11968657455484578525U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17920294117231191705U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 486058453837528110U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 8851102552244026737U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2789178451938129313U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 420772587981211184U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 17402987842294006667U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 48U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aNonceWordB);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterG, 50U)) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 38U) + aOrbiterG) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 3U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 50U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27373U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 25148U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30127U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28711U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27816U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31008U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 24756U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 6U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = ((((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 57U)) + 2225397913940961213U) + aOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 8342544893601343643U) + aNonceWordC;
            aOrbiterE = (aWandererD + RotL64(aIngress, 23U)) + 162922186381417187U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 60U)) + 11660218373710972210U) + aNonceWordI;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 14909034764605802354U) + aOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 16776955237009701511U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 5834487809188925253U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4458820879204327709U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1498492772767040320U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 4161765458781579617U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 15535994410289065281U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10511923076962447765U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 8575954471692620021U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12526744988828982731U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6536325446331340573U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1790628986900286346U;
            aOrbiterB = RotL64((aOrbiterB * 5262997114200816715U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2623814807619278590U) + aNonceWordE;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11676970995834706612U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 10057461115132434901U), 27U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 41U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterF, 50U)) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterE, 3U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((((RotL64(aCross, 21U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordG) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x89D2ADC083E6CBBDULL + 0x8661ABE7E8967AAFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBB3DF83554CE0917ULL + 0xD4BE0C32ECC3E33BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x93D4AEAA5C81CD33ULL + 0xDBE90E534C5F5717ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE42C505822825AD1ULL + 0xC5D125EF1E013144ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE36E05666B1042E3ULL + 0xF13C964717A48DD9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCAACDD5D1F776DB5ULL + 0xA1BC33279B09DB96ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC744D526EA082FE9ULL + 0x88658098D1D429EDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE23933AECAAEE853ULL + 0x9AB8A880DDBAE8B7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFD535014DD2E0881ULL + 0xB72E7B1F9AF55B22ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xACA550E33A66F4E5ULL + 0xFEEE5CA529565E65ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9EAE44908951F7FFULL + 0xFD588548D7F9C3C0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xCE41DDEA77972EE9ULL + 0xD1FDDE792D91CA49ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBCA8F07ED1A1FDC3ULL + 0x8508E7754055BE8EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD51E14008E4D1253ULL + 0x85ACD1F0F77B8A52ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEE2CB97DEB56D0B5ULL + 0x880E70B98781212FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA016301DD0F44E33ULL + 0x9985C6C90A207C46ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneA, aExpandLaneC, aExpandLaneD, aFireLaneC, aWorkLaneA, aOperationLaneA, aOperationLaneC, aWorkLaneB, aOperationLaneB, aFireLaneB, aWorkLaneC, aOperationLaneD, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3695U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 666U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7996U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3862U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6610U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7774U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 34U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = ((((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 826930775230515406U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 5137814617363250861U) + aNonceWordF;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 53U)) + 14761561947426681616U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 21U)) + 12773023438753662590U) + aNonceWordJ;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 3U)) + 7331345852207096322U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = ((aWandererK + RotL64(aCross, 12U)) + RotL64(aCarry, 11U)) + 3899381212671247460U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 41U)) + 10072004147620068599U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterE) + 3424585039401897560U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8246760141625966321U;
            aOrbiterH = RotL64((aOrbiterH * 11478879365443736383U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3655992860610853290U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11154618022505863898U;
            aOrbiterE = RotL64((aOrbiterE * 4791494171286145231U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15629361991059709973U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10842068502278489664U;
            aOrbiterD = RotL64((aOrbiterD * 17223002513104960799U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5571312349016336686U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 589313823745748879U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 1356685926549786027U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13633457935771935260U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12684602052812183096U;
            aOrbiterI = RotL64((aOrbiterI * 4689206269919806711U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5711307583717354204U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7181854170553728211U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9835601115561325911U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 1884620014396115821U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1471516373272364262U;
            aOrbiterJ = RotL64((aOrbiterJ * 5126319375714848029U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterE, 41U)) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 20U) + aOrbiterI) + RotL64(aOrbiterJ, 47U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 43U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11327U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneC[((aIndex + 9558U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9305U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15094U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10687U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 13379U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 27U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 17264605017518259932U;
            aOrbiterH = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 15209184354580778643U) + aNonceWordD;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 35U)) + 3299527965014731384U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 16293096431816127821U) + aNonceWordE;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 3U)) + 11031983436878828337U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aIngress, 51U)) + 9188018632448236358U) + aNonceWordM;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 58U)) + 13420816400363406556U) + aNonceWordP;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2485063384097917101U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3089135816938128264U;
            aOrbiterJ = RotL64((aOrbiterJ * 8813152992957361153U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10730544971770435788U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10431767565618874806U;
            aOrbiterC = RotL64((aOrbiterC * 4723078464590561545U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14883796491656899074U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 13465877783538483706U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 14311686051108108503U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13322163435314643713U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3307316600284371955U;
            aOrbiterG = RotL64((aOrbiterG * 12337846092069506365U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4950101626975919939U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2596253994220103666U;
            aOrbiterH = RotL64((aOrbiterH * 7181706961838582889U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17961706029559914243U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10321902557977495175U;
            aOrbiterE = RotL64((aOrbiterE * 16189559888625084711U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 18146616411403012772U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8414050129421955787U;
            aOrbiterD = RotL64((aOrbiterD * 14879448948196182863U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterG, 19U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 56U)) + aOrbiterD) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 47U)) + aOrbiterH) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22103U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((aIndex + 20561U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17746U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19658U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20124U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 22855U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 56U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 2617613537256538553U) + aNonceWordJ;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 19U)) + 16642868916835132715U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = (aWandererE + RotL64(aIngress, 27U)) + 10860291124337073254U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 6432511273906902472U) + aNonceWordA;
            aOrbiterK = (aWandererD + RotL64(aScatter, 60U)) + 7505375005848241910U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 11086616004678821329U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 39U)) + 3298830587569881951U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9775143140064220979U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4147601326580823120U;
            aOrbiterI = RotL64((aOrbiterI * 13462244678782260871U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12245920269898100415U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8391940489176734499U;
            aOrbiterG = RotL64((aOrbiterG * 9119606167674098007U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17876893379544668477U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18301882058180370541U;
            aOrbiterH = RotL64((aOrbiterH * 16680384667098921309U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6869225862715140102U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15404118372589259800U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5766851935950389915U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 17757381020518233814U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17677969146092374455U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3469432916562405063U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15783378556632870114U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 5792858258663697864U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 12008981883482080427U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11737803388202260296U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16001927091970715330U;
            aOrbiterJ = RotL64((aOrbiterJ * 3062030309852922061U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterI, 57U)) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterG, 13U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterI, 44U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 14U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31400U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 32584U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24616U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26837U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26339U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 30399U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 54U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 13350544654542863236U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 12364346790125404372U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 27U)) + 9738750172849512764U) + aNonceWordJ;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 3781373837635491421U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 41U)) + 16635020317512702337U) + aNonceWordB;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 35U)) + 5383653921676231276U) + aNonceWordL;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 29U)) + 10181959815492056493U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 10005510924273927017U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9524687662265740565U;
            aOrbiterA = RotL64((aOrbiterA * 13687380438646756931U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4259138552009771014U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8973051213213726023U;
            aOrbiterJ = RotL64((aOrbiterJ * 12625091476068190979U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17602611840127337490U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8218984546932905269U;
            aOrbiterI = RotL64((aOrbiterI * 17504305273683304231U), 43U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 18102186122213487888U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2629927500298092976U;
            aOrbiterE = RotL64((aOrbiterE * 6983280164448292723U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 2491581597835795234U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9506602492971620955U;
            aOrbiterB = RotL64((aOrbiterB * 9559829640915637163U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 13422942713680612924U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15037354693234876601U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12692376075738621447U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 12896066842192894694U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2202952306291905855U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 6779368532763429997U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 50U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterH, 21U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 11U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF366767D4ECB019DULL + 0x9870631C0B5E197AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE3C6029558522E61ULL + 0xC3E92B764A908EB5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFD6018166A4E14FDULL + 0xA1DBA09E10839875ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB5DF2B353D1AFAB1ULL + 0xF42A1A58B877189AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD12E9D277729B85DULL + 0xA02BB4398825BC5EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCA39FF0A0D2A4D79ULL + 0x9DFB2C70578C2FB3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEFB691ECCB335213ULL + 0x8B26ACC986DB9F82ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9BC9E0B1D6630DDBULL + 0xEF0BDFF70B5B8ABAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF410C734AC7FB6B7ULL + 0xB44952A2AB5161C1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9BA2E7F79485B9F3ULL + 0xA19A64FF6C8D5D84ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE395FCBD35845C9DULL + 0xAD8F28738578CF5BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x9A2D8A2FCABDF4E1ULL + 0xB754D758FCBC3285ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE0B4333F2532D9B3ULL + 0xD971F94D99357B14ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x820B0F5CE5F9ABA1ULL + 0xC13630D46ABE4815ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFCBBF78F93EBB6BBULL + 0xC737D50856FA33FAULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9C1BC6FDA0F83199ULL + 0xA3312394DA747176ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneC, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aFireLaneA, aOperationLaneA, aExpandLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneC, aFireLaneB, aOperationLaneB
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6998U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 3647U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 4146U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 407U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 364U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 112U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 58U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 47U)) + 12222235191147985484U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 39U)) + 16367317014523328414U) + aNonceWordC;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 3511378091284703789U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 37U)) + 15247492830966725949U) + aNonceWordB;
            aOrbiterA = (aWandererE + RotL64(aCross, 27U)) + 7745995913390407897U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 53U)) + 6463593307540108810U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 1101669311005268630U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 12988052764067518580U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 17717179747434679772U;
            aOrbiterH = RotL64((aOrbiterH * 10820310705487638793U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 11662190906682400416U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6563014073547628748U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16967910471722117761U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13099094932059419219U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16342730862261868847U;
            aOrbiterE = RotL64((aOrbiterE * 10988124108686164829U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 16855346813127524624U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6570063128502306944U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 4571570049463124831U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 11328352033809240501U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11640986648833160901U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2895830492089678919U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2675226158571501666U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 17700531248266458165U;
            aOrbiterC = RotL64((aOrbiterC * 2231403813970188657U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7729597396731910874U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15172374484412053756U;
            aOrbiterD = RotL64((aOrbiterD * 149009041406406517U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterE, 5U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 11U)) + aOrbiterI) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 30U)) + aOrbiterH) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterC, 43U));
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneA
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11552U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 16221U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 9002U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14910U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11362U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 9159U)) & S_BLOCK1], 18U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = ((aWandererI + RotL64(aIngress, 21U)) + 2101601659597850213U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 11U)) + 2759794072560720121U) + aNonceWordA;
            aOrbiterF = ((((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 9443562552411269339U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = ((aWandererA + RotL64(aCross, 47U)) + 10801360546699857975U) + aNonceWordI;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 5U)) + 8020716394829332019U) + aNonceWordK;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 27U)) + 1021894212367773801U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 13346855534622490176U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 16359309548462953836U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12642446944680783519U;
            aOrbiterF = RotL64((aOrbiterF * 12197935153255283321U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8197424982767553380U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 14346334610901859094U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 16982899923227935679U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14171304260534233539U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 334531601308283605U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 5012968232749075075U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10707856298471572695U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18364775750091914766U;
            aOrbiterH = RotL64((aOrbiterH * 15735143943129143265U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 8531394793118363836U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15352876929406908882U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 475199047053777179U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 567682016232278157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2068146551757663119U;
            aOrbiterJ = RotL64((aOrbiterJ * 1557877740957797555U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 7776122587613256525U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 16430938890724272256U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 4540270493783593257U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 54U)) + aOrbiterJ) + aNonceWordH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 41U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneD
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18240U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 19276U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 20526U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18075U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23367U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21167U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 24U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererH + RotL64(aCross, 47U)) + 12262991801139086177U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 3U)) + 7963038771924890197U;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 15540520327933568896U) + aNonceWordK;
            aOrbiterI = (aWandererB + RotL64(aIngress, 28U)) + 8745565892055020722U;
            aOrbiterB = (aWandererE + RotL64(aCross, 57U)) + 16619329199683755286U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 10865705026433867260U) + aNonceWordI;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 2743368697984518059U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5556006271515473135U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 5355833281353498588U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 4190140212757841511U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8313616108963479829U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 16657121016801866434U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 331533349428472477U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16532226425013000833U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5800465874932467232U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5966395771690704577U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 17882948163883121328U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15029375310296563175U;
            aOrbiterK = RotL64((aOrbiterK * 17021415832288477713U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10170682648007918739U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11829089574189398773U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 15755874363488568849U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1746524867389196322U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10217423427886742775U;
            aOrbiterB = RotL64((aOrbiterB * 9166162099575333519U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1338457710729082656U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1319981417675542556U) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 9518448254565489715U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterK, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 5U)) + aOrbiterI) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 35U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 53U)) + aOrbiterC) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterF, 28U)) + aNonceWordB);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterI, 21U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 10U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 18U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26267U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 28468U)) & S_BLOCK1], 10U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 26209U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32481U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29978U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 31167U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 43U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (aWandererA + RotL64(aPrevious, 13U)) + 6163290588946759209U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 35U)) + 7342672468560105447U) + aNonceWordB;
            aOrbiterF = (aWandererH + RotL64(aIngress, 47U)) + 11574563167017282321U;
            aOrbiterC = ((((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 47U)) + 2254820206194758964U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 1469783447473099498U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 60U)) + 14174828900676165088U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 16277954291890598132U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14845750668693136766U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 150099699692047766U;
            aOrbiterF = RotL64((aOrbiterF * 7644895634421086357U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1200784917165131703U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 9469982764806754302U;
            aOrbiterE = RotL64((aOrbiterE * 17851969334511301943U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10956702761701710182U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7915506894975487807U;
            aOrbiterI = RotL64((aOrbiterI * 8874108311712727983U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 17335794183733623213U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 557028996286989506U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3993359298602424281U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 1597385667771002414U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4376417959915162639U;
            aOrbiterA = RotL64((aOrbiterA * 4626236858205178149U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 549770198518993876U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 756554555648070919U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16272320259614325355U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7298557532533152193U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3336802611342112013U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 14679103452120080499U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterD, 3U));
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 12U)) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 47U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordL);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterE) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE53A35677105A93FULL + 0xDF1BC61C16286475ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF9C38337A750557BULL + 0x83229C5F593D31BAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC6BB959F0DD377D7ULL + 0xBBDF25CC7F912F24ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB949DBF4244C17F1ULL + 0xA41EBD2581B7726DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x890BC54E99C01EADULL + 0x987D1E7E6670553AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBF9BDFC849CA1BB9ULL + 0x963DD3C8B7701BE5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x87E47E1C1EFE08B1ULL + 0x8706C51B21B9728BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x96EDEDA01C0FF10DULL + 0x860877BFEE3CFFB5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC485B40736BC9545ULL + 0xBA88E573F92E1491ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB0FA203C12A5AAABULL + 0xB3DA97E9593E9610ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC53985741EC37287ULL + 0xE1885DDD3F46F00CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFF98089FC2B4D227ULL + 0xBD4D5C5EAC3D8602ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAD76556E385CBB47ULL + 0xBB701F718E0D1D19ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x915FE5D0F7766869ULL + 0x8A21AC7FED0238E3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCC0A7BA4D247E4EBULL + 0xFDBA43B209323962ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC11E7E6549781B23ULL + 0xE491480ABED5BB2EULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aWorkLaneD, aOperationLaneA, aFireLaneC, aWorkLaneA, aOperationLaneB, aWorkLaneB, aWorkLaneC, aOperationLaneC, aFireLaneD, aFireLaneA
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3568U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 2283U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2997U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5820U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 201U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 6791U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 12U) + RotL64(aCross, 53U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 20U)) + 3973833383430652211U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 5760227042747169187U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 29U)) + 4923009065139227286U;
            aOrbiterF = ((((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 1477807307009107590U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 5707194514329007301U) + aNonceWordG;
            aOrbiterH = ((aWandererI + RotL64(aCross, 4U)) + 5340439728375269724U) + aNonceWordB;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 47U)) + 17080457898946572387U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 23U)) + 281559150259472813U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 35U)) + 16160633048230910560U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 41U)) + 9003989610509592121U) + aNonceWordC;
            aOrbiterI = (aWandererB + RotL64(aCross, 39U)) + 10579322462808454333U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 15059383289528723069U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10417647757852880956U;
            aOrbiterK = RotL64((aOrbiterK * 1457919230286043137U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14484665027393813330U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 12344463053485837974U;
            aOrbiterH = RotL64((aOrbiterH * 5762654194001525041U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5826453246659297805U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 12547902286376986223U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 2982850000322672789U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9637855144278126174U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2132744427444501938U;
            aOrbiterF = RotL64((aOrbiterF * 5911587798564836199U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9248933938130311231U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13274297928717090383U;
            aOrbiterE = RotL64((aOrbiterE * 2901398809555237563U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 3690262236918560930U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3626005326410800344U;
            aOrbiterB = RotL64((aOrbiterB * 13030443356669355355U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10801089744186148218U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5446653082176311031U;
            aOrbiterJ = RotL64((aOrbiterJ * 4594267575901248321U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3205541585889107366U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4532327942368884436U;
            aOrbiterI = RotL64((aOrbiterI * 16287094987689326229U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9755333481079721632U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 722154154363571049U;
            aOrbiterC = RotL64((aOrbiterC * 11002432494248958957U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8071668483354405205U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 8770466248803121315U) ^ aNonceWordF;
            aOrbiterG = RotL64((aOrbiterG * 12780438190628717807U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1999251593502332271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3973833383430652211U;
            aOrbiterA = RotL64((aOrbiterA * 5325244982474631559U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterA, 46U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 3U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + aNonceWordE);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aNonceWordD) + aWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 50U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aWorkLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11175U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 14681U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12481U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16016U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14279U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 14919U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 22U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 10U)) + 15813325389431304548U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 41U)) + 2223874171125403602U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 5510483568496824130U;
            aOrbiterH = (aWandererD + RotL64(aCross, 29U)) + 15474152493495661876U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 21U)) + 16846339705130829195U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 60U)) + 1289670576865739669U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 35U)) + 18017354919647006944U) + aNonceWordF;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 8539685539928984921U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 37U)) + 3333721400836704048U) + aNonceWordL;
            aOrbiterI = (aWandererH + RotL64(aIngress, 51U)) + 2261560416623815491U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 4377786131746816567U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18047393176583722719U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8184724021940434631U;
            aOrbiterG = RotL64((aOrbiterG * 9800116157750921119U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 10469895939183324807U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 14543391765109879223U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4817987697437667225U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5757225781746158178U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3539000495894022869U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1032298408884695925U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11288971092707065923U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2761384065186568294U;
            aOrbiterD = RotL64((aOrbiterD * 3323838837427471051U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7120580145300417101U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6977246291769372866U;
            aOrbiterF = RotL64((aOrbiterF * 15170353875184253779U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17625434527765525937U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3299714663631376190U;
            aOrbiterB = RotL64((aOrbiterB * 6532628892760776767U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10331889953489885250U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8550932256881727932U;
            aOrbiterI = RotL64((aOrbiterI * 13085531621192583719U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11151195711186126257U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2552002192824926483U;
            aOrbiterJ = RotL64((aOrbiterJ * 9754056316698523849U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8038115194286715268U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16594489591573505305U;
            aOrbiterC = RotL64((aOrbiterC * 1241387574663818247U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 13476964484361081681U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2136330439951908303U) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 12728359054660550527U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 231990686776499700U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15813325389431304548U;
            aOrbiterE = RotL64((aOrbiterE * 9155088985405261637U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 46U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 26U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterK, 35U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterD, 21U)) + aNonceWordM);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererF = aWandererF + ((((RotL64(aCross, 37U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 30U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 48U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneB
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneB forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneC
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21509U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 20105U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 18034U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17288U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18414U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 20514U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 58U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (aWandererB + RotL64(aCross, 29U)) + 8604208734152026945U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 1374329953253889829U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 51U)) + 5779278910548228339U) + aNonceWordJ;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 41U)) + 17670451230882805140U) + aNonceWordE;
            aOrbiterE = (aWandererK + RotL64(aScatter, 5U)) + 8193848740764866860U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 19U)) + 15801168428145650104U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 37U)) + 2584718176087499066U) + aNonceWordI;
            aOrbiterB = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 14950366247822737997U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 37U)) + 9779293225265670135U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 57U)) + 8688968319288372383U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 3U)) + 13665723186950342601U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9395428688359973510U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2152719218018108418U;
            aOrbiterF = RotL64((aOrbiterF * 15271961483518392671U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1350324137411377992U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 8729317951386057921U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 6008790836417785083U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6317310451893678411U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10175620379041384281U;
            aOrbiterD = RotL64((aOrbiterD * 14079679617394330781U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1203082119358827708U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 523869107818193101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4629501113595689157U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4028324959540432983U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 15447631947468213912U;
            aOrbiterK = RotL64((aOrbiterK * 6037306615787729185U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14225888694733041031U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 11925000696281947629U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 4337022940520411253U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15015531024930608745U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16752579225076943550U;
            aOrbiterA = RotL64((aOrbiterA * 15551083683579981439U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2432733494869267901U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10103430321388601485U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 18372919379972432569U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15943360147468638325U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 9782703760233558733U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 685056980418243879U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18345087852012669037U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 8897505040792027675U;
            aOrbiterB = RotL64((aOrbiterB * 14333687539092412967U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7402581293947129667U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8604208734152026945U;
            aOrbiterC = RotL64((aOrbiterC * 9965525485538037673U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 6U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 21U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 47U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterB) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterH) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 56U)) + aOrbiterK);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterA, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI) + aNonceWordO);
            aWandererE = aWandererE + ((((RotL64(aScatter, 30U) + RotL64(aOrbiterF, 10U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererE, 58U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aFireLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneA
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25076U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 27576U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 29363U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31769U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30036U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 29099U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 27U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 12U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterH = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 13442819395490639310U) + aNonceWordB;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 39U)) + 8187292523194120936U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 3U)) + 11469697159823131388U) + aNonceWordI;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 52U)) + RotL64(aCarry, 35U)) + 13414083692375929653U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 47U)) + 11404010733687907517U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 11U)) + 6783212827186218247U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 13U)) + 8561131439340372614U) + aNonceWordF;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 47U)) + 6252609642004429113U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aScatter, 43U)) + 12804867444200448952U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 22U)) + 2739648749603690781U) + aNonceWordE;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 27U)) + 14808861217017399752U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17588866502571268888U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5882260142735642980U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 7688252946143263869U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15493099088132862949U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5175647411532429582U;
            aOrbiterJ = RotL64((aOrbiterJ * 15226544495598541883U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14279707376173642767U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6826363572161275158U;
            aOrbiterH = RotL64((aOrbiterH * 5263708315440161809U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13267185753040999992U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9980987858092888720U;
            aOrbiterD = RotL64((aOrbiterD * 13210290848800728635U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3582972937645514549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10140409019562890804U;
            aOrbiterE = RotL64((aOrbiterE * 6944490201647678479U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6160444117287330557U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16344602960561293113U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 2319964919335633293U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 3497141036108337171U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 91269118352540308U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5160060720189045505U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12739932748793144857U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12820180915064791197U;
            aOrbiterK = RotL64((aOrbiterK * 5843849637411948699U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17572075652083359962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10684041099654982701U;
            aOrbiterA = RotL64((aOrbiterA * 7121293375756263771U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10739534650885677354U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 9731206787727954809U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3730875775588585547U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 9655432616347117764U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13442819395490639310U;
            aOrbiterB = RotL64((aOrbiterB * 3650859301708619119U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 26U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterE, 11U)) + aNonceWordA);
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 19U)) + aNonceWordP);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterG, 34U)) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 36U) + aOrbiterK) + RotL64(aOrbiterJ, 53U));
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 40U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x910B70897E112A17ULL + 0xCCDDA49F98DB1BECULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEEC51D27B60A9395ULL + 0xF54D0BDEEA44AEA4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAD78583AFD1C109FULL + 0x9F2D9298008947F3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA68921DB3B1027D9ULL + 0x8768A588F266D58BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8B1A4531D2958A31ULL + 0xA541FB048E55C900ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD16C42EA2408C677ULL + 0xCB9B4CFFE0067D62ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x90F9B5D40D762BFDULL + 0xCB51FE0A9AE93222ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF235103A07B7620DULL + 0x919782794B7DDE49ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE86F26F08502AC7FULL + 0x8EBB35B3C29E55FEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x96317A82A8D83D85ULL + 0xB656545DE8C85C55ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD77405AEED62C5A9ULL + 0xA3AA35C16DA0F99AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x81519687611BA119ULL + 0xBF674C6BD953503CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x95F7901A08F2AA6BULL + 0xBFC45C3201091E73ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF419B0C139E7647FULL + 0xB4BC628AFBFB04F2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC7D38912EE6D3BC3ULL + 0xAB3D0F0587780A00ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8E8C1289EE899A1BULL + 0xFD85A33B36767D61ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneA, aOperationLaneC, aOperationLaneD, aFireLaneB, aExpandLaneA, aWorkLaneC, aWorkLaneD, aExpandLaneB, aFireLaneD, aWorkLaneB, aExpandLaneC, aFireLaneC, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2509U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 6192U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5196U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5649U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 881U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3768U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 26U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 4068921616130916949U) + aNonceWordF;
            aOrbiterC = (aWandererH + RotL64(aScatter, 27U)) + 12077715273915151726U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 34U)) + 16047546802670596833U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 43U)) + 9690277462716999763U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 57U)) + 14484814700447992628U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 39U)) + 17089267243053958210U) + aNonceWordE;
            aOrbiterD = (((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 13U)) + 9138746214446211147U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 10181001536979097045U;
            aOrbiterH = (aWandererB + RotL64(aCross, 14U)) + 6657458969093373191U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7515983477876590988U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 3039935555863947600U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 12511160550780270119U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16209389224740851136U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 725253312098083182U;
            aOrbiterK = RotL64((aOrbiterK * 17535989492095522597U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13307041115748941383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7159572004825238263U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 4855009895002398449U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12027236743251643820U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8717826175991286553U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 1175614802543098451U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 4769096034227659937U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11201226563992939616U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15595355978388159931U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17295978531215563256U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11850923890626719833U;
            aOrbiterC = RotL64((aOrbiterC * 3854851059897397075U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14139441565288097706U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 988684899382304485U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11929090869999700891U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6159251276942253175U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4849529993914550651U;
            aOrbiterJ = RotL64((aOrbiterJ * 18240712676783671317U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6679745455842119497U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15838404437552215214U;
            aOrbiterE = RotL64((aOrbiterE * 17357853511591350887U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 60U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 56U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 28U)) + aNonceWordL);
            aWandererK = aWandererK ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterE, 37U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterD, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 53U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 10U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordD);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterA, 43U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15757U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 11075U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9297U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14212U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16125U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 13820U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 4U)) + (RotL64(aCross, 29U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 57U)) + 8604208734152026945U) + aOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 40U)) + 1374329953253889829U) + aNonceWordC;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 35U)) + 5779278910548228339U) + aNonceWordF;
            aOrbiterB = (aWandererE + RotL64(aCross, 23U)) + 17670451230882805140U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 5U)) + 8193848740764866860U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 15801168428145650104U;
            aOrbiterC = (aWandererK + RotL64(aCross, 27U)) + 2584718176087499066U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 46U)) + RotL64(aCarry, 11U)) + 14950366247822737997U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 9779293225265670135U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 8688968319288372383U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13665723186950342601U;
            aOrbiterE = RotL64((aOrbiterE * 292035540396910837U), 47U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 9395428688359973510U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2152719218018108418U;
            aOrbiterG = RotL64((aOrbiterG * 15271961483518392671U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1350324137411377992U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8729317951386057921U;
            aOrbiterC = RotL64((aOrbiterC * 6008790836417785083U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6317310451893678411U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10175620379041384281U;
            aOrbiterB = RotL64((aOrbiterB * 14079679617394330781U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1203082119358827708U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 523869107818193101U;
            aOrbiterI = RotL64((aOrbiterI * 4629501113595689157U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4028324959540432983U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15447631947468213912U;
            aOrbiterH = RotL64((aOrbiterH * 6037306615787729185U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14225888694733041031U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11925000696281947629U;
            aOrbiterK = RotL64((aOrbiterK * 4337022940520411253U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15015531024930608745U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16752579225076943550U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15551083683579981439U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2432733494869267901U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 10103430321388601485U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 18372919379972432569U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 58U) + aOrbiterE) + RotL64(aOrbiterI, 6U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 53U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterA, 38U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneD
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19827U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((aIndex + 16909U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 23739U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23282U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 21144U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21794U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 20U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 5173905450211892891U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + 3555542451908039957U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 11559884700283861559U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 28U)) + 1352524329968738673U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 39U)) + 8914206450420616349U) + aNonceWordD;
            aOrbiterE = (((aWandererE + RotL64(aCross, 11U)) + 2251523378498463946U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 9541575923299247038U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 51U)) + 1239854507907214595U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 20U)) + 17698101462598498934U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 12305566971683256060U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13804545036303215569U;
            aOrbiterA = RotL64((aOrbiterA * 10359543704152744971U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10239749097704329264U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 4212214906286320308U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3661436621615751071U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12192418916967430783U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4475514289326450361U;
            aOrbiterF = RotL64((aOrbiterF * 17497164630368757887U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 17376102613298827459U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18129393209955439341U;
            aOrbiterD = RotL64((aOrbiterD * 6404089025014118979U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4014763724300253568U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 17325007199676828814U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 1420888274815627083U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15480474849292388685U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 14357924730184375449U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 16723492259068034209U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4335731868597970070U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8296023680394303015U;
            aOrbiterB = RotL64((aOrbiterB * 14027415401430120543U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2807312426993262800U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15510369660839648501U;
            aOrbiterI = RotL64((aOrbiterI * 18207954408298333959U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12597844696606519907U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7231012798553551535U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2841306785994479299U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 40U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterB, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 13U)) + aOrbiterI) + aNonceWordN);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 18U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 52U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterD, 39U)) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterI, 22U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterI) + aNonceWordA) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 10U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 29U)) + aOrbiterB) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31555U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneA[((aIndex + 24605U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 27376U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26813U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27715U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 30508U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 43U)) + 479672811032092393U) + aNonceWordM;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 29U)) + 18061121631394564425U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 52U)) + RotL64(aCarry, 29U)) + 14237400452740566065U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 39U)) + 6723123812257706134U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 47U)) + 4247997188026499248U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 19U)) + 1939107415066134869U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 3912640123546395979U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 35U)) + 8295478436553964298U) + aNonceWordN;
            aOrbiterE = (((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 41U)) + 3218960600711526885U) + aNonceWordH;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5874096203353388890U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10294536533673023358U;
            aOrbiterD = RotL64((aOrbiterD * 15561710414949058923U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 11268561953904130747U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16693201256788898423U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 16291987237693567209U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7550969634681894654U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9501647424602245869U;
            aOrbiterB = RotL64((aOrbiterB * 11265865222096866605U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8881869255994319423U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16770136406906800016U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1782039587385512923U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16185384746435761363U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13841034186650721627U;
            aOrbiterA = RotL64((aOrbiterA * 12000155593277035447U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15229062695864608309U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3576122704615303733U;
            aOrbiterH = RotL64((aOrbiterH * 2433987493885779279U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13898167174453181224U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12878032061609524049U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18104665741338251495U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12719156051299028649U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8640980843376950769U;
            aOrbiterF = RotL64((aOrbiterF * 10242616778390983333U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12133332160916004365U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8743563985229104484U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4575129690615054691U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 30U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 23U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 13U)) + aNonceWordA);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterE, 13U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterJ, 56U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 43U)) + aOrbiterA) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF82961BF59E65783ULL + 0xC7A04709723FBBF1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xE82783AC5C0291FFULL + 0xDE0D39BDDE7CB44AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEC4F3275841C0937ULL + 0xC918713BA523DCF7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA682DCC594E60931ULL + 0x91BAC7B2E5564EC5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD283EB76DB1BA255ULL + 0x9DF6EACBC187DDD6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB5F5C15397735A37ULL + 0xDE47941BA2B15DD7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9E4BDAC43E9E7D37ULL + 0xE24EA72D07B3E9F8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x84244A5D1B08F77BULL + 0xB91E0E6A8D80101EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8CE34A06E2679C41ULL + 0xA9CAA012AC8CF0DDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA49DE7EB2A4CA88DULL + 0xED366E6EA503BE6DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFDB350E551CBA673ULL + 0x84F1C79603A33FD1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEBB3259E7CF49E5BULL + 0xBB3E55B94F519594ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF061A737B91560B5ULL + 0xD722235F1E3FBC70ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF75EB461BECE4EE7ULL + 0xE7E496BEFB77DA44ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFA785140272E9125ULL + 0xFEDEC65F530EC44AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD1F455707C0939AFULL + 0x90F0C719FFA37E84ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aFireLaneD, aExpandLaneA, aOperationLaneD, aFireLaneB, aExpandLaneB, aOperationLaneB, aFireLaneC, aExpandLaneC, aOperationLaneC, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 269U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 2547U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 434U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8108U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4176U)) & S_BLOCK1], 54U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 698U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 60U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 20U)) + RotL64(aCarry, 51U)) + 2558105147674438050U) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 13U)) + 15856662514774702561U) + aNonceWordP;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 47U)) + 13346869226246584582U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 7632111846116243973U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 41U)) + 2102101361626976279U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 29U)) + 5605968705067851563U) + aNonceWordN;
            aOrbiterC = (aWandererA + RotL64(aCross, 3U)) + 6842483186584326681U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5559797213819425064U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12422313931331576759U;
            aOrbiterE = RotL64((aOrbiterE * 7399849122565913401U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2751024420047872601U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11031320239359798610U;
            aOrbiterH = RotL64((aOrbiterH * 8607639453141148025U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14366375309473793217U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11971479429768505316U;
            aOrbiterF = RotL64((aOrbiterF * 10063001532313098203U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3947595951884469542U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 17882767922372770896U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 513871456983509223U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5951677013597794294U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 8508629569649935293U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 437626309049021931U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 466674061172005705U;
            aOrbiterJ = RotL64((aOrbiterJ * 1310502572084891157U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12362602809233133718U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10525852878882195702U;
            aOrbiterA = RotL64((aOrbiterA * 17755022180514914325U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 14U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 12U) + aOrbiterI) + RotL64(aOrbiterF, 3U)) + aNonceWordB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordE);
            aWandererF = aWandererF ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 48U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10908U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 9657U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14997U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15495U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14330U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11188U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 41U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 11U)) + 12426357877879529292U;
            aOrbiterH = (((aWandererB + RotL64(aIngress, 53U)) + 12604900366173639176U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 13511119007338929401U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 5U)) + 9878720081166788060U) + aNonceWordP;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 15463195409806395076U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aScatter, 35U)) + 6407922778852833423U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 42U)) + RotL64(aCarry, 57U)) + 7690427254160734016U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18030974031722143619U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterG) ^ 17983938038322737041U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 12479365337221685413U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16605512170117753884U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 681802273302348322U;
            aOrbiterH = RotL64((aOrbiterH * 14608920184802647123U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15550312921312083819U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17824154101711884508U;
            aOrbiterG = RotL64((aOrbiterG * 7358612830654795357U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1939207786756735430U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3132864634777826569U;
            aOrbiterA = RotL64((aOrbiterA * 13606281919426730325U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12822929773923954849U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16576106045887115660U;
            aOrbiterK = RotL64((aOrbiterK * 16370914370769903051U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2398825881649235260U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13700821892926092479U;
            aOrbiterF = RotL64((aOrbiterF * 10830623703416956043U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2439833784883391606U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 15870638514107637833U;
            aOrbiterC = RotL64((aOrbiterC * 3797380922767479287U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 21U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 41U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 12U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + aNonceWordC);
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterH, 35U));
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterK, 20U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 56U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23113U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 22367U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 18546U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19145U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23361U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 17228U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 58U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 1898718075389870739U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 11U)) + 5631794889237247403U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 18219714659484524607U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 21U)) + 15419581386225732921U) + aNonceWordB;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 37U)) + 9125575431710198210U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 56U)) + 12205871520544965505U) + aNonceWordK;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 7617534300497343422U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 18017579105368135814U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10693882161946020042U;
            aOrbiterF = RotL64((aOrbiterF * 2326507900303932855U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11669615701700895306U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11045110212889232165U) ^ aNonceWordG;
            aOrbiterA = RotL64((aOrbiterA * 5965171269273719849U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18019107802806469913U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 12315940560472528716U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4505122470351404065U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4899009736070044310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17412253404253730364U;
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4826286251927854181U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4523455921321845084U;
            aOrbiterJ = RotL64((aOrbiterJ * 14534103906736598099U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4132514462154182215U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7164745605985109269U;
            aOrbiterG = RotL64((aOrbiterG * 14107325508977225261U), 5U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 6297434295807635654U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 8813887638672996646U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 17495632530773158201U), 27U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 53U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aIngress, 40U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 21U)) + aOrbiterJ) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 35U)) + aOrbiterE) + aNonceWordO) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 12U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterF, 47U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 4U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29237U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((aIndex + 26610U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27656U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25584U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31285U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28867U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 19U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterA = ((aWandererH + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 17711946802293254150U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 19U)) + 16652362590489569378U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 54U)) + RotL64(aCarry, 57U)) + 6972810344198183097U) + aNonceWordC;
            aOrbiterB = ((((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 13117100889782940546U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererJ + RotL64(aCross, 47U)) + 13199305696782626591U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 11U)) + 992156184392760945U) + aNonceWordH;
            aOrbiterF = (aWandererD + RotL64(aIngress, 29U)) + 13791265442074543880U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17057087245252294859U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13444195995883541046U;
            aOrbiterJ = RotL64((aOrbiterJ * 13067044288608808777U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6723678233676059420U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 7913379431208430475U) ^ aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 2295062944289127123U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4481887195529300665U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11892724101424384078U;
            aOrbiterK = RotL64((aOrbiterK * 3468639499716604111U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7700902083270424194U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 1888001433557140271U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 8975562955027025349U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14996753906788986929U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 939004845422123765U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2507090308972292313U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11922230289291941807U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15681187459741147199U;
            aOrbiterA = RotL64((aOrbiterA * 10124947739653819101U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9119043713532718155U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 8327697433992362166U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 11157657162184304567U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + RotL64(aCarry, 41U)) + aNonceWordB) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + aNonceWordP) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterF, 60U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
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
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x934D13E4D46C80F7ULL + 0xA7F4D5538917496BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDB3EE5D8B96AC169ULL + 0x815EAD6D2FA6225DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x80E7137E07F73607ULL + 0xEA5F72704910ED97ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDB9D81360200FB9DULL + 0x8C0A11C961CE4109ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD8ACB4193D65B781ULL + 0x8B5B36D063BB1A1DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFEACC69530616935ULL + 0xCA391D97DD627263ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFB85C2E8D1119F23ULL + 0xD33C675B89161C2BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8A0FF2BD38E2E3BFULL + 0x9D92E7DDB53FEB26ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC006E16C3181D0C3ULL + 0xE9108E1856C720A1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x982752549AC69C2FULL + 0xA672686DFDBBC6FEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFA2FF7B0DC2C32EBULL + 0xB5F592B9BEB9AE0DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCB72D1D7B839244BULL + 0xE536725FAB85BD37ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDB0B7A900DDEB63DULL + 0xA2A8F01AA51A2FF0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x983CF7323E083D49ULL + 0x9C9B95BE6C643412ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCFEBEF91383C2159ULL + 0xDF7F03785AE55808ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8F447B3C1F5CC275ULL + 0xF8002D7C53108A6FULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 588U)) & W_KEY1], 30U) ^ RotL64(aKeyRowReadB[((aIndex + 2251U)) & W_KEY1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1287U)) & W_KEY1], 36U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1533U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 3U)) + 5088525177670191619U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 9966456257813932112U) + aNonceWordA;
            aOrbiterA = ((((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 53U)) + 7707646574027146307U) + aPhaseEOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererG + RotL64(aIngress, 37U)) + 75480203757681173U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 43U)) + 384659134071835163U) + aNonceWordJ;
            aOrbiterE = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 3158769775373307778U) + aNonceWordC;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 51U)) + 17360830943513941272U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5317278822721604586U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1371427105215954781U;
            aOrbiterA = RotL64((aOrbiterA * 10956603063464438611U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3162710551223553423U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5332921933853550756U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11709546145149357887U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10572462410297815854U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10234389605554817892U;
            aOrbiterI = RotL64((aOrbiterI * 2130374833440291193U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13421365517991380605U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10186643614984034083U;
            aOrbiterJ = RotL64((aOrbiterJ * 8554471709467808453U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4742438973260817120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6081590345899008846U;
            aOrbiterB = RotL64((aOrbiterB * 7069396301823124931U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15360092808493795340U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12186413069553132646U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 3815981440611914267U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16756221656224451552U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12232880965861373143U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14196910735715726471U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 26U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 50U) + aOrbiterG) + RotL64(aOrbiterB, 35U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterB, 43U)) + aNonceWordI) + aPhaseEWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 57U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aNonceWordE) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4500U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 3529U)) & W_KEY1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3062U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5161U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 5295352595333316211U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 11U)) + 2341795367042042605U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + 10122175780504033663U) + aNonceWordB;
            aOrbiterI = (((aWandererC + RotL64(aCross, 19U)) + 10084612804696198554U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 35U)) + 16470424309851045971U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aScatter, 3U)) + 656016130975227994U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 15313268829659834317U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3795220914993923394U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14044442220988813825U;
            aOrbiterD = RotL64((aOrbiterD * 3270650852546606835U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3804224626734584802U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 7980006306010255693U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 13958505239726088561U), 11U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 13746830564584711549U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11852212099729274845U;
            aOrbiterJ = RotL64((aOrbiterJ * 2164880979318247855U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9083223471018084847U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13706723820703853346U;
            aOrbiterH = RotL64((aOrbiterH * 11361854103656219887U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1713819986642275223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1382000168233902914U;
            aOrbiterE = RotL64((aOrbiterE * 3894160765130198157U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 4540474625764565485U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1756168174375757220U;
            aOrbiterF = RotL64((aOrbiterF * 12739160208010092017U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 1409297070183609309U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6082750101445444357U;
            aOrbiterI = RotL64((aOrbiterI * 17438740230251860935U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 41U)) + aOrbiterH) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aCross, 10U) + aOrbiterF) + RotL64(aOrbiterE, 3U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 57U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6773U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6810U)) & W_KEY1], 40U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6825U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8017U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6164U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 56U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 14499676118633326000U) + aNonceWordD;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 57U)) + 17191273593018552288U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 4085176294948097737U) + aPhaseEOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 51U)) + 11112671474158908186U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordI;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 4U)) + 8745787969012266485U) + aNonceWordE;
            aOrbiterD = ((aWandererI + RotL64(aCross, 29U)) + 18074049663777707948U) + aNonceWordB;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 2543758649719164688U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4659584749412700523U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 974639159259871273U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 17918719351847605523U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9211220687971081987U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8567024626862182714U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7755874089832496393U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5803002132294840900U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11968489432878148467U;
            aOrbiterI = RotL64((aOrbiterI * 4501441062617123165U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9470807228394903442U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 1692347973120388469U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17433393164156231575U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16510815732690193145U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 755159406833096510U;
            aOrbiterE = RotL64((aOrbiterE * 14091736464659561165U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 1518824876475937620U) + aNonceWordP;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 701225390867330446U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 12264618860580199927U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8425976693733003889U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7182176375442410367U;
            aOrbiterD = RotL64((aOrbiterD * 8860605703761731859U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 23U)) + aNonceWordN) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 35U));
            aWandererG = aWandererG + (((((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 53U)) + aNonceWordG) + aPhaseEWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 19U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 4U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 58U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8570U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 8231U)) & W_KEY1], 14U));
            aIngress ^= (RotL64(mSource[((aIndex + 10558U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 9082U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 10395U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10665U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 38U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 19U)) + 1457104756581596530U) + aNonceWordE;
            aOrbiterK = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 6127240317844622874U) + aPhaseFOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 41U)) + 16492290056044189421U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 27U)) + 10963676850938416468U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 4872917367399752405U) + aNonceWordG;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 15218882377875616148U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 53U)) + 5934166612122118251U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14215280930872003003U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11428034799044600979U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12162528943733976177U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5453003654321728726U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14273775120265649389U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5139018128323795309U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 328723770018440271U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13032190719588211088U;
            aOrbiterE = RotL64((aOrbiterE * 13363368478932798315U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 2386881543033598494U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1649501123340887116U;
            aOrbiterI = RotL64((aOrbiterI * 11148976582360499033U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16462401546754210583U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 1510579201823042227U;
            aOrbiterK = RotL64((aOrbiterK * 16287912400104043275U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6889066000014251983U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 11324594596597724357U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 15344987814648586023U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12237796033168436537U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17306069670330000343U;
            aOrbiterG = RotL64((aOrbiterG * 3167451351403385259U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 48U) + aOrbiterA) + RotL64(aOrbiterH, 6U)) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aNonceWordK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aNonceWordC);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 19U)) + aOrbiterA) + aNonceWordL) + aPhaseFWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterK) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11551U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 11382U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13521U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 12256U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13106U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11170U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12091U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 56U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererB + RotL64(aCross, 11U)) + 4634399531433127141U) + aPhaseFOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aIngress, 3U)) + 16961792729406903200U) + aNonceWordL;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 57U)) + 4105280732301137738U) + aNonceWordC;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 15692013501147331191U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 51U)) + 1252216715968780587U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 18U)) + RotL64(aCarry, 13U)) + 7958289043012473752U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 57U)) + 6611577301818896615U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8506226754305949140U) + aNonceWordE;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3648813120449403353U;
            aOrbiterB = RotL64((aOrbiterB * 9521367946879238849U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5195245426245535735U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterA) ^ 542948051600803051U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 4631106308856448475U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11974253551208964789U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10596463592332655367U;
            aOrbiterH = RotL64((aOrbiterH * 10941161258815714641U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12015129484061440159U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 8254944355710109060U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 3233697992479357615U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2754858806943915419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5007802002906662779U;
            aOrbiterD = RotL64((aOrbiterD * 15613733948331639723U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6262190752136523216U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10528977986487821428U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1184258264034585525U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8511097226098211854U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 12091864735686692582U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 6128140528141411237U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 58U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 3U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterH, 13U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterG, 40U)) + aNonceWordM) + aPhaseFWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterA) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15360U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14166U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16157U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14148U)) & W_KEY1], 24U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15003U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16096U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13790U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 18U)) + (RotL64(aCarry, 35U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 6U)) + 3561491146322798260U) + aNonceWordC;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 7075025056181885339U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 5U)) + 9230910887904171613U) + aPhaseFOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 4119781172609908917U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 35U)) + 17155609083870983149U) + aNonceWordB;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 47U)) + 2423018561430181695U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aScatter, 41U)) + 12957280305617615744U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 2461704174772065813U) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7907123257849391997U;
            aOrbiterG = RotL64((aOrbiterG * 9416171962847312179U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7257868138318960007U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16425903703085702285U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7996935869077231999U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2990822664594079467U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5654819006718953817U;
            aOrbiterH = RotL64((aOrbiterH * 4465096036756887801U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 12183676471235678779U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15026286960542123922U;
            aOrbiterE = RotL64((aOrbiterE * 17199049329995315279U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12169080607071830522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2906296852254787499U;
            aOrbiterI = RotL64((aOrbiterI * 6754514406846040163U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 3029858695410344584U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 14406410317495954566U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9663780721657983421U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 11048818178401163861U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13622063920319445043U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 2516025554421589857U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterD, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 19U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererC = aWandererC + (((RotL64(aCross, 28U) + RotL64(aOrbiterE, 46U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 57U)) + aOrbiterG);
            aWandererF = aWandererF + ((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + aNonceWordH) + aPhaseFWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16483U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 19024U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(mSource[((aIndex + 17823U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18846U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17194U)) & W_KEY1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17150U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16563U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 50U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = ((((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 6068543441070417854U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererD + RotL64(aCross, 29U)) + 2995980468193441856U) + aNonceWordF;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 3U)) + 18020277482171594003U) + aNonceWordE;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 4293807434721230702U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 41U)) + 7980599111583893156U) + aPhaseGOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 53U)) + 8593141111851052016U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 47U)) + 5903487523900084325U;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterE) + 15112035513447930209U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9854037263057006439U;
            aOrbiterJ = RotL64((aOrbiterJ * 396276470208637283U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16759760289688823193U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12622628933030601390U;
            aOrbiterK = RotL64((aOrbiterK * 2151912984825538321U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1264668857268123425U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16302812053619101593U;
            aOrbiterH = RotL64((aOrbiterH * 18291400055836111547U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16087995784896123610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7970269262800468363U;
            aOrbiterB = RotL64((aOrbiterB * 14924752223305807461U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5331477046030959632U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16534913204255550893U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 1013433634373673565U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11042821902537871209U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 8069677512345031660U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 13622218526054132397U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5737130058129936372U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1076627182956662997U;
            aOrbiterE = RotL64((aOrbiterE * 14342191224014199929U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 53U);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + RotL64(aOrbiterK, 41U)) + aOrbiterA) + aPhaseGWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 48U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 20012U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 19205U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21025U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21306U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19744U)) & W_KEY1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21464U)) & W_KEY1], 5U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19268U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19552U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 6U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 14157904117287696136U) + aNonceWordN;
            aOrbiterK = ((aWandererC + RotL64(aCross, 29U)) + 7369512677371640676U) + aNonceWordI;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 8411250745902073798U) + aNonceWordC;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 41U)) + 5002041814539710275U) + aNonceWordO;
            aOrbiterA = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 27U)) + 9538041410816283124U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aIngress, 6U)) + 5210700103927513061U) + aPhaseGOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aScatter, 13U)) + 7600709399101287982U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2366369466696580499U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 5544575244203019109U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 16231219246786333057U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8710073749110329779U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 15998211310115361630U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 15275657696897688955U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15354357553877376422U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10657523549259276169U;
            aOrbiterC = RotL64((aOrbiterC * 13695239532898311073U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10405750198355464768U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3465819693133515142U;
            aOrbiterJ = RotL64((aOrbiterJ * 14678343718277562799U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16724189641701408630U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3484340153620198872U;
            aOrbiterE = RotL64((aOrbiterE * 17247547677520703125U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7420442404884871126U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11138445997256757636U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 11167543379937571127U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1428191560884663125U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 16950093140800653985U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4423012306984814805U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterC, 12U)) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterK, 57U)) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + aNonceWordB);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 23U)) + aOrbiterG) + aNonceWordG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterC, 39U)) + aPhaseGWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23633U)) & S_BLOCK1], 27U) ^ RotL64(aKeyRowReadA[((aIndex + 24447U)) & W_KEY1], 53U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23271U)) & W_KEY1], 19U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21961U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22694U)) & S_BLOCK1], 57U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 23415U)) & S_BLOCK1], 12U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21997U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22067U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 10812151398716051703U) + aNonceWordN;
            aOrbiterK = (aWandererH + RotL64(aScatter, 5U)) + 18202551453336003710U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 9434410809101973752U;
            aOrbiterE = (((aWandererC + RotL64(aIngress, 36U)) + 12955829998028534045U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 12271740641929640181U) + aPhaseGOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 51U)) + 14009351527014534752U;
            aOrbiterB = (aWandererD + RotL64(aCross, 11U)) + 4316296955679133450U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16473324966997442872U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15735123324965019802U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5624078184997601019U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17656375090484080236U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16066325053456055298U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17912970706985130327U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12908968778503516903U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12761433987676836197U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 1023329467480907925U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12737513138040664509U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14535795767570998392U;
            aOrbiterF = RotL64((aOrbiterF * 15560519667062222269U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14370908061811284364U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7001358781208669795U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 11641248025734015835U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7298578161120090849U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10498302152357484629U;
            aOrbiterG = RotL64((aOrbiterG * 13144110412179037175U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11447343228638006767U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 18284143620422655675U;
            aOrbiterE = RotL64((aOrbiterE * 572862190073605651U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 42U) + aOrbiterF) + RotL64(aOrbiterC, 21U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + aNonceWordB) + aPhaseGWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterE, 41U)) + aOrbiterF) + aNonceWordL) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 56U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterB, 11U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 27147U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadA[((aIndex + 24792U)) & W_KEY1], 41U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26275U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 24911U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26797U)) & W_KEY1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25802U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26686U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 26843U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aPrevious, 47U)) ^ (RotL64(aCarry, 20U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterF = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 14249093584376402677U) + aPhaseHOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 44U)) + 8756965951816492264U) + aNonceWordF;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 29U)) + 11221139480258176330U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 17218894445564194851U) + aNonceWordE;
            aOrbiterK = (((aWandererH + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 8064642692524949490U) + aPhaseHOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 23U)) + 5822093203710704646U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 35U)) + 3217799620158102238U) + aNonceWordN;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2613757677892120843U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13647481499551657237U;
            aOrbiterD = RotL64((aOrbiterD * 5517563514031899891U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3545714196663685016U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9735422670576621521U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7276207208162697249U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3911046580637583767U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9315984027042049203U;
            aOrbiterG = RotL64((aOrbiterG * 12568550776487242469U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 8926367674641729058U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11035347490524961446U;
            aOrbiterB = RotL64((aOrbiterB * 10948288997163592463U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10748158733051120339U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2467801787989056455U;
            aOrbiterK = RotL64((aOrbiterK * 12621934274702358977U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 9244415080474351390U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8517784887959492079U;
            aOrbiterE = RotL64((aOrbiterE * 17022899813765884147U), 13U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 8409307332803038455U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11043806021873232950U;
            aOrbiterF = RotL64((aOrbiterF * 8294888329708842989U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterK, 12U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aNonceWordJ);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + aNonceWordM) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterG, 50U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29146U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneD[((aIndex + 28912U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 28067U)) & W_KEY1], 46U) ^ RotL64(aFireLaneC[((aIndex + 29849U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28148U)) & W_KEY1], 54U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28198U)) & S_BLOCK1], 35U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27437U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((aIndex + 27763U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 13U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterA = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 15549114274303128055U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 16466750056388063241U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 52U)) + 12209449840836787142U) + aNonceWordE;
            aOrbiterC = (aWandererA + RotL64(aScatter, 37U)) + 14551496099734294336U;
            aOrbiterI = (((aWandererH + RotL64(aCross, 21U)) + 6266576428679808622U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 16892841575635668152U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 27U)) + 7375966221423362125U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11926105302821753530U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16219253791550461124U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2117550758226173419U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7299056065319248160U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15234001484933728439U;
            aOrbiterI = RotL64((aOrbiterI * 8182244796017018911U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6615802589932632120U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 5481176858895819247U;
            aOrbiterH = RotL64((aOrbiterH * 3604590158551984877U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17220507586542139380U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 14137921473739415340U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 10634645686035907603U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16981960446540932787U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10897565927079518588U;
            aOrbiterD = RotL64((aOrbiterD * 418843936329303571U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2746889569299593263U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4894117146736361379U;
            aOrbiterC = RotL64((aOrbiterC * 2656750612042673191U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 18294823016957137777U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 86828501068883383U;
            aOrbiterA = RotL64((aOrbiterA * 11432686669235402365U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aCross, 60U) + RotL64(aOrbiterI, 3U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordJ) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aNonceWordG) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 29U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterI, 36U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31202U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 31115U)) & W_KEY1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30965U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31615U)) & S_BLOCK1], 3U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30137U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30221U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 4U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 29U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererH + RotL64(aScatter, 60U)) + 4476099022490972343U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 11U)) + 16836423700375760429U) + aNonceWordK;
            aOrbiterI = (aWandererG + RotL64(aCross, 39U)) + 8850577488928703557U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 51U)) + 7091631824560042743U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 12560498899956759494U) + aNonceWordB;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 7797973377112012161U) + aPhaseHOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 6173820673874805794U) + aNonceWordN;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10805025132310245348U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7139216143268029968U;
            aOrbiterI = RotL64((aOrbiterI * 8349754682635765573U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8241544862261635722U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4735527016563596150U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 6621354217673598381U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5166171126690294033U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11117641762075368393U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 4980156869201219393U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6312932356458415421U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1304139291184508668U;
            aOrbiterC = RotL64((aOrbiterC * 90744653170922319U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10085025354842771067U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16745854428789531080U;
            aOrbiterG = RotL64((aOrbiterG * 1945983905747274355U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2497187958708890337U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 16069701876646548995U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16606039730973709495U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17242004368025978091U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12334315722243232121U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 16528598396696346719U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 26U));
            aWandererA = aWandererA + (((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 50U) + RotL64(aOrbiterC, 37U)) + aOrbiterD) + aNonceWordG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 29U)) + aNonceWordM) + aPhaseHWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + aNonceWordC);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB707BD7CCDB8FD73ULL + 0xA4349C98157B0673ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE8BC06C5EA79C787ULL + 0x92108D871D62C2C8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA5B347C68806F5EFULL + 0xA1354D54D0A45E77ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDC8135B5777FE273ULL + 0x8EB5A73989EF0B29ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE0506834BA6D1071ULL + 0xE4E97A95AC7B9263ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCAE9A68FAC92EE77ULL + 0xF77998A354333364ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE2BB185C4408A707ULL + 0xC5B895364646C34EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF3D6A39CA72493CBULL + 0xD80684072D64C864ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9A21C807D85D8B33ULL + 0x9F3F5E1F9BA0B50BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x898A5963F1D3AC33ULL + 0x8C948B12D0DE69B2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBB909E82167367F5ULL + 0xEE18D123AEA6E804ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9D7DA2683AB5DB55ULL + 0xAB028ABE3381F353ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9C36793DC2A111E3ULL + 0x83578B3C2F5B4E0CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x82829AF3214684FDULL + 0xD8BA75C4C645D198ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDE42857C64012E9DULL + 0xEB8FDA13298AFDE3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC38B5A533B6B0405ULL + 0x9C1AE3ECDF349BC6ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3469U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 2931U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 1663U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1702U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 1400U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 28U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 21U)) + 6916817163240024692U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 37U)) + 14554930751292077817U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 29U)) + 1098305064484336101U) + aNonceWordK;
            aOrbiterB = ((((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 12192821172420471527U) + aPhaseAOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = ((((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 2435134991707318845U) + aPhaseAOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterE) + 1896745368738512624U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1114996424222923873U;
            aOrbiterD = RotL64((aOrbiterD * 6248754732325773087U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9839135798371512656U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8037967239603177043U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 7848951103759663025U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 15185468738487237432U) + aNonceWordC;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4912098316394854543U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3072785550384399929U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 13142688607850380888U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4507379759608945839U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 2989332387754215967U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7299006009652289342U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5390655277207053627U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10973744708856143715U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterB, 4U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + aNonceWordA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 35U)) + aOrbiterI);
            aWandererI = aWandererI + (((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterK) + RotL64(aCarry, 35U)) + aNonceWordE) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 14U)) + aOrbiterD) + aNonceWordF);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 10622U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 9410U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10553U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10216U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 6641U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 34U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 12632404972795375757U;
            aOrbiterC = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 29U)) + 5351879979055988456U) + aNonceWordJ;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 35U)) + 3597737727467443413U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 48U)) + RotL64(aCarry, 11U)) + 2830846754917852318U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 21U)) + 17311925960294518018U) + aPhaseAOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2083584640523695383U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15049343611387010158U;
            aOrbiterE = RotL64((aOrbiterE * 5567816356477420399U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6443050378205811147U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 6021965178697344070U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6054064448935006741U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5080289878758029976U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 576927745306972983U;
            aOrbiterI = RotL64((aOrbiterI * 16008958833683246115U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4728489691382690859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6184355840165758855U;
            aOrbiterC = RotL64((aOrbiterC * 1515043910404156423U), 53U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 11220539885798595450U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11091438724966718214U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8225347114759391961U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterI, 12U));
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + aPhaseAWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterE, 3U)) + aOrbiterF) + aNonceWordK) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11413U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 15172U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13608U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13028U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16179U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12924U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 51U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = ((((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 15316464782468770057U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 6642872057476351588U) + aNonceWordG;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 3U)) + 660732654689529192U) + aNonceWordJ;
            aOrbiterB = ((aWandererD + RotL64(aCross, 20U)) + RotL64(aCarry, 21U)) + 7235418086884000655U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 11U)) + 14784518476694580493U) + aPhaseAOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12222433977933449375U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8573001207708329927U;
            aOrbiterG = RotL64((aOrbiterG * 17771120145431297541U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 16035256260815013172U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15767726974121910203U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 719060452537759331U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 17712217935322939971U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 13488963456923357159U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 16785285630840310405U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10222949131965611079U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1495561412321657209U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9706305581868526265U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 16156530750584361434U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7773792489045606309U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 10730624207715601393U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 28U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 13U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aNonceWordC) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 38U)) + aOrbiterH) + aNonceWordK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 37U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + aOrbiterK) + RotL64(aOrbiterD, 27U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 57U)) + aNonceWordH) + aPhaseAWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19660U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneA[((aIndex + 19977U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18179U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18500U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16938U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 20644U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 37U)) ^ (RotL64(aIngress, 18U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererG + RotL64(aScatter, 26U)) + RotL64(aCarry, 11U)) + 6342299552323486695U;
            aOrbiterF = ((((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 12692748514781367538U) + aPhaseAOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 8202639945493229155U;
            aOrbiterI = (((aWandererJ + RotL64(aPrevious, 3U)) + 4439975701793231639U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 37U)) + 16774235182859553759U) + aNonceWordD;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8764155413335405667U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7167848811974967685U;
            aOrbiterK = RotL64((aOrbiterK * 1052856924757654735U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16768278912125334220U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9090838954826296201U;
            aOrbiterG = RotL64((aOrbiterG * 5459329624017272077U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7644075729758006298U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17326182797908071215U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2408330168749256075U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16158809721888137555U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterJ) ^ 8029938783858263694U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 12628072435324195483U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8716553521415553404U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7012599977009208840U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8775355876188948851U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 46U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 13U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + aNonceWordL) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 40U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 54U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererG, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23004U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 21920U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26453U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24903U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23734U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27253U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 10U) ^ RotL64(aCarry, 39U)) + (RotL64(aPrevious, 27U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = (((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 13U)) + 5160910997561396461U) + aNonceWordA;
            aOrbiterG = ((((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 14920764751058512062U) + aPhaseAOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((aWandererI + RotL64(aCross, 3U)) + 6080952401749660022U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 17667234330526298627U;
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 760630072638686756U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3504157162816997476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9489022223422585882U;
            aOrbiterD = RotL64((aOrbiterD * 2398110457196177747U), 43U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 1149898536879968964U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10492284328940025310U;
            aOrbiterG = RotL64((aOrbiterG * 7893416766300156495U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 13213275606286399312U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10557118912847180413U;
            aOrbiterF = RotL64((aOrbiterF * 10077877991284587845U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 15618980209023994776U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5268600749854045564U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3849660559223919613U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8011552687609649990U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3148133096349525066U;
            aOrbiterK = RotL64((aOrbiterK * 5245156554959620007U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterK, 24U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 47U)) + aNonceWordC) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 4U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 19U)) + aNonceWordE);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterD, 52U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterD, 11U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28020U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 30863U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 31046U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30308U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27777U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 29683U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 36U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = (((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 9914837590440975587U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 37U)) + 6706125076401958051U) + aNonceWordO;
            aOrbiterG = (((aWandererK + RotL64(aCross, 3U)) + 16570817772679258409U) + aPhaseAOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 39U)) + 6843705658115186948U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 16099930446791572351U) + aNonceWordK;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 5420550009556030459U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5729549069420177477U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7842192631021712569U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15590601126188675834U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 13044027390998620029U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 16845199115313444123U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11068338135659636772U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 6584988841809544332U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 1683336180438945439U), 3U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 8516813219883915404U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10647314042912492785U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15559481057047148785U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 201691689889605304U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15512161798401184003U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 11473219183982564709U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterB, 58U)) + aNonceWordJ);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterI, 21U)) + aNonceWordF) + aPhaseAWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 4U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + aNonceWordP) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFE0FB1CDE8320A8BULL + 0xD041AD9BFCBAB345ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB084229F91B630EDULL + 0x858DDB73923EBE54ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA54627D829E51D67ULL + 0xAFE6AEC8EFCCF2A8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8712CA902C4B468DULL + 0xACC37FE15965A46AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD8D3F368EA44B0A9ULL + 0xB625508CAEEB78E0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEB18DD276DE67B25ULL + 0xE2B6257DA8B1EC31ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF4C14235D3CADF3BULL + 0xA40147091245A8DEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA98981882956D975ULL + 0xF7A5A9E504F228DBULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x850200172D0A2C45ULL + 0xC2DB3EAB81360D7DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD26925A65B2BDA7FULL + 0xE5A67F7413D96514ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xDBBBCEC8B23D1719ULL + 0x84E3FD33B4706AECULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x83379ABD2BEF6321ULL + 0xB251EEF8B45FB888ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8C75063E604C6C0DULL + 0xBDE616F2DA565647ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF5C34D8D1EF07A39ULL + 0xD6B03D1E995B8643ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC16724DF7281234BULL + 0x91DEB70908F919F2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x97B19CEC6FEB71A9ULL + 0xB421C354C3651D91ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneB, aOperationLaneC, aOperationLaneD, aExpandLaneB, aInvestLaneC, aExpandLaneA, aFireLaneC, aInvestLaneD, aFireLaneA, aWorkLaneA, aFireLaneD, aWorkLaneB, aExpandLaneC, aWorkLaneC, aExpandLaneD
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3642U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 1810U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5000U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2668U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5439U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 4962U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 21U)) ^ (RotL64(aPrevious, 34U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 57U)) + 4848316479321533394U) + aNonceWordI;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 44U)) + 6919360256662636195U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 3U)) + 9897013582181108544U) + aNonceWordH;
            aOrbiterG = (aWandererB + RotL64(aScatter, 27U)) + 7319353809896158678U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 53U)) + 2848175435514849859U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aWandererD + RotL64(aCross, 23U)) + 6967780718720437934U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 48U)) + RotL64(aCarry, 53U)) + 10143884766603388136U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 11U)) + 8675965006150972051U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 16350117755560994281U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17976597517118423760U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1399631141355370237U;
            aOrbiterF = RotL64((aOrbiterF * 16537788276543236833U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3590613762034716792U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5134624314245932157U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13077589037975283371U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10082236952942943654U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 4015535035905433450U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 4961808568701908559U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 611474103801573800U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5786708483794098001U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 7694007039340089267U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5201943497363274455U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9282160506938328489U;
            aOrbiterJ = RotL64((aOrbiterJ * 5368182164239021367U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 4932320527498940158U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11576526341731392916U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 1712051774729439363U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10790691517638887125U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16280649213607464422U;
            aOrbiterH = RotL64((aOrbiterH * 10756733801499471873U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9553716940667712810U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 11827518270964003341U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1322489827908132831U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16777463701235809321U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3375489084588454149U;
            aOrbiterB = RotL64((aOrbiterB * 3335010977457647307U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 58U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererF = aWandererF + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterD, 19U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + aNonceWordN) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 42U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 4U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aFireLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 9920U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 9084U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7726U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10429U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 9371U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9437U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8201U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = ((((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 17711946802293254150U) + aPhaseBOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 19U)) + 16652362590489569378U;
            aOrbiterC = ((((aWandererF + RotL64(aScatter, 26U)) + RotL64(aCarry, 57U)) + 6972810344198183097U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 13117100889782940546U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 51U)) + 13199305696782626591U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 3U)) + 992156184392760945U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 41U)) + 13791265442074543880U;
            aOrbiterK = (aWandererG + RotL64(aCross, 46U)) + 17057087245252294859U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 13444195995883541046U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6723678233676059420U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7913379431208430475U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 2295062944289127123U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4481887195529300665U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11892724101424384078U;
            aOrbiterJ = RotL64((aOrbiterJ * 3468639499716604111U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7700902083270424194U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1888001433557140271U;
            aOrbiterI = RotL64((aOrbiterI * 8975562955027025349U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14996753906788986929U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 939004845422123765U;
            aOrbiterF = RotL64((aOrbiterF * 2507090308972292313U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11922230289291941807U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15681187459741147199U;
            aOrbiterE = RotL64((aOrbiterE * 10124947739653819101U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9119043713532718155U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 8327697433992362166U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11157657162184304567U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13630755116592440359U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 771252613886022889U;
            aOrbiterB = RotL64((aOrbiterB * 2958918915223536519U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8524239721467527770U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 17732617735422435572U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13992947983987668631U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5265753270696005619U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14456128349522985053U;
            aOrbiterH = RotL64((aOrbiterH * 5406509991740849617U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 14U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 29U)) + aOrbiterB);
            aWandererC = aWandererC + (((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 53U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordM) + aPhaseBWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 18U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 48U) + aOrbiterH) + RotL64(aOrbiterB, 57U)) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 43U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 13U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 34U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneA
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 15716U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 14604U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 15058U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12568U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((aIndex + 12710U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 26U)) + RotL64(aCarry, 23U)) + 15045917390223766480U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 19U)) + 10763054007033668758U) + aPhaseBOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 13U)) + 13190170142593666607U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 43U)) + 9657025731441167065U) + aNonceWordN;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 5U)) + 11433367178975954211U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 39U)) + 17904920143996810366U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 41U)) + 3244383020512113283U) + aNonceWordA;
            aOrbiterE = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 6538815775171139091U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 30U)) + 7195368312757976343U) + aNonceWordO;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18134430713910279374U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6571776588427107976U;
            aOrbiterG = RotL64((aOrbiterG * 11916502085252589161U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11830778129647517758U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 9793702760907767365U;
            aOrbiterD = RotL64((aOrbiterD * 4096246227968677179U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 2287235876793192036U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8951959188326141794U;
            aOrbiterJ = RotL64((aOrbiterJ * 9968356718110753845U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7583061790273240157U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3571364625022806085U;
            aOrbiterB = RotL64((aOrbiterB * 6238360922735480669U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13869345563551689212U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 277480328952975002U;
            aOrbiterI = RotL64((aOrbiterI * 1057564597096163085U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4983735092494677578U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9490022869381030928U;
            aOrbiterK = RotL64((aOrbiterK * 12926352917961703123U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7928039573014765566U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6504190875809407084U;
            aOrbiterF = RotL64((aOrbiterF * 14648214826494826711U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2787985600176307413U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16308785053443116826U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17867565986311256691U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12788128335006767824U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1187040019537798339U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 10834905007658184183U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 6U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterE, 57U)) + aNonceWordE) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 37U));
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 12U)) + aOrbiterC) + aNonceWordD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 36U) + aOrbiterD) + RotL64(aOrbiterB, 23U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17737U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 17015U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 20397U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 21233U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((aIndex + 16915U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 24U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 34U)) + 14823268998003220191U) + aNonceWordA;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 15295237288788213847U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 23U)) + 16434853402001133899U) + aPhaseBOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererB + RotL64(aCross, 57U)) + 7555911304407871631U;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 47U)) + 14977248264994834620U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 41U)) + 9707764144919392380U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 29U)) + 1277304385464681529U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 3U)) + 3089786220465849395U) + aNonceWordF;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 39U)) + 3700503853358695085U;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 3240054112993517371U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (((aOrbiterI ^ aOrbiterH) ^ 16897532076915366859U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 4120874717534309035U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 18167359289798364307U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8870819278575769863U;
            aOrbiterG = RotL64((aOrbiterG * 9334066154398059075U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15363069206212330251U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14858164441499725158U;
            aOrbiterH = RotL64((aOrbiterH * 14931933411393847915U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5357144808788707522U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2910681277417754860U;
            aOrbiterD = RotL64((aOrbiterD * 13170868582159347059U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9824408699018165151U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 368370224788793300U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14358982366258729959U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7095398304588825115U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11418879758164313554U;
            aOrbiterB = RotL64((aOrbiterB * 5983520332639771791U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2171599720681913272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17593730219647495033U;
            aOrbiterA = RotL64((aOrbiterA * 12926053208918563087U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17755947635188715523U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 14565740605227022106U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 15866418354612945335U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 14538017880915584414U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6174566474851449123U;
            aOrbiterK = RotL64((aOrbiterK * 179569008593475683U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + aNonceWordL) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 24U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 30U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 53U)) + aPhaseBWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 40U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22105U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneD[((aIndex + 25441U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26104U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22398U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 24081U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererJ + RotL64(aPrevious, 51U)) + 1142447269198373880U) + aNonceWordG;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 10581460640040336191U;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 14703062773878202900U;
            aOrbiterF = (aWandererC + RotL64(aCross, 14U)) + 15737525756286914746U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 21U)) + 16178774478273186999U) + aPhaseBOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 2514897053906809160U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 57U)) + 13702496607592508464U) + aNonceWordI;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 36U)) + 18030885275418337965U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 41U)) + 5241783876161655984U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2807052676283587925U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8022804576763271327U;
            aOrbiterD = RotL64((aOrbiterD * 11727096043219370577U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15597099852232205860U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 1538435607932096400U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 7900752511710516981U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11147868774413615365U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9325213746830411568U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 561819005818948769U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13792300423550555634U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3134856508983945719U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 4271845067763664863U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 8654966018053784882U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8937113935476779267U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 7386875687217705855U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4135676350355234788U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 11407912615743682678U;
            aOrbiterJ = RotL64((aOrbiterJ * 2773506587480714695U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10966950663872392059U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6686634993700944582U;
            aOrbiterC = RotL64((aOrbiterC * 2509459942163678241U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14154407529749257990U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 18054640398549782388U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7830759861389060149U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14623473030642960240U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1857945571104460086U;
            aOrbiterI = RotL64((aOrbiterI * 18039903315045620079U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 56U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterI, 19U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 46U)) + aNonceWordE) + aPhaseBWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterB, 39U));
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + RotL64(aOrbiterD, 34U)) + aOrbiterC) + aPhaseBWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27931U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 28186U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30992U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29251U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30355U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aIngress, 38U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 2974056819475622600U;
            aOrbiterF = (aWandererC + RotL64(aCross, 57U)) + 7345051759236356098U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 14U)) + 12738468816846628882U) + aNonceWordK;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 7694520596043297922U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 37U)) + 5530753590015084774U) + aPhaseBOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 19U)) + 3776309161718383105U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((aWandererK + RotL64(aCross, 10U)) + 784780304358106404U) + aNonceWordC;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 43U)) + 8999942326995036509U) + aNonceWordO;
            aOrbiterC = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 5194986506064092779U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7920040007459652762U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11311997270710107937U;
            aOrbiterD = RotL64((aOrbiterD * 6227571709361790209U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5365231114813547251U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8630110234623825263U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2735881715888325759U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2358235238039571072U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18059414891616491807U;
            aOrbiterG = RotL64((aOrbiterG * 17150786106857185467U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14526050556461782864U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6937282036603272474U;
            aOrbiterJ = RotL64((aOrbiterJ * 14954512365270028029U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10105832250694931310U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3884223553012098137U;
            aOrbiterA = RotL64((aOrbiterA * 16340956813003906195U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10385284339549648087U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1257633893341505930U;
            aOrbiterI = RotL64((aOrbiterI * 2669950791270500977U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5528890519572824318U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15664241747527713256U;
            aOrbiterC = RotL64((aOrbiterC * 16670884497088220497U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 14264122979415331887U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17985061405540198036U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2729487440173395133U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1663986734997903415U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 3706166884286400587U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 10549736618301955745U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 40U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 34U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 29U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterI, 18U)) + aOrbiterC) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x867599A0E2F08083ULL + 0x8DDC1FAA4797AB9FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFDB30B7C3066B50FULL + 0xE9FD85977B9D7AB8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF89B90D3F0F6FD39ULL + 0xC0D7AE64D3AE32CDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x88AAC6E84F0CED5BULL + 0xE9A17415884C559EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB2A4494EDE068737ULL + 0xB5653A10DAC3C4A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xEDC777B1BED7C953ULL + 0xAEA814CAE9FBF9ADULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF96D6D35E7136CF5ULL + 0x92F45EE4DBF44673ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB6B85B4585E4EF1BULL + 0xFBF9EDF461E5898DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9E1C194045E8B797ULL + 0x9AF654385F97A013ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9B3DB6D173AE467BULL + 0xF8016396BAD4E579ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x97C8BC3F46A50FADULL + 0xC64FB8278E932E36ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDC08605FBA1ECAF3ULL + 0xF739F5E919E7C911ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x803DD4E8B7D754AFULL + 0xD3AD3D9105F55554ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x96BA84553BE9A669ULL + 0xFDC28C588EB8C960ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB4F2D0630CE7F203ULL + 0x9925C0929B8A4B46ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9338D138AFE61EC1ULL + 0xA2A4B026919317CCULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4967U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 487U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1754U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2071U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3711U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 1342U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 13U)) + 826930775230515406U) + aNonceWordO;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 5U)) + 5137814617363250861U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 46U)) + 14761561947426681616U) + aNonceWordP;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 12773023438753662590U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aIngress, 5U)) + 7331345852207096322U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 39U)) + 3899381212671247460U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 10072004147620068599U) + aNonceWordL;
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 3424585039401897560U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8246760141625966321U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11478879365443736383U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3655992860610853290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11154618022505863898U;
            aOrbiterA = RotL64((aOrbiterA * 4791494171286145231U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15629361991059709973U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 10842068502278489664U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5571312349016336686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 589313823745748879U;
            aOrbiterH = RotL64((aOrbiterH * 1356685926549786027U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13633457935771935260U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12684602052812183096U;
            aOrbiterF = RotL64((aOrbiterF * 4689206269919806711U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5711307583717354204U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 7181854170553728211U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 9835601115561325911U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1884620014396115821U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1471516373272364262U;
            aOrbiterG = RotL64((aOrbiterG * 5126319375714848029U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 28U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + aNonceWordJ);
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterG, 5U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 53U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + aNonceWordI) + aPhaseDWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 56U)) + aOrbiterD) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8921U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((aIndex + 10517U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 7821U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 8180U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10765U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7139U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 6499U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 37U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 37U)) + 16462052553719977502U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 12337064059566619581U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 15801005007094515447U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 29U)) + 8228706742665081656U) + aNonceWordC;
            aOrbiterF = (aWandererK + RotL64(aCross, 53U)) + 11006723027845190869U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 19U)) + 18173765337829177450U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 27U)) + 530215083653542558U) + aNonceWordF;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 6608611827035564511U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2246051826221626809U;
            aOrbiterK = RotL64((aOrbiterK * 6333352641495253539U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5228575308895381421U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10999213210689606857U;
            aOrbiterF = RotL64((aOrbiterF * 5467601259546342925U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3773371037240485696U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 8887985779436152504U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 698713082830739677U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11150566414723818350U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8336366151003049546U;
            aOrbiterH = RotL64((aOrbiterH * 9033771197242493699U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13233968794237090787U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8172558473508478819U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17837070423649268435U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 133564480283347997U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 15104810248883567064U;
            aOrbiterI = RotL64((aOrbiterI * 706802420642303533U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9138629520201127075U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13993086066341664080U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4875046427147105077U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterI, 43U)) + aOrbiterD) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterF, 37U));
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterA);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 58U)) + aOrbiterK) + aNonceWordL) + aPhaseDWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 5U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12201U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 16342U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15578U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14170U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16043U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 40U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 35U)) + 8101351470141807662U;
            aOrbiterF = (((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 6965474099521076705U) + aPhaseDOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 53U)) + 6803828268885684784U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 51U)) + 13454235922950972488U) + aPhaseDOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aWandererB + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 11678091885751244777U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 29U)) + 5307134544628507141U) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 13U)) + 4873703518950429353U) + aNonceWordD;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 8542156221858586039U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3993726182905296513U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 11331376012938127609U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12113047622035464386U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 1944244448665721151U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7010050836758762003U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12914188029425467576U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2486762763475327024U;
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 14580191602982245481U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12093414832400135066U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12720286833215690663U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13623906997320021065U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9977356009806428696U;
            aOrbiterF = RotL64((aOrbiterF * 2005536391712733499U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3694954095397810851U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11453812627797091638U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 13730420725113907161U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 542311345544726351U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3024285045990499484U;
            aOrbiterB = RotL64((aOrbiterB * 5153745952148205645U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 35U)) + aOrbiterI) + aNonceWordI);
            aWandererB = aWandererB + ((RotL64(aScatter, 4U) + aOrbiterH) + RotL64(aOrbiterI, 29U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + aNonceWordL);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 54U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20751U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((aIndex + 20704U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21052U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21090U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 21480U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 13499155707765393469U) + aNonceWordH;
            aOrbiterK = (((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 3740324981823726185U) + aPhaseDOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 35U)) + 5470765363949735652U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 5U)) + 3446436171274452326U;
            aOrbiterE = (aWandererH + RotL64(aCross, 13U)) + 1778929412631211933U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 51U)) + 14666308799855220954U;
            aOrbiterJ = ((((aWandererK + RotL64(aIngress, 28U)) + RotL64(aCarry, 13U)) + 4548410236791175055U) + aPhaseDOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 5829739767694190372U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14319231414903675748U;
            aOrbiterA = RotL64((aOrbiterA * 4966501102515775601U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 1513851750246111405U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1685620217748986019U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 9286548037413609445U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterH) + 16284162182006054402U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6271539598462003309U;
            aOrbiterE = RotL64((aOrbiterE * 13923286694131331137U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 12669312437565969473U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11894755313393001665U;
            aOrbiterI = RotL64((aOrbiterI * 12556759675372354075U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6315983824634946566U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17106616474222892782U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 167205520766791073U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 13350266700180455548U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4608846311203767162U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2504857468837437365U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14195866746143604365U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7917977448256795054U;
            aOrbiterF = RotL64((aOrbiterF * 5927771378657284557U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 38U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 14U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 58U)) + aNonceWordD);
            aWandererC = aWandererC + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterK, 3U)) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 23U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterF) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 19U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22876U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneB[((aIndex + 24741U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22064U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25041U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26951U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 12U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 43U)) + 1898718075389870739U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 5631794889237247403U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 37U)) + 18219714659484524607U) + aNonceWordA;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 18U)) + 15419581386225732921U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 11U)) + 9125575431710198210U;
            aOrbiterB = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 37U)) + 12205871520544965505U) + aNonceWordD;
            aOrbiterA = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 7617534300497343422U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 18017579105368135814U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 10693882161946020042U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 2326507900303932855U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11669615701700895306U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11045110212889232165U;
            aOrbiterK = RotL64((aOrbiterK * 5965171269273719849U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18019107802806469913U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12315940560472528716U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4505122470351404065U), 27U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterG) + 4899009736070044310U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 17412253404253730364U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 10791901166391946485U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4826286251927854181U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4523455921321845084U;
            aOrbiterI = RotL64((aOrbiterI * 14534103906736598099U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4132514462154182215U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7164745605985109269U;
            aOrbiterB = RotL64((aOrbiterB * 14107325508977225261U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6297434295807635654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8813887638672996646U;
            aOrbiterA = RotL64((aOrbiterA * 17495632530773158201U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 41U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aScatter, 50U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterG, 10U));
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterA, 21U)) + aNonceWordI);
            aWandererF = aWandererF + (((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 3U)) + aNonceWordE) + aPhaseDWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterI, 51U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 24U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 29531U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 28846U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 28830U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 28602U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31781U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 21U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterA = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 13854738573712660276U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 35U)) + 16835460633412286294U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 6785859293758091931U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 51U)) + 126317283127992659U;
            aOrbiterI = (aWandererC + RotL64(aCross, 3U)) + 7568963536291415413U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 19U)) + 12294016745653004819U) + aNonceWordP;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 56U)) + 18269588932920281147U) + aNonceWordF;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5872406424994751026U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7764434758831474129U;
            aOrbiterK = RotL64((aOrbiterK * 3772146788188420071U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4804168969415573371U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 959601763507651280U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 4647396592804833217U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9257644462479293048U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14332699366894494579U;
            aOrbiterH = RotL64((aOrbiterH * 8829304078930625541U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10487012596470786004U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 612729229562321440U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11380387280507726003U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7845523921295625315U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12742115479740024747U;
            aOrbiterJ = RotL64((aOrbiterJ * 15578543510683986421U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10294667720904610944U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14369711143154904567U;
            aOrbiterI = RotL64((aOrbiterI * 13753005602288309379U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10918344717497681894U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 18136794828308636957U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 17899418637978002409U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 11U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterK, 58U)) + aNonceWordO) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 20U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + aNonceWordC);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + aPhaseDWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 40U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x92A448954893BA0FULL + 0xA086497C8221BEC2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x83D013240DC14C65ULL + 0x90131DF6F653A46FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF819CA95CC49727DULL + 0xC6D09ACF9A6DE986ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBA5343EA02D10B59ULL + 0xE02CBA72B2A60D3CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCDCAC09EE7C99AA1ULL + 0xA61E3AD70DFD5F7BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB0E6EF7B51E6CE55ULL + 0xB9DD969D8E56AD1CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA340F33D417B95E9ULL + 0x8D52E22B2E0DD71DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x907D6157224FC211ULL + 0xBB10044DCD8CAC43ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDD5C5E81B3328205ULL + 0x9F0DB4FF7B647CB9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x93365C0936B90A29ULL + 0xA287D99DF4883EEAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9EED2CDA15150003ULL + 0xBA72B6D09FBC13D3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDA6FCCA014424833ULL + 0xBFC597E78BB93F7FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x884086F4E89A5E2DULL + 0xDA501CA62B509ECFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xB8A200B343BA3CF5ULL + 0xC26567135B0ECF64ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDB644259115F4F99ULL + 0xB3AC1F0388F87703ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD16174CA37973759ULL + 0x92FDCEA97A96018DULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 543U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((aIndex + 4591U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4988U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 225U)) & S_BLOCK1], 12U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3308U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 2241U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererE + RotL64(aPrevious, 39U)) + 8975885703279267062U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 23U)) + 8664844915562660637U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 3U)) + 12281774799736296726U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 35U)) + 15347461352311329726U) + aNonceWordM;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 50U)) + 12967500561828907834U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 5002833859280402726U) + aPhaseEOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aScatter, 5U)) + 11908257536954668983U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 17017174811949227162U) + aNonceWordG;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 16851323125613931180U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 19U)) + 13469326957728686706U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 12U)) + 5228638551056105241U;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 11945166198089308564U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16268645041872996022U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5391448793718370911U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14781204627695095701U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5365325354838101092U;
            aOrbiterK = RotL64((aOrbiterK * 8017284997946310807U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 563147416025715953U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14660867395395625851U;
            aOrbiterB = RotL64((aOrbiterB * 4769458126865307103U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3168989056355712105U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16179131669773665579U;
            aOrbiterD = RotL64((aOrbiterD * 5641461617066671723U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4160220074225527179U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8597134686962559111U;
            aOrbiterF = RotL64((aOrbiterF * 639572585431474015U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16811551552456811661U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 5827323970423386301U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9328247349730652021U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15583234353262170227U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2950816254621717748U;
            aOrbiterC = RotL64((aOrbiterC * 1102417597476170143U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4426165025104306337U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11871220132164971152U;
            aOrbiterA = RotL64((aOrbiterA * 2366168050042802207U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3832424136113939717U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17673885217916768611U;
            aOrbiterG = RotL64((aOrbiterG * 10887063696370811871U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3479289844909914390U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9498461576098567546U;
            aOrbiterI = RotL64((aOrbiterI * 8734492074299676555U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10645314291190544864U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8975885703279267062U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 16584086014947250551U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 35U)) + aNonceWordK) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterK, 57U)) + aNonceWordL);
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 37U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 44U) + aOrbiterE) + RotL64(aOrbiterB, 51U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 6U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterA, 39U));
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 42U) + RotL64(aOrbiterK, 29U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 50U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6834U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 7298U)) & S_BLOCK1], 48U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 8326U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 8593U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 7785U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 9954U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 10887U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererD + RotL64(aScatter, 41U)) + 1708250618750199233U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aIngress, 39U)) + 12009147777553691142U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 22U)) + RotL64(aCarry, 27U)) + 8393982703399156592U) + aNonceWordG;
            aOrbiterF = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 3247327098356831221U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 47U)) + 3403590155376353737U) + aNonceWordP;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 27U)) + 18197244558104735044U) + aNonceWordD;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 3096253642040701606U;
            aOrbiterD = (aWandererG + RotL64(aCross, 18U)) + 8012692688785412179U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 3U)) + 17531946907545680745U) + aNonceWordO;
            aOrbiterC = (aWandererJ + RotL64(aCross, 11U)) + 17687695944270225817U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 51U)) + 16147773866007628769U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18244641303026196497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8839160526348897457U;
            aOrbiterJ = RotL64((aOrbiterJ * 14268021129087663397U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 10599266240854068246U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2056723540756216155U;
            aOrbiterK = RotL64((aOrbiterK * 13311591601230386375U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4629354220460621284U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9505955649473204942U;
            aOrbiterF = RotL64((aOrbiterF * 17775391885312236187U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17078153810088721310U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9470436761716263000U;
            aOrbiterD = RotL64((aOrbiterD * 5431855497250357229U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3305863413630104742U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14377172434239576161U;
            aOrbiterE = RotL64((aOrbiterE * 6880176890091033423U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 415687827894226513U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 16975319836893760993U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 6597144958013976445U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12707054129431596074U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 8974182792497231239U;
            aOrbiterC = RotL64((aOrbiterC * 7874658957269462717U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10826131924322955095U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 4168545139712703154U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 10305904857550051705U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 4539070253658625193U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3737870219498561326U;
            aOrbiterG = RotL64((aOrbiterG * 13130847633918921393U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11563084648810555040U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7410695535361901473U;
            aOrbiterI = RotL64((aOrbiterI * 7540855656023807389U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6687453696858775037U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1708250618750199233U;
            aOrbiterH = RotL64((aOrbiterH * 13104250803527718135U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 10U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterD, 13U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 18U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterA, 27U));
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 47U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 34U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 34U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + aPhaseEWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 42U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15561U)) & S_BLOCK1], 22U) ^ RotL64(aInvestLaneA[((aIndex + 14958U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 15849U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14276U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneC[((aIndex + 11696U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 21U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 12775735908960052604U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 11791373812080296887U;
            aOrbiterA = (aWandererC + RotL64(aIngress, 27U)) + 5537362877706057303U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 42U)) + 2023912048504189380U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 47U)) + 17668828109963766893U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 558908629933941224U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 53U)) + 1479633119685446888U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 35U)) + 15460320397843364063U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 37U)) + 10059749397555469054U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 60U)) + 9987633811929693924U) + aNonceWordE;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 11U)) + 10087337844580228269U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4446204415503364254U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15106063243302192717U;
            aOrbiterA = RotL64((aOrbiterA * 13273756657334709803U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9430197906134676162U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1226048679997253363U;
            aOrbiterD = RotL64((aOrbiterD * 14247538885252664127U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 10611580584157624739U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 3137391249289641509U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9327201928815412810U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 7890659377013147073U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 13827717178378062047U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 10675114832750356941U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8804440385852327267U;
            aOrbiterG = RotL64((aOrbiterG * 8520671775587260601U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12871947817782057116U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11015991745792051390U;
            aOrbiterH = RotL64((aOrbiterH * 17152451500505815031U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6320437975845673731U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 702457937087191287U;
            aOrbiterJ = RotL64((aOrbiterJ * 17491257114676739589U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16629064896250312921U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6054107387816339103U;
            aOrbiterC = RotL64((aOrbiterC * 6983767878966747219U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13274874838094190290U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12211422735294360321U;
            aOrbiterE = RotL64((aOrbiterE * 5113738196151089817U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15338616110718583619U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1475787183754511373U;
            aOrbiterK = RotL64((aOrbiterK * 10904607643785840003U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 15486810401396777742U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12775735908960052604U;
            aOrbiterF = RotL64((aOrbiterF * 7478156942468930207U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 23U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 6U) + aOrbiterA) + RotL64(aOrbiterF, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 46U)) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + aNonceWordG);
            aWandererB = aWandererB + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 38U)) + aOrbiterE) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aNonceWordP);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 34U) + aOrbiterD) + RotL64(aOrbiterI, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 42U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 52U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18868U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((aIndex + 20164U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 17004U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21339U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((aIndex + 17488U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 51U)) + 14008824488073394623U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 5U)) + 13317978415866411468U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 26U)) + RotL64(aCarry, 53U)) + 13209180141897453900U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 13U)) + 11870521586865233578U) + aNonceWordO;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 37U)) + 8052156380448047385U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 23U)) + 12158131176743680605U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 21U)) + 14674467487607719347U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 39U)) + 18055496790566231147U) + aNonceWordF;
            aOrbiterK = (aWandererD + RotL64(aCross, 41U)) + 3838105585041578784U;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 2839568255183054418U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 54U)) + RotL64(aCarry, 57U)) + 11933612922864258179U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6289849094151630580U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2640344350528492271U;
            aOrbiterG = RotL64((aOrbiterG * 16197726750829369365U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16306175266267657791U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3339898380394883600U;
            aOrbiterB = RotL64((aOrbiterB * 7105436590182982373U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15017076663742800002U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8973064296077602496U;
            aOrbiterH = RotL64((aOrbiterH * 9309462227233615761U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17580319233338139859U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14063208878807603874U;
            aOrbiterF = RotL64((aOrbiterF * 16601475239075164585U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13326130855721009942U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12843186026737544416U;
            aOrbiterE = RotL64((aOrbiterE * 4975848122837321619U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14102887715772847499U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14495942314329085733U;
            aOrbiterC = RotL64((aOrbiterC * 4236795312917583565U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11564857125101669667U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17435970784822000464U;
            aOrbiterJ = RotL64((aOrbiterJ * 1472691848852381173U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16561390130356833062U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9952805588514363872U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 3720874990001086597U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 8246822023509690545U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 305480212301772662U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 4295787267516476485U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11729872285756639125U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9669174142543613799U;
            aOrbiterK = RotL64((aOrbiterK * 9443240779947114779U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 7653344907616923293U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14008824488073394623U;
            aOrbiterD = RotL64((aOrbiterD * 8362849599309360823U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 27U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 50U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterK, 41U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aNonceWordI) + aPhaseEWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterB) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterE, 38U)) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererK = aWandererK + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + RotL64(aCarry, 13U)) + aNonceWordE) + aPhaseEWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 44U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25584U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 23084U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 22383U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24617U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25074U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25915U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aPrevious, 57U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 29U)) + 5295352595333316211U) + aPhaseEOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordM;
            aOrbiterH = (aWandererK + RotL64(aScatter, 41U)) + 2341795367042042605U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 11U)) + 10122175780504033663U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 24U)) + RotL64(aCarry, 53U)) + 10084612804696198554U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 37U)) + 16470424309851045971U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 5U)) + 656016130975227994U;
            aOrbiterD = (aWandererD + RotL64(aCross, 3U)) + 15313268829659834317U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 3795220914993923394U;
            aOrbiterK = (aWandererI + RotL64(aCross, 50U)) + 14044442220988813825U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 53U)) + 3804224626734584802U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aScatter, 35U)) + 7980006306010255693U) + aNonceWordA;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13746830564584711549U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11852212099729274845U;
            aOrbiterE = RotL64((aOrbiterE * 2164880979318247855U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9083223471018084847U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13706723820703853346U;
            aOrbiterF = RotL64((aOrbiterF * 11361854103656219887U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1713819986642275223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1382000168233902914U;
            aOrbiterJ = RotL64((aOrbiterJ * 3894160765130198157U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4540474625764565485U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1756168174375757220U;
            aOrbiterH = RotL64((aOrbiterH * 12739160208010092017U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1409297070183609309U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6082750101445444357U;
            aOrbiterK = RotL64((aOrbiterK * 17438740230251860935U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1113239890859479202U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10932192439503964363U;
            aOrbiterI = RotL64((aOrbiterI * 5915660289913324281U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3732595033748508428U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5117760372351117286U;
            aOrbiterA = RotL64((aOrbiterA * 2671510075176315761U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7399968659654088641U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14835608167871904147U;
            aOrbiterD = RotL64((aOrbiterD * 8312521710415756159U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7851355416751467648U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 262169565276199916U;
            aOrbiterG = RotL64((aOrbiterG * 11801419425408657509U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1771847554312299305U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 15588805765521695222U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 8541206691371972017U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6162696602553964144U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5295352595333316211U;
            aOrbiterC = RotL64((aOrbiterC * 8368226841948931873U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterH, 35U)) + aOrbiterK) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterC, 53U)) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + aNonceWordE);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterK, 24U)) + aPhaseEWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 21U)) + aOrbiterA) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 46U)) + aOrbiterI) + aNonceWordI);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 28U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 10U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31707U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 31711U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28573U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29896U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneB[((aIndex + 30962U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 37U)) + (RotL64(aIngress, 22U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererF + RotL64(aCross, 53U)) + 9630214189402543339U) + aNonceWordN;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 35U)) + 4072576573737526819U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 47U)) + 15994787452709618869U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 39U)) + 6403240137132259482U;
            aOrbiterF = (aWandererK + RotL64(aCross, 13U)) + 10229266900170507720U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 26U)) + RotL64(aCarry, 13U)) + 5025294577989748989U;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 16696461238217956883U) + aNonceWordJ;
            aOrbiterB = (aWandererC + RotL64(aScatter, 11U)) + 9878318855341719119U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 3U)) + 16086635438116177346U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 58U)) + RotL64(aCarry, 21U)) + 12295437783084203730U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 37U)) + 7681150419912842402U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2639104034287637448U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12298170009332243573U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9397919591171238575U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3485932317267669626U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16569551670038752475U;
            aOrbiterI = RotL64((aOrbiterI * 8139802826402217631U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4448490103784103954U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14510534073046885941U;
            aOrbiterD = RotL64((aOrbiterD * 7777192047386438305U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4286195398675733451U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15790355933840266463U;
            aOrbiterG = RotL64((aOrbiterG * 13342257823027075501U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6362891510370156055U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 15121822034579983174U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 7268045994574844937U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13817341015719915628U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14113474087906143783U;
            aOrbiterF = RotL64((aOrbiterF * 12838910141533126059U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9988301252236121106U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11287477288382171758U;
            aOrbiterA = RotL64((aOrbiterA * 4979297247881426383U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9491727010910328644U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 7961202721830514030U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 16300364540313620767U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10058066852293995222U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 541563830282750968U;
            aOrbiterC = RotL64((aOrbiterC * 1516823517052019845U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7791201128863372861U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8334318157449352359U;
            aOrbiterE = RotL64((aOrbiterE * 2924838607279239375U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6861081455774799715U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 9630214189402543339U;
            aOrbiterB = RotL64((aOrbiterB * 10837610668580336781U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 60U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + aPhaseEWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterK, 3U)) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterE, 10U));
            aWandererC = aWandererC + (((RotL64(aIngress, 46U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB2D7AFFAEE30DD05ULL + 0xEA9FD24644FE988AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC8FBE632F445B4B3ULL + 0xF7D1ECEEB73019D9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD4B67587EE4FC45DULL + 0xED6321B82D34F304ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xDFAA5A83527E96D1ULL + 0x82C5A7A73742461FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC7C0B39BCDFC9549ULL + 0xC96BDFCFAB5CF23DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE193FCBEA2C46173ULL + 0xF51DA30B1F332532ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF0D9AEFC2E12A46DULL + 0xB472B89D8CB1BADFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x94B281BB91968B3BULL + 0xD537F149205A994CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x87933C8AA848A217ULL + 0xD733809605B23F1EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD5162A54A1CE138DULL + 0xBFA50B845C71CA39ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD71EEB9526339E07ULL + 0xAA3FD4389B7C6D3EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB16EF9DCCA2A87FDULL + 0xE9AFF8948F576364ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x9486179E4D90A0C7ULL + 0xDAD967B2B3F5156EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF3823B809B04DC07ULL + 0xD78B92A07EE924B2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDFD8B634806D15CBULL + 0x8B7FA1C2E7CC13CEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD6F9B8EBCB880DCDULL + 0x8BD42907AAD01AD1ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneD, aOperationLaneC, aOperationLaneD, aSnowLaneA, aSnowLaneC, aInvestLaneB, aInvestLaneC, aSnowLaneD, aSnowLaneB, aExpandLaneA, aWorkLaneD, aExpandLaneB, aWorkLaneC, aExpandLaneC, aInvestLaneA
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 74U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 4797U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 2640U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3646U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1139U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 3632U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 57U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 4773124477323378268U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 56U)) + 16848723289435796005U) + aNonceWordB;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 51U)) + 13846642134917107058U) + aNonceWordP;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 11U)) + 6472057872482789939U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 51U)) + 2747019500690707226U) + aNonceWordH;
            aOrbiterG = (aWandererC + RotL64(aIngress, 41U)) + 9003965289739733880U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 23U)) + 3013390651936257377U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 3331004709895625067U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 46U)) + 15355010435553517129U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7709870658004280052U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13568728443963926564U;
            aOrbiterK = RotL64((aOrbiterK * 6736090830113688981U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12409548853419307131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 969183352023661537U;
            aOrbiterI = RotL64((aOrbiterI * 5549220554838837145U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 15370309834426476775U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3896803894396631184U;
            aOrbiterF = RotL64((aOrbiterF * 11018830202891911603U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10848873633291935766U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12885336509190543440U;
            aOrbiterH = RotL64((aOrbiterH * 1487357252619221365U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8252290890093788010U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9201553615601641350U) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 420321130559162915U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14014209645503188472U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4015071464301844550U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17444195018239904971U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16173085647514027347U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16916627014974363360U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7699587344277490953U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1591680303404522110U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 16499606051269327916U;
            aOrbiterE = RotL64((aOrbiterE * 814405848002794813U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6932673635509444619U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8745681160108707944U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 14565255558668084787U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 56U)) + aOrbiterC) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 46U) + aOrbiterG) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterH, 60U)) + aNonceWordN) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterA, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 21U)) + aOrbiterH) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneB
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 10888U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 10458U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9386U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneB[((aIndex + 9666U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6626U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6254U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneC[((aIndex + 6172U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 40U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterG = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 18319689184146942855U) + aNonceWordJ;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 48U)) + 8041304130090501019U) + aPhaseFOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 5U)) + 11347064191990897738U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 35U)) + 15242243470024447468U;
            aOrbiterC = (((aWandererI + RotL64(aCross, 29U)) + 10619749107163611105U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 18U)) + RotL64(aCarry, 5U)) + 14795614276221947128U) + aNonceWordE;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 39U)) + 1578095288886372393U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 13593906305770501684U) + aNonceWordH;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 11U)) + 8919815528334599172U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 17425548324720065145U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterG) ^ 11125018338392347335U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 4377887040461528587U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3779189180734244399U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 10958224663276134041U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6206963519509783781U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4317305352561612995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4891139433808505355U;
            aOrbiterC = RotL64((aOrbiterC * 11507024985663120317U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5166074784835930965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10080890270621589202U;
            aOrbiterI = RotL64((aOrbiterI * 13170894418184288695U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4501071771615514619U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6486573807774431753U) ^ aNonceWordP;
            aOrbiterK = RotL64((aOrbiterK * 324029625116648669U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15714881857668975753U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 3506619392820235900U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5707033870161224499U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5295711072762443783U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 11192836530396570648U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 4361810118382207039U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7993389678399774574U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12551394763541226695U;
            aOrbiterB = RotL64((aOrbiterB * 11903486656172026403U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 11553674370322129668U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4459881583199320245U;
            aOrbiterJ = RotL64((aOrbiterJ * 2805857426321555685U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 54U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 48U) + aOrbiterB) + RotL64(aOrbiterK, 51U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterH, 56U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterA, 29U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterG, 46U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aSnowLaneB
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aSnowLaneB forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 13337U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((aIndex + 12923U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aSnowLaneB[((aIndex + 14008U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 13820U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 13143U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 41U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 13296600294247799698U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 5818503518080877515U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 6U)) + 6735784238734173597U) + aNonceWordD;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 29U)) + 7368398209488856201U) + aNonceWordN;
            aOrbiterC = (aWandererI + RotL64(aIngress, 35U)) + 961734029066455638U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 797011946660892011U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 24U)) + 12841876018396622350U) + aNonceWordF;
            aOrbiterG = ((aWandererB + RotL64(aCross, 11U)) + 16213253970483895623U) + aNonceWordH;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 19U)) + 15186950557113470375U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5117930310827477341U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12265429373166094162U;
            aOrbiterH = RotL64((aOrbiterH * 1522823535151532249U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13920531346698601568U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 14695405206998211456U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 13950964363414164279U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7851960904825938443U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9501511171732550190U;
            aOrbiterF = RotL64((aOrbiterF * 5614164120361489613U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5663365182245722077U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 9607860124321315555U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3461820361914280601U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 18171052650586819280U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3442698321538580861U;
            aOrbiterK = RotL64((aOrbiterK * 6317525514963824829U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1491052813469258970U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3956599824067616133U;
            aOrbiterD = RotL64((aOrbiterD * 2928600779267623085U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10963841237346073453U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2303020125591252534U;
            aOrbiterC = RotL64((aOrbiterC * 9969099842343321981U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 14503856057958162356U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11147548150090597694U;
            aOrbiterE = RotL64((aOrbiterE * 11856382308792700441U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9191681438318311481U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 13556072770381999852U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 18316231099054203683U), 37U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 4U)) + aOrbiterH) + aNonceWordK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterC);
            aWandererH = aWandererH + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterB, 35U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 22U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 13U)) + aOrbiterC) + aNonceWordP) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 47U)) + aOrbiterC) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 20U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aWorkLaneD
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aWorkLaneD forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 17824U)) & S_BLOCK1], 52U) ^ RotL64(aSnowLaneC[((aIndex + 16450U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 19371U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17762U)) & S_BLOCK1], 20U) ^ RotL64(aOperationLaneD[((aIndex + 19907U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 38U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererK + RotL64(aCross, 38U)) + 3550722402315312207U) + aNonceWordP;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 43U)) + 16724184551669522754U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 981751330116773021U) + aPhaseFOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 11U)) + 7891159229704944868U) + aNonceWordN;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 13618396711464799841U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 23U)) + 5969291018449003648U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 53U)) + 14595540413313640042U;
            aOrbiterB = (((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 3287990436916111762U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 4U)) + 12534369400200483704U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2277312067930392274U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10026320559261334353U;
            aOrbiterC = RotL64((aOrbiterC * 11020464940995912637U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11258082063135659551U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1445958517675746990U;
            aOrbiterJ = RotL64((aOrbiterJ * 10062265337488757971U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1011298251290970844U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6487834862470043744U;
            aOrbiterH = RotL64((aOrbiterH * 15477913837027179675U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9966279022928268335U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 10285993486057704393U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15965714363201157535U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 16005362468813966136U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 223843444699390781U;
            aOrbiterB = RotL64((aOrbiterB * 665392038954573081U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 18178876294968532775U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12490136112181806806U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 16380841616662993709U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8775696166557913635U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16464340319444310842U;
            aOrbiterF = RotL64((aOrbiterF * 18111632334728200721U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 6296039992673546227U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7152939277656436037U;
            aOrbiterA = RotL64((aOrbiterA * 15183918431501487319U), 3U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 14066791413416223271U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 5026743227399908016U;
            aOrbiterG = RotL64((aOrbiterG * 5891343232759075675U), 35U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 14U)) + aOrbiterG) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 29U)) + aOrbiterH) + aNonceWordD);
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + aNonceWordB) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 57U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterG, 24U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 4U) + aOrbiterH) + RotL64(aOrbiterA, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 25841U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneD[((aIndex + 26524U)) & S_BLOCK1], 52U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 26431U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26816U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneC[((aIndex + 22450U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 4U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterB = (((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 14214886793361825363U) + aNonceWordH;
            aOrbiterG = (aWandererK + RotL64(aScatter, 50U)) + 17267959031078766320U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 3U)) + 16436067429484887644U) + aNonceWordG;
            aOrbiterD = (aWandererE + RotL64(aIngress, 39U)) + 9885951769332633820U;
            aOrbiterH = (aWandererD + RotL64(aCross, 27U)) + 12971711341813893304U;
            aOrbiterJ = ((((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 199970353398450154U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 23U)) + 1237341696444162094U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 21U)) + 7991128854417613360U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 57U)) + 14809029847149045833U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2559509556915775947U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14336829730147834160U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15103242520064900873U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8853631886733610440U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13346159398673246914U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13660497151446983393U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12121095718571872976U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16239781125815589804U;
            aOrbiterK = RotL64((aOrbiterK * 5157009090454962231U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9051377033794324106U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13805815136723461780U;
            aOrbiterH = RotL64((aOrbiterH * 571129481747181357U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14849157800322754413U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18116651528452542634U;
            aOrbiterG = RotL64((aOrbiterG * 3638480428016835537U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 4105057226952948599U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5911714320560994391U;
            aOrbiterB = RotL64((aOrbiterB * 1796514171654961389U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4439149331729987587U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10278532228230163632U;
            aOrbiterI = RotL64((aOrbiterI * 17428224919864716517U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2342456582668741750U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2360578572554664800U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1108428466956691925U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12132934875391401246U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17213278726790245812U;
            aOrbiterA = RotL64((aOrbiterA * 11904899990681410419U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 27U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 48U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 53U)) + aOrbiterI) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 48U) + aOrbiterH) + RotL64(aOrbiterA, 23U)) + aNonceWordE);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterA, 10U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28194U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 28694U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 30488U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27790U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 27384U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 4U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 43U)) + 15036852811491820366U) + aNonceWordK;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 10U)) + RotL64(aCarry, 19U)) + 305637140752898475U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 19U)) + 11948631574496129610U) + aNonceWordF;
            aOrbiterE = ((((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 5321623592482991426U) + aPhaseFOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererF + RotL64(aCross, 39U)) + 4075270159062690728U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 15111580500356908928U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 27U)) + 7244150695504160363U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 14U)) + 5131563519577488862U;
            aOrbiterC = (((aWandererH + RotL64(aCross, 3U)) + 5881954992088651371U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12780935808751507998U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12599159643925470226U;
            aOrbiterD = RotL64((aOrbiterD * 17690046932587062701U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 9466589929741834066U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 6093158735705189789U;
            aOrbiterG = RotL64((aOrbiterG * 7453778295800853653U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17461243886150519249U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15456408913739900718U;
            aOrbiterA = RotL64((aOrbiterA * 16093292401746174671U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11260643903290392780U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7870342756041882616U;
            aOrbiterK = RotL64((aOrbiterK * 2431528656086173419U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 134484990005888936U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10626896209992890407U;
            aOrbiterF = RotL64((aOrbiterF * 12034131076645285597U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14031164129515132292U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1771835705730244212U;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16395472745067254664U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 1455944290845294254U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 6757824754363319079U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17866422769075350837U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10226884082632410805U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 206035536985843815U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14474587247775371703U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 8501763445324525303U) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 5298694643596784007U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 56U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 3U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 50U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterC, 57U));
            aWandererH = aWandererH + (((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 10U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aCross, 34U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + aNonceWordN) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8D7E8C0CF5A1260BULL + 0xC17375574D891301ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xBDB6D1F407311B59ULL + 0xB40F09994EAF8B3CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEA844AE4793302FFULL + 0xFF82330B6E5AF475ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFEA580D3D7032821ULL + 0xF56B7CC71E164F90ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x825860B4F01ABFCDULL + 0xBF1D6AB1399F5407ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCC17F46182C37655ULL + 0xE96C916885DDE420ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD3EED23ED3AD3BADULL + 0xFF6AA79974B6BD35ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC9EFDB7919AEA825ULL + 0xD82C10C56204538DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA95BD20B45A04D19ULL + 0x94898FD476ADC8DDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAD622022E1F1A791ULL + 0xA423FFE03F9E7589ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB18682B5ADB81851ULL + 0xCB77BC60D4092E98ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xEF647F5152432881ULL + 0xEA4D535998E34B59ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDBF6A3B500A1CBFFULL + 0xF5E181E938246956ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xEE1F558A858AFCC3ULL + 0x9B35543EF2505243ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB4AA291A8A280489ULL + 0xA689C81FC8862211ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD61C4ACD2C4F104FULL + 0xB03FA0A99A7BE108ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneD, aSnowLaneC, aSnowLaneD, aFireLaneA, aWorkLaneA, aInvestLaneC, aFireLaneB, aWorkLaneB, aInvestLaneA, aExpandLaneA, aFireLaneC, aExpandLaneB, aFireLaneD, aExpandLaneC, aInvestLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneD
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aFireLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 933U)) & S_BLOCK1], 35U) ^ RotL64(aSnowLaneB[((aIndex + 67U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 1034U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3005U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5395U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 962U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 26U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 27U)) + 9855743441035905047U) + aPhaseHOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 8426286937143990276U) + aNonceWordC;
            aOrbiterC = (aWandererD + RotL64(aScatter, 5U)) + 7146752367170267002U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 41U)) + 12947210066678101726U) + aNonceWordO;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 18U)) + 15902163559925328965U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 8506649889346449469U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (((aWandererH + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 8226286036430263052U) + aNonceWordL;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 2703047093452420216U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6769351326360139560U;
            aOrbiterC = RotL64((aOrbiterC * 5318104980014706265U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9857025533281333281U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 238297452132277585U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 12974709749856065985U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7203572312072908931U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 12497027346166575632U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 1703586436725662307U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 473851890609048879U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1664484956453886047U;
            aOrbiterF = RotL64((aOrbiterF * 8566500756326590209U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4635095143004754116U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17695676150967345793U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5780416541584439301U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 15628965269863402796U) + aNonceWordF;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9190117464399730235U;
            aOrbiterK = RotL64((aOrbiterK * 5586437438425999715U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17835918238346011086U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4398005402429282682U;
            aOrbiterI = RotL64((aOrbiterI * 14828737209913317463U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 4U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aPhaseHWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterA, 60U)) + aPhaseHWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 22U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aFireLaneB
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 9037U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneC[((aIndex + 9711U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 5614U)) & S_BLOCK1], 42U) ^ RotL64(aInvestLaneC[((aIndex + 5521U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10370U)) & S_BLOCK1], 36U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7633U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10876U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 47U)) + 14499676118633326000U) + aNonceWordF;
            aOrbiterF = (aWandererJ + RotL64(aCross, 53U)) + 17191273593018552288U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 21U)) + 4085176294948097737U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 11112671474158908186U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 27U)) + 8745787969012266485U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 14U)) + RotL64(aCarry, 23U)) + 18074049663777707948U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 5U)) + 2543758649719164688U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4659584749412700523U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 974639159259871273U;
            aOrbiterC = RotL64((aOrbiterC * 17918719351847605523U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 9211220687971081987U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8567024626862182714U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7755874089832496393U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5803002132294840900U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11968489432878148467U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4501441062617123165U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9470807228394903442U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1692347973120388469U;
            aOrbiterB = RotL64((aOrbiterB * 17433393164156231575U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16510815732690193145U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 755159406833096510U;
            aOrbiterK = RotL64((aOrbiterK * 14091736464659561165U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1518824876475937620U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 701225390867330446U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12264618860580199927U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8425976693733003889U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7182176375442410367U;
            aOrbiterE = RotL64((aOrbiterE * 8860605703761731859U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aNonceWordE) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 60U)) + aOrbiterC) + aNonceWordJ) + aPhaseHWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 5U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterB, 35U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 11U)) + aOrbiterC) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14442U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 10938U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14992U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15774U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneC[((aIndex + 12610U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 19U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 29U)) + 13714409587461539863U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = (aWandererD + RotL64(aIngress, 47U)) + 14101156723903265839U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 19U)) + 7063754562895369001U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 4U)) + RotL64(aCarry, 13U)) + 12320578575245519386U) + aNonceWordE;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 11744826789631008424U) + aNonceWordM;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 35U)) + 8744816505096675597U) + aPhaseHOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 29U)) + 10405435520084528645U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1463157688070683543U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterI) ^ 12379603577919617703U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 14858901470015109311U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 1343439118031348146U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16118850268070235540U;
            aOrbiterE = RotL64((aOrbiterE * 11184386483735388257U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14116264435819277136U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 5251698273012432109U;
            aOrbiterH = RotL64((aOrbiterH * 1495818611622063967U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14806408656041403829U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11569345414052398227U;
            aOrbiterK = RotL64((aOrbiterK * 9913158908301414861U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17063874769147888574U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 9927420478679581917U;
            aOrbiterI = RotL64((aOrbiterI * 9042782809534196563U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2550285599827162167U) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17801534123304996448U;
            aOrbiterC = RotL64((aOrbiterC * 2160836889363614721U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 6456685241021762041U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17064208177372969289U;
            aOrbiterA = RotL64((aOrbiterA * 13726627607233302493U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 28U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterA, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 35U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordP);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + aNonceWordH) + aPhaseHWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 56U)) + aOrbiterC) + aNonceWordI) + aPhaseHWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 18U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20328U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 20962U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 17484U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17576U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneD[((aIndex + 18843U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 35U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 11U)) + 9630214189402543339U) + aNonceWordP;
            aOrbiterK = (((aWandererI + RotL64(aCross, 27U)) + 4072576573737526819U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 21U)) + 15994787452709618869U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 5U)) + 6403240137132259482U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 53U)) + 10229266900170507720U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 5025294577989748989U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 19U)) + 16696461238217956883U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9878318855341719119U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16086635438116177346U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5585682357395705671U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12295437783084203730U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7681150419912842402U;
            aOrbiterK = RotL64((aOrbiterK * 7289497379725191451U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 2639104034287637448U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 12298170009332243573U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9397919591171238575U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3485932317267669626U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 16569551670038752475U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterH = RotL64((aOrbiterH * 8139802826402217631U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4448490103784103954U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14510534073046885941U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 7777192047386438305U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4286195398675733451U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15790355933840266463U;
            aOrbiterI = RotL64((aOrbiterI * 13342257823027075501U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6362891510370156055U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 15121822034579983174U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 7268045994574844937U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 37U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 28U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordO);
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 57U)) + aOrbiterB) + aNonceWordF) + aPhaseHWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 13U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 3U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 37U)) + aOrbiterC) + aNonceWordN) + aPhaseHWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 20U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27022U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 23811U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25494U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22693U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23264U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterD = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 53U)) + 11274974230580265396U) + aNonceWordI;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 48U)) + RotL64(aCarry, 39U)) + 16658438747342741547U;
            aOrbiterA = (((aWandererC + RotL64(aCross, 11U)) + 16612986966106053844U) + aPhaseHOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 57U)) + 9329502236843231290U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 14088261356708344656U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 13692608802007789581U) + aNonceWordF;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 37U)) + 6824473946645682398U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2072915876348570040U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7420507753044460759U;
            aOrbiterA = RotL64((aOrbiterA * 13239288539564571257U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4677557318688502593U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15081678577055628459U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16659305295251177155U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7026792817486507482U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14871665922943969918U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 6807734532159292872U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17882797335141303280U;
            aOrbiterB = RotL64((aOrbiterB * 15439872930381050291U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9233542707022629190U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1205501586581350876U;
            aOrbiterK = RotL64((aOrbiterK * 2596053290311090589U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10878718669747466677U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8066049063548639241U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 3031382633089381605U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterI) + 861295180226875235U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9134969787937288583U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 7565008208670843555U), 19U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterD, 51U)) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterB, 12U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterI, 35U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 27U)) + aOrbiterI) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aInvestLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30456U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 30741U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 28180U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27610U)) & S_BLOCK1], 14U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31902U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 57U)) + 3561491146322798260U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 27U)) + 7075025056181885339U) + aNonceWordI;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 5U)) + 9230910887904171613U;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 4U)) + RotL64(aCarry, 23U)) + 4119781172609908917U) + aNonceWordH;
            aOrbiterK = (aWandererF + RotL64(aIngress, 13U)) + 17155609083870983149U;
            aOrbiterF = (((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 2423018561430181695U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 21U)) + 12957280305617615744U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2461704174772065813U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7907123257849391997U;
            aOrbiterH = RotL64((aOrbiterH * 9416171962847312179U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7257868138318960007U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16425903703085702285U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 7996935869077231999U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 2990822664594079467U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5654819006718953817U;
            aOrbiterJ = RotL64((aOrbiterJ * 4465096036756887801U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12183676471235678779U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15026286960542123922U;
            aOrbiterI = RotL64((aOrbiterI * 17199049329995315279U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 12169080607071830522U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2906296852254787499U;
            aOrbiterD = RotL64((aOrbiterD * 6754514406846040163U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3029858695410344584U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14406410317495954566U;
            aOrbiterF = RotL64((aOrbiterF * 9663780721657983421U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11048818178401163861U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13622063920319445043U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2516025554421589857U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 20U));
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterI) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterK, 28U)) + aPhaseHWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 22U) + aOrbiterD) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 11U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 19U)) + aOrbiterD);
            aWandererC = aWandererC ^ (((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterI, 57U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
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
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 722U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 1026U)) & W_KEY1], 20U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 637U)) & W_KEY1], 4U) ^ RotL64(mSource[((aIndex + 1093U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 18U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 13U)) + 16802219662864902427U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 57U)) + 14332033461409490629U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 41U)) + 8781794298640286845U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 44U)) + 8459933908074937264U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aIngress, 5U)) + 1883580287986004426U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 11U)) + 17500258188004626118U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 35U)) + 7934811305150872870U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 19U)) + 6380363892361098905U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 24U)) + RotL64(aCarry, 51U)) + 12623079132626676910U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10455208121949202703U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8805532707916767629U;
            aOrbiterC = RotL64((aOrbiterC * 666082374369701881U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9161544391400377699U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3501434325829663268U;
            aOrbiterD = RotL64((aOrbiterD * 7933545151293799637U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 651783304096081996U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 441505031509930622U;
            aOrbiterG = RotL64((aOrbiterG * 8045355432310956143U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1771159983581326424U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15227946417377695989U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1563141188972797601U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4153717524193279095U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4404521756523902829U;
            aOrbiterF = RotL64((aOrbiterF * 1410342912973206203U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6231945075461813285U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3864780227164426690U;
            aOrbiterH = RotL64((aOrbiterH * 18031353247480673617U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1509699687948576558U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17316114302489411191U;
            aOrbiterI = RotL64((aOrbiterI * 15490661284980281585U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2250572827340157410U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6403966113144372915U;
            aOrbiterJ = RotL64((aOrbiterJ * 726441947009132383U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2329903609147403156U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2486330017319455238U;
            aOrbiterA = RotL64((aOrbiterA * 17427461345935191757U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 36U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 41U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 52U) + RotL64(aOrbiterK, 14U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterK, 47U)) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterG, 23U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4758U)) & S_BLOCK1], 22U) ^ RotL64(aKeyRowReadA[((aIndex + 4306U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 3519U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4620U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 37U) + RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aIngress, 28U)) + RotL64(aCarry, 43U)) + 11521331427196538632U;
            aOrbiterE = (aWandererA + RotL64(aScatter, 51U)) + 16653824187682957632U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 35U)) + 11654676587350088289U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 19U)) + 8010313317412193584U;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 56U)) + RotL64(aCarry, 21U)) + 1108775560502907471U) + aPhaseAOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 11U)) + 243952321439823521U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 47U)) + 2324945800401240403U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 39U)) + 9257554497543369657U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 16701314607244592540U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3900445848034341782U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7652316487347103658U;
            aOrbiterH = RotL64((aOrbiterH * 11480123491361589799U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14980368605272070578U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2001165460948764796U;
            aOrbiterI = RotL64((aOrbiterI * 8110980921827107649U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1911044015666991050U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11366207111147818339U;
            aOrbiterG = RotL64((aOrbiterG * 17234439040652553865U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16469329744002456607U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8062793687044950815U;
            aOrbiterD = RotL64((aOrbiterD * 5856142259851144369U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15364721421972807872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8979915611483540231U;
            aOrbiterE = RotL64((aOrbiterE * 10899377466171153383U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7654234623563110457U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1526832460342135008U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12766083052650723051U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1596625448797520938U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15723912914858523080U;
            aOrbiterJ = RotL64((aOrbiterJ * 6003857787643420337U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7664226719746532168U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13767298788411473401U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15663266144965532019U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8371251860069346385U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 10143279934304029980U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12764966547132248131U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 5U)) + aOrbiterI);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 22U) + aOrbiterE) + RotL64(aOrbiterK, 39U));
            aWandererI = aWandererI + (((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterI, 56U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 27U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 4U) + RotL64(aOrbiterC, 11U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterD, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 44U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6289U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadB[((aIndex + 5986U)) & W_KEY1], 24U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6563U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7790U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 7474U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 56U)) + 9220392006207660113U) + aPhaseAOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 5U)) + 11305018553489132882U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + 5860373868073513684U) + aPhaseAOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 12319586170883987589U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 14072333614354649021U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 9332158529453194608U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 14U)) + 3860569321145958686U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 37U)) + 8119005668901240093U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 51U)) + 13918259792880333239U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6938856216758228704U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3960905839118710604U;
            aOrbiterB = RotL64((aOrbiterB * 16203746868670689793U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 6043879193734253929U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15691425268831319195U;
            aOrbiterF = RotL64((aOrbiterF * 7189195135654636271U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14912209933584715274U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16180183395910618923U;
            aOrbiterJ = RotL64((aOrbiterJ * 3942858974766467849U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4966642362507707776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 6962226782462822861U;
            aOrbiterI = RotL64((aOrbiterI * 3647802407741095419U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12409120845092026295U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2302946450253872465U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7099576330777297911U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16118304388937163838U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15968419034359049422U;
            aOrbiterA = RotL64((aOrbiterA * 11736207775827080165U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17098982091525008231U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 10298979200690822062U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12620028874653521945U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 552826643694256437U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11786560990790695378U;
            aOrbiterC = RotL64((aOrbiterC * 11190309640069208311U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13730399230389329793U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17614226859252305432U;
            aOrbiterE = RotL64((aOrbiterE * 2640019643570222977U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterC, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 22U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 5U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 56U)) + aPhaseAWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            aWandererF = aWandererF + ((RotL64(aScatter, 34U) + RotL64(aOrbiterE, 47U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 52U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 10U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9804U)) & S_BLOCK1], 38U) ^ RotL64(aKeyRowReadB[((aIndex + 10119U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 9138U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9169U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9722U)) & W_KEY1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8806U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 20U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aCross, 11U)) + 14008824488073394623U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 43U)) + 13317978415866411468U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 51U)) + 13209180141897453900U;
            aOrbiterK = (aWandererC + RotL64(aIngress, 34U)) + 11870521586865233578U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 8052156380448047385U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 5U)) + 12158131176743680605U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 14674467487607719347U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 18055496790566231147U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 60U)) + 3838105585041578784U) + aPhaseBOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2839568255183054418U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11933612922864258179U;
            aOrbiterA = RotL64((aOrbiterA * 7571964469321160347U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6289849094151630580U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2640344350528492271U;
            aOrbiterI = RotL64((aOrbiterI * 16197726750829369365U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16306175266267657791U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3339898380394883600U;
            aOrbiterJ = RotL64((aOrbiterJ * 7105436590182982373U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15017076663742800002U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8973064296077602496U;
            aOrbiterB = RotL64((aOrbiterB * 9309462227233615761U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17580319233338139859U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14063208878807603874U;
            aOrbiterK = RotL64((aOrbiterK * 16601475239075164585U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13326130855721009942U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 12843186026737544416U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4975848122837321619U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14102887715772847499U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14495942314329085733U;
            aOrbiterE = RotL64((aOrbiterE * 4236795312917583565U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11564857125101669667U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17435970784822000464U;
            aOrbiterC = RotL64((aOrbiterC * 1472691848852381173U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16561390130356833062U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9952805588514363872U;
            aOrbiterD = RotL64((aOrbiterD * 3720874990001086597U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 56U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 24U)) + aOrbiterI) + RotL64(aCarry, 27U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 39U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + aPhaseBWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 53U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterA, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 20U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aCross, 14U) + RotL64(aOrbiterB, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11076U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 13198U)) & W_KEY1], 5U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12400U)) & W_KEY1], 21U) ^ RotL64(mSource[((aIndex + 13644U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 12807U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11063U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 11281U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 26U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 42U)) + RotL64(aCarry, 43U)) + 4751694786009671052U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 23U)) + 16362725160370844224U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 5U)) + 6360885380915941057U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 37U)) + 5154536007972297036U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + 9362540581874808253U) + aPhaseBOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 11U)) + 13902493871525612934U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 47U)) + 10208452885367546542U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 5U)) + 3117030377279160998U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 21U)) + 17286247690414027870U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 3930314320040949141U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7289525252391668404U;
            aOrbiterC = RotL64((aOrbiterC * 15452162299105112187U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3434167955466809185U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17852573095128575663U;
            aOrbiterG = RotL64((aOrbiterG * 1485660158767033425U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6137259687928853253U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13992510605237574698U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15346263295995333395U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6470556523400123474U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 4333255670390099293U;
            aOrbiterI = RotL64((aOrbiterI * 11089933812030082647U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7700424876430257995U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 16920736951239453071U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8920407493132380497U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1635071690430295730U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9966700845966398620U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17210048121896546867U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9833458070123027075U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 1990346556486746432U;
            aOrbiterH = RotL64((aOrbiterH * 8704943923474148699U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13339523466436517327U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5018264760406215603U;
            aOrbiterJ = RotL64((aOrbiterJ * 2769197961801783627U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 123427497520755346U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4535841104215792886U;
            aOrbiterF = RotL64((aOrbiterF * 1417676310539177131U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 18U) + aOrbiterG) + RotL64(aOrbiterJ, 39U));
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 57U)) + aOrbiterC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 43U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 6U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 30U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14873U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13769U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14756U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15403U)) & W_KEY1], 19U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15810U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 14100U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15090U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 20U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererF + RotL64(aIngress, 28U)) + 9751314027302668907U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 12175450995523107056U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 27U)) + 17519694958730119552U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 39U)) + 9093525527925682263U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 43U)) + 3713831321786810138U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 13U)) + 10108355209191835040U) + aPhaseBOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 51U)) + 12956307447311314768U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 48U)) + 1904298513945877359U) + aPhaseBOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 35U)) + 4658049993308574460U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9826333658248851902U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12058666914724365134U;
            aOrbiterC = RotL64((aOrbiterC * 964233873188373939U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 2516574707110528099U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13335308331049750235U;
            aOrbiterG = RotL64((aOrbiterG * 5880227828760598587U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 8230749255538495304U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16536559486797811486U;
            aOrbiterA = RotL64((aOrbiterA * 7097036838156464969U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 12387639130570188998U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8459259798142872020U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8001346480955847013U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 16083784052002800300U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1957284290736468379U;
            aOrbiterD = RotL64((aOrbiterD * 5046501301740813065U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7349538179311335863U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 16395170077006105258U;
            aOrbiterJ = RotL64((aOrbiterJ * 4230485452156662763U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3317652065873784068U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5517155804799120700U;
            aOrbiterE = RotL64((aOrbiterE * 9789270651974719183U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5568525912112200094U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9334250662962319598U;
            aOrbiterB = RotL64((aOrbiterB * 5034887614541768961U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5641394627075994165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13524971148931512745U;
            aOrbiterF = RotL64((aOrbiterF * 3699457147759854357U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH + ((RotL64(aCross, 12U) + aOrbiterD) + RotL64(aOrbiterI, 56U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 11U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 46U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 48U) + aOrbiterJ) + RotL64(aOrbiterI, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 14U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 18648U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 17962U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 18618U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((aIndex + 18652U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17887U)) & W_KEY1], 20U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19027U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17281U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 22U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 29U)) + 12029393034357490020U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 51U)) + 4526754731580694987U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 17060419646421271853U) + aPhaseCOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 24U)) + 4128488893837059683U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 11U)) + 12706894827547160110U;
            aOrbiterE = (aWandererD + RotL64(aCross, 35U)) + 12506324593645825056U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 47U)) + 12581344490649250025U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 14357032418199130132U) + aPhaseCOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 18U)) + RotL64(aCarry, 35U)) + 15341977701796331249U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 7086602307544733241U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12398300065276832486U;
            aOrbiterJ = RotL64((aOrbiterJ * 18157408831225635333U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2499745046076601988U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7249361592814001829U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14597139848072319685U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3254456186337366437U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3472973415969046680U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14583566953969168353U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7905718972111691591U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15941413652144021522U;
            aOrbiterI = RotL64((aOrbiterI * 3473779492962783565U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10583964125960308762U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13659925272340853715U;
            aOrbiterD = RotL64((aOrbiterD * 16708294803316630743U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9487054537489454887U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13287757570441887517U;
            aOrbiterE = RotL64((aOrbiterE * 17351439045329892107U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 15279245465808571942U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12424999114621745879U;
            aOrbiterF = RotL64((aOrbiterF * 2274918760256527137U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13915392738892970475U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13797668053788805126U;
            aOrbiterC = RotL64((aOrbiterC * 13752161103680525317U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14344766585550401077U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13727554194373146727U;
            aOrbiterH = RotL64((aOrbiterH * 17164450431362670223U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 4U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 40U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + aPhaseCWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            aWandererH = aWandererH + ((((RotL64(aCross, 23U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aPhaseCWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 27U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterH, 54U));
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 21767U)) & S_BLOCK1], 44U) ^ RotL64(mSource[((aIndex + 19408U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 21056U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19245U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21365U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19570U)) & W_KEY1], 57U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20285U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((aIndex + 21375U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 60U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 16462052553719977502U;
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 10U)) + RotL64(aCarry, 37U)) + 12337064059566619581U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 15801005007094515447U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 3U)) + 8228706742665081656U;
            aOrbiterH = (aWandererD + RotL64(aScatter, 43U)) + 11006723027845190869U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 57U)) + 18173765337829177450U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 530215083653542558U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aCross, 39U)) + 6608611827035564511U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 34U)) + 2246051826221626809U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5228575308895381421U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 10999213210689606857U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5467601259546342925U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3773371037240485696U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8887985779436152504U;
            aOrbiterH = RotL64((aOrbiterH * 698713082830739677U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11150566414723818350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8336366151003049546U;
            aOrbiterI = RotL64((aOrbiterI * 9033771197242493699U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13233968794237090787U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8172558473508478819U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17837070423649268435U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 133564480283347997U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15104810248883567064U;
            aOrbiterK = RotL64((aOrbiterK * 706802420642303533U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9138629520201127075U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13993086066341664080U;
            aOrbiterJ = RotL64((aOrbiterJ * 4875046427147105077U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6547273508580516932U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9838727018769865759U;
            aOrbiterG = RotL64((aOrbiterG * 11395273371936839815U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11685694999526122626U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8945983172566303116U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17791527981004597623U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17606249889617356327U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9296903152000480008U;
            aOrbiterA = RotL64((aOrbiterA * 18066622289408024413U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 6U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterF, 48U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 40U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 43U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 60U)) + aOrbiterF) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 14U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23719U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[((aIndex + 24307U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22034U)) & W_KEY1], 51U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23622U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 21852U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24180U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24391U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22683U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 11U)) + (RotL64(aCarry, 58U) ^ RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 30U)) + 1708250618750199233U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 12009147777553691142U) + aPhaseCOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 8393982703399156592U) + aPhaseCOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 39U)) + 3247327098356831221U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 43U)) + 3403590155376353737U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 12U)) + 18197244558104735044U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 3096253642040701606U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 47U)) + 8012692688785412179U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 19U)) + 17531946907545680745U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17687695944270225817U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16147773866007628769U;
            aOrbiterD = RotL64((aOrbiterD * 16926442582711557877U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 18244641303026196497U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8839160526348897457U;
            aOrbiterE = RotL64((aOrbiterE * 14268021129087663397U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10599266240854068246U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2056723540756216155U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13311591601230386375U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4629354220460621284U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9505955649473204942U;
            aOrbiterJ = RotL64((aOrbiterJ * 17775391885312236187U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17078153810088721310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9470436761716263000U;
            aOrbiterB = RotL64((aOrbiterB * 5431855497250357229U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3305863413630104742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14377172434239576161U;
            aOrbiterK = RotL64((aOrbiterK * 6880176890091033423U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 415687827894226513U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16975319836893760993U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6597144958013976445U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12707054129431596074U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8974182792497231239U;
            aOrbiterI = RotL64((aOrbiterI * 7874658957269462717U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 10826131924322955095U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 4168545139712703154U;
            aOrbiterA = RotL64((aOrbiterA * 10305904857550051705U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 30U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterE, 24U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterD) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 52U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25485U)) & S_BLOCK1], 54U) ^ RotL64(aKeyRowReadA[((aIndex + 27221U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26182U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((aIndex + 26712U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26306U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26780U)) & S_BLOCK1], 51U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27287U)) & S_BLOCK1], 6U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25390U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 50U) + RotL64(aPrevious, 35U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererD + RotL64(aPrevious, 37U)) + 11480359716598965890U;
            aOrbiterD = (aWandererH + RotL64(aCross, 48U)) + 15431182525482873419U;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 3U)) + 11360504974812776707U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 9292576416573382769U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 1549257414531028975U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 5347769463033129317U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 14U)) + 17019199177478377234U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 53U)) + 16558106007323125094U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 27U)) + 3976182233825939422U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2889047161195954395U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2241831345026962605U;
            aOrbiterJ = RotL64((aOrbiterJ * 5757458560979927857U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12850802412140579294U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13541744735436450160U;
            aOrbiterI = RotL64((aOrbiterI * 906089290000537439U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2085863085516538212U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2969034221711544086U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7768528124408400403U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6482666944512391472U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16969153556875844613U;
            aOrbiterH = RotL64((aOrbiterH * 9483462388353216219U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5161314086757363678U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7150282484670673211U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8522427002337918663U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5465304381272305847U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2344610773390354017U;
            aOrbiterD = RotL64((aOrbiterD * 17010258514288089191U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8335906578006588582U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13668796013474193793U;
            aOrbiterA = RotL64((aOrbiterA * 8228000547141147777U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9663362594301419686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3683773739120343413U;
            aOrbiterC = RotL64((aOrbiterC * 8319320803406104749U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2538583190438044942U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 4454069062219406996U;
            aOrbiterK = RotL64((aOrbiterK * 16329554225309389599U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 50U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererK = aWandererK + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterA, 4U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterH, 13U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterK, 38U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererE, 14U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27811U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 29847U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29472U)) & W_KEY1], 50U) ^ RotL64(aFireLaneC[((aIndex + 27345U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29770U)) & W_KEY1], 3U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29431U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28962U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneB[((aIndex + 27673U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 22U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 60U)) + 17936518874386450467U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 3U)) + 13722737841589910344U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 39U)) + 11774969167948715796U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 3640101505680493777U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 1369495382725650822U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 11827310354654653345U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 23U)) + 186037671377175394U) + aPhaseDOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 51U)) + 11428829344234627340U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 10U)) + 2275016369870029068U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15471646673734798328U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 12172082573115640145U;
            aOrbiterH = RotL64((aOrbiterH * 9629417882787847753U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6626736341348283154U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12220614992483863623U;
            aOrbiterI = RotL64((aOrbiterI * 8137086205714097487U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13157102324253760215U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 4143587482368093601U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5060677690991506895U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11007575246013796426U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11721585930088637162U;
            aOrbiterG = RotL64((aOrbiterG * 15009627907125738519U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5720789204450196217U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3094696226821431648U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4412033981712165541U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14675830108100986773U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9444071495289719645U;
            aOrbiterA = RotL64((aOrbiterA * 10983136361953366557U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5106753847015199956U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7585421898593510010U;
            aOrbiterD = RotL64((aOrbiterD * 140996914192351011U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 11746948407655524690U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16336323220286344483U;
            aOrbiterF = RotL64((aOrbiterF * 6590417628835864497U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 8030445186765781136U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 276034088015165891U;
            aOrbiterE = RotL64((aOrbiterE * 7626025612710225099U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 58U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 22U) + aOrbiterE) + RotL64(aOrbiterB, 12U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 4U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterE) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 43U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31400U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 30950U)) & W_KEY1], 12U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30402U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31376U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31171U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 30917U)) & W_KEY1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 6U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 29U)) + 11998579547770778580U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 13U)) + 8409465187298704610U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 3470222286110333500U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 60U)) + 5704486785203069994U;
            aOrbiterI = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 10334944660253279633U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aPrevious, 19U)) + 7626852700722567477U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 39U)) + 14631310754943209743U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 5U)) + 807160297237854120U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 46U)) + 5624154783624196107U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4971444394698940423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6340057638461027062U;
            aOrbiterH = RotL64((aOrbiterH * 12027586111086798629U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9003019862787819481U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13632057463595873033U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12575202147280216765U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12766104026871797746U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4062118445824915939U;
            aOrbiterK = RotL64((aOrbiterK * 13130770039048080701U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5258212525426469978U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9956946981015983939U;
            aOrbiterA = RotL64((aOrbiterA * 8106382657040497669U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10837606223056473999U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13292864885504191134U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4445739587553669471U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 166087925900318658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6786842221885441388U;
            aOrbiterE = RotL64((aOrbiterE * 4411147600413147773U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16888086378070246404U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5240855484445974002U;
            aOrbiterJ = RotL64((aOrbiterJ * 402652898573422271U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6874866669211571608U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 732890824978127460U;
            aOrbiterF = RotL64((aOrbiterF * 3776365957702257453U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5541380495707308058U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17947326584411475765U;
            aOrbiterB = RotL64((aOrbiterB * 10920952349981652899U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 4U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + (((RotL64(aScatter, 58U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 3U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterF, 46U)) + aPhaseDWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 4U) + RotL64(aOrbiterG, 19U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterE, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneB, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3344U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 2629U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 4129U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1200U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 5112U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 12426357877879529292U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 12604900366173639176U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 13511119007338929401U;
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 9878720081166788060U) + aPhaseEOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 60U)) + 15463195409806395076U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 35U)) + 6407922778852833423U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 3U)) + 7690427254160734016U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18030974031722143619U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17983938038322737041U;
            aOrbiterF = RotL64((aOrbiterF * 12479365337221685413U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16605512170117753884U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 681802273302348322U;
            aOrbiterD = RotL64((aOrbiterD * 14608920184802647123U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15550312921312083819U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17824154101711884508U;
            aOrbiterJ = RotL64((aOrbiterJ * 7358612830654795357U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1939207786756735430U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3132864634777826569U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12822929773923954849U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16576106045887115660U;
            aOrbiterA = RotL64((aOrbiterA * 16370914370769903051U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2398825881649235260U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 13700821892926092479U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10830623703416956043U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2439833784883391606U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15870638514107637833U;
            aOrbiterB = RotL64((aOrbiterB * 3797380922767479287U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 36U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterB, 19U)) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 10U) + RotL64(aOrbiterA, 48U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterF, 5U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 29U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5714U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 10732U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 10502U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7513U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 6564U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 27U)) + 2915859148137000694U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 47U)) + 210680583721444425U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 41U)) + 6668118118775650387U) + aPhaseEOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 15794200818099010989U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 13U)) + 6565076707062828369U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 19U)) + 16323164497808856719U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 6U)) + RotL64(aCarry, 23U)) + 7965435318816716560U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7390281030573369017U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2269738866911824875U;
            aOrbiterE = RotL64((aOrbiterE * 1198697877998135567U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9664014216039993873U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18284857398028357633U;
            aOrbiterH = RotL64((aOrbiterH * 8402008251343393737U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 367667619795303009U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7935945060956274197U;
            aOrbiterJ = RotL64((aOrbiterJ * 5481786693511955209U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16683666162337789540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10655658270998102390U;
            aOrbiterI = RotL64((aOrbiterI * 15231596813382239841U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8307037916581540297U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3247742749860703524U;
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10446792483683818139U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16374602929344972364U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12599903932725787599U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2411334498322777183U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 1093701164116833765U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13129220206835381729U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 4U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterA, 35U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 3U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 48U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterI, 21U));
            aWandererA = aWandererA + (((RotL64(aCross, 4U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14963U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 13159U)) & S_BLOCK1], 22U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13085U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 15802U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11309U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 12933U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCross, 60U)) + (RotL64(aCarry, 47U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 13296600294247799698U;
            aOrbiterK = (aWandererA + RotL64(aCross, 13U)) + 5818503518080877515U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 6735784238734173597U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 7368398209488856201U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aCross, 19U)) + 961734029066455638U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 51U)) + 797011946660892011U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 58U)) + 12841876018396622350U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 16213253970483895623U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15186950557113470375U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4647470430467908107U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5117930310827477341U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12265429373166094162U;
            aOrbiterE = RotL64((aOrbiterE * 1522823535151532249U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13920531346698601568U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 14695405206998211456U;
            aOrbiterA = RotL64((aOrbiterA * 13950964363414164279U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7851960904825938443U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9501511171732550190U;
            aOrbiterC = RotL64((aOrbiterC * 5614164120361489613U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5663365182245722077U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9607860124321315555U;
            aOrbiterB = RotL64((aOrbiterB * 3461820361914280601U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 18171052650586819280U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 3442698321538580861U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6317525514963824829U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1491052813469258970U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3956599824067616133U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2928600779267623085U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererC = aWandererC + (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 53U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterE, 60U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterB);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 6U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21116U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((aIndex + 21751U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 18842U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19529U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18224U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21688U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 52U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererE + RotL64(aScatter, 35U)) + 13481227414590594621U;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 17425964381118918026U;
            aOrbiterE = (aWandererG + RotL64(aCross, 51U)) + 4792004356135956581U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 11926849936000639098U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 18U)) + 990697329347742142U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 9307721505373076588U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 43U)) + 17605732738841908719U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13110764518634187439U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17970109897810645911U;
            aOrbiterE = RotL64((aOrbiterE * 10395095143998920213U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10273133817644703654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11239046688920468137U;
            aOrbiterF = RotL64((aOrbiterF * 5197802934333553327U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8355821483275763145U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15522151127786049345U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4844278537850520413U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5381663179722418112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9551368011768104906U;
            aOrbiterC = RotL64((aOrbiterC * 14202470972121732997U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16264476585232221270U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 7721417776432288282U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10267770327791051869U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 339418090653475277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3247926250495935511U;
            aOrbiterG = RotL64((aOrbiterG * 16824669543765729097U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3390560045236418590U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3894024951542543635U;
            aOrbiterH = RotL64((aOrbiterH * 10599637790900418767U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterI, 44U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterC, 13U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 37U)) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 35U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 21U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + aPhaseEWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 27055U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 22418U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27144U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23192U)) & S_BLOCK1], 18U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23452U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 22643U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererE + RotL64(aCross, 21U)) + 13174219512651137892U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 2715455762789269341U) + aPhaseEOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 1338018183235594313U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 27U)) + 16566866551729552930U) + aPhaseEOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 60U)) + RotL64(aCarry, 23U)) + 6901845297307236726U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 41U)) + 2476078302049201718U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 47U)) + 15531109473927052260U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4087849380858572351U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5167830630098599644U;
            aOrbiterE = RotL64((aOrbiterE * 1982835131228146099U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 7275995452428627217U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14794340370010024117U;
            aOrbiterG = RotL64((aOrbiterG * 8779497557416568379U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8509217403041662849U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2321522025240806996U;
            aOrbiterD = RotL64((aOrbiterD * 113568101672878697U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 5676672952755594051U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2304681269233504384U;
            aOrbiterK = RotL64((aOrbiterK * 15731441084605554497U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8383399721062437300U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13181984036942227666U;
            aOrbiterA = RotL64((aOrbiterA * 1648761328771932069U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 13602604532551684210U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12725687663616352843U;
            aOrbiterC = RotL64((aOrbiterC * 4684699861686199753U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5831790822416009806U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 4535048543735457407U;
            aOrbiterH = RotL64((aOrbiterH * 12076777878870257053U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 54U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterG, 51U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 10U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 42U));
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32411U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 27634U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28327U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31339U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32649U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 30335U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 50U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aCross, 34U)) + RotL64(aCarry, 35U)) + 13053031069776604052U;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 13U)) + 1331396630251085122U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 41U)) + 15879286043343942393U) + aPhaseEOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 19U)) + 13590365633321406830U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 14569235423040242618U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 27U)) + 11397370636618371560U;
            aOrbiterK = (aWandererH + RotL64(aCross, 5U)) + 3455933494593971847U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1307153376443784593U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10688618762584786871U;
            aOrbiterI = RotL64((aOrbiterI * 9503823896874842411U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17746248451153600096U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 8512568600755410158U;
            aOrbiterA = RotL64((aOrbiterA * 16648320170768234063U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8950230550112591092U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17790968369472845496U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5104988920132008913U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 12583323865381967534U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 11243927099685293887U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12867003042486433971U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9690268715525781389U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7466066217365074653U;
            aOrbiterK = RotL64((aOrbiterK * 17565696765505320889U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3673528673209875118U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14079103852360952255U;
            aOrbiterJ = RotL64((aOrbiterJ * 17449228863409999629U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 6747836856132250630U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5027692924422297153U;
            aOrbiterC = RotL64((aOrbiterC * 2492421273167124437U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterE, 53U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 27U)) + aOrbiterC) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterD, 41U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            aWandererD = aWandererD + ((RotL64(aCross, 36U) + aOrbiterD) + RotL64(aOrbiterJ, 10U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneD, aSnowLaneA, aInvestLaneC, aExpandLaneC, aSnowLaneB, aExpandLaneD, aWorkLaneA, aExpandLaneB, aWorkLaneB, aExpandLaneA, aWorkLaneC, aInvestLaneB
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneD backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2122U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 2399U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1535U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3166U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4037U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 3112U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCarry, 43U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 41U)) + 5697928251815176134U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 337587740689259575U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 48U)) + RotL64(aCarry, 35U)) + 4927686903263973950U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 37U)) + 3742409032569801033U;
            aOrbiterA = (aWandererF + RotL64(aScatter, 3U)) + 1608092659172197650U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 27U)) + 15848744267145717509U;
            aOrbiterK = (aWandererB + RotL64(aCross, 35U)) + 15300174177963339253U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 11U)) + 14162868453323648628U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 60U)) + 12020167069983729869U) + aPhaseFOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 41U)) + 16259538291658723956U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 13U)) + 8516686212464112245U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3722184575520553132U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5663609293306386784U;
            aOrbiterF = RotL64((aOrbiterF * 14364218128780764749U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15265344442454471986U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3050323350098829515U;
            aOrbiterC = RotL64((aOrbiterC * 5890624677162388135U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1093356813820599238U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 15167726103772238440U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5719466863561311069U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15170797965325981472U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17826286701992981628U;
            aOrbiterA = RotL64((aOrbiterA * 11186808881726573677U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14710892030473425181U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 397194787697553904U;
            aOrbiterB = RotL64((aOrbiterB * 14368930300818752833U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1273724124862533034U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13018397560392545616U;
            aOrbiterH = RotL64((aOrbiterH * 4644812473262395329U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9638716186445643730U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7255587739807843785U;
            aOrbiterI = RotL64((aOrbiterI * 6055682981584011189U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9272350563697399628U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1040729335295009339U;
            aOrbiterD = RotL64((aOrbiterD * 17825687660830291443U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12128124729613601747U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2285238815562202219U;
            aOrbiterJ = RotL64((aOrbiterJ * 15398840993074390573U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6339113298619163493U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5911895708485037040U;
            aOrbiterG = RotL64((aOrbiterG * 3271006139923200439U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7601399508218901328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5697928251815176134U;
            aOrbiterK = RotL64((aOrbiterK * 8184257916861355735U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 53U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 40U));
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 58U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterK, 41U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterE, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterI, 44U)) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF + (((RotL64(aCross, 18U) + RotL64(aOrbiterE, 21U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 34U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 7819U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 7836U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6510U)) & S_BLOCK1], 38U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7891U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8077U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7852U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7715U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 42U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererE + RotL64(aPrevious, 47U)) + 10404808878585437255U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 42U)) + 10587858736301591439U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 1430530909801644435U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 19U)) + 9090938022430118902U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 51U)) + 12936604311751121235U;
            aOrbiterA = (aWandererH + RotL64(aCross, 23U)) + 1000583006020232032U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 13U)) + 12352532088997042232U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 16723410947058502564U;
            aOrbiterB = (aWandererK + RotL64(aCross, 57U)) + 16614089235313154270U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 53U)) + 4245553025593349277U) + aPhaseFOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 39U)) + 3353146318549477494U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5935727336135635196U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 10312187090293319667U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1395964500396711899U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12192843181244744484U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2542570124502586365U;
            aOrbiterD = RotL64((aOrbiterD * 17222847847573534963U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3315472769469002444U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17512858811783071174U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9070400454074283765U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16633218007427888082U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2502077714838858460U;
            aOrbiterG = RotL64((aOrbiterG * 970762420815997725U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14792910273226469214U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15739513291150783151U;
            aOrbiterE = RotL64((aOrbiterE * 11896279674116906915U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 2192903544350345992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 844428341223009295U;
            aOrbiterJ = RotL64((aOrbiterJ * 4768368713974002539U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2998511458298901402U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7790789639864783373U;
            aOrbiterC = RotL64((aOrbiterC * 9173097618440495497U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4540735375055164995U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13700342877362633034U;
            aOrbiterA = RotL64((aOrbiterA * 14730797752841670505U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 16966725424259324323U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5945539295893015935U;
            aOrbiterK = RotL64((aOrbiterK * 12226268057062268981U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12560355243513521281U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2104086086480258265U;
            aOrbiterB = RotL64((aOrbiterB * 17989755118752755577U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4476697099257280568U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10404808878585437255U;
            aOrbiterH = RotL64((aOrbiterH * 6245415417832089357U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 56U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 14U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterG, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterG, 26U));
            aWandererG = aWandererG + (((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 29U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 37U) + RotL64(aOrbiterI, 11U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterK, 52U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13471U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 12572U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16297U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14353U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14468U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 22U) + RotL64(aIngress, 47U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 26U)) + 2672739400294801233U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 8475624545015101850U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 43U)) + 1252755112289831257U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 5U)) + 7938039507649183387U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 35U)) + 8167413146948861022U;
            aOrbiterC = (aWandererE + RotL64(aCross, 57U)) + 17712313989694374353U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 12U)) + RotL64(aCarry, 19U)) + 7637042279892596975U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 53U)) + 15770412950033467341U;
            aOrbiterB = (aWandererC + RotL64(aPrevious, 47U)) + 3951812021898608685U;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 51U)) + 8656983621098246507U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 17943342344730687317U) + aPhaseFOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3087677463651608668U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16493240011924342788U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16898479041530771871U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7750923317452683057U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2185924841611106546U;
            aOrbiterC = RotL64((aOrbiterC * 708072658250726381U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14676868738946722416U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 6849098251696302393U;
            aOrbiterI = RotL64((aOrbiterI * 2599806275837778069U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17817755047153606419U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9900465270314068757U;
            aOrbiterB = RotL64((aOrbiterB * 9267925873983176685U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11380000891112113701U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15930503831156546113U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14450535035065393845U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5439183530402949780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3731802052051181843U;
            aOrbiterF = RotL64((aOrbiterF * 7739775058947333169U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14432344583247783600U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16192098795467501636U;
            aOrbiterA = RotL64((aOrbiterA * 6285466374319549047U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1523272672673940290U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 7462092373525113574U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15067751170235540679U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4612539457663050732U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7959404391235752875U;
            aOrbiterK = RotL64((aOrbiterK * 137834571274065007U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11853468935131763944U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3575434598998149168U;
            aOrbiterJ = RotL64((aOrbiterJ * 16971321675425065041U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6135993440654291404U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2672739400294801233U;
            aOrbiterG = RotL64((aOrbiterG * 12891757276825641567U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 37U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterJ, 56U));
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterD, 20U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + RotL64(aOrbiterC, 27U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 53U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 19332U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 20009U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19753U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19903U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 16942U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aIngress, 58U)) + 898812731947995389U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 8677347622525527167U;
            aOrbiterF = (aWandererA + RotL64(aScatter, 41U)) + 770321564027567654U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 35U)) + 11020474858081526395U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 5U)) + 17289793580414993470U;
            aOrbiterH = (aWandererI + RotL64(aCross, 29U)) + 10111912559295118444U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 48U)) + 8083622125544542011U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 39U)) + 7149858558922988240U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 27U)) + 5919683821379905699U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 6860902846079238714U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 47U)) + 15083517836867542075U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14852868368708376381U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9860233289028878323U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 772406119079116272U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7971141501337627589U;
            aOrbiterI = RotL64((aOrbiterI * 10168120622976358617U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8478568022896691911U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4027604850785607101U;
            aOrbiterJ = RotL64((aOrbiterJ * 4826627523578901467U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17199331557841535430U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7515957656979776361U;
            aOrbiterB = RotL64((aOrbiterB * 5468950152869656599U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17138249294921502391U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16236812863923234668U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2925542836624164807U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16941524155859123682U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11240343728857342866U;
            aOrbiterK = RotL64((aOrbiterK * 7281012444214294659U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 15163914964139858328U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6673576554415729652U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1558880328574736975U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5399050402101642989U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11806006719060024615U;
            aOrbiterC = RotL64((aOrbiterC * 15782156615926092159U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9812148913932011655U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4737919734590584193U;
            aOrbiterG = RotL64((aOrbiterG * 2739737604370936959U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3415477403346468057U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5922725868927615919U;
            aOrbiterE = RotL64((aOrbiterE * 12390148483052777871U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 17435294951520465659U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 898812731947995389U;
            aOrbiterA = RotL64((aOrbiterA * 17248379279729365007U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 18U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterE, 11U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 60U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 14U)) + aOrbiterH) + aPhaseFWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 44U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24499U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((aIndex + 26716U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 25990U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24698U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 26622U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 18302975933754610273U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 29U)) + 16736972646771456082U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 17389406266488137442U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 24U)) + RotL64(aCarry, 47U)) + 5252511566486165539U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 53U)) + 5730715427422747640U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 51U)) + 6412695646456045825U;
            aOrbiterF = (aWandererE + RotL64(aCross, 11U)) + 9539701605708994494U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 42U)) + 18355107116412945722U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 19U)) + 11735742491750132942U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 57U)) + 12363819388562658842U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 13U)) + 5861430292304371543U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 15027487084595017708U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7012850020745791926U;
            aOrbiterB = RotL64((aOrbiterB * 15952928839355613939U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11904871669287886120U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11199760114477343208U;
            aOrbiterE = RotL64((aOrbiterE * 7156374911847525867U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3856004502263742700U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3705931243173921893U;
            aOrbiterF = RotL64((aOrbiterF * 10334871178498711485U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12305785390539209389U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 18057980996551978823U;
            aOrbiterJ = RotL64((aOrbiterJ * 4850564181113470859U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 3229431819292153014U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2994716629242460094U;
            aOrbiterG = RotL64((aOrbiterG * 1029427328395257917U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9796307843453735512U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 2957260393651252432U;
            aOrbiterH = RotL64((aOrbiterH * 7261055869794739609U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 4060469664218866340U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17462081697889685330U;
            aOrbiterK = RotL64((aOrbiterK * 7712009170974461225U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13638660073917821172U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15202349592659062565U;
            aOrbiterI = RotL64((aOrbiterI * 4514326257446024301U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12071949111168967041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11930843273199806728U;
            aOrbiterA = RotL64((aOrbiterA * 16229663295689525137U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11294220104731500296U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 440743185210586759U;
            aOrbiterD = RotL64((aOrbiterD * 14810195235168807229U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8514240764798061804U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 18302975933754610273U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1972439346780950873U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 37U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterB, 56U));
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 23U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 48U) + RotL64(aOrbiterB, 35U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererH = aWandererH + ((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterD, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 44U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29723U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 32696U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 31091U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32587U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30272U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererE + RotL64(aCross, 21U)) + 13174219512651137892U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 3U)) + 2715455762789269341U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 12U)) + 1338018183235594313U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 39U)) + 16566866551729552930U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 6901845297307236726U;
            aOrbiterF = (aWandererD + RotL64(aCross, 41U)) + 2476078302049201718U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 37U)) + 15531109473927052260U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 5U)) + 4087849380858572351U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 13U)) + 5167830630098599644U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 51U)) + 7275995452428627217U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 14794340370010024117U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 8509217403041662849U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2321522025240806996U;
            aOrbiterH = RotL64((aOrbiterH * 113568101672878697U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5676672952755594051U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2304681269233504384U;
            aOrbiterD = RotL64((aOrbiterD * 15731441084605554497U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 8383399721062437300U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13181984036942227666U;
            aOrbiterF = RotL64((aOrbiterF * 1648761328771932069U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13602604532551684210U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12725687663616352843U;
            aOrbiterI = RotL64((aOrbiterI * 4684699861686199753U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5831790822416009806U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4535048543735457407U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12076777878870257053U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10617608605149381858U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5244225377862618630U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15307177251167023999U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 18229989093139888456U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9728120630096192811U;
            aOrbiterK = RotL64((aOrbiterK * 16052574428163231023U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1312233443099767304U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8043115602160128619U;
            aOrbiterB = RotL64((aOrbiterB * 9365756845731616963U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4679339316686216023U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 211799535650113758U;
            aOrbiterJ = RotL64((aOrbiterJ * 1478368466990144107U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13307123762743628190U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7093673238704478497U;
            aOrbiterE = RotL64((aOrbiterE * 13273906568866802561U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 16396459072175632290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13174219512651137892U;
            aOrbiterA = RotL64((aOrbiterA * 7581008806810219369U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 60U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererC = aWandererC + ((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterA, 50U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + aPhaseFWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 46U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 21U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterE, 29U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterE, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererF, 34U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2397U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 1272U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1420U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4510U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7195U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2271U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 23U)) + (RotL64(aIngress, 37U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 12262991801139086177U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 14U)) + 7963038771924890197U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 35U)) + 15540520327933568896U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 8745565892055020722U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aIngress, 39U)) + 16619329199683755286U) + aPhaseGOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10865705026433867260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2743368697984518059U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2989232417816919375U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5556006271515473135U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5355833281353498588U;
            aOrbiterE = RotL64((aOrbiterE * 4190140212757841511U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8313616108963479829U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16657121016801866434U;
            aOrbiterC = RotL64((aOrbiterC * 331533349428472477U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 16532226425013000833U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5800465874932467232U;
            aOrbiterG = RotL64((aOrbiterG * 5966395771690704577U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 17882948163883121328U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15029375310296563175U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17021415832288477713U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 18U);
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 44U) + aOrbiterE) + RotL64(aOrbiterH, 56U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12406U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((aIndex + 13473U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 11568U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9942U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12544U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 13509U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 27U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 6733949564325516029U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 13U)) + 7304098437143918796U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 3923949518391777800U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 54U)) + RotL64(aCarry, 43U)) + 14243591003388927124U) + aPhaseGOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 21U)) + 18329498724605410406U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 13118172167747037249U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 5272025143849174212U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9935990954321437743U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16075917179214318424U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15263590648674658399U;
            aOrbiterI = RotL64((aOrbiterI * 9918239923411740337U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13730046728289525921U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 7703141464499623408U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5886009900621521987U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1382279753822135359U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2973369221699098292U;
            aOrbiterA = RotL64((aOrbiterA * 7440242040663550631U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11578274119583013219U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3419411247737896674U;
            aOrbiterJ = RotL64((aOrbiterJ * 17814942652262802991U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (RotL64(aOrbiterB, 56U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 24U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 38U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aPhaseGWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21744U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 16389U)) & S_BLOCK1], 54U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 19486U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23939U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18224U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 19192U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 28U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aCross, 51U)) + 9080426856729228705U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 36U)) + RotL64(aCarry, 47U)) + 7851218321653539276U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 7023344692919298036U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 23U)) + 9772846154227440734U;
            aOrbiterA = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 12008298632429608431U) + aPhaseGOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12201090455849562875U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 9498721803411445471U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6511810500788451775U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 351203764023093632U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 4966360430644539250U;
            aOrbiterA = RotL64((aOrbiterA * 10138518378274592739U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 9194167899071345693U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4922477697284269116U;
            aOrbiterI = RotL64((aOrbiterI * 8444814161720407881U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15742625291642356429U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7528703106518431730U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11530049278751507567U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15279053574704935317U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2425839793660355555U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11486964816849830667U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG) + aPhaseGWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 56U) + RotL64(aOrbiterA, 56U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterE, 43U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26426U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((aIndex + 30963U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 29848U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31317U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30168U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24607U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 37U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 7790166497945719700U;
            aOrbiterK = (((aWandererB + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 7136208896846119188U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 21U)) + 12123156943355100886U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 30U)) + 5095546037880875199U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 17642705393916765992U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 9918479837334416990U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4890009823843176466U;
            aOrbiterE = RotL64((aOrbiterE * 16898633181256061239U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 17652590786213674124U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 870002527644696135U;
            aOrbiterK = RotL64((aOrbiterK * 915408393979165539U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12545429703552643682U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5310272867406182581U;
            aOrbiterI = RotL64((aOrbiterI * 10420003334833925011U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3264719049050179440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 1967241238180278937U;
            aOrbiterB = RotL64((aOrbiterB * 13004319774269457957U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 773883832927040736U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12766817190261232485U;
            aOrbiterF = RotL64((aOrbiterF * 7448864556802318431U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 50U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 44U)) + aOrbiterI);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 52U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0;
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
        // ingress from: aExpandLaneA, aExpandLaneB, aInvestLaneA
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1069U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 1831U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 8162U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3584U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2363U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1017U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCarry, 4U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 5295352595333316211U;
            aOrbiterE = (((aWandererH + RotL64(aScatter, 38U)) + RotL64(aCarry, 47U)) + 2341795367042042605U) + aPhaseHOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 27U)) + 10122175780504033663U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 10084612804696198554U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 13U)) + 16470424309851045971U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 656016130975227994U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15313268829659834317U;
            aOrbiterF = RotL64((aOrbiterF * 3553315008401417123U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3795220914993923394U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14044442220988813825U;
            aOrbiterB = RotL64((aOrbiterB * 3270650852546606835U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 3804224626734584802U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7980006306010255693U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13958505239726088561U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13746830564584711549U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11852212099729274845U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2164880979318247855U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9083223471018084847U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13706723820703853346U;
            aOrbiterA = RotL64((aOrbiterA * 11361854103656219887U), 13U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 29U)) + aOrbiterA) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 40U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 19U)) + aOrbiterB) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterE, 44U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15784U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 15444U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10407U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8504U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15231U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9479U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 37U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 16424657151168221875U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aScatter, 12U)) + 17150123681886380361U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 16041993588694572757U) + aPhaseHOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 9871185846434828537U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 47U)) + 11227236398354430757U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 5399325217402192631U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9248828789282890454U;
            aOrbiterA = RotL64((aOrbiterA * 6733832755349139621U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9041370494203701062U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14944424084524970764U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10283363059424655079U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5481938174456671041U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14783648629543752715U;
            aOrbiterI = RotL64((aOrbiterI * 7260164783191886395U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12355573914530445723U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 9863991559011968318U;
            aOrbiterG = RotL64((aOrbiterG * 8495251211794343179U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16149688605937250965U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 106041828692026825U;
            aOrbiterJ = RotL64((aOrbiterJ * 12199934305374582599U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterG, 36U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 34U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17636U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 18630U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23352U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19731U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 16458U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 19713U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 19U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 9107326720193244489U) + aPhaseHOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 13U)) + 10868585484401664145U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 58U)) + RotL64(aCarry, 13U)) + 13637736741437846622U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 5U)) + 6130725216183918844U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 2063834478521338187U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8564870627911949158U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 6524015751064086390U;
            aOrbiterB = RotL64((aOrbiterB * 12055267995727104463U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9874937766875388236U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14723718409522680894U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17379140128833323431U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13767059954741528279U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6387608251033722169U;
            aOrbiterI = RotL64((aOrbiterI * 6601902195707980693U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5391425980008431000U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11524218415655093779U;
            aOrbiterA = RotL64((aOrbiterA * 12508457981779189389U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 155510463350385905U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10554591788433641311U;
            aOrbiterK = RotL64((aOrbiterK * 5412084824127934293U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 48U) + aOrbiterE) + RotL64(aOrbiterK, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 26U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30030U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 26193U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 26717U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28544U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26214U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28386U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 30U)) + RotL64(aCarry, 3U)) + 12690502671561165478U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 47U)) + 17519943923428102801U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 10705515807975331385U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 16586447272278538179U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 5U)) + 8006560996840971798U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12928600185788857701U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14240723153798267172U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7446040187505339853U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8636219177994872072U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7586790235186467512U;
            aOrbiterB = RotL64((aOrbiterB * 15052686382507614169U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1103807034179512424U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7547526530239498693U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3360295583636013509U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8380239679344786397U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 5690809173787433519U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5354724308093372953U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 8390902801141804609U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3507306189192059486U;
            aOrbiterG = RotL64((aOrbiterG * 18336280496510253103U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterF, 29U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 38U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
