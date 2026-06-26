#include "TwistExpander_BasketBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_BasketBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
                     std::uint8_t *pSource,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x9E05645671CB96CBULL + 0x877E9E7AA311A666ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8A80CD8FFFE94521ULL + 0x9526A004900D0F70ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC1224ED41DC39F33ULL + 0x9327B92F22DBA034ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x8EBEFEC8F7555E7FULL + 0xD6E682166297D4CCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF0E742B266817CF3ULL + 0x907755EBAC8F1561ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF247758FBC154711ULL + 0xB4020B74DDDA6704ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x99916798E3FB95A7ULL + 0xA60112FE654BE127ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x88B74DF09CDF66C3ULL + 0xE19332C2F8A16B72ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
    [[maybe_unused]] std::uint8_t *mSource = pSource;
    [[maybe_unused]] std::uint8_t *mSnow = pSnow;
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
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, mSnow
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordD, 27U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3710U)) & S_BLOCK1], 53U) ^ RotL64(mSnow[((aIndex + 4354U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 1006U)) & S_BLOCK1], 12U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 4225U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 21U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererH + RotL64(aPrevious, 51U)) + 9435962834163239322U;
            aOrbiterD = (aWandererB + RotL64(aCross, 60U)) + 10524704356081318973U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 39U)) + 7403401305665208680U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordE, 16U);
            aOrbiterB = (aWandererJ + RotL64(aIngress, 23U)) + 7525414805023556493U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 1116686470029070951U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 35U)) + 13257612299137802420U) + RotL64(aNonceWordB, 17U);
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 9181543003986598283U;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 28U)) + RotL64(aCarry, 47U)) + 9739384852307501107U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 21U)) + 11308402900229016057U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 11U)) + 14935167593705272337U) + aOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 41U)) + 7171824007631943535U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 8068411284829563567U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12350207458513447578U;
            aOrbiterH = RotL64((aOrbiterH * 813973258659041895U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17039236343991574134U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 18291683592714999632U;
            aOrbiterK = RotL64((aOrbiterK * 7771718817924840713U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6239616841884430968U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10604527977569876774U;
            aOrbiterA = RotL64((aOrbiterA * 6972820410084939637U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1707724300671717658U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3802268808625297647U;
            aOrbiterB = RotL64((aOrbiterB * 11296811630387191563U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9423064323799920219U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 242153923313096551U;
            aOrbiterG = RotL64((aOrbiterG * 12117679073775630197U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 945801070951928277U) + RotL64(aNonceWordA, 29U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 13094814302414492064U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14638176479878969775U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 7572219725951040117U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16494986983782503428U;
            aOrbiterJ = RotL64((aOrbiterJ * 2739189408707408171U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10949497978229234856U) + aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11219643352002119905U;
            aOrbiterD = RotL64((aOrbiterD * 16900635614259262873U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 14245670385849499678U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13771155918235018585U;
            aOrbiterE = RotL64((aOrbiterE * 14121731385133220921U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15722734439532828816U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11032710342174118366U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16096465375397981585U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2071496769185495150U) + RotL64(aNonceWordC, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9435962834163239322U;
            aOrbiterC = RotL64((aOrbiterC * 10640995428633266765U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 52U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 14U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterG, 39U));
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterD, 47U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 22U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterB, 37U)) + RotL64(aNonceWordH, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererE = aWandererE + (((RotL64(aPrevious, 40U) + aOrbiterE) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 41U)) + RotL64(aNonceWordG, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: mSource, mSnow, aWorkLaneA
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordC, 53U)) ^ RotL64(aNonceWordG, 4U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 10157U)) & S_BLOCK1], 41U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 8092U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 11U)) ^ RotL64(aNonceWordH, 35U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6142U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5635U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aPrevious, 56U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 11U)) + 785861751704720606U) + RotL64(aNonceWordA, 45U);
            aOrbiterI = ((aWandererK + RotL64(aIngress, 5U)) + 15968088718435606299U) + RotL64(aNonceWordB, 39U);
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 51U)) + 1393976526590347151U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 58U)) + 17240750947292745884U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 53U)) + 4921576136163183137U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 3334047873553153032U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 41U)) + RotL64(aCarry, 27U)) + 15086509978458408698U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 44U)) + 892391205397581998U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 47U)) + 2965686403183767521U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 14632215393655706170U;
            aOrbiterC = (aWandererB + RotL64(aCross, 29U)) + 15740589515342377322U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 11131164813943086445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6988080581278900960U;
            aOrbiterD = RotL64((aOrbiterD * 6412189142344044255U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16021254613117657178U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 6183615599897921154U) ^ RotL64(aNonceWordH, 7U);
            aOrbiterI = RotL64((aOrbiterI * 9976411093264211033U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12533992547026652747U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3104325358982904219U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14977348108778147265U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3878525937957474644U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 2120435259884368445U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15964718652193073177U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14928658302694194856U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9121310461310309348U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17304439784647477491U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3715693239100476493U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7336577492932262490U;
            aOrbiterH = RotL64((aOrbiterH * 11074754160002665253U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2312452827448455675U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4322756069651934618U;
            aOrbiterF = RotL64((aOrbiterF * 6908893297397073539U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4962079617577705818U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5072727464750706525U;
            aOrbiterG = RotL64((aOrbiterG * 4947670001221089155U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4553791875259778686U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15823770920225774233U;
            aOrbiterJ = RotL64((aOrbiterJ * 409663191536830375U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9468608484284459072U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8658861660659699947U) ^ RotL64(aNonceWordF, 51U);
            aOrbiterB = RotL64((aOrbiterB * 2933359123761406353U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14453429515273506170U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 785861751704720606U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3544627380583668815U), 57U);
            //
            aIngress = RotL64(aOrbiterJ, 58U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 10U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 54U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 23U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterJ, 19U)) + RotL64(aNonceWordG, 9U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 43U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordD, 26U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 46U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterF, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterK, 3U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 40U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: mSource, mSnow, aWorkLaneA, aWorkLaneB
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordE, 39U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 13772U)) & S_BLOCK1], 29U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 15508U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 24U) ^ RotL64(aNonceWordB, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15235U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 15604U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 12380376990224645149U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 18296928500297384014U;
            aOrbiterK = (aWandererE + RotL64(aCross, 47U)) + 3550626816361145100U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 37U)) + 2667792936946706027U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 39U)) + 12020969779370926953U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 3U)) + 737340727886903447U) + RotL64(aNonceWordG, 3U);
            aOrbiterG = ((aWandererC + RotL64(aCross, 34U)) + 1681797651799760502U) + RotL64(aNonceWordD, 7U);
            aOrbiterB = (aWandererH + RotL64(aIngress, 21U)) + 2956186342689489064U;
            aOrbiterF = (aWandererK + RotL64(aCross, 27U)) + 1876852870402977177U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 29U)) + 6433205819353555071U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 24U)) + 9065076854974222998U) + aOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3254410578766789992U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2005081975473815576U;
            aOrbiterK = RotL64((aOrbiterK * 9947701153722014085U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15992999234834560419U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3458344156815120948U;
            aOrbiterD = RotL64((aOrbiterD * 1668460113964608051U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17069783053664877727U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1260234710193913099U;
            aOrbiterI = RotL64((aOrbiterI * 4561226779897414381U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3825186451876061335U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2905344294992827535U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2469896090698580795U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 18141402347899180617U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8760129857609925066U;
            aOrbiterB = RotL64((aOrbiterB * 2507999156108123047U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 594052473780678210U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 13216719212966128379U) ^ RotL64(aNonceWordC, 13U);
            aOrbiterA = RotL64((aOrbiterA * 10691355329696722303U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 10029948739466316169U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 11912428807431992996U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) ^ RotL64(aNonceWordF, 10U);
            aOrbiterC = RotL64((aOrbiterC * 85016510811938307U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8735634019801417287U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12785916159063273545U;
            aOrbiterE = RotL64((aOrbiterE * 1161917531260663357U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 367752057919802452U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 3961036242431041564U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16352646009782597315U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3858415336170090719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 14325258358254321551U;
            aOrbiterF = RotL64((aOrbiterF * 12080431158781060059U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16872184337970977180U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12380376990224645149U;
            aOrbiterH = RotL64((aOrbiterH * 16559121155413059221U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterF, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterG, 23U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + RotL64(aOrbiterI, 38U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 51U)) + aOrbiterE) + aWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 27U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aNonceWordH, 35U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterB, 46U)) + aOrbiterE) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 3U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 53U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + RotL64(aCarry, 53U)) + RotL64(aNonceWordA, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 40U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: mSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordA, 36U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 17523U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18475U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordF, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17760U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneA[((aIndex + 17567U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aPrevious, 60U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aIngress, 47U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 19U)) + 9630214189402543339U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 44U)) + 4072576573737526819U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 39U)) + 15994787452709618869U) + RotL64(aNonceWordE, 42U);
            aOrbiterK = (aWandererE + RotL64(aScatter, 41U)) + 6403240137132259482U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 29U)) + 10229266900170507720U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 53U)) + 5025294577989748989U) + RotL64(aNonceWordD, 47U);
            aOrbiterI = ((aWandererG + RotL64(aScatter, 5U)) + 16696461238217956883U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 9878318855341719119U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aPrevious, 34U)) + 16086635438116177346U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 21U)) + 12295437783084203730U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 7681150419912842402U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2639104034287637448U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12298170009332243573U;
            aOrbiterH = RotL64((aOrbiterH * 9397919591171238575U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 3485932317267669626U) + RotL64(aNonceWordC, 13U);
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16569551670038752475U;
            aOrbiterG = RotL64((aOrbiterG * 8139802826402217631U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4448490103784103954U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 14510534073046885941U;
            aOrbiterJ = RotL64((aOrbiterJ * 7777192047386438305U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4286195398675733451U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15790355933840266463U;
            aOrbiterI = RotL64((aOrbiterI * 13342257823027075501U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6362891510370156055U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15121822034579983174U;
            aOrbiterF = RotL64((aOrbiterF * 7268045994574844937U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13817341015719915628U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14113474087906143783U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12838910141533126059U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9988301252236121106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11287477288382171758U;
            aOrbiterE = RotL64((aOrbiterE * 4979297247881426383U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9491727010910328644U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7961202721830514030U;
            aOrbiterC = RotL64((aOrbiterC * 16300364540313620767U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10058066852293995222U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 541563830282750968U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1516823517052019845U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 7791201128863372861U) + RotL64(aNonceWordF, 41U);
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8334318157449352359U;
            aOrbiterD = RotL64((aOrbiterD * 2924838607279239375U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6861081455774799715U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9630214189402543339U;
            aOrbiterK = RotL64((aOrbiterK * 10837610668580336781U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 22U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 52U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceWordH, 59U));
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterA, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 26U) + aOrbiterE) + RotL64(aOrbiterC, 37U));
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterA, 41U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterF, 23U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 40U) + RotL64(aOrbiterC, 14U)) + aOrbiterD) + RotL64(aNonceWordB, 19U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterD) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // read from: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordC, 58U)) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 26422U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 26218U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 39U) ^ RotL64(aNonceWordE, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24851U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 26905U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 21U)) + (RotL64(aPrevious, 37U) ^ RotL64(aCross, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererF + RotL64(aIngress, 57U)) + 10726035965553989335U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 967354339530195662U;
            aOrbiterF = (((aWandererB + RotL64(aCross, 50U)) + 10834593005478605624U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordB, 6U);
            aOrbiterB = (aWandererE + RotL64(aScatter, 47U)) + 1012888282838656933U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 35U)) + 15283530351725183253U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 5U)) + 11724495956731703750U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 29U)) + 4288330117317505776U;
            aOrbiterD = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 10894778070022873473U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 54U)) + 15563886747621617467U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 11U)) + 11182488628562891937U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 47U)) + 10420140066310588580U) + RotL64(aNonceWordD, 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11775138062167543111U) + RotL64(aNonceWordG, 23U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16545391898578161683U;
            aOrbiterF = RotL64((aOrbiterF * 14588306527161321535U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1550144656312299266U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14903504853138279883U;
            aOrbiterI = RotL64((aOrbiterI * 8003033561266164387U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 309935535526750396U) + aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13991265868040011411U;
            aOrbiterD = RotL64((aOrbiterD * 2887531132228588441U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1755976294857114222U) + RotL64(aNonceWordE, 37U);
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2259275858478396846U;
            aOrbiterH = RotL64((aOrbiterH * 7416165760067878161U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4838175912944552936U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 12307900457200936013U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14719363144850838805U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18025411832912225805U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 981375022769564523U;
            aOrbiterB = RotL64((aOrbiterB * 15869361544011831483U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3174014054982742562U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8119692378748963609U;
            aOrbiterC = RotL64((aOrbiterC * 3072354179707448489U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14502863160788675807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1207582534593709516U;
            aOrbiterJ = RotL64((aOrbiterJ * 3045412087535529357U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5838011917777875072U) + aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 434594114594643600U;
            aOrbiterK = RotL64((aOrbiterK * 1591023655239709931U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15711060039063734443U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8307150522686198490U;
            aOrbiterG = RotL64((aOrbiterG * 2082452039297764679U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 5805686529930815226U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10726035965553989335U;
            aOrbiterA = RotL64((aOrbiterA * 5563221485243331689U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 10U));
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 39U)) + RotL64(aNonceWordH, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aCross, 6U) + aOrbiterG) + RotL64(aOrbiterD, 30U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 11U)) + aOrbiterJ) + RotL64(aNonceWordA, 59U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 23U));
            aWandererG = aWandererG + ((RotL64(aIngress, 60U) + RotL64(aOrbiterE, 57U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterK, 14U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 18U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // read from: aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aNonceWordH, 39U) ^ RotL64(aNonceWordC, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 31157U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29618U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordG, 30U)) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30503U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 30601U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 51U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 38U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 6U)) + RotL64(aCarry, 27U)) + 18180797995100240808U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 51U)) + 6585906608223552885U) + RotL64(aNonceWordG, 41U);
            aOrbiterJ = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 14088708930575939855U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 43U)) + 468974153311516044U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 57U)) + 12481951025619894110U;
            aOrbiterB = (aWandererH + RotL64(aCross, 60U)) + 17227987923860711763U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 53U)) + 4373962756657477139U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 21U)) + 2077576476565420951U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 23U)) + 17435011300234663764U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aScatter, 27U)) + 4118039398293246896U;
            aOrbiterG = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 13724716599855216683U) + RotL64(aNonceWordA, 17U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12391461204689596339U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9900605191533799627U;
            aOrbiterJ = RotL64((aOrbiterJ * 13553565332531046301U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 972946858824366125U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17247681919694541215U;
            aOrbiterE = RotL64((aOrbiterE * 2974639094630445643U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15442851427306771601U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7303586227288294037U;
            aOrbiterB = RotL64((aOrbiterB * 15406402525021428799U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12650358753454105119U) + RotL64(aNonceWordE, 6U);
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1483710933373510492U;
            aOrbiterA = RotL64((aOrbiterA * 6531763256577221891U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18065810162229740788U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11311677121338794007U;
            aOrbiterH = RotL64((aOrbiterH * 15116367961682119467U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2355285311890287611U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1287783821903407734U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8054011680932255985U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9282654686791135654U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15488608017745542551U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7858866274035085123U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13296835576073421802U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7127700236018338741U;
            aOrbiterG = RotL64((aOrbiterG * 11246173563106014149U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1365928843264598789U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 7777790578813003657U;
            aOrbiterD = RotL64((aOrbiterD * 10121688100505628161U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2104270617375082523U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 13363764449819651164U) ^ RotL64(aNonceWordF, 21U);
            aOrbiterC = RotL64((aOrbiterC * 2685452132715528975U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2008038686059197988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18180797995100240808U;
            aOrbiterI = RotL64((aOrbiterI * 8978998151475372047U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 52U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 14U) + RotL64(aOrbiterE, 58U)) + aOrbiterK) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 37U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 27U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aCross, 20U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordD, 19U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + RotL64(aNonceWordB, 29U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 13U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 22U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_BasketBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEA15BA48CD49FA91ULL + 0xB8AF6B4F73E46490ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBE2329C1E987D1ADULL + 0x9AF5FE9D228ADE4BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x915D694C1ADD971FULL + 0xF612AF77A188E356ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFE9700545E36DE0DULL + 0xC9D3D65CAAAA1465ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8242142B753747C3ULL + 0xB85D3DF57D2122D9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x871DDABCBE14DC4BULL + 0xF795980306D01C29ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE21DB5865801D4D7ULL + 0xF43B9121A9E1238DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE9E6D24F583C623BULL + 0xF681EA0125A2469AULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordA, 46U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6998U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 7923U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordC, 35U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5118U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 3051U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 22U)) + (RotL64(aIngress, 35U) ^ RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 11U)) + 3684295017013759987U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 30U)) + 6740408842457292881U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordE, 17U);
            aOrbiterB = ((aWandererE + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 4563975890702399441U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 41U)) + 797804144825287940U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 21U)) + 2763779540450101303U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 35U)) + 13211846164102089685U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + 15214578447281401982U) + RotL64(aNonceWordC, 11U);
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 13745208628754232427U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 17358621225969190747U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 779739369960480023U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4370963533701407813U;
            aOrbiterB = RotL64((aOrbiterB * 3123135216876641039U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6061333005507739975U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 3589705340762734456U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16499293983611196967U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 10607697666369230567U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9356757995305239271U;
            aOrbiterJ = RotL64((aOrbiterJ * 10945513661439954731U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10093033335903048138U) + RotL64(aNonceWordF, 16U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11037328061699834100U;
            aOrbiterD = RotL64((aOrbiterD * 11189760551792389605U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 558431161176115540U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17795680919453449358U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3910117359996283803U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6096779391116214109U) + RotL64(aNonceWordD, 3U);
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17594243286880690775U;
            aOrbiterH = RotL64((aOrbiterH * 12655610181937429915U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15414704802398002423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 18040588240488602196U;
            aOrbiterF = RotL64((aOrbiterF * 16344249573086571225U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14636298592697156931U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9677305688594936561U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8354776999961642997U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16408025751875050713U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 10018342878801454965U;
            aOrbiterC = RotL64((aOrbiterC * 10349132962708124117U), 53U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 42U);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterD, 12U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 40U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterF, 53U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 57U)) + aOrbiterG) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterC, 42U)) + aOrbiterH) + RotL64(aNonceWordB, 57U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 47U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterB, 23U)) + RotL64(aNonceWordG, 53U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16205U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14585U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15672U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 14045U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 60U)) + 7825479804710770560U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 19U)) + 5298124167101358123U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 17774541024369233726U) + RotL64(aNonceWordF, 9U);
            aOrbiterF = (aWandererA + RotL64(aPrevious, 27U)) + 7679371833537454082U;
            aOrbiterG = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 5385914900748772224U) + RotL64(aNonceWordG, 21U);
            aOrbiterJ = (aWandererC + RotL64(aIngress, 46U)) + 3879781930908486531U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 51U)) + 659110346638873236U;
            aOrbiterE = (aWandererH + RotL64(aCross, 35U)) + 10749021728538539749U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 5U)) + 3631252455767429457U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2271978810960685021U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5963558780692551176U;
            aOrbiterC = RotL64((aOrbiterC * 4772055335210781149U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 974909966119198104U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 9296998242911152296U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2613629915877957661U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2245318466901521959U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13391076374843288568U;
            aOrbiterA = RotL64((aOrbiterA * 18094558036982107419U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 6184487746594236737U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1563385912137291418U;
            aOrbiterE = RotL64((aOrbiterE * 4805455299959232321U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1744840092006498629U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2100927276837188416U) ^ RotL64(aNonceWordB, 19U);
            aOrbiterB = RotL64((aOrbiterB * 3541788262067077997U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9998911862807246338U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12239948725635220096U;
            aOrbiterD = RotL64((aOrbiterD * 7098620484129489129U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3307447094994950246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12746613971448298932U;
            aOrbiterF = RotL64((aOrbiterF * 9463975886346934681U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11577488293733790649U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 191108997585598809U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9574978681405356871U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 18096145693841273722U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10026281133603934071U) ^ RotL64(aNonceWordE, 7U);
            aOrbiterI = RotL64((aOrbiterI * 17261343107314203471U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 56U) + aOrbiterA) + RotL64(aOrbiterD, 10U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterG) + RotL64(aNonceWordC, 52U)) + aWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aNonceWordA, 31U));
            aWandererD = aWandererD + ((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterG, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 35U));
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 28U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23291U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19414U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordF, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24357U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 18377U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 57U)) + 7651355040951791298U) + RotL64(aNonceWordC, 45U);
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 30U)) + RotL64(aCarry, 11U)) + 13988210277931659312U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 37U)) + 9846849412579537783U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 11U)) + 12746719939495876158U) + RotL64(aNonceWordH, 19U);
            aOrbiterA = (aWandererH + RotL64(aScatter, 53U)) + 11498066185182895284U;
            aOrbiterE = (((aWandererD + RotL64(aIngress, 6U)) + RotL64(aCarry, 43U)) + 11101058955193080232U) + aOrbiterAssignSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 19U)) + 15513734459555672046U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 23U)) + 15711108675349394643U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 4771231759949468556U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11449258010811305256U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17036938391509986723U;
            aOrbiterC = RotL64((aOrbiterC * 7411466953205347639U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6999245666776654250U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 2106819066263369528U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13005885810757743129U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12716183358903477216U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 16752724547046059889U) ^ aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11475905692393034141U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17623077680983093163U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6726003022297274986U;
            aOrbiterH = RotL64((aOrbiterH * 14709385877103232653U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 2842410225096524740U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 9235178377537910514U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11813751114775673845U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2619888019860844610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6295481948199619613U;
            aOrbiterE = RotL64((aOrbiterE * 15429161806953951205U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 9724921158061115570U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4070976180958458679U;
            aOrbiterF = RotL64((aOrbiterF * 6080566609081811453U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5864247978960125554U) + RotL64(aNonceWordE, 9U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7771249710071026757U;
            aOrbiterJ = RotL64((aOrbiterJ * 4787660062590737657U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15006900854988166845U) + RotL64(aNonceWordD, 5U);
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2755659268987119046U;
            aOrbiterI = RotL64((aOrbiterI * 8043939381186802359U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 34U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 24U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterI, 20U));
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 13U)) + RotL64(aNonceWordB, 55U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 43U)) + aOrbiterE) + RotL64(aNonceWordG, 6U));
            aWandererD = aWandererD + (((RotL64(aCross, 42U) + RotL64(aOrbiterE, 39U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 56U)) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 18U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterF, 35U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 36U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordE, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30338U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 31268U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordD, 4U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24752U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 25450U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 60U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 23U)) + 15316464782468770057U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 41U)) + 6642872057476351588U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 660732654689529192U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 7235418086884000655U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 19U)) + 14784518476694580493U) + RotL64(aNonceWordC, 54U);
            aOrbiterK = (aWandererC + RotL64(aScatter, 5U)) + 12222433977933449375U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 51U)) + 8573001207708329927U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 56U)) + 16035256260815013172U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 11U)) + 15767726974121910203U) + RotL64(aNonceWordB, 31U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17712217935322939971U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13488963456923357159U;
            aOrbiterG = RotL64((aOrbiterG * 16785285630840310405U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10222949131965611079U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1495561412321657209U;
            aOrbiterF = RotL64((aOrbiterF * 9706305581868526265U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16156530750584361434U) + RotL64(aNonceWordE, 39U);
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11544578291333360613U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3665587867634242865U) ^ RotL64(aNonceWordF, 51U);
            aOrbiterB = RotL64((aOrbiterB * 4840528190844842595U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15248434984650998090U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15487979645426567581U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10868107809356766183U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6972347795052712690U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 16074994810010431338U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1262655238856775853U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16851139687900415292U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14630026837021552812U;
            aOrbiterE = RotL64((aOrbiterE * 9577900853521254603U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14236330619137368169U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17778707026111136216U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16239561893843454747U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9390961969105999083U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1174881758316573228U;
            aOrbiterC = RotL64((aOrbiterC * 6602061268277529311U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 35U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterB, 48U)) + aOrbiterK) + RotL64(aCarry, 11U)) + RotL64(aNonceWordG, 55U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 23U)) + aOrbiterA) + RotL64(aNonceWordA, 25U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 39U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 53U));
            aWandererC = aWandererC + ((RotL64(aCross, 56U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterD, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 58U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_BasketBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xCB70D90339D0EF5DULL + 0xC3FF3528DE56DC47ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDFEC6D1AE001B71DULL + 0xE1F622A40BD8F327ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB592BF3A3CAFBBFDULL + 0x82FE3A0F2672F421ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD6320C18AF5ABB9FULL + 0xC7274D8D785CF887ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD14FA3D276BD58CBULL + 0xE68F096E75B7804FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDED5EA58EF703225ULL + 0xBAF0FCBEE818210DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF5FBC5164640157BULL + 0xB117069C80EFC47FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8703FCDCE9C6F54BULL + 0xB147F613E1B941E8ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordD, 18U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7037U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 4518U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordC, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7714U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 5873U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 50U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 11410829607777684449U;
            aOrbiterA = ((((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 57U)) + 7502698839700975347U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordA, 29U);
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + 13267685058252106173U) + RotL64(aNonceWordH, 21U);
            aOrbiterC = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 238242706996630625U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 35U)) + 8184695499511454281U) + aOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12767823220461985403U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12293198423143850330U;
            aOrbiterJ = RotL64((aOrbiterJ * 5073886956792823825U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11149495229952495939U) + aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 7556992689338382800U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) ^ RotL64(aNonceWordC, 39U);
            aOrbiterE = RotL64((aOrbiterE * 18232398462716803063U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3431338808774134649U) + aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16863099140844995099U;
            aOrbiterC = RotL64((aOrbiterC * 752376661101787919U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17872458049880677604U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 16760153457252546974U) ^ RotL64(aNonceWordG, 30U);
            aOrbiterA = RotL64((aOrbiterA * 11225037229069712805U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3115544493537438408U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4359882942759752958U;
            aOrbiterK = RotL64((aOrbiterK * 561477566995575801U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 52U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + RotL64(aNonceWordF, 59U));
            aWandererK = aWandererK + ((((RotL64(aCross, 39U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 56U)) + aOrbiterE) + RotL64(aNonceWordE, 49U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordB, 53U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14841U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((aIndex + 9209U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordG, 27U)) ^ RotL64(aNonceWordF, 58U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15828U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 11108U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 10U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 17019646486641172469U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aCross, 29U)) + 12276141179299971572U) + RotL64(aNonceWordD, 15U);
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 38U)) + RotL64(aCarry, 37U)) + 3617241694029841555U;
            aOrbiterC = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 6967963401259371737U;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 13U)) + 6340709284279891017U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordG, 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 456065368903896482U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 17686765719908116203U) ^ RotL64(aNonceWordE, 17U);
            aOrbiterH = RotL64((aOrbiterH * 4451942512173336609U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 1322045955429785736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5163772703302372887U;
            aOrbiterJ = RotL64((aOrbiterJ * 3193272189179082313U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13268431135020363252U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6538789950366849332U;
            aOrbiterB = RotL64((aOrbiterB * 5352960308459065837U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 10390344544314544893U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5087084271300584267U;
            aOrbiterD = RotL64((aOrbiterD * 15149302947570776165U), 23U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterB) + 13423071121590981727U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordH, 49U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 18324443012024134729U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15814349432207734533U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 36U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 56U)) + RotL64(aNonceWordB, 60U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + RotL64(aNonceWordA, 13U)) + aWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17880U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17797U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordH, 22U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21391U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 17397U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 4U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 17081642665820489793U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 57U)) + 14468854040067229623U) + RotL64(aNonceWordE, 49U);
            aOrbiterJ = ((((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 2249450222593057429U) + aOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordD, 35U);
            aOrbiterB = (((aWandererG + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 14964389079511378664U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aPrevious, 10U)) + 17003491054252360650U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 12710882240582032588U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9887078182156755359U;
            aOrbiterJ = RotL64((aOrbiterJ * 8205865025853482573U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7665284531810584704U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7304284015511876717U;
            aOrbiterI = RotL64((aOrbiterI * 6193179739025093929U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5517927023543751734U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 17704756310857362759U;
            aOrbiterD = RotL64((aOrbiterD * 15826832172923213591U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11347400363019508578U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 11696395232760991243U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1]) ^ RotL64(aNonceWordG, 21U);
            aOrbiterB = RotL64((aOrbiterB * 9725231749679442003U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 10875780291242873583U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 7808740614343437672U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1]) ^ RotL64(aNonceWordF, 17U);
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 10U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterE) + RotL64(aCarry, 43U)) + RotL64(aNonceWordA, 58U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 20U) + RotL64(aOrbiterE, 29U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 10U)) + aOrbiterD) + RotL64(aNonceWordC, 37U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 21U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + RotL64(aWandererG, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 35U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordA, 24U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29897U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29759U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordE, 3U)) ^ RotL64(aNonceWordF, 58U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26884U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 32127U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 37U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererG + RotL64(aIngress, 22U)) + 15652862298542575895U) + RotL64(aNonceWordG, 3U);
            aOrbiterE = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 16925323928418184554U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 57U)) + 4413861484961668394U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 2215946422098155969U) + aOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 14975185533513111110U) + RotL64(aNonceWordE, 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9711613814905834552U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13154957291850149471U;
            aOrbiterK = RotL64((aOrbiterK * 17049677190793844477U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5058313016418534840U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15011423472941211620U;
            aOrbiterI = RotL64((aOrbiterI * 6125316151731105673U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2030053257469580168U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterE) ^ 150530795186791193U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) ^ RotL64(aNonceWordD, 5U);
            aOrbiterJ = RotL64((aOrbiterJ * 11106050063717096073U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10878237472104183427U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 11724672539469573109U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) ^ RotL64(aNonceWordC, 49U);
            aOrbiterE = RotL64((aOrbiterE * 16158741837357985395U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9589700906445846956U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1367381624958248949U;
            aOrbiterA = RotL64((aOrbiterA * 8459515089081211977U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterI, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 54U)) + aOrbiterE) + RotL64(aNonceWordA, 43U));
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordB, 26U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterK, 27U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 37U);
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

void TwistExpander_BasketBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9A6EEAF40727468FULL + 0xE1125FD231E4EEA8ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9614A13ED6CB114FULL + 0xE361FB5875387B9FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBCF4A7ED8BF24301ULL + 0x93EE6F3BD21E582AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFC016ADDCA8328D5ULL + 0xC123A82E73B5C886ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xF335234385527B91ULL + 0xA8B98F25F4E2B6A9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF36C5C9FA70CC409ULL + 0x955018ED94C25531ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x98276170C2760651ULL + 0xD7B974E7E258799AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x822062928D845E0FULL + 0xD2D28BF6FDA17C32ULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 14U) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1971U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1086U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4959U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4127U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 6U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 53U)) + 5171470532667965920U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 47U)) + 750549462358682403U) + RotL64(aNonceWordH, 27U);
            aOrbiterC = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 19U)) + 3325689257577120525U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 18031575461559790826U) + aOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aIngress, 41U)) + 13874739537012288677U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 11U)) + 4250029868785016865U) + RotL64(aNonceWordA, 51U);
            aOrbiterH = (aWandererG + RotL64(aScatter, 26U)) + 8211158803112611161U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1083939790236786027U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3446525462376962464U) ^ RotL64(aNonceWordF, 29U);
            aOrbiterC = RotL64((aOrbiterC * 13603702473750888213U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 6973817815000417325U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15230876489676945543U;
            aOrbiterA = RotL64((aOrbiterA * 7737039082964537651U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 9359727659738755880U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8775170107816327654U;
            aOrbiterE = RotL64((aOrbiterE * 6910680458261008653U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 11958941755525038545U) + RotL64(aNonceWordB, 48U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16966819714283167348U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16363457661846050749U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14556087985619763243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 17915047508377045221U;
            aOrbiterD = RotL64((aOrbiterD * 6727635453185130109U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8578745677485367222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7002181668717618866U;
            aOrbiterK = RotL64((aOrbiterK * 12329703532414955235U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 3569939503066735457U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2956247934282522184U) ^ aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9946650822131152531U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 41U)) + aOrbiterC) + RotL64(aNonceWordE, 59U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 50U) + RotL64(aOrbiterA, 53U)) + aOrbiterK) + RotL64(aNonceWordC, 13U));
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 27U)) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 60U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 14U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 21U) ^ RotL64(aNonceWordE, 51U)) ^ RotL64(aNonceWordH, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14341U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14009U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 24U) ^ RotL64(aNonceWordC, 43U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12228U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 16182U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 10U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 4980738603982643969U;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 3U)) + 17660278413018470020U) + RotL64(aNonceWordC, 29U);
            aOrbiterA = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 17598114429859543466U) + aOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 10993929335279994739U;
            aOrbiterE = (((aWandererA + RotL64(aCross, 42U)) + 17967203122976322481U) + aOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + RotL64(aNonceWordH, 25U);
            aOrbiterC = (aWandererF + RotL64(aScatter, 29U)) + 1872290205549034384U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 51U)) + 16607778671782810797U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4895226930754394376U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 14960359005982301383U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8546231310054433721U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9921642352377700630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 893281964367208693U;
            aOrbiterJ = RotL64((aOrbiterJ * 2345509157333444217U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 8232519988397858732U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4433022122758913407U;
            aOrbiterI = RotL64((aOrbiterI * 834240393225479419U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12689609831247168353U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 404535388957472176U;
            aOrbiterH = RotL64((aOrbiterH * 14534020545479806593U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3349108201964013155U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4386449511297371730U) ^ RotL64(aNonceWordE, 17U);
            aOrbiterE = RotL64((aOrbiterE * 9596273264321140229U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14314587717949070586U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 10923886625271054985U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7838969002623486809U), 29U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterI) + 17634909585329833520U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1]) + RotL64(aNonceWordF, 34U);
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2021301459918350372U;
            aOrbiterG = RotL64((aOrbiterG * 1388242915918642741U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 20U) + aOrbiterA) + RotL64(aOrbiterI, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordB, 23U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 35U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + RotL64(aCarry, 13U)) + RotL64(aNonceWordG, 49U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 26U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordH, 58U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19542U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23357U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordE, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20733U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((aIndex + 23037U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 19U)) + (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 43U)) + 4204560462077827182U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 6572370199668594039U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 25U);
            aOrbiterI = (aWandererH + RotL64(aScatter, 51U)) + 15958999876732622825U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 22U)) + 9969349486879280377U) + RotL64(aNonceWordG, 21U);
            aOrbiterJ = (aWandererA + RotL64(aScatter, 13U)) + 15450238998293956181U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 9128619863683138259U;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 5691270563628979565U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 5901029710568933106U) + RotL64(aNonceWordA, 31U);
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10442738941988588834U;
            aOrbiterI = RotL64((aOrbiterI * 7386621444831603817U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3508116020325721993U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 13221917083569767259U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6845108555710135357U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11627915460377128176U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 17858261365514253433U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7535577636975884641U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4294837988806295989U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11242915481585070249U;
            aOrbiterE = RotL64((aOrbiterE * 17540688242763829319U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13030663829236027109U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7451948220723185149U;
            aOrbiterJ = RotL64((aOrbiterJ * 5191778587712222029U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5575508866505031037U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5161096033789876794U;
            aOrbiterB = RotL64((aOrbiterB * 16843827915802461797U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3980482740649505122U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterA) ^ 11188906150207270241U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ RotL64(aNonceWordF, 3U);
            aOrbiterH = RotL64((aOrbiterH * 408550837615188413U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 10U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterI, 37U)) + RotL64(aNonceWordB, 60U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 19U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 28U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterE) + RotL64(aNonceWordE, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordD, 12U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25403U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 27907U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 56U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordE, 41U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28073U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 27852U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aCross, 27U)) + 8793908991006073956U) + aOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aScatter, 11U)) + 2932916283348441943U) + aOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordG, 35U);
            aOrbiterD = (aWandererF + RotL64(aPrevious, 41U)) + 11069042087940968262U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 14369628676782894441U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 8602903272780978282U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 3827036107178568820U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 4U)) + 8905245209036772489U) + RotL64(aNonceWordH, 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13331387530760017893U) + aOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9880107580289737823U;
            aOrbiterD = RotL64((aOrbiterD * 10302652857542703753U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10199619040626900278U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2466307560891374281U;
            aOrbiterK = RotL64((aOrbiterK * 6295342978834217571U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13973403407981259448U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2851460278409385243U;
            aOrbiterH = RotL64((aOrbiterH * 11226902976321781743U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10365453393815690776U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2382382358987358791U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterG = RotL64((aOrbiterG * 481563628980705781U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 5058198848163792422U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10500434740387593487U) ^ RotL64(aNonceWordB, 60U);
            aOrbiterC = RotL64((aOrbiterC * 5946747708776079787U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11289798395177667084U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 14327152153231286666U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18155778059595245561U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8065137263811956313U) + aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3865153574847924816U;
            aOrbiterE = RotL64((aOrbiterE * 9495741102667755161U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + RotL64(aNonceWordF, 13U)) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterK) + RotL64(aNonceWordD, 15U)) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterC, 46U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 53U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 28U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_BasketBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE83F050B41E4D76FULL + 0x82D87576D2CB205BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC35FC35404F14AC9ULL + 0xBB992516631D7E21ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x85D28B60F091D501ULL + 0xAA8074B1B6385525ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9859EA40B2CD143FULL + 0x82B57D7BFA55FC3CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD71787D7AE874D51ULL + 0x852E45C6AC962129ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE7BB1A8AC33CB291ULL + 0xF0A1C7AE331FBA00ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE1E7A94F94F89A9DULL + 0x92D2FD2BE18CBB6DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD3B2473D1EA03A83ULL + 0xE1EA1B5F5C78804DULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 38U) ^ RotL64(aNonceWordB, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5353U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 6106U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2676U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 5363U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 54U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 13U)) + 12131317914288566437U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (((aWandererB + RotL64(aPrevious, 53U)) + 5672805657999385496U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordF, 55U);
            aOrbiterF = (aWandererD + RotL64(aCross, 47U)) + 3581710244233124197U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 5U)) + 15251296040538489436U) + RotL64(aNonceWordA, 59U);
            aOrbiterK = (aWandererH + RotL64(aIngress, 11U)) + 11295008604679904153U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 2230897493419504490U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 26U)) + RotL64(aCarry, 39U)) + 7109600123297458999U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13119156643107683803U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14755160867807355250U;
            aOrbiterF = RotL64((aOrbiterF * 10007087518844899239U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16829363373287496832U) + RotL64(aNonceWordH, 14U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16981122946707720883U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5394974422201576627U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8806000776958603317U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16810923047720876014U;
            aOrbiterH = RotL64((aOrbiterH * 17872735050219539145U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8129657889554436328U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8653100378491974463U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11395283153912468661U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17048985838727432415U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 10892675550889823573U;
            aOrbiterG = RotL64((aOrbiterG * 976298937314081913U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 15960158965421254346U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordE, 13U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 12290011578634850001U) ^ aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9280475585104357745U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16265047040311479093U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10312956912303656248U;
            aOrbiterD = RotL64((aOrbiterD * 3012584393253845131U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 53U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordG, 37U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 43U) + RotL64(aOrbiterD, 19U)) + aOrbiterG) + RotL64(aNonceWordC, 11U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterB, 12U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterD, 29U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 4U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 42U)) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10192U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10570U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 14U) ^ RotL64(aNonceWordD, 53U)) ^ RotL64(aNonceWordE, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9368U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16368U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 27U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aScatter, 21U)) + 13650869943246163567U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 41U)) + 3435284932011770999U) + RotL64(aNonceWordH, 43U);
            aOrbiterC = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 13U)) + 12388155658186776579U) + aOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 2374345913955712039U) + RotL64(aNonceWordF, 22U);
            aOrbiterJ = ((aWandererH + RotL64(aCross, 58U)) + 6095094526980292156U) + aOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 4965147025852444174U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 27U)) + 3261881216269075298U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4939780217097329222U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3019862009792676287U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2452316208025448747U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 901910626217143974U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3647055146712366383U;
            aOrbiterG = RotL64((aOrbiterG * 1792602402476450009U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7731765438957392967U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13409819457393479741U;
            aOrbiterB = RotL64((aOrbiterB * 3345078200262410715U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5415832109107794258U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8876738832313114471U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1304277600444504135U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17135570542519390359U) + RotL64(aNonceWordA, 45U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2373193062766802082U;
            aOrbiterJ = RotL64((aOrbiterJ * 4213691513185791519U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 16318403285501718552U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8456043288604687045U;
            aOrbiterH = RotL64((aOrbiterH * 10556964529144571683U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10572534930284516528U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14616251186735204677U) ^ RotL64(aNonceWordG, 3U);
            aOrbiterI = RotL64((aOrbiterI * 2048651204265459805U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 13U)) + RotL64(aNonceWordB, 13U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 53U)) + aOrbiterH) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterI, 11U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + RotL64(aNonceWordE, 23U)) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 46U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 5U) ^ RotL64(aNonceWordH, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23283U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23957U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordC, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18583U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 23378U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 3U)) + (RotL64(aCross, 18U) ^ RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 47U)) + 6069475454765660321U;
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 35U)) + 11483704742497268068U) + aOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 11055697447388986418U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 37U)) + 10897095046039997004U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordG, 45U);
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 13U)) + 4731637118230457840U) + RotL64(aNonceWordD, 39U);
            aOrbiterG = (aWandererF + RotL64(aCross, 27U)) + 13855839187084986751U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 44U)) + 5328208115460188239U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12479538544291412985U) + RotL64(aNonceWordE, 27U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10740165998792608231U;
            aOrbiterE = RotL64((aOrbiterE * 14046827922294477379U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6492798157284955373U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13056825957483891921U;
            aOrbiterB = RotL64((aOrbiterB * 14882112110627751751U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2068184064919194657U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5656302738780746294U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16493021179127646345U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11193756120230763294U) + RotL64(aNonceWordB, 44U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17306750816837208999U) ^ aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7949360041241439741U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12952818800389361804U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15380412293642628312U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2914662289178925547U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7706090204767242996U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14598802276412649570U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4821408736292041399U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17819762117328075515U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6481384240915075101U;
            aOrbiterC = RotL64((aOrbiterC * 4836701121865783029U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 6U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 54U) + RotL64(aOrbiterE, 27U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterA, 36U)) + RotL64(aNonceWordA, 7U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererF = aWandererF + (((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordF, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27661U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27968U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 12U) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27022U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((aIndex + 26724U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 20U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererA + RotL64(aCross, 44U)) + 9751314027302668907U) + RotL64(aNonceWordC, 31U);
            aOrbiterG = (aWandererC + RotL64(aPrevious, 37U)) + 12175450995523107056U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 17519694958730119552U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 9093525527925682263U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 3713831321786810138U) + RotL64(aNonceWordG, 47U);
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 21U)) + 10108355209191835040U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 57U)) + 12956307447311314768U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 1904298513945877359U) + aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4658049993308574460U;
            aOrbiterK = RotL64((aOrbiterK * 10482422152074338611U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 9826333658248851902U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12058666914724365134U) ^ RotL64(aNonceWordH, 9U);
            aOrbiterB = RotL64((aOrbiterB * 964233873188373939U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 2516574707110528099U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 13335308331049750235U;
            aOrbiterG = RotL64((aOrbiterG * 5880227828760598587U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8230749255538495304U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16536559486797811486U;
            aOrbiterJ = RotL64((aOrbiterJ * 7097036838156464969U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12387639130570188998U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8459259798142872020U) ^ RotL64(aNonceWordE, 13U);
            aOrbiterH = RotL64((aOrbiterH * 8001346480955847013U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16083784052002800300U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1957284290736468379U;
            aOrbiterD = RotL64((aOrbiterD * 5046501301740813065U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7349538179311335863U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 16395170077006105258U;
            aOrbiterF = RotL64((aOrbiterF * 4230485452156662763U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 5U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterG, 12U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + RotL64(aCarry, 43U)) + RotL64(aNonceWordD, 30U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 51U)) + aOrbiterB) + RotL64(aCarry, 19U)) + RotL64(aNonceWordB, 51U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 53U);
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

void TwistExpander_BasketBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
                     TwistDomainConstants *pConstants,
                     TwistDomainSaltSet *pDomainSaltSet,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBDBF9BDEF542FC5DULL + 0xD98798524F58B0F3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEB1551AD5106D369ULL + 0xD58322F9361BB308ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8FBC08289B3C9BE5ULL + 0xD4A15C2BB827E39AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xC28B70ACBD2DC9A7ULL + 0xC4664AB34BCF3E03ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCE565E7DEF793E19ULL + 0xBFA10A9F3A94EA9FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xDDB7FECF0DFDC84BULL + 0xD8FD2E2BE699B619ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCFBB42A7A9B7EBE9ULL + 0x8775E65E37C6A678ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD06879E3EA35EE13ULL + 0x82A73E10976FE36DULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 27U) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5030U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6438U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 26U) ^ RotL64(aNonceWordA, 41U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4859U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1378U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 23U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 23U)) + 5510690816044082200U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 3U)) + 15967820875033940530U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 27U)) + 539348720848176221U;
            aOrbiterI = (aWandererH + RotL64(aCross, 5U)) + 15779318183635560817U;
            aOrbiterK = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 14511058534424187469U) + aOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 5811130556873428391U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 39U)) + 1085928476499444025U) + RotL64(aNonceWordC, 52U);
            aOrbiterJ = (aWandererI + RotL64(aScatter, 43U)) + 6973335316600768130U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 53U)) + 10747243745475009744U;
            aOrbiterE = (aWandererB + RotL64(aCross, 20U)) + 1072260008981349754U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 37U)) + 2018772405352495753U) + RotL64(aNonceWordD, 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 1092091597048996547U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15103140149542167197U;
            aOrbiterH = RotL64((aOrbiterH * 621856991658027989U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 13194619321108681542U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 16749188603268621850U) ^ RotL64(aNonceWordB, 7U);
            aOrbiterG = RotL64((aOrbiterG * 9575408950550922039U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7427959503086895166U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9895804051379551393U;
            aOrbiterC = RotL64((aOrbiterC * 2701997336201570715U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4526020800679774259U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4484850928870048176U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17556987520625677313U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 1837404844299040155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 15213208978489570694U;
            aOrbiterF = RotL64((aOrbiterF * 7062740584650274133U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9615231781751396800U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15872192167825648096U;
            aOrbiterD = RotL64((aOrbiterD * 2900526493682580729U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12530672039655918903U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10617836782870315804U;
            aOrbiterA = RotL64((aOrbiterA * 9716778004909794973U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 550750725406860977U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3498554352021622907U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9846933294851238495U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4059346317776216057U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14161853870874499023U;
            aOrbiterK = RotL64((aOrbiterK * 8601560894939097781U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4088411647683253905U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9321241420172776158U) ^ RotL64(aNonceWordE, 23U);
            aOrbiterJ = RotL64((aOrbiterJ * 4167888281125330225U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8527337525861632945U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5510690816044082200U;
            aOrbiterE = RotL64((aOrbiterE * 12464836001483233379U), 21U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 40U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 60U)) + aOrbiterI);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterF, 51U));
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterK, 53U)) + RotL64(aNonceWordF, 55U));
            aWandererD = aWandererD + (((RotL64(aIngress, 12U) + RotL64(aOrbiterD, 29U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterE, 41U)) + aWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterA, 20U));
            aWandererH = aWandererH + (((RotL64(aIngress, 38U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + RotL64(aNonceWordG, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterI, 3U));
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 34U) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13616U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13357U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordE, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13198U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 16282U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 47U)) + 3917730204724097072U) + RotL64(aNonceWordB, 13U);
            aOrbiterA = (aWandererC + RotL64(aPrevious, 29U)) + 1874642340716212824U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 6900165757434854160U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 35U)) + 12750946097023807161U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 3U)) + 6563216048479513594U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 43U)) + 14960240191349450795U) + RotL64(aNonceWordE, 24U);
            aOrbiterK = (aWandererD + RotL64(aScatter, 27U)) + 16306180275951788289U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 48U)) + RotL64(aCarry, 35U)) + 6502066618271045547U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 57U)) + 6219852857850888738U;
            aOrbiterD = (aWandererK + RotL64(aCross, 13U)) + 2272931312452845850U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 37U)) + 3028929882263199463U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6067393030073568112U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10094809900437037258U;
            aOrbiterF = RotL64((aOrbiterF * 18095564940730322769U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 5962414178157074575U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15755563045799129417U;
            aOrbiterA = RotL64((aOrbiterA * 3692603590609922031U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6321455513889880590U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 1197435601998121700U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ RotL64(aNonceWordA, 19U);
            aOrbiterE = RotL64((aOrbiterE * 17693996266260557625U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12496949381666299968U) + RotL64(aNonceWordF, 31U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6357070235648527030U;
            aOrbiterK = RotL64((aOrbiterK * 2931486644220862433U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 8423760160877540210U) + aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8090246492554850768U;
            aOrbiterJ = RotL64((aOrbiterJ * 2949407491181921633U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 11436635942985063755U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17086363141014359856U;
            aOrbiterC = RotL64((aOrbiterC * 10504127577318206801U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10734017887545474935U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 375515325165740779U;
            aOrbiterH = RotL64((aOrbiterH * 9980486695448151709U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5217148491945389821U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 14696058217023530058U;
            aOrbiterG = RotL64((aOrbiterG * 11026674782236654799U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11869055287836412650U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16951500118659983436U;
            aOrbiterI = RotL64((aOrbiterI * 4304372681583055077U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7866300390953569803U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 18017335943787362993U;
            aOrbiterD = RotL64((aOrbiterD * 15683049583437004889U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2477944286851267725U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3917730204724097072U;
            aOrbiterB = RotL64((aOrbiterB * 6617615984203047419U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterG, 53U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + RotL64(aNonceWordD, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 60U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + RotL64(aNonceWordG, 51U));
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 39U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 6U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererJ, 52U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordA, 39U)) ^ RotL64(aNonceWordG, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23981U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 16928U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordH, 43U)) ^ RotL64(aNonceWordE, 24U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24431U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 22657U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 4U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererJ + RotL64(aCross, 51U)) + 14686411261024919129U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 43U)) + 7514582233957632005U) + aOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aIngress, 39U)) + 6520710480103365552U) + RotL64(aNonceWordE, 46U);
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 1983621978676188036U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 9003524602590749672U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 10U)) + 6428568234045228995U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 13U)) + 8656552687136446989U;
            aOrbiterC = (aWandererC + RotL64(aCross, 27U)) + 16916248288415922490U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 47U)) + 9740237548002535784U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 18U)) + 907561000814618339U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 29U)) + 4751108900841197631U) + RotL64(aNonceWordC, 15U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 167774899400732287U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 11907484918310854962U;
            aOrbiterH = RotL64((aOrbiterH * 7213139491146402985U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14910318613649863924U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14882888155751455276U;
            aOrbiterI = RotL64((aOrbiterI * 11394136445442060201U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16175942562693781908U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11022373758481651102U;
            aOrbiterE = RotL64((aOrbiterE * 6836331461393816027U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12548405399045031548U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10850926364556828443U;
            aOrbiterA = RotL64((aOrbiterA * 16231561687709867431U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13391684887911141790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14648937281264822988U;
            aOrbiterC = RotL64((aOrbiterC * 6533299316940026059U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8298658887198526821U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13822977698661348891U;
            aOrbiterG = RotL64((aOrbiterG * 17769262972278410937U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7505646847564645719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3238749538197209166U;
            aOrbiterB = RotL64((aOrbiterB * 15394286542600778567U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15853506915123709257U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8426329899401071248U) ^ RotL64(aNonceWordD, 55U);
            aOrbiterJ = RotL64((aOrbiterJ * 1330397096577715113U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14848635392815613098U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3549927798350175044U;
            aOrbiterD = RotL64((aOrbiterD * 1899044682313056949U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1798973117197750802U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13056711228618953977U;
            aOrbiterF = RotL64((aOrbiterF * 9102877396419306689U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1395893547965799281U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 14686411261024919129U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]) ^ RotL64(aNonceWordB, 47U);
            aOrbiterK = RotL64((aOrbiterK * 17075377081365066067U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 19U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordA, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterF, 60U)) + aWandererUpdateSaltA[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 24U) + aOrbiterG) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 18U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA) + RotL64(aNonceWordH, 31U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 18U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 11U) ^ RotL64(aNonceWordC, 3U)) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26701U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneB[((aIndex + 31381U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 60U) ^ RotL64(aNonceWordB, 43U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31927U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 28658U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aIngress, 38U)) + RotL64(aCarry, 19U)) + 12535417189990029950U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 6204401443676390273U) + RotL64(aNonceWordE, 9U);
            aOrbiterB = ((aWandererH + RotL64(aCross, 53U)) + 869613505613154672U) + RotL64(aNonceWordA, 55U);
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 21U)) + 15053590879563855802U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aCross, 5U)) + 13338989605204591428U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 51U)) + 18306470022403825392U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 14U)) + 1150696349434090218U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 13549541786420596437U;
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 19U)) + 14302878430259588461U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 35U)) + 4660437084477165225U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 47U)) + 1653628537860912069U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5594199757006711631U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11008472193138708891U;
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3668516817279364310U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 128159531749679984U;
            aOrbiterH = RotL64((aOrbiterH * 4523246859249826987U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 6378674346113979108U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11438762460659123362U) ^ RotL64(aNonceWordC, 37U);
            aOrbiterA = RotL64((aOrbiterA * 2733309638158283953U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 10624263004446482910U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 12546839706919241411U;
            aOrbiterE = RotL64((aOrbiterE * 11468326687628079347U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8466639576503293921U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5828694979857951504U;
            aOrbiterI = RotL64((aOrbiterI * 7835487310289634515U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16496305151014092976U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 589464613876410567U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13190816610718051897U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4168532743415647825U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15944887793736489375U;
            aOrbiterD = RotL64((aOrbiterD * 17273403561158196717U), 57U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterJ) + 11642456814106259483U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordD, 41U);
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1609897693632334867U;
            aOrbiterF = RotL64((aOrbiterF * 12912773555616819941U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14950238412766325479U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11862438528287402255U;
            aOrbiterG = RotL64((aOrbiterG * 7635864312080265695U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5900629306795222263U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 3221591991392500536U;
            aOrbiterK = RotL64((aOrbiterK * 7188525011266868855U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 16938699391746264010U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12535417189990029950U;
            aOrbiterC = RotL64((aOrbiterC * 18212319484142613215U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterI, 50U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterB, 21U));
            aWandererH = aWandererH + (((RotL64(aScatter, 42U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 37U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 54U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aNonceWordB, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + RotL64(aCarry, 51U)) + RotL64(aNonceWordG, 28U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 26U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterB, 29U)) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 58U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD87EA3BE71C03595ULL + 0xA45A742E7823BA6BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9BDA734CDEED95F9ULL + 0x9F2FFED766D5358EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xCFEED85F6ACA9803ULL + 0xA622E96F6B0A3034ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA15140801CDCB977ULL + 0xF297CDA6402716B5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xD0B13B9B76193863ULL + 0xC33C791A36B3940CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x844244162E16FD13ULL + 0x8CD388C6F92C2CA2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB0CEC4293F2F1285ULL + 0x9762E9AA9CE15D43ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFEE3E59F18DC0A85ULL + 0xC205EB36BB030D4CULL);
    std::uint64_t aDomainWordIngress = pConstants->mIngress;
    std::uint64_t aDomainWordScatter = pConstants->mScatter;
    std::uint64_t aDomainWordCross = pConstants->mCross;
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 46U) ^ RotL64(aNonceWordG, 37U)) ^ RotL64(aNonceWordH, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2462U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneC[((aIndex + 1913U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordD, 43U)) ^ RotL64(aNonceWordE, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3380U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 906U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U)) + (RotL64(aPrevious, 54U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aScatter, 27U)) + 11998579547770778580U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 20U)) + RotL64(aCarry, 3U)) + 8409465187298704610U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 35U)) + 3470222286110333500U;
            aOrbiterE = (((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 5704486785203069994U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 13U)) + 10334944660253279633U) + RotL64(aNonceWordC, 21U);
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 39U)) + 7626852700722567477U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 3U)) + 14631310754943209743U) + RotL64(aNonceWordH, 11U);
            aOrbiterA = ((aWandererB + RotL64(aIngress, 51U)) + 807160297237854120U) + aOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 56U)) + 5624154783624196107U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 4971444394698940423U) + RotL64(aNonceWordE, 57U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6340057638461027062U;
            aOrbiterB = RotL64((aOrbiterB * 12027586111086798629U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 9003019862787819481U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13632057463595873033U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12575202147280216765U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12766104026871797746U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4062118445824915939U;
            aOrbiterA = RotL64((aOrbiterA * 13130770039048080701U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5258212525426469978U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9956946981015983939U;
            aOrbiterJ = RotL64((aOrbiterJ * 8106382657040497669U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10837606223056473999U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 13292864885504191134U;
            aOrbiterF = RotL64((aOrbiterF * 4445739587553669471U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 166087925900318658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6786842221885441388U;
            aOrbiterE = RotL64((aOrbiterE * 4411147600413147773U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16888086378070246404U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 5240855484445974002U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 402652898573422271U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6874866669211571608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 732890824978127460U;
            aOrbiterC = RotL64((aOrbiterC * 3776365957702257453U), 37U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 5541380495707308058U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1]) + RotL64(aNonceWordA, 25U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17947326584411475765U;
            aOrbiterK = RotL64((aOrbiterK * 10920952349981652899U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 12U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 23U)) + aOrbiterF) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterF, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 11U)) + RotL64(aNonceWordB, 52U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterD, 27U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + RotL64(aCarry, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + RotL64(aNonceWordG, 35U));
            aWandererG = aWandererG + ((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterC, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererG, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordH, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8661U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6867U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 24U) ^ RotL64(aNonceWordB, 41U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7810U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 6730U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 53U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 5U)) + 7632760812370906911U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 6007174525479723089U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 36U)) + 3362829642521821048U;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 23U)) + RotL64(aCarry, 11U)) + 18009548556107978286U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 57U)) + 17880909432272697327U;
            aOrbiterI = (((aWandererC + RotL64(aCross, 13U)) + 15961567935420752568U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordG, 27U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 28U)) + RotL64(aCarry, 27U)) + 10136559064656837921U;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + 17622019364405410277U) + RotL64(aNonceWordB, 41U);
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 19U)) + 6927494824421416306U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 7125170407794874847U) + aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12342273503071032250U;
            aOrbiterA = RotL64((aOrbiterA * 867417849555857179U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterA) + 14997696377476124836U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) + RotL64(aNonceWordE, 61U);
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14874498694181230698U;
            aOrbiterF = RotL64((aOrbiterF * 4026127545746010937U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2549397729130885686U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4217995818662767955U;
            aOrbiterB = RotL64((aOrbiterB * 5525525344485251063U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4706089044415442525U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17983900172670031015U) ^ aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 541552737180932879U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1904937798143929988U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10620877287033139483U;
            aOrbiterJ = RotL64((aOrbiterJ * 16711012562024287213U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15681091173163181525U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2655543246639000084U) ^ RotL64(aNonceWordF, 26U);
            aOrbiterH = RotL64((aOrbiterH * 16686375598149755947U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 2647895110857289213U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 5581609212017175954U;
            aOrbiterK = RotL64((aOrbiterK * 15330263616699031311U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13609076329627787987U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6244266279516622070U;
            aOrbiterI = RotL64((aOrbiterI * 12488345779236971095U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 5289624364508923581U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16351476803965903112U;
            aOrbiterE = RotL64((aOrbiterE * 9012522724650442597U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterJ, 4U));
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + RotL64(aNonceWordA, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterI) + RotL64(aNonceWordD, 35U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 52U) + aOrbiterF) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 34U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 27U) ^ RotL64(aNonceWordE, 54U)) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13435U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16371U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 28U) ^ RotL64(aNonceWordD, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11840U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13659U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aPrevious, 60U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 34U)) + RotL64(aCarry, 35U)) + 4384716820085860551U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 9715780315942116888U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 53U)) + 15963520052789178632U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordH, 31U);
            aOrbiterE = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 51U)) + 14346700690686392938U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 19U)) + 6005518012489966643U;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 3U)) + 2506732930310252119U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 29U)) + 16782163084851775826U) + aOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordC, 37U);
            aOrbiterH = (aWandererB + RotL64(aIngress, 21U)) + 823673076571076303U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 39U)) + 1634084509064077736U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1288134975466877686U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2998220403162908444U;
            aOrbiterD = RotL64((aOrbiterD * 4321412662318298283U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 220430672180734911U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10223923547068528867U;
            aOrbiterB = RotL64((aOrbiterB * 12577370238343872139U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11696469696177647608U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6545430420379636963U;
            aOrbiterE = RotL64((aOrbiterE * 8387163146257553773U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 79691451831797107U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8971444023498649419U;
            aOrbiterJ = RotL64((aOrbiterJ * 7148919880477390009U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 5624403902454498793U) + RotL64(aNonceWordG, 27U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9468064161002030997U) ^ RotL64(aNonceWordD, 58U);
            aOrbiterC = RotL64((aOrbiterC * 8243560528100864595U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4619361544913629805U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8728730962617599223U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9099675924074253030U;
            aOrbiterA = RotL64((aOrbiterA * 5525644236954497523U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 3298303921318288541U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 5953276499411658358U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10565471305001292693U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 6725769507592688539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1057277456510215817U;
            aOrbiterK = RotL64((aOrbiterK * 8269412198279297075U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 14U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 6U)) + aOrbiterD) + aWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aNonceWordA, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterA) + RotL64(aNonceWordB, 25U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 23U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 30U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 43U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 53U) ^ RotL64(aNonceWordG, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21714U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17722U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordC, 51U)) ^ RotL64(aNonceWordA, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19938U)) & S_BLOCK1], 28U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17196U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCarry, 29U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererG + RotL64(aScatter, 51U)) + 2672739400294801233U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordA, 49U);
            aOrbiterI = ((aWandererC + RotL64(aCross, 47U)) + 8475624545015101850U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 42U)) + 1252755112289831257U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 23U)) + 7938039507649183387U) + RotL64(aNonceWordH, 31U);
            aOrbiterG = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 8167413146948861022U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 23U)) + 17712313989694374353U;
            aOrbiterC = (aWandererD + RotL64(aCross, 38U)) + 7637042279892596975U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 11U)) + 15770412950033467341U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 3951812021898608685U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8656983621098246507U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17943342344730687317U;
            aOrbiterF = RotL64((aOrbiterF * 16495519451034883813U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3087677463651608668U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16493240011924342788U;
            aOrbiterG = RotL64((aOrbiterG * 16898479041530771871U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7750923317452683057U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2185924841611106546U;
            aOrbiterC = RotL64((aOrbiterC * 708072658250726381U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14676868738946722416U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 6849098251696302393U) ^ RotL64(aNonceWordD, 55U);
            aOrbiterB = RotL64((aOrbiterB * 2599806275837778069U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 17817755047153606419U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 9900465270314068757U;
            aOrbiterJ = RotL64((aOrbiterJ * 9267925873983176685U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 11380000891112113701U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15930503831156546113U;
            aOrbiterD = RotL64((aOrbiterD * 14450535035065393845U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5439183530402949780U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3731802052051181843U;
            aOrbiterA = RotL64((aOrbiterA * 7739775058947333169U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 14432344583247783600U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 16192098795467501636U;
            aOrbiterE = RotL64((aOrbiterE * 6285466374319549047U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1523272672673940290U) + RotL64(aNonceWordB, 53U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7462092373525113574U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15067751170235540679U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 26U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 3U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterB, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterB, 52U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ) + RotL64(aNonceWordF, 27U)) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF);
            aWandererE = aWandererE + (((((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 51U)) + RotL64(aNonceWordE, 14U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterE, 27U));
            aWandererB = aWandererB + (((RotL64(aIngress, 40U) + RotL64(aOrbiterI, 12U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 22U) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24950U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22916U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 51U) ^ RotL64(aNonceWordB, 34U)) ^ RotL64(aNonceWordE, 23U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27288U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26559U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 14U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aScatter, 13U)) + 12027839670755583592U) + RotL64(aNonceWordB, 59U);
            aOrbiterD = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 15380130703509859843U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 42U)) + 4590907433867798074U) + RotL64(aNonceWordH, 35U);
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 1754574023602519724U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 5U)) + 9832756659564903767U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 53U)) + 5035088494491470403U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 57U)) + 14199170923323644638U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 8325619421264440438U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 34U)) + 969534320779067977U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 270575869402913847U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 13344806516599578910U;
            aOrbiterB = RotL64((aOrbiterB * 10193544126281901579U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15143147951139409101U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 14425582489214169238U;
            aOrbiterI = RotL64((aOrbiterI * 16893787086337916355U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13951127523239064584U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14177925225918293579U;
            aOrbiterK = RotL64((aOrbiterK * 13079514031864998485U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8258920744278218901U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7408161179397242453U;
            aOrbiterC = RotL64((aOrbiterC * 975737128100519169U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8581481606764773468U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10078416198417433133U;
            aOrbiterH = RotL64((aOrbiterH * 1102721083915858247U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 18299772198826189580U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 18304668908084397946U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ RotL64(aNonceWordG, 41U);
            aOrbiterG = RotL64((aOrbiterG * 10589455451200578687U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16729632621573817223U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13362300981585573239U;
            aOrbiterA = RotL64((aOrbiterA * 9824473895535518785U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8629682832849915380U) + RotL64(aNonceWordC, 25U);
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6852852009091469641U;
            aOrbiterD = RotL64((aOrbiterD * 11912646687050011915U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7433098156961745198U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10931806208899417308U;
            aOrbiterF = RotL64((aOrbiterF * 14699197041038067483U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 50U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 56U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 40U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + RotL64(aNonceWordF, 57U));
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 19U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterG, 36U)) + aOrbiterB) + RotL64(aNonceWordA, 20U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 23U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordC, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32134U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 30265U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordA, 46U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27850U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 32500U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 40U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aIngress, 12U)) + 9914837590440975587U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 6706125076401958051U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 16570817772679258409U;
            aOrbiterE = (aWandererB + RotL64(aScatter, 43U)) + 6843705658115186948U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 57U)) + 16099930446791572351U) + RotL64(aNonceWordF, 49U);
            aOrbiterA = (((aWandererA + RotL64(aIngress, 52U)) + 5420550009556030459U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + RotL64(aNonceWordB, 47U);
            aOrbiterC = (aWandererE + RotL64(aPrevious, 19U)) + 5729549069420177477U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 15590601126188675834U;
            aOrbiterD = (aWandererH + RotL64(aIngress, 27U)) + 13044027390998620029U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 11068338135659636772U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 6584988841809544332U;
            aOrbiterG = RotL64((aOrbiterG * 1683336180438945439U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8516813219883915404U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10647314042912492785U;
            aOrbiterF = RotL64((aOrbiterF * 15559481057047148785U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 201691689889605304U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15512161798401184003U;
            aOrbiterC = RotL64((aOrbiterC * 11473219183982564709U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3883760518944464145U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13861805129175491145U) ^ RotL64(aNonceWordD, 3U);
            aOrbiterK = RotL64((aOrbiterK * 17194438894492581181U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12019138626550801486U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13030350224959652248U) ^ RotL64(aNonceWordE, 53U);
            aOrbiterD = RotL64((aOrbiterD * 11724200983306280107U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 2643807255422544248U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 4127143302485631794U;
            aOrbiterH = RotL64((aOrbiterH * 5441038881111578487U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14602951930809633069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4555737199162278494U;
            aOrbiterE = RotL64((aOrbiterE * 12415825635220991865U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6343143902997169834U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10404783711336491985U;
            aOrbiterA = RotL64((aOrbiterA * 6235474458879439079U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7406959231434835393U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6684368109277850196U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8760360417572331159U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 54U);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 23U)) + aOrbiterA) + RotL64(aNonceWordH, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 38U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterE) + RotL64(aCarry, 19U)) + RotL64(aNonceWordG, 28U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 58U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 34U));
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB7BC9BF3B9149E93ULL + 0x81177F71A6A46CEEULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC8E17B7BD845717DULL + 0xA468E2CCC9476923ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC3798BCD3C9E322BULL + 0xA838B742BF613EB5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFBCB1FD0F73ECE9DULL + 0xCFF47C814F5B8F3AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCC02462A2357E7BFULL + 0xA0862626588559F0ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCE9409020A9A0285ULL + 0x9FDA81BB6129BA31ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB05988BCC33DA54BULL + 0xE001EEC0D93D361AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD05311C64F4433CBULL + 0xCDEB801C1A996D34ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 57U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordE, 26U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1989U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4123U)) & W_KEY1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordD, 47U)) ^ RotL64(aNonceWordF, 14U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5260U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 543U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCross, 11U)) ^ (RotL64(aPrevious, 54U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 19U)) + 16519040829220310189U) + aPhaseAOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 23U)) + 6888002778416941825U) + RotL64(aNonceWordG, 59U);
            aOrbiterD = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 1310832187746534025U;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 53U)) + 5890888009051281674U) + RotL64(aNonceWordA, 7U);
            aOrbiterJ = (aWandererE + RotL64(aCross, 51U)) + 5143864838362464857U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 11U)) + 15591534069452660003U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 57U)) + 1466867671765325096U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 13931443680107902488U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15400747367673245552U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7011651369456453127U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2836975369734495759U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2370720358274970117U;
            aOrbiterJ = RotL64((aOrbiterJ * 4615571902817575375U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3470677184188006133U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 7175584278499266723U;
            aOrbiterI = RotL64((aOrbiterI * 10067096593682482345U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6095078817776863055U) + RotL64(aNonceWordH, 19U);
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2176637999243513070U;
            aOrbiterK = RotL64((aOrbiterK * 12215701810843975501U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5580391239754903129U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 15196125567953871184U;
            aOrbiterA = RotL64((aOrbiterA * 12686361960729564519U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12787014151503209931U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 1523153207064063495U) ^ RotL64(aNonceWordF, 13U);
            aOrbiterF = RotL64((aOrbiterF * 3113907543551927561U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12973289026485937829U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9087439766232078173U;
            aOrbiterB = RotL64((aOrbiterB * 5817029335999350327U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 60U));
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordE, 28U));
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 4U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordB, 39U)) + aPhaseAWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterB) + aPhaseAWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererH);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererA, 42U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 14U) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8137U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9354U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordA, 37U)) ^ RotL64(aNonceWordF, 21U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9662U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 8613U)) & W_KEY1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 51U)) ^ (RotL64(aCarry, 18U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 20U)) + 15036852811491820366U) + RotL64(aNonceWordC, 58U);
            aOrbiterG = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 305637140752898475U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 11948631574496129610U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 27U)) + 5321623592482991426U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 5U)) + 4075270159062690728U) + RotL64(aNonceWordD, 9U);
            aOrbiterB = ((aWandererD + RotL64(aCross, 35U)) + 15111580500356908928U) + aPhaseAOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 7244150695504160363U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5131563519577488862U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5881954992088651371U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2424421828597294607U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12780935808751507998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 12599159643925470226U;
            aOrbiterA = RotL64((aOrbiterA * 17690046932587062701U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9466589929741834066U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6093158735705189789U;
            aOrbiterE = RotL64((aOrbiterE * 7453778295800853653U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17461243886150519249U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15456408913739900718U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16093292401746174671U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11260643903290392780U) + RotL64(aNonceWordE, 39U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7870342756041882616U;
            aOrbiterJ = RotL64((aOrbiterJ * 2431528656086173419U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 134484990005888936U) + RotL64(aNonceWordB, 43U);
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10626896209992890407U;
            aOrbiterB = RotL64((aOrbiterB * 12034131076645285597U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14031164129515132292U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 1771835705730244212U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 186981668443596623U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 54U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 11U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 61U)) + aPhaseAWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 50U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 3U)) + RotL64(aNonceWordH, 49U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterA, 27U));
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 43U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 51U) ^ RotL64(aNonceWordC, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15613U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13379U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordF, 40U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16332U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 10966U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 13204735390996728477U;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 851171359595647173U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 16745304202825290723U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 51U)) + 562392736584913979U;
            aOrbiterB = (((aWandererI + RotL64(aIngress, 22U)) + 3244267012529053918U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordA, 24U);
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 3U)) + 17282536111067869133U) + RotL64(aNonceWordH, 45U);
            aOrbiterJ = (aWandererD + RotL64(aScatter, 29U)) + 14851130066471729068U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5256130407952363129U) + RotL64(aNonceWordG, 7U);
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 2904742485828362001U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1]) ^ RotL64(aNonceWordD, 25U);
            aOrbiterF = RotL64((aOrbiterF * 12941135856735075457U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3723346325449225387U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5344621093694027341U;
            aOrbiterI = RotL64((aOrbiterI * 9044881458629673499U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12919263300833603026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17989801264160996071U;
            aOrbiterC = RotL64((aOrbiterC * 15468293047311883751U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 5022175042377172157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16684822380107847758U;
            aOrbiterA = RotL64((aOrbiterA * 2834049270263837537U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2740326510600876682U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13981423865219318820U;
            aOrbiterB = RotL64((aOrbiterB * 14593082145080056441U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 231945878229848395U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14139797734944312580U;
            aOrbiterG = RotL64((aOrbiterG * 6492256080432266407U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 16704102101387552373U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 8506734780526852552U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4684566118627414659U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterA, 27U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + aOrbiterC) + RotL64(aOrbiterB, 35U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 51U)) + aOrbiterC) + RotL64(aNonceWordE, 49U));
            aWandererK = aWandererK + (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordB, 15U));
            aWandererG = aWandererG + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 6U)) + aOrbiterF) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 6U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordD, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17882U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17794U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 5U) ^ RotL64(aNonceWordC, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21564U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18834U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 22U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aPrevious, 6U)) + 2330952702412094686U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 21U)) + 7820188225935060799U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 9347644591709839145U;
            aOrbiterE = (aWandererH + RotL64(aCross, 57U)) + 2288624878446846870U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 9358977729492824128U) + RotL64(aNonceWordF, 15U);
            aOrbiterA = (((aWandererB + RotL64(aCross, 13U)) + 1858511275052455039U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordA, 11U);
            aOrbiterF = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 13715478509322292552U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16413396625604260455U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17714322215518432705U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1904184102419934333U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16188315436202861122U) + RotL64(aNonceWordD, 21U);
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5564445841368207813U;
            aOrbiterA = RotL64((aOrbiterA * 14125834616162835983U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 13717068949900594673U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 27U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14143659432287313765U;
            aOrbiterD = RotL64((aOrbiterD * 17281441046722262917U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5729546141908425670U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4297827922736712074U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13631630436759768885U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 829520109395163673U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11547160328525174295U;
            aOrbiterG = RotL64((aOrbiterG * 4759690159673049775U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2907177944512117206U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11100346409065275671U;
            aOrbiterE = RotL64((aOrbiterE * 17927994356809011637U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1344592529249949068U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6470438516791143572U;
            aOrbiterF = RotL64((aOrbiterF * 13339390828725370475U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 21U)) + aOrbiterI) + RotL64(aNonceWordB, 60U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + RotL64(aNonceWordG, 41U)) + aPhaseAWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 29U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 44U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22796U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26304U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 29U) ^ RotL64(aNonceWordH, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22836U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 22601U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 6U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 12131317914288566437U) + RotL64(aNonceWordD, 43U);
            aOrbiterJ = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 5672805657999385496U;
            aOrbiterD = (((aWandererH + RotL64(aScatter, 5U)) + 3581710244233124197U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 13U);
            aOrbiterE = (aWandererA + RotL64(aIngress, 19U)) + 15251296040538489436U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 11U)) + 11295008604679904153U) + aPhaseAOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 2230897493419504490U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 60U)) + 7109600123297458999U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13119156643107683803U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14755160867807355250U) ^ RotL64(aNonceWordE, 9U);
            aOrbiterD = RotL64((aOrbiterD * 10007087518844899239U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16829363373287496832U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 16981122946707720883U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5394974422201576627U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8806000776958603317U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16810923047720876014U;
            aOrbiterE = RotL64((aOrbiterE * 17872735050219539145U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 8129657889554436328U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8653100378491974463U;
            aOrbiterJ = RotL64((aOrbiterJ * 11395283153912468661U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 17048985838727432415U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10892675550889823573U;
            aOrbiterA = RotL64((aOrbiterA * 976298937314081913U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 15960158965421254346U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]) + RotL64(aNonceWordC, 11U);
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12290011578634850001U;
            aOrbiterI = RotL64((aOrbiterI * 9280475585104357745U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16265047040311479093U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10312956912303656248U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3012584393253845131U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 3U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterF, 37U)) + RotL64(aNonceWordF, 7U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 51U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 12U)) + RotL64(aNonceWordA, 56U));
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + aPhaseAWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterA, 23U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 30U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 36U) ^ RotL64(aNonceWordF, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29362U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 29623U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 38U) ^ RotL64(aNonceWordB, 21U)) ^ RotL64(aNonceWordA, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27404U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 28827U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 11U)) + (RotL64(aIngress, 40U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 27U)) + 9435962834163239322U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 47U)) + 10524704356081318973U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 7403401305665208680U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 58U)) + 7525414805023556493U) + RotL64(aNonceWordH, 3U);
            aOrbiterA = (((aWandererF + RotL64(aIngress, 35U)) + 1116686470029070951U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1]) + RotL64(aNonceWordD, 59U);
            aOrbiterB = (aWandererA + RotL64(aCross, 5U)) + 13257612299137802420U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 9181543003986598283U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9739384852307501107U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11308402900229016057U;
            aOrbiterI = RotL64((aOrbiterI * 12690186771773188967U), 29U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterI) + 14935167593705272337U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + RotL64(aNonceWordC, 43U);
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7171824007631943535U;
            aOrbiterA = RotL64((aOrbiterA * 4839974427616194289U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8068411284829563567U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 12350207458513447578U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 813973258659041895U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17039236343991574134U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 18291683592714999632U;
            aOrbiterJ = RotL64((aOrbiterJ * 7771718817924840713U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6239616841884430968U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10604527977569876774U;
            aOrbiterH = RotL64((aOrbiterH * 6972820410084939637U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1707724300671717658U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3802268808625297647U;
            aOrbiterC = RotL64((aOrbiterC * 11296811630387191563U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9423064323799920219U) + RotL64(aNonceWordF, 7U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 242153923313096551U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12117679073775630197U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 51U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererD = aWandererD + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterC, 19U)) + aPhaseAWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 39U)) + RotL64(aNonceWordE, 58U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 34U)) + RotL64(aNonceWordG, 45U));
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD43FF15790E7FB19ULL + 0xDAC32D9F71FFF792ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB1BA861B22411D9FULL + 0xEBCB823EA360C3E0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB49837858D12F9B9ULL + 0xDF407B332677CB63ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA529C7D434D2A81BULL + 0xF575EBD1D2118ADAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBBC913A3234F413BULL + 0xAE4AB4B6ED89917FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE5F3A689441805E9ULL + 0xBE9978106E35A26AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC45CCB9E529E2AD5ULL + 0x9976323684B51DD7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC268E08B2C4B2611ULL + 0xDD979D1C95BA5570ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4190U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 403U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordA, 54U)) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4674U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1368U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 35U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 16124889768301047791U) + aPhaseBOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 37U)) + 11912338587186717280U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 8594012868813114354U) + RotL64(aNonceWordC, 47U);
            aOrbiterB = (((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 23U)) + 18281043566156682815U) + RotL64(aNonceWordA, 31U);
            aOrbiterH = (aWandererC + RotL64(aScatter, 47U)) + 16853106130200942302U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2611212958619673086U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 18039472325066855180U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10213999643376367785U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14495785571345122046U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 4556063793412832418U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13166927543135467627U), 27U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 14896419970271244358U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 880028529183500036U;
            aOrbiterB = RotL64((aOrbiterB * 14228281807461251361U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2379557167489415783U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 11854373946064529806U) ^ RotL64(aNonceWordE, 14U);
            aOrbiterJ = RotL64((aOrbiterJ * 150755294320438887U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1487252775956449964U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 12777924204511625545U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1366019527386994789U), 3U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 52U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 4U)) + aOrbiterJ) + RotL64(aCarry, 37U)) + RotL64(aNonceWordF, 15U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterA, 13U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 4U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 39U)) + aOrbiterB) + RotL64(aNonceWordG, 25U)) + aPhaseBWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 46U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 30U) ^ RotL64(aNonceWordA, 39U)) ^ RotL64(aNonceWordG, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9136U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((aIndex + 8681U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 14U) ^ RotL64(aNonceWordE, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8811U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 8864U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 5U)) + (RotL64(aIngress, 52U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 5960680319644404115U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 3U)) + 16050752633567034185U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 57U)) + 8447503223226854741U) + RotL64(aNonceWordB, 22U);
            aOrbiterD = (((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 14176813813397917591U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((((aWandererF + RotL64(aPrevious, 20U)) + RotL64(aCarry, 47U)) + 10534915376130006644U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordD, 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6866224454375302514U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16506374165041008396U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1326855300197233833U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7167814023968794098U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13870852197416596664U;
            aOrbiterI = RotL64((aOrbiterI * 17015971222069856463U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 18064038854848993105U) + RotL64(aNonceWordC, 17U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 9869630811507771691U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13723164383800461387U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 863613100452759380U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) + RotL64(aNonceWordA, 29U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 16597969741225436529U;
            aOrbiterC = RotL64((aOrbiterC * 2680793528887208903U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 6575347108051310653U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17062262265485019063U;
            aOrbiterD = RotL64((aOrbiterD * 7601045488473620019U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 39U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterG, 19U));
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 3U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 51U)) + aOrbiterD) + RotL64(aNonceWordH, 3U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 39U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterD, 30U)) + RotL64(aNonceWordF, 55U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13004U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneA[((aIndex + 12271U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordA, 29U)) ^ RotL64(aNonceWordG, 50U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14049U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12430U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCarry, 5U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 4U)) + 1297415699043177788U) + RotL64(aNonceWordD, 50U);
            aOrbiterF = (((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 17583786534509260153U) + RotL64(aNonceWordG, 25U);
            aOrbiterI = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 643197858925708798U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 5062653766915694874U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 13U)) + 7034273638367180511U) + aPhaseBOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2026909726972916996U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 2785690475553211646U) ^ RotL64(aNonceWordA, 19U);
            aOrbiterI = RotL64((aOrbiterI * 6612792037861160393U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2910341716302991892U) + RotL64(aNonceWordB, 55U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2834181605200829791U;
            aOrbiterF = RotL64((aOrbiterF * 1510617068750957651U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 13323052600571281928U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10434901530315760460U;
            aOrbiterD = RotL64((aOrbiterD * 2042210188346767033U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 247903955625194782U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5196515747387257163U;
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7196305682377987476U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14777739876892587484U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 95220583948241581U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 56U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 13U)) + RotL64(aNonceWordE, 3U)) + aPhaseBWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 51U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterF, 21U)) + RotL64(aNonceWordC, 53U)) + aPhaseBWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterB, 30U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 58U) + RotL64(aOrbiterD, 43U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 11U) ^ RotL64(aNonceWordH, 21U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 20399U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((aIndex + 16721U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 52U) ^ RotL64(aNonceWordC, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17990U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 21155U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 36U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aIngress, 47U)) + 12136097566601676613U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 21U)) + 7969431322248040056U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordG, 59U);
            aOrbiterB = ((aWandererJ + RotL64(aCross, 58U)) + 10530676021510553889U) + RotL64(aNonceWordD, 11U);
            aOrbiterD = ((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 8740777303075445264U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 13249434169895564739U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15529577005925628472U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 344627093687331562U;
            aOrbiterB = RotL64((aOrbiterB * 3226087371456521323U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8824277416519988893U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5636276438449709875U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 222817930773618893U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2079413361031851552U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 7807998179168655561U;
            aOrbiterD = RotL64((aOrbiterD * 961456853699784753U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13589392896232029112U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10733011474804473996U) ^ RotL64(aNonceWordE, 29U);
            aOrbiterJ = RotL64((aOrbiterJ * 361749145931578805U), 21U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 15934162328347805968U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordF, 35U);
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 7573511217796245232U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10694563909931636155U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 38U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 51U)) + aOrbiterA) + RotL64(aNonceWordB, 12U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordA, 17U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterD, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordE, 5U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24513U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((aIndex + 27073U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 11U) ^ RotL64(aNonceWordA, 3U)) ^ RotL64(aNonceWordG, 21U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24884U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 23000U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 56U)) + 16016931609704150191U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (((aWandererK + RotL64(aCross, 35U)) + RotL64(aCarry, 43U)) + 14511433515861302636U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 11691237442613269593U) + RotL64(aNonceWordH, 59U);
            aOrbiterF = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 16383220587320484649U) + RotL64(aNonceWordC, 53U);
            aOrbiterD = (aWandererF + RotL64(aCross, 13U)) + 14293015313458219868U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4407695248205526670U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1158323195324398372U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7489061637031434357U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6577683409653864555U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 171080079472863843U) ^ RotL64(aNonceWordD, 38U);
            aOrbiterD = RotL64((aOrbiterD * 3063978974927752653U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5766333425872228205U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 16173508656917582960U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) ^ RotL64(aNonceWordB, 43U);
            aOrbiterA = RotL64((aOrbiterA * 12187968015372936695U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11781450063402219202U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 13033139686637576694U;
            aOrbiterJ = RotL64((aOrbiterJ * 4331137994135472025U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4006310759400926020U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13156817947481574467U;
            aOrbiterF = RotL64((aOrbiterF * 563189239835001483U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 39U);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 29U)) + RotL64(aNonceWordE, 47U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterA, 56U)) + RotL64(aNonceWordA, 17U));
            aWandererD = aWandererD + ((((RotL64(aCross, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 52U) + aOrbiterD) + RotL64(aOrbiterJ, 13U)) + aPhaseBWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 50U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 57U) ^ RotL64(aNonceWordH, 4U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31134U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 32375U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 51U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordG, 41U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32556U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneB[((aIndex + 28391U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 44U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 12222235191147985484U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 16367317014523328414U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 14U)) + 3511378091284703789U) + RotL64(aNonceWordH, 37U);
            aOrbiterB = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 5U)) + 15247492830966725949U) + RotL64(aNonceWordD, 55U);
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 47U)) + 7745995913390407897U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 6463593307540108810U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1101669311005268630U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10550146460887359369U), 3U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 12988052764067518580U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1]) + RotL64(aNonceWordE, 34U);
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17717179747434679772U;
            aOrbiterF = RotL64((aOrbiterF * 10820310705487638793U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11662190906682400416U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6563014073547628748U;
            aOrbiterK = RotL64((aOrbiterK * 16967910471722117761U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13099094932059419219U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16342730862261868847U;
            aOrbiterB = RotL64((aOrbiterB * 10988124108686164829U), 39U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 16855346813127524624U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordC, 45U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6570063128502306944U;
            aOrbiterJ = RotL64((aOrbiterJ * 4571570049463124831U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterF) + RotL64(aNonceWordF, 19U));
            aWandererC = aWandererC + ((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterF, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 36U) + aOrbiterF) + RotL64(aOrbiterJ, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 22U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordG, 41U)) + aPhaseBWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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

void TwistExpander_BasketBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [seed arx]
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA5F1392742FB93CBULL + 0x882E19C59A984E11ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEA979591001C4BEDULL + 0xB627166F86AA8ECAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF8B5629117B8E1D3ULL + 0xB1C8E8BA99C67622ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA9313D14F9F47D75ULL + 0xC4EF8DB84B0EA57EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9048198E770FA4A3ULL + 0xFF2A44C9AB4DF9ECULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xBB4DBB296080B2FFULL + 0xF7C0CC2037EF75F0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA46C0E6E35C54A59ULL + 0xB3AC0035E589F471ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xDE81FAA2CE9F3563ULL + 0xBA3864E1E9D304A0ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 26U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordE, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4916U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1153U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordH, 13U)) ^ RotL64(aNonceWordA, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7701U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 5212U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 23U)) + (RotL64(aIngress, 54U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererE + RotL64(aIngress, 34U)) + 18255347001097480328U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 13679246790311505735U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 47U)) + 10565839529765027116U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 14327172566224769901U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 16239024612038195174U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 23U)) + 13800012174212131890U) + aPhaseCOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 29U)) + 13900288860157577583U) + RotL64(aNonceWordC, 54U);
            aOrbiterD = ((aWandererF + RotL64(aCross, 52U)) + 4144386119777112740U) + RotL64(aNonceWordD, 15U);
            aOrbiterF = (aWandererD + RotL64(aScatter, 11U)) + 3154558262670631372U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7456728543137614001U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11709519851158935384U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7016689518570071587U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15607438907832240304U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 9276575329661725624U) ^ RotL64(aNonceWordA, 43U);
            aOrbiterC = RotL64((aOrbiterC * 8879744070762412745U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 6459435969129449226U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6442382118416542275U;
            aOrbiterD = RotL64((aOrbiterD * 2921027306686588233U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12117432107282150865U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6831279293184793243U;
            aOrbiterF = RotL64((aOrbiterF * 2435360641135249073U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9520022957804572889U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8322178689474588679U;
            aOrbiterB = RotL64((aOrbiterB * 1627707191467537115U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4162401591586869316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8994015844714895961U;
            aOrbiterH = RotL64((aOrbiterH * 15421910378057951895U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10038095909727959633U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17756404450592957616U;
            aOrbiterK = RotL64((aOrbiterK * 14255952184627347295U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3379089265413427719U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11341713098678108441U) ^ RotL64(aNonceWordF, 31U);
            aOrbiterG = RotL64((aOrbiterG * 2500587373161411961U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4030296130743454165U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 6332387792111212064U;
            aOrbiterI = RotL64((aOrbiterI * 16490982218150897861U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterB) + RotL64(aNonceWordG, 11U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterI, 30U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + RotL64(aNonceWordB, 59U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 10U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 24U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterH, 37U));
            aWandererK = aWandererK + ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 37U) ^ RotL64(aNonceWordA, 53U)) ^ RotL64(aNonceWordF, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9102U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 15711U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 46U) ^ RotL64(aNonceWordD, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9985U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 8852U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 57U)) ^ (RotL64(aPrevious, 11U) + RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 12U)) + RotL64(aCarry, 53U)) + 16183871922837164759U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 19U)) + 7002058258090219055U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 27U)) + 5650868611888303705U) + RotL64(aNonceWordB, 52U);
            aOrbiterA = ((aWandererK + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 11899839660943876690U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 43U)) + 15349649504488111111U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 35U)) + 14060149569086744970U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 3U)) + 12920917574225030112U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 47U)) + 2831994965175330135U) + RotL64(aNonceWordE, 5U);
            aOrbiterE = ((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 21U)) + 18312543585028439192U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11657562205118394239U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10850792819281246052U;
            aOrbiterG = RotL64((aOrbiterG * 10663100544207879337U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17810371216216125323U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7963413941144223128U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 534217972450595401U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5498715358793875584U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9256727548911651373U) ^ RotL64(aNonceWordD, 45U);
            aOrbiterC = RotL64((aOrbiterC * 10498848323914000989U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17246360111302191699U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 18309978718113983369U;
            aOrbiterI = RotL64((aOrbiterI * 18267472694666221077U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3100998994319502921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterE = RotL64((aOrbiterE * 17847033539279176187U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1889641029473279114U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 16538494307002917945U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8081488217920885783U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5432230549146849322U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2634437941396090817U) ^ RotL64(aNonceWordH, 55U);
            aOrbiterA = RotL64((aOrbiterA * 7612999214758935211U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16940172599174185058U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13151669140593952203U;
            aOrbiterJ = RotL64((aOrbiterJ * 16225319638131723487U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 3995064294869931681U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 913081077665768816U;
            aOrbiterF = RotL64((aOrbiterF * 9299514648768060453U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 40U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 40U) + aOrbiterD) + RotL64(aOrbiterC, 58U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordA, 25U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 35U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 51U)) + aOrbiterI) + aPhaseCWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterA, 19U));
            aWandererH = aWandererH + ((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterE, 24U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + RotL64(aNonceWordG, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordH, 3U)) ^ RotL64(aNonceWordC, 23U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23133U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17978U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 37U) ^ RotL64(aNonceWordE, 14U)) ^ RotL64(aNonceWordF, 23U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23591U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneC[((aIndex + 16938U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 42U)) + (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterF = ((((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 898812731947995389U) + aPhaseCOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1]) + RotL64(aNonceWordG, 7U);
            aOrbiterC = (aWandererI + RotL64(aIngress, 52U)) + 8677347622525527167U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 770321564027567654U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 11020474858081526395U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + 17289793580414993470U) + aPhaseCOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aScatter, 4U)) + 10111912559295118444U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 43U)) + 8083622125544542011U;
            aOrbiterI = (aWandererF + RotL64(aCross, 13U)) + 7149858558922988240U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 27U)) + 5919683821379905699U) + RotL64(aNonceWordD, 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6860902846079238714U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15083517836867542075U;
            aOrbiterK = RotL64((aOrbiterK * 4686657139237578325U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14852868368708376381U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 9860233289028878323U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13418143547952204667U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 772406119079116272U) + RotL64(aNonceWordC, 55U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7971141501337627589U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10168120622976358617U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8478568022896691911U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 4027604850785607101U;
            aOrbiterC = RotL64((aOrbiterC * 4826627523578901467U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17199331557841535430U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7515957656979776361U) ^ RotL64(aNonceWordB, 43U);
            aOrbiterJ = RotL64((aOrbiterJ * 5468950152869656599U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17138249294921502391U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16236812863923234668U;
            aOrbiterA = RotL64((aOrbiterA * 2925542836624164807U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16941524155859123682U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11240343728857342866U;
            aOrbiterD = RotL64((aOrbiterD * 7281012444214294659U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15163914964139858328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6673576554415729652U;
            aOrbiterI = RotL64((aOrbiterI * 1558880328574736975U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5399050402101642989U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11806006719060024615U;
            aOrbiterH = RotL64((aOrbiterH * 15782156615926092159U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 46U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + RotL64(aNonceWordA, 47U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 44U) + aOrbiterH) + RotL64(aOrbiterK, 48U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 11U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + aOrbiterA) + RotL64(aOrbiterH, 37U));
            aWandererI = aWandererI + (((RotL64(aCross, 4U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + aPhaseCWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterB, 19U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterI, 60U)) + RotL64(aNonceWordH, 54U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererI, 41U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordA, 27U)) ^ RotL64(aNonceWordC, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25904U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30939U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordF, 29U)) ^ RotL64(aNonceWordE, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27310U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 30059U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 27U)) + (RotL64(aCross, 11U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererD + RotL64(aScatter, 53U)) + 5480870806135400132U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 58U)) + RotL64(aCarry, 29U)) + 8034874599430768743U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 43U)) + 4006919843736863767U) + RotL64(aNonceWordB, 19U);
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 23U)) + 2988069748674633718U) + aPhaseCOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 12347295651973135786U) + aPhaseCOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 14152683894431568192U) + RotL64(aNonceWordC, 53U);
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 28U)) + 15765143815254196598U;
            aOrbiterA = (aWandererI + RotL64(aCross, 39U)) + 10473067082331244233U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 19U)) + 1089466925383677249U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13215039929873682230U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 3957997712247961479U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7631186240013784703U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10023907397941685546U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14593012591254614353U;
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13353797968154036726U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9259966668512102858U;
            aOrbiterJ = RotL64((aOrbiterJ * 8326732574268308221U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10757861831070349321U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 10530223113483866178U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11269177745265396583U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7554320926405521865U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6978052067277966996U;
            aOrbiterB = RotL64((aOrbiterB * 18020134738536217801U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 1053695861967171420U) + RotL64(aNonceWordG, 23U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 15980734683539854451U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3208466640010555357U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17041258393808061556U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 12846551858751995530U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordH, 25U);
            aOrbiterA = RotL64((aOrbiterA * 9303891433380993639U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14617434286683320666U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3999309956180741302U;
            aOrbiterE = RotL64((aOrbiterE * 15037707937050015205U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13452627760403094126U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2633241575260427158U;
            aOrbiterK = RotL64((aOrbiterK * 2638570213290747581U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 57U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterB, 53U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 48U));
            aWandererG = aWandererG + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + RotL64(aCarry, 29U)) + RotL64(aNonceWordE, 41U)) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 43U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterH, 13U)) + aOrbiterA) + aPhaseCWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 28U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aNonceWordA, 44U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 40U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererH, 48U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_BasketBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x83C87783EF6B29A5ULL + 0x9253D7A362877D19ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDB3EEF6B67613FB1ULL + 0xF9346AF4C19F517DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD45CD8B20AFCE98FULL + 0xA4506EFFF7612A10ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBAFF12A03A90A7ABULL + 0xB677AF8FEC95581FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF086516FCACB132BULL + 0xBBC92F67C8C0CF52ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xED4D67D5F9AA9329ULL + 0x955223E70CDF0B90ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9ABD4CC2C432F04DULL + 0xED5CB23096BF39C4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCB64E545D9C35DD3ULL + 0xB31767594F23267BULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordH, 27U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5236U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1949U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 28U) ^ RotL64(aNonceWordD, 41U)) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4010U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 5087U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 28U) + RotL64(aIngress, 11U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererJ + RotL64(aCross, 51U)) + 2617613537256538553U;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 16642868916835132715U;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 27U)) + RotL64(aCarry, 35U)) + 10860291124337073254U;
            aOrbiterK = (((aWandererD + RotL64(aScatter, 4U)) + 6432511273906902472U) + aPhaseDOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + RotL64(aNonceWordG, 15U);
            aOrbiterJ = (aWandererH + RotL64(aCross, 57U)) + 7505375005848241910U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 39U)) + 11086616004678821329U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 29U)) + 3298830587569881951U) + RotL64(aNonceWordH, 3U);
            aOrbiterE = (aWandererE + RotL64(aScatter, 43U)) + 9775143140064220979U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 23U)) + 4147601326580823120U;
            aOrbiterC = (aWandererA + RotL64(aScatter, 14U)) + 12245920269898100415U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 8391940489176734499U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 17876893379544668477U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 18301882058180370541U;
            aOrbiterA = RotL64((aOrbiterA * 16680384667098921309U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 6869225862715140102U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordF, 7U);
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15404118372589259800U;
            aOrbiterI = RotL64((aOrbiterI * 5766851935950389915U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17757381020518233814U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 17677969146092374455U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3469432916562405063U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15783378556632870114U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5792858258663697864U;
            aOrbiterK = RotL64((aOrbiterK * 12008981883482080427U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11737803388202260296U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16001927091970715330U;
            aOrbiterB = RotL64((aOrbiterB * 3062030309852922061U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1749586939123286632U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6169421068855905938U;
            aOrbiterH = RotL64((aOrbiterH * 12374789910763348695U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10073586820719728062U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17744171227198661555U;
            aOrbiterD = RotL64((aOrbiterD * 10658375268803957647U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1149819647337612792U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7725598665625892006U;
            aOrbiterG = RotL64((aOrbiterG * 15097586655234391559U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 13930096050550704122U) + RotL64(aNonceWordB, 34U);
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3632241034947389647U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8442222389196610427U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17933893495867517142U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7888594392078082482U;
            aOrbiterE = RotL64((aOrbiterE * 9809847720610861237U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10805303827043372168U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2617613537256538553U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3940471942234248791U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK) + RotL64(aNonceWordA, 25U)) + aPhaseDWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterB, 43U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererC = aWandererC + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 60U)) + aOrbiterH) + RotL64(aCarry, 3U)) + RotL64(aNonceWordC, 45U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererB = aWandererB + ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 40U) + aOrbiterK) + RotL64(aOrbiterB, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 22U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterK, 53U)) + aPhaseDWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6411U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 8290U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordA, 5U)) ^ RotL64(aNonceWordH, 51U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10470U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10035U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 24U)) + (RotL64(aIngress, 53U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aCross, 54U)) + 2101601659597850213U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 37U)) + 2759794072560720121U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 47U)) + 9443562552411269339U) + RotL64(aNonceWordA, 45U);
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 21U)) + 10801360546699857975U) + aPhaseDOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 8020716394829332019U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 39U)) + 1021894212367773801U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 35U)) + 13346855534622490176U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 24U)) + RotL64(aCarry, 5U)) + 16359309548462953836U) + RotL64(aNonceWordE, 13U);
            aOrbiterG = (aWandererF + RotL64(aCross, 43U)) + 12642446944680783519U;
            aOrbiterD = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 8197424982767553380U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aPrevious, 13U)) + 14346334610901859094U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14171304260534233539U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 334531601308283605U;
            aOrbiterK = RotL64((aOrbiterK * 5012968232749075075U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10707856298471572695U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18364775750091914766U;
            aOrbiterH = RotL64((aOrbiterH * 15735143943129143265U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8531394793118363836U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15352876929406908882U;
            aOrbiterB = RotL64((aOrbiterB * 475199047053777179U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 567682016232278157U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 2068146551757663119U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1557877740957797555U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 7776122587613256525U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16430938890724272256U) ^ RotL64(aNonceWordG, 39U);
            aOrbiterG = RotL64((aOrbiterG * 4540270493783593257U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 11912000645055436094U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16800749242578741498U;
            aOrbiterF = RotL64((aOrbiterF * 17804584625034241737U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 5909199180260499150U) + RotL64(aNonceWordD, 61U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5751089915336865588U;
            aOrbiterJ = RotL64((aOrbiterJ * 15376689503142397927U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3478216857728853008U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 18007567146937338241U;
            aOrbiterC = RotL64((aOrbiterC * 6620498877303917855U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17454259424163653490U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6276120962018305311U;
            aOrbiterA = RotL64((aOrbiterA * 7560618224285018801U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3839336239901666431U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6230149015045237670U;
            aOrbiterD = RotL64((aOrbiterD * 1838983748994340883U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17552095486612766544U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2101601659597850213U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2915330118061857271U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 21U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + aPhaseDWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 3U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + RotL64(aNonceWordH, 23U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 14U) + aOrbiterF) + RotL64(aOrbiterH, 44U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterB, 14U)) + RotL64(aNonceWordB, 60U));
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererH, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 42U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 5U) ^ RotL64(aNonceWordA, 53U)) ^ RotL64(aNonceWordB, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14189U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 14411U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordE, 30U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13393U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15016U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 14U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererD + RotL64(aScatter, 37U)) + 18255347001097480328U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 60U)) + 13679246790311505735U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 10565839529765027116U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 35U)) + 14327172566224769901U;
            aOrbiterC = (((aWandererB + RotL64(aIngress, 41U)) + 16239024612038195174U) + aPhaseDOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordG, 37U);
            aOrbiterJ = (aWandererC + RotL64(aScatter, 19U)) + 13800012174212131890U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 13900288860157577583U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 4144386119777112740U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 39U)) + 3154558262670631372U) + RotL64(aNonceWordF, 35U);
            aOrbiterF = (aWandererE + RotL64(aScatter, 30U)) + 7456728543137614001U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 21U)) + 11709519851158935384U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15607438907832240304U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9276575329661725624U;
            aOrbiterG = RotL64((aOrbiterG * 8879744070762412745U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6459435969129449226U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6442382118416542275U;
            aOrbiterJ = RotL64((aOrbiterJ * 2921027306686588233U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12117432107282150865U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6831279293184793243U;
            aOrbiterI = RotL64((aOrbiterI * 2435360641135249073U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9520022957804572889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8322178689474588679U;
            aOrbiterC = RotL64((aOrbiterC * 1627707191467537115U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4162401591586869316U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8994015844714895961U;
            aOrbiterB = RotL64((aOrbiterB * 15421910378057951895U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10038095909727959633U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 17756404450592957616U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14255952184627347295U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3379089265413427719U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11341713098678108441U;
            aOrbiterD = RotL64((aOrbiterD * 2500587373161411961U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4030296130743454165U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 6332387792111212064U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16490982218150897861U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 14893209417387662133U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordC, 9U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 9265457389326311687U) ^ RotL64(aNonceWordA, 48U);
            aOrbiterA = RotL64((aOrbiterA * 9778404505547862689U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13496086915199406901U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14576555328710787951U;
            aOrbiterH = RotL64((aOrbiterH * 13155395071667672943U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11482324648071976743U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18255347001097480328U;
            aOrbiterK = RotL64((aOrbiterK * 10918514878283385643U), 27U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterC, 40U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterE) + RotL64(aCarry, 5U)) + RotL64(aNonceWordB, 25U)) + aPhaseDWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterD, 21U));
            aWandererG = aWandererG + ((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterA, 36U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + RotL64(aNonceWordH, 43U));
            aWandererF = aWandererF + ((RotL64(aCross, 4U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordE, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21594U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((aIndex + 20796U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordB, 56U)) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20144U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 20204U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 12U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 21U)) + 12849591986267890852U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 27U)) + 8232614804696815750U;
            aOrbiterI = (aWandererG + RotL64(aCross, 34U)) + 12141567259210877281U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 13U)) + 2928641981037885644U;
            aOrbiterG = (aWandererB + RotL64(aCross, 23U)) + 980733350554783938U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 53U)) + 2683985177993350746U) + RotL64(aNonceWordG, 45U);
            aOrbiterK = (aWandererK + RotL64(aIngress, 5U)) + 14532148403815527355U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 47U)) + 7736296629433884203U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 10428437770166310549U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 43U)) + 18327174144859461029U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 30U)) + RotL64(aCarry, 5U)) + 6810436935194432002U) + RotL64(aNonceWordH, 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 12606153309690753435U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17123256945895150555U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13469111258504672565U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9057777759026189541U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16478485918911194442U) ^ RotL64(aNonceWordE, 29U);
            aOrbiterG = RotL64((aOrbiterG * 11054247078884894131U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 18064460487552100483U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11477276762421684083U;
            aOrbiterJ = RotL64((aOrbiterJ * 3886501230380184395U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18318375441973295081U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13849305985380030986U;
            aOrbiterK = RotL64((aOrbiterK * 12962140243967824959U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10240409420338313641U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18360586077779529086U;
            aOrbiterD = RotL64((aOrbiterD * 18196875422391501927U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16801797158622424257U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 4950305991208513887U;
            aOrbiterF = RotL64((aOrbiterF * 4437082499761416951U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15790878572843321918U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9808781805065559728U;
            aOrbiterA = RotL64((aOrbiterA * 9394280083159162953U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11974996650410830731U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4955004489435232515U;
            aOrbiterC = RotL64((aOrbiterC * 13301966529515483085U), 3U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 1187569634223338864U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + RotL64(aNonceWordC, 56U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5351017164244226367U;
            aOrbiterB = RotL64((aOrbiterB * 14735674576470803699U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9587142385246940125U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16253850371962732943U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3408021872390904463U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14990060157351237661U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 12849591986267890852U;
            aOrbiterE = RotL64((aOrbiterE * 2158106726261981983U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 26U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 53U) + RotL64(aOrbiterB, 14U)) + aOrbiterD) + RotL64(aNonceWordD, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 41U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterH, 51U)) + aOrbiterG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterC, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 37U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aIngress, 27U) + aOrbiterD) + RotL64(aOrbiterI, 34U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterI, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aNonceWordF, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 20U) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22642U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 23776U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 19U) ^ RotL64(aNonceWordE, 56U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24342U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 26189U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 5U) ^ RotL64(aIngress, 50U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererI + RotL64(aIngress, 21U)) + 15045917390223766480U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 6U)) + 10763054007033668758U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 13190170142593666607U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 41U)) + 9657025731441167065U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 11433367178975954211U) + RotL64(aNonceWordH, 15U);
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 39U)) + 17904920143996810366U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 29U)) + 3244383020512113283U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 43U)) + 6538815775171139091U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 23U)) + 7195368312757976343U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 54U)) + 18134430713910279374U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 57U)) + 6571776588427107976U) + RotL64(aNonceWordG, 55U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11830778129647517758U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 9793702760907767365U;
            aOrbiterJ = RotL64((aOrbiterJ * 4096246227968677179U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 2287235876793192036U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8951959188326141794U;
            aOrbiterB = RotL64((aOrbiterB * 9968356718110753845U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7583061790273240157U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3571364625022806085U;
            aOrbiterA = RotL64((aOrbiterA * 6238360922735480669U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 13869345563551689212U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordD, 25U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 277480328952975002U;
            aOrbiterE = RotL64((aOrbiterE * 1057564597096163085U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 4983735092494677578U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9490022869381030928U;
            aOrbiterG = RotL64((aOrbiterG * 12926352917961703123U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 7928039573014765566U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6504190875809407084U;
            aOrbiterF = RotL64((aOrbiterF * 14648214826494826711U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2787985600176307413U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16308785053443116826U;
            aOrbiterD = RotL64((aOrbiterD * 17867565986311256691U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12788128335006767824U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1187040019537798339U;
            aOrbiterK = RotL64((aOrbiterK * 10834905007658184183U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10771230162770496645U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 6542421559654716320U) ^ RotL64(aNonceWordF, 45U);
            aOrbiterH = RotL64((aOrbiterH * 16829492790597069373U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 702458690970201679U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 2806140783487813070U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7415398198842270381U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 950611302199732036U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 15045917390223766480U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9358017420417979347U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 44U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 27U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterD, 39U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterD, 57U));
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 56U) + aOrbiterC) + RotL64(aOrbiterA, 46U)) + RotL64(aNonceWordA, 51U));
            aWandererC = aWandererC + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK) + RotL64(aCarry, 29U)) + RotL64(aNonceWordB, 54U)) + aPhaseDWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterE, 41U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 22U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterC, 3U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 29U) ^ RotL64(aNonceWordB, 6U)) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28600U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 27744U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordF, 29U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27387U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 31363U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 17711946802293254150U;
            aOrbiterB = (aWandererD + RotL64(aCross, 23U)) + 16652362590489569378U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 14U)) + 6972810344198183097U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 39U)) + 13117100889782940546U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 11U)) + RotL64(aCarry, 43U)) + 13199305696782626591U;
            aOrbiterK = (((aWandererE + RotL64(aScatter, 43U)) + 992156184392760945U) + aPhaseDOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + RotL64(aNonceWordH, 41U);
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 27U)) + 13791265442074543880U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 17057087245252294859U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 35U)) + 13444195995883541046U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererF + RotL64(aCross, 54U)) + 6723678233676059420U) + RotL64(aNonceWordF, 61U);
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 57U)) + 7913379431208430475U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4481887195529300665U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11892724101424384078U;
            aOrbiterD = RotL64((aOrbiterD * 3468639499716604111U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7700902083270424194U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1888001433557140271U;
            aOrbiterA = RotL64((aOrbiterA * 8975562955027025349U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14996753906788986929U) + RotL64(aNonceWordB, 45U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 939004845422123765U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2507090308972292313U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11922230289291941807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15681187459741147199U;
            aOrbiterJ = RotL64((aOrbiterJ * 10124947739653819101U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9119043713532718155U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8327697433992362166U;
            aOrbiterF = RotL64((aOrbiterF * 11157657162184304567U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13630755116592440359U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 771252613886022889U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2958918915223536519U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8524239721467527770U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17732617735422435572U;
            aOrbiterI = RotL64((aOrbiterI * 13992947983987668631U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5265753270696005619U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14456128349522985053U;
            aOrbiterE = RotL64((aOrbiterE * 5406509991740849617U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12909993509014176457U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 10113568710432654194U;
            aOrbiterH = RotL64((aOrbiterH * 6857806395910432831U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14818978163348513071U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 17843349910031998923U) ^ RotL64(aNonceWordG, 4U);
            aOrbiterB = RotL64((aOrbiterB * 13608449524810499593U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12589077818524017161U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 17711946802293254150U;
            aOrbiterC = RotL64((aOrbiterC * 9454569713107675231U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterF, 56U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 26U) + RotL64(aOrbiterA, 39U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 54U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordE, 15U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 48U)) + aOrbiterE) + RotL64(aNonceWordA, 9U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 29U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + aPhaseDWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 20U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterJ, 37U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_BasketBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAF617F3A6D17C2C7ULL + 0xB3B0C42A4A157A00ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD6676E938BA6AC3FULL + 0x9CC0289A180BCB87ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD601021C31186C7DULL + 0xDCEE75F7C92EC258ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF15052800152182DULL + 0xA91528908B0FBE31ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC06EAF25C06B6BDDULL + 0x9304BA6C3E6F2FD6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFFFC259A97557FD5ULL + 0x9A8FA98615D01298ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE39AF1E90637D463ULL + 0x9C8A77A4CF69DBD0ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFE063CA16927F567ULL + 0xE568F31F008205F2ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 21U) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3435U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3241U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordC, 47U)) ^ RotL64(aNonceWordH, 36U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2461U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3955U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 52U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (aWandererJ + RotL64(aScatter, 11U)) + 826930775230515406U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 3U)) + 5137814617363250861U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 60U)) + 14761561947426681616U;
            aOrbiterH = (aWandererG + RotL64(aCross, 41U)) + 12773023438753662590U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 29U)) + 7331345852207096322U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 13U)) + 3899381212671247460U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 43U)) + 10072004147620068599U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 3424585039401897560U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 35U)) + 8246760141625966321U) + RotL64(aNonceWordD, 51U);
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 54U)) + RotL64(aCarry, 23U)) + 3655992860610853290U) + RotL64(aNonceWordC, 17U);
            aOrbiterI = (((aWandererC + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 11154618022505863898U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15629361991059709973U) + RotL64(aNonceWordA, 21U);
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10842068502278489664U;
            aOrbiterE = RotL64((aOrbiterE * 17223002513104960799U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5571312349016336686U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 589313823745748879U;
            aOrbiterF = RotL64((aOrbiterF * 1356685926549786027U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13633457935771935260U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12684602052812183096U;
            aOrbiterA = RotL64((aOrbiterA * 4689206269919806711U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 5711307583717354204U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordB, 41U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 7181854170553728211U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9835601115561325911U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1884620014396115821U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1471516373272364262U;
            aOrbiterK = RotL64((aOrbiterK * 5126319375714848029U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 742739371092077733U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 8075893317715227838U;
            aOrbiterJ = RotL64((aOrbiterJ * 11208274111743259795U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8179547722249281263U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 15305282712174742323U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7951986906055462929U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1430543231751281079U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 14585341768267283387U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 313213844964269133U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8123889986027932297U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2081696191347150910U;
            aOrbiterD = RotL64((aOrbiterD * 4869653441012615053U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10166788886199265936U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15927074835525735601U;
            aOrbiterB = RotL64((aOrbiterB * 6747650218540675523U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6997764816848988590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 826930775230515406U;
            aOrbiterG = RotL64((aOrbiterG * 9943232461538279601U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 30U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + RotL64(aNonceWordF, 13U));
            aWandererI = aWandererI + (((RotL64(aCross, 52U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterC, 14U));
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + RotL64(aNonceWordH, 60U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 19U)) + aOrbiterH);
            aWandererK = aWandererK + ((RotL64(aIngress, 48U) + RotL64(aOrbiterI, 43U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterH, 46U)) + aPhaseEWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 41U)) + aOrbiterE) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordF, 5U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8787U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7713U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8232U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7025U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 22U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aCross, 3U)) + 8402620908307642697U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 11347672014525086047U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 11U)) + 2816462912503401876U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 6940159795470696093U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 9134692490095883851U;
            aOrbiterC = ((((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 4999455497008026526U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 31U);
            aOrbiterD = (aWandererI + RotL64(aScatter, 6U)) + 5992451460350651332U;
            aOrbiterI = (aWandererH + RotL64(aCross, 41U)) + 3417087346651371924U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 57U)) + 3612773820086198270U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 13U)) + 463398077083428570U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 34U)) + 11249391303705089012U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordA, 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17027535139825739501U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 568131384979596481U;
            aOrbiterE = RotL64((aOrbiterE * 5683451044852895957U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4793712537158004047U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 10415170179135963622U;
            aOrbiterA = RotL64((aOrbiterA * 13729564030210361415U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2391473979460065630U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4240058362680064261U;
            aOrbiterB = RotL64((aOrbiterB * 12375884373396400889U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9963957011090031698U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3325305624067445525U;
            aOrbiterD = RotL64((aOrbiterD * 3128542681461806309U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 2094945647665114693U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10703615640774042674U;
            aOrbiterJ = RotL64((aOrbiterJ * 12641986098450423751U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 3768738815518590289U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15021301790376706827U;
            aOrbiterG = RotL64((aOrbiterG * 14445850924223550339U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10571246886181608316U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5130325144599151793U;
            aOrbiterH = RotL64((aOrbiterH * 3185251943547657467U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 8617523421720966373U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16574597770835250074U;
            aOrbiterC = RotL64((aOrbiterC * 1759209403428937799U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 17474733286551120355U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17914672092861237776U) ^ RotL64(aNonceWordG, 19U);
            aOrbiterI = RotL64((aOrbiterI * 13657291990878792267U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12856557371623447773U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 1636296609747335898U;
            aOrbiterK = RotL64((aOrbiterK * 9286345529656087313U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12588848560509679821U) + RotL64(aNonceWordF, 41U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 8402620908307642697U;
            aOrbiterF = RotL64((aOrbiterF * 2269772223506258147U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererI = aWandererI + (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterK, 5U));
            aWandererG = aWandererG + ((((RotL64(aCross, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterH) + RotL64(aNonceWordD, 43U)) + aPhaseEWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + aOrbiterI) + RotL64(aOrbiterJ, 58U)) + RotL64(aNonceWordH, 6U));
            aWandererK = aWandererK + (((RotL64(aIngress, 5U) + aOrbiterB) + RotL64(aOrbiterC, 41U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 35U) + aOrbiterE) + RotL64(aOrbiterF, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterB, 34U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + aOrbiterH) + RotL64(aOrbiterK, 11U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 23U) ^ RotL64(aNonceWordC, 13U)) ^ RotL64(aNonceWordE, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14403U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((aIndex + 12421U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordA, 6U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12351U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 13115U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aScatter, 3U)) + 1393781663398437180U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 23U)) + 17414594746688585273U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 5U)) + 2823888497053071250U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 17032631958617884859U) + RotL64(aNonceWordE, 49U);
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 26U)) + RotL64(aCarry, 23U)) + 15222697630461125019U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 21U)) + 15737414920751551780U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 3U)) + 1357196111055783001U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 43U)) + 5315122321649251691U;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 50U)) + 7893744655508595974U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 54U);
            aOrbiterE = (aWandererF + RotL64(aScatter, 39U)) + 16721939414324611738U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 37U)) + 3444375866323610848U;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 1825716513674511632U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordF, 45U);
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15582066843912467318U;
            aOrbiterB = RotL64((aOrbiterB * 12765146555943757373U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15673590949193923915U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 13887365046280406413U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3169061375011420121U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12730414371734709356U) + RotL64(aNonceWordC, 47U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4819112390640821927U;
            aOrbiterJ = RotL64((aOrbiterJ * 8782547948627685451U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3089925954422937464U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7180179304678622530U;
            aOrbiterH = RotL64((aOrbiterH * 16118051565147747413U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17030269962085008657U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6675917351883004046U;
            aOrbiterI = RotL64((aOrbiterI * 14134335325316949687U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12572022803491077491U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2801421744689267375U;
            aOrbiterE = RotL64((aOrbiterE * 315045745990934023U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4335148696780313055U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12526298573395110141U;
            aOrbiterK = RotL64((aOrbiterK * 11276803410698178607U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 6984239833558496091U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12195433952105336808U;
            aOrbiterF = RotL64((aOrbiterF * 8642600547427664495U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6392683095502982341U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 18047201953488013325U;
            aOrbiterG = RotL64((aOrbiterG * 16151795290455603489U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 15433458942878109208U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1700365768743794306U;
            aOrbiterD = RotL64((aOrbiterD * 16151638348775286903U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10951473638533187729U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 1393781663398437180U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2661447713922232789U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 38U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 48U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseEWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterI, 38U)) + RotL64(aNonceWordB, 15U)) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterF, 41U)) + RotL64(aNonceWordG, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 48U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 56U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterA, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aCross, 26U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 4U) ^ RotL64(aNonceWordA, 47U)) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19858U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20171U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 43U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17781U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20203U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 5U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aCross, 21U)) + 14214886793361825363U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 39U)) + 17267959031078766320U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 16436067429484887644U) + aPhaseEOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aScatter, 3U)) + 9885951769332633820U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 12971711341813893304U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 11U)) + 199970353398450154U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 30U)) + RotL64(aCarry, 47U)) + 1237341696444162094U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 41U)) + 7991128854417613360U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 57U)) + 14809029847149045833U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + RotL64(aNonceWordA, 35U);
            aOrbiterB = (aWandererK + RotL64(aScatter, 43U)) + 2559509556915775947U;
            aOrbiterH = ((aWandererI + RotL64(aCross, 24U)) + 14336829730147834160U) + RotL64(aNonceWordB, 9U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 8853631886733610440U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordE, 61U);
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 13346159398673246914U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1]) ^ RotL64(aNonceWordG, 31U);
            aOrbiterF = RotL64((aOrbiterF * 13660497151446983393U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12121095718571872976U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16239781125815589804U;
            aOrbiterA = RotL64((aOrbiterA * 5157009090454962231U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9051377033794324106U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13805815136723461780U;
            aOrbiterJ = RotL64((aOrbiterJ * 571129481747181357U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14849157800322754413U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18116651528452542634U;
            aOrbiterK = RotL64((aOrbiterK * 3638480428016835537U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 4105057226952948599U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5911714320560994391U;
            aOrbiterD = RotL64((aOrbiterD * 1796514171654961389U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4439149331729987587U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10278532228230163632U;
            aOrbiterE = RotL64((aOrbiterE * 17428224919864716517U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2342456582668741750U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2360578572554664800U;
            aOrbiterB = RotL64((aOrbiterB * 1108428466956691925U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 12132934875391401246U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17213278726790245812U;
            aOrbiterH = RotL64((aOrbiterH * 11904899990681410419U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7994340481560109811U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13735851271080138255U;
            aOrbiterG = RotL64((aOrbiterG * 12387076892129731557U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6682417543888875268U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15642799286975840550U;
            aOrbiterC = RotL64((aOrbiterC * 7861250716882028053U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 9839299346094784067U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14214886793361825363U;
            aOrbiterI = RotL64((aOrbiterI * 2103132743364916037U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterG, 29U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + RotL64(aNonceWordF, 11U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterJ, 43U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 48U) + aOrbiterF) + RotL64(aOrbiterE, 22U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 19U)) + aOrbiterC);
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 38U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + RotL64(aNonceWordH, 16U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 37U)) + aOrbiterD);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterE, 26U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 28U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 19U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24875U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23842U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 54U) ^ RotL64(aNonceWordC, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27303U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26270U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCarry, 48U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererI + RotL64(aCross, 37U)) + 10881271196314989997U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 46U)) + 6406461249988567558U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordG, 15U);
            aOrbiterC = (aWandererB + RotL64(aPrevious, 51U)) + 17255067918280095959U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 16690850682497718411U) + RotL64(aNonceWordB, 60U);
            aOrbiterB = (aWandererF + RotL64(aPrevious, 23U)) + 5576201059361086866U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 5U)) + 11991259685693687554U;
            aOrbiterG = (aWandererA + RotL64(aCross, 41U)) + 14652535244217836909U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 1701789037170782122U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 13U)) + 953429054903473833U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 53U)) + 12064513610469714211U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aPrevious, 14U)) + 7993881398822002424U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14421313768013320050U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11112386845630998889U;
            aOrbiterC = RotL64((aOrbiterC * 11771526352030371669U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17069630896535699015U) + RotL64(aNonceWordF, 55U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3308240081138623373U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10449509484417835159U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17615529807112933619U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11782807146851563541U;
            aOrbiterH = RotL64((aOrbiterH * 12992075832343669221U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14401645829607611983U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6736397344219993532U;
            aOrbiterI = RotL64((aOrbiterI * 1667287547938175641U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6446974060524700550U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 7840991992443308254U) ^ RotL64(aNonceWordH, 23U);
            aOrbiterJ = RotL64((aOrbiterJ * 6891023544882740107U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 10362169906019794305U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4503700997923168911U;
            aOrbiterA = RotL64((aOrbiterA * 15066164494038852559U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13492041134973259041U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14337899277551397976U;
            aOrbiterG = RotL64((aOrbiterG * 5966740718899290915U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13693100781608180748U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16177545026405910052U;
            aOrbiterE = RotL64((aOrbiterE * 6019231448444020563U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9641191118119415680U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 735491776764667034U;
            aOrbiterK = RotL64((aOrbiterK * 11305930862759869997U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2225714710491247284U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16906789796765378455U;
            aOrbiterD = RotL64((aOrbiterD * 4341667316266234469U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9451961177946601088U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10881271196314989997U;
            aOrbiterB = RotL64((aOrbiterB * 10929686721061541543U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 14U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterD, 52U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterA, 43U)) + RotL64(aNonceWordC, 35U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 24U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + RotL64(aNonceWordA, 9U));
            aWandererB = aWandererB + ((RotL64(aIngress, 41U) + aOrbiterE) + RotL64(aOrbiterC, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 54U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 60U) ^ RotL64(aNonceWordB, 51U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28814U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 32655U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 47U) ^ RotL64(aNonceWordF, 60U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28747U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 31767U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 37U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 53U)) + 7893287783892523139U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 41U)) + 10257331997383491153U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 11U)) + 14562226733652231753U) + RotL64(aNonceWordD, 41U);
            aOrbiterG = ((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 14320342577110737851U;
            aOrbiterB = (aWandererK + RotL64(aScatter, 5U)) + 9816717579822880756U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 37U)) + 9558926960095881953U) + aPhaseEOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 9230371862654338324U) + RotL64(aNonceWordH, 3U);
            aOrbiterE = (aWandererI + RotL64(aIngress, 21U)) + 6414274291252913420U;
            aOrbiterH = (aWandererA + RotL64(aCross, 39U)) + 13868546184398350849U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 48U)) + 16940736952569949038U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 53U)) + 2866957764814864371U) + aPhaseEOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 7916721976073979724U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 1602444214978842275U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterA = RotL64((aOrbiterA * 11072503711308122385U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9529061385251008037U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8402775110887376588U;
            aOrbiterB = RotL64((aOrbiterB * 13980225144628227381U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15003592180290390713U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14195681406520825751U;
            aOrbiterK = RotL64((aOrbiterK * 11455000833788877217U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3263577002367714202U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12019422062655581928U;
            aOrbiterD = RotL64((aOrbiterD * 5002313835338447799U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8508638054582582917U) + RotL64(aNonceWordF, 12U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6536618106353552880U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6233964121117511885U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9654542989321430868U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 7019594782797863244U;
            aOrbiterH = RotL64((aOrbiterH * 1234877854354279981U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8256061220727519919U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 9232754129467036130U;
            aOrbiterF = RotL64((aOrbiterF * 17556001874302369781U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5608829951337740378U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12632120498473345701U;
            aOrbiterJ = RotL64((aOrbiterJ * 6994794653605831925U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17313364434369677697U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10147405701828074385U;
            aOrbiterI = RotL64((aOrbiterI * 11544579984323623009U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16853703086012867980U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3591438641820423822U;
            aOrbiterC = RotL64((aOrbiterC * 3570430739475340845U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13974806289212867511U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7893287783892523139U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6648351608953339723U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 37U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 57U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterA, 51U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterK, 48U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD);
            aWandererH = aWandererH + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 3U)) + RotL64(aNonceWordE, 17U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterH, 19U));
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterF, 46U)) + RotL64(aNonceWordA, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 50U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xAB5A0C8D1123D003ULL + 0x91B3AA50FE74A57EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEA0CBD4DEBAB8FB7ULL + 0xAD12DAF064595093ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA4232ECB4D461053ULL + 0xE3455A5776E89EE4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x88798CB9AACBEF79ULL + 0xA7F9015D1C68C6DAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xAEAA7C462AE85EEBULL + 0xC467A8ABD127F4E4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC228DF7D3E57E01BULL + 0xBDB88258091A06BCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xE4E29A37238F5BBBULL + 0xC7D57ACEB912646CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD8705F2E3B056161ULL + 0xFF79F8C21A56CF84ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordD, 10U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1176U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 797U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 22U) ^ RotL64(aNonceWordG, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1012U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 487U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aIngress, 41U)) + (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererD + RotL64(aPrevious, 27U)) + 2571116506511057880U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 3U)) + 13112435411509707292U;
            aOrbiterE = (aWandererH + RotL64(aCross, 23U)) + 10403251762787357256U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 53U)) + 8461951095541400405U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 51U)) + 9890793478557463815U) + RotL64(aNonceWordC, 57U);
            aOrbiterI = (aWandererF + RotL64(aCross, 11U)) + 3030229465991783707U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 29U)) + 7273848154043719247U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 5U)) + 10681774862516028276U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 39U)) + 7105082755586853104U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + RotL64(aNonceWordE, 45U);
            aOrbiterK = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 19U)) + 6588579345319551129U;
            aOrbiterH = (((aWandererG + RotL64(aPrevious, 44U)) + RotL64(aCarry, 35U)) + 14616333550242386092U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15439666290229654921U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3360304356760164799U;
            aOrbiterE = RotL64((aOrbiterE * 5164191920584106237U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 14438730801970761889U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14515616787452085729U;
            aOrbiterI = RotL64((aOrbiterI * 2041601927968559821U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4167853822635132419U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8950982233003320239U;
            aOrbiterG = RotL64((aOrbiterG * 887144270884244907U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12391327853728029953U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7100871010552394421U;
            aOrbiterJ = RotL64((aOrbiterJ * 16552349374101955967U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15381697462381887944U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6801677551341079401U;
            aOrbiterA = RotL64((aOrbiterA * 13325954438427340703U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 947011315719204867U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordD, 15U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6356920162398333481U;
            aOrbiterD = RotL64((aOrbiterD * 5566721941682667419U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8910262020598577378U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 8778455415977526457U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4092470497616637283U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5585696961453127223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9670655481681494412U;
            aOrbiterF = RotL64((aOrbiterF * 7863197168965036383U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10713004007087085729U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4036355047492922339U;
            aOrbiterB = RotL64((aOrbiterB * 6923922258047667173U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14580156873863533497U) + RotL64(aNonceWordB, 16U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7049502932205025182U;
            aOrbiterC = RotL64((aOrbiterC * 8665428649262370727U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12707521269341941677U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2571116506511057880U;
            aOrbiterK = RotL64((aOrbiterK * 2388236789245943699U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 53U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 38U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 43U)) + RotL64(aNonceWordA, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 11U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + aOrbiterK) + RotL64(aOrbiterI, 20U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + RotL64(aNonceWordF, 23U));
            aWandererK = aWandererK + ((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 27U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 10U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 18U) ^ RotL64(aNonceWordB, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6350U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9686U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 36U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordG, 27U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9972U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 7364U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aIngress, 39U)) + 11039986441331892533U;
            aOrbiterA = (aWandererA + RotL64(aCross, 53U)) + 6256024955965426119U;
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 35U)) + 9857443189988995666U) + aPhaseFOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 58U)) + 11900944813380998208U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 8422577734978875541U) + RotL64(aNonceWordF, 57U);
            aOrbiterJ = (aWandererI + RotL64(aScatter, 23U)) + 3100835100713928724U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 27U)) + 11871553509810206993U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 29U)) + 17614749493763417027U) + aPhaseFOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 43U)) + 3638372131856199916U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 5U)) + 6582275259281025770U) + RotL64(aNonceWordG, 44U);
            aOrbiterB = ((aWandererD + RotL64(aScatter, 56U)) + RotL64(aCarry, 23U)) + 17016882418498941958U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1747214688658984715U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9356088987044015278U) ^ RotL64(aNonceWordH, 59U);
            aOrbiterD = RotL64((aOrbiterD * 16221733545319753695U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4056238112133473456U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16013150119949532998U;
            aOrbiterA = RotL64((aOrbiterA * 12913648646318115315U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16076621211111834889U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9940824359571581765U;
            aOrbiterC = RotL64((aOrbiterC * 11624767861336495331U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 15624084004784515753U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7630989544834680335U;
            aOrbiterE = RotL64((aOrbiterE * 12261063237156822067U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18003586430673313786U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1654118743290334161U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1153250137357176071U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3254189676528343910U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15629083361573065165U) ^ RotL64(aNonceWordB, 43U);
            aOrbiterH = RotL64((aOrbiterH * 17024833368570949107U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10056859810555674806U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15976683222786846254U;
            aOrbiterK = RotL64((aOrbiterK * 2801754232182942635U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11872378594829637933U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 7633773773528713489U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8218288492011593353U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16305188578382203720U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13293036594949754170U;
            aOrbiterG = RotL64((aOrbiterG * 1300645662609848183U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15185013801659166674U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11562899709899198100U;
            aOrbiterF = RotL64((aOrbiterF * 9115495024409604629U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1525205566739385260U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11039986441331892533U;
            aOrbiterB = RotL64((aOrbiterB * 9802284050237622047U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 6U) + aOrbiterB) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterC, 11U)) + RotL64(aNonceWordE, 11U));
            aWandererI = aWandererI + ((RotL64(aCross, 27U) + RotL64(aOrbiterJ, 53U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterA) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 50U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 48U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aNonceWordC, 5U));
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterE, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 6U) ^ RotL64(aNonceWordE, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13934U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 13028U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 27U) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12663U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14646U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 3U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 22U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aIngress, 35U)) + 13174219512651137892U;
            aOrbiterI = (((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 2715455762789269341U) + RotL64(aNonceWordD, 45U);
            aOrbiterA = (aWandererB + RotL64(aCross, 47U)) + 1338018183235594313U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 60U)) + 16566866551729552930U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aScatter, 23U)) + 6901845297307236726U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aIngress, 3U)) + 2476078302049201718U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 39U)) + 15531109473927052260U;
            aOrbiterB = (aWandererK + RotL64(aCross, 29U)) + 4087849380858572351U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 5167830630098599644U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 26U)) + RotL64(aCarry, 35U)) + 7275995452428627217U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 19U)) + 14794340370010024117U) + RotL64(aNonceWordH, 55U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8509217403041662849U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 2321522025240806996U) ^ RotL64(aNonceWordE, 39U);
            aOrbiterA = RotL64((aOrbiterA * 113568101672878697U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 5676672952755594051U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2304681269233504384U;
            aOrbiterG = RotL64((aOrbiterG * 15731441084605554497U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 8383399721062437300U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13181984036942227666U;
            aOrbiterI = RotL64((aOrbiterI * 1648761328771932069U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13602604532551684210U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12725687663616352843U;
            aOrbiterH = RotL64((aOrbiterH * 4684699861686199753U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 5831790822416009806U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4535048543735457407U;
            aOrbiterB = RotL64((aOrbiterB * 12076777878870257053U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10617608605149381858U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5244225377862618630U;
            aOrbiterC = RotL64((aOrbiterC * 15307177251167023999U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 18229989093139888456U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9728120630096192811U) ^ RotL64(aNonceWordF, 34U);
            aOrbiterJ = RotL64((aOrbiterJ * 16052574428163231023U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1312233443099767304U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8043115602160128619U;
            aOrbiterD = RotL64((aOrbiterD * 9365756845731616963U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 4679339316686216023U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 211799535650113758U;
            aOrbiterE = RotL64((aOrbiterE * 1478368466990144107U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13307123762743628190U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7093673238704478497U;
            aOrbiterK = RotL64((aOrbiterK * 13273906568866802561U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16396459072175632290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13174219512651137892U;
            aOrbiterF = RotL64((aOrbiterF * 7581008806810219369U), 43U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterE, 43U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterJ, 34U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 57U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterE) + RotL64(aNonceWordC, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 11U) + aOrbiterK) + RotL64(aOrbiterG, 5U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 47U)) + aOrbiterE) + RotL64(aNonceWordA, 49U)) + aPhaseFWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 54U)) + aOrbiterG) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 26U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20627U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 18623U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 58U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordB, 37U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16455U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 19597U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 10U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aIngress, 21U)) + 6361545377408870615U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 54U)) + 2967245486744774933U;
            aOrbiterK = (aWandererF + RotL64(aCross, 37U)) + 3836634268482850139U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 39U)) + 7691642115360086297U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 27U)) + 16479280384178279281U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 11U)) + 2901468732552539249U) + RotL64(aNonceWordH, 3U);
            aOrbiterF = (aWandererJ + RotL64(aIngress, 13U)) + 2600353867755647475U;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 23U)) + 5666596904781510956U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 50U)) + 16108791609267427553U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 19U)) + 8389926875737312112U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 47U)) + RotL64(aCarry, 39U)) + 1689501721163024426U) + RotL64(aNonceWordE, 7U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11721701506949917719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 3963842745030140473U;
            aOrbiterK = RotL64((aOrbiterK * 6692473494944919373U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8510538243472109368U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18281865214102080387U;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2259725140963665123U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11652011949557979650U) ^ RotL64(aNonceWordG, 21U);
            aOrbiterG = RotL64((aOrbiterG * 11260100762113295037U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1116085424226174473U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4725260319270802912U;
            aOrbiterF = RotL64((aOrbiterF * 4697109059565450269U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7348945429843437036U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1249234309180653260U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3136745255820405881U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12463505532573389603U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2304125977906510386U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9960816714791454421U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2178037443783425551U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11712110130079307683U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9797864956200779505U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 10703510612147312252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 18155460326242413483U;
            aOrbiterH = RotL64((aOrbiterH * 6903953708987478723U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5753486645345036069U) + RotL64(aNonceWordC, 58U);
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2314216774606770444U;
            aOrbiterA = RotL64((aOrbiterA * 14002639533287566667U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 9662599462788305323U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3805101172359199209U;
            aOrbiterB = RotL64((aOrbiterB * 10669315962181581543U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1073926575064224947U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6361545377408870615U;
            aOrbiterD = RotL64((aOrbiterD * 10685650563722188837U), 5U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aNonceWordA, 9U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 41U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 48U) + RotL64(aOrbiterA, 37U)) + aOrbiterB) + RotL64(aNonceWordB, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 13U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 20U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 27U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aIngress, 34U) + RotL64(aOrbiterI, 23U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterG, 10U));
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterE) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererC, 18U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordD, 54U)) ^ RotL64(aNonceWordB, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24336U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 23675U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 56U) ^ RotL64(aNonceWordC, 21U)) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23954U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21895U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 40U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 24U)) + RotL64(aCarry, 29U)) + 1364174714924216027U) + RotL64(aNonceWordD, 7U);
            aOrbiterC = ((aWandererD + RotL64(aCross, 43U)) + 13561796874229506613U) + RotL64(aNonceWordE, 4U);
            aOrbiterF = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 11845572344206238305U;
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 57U)) + 15762708240326773763U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aIngress, 21U)) + 1157119665207900473U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 13U)) + 6823546624372055260U) + aPhaseFOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aScatter, 29U)) + 14465564210523945121U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 43U)) + 10667464548080807531U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 26U)) + 13445737493224316575U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 3U)) + 3009837893785957665U;
            aOrbiterK = (aWandererK + RotL64(aCross, 11U)) + 2886920524111083752U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10886177449328249656U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15067759884678100433U;
            aOrbiterF = RotL64((aOrbiterF * 5724566815989860041U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18307930462682331536U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8791864377579255801U;
            aOrbiterB = RotL64((aOrbiterB * 9265158882471421767U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 805797468642992351U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5743305867058244964U;
            aOrbiterH = RotL64((aOrbiterH * 16263000753351131717U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 17102025528234481273U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1841579177327486899U;
            aOrbiterA = RotL64((aOrbiterA * 3841603385577825265U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 2189493507896508972U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 18209567010094914374U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3737080408976852351U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 6697069234216868330U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 927471474577415372U;
            aOrbiterJ = RotL64((aOrbiterJ * 10680760991009199309U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 13155854301197725408U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1014625081915435892U;
            aOrbiterG = RotL64((aOrbiterG * 11592754232949990435U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 12697209921410914931U) + RotL64(aNonceWordB, 23U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11555096613655648647U;
            aOrbiterD = RotL64((aOrbiterD * 4598821388864997089U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 9335308231651271690U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3160859883353473444U;
            aOrbiterK = RotL64((aOrbiterK * 4753600703924906409U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 15681189182414315768U) + RotL64(aNonceWordA, 3U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3147692210581710663U;
            aOrbiterC = RotL64((aOrbiterC * 6271949093080510861U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5373388632562432117U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1364174714924216027U;
            aOrbiterI = RotL64((aOrbiterI * 4694926665965807945U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 30U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterB, 4U)) + aOrbiterH) + RotL64(aNonceWordH, 49U));
            aWandererA = aWandererA + (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            aWandererB = aWandererB + ((((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 47U)) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 53U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aPhaseFWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterA, 46U)) + RotL64(aNonceWordG, 9U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordA, 60U)) ^ RotL64(aNonceWordG, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32596U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31666U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 37U) ^ RotL64(aNonceWordB, 23U)) ^ RotL64(aNonceWordC, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28530U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 31991U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 12U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 5U)) + 13714409587461539863U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 35U)) + 14101156723903265839U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 58U)) + 7063754562895369001U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 43U)) + 12320578575245519386U) + RotL64(aNonceWordB, 48U);
            aOrbiterI = (((aWandererA + RotL64(aCross, 53U)) + 11744826789631008424U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 27U);
            aOrbiterK = (aWandererH + RotL64(aIngress, 23U)) + 8744816505096675597U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 37U)) + 10405435520084528645U;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 37U)) + 1463157688070683543U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 12379603577919617703U;
            aOrbiterH = (aWandererI + RotL64(aCross, 39U)) + 1343439118031348146U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 16118850268070235540U) + aPhaseFOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 14116264435819277136U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5251698273012432109U;
            aOrbiterF = RotL64((aOrbiterF * 1495818611622063967U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14806408656041403829U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11569345414052398227U;
            aOrbiterI = RotL64((aOrbiterI * 9913158908301414861U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17063874769147888574U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9927420478679581917U;
            aOrbiterK = RotL64((aOrbiterK * 9042782809534196563U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2550285599827162167U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17801534123304996448U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2160836889363614721U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6456685241021762041U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 17064208177372969289U;
            aOrbiterC = RotL64((aOrbiterC * 13726627607233302493U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 18279938244131982650U) + RotL64(aNonceWordD, 7U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8211002229712129419U;
            aOrbiterJ = RotL64((aOrbiterJ * 12931373380977640645U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12795832560781931767U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 286378504074349650U;
            aOrbiterH = RotL64((aOrbiterH * 85453101173293509U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 5835304250436889513U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 12704972686724379659U) ^ RotL64(aNonceWordC, 49U);
            aOrbiterG = RotL64((aOrbiterG * 1198789639656336053U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12555700587254295099U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6740149669657971715U;
            aOrbiterE = RotL64((aOrbiterE * 9376048577305482691U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1541392147096889431U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16891341703173286949U;
            aOrbiterB = RotL64((aOrbiterB * 697452963711223355U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8811637585092392653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 13714409587461539863U;
            aOrbiterA = RotL64((aOrbiterA * 2578939920876994763U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 6U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 56U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 39U)) + RotL64(aNonceWordH, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterA, 23U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterG, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterI, 58U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterH, 27U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 47U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aNonceWordG, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_BasketBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
                     std::uint64_t pNonce,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE446F4660E2E4C43ULL + 0xDDF1F03EC81FE777ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB133BBA22DD8CCAFULL + 0xB4EBA1FFC528D3B5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x87513A42BA12DC8DULL + 0xF8BB707259A4A72FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x885FB447CA4D1183ULL + 0xC9958A29B7FECD41ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x92C2AA5AB6932BCFULL + 0xC2A48E7C2D90D2BFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9812B4373E278177ULL + 0xE59CF8EC9817A78FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x97DBC86933C6E8B1ULL + 0x93EDD28329564B42ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC335B30688220DCBULL + 0xCFF72510EC3D27D4ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordF, 22U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 59U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2343U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordD, 47U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2389U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 824U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) + RotL64(aIngress, 3U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 51U)) + 14823268998003220191U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 23U)) + 15295237288788213847U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 3U)) + 16434853402001133899U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 7555911304407871631U) + RotL64(aNonceWordB, 61U);
            aOrbiterF = (aWandererG + RotL64(aPrevious, 21U)) + 14977248264994834620U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 58U)) + 9707764144919392380U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 5U)) + 1277304385464681529U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 51U)) + 3089786220465849395U) + RotL64(aNonceWordE, 49U);
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 19U)) + 3700503853358695085U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 30U)) + 3240054112993517371U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 16897532076915366859U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18167359289798364307U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8870819278575769863U;
            aOrbiterG = RotL64((aOrbiterG * 9334066154398059075U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15363069206212330251U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 14858164441499725158U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14931933411393847915U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5357144808788707522U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 2910681277417754860U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) ^ RotL64(aNonceWordD, 12U);
            aOrbiterE = RotL64((aOrbiterE * 13170868582159347059U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 9824408699018165151U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 368370224788793300U;
            aOrbiterK = RotL64((aOrbiterK * 14358982366258729959U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7095398304588825115U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11418879758164313554U;
            aOrbiterJ = RotL64((aOrbiterJ * 5983520332639771791U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2171599720681913272U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 17593730219647495033U) ^ RotL64(aNonceWordH, 41U);
            aOrbiterC = RotL64((aOrbiterC * 12926053208918563087U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17755947635188715523U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14565740605227022106U;
            aOrbiterI = RotL64((aOrbiterI * 15866418354612945335U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14538017880915584414U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6174566474851449123U;
            aOrbiterA = RotL64((aOrbiterA * 179569008593475683U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3806438394748643441U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13737114463856719285U;
            aOrbiterF = RotL64((aOrbiterF * 13439346068497710151U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3698379331577470045U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1097081284062708554U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3498627643013255777U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 215117138867597766U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14823268998003220191U;
            aOrbiterH = RotL64((aOrbiterH * 12131828437975771377U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 11U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 10U)) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 48U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + RotL64(aNonceWordC, 47U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 3U)) + aOrbiterD) + RotL64(aNonceWordA, 57U)) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aCross, 54U) + aOrbiterF) + RotL64(aOrbiterK, 57U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterI, 18U));
            aWandererE = aWandererE + ((RotL64(aCross, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 53U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererE, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 30U) ^ RotL64(aNonceWordD, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8291U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 10378U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordC, 34U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6990U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 10500U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aCross, 35U)) + 1042610313571524121U) + aPhaseFOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aScatter, 11U)) + 3505725321008825582U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 12584654563843782991U) + RotL64(aNonceWordE, 27U);
            aOrbiterK = (aWandererK + RotL64(aIngress, 44U)) + 6645399144515770935U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 3608978423753715584U;
            aOrbiterG = (aWandererH + RotL64(aIngress, 27U)) + 8089198857670370983U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 15207251813516399879U;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 41U)) + 9579268660105824516U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 57U)) + 16055044469473802812U) + RotL64(aNonceWordB, 25U);
            aOrbiterB = (aWandererI + RotL64(aPrevious, 23U)) + 583811872609805949U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 18U)) + 7027491967970873942U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18256061823189677508U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12708429127816136937U;
            aOrbiterE = RotL64((aOrbiterE * 12593886633108075321U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12169216645156306078U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12694325407567795065U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3711789483877261899U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16109994660203297503U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4234704064165718913U;
            aOrbiterF = RotL64((aOrbiterF * 730085881474787681U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14119541943554602878U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 8777769004811352951U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2556957257736134223U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15642663488392549609U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 11594468530833278624U) ^ RotL64(aNonceWordG, 61U);
            aOrbiterD = RotL64((aOrbiterD * 6639306656361601143U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 7365350535791499871U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5965170981970155956U;
            aOrbiterA = RotL64((aOrbiterA * 1898702752753066851U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9115232101451815522U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 9433983580038990072U;
            aOrbiterK = RotL64((aOrbiterK * 1951249217843992179U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8810565477444156140U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12081286530401844859U;
            aOrbiterG = RotL64((aOrbiterG * 1991383259486140229U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7498045374283306625U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13095973566401200720U;
            aOrbiterJ = RotL64((aOrbiterJ * 2657451581036351987U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 18205793828042507364U) + RotL64(aNonceWordD, 45U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3339020890428651569U;
            aOrbiterB = RotL64((aOrbiterB * 10195916881103252701U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16957913958369950483U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 1042610313571524121U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11206619213970727629U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 23U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterD, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterI, 54U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 5U));
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterH, 48U)) + aPhaseFWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterB, 51U)) + RotL64(aNonceWordF, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterK, 37U)) + RotL64(aNonceWordA, 20U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 54U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordB, 5U)) ^ RotL64(aNonceWordC, 50U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14452U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 14763U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 57U) ^ RotL64(aNonceWordD, 37U)) ^ RotL64(aNonceWordG, 24U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15342U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11300U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 35U)) + 6243113109470883144U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 13U)) + 3891552123999605832U;
            aOrbiterE = (aWandererG + RotL64(aCross, 30U)) + 8758797898587019128U;
            aOrbiterB = ((aWandererC + RotL64(aIngress, 43U)) + 1005891374086408851U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 3713426782180050764U) + RotL64(aNonceWordG, 35U);
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 39U)) + 18358143862391573534U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 27U)) + 17504394029693712404U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 57U)) + 5312729289027417014U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 27U)) + 2560873623431186029U) + RotL64(aNonceWordC, 29U);
            aOrbiterK = (aWandererE + RotL64(aPrevious, 10U)) + 16309322822806704211U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 10195513918020652600U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 2552116263258744287U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7732784879810980089U) ^ RotL64(aNonceWordF, 9U);
            aOrbiterE = RotL64((aOrbiterE * 15041929399477790999U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 16499127570665381507U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 10890036715535519036U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9065115450010475187U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16288944603478791554U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14542766121469312846U;
            aOrbiterI = RotL64((aOrbiterI * 8435383464425875209U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 5973595239494084696U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1820492719977197097U;
            aOrbiterF = RotL64((aOrbiterF * 16164917159141304405U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10489529555776381736U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6392552206958240484U;
            aOrbiterJ = RotL64((aOrbiterJ * 11761477994533503307U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 10163241948999404556U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16054678853554707148U) ^ RotL64(aNonceWordH, 57U);
            aOrbiterK = RotL64((aOrbiterK * 10570418210789350091U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3606021702108590330U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 16920568417324295852U;
            aOrbiterC = RotL64((aOrbiterC * 5222656554577625385U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13889995689147406315U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7908387312354285092U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7995682580514280949U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14161911472715334589U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12386100977925313406U;
            aOrbiterA = RotL64((aOrbiterA * 17136336570895231639U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14408470657696841139U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7466281699619513012U;
            aOrbiterG = RotL64((aOrbiterG * 2706710684289882025U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11125044052260579351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6243113109470883144U;
            aOrbiterH = RotL64((aOrbiterH * 17390954549755941181U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 37U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 48U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            aWandererF = aWandererF + ((RotL64(aCross, 42U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aNonceWordA, 52U));
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterB) + RotL64(aNonceWordB, 25U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterH, 5U));
            aWandererK = aWandererK + (((RotL64(aCross, 14U) + aOrbiterD) + RotL64(aOrbiterB, 26U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 11U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 26U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 27U) ^ RotL64(aNonceWordE, 36U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21591U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 17616U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 60U) ^ RotL64(aNonceWordA, 35U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17972U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21619U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 17668251151213543491U) + RotL64(aNonceWordF, 5U);
            aOrbiterJ = (aWandererG + RotL64(aScatter, 11U)) + 16101602509895104517U;
            aOrbiterI = (aWandererA + RotL64(aCross, 51U)) + 9083915270773304935U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 19U)) + 12810720730318214811U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 18113428002071925621U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 46U)) + RotL64(aCarry, 23U)) + 1582208899354109878U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 5U)) + 4180688104819188154U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 57U)) + 8954598189262820611U;
            aOrbiterK = (aWandererH + RotL64(aCross, 39U)) + 15360094153175355879U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 30U)) + 8383954114668216260U) + RotL64(aNonceWordB, 24U);
            aOrbiterE = (aWandererC + RotL64(aIngress, 21U)) + 15626783326234049197U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 10609978564404958066U) + RotL64(aNonceWordD, 31U);
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17656516608997517984U;
            aOrbiterI = RotL64((aOrbiterI * 4590620354119899777U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 760077259110786536U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3597338735888033063U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6548831472863517621U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4431777844935985157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 10710423172154671296U;
            aOrbiterC = RotL64((aOrbiterC * 16267496318491473315U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 10240882795242085185U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterI) ^ 7826053487019825891U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) ^ RotL64(aNonceWordC, 35U);
            aOrbiterA = RotL64((aOrbiterA * 15053729937684375907U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 9418883403715727353U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11507423614799075545U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16189463984557044693U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11545217316421066655U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 617921402135485341U;
            aOrbiterK = RotL64((aOrbiterK * 8182920764965471653U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14456933220749921009U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 7990243583564535387U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5994900368027985469U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14023633125757654751U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11319146808574958827U;
            aOrbiterE = RotL64((aOrbiterE * 13676159969338309307U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14161653180846538446U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 17993503892528842342U;
            aOrbiterD = RotL64((aOrbiterD * 12184170842617942651U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10449311783872638478U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17210495321003036773U;
            aOrbiterJ = RotL64((aOrbiterJ * 17591257107603354151U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14586515403314763393U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17668251151213543491U;
            aOrbiterH = RotL64((aOrbiterH * 9367185933291003363U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 34U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + RotL64(aNonceWordG, 21U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 18U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aNonceWordH, 7U));
            aWandererB = aWandererB + (((RotL64(aCross, 18U) + aOrbiterI) + RotL64(aOrbiterB, 23U)) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 6U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 11U)) + aOrbiterC) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 42U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordA, 48U)) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24671U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24665U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordD, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24647U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24992U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 60U) + RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 47U)) + 11274974230580265396U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 42U)) + RotL64(aCarry, 41U)) + 16658438747342741547U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 37U)) + 16612986966106053844U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 5U)) + 9329502236843231290U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 14088261356708344656U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 53U)) + 13692608802007789581U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 3U)) + 6824473946645682398U) + RotL64(aNonceWordC, 19U);
            aOrbiterA = (((aWandererD + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 2072915876348570040U) + aPhaseFOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aScatter, 11U)) + 7420507753044460759U) + RotL64(aNonceWordF, 59U);
            aOrbiterF = (aWandererE + RotL64(aPrevious, 19U)) + 4677557318688502593U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 40U)) + 15081678577055628459U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7026792817486507482U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14871665922943969918U;
            aOrbiterJ = RotL64((aOrbiterJ * 694073180313083145U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6807734532159292872U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17882797335141303280U;
            aOrbiterE = RotL64((aOrbiterE * 15439872930381050291U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9233542707022629190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1205501586581350876U;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10878718669747466677U) + RotL64(aNonceWordB, 53U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 8066049063548639241U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3031382633089381605U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 861295180226875235U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9134969787937288583U;
            aOrbiterG = RotL64((aOrbiterG * 7565008208670843555U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6726642007159809594U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8061661744643240470U;
            aOrbiterD = RotL64((aOrbiterD * 6703498926835391813U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 13541412083111962884U) + RotL64(aNonceWordH, 13U);
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8617442758729315637U;
            aOrbiterH = RotL64((aOrbiterH * 15471862889276160953U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16884403561131293362U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9490680911678221233U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15988763830018001033U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10486145044311386738U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10200001044821063684U;
            aOrbiterC = RotL64((aOrbiterC * 16149790736141571017U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6997073594007878034U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13585783612009989767U;
            aOrbiterB = RotL64((aOrbiterB * 11425303157774550449U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3847846040256340653U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11274974230580265396U;
            aOrbiterI = RotL64((aOrbiterI * 13970270689108369205U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 12U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 29U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + (((RotL64(aCross, 44U) + aOrbiterE) + RotL64(aOrbiterB, 14U)) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ) + RotL64(aNonceWordE, 35U));
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 35U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 37U)) + aOrbiterJ) + RotL64(aNonceWordG, 40U));
            aWandererG = aWandererG + ((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 47U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 20U) + RotL64(aOrbiterH, 24U)) + aOrbiterA) + RotL64(aCarry, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32298U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32525U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 47U) ^ RotL64(aNonceWordG, 12U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31500U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28551U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aIngress, 5U)) + 18255347001097480328U) + RotL64(aNonceWordB, 15U);
            aOrbiterF = (aWandererI + RotL64(aScatter, 47U)) + 13679246790311505735U;
            aOrbiterC = (aWandererG + RotL64(aCross, 19U)) + 10565839529765027116U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 14327172566224769901U) + aPhaseFOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aScatter, 26U)) + 16239024612038195174U;
            aOrbiterG = (aWandererB + RotL64(aCross, 41U)) + 13800012174212131890U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 53U)) + 13900288860157577583U) + RotL64(aNonceWordF, 53U);
            aOrbiterA = ((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 4144386119777112740U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 23U)) + 3154558262670631372U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 7456728543137614001U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 12U)) + 11709519851158935384U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 15607438907832240304U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 9276575329661725624U) ^ RotL64(aNonceWordA, 61U);
            aOrbiterC = RotL64((aOrbiterC * 8879744070762412745U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 6459435969129449226U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6442382118416542275U;
            aOrbiterE = RotL64((aOrbiterE * 2921027306686588233U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12117432107282150865U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6831279293184793243U;
            aOrbiterG = RotL64((aOrbiterG * 2435360641135249073U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 9520022957804572889U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8322178689474588679U;
            aOrbiterD = RotL64((aOrbiterD * 1627707191467537115U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4162401591586869316U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 8994015844714895961U;
            aOrbiterA = RotL64((aOrbiterA * 15421910378057951895U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10038095909727959633U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17756404450592957616U;
            aOrbiterH = RotL64((aOrbiterH * 14255952184627347295U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3379089265413427719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11341713098678108441U;
            aOrbiterK = RotL64((aOrbiterK * 2500587373161411961U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4030296130743454165U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6332387792111212064U;
            aOrbiterJ = RotL64((aOrbiterJ * 16490982218150897861U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14893209417387662133U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 9265457389326311687U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9778404505547862689U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13496086915199406901U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14576555328710787951U;
            aOrbiterF = RotL64((aOrbiterF * 13155395071667672943U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 11482324648071976743U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 18255347001097480328U) ^ RotL64(aNonceWordC, 42U);
            aOrbiterI = RotL64((aOrbiterI * 10918514878283385643U), 41U);
            //
            aIngress = RotL64(aOrbiterH, 53U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 24U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterE) + RotL64(aOrbiterH, 21U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterF, 60U));
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + RotL64(aOrbiterG, 11U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterJ);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 53U)) + RotL64(aNonceWordD, 29U));
            aWandererC = aWandererC + ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 29U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 4U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 41U) + aOrbiterK) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 46U) + aOrbiterD) + RotL64(aOrbiterA, 47U)) + RotL64(aNonceWordE, 21U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5269U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 1633U)) & W_KEY1], 6U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1603U)) & W_KEY1], 53U) ^ RotL64(mSource[((aIndex + 5309U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 13U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 60U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aPrevious, 39U)) + 3448371607470865612U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 4U)) + RotL64(aCarry, 35U)) + 3743742913651580573U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 47U)) + 13069491287948807280U) + aPhaseCOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 16872779275586545632U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 17945792656755062795U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aScatter, 18U)) + 18199747196793731853U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 51U)) + 15953311878379809513U;
            aOrbiterK = (aWandererD + RotL64(aCross, 57U)) + 941268763494588338U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 43U)) + 10090221530365796809U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8335698093307607001U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 6147498804734306100U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6904444049941211327U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5980246079567570090U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4152167624425912978U;
            aOrbiterJ = RotL64((aOrbiterJ * 10019421651535123573U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14990418790239735916U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3418668387496597219U;
            aOrbiterK = RotL64((aOrbiterK * 12814077238529863119U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4206650904177199425U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3905470780938996069U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16030122739273137005U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9968672788233080924U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 602258075661864866U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2615726693066300065U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17751667243048041383U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2414054413585296027U;
            aOrbiterA = RotL64((aOrbiterA * 1049512574773201893U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6523322402744047752U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6729901917767398779U;
            aOrbiterB = RotL64((aOrbiterB * 8039939871405367139U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11460169185076814539U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7559640379553110573U;
            aOrbiterE = RotL64((aOrbiterE * 9864654321914036135U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17271150091827475028U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3541809324556914646U;
            aOrbiterI = RotL64((aOrbiterI * 12655168871428868639U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterG, 26U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 24U) + aOrbiterK) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterA, 57U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterF, 5U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterI, 37U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterF, 48U));
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 38U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10503U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((aIndex + 16081U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15361U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 12620U)) & W_KEY1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 5906639480605353429U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 21U)) + 5293518570213287605U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 3U)) + 15383185501428521377U;
            aOrbiterK = (((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 15364072512743978902U) + aPhaseCOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 23U)) + 4525473357144014271U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 11U)) + 10400911938125603074U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aCross, 41U)) + 16417506293824627550U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 56U)) + 2419329331753341815U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 29U)) + 14929222427923332069U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16771573504983922586U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1863466450051787622U;
            aOrbiterG = RotL64((aOrbiterG * 2585626547126027053U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12895350137096692415U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 3700979086526298327U;
            aOrbiterC = RotL64((aOrbiterC * 10279730254867618193U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1977099106211282426U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6144698304096915742U;
            aOrbiterB = RotL64((aOrbiterB * 5039822990560519609U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3858895556659724975U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1283646340363435327U;
            aOrbiterE = RotL64((aOrbiterE * 11622421841377018069U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6240532051889108891U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 757364889381634634U;
            aOrbiterF = RotL64((aOrbiterF * 943852137901972945U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5272945693977418174U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 6850528198786172283U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1966383079897679953U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14431587733859573714U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 16124590257870999553U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7755796211433191143U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14912695018110241411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11098623474413346520U;
            aOrbiterI = RotL64((aOrbiterI * 15167688959990872051U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3484847683376368686U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2295388097292719800U;
            aOrbiterD = RotL64((aOrbiterD * 1240808318176106909U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 47U)) + aOrbiterD);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterK) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterF, 12U)) + aOrbiterB) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 37U)) + aOrbiterA);
            aWandererD = aWandererD + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 21U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aCross, 36U) + aOrbiterA) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21938U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 21015U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 24304U)) & W_KEY1], 53U) ^ RotL64(aKeyRowReadB[((aIndex + 21784U)) & W_KEY1], 20U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (aWandererF + RotL64(aIngress, 6U)) + 1457104756581596530U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 23U)) + 6127240317844622874U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 16492290056044189421U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 10963676850938416468U) + aPhaseCOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aIngress, 19U)) + 4872917367399752405U;
            aOrbiterH = (aWandererK + RotL64(aScatter, 43U)) + 15218882377875616148U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 5934166612122118251U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 34U)) + 14215280930872003003U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 51U)) + 11428034799044600979U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5453003654321728726U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14273775120265649389U;
            aOrbiterD = RotL64((aOrbiterD * 5139018128323795309U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 328723770018440271U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13032190719588211088U;
            aOrbiterE = RotL64((aOrbiterE * 13363368478932798315U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2386881543033598494U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1649501123340887116U;
            aOrbiterA = RotL64((aOrbiterA * 11148976582360499033U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16462401546754210583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1510579201823042227U;
            aOrbiterF = RotL64((aOrbiterF * 16287912400104043275U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 6889066000014251983U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11324594596597724357U;
            aOrbiterC = RotL64((aOrbiterC * 15344987814648586023U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12237796033168436537U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 17306069670330000343U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3167451351403385259U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14197284538008811658U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4754134852883071927U;
            aOrbiterK = RotL64((aOrbiterK * 3484427259538998699U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 17201907781639753736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8318419319239859855U;
            aOrbiterI = RotL64((aOrbiterI * 10320390501983802091U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16012488623961565780U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15583721012865354925U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10656414363201743961U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 6U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterI, 57U)) + aOrbiterC);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterA, 34U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 51U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterC, 43U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 48U) + RotL64(aOrbiterE, 29U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 12U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 46U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 25393U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28733U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26058U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27424U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 19U)) + (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 13854738573712660276U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 39U)) + 16835460633412286294U;
            aOrbiterD = (aWandererC + RotL64(aCross, 22U)) + 6785859293758091931U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 27U)) + 126317283127992659U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 7568963536291415413U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 51U)) + 12294016745653004819U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 10U)) + 18269588932920281147U;
            aOrbiterB = (((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 5872406424994751026U) + aPhaseCOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 47U)) + 7764434758831474129U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4804168969415573371U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 959601763507651280U;
            aOrbiterD = RotL64((aOrbiterD * 4647396592804833217U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9257644462479293048U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14332699366894494579U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8829304078930625541U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10487012596470786004U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 612729229562321440U;
            aOrbiterA = RotL64((aOrbiterA * 11380387280507726003U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7845523921295625315U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12742115479740024747U;
            aOrbiterF = RotL64((aOrbiterF * 15578543510683986421U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 10294667720904610944U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14369711143154904567U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13753005602288309379U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10918344717497681894U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 18136794828308636957U;
            aOrbiterC = RotL64((aOrbiterC * 17899418637978002409U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14378638206724886404U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7077588188450008059U;
            aOrbiterB = RotL64((aOrbiterB * 485375960462924335U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8941870012851971932U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15242087859620352399U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4963002810455992839U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10395280254030875387U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6826595516076975980U;
            aOrbiterH = RotL64((aOrbiterH * 6198886240333178001U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 37U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 60U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterB, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 41U)) + aOrbiterC) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 47U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 5U)) + aOrbiterC);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 12U)) + aOrbiterH) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 592U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 7641U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 702U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 3U)) ^ (RotL64(aCross, 36U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 39U)) + 10881271196314989997U) + aPhaseDOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 27U)) + 6406461249988567558U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aCross, 48U)) + RotL64(aCarry, 3U)) + 17255067918280095959U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 16690850682497718411U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 5576201059361086866U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 11991259685693687554U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14652535244217836909U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18283959577075524171U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1701789037170782122U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 953429054903473833U;
            aOrbiterA = RotL64((aOrbiterA * 13482379459700651427U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 12064513610469714211U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7993881398822002424U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11572884842788918377U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14421313768013320050U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11112386845630998889U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11771526352030371669U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17069630896535699015U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3308240081138623373U;
            aOrbiterH = RotL64((aOrbiterH * 10449509484417835159U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterA, 53U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterD, 3U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 28U)) + aOrbiterE);
            aWandererC = aWandererC + ((RotL64(aCross, 38U) + aOrbiterD) + RotL64(aOrbiterA, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + RotL64(aWandererI, 46U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8591U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16221U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8718U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15381U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 18180797995100240808U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 41U)) + 6585906608223552885U) + aPhaseDOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 14088708930575939855U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 468974153311516044U) + aPhaseDOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 51U)) + 12481951025619894110U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17227987923860711763U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4373962756657477139U;
            aOrbiterJ = RotL64((aOrbiterJ * 6069068316234356267U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2077576476565420951U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17435011300234663764U;
            aOrbiterC = RotL64((aOrbiterC * 8910133867294004711U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 4118039398293246896U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13724716599855216683U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17556333902751079677U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12391461204689596339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9900605191533799627U;
            aOrbiterB = RotL64((aOrbiterB * 13553565332531046301U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 972946858824366125U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 17247681919694541215U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2974639094630445643U), 19U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterH, 28U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterC, 13U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterE, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 30U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 20565U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 19081U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18102U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16963U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 26U)) + RotL64(aCarry, 23U)) + 14157904117287696136U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 3U)) + 7369512677371640676U) + aPhaseDOrbiterAssignSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 43U)) + 8411250745902073798U;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 5002041814539710275U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 9538041410816283124U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 5210700103927513061U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7600709399101287982U;
            aOrbiterH = RotL64((aOrbiterH * 6777896926889560889U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2366369466696580499U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5544575244203019109U;
            aOrbiterJ = RotL64((aOrbiterJ * 16231219246786333057U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8710073749110329779U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15998211310115361630U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15275657696897688955U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15354357553877376422U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10657523549259276169U;
            aOrbiterG = RotL64((aOrbiterG * 13695239532898311073U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10405750198355464768U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3465819693133515142U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14678343718277562799U), 37U);
            //
            aIngress = RotL64(aOrbiterG, 58U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterC, 56U)) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            aWandererA = aWandererA + (((RotL64(aIngress, 30U) + aOrbiterH) + RotL64(aOrbiterC, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterC, 21U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27428U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneB[((aIndex + 32470U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29852U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27231U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 6U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 19U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 3U)) + 10038936806177516123U) + aPhaseDOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 51U)) + 1773168435195292638U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 10655711161526628072U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 23U)) + 14422295664639740437U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 11U)) + 4125228715513159576U) + aPhaseDOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 3670449653158650845U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 17553727567180813057U;
            aOrbiterD = RotL64((aOrbiterD * 11814335762020146785U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5111401772713882743U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7688573124662314413U;
            aOrbiterI = RotL64((aOrbiterI * 10846442063022821393U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9438375825507814395U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 14177477039902118886U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6467406626985022537U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 16329942595859623928U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3990536794006836672U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 579024714339065373U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5072881436583180756U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16789727877867289997U;
            aOrbiterA = RotL64((aOrbiterA * 8766246302636197905U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 52U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 28U) + aOrbiterC) + RotL64(aOrbiterI, 57U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterC) + RotL64(aCarry, 37U)) + aPhaseDWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 6U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 43U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3148U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((aIndex + 1424U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5260U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 629U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 37U)) + (RotL64(aCarry, 50U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 2168513956284366370U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 53U)) + 10290361969974613111U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aCross, 47U)) + 15673836275828498050U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 18U)) + 16600540024145812236U) + aPhaseEOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 9428052101528111892U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 37U)) + 12763657928312763377U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 11U)) + 10751286982008662485U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1708230173038057979U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4011389705422783816U;
            aOrbiterC = RotL64((aOrbiterC * 11692237130784795961U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11704428328093077714U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2055336619674699284U;
            aOrbiterG = RotL64((aOrbiterG * 6374289210096410907U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1870865272102705804U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 3574214263751923179U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13132083406834413563U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 984611970726966186U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15207945449947643672U;
            aOrbiterB = RotL64((aOrbiterB * 9539470161576639981U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4181398506373973169U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15222345431506025949U;
            aOrbiterK = RotL64((aOrbiterK * 6925143692628659467U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15023513452326240962U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14965669361708810699U;
            aOrbiterE = RotL64((aOrbiterE * 587008860996713147U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7985755518735406360U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 225592097619240187U;
            aOrbiterA = RotL64((aOrbiterA * 2313509354133400439U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 51U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 42U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 11U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterG, 57U)) + aOrbiterK) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 36U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8982U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10546U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10469U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 15584U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 29U)) + (RotL64(aCarry, 13U) + RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 21U)) + 12690502671561165478U) + aPhaseEOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aIngress, 13U)) + 17519943923428102801U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 41U)) + 10705515807975331385U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 29U)) + 16586447272278538179U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 13U)) + 8006560996840971798U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 35U)) + 12928600185788857701U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aIngress, 6U)) + 14240723153798267172U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 8636219177994872072U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 7586790235186467512U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15052686382507614169U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1103807034179512424U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7547526530239498693U;
            aOrbiterE = RotL64((aOrbiterE * 3360295583636013509U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8380239679344786397U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5690809173787433519U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5354724308093372953U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 8390902801141804609U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3507306189192059486U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18336280496510253103U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6190745292098482871U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8065418693975056902U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6414621418430102589U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12111755051718111803U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7605877769709909297U;
            aOrbiterJ = RotL64((aOrbiterJ * 17525248694315944599U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5969794501112646237U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5127559299360591476U;
            aOrbiterI = RotL64((aOrbiterI * 4521563633438853069U), 13U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 36U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 14U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 12U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterB);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21835U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 19416U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23932U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 23940U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 13583136155674166402U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 3U)) + 12830472187484919497U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 11U)) + 18081197909484522509U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 37U)) + 8680634051297891550U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 20U)) + 13939998767458656823U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 37U)) + 1795730579103692594U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 51U)) + 17369751719734069999U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 224769585901248068U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 4133547085925268180U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2611561365156544735U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 7022512056309567391U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 10319484359046945495U;
            aOrbiterH = RotL64((aOrbiterH * 3400140531307001933U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10483878349412282069U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6481381149199985736U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9701719367082506253U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13721077228796934509U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9704818014314175007U;
            aOrbiterA = RotL64((aOrbiterA * 760445624027740287U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6253040047758584339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16890211690273641226U;
            aOrbiterB = RotL64((aOrbiterB * 5622534399866057841U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6216227831265032436U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2023609047004658739U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3252332895698310147U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9201669637050388263U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5106927540934338576U;
            aOrbiterI = RotL64((aOrbiterI * 6368134569042291431U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 14U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 23U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + aPhaseEWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterH) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aPhaseEWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32284U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneB[((aIndex + 30586U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32761U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneD[((aIndex + 28701U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 15813325389431304548U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + 2223874171125403602U) + aPhaseEOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aPrevious, 23U)) + 5510483568496824130U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 15474152493495661876U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 11U)) + 16846339705130829195U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 1289670576865739669U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 18017354919647006944U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8539685539928984921U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3333721400836704048U;
            aOrbiterK = RotL64((aOrbiterK * 3745286323481400085U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 2261560416623815491U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4377786131746816567U;
            aOrbiterE = RotL64((aOrbiterE * 9164777834392621157U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18047393176583722719U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8184724021940434631U;
            aOrbiterB = RotL64((aOrbiterB * 9800116157750921119U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10469895939183324807U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14543391765109879223U;
            aOrbiterC = RotL64((aOrbiterC * 4817987697437667225U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5757225781746158178U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3539000495894022869U;
            aOrbiterG = RotL64((aOrbiterG * 1032298408884695925U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11288971092707065923U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 2761384065186568294U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3323838837427471051U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7120580145300417101U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6977246291769372866U;
            aOrbiterF = RotL64((aOrbiterF * 15170353875184253779U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 29U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK + ((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterF, 12U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 3U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + RotL64(aWandererK, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_BasketBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2609U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 959U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3331U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 829U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aPrevious, 26U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aCross, 3U)) + 12690502671561165478U) + aPhaseFOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 51U)) + 17519943923428102801U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 27U)) + RotL64(aCarry, 23U)) + 10705515807975331385U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 16586447272278538179U) + aPhaseFOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aIngress, 43U)) + 8006560996840971798U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 12928600185788857701U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 14240723153798267172U;
            aOrbiterB = RotL64((aOrbiterB * 7446040187505339853U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 8636219177994872072U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7586790235186467512U;
            aOrbiterK = RotL64((aOrbiterK * 15052686382507614169U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1103807034179512424U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7547526530239498693U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3360295583636013509U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8380239679344786397U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 5690809173787433519U;
            aOrbiterE = RotL64((aOrbiterE * 5354724308093372953U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8390902801141804609U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3507306189192059486U;
            aOrbiterF = RotL64((aOrbiterF * 18336280496510253103U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterB, 38U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8617U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15881U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15713U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10771U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 54U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 24U)) + RotL64(aCarry, 51U)) + 9220392006207660113U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 39U)) + 11305018553489132882U) + aPhaseFOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 29U)) + 5860373868073513684U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 57U)) + 12319586170883987589U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 14072333614354649021U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9332158529453194608U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3860569321145958686U;
            aOrbiterK = RotL64((aOrbiterK * 907977527866467591U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8119005668901240093U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13918259792880333239U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5441062406822088853U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6938856216758228704U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3960905839118710604U;
            aOrbiterB = RotL64((aOrbiterB * 16203746868670689793U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 6043879193734253929U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 15691425268831319195U;
            aOrbiterA = RotL64((aOrbiterA * 7189195135654636271U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14912209933584715274U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16180183395910618923U;
            aOrbiterC = RotL64((aOrbiterC * 3942858974766467849U), 21U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 52U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterK, 58U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 39U)) + aOrbiterA) + aPhaseFWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23330U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 20187U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20331U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 17018U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 47U) + RotL64(aCarry, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 13U)) + 1952750591494698524U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 4488270851303332830U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 57U)) + 2738763375328927635U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 6728843649480454340U;
            aOrbiterA = (((aWandererA + RotL64(aPrevious, 24U)) + RotL64(aCarry, 19U)) + 10490717875258865358U) + aPhaseFOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1429288737812910205U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2761375016998907636U;
            aOrbiterE = RotL64((aOrbiterE * 16589197409983023283U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 1088988605204499835U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6829840407300289709U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13101432880030791787U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9267240337867690471U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 8120113021183975703U;
            aOrbiterF = RotL64((aOrbiterF * 14296504593187173107U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 1340980511302566784U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11874452169979878835U;
            aOrbiterH = RotL64((aOrbiterH * 8638486178860092537U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 1872314794140971426U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6013952618696225751U;
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 60U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 20U) + aOrbiterA) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterG, 26U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27448U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 26024U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30346U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 27895U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = (aWandererD + RotL64(aIngress, 5U)) + 13278949403988203974U;
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 30U)) + RotL64(aCarry, 5U)) + 9213599924054673756U) + aPhaseFOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 1255746482932381798U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 11575321997144516122U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 21U)) + 15881587525529432437U) + aPhaseFOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9846195809864862707U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12319815691858217670U;
            aOrbiterK = RotL64((aOrbiterK * 14271546305640811091U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16322617427294439587U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16332130810525887437U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7588076439690559343U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4920951156015336794U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16767126455124552329U;
            aOrbiterD = RotL64((aOrbiterD * 4440352337076842603U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12553595911087945223U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1437522202135436142U;
            aOrbiterI = RotL64((aOrbiterI * 2001992794165550905U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 12313100454852227143U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 2761983020631055729U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3874839760378039509U), 41U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 29U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 54U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 40U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 26U));
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 385U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 4079U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3312U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneD[((aIndex + 8016U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 52U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 13499155707765393469U;
            aOrbiterI = (aWandererI + RotL64(aCross, 11U)) + 3740324981823726185U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 20U)) + 5470765363949735652U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 3U)) + 3446436171274452326U) + aPhaseGOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 35U)) + 1778929412631211933U) + aPhaseGOrbiterAssignSaltD[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14666308799855220954U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 4548410236791175055U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6822908616815218501U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 5829739767694190372U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14319231414903675748U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4966501102515775601U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 1513851750246111405U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1685620217748986019U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9286548037413609445U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16284162182006054402U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 6271539598462003309U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13923286694131331137U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12669312437565969473U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11894755313393001665U;
            aOrbiterB = RotL64((aOrbiterB * 12556759675372354075U), 13U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 19U)) + aOrbiterK) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterE, 28U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15279U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13249U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13553U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16030U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 48U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 13442819395490639310U) + aPhaseGOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 8187292523194120936U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 3U)) + 11469697159823131388U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 38U)) + RotL64(aCarry, 3U)) + 13414083692375929653U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 47U)) + 11404010733687907517U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6783212827186218247U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8561131439340372614U;
            aOrbiterH = RotL64((aOrbiterH * 7426867125542470683U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 6252609642004429113U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12804867444200448952U;
            aOrbiterE = RotL64((aOrbiterE * 3114688959081972615U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2739648749603690781U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14808861217017399752U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 373911885694012101U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17588866502571268888U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5882260142735642980U;
            aOrbiterJ = RotL64((aOrbiterJ * 7688252946143263869U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 15493099088132862949U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 5175647411532429582U;
            aOrbiterA = RotL64((aOrbiterA * 15226544495598541883U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 20U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 4U) + aOrbiterJ) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 43U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 17540U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((aIndex + 16640U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19750U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19927U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCarry, 53U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 29U)) + 12632404972795375757U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 5U)) + 5351879979055988456U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 51U)) + 3597737727467443413U) + aPhaseGOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 2830846754917852318U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 19U)) + 17311925960294518018U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2083584640523695383U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15049343611387010158U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5567816356477420399U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6443050378205811147U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6021965178697344070U;
            aOrbiterC = RotL64((aOrbiterC * 6054064448935006741U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5080289878758029976U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 576927745306972983U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16008958833683246115U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4728489691382690859U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6184355840165758855U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1515043910404156423U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 11220539885798595450U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11091438724966718214U;
            aOrbiterD = RotL64((aOrbiterD * 8225347114759391961U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 14U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererD = aWandererD + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterC, 48U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererB, 60U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28915U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 30319U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32577U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30541U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 41U)) + 2783898056762489197U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 21U)) + 7177192902873343053U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 56U)) + 12254703232691980774U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 27U)) + 15446547245691219559U) + aPhaseGOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 888475203006174856U) + aPhaseGOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3649183529366307877U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4642631047518805167U;
            aOrbiterK = RotL64((aOrbiterK * 14791564497487717167U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6108329730724782250U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8334054653023816636U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9352516059501924393U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5891895375031474350U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3176720746238477862U;
            aOrbiterA = RotL64((aOrbiterA * 1869961473768307911U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6111038696865301675U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 11914998302228682704U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11738924766359642853U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17005063057791320948U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 18333780598768130670U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5416759844884107303U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + aPhaseGWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 24U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterI) + RotL64(aOrbiterK, 4U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 1194U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7288U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4977U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((aIndex + 7511U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 14U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererD + RotL64(aCross, 29U)) + 15036852811491820366U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 305637140752898475U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 11948631574496129610U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 21U)) + 5321623592482991426U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aCross, 44U)) + RotL64(aCarry, 43U)) + 4075270159062690728U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 15111580500356908928U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7244150695504160363U;
            aOrbiterD = RotL64((aOrbiterD * 2445733898697939969U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5131563519577488862U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5881954992088651371U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2424421828597294607U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12780935808751507998U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12599159643925470226U;
            aOrbiterJ = RotL64((aOrbiterJ * 17690046932587062701U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9466589929741834066U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6093158735705189789U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7453778295800853653U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17461243886150519249U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15456408913739900718U;
            aOrbiterE = RotL64((aOrbiterE * 16093292401746174671U), 41U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 4U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + aPhaseHWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 6U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16244U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 10826U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9124U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 11660U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 20U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 39U)) + 3339283916456813609U) + aPhaseHOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterE = (aWandererC + RotL64(aIngress, 30U)) + 11339086426180649584U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 16819191669329316585U;
            aOrbiterG = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 39U)) + 8361916937762630725U) + aPhaseHOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 18031328374429899857U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 18261756894092897276U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 4250319792907645666U;
            aOrbiterH = RotL64((aOrbiterH * 7053489184750217963U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1492411503643460886U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17369549067879344180U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2947354306696216579U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7301713524358676722U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 2985193736033012535U;
            aOrbiterB = RotL64((aOrbiterB * 7473297294949338265U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 14086975808140927408U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 10390516547834639800U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 18205555540941493267U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16967799565443938873U;
            aOrbiterG = RotL64((aOrbiterG * 3009081009044782443U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterD) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aCross, 6U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 35U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterE, 20U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 16455U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18252U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23047U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18565U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 58U) ^ RotL64(aCarry, 13U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 23U)) + 3973833383430652211U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 5760227042747169187U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 38U)) + RotL64(aCarry, 5U)) + 4923009065139227286U;
            aOrbiterD = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 1477807307009107590U) + aPhaseHOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 51U)) + 5707194514329007301U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5340439728375269724U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17080457898946572387U;
            aOrbiterA = RotL64((aOrbiterA * 17719588880215414933U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 281559150259472813U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16160633048230910560U;
            aOrbiterB = RotL64((aOrbiterB * 16883442583309073785U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9003989610509592121U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 10579322462808454333U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 100832431598087235U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15059383289528723069U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10417647757852880956U;
            aOrbiterD = RotL64((aOrbiterD * 1457919230286043137U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14484665027393813330U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12344463053485837974U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5762654194001525041U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 3U)) + aOrbiterC) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aPhaseHWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 24U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 51U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 29608U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28564U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31388U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneC[((aIndex + 26020U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 3236820517816085022U;
            aOrbiterA = (((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 741288875914097926U) + aPhaseHOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (((aWandererK + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 8417246926007729580U) + aPhaseHOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 47U)) + 9715717805774537170U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 30U)) + 14360243844821619482U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10760908100206775334U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3434641779946167811U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3305698324169010803U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7885568822756234567U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3041563437672051294U;
            aOrbiterJ = RotL64((aOrbiterJ * 11440300917533482297U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15761355327564963516U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1158633562785937421U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15511324886867188235U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 9338581575871970653U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9172038894262857354U;
            aOrbiterA = RotL64((aOrbiterA * 3110871165285625807U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14653924713599790081U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3854497592598563309U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11737111068815795303U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 26U) + aOrbiterC) + RotL64(aOrbiterA, 40U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 3U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterB, 51U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererB, 11U);
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
