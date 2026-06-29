#include "TwistExpander_FootBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_FootBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDF928B2B2D6A6A71ULL + 0xA957C7D85D2C836AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAE35BCF89197FBD9ULL + 0xA8A333A9980D7ADAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF7FF7B0E93EBE281ULL + 0xF6472E2612B33B5DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA5826C645214592FULL + 0xADFDAB07C7FF0C01ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB70FDEB319D4530BULL + 0xACCE080C7E2933D4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xACBEEEFF1F3DD6CDULL + 0xA8E407CC25D44B21ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC23E832D2303481DULL + 0xB75643279D4BEA06ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA13FEB166F4B1785ULL + 0xE4416D7AAAE201B5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC9A7FA1F6408345BULL + 0xD43B48C6E14CC570ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9F4E0C1CCEFE8727ULL + 0xF741A186A960AFF9ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBE0080CC252C2D5FULL + 0x93FB091FEF110A6DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBB83BD17F063F2B3ULL + 0x986ECF7783D11367ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8ADA5F742E1B96DFULL + 0xE3B6B0CFE70CD690ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x9F599C2E7F6131B5ULL + 0xADCA4CE43A270C1CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDCD8A3883B16DE47ULL + 0xEA36D2B2AF77D59EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x91F6BBA40C5119DBULL + 0x98790B2F903221D2ULL);
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
            aIngress = RotL64(mSource[((aIndex + 608U)) & S_BLOCK1], 48U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 930U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 3334U)) & S_BLOCK1], 52U) ^ RotL64(mSource[((aIndex + 1990U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 11U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterE = (((aWandererE + RotL64(aIngress, 52U)) + 12632404972795375757U) + aOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = (aWandererC + RotL64(aCross, 5U)) + 5351879979055988456U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 47U)) + 3597737727467443413U) + aNonceWordJ;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 35U)) + 2830846754917852318U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 27U)) + 17311925960294518018U) + aNonceWordP;
            aOrbiterA = (aWandererG + RotL64(aScatter, 39U)) + 2083584640523695383U;
            aOrbiterG = (((aWandererJ + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 15049343611387010158U) + aNonceWordB;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 47U)) + 6443050378205811147U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 50U)) + 6021965178697344070U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 21U)) + 5080289878758029976U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 576927745306972983U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4728489691382690859U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6184355840165758855U;
            aOrbiterB = RotL64((aOrbiterB * 1515043910404156423U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11220539885798595450U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11091438724966718214U;
            aOrbiterF = RotL64((aOrbiterF * 8225347114759391961U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17184210490020062419U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2150997767099116408U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 8058553821648892499U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7021953562676903717U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17159676348343312834U;
            aOrbiterK = RotL64((aOrbiterK * 13877284519668483549U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10367891770525239784U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11922478487264201233U;
            aOrbiterD = RotL64((aOrbiterD * 9195137452661956029U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17815162358981720634U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9582631251085100284U;
            aOrbiterI = RotL64((aOrbiterI * 11838992994130850483U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 872593750259572264U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17832330100262167302U;
            aOrbiterJ = RotL64((aOrbiterJ * 1114416841510028467U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16601139856969287418U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14931287111691324985U;
            aOrbiterH = RotL64((aOrbiterH * 16757174577841001179U), 21U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 11413072442039115924U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15253605470589905889U;
            aOrbiterA = RotL64((aOrbiterA * 10832817442285245673U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3653487723581514107U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 14891378240114471865U;
            aOrbiterE = RotL64((aOrbiterE * 1386594204573386051U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15659724464711852035U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12632404972795375757U;
            aOrbiterC = RotL64((aOrbiterC * 2407347385127296647U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 58U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + aOrbiterE) + RotL64(aOrbiterB, 27U));
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aCross, 6U) + aOrbiterF) + RotL64(aOrbiterK, 4U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 41U)) + aOrbiterE) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterG) + aNonceWordN);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + aNonceWordA);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 44U)) + aOrbiterA) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 9280U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 5911U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 8555U)) & S_BLOCK1], 34U) ^ RotL64(mSource[((aIndex + 6866U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 4U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterH = (aWandererG + RotL64(aIngress, 39U)) + 9080426856729228705U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 7851218321653539276U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 7023344692919298036U;
            aOrbiterC = (aWandererC + RotL64(aCross, 54U)) + 9772846154227440734U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 12008298632429608431U) + aNonceWordF;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 51U)) + 12201090455849562875U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 41U)) + 9498721803411445471U;
            aOrbiterF = (aWandererF + RotL64(aCross, 47U)) + 351203764023093632U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 58U)) + 4966360430644539250U) + aNonceWordD;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 23U)) + 9194167899071345693U) + aNonceWordC;
            aOrbiterD = ((aWandererD + RotL64(aCross, 27U)) + 4922477697284269116U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15742625291642356429U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7528703106518431730U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 11530049278751507567U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 15279053574704935317U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2425839793660355555U;
            aOrbiterA = RotL64((aOrbiterA * 11486964816849830667U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13209849392400008898U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9041500097716231309U;
            aOrbiterE = RotL64((aOrbiterE * 340661035700748739U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7885423750878814599U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1992993999902904603U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1478629826632201617U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6120758615019314102U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 8529621625846992066U;
            aOrbiterG = RotL64((aOrbiterG * 8485991471612862467U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9125182130757385320U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15691232622970220043U;
            aOrbiterK = RotL64((aOrbiterK * 16517916951054758147U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11413090085435424697U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 11563151001080914939U;
            aOrbiterC = RotL64((aOrbiterC * 16828196274450408201U), 47U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 1778975369262558069U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3232132443557192010U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17132823737792200981U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 277456309842614908U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10470076566806421600U;
            aOrbiterI = RotL64((aOrbiterI * 7526503789282158285U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12466953663713418197U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15871548472936716844U;
            aOrbiterF = RotL64((aOrbiterF * 11788139245249205765U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12322317028530419228U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9080426856729228705U;
            aOrbiterB = RotL64((aOrbiterB * 4204042134412769955U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + aNonceWordA) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterB, 46U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 11U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 19U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 37U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterK, 48U));
            aWandererG = aWandererG + (((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 36U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 12162U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15240U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12803U)) & S_BLOCK1], 54U) ^ RotL64(pSnow[((aIndex + 13265U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererB + RotL64(aCross, 42U)) + RotL64(aCarry, 11U)) + 16200278595895089008U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 57U)) + 1029614154810465897U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 51U)) + 7129562468705441295U) + aNonceWordH;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 14388903902433951274U) + aNonceWordJ;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 40U)) + 1013568949315967455U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 3128823373497815651U) + aNonceWordG;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 19U)) + 14525694606889470589U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 5U)) + 14443983602196782887U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 35U)) + 12244220415328641190U) + aNonceWordK;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + 10477159225338766614U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 23U)) + 2842870123078131566U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8621138818955849917U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5038396344400303181U;
            aOrbiterA = RotL64((aOrbiterA * 14636756322207385447U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2768613802894372496U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 2027754864051410015U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2848088309172056399U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 15017458513904884651U;
            aOrbiterE = RotL64((aOrbiterE * 9926904679902843055U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9079797279596336139U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15424866642305110811U;
            aOrbiterD = RotL64((aOrbiterD * 12912331089970158845U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13751764050290602740U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7694557131324740282U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14980807690491467023U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3508673897305667669U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3600868397311393233U;
            aOrbiterI = RotL64((aOrbiterI * 5165032044164139165U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1222655844979128996U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2257342337168905875U;
            aOrbiterF = RotL64((aOrbiterF * 6198995971182272119U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6290990717563682725U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15308494772443447109U;
            aOrbiterH = RotL64((aOrbiterH * 1925593111157842325U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4065385272074155855U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17216369169581934516U;
            aOrbiterJ = RotL64((aOrbiterJ * 16172589962950781777U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 15683161334290612079U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4197626901960576264U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2822547214684481747U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4400047838649306704U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16200278595895089008U;
            aOrbiterG = RotL64((aOrbiterG * 6603195071605635697U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 21U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterF, 29U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 44U)) + aOrbiterJ) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 39U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 5U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 24U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererK);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 18323U)) & S_BLOCK1], 56U) ^ RotL64(pSnow[((aIndex + 16475U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18462U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(mSource[((S_BLOCK1 - aIndex + 20498U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneB[((aIndex + 21172U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 34U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererA + RotL64(aScatter, 57U)) + 9023059520606551446U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 48U)) + 662441755115638133U) + aNonceWordA;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 41U)) + 16957253361196144712U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 51U)) + 7840955025765308605U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterB = (aWandererH + RotL64(aCross, 19U)) + 346855809270395799U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 60U)) + 16099139781586668343U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 43U)) + 3706457327118322098U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 12166825885547622870U) + aNonceWordK;
            aOrbiterG = ((aWandererB + RotL64(aCross, 27U)) + 7792658665720344200U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 7128477606152986326U) + aNonceWordG;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 11116533962780290084U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10443889548568288532U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4402387036946561017U;
            aOrbiterA = RotL64((aOrbiterA * 9032964741841833277U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13002706161178447654U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 13929727277530310708U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7005639090871200285U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10949073760696935106U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15405923432006783533U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 17989565878445202495U), 51U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 18096057968822208905U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3032155040484574973U;
            aOrbiterH = RotL64((aOrbiterH * 448597307502544605U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17462076466907467134U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15471015427013701406U;
            aOrbiterI = RotL64((aOrbiterI * 6113474000571976139U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3549031751266594344U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 14243218483842508113U;
            aOrbiterG = RotL64((aOrbiterG * 9041601306479302047U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5803147589312920032U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5549470512227427855U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12592362489263862879U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10076661824293832189U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3196799148974716550U;
            aOrbiterK = RotL64((aOrbiterK * 8183276968961467775U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 5245559903456662243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 5907555542861339984U;
            aOrbiterC = RotL64((aOrbiterC * 10224549416454347583U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 12670710096595941569U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 655047039452620836U;
            aOrbiterE = RotL64((aOrbiterE * 9717552134857988153U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2654837870443908572U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9023059520606551446U;
            aOrbiterF = RotL64((aOrbiterF * 170905364378771841U), 29U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 30U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterA, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + aWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterK, 41U)) + aNonceWordD) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 56U)) + aOrbiterH) + aNonceWordB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 13U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aCross, 26U) + RotL64(aOrbiterE, 47U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterC, 58U)) + aNonceWordE);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26000U)) & S_BLOCK1], 24U) ^ RotL64(mSource[((aIndex + 25636U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25804U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25353U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25099U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((aIndex + 23847U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 56U)) + (RotL64(aCross, 43U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 15920462086654025436U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 3U)) + 487844076858004017U) + aNonceWordO;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 14502883786442630566U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 3787107318658233674U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 37U)) + 12548777544693755491U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aScatter, 39U)) + 4907309444075181683U) + aNonceWordM;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 26U)) + 18342396700266492072U) + aNonceWordJ;
            aOrbiterE = ((aWandererA + RotL64(aCross, 53U)) + 13503051997624242670U) + aNonceWordD;
            aOrbiterK = (aWandererG + RotL64(aScatter, 5U)) + 17845742460521374571U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 41U)) + 8640887211877858169U;
            aOrbiterD = (aWandererC + RotL64(aCross, 18U)) + 5273913123709097537U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17756844173695563883U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6713055830729302951U;
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5106468334224035972U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10228769728713526172U;
            aOrbiterH = RotL64((aOrbiterH * 9760310686414358435U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7687649520668883142U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 7757480627354711605U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 7222553727737349209U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10876291698508634557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8149278085586014186U;
            aOrbiterB = RotL64((aOrbiterB * 8577133863470695381U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 15592893988925610485U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8639028256640537165U;
            aOrbiterJ = RotL64((aOrbiterJ * 1880655276432963955U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 475660347892196219U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1903736092401853832U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8486318978769094799U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12463250192809450953U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7253918448601703982U;
            aOrbiterI = RotL64((aOrbiterI * 3821034106528009129U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5171661020093804486U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 11627344933828324146U;
            aOrbiterD = RotL64((aOrbiterD * 5388047063152043277U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6206801139131132815U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9221302203943031377U;
            aOrbiterE = RotL64((aOrbiterE * 12912049016813367241U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1798857939965423979U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5476854168685641232U;
            aOrbiterK = RotL64((aOrbiterK * 3884216989250294213U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2816659151953455230U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15920462086654025436U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17843161654734820613U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 21U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 40U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterG);
            aWandererC = aWandererC + (((((RotL64(aScatter, 46U) + RotL64(aOrbiterI, 23U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aNonceWordI) + aWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterB, 38U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 50U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28351U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27791U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31009U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32255U)) & S_BLOCK1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 30456U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(pSnow[((S_BLOCK1 - aIndex + 31758U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31808U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCarry, 19U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 37U)) + 12535417189990029950U) + aNonceWordB;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 48U)) + 6204401443676390273U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 869613505613154672U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 11U)) + 15053590879563855802U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 19U)) + 13338989605204591428U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 18306470022403825392U;
            aOrbiterK = (aWandererF + RotL64(aCross, 3U)) + 1150696349434090218U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 41U)) + 13549541786420596437U;
            aOrbiterC = ((((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 14302878430259588461U) + aOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aWandererI + RotL64(aIngress, 30U)) + 4660437084477165225U;
            aOrbiterH = (aWandererE + RotL64(aCross, 35U)) + 1653628537860912069U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5594199757006711631U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11008472193138708891U;
            aOrbiterI = RotL64((aOrbiterI * 13645764762027798301U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3668516817279364310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 128159531749679984U;
            aOrbiterD = RotL64((aOrbiterD * 4523246859249826987U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6378674346113979108U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 11438762460659123362U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2733309638158283953U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10624263004446482910U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12546839706919241411U;
            aOrbiterE = RotL64((aOrbiterE * 11468326687628079347U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8466639576503293921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 5828694979857951504U;
            aOrbiterB = RotL64((aOrbiterB * 7835487310289634515U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16496305151014092976U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 589464613876410567U;
            aOrbiterG = RotL64((aOrbiterG * 13190816610718051897U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4168532743415647825U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15944887793736489375U;
            aOrbiterC = RotL64((aOrbiterC * 17273403561158196717U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11642456814106259483U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 1609897693632334867U;
            aOrbiterH = RotL64((aOrbiterH * 12912773555616819941U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 14950238412766325479U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11862438528287402255U;
            aOrbiterA = RotL64((aOrbiterA * 7635864312080265695U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 5900629306795222263U) + aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3221591991392500536U;
            aOrbiterF = RotL64((aOrbiterF * 7188525011266868855U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16938699391746264010U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 12535417189990029950U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 18212319484142613215U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 20U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 53U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + aNonceWordD) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 37U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 30U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterB, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + aNonceWordP);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterD, 21U)) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aScatter, 6U) + aOrbiterC) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterH, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 50U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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

void TwistExpander_FootBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC951AF7DF3596B0BULL + 0xE4BCCC98697EA5B0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA72D8DAA4CC44A77ULL + 0xD60BE9049ED9D412ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD755728BBC1AD28FULL + 0xF9F822C69B3CA1E0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEE97D91A37EEEBD7ULL + 0xB15623A8B2426C4AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x80399B14622683AFULL + 0xB2A90DFE93689E99ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x810C68AD64D59205ULL + 0xBA03428521D419F7ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x973F63D85D8101B1ULL + 0x85B55CBB78BA11C7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFEA67077584B0F4FULL + 0x9856893CC4A24F15ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB1FDE2B8800A4E99ULL + 0xF60A2B17538FE4A3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD7B7188AB57BE9D3ULL + 0x96481E7DEEFEE19FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF2FC06CEED3C2A5FULL + 0x9B5A2DC924CAAED4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x90007A0DAE632E69ULL + 0xA5956DA4C9E71CB0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE2E47EDDDEA0E39FULL + 0xF015BAC52EABF248ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB372D69549F0E19DULL + 0xC96653D975BFDBC1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAE47F47E333B7A4BULL + 0x955E8869B4633D1EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBE9E456BB5BDC9F5ULL + 0x9493B6FED8D4FFF1ULL);
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
            aIngress = RotL64(aExpandLaneA[((aIndex + 624U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2988U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 108U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1317U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 6U)) + (RotL64(aCarry, 43U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = ((aWandererH + RotL64(aCross, 6U)) + RotL64(aCarry, 5U)) + 1297415699043177788U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 47U)) + 17583786534509260153U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 643197858925708798U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 35U)) + 5062653766915694874U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 14U)) + 7034273638367180511U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aScatter, 41U)) + 2026909726972916996U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 27U)) + 2785690475553211646U) + aNonceWordD;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 2910341716302991892U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 19U)) + 2834181605200829791U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 13323052600571281928U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10434901530315760460U;
            aOrbiterB = RotL64((aOrbiterB * 2042210188346767033U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 247903955625194782U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 5196515747387257163U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1799024689023272275U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 7196305682377987476U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14777739876892587484U;
            aOrbiterK = RotL64((aOrbiterK * 95220583948241581U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10609060796540136671U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 8386027207212484155U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 4855610536246556893U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 729659744301903424U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2350564261412606157U;
            aOrbiterD = RotL64((aOrbiterD * 16713856782349084977U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16611987556673864177U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 1525195188708550503U;
            aOrbiterJ = RotL64((aOrbiterJ * 10045858602151004553U), 51U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 4654808490980989596U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8189569777087686263U;
            aOrbiterI = RotL64((aOrbiterI * 17278657566389299577U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10932857495004451792U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 1833880112534916813U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8004341577533825681U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13100236350175516423U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2773759534195186313U;
            aOrbiterC = RotL64((aOrbiterC * 3194954066097323161U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 18U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterH, 35U)) + aNonceWordH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterG, 39U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterK, 56U)) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8626U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 9610U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7694U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8666U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8010U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 14U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 3238389262925516513U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 60U)) + 12381787182611386995U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 3U)) + 7883885539305181549U) + aNonceWordK;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 23U)) + 1185413044597727092U) + aOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 19U)) + 15219353497204773135U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 42U)) + 7533774715626734082U) + aNonceWordO;
            aOrbiterH = ((aWandererD + RotL64(aCross, 27U)) + 2599930450937763464U) + aNonceWordP;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 16074720663961214284U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 15483613196360051221U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9396557867081376268U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9668459976852660245U;
            aOrbiterF = RotL64((aOrbiterF * 11748505665890567063U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9037269914643207212U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16936742640861088240U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 1040172193161012227U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16481274825758546398U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 481851372837611166U) ^ aNonceWordC;
            aOrbiterE = RotL64((aOrbiterE * 2225030139210599207U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 13608921517203544108U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16930740723286214636U;
            aOrbiterI = RotL64((aOrbiterI * 2605108503821980865U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 902242902582149908U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1510861213079342977U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3309753895727400707U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7116243600304980310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6631412278359709602U;
            aOrbiterH = RotL64((aOrbiterH * 11452627691392637463U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9246698682265275165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8594373032014031450U;
            aOrbiterG = RotL64((aOrbiterG * 2550138341089957033U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 15912837963877821048U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11404583513022627609U;
            aOrbiterK = RotL64((aOrbiterK * 17715204726760125357U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17295214920690244319U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 18315664494984189344U;
            aOrbiterD = RotL64((aOrbiterD * 17398893532076312945U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 50U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 24U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterF) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + aWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 24U) + aOrbiterE) + RotL64(aOrbiterI, 19U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + aNonceWordF);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 14U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 40U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 12772U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 14781U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12893U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 13860U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 14730U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 20U)) + (RotL64(aIngress, 37U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 12U)) + RotL64(aCarry, 39U)) + 17470880031634374199U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 27U)) + 757565846006937746U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 47U)) + 9419282475801345674U) + aNonceWordD;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 2014248014107898196U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 3U)) + 15113928519446490441U) + aNonceWordL;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 52U)) + 7346126964886259935U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 19U)) + 5594123113093162359U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 11U)) + 5659237263369402005U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 57U)) + 11565709683423969703U) + aNonceWordP;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16782863743534856287U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13499100900072115907U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5567729598873214433U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11414447651044205242U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7545993795121430538U;
            aOrbiterG = RotL64((aOrbiterG * 10758488381206257261U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11778229237616454988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2544793391976514665U;
            aOrbiterI = RotL64((aOrbiterI * 4021060413798523299U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9972156716619459164U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 17651030383827445664U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 6742914240706775487U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17439147296849134543U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10021926927948343656U) ^ aOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18139540407315440909U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9309867875882669289U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14951424455944346337U;
            aOrbiterJ = RotL64((aOrbiterJ * 10569523948169951309U), 35U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 2166343974068770659U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 11386993629011562026U;
            aOrbiterA = RotL64((aOrbiterA * 3091639433512536097U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5747849744680120960U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4019290369160113026U;
            aOrbiterC = RotL64((aOrbiterC * 5567515306039646735U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3820540009554769592U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8210747198363020939U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 16215133106542452509U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 14U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 13U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterE, 46U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterF, 41U)) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterE, 50U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20626U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 18851U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 19976U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20769U)) & S_BLOCK1], 52U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 19601U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 24U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 13U)) + 9435962834163239322U;
            aOrbiterH = (aWandererE + RotL64(aCross, 23U)) + 10524704356081318973U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 57U)) + 7403401305665208680U;
            aOrbiterC = (((aWandererH + RotL64(aScatter, 4U)) + 7525414805023556493U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 29U)) + 1116686470029070951U) + aNonceWordM;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 19U)) + 13257612299137802420U;
            aOrbiterB = ((((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 37U)) + 9181543003986598283U) + aOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererB + RotL64(aIngress, 51U)) + 9739384852307501107U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 42U)) + RotL64(aCarry, 11U)) + 11308402900229016057U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 14935167593705272337U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7171824007631943535U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 4839974427616194289U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8068411284829563567U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12350207458513447578U;
            aOrbiterJ = RotL64((aOrbiterJ * 813973258659041895U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 17039236343991574134U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18291683592714999632U;
            aOrbiterH = RotL64((aOrbiterH * 7771718817924840713U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6239616841884430968U) + aNonceWordH;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10604527977569876774U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 6972820410084939637U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1707724300671717658U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3802268808625297647U) ^ aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11296811630387191563U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 9423064323799920219U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 242153923313096551U;
            aOrbiterD = RotL64((aOrbiterD * 12117679073775630197U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 945801070951928277U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 13094814302414492064U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14638176479878969775U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7572219725951040117U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16494986983782503428U;
            aOrbiterB = RotL64((aOrbiterB * 2739189408707408171U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10949497978229234856U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11219643352002119905U;
            aOrbiterE = RotL64((aOrbiterE * 16900635614259262873U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 42U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 36U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 41U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 52U)) + aOrbiterH) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aNonceWordK);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aOperationLaneB[((aIndex + 24758U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 22489U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25586U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 24877U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 39U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterJ = (((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 15813325389431304548U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aPrevious, 35U)) + 2223874171125403602U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 56U)) + RotL64(aCarry, 35U)) + 5510483568496824130U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 15474152493495661876U) + aNonceWordH;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 19U)) + 16846339705130829195U) + aNonceWordG;
            aOrbiterG = (aWandererJ + RotL64(aCross, 39U)) + 1289670576865739669U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 51U)) + 18017354919647006944U) + aNonceWordJ;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 23U)) + 8539685539928984921U) + aNonceWordB;
            aOrbiterI = ((aWandererF + RotL64(aCross, 44U)) + 3333721400836704048U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2261560416623815491U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4377786131746816567U;
            aOrbiterH = RotL64((aOrbiterH * 9164777834392621157U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 18047393176583722719U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8184724021940434631U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9800116157750921119U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10469895939183324807U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14543391765109879223U;
            aOrbiterA = RotL64((aOrbiterA * 4817987697437667225U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5757225781746158178U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterB) ^ 3539000495894022869U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 1032298408884695925U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11288971092707065923U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2761384065186568294U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 3323838837427471051U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7120580145300417101U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6977246291769372866U;
            aOrbiterI = RotL64((aOrbiterI * 15170353875184253779U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17625434527765525937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3299714663631376190U;
            aOrbiterC = RotL64((aOrbiterC * 6532628892760776767U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10331889953489885250U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8550932256881727932U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13085531621192583719U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11151195711186126257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2552002192824926483U;
            aOrbiterF = RotL64((aOrbiterF * 9754056316698523849U), 11U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 10U);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterF) + aNonceWordC);
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterG, 43U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 58U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 5U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 5U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterG, 48U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 20U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aOperationLaneC[((aIndex + 29442U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31437U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27975U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28989U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterF = ((aWandererD + RotL64(aIngress, 58U)) + 3448371607470865612U) + aNonceWordC;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 11U)) + 3743742913651580573U;
            aOrbiterD = (aWandererB + RotL64(aCross, 37U)) + 13069491287948807280U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 5U)) + 16872779275586545632U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 17945792656755062795U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 54U)) + RotL64(aCarry, 19U)) + 18199747196793731853U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 43U)) + 15953311878379809513U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 27U)) + 941268763494588338U) + aNonceWordF;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 10090221530365796809U) + aOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8335698093307607001U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6147498804734306100U;
            aOrbiterD = RotL64((aOrbiterD * 6904444049941211327U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 5980246079567570090U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 4152167624425912978U;
            aOrbiterK = RotL64((aOrbiterK * 10019421651535123573U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14990418790239735916U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3418668387496597219U;
            aOrbiterJ = RotL64((aOrbiterJ * 12814077238529863119U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4206650904177199425U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3905470780938996069U;
            aOrbiterA = RotL64((aOrbiterA * 16030122739273137005U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9968672788233080924U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 602258075661864866U;
            aOrbiterB = RotL64((aOrbiterB * 2615726693066300065U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17751667243048041383U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 2414054413585296027U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1049512574773201893U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6523322402744047752U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 6729901917767398779U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8039939871405367139U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11460169185076814539U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7559640379553110573U;
            aOrbiterC = RotL64((aOrbiterC * 9864654321914036135U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 17271150091827475028U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3541809324556914646U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12655168871428868639U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 12U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 18U) + aOrbiterH) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 29U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aNonceWordA);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 36U)) + aOrbiterC) + aNonceWordK);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 6U) + aOrbiterK) + RotL64(aOrbiterE, 24U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererA, 50U);
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

void TwistExpander_FootBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x88B7E9EBDFE2E3C1ULL + 0xB403D1C6F30F2A7FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x93944E74AFA57DDFULL + 0x87D219D7580D4B1DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA4EA228BCDB37339ULL + 0xA7AC9F403D6331DEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCE56C40B3C992C57ULL + 0x91905DA45445067BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA3079519BDE70DADULL + 0x89C7C48B7C71C946ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x920E22CF011C04E1ULL + 0xE951232BCAA90E05ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBB1A7DA827259FF5ULL + 0x9250E1B60F8C1057ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDAC1835A4D7E299FULL + 0x9FA35977D7817946ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC0B667688C18ACF3ULL + 0xA6CD1B27ED7AFF3BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF0A16EC8C7E439A1ULL + 0xD96BB197FFCB8CF3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB6CFA8B40ECE9AD3ULL + 0xA386625A2ABF5413ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAF607DDD9DED9A21ULL + 0xC7D83AD194AE248AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF85693C6DDD51213ULL + 0xCA8F6659AE993F08ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC564AE1DE39CBE4BULL + 0x8D66F60F945B7082ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x93822AC5CA67BFE5ULL + 0x9D3E86FC9ABB01C0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8C4743984257E7ADULL + 0xD9EF03FF33C3B6DBULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 4420U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 7620U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3266U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3042U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7379U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7540U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 47U)) + 12980104182836602177U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 57U)) + 3172622203188863995U) + aNonceWordH;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 19U)) + 1170974132219980203U;
            aOrbiterA = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 6035201940965047490U) + aNonceWordD;
            aOrbiterE = ((((aWandererH + RotL64(aPrevious, 22U)) + RotL64(aCarry, 57U)) + 18033907118424996722U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14604813424800580304U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 13720232492851066035U;
            aOrbiterH = RotL64((aOrbiterH * 8927246214721284759U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3902659710585257448U) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8331560652661619868U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11418103770615560205U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4485014147538689794U) + aNonceWordB;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 168202636924512424U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 13711020666131492091U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16227825670092707848U) + aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4792781933944671365U;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12636865372722601282U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18198291399585556632U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18155803890313399795U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 4U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aNonceWordP);
            aWandererB = aWandererB + (((((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 53U)) + aNonceWordN) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 56U)) + aOrbiterA) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 27U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12565U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 12511U)) & S_BLOCK1], 42U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8358U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 12570U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10479U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10339U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15184U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = ((aWandererD + RotL64(aIngress, 41U)) + 2617613537256538553U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 23U)) + 16642868916835132715U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aWandererK + RotL64(aCross, 30U)) + 10860291124337073254U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 6432511273906902472U;
            aOrbiterF = (((aWandererG + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 7505375005848241910U) + aNonceWordM;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11086616004678821329U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3298830587569881951U;
            aOrbiterB = RotL64((aOrbiterB * 4304047944073454489U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 9775143140064220979U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4147601326580823120U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13462244678782260871U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12245920269898100415U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8391940489176734499U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 9119606167674098007U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 17876893379544668477U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 18301882058180370541U;
            aOrbiterF = RotL64((aOrbiterF * 16680384667098921309U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6869225862715140102U) + aNonceWordP;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 15404118372589259800U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5766851935950389915U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + aNonceWordD);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 53U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23293U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 24545U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 20760U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 23395U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20827U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23003U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 22237U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 21U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterH = ((((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 23U)) + 8866844335448071821U) + aOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 15159698739856430085U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 9582805772989594633U) + aNonceWordO;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 18U)) + 1438538239931588373U) + aNonceWordF;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 27U)) + 10862044156620436139U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13682173320058164615U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8351013291045977592U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5722336275651615473U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15777857431516633916U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16178966745333885377U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7545129923202147703U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9031889187993001617U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17118710301967158153U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 642109145903321046U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9186268569255318035U;
            aOrbiterA = RotL64((aOrbiterA * 10714674348507516749U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 6091345356803675860U) + aNonceWordM;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13218507921880873749U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 15415157927185637717U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aNonceWordN);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterG, 19U)) + aNonceWordK) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterH, 60U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 24645U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 25587U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 30875U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 29296U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27980U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31478U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 24831U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 4U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererK + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 12222235191147985484U) + aNonceWordF;
            aOrbiterI = ((((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 16367317014523328414U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 47U)) + 3511378091284703789U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 15247492830966725949U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 5U)) + 7745995913390407897U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 6463593307540108810U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 1101669311005268630U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 10550146460887359369U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12988052764067518580U) + aOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17717179747434679772U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10820310705487638793U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11662190906682400416U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6563014073547628748U;
            aOrbiterI = RotL64((aOrbiterI * 16967910471722117761U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 13099094932059419219U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16342730862261868847U;
            aOrbiterK = RotL64((aOrbiterK * 10988124108686164829U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16855346813127524624U) + aNonceWordO;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6570063128502306944U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 4571570049463124831U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + aNonceWordL) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 6U)) + RotL64(aCarry, 5U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((((RotL64(aCross, 54U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterK, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 20U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 3U);
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

void TwistExpander_FootBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE24BEF132275F663ULL + 0xFDA304142BDE4D18ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDE78E4D2ED74F2CBULL + 0xD13EC6EABF86A449ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xE66D9C86E63D593FULL + 0xB3DC110001D43524ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEF9439FE7324E4A7ULL + 0xF7F6F9EAC7BEEE6FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDA3328F8FC2F1A17ULL + 0x9A13E0EEF5D74650ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB4A28F1310DD5A57ULL + 0x926B8824375011FFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x8FFF8995D7A57557ULL + 0x881200FCBBB6A90EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9910CF6EF7292C91ULL + 0x8E4DAB1CFAAE0ADFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x89097FC7D8B7ADF1ULL + 0xE1FFA0B78569F74DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAA60E946EC7EDCF3ULL + 0xBDED75656DCF9BB7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8FC9E216F89085DFULL + 0xFADA2FC4282520C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC185C181813FFFFDULL + 0xF03BF6F3822EC99CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB7DA933E51A2A7BFULL + 0x9A01271F33207A58ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8F875BD72A164F75ULL + 0xC3A311266099D20DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC0464515C4BD38F1ULL + 0xE5D29423A166AB0CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDE35B73D1EAC1CF7ULL + 0x96072641E77F0D14ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7147U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 537U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 5923U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2092U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7165U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6622U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 10U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 12690502671561165478U) + aNonceWordG;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 5U)) + 17519943923428102801U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 10705515807975331385U;
            aOrbiterK = (((aWandererA + RotL64(aScatter, 19U)) + 16586447272278538179U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 27U)) + 8006560996840971798U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 58U)) + 12928600185788857701U) + aNonceWordE;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 14240723153798267172U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8636219177994872072U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 7586790235186467512U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 15052686382507614169U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1103807034179512424U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7547526530239498693U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 3360295583636013509U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8380239679344786397U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5690809173787433519U;
            aOrbiterC = RotL64((aOrbiterC * 5354724308093372953U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 8390902801141804609U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3507306189192059486U;
            aOrbiterH = RotL64((aOrbiterH * 18336280496510253103U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6190745292098482871U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8065418693975056902U;
            aOrbiterG = RotL64((aOrbiterG * 6414621418430102589U), 11U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 12111755051718111803U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 7605877769709909297U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 17525248694315944599U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5969794501112646237U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5127559299360591476U;
            aOrbiterF = RotL64((aOrbiterF * 4521563633438853069U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterC, 34U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aIngress, 46U) + RotL64(aOrbiterB, 41U)) + aOrbiterG) + aNonceWordK);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 11U)) + aNonceWordO);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 51U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 11743U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 9591U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9191U)) & S_BLOCK1], 4U) ^ RotL64(aFireLaneC[((aIndex + 14933U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 14290U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12751U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9952U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererC + RotL64(aIngress, 6U)) + 4773124477323378268U) + aNonceWordE;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 13U)) + 16848723289435796005U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 13846642134917107058U;
            aOrbiterI = (aWandererB + RotL64(aCross, 51U)) + 6472057872482789939U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 57U)) + 2747019500690707226U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 9003965289739733880U) + aNonceWordP;
            aOrbiterG = ((((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 3013390651936257377U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 3331004709895625067U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15355010435553517129U;
            aOrbiterJ = RotL64((aOrbiterJ * 8322759117004876831U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7709870658004280052U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13568728443963926564U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6736090830113688981U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12409548853419307131U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 969183352023661537U;
            aOrbiterG = RotL64((aOrbiterG * 5549220554838837145U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 15370309834426476775U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 3896803894396631184U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 11018830202891911603U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 10848873633291935766U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12885336509190543440U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1487357252619221365U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8252290890093788010U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9201553615601641350U;
            aOrbiterF = RotL64((aOrbiterF * 420321130559162915U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14014209645503188472U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4015071464301844550U;
            aOrbiterK = RotL64((aOrbiterK * 17444195018239904971U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 37U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 50U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 4U)) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterF, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterE, 11U)) + aOrbiterK) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 29U)) + aOrbiterK) + RotL64(aCarry, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 19130U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 20112U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 17041U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((aIndex + 17158U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17252U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 23030U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 23312U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererC + RotL64(aIngress, 51U)) + 16451272412693907816U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 10099485419723255462U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 5U)) + 17668900099534923192U) + aNonceWordP;
            aOrbiterK = ((aWandererK + RotL64(aCross, 13U)) + 5497093724143181753U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 20U)) + RotL64(aCarry, 39U)) + 10354044773550071706U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 57U)) + 12728258851198019099U) + aNonceWordN;
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 4144050505314242618U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14133805325480076530U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 308863673210602899U) ^ aNonceWordM;
            aOrbiterG = RotL64((aOrbiterG * 2672613556981540433U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11741180130160569753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12926863156769180448U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 9726030996091054939U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 211920854786494259U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13234608842479411078U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 2556747209733759467U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9164711974854618892U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6667377062281954219U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2603737166987437649U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4559040002406721850U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1749875480850675109U;
            aOrbiterE = RotL64((aOrbiterE * 15822640067349481089U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9555365165561936366U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 18289733999504213574U;
            aOrbiterB = RotL64((aOrbiterB * 14156217554673229429U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8727162691639622461U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 291406782452963706U;
            aOrbiterI = RotL64((aOrbiterI * 8413500075082350243U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 60U));
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + aOrbiterD) + RotL64(aOrbiterG, 21U));
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 60U)) + aOrbiterD) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 5U)) + aOrbiterI) + aNonceWordB) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29142U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 25761U)) & S_BLOCK1], 26U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 30031U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 25488U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31178U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24725U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 31961U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 13053031069776604052U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 1331396630251085122U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 35U)) + 15879286043343942393U) + aNonceWordC;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 27U)) + 13590365633321406830U) + aNonceWordN;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 11U)) + 14569235423040242618U) + aNonceWordJ;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 42U)) + 11397370636618371560U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 51U)) + 3455933494593971847U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1307153376443784593U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 10688618762584786871U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 9503823896874842411U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 17746248451153600096U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8512568600755410158U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 16648320170768234063U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8950230550112591092U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17790968369472845496U;
            aOrbiterC = RotL64((aOrbiterC * 5104988920132008913U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12583323865381967534U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 11243927099685293887U) ^ aOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12867003042486433971U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9690268715525781389U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7466066217365074653U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17565696765505320889U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 3673528673209875118U) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14079103852360952255U;
            aOrbiterB = RotL64((aOrbiterB * 17449228863409999629U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 6747836856132250630U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5027692924422297153U;
            aOrbiterH = RotL64((aOrbiterH * 2492421273167124437U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 37U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB) + aNonceWordF);
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 12U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterB, 47U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_FootBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD5528F3A1F2103F7ULL + 0xCBE77A88E337EB62ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA463D1EA236FD72BULL + 0xE94DA70CB8AF32E0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD7199AE9AA814EDBULL + 0xC85D19056721B093ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE03D338C5395FE15ULL + 0xA7B1BA29FC000E17ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDCDB9FB51EF82ECDULL + 0xA0A164A24886BE8CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC3D43735F9B1E093ULL + 0xC3420500F945DFA5ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x8514C666BFAF7DADULL + 0xF444DBFEA292755DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC5253FBF31992C03ULL + 0xFC66A6D862453521ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE1DE134D5EECF781ULL + 0xE242E59224A05351ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xFE1A0D43C95B03C9ULL + 0xE257E9CC3CA5E3A4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA5EC78715EDF7CDDULL + 0xB2B2C4E0297AE059ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8EFDC2128A3B6471ULL + 0x8373049A3140ADE5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xECCCB396F58CF609ULL + 0xF84FED7E30F1D096ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xAED0ADE21E16B281ULL + 0xAC36BF359561B9EAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x89CC3BDEC3B377ADULL + 0xE2D5D6C645303817ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8D50F07167ADC4C7ULL + 0xF521FEF40180CFBCULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 3417U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 1229U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5059U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5302U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneD[((aIndex + 1161U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 44U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = (aWandererK + RotL64(aIngress, 5U)) + 15045917390223766480U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 39U)) + 10763054007033668758U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 29U)) + 13190170142593666607U;
            aOrbiterC = ((((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 9657025731441167065U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 54U)) + RotL64(aCarry, 5U)) + 11433367178975954211U) + aNonceWordA;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 13U)) + 17904920143996810366U) + aNonceWordF;
            aOrbiterA = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 3244383020512113283U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6538815775171139091U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7195368312757976343U;
            aOrbiterG = RotL64((aOrbiterG * 10515679176134176565U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 18134430713910279374U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 6571776588427107976U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11916502085252589161U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterG) + 11830778129647517758U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 9793702760907767365U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4096246227968677179U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 2287235876793192036U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8951959188326141794U;
            aOrbiterJ = RotL64((aOrbiterJ * 9968356718110753845U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7583061790273240157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3571364625022806085U;
            aOrbiterC = RotL64((aOrbiterC * 6238360922735480669U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13869345563551689212U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 277480328952975002U;
            aOrbiterD = RotL64((aOrbiterD * 1057564597096163085U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4983735092494677578U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9490022869381030928U;
            aOrbiterA = RotL64((aOrbiterA * 12926352917961703123U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 41U)) + aOrbiterA) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 4U) + aOrbiterI) + RotL64(aOrbiterH, 12U));
            aWandererG = aWandererG + (((((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 35U)) + aNonceWordB) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterA, 27U));
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 40U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9166U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 8019U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8961U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5886U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6005U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 6497U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCarry, 20U) ^ RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (aWandererD + RotL64(aIngress, 19U)) + 12690502671561165478U;
            aOrbiterH = ((((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 17519943923428102801U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterG = (aWandererH + RotL64(aCross, 41U)) + 10705515807975331385U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 16586447272278538179U) + aNonceWordF;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 58U)) + 8006560996840971798U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 12928600185788857701U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 29U)) + 14240723153798267172U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8636219177994872072U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 7586790235186467512U) ^ aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 15052686382507614169U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 1103807034179512424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7547526530239498693U;
            aOrbiterD = RotL64((aOrbiterD * 3360295583636013509U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8380239679344786397U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5690809173787433519U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 5354724308093372953U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8390902801141804609U) + aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3507306189192059486U;
            aOrbiterK = RotL64((aOrbiterK * 18336280496510253103U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6190745292098482871U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8065418693975056902U;
            aOrbiterA = RotL64((aOrbiterA * 6414621418430102589U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12111755051718111803U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7605877769709909297U;
            aOrbiterC = RotL64((aOrbiterC * 17525248694315944599U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5969794501112646237U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5127559299360591476U;
            aOrbiterJ = RotL64((aOrbiterJ * 4521563633438853069U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterH, 28U)) + aOrbiterJ) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 3U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + RotL64(aWandererE, 12U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 15434U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 15099U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14870U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15098U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13919U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 22U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 13854738573712660276U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 27U)) + 16835460633412286294U) + aNonceWordN;
            aOrbiterI = (aWandererH + RotL64(aScatter, 19U)) + 6785859293758091931U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 126317283127992659U) + aNonceWordE;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 57U)) + 7568963536291415413U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 13U)) + 12294016745653004819U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aCross, 35U)) + 18269588932920281147U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5872406424994751026U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 7764434758831474129U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3772146788188420071U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4804168969415573371U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 959601763507651280U;
            aOrbiterK = RotL64((aOrbiterK * 4647396592804833217U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9257644462479293048U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 14332699366894494579U;
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10487012596470786004U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 612729229562321440U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 11380387280507726003U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7845523921295625315U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12742115479740024747U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10294667720904610944U) + aNonceWordB;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14369711143154904567U) ^ aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13753005602288309379U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10918344717497681894U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18136794828308636957U;
            aOrbiterD = RotL64((aOrbiterD * 17899418637978002409U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 36U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aNonceWordO);
            aWandererB = aWandererB + ((((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterI, 52U)) + aNonceWordL);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 29U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            aWandererK = aWandererK + (((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 13U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 5U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16385U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 18508U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21621U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20828U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 18956U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aIngress, 5U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 11U)) + 12583180859826261500U) + aNonceWordD;
            aOrbiterC = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 9067093488553721468U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 12173106198862881754U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 11333491014394592654U;
            aOrbiterK = (aWandererH + RotL64(aCross, 58U)) + 3511883526940919554U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 3U)) + 7416810692106273044U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 35U)) + 8341174972619784110U) + aNonceWordN;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 2220852854836962979U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8090781422229383825U;
            aOrbiterE = RotL64((aOrbiterE * 578293950675644397U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 2338801236599102223U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12484514711848308104U;
            aOrbiterB = RotL64((aOrbiterB * 10364216764253366067U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13684861340589131816U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 12796636819991873058U) ^ aOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5533508014234835669U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 7634198650894837690U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10240326122201201762U;
            aOrbiterC = RotL64((aOrbiterC * 8758703497719125901U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4162814763739453934U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2766504649149048469U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16731843453895178671U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 11051393030148769655U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17687055068651386665U;
            aOrbiterH = RotL64((aOrbiterH * 1042927176246229537U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3353615315436983420U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5971640796220306310U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15804313508835034807U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 4U)) + aOrbiterA) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 51U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterG) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + RotL64(aWandererF, 4U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aExpandLaneB[((aIndex + 26999U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26183U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24079U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((aIndex + 24096U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 6U)) + (RotL64(aCross, 43U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 8866844335448071821U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererG + RotL64(aCross, 50U)) + 15159698739856430085U) + aNonceWordE;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 57U)) + 9582805772989594633U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererI + RotL64(aIngress, 23U)) + 1438538239931588373U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 10862044156620436139U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 37U)) + 13682173320058164615U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 29U)) + 8351013291045977592U) + aNonceWordH;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15777857431516633916U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 16178966745333885377U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7545129923202147703U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 9031889187993001617U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6308472367425865347U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17118710301967158153U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 642109145903321046U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9186268569255318035U;
            aOrbiterA = RotL64((aOrbiterA * 10714674348507516749U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6091345356803675860U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 13218507921880873749U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15415157927185637717U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 4266652275234474616U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4391422098164506195U;
            aOrbiterD = RotL64((aOrbiterD * 17634679403195085867U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5160682323243635577U) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10351728852161347404U;
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3950932176454814023U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9536466386833427441U;
            aOrbiterF = RotL64((aOrbiterF * 18064984243491293435U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 43U)) + aOrbiterJ) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterJ, 51U)) + aNonceWordA);
            aWandererE = aWandererE + ((((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 28U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32179U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 31411U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32659U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((aIndex + 30804U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 44U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 8375305456876489425U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 29U)) + 16193562952772453047U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 5U)) + 18088652458594816223U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 47U)) + 767344788620249944U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 7705194930396368752U) + aNonceWordB;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 3829736891311272834U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 14U)) + 9881681671347640061U) + aNonceWordA;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1721196560190164264U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3002652618388454213U;
            aOrbiterE = RotL64((aOrbiterE * 15289749311593032657U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 9811621464004005202U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (((aOrbiterI ^ aOrbiterF) ^ 5652598941069986530U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterI = RotL64((aOrbiterI * 4797973356708091621U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6250499348327316328U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16025054277615264530U;
            aOrbiterH = RotL64((aOrbiterH * 16446892258704281903U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13800298546867243172U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12256104592865905782U;
            aOrbiterD = RotL64((aOrbiterD * 16983140179497142713U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17817225416918329229U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 17738671327352776217U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 393488251327705063U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6816031224188400541U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16989563985059237014U;
            aOrbiterF = RotL64((aOrbiterF * 8677884225771717797U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16891524847268207549U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1833508573940405571U;
            aOrbiterG = RotL64((aOrbiterG * 9709196587703979539U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 21U)) + aOrbiterE) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterI) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 56U)) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_FootBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF75C8642A6FC9E63ULL + 0xAC0E718F2937563BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF908D7FA043630D5ULL + 0xF9E613D83DE77621ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB220C4941A0B4705ULL + 0xC2560C2394329B9AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA48B107397F5E60DULL + 0x826281095E6394DFULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8D57104F495239A7ULL + 0xC564F1E665473F5CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE4CDD1E119BEDFC3ULL + 0xEB4D5AD67D78F6E3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDB53FB5E416094A1ULL + 0xBB89273C8718E935ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC77DCC6ED7A5F93FULL + 0xD590A9D62FD4E83FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xB8725D01923C7FE3ULL + 0xB21E21332DF9D141ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAC6A54F275397C2FULL + 0x8203139023F412F8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF9C7EE816640BA3FULL + 0xDED3F2655DEB76E7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x88F3B29044E644C7ULL + 0xFEABED7C9D5DE07CULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF8A12101225DC8B1ULL + 0xFC3C6782C83CF0EBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC6B994909953EDF1ULL + 0xFB2DEB99667CFAC6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFEB28A31831DC1E1ULL + 0xED3B1EC4C9851828ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA49AD03054B5B83DULL + 0xBA3F2929C1C11CAAULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7129U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneB[((aIndex + 2331U)) & S_BLOCK1], 12U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 1847U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7970U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3483U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6587U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 50U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterB = (aWandererI + RotL64(aIngress, 20U)) + 4476099022490972343U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 47U)) + 16836423700375760429U;
            aOrbiterI = (aWandererH + RotL64(aCross, 27U)) + 8850577488928703557U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 39U)) + 7091631824560042743U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 57U)) + 12560498899956759494U;
            aOrbiterG = ((aWandererF + RotL64(aCross, 10U)) + RotL64(aCarry, 13U)) + 7797973377112012161U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 5U)) + 6173820673874805794U) + aNonceWordO;
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 10805025132310245348U;
            aOrbiterA = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 7139216143268029968U) + aNonceWordI;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 53U)) + 8241544862261635722U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 35U)) + 4735527016563596150U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5166171126690294033U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11117641762075368393U;
            aOrbiterI = RotL64((aOrbiterI * 4980156869201219393U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6312932356458415421U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1304139291184508668U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 90744653170922319U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10085025354842771067U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16745854428789531080U;
            aOrbiterD = RotL64((aOrbiterD * 1945983905747274355U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2497187958708890337U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 16069701876646548995U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16606039730973709495U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 17242004368025978091U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12334315722243232121U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 16528598396696346719U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 8007042082518126895U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5665686359038811484U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11289316305875751813U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3913477186958600592U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16918984318564170343U;
            aOrbiterE = RotL64((aOrbiterE * 5128293326494417281U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10227611546502931418U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 7187623463085447228U;
            aOrbiterA = RotL64((aOrbiterA * 8479839369622163181U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16655159122037336519U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9844145011519243346U;
            aOrbiterH = RotL64((aOrbiterH * 16512883184116277583U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8660130685326542506U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16192687259641294851U;
            aOrbiterK = RotL64((aOrbiterK * 2882649237163668499U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15208432734447317310U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4476099022490972343U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 7447168142776253041U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterB, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 30U)) + aOrbiterI) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 47U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 40U) + RotL64(aOrbiterE, 41U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterC, 27U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterK, 39U)) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterH, 13U)) + aOrbiterK);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 60U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordD) + aWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 50U) + aOrbiterK) + RotL64(aOrbiterD, 53U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + RotL64(aWandererC, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11318U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((aIndex + 13237U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9683U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneC[((aIndex + 15795U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13172U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12496U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14698U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = ((((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 23U)) + 9654059367478508868U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aWandererK + RotL64(aIngress, 60U)) + 6473006635864677427U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 19U)) + 6944184481315853243U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 4061496421939102306U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererE + RotL64(aCross, 35U)) + 15791809275719085463U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 26U)) + 14050798802646323055U) + aNonceWordB;
            aOrbiterK = (aWandererI + RotL64(aIngress, 13U)) + 12072905924741758266U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 41U)) + 17639076509231343896U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 21U)) + 12195388285571234715U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 37U)) + 4325404419499496529U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 29U)) + 5910567888204238382U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13092940059929942699U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13381962590820308761U;
            aOrbiterF = RotL64((aOrbiterF * 6345904465930943295U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 15622862439323440527U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14027151901132249793U;
            aOrbiterC = RotL64((aOrbiterC * 2273573821630510087U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4584410023907605157U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15763755180625487157U;
            aOrbiterD = RotL64((aOrbiterD * 6755736130607297639U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17023059745666559199U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5298529579288492971U;
            aOrbiterK = RotL64((aOrbiterK * 2483562793328357721U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 2870152867331654736U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 12017191100173748848U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9958191466506480519U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15899529176182436062U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16482713846343388735U;
            aOrbiterB = RotL64((aOrbiterB * 719465695044265601U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 12943393531812774449U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9881108254540483225U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 8011108108007885059U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3532054586199716750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7142230313294797435U;
            aOrbiterH = RotL64((aOrbiterH * 14154176174768868421U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 733958394016131587U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2060800099014517137U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12988885554457108631U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2278498033811574812U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15342071118593803929U;
            aOrbiterG = RotL64((aOrbiterG * 7842196613533603835U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12987212219357101955U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9654059367478508868U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11796100167917742307U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 22U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 41U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 22U) + aOrbiterC) + RotL64(aOrbiterK, 19U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterK, 56U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 12U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 21430U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneA[((aIndex + 22488U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 18256U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20249U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22613U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22839U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22969U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 26U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = (aWandererH + RotL64(aCross, 57U)) + 8375305456876489425U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 41U)) + 16193562952772453047U) + aNonceWordH;
            aOrbiterA = (aWandererA + RotL64(aIngress, 51U)) + 18088652458594816223U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 767344788620249944U;
            aOrbiterG = (aWandererF + RotL64(aCross, 26U)) + 7705194930396368752U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 53U)) + 3829736891311272834U) + aOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1]) + aNonceWordD;
            aOrbiterF = ((((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 9881681671347640061U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = (aWandererB + RotL64(aScatter, 29U)) + 1721196560190164264U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 20U)) + 3002652618388454213U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 9811621464004005202U) + aNonceWordG;
            aOrbiterC = (aWandererD + RotL64(aIngress, 5U)) + 5652598941069986530U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 6250499348327316328U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16025054277615264530U;
            aOrbiterA = RotL64((aOrbiterA * 16446892258704281903U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13800298546867243172U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 12256104592865905782U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 16983140179497142713U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17817225416918329229U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17738671327352776217U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 393488251327705063U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6816031224188400541U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16989563985059237014U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8677884225771717797U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16891524847268207549U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1833508573940405571U;
            aOrbiterC = RotL64((aOrbiterC * 9709196587703979539U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12729999421507068973U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6839758643521968957U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16350557395881283975U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8524167125469267428U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 14741523560290472617U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 4367850822282205897U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 10983798459868424892U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5649250846622078964U;
            aOrbiterB = RotL64((aOrbiterB * 7149612714806023987U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8587302028325090061U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17457129226030333666U;
            aOrbiterI = RotL64((aOrbiterI * 18107356450566915215U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15600113588474915690U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6595247491374683783U;
            aOrbiterE = RotL64((aOrbiterE * 1432432381540098765U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13246325856585534283U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8375305456876489425U;
            aOrbiterF = RotL64((aOrbiterF * 8331406038795786099U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 51U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 56U)) + aOrbiterE) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aNonceWordA);
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterI, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterI, 34U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aCross, 41U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28497U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 31104U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 32728U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31621U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27366U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25051U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27757U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 6U)) + (RotL64(aPrevious, 35U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = ((aWandererK + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 11177787645248006236U;
            aOrbiterG = (aWandererC + RotL64(aCross, 11U)) + 3808340254579817169U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 39U)) + 828030667598518279U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 37U)) + 16177835921238398371U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aScatter, 47U)) + 5518747735458708741U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 60U)) + 17346319082399995165U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 6397156921893030937U) + aNonceWordN;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 15559381654710713582U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 57U)) + 940404446491415088U;
            aOrbiterF = (aWandererI + RotL64(aCross, 52U)) + 8047166032048732645U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 43U)) + 4688468645859470491U) + aNonceWordD;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3710878044770337260U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 116343189456629220U;
            aOrbiterD = RotL64((aOrbiterD * 5637725064169289339U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 883908030159391659U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18058691521694880482U;
            aOrbiterC = RotL64((aOrbiterC * 3132200449123497619U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17521015077103586117U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3668332225435714918U;
            aOrbiterE = RotL64((aOrbiterE * 12658899101297839881U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12229480388278883300U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16206524049491531816U;
            aOrbiterJ = RotL64((aOrbiterJ * 11122340196620859805U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5743265849441077466U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2812293020719282236U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8903956475200417109U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13718364781538837074U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 861529717259766236U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 17019744777211266685U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4862687502126693872U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7722024283321020761U;
            aOrbiterG = RotL64((aOrbiterG * 18086944039541060829U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8205803118233399853U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15130160926615050422U;
            aOrbiterI = RotL64((aOrbiterI * 1454552751453996765U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 667469191899263617U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 18048970185163843471U;
            aOrbiterK = RotL64((aOrbiterK * 1800698970568737425U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 508102841337488721U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 3803840516662727630U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8477778555284121637U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17055028117762299436U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11177787645248006236U;
            aOrbiterF = RotL64((aOrbiterF * 12457019014051206805U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 43U)) + aNonceWordB);
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 27U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 50U) + aOrbiterI) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 53U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 12U)) + aOrbiterH) + aNonceWordA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterI, 10U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 54U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 56U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_FootBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCB4272AAEFF47983ULL + 0xBFFF117DA7CC3C69ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8EA3C719196805A3ULL + 0xA05C3A3691413CBBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAD43EAA2462C7C9FULL + 0xEF2A70989C09881DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB46833848386ADF1ULL + 0xD9F72976B13A5BB7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9BDBD806DCAB3F9BULL + 0xA24314D70B038E79ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC525D5E84CCEFFF3ULL + 0xD0FCB2361330DE76ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF542C3756D774FE5ULL + 0x908C20A388957CD7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9FB06A7207D6B9EFULL + 0xE675FC2552479869ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC2766768835B7A01ULL + 0xBDD7D0DB19BDB3A5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB344B9601449B62BULL + 0xF27E784B133AE319ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xB436E631B28B969BULL + 0x9161D251B4691A05ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAFD660B03921471DULL + 0xAAFEAB28F5AA2180ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x82F51D7DF22EAAF7ULL + 0x9A766E906F174E6FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCD284FFC3C96481FULL + 0xFF360644A7C23097ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFFE8748176139CBBULL + 0xBE8E1DD34AF8A01BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBCA08220400623CFULL + 0xF0399234656E7FF3ULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1883U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 671U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7981U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6920U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 675U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4404U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 47U)) + (RotL64(aPrevious, 4U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = (aWandererF + RotL64(aCross, 14U)) + 252059974543142812U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 11690823093681457368U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 13282189752890971123U;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 9507416294305708435U) + aNonceWordI;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 51U)) + 14053038174390776539U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + 14605253312318725009U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 57U)) + 18138286582677863671U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 28U)) + 8530091235978489988U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 14381731677571170073U) + aNonceWordM;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13316413456378978456U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3910529530149320706U;
            aOrbiterK = RotL64((aOrbiterK * 16000139333493588429U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 6302070286831566901U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12324134652758551396U;
            aOrbiterB = RotL64((aOrbiterB * 17136438281540250165U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4773478557638475048U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4031153435446078944U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3876928995240982769U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3114794895962903899U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3552936509969106796U;
            aOrbiterD = RotL64((aOrbiterD * 16823186892738820299U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5828754613946145627U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17985241114076114558U;
            aOrbiterA = RotL64((aOrbiterA * 1986669631395606833U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11319331046368072261U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 6104267020171882160U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12525117969211576177U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7662668379725735125U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6583034411403600735U;
            aOrbiterC = RotL64((aOrbiterC * 262095656452193889U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5569865728026310280U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4176065898330374039U;
            aOrbiterI = RotL64((aOrbiterI * 11305749530796963967U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13677146592276526676U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2734371113158117596U;
            aOrbiterJ = RotL64((aOrbiterJ * 13146444882662731975U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 24U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 12U)) + aOrbiterI) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + aNonceWordK);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + aNonceWordH);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 18U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordG) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterE, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14124U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneC[((aIndex + 14522U)) & S_BLOCK1], 12U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 11414U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 13083U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12292U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11139U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10326U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 12U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 51U)) + 16922357079016918108U) + aNonceWordO;
            aOrbiterB = (aWandererF + RotL64(aIngress, 30U)) + 11771749797137599131U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 57U)) + 4635668433708036077U;
            aOrbiterI = (aWandererB + RotL64(aCross, 47U)) + 15827952719230577008U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 57U)) + 1495675306110023086U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + 7294835466949728365U) + aNonceWordC;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 37U)) + 179122461212041978U) + aNonceWordL;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 12U)) + RotL64(aCarry, 35U)) + 545981421632236251U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = ((((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 15338259639814630535U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12924313840290895215U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17846785921286020610U;
            aOrbiterD = RotL64((aOrbiterD * 18309347016029917133U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5721472794107057875U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16359630793856870319U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14186771515526698907U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10614102110239037308U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 16421992251278236531U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 2561232904676068089U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8668149834861244963U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12699331834360948734U;
            aOrbiterF = RotL64((aOrbiterF * 2249360824172616357U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4470693178142950471U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 526000656022724741U;
            aOrbiterA = RotL64((aOrbiterA * 16688501462334673493U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6880246132270094141U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 7126466778855297013U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 5692237926830293205U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6436404501390442054U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1213633065612242699U;
            aOrbiterC = RotL64((aOrbiterC * 17604454985534439259U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8186529105901185854U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10607460957358250935U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17172191011625677861U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9743278964993305169U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14007577681873418075U;
            aOrbiterG = RotL64((aOrbiterG * 4231122580398039133U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 38U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 5U)) + aOrbiterI) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterC, 56U));
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterD, 29U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 60U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 18U) + aOrbiterE) + RotL64(aOrbiterF, 43U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererK, 12U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23118U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 16915U)) & S_BLOCK1], 56U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 22420U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18173U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19366U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 23447U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17459U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 12U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 34U)) + 7790166497945719700U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 43U)) + 7136208896846119188U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 21U)) + 12123156943355100886U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 57U)) + 5095546037880875199U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 5U)) + 17642705393916765992U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 9918479837334416990U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 4890009823843176466U) + aNonceWordI;
            aOrbiterK = ((aWandererA + RotL64(aCross, 53U)) + 17652590786213674124U) + aNonceWordA;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 26U)) + 870002527644696135U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12545429703552643682U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5310272867406182581U;
            aOrbiterB = RotL64((aOrbiterB * 10420003334833925011U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3264719049050179440U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 1967241238180278937U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13004319774269457957U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 773883832927040736U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12766817190261232485U;
            aOrbiterC = RotL64((aOrbiterC * 7448864556802318431U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 260069382395598265U) + aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 15462103891287350123U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5029268763635635753U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4072032867513289827U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17153061419083897076U;
            aOrbiterF = RotL64((aOrbiterF * 11934532169271718913U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6207264270332656966U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18048064697837314947U;
            aOrbiterE = RotL64((aOrbiterE * 13632594619404208489U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14484617445340272026U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16160443600497652026U;
            aOrbiterA = RotL64((aOrbiterA * 1988599349457831597U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5873314228291583482U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16418290052752166515U;
            aOrbiterG = RotL64((aOrbiterG * 18270363452003213317U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9158414409987627714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 8205937960146492168U;
            aOrbiterK = RotL64((aOrbiterK * 14008398661393344261U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 38U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 34U)) + aOrbiterD) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 48U) + RotL64(aOrbiterK, 13U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterA, 39U)) + aNonceWordB);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 37U)) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterF, 6U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererD, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25347U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 27399U)) & S_BLOCK1], 37U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 26696U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29383U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28181U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 25728U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 25691U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 11U) + RotL64(aCross, 48U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterH = (aWandererC + RotL64(aScatter, 24U)) + 6916817163240024692U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 14554930751292077817U;
            aOrbiterD = (((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 1098305064484336101U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 47U)) + 12192821172420471527U) + aNonceWordM;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 57U)) + 2435134991707318845U) + aNonceWordN;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 18U)) + 1896745368738512624U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 51U)) + 1114996424222923873U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 13U)) + 9839135798371512656U) + aNonceWordD;
            aOrbiterG = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 8037967239603177043U) + aNonceWordB;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 15185468738487237432U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 4912098316394854543U;
            aOrbiterD = RotL64((aOrbiterD * 3072785550384399929U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13142688607850380888U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4507379759608945839U;
            aOrbiterK = RotL64((aOrbiterK * 2989332387754215967U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7299006009652289342U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 5390655277207053627U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10973744708856143715U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6744737023577785725U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 15539737698867067285U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 4686092035261336911U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13329866734681377952U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13284937458969166257U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 3965985432462699445U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8695002088915702168U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3858059421620839286U) ^ aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9559783727301092937U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 6609163873243179836U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9416165620556710540U;
            aOrbiterA = RotL64((aOrbiterA * 240385043740268229U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1578449067529000433U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14309000104419489303U;
            aOrbiterJ = RotL64((aOrbiterJ * 7599078306153684729U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15785180680737461320U) + aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 10099222679918382021U;
            aOrbiterC = RotL64((aOrbiterC * 2012232597046182581U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterD, 11U)) + aOrbiterH) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 60U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterA, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 53U)) + aOrbiterA) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 34U) + aOrbiterK) + RotL64(aOrbiterB, 34U));
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_FootBall_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDAA642A841D3FB4DULL + 0xF7812F2E92312665ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x83594C9B4FFB043BULL + 0xD2F7C1D6DD5260A3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC3022F742F89AF7DULL + 0xCF1C0F8EB39D7FEFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA7C043889A82B7B9ULL + 0x995D56C456204C04ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBA04A5A341F8EEB9ULL + 0x879BF04A41ED2D6AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x983AECE2513E38C9ULL + 0xAE1067991E3A7D20ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB4395E8D9E8FD213ULL + 0xDDC6D7AA5846B209ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE2322777C5E5DB69ULL + 0xE92B54D8A53A6556ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8FFE870479F4AC4DULL + 0x9020137558EAC4A1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8B6F3607C8C22037ULL + 0xA2CC90F117573C73ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC1E841EC3013F183ULL + 0x9354C7D7226B8673ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x891C815DACF00737ULL + 0xA2A21DEDD9C944BBULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDE5211A06E2BD3C5ULL + 0xC35BDC83FD9D9428ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF9DB2B0672C0FAF9ULL + 0xCCC6C76B4E467980ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xCAD0E984A0DD38DDULL + 0xD4FEE4C82D06A445ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD81256C4A50BE67DULL + 0xDD8857FAC27521D4ULL);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 7796U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneB[((aIndex + 2271U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 475U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6915U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6099U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4989U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 53U) + RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = (((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 1364174714924216027U) + aNonceWordK;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 51U)) + 13561796874229506613U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 13U)) + 11845572344206238305U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 15762708240326773763U) + aNonceWordH;
            aOrbiterG = ((((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 1157119665207900473U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 43U)) + 6823546624372055260U) + aNonceWordP;
            aOrbiterH = ((aWandererA + RotL64(aCross, 27U)) + 14465564210523945121U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10667464548080807531U) + aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13445737493224316575U;
            aOrbiterI = RotL64((aOrbiterI * 12137295000900795711U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3009837893785957665U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2886920524111083752U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15308180928967762543U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10886177449328249656U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15067759884678100433U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 5724566815989860041U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18307930462682331536U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8791864377579255801U;
            aOrbiterJ = RotL64((aOrbiterJ * 9265158882471421767U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 805797468642992351U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5743305867058244964U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16263000753351131717U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17102025528234481273U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1841579177327486899U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 3841603385577825265U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2189493507896508972U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18209567010094914374U;
            aOrbiterF = RotL64((aOrbiterF * 3737080408976852351U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterI, 18U)) + aNonceWordI) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterB, 27U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 6U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 14416U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 16380U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 12975U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 13010U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10468U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11073U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 10811U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 57U)) + (RotL64(aIngress, 18U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 27U)) + 14008824488073394623U) + aNonceWordP;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 13317978415866411468U) + aNonceWordI;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 57U)) + 13209180141897453900U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 11870521586865233578U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 50U)) + RotL64(aCarry, 37U)) + 8052156380448047385U) + aNonceWordF;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 35U)) + 12158131176743680605U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 19U)) + 14674467487607719347U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterA) + 18055496790566231147U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 3838105585041578784U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 1075709247574580091U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2839568255183054418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11933612922864258179U;
            aOrbiterJ = RotL64((aOrbiterJ * 7571964469321160347U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6289849094151630580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2640344350528492271U;
            aOrbiterK = RotL64((aOrbiterK * 16197726750829369365U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16306175266267657791U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3339898380394883600U;
            aOrbiterE = RotL64((aOrbiterE * 7105436590182982373U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15017076663742800002U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 8973064296077602496U;
            aOrbiterA = RotL64((aOrbiterA * 9309462227233615761U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17580319233338139859U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14063208878807603874U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16601475239075164585U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13326130855721009942U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12843186026737544416U;
            aOrbiterC = RotL64((aOrbiterC * 4975848122837321619U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 12U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterC, 29U));
            aWandererI = aWandererI + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterA, 10U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 51U)) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aCross, 30U) + aOrbiterK) + RotL64(aOrbiterC, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 23U)) + aNonceWordA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20032U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 19770U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aWorkLaneB[((aIndex + 17737U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22103U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19289U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16757U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 24262U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCross, 19U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterA = (aWandererK + RotL64(aScatter, 47U)) + 15726877954695761686U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 14187652171881943587U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 26U)) + RotL64(aCarry, 11U)) + 8420423151313882782U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 39U)) + 14942322692433259283U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterK = ((aWandererF + RotL64(aCross, 19U)) + 7272331475919796255U) + aNonceWordG;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 154504365041805840U) + aNonceWordJ;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 11U)) + 17475491222554948786U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5759181483165339605U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5993060214499322845U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10799489831896153301U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10901786237875941844U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17135786595614068473U;
            aOrbiterG = RotL64((aOrbiterG * 15923538730142047043U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5208202073886811165U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6821452921018900631U;
            aOrbiterA = RotL64((aOrbiterA * 13119330055184115669U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 13348064837402206969U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8967943922403445136U;
            aOrbiterI = RotL64((aOrbiterI * 300168481725373093U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 8130283784171430891U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 6351113882502502876U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 15960622823993072903U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6894708729226455769U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12065058511247133944U;
            aOrbiterB = RotL64((aOrbiterB * 5432601727436935831U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17138279326229372741U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 12987698199066890628U;
            aOrbiterK = RotL64((aOrbiterK * 12665716655177320977U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 23U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 39U)) + aNonceWordM);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterA, 3U)) + aWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 10U)) + aOrbiterA) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aCross, 30U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30576U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 31743U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 27150U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 32158U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30064U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24590U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32551U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 4U) ^ RotL64(aCross, 19U)) + (RotL64(aCarry, 51U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 29U)) + 966899917801652720U) + aNonceWordM;
            aOrbiterC = ((((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 10996327672320748649U) + aOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 3U)) + 4188171566846621107U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 20U)) + RotL64(aCarry, 43U)) + 5886209243097387959U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 14940428957136728111U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 57U)) + 179187285531914832U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 41U)) + 6685351948936817752U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1894506461704029700U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4182760368636977082U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 972988091869133921U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12523318028514940790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5059306166973366892U;
            aOrbiterC = RotL64((aOrbiterC * 2857409765717296483U), 51U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 5890872367917643851U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17747338389865221534U;
            aOrbiterB = RotL64((aOrbiterB * 5306740664798049267U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13906227834259884100U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7152105382899756368U;
            aOrbiterH = RotL64((aOrbiterH * 6772157117358310485U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17868101884759619240U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11758843266314148347U;
            aOrbiterE = RotL64((aOrbiterE * 5919135169337501485U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13950566197090324859U) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17278105609930477854U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 11431842718945107359U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9556785965646738355U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 841298436857932987U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15077843186688841797U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 29U)) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 53U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 50U) + aOrbiterH) + RotL64(aOrbiterC, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_FootBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseEWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseESalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseHWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mWandererUpdate.mSaltC;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE80BD0FBFB3C4573ULL + 0xD3832CF5CE1060F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF53588AFA2C69F4FULL + 0xD613428D1A55FFFFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD6F9904A28EA224DULL + 0x94BF09FDDBAC1E7EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x9DEC9EE186BDDD53ULL + 0xA2331DF5318F4E17ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8C72083F156B4ECDULL + 0xCF7F70B7F6A5F847ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE334A7ECE6CCD6EFULL + 0xEF7A440424BDDB63ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA717D3544318252BULL + 0x9D82F1293B89CAA7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF06B60FF6BEC8C5FULL + 0x94E82947873C07C0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAB3EED0DD11F0563ULL + 0xF0B45721401C6B36ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFAC55DEADF54A3F9ULL + 0x9884406A074076FDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCFC9BB2370E31F8BULL + 0xAA8F66B0F12D8799ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDE22301AB5EF49C5ULL + 0x971DAB50C3953FA3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x809396E3B6F57287ULL + 0xD08F20D757742398ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xA41AB225E20C961DULL + 0xE6CAB551B0B9CEB0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD0B8682FA144AD6BULL + 0xBCAC50A36FF65BC6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC5EF4AB111059FAFULL + 0xF67A91CC2C2F9811ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1329U)) & W_KEY1], 40U) ^ RotL64(aKeyRowReadB[((aIndex + 1438U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1754U)) & W_KEY1], 43U) ^ RotL64(mSource[((aIndex + 1117U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 44U)) + RotL64(aCarry, 51U)) + 9654059367478508868U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 51U)) + 6473006635864677427U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 6944184481315853243U) + aPhaseEOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 11U)) + 4061496421939102306U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aIngress, 57U)) + 15791809275719085463U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 13U)) + 14050798802646323055U) + aNonceWordN;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 35U)) + 12072905924741758266U) + aNonceWordH;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17639076509231343896U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12195388285571234715U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 4317060502521195769U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4325404419499496529U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5910567888204238382U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 11503787177122206937U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13092940059929942699U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13381962590820308761U;
            aOrbiterK = RotL64((aOrbiterK * 6345904465930943295U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15622862439323440527U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14027151901132249793U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2273573821630510087U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4584410023907605157U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15763755180625487157U;
            aOrbiterB = RotL64((aOrbiterB * 6755736130607297639U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17023059745666559199U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5298529579288492971U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2483562793328357721U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 2870152867331654736U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12017191100173748848U;
            aOrbiterF = RotL64((aOrbiterF * 9958191466506480519U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterK, 27U)) + aNonceWordP) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 12U)) + aNonceWordG);
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aCross, 28U) + RotL64(aOrbiterK, 35U)) + aOrbiterC);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 57U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordI) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 5261U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 5384U)) & W_KEY1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4242U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4756U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 40U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 2915859148137000694U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 28U)) + 210680583721444425U) + aNonceWordN;
            aOrbiterI = (aWandererK + RotL64(aIngress, 19U)) + 6668118118775650387U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 53U)) + 15794200818099010989U) + aNonceWordE;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 37U)) + 6565076707062828369U) + aPhaseEOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1]) + aNonceWordK;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 53U)) + 16323164497808856719U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 7965435318816716560U) + aNonceWordJ;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7390281030573369017U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 2269738866911824875U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 1198697877998135567U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9664014216039993873U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18284857398028357633U;
            aOrbiterG = RotL64((aOrbiterG * 8402008251343393737U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 367667619795303009U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7935945060956274197U;
            aOrbiterC = RotL64((aOrbiterC * 5481786693511955209U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16683666162337789540U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10655658270998102390U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15231596813382239841U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8307037916581540297U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3247742749860703524U;
            aOrbiterD = RotL64((aOrbiterD * 15052136713218656641U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 10446792483683818139U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 16374602929344972364U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 12599903932725787599U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2411334498322777183U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 1093701164116833765U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13129220206835381729U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 27U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 12U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterI, 19U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 3U)) + aNonceWordG);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 5U)) + aPhaseEWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 46U)) + aOrbiterK) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7386U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 7326U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 5590U)) & W_KEY1], 34U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6091U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6492U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 35U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 7825479804710770560U) + aNonceWordI;
            aOrbiterI = ((((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 47U)) + 5298124167101358123U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 17774541024369233726U) + aNonceWordH;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 54U)) + 7679371833537454082U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 47U)) + 5385914900748772224U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 29U)) + 3879781930908486531U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aWandererH + RotL64(aScatter, 35U)) + 659110346638873236U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10749021728538539749U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3631252455767429457U;
            aOrbiterG = RotL64((aOrbiterG * 8552825360915119613U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 2271978810960685021U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5963558780692551176U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4772055335210781149U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 974909966119198104U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9296998242911152296U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 2613629915877957661U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 2245318466901521959U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13391076374843288568U;
            aOrbiterB = RotL64((aOrbiterB * 18094558036982107419U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6184487746594236737U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1563385912137291418U;
            aOrbiterA = RotL64((aOrbiterA * 4805455299959232321U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1744840092006498629U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2100927276837188416U;
            aOrbiterH = RotL64((aOrbiterH * 3541788262067077997U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9998911862807246338U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12239948725635220096U;
            aOrbiterI = RotL64((aOrbiterI * 7098620484129489129U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 60U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterB, 53U)) + aNonceWordF);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 60U)) + aOrbiterA) + aNonceWordN);
            aWandererG = aWandererG + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterG, 35U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererK = aWandererK + ((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 29U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 9086U)) & S_BLOCK1], 46U) ^ RotL64(aKeyRowReadB[((aIndex + 9524U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(mSource[((aIndex + 10734U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10827U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9460U)) & W_KEY1], 41U) ^ RotL64(aFireLaneB[((aIndex + 8324U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 51U)) + (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererA + RotL64(aIngress, 29U)) + 18319689184146942855U;
            aOrbiterE = (((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 8041304130090501019U) + aNonceWordL;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 41U)) + 11347064191990897738U) + aNonceWordA;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 15242243470024447468U) + aNonceWordB;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 6U)) + RotL64(aCarry, 3U)) + 10619749107163611105U) + aPhaseFOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aCross, 21U)) + 14795614276221947128U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 57U)) + 1578095288886372393U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13593906305770501684U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8919815528334599172U;
            aOrbiterI = RotL64((aOrbiterI * 2033810402808238127U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17425548324720065145U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 11125018338392347335U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4377887040461528587U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3779189180734244399U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 10958224663276134041U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 6206963519509783781U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4317305352561612995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4891139433808505355U;
            aOrbiterC = RotL64((aOrbiterC * 11507024985663120317U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5166074784835930965U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10080890270621589202U;
            aOrbiterE = RotL64((aOrbiterE * 13170894418184288695U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4501071771615514619U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6486573807774431753U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 324029625116648669U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 15714881857668975753U) + aNonceWordI;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 3506619392820235900U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 5707033870161224499U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 29U);
            aIngress = aIngress + (RotL64(aOrbiterI, 48U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 60U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterD, 60U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterH, 37U));
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 13274U)) & S_BLOCK1], 47U) ^ RotL64(aKeyRowReadA[((aIndex + 11261U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13190U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 13274U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11191U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12992U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12664U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 6U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 1210605127156905516U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 11964595428173569519U) + aNonceWordD;
            aOrbiterK = (aWandererK + RotL64(aCross, 27U)) + 16277319029916258482U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 56U)) + RotL64(aCarry, 11U)) + 12369497463101824572U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 3U)) + 6201248574067068202U) + aNonceWordN;
            aOrbiterH = (aWandererA + RotL64(aCross, 41U)) + 1727477025667206661U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 19U)) + 1404510627789806851U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6948213591282018925U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 6688865181284421478U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 12619122841662247279U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3351130769402360855U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12681032488906270823U;
            aOrbiterD = RotL64((aOrbiterD * 3680893896579741263U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 3591412591193726763U) + aNonceWordF;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 16153817571210878589U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 4165137036092246349U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3808228354421006630U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1427373776207504205U;
            aOrbiterE = RotL64((aOrbiterE * 4534374093769595531U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1831554180932501132U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1114853085120949215U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4264176108298812905U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2080935638828366835U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16104777999646489828U;
            aOrbiterA = RotL64((aOrbiterA * 15205199362011777473U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 9782806013673440791U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3721620299829386454U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6286765834910272409U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 4U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + aNonceWordO);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 57U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aNonceWordJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 36U) + aOrbiterF) + RotL64(aOrbiterJ, 46U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 14120U)) & S_BLOCK1], 54U) ^ RotL64(aFireLaneC[((aIndex + 14394U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15223U)) & W_KEY1], 30U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15995U)) & W_KEY1], 5U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14792U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15805U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 14365U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 23U)) + 9914837590440975587U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 6706125076401958051U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 10U)) + 16570817772679258409U;
            aOrbiterJ = ((((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 6843705658115186948U) + aPhaseFOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 41U)) + 16099930446791572351U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 35U)) + 5420550009556030459U) + aNonceWordO;
            aOrbiterD = ((aWandererC + RotL64(aCross, 29U)) + 5729549069420177477U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15590601126188675834U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 13044027390998620029U;
            aOrbiterA = RotL64((aOrbiterA * 16845199115313444123U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11068338135659636772U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 6584988841809544332U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1683336180438945439U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8516813219883915404U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10647314042912492785U;
            aOrbiterH = RotL64((aOrbiterH * 15559481057047148785U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 201691689889605304U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15512161798401184003U;
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 3883760518944464145U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13861805129175491145U;
            aOrbiterD = RotL64((aOrbiterD * 17194438894492581181U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12019138626550801486U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13030350224959652248U;
            aOrbiterK = RotL64((aOrbiterK * 11724200983306280107U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2643807255422544248U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4127143302485631794U;
            aOrbiterJ = RotL64((aOrbiterJ * 5441038881111578487U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 27U) + RotL64(aOrbiterE, 51U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterK, 44U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17673U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 19005U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 16735U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16851U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17730U)) & W_KEY1], 4U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17246U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18565U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 18U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 11700815697312060726U) + aNonceWordC;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 24U)) + 11808423452327465441U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 51U)) + 8670503858631730886U) + aNonceWordE;
            aOrbiterE = ((aWandererH + RotL64(aCross, 37U)) + 2400061067991988544U) + aNonceWordD;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 5U)) + 16163118178366229686U) + aNonceWordP;
            aOrbiterA = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 41U)) + 3280178595904941068U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 3298683600817047727U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 16321624053445183574U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6730229877611375225U;
            aOrbiterF = RotL64((aOrbiterF * 2022290495153519279U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10162830636713641322U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15646771327759599256U;
            aOrbiterH = RotL64((aOrbiterH * 15333053762177144775U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14841751262270544102U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 9545541117228834895U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11529769874752969377U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14676615635857599982U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1231768638470558855U;
            aOrbiterG = RotL64((aOrbiterG * 2716808508509014677U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 1945905595345404833U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1406171421638586846U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4577864352425476233U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1970292335806697198U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 12309719390375013297U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 16540660957923687327U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5352135521358954576U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 15465675376193501658U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 16385761112921041387U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 60U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterH, 53U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterG) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 21U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterB, 60U)) + aOrbiterA) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20065U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((aIndex + 21641U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 19117U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19954U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21711U)) & W_KEY1], 47U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20516U)) & W_KEY1], 27U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21596U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneB[((aIndex + 21455U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 43U)) ^ (RotL64(aCarry, 13U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 4773124477323378268U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 35U)) + 16848723289435796005U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 13846642134917107058U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 13U)) + 6472057872482789939U) + aNonceWordM;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 28U)) + 2747019500690707226U) + aPhaseGOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((aWandererE + RotL64(aCross, 5U)) + 9003965289739733880U) + aNonceWordA;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 11U)) + 3013390651936257377U) + aNonceWordG;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3331004709895625067U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15355010435553517129U;
            aOrbiterK = RotL64((aOrbiterK * 8322759117004876831U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 7709870658004280052U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13568728443963926564U;
            aOrbiterE = RotL64((aOrbiterE * 6736090830113688981U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12409548853419307131U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 969183352023661537U;
            aOrbiterB = RotL64((aOrbiterB * 5549220554838837145U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15370309834426476775U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 3896803894396631184U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 11018830202891911603U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10848873633291935766U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 12885336509190543440U;
            aOrbiterA = RotL64((aOrbiterA * 1487357252619221365U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8252290890093788010U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9201553615601641350U;
            aOrbiterH = RotL64((aOrbiterH * 420321130559162915U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14014209645503188472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4015071464301844550U;
            aOrbiterD = RotL64((aOrbiterD * 17444195018239904971U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterH) + aNonceWordH);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterK, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 28U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 22677U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadA[((aIndex + 24412U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23492U)) & W_KEY1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21882U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22411U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23999U)) & S_BLOCK1], 24U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23196U)) & S_BLOCK1], 35U) ^ RotL64(aFireLaneD[((aIndex + 22922U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCross, 27U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterC = (aWandererK + RotL64(aPrevious, 11U)) + 15188686795415908074U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 17310049041983079779U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 35U)) + 8246925977992441471U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 8644260919918112781U) + aNonceWordO;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 21U)) + 13401663736874819483U) + aPhaseGOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 7940358935238314973U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 47U)) + 13278990328548007839U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11346868298353840706U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2374077904806833579U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1765686942154321425U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 6978903378645019166U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11951633297870965212U;
            aOrbiterC = RotL64((aOrbiterC * 12778236598654492185U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17398460995357409673U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1215437945597836770U;
            aOrbiterK = RotL64((aOrbiterK * 9322970054123481621U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1878751468043972239U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5343002808239712390U;
            aOrbiterG = RotL64((aOrbiterG * 11878640995447558811U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9884918450053276861U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 15894599082080422550U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 8359936745539546131U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13917339232771145459U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 18101134009493720683U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 15835859435306756387U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3830086372356903769U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15894394599564584010U;
            aOrbiterA = RotL64((aOrbiterA * 9513921913446609263U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 21U)) + aPhaseGWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterA, 44U)) + aOrbiterG) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + RotL64(aCarry, 3U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 51U)) + aOrbiterC) + aPhaseGWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26547U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 25703U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25656U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25125U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26474U)) & W_KEY1], 37U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26903U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26837U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((aIndex + 24581U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 50U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterK = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 2558105147674438050U) + aNonceWordG;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 36U)) + 15856662514774702561U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 19U)) + 13346869226246584582U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 7632111846116243973U;
            aOrbiterB = ((((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 2102101361626976279U) + aPhaseHOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 57U)) + 5605968705067851563U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 43U)) + 6842483186584326681U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5559797213819425064U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12422313931331576759U;
            aOrbiterF = RotL64((aOrbiterF * 7399849122565913401U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2751024420047872601U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11031320239359798610U;
            aOrbiterK = RotL64((aOrbiterK * 8607639453141148025U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 14366375309473793217U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 11971479429768505316U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10063001532313098203U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3947595951884469542U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17882767922372770896U;
            aOrbiterC = RotL64((aOrbiterC * 3361906348965810211U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 513871456983509223U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5951677013597794294U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8508629569649935293U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 437626309049021931U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 466674061172005705U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 1310502572084891157U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 12362602809233133718U) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 10525852878882195702U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17755022180514914325U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterJ, 4U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterC, 35U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterK, 53U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 4U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29399U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneD[((aIndex + 28745U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29781U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27484U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29794U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27576U)) & S_BLOCK1], 27U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29310U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 27556U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCarry, 57U)) + (RotL64(aPrevious, 44U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = (aWandererA + RotL64(aIngress, 57U)) + 15652862298542575895U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 29U)) + 16925323928418184554U) + aNonceWordB;
            aOrbiterF = ((((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 4413861484961668394U) + aPhaseHOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aWandererD + RotL64(aCross, 35U)) + 2215946422098155969U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 48U)) + RotL64(aCarry, 27U)) + 14975185533513111110U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 3U)) + 9711613814905834552U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 13154957291850149471U) + aNonceWordO;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 5058313016418534840U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15011423472941211620U;
            aOrbiterF = RotL64((aOrbiterF * 6125316151731105673U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2030053257469580168U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 150530795186791193U;
            aOrbiterI = RotL64((aOrbiterI * 11106050063717096073U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10878237472104183427U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11724672539469573109U;
            aOrbiterJ = RotL64((aOrbiterJ * 16158741837357985395U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 9589700906445846956U) + aNonceWordA;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1367381624958248949U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8459515089081211977U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12003215666757518106U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11232479330848006729U;
            aOrbiterH = RotL64((aOrbiterH * 10993290955464593033U), 35U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 13013910456628561621U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6092509838924105265U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 805601154718006061U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11999225836250312801U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14421271973875748413U;
            aOrbiterG = RotL64((aOrbiterG * 9529010940887430157U), 29U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 10U) + aOrbiterI) + RotL64(aOrbiterE, 54U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 41U)) + aNonceWordG);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterE, 21U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterB, 3U)) + aNonceWordE) + aPhaseHWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 24U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32287U)) & S_BLOCK1], 58U) ^ RotL64(aKeyRowReadA[((aIndex + 31767U)) & W_KEY1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 31952U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30718U)) & S_BLOCK1], 21U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31466U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 31494U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 19U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 52U)) + 9774364261626083532U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 5U)) + 18059001521926116420U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 43U)) + 10615626210406381148U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 37U)) + 10536484278007898620U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 13320663045139972700U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 17127001787268166583U) + aNonceWordN;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 29U)) + 16742574590844166551U) + aNonceWordO;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8347719720758228053U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13502468705946051986U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 13822952083584784695U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3512687886188904904U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 495660316165795934U;
            aOrbiterD = RotL64((aOrbiterD * 6724596801190194913U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 5092722552034477356U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15641128019608284015U;
            aOrbiterJ = RotL64((aOrbiterJ * 3621036395703527059U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15421873776811085458U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 17978775513204574125U;
            aOrbiterG = RotL64((aOrbiterG * 18359600395119440183U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 16617179197537669849U) + aNonceWordJ;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1931805387534012528U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 3400139345857733775U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9544923119559308431U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12930999400470173353U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16791006919271490005U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13673733276226249890U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2032263473309124738U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3088728329261360607U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 22U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 58U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aCross, 27U) + RotL64(aOrbiterC, 21U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 41U)) + aOrbiterD) + aNonceWordI);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + aOrbiterK) + RotL64(aOrbiterF, 51U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + aNonceWordG);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + RotL64(aWandererF, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_FootBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEDBA476A852F5BB5ULL + 0xDA5BB1486BFC8976ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC7633F4D40C7BEC1ULL + 0xB77032452F1B1385ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x88DDFC701A19D545ULL + 0x8A7B99E36E6F8FA3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8FC6E7EA31446877ULL + 0xA5836DC2BBC4D2BAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8EA8B2580756DA0DULL + 0x96793BAB315E63A1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xCF0B53D55DF76AD5ULL + 0xADD726D8E50E3618ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC6AC0227466C42A1ULL + 0x8BA9382DCECCD57AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8C5BD0C3FF916A37ULL + 0xB8B63840EB116AABULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF455467E4F576C7BULL + 0xECC91633029E840CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF416E2B7C1CCAD61ULL + 0xF460D074D26CCBF1ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8890E53781703F31ULL + 0xC6101544F1B6261AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xAF5CF8A818A270C9ULL + 0xBC76685AA860E446ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8E527879E1A6CC57ULL + 0xDDC0D76CDD442F1FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBFE5E1169BD2B019ULL + 0x975BFE878F9EF95AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE2F71ED679E0425BULL + 0xA3C81288A74E8DA3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC493DF7252A09E09ULL + 0x9459E2CA054AAE48ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2980U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 4651U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 401U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1301U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1048U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 3076U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCarry, 4U)) + (RotL64(aCross, 53U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererJ + RotL64(aIngress, 53U)) + 3684295017013759987U;
            aOrbiterF = ((((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 6740408842457292881U) + aPhaseAOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 11U)) + 4563975890702399441U) + aNonceWordN;
            aOrbiterK = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 797804144825287940U) + aNonceWordF;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 29U)) + 2763779540450101303U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordM;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 13211846164102089685U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 15214578447281401982U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 12107189619131483661U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 13745208628754232427U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 17358621225969190747U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5325024317338823061U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 779739369960480023U) + aNonceWordC;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4370963533701407813U;
            aOrbiterA = RotL64((aOrbiterA * 3123135216876641039U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6061333005507739975U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterF) ^ 3589705340762734456U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 16499293983611196967U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10607697666369230567U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9356757995305239271U;
            aOrbiterK = RotL64((aOrbiterK * 10945513661439954731U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 30U));
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK) + aNonceWordA) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 38U)) + aNonceWordI);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 56U) + aOrbiterC) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 3U)) + aNonceWordO) + aPhaseAWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9084U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 10525U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 9113U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 8562U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5975U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10332U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9344U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 18U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterE = (((aWandererI + RotL64(aIngress, 19U)) + 12690502671561165478U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 17519943923428102801U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 10705515807975331385U;
            aOrbiterI = ((((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 21U)) + 16586447272278538179U) + aPhaseAOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 42U)) + 8006560996840971798U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12928600185788857701U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14240723153798267172U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7446040187505339853U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8636219177994872072U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7586790235186467512U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15052686382507614169U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 1103807034179512424U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7547526530239498693U;
            aOrbiterI = RotL64((aOrbiterI * 3360295583636013509U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8380239679344786397U) + aNonceWordF;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5690809173787433519U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 5354724308093372953U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8390902801141804609U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3507306189192059486U;
            aOrbiterC = RotL64((aOrbiterC * 18336280496510253103U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 53U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 21U)) + aNonceWordN) + aPhaseAWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 3U)) + aNonceWordG) + aPhaseAWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterI, 48U)) + aNonceWordK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 4U) + aOrbiterG) + RotL64(aOrbiterI, 39U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 14560U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 10940U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12638U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13264U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 12450U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 41U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 35U)) + 4179952823252098240U) + aNonceWordN;
            aOrbiterE = ((aWandererD + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 3745613452332101749U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 2955689793395307176U) + aNonceWordM;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 5U)) + 5639060180251322019U) + aPhaseAOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 23U)) + 7901969163853586463U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2242166787816318119U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5239936443960750064U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2752853245379816327U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13939136954732185558U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17058884136712717463U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 7222348891215482977U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18148618660054585941U) + aNonceWordH;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7022023484530327814U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 650100011311048589U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 7722084537340095637U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 11764151879690934182U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12264384877711365655U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16412785901758144708U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9666718667728274824U;
            aOrbiterE = RotL64((aOrbiterE * 10865799822751771795U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aNonceWordB);
            aWandererK = aWandererK + (((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 18U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aNonceWordL) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + aPhaseAWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20979U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((aIndex + 20857U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 18756U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 19324U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((aIndex + 21009U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 6U)) + RotL64(aCarry, 51U)) + 6068543441070417854U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 2995980468193441856U) + aNonceWordK;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 27U)) + 18020277482171594003U) + aPhaseAOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = ((((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 4293807434721230702U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 19U)) + 7980599111583893156U) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8593141111851052016U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 5903487523900084325U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2508618861111356699U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 15112035513447930209U) + aNonceWordH;
            aOrbiterB = (((aOrbiterB ^ aOrbiterE) ^ 9854037263057006439U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 396276470208637283U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 16759760289688823193U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12622628933030601390U;
            aOrbiterH = RotL64((aOrbiterH * 2151912984825538321U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 1264668857268123425U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16302812053619101593U;
            aOrbiterE = RotL64((aOrbiterE * 18291400055836111547U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16087995784896123610U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7970269262800468363U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14924752223305807461U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 42U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aNonceWordN) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 47U));
            aWandererI = aWandererI + (((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 37U)) + aNonceWordC) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterA) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22667U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 24593U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23551U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25514U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26955U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 11U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 15904465836916519864U) + aNonceWordB;
            aOrbiterH = ((aWandererG + RotL64(aCross, 39U)) + 17725629806317789307U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 51U)) + 13794170125914914828U) + aNonceWordA;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 2149055907476874332U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 14U)) + 5342047776745074649U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8268148484060546838U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10821151364028563719U;
            aOrbiterG = RotL64((aOrbiterG * 13626634259250509711U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4294213820894407378U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterH) ^ 10884726101307943090U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 1116128870387229159U), 27U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 16432210042202444824U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15196602644336228055U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 12680438355124070237U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14117787670220328165U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 219833877949480215U;
            aOrbiterF = RotL64((aOrbiterF * 10736293047771972173U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3326396981881473962U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14918513066311426279U;
            aOrbiterK = RotL64((aOrbiterK * 14269763278564574663U), 43U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 18U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterK, 4U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterF, 57U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aCross, 53U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + aNonceWordE) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 30261U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 27527U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 30456U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27887U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29528U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = (((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 2783898056762489197U) + aNonceWordE;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 13U)) + 7177192902873343053U) + aNonceWordD;
            aOrbiterJ = ((((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 12254703232691980774U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((((aWandererI + RotL64(aCross, 54U)) + RotL64(aCarry, 51U)) + 15446547245691219559U) + aPhaseAOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererG + RotL64(aIngress, 3U)) + 888475203006174856U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3649183529366307877U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4642631047518805167U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14791564497487717167U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6108329730724782250U) + aNonceWordM;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8334054653023816636U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9352516059501924393U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5891895375031474350U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3176720746238477862U;
            aOrbiterA = RotL64((aOrbiterA * 1869961473768307911U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 6111038696865301675U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11914998302228682704U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 11738924766359642853U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17005063057791320948U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 18333780598768130670U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 5416759844884107303U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 46U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterB, 37U)) + RotL64(aCarry, 51U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aNonceWordK) + aPhaseAWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterB, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_FootBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA039D3D9597DFBFBULL + 0x8D0720DBE0E1AE90ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB18BF47A76414367ULL + 0xAABAC8610EF952CEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEB6FB9020E247345ULL + 0xC3414B34B12F3A0FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x938B294AB26BD407ULL + 0x9893E27561F626ABULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAF5BCC5BBDC20B9FULL + 0xD897A15A8A360184ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC9C5CCC78B04B515ULL + 0xEFA92E1647F1B59AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFC0DC5E21E3949DFULL + 0xA3DA3401F649720CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEED11AD8851EE2E9ULL + 0xD6521B4108C6D0A6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBA391C4A1AD09F75ULL + 0x97FFE7DDE22AE679ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB294F2ED3BBECEBFULL + 0xC9053408816DCAE8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD23C275FDEC5CF55ULL + 0xCDC08FC2C40989FDULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB27FDBC85B36C0B5ULL + 0xDB044BECBBEC08C1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA9CCFC6B9C499F31ULL + 0xFB7CCF41C648D8D4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9F22177929E6FC2BULL + 0xA021C641F8057284ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCD52B075973E5589ULL + 0xBA40C0407663CCEFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE8A04345003101EDULL + 0xA1E4F035AF0FDB8AULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 645U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 1173U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4701U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3009U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 7213U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1424U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCross, 41U)) + (RotL64(aIngress, 10U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (aWandererA + RotL64(aScatter, 39U)) + 826930775230515406U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 14U)) + RotL64(aCarry, 41U)) + 5137814617363250861U;
            aOrbiterI = (((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 14761561947426681616U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aWandererD + RotL64(aCross, 19U)) + 12773023438753662590U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 47U)) + 7331345852207096322U) + aNonceWordP;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 43U)) + 3899381212671247460U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterB = (aWandererE + RotL64(aIngress, 60U)) + 10072004147620068599U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 5U)) + 3424585039401897560U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 8246760141625966321U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3655992860610853290U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11154618022505863898U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4791494171286145231U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 15629361991059709973U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10842068502278489664U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 17223002513104960799U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5571312349016336686U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 589313823745748879U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 1356685926549786027U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13633457935771935260U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12684602052812183096U;
            aOrbiterE = RotL64((aOrbiterE * 4689206269919806711U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5711307583717354204U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 7181854170553728211U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9835601115561325911U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 1884620014396115821U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1471516373272364262U;
            aOrbiterK = RotL64((aOrbiterK * 5126319375714848029U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 742739371092077733U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8075893317715227838U;
            aOrbiterH = RotL64((aOrbiterH * 11208274111743259795U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8179547722249281263U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15305282712174742323U;
            aOrbiterA = RotL64((aOrbiterA * 7951986906055462929U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 1430543231751281079U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14585341768267283387U;
            aOrbiterJ = RotL64((aOrbiterJ * 313213844964269133U), 27U);
            //
            aIngress = RotL64(aOrbiterA, 10U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + aNonceWordH);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aPrevious, 46U) + RotL64(aOrbiterJ, 28U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 12U) + aOrbiterH) + RotL64(aOrbiterI, 13U)) + aNonceWordD);
            aWandererC = aWandererC + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 54U)) + aOrbiterK) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 54U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12151U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 15985U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10737U)) & S_BLOCK1], 38U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10626U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12271U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10392U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 13550U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 5697928251815176134U) + aNonceWordH;
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 42U)) + 337587740689259575U) + aPhaseBOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 4927686903263973950U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 3742409032569801033U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 23U)) + 1608092659172197650U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 51U)) + 15848744267145717509U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 35U)) + 15300174177963339253U) + aPhaseBOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 4U)) + 14162868453323648628U;
            aOrbiterI = (aWandererA + RotL64(aCross, 11U)) + 12020167069983729869U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16259538291658723956U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8516686212464112245U;
            aOrbiterE = RotL64((aOrbiterE * 4731296903548893627U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 3722184575520553132U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5663609293306386784U;
            aOrbiterG = RotL64((aOrbiterG * 14364218128780764749U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15265344442454471986U) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 3050323350098829515U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 5890624677162388135U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1093356813820599238U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15167726103772238440U;
            aOrbiterH = RotL64((aOrbiterH * 5719466863561311069U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15170797965325981472U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterB = RotL64((aOrbiterB * 11186808881726573677U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 14710892030473425181U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 397194787697553904U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14368930300818752833U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 1273724124862533034U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13018397560392545616U;
            aOrbiterJ = RotL64((aOrbiterJ * 4644812473262395329U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 9638716186445643730U) + aNonceWordB;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 7255587739807843785U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6055682981584011189U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 9272350563697399628U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1040729335295009339U;
            aOrbiterI = RotL64((aOrbiterI * 17825687660830291443U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 13U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterE, 19U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 56U)) + aOrbiterA) + aNonceWordL) + aPhaseBWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 39U)) + aOrbiterA) + aNonceWordO);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 18U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24469U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 20466U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 21384U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22001U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16451U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18310U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18997U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 36U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 19U)) + 17936518874386450467U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 3U)) + 13722737841589910344U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 40U)) + 11774969167948715796U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 23U)) + 3640101505680493777U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 29U)) + 1369495382725650822U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 11827310354654653345U) + aNonceWordO;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 36U)) + RotL64(aCarry, 29U)) + 186037671377175394U) + aNonceWordE;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 11428829344234627340U) + aNonceWordM;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 57U)) + 2275016369870029068U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 15471646673734798328U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12172082573115640145U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9629417882787847753U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 6626736341348283154U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12220614992483863623U;
            aOrbiterJ = RotL64((aOrbiterJ * 8137086205714097487U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13157102324253760215U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4143587482368093601U;
            aOrbiterG = RotL64((aOrbiterG * 5060677690991506895U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 11007575246013796426U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11721585930088637162U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15009627907125738519U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5720789204450196217U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3094696226821431648U;
            aOrbiterK = RotL64((aOrbiterK * 4412033981712165541U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 14675830108100986773U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9444071495289719645U;
            aOrbiterF = RotL64((aOrbiterF * 10983136361953366557U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5106753847015199956U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7585421898593510010U;
            aOrbiterD = RotL64((aOrbiterD * 140996914192351011U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11746948407655524690U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16336323220286344483U;
            aOrbiterC = RotL64((aOrbiterC * 6590417628835864497U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8030445186765781136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 276034088015165891U;
            aOrbiterA = RotL64((aOrbiterA * 7626025612710225099U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterK, 43U));
            aWandererD = aWandererD + (((RotL64(aScatter, 14U) + aOrbiterD) + RotL64(aOrbiterG, 23U)) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 57U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 12U)) + aOrbiterD) + aNonceWordN);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA);
            aWandererI = aWandererI + (((((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordC) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 27U)) + aNonceWordP);
            aWandererF = aWandererF + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterD, 53U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 18U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 38U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27975U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 32538U)) & S_BLOCK1], 29U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 24848U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 30633U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29770U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31552U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneD[((aIndex + 32730U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCross, 18U) + RotL64(aPrevious, 51U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 47U)) + 12775735908960052604U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 60U)) + 11791373812080296887U;
            aOrbiterF = ((((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 5537362877706057303U) + aPhaseBOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aWandererD + RotL64(aCross, 53U)) + 2023912048504189380U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + 17668828109963766893U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 39U)) + 558908629933941224U) + aNonceWordL;
            aOrbiterB = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 1479633119685446888U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 23U)) + 15460320397843364063U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 10U)) + 10059749397555469054U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9987633811929693924U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10087337844580228269U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13817142288940843815U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 4446204415503364254U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15106063243302192717U;
            aOrbiterC = RotL64((aOrbiterC * 13273756657334709803U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 9430197906134676162U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1226048679997253363U;
            aOrbiterJ = RotL64((aOrbiterJ * 14247538885252664127U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10611580584157624739U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 3137391249289641509U;
            aOrbiterI = RotL64((aOrbiterI * 5462682413239873181U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9327201928815412810U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7890659377013147073U;
            aOrbiterH = RotL64((aOrbiterH * 13827717178378062047U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10675114832750356941U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8804440385852327267U;
            aOrbiterE = RotL64((aOrbiterE * 8520671775587260601U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12871947817782057116U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11015991745792051390U;
            aOrbiterD = RotL64((aOrbiterD * 17152451500505815031U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6320437975845673731U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 702457937087191287U;
            aOrbiterG = RotL64((aOrbiterG * 17491257114676739589U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16629064896250312921U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6054107387816339103U;
            aOrbiterB = RotL64((aOrbiterB * 6983767878966747219U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 42U));
            aIngress = aIngress + RotL64(aOrbiterE, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterB, 48U));
            aWandererA = aWandererA + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 43U)) + aOrbiterF);
            aWandererD = aWandererD + (((((RotL64(aCross, 24U) + RotL64(aOrbiterF, 19U)) + aOrbiterG) + RotL64(aCarry, 21U)) + aNonceWordH) + aPhaseBWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 60U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterI) + aNonceWordK) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 6U);
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

void TwistExpander_FootBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA418D32E73D7E0E5ULL + 0xB53F538A9AAE39FBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9090DD7F2F88E623ULL + 0xF2642D0884CDE4FAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE887E9D0D061B725ULL + 0xCFD0D0C3480F16CFULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8F7ED69EDE5897EFULL + 0xDBFD83892D915485ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA437B1560EFFC805ULL + 0xFEC7E183FE021FD7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA85B0B200D1C54C7ULL + 0xE759FB633CA0B539ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA98A47D58FC33445ULL + 0xB098FE4CD599124FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD24E98F9EF9FDCC7ULL + 0x81349511FB556764ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x87CA98881C0787DFULL + 0x96C5D7783B94E5C5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE56D210004F04F0FULL + 0xE23BA3E11B770DFDULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC3AC67E26F4673BDULL + 0xE2D8B5B9BA2B6D68ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9CE713206FBE7BF1ULL + 0xABE9C48C94119D64ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA248E10BE0CFF0BDULL + 0xCE5B4B119CF8F553ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD41AD5E24C0DB955ULL + 0xAA46F754829BD2B1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD27CA223AE39A86BULL + 0x9944171AADD20025ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB05B75CDB316D1A5ULL + 0xCE7F5F16F3BEEC39ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5258U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 2057U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2935U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4382U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3468U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 946U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 24U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterA = (aWandererH + RotL64(aIngress, 26U)) + 5721224134332887360U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 3U)) + 6892749729775049095U) + aNonceWordN;
            aOrbiterH = (aWandererD + RotL64(aCross, 35U)) + 3884839462099556836U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 51U)) + 4365431706830216193U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 41U)) + 15501528746571578773U) + aNonceWordI;
            aOrbiterC = ((((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 4505911326320650606U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = ((((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 1865129050927879580U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2011737665969640369U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 611672935827062688U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12873671551304596619U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 663547038310431047U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5468932264754299556U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11968657455484578525U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17920294117231191705U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 486058453837528110U;
            aOrbiterC = RotL64((aOrbiterC * 8851102552244026737U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2789178451938129313U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 420772587981211184U;
            aOrbiterI = RotL64((aOrbiterI * 17402987842294006667U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16196774774442181825U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16264169656793713547U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 6900221986041638783U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10207659833859860796U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 8593749091183323678U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 10696776033512404927U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7224922076047787384U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15366267474865172373U;
            aOrbiterB = RotL64((aOrbiterB * 10134187073321814217U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 5U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterA, 27U)) + aNonceWordL);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 22U) + aOrbiterB) + RotL64(aOrbiterK, 36U));
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterG, 53U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterG, 47U)) + aNonceWordF) + aPhaseDWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5744U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 6918U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 6922U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneC[((aIndex + 8310U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7731U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10508U)) & S_BLOCK1], 12U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 10727U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 19U)) + 11700815697312060726U;
            aOrbiterA = ((((aWandererG + RotL64(aCross, 60U)) + RotL64(aCarry, 11U)) + 11808423452327465441U) + aPhaseDOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 8670503858631730886U;
            aOrbiterF = (((aWandererC + RotL64(aIngress, 35U)) + 2400061067991988544U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aWandererI + RotL64(aCross, 13U)) + 16163118178366229686U) + aNonceWordC;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 43U)) + 3280178595904941068U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 3298683600817047727U) + aNonceWordI;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16321624053445183574U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6730229877611375225U;
            aOrbiterJ = RotL64((aOrbiterJ * 2022290495153519279U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 10162830636713641322U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15646771327759599256U;
            aOrbiterC = RotL64((aOrbiterC * 15333053762177144775U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14841751262270544102U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9545541117228834895U;
            aOrbiterD = RotL64((aOrbiterD * 11529769874752969377U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 14676615635857599982U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1231768638470558855U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2716808508509014677U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1945905595345404833U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1406171421638586846U;
            aOrbiterE = RotL64((aOrbiterE * 4577864352425476233U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1970292335806697198U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12309719390375013297U;
            aOrbiterF = RotL64((aOrbiterF * 16540660957923687327U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5352135521358954576U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15465675376193501658U;
            aOrbiterI = RotL64((aOrbiterI * 16385761112921041387U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 36U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterD) + aNonceWordK);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 26U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 13U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterE, 19U)) + aNonceWordA) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 20U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 13792U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 14205U)) & S_BLOCK1], 60U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 15124U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14454U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 12642U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 43U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 1898718075389870739U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 5631794889237247403U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 18219714659484524607U) + aNonceWordI;
            aOrbiterH = (aWandererA + RotL64(aScatter, 13U)) + 15419581386225732921U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 57U)) + 9125575431710198210U) + aNonceWordB;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 20U)) + 12205871520544965505U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 47U)) + 7617534300497343422U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 18017579105368135814U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10693882161946020042U;
            aOrbiterA = RotL64((aOrbiterA * 2326507900303932855U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11669615701700895306U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11045110212889232165U;
            aOrbiterK = RotL64((aOrbiterK * 5965171269273719849U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18019107802806469913U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12315940560472528716U;
            aOrbiterE = RotL64((aOrbiterE * 4505122470351404065U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4899009736070044310U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 17412253404253730364U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10791901166391946485U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 4826286251927854181U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 4523455921321845084U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 14534103906736598099U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 4132514462154182215U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7164745605985109269U;
            aOrbiterI = RotL64((aOrbiterI * 14107325508977225261U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 6297434295807635654U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8813887638672996646U;
            aOrbiterD = RotL64((aOrbiterD * 17495632530773158201U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 28U)) + aOrbiterD) + aNonceWordM);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterK, 19U)) + aPhaseDWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 20U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 35U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21679U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 17855U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18048U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19932U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 17647U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 18U)) ^ (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterA = (((aWandererC + RotL64(aCross, 29U)) + 3621877681473089725U) + aPhaseDOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 4451752751536414717U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 11371625415377772117U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 51U)) + 6046792758881150619U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 57U)) + 8213166120394461682U) + aNonceWordA;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 36U)) + 4343156661140422645U;
            aOrbiterH = ((((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 11105271483234947905U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 348904609985341372U) + aNonceWordH;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 12924652822526858767U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2801892489296408735U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7461211697358520287U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16551553555297890558U;
            aOrbiterB = RotL64((aOrbiterB * 16432952324635746293U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11908056404140782995U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 9147367258259948715U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 10777628928376261667U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8876461054692728610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10546855952702525404U;
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 4748636139110443794U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 783046909529525098U;
            aOrbiterD = RotL64((aOrbiterD * 8969157702460927215U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16683965945838696665U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12385412690177109575U;
            aOrbiterA = RotL64((aOrbiterA * 10795062772707143187U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8210546822184469023U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13146493623236979963U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13199947810161148155U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 6U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + aNonceWordE);
            aWandererB = aWandererB + (((((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 39U)) + aNonceWordB) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterB, 13U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 11U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 36U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 26288U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 26229U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26811U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 23551U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23571U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 13687218104610230596U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererC + RotL64(aIngress, 47U)) + 6841550124960692709U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 6U)) + 17418968668458764131U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 8303537912696948204U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aIngress, 19U)) + 12376614417285936537U) + aNonceWordK;
            aOrbiterK = (aWandererH + RotL64(aCross, 13U)) + 14215749063579232654U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 4111736931433665347U) + aNonceWordE;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11250375934571631522U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5367367837773331275U;
            aOrbiterC = RotL64((aOrbiterC * 7262723007545807179U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 15514089192382674434U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1475991716685034960U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17720681295551650891U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5531622777788629748U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8363822215908303335U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17850203366840994883U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3741256932685720414U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 11634667238062155772U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 15925089729784547403U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 18180546911210417155U) + aNonceWordI;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5123234656838556335U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15362857462853398025U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11215734271189250284U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16863747802158398092U;
            aOrbiterK = RotL64((aOrbiterK * 1828035970246160023U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9859050606636646323U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9331300036643654675U;
            aOrbiterJ = RotL64((aOrbiterJ * 2502263410556166281U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 22U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 29U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 41U));
            aWandererG = aWandererG + (((RotL64(aCross, 13U) + RotL64(aOrbiterC, 3U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterE, 60U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterK, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30117U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneA[((aIndex + 28472U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28397U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29590U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31586U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 57U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererA + RotL64(aIngress, 27U)) + 12046647397183218524U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 44U)) + 2760779375026461991U) + aPhaseDOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 13735454443176855650U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 4370377000586647724U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 3U)) + 14566322384189969094U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + 5056565959818422786U) + aNonceWordA;
            aOrbiterC = (aWandererG + RotL64(aScatter, 3U)) + 8795403810686579209U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9625947666256011567U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 1703669290934254701U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 5763881345676123583U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6664070663184147951U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2104148316797553431U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12887842067180975983U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1197910004222596145U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9922977170060903197U;
            aOrbiterG = RotL64((aOrbiterG * 13047828062605568603U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 2048376210852567829U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 12568990647075931409U;
            aOrbiterC = RotL64((aOrbiterC * 9860242601194210927U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15026894775772902751U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3439447160137900629U;
            aOrbiterH = RotL64((aOrbiterH * 1813754963043785165U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6532671388552829796U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17261098369835997661U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 568292591215203521U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 3171300991007459947U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5935563269327662024U;
            aOrbiterE = RotL64((aOrbiterE * 11271790283157765003U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 58U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterE, 37U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + aNonceWordB);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 47U)) + aNonceWordI) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 28U) + RotL64(aOrbiterH, 58U)) + aOrbiterI) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + aNonceWordD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 36U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_FootBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFD12A166101E6E73ULL + 0xCABE6E89EDA72332ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD6A5D942F5A58B3FULL + 0xFF7E2DB30B9FE407ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFE06DD59B5D91681ULL + 0xC6524649DD875F4DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE17760FF54E80AF3ULL + 0xF4EAF689AF73D204ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFB4E6C911032F325ULL + 0xA1B7A2E3078436E2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFB1D85C2F35085E1ULL + 0x891C85E71499C13CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xAF413EE380A39673ULL + 0xC22EEFA85B5E662AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCAF49CC3CC18AEFBULL + 0xB5A79C9B866CB5BEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDA7066C44C307C4FULL + 0xD1A6E78051F03C4FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE760E3173D7FAFE9ULL + 0xA2C048A830514B2FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xAC10EA26308ECE93ULL + 0xCAA4DBC1B71C491DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF0F841297CB26BE3ULL + 0x83A5C9737F2FBE8DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD94305B29FD6982BULL + 0xEB02553A73B38054ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAB344B9EDA823659ULL + 0xA41D2E770628F5DBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xDA5D73AC438B07B3ULL + 0xAD70CB4E167B7DE3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9F8C12726AD5F049ULL + 0xD008C5211F957418ULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1644U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneB[((aIndex + 2518U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4255U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 2014U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3126U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4598U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 47U) + RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterB = ((aWandererH + RotL64(aIngress, 18U)) + RotL64(aCarry, 39U)) + 77518479758428414U;
            aOrbiterG = (aWandererD + RotL64(aCross, 5U)) + 4832061802166300011U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 11695291171006574112U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 7467412817843260094U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 57U)) + 17801484124471154757U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 13U)) + 5555455638503958639U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 43U)) + 5669470540733721606U) + aNonceWordG;
            aOrbiterD = ((aWandererI + RotL64(aCross, 3U)) + 3042388456327784163U) + aNonceWordO;
            aOrbiterC = (aWandererK + RotL64(aIngress, 34U)) + 2236734925228156691U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 29U)) + 14459720401528685450U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 53U)) + 4814967631216658856U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16950679344449075945U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6262238639302011050U;
            aOrbiterA = RotL64((aOrbiterA * 9942659897425088183U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3522256359074996724U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 12524717897707074242U;
            aOrbiterE = RotL64((aOrbiterE * 6787771338063891989U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13891759914865623828U) + aNonceWordN;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 11910250571469028666U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12311343917878428995U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2240189915640314069U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5365912986308810837U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15133972552032469957U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9323732721344489753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13087326560957916553U;
            aOrbiterG = RotL64((aOrbiterG * 14659491687401151733U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16398238057564892809U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11517870519285159224U;
            aOrbiterK = RotL64((aOrbiterK * 1501848878469712681U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7758285512254776734U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17475149091906684720U;
            aOrbiterC = RotL64((aOrbiterC * 6015816725428299273U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2051631493975035243U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11684740065349595315U;
            aOrbiterH = RotL64((aOrbiterH * 10918975496337269197U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10575473798991451167U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8267005776169272822U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13166868678285963961U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6249698995716039231U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13808085811784323978U;
            aOrbiterF = RotL64((aOrbiterF * 3897731011582061983U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2739364646624876985U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 77518479758428414U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 6977724811175035551U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterF, 5U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 43U) + aOrbiterK) + RotL64(aOrbiterI, 13U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterI, 34U)) + aOrbiterC) + aNonceWordD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 36U)) + aOrbiterB) + aPhaseEWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 23U)) + aOrbiterG) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 9675U)) & S_BLOCK1], 3U) ^ RotL64(aInvestLaneC[((aIndex + 9831U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 5543U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneC[((aIndex + 8305U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9553U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10460U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 8330U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 58U) + RotL64(aCarry, 13U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 43U)) + 6521330037475130256U;
            aOrbiterG = (((aWandererK + RotL64(aScatter, 39U)) + 12611880456055428940U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 41U)) + 12061611078130934708U) + aPhaseEOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 54U)) + RotL64(aCarry, 11U)) + 1558112410801116984U;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 13U)) + 10509115227850160786U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 57U)) + 4045915960688792066U;
            aOrbiterC = (aWandererI + RotL64(aCross, 51U)) + 1196541286513243082U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 29U)) + 15564991032722373702U;
            aOrbiterB = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 4897765238703641798U) + aNonceWordA;
            aOrbiterI = (aWandererG + RotL64(aScatter, 5U)) + 12327429514907752733U;
            aOrbiterF = (aWandererH + RotL64(aCross, 60U)) + 6189189797708711636U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6374267075282018852U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 1888758503831341439U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 74387714918264257U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14956857689299491800U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14879361107223331957U;
            aOrbiterA = RotL64((aOrbiterA * 9166712966729591953U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16086885494838105042U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8069724185844303923U;
            aOrbiterD = RotL64((aOrbiterD * 8878470736758734353U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10854345917959911439U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7078313614360332089U;
            aOrbiterH = RotL64((aOrbiterH * 9864025732292844871U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 15083669236062255011U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 594879695916679116U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 9852515479152735283U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6721466068234534523U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 475816724162626782U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 4799725182757588407U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4341655358154605899U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15477254302340298586U;
            aOrbiterG = RotL64((aOrbiterG * 13961520225881974201U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10179091913200895775U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6310490897546909571U;
            aOrbiterF = RotL64((aOrbiterF * 15080621088825477613U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13462682513035460711U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16739138858084100385U;
            aOrbiterJ = RotL64((aOrbiterJ * 16386371811268298031U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13608837667062268989U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12902415667552110103U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16398790854093048017U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16596211634603915761U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6521330037475130256U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 631958426544321145U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 5U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 11U)) + aOrbiterK) + aNonceWordM);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 60U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 13U)) + aOrbiterD) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterE, 34U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13040U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 15161U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11104U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14017U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12127U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 50U) + RotL64(aCross, 3U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = (aWandererH + RotL64(aPrevious, 21U)) + 6467297102954816305U;
            aOrbiterD = (aWandererC + RotL64(aCross, 27U)) + 7921154109831114952U;
            aOrbiterE = ((((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 5701131763215638919U) + aPhaseEOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 12U)) + RotL64(aCarry, 3U)) + 10022999076719002684U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 4367135243038982316U) + aPhaseEOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 14445846824810383592U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 51U)) + 7683697954545773253U) + aNonceWordI;
            aOrbiterB = (aWandererI + RotL64(aScatter, 41U)) + 17517006750428030899U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 18U)) + 2052484792684025476U) + aNonceWordB;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 35U)) + 6279463052085808926U) + aNonceWordO;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 5U)) + 679280153651813684U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2939516520188460569U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1960616434964712325U;
            aOrbiterE = RotL64((aOrbiterE * 15145998415466343039U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12273819390719947361U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5685033154709449397U;
            aOrbiterH = RotL64((aOrbiterH * 9845666295874714959U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9314494172199500653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15757631834636427621U;
            aOrbiterA = RotL64((aOrbiterA * 15483543888965744529U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10878078046389399574U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3583495913766365232U;
            aOrbiterC = RotL64((aOrbiterC * 2913540984990155225U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7385544065754622301U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16839599460207922881U;
            aOrbiterD = RotL64((aOrbiterD * 240651605910592561U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13038163804940349251U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2587538594933924000U;
            aOrbiterI = RotL64((aOrbiterI * 3091149760401278671U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13109518583364738004U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2447689055742474261U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 12100180201235703193U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5752044906692668618U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 6637725371036522120U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6021986525167161115U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 16549229877442298618U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12825651879441561108U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9079931351967033993U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 16088338999978085987U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12584648360998154782U;
            aOrbiterG = RotL64((aOrbiterG * 2109996837220975261U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7526256599938771686U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 6467297102954816305U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 9289442676936248653U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 30U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 10U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterB, 11U)) + aNonceWordP);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterA, 43U)) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 19U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 34U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterD) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 42U) + aOrbiterJ) + RotL64(aOrbiterC, 51U)) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            aWandererF = aWandererF + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19663U)) & S_BLOCK1], 30U) ^ RotL64(aSnowLaneA[((aIndex + 20531U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 18336U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21630U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((aIndex + 21746U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererI + RotL64(aScatter, 37U)) + 4739486756133131180U) + aNonceWordI;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 10U)) + 16089707555501328184U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 15310047330238536453U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 7901411596386834955U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 41U)) + 4357555491060982163U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 3U)) + 15667085602825720102U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = (aWandererH + RotL64(aIngress, 35U)) + 8520635334382269253U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 44U)) + 1772509779231068315U) + aNonceWordO;
            aOrbiterH = (aWandererG + RotL64(aScatter, 29U)) + 15336170957886025677U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 13U)) + 8628770833489469980U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 15469234024247246228U) + aNonceWordL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10796430900884288328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10660110397012853289U;
            aOrbiterI = RotL64((aOrbiterI * 9140007610912037461U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11202284258711214794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17509491802893182994U;
            aOrbiterG = RotL64((aOrbiterG * 9329107599972703671U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16212572740740103554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2190030203761579226U;
            aOrbiterK = RotL64((aOrbiterK * 3101886685668871045U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12014337082293041909U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3733531010807001506U;
            aOrbiterB = RotL64((aOrbiterB * 5797362244066062299U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 7100994963061975529U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 17837541162838600258U;
            aOrbiterC = RotL64((aOrbiterC * 8745987361678166553U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3311518938023146951U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7709505172646831553U;
            aOrbiterJ = RotL64((aOrbiterJ * 7121143171245765213U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4979968094554018443U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16822214821463034107U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8618262120451291765U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8376124175020587079U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 11084586282092424876U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5835632742522563537U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7816368455027681621U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10893292019060642422U;
            aOrbiterH = RotL64((aOrbiterH * 3995821210667317677U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 13602875505184178486U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5425735673005681983U;
            aOrbiterA = RotL64((aOrbiterA * 12667085597129312079U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 5995385043278810987U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4739486756133131180U;
            aOrbiterF = RotL64((aOrbiterF * 15709273328685013399U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterC, 42U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterH, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 27U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterA, 13U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterG, 37U)) + aPhaseEWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterC, 44U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterD, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24648U)) & S_BLOCK1], 48U) ^ RotL64(aSnowLaneB[((aIndex + 23666U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 26485U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23483U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 27293U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 11U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 14624277139785904404U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 47U)) + 6966977309498165611U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 41U)) + 205536824352530761U) + aNonceWordG;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 16629575265808255692U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 39U)) + 596881340147972746U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 27U)) + 11944412799107412650U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererC + RotL64(aCross, 13U)) + 4615021315668210206U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 35U)) + 8497630055977606216U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 53U)) + 11131601107309336885U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 50U)) + 5935883479805510099U) + aNonceWordI;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 43U)) + 15629346719765798174U) + aPhaseEOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5279128339113651273U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16778365912440331821U;
            aOrbiterB = RotL64((aOrbiterB * 705421028266789241U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 16003052937645491524U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 6723226158737614764U;
            aOrbiterF = RotL64((aOrbiterF * 16690657664909260573U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9785784358981219543U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10055457337292292710U;
            aOrbiterD = RotL64((aOrbiterD * 17919129940751761111U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11779163108592974175U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1177999477942202687U;
            aOrbiterG = RotL64((aOrbiterG * 13475069421684114643U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 9190694445141492214U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15605342360346353457U;
            aOrbiterE = RotL64((aOrbiterE * 14547769706392595647U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14877565450677523492U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1074095623308025684U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 7884068939436891093U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12803174154216941583U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8813356463693637033U;
            aOrbiterH = RotL64((aOrbiterH * 4898237214617563167U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6063909634038581414U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15112191502834052566U) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 6780741782103553485U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13926459034757240311U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4324555954703597591U;
            aOrbiterC = RotL64((aOrbiterC * 18068922072149745351U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7183063131331255506U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18072787091203847052U;
            aOrbiterI = RotL64((aOrbiterI * 12530396154012878153U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10143386327707219710U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14624277139785904404U;
            aOrbiterK = RotL64((aOrbiterK * 12100828883424264587U), 19U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (RotL64(aOrbiterF, 28U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 11U)) + aPhaseEWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterE, 37U));
            aWandererE = aWandererE + (((RotL64(aIngress, 51U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterI, 60U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 13U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 29U)) + aOrbiterB);
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + RotL64(aOrbiterG, 46U)) + aOrbiterD) + aNonceWordA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 38U) + aOrbiterD) + RotL64(aOrbiterI, 21U));
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 31663U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 31354U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 28032U)) & S_BLOCK1], 20U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29093U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 30330U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 26U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 58U)) + 439898681482066326U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 39U)) + 17362083676671776094U) + aNonceWordO;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 6418499837265155024U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 43U)) + 17262244253027454972U;
            aOrbiterH = (aWandererF + RotL64(aCross, 53U)) + 2382066162993139503U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 29U)) + 14345808395587174135U;
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 7534743166385552851U) + aPhaseEOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 16994453324688523966U) + aNonceWordD;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 37U)) + 7079553728544045092U) + aNonceWordE;
            aOrbiterC = (aWandererI + RotL64(aIngress, 3U)) + 3562822704508440641U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 46U)) + 13990892681975857821U) + aPhaseEOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 1796728922368577238U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6605161260520067178U;
            aOrbiterA = RotL64((aOrbiterA * 8147537646591674091U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13994083795942328918U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6144523182899107711U;
            aOrbiterH = RotL64((aOrbiterH * 4153879991344611283U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12247462325297436642U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1065809332002012789U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 5496601177032953251U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 10147919864511540753U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17138553441127273354U;
            aOrbiterJ = RotL64((aOrbiterJ * 5773875596275267871U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 2653924016109573974U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6254416952351699582U;
            aOrbiterD = RotL64((aOrbiterD * 12756861659704947257U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 813046408080197079U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 9624466135414123483U;
            aOrbiterI = RotL64((aOrbiterI * 6960320253124395015U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 972586705850825744U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 155283774901960223U;
            aOrbiterB = RotL64((aOrbiterB * 9928051687724257041U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 18200100644751360406U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1168426822045686004U;
            aOrbiterC = RotL64((aOrbiterC * 5867027156069481313U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2271564377169233643U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1896317305868283986U;
            aOrbiterF = RotL64((aOrbiterF * 8080751157990019287U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 10209708407397294552U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 947585551223387294U;
            aOrbiterG = RotL64((aOrbiterG * 15339472308062247067U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12313594490465462211U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 439898681482066326U;
            aOrbiterK = RotL64((aOrbiterK * 12336632799055203705U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 43U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aPhaseEWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 18U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterI, 21U));
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 43U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterC, 29U)) + aOrbiterF);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterD, 47U)) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterF, 4U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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

void TwistExpander_FootBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC4A292779450FCAFULL + 0xAF85A967E75635FAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAC26FD6654256935ULL + 0x96F3BB184F6BC0DDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x892F611BFBF2C5AFULL + 0x90D532EB0915D046ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDD372E0F1EE6B313ULL + 0xDA9118C763544E95ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x932DF4883FCE863DULL + 0xD8D0D91C767686CDULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xCA8FE66F13C569DFULL + 0xCDE3B461E8EC72B3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCF6BF3B0C68527C5ULL + 0xA144E7B4944F3CE9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9C33DE6326089413ULL + 0x879BE251B6D844DFULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC7693D78CBDF7F79ULL + 0xBC73E7C23034D6E8ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD5270FEBE65940CBULL + 0xC7916D2B513B6EA8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD7CFF70A5A103447ULL + 0xA9099AA05CCB9D92ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8A0631E0395E3DADULL + 0xD46FEE03682B57E3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDB29AB42EAD5EB25ULL + 0x9578EFF87D26D2B3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9BB245F292DE40E7ULL + 0xC12D042419D10EF0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x861DFC4966D75F71ULL + 0xCAB5085CB816D2A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9C30984345861ABBULL + 0xD0CAA6ABC6110FCFULL);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1078U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((aIndex + 506U)) & S_BLOCK1], 4U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 2796U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2552U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1719U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 199U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 57U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 26U)) + RotL64(aCarry, 35U)) + 11039986441331892533U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 47U)) + 6256024955965426119U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 57U)) + 9857443189988995666U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 11900944813380998208U) + aNonceWordP;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 36U)) + 8422577734978875541U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aScatter, 19U)) + 3100835100713928724U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 13U)) + 11871553509810206993U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 17614749493763417027U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 41U)) + 3638372131856199916U) + aNonceWordL;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6582275259281025770U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17016882418498941958U;
            aOrbiterK = RotL64((aOrbiterK * 4269869255230867823U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1747214688658984715U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9356088987044015278U;
            aOrbiterC = RotL64((aOrbiterC * 16221733545319753695U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 4056238112133473456U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16013150119949532998U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 12913648646318115315U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16076621211111834889U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9940824359571581765U;
            aOrbiterI = RotL64((aOrbiterI * 11624767861336495331U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15624084004784515753U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7630989544834680335U;
            aOrbiterE = RotL64((aOrbiterE * 12261063237156822067U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18003586430673313786U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1654118743290334161U;
            aOrbiterA = RotL64((aOrbiterA * 1153250137357176071U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3254189676528343910U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15629083361573065165U;
            aOrbiterF = RotL64((aOrbiterF * 17024833368570949107U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 10056859810555674806U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15976683222786846254U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 2801754232182942635U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 11872378594829637933U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7633773773528713489U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8218288492011593353U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 39U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 53U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterB, 28U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 23U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererE = aWandererE + ((RotL64(aCross, 48U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterB, 12U)) + aNonceWordM) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10545U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((aIndex + 5713U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 6842U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 8586U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7905U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9127U)) & S_BLOCK1], 52U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 9961U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 36U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterE = ((((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 9774364261626083532U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererK + RotL64(aIngress, 47U)) + 18059001521926116420U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 53U)) + 10615626210406381148U) + aPhaseFOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 34U)) + 10536484278007898620U) + aNonceWordA;
            aOrbiterB = (aWandererG + RotL64(aIngress, 19U)) + 13320663045139972700U;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 17127001787268166583U) + aNonceWordN;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 3U)) + 16742574590844166551U;
            aOrbiterC = (aWandererA + RotL64(aCross, 27U)) + 8347719720758228053U;
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 58U)) + RotL64(aCarry, 13U)) + 13502468705946051986U) + aNonceWordG;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3512687886188904904U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 495660316165795934U;
            aOrbiterG = RotL64((aOrbiterG * 6724596801190194913U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 5092722552034477356U) + aNonceWordH;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 15641128019608284015U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 3621036395703527059U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15421873776811085458U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 17978775513204574125U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18359600395119440183U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16617179197537669849U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 1931805387534012528U;
            aOrbiterE = RotL64((aOrbiterE * 3400139345857733775U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9544923119559308431U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12930999400470173353U;
            aOrbiterB = RotL64((aOrbiterB * 16791006919271490005U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13673733276226249890U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2032263473309124738U;
            aOrbiterK = RotL64((aOrbiterK * 3088728329261360607U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14868502349358414206U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 10116495537187552321U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 1380512121796709469U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5341113995358179244U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8415417980279705731U;
            aOrbiterI = RotL64((aOrbiterI * 8521501372683793821U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2462819265072352463U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 7657062767608441931U;
            aOrbiterC = RotL64((aOrbiterC * 15554638801273540163U), 39U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + aNonceWordD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterF, 10U)) + aOrbiterG) + aNonceWordK);
            aWandererK = aWandererK + (((RotL64(aScatter, 43U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 53U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterI, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 40U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 34U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15727U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 12221U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13137U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 12133U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 14828U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 22U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 4739486756133131180U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 16089707555501328184U;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 18U)) + RotL64(aCarry, 37U)) + 15310047330238536453U) + aNonceWordJ;
            aOrbiterG = ((aWandererD + RotL64(aIngress, 43U)) + 7901411596386834955U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aScatter, 5U)) + 4357555491060982163U;
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 35U)) + 15667085602825720102U) + aPhaseFOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aWandererA + RotL64(aCross, 28U)) + 8520635334382269253U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 39U)) + 1772509779231068315U;
            aOrbiterB = (aWandererI + RotL64(aCross, 13U)) + 15336170957886025677U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8628770833489469980U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15469234024247246228U;
            aOrbiterH = RotL64((aOrbiterH * 8905266995119987947U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 10796430900884288328U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 10660110397012853289U;
            aOrbiterJ = RotL64((aOrbiterJ * 9140007610912037461U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11202284258711214794U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17509491802893182994U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9329107599972703671U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16212572740740103554U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2190030203761579226U;
            aOrbiterK = RotL64((aOrbiterK * 3101886685668871045U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12014337082293041909U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3733531010807001506U;
            aOrbiterD = RotL64((aOrbiterD * 5797362244066062299U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 7100994963061975529U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 17837541162838600258U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8745987361678166553U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3311518938023146951U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7709505172646831553U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7121143171245765213U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4979968094554018443U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 16822214821463034107U;
            aOrbiterG = RotL64((aOrbiterG * 8618262120451291765U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8376124175020587079U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 11084586282092424876U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5835632742522563537U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aCross, 38U) + RotL64(aOrbiterH, 10U)) + aOrbiterJ) + aNonceWordF) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterE, 6U)) + RotL64(aCarry, 35U)) + aNonceWordL);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 51U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 57U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19599U)) & S_BLOCK1], 24U) ^ RotL64(aSnowLaneA[((aIndex + 21553U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17212U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 16727U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21008U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aIngress, 54U)) + (RotL64(aPrevious, 3U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = ((aWandererH + RotL64(aScatter, 60U)) + 15920462086654025436U) + aNonceWordD;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 13U)) + 487844076858004017U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 47U)) + 14502883786442630566U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aIngress, 35U)) + 3787107318658233674U) + aNonceWordF;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 39U)) + 12548777544693755491U) + aPhaseFOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 4907309444075181683U;
            aOrbiterD = (aWandererD + RotL64(aCross, 27U)) + 18342396700266492072U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 56U)) + RotL64(aCarry, 21U)) + 13503051997624242670U;
            aOrbiterH = (aWandererF + RotL64(aCross, 43U)) + 17845742460521374571U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8640887211877858169U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5273913123709097537U) ^ aNonceWordK;
            aOrbiterA = RotL64((aOrbiterA * 1661149444148461791U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 17756844173695563883U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6713055830729302951U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2832836748513174311U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5106468334224035972U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10228769728713526172U;
            aOrbiterD = RotL64((aOrbiterD * 9760310686414358435U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 7687649520668883142U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7757480627354711605U;
            aOrbiterF = RotL64((aOrbiterF * 7222553727737349209U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10876291698508634557U) + aNonceWordP;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8149278085586014186U;
            aOrbiterH = RotL64((aOrbiterH * 8577133863470695381U), 47U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 15592893988925610485U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8639028256640537165U;
            aOrbiterJ = RotL64((aOrbiterJ * 1880655276432963955U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 475660347892196219U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1903736092401853832U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8486318978769094799U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12463250192809450953U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7253918448601703982U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 3821034106528009129U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5171661020093804486U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11627344933828324146U;
            aOrbiterE = RotL64((aOrbiterE * 5388047063152043277U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 42U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 29U)) + aOrbiterA) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterF, 52U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 57U)) + aOrbiterD) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + aNonceWordO);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 48U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 39U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24351U)) & S_BLOCK1], 6U) ^ RotL64(aSnowLaneB[((aIndex + 26740U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 26377U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22736U)) & S_BLOCK1], 58U) ^ RotL64(aSnowLaneA[((aIndex + 24303U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterI = (aWandererA + RotL64(aCross, 43U)) + 7632760812370906911U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 35U)) + 6007174525479723089U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 5U)) + 3362829642521821048U) + aNonceWordA;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 58U)) + 18009548556107978286U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterJ = ((((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 17880909432272697327U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 15961567935420752568U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 39U)) + 10136559064656837921U) + aNonceWordM;
            aOrbiterC = ((aWandererD + RotL64(aCross, 20U)) + RotL64(aCarry, 19U)) + 17622019364405410277U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 13U)) + 6927494824421416306U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7125170407794874847U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 12342273503071032250U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 867417849555857179U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 14997696377476124836U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14874498694181230698U;
            aOrbiterK = RotL64((aOrbiterK * 4026127545746010937U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2549397729130885686U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4217995818662767955U;
            aOrbiterD = RotL64((aOrbiterD * 5525525344485251063U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4706089044415442525U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17983900172670031015U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 541552737180932879U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1904937798143929988U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 10620877287033139483U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 16711012562024287213U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 15681091173163181525U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2655543246639000084U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16686375598149755947U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2647895110857289213U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5581609212017175954U;
            aOrbiterC = RotL64((aOrbiterC * 15330263616699031311U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 13609076329627787987U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6244266279516622070U;
            aOrbiterJ = RotL64((aOrbiterJ * 12488345779236971095U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5289624364508923581U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16351476803965903112U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 9012522724650442597U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterK, 56U)) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 20U) + aOrbiterC) + RotL64(aOrbiterA, 37U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 3U)) + aOrbiterJ) + aNonceWordI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterD) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterK, 46U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterJ, 19U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 40U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29578U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 27808U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 28180U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31145U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28147U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterE = (aWandererF + RotL64(aScatter, 19U)) + 16519040829220310189U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 6888002778416941825U) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 40U)) + 1310832187746534025U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 5890888009051281674U) + aNonceWordG;
            aOrbiterD = (aWandererK + RotL64(aCross, 35U)) + 5143864838362464857U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 29U)) + 15591534069452660003U) + aPhaseFOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 53U)) + 1466867671765325096U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 13931443680107902488U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 44U)) + 15400747367673245552U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2836975369734495759U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2370720358274970117U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4615571902817575375U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3470677184188006133U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 7175584278499266723U;
            aOrbiterD = RotL64((aOrbiterD * 10067096593682482345U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6095078817776863055U) + aNonceWordL;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2176637999243513070U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12215701810843975501U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5580391239754903129U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 15196125567953871184U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12686361960729564519U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12787014151503209931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1523153207064063495U;
            aOrbiterJ = RotL64((aOrbiterJ * 3113907543551927561U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12973289026485937829U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9087439766232078173U;
            aOrbiterB = RotL64((aOrbiterB * 5817029335999350327U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16318022893068674015U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11089160685103562409U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 17087834321385147603U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8680037953925067235U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3112588943274158119U;
            aOrbiterH = RotL64((aOrbiterH * 9214011370307670371U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16749015684369649821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9419550535891334966U;
            aOrbiterE = RotL64((aOrbiterE * 5421312787569114811U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 28U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterC, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 27U)) + aOrbiterB) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 58U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterK, 35U)) + aOrbiterA) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aIngress, 24U) + RotL64(aOrbiterB, 41U)) + aOrbiterH) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_FootBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xAD4D44C312C2CDC3ULL + 0xC4477289F6B5A673ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8A0030B07BC44787ULL + 0xD1F26C86F4420807ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAFEC4B956FF600EDULL + 0x9A1A76FF8D917645ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8599B16A2C33877BULL + 0xBD1DDE956389A7BCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x99EB5211687741B7ULL + 0x9A3512DE1BF95115ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x82B41408201AB2E3ULL + 0xF3C660FCC73843D1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF82380E36D613491ULL + 0xD228352E7922B0ABULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE4503D6F18280917ULL + 0xC8ED82ECACE4E70FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA8BC50247FC2B78DULL + 0xE59374D858C1D264ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xC18559B81CBA5725ULL + 0xD63CAC272161037CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xABB45B545B0EDB31ULL + 0x9934DD16E142E38DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE2C626F35DBB152DULL + 0xE4DBA2B4D169B5D6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF39368281E1D2C5BULL + 0xB28A1B31CD44C76FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x87B4D839F21ACA71ULL + 0xEC866F28C470AA51ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBC531C91FFF24FA9ULL + 0x8AE1DEDEDC572084ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xBC1BCE424D985885ULL + 0xC96E173DA3C4E744ULL);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 1512U)) & S_BLOCK1], 28U) ^ RotL64(aSnowLaneB[((aIndex + 5122U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 4119U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 4207U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 3607U)) & S_BLOCK1], 48U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 2174U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterD = ((aWandererA + RotL64(aCross, 44U)) + RotL64(aCarry, 27U)) + 1042610313571524121U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 3505725321008825582U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 12584654563843782991U) + aNonceWordC;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 51U)) + 6645399144515770935U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 29U)) + 3608978423753715584U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 5U)) + 8089198857670370983U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 57U)) + 15207251813516399879U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 9579268660105824516U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16055044469473802812U;
            aOrbiterG = RotL64((aOrbiterG * 2269649280637188723U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 583811872609805949U) + aNonceWordJ;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 7027491967970873942U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12686754713465826139U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 18256061823189677508U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12708429127816136937U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 12593886633108075321U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12169216645156306078U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12694325407567795065U;
            aOrbiterA = RotL64((aOrbiterA * 3711789483877261899U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16109994660203297503U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4234704064165718913U;
            aOrbiterC = RotL64((aOrbiterC * 730085881474787681U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14119541943554602878U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 8777769004811352951U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2556957257736134223U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 15642663488392549609U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11594468530833278624U;
            aOrbiterE = RotL64((aOrbiterE * 6639306656361601143U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterH, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 42U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + aNonceWordO) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterI, 11U)) + aOrbiterC);
            aWandererC = aWandererC + (((((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + RotL64(aCarry, 53U)) + aNonceWordN) + aPhaseHWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 19U)) + aOrbiterC) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 10U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10452U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneC[((aIndex + 10467U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 7095U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 6724U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 6967U)) & S_BLOCK1], 41U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 7536U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 5521U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 6U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 27U)) + 14823268998003220191U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 19U)) + 15295237288788213847U) + aNonceWordK;
            aOrbiterD = (((aWandererD + RotL64(aCross, 47U)) + 16434853402001133899U) + aPhaseHOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 7555911304407871631U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aIngress, 13U)) + 14977248264994834620U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 28U)) + 9707764144919392380U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 1277304385464681529U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 3089786220465849395U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 3700503853358695085U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2079089949442685421U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 3240054112993517371U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16897532076915366859U;
            aOrbiterE = RotL64((aOrbiterE * 4120874717534309035U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 18167359289798364307U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 8870819278575769863U;
            aOrbiterJ = RotL64((aOrbiterJ * 9334066154398059075U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15363069206212330251U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14858164441499725158U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 14931933411393847915U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5357144808788707522U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2910681277417754860U;
            aOrbiterI = RotL64((aOrbiterI * 13170868582159347059U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9824408699018165151U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 368370224788793300U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 14358982366258729959U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7095398304588825115U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11418879758164313554U;
            aOrbiterH = RotL64((aOrbiterH * 5983520332639771791U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 20U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterE, 47U)) + aNonceWordA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 22U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + aNonceWordJ) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererG = aWandererG + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 15593U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneA[((aIndex + 13212U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15451U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11786U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((aIndex + 16095U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 35U)) + (RotL64(aIngress, 21U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 13U)) + 13714409587461539863U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 26U)) + 14101156723903265839U) + aNonceWordN;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 7063754562895369001U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 57U)) + 12320578575245519386U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = ((aWandererE + RotL64(aCross, 5U)) + 11744826789631008424U) + aNonceWordA;
            aOrbiterC = (aWandererD + RotL64(aIngress, 51U)) + 8744816505096675597U;
            aOrbiterB = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 57U)) + 10405435520084528645U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1463157688070683543U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12379603577919617703U;
            aOrbiterE = RotL64((aOrbiterE * 14858901470015109311U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 1343439118031348146U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16118850268070235540U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 11184386483735388257U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14116264435819277136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5251698273012432109U;
            aOrbiterB = RotL64((aOrbiterB * 1495818611622063967U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14806408656041403829U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 11569345414052398227U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 9913158908301414861U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17063874769147888574U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9927420478679581917U;
            aOrbiterD = RotL64((aOrbiterD * 9042782809534196563U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2550285599827162167U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 17801534123304996448U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 2160836889363614721U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6456685241021762041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17064208177372969289U;
            aOrbiterG = RotL64((aOrbiterG * 13726627607233302493U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 19U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aNonceWordH) + aPhaseHWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 34U)) + aOrbiterC) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20642U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 18172U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17039U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20464U)) & S_BLOCK1], 44U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 20646U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 56U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 60U)) + 12809562813316740345U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 17084212535326321199U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aScatter, 41U)) + 16074921689983846769U) + aNonceWordP;
            aOrbiterF = ((aWandererA + RotL64(aCross, 21U)) + 14027986153007120145U) + aNonceWordB;
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 7633455951809250227U) + aNonceWordN;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 340989348513370174U;
            aOrbiterA = (aWandererH + RotL64(aCross, 35U)) + 5307820377645020116U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5605285015771527274U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5293500434746182790U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17674669610895537063U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7263156475892261811U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10672879570907433005U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2506338667179450741U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16659226780900986107U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9774892622769850665U;
            aOrbiterI = RotL64((aOrbiterI * 7487477727543183211U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10728057184108279042U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5032485856947407217U;
            aOrbiterE = RotL64((aOrbiterE * 16651577903809154285U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14642241075374862345U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8386481273395203518U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11649977733867003445U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2874153265304098104U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 11519900149177261000U) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 2010158758971864505U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8885690878540115768U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterB) ^ 4482143389870987714U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 7105332459437434281U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 20U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 14U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 23U) + RotL64(aOrbiterG, 13U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + aPhaseHWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 39U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 48U)) + aOrbiterF) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23823U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneB[((aIndex + 24740U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 25556U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27116U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 24479U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 35U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 11480359716598965890U) + aNonceWordG;
            aOrbiterB = ((aWandererC + RotL64(aCross, 57U)) + 15431182525482873419U) + aPhaseHOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 22U)) + RotL64(aCarry, 27U)) + 11360504974812776707U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 11U)) + 9292576416573382769U) + aNonceWordH;
            aOrbiterE = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 1549257414531028975U) + aNonceWordI;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 51U)) + 5347769463033129317U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 41U)) + 17019199177478377234U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 16558106007323125094U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 3976182233825939422U;
            aOrbiterK = RotL64((aOrbiterK * 4392162052317572289U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 2889047161195954395U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2241831345026962605U;
            aOrbiterB = RotL64((aOrbiterB * 5757458560979927857U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12850802412140579294U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13541744735436450160U;
            aOrbiterE = RotL64((aOrbiterE * 906089290000537439U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2085863085516538212U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2969034221711544086U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7768528124408400403U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6482666944512391472U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16969153556875844613U;
            aOrbiterF = RotL64((aOrbiterF * 9483462388353216219U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 5161314086757363678U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7150282484670673211U;
            aOrbiterA = RotL64((aOrbiterA * 8522427002337918663U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 5465304381272305847U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 2344610773390354017U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17010258514288089191U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 14U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterI, 20U)) + RotL64(aCarry, 13U)) + aNonceWordJ);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterB, 41U)) + aPhaseHWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + aNonceWordM) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 12U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 50U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 31195U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 31235U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 31349U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29019U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneB[((aIndex + 32760U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 18U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterJ = (aWandererG + RotL64(aCross, 57U)) + 12775735908960052604U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 13U)) + 11791373812080296887U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = (aWandererH + RotL64(aScatter, 51U)) + 5537362877706057303U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 2023912048504189380U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 19U)) + 17668828109963766893U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 558908629933941224U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 23U)) + 1479633119685446888U) + aNonceWordK;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15460320397843364063U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10059749397555469054U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8671817118586065469U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9987633811929693924U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10087337844580228269U;
            aOrbiterJ = RotL64((aOrbiterJ * 13817142288940843815U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4446204415503364254U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15106063243302192717U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9430197906134676162U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1226048679997253363U;
            aOrbiterA = RotL64((aOrbiterA * 14247538885252664127U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10611580584157624739U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3137391249289641509U;
            aOrbiterF = RotL64((aOrbiterF * 5462682413239873181U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9327201928815412810U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7890659377013147073U) ^ aNonceWordI;
            aOrbiterB = RotL64((aOrbiterB * 13827717178378062047U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10675114832750356941U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 8804440385852327267U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterD = RotL64((aOrbiterD * 8520671775587260601U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 48U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 47U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 26U) + aOrbiterD) + RotL64(aOrbiterA, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 44U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordP) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 4U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_FootBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 2476U)) & W_KEY1], 10U) ^ RotL64(aKeyRowReadB[((aIndex + 248U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1902U)) & W_KEY1], 40U) ^ RotL64(mSource[((aIndex + 1497U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererA + RotL64(aPrevious, 47U)) + 2915859148137000694U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 20U)) + RotL64(aCarry, 27U)) + 210680583721444425U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 29U)) + 6668118118775650387U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 11U)) + 15794200818099010989U;
            aOrbiterG = (((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 6565076707062828369U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 16323164497808856719U;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 35U)) + 7965435318816716560U;
            aOrbiterK = (aWandererH + RotL64(aCross, 6U)) + 7390281030573369017U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 43U)) + 2269738866911824875U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9664014216039993873U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 18284857398028357633U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8402008251343393737U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 367667619795303009U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7935945060956274197U;
            aOrbiterD = RotL64((aOrbiterD * 5481786693511955209U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 16683666162337789540U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 10655658270998102390U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15231596813382239841U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8307037916581540297U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 3247742749860703524U;
            aOrbiterB = RotL64((aOrbiterB * 15052136713218656641U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10446792483683818139U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16374602929344972364U;
            aOrbiterK = RotL64((aOrbiterK * 12599903932725787599U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2411334498322777183U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1093701164116833765U;
            aOrbiterG = RotL64((aOrbiterG * 13129220206835381729U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17018480952982840635U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17348395690080029814U;
            aOrbiterH = RotL64((aOrbiterH * 6212591395713433257U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 16111252311283623152U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12776492920397785951U;
            aOrbiterI = RotL64((aOrbiterI * 6136009241593081821U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12214538600808144816U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10043377462096783363U;
            aOrbiterC = RotL64((aOrbiterC * 14639467375095185877U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 56U) + RotL64(aOrbiterK, 51U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterK, 5U)) + aPhaseAWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 28U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterE, 41U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 35U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 47U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 58U)) + aOrbiterI) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4299U)) & S_BLOCK1], 26U) ^ RotL64(aKeyRowReadA[((aIndex + 3572U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 4738U)) & W_KEY1], 44U) ^ RotL64(mSource[((aIndex + 4962U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 10U)) ^ (RotL64(aCarry, 29U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererE + RotL64(aIngress, 22U)) + RotL64(aCarry, 13U)) + 3105313968748067810U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 41U)) + 9977249451119627064U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 3U)) + 17941392803495349366U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 35U)) + 4279533326705471133U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 53U)) + 13983828966811580039U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 3983490984234810378U;
            aOrbiterC = (aWandererD + RotL64(aCross, 57U)) + 308786542215259956U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 26U)) + RotL64(aCarry, 21U)) + 8443607695364427037U;
            aOrbiterD = (aWandererC + RotL64(aCross, 47U)) + 14939626441464340668U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9350693577306121110U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1717071159396961752U;
            aOrbiterH = RotL64((aOrbiterH * 11062480662625054525U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15911765265202100610U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14898546272333182767U;
            aOrbiterK = RotL64((aOrbiterK * 2674900543810733067U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 3560903518513465868U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 5367062725726860234U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8521908836601319553U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15233321480618877327U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9288449812290126074U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6815298520404038519U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5504840529511585676U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6825598386801620046U;
            aOrbiterI = RotL64((aOrbiterI * 11666542445846250077U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6433024450721339470U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 97934156644929458U;
            aOrbiterE = RotL64((aOrbiterE * 8630530773006923215U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3260053604798744515U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16539416623243059076U;
            aOrbiterD = RotL64((aOrbiterD * 12199577351166064503U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9814290051339038920U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13280156404507444041U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15269010043398910061U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11853942590993546833U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13207869904312989977U;
            aOrbiterF = RotL64((aOrbiterF * 15503461937625795969U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 44U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterI, 46U));
            aWandererK = aWandererK + (((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 21U)) + aOrbiterE) + aPhaseAWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 57U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 53U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterD, 30U));
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aFireLaneB[((aIndex + 7409U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 5747U)) & W_KEY1], 3U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7046U)) & W_KEY1], 42U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7380U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 6503U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 23U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 47U)) + 5568146815535263910U) + aPhaseAOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aCross, 18U)) + RotL64(aCarry, 53U)) + 7736084960873834666U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 57U)) + 1336413621817562093U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 53U)) + 5218462026934984692U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 23U)) + 7048890985969555935U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 13415955213864702118U;
            aOrbiterB = (aWandererI + RotL64(aCross, 11U)) + 5657023257021528548U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 14338310943137497116U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 6U)) + 12305161641833950473U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14514226578370459131U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 12692904083266024340U;
            aOrbiterE = RotL64((aOrbiterE * 14800805065279908839U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11012959130001327964U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7106471380403489078U;
            aOrbiterF = RotL64((aOrbiterF * 515626559384817223U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 3718101961355280891U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 13364192077222322664U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6720867800318913440U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14497243926965866546U;
            aOrbiterH = RotL64((aOrbiterH * 13595058589060114653U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5789056168233262435U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14438482587495779937U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10593535547917767263U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 313917798940179945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15241845511889502917U;
            aOrbiterB = RotL64((aOrbiterB * 16483477103771326107U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3591957424821693032U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1559050939014453558U;
            aOrbiterD = RotL64((aOrbiterD * 17933346117866604725U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15340590914441451383U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5538037287390050110U;
            aOrbiterI = RotL64((aOrbiterI * 4082576643144951473U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4151270491894969214U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 263593701314144898U;
            aOrbiterJ = RotL64((aOrbiterJ * 10372046955804512457U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 53U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + aPhaseAWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterK, 24U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterH, 39U));
            aWandererB = aWandererB + ((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterD, 4U));
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aPhaseAWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 8605U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 8689U)) & W_KEY1], 50U));
            aIngress ^= (RotL64(mSource[((aIndex + 9980U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10275U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9549U)) & W_KEY1], 10U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9020U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 50U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aCross, 4U)) + RotL64(aCarry, 41U)) + 4384716820085860551U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 13U)) + 9715780315942116888U;
            aOrbiterI = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 15963520052789178632U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 51U)) + 14346700690686392938U;
            aOrbiterK = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 6005518012489966643U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 27U)) + 2506732930310252119U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 57U)) + 16782163084851775826U;
            aOrbiterB = (aWandererB + RotL64(aCross, 19U)) + 823673076571076303U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 42U)) + 1634084509064077736U) + aPhaseBOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1288134975466877686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2998220403162908444U;
            aOrbiterI = RotL64((aOrbiterI * 4321412662318298283U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 220430672180734911U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10223923547068528867U;
            aOrbiterD = RotL64((aOrbiterD * 12577370238343872139U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11696469696177647608U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6545430420379636963U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 79691451831797107U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8971444023498649419U;
            aOrbiterC = RotL64((aOrbiterC * 7148919880477390009U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5624403902454498793U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9468064161002030997U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8243560528100864595U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4619361544913629805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12682446273369750704U;
            aOrbiterF = RotL64((aOrbiterF * 10879074713156075641U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8728730962617599223U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9099675924074253030U;
            aOrbiterB = RotL64((aOrbiterB * 5525644236954497523U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3298303921318288541U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5953276499411658358U;
            aOrbiterA = RotL64((aOrbiterA * 10565471305001292693U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6725769507592688539U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1057277456510215817U;
            aOrbiterH = RotL64((aOrbiterH * 8269412198279297075U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + RotL64(aOrbiterE, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 57U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 30U) + aOrbiterB) + RotL64(aOrbiterC, 28U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterH) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + aPhaseBWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 11338U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 12087U)) & W_KEY1], 21U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11574U)) & W_KEY1], 13U) ^ RotL64(mSource[((aIndex + 10987U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 13051U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13210U)) & S_BLOCK1], 43U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 12002U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 6U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 53U)) + 2168513956284366370U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 39U)) + 10290361969974613111U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 28U)) + 15673836275828498050U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 16600540024145812236U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 9428052101528111892U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 5U)) + 12763657928312763377U) + aPhaseBOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 13U)) + 10751286982008662485U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 34U)) + RotL64(aCarry, 41U)) + 1708230173038057979U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 21U)) + 4011389705422783816U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11704428328093077714U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2055336619674699284U;
            aOrbiterC = RotL64((aOrbiterC * 6374289210096410907U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1870865272102705804U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3574214263751923179U;
            aOrbiterH = RotL64((aOrbiterH * 13132083406834413563U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 984611970726966186U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 15207945449947643672U;
            aOrbiterF = RotL64((aOrbiterF * 9539470161576639981U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4181398506373973169U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15222345431506025949U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6925143692628659467U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15023513452326240962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14965669361708810699U;
            aOrbiterD = RotL64((aOrbiterD * 587008860996713147U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7985755518735406360U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 225592097619240187U;
            aOrbiterJ = RotL64((aOrbiterJ * 2313509354133400439U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3659537916566939383U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17043668033610689611U;
            aOrbiterG = RotL64((aOrbiterG * 10797634709118100773U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 10217321522161675848U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8013663869536146842U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2293233079384777175U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13762445330867496042U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2692400019659269106U;
            aOrbiterB = RotL64((aOrbiterB * 167704184292219399U), 57U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 4U) + aOrbiterI) + RotL64(aOrbiterG, 56U)) + aPhaseBWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterD, 41U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 37U)) + aOrbiterC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + aOrbiterC) + RotL64(aOrbiterB, 60U));
            aWandererK = aWandererK + ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 51U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 48U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 16038U)) & S_BLOCK1], 22U) ^ RotL64(aFireLaneC[((aIndex + 15798U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14138U)) & W_KEY1], 3U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14084U)) & W_KEY1], 50U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14186U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 15455U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16041U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 60U)) + 16451272412693907816U) + aPhaseBOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 19U)) + 10099485419723255462U;
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 47U)) + RotL64(aCarry, 43U)) + 17668900099534923192U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 5497093724143181753U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 27U)) + 10354044773550071706U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 51U)) + 12728258851198019099U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 3U)) + 4144050505314242618U) + aPhaseBOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aCross, 56U)) + RotL64(aCarry, 27U)) + 14133805325480076530U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 39U)) + 308863673210602899U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11741180130160569753U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12926863156769180448U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9726030996091054939U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 211920854786494259U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13234608842479411078U;
            aOrbiterC = RotL64((aOrbiterC * 2556747209733759467U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9164711974854618892U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 6667377062281954219U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2603737166987437649U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4559040002406721850U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1749875480850675109U;
            aOrbiterB = RotL64((aOrbiterB * 15822640067349481089U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9555365165561936366U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 18289733999504213574U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14156217554673229429U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 8727162691639622461U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 291406782452963706U;
            aOrbiterE = RotL64((aOrbiterE * 8413500075082350243U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8294911802626492257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15853578397277298548U;
            aOrbiterF = RotL64((aOrbiterF * 13256191781365357747U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11535146194939658681U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2177540476748375661U;
            aOrbiterD = RotL64((aOrbiterD * 15791341922007841029U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2705306323728084136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17617871830709148043U;
            aOrbiterA = RotL64((aOrbiterA * 3449981219502809255U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 44U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 52U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 23U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterE, 27U));
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 57U)) + aOrbiterE);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 18U)) + aOrbiterB) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterI, 41U));
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterG, 36U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17610U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[((aIndex + 19035U)) & W_KEY1], 6U));
            aIngress ^= (RotL64(mSource[((aIndex + 17067U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((aIndex + 18825U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 18243U)) & W_KEY1], 35U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 17374U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16611U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aCross, 57U)) + 12046647397183218524U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 24U)) + 2760779375026461991U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 19U)) + 13735454443176855650U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 11U)) + 4370377000586647724U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 47U)) + 14566322384189969094U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 5056565959818422786U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 27U)) + 8795403810686579209U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 35U)) + 9625947666256011567U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 29U)) + 1703669290934254701U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6664070663184147951U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2104148316797553431U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12887842067180975983U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1197910004222596145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9922977170060903197U;
            aOrbiterI = RotL64((aOrbiterI * 13047828062605568603U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2048376210852567829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12568990647075931409U;
            aOrbiterH = RotL64((aOrbiterH * 9860242601194210927U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15026894775772902751U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3439447160137900629U;
            aOrbiterB = RotL64((aOrbiterB * 1813754963043785165U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6532671388552829796U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 17261098369835997661U;
            aOrbiterG = RotL64((aOrbiterG * 568292591215203521U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3171300991007459947U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 5935563269327662024U;
            aOrbiterC = RotL64((aOrbiterC * 11271790283157765003U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 14290941734320455612U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12371794745736518824U;
            aOrbiterA = RotL64((aOrbiterA * 12208762336145168647U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8782840145467637373U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4067525421190366741U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6671002797916227485U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11854812920571789853U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17564890418553131451U;
            aOrbiterD = RotL64((aOrbiterD * 16657184504366731805U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 36U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 6U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseCWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 38U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterK, 3U));
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterA, 42U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 48U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + aPhaseCWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 36U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 20189U)) & S_BLOCK1], 18U) ^ RotL64(mSource[((aIndex + 19856U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aWorkLaneA[((aIndex + 20315U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21448U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19598U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20668U)) & W_KEY1], 29U));
            aCross ^= (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20423U)) & S_BLOCK1], 6U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21826U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 21U) + RotL64(aIngress, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererA + RotL64(aIngress, 20U)) + 13481227414590594621U;
            aOrbiterE = (aWandererE + RotL64(aCross, 11U)) + 17425964381118918026U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 53U)) + 4792004356135956581U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 11926849936000639098U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 5U)) + 990697329347742142U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 9307721505373076588U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 34U)) + RotL64(aCarry, 3U)) + 17605732738841908719U) + aPhaseCOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 57U)) + 13110764518634187439U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 29U)) + 17970109897810645911U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10273133817644703654U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11239046688920468137U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5197802934333553327U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 8355821483275763145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15522151127786049345U;
            aOrbiterG = RotL64((aOrbiterG * 4844278537850520413U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5381663179722418112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9551368011768104906U;
            aOrbiterE = RotL64((aOrbiterE * 14202470972121732997U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16264476585232221270U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7721417776432288282U;
            aOrbiterJ = RotL64((aOrbiterJ * 10267770327791051869U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 339418090653475277U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3247926250495935511U;
            aOrbiterH = RotL64((aOrbiterH * 16824669543765729097U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3390560045236418590U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3894024951542543635U;
            aOrbiterD = RotL64((aOrbiterD * 10599637790900418767U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 3878539166189668154U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 5617705593218220843U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 82771190372750823U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12320861089148474544U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14943790251625519550U;
            aOrbiterF = RotL64((aOrbiterF * 13758322022902008313U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18119213517612562775U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1413193144229486646U;
            aOrbiterA = RotL64((aOrbiterA * 14562375280658115687U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 30U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterC, 26U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 18U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 30U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 56U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + aPhaseCWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 23194U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 23123U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23775U)) & W_KEY1], 26U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24543U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22121U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23563U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23843U)) & S_BLOCK1], 37U) ^ RotL64(aFireLaneD[((aIndex + 22941U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 51U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererG + RotL64(aScatter, 58U)) + RotL64(aCarry, 21U)) + 701291026547470433U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 11U)) + 17283292650462111643U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 9969124091931303406U;
            aOrbiterJ = (((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 889176772718046988U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aPrevious, 53U)) + 6054541844643748084U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 48U)) + 14703226235143028132U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 5U)) + 7977975878522921062U) + aPhaseCOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 27U)) + 16894322614172266274U;
            aOrbiterK = (aWandererB + RotL64(aCross, 23U)) + 12160451749345900570U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10870847008043897470U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8159920947172520247U;
            aOrbiterG = RotL64((aOrbiterG * 4833194641611011805U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2440099120969517932U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2428396147731468007U;
            aOrbiterD = RotL64((aOrbiterD * 9363073341539598441U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2213226274394673479U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7079731443427765333U;
            aOrbiterB = RotL64((aOrbiterB * 16918930776877030559U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 958896789550478970U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 10788682955708075458U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 913321215613559729U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2003386579317564870U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8419686358774204999U;
            aOrbiterJ = RotL64((aOrbiterJ * 6547052526438697621U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6989167615157578904U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17636634003643824148U;
            aOrbiterK = RotL64((aOrbiterK * 11038576417283732937U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13824962118933907859U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 9543912892587859646U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14736710162285997415U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 15729878041027706114U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9542137475454825463U;
            aOrbiterC = RotL64((aOrbiterC * 11420547128115090491U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5327302277575009955U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2707383132257428583U;
            aOrbiterF = RotL64((aOrbiterF * 6120763309390182129U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 58U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + RotL64(aCarry, 11U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 10U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + aOrbiterD) + RotL64(aOrbiterJ, 5U)) + aPhaseCWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 35U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 53U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 22U) + aOrbiterG) + RotL64(aOrbiterC, 18U)) + aPhaseCWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26394U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 26677U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aWorkLaneD[((aIndex + 25146U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 25078U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25044U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26154U)) & S_BLOCK1], 58U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26892U)) & S_BLOCK1], 21U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 25275U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 29U)) + 77518479758428414U) + aPhaseDOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 53U)) + 4832061802166300011U;
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 37U)) + 11695291171006574112U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 23U)) + 7467412817843260094U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 23U)) + 17801484124471154757U;
            aOrbiterB = (aWandererG + RotL64(aCross, 51U)) + 5555455638503958639U;
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 58U)) + 5669470540733721606U) + aPhaseDOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 35U)) + 3042388456327784163U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 43U)) + 2236734925228156691U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14459720401528685450U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 4814967631216658856U;
            aOrbiterH = RotL64((aOrbiterH * 18288097536171386643U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16950679344449075945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6262238639302011050U;
            aOrbiterB = RotL64((aOrbiterB * 9942659897425088183U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3522256359074996724U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12524717897707074242U;
            aOrbiterI = RotL64((aOrbiterI * 6787771338063891989U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13891759914865623828U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11910250571469028666U;
            aOrbiterD = RotL64((aOrbiterD * 12311343917878428995U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2240189915640314069U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5365912986308810837U;
            aOrbiterA = RotL64((aOrbiterA * 15133972552032469957U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9323732721344489753U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 13087326560957916553U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14659491687401151733U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16398238057564892809U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 11517870519285159224U;
            aOrbiterF = RotL64((aOrbiterF * 1501848878469712681U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 7758285512254776734U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17475149091906684720U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6015816725428299273U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2051631493975035243U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 11684740065349595315U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10918975496337269197U), 47U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 42U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 29U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterJ, 6U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 14U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + RotL64(aWandererA, 6U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28869U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 29332U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27738U)) & W_KEY1], 6U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27313U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 27717U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29456U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29459U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28858U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 3684295017013759987U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 13U)) + 6740408842457292881U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 4563975890702399441U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 60U)) + 797804144825287940U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aScatter, 53U)) + 2763779540450101303U;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 13211846164102089685U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aCross, 3U)) + 15214578447281401982U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 38U)) + 13745208628754232427U;
            aOrbiterD = (aWandererF + RotL64(aCross, 47U)) + 17358621225969190747U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 779739369960480023U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4370963533701407813U;
            aOrbiterK = RotL64((aOrbiterK * 3123135216876641039U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 6061333005507739975U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3589705340762734456U;
            aOrbiterE = RotL64((aOrbiterE * 16499293983611196967U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10607697666369230567U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9356757995305239271U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10945513661439954731U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10093033335903048138U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11037328061699834100U;
            aOrbiterA = RotL64((aOrbiterA * 11189760551792389605U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 558431161176115540U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17795680919453449358U;
            aOrbiterG = RotL64((aOrbiterG * 3910117359996283803U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6096779391116214109U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17594243286880690775U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12655610181937429915U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15414704802398002423U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 18040588240488602196U;
            aOrbiterB = RotL64((aOrbiterB * 16344249573086571225U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 14636298592697156931U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9677305688594936561U;
            aOrbiterF = RotL64((aOrbiterF * 8354776999961642997U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 16408025751875050713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10018342878801454965U;
            aOrbiterC = RotL64((aOrbiterC * 10349132962708124117U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 56U) + aOrbiterC) + RotL64(aOrbiterJ, 54U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 29U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 11U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterK, 19U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 6U)) + aOrbiterB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 20U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 31276U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadA[((aIndex + 32439U)) & W_KEY1], 51U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30468U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31805U)) & S_BLOCK1], 11U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31320U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 31236U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 60U)) + (RotL64(aCross, 29U) + RotL64(aIngress, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aPrevious, 48U)) + 3339283916456813609U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 11339086426180649584U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 16819191669329316585U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 43U)) + 8361916937762630725U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 19U)) + 18031328374429899857U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 52U)) + 18261756894092897276U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 29U)) + 4250319792907645666U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 1492411503643460886U;
            aOrbiterC = (aWandererG + RotL64(aCross, 11U)) + 17369549067879344180U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7301713524358676722U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2985193736033012535U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7473297294949338265U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 14086975808140927408U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 10390516547834639800U;
            aOrbiterA = RotL64((aOrbiterA * 11441293212275890819U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 18205555540941493267U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16967799565443938873U;
            aOrbiterE = RotL64((aOrbiterE * 3009081009044782443U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9209505304067579944U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3522631966146762306U;
            aOrbiterG = RotL64((aOrbiterG * 3441982898533162599U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 8811497120829041188U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14707301680850257294U;
            aOrbiterC = RotL64((aOrbiterC * 11383709499376464085U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10080595991787801029U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6822892187784299166U;
            aOrbiterI = RotL64((aOrbiterI * 7417016898027778287U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1981637172055758689U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16463077485583119324U;
            aOrbiterB = RotL64((aOrbiterB * 2876782050665869121U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8383837717361569465U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 2788511294985017326U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2809163242875130677U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3529607472855930041U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8850940802020173766U;
            aOrbiterJ = RotL64((aOrbiterJ * 7821450253655655943U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterF, 14U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 28U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 6U) + aOrbiterB) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 13U)) + aOrbiterG);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterB, 34U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 39U)) + aOrbiterH) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 22U);
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

void TwistExpander_FootBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2999U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 7459U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 6533U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4740U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 2212U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 718U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererI + RotL64(aScatter, 19U)) + 8367680518550579791U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 58U)) + 11491674725611181241U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aCross, 27U)) + 16673861720782164214U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 13U)) + 9786610124108350855U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 21U)) + 5745080601557577637U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 5U)) + 1959402215131684684U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 6121650036079196522U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12016309761037342392U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5986936646177049603U;
            aOrbiterJ = RotL64((aOrbiterJ * 3585650475703294895U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1000367700904043468U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17425288243569101032U;
            aOrbiterE = RotL64((aOrbiterE * 2174614006719048535U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4856917474950325209U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16312111093223166419U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 456110002032422270U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11393724374787795662U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1176984359123668389U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8378176867715697176U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 8086186452345234815U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8450438271765985235U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8470349167474173245U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2528229938740192694U;
            aOrbiterG = RotL64((aOrbiterG * 8717790851266520943U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13247168811545753141U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 8745293957516815264U;
            aOrbiterD = RotL64((aOrbiterD * 14270617180621072619U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterE, 44U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterE);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 50U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 11575U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 9003U)) & S_BLOCK1], 27U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 15502U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15456U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11300U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9519U)) & S_BLOCK1], 36U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 16086U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 19U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 6469584119078165548U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 29U)) + 14329756366517987910U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 28U)) + 12890831797059772123U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 57U)) + 3164503807500018990U;
            aOrbiterA = (aWandererC + RotL64(aCross, 5U)) + 177531431387646836U;
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 3167421392893561015U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aPrevious, 43U)) + 2813174781844753460U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10953270419153249857U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16911518309710356951U;
            aOrbiterH = RotL64((aOrbiterH * 13162785997686570445U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6616750447844893150U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10276741398025985982U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6824712685896987133U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6206043608461213208U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12021552904553405793U;
            aOrbiterI = RotL64((aOrbiterI * 10023362889960174909U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15283586234744144846U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 5923238786775948571U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8200882393521882651U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11044014510971660078U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9351141024085076044U;
            aOrbiterD = RotL64((aOrbiterD * 13316079344614432317U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17703395981862992420U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10154548848376027087U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12324478347590509035U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8836420852291617425U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10193385413543886344U;
            aOrbiterF = RotL64((aOrbiterF * 824935982418585449U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterA, 37U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 50U) + RotL64(aOrbiterA, 20U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23651U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneA[((aIndex + 19395U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aExpandLaneB[((aIndex + 22598U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 17303U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22969U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22037U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 24035U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 39U)) + (RotL64(aCross, 27U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 1393781663398437180U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 17414594746688585273U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 47U)) + 2823888497053071250U) + aPhaseEOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 11U)) + 17032631958617884859U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 29U)) + 15222697630461125019U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 35U)) + 15737414920751551780U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 20U)) + RotL64(aCarry, 13U)) + 1357196111055783001U) + aPhaseEOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5315122321649251691U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7893744655508595974U;
            aOrbiterI = RotL64((aOrbiterI * 17863000246694319149U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16721939414324611738U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 3444375866323610848U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10874157227815775661U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1825716513674511632U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15582066843912467318U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12765146555943757373U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15673590949193923915U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 13887365046280406413U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3169061375011420121U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 12730414371734709356U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4819112390640821927U;
            aOrbiterD = RotL64((aOrbiterD * 8782547948627685451U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3089925954422937464U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7180179304678622530U;
            aOrbiterG = RotL64((aOrbiterG * 16118051565147747413U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17030269962085008657U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6675917351883004046U;
            aOrbiterE = RotL64((aOrbiterE * 14134335325316949687U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 27U);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 39U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 13U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterG, 28U));
            aWandererK = aWandererK + (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 26479U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 26089U)) & S_BLOCK1], 41U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 26507U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneC[((aIndex + 28860U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29790U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29185U)) & S_BLOCK1], 42U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30008U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 42U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 12426357877879529292U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 39U)) + 12604900366173639176U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 5U)) + 13511119007338929401U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 13U)) + 9878720081166788060U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aIngress, 30U)) + RotL64(aCarry, 53U)) + 15463195409806395076U;
            aOrbiterK = (aWandererA + RotL64(aCross, 51U)) + 6407922778852833423U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 7690427254160734016U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 18030974031722143619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17983938038322737041U;
            aOrbiterG = RotL64((aOrbiterG * 12479365337221685413U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16605512170117753884U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 681802273302348322U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14608920184802647123U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15550312921312083819U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17824154101711884508U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7358612830654795357U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1939207786756735430U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3132864634777826569U;
            aOrbiterK = RotL64((aOrbiterK * 13606281919426730325U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12822929773923954849U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16576106045887115660U;
            aOrbiterJ = RotL64((aOrbiterJ * 16370914370769903051U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2398825881649235260U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13700821892926092479U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10830623703416956043U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2439833784883391606U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15870638514107637833U;
            aOrbiterE = RotL64((aOrbiterE * 3797380922767479287U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            aWandererC = aWandererC + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterJ, 28U)) + aPhaseEWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterJ, 3U)) + aPhaseEWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 47U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 50U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 53U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_FootBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1049U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneB[((aIndex + 4671U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 3980U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2063U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1930U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 6813U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 41U)) + (RotL64(aCross, 28U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererB + RotL64(aIngress, 6U)) + 2786079456995203065U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 39U)) + 7237256119153857253U;
            aOrbiterE = (aWandererI + RotL64(aCross, 37U)) + 9310834010563647604U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 57U)) + 17361734905706517877U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 15837111231884647451U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 35U)) + 18065431964418026445U;
            aOrbiterH = (aWandererA + RotL64(aCross, 4U)) + 3029123922999952652U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 5166926595573507837U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 51U)) + 1918425684273807598U;
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 4724551751012661440U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 47U)) + 1818014487579644390U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 6670090372241084216U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8485757110007268693U;
            aOrbiterE = RotL64((aOrbiterE * 11876760095108618363U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4928130251509514742U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2528788422725346792U;
            aOrbiterB = RotL64((aOrbiterB * 1855982047967756661U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2860387120895147503U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 12927802338151379368U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8876144125458603029U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18029699867733207083U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13361836994951253312U;
            aOrbiterF = RotL64((aOrbiterF * 5349767426256597073U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11957294454794128079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3755417922063414648U;
            aOrbiterJ = RotL64((aOrbiterJ * 13896364063651241401U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 18001157153447913032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16214145724690286854U;
            aOrbiterI = RotL64((aOrbiterI * 5874139687703360515U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3860958772090975562U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12395621524459640173U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 722817135977510161U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 3402035664910754484U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2139099117325745602U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14008983756425796029U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7769274487425053026U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 6492669707749367728U;
            aOrbiterA = RotL64((aOrbiterA * 5149771861620757839U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14963366447884375043U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11398874662567519691U;
            aOrbiterG = RotL64((aOrbiterG * 8221521452475029835U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7168445485232814860U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2786079456995203065U;
            aOrbiterK = RotL64((aOrbiterK * 14258367164534307955U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 58U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterH, 13U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 52U) + aOrbiterA) + RotL64(aOrbiterI, 27U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14743U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((aIndex + 15441U)) & S_BLOCK1], 40U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 13957U)) & S_BLOCK1], 27U) ^ RotL64(aFireLaneC[((aIndex + 14701U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16036U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8958U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 15450U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCross, 4U)) + (RotL64(aCarry, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 57U)) + 3917730204724097072U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererG + RotL64(aCross, 3U)) + 1874642340716212824U;
            aOrbiterF = (aWandererC + RotL64(aScatter, 41U)) + 6900165757434854160U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 26U)) + 12750946097023807161U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 6563216048479513594U;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 14960240191349450795U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 43U)) + 16306180275951788289U) + aPhaseFOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aScatter, 19U)) + 6502066618271045547U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 14U)) + 6219852857850888738U;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 11U)) + 2272931312452845850U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 3028929882263199463U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 6067393030073568112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10094809900437037258U;
            aOrbiterF = RotL64((aOrbiterF * 18095564940730322769U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5962414178157074575U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15755563045799129417U;
            aOrbiterG = RotL64((aOrbiterG * 3692603590609922031U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6321455513889880590U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1197435601998121700U;
            aOrbiterE = RotL64((aOrbiterE * 17693996266260557625U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12496949381666299968U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6357070235648527030U;
            aOrbiterI = RotL64((aOrbiterI * 2931486644220862433U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 8423760160877540210U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8090246492554850768U;
            aOrbiterJ = RotL64((aOrbiterJ * 2949407491181921633U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 11436635942985063755U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17086363141014359856U;
            aOrbiterH = RotL64((aOrbiterH * 10504127577318206801U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10734017887545474935U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 375515325165740779U;
            aOrbiterA = RotL64((aOrbiterA * 9980486695448151709U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5217148491945389821U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14696058217023530058U;
            aOrbiterD = RotL64((aOrbiterD * 11026674782236654799U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11869055287836412650U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16951500118659983436U;
            aOrbiterK = RotL64((aOrbiterK * 4304372681583055077U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7866300390953569803U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 18017335943787362993U;
            aOrbiterB = RotL64((aOrbiterB * 15683049583437004889U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2477944286851267725U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3917730204724097072U;
            aOrbiterC = RotL64((aOrbiterC * 6617615984203047419U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 40U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterI, 27U));
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 52U)) + aOrbiterC) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterF, 57U));
            aWandererC = aWandererC + (((RotL64(aCross, 48U) + RotL64(aOrbiterH, 10U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 26U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 22561U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneA[((aIndex + 23826U)) & S_BLOCK1], 21U));
            aIngress ^= (RotL64(aOperationLaneB[((aIndex + 16778U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16591U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19305U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 24454U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aExpandLaneB[((aIndex + 17273U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 34U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aScatter, 27U)) + 12222235191147985484U;
            aOrbiterA = (aWandererE + RotL64(aCross, 43U)) + 16367317014523328414U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 18U)) + 3511378091284703789U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aPrevious, 3U)) + 15247492830966725949U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 29U)) + 7745995913390407897U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 39U)) + 6463593307540108810U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aIngress, 51U)) + 1101669311005268630U;
            aOrbiterH = (aWandererC + RotL64(aCross, 48U)) + 12988052764067518580U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 17717179747434679772U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 11662190906682400416U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 6563014073547628748U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13099094932059419219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16342730862261868847U;
            aOrbiterB = RotL64((aOrbiterB * 10988124108686164829U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16855346813127524624U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6570063128502306944U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4571570049463124831U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11328352033809240501U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11640986648833160901U;
            aOrbiterI = RotL64((aOrbiterI * 2895830492089678919U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2675226158571501666U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17700531248266458165U;
            aOrbiterK = RotL64((aOrbiterK * 2231403813970188657U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7729597396731910874U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15172374484412053756U;
            aOrbiterC = RotL64((aOrbiterC * 149009041406406517U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9178769489257842683U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9020154972097834926U;
            aOrbiterG = RotL64((aOrbiterG * 8910504667566521429U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1317403761217790562U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17151528554929201571U;
            aOrbiterE = RotL64((aOrbiterE * 3735945655450625203U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11621882033959669977U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10289504450815075623U;
            aOrbiterH = RotL64((aOrbiterH * 13365982786836243195U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 16178772981106335703U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 16896130772325866910U;
            aOrbiterD = RotL64((aOrbiterD * 6993524735412868965U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9573223644675562575U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17552463713786507189U;
            aOrbiterA = RotL64((aOrbiterA * 16103431656424881779U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4801852246698369631U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12222235191147985484U;
            aOrbiterF = RotL64((aOrbiterF * 2835204872125428065U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aCross, 35U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 47U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 10U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterB, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 5U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 58U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterB, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25212U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 26298U)) & S_BLOCK1], 28U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 24855U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 30939U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28311U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26542U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28872U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 13687218104610230596U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 53U)) + 6841550124960692709U;
            aOrbiterG = (aWandererG + RotL64(aScatter, 27U)) + 17418968668458764131U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 8303537912696948204U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 41U)) + 12376614417285936537U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 14215749063579232654U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 3U)) + 4111736931433665347U;
            aOrbiterB = (aWandererE + RotL64(aIngress, 13U)) + 11250375934571631522U;
            aOrbiterK = (aWandererF + RotL64(aCross, 22U)) + 5367367837773331275U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 35U)) + 15514089192382674434U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 51U)) + 1475991716685034960U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5531622777788629748U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8363822215908303335U;
            aOrbiterG = RotL64((aOrbiterG * 17850203366840994883U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3741256932685720414U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11634667238062155772U;
            aOrbiterI = RotL64((aOrbiterI * 15925089729784547403U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18180546911210417155U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5123234656838556335U;
            aOrbiterJ = RotL64((aOrbiterJ * 15362857462853398025U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11215734271189250284U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16863747802158398092U;
            aOrbiterA = RotL64((aOrbiterA * 1828035970246160023U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9859050606636646323U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 9331300036643654675U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2502263410556166281U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 15028845665427209759U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 8916444839488901676U;
            aOrbiterE = RotL64((aOrbiterE * 6646561894156038791U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 8024631140949068570U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1116378858490660031U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4247798531910227367U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5066486214537899212U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9346312092322423057U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13443190089768875191U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11651011617027950122U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11308862427412671711U;
            aOrbiterK = RotL64((aOrbiterK * 12167147966934334703U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3850136281462840708U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13461307727665667424U;
            aOrbiterC = RotL64((aOrbiterC * 10788040812090673421U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17824744996404571928U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13687218104610230596U;
            aOrbiterH = RotL64((aOrbiterH * 325803029547254631U), 39U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 24U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterF, 6U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererI = aWandererI + ((RotL64(aScatter, 44U) + aOrbiterD) + RotL64(aOrbiterH, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterH, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 50U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 44U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_FootBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2738U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 6782U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3637U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6527U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5474U)) & S_BLOCK1], 4U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4959U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 54U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 13442819395490639310U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 8187292523194120936U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 11U)) + 11469697159823131388U) + aPhaseGOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 13414083692375929653U;
            aOrbiterA = (aWandererK + RotL64(aCross, 24U)) + 11404010733687907517U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6783212827186218247U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8561131439340372614U;
            aOrbiterJ = RotL64((aOrbiterJ * 7426867125542470683U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6252609642004429113U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12804867444200448952U;
            aOrbiterG = RotL64((aOrbiterG * 3114688959081972615U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2739648749603690781U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14808861217017399752U;
            aOrbiterF = RotL64((aOrbiterF * 373911885694012101U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17588866502571268888U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5882260142735642980U;
            aOrbiterH = RotL64((aOrbiterH * 7688252946143263869U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15493099088132862949U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 5175647411532429582U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15226544495598541883U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 38U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 22U)) + aOrbiterH);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15492U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 15867U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 9411U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11894U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14841U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 14081U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCross, 54U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 52U)) + RotL64(aCarry, 39U)) + 10404808878585437255U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 3U)) + 10587858736301591439U) + aPhaseGOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 1430530909801644435U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 9090938022430118902U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 43U)) + 12936604311751121235U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 1000583006020232032U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12352532088997042232U;
            aOrbiterD = RotL64((aOrbiterD * 494418029883239087U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16723410947058502564U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16614089235313154270U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11530998303573027827U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 4245553025593349277U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3353146318549477494U;
            aOrbiterF = RotL64((aOrbiterF * 14246377408238318091U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5935727336135635196U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10312187090293319667U;
            aOrbiterC = RotL64((aOrbiterC * 1395964500396711899U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12192843181244744484U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2542570124502586365U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17222847847573534963U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 43U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 4U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterB, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 36U) + RotL64(aOrbiterC, 21U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 13U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterF, 38U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21372U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 19111U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16390U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17892U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24409U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 19601U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 38U)) + (RotL64(aCross, 19U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 28U)) + 9041099828460168106U) + aPhaseGOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 12883711604096848454U;
            aOrbiterI = (aWandererG + RotL64(aCross, 43U)) + 17420968786226443079U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 3448213891716125104U) + aPhaseGOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 11866455977445336560U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 4119356835384495905U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2186212599698637068U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6756888950976735707U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6506144898969301620U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12556800923644051626U;
            aOrbiterE = RotL64((aOrbiterE * 15961043406612913121U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 4075551535185182945U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17877694808492008749U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 901315308379887473U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5553428900598223316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14362304852277160675U;
            aOrbiterH = RotL64((aOrbiterH * 11415103199856419303U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9174200302876075831U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 16110739511917638547U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7004356839428657949U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 18U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 27U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 6U)) + aOrbiterI) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aCross, 42U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 40U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26013U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((aIndex + 30611U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31946U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25111U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28648U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 29777U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aIngress, 11U)) + (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 26U)) + RotL64(aCarry, 47U)) + 826930775230515406U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 57U)) + 5137814617363250861U) + aPhaseGOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aIngress, 35U)) + 14761561947426681616U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 12773023438753662590U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 5U)) + 7331345852207096322U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3899381212671247460U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10072004147620068599U;
            aOrbiterI = RotL64((aOrbiterI * 5663583566047763435U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3424585039401897560U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8246760141625966321U;
            aOrbiterD = RotL64((aOrbiterD * 11478879365443736383U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3655992860610853290U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11154618022505863898U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4791494171286145231U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 15629361991059709973U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 10842068502278489664U;
            aOrbiterK = RotL64((aOrbiterK * 17223002513104960799U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 5571312349016336686U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 589313823745748879U;
            aOrbiterE = RotL64((aOrbiterE * 1356685926549786027U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 56U);
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterA, 39U)) + aPhaseGWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 14U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 56U) + aOrbiterI) + RotL64(aOrbiterE, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_FootBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 6511U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 2663U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 351U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1488U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4101U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1980U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 27U)) ^ (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 37U)) + 7722279280863371124U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 21U)) + 11584220561732385598U) + aPhaseHOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 7834679350105534657U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 11347994382444180879U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 46U)) + RotL64(aCarry, 23U)) + 9449903188047063431U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6516243976652795170U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8420815253991184777U;
            aOrbiterK = RotL64((aOrbiterK * 1358649408967265415U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9081386852515170937U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14375955191735286867U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2772840314542262283U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 880757589768436072U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3349856625725164229U;
            aOrbiterJ = RotL64((aOrbiterJ * 681514212582331781U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 7826309957607577207U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8057435761214313635U;
            aOrbiterC = RotL64((aOrbiterC * 4718430712767038607U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 9565237500443303103U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15893066735310588501U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8457633439171452397U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 57U) + RotL64(aOrbiterD, 29U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 40U) + aOrbiterJ) + RotL64(aOrbiterD, 52U));
            aWandererI = aWandererI + ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13392U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 9828U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 15933U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15267U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10690U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 12916U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererH + RotL64(aIngress, 5U)) + 10404808878585437255U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 10587858736301591439U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 1430530909801644435U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 9090938022430118902U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 38U)) + 12936604311751121235U) + aPhaseHOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1000583006020232032U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12352532088997042232U;
            aOrbiterF = RotL64((aOrbiterF * 494418029883239087U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16723410947058502564U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16614089235313154270U;
            aOrbiterA = RotL64((aOrbiterA * 11530998303573027827U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 4245553025593349277U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3353146318549477494U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14246377408238318091U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5935727336135635196U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10312187090293319667U;
            aOrbiterE = RotL64((aOrbiterE * 1395964500396711899U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 12192843181244744484U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 2542570124502586365U;
            aOrbiterJ = RotL64((aOrbiterJ * 17222847847573534963U), 29U);
            //
            aIngress = RotL64(aOrbiterJ, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 54U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 19U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 48U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18613U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 17090U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 20101U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21534U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20901U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16917U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 11U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 2783898056762489197U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 56U)) + 7177192902873343053U;
            aOrbiterD = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 12254703232691980774U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 15446547245691219559U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 29U)) + 888475203006174856U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3649183529366307877U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4642631047518805167U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14791564497487717167U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6108329730724782250U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 8334054653023816636U;
            aOrbiterC = RotL64((aOrbiterC * 9352516059501924393U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5891895375031474350U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3176720746238477862U;
            aOrbiterF = RotL64((aOrbiterF * 1869961473768307911U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6111038696865301675U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11914998302228682704U;
            aOrbiterJ = RotL64((aOrbiterJ * 11738924766359642853U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 17005063057791320948U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 18333780598768130670U;
            aOrbiterE = RotL64((aOrbiterE * 5416759844884107303U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterC, 56U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aCross, 23U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32323U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((aIndex + 27365U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28580U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32367U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31530U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27392U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aIngress, 44U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 17081642665820489793U) + aPhaseHOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 39U)) + 14468854040067229623U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 2249450222593057429U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 28U)) + RotL64(aCarry, 19U)) + 14964389079511378664U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 57U)) + 17003491054252360650U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12710882240582032588U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 9887078182156755359U;
            aOrbiterA = RotL64((aOrbiterA * 8205865025853482573U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7665284531810584704U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7304284015511876717U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6193179739025093929U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5517927023543751734U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 17704756310857362759U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15826832172923213591U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11347400363019508578U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11696395232760991243U;
            aOrbiterF = RotL64((aOrbiterF * 9725231749679442003U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10875780291242873583U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 7808740614343437672U;
            aOrbiterC = RotL64((aOrbiterC * 8889516201913716283U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 58U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aPhaseHWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
