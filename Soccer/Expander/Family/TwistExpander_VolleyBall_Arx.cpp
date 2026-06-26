#include "TwistExpander_VolleyBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_VolleyBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aWorkLaneA = pWorkSpace->mWorkLaneA;
    [[maybe_unused]] std::uint8_t *aWorkLaneB = pWorkSpace->mWorkLaneB;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x866C5B35DC82DBEDULL + 0xC42C18E76B05C185ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x82856D65093CEE93ULL + 0x8A1A26B888406F47ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD16F3D40245E121DULL + 0x8B4BD0A0D450F4DCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9CC81775F5B6605BULL + 0xAB31E7CDE1B78339ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x94619DF5F0B4887BULL + 0xCA9DF092CEB89DE7ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x819BCAAEBF06C293ULL + 0xCD4F60DB4CA67323ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF820DE5037E3C43DULL + 0x9042BD04E099AB80ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFF4DFABFFDB3E945ULL + 0xE772A166CF33073AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB85A009B1EDB048BULL + 0x977929139B930057ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDBD98231A0E947DBULL + 0x83F984D816F5C81EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xF8FC772A2E66572BULL + 0xA8B99C53F0158800ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8300EF8F2A670F11ULL + 0xC9F59E019F820817ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD9F6570987A3628BULL + 0xD7BBE3699BEA7331ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xCD794AAB7C50F2D1ULL + 0xB453A63489A3FEF3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA9A93000B8119CA1ULL + 0xCA271DC249BA9E4EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB25D9A10CAB7D111ULL + 0x98600E624E95BBD1ULL);
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
        // read from: mSource, pSnow, aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_a_loop_a loop 1
        // read from: mSource, pSnow
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2276U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((aIndex + 4781U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3462U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3289U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 47U)) ^ (RotL64(aPrevious, 4U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 5568146815535263910U) + aNonceWordL;
            aOrbiterA = ((aWandererE + RotL64(aCross, 60U)) + 7736084960873834666U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 39U)) + 1336413621817562093U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 11U)) + 5218462026934984692U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 47U)) + 7048890985969555935U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 56U)) + 13415955213864702118U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 19U)) + 5657023257021528548U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 14338310943137497116U) + aNonceWordE;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 41U)) + 12305161641833950473U) + aNonceWordM;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 51U)) + 14514226578370459131U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 47U)) + 12692904083266024340U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11012959130001327964U) + aNonceWordN;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 7106471380403489078U;
            aOrbiterK = RotL64((aOrbiterK * 515626559384817223U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3718101961355280891U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13364192077222322664U;
            aOrbiterJ = RotL64((aOrbiterJ * 1411328915372590283U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6720867800318913440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14497243926965866546U;
            aOrbiterB = RotL64((aOrbiterB * 13595058589060114653U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5789056168233262435U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14438482587495779937U;
            aOrbiterI = RotL64((aOrbiterI * 10593535547917767263U), 57U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 313917798940179945U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 15241845511889502917U;
            aOrbiterF = RotL64((aOrbiterF * 16483477103771326107U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 3591957424821693032U) + aOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1559050939014453558U;
            aOrbiterC = RotL64((aOrbiterC * 17933346117866604725U), 51U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterB) + 15340590914441451383U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5538037287390050110U;
            aOrbiterH = RotL64((aOrbiterH * 4082576643144951473U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4151270491894969214U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 263593701314144898U;
            aOrbiterA = RotL64((aOrbiterA * 10372046955804512457U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9025145270653080646U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6867950904094870056U;
            aOrbiterD = RotL64((aOrbiterD * 9975247022340627751U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3183454301841252109U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3054904157641290615U;
            aOrbiterE = RotL64((aOrbiterE * 4092317552439599475U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1768555574434776135U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5568146815535263910U) ^ aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12466957001078663927U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 30U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 58U)) + aOrbiterC) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterB, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterC, 51U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 48U) + aOrbiterK) + RotL64(aOrbiterB, 44U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterI, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererG = aWandererG + ((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterK, 29U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererC = aWandererC + ((((RotL64(aIngress, 34U) + aOrbiterH) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 2
        // read from: aWorkLaneA, mSource, pSnow
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7491U)) & S_BLOCK1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7671U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 6851U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 6331U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 43U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 21U)) + 6521330037475130256U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 12611880456055428940U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 53U)) + 12061611078130934708U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 37U)) + 1558112410801116984U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 37U)) + 10509115227850160786U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 14U)) + 4045915960688792066U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 5U)) + 1196541286513243082U;
            aOrbiterA = (aWandererK + RotL64(aCross, 3U)) + 15564991032722373702U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 35U)) + 4897765238703641798U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 12U)) + 12327429514907752733U) + aNonceWordE;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 19U)) + 6189189797708711636U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6374267075282018852U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1888758503831341439U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 74387714918264257U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14956857689299491800U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14879361107223331957U;
            aOrbiterJ = RotL64((aOrbiterJ * 9166712966729591953U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16086885494838105042U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8069724185844303923U;
            aOrbiterH = RotL64((aOrbiterH * 8878470736758734353U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10854345917959911439U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7078313614360332089U;
            aOrbiterF = RotL64((aOrbiterF * 9864025732292844871U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15083669236062255011U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 594879695916679116U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 9852515479152735283U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6721466068234534523U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 475816724162626782U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4799725182757588407U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4341655358154605899U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 15477254302340298586U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13961520225881974201U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 10179091913200895775U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6310490897546909571U;
            aOrbiterI = RotL64((aOrbiterI * 15080621088825477613U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 13462682513035460711U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16739138858084100385U;
            aOrbiterA = RotL64((aOrbiterA * 16386371811268298031U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13608837667062268989U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 12902415667552110103U;
            aOrbiterK = RotL64((aOrbiterK * 16398790854093048017U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 16596211634603915761U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6521330037475130256U;
            aOrbiterE = RotL64((aOrbiterE * 631958426544321145U), 29U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 6U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 48U)) + aNonceWordM);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterD, 21U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 20U) + RotL64(aOrbiterC, 35U)) + aOrbiterB) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterA, 26U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltD[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + aOrbiterF) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterK, 3U)) + aOrbiterB) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 3U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 3
        // read from: aWorkLaneB, aWorkLaneA, mSource, pSnow
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13311U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15008U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 12677U)) & S_BLOCK1], 11U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 15728U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCross, 21U) + RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 13278949403988203974U;
            aOrbiterK = (aWandererG + RotL64(aCross, 23U)) + 9213599924054673756U;
            aOrbiterG = (aWandererI + RotL64(aIngress, 53U)) + 1255746482932381798U;
            aOrbiterF = ((((aWandererE + RotL64(aPrevious, 46U)) + RotL64(aCarry, 13U)) + 11575321997144516122U) + aOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 15881587525529432437U) + aNonceWordK;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 35U)) + 9846195809864862707U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 12319815691858217670U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 5U)) + 16322617427294439587U;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 50U)) + 16332130810525887437U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 13U)) + 4920951156015336794U;
            aOrbiterB = (aWandererK + RotL64(aCross, 3U)) + 16767126455124552329U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12553595911087945223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1437522202135436142U;
            aOrbiterG = RotL64((aOrbiterG * 2001992794165550905U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 12313100454852227143U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2761983020631055729U;
            aOrbiterJ = RotL64((aOrbiterJ * 3874839760378039509U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17635303588421554367U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 788212489507463763U;
            aOrbiterK = RotL64((aOrbiterK * 17896475584538528059U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5192552894670654434U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6784748488807738811U;
            aOrbiterE = RotL64((aOrbiterE * 8077237651953896479U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16113417046719114943U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1096874945215225916U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 17308604412622879833U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 7610274704570171595U) + aOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 10466070212284342550U;
            aOrbiterA = RotL64((aOrbiterA * 6449728258497920613U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6777845928873855221U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5251515022021984126U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9018277343404261611U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13849343158824111498U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 7977711210181714021U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4182053966171053577U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6494539818728106982U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11314590450226080781U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 12455979257225599157U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 552687702594328012U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14961304171192292246U;
            aOrbiterD = RotL64((aOrbiterD * 846375892915484717U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9771874402848476494U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13278949403988203974U;
            aOrbiterB = RotL64((aOrbiterB * 2119203863777871233U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 54U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 43U)) + aOrbiterA);
            aWandererH = aWandererH ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 46U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 34U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 27U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterF, 29U)) + aNonceWordC);
            aWandererE = aWandererE ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterI, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordM);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 4
        // read from: aExpandLaneA, aWorkLaneB, aWorkLaneA, mSource
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19289U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17459U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21817U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 20828U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 35U)) ^ (RotL64(aCross, 19U) + RotL64(aPrevious, 52U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 29U)) + 9220392006207660113U) + aOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aCross, 3U)) + 11305018553489132882U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 39U)) + 5860373868073513684U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 12319586170883987589U;
            aOrbiterD = (aWandererE + RotL64(aCross, 13U)) + 14072333614354649021U;
            aOrbiterI = (((aWandererI + RotL64(aScatter, 48U)) + 9332158529453194608U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererD + RotL64(aIngress, 43U)) + 3860569321145958686U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 8119005668901240093U;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 27U)) + 13918259792880333239U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 35U)) + 6938856216758228704U) + aNonceWordO;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 43U)) + 3960905839118710604U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 6043879193734253929U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15691425268831319195U;
            aOrbiterE = RotL64((aOrbiterE * 7189195135654636271U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 14912209933584715274U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16180183395910618923U;
            aOrbiterD = RotL64((aOrbiterD * 3942858974766467849U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 4966642362507707776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6962226782462822861U;
            aOrbiterI = RotL64((aOrbiterI * 3647802407741095419U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12409120845092026295U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2302946450253872465U;
            aOrbiterC = RotL64((aOrbiterC * 7099576330777297911U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16118304388937163838U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 15968419034359049422U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11736207775827080165U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 17098982091525008231U) + aNonceWordF;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10298979200690822062U;
            aOrbiterJ = RotL64((aOrbiterJ * 12620028874653521945U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 552826643694256437U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11786560990790695378U) ^ aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11190309640069208311U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13730399230389329793U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17614226859252305432U;
            aOrbiterK = RotL64((aOrbiterK * 2640019643570222977U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1062738267846296283U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13959480457644980835U;
            aOrbiterF = RotL64((aOrbiterF * 1194145909157002977U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 4635071137794189167U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13374502212707796180U;
            aOrbiterG = RotL64((aOrbiterG * 129680788767298945U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11479902881487238033U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9220392006207660113U;
            aOrbiterH = RotL64((aOrbiterH * 1437457810224888809U), 3U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 48U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 50U)) + aOrbiterH) + aNonceWordD);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + RotL64(aOrbiterK, 3U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordC);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 37U));
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterK, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 58U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 24U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 19U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 5
        // read from: aExpandLaneB, aExpandLaneA, aWorkLaneB, aWorkLaneA
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24625U)) & S_BLOCK1], 34U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25449U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26148U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 26275U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 20U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 26U)) + RotL64(aCarry, 53U)) + 14179205183062705133U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 5U)) + 210032324058740920U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 57U)) + 7387115089142500152U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 17583362781238061430U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 3U)) + 4991442849150005943U;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 47U)) + 2891376254689854555U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererK + RotL64(aCross, 51U)) + 10523274382407446239U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 3861893764676218667U;
            aOrbiterB = (aWandererE + RotL64(aCross, 24U)) + 3366674459852093746U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 21U)) + 5898492634386601145U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 29U)) + 7047353571244768721U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14374108805453186316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8763667021501226510U;
            aOrbiterE = RotL64((aOrbiterE * 7694695426430267863U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 18261523829316379575U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 650477532238860965U;
            aOrbiterJ = RotL64((aOrbiterJ * 8291758490821819851U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2162326554604894042U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5776546692501825278U;
            aOrbiterF = RotL64((aOrbiterF * 14911545784585246537U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3501863793638415049U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14853789267425352958U;
            aOrbiterK = RotL64((aOrbiterK * 10590325397179928739U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15399673014671329743U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 12253428583438990426U;
            aOrbiterG = RotL64((aOrbiterG * 12052855472196447849U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13202953937621953839U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 7547616636832698398U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9533399972562428073U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15709801946594868318U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12458677982746610971U;
            aOrbiterD = RotL64((aOrbiterD * 6662570874316418993U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6957370791367530127U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10511379961344950861U;
            aOrbiterB = RotL64((aOrbiterB * 15551333099264031337U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16489828646914719181U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6827290294344770680U;
            aOrbiterC = RotL64((aOrbiterC * 6408864925398536651U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3308531598034561099U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10336568208337990458U;
            aOrbiterI = RotL64((aOrbiterI * 5606941634846696657U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 14116471880098183908U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14179205183062705133U;
            aOrbiterA = RotL64((aOrbiterA * 8824119255416045191U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 14U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 12U)) + aOrbiterK) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 47U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterK, 41U)) + aNonceWordA);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterA, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 21U) + RotL64(aOrbiterC, 27U)) + aOrbiterK) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererK = aWandererK + (((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterE, 36U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 3U)) + aOrbiterE) + aNonceWordB);
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterF, 43U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 26U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_a loop 6
        // read from: aExpandLaneC, aExpandLaneB, aExpandLaneA, aWorkLaneB
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32085U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 32108U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27855U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31980U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 53U)) + (RotL64(aIngress, 41U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 11U)) + 2101601659597850213U) + aNonceWordJ;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 48U)) + RotL64(aCarry, 39U)) + 2759794072560720121U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 9443562552411269339U) + aNonceWordC;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 10801360546699857975U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 51U)) + 8020716394829332019U) + aNonceWordK;
            aOrbiterE = (aWandererG + RotL64(aScatter, 29U)) + 1021894212367773801U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 27U)) + 13346855534622490176U;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 18U)) + 16359309548462953836U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 35U)) + 12642446944680783519U) + aOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 39U)) + 8197424982767553380U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 53U)) + 14346334610901859094U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14171304260534233539U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterC) ^ 334531601308283605U) ^ aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterJ = RotL64((aOrbiterJ * 5012968232749075075U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10707856298471572695U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 18364775750091914766U;
            aOrbiterB = RotL64((aOrbiterB * 15735143943129143265U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8531394793118363836U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15352876929406908882U;
            aOrbiterE = RotL64((aOrbiterE * 475199047053777179U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 567682016232278157U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2068146551757663119U;
            aOrbiterK = RotL64((aOrbiterK * 1557877740957797555U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 7776122587613256525U) + aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16430938890724272256U;
            aOrbiterI = RotL64((aOrbiterI * 4540270493783593257U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11912000645055436094U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16800749242578741498U;
            aOrbiterF = RotL64((aOrbiterF * 17804584625034241737U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5909199180260499150U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5751089915336865588U;
            aOrbiterA = RotL64((aOrbiterA * 15376689503142397927U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3478216857728853008U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18007567146937338241U;
            aOrbiterD = RotL64((aOrbiterD * 6620498877303917855U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17454259424163653490U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6276120962018305311U;
            aOrbiterC = RotL64((aOrbiterC * 7560618224285018801U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3839336239901666431U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6230149015045237670U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1838983748994340883U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17552095486612766544U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2101601659597850213U;
            aOrbiterG = RotL64((aOrbiterG * 2915330118061857271U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 11U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 58U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 37U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterI, 3U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 14U) + aOrbiterF) + RotL64(aOrbiterE, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterK, 50U));
            aWandererI = aWandererI + ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererD = aWandererD + ((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC + (((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 53U)) + aOrbiterE) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordA);
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

void TwistExpander_VolleyBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB37E7267CA14FFC9ULL + 0x93B77E20E75941BDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xF61ECCEA1327ED17ULL + 0xAA032D1CBBC7DE1EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x85BB50D32A5E6A6FULL + 0xECF85472E4F9029BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEC4ED4593053B995ULL + 0x9CE5067EB7316141ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC47A8A7E8E34A32BULL + 0xC4F451453745806AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xF7116E24BFB9EAA1ULL + 0xEBB9F7A759EF8368ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9A59336FC3D48CCDULL + 0xF7A9A8E699606A54ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x96CB1552B5CFD029ULL + 0x8780A041A064C321ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x91C613C08AC8273BULL + 0xD4B344A08A2D6682ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBAD0CE941F7D25D7ULL + 0xB163A755C4372F1DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB3F9E69987C6BE2DULL + 0xD6D61685B4A41740ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x83369A8B2B343B8BULL + 0xD00ECCA8FB08774FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDCB009CD2AF62967ULL + 0xB8F1E95CAE594698ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDFFDD8041235C42FULL + 0x9A8CC849ECAB1F8BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xDB0D067506CA3F3DULL + 0x8CF6AD7C3A50FB99ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA79A70A2B69554CDULL + 0x91BC8F2899671FA1ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2501U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 328U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2452U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7231U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 3U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 43U)) + 3684295017013759987U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 19U)) + 6740408842457292881U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 34U)) + 4563975890702399441U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 39U)) + 797804144825287940U) + aNonceWordA;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 27U)) + 2763779540450101303U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 13211846164102089685U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 47U)) + 15214578447281401982U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 13745208628754232427U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 4U)) + RotL64(aCarry, 57U)) + 17358621225969190747U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 779739369960480023U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4370963533701407813U;
            aOrbiterJ = RotL64((aOrbiterJ * 3123135216876641039U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6061333005507739975U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3589705340762734456U;
            aOrbiterE = RotL64((aOrbiterE * 16499293983611196967U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10607697666369230567U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9356757995305239271U;
            aOrbiterI = RotL64((aOrbiterI * 10945513661439954731U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10093033335903048138U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11037328061699834100U;
            aOrbiterC = RotL64((aOrbiterC * 11189760551792389605U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 558431161176115540U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 17795680919453449358U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 3910117359996283803U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 6096779391116214109U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17594243286880690775U;
            aOrbiterF = RotL64((aOrbiterF * 12655610181937429915U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15414704802398002423U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18040588240488602196U;
            aOrbiterG = RotL64((aOrbiterG * 16344249573086571225U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 14636298592697156931U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 9677305688594936561U;
            aOrbiterH = RotL64((aOrbiterH * 8354776999961642997U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16408025751875050713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 10018342878801454965U;
            aOrbiterA = RotL64((aOrbiterA * 10349132962708124117U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 40U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterC, 52U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + aNonceWordJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterE, 3U)) + aOrbiterI) + aNonceWordH);
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterI, 13U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterG, 56U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13585U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8955U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10432U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12853U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 26U) + RotL64(aIngress, 57U)) ^ (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 51U)) + 18087125778766689269U) + aOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aPrevious, 3U)) + 13710545066503235196U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 1701939704736254645U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 26U)) + 8064093611384019909U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 57U)) + 16623332751533885431U) + aNonceWordM;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 35U)) + 15590129153794910109U;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 7413312683079107383U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aScatter, 30U)) + RotL64(aCarry, 5U)) + 4186064478651458810U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 39U)) + 5501191643940735954U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11064645242200570835U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 13825922087298055833U;
            aOrbiterF = RotL64((aOrbiterF * 7529317892716108867U), 43U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 5944980709887369970U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8181136916070569646U;
            aOrbiterG = RotL64((aOrbiterG * 395183021205661827U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15442336949157292482U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 11580554435240641337U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6654637892858767739U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 11240018128174598322U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2027565596050777471U;
            aOrbiterK = RotL64((aOrbiterK * 18048186560314431815U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16425887196883725233U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16828683527588834095U;
            aOrbiterE = RotL64((aOrbiterE * 17746289103235902485U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9923829146479008804U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6669171007279929454U;
            aOrbiterB = RotL64((aOrbiterB * 681823450939955099U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3902430046523165149U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6739998149289590041U;
            aOrbiterA = RotL64((aOrbiterA * 2675037435528416821U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16014401255534234075U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 14741857638680634564U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 8723611021403369393U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5064807861673260054U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 968747317273200299U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14122304002722582329U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 11U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 6U));
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 4U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterA, 39U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aNonceWordC) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterC, 58U));
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterG, 53U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18665U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17492U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23797U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18599U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 26U) ^ RotL64(aCross, 41U)) + (RotL64(aPrevious, 11U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 37U)) + 439898681482066326U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 51U)) + 17362083676671776094U;
            aOrbiterF = (aWandererE + RotL64(aCross, 5U)) + 6418499837265155024U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 17262244253027454972U;
            aOrbiterC = (((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 2382066162993139503U) + aOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 13U)) + 14345808395587174135U;
            aOrbiterB = (aWandererB + RotL64(aCross, 47U)) + 7534743166385552851U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 29U)) + 16994453324688523966U) + aNonceWordM;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 20U)) + 7079553728544045092U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3562822704508440641U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13990892681975857821U;
            aOrbiterF = RotL64((aOrbiterF * 8352929306654078795U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1796728922368577238U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 6605161260520067178U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8147537646591674091U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 13994083795942328918U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6144523182899107711U;
            aOrbiterA = RotL64((aOrbiterA * 4153879991344611283U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12247462325297436642U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1065809332002012789U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 5496601177032953251U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10147919864511540753U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17138553441127273354U;
            aOrbiterC = RotL64((aOrbiterC * 5773875596275267871U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2653924016109573974U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6254416952351699582U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12756861659704947257U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 813046408080197079U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 9624466135414123483U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6960320253124395015U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 972586705850825744U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 155283774901960223U;
            aOrbiterD = RotL64((aOrbiterD * 9928051687724257041U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 18200100644751360406U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1168426822045686004U;
            aOrbiterG = RotL64((aOrbiterG * 5867027156069481313U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 10U);
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterK, 52U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 39U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterF, 47U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 34U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 28U) + RotL64(aOrbiterB, 13U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28076U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26430U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25107U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31317U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 3U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 22U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 13880995121909552664U) + aNonceWordE;
            aOrbiterD = (aWandererA + RotL64(aCross, 35U)) + 14534942818069300546U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 12U)) + 17745973100886007133U;
            aOrbiterH = ((((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 2249805580771946872U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 4460116116396439410U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 51U)) + 3378683994078106878U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 43U)) + 3992996501048809123U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aScatter, 22U)) + 12057768808864451929U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 29U)) + 4115362079047921130U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15297384955502206698U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17623548383481905636U;
            aOrbiterJ = RotL64((aOrbiterJ * 7487278217901483685U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3559213898000162417U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12311605719074507335U;
            aOrbiterK = RotL64((aOrbiterK * 3982199462062847697U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14807313864347885885U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11222085523291581822U;
            aOrbiterF = RotL64((aOrbiterF * 12580941911587215653U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 916681229436292462U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2441350114032314686U;
            aOrbiterA = RotL64((aOrbiterA * 7336079498999018067U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7361470539894653271U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12153585147213579808U;
            aOrbiterH = RotL64((aOrbiterH * 3040327545467672961U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13566300726101613579U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14875254144748509128U;
            aOrbiterC = RotL64((aOrbiterC * 13699179902908972403U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 9268158535644002904U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14144295981814993491U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12739937231684038161U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13861225650900541642U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12620513474052058164U;
            aOrbiterB = RotL64((aOrbiterB * 18141974182442267181U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14163773386433257965U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5725700029399455855U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 10446930901088908809U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 14U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterB, 19U)) + aOrbiterA);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 10U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 47U) + aOrbiterB) + RotL64(aOrbiterD, 47U)) + aWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 3U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 11U)) + aNonceWordH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterF, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordM;
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

void TwistExpander_VolleyBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xBEDB660846C46F6DULL + 0xD80FA1F2F35B2C1CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB896E6A561C9D00FULL + 0xBC0AA3156D6CEA8AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9D3198DAF173C1BDULL + 0xD371B6CC4DF36299ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE3F0ACA6361739AFULL + 0xBEC0AAED1B9FC378ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFF7890B23FE1ADC5ULL + 0xFA715E187E34265AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBF20639E57537A19ULL + 0xBC7A5B69BA2DA2C2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xE25455530CF5F65BULL + 0xDD6133C31ECB9D1CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x99DCCD30669830E5ULL + 0xF88E8A1EB3AAC2E4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCA9BAB9BF9787F95ULL + 0xC8D88035282603BCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x84FC04263A806E9DULL + 0x9B97325F26F1E734ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA6B951328A412085ULL + 0xF9E5B9AB068F25C7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xB7543E811B54A73BULL + 0xD6A52B0FE3A06980ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA6523FD994CE8947ULL + 0xD2FDBAEFBFB0F620ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x81524CEE2C91CA41ULL + 0xB5F801B97A59ACF4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9564DEA66873C853ULL + 0x8D3D8FB75959648FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB0FD153DA60A1359ULL + 0x8D77936E2B433DB7ULL);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4916U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 880U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4631U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1915U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 14U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 14179205183062705133U) + aNonceWordA;
            aOrbiterK = ((aWandererH + RotL64(aCross, 21U)) + 210032324058740920U) + aOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 7387115089142500152U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 17583362781238061430U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 35U)) + 4991442849150005943U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 2891376254689854555U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10523274382407446239U;
            aOrbiterH = RotL64((aOrbiterH * 17443994099359920915U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3861893764676218667U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3366674459852093746U;
            aOrbiterC = RotL64((aOrbiterC * 14005994095369483813U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5898492634386601145U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7047353571244768721U;
            aOrbiterD = RotL64((aOrbiterD * 2257518291062508467U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14374108805453186316U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8763667021501226510U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7694695426430267863U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterD) + 18261523829316379575U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 650477532238860965U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 8291758490821819851U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterH, 14U));
            aWandererK = aWandererK + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterA, 35U)) + aNonceWordK);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 54U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13038U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9723U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9808U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12814U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 5U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((((aWandererC + RotL64(aCross, 46U)) + RotL64(aCarry, 51U)) + 14249093584376402677U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 8756965951816492264U) + aNonceWordM;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 11221139480258176330U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 29U)) + 17218894445564194851U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 3U)) + 8064642692524949490U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5822093203710704646U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3217799620158102238U;
            aOrbiterF = RotL64((aOrbiterF * 2806328682494910635U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2613757677892120843U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 13647481499551657237U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5517563514031899891U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 3545714196663685016U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9735422670576621521U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7276207208162697249U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3911046580637583767U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9315984027042049203U;
            aOrbiterJ = RotL64((aOrbiterJ * 12568550776487242469U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8926367674641729058U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11035347490524961446U;
            aOrbiterG = RotL64((aOrbiterG * 10948288997163592463U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + aNonceWordK) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 38U) + aOrbiterF) + RotL64(aOrbiterA, 26U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterA, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 39U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererI, 51U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17823U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 21420U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23406U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 22158U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 48U)) + 8402620908307642697U) + aNonceWordM;
            aOrbiterB = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 11347672014525086047U;
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 2816462912503401876U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = ((((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 6940159795470696093U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 5U)) + 9134692490095883851U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4999455497008026526U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5992451460350651332U;
            aOrbiterE = RotL64((aOrbiterE * 12796550245322491401U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 3417087346651371924U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3612773820086198270U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 5519856345435871169U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 463398077083428570U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11249391303705089012U;
            aOrbiterI = RotL64((aOrbiterI * 7106735772303292983U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 17027535139825739501U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 568131384979596481U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 5683451044852895957U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4793712537158004047U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 10415170179135963622U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13729564030210361415U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((((RotL64(aCross, 23U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 47U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 52U) + aOrbiterB) + RotL64(aOrbiterE, 28U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aNonceWordO);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30778U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31465U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27388U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 25832U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 3U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 5576732410244514238U) + aNonceWordO;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 26U)) + RotL64(aCarry, 39U)) + 2833808925935929629U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 3670188682914544792U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aScatter, 11U)) + 15759072378887814995U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 51U)) + 13934007231137439994U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11022225696007690512U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 16989177104453635790U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 14156758251105809453U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 9256930045263527091U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17788596104417068290U;
            aOrbiterC = RotL64((aOrbiterC * 675554110563253305U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17044369456673337625U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterB) ^ 1310908395523250343U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 16305084373037705921U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12067065689034065422U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 15130844248737512262U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9409499577465934107U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 14532689204495587494U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 8198147292120244178U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 1418356389507740991U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 12U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 29U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterB, 57U)) + aNonceWordB);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_VolleyBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8A1359722139EF41ULL + 0xDF3F824536332F96ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC59D427009ED4C2FULL + 0x8D33F4102920635AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA720625DE09C884FULL + 0xCA5C826C3859E90AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA440099E3A67D669ULL + 0xDD4480A08853B943ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9AD28BF22CA84D73ULL + 0xEAEC42D27931140AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9BFE799902D2EEC5ULL + 0xC20A23EC48779567ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCB667BA3174F05FDULL + 0xDCD8448C1465A53FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF10FAA2C13798CAFULL + 0xFF00A38D14AA5E98ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x84E735A902B566D3ULL + 0xAA50EC6A8B975C34ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF456489E15C30141ULL + 0xE80AD4321E85DE8AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xADEEEA1EB62A793FULL + 0xA021719186AC96C5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xA21D1B0D83A8AB33ULL + 0x9C0E088E7CA8570DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAE28FF1EADA74FD7ULL + 0xB7EB7D620C0833D3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCE76576D0F7EF87DULL + 0xED7036B7D3689B2AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x9F06590019B4C75FULL + 0xA99FE45A91FD0EBCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD519B607F5E621BBULL + 0xF347E63A25B3B823ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5639U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneC[((aIndex + 6211U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8025U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 34U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 22U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aPrevious, 41U)) + 8604208734152026945U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 1374329953253889829U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 5779278910548228339U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 17670451230882805140U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 3U)) + 8193848740764866860U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aScatter, 60U)) + 15801168428145650104U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 35U)) + 2584718176087499066U) + aNonceWordL;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 14950366247822737997U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9779293225265670135U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 11625969538497982117U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8688968319288372383U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 13665723186950342601U;
            aOrbiterH = RotL64((aOrbiterH * 292035540396910837U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9395428688359973510U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2152719218018108418U;
            aOrbiterA = RotL64((aOrbiterA * 15271961483518392671U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1350324137411377992U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8729317951386057921U;
            aOrbiterE = RotL64((aOrbiterE * 6008790836417785083U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 6317310451893678411U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10175620379041384281U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14079679617394330781U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1203082119358827708U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 523869107818193101U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4629501113595689157U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4028324959540432983U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15447631947468213912U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6037306615787729185U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterB, 6U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 4U) + RotL64(aOrbiterE, 11U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterI) + aNonceWordH);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 18U)) + aOrbiterH) + aNonceWordK) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterB, 39U));
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 36U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15957U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12541U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10530U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 13472U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 6024062041314952357U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 13U)) + 18340757093658015585U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 23U)) + 11911120493880346751U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 41U)) + 17428074353884654439U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 53U)) + 12790849760814795936U) + aNonceWordF;
            aOrbiterJ = (aWandererB + RotL64(aScatter, 51U)) + 12633397052172117800U;
            aOrbiterI = (((aWandererJ + RotL64(aCross, 60U)) + 11946150433665237945U) + aOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 16842157900909419285U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14186235783224155962U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 10521157787073684417U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13284904542579767591U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11609181965078844357U;
            aOrbiterG = RotL64((aOrbiterG * 5455780554452453513U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9628562297095374984U) + aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 7850281529011259759U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17611485102925470357U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 257458718073794527U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 10693404545773519306U;
            aOrbiterF = RotL64((aOrbiterF * 14821443722828498323U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 3430519236533871460U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 6183054506953198055U) ^ aOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6121082743789970911U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 2905610989884221654U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4472163910775333862U;
            aOrbiterJ = RotL64((aOrbiterJ * 7770678426310856745U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 16870142883133769663U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1403692060594816451U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 9740854430251597879U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 50U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 20U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 53U)) + aWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21201U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 22945U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16984U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 24230U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 37U)) + 1952750591494698524U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 27U)) + 4488270851303332830U) + aNonceWordP;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 2738763375328927635U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 6728843649480454340U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 43U)) + 10490717875258865358U) + aNonceWordO;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 3U)) + 1429288737812910205U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 50U)) + 2761375016998907636U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1088988605204499835U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6829840407300289709U;
            aOrbiterK = RotL64((aOrbiterK * 13101432880030791787U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9267240337867690471U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8120113021183975703U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14296504593187173107U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1340980511302566784U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11874452169979878835U;
            aOrbiterA = RotL64((aOrbiterA * 8638486178860092537U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1872314794140971426U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6013952618696225751U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7994863587373565715U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3644011378086236002U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8501867691997891731U) ^ aNonceWordB;
            aOrbiterE = RotL64((aOrbiterE * 7115282675461711509U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2493546555198066143U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5179240189571799179U;
            aOrbiterH = RotL64((aOrbiterH * 1267579130962756135U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 11273348247858394197U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4577476419423118925U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8427261005061162673U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 53U)) + aNonceWordN);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 13U)) + aWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 40U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 21U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 60U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 56U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26350U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27105U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29356U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26875U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 10U)) + (RotL64(aCross, 39U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aCross, 23U)) + 8101351470141807662U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 3U)) + 6965474099521076705U) + aNonceWordB;
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 6803828268885684784U) + aNonceWordM;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 13454235922950972488U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 11U)) + 11678091885751244777U;
            aOrbiterG = (((aWandererH + RotL64(aCross, 54U)) + RotL64(aCarry, 41U)) + 5307134544628507141U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 35U)) + 4873703518950429353U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8542156221858586039U) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3993726182905296513U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 11331376012938127609U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12113047622035464386U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1944244448665721151U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7010050836758762003U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12914188029425467576U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2486762763475327024U;
            aOrbiterK = RotL64((aOrbiterK * 12319769994433811617U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 14580191602982245481U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12093414832400135066U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12720286833215690663U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13623906997320021065U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9977356009806428696U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2005536391712733499U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3694954095397810851U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11453812627797091638U;
            aOrbiterA = RotL64((aOrbiterA * 13730420725113907161U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 542311345544726351U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3024285045990499484U;
            aOrbiterJ = RotL64((aOrbiterJ * 5153745952148205645U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 5U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 34U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 23U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 20U) + aOrbiterK) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterE, 57U)) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordC;
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

void TwistExpander_VolleyBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF5E3BF27F8583C6DULL + 0xF74E1D92819EEF3EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB877FC0E63FA959BULL + 0xBFBFF2A8EFE95FC4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9E4CD5FA7FD2CD89ULL + 0xE613B48B28A49639ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA8A61DA72A5B8FD1ULL + 0xF8AA5C9815474742ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB83D41B96B53825DULL + 0xA0906E483F949D6DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF9545887CF2B016BULL + 0xA9831634CF3041EBULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDB16B2A4D1081E2BULL + 0xD6726431DE6330C8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9F663D69B332E023ULL + 0x82C4E5D0B8472F69ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF3BADCFD22F6AA09ULL + 0xBF6F9E60E106CC17ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x81A7DA33E4C613BBULL + 0xFC087A4848D8FA09ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x961E4C16044EF6B1ULL + 0xD3A0E46A4FF103F5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE9F3F591A1D4E367ULL + 0xE0E92A0C3039E0DCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD5B55512113A7519ULL + 0xEBA43C239414C65BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA02EC8A2353F38D7ULL + 0xEED3083073050B78ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xD245C2B62C864B8DULL + 0xB2C27C79650917AEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xDF69772798667E9FULL + 0x9E48CE928828AB19ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7134U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 5209U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2896U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 1481U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 19U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 52U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 29U)) + 15910560457440369082U;
            aOrbiterI = (((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 17953072986407436888U) + aNonceWordA;
            aOrbiterE = ((((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 15446940721193538669U) + aOrbiterAssignSaltD[((aIndex + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererE + RotL64(aIngress, 5U)) + 3020785262774422009U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 27U)) + 7001288645424994404U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 12U)) + 13385250665458462689U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 47U)) + 4841895644623005949U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 13053476783239482065U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 641996979335975244U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3697673197256549833U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16211238020928688299U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12715448751323279480U;
            aOrbiterD = RotL64((aOrbiterD * 2116880429675303291U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17784406727699995290U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 16626339815786580778U;
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9035070625716345139U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6085848172494001945U;
            aOrbiterF = RotL64((aOrbiterF * 10405728912339646693U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1177103851507561053U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2281901691017816407U;
            aOrbiterJ = RotL64((aOrbiterJ * 3142197009403602497U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9040984343694325070U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 13334258224023902365U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 4782523727707164869U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1079824790138592518U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14024082692012948652U;
            aOrbiterI = RotL64((aOrbiterI * 3219489374333737903U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterK) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 38U)) + aOrbiterE);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 56U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterA, 47U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterE) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11893U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 13911U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15638U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 11065U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 34U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aCross, 3U)) + 6654158889644956636U;
            aOrbiterH = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 9045779659363991870U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 20U)) + RotL64(aCarry, 53U)) + 3888897662136993491U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 6882016842864459345U) + aNonceWordE;
            aOrbiterE = (aWandererE + RotL64(aScatter, 29U)) + 15601891715956172291U;
            aOrbiterG = (aWandererD + RotL64(aCross, 53U)) + 5176811598629335350U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 43U)) + 12519945150889074325U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4552583214397603278U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 14225482701804864688U;
            aOrbiterA = RotL64((aOrbiterA * 8526052833180466359U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 5485298070606280363U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11237713257388094289U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 11032429223099413011U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14340345895626142788U) + aOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16275167270553643347U;
            aOrbiterD = RotL64((aOrbiterD * 7308578867128951199U), 53U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 14041860597556520250U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1436068974197066343U;
            aOrbiterH = RotL64((aOrbiterH * 3938460345031496843U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11483155566419547004U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 4608508534724289325U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 13461385011638899485U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2389196334288832895U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4062682330273866602U;
            aOrbiterG = RotL64((aOrbiterG * 8787682133271101901U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5655656046585592034U) + aOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7977947821249746880U;
            aOrbiterB = RotL64((aOrbiterB * 10082104644185964787U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterA, 19U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterI, 43U)) + aOrbiterH);
            aWandererK = aWandererK + (((((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 5U)) + aNonceWordO) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterG, 58U)) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23883U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 22132U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21319U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneC[((aIndex + 21979U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 24U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 19U)) + 8375305456876489425U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 13U)) + 16193562952772453047U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 54U)) + 18088652458594816223U) + aNonceWordP;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 767344788620249944U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 7705194930396368752U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 47U)) + 3829736891311272834U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 3U)) + 9881681671347640061U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1721196560190164264U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3002652618388454213U;
            aOrbiterE = RotL64((aOrbiterE * 15289749311593032657U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 9811621464004005202U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 5652598941069986530U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4797973356708091621U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 6250499348327316328U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 16025054277615264530U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 16446892258704281903U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13800298546867243172U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12256104592865905782U;
            aOrbiterJ = RotL64((aOrbiterJ * 16983140179497142713U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17817225416918329229U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17738671327352776217U;
            aOrbiterG = RotL64((aOrbiterG * 393488251327705063U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6816031224188400541U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16989563985059237014U;
            aOrbiterB = RotL64((aOrbiterB * 8677884225771717797U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 16891524847268207549U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 1833508573940405571U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 9709196587703979539U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 38U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererH = aWandererH + (((((RotL64(aPrevious, 58U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 35U)) + aNonceWordE) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 56U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterB, 5U));
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterC, 21U)) + aNonceWordD) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 20U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29446U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29420U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28068U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27965U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 40U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 43U)) + 18144572925667544139U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 5659758077574059728U) + aNonceWordJ;
            aOrbiterC = (aWandererG + RotL64(aIngress, 11U)) + 6343330616999166392U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 37U)) + 17754639838410839447U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aCross, 3U)) + 9451843819849581729U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 53U)) + 7957854457197462212U) + aNonceWordI;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 30U)) + RotL64(aCarry, 57U)) + 1461994799722205010U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 18002214276252170177U) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14689869073147027164U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12242482963989582191U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3978104368003440293U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8512135845221335386U;
            aOrbiterA = RotL64((aOrbiterA * 10506667163729414667U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1477533446382953439U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2166717790929947990U;
            aOrbiterE = RotL64((aOrbiterE * 6538884492418324461U), 27U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 8082437060686606995U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 4363687722464700362U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7199165810993478887U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15782763348014924206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8572509150015960728U;
            aOrbiterD = RotL64((aOrbiterD * 3340528604891897779U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12248271773316742521U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 9602078627638561949U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1860631869877427405U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17244849374768558859U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1030743048280579012U;
            aOrbiterI = RotL64((aOrbiterI * 10858949914285817051U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 43U)) + aOrbiterK) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterE, 18U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 20U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 29U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordP);
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

void TwistExpander_VolleyBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8545DDAE143C5395ULL + 0x880EAEFD71995DDAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB18F1CF366F1F02FULL + 0xADD0BBB52F0DF954ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xFECF9081E9972109ULL + 0xD4318B776865F8FEULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x964664B3F1A165DDULL + 0xE42BB7FCB3F02B4EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xBE74D962D5DBE48BULL + 0x90AA9F263F8B2ADBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD928AA8BE3B05809ULL + 0xE2DA7DD0BFC487C6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC7A32CABC446FC83ULL + 0xFCD3AF5BB5D67CB2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE021749D64C570A5ULL + 0xDBFA747969660604ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x920F155FC830C55DULL + 0xD26887585B2E808DULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x912506427254F5A3ULL + 0xBB9502D0681061C2ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC564BF30157EB191ULL + 0xF0728AC58734CC27ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE74DFF66FBC4C439ULL + 0xB79783C258BB4878ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAD20EC6B60378F49ULL + 0xC0CACD9169F5FA82ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x943BFF03ED709B01ULL + 0xE8E24B60CEE30DBAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD5EAB98343726989ULL + 0xFA9151F27149EB88ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xF00FB558B5091323ULL + 0x88BD3A6D04805BC9ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2629U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((aIndex + 401U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1450U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3336U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aScatter, 54U)) + 13650869943246163567U) + aNonceWordA;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 3435284932011770999U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 29U)) + 12388155658186776579U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 39U)) + 2374345913955712039U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 11U)) + 6095094526980292156U) + aNonceWordG;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 22U)) + 4965147025852444174U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aScatter, 57U)) + 3261881216269075298U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 4939780217097329222U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 3019862009792676287U;
            aOrbiterA = (aWandererA + RotL64(aCross, 3U)) + 901910626217143974U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 47U)) + 3647055146712366383U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7731765438957392967U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13409819457393479741U;
            aOrbiterK = RotL64((aOrbiterK * 3345078200262410715U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5415832109107794258U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 8876738832313114471U;
            aOrbiterC = RotL64((aOrbiterC * 1304277600444504135U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17135570542519390359U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2373193062766802082U;
            aOrbiterF = RotL64((aOrbiterF * 4213691513185791519U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16318403285501718552U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 8456043288604687045U;
            aOrbiterB = RotL64((aOrbiterB * 10556964529144571683U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 10572534930284516528U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14616251186735204677U;
            aOrbiterJ = RotL64((aOrbiterJ * 2048651204265459805U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2837006243817205610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 5315917323622194254U;
            aOrbiterE = RotL64((aOrbiterE * 4080522050089666599U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 12084676282761185907U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7922080344175593788U;
            aOrbiterD = RotL64((aOrbiterD * 7603522302708937379U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17620847289789547792U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12140386059533463650U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1443266480620969535U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4006608081473218762U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3152507055132739011U;
            aOrbiterG = RotL64((aOrbiterG * 11929522909695002321U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 10845720206369283181U) + aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16572752872386133133U;
            aOrbiterI = RotL64((aOrbiterI * 2891952650448087211U), 53U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterD) + 15544908026178481075U) + aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13650869943246163567U;
            aOrbiterA = RotL64((aOrbiterA * 1275090431127426217U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 39U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aWandererUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 39U)) + aOrbiterC) + aNonceWordO);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 56U) + RotL64(aOrbiterF, 3U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 54U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 11U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + aNonceWordH);
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + aNonceWordB);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 23U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 30U)) + aOrbiterI) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14514U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10785U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15164U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 10174U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 56U) ^ RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 29U)) + 16189787374324972735U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 21U)) + 17563763730956242224U) + aNonceWordJ;
            aOrbiterD = ((aWandererB + RotL64(aCross, 14U)) + RotL64(aCarry, 47U)) + 10572803498593789385U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 39U)) + 7713105232072974166U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 51U)) + 10760839534772718139U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 3U)) + 13397069448391230253U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 4569255679998375682U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 37U)) + 9888769350817876949U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 34U)) + 11351796060878856300U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 41U)) + 18153775071965707204U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 19U)) + 1282846411145853435U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16457743979262460660U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 173493260775251032U;
            aOrbiterD = RotL64((aOrbiterD * 4935807229040883505U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3927345926316409630U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5158769729850853623U;
            aOrbiterK = RotL64((aOrbiterK * 2446452358663812945U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12331351600010165154U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 3940794200348684050U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 13248997263062075043U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11248514843822945425U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1391497323278226522U;
            aOrbiterF = RotL64((aOrbiterF * 8376841806072565005U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13265623528678787307U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2802033745265647317U;
            aOrbiterJ = RotL64((aOrbiterJ * 3437626962562016147U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6938444301018051844U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1086544666755559028U;
            aOrbiterC = RotL64((aOrbiterC * 16039728388882079889U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 16156443117365816536U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 3619942859562697142U;
            aOrbiterI = RotL64((aOrbiterI * 7589346043159112151U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17681848914912743292U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8848238631758130416U;
            aOrbiterB = RotL64((aOrbiterB * 810402256099500607U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6019192027793541890U) + aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16917288363166352778U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17673667086593738207U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5598218150530046752U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17285995539011279010U) ^ aOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15621233176885995065U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12380627610747299268U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16189787374324972735U;
            aOrbiterA = RotL64((aOrbiterA * 2144714828503219209U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 22U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterH, 43U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterJ, 29U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterK, 48U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterB, 11U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 40U)) + aOrbiterG) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 46U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24526U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23233U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24112U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18240U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 48U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aIngress, 23U)) + 14686411261024919129U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 27U)) + 7514582233957632005U) + aNonceWordD;
            aOrbiterJ = (aWandererH + RotL64(aCross, 37U)) + 6520710480103365552U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 35U)) + 1983621978676188036U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 54U)) + 9003524602590749672U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 6428568234045228995U) + aNonceWordE;
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 29U)) + 8656552687136446989U) + aOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 57U)) + 16916248288415922490U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 19U)) + 9740237548002535784U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 48U)) + 907561000814618339U;
            aOrbiterD = (aWandererK + RotL64(aCross, 43U)) + 4751108900841197631U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 167774899400732287U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11907484918310854962U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 7213139491146402985U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14910318613649863924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14882888155751455276U;
            aOrbiterB = RotL64((aOrbiterB * 11394136445442060201U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16175942562693781908U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11022373758481651102U;
            aOrbiterH = RotL64((aOrbiterH * 6836331461393816027U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 12548405399045031548U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 10850926364556828443U;
            aOrbiterF = RotL64((aOrbiterF * 16231561687709867431U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 13391684887911141790U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 14648937281264822988U;
            aOrbiterK = RotL64((aOrbiterK * 6533299316940026059U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8298658887198526821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13822977698661348891U;
            aOrbiterC = RotL64((aOrbiterC * 17769262972278410937U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7505646847564645719U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3238749538197209166U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15394286542600778567U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15853506915123709257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8426329899401071248U;
            aOrbiterI = RotL64((aOrbiterI * 1330397096577715113U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 14848635392815613098U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3549927798350175044U;
            aOrbiterA = RotL64((aOrbiterA * 1899044682313056949U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1798973117197750802U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13056711228618953977U;
            aOrbiterG = RotL64((aOrbiterG * 9102877396419306689U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 1395893547965799281U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 14686411261024919129U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17075377081365066067U), 53U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aCross, 24U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 52U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 57U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 23U)) + aOrbiterB) + aWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aNonceWordF);
            aWandererH = aWandererH + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordI);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 18U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterF, 37U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 40U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordO;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29016U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneB[((aIndex + 31972U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28963U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25553U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 47U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 4970414922752555648U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 24U)) + 9462756592787669327U) + aNonceWordP;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 3948790686662213095U) + aNonceWordA;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 37U)) + 14542857212241578311U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererE + RotL64(aScatter, 51U)) + 3387479009827029547U;
            aOrbiterE = (aWandererB + RotL64(aCross, 41U)) + 1411421370057797877U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 16894451466895681236U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 35U)) + 12727136462290223542U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 11U)) + 4625389198191960525U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 53U)) + 3471881403786164913U;
            aOrbiterI = ((aWandererK + RotL64(aCross, 60U)) + 6433115856048534831U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 9825592965466157982U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1553125767261293088U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 411535191177308781U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 9951616357109647617U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 11231080382787286889U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 14024961994986659187U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13419663264017317947U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 4835055642466215566U;
            aOrbiterE = RotL64((aOrbiterE * 17898065852351759171U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14558747666410946768U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13120938960926874504U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5681766019285559739U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 11910501376797343986U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 15074100100781785300U) ^ aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 228976960937473851U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12415377930578091821U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14882039078390681802U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13855446647753150713U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8094338361713756895U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5478280604704108822U;
            aOrbiterG = RotL64((aOrbiterG * 18062931724700600993U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6977017654546871841U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 4131602217285988962U;
            aOrbiterI = RotL64((aOrbiterI * 11865422227883712419U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 9619228479582032318U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13506679497441415586U;
            aOrbiterH = RotL64((aOrbiterH * 5789932662418992799U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10180259475831448124U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4721628773773094283U;
            aOrbiterF = RotL64((aOrbiterF * 10834196399754443771U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7898137727558813688U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4970414922752555648U;
            aOrbiterA = RotL64((aOrbiterA * 6651835668618579479U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 4U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterH, 4U)) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterG, 60U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 11U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 5U) + aOrbiterD) + RotL64(aOrbiterC, 39U)) + RotL64(aCarry, 19U)) + aNonceWordF);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 54U) + aOrbiterE) + RotL64(aOrbiterI, 53U));
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 46U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordK);
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

void TwistExpander_VolleyBall_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint8_t *aOperationLaneA = pWorkSpace->mOperationLaneA;
    [[maybe_unused]] std::uint8_t *aOperationLaneB = pWorkSpace->mOperationLaneB;
    [[maybe_unused]] std::uint8_t *aOperationLaneC = pWorkSpace->mOperationLaneC;
    [[maybe_unused]] std::uint8_t *aOperationLaneD = pWorkSpace->mOperationLaneD;
    std::uint64_t aCross = 0; std::uint64_t aScatter = 0;

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0;
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE6DD2373663B3871ULL + 0x82B2BB21442472BBULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8D1F0B87037DFBDBULL + 0xE646CF4CF5CA6504ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEA43767720D07495ULL + 0xFC2422F66A5CDDCCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xCC50C37BADC4E331ULL + 0xD804C5B072E665A3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x83860A079014BFD3ULL + 0xD47BB6D4E63793DAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC49867E0705A23B1ULL + 0xE613FA5C9F67DE17ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xFB915283E1943DC3ULL + 0xAD377A8662E9F4ADULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x976E2DFE5E0FA549ULL + 0x8B15719FFE95E112ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xAE0804F3A7E7218BULL + 0xBDE22975D30C042AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA6BC0AFD2C045A4DULL + 0x8A2D0FF82B3956F5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xE7C6ED81E88F40BFULL + 0xC80B8817F4413549ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDD82E411F46452F7ULL + 0x85BB63735269F3FAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9FB9D697717231FBULL + 0x948C0594CD012B1AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x9180CC9FAD2D15FBULL + 0xDD7199A57D76D896ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC0C9BAA7DB5DB2A1ULL + 0xD301DFAD3CC8379DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD1F197571B973D59ULL + 0x89358BE7A2D68576ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4138U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 4560U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5310U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 3394U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 6U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 16802219662864902427U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 6U)) + 14332033461409490629U) + aNonceWordO;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 43U)) + 8781794298640286845U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererG + RotL64(aCross, 57U)) + 8459933908074937264U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 1883580287986004426U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 17500258188004626118U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 53U)) + 7934811305150872870U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 34U)) + 6380363892361098905U) + aNonceWordC;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 19U)) + 12623079132626676910U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10455208121949202703U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8805532707916767629U;
            aOrbiterD = RotL64((aOrbiterD * 666082374369701881U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 9161544391400377699U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3501434325829663268U;
            aOrbiterJ = RotL64((aOrbiterJ * 7933545151293799637U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 651783304096081996U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 441505031509930622U;
            aOrbiterE = RotL64((aOrbiterE * 8045355432310956143U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1771159983581326424U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15227946417377695989U;
            aOrbiterF = RotL64((aOrbiterF * 1563141188972797601U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4153717524193279095U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 4404521756523902829U;
            aOrbiterI = RotL64((aOrbiterI * 1410342912973206203U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 6231945075461813285U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3864780227164426690U;
            aOrbiterA = RotL64((aOrbiterA * 18031353247480673617U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1509699687948576558U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 17316114302489411191U;
            aOrbiterK = RotL64((aOrbiterK * 15490661284980281585U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2250572827340157410U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6403966113144372915U;
            aOrbiterG = RotL64((aOrbiterG * 726441947009132383U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2329903609147403156U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2486330017319455238U;
            aOrbiterC = RotL64((aOrbiterC * 17427461345935191757U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 56U)) + aOrbiterK) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 53U)) + aNonceWordM);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 41U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 26U) + aOrbiterI) + RotL64(aOrbiterC, 46U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8125U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6671U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8178U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6155U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 52U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererF + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 13278949403988203974U) + aNonceWordL;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 23U)) + 9213599924054673756U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 47U)) + 1255746482932381798U) + aOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aScatter, 58U)) + 11575321997144516122U;
            aOrbiterE = (aWandererE + RotL64(aPrevious, 37U)) + 15881587525529432437U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 9846195809864862707U;
            aOrbiterG = (aWandererH + RotL64(aCross, 41U)) + 12319815691858217670U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 10U)) + RotL64(aCarry, 11U)) + 16322617427294439587U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aCross, 53U)) + 16332130810525887437U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 4920951156015336794U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16767126455124552329U;
            aOrbiterC = RotL64((aOrbiterC * 4440352337076842603U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12553595911087945223U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1437522202135436142U;
            aOrbiterE = RotL64((aOrbiterE * 2001992794165550905U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12313100454852227143U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2761983020631055729U;
            aOrbiterG = RotL64((aOrbiterG * 3874839760378039509U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17635303588421554367U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 788212489507463763U;
            aOrbiterA = RotL64((aOrbiterA * 17896475584538528059U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5192552894670654434U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6784748488807738811U) ^ aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8077237651953896479U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16113417046719114943U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1096874945215225916U;
            aOrbiterJ = RotL64((aOrbiterJ * 17308604412622879833U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7610274704570171595U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10466070212284342550U;
            aOrbiterK = RotL64((aOrbiterK * 6449728258497920613U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 6777845928873855221U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterA) ^ 5251515022021984126U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 9018277343404261611U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13849343158824111498U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7977711210181714021U;
            aOrbiterH = RotL64((aOrbiterH * 4182053966171053577U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (RotL64(aOrbiterG, 42U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterK, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aIngress, 18U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 27U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterC, 14U));
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterF, 23U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 26U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13047U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11155U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13742U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 11462U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 27U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 47U)) + 6733949564325516029U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 5U)) + 7304098437143918796U) + aNonceWordJ;
            aOrbiterF = ((aWandererE + RotL64(aIngress, 54U)) + 3923949518391777800U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aPrevious, 29U)) + 14243591003388927124U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 19U)) + 18329498724605410406U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 13118172167747037249U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 5272025143849174212U) + aNonceWordF;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 16075917179214318424U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 24U)) + 15263590648674658399U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13730046728289525921U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7703141464499623408U;
            aOrbiterF = RotL64((aOrbiterF * 5886009900621521987U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1382279753822135359U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2973369221699098292U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 7440242040663550631U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11578274119583013219U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3419411247737896674U;
            aOrbiterA = RotL64((aOrbiterA * 17814942652262802991U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2582783513078999303U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3959762790273529677U;
            aOrbiterJ = RotL64((aOrbiterJ * 383974377372162751U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 465795011576934604U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17880826624185821135U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4445949147592860913U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10819659185349413173U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17298208553586835030U;
            aOrbiterK = RotL64((aOrbiterK * 1965860510614222093U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12585880006661489402U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16650193903267408586U;
            aOrbiterE = RotL64((aOrbiterE * 5781132589396936615U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 885882046325991589U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 869560078374809974U;
            aOrbiterC = RotL64((aOrbiterC * 13440973563438747181U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 11871305571797951851U) + aOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 12137095015607196226U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 7618152256560808581U), 57U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 24U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterA) + RotL64(aOrbiterF, 18U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterA, 23U)) + aNonceWordK) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 39U)) + aOrbiterE) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 44U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterK, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 14U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16584U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 20406U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21816U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 20836U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 13U)) + (RotL64(aIngress, 43U) + RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aIngress, 56U)) + 2168513956284366370U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aScatter, 29U)) + 10290361969974613111U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 15673836275828498050U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 39U)) + 16600540024145812236U) + aNonceWordJ;
            aOrbiterA = (aWandererC + RotL64(aScatter, 3U)) + 9428052101528111892U;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 29U)) + 12763657928312763377U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 10751286982008662485U) + aOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 13U)) + 1708230173038057979U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 48U)) + 4011389705422783816U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11704428328093077714U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 2055336619674699284U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6374289210096410907U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1870865272102705804U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3574214263751923179U;
            aOrbiterA = RotL64((aOrbiterA * 13132083406834413563U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 984611970726966186U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 15207945449947643672U;
            aOrbiterE = RotL64((aOrbiterE * 9539470161576639981U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4181398506373973169U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15222345431506025949U;
            aOrbiterJ = RotL64((aOrbiterJ * 6925143692628659467U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15023513452326240962U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14965669361708810699U;
            aOrbiterC = RotL64((aOrbiterC * 587008860996713147U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7985755518735406360U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 225592097619240187U;
            aOrbiterF = RotL64((aOrbiterF * 2313509354133400439U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3659537916566939383U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 17043668033610689611U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterG = RotL64((aOrbiterG * 10797634709118100773U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10217321522161675848U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8013663869536146842U;
            aOrbiterK = RotL64((aOrbiterK * 2293233079384777175U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 13762445330867496042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2692400019659269106U;
            aOrbiterD = RotL64((aOrbiterD * 167704184292219399U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aScatter, 22U) + RotL64(aOrbiterG, 56U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + aNonceWordG);
            aWandererE = aWandererE + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterK, 34U));
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 47U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + aNonceWordK);
            aWandererA = aWandererA + (((RotL64(aCross, 14U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererB, 46U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25316U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 21883U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24365U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 23970U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 14U)) ^ (RotL64(aCarry, 39U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 4U)) + 7270044678408187242U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 35U)) + 10192278965379756766U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 17568666746676060748U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 14312927531124963037U) + aNonceWordM;
            aOrbiterC = (((aWandererE + RotL64(aCross, 27U)) + 9825825726152087706U) + aOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 47U)) + 9696778570255265896U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 17657841352013417228U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 43U)) + 16207815085909628439U) + aNonceWordF;
            aOrbiterH = ((aWandererH + RotL64(aCross, 14U)) + 1752979206374514227U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 10456310689643905854U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16127830548663742550U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 4355938404839045417U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2940917376003930842U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7353596864777649953U;
            aOrbiterE = RotL64((aOrbiterE * 7499468723171042005U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12725092740446150705U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5791296650856037010U;
            aOrbiterA = RotL64((aOrbiterA * 760379251950502133U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1200130368046206150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 16689604428598558547U;
            aOrbiterH = RotL64((aOrbiterH * 13815324235939996623U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 14359561591103730856U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 3975025843599045263U;
            aOrbiterD = RotL64((aOrbiterD * 5025047888533298617U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14017901732955607601U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10431526786489555196U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 10181915874476132407U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7320527073559849223U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15333411223710709907U;
            aOrbiterK = RotL64((aOrbiterK * 3488684905528068775U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14302474063321663801U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 2104154521019935187U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12944382959742278055U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5167600586916325228U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 4566823109447208716U;
            aOrbiterC = RotL64((aOrbiterC * 9997799807454267443U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 53U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 24U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 18U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterI, 60U)) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterC, 11U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 19U)) + aOrbiterB) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 41U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 10U) + aOrbiterA) + RotL64(aOrbiterK, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 52U)) + aOrbiterB) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 3U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 28U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27773U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27723U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29396U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 32320U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 54U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 60U)) + 15188686795415908074U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 35U)) + 17310049041983079779U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 3U)) + 8246925977992441471U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 8644260919918112781U;
            aOrbiterB = ((((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 23U)) + 13401663736874819483U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 18U)) + 7940358935238314973U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aWandererG + RotL64(aIngress, 43U)) + 13278990328548007839U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 53U)) + 11346868298353840706U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 23U)) + 2374077904806833579U) + aNonceWordK;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 6978903378645019166U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11951633297870965212U;
            aOrbiterJ = RotL64((aOrbiterJ * 12778236598654492185U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 17398460995357409673U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 1215437945597836770U;
            aOrbiterB = RotL64((aOrbiterB * 9322970054123481621U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 1878751468043972239U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5343002808239712390U;
            aOrbiterE = RotL64((aOrbiterE * 11878640995447558811U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9884918450053276861U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15894599082080422550U;
            aOrbiterK = RotL64((aOrbiterK * 8359936745539546131U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 13917339232771145459U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18101134009493720683U;
            aOrbiterH = RotL64((aOrbiterH * 15835859435306756387U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3830086372356903769U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15894394599564584010U;
            aOrbiterC = RotL64((aOrbiterC * 9513921913446609263U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 5127590955274245812U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9410946933309720054U;
            aOrbiterA = RotL64((aOrbiterA * 14507476989423060561U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15544384157294987085U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 998801294460434123U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5946968142746472745U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16442095194965452163U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14294936349037516932U;
            aOrbiterF = RotL64((aOrbiterF * 14655345374740882581U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterA, 58U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterE, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aNonceWordL);
            aWandererH = aWandererH + (((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterH, 26U)) + aWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC77090EE02885243ULL + 0xBDBCEC98904D3D11ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBD4FBCAB80FB8D87ULL + 0xFDBA79AFC6DF2175ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC43C0C67F0FE716FULL + 0xE689F9D89AB05302ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x933C793235710A75ULL + 0xBA4C20751E8EBF87ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDCC7700FB8A69213ULL + 0xE7E6DB63CF5BF555ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD69D387FF2063897ULL + 0xFF2263FA6026D27BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB75F3E4FEF9F2067ULL + 0xE3529B248AC873BAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE0FDBEAC28AE097FULL + 0xF682BFCA9D3E0011ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xF9D9F6C309B9EA85ULL + 0xBB8C25F86B64276FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA2C0BF01DD380987ULL + 0xE2E8C05E9D61DBEEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xBBC337D29CE9331BULL + 0xE1F6A471E9724647ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8C3CBE0F89C798C7ULL + 0xA8E9183D5B819480ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDC9040B265A079B1ULL + 0x91F61518018FD774ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x98B66D10CBDE7771ULL + 0xB3F4D7A7FFFD7DABULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF25002CA7F0AC391ULL + 0xA25BC7A67001318FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xEB15A606438AD96FULL + 0xF60E62B8E34628F3ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3776U)) & S_BLOCK1], 10U) ^ RotL64(aKeyRowReadA[((aIndex + 3961U)) & W_KEY1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3445U)) & W_KEY1], 37U) ^ RotL64(mSource[((aIndex + 4254U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 19U)) + 12426357877879529292U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aCross, 3U)) + 12604900366173639176U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 41U)) + 13511119007338929401U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 9878720081166788060U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 23U)) + 15463195409806395076U) + aNonceWordF;
            aOrbiterE = (aWandererF + RotL64(aCross, 57U)) + 6407922778852833423U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 12U)) + 7690427254160734016U) + aPhaseAOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 18030974031722143619U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 17983938038322737041U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12479365337221685413U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 16605512170117753884U) + aNonceWordE;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 681802273302348322U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 14608920184802647123U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15550312921312083819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17824154101711884508U;
            aOrbiterE = RotL64((aOrbiterE * 7358612830654795357U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1939207786756735430U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3132864634777826569U;
            aOrbiterD = RotL64((aOrbiterD * 13606281919426730325U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 12822929773923954849U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16576106045887115660U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16370914370769903051U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2398825881649235260U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 13700821892926092479U;
            aOrbiterF = RotL64((aOrbiterF * 10830623703416956043U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2439833784883391606U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15870638514107637833U;
            aOrbiterJ = RotL64((aOrbiterJ * 3797380922767479287U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 43U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterC, 30U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterC, 51U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 57U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterD, 11U)) + aPhaseAWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 56U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6187U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 10469U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6109U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 10285U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 26U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 13U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 12535417189990029950U) + aPhaseAOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 27U)) + 6204401443676390273U) + aNonceWordH;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 57U)) + 869613505613154672U;
            aOrbiterG = (((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 21U)) + 15053590879563855802U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aPrevious, 51U)) + 13338989605204591428U;
            aOrbiterC = (aWandererC + RotL64(aCross, 43U)) + 18306470022403825392U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 18U)) + RotL64(aCarry, 37U)) + 1150696349434090218U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 13549541786420596437U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14302878430259588461U;
            aOrbiterE = RotL64((aOrbiterE * 16813606782134305513U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 4660437084477165225U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1653628537860912069U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 2624835201155303123U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 5594199757006711631U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11008472193138708891U;
            aOrbiterG = RotL64((aOrbiterG * 13645764762027798301U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 3668516817279364310U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 128159531749679984U;
            aOrbiterA = RotL64((aOrbiterA * 4523246859249826987U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6378674346113979108U) + aNonceWordB;
            aOrbiterI = (((aOrbiterI ^ aOrbiterC) ^ 11438762460659123362U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 2733309638158283953U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10624263004446482910U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12546839706919241411U;
            aOrbiterC = RotL64((aOrbiterC * 11468326687628079347U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8466639576503293921U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5828694979857951504U;
            aOrbiterD = RotL64((aOrbiterD * 7835487310289634515U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterC, 60U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + aNonceWordD) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 10U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11586U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneA[((aIndex + 14666U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 13464U)) & W_KEY1], 38U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 12810U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 56U)) + (RotL64(aPrevious, 5U) + RotL64(aCross, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 34U)) + 12311607308490066301U) + aPhaseAOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 21U)) + 13100864684740679846U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 11U)) + 13697304189274329704U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 53U)) + 9047976902871216732U;
            aOrbiterF = (aWandererF + RotL64(aCross, 51U)) + 2147897579538537888U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 57U)) + 2072444829390996142U) + aNonceWordB;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 2129307836981020908U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 10663145333751112064U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15019844390503785459U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7442321463110790449U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 5460865577557928142U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15806522559993224197U;
            aOrbiterA = RotL64((aOrbiterA * 8722932687972240099U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 6361113778657833389U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8306013884615042570U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8234258702656728667U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4038420580499706912U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11908091484457158973U;
            aOrbiterB = RotL64((aOrbiterB * 3964111175645156719U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11133912466611921250U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2469227904206936928U;
            aOrbiterF = RotL64((aOrbiterF * 2704438771198001599U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 13234017916788297295U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9061117693840451988U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 3637440416741459419U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12013423690843812324U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14371779015144617412U;
            aOrbiterC = RotL64((aOrbiterC * 3359568073302062667U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterK, 35U)) + aNonceWordL) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + RotL64(aCarry, 29U)) + aNonceWordK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 14U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterI);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterK, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20979U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 20063U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17036U)) & S_BLOCK1], 3U) ^ RotL64(mSource[((aIndex + 20224U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 20U)) ^ (RotL64(aCross, 3U) + RotL64(aPrevious, 47U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aScatter, 11U)) + 13854738573712660276U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 16835460633412286294U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 6785859293758091931U) + aNonceWordI;
            aOrbiterK = ((aWandererC + RotL64(aCross, 35U)) + 126317283127992659U) + aNonceWordH;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 44U)) + 7568963536291415413U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 57U)) + 12294016745653004819U) + aPhaseAOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = ((((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 18269588932920281147U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5872406424994751026U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7764434758831474129U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 3772146788188420071U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4804168969415573371U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 959601763507651280U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 4647396592804833217U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9257644462479293048U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14332699366894494579U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 10487012596470786004U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 612729229562321440U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11380387280507726003U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7845523921295625315U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12742115479740024747U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15578543510683986421U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10294667720904610944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14369711143154904567U;
            aOrbiterK = RotL64((aOrbiterK * 13753005602288309379U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10918344717497681894U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 18136794828308636957U;
            aOrbiterA = RotL64((aOrbiterA * 17899418637978002409U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + RotL64(aOrbiterG, 13U)) + aOrbiterI) + aNonceWordE) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 20U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 58U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 5U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 19U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22827U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 25999U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26819U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 24447U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 20U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 21U)) + 9914837590440975587U) + aNonceWordC;
            aOrbiterB = ((((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 6706125076401958051U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererF + RotL64(aScatter, 23U)) + 16570817772679258409U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 51U)) + 6843705658115186948U;
            aOrbiterI = (aWandererD + RotL64(aCross, 29U)) + 16099930446791572351U;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 3U)) + 5420550009556030459U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordN;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 5729549069420177477U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15590601126188675834U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13044027390998620029U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16845199115313444123U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11068338135659636772U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6584988841809544332U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 1683336180438945439U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8516813219883915404U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10647314042912492785U;
            aOrbiterJ = RotL64((aOrbiterJ * 15559481057047148785U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 201691689889605304U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15512161798401184003U;
            aOrbiterB = RotL64((aOrbiterB * 11473219183982564709U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 3883760518944464145U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 13861805129175491145U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17194438894492581181U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12019138626550801486U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 13030350224959652248U;
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2643807255422544248U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4127143302485631794U;
            aOrbiterC = RotL64((aOrbiterC * 5441038881111578487U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 54U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 13U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterC, 19U));
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 43U)) + aPhaseAWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 4U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 6U)) + aOrbiterK) + aNonceWordD) + aPhaseAWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + RotL64(aWandererH, 11U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordM);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27466U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27588U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31090U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((aIndex + 31798U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 27U)) + (RotL64(aCarry, 11U) + RotL64(aIngress, 44U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 41U)) + 13583136155674166402U) + aNonceWordA;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 12830472187484919497U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 18081197909484522509U;
            aOrbiterG = ((aWandererB + RotL64(aCross, 24U)) + 8680634051297891550U) + aPhaseAOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 47U)) + 13939998767458656823U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = ((aWandererF + RotL64(aIngress, 57U)) + 1795730579103692594U) + aNonceWordE;
            aOrbiterA = ((aWandererC + RotL64(aCross, 35U)) + RotL64(aCarry, 27U)) + 17369751719734069999U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 224769585901248068U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4133547085925268180U;
            aOrbiterC = RotL64((aOrbiterC * 2611561365156544735U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7022512056309567391U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10319484359046945495U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3400140531307001933U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10483878349412282069U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 6481381149199985736U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 9701719367082506253U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13721077228796934509U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9704818014314175007U;
            aOrbiterA = RotL64((aOrbiterA * 760445624027740287U), 3U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 6253040047758584339U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 16890211690273641226U) ^ aNonceWordJ;
            aOrbiterD = RotL64((aOrbiterD * 5622534399866057841U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 6216227831265032436U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2023609047004658739U;
            aOrbiterG = RotL64((aOrbiterG * 3252332895698310147U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9201669637050388263U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5106927540934338576U;
            aOrbiterJ = RotL64((aOrbiterJ * 6368134569042291431U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 14U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 50U) + aOrbiterA) + RotL64(aOrbiterC, 23U));
            aWandererB = aWandererB + (((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 6U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterI, 35U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 47U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterH) + aNonceWordK) + aPhaseAWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 13U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 57U)) + aOrbiterC) + aPhaseAWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 37U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_VolleyBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCA71CB3C6B2ADEA3ULL + 0xEE6B38AE7BF08218ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9F4383B7391FDC07ULL + 0xECB96D57A69B0BC1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x925EE04EF6509A0BULL + 0xA79251F1D1345E9DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8B4D4059D850A597ULL + 0x9DFEB54274CFE12FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9D111D7ADA62B09FULL + 0xAD2BA339DE328C7EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA28C1641DA8385B5ULL + 0xCB68A0EA9A942D2BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xCD9CCEF5DD977287ULL + 0xFEB6CB621688BC01ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8E763DAE4B310697ULL + 0xC8E44D3FF5C46415ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC6FF2A99A0EB43C5ULL + 0xE98DD118B810E9E2ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xAF89E75CE6A68BEDULL + 0xD62BB7D423C30BBAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x842FE225B793A4DDULL + 0xD41CB628BAA895B8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD9E4E7CE3296B29BULL + 0xB1D35F6A2C33B388ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA3EC221449C0461DULL + 0xA56A185FEE238DA0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFA39906CDA46F073ULL + 0xE6F529AEC56DD254ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE58C5B310561215FULL + 0xD88FB597065336E2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x8B664E15D3807451ULL + 0xA955B8594FA79AB2ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1328U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 870U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4853U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1377U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aPrevious, 20U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 3U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 27U)) + 9041099828460168106U) + aNonceWordC;
            aOrbiterC = (((aWandererJ + RotL64(aCross, 21U)) + 12883711604096848454U) + aPhaseBOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1]) + aNonceWordD;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 44U)) + 17420968786226443079U) + aPhaseBOrbiterAssignSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 3448213891716125104U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 11866455977445336560U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 4119356835384495905U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2186212599698637068U;
            aOrbiterK = RotL64((aOrbiterK * 6756888950976735707U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6506144898969301620U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12556800923644051626U;
            aOrbiterG = RotL64((aOrbiterG * 15961043406612913121U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4075551535185182945U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 17877694808492008749U;
            aOrbiterJ = RotL64((aOrbiterJ * 901315308379887473U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 5553428900598223316U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 14362304852277160675U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11415103199856419303U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 9174200302876075831U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16110739511917638547U;
            aOrbiterF = RotL64((aOrbiterF * 7004356839428657949U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 3U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 43U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 43U) + RotL64(aOrbiterF, 42U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + aNonceWordA);
            aWandererC = aWandererC + (((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7469U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10371U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9705U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6640U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 14U) + RotL64(aCross, 29U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 22U)) + RotL64(aCarry, 11U)) + 8793908991006073956U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 43U)) + 2932916283348441943U) + aNonceWordK;
            aOrbiterH = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 11069042087940968262U) + aPhaseBOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 53U)) + 14369628676782894441U) + aNonceWordL;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 13U)) + 8602903272780978282U) + aPhaseBOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 3827036107178568820U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8905245209036772489U;
            aOrbiterH = RotL64((aOrbiterH * 5744017326197157667U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13331387530760017893U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9880107580289737823U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10302652857542703753U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10199619040626900278U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2466307560891374281U;
            aOrbiterA = RotL64((aOrbiterA * 6295342978834217571U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13973403407981259448U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2851460278409385243U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 11226902976321781743U), 39U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 10365453393815690776U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2382382358987358791U;
            aOrbiterK = RotL64((aOrbiterK * 481563628980705781U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 22U) + aOrbiterK) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterF) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 37U)) + aNonceWordJ) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13087U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12781U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13858U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14108U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 11U)) + (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((((aWandererB + RotL64(aCross, 37U)) + RotL64(aCarry, 53U)) + 12131317914288566437U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 23U)) + 5672805657999385496U) + aNonceWordL;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 3U)) + 3581710244233124197U;
            aOrbiterF = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 27U)) + 15251296040538489436U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 52U)) + RotL64(aCarry, 11U)) + 11295008604679904153U) + aNonceWordJ;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2230897493419504490U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7109600123297458999U;
            aOrbiterD = RotL64((aOrbiterD * 8267799351136506307U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13119156643107683803U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14755160867807355250U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10007087518844899239U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 16829363373287496832U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16981122946707720883U;
            aOrbiterG = RotL64((aOrbiterG * 5394974422201576627U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8806000776958603317U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16810923047720876014U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17872735050219539145U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 8129657889554436328U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8653100378491974463U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11395283153912468661U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 6U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 18U) + aOrbiterF) + RotL64(aOrbiterD, 10U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + aNonceWordA);
            aWandererG = aWandererG + (((((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + RotL64(aCarry, 23U)) + aNonceWordB) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterF, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16466U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneB[((aIndex + 16932U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20531U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20201U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 52U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 18319689184146942855U) + aNonceWordH;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 8041304130090501019U) + aNonceWordE;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 5U)) + 11347064191990897738U;
            aOrbiterF = ((((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 43U)) + 15242243470024447468U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 21U)) + 10619749107163611105U) + aPhaseBOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14795614276221947128U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1578095288886372393U;
            aOrbiterC = RotL64((aOrbiterC * 9953192041564147241U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13593906305770501684U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8919815528334599172U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2033810402808238127U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17425548324720065145U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11125018338392347335U;
            aOrbiterF = RotL64((aOrbiterF * 4377887040461528587U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3779189180734244399U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 10958224663276134041U;
            aOrbiterA = RotL64((aOrbiterA * 6206963519509783781U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4317305352561612995U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 4891139433808505355U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11507024985663120317U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterF) + aPhaseBWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterC, 30U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterF, 19U)) + aPhaseBWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23013U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneA[((aIndex + 25022U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26647U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 27007U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aPrevious, 54U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 5576732410244514238U) + aNonceWordN;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 30U)) + 2833808925935929629U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 3670188682914544792U) + aPhaseBOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 15759072378887814995U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 39U)) + 13934007231137439994U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11022225696007690512U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16989177104453635790U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 14156758251105809453U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9256930045263527091U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 17788596104417068290U;
            aOrbiterJ = RotL64((aOrbiterJ * 675554110563253305U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17044369456673337625U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1310908395523250343U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16305084373037705921U), 3U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 12067065689034065422U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15130844248737512262U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9409499577465934107U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14532689204495587494U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8198147292120244178U;
            aOrbiterB = RotL64((aOrbiterB * 1418356389507740991U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterA, 58U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 21U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31842U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 32254U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31722U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 31882U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 29U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 12U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 37U)) + 3684295017013759987U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 35U)) + 6740408842457292881U) + aNonceWordP;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 4563975890702399441U) + aPhaseBOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 797804144825287940U) + aNonceWordE;
            aOrbiterG = ((aWandererB + RotL64(aCross, 27U)) + 2763779540450101303U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13211846164102089685U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 15214578447281401982U;
            aOrbiterC = RotL64((aOrbiterC * 12107189619131483661U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 13745208628754232427U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17358621225969190747U;
            aOrbiterK = RotL64((aOrbiterK * 5325024317338823061U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 779739369960480023U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 4370963533701407813U;
            aOrbiterB = RotL64((aOrbiterB * 3123135216876641039U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 6061333005507739975U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 3589705340762734456U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 16499293983611196967U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10607697666369230567U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 9356757995305239271U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10945513661439954731U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 53U) + aOrbiterB) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 53U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterF, 43U)) + aOrbiterK) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterB, 20U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_VolleyBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF39342663302D967ULL + 0xBAE3907DEE66429AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xAFB90CA03F7E961DULL + 0xEAD96D1CC67484E3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF1D305F65B8AEBEFULL + 0xD5599A3D131C7AB1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB9452B1DC18CC51FULL + 0xACCBBD6D24AEB6C9ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x902D45C32E18D5DDULL + 0x99994CA92C1A08FBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFA37BE1A0AD1BAC7ULL + 0xA50FB6465ABFD964ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC232AF597B09128BULL + 0xD0822C33202CBC17ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB954FA5CA245A505ULL + 0xADDC58E13D2F6C4BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDDFA9098546ED71FULL + 0xB63A9D326957D249ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9538A82866EA08DFULL + 0xF1CA8DEABA35DA49ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFD9E7A22D7379751ULL + 0x851DB4A694B9F843ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF567CB5BB5D3F477ULL + 0x9EABB5EA4F74FAF6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9C87EC1BFE269CC5ULL + 0x98D60162A4EB7781ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF5DF8DB19306BD01ULL + 0xB6E8A7F110B3BEACULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8A93B6AA4E5D8709ULL + 0x84C352649C208DABULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEA18155D000E2FEFULL + 0xBEDDBC276F9AB911ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3737U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4208U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1921U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 3639U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 34U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterC = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 15188686795415908074U) + aNonceWordG;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 52U)) + 17310049041983079779U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 47U)) + 8246925977992441471U;
            aOrbiterK = (aWandererD + RotL64(aCross, 27U)) + 8644260919918112781U;
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 13401663736874819483U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 18U)) + 7940358935238314973U;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 39U)) + 13278990328548007839U) + aPhaseCOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 3U)) + 11346868298353840706U) + aNonceWordK;
            aOrbiterB = (aWandererC + RotL64(aCross, 47U)) + 2374077904806833579U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6978903378645019166U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11951633297870965212U;
            aOrbiterE = RotL64((aOrbiterE * 12778236598654492185U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 17398460995357409673U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 1215437945597836770U;
            aOrbiterD = RotL64((aOrbiterD * 9322970054123481621U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1878751468043972239U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 5343002808239712390U;
            aOrbiterJ = RotL64((aOrbiterJ * 11878640995447558811U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9884918450053276861U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15894599082080422550U;
            aOrbiterB = RotL64((aOrbiterB * 8359936745539546131U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13917339232771145459U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 18101134009493720683U;
            aOrbiterC = RotL64((aOrbiterC * 15835859435306756387U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3830086372356903769U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15894394599564584010U;
            aOrbiterK = RotL64((aOrbiterK * 9513921913446609263U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5127590955274245812U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9410946933309720054U;
            aOrbiterG = RotL64((aOrbiterG * 14507476989423060561U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 15544384157294987085U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 998801294460434123U;
            aOrbiterI = RotL64((aOrbiterI * 5946968142746472745U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16442095194965452163U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14294936349037516932U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 14655345374740882581U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 24U));
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 4U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 53U)) + aOrbiterH) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterK, 60U));
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB + ((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13878U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15577U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15596U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 13931U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 18U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 52U)) + 1142447269198373880U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 19U)) + 10581460640040336191U) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 43U)) + 14703062773878202900U) + aNonceWordB;
            aOrbiterI = (aWandererA + RotL64(aScatter, 57U)) + 15737525756286914746U;
            aOrbiterE = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 47U)) + 16178774478273186999U) + aPhaseCOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 21U)) + 2514897053906809160U;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 13702496607592508464U) + aPhaseCOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aScatter, 27U)) + 18030885275418337965U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 6U)) + 5241783876161655984U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2807052676283587925U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 8022804576763271327U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11727096043219370577U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15597099852232205860U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1538435607932096400U;
            aOrbiterE = RotL64((aOrbiterE * 7900752511710516981U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11147868774413615365U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 9325213746830411568U;
            aOrbiterK = RotL64((aOrbiterK * 561819005818948769U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 13792300423550555634U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3134856508983945719U;
            aOrbiterC = RotL64((aOrbiterC * 4271845067763664863U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 8654966018053784882U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8937113935476779267U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 7386875687217705855U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4135676350355234788U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11407912615743682678U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2773506587480714695U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10966950663872392059U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6686634993700944582U;
            aOrbiterI = RotL64((aOrbiterI * 2509459942163678241U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14154407529749257990U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 18054640398549782388U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 7830759861389060149U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14623473030642960240U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1857945571104460086U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 18039903315045620079U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 60U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 6U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterH, 13U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 23U)) + aOrbiterC);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterF) + RotL64(aOrbiterG, 34U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 41U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 19U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19189U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22882U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23808U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneC[((aIndex + 19680U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 56U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aScatter, 36U)) + 1364174714924216027U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 27U)) + 13561796874229506613U;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 11845572344206238305U) + aPhaseCOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aWandererK + RotL64(aPrevious, 47U)) + 15762708240326773763U;
            aOrbiterB = (aWandererF + RotL64(aCross, 41U)) + 1157119665207900473U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 6823546624372055260U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 22U)) + 14465564210523945121U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 13U)) + 10667464548080807531U) + aNonceWordH;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 13445737493224316575U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3009837893785957665U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2886920524111083752U;
            aOrbiterK = RotL64((aOrbiterK * 15308180928967762543U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10886177449328249656U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15067759884678100433U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5724566815989860041U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 18307930462682331536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8791864377579255801U;
            aOrbiterH = RotL64((aOrbiterH * 9265158882471421767U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 805797468642992351U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5743305867058244964U;
            aOrbiterG = RotL64((aOrbiterG * 16263000753351131717U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17102025528234481273U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 1841579177327486899U;
            aOrbiterB = RotL64((aOrbiterB * 3841603385577825265U), 39U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 2189493507896508972U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18209567010094914374U;
            aOrbiterD = RotL64((aOrbiterD * 3737080408976852351U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 6697069234216868330U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 927471474577415372U;
            aOrbiterJ = RotL64((aOrbiterJ * 10680760991009199309U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13155854301197725408U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1014625081915435892U;
            aOrbiterC = RotL64((aOrbiterC * 11592754232949990435U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12697209921410914931U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 11555096613655648647U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4598821388864997089U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterJ, 53U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 51U) + RotL64(aOrbiterF, 57U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterD) + aNonceWordJ);
            aWandererI = aWandererI + (((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterD, 48U)) + RotL64(aCarry, 57U)) + aNonceWordN) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 29U)) + aOrbiterE);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + aNonceWordL);
            aWandererB = aWandererB + ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterH, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterH, 34U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 22U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 24648U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 28220U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 31269U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29418U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 23U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterK = ((((aWandererI + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 13481227414590594621U) + aPhaseCOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 13U)) + 17425964381118918026U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 19U)) + 4792004356135956581U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 27U)) + 11926849936000639098U;
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 990697329347742142U;
            aOrbiterB = (aWandererF + RotL64(aPrevious, 34U)) + 9307721505373076588U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 43U)) + 17605732738841908719U) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 41U)) + 13110764518634187439U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 17970109897810645911U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10273133817644703654U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 11239046688920468137U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 5197802934333553327U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 8355821483275763145U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15522151127786049345U;
            aOrbiterG = RotL64((aOrbiterG * 4844278537850520413U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5381663179722418112U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9551368011768104906U;
            aOrbiterE = RotL64((aOrbiterE * 14202470972121732997U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16264476585232221270U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7721417776432288282U;
            aOrbiterK = RotL64((aOrbiterK * 10267770327791051869U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 339418090653475277U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3247926250495935511U;
            aOrbiterJ = RotL64((aOrbiterJ * 16824669543765729097U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 3390560045236418590U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3894024951542543635U;
            aOrbiterB = RotL64((aOrbiterB * 10599637790900418767U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3878539166189668154U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5617705593218220843U;
            aOrbiterA = RotL64((aOrbiterA * 82771190372750823U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12320861089148474544U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14943790251625519550U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13758322022902008313U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 18119213517612562775U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1413193144229486646U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14562375280658115687U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 26U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 24U)) + aOrbiterG) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 26U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 51U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + ((RotL64(aScatter, 52U) + aOrbiterK) + RotL64(aOrbiterC, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 14U)) + aOrbiterH) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xED64B5ED85FFD709ULL + 0xCBB47346713747D2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC441D517C440E6B1ULL + 0xFE530EBAC3F143EEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x9FFCBAEE9241C297ULL + 0xB094E69A014F52ADULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFDD420BD2F7BAEE5ULL + 0x82450049366DD559ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA6F861A1FD3F8295ULL + 0xBC2D6E43EFBF6278ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF7B6CAE2CF04A45BULL + 0xE2115DEB91BCEE19ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC344F439E44B193FULL + 0x93D086A6F063D139ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE5049C96E9FA6B05ULL + 0xF2E2DB102A722672ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xDA8A7884936F40EFULL + 0xC13F3C582A0F84D7ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9771A8F2EE22CD7BULL + 0xB0C5FF3858126456ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA181E0DD1A090AC3ULL + 0xB71767242ECB406AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFFF1739EC1094609ULL + 0x8C080FDE1BC5C770ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF9F2E2A499EED69FULL + 0xB24BBFA1E7F48AEEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCD0DD3C96BF60B4BULL + 0xC0A8704E55ADD180ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC9435BE707DEF2B7ULL + 0x944C5F98D32B04FDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x82436A5AE6F855E1ULL + 0xA252FB6A8F9B2C9DULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5022U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2960U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1501U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2171U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 39U)) + 77518479758428414U) + aPhaseDOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aIngress, 13U)) + 4832061802166300011U) + aNonceWordP;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 29U)) + 11695291171006574112U;
            aOrbiterE = (aWandererF + RotL64(aCross, 5U)) + 7467412817843260094U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 11U)) + 17801484124471154757U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 53U)) + 5555455638503958639U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 18U)) + 5669470540733721606U;
            aOrbiterJ = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 3042388456327784163U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 51U)) + 2236734925228156691U;
            aOrbiterI = ((aWandererI + RotL64(aIngress, 41U)) + 14459720401528685450U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aScatter, 22U)) + RotL64(aCarry, 47U)) + 4814967631216658856U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16950679344449075945U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6262238639302011050U;
            aOrbiterD = RotL64((aOrbiterD * 9942659897425088183U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3522256359074996724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12524717897707074242U;
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 13891759914865623828U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11910250571469028666U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12311343917878428995U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 2240189915640314069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5365912986308810837U;
            aOrbiterE = RotL64((aOrbiterE * 15133972552032469957U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9323732721344489753U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13087326560957916553U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14659491687401151733U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16398238057564892809U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11517870519285159224U;
            aOrbiterG = RotL64((aOrbiterG * 1501848878469712681U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7758285512254776734U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 17475149091906684720U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6015816725428299273U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2051631493975035243U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11684740065349595315U;
            aOrbiterB = RotL64((aOrbiterB * 10918975496337269197U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10575473798991451167U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8267005776169272822U;
            aOrbiterH = RotL64((aOrbiterH * 13166868678285963961U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6249698995716039231U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13808085811784323978U;
            aOrbiterJ = RotL64((aOrbiterJ * 3897731011582061983U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2739364646624876985U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 77518479758428414U;
            aOrbiterI = RotL64((aOrbiterI * 6977724811175035551U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 28U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterD, 18U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + aNonceWordC);
            aWandererE = aWandererE + ((((RotL64(aIngress, 24U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 5U)) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterA, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 39U));
            aWandererG = aWandererG + ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 22U) + RotL64(aOrbiterC, 3U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterA, 37U)) + aPhaseDWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterD, 26U)) + aOrbiterF) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9138U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10249U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7170U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 10820U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) + RotL64(aIngress, 19U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = (((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 5697928251815176134U) + aPhaseDOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aIngress, 51U)) + 337587740689259575U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 3U)) + 4927686903263973950U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 57U)) + 3742409032569801033U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 24U)) + 1608092659172197650U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 43U)) + 15848744267145717509U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 15300174177963339253U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aCross, 41U)) + 14162868453323648628U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 57U)) + 12020167069983729869U) + aNonceWordD;
            aOrbiterG = (aWandererH + RotL64(aCross, 19U)) + 16259538291658723956U;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 53U)) + 8516686212464112245U) + aNonceWordC;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3722184575520553132U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5663609293306386784U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14364218128780764749U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15265344442454471986U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3050323350098829515U;
            aOrbiterH = RotL64((aOrbiterH * 5890624677162388135U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1093356813820599238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15167726103772238440U;
            aOrbiterA = RotL64((aOrbiterA * 5719466863561311069U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15170797965325981472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17826286701992981628U;
            aOrbiterD = RotL64((aOrbiterD * 11186808881726573677U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14710892030473425181U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 397194787697553904U;
            aOrbiterF = RotL64((aOrbiterF * 14368930300818752833U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 1273724124862533034U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13018397560392545616U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4644812473262395329U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9638716186445643730U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7255587739807843785U;
            aOrbiterJ = RotL64((aOrbiterJ * 6055682981584011189U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9272350563697399628U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 1040729335295009339U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 17825687660830291443U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12128124729613601747U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2285238815562202219U;
            aOrbiterC = RotL64((aOrbiterC * 15398840993074390573U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6339113298619163493U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5911895708485037040U;
            aOrbiterG = RotL64((aOrbiterG * 3271006139923200439U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 7601399508218901328U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 5697928251815176134U;
            aOrbiterI = RotL64((aOrbiterI * 8184257916861355735U), 37U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 46U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 54U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterG, 13U)) + aOrbiterF) + aNonceWordL);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 53U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterB, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 43U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterC, 21U)) + aNonceWordG) + aPhaseDWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterD, 60U));
            aWandererG = aWandererG + ((((RotL64(aCross, 40U) + aOrbiterA) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 11141U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12982U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11037U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 13511U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 27U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 7075016829833562104U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 8783765886115517036U) + aNonceWordL;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 3U)) + 2996723892384565829U) + aNonceWordD;
            aOrbiterI = (aWandererC + RotL64(aCross, 21U)) + 9494134707342189476U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 51U)) + 5052642981395679904U) + aNonceWordN;
            aOrbiterK = (aWandererK + RotL64(aScatter, 53U)) + 8766787055127962238U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 13U)) + 4467211954388738079U) + aPhaseDOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 8030255604633658608U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 11U)) + 16962408063455702251U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aIngress, 26U)) + 3768222186567699076U;
            aOrbiterA = (aWandererH + RotL64(aPrevious, 19U)) + 14930990410207899871U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14179761938395502502U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1879084742719898108U;
            aOrbiterF = RotL64((aOrbiterF * 16783034788172670121U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5535012408925981515U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12792553516710295939U;
            aOrbiterK = RotL64((aOrbiterK * 8577530993755159329U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8979253163346099252U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5559189896063990740U;
            aOrbiterG = RotL64((aOrbiterG * 8832485423727331621U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13937564337299044079U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2393376759689394948U;
            aOrbiterJ = RotL64((aOrbiterJ * 2352815657830413941U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 12647519563697356479U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10946871249960389549U;
            aOrbiterC = RotL64((aOrbiterC * 6272580371881237173U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13376798695582123147U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10958115913599631271U;
            aOrbiterH = RotL64((aOrbiterH * 18233981473003345217U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4283914227806672773U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 910842005516235816U;
            aOrbiterB = RotL64((aOrbiterB * 6722229871617873429U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1509644316619370324U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 165987596716078174U;
            aOrbiterI = RotL64((aOrbiterI * 13600064054240185123U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12491315345199091186U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 5982431705686495125U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2547243804779022665U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 231183123382412440U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2872632389683254396U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1972278820468847241U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15259314110008210315U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 7075016829833562104U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8350093877370898869U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 41U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 52U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 37U) + aOrbiterC) + RotL64(aOrbiterJ, 43U)) + aNonceWordJ);
            aWandererK = aWandererK + ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 56U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 53U)) + aOrbiterH);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 22U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 41U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterH, 21U));
            aWandererI = aWandererI + ((((RotL64(aCross, 56U) + RotL64(aOrbiterK, 24U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseDWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordG;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 19460U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19873U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 16407U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19141U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = (aWandererE + RotL64(aIngress, 23U)) + 6521330037475130256U;
            aOrbiterI = (aWandererD + RotL64(aCross, 41U)) + 12611880456055428940U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 11U)) + 12061611078130934708U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 60U)) + RotL64(aCarry, 19U)) + 1558112410801116984U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 43U)) + 10509115227850160786U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 4045915960688792066U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 51U)) + 1196541286513243082U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 20U)) + 15564991032722373702U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 27U)) + 4897765238703641798U;
            aOrbiterD = (aWandererI + RotL64(aCross, 29U)) + 12327429514907752733U;
            aOrbiterH = ((((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 6189189797708711636U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordN;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6374267075282018852U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1888758503831341439U;
            aOrbiterE = RotL64((aOrbiterE * 74387714918264257U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14956857689299491800U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 14879361107223331957U;
            aOrbiterG = RotL64((aOrbiterG * 9166712966729591953U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16086885494838105042U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8069724185844303923U;
            aOrbiterB = RotL64((aOrbiterB * 8878470736758734353U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 10854345917959911439U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7078313614360332089U;
            aOrbiterJ = RotL64((aOrbiterJ * 9864025732292844871U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15083669236062255011U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 594879695916679116U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 9852515479152735283U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6721466068234534523U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 475816724162626782U;
            aOrbiterK = RotL64((aOrbiterK * 4799725182757588407U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4341655358154605899U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15477254302340298586U;
            aOrbiterD = RotL64((aOrbiterD * 13961520225881974201U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10179091913200895775U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 6310490897546909571U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15080621088825477613U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 13462682513035460711U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16739138858084100385U;
            aOrbiterA = RotL64((aOrbiterA * 16386371811268298031U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 13608837667062268989U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12902415667552110103U;
            aOrbiterI = RotL64((aOrbiterI * 16398790854093048017U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16596211634603915761U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6521330037475130256U;
            aOrbiterF = RotL64((aOrbiterF * 631958426544321145U), 39U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 41U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 12U)) + aOrbiterF) + aPhaseDWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 29U));
            aWandererF = aWandererF + ((RotL64(aScatter, 42U) + RotL64(aOrbiterB, 51U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterF, 41U));
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 53U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterG, 10U)) + aNonceWordJ);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterD, 21U));
            aWandererE = aWandererE + ((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23195U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22163U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24930U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23275U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aIngress, 21U)) + 6024062041314952357U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 18340757093658015585U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 3U)) + 11911120493880346751U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 19U)) + 17428074353884654439U) + aNonceWordN;
            aOrbiterF = (aWandererE + RotL64(aScatter, 35U)) + 12790849760814795936U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 12633397052172117800U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 38U)) + 11946150433665237945U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 16842157900909419285U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 13U)) + 14186235783224155962U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 53U)) + 13284904542579767591U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 42U)) + 11609181965078844357U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9628562297095374984U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7850281529011259759U;
            aOrbiterH = RotL64((aOrbiterH * 17611485102925470357U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 257458718073794527U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10693404545773519306U;
            aOrbiterD = RotL64((aOrbiterD * 14821443722828498323U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 3430519236533871460U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 6183054506953198055U;
            aOrbiterC = RotL64((aOrbiterC * 6121082743789970911U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2905610989884221654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4472163910775333862U;
            aOrbiterE = RotL64((aOrbiterE * 7770678426310856745U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16870142883133769663U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterG = RotL64((aOrbiterG * 9740854430251597879U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16904169913507057108U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4773518591580333357U;
            aOrbiterB = RotL64((aOrbiterB * 5306070307776061267U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6528141733853494275U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 11254806909313951442U;
            aOrbiterA = RotL64((aOrbiterA * 6316669786405548827U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6857506858448143407U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2855763534355983644U;
            aOrbiterI = RotL64((aOrbiterI * 16881334940165182415U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12328391751024624740U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16475072086109949522U;
            aOrbiterJ = RotL64((aOrbiterJ * 15218626930666825883U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15505670341076785424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6972128419331939330U;
            aOrbiterK = RotL64((aOrbiterK * 12206069109180246067U), 57U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 7151546362283646210U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6024062041314952357U;
            aOrbiterF = RotL64((aOrbiterF * 10243806128059850493U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 30U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterI, 13U));
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 6U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 38U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + aNonceWordG);
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 19U));
            aWandererC = aWandererC ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterK) + aNonceWordK) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterI, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 54U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 34U) + aOrbiterI) + RotL64(aOrbiterE, 37U)) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 11U)) + aOrbiterB);
            aWandererF = aWandererF ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + aPhaseDWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31622U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30616U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27321U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30662U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 56U)) + (RotL64(aCarry, 29U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 53U)) + 13915875634607599122U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 58U)) + RotL64(aCarry, 39U)) + 1695770381382411673U) + aNonceWordD;
            aOrbiterK = (aWandererI + RotL64(aScatter, 23U)) + 3709105579778295511U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 7673376335333251804U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 47U)) + 8814147709738503518U;
            aOrbiterG = (aWandererG + RotL64(aCross, 51U)) + 13451412605350381172U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 5U)) + 6447870234069609538U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 43U)) + 13419487997946496825U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 14U)) + RotL64(aCarry, 35U)) + 5478309847615220345U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 19U)) + 3635184969215610049U) + aPhaseDOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aPrevious, 29U)) + 12527903812035294828U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1684685110885338814U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 12860354576326835090U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12743745087733307255U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 9081823570147481835U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 14369321778210049109U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17865953349448767035U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11518132079084873250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11893535026126957389U;
            aOrbiterG = RotL64((aOrbiterG * 15751374986135615095U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7084079180579206226U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2999676609847603277U;
            aOrbiterH = RotL64((aOrbiterH * 14602698397511266403U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17683445810614029153U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 11576460512964896969U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 5243651036457051155U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13429800604736567949U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14661785761747367546U;
            aOrbiterE = RotL64((aOrbiterE * 4765843989277333421U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12837164345582888950U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6222666313184669392U;
            aOrbiterD = RotL64((aOrbiterD * 17402483466567712319U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5358647039491079457U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12459911673401497180U;
            aOrbiterC = RotL64((aOrbiterC * 13605465035256188065U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 3333017644772803587U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15501587702102554928U;
            aOrbiterA = RotL64((aOrbiterA * 4921693371641768339U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8492287653837766613U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3432736785678875404U;
            aOrbiterJ = RotL64((aOrbiterJ * 7326419883291516513U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2841486107704281869U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13915875634607599122U;
            aOrbiterI = RotL64((aOrbiterI * 707861617246345083U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            aWandererD = aWandererD + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 52U) + aOrbiterJ) + RotL64(aOrbiterA, 24U)) + aNonceWordJ);
            aWandererI = aWandererI + (((RotL64(aCross, 35U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 53U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 42U) + aOrbiterK) + RotL64(aOrbiterB, 27U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterF, 30U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterK, 3U));
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordE;
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

void TwistExpander_VolleyBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xEEAE0E5E186841C7ULL + 0xC02E83392C457E73ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xADD4A58177531B85ULL + 0x93A20ED694A706EBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD6EDEA72B00C4259ULL + 0xBEA193CA4F92680AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAAAF7F5B5BFED0E1ULL + 0xAA2E0F7473297205ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xAF488BA6ED682DA5ULL + 0xB1B560F83C59B3C4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9515CC2DE659234DULL + 0xE94CDF1CFFD345AEULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x804B12C0F739F7D3ULL + 0xF7A594A6363A2673ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEA17E7D142FF7FB3ULL + 0xA03D4AED2D87772EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xD34921462C9F3A9FULL + 0xD4B64CF9D9838B9FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD2775D6C2D3AEE5FULL + 0xC59C6BBD9E65AA91ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9F0D3EC0119CE6DDULL + 0x939E8CA4C7DE02B7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB710091E2CDCF80FULL + 0xB7BD33C0F69D89C2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8334B4F0F2F0897FULL + 0xE495B6DD4A48BF8CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAC3ABB12F1AF7005ULL + 0x98FEFC48F7A84699ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC0F851CA8723F011ULL + 0xD2ADC1AD39ECFE39ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC7B120F763AD7C71ULL + 0xEBCD6D32BE681B38ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3799U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4520U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1472U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 2242U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCarry, 6U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 12136097566601676613U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aScatter, 44U)) + 7969431322248040056U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 11U)) + 10530676021510553889U) + aNonceWordP;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 53U)) + 8740777303075445264U;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 39U)) + 13249434169895564739U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 37U)) + 15529577005925628472U) + aPhaseEOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aCross, 3U)) + 344627093687331562U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 35U)) + 8824277416519988893U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 5636276438449709875U) + aNonceWordI;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 2079413361031851552U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 46U)) + 7807998179168655561U) + aNonceWordG;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13589392896232029112U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10733011474804473996U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 361749145931578805U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 15934162328347805968U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 7573511217796245232U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10694563909931636155U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 4828475187337891975U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13284974329890393113U;
            aOrbiterI = RotL64((aOrbiterI * 10831075817642374287U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13173869918669643112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15841507674783398167U;
            aOrbiterH = RotL64((aOrbiterH * 15632933198136963277U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14168272451055700516U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11134471485501999898U;
            aOrbiterF = RotL64((aOrbiterF * 8019507184494591705U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2611858916687822610U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17863271539727513641U;
            aOrbiterE = RotL64((aOrbiterE * 4987884722174985677U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8874401993454249066U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5131480593493950665U;
            aOrbiterD = RotL64((aOrbiterD * 8585874663602346121U), 41U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 9366563022381918996U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7890729519928340296U;
            aOrbiterC = RotL64((aOrbiterC * 11428572374057899517U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 131774386529223292U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 4108356674478240148U;
            aOrbiterJ = RotL64((aOrbiterJ * 2492753294539081613U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7651738365157869789U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2745458108574051004U;
            aOrbiterG = RotL64((aOrbiterG * 2175955806036373729U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10492013124307434604U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 12136097566601676613U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13128652803485742119U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 29U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 50U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 12U) + aOrbiterB) + RotL64(aOrbiterD, 56U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB + ((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 23U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 37U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 13U)) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 10U)) + aOrbiterA) + aNonceWordM) + aPhaseEWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 48U) + RotL64(aOrbiterD, 13U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordB;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7160U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10455U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9604U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10811U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 26U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = ((((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 23U)) + 3550722402315312207U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (aWandererH + RotL64(aCross, 23U)) + 16724184551669522754U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 981751330116773021U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 14U)) + RotL64(aCarry, 51U)) + 7891159229704944868U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 41U)) + 13618396711464799841U) + aPhaseEOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 3U)) + 5969291018449003648U;
            aOrbiterJ = (aWandererC + RotL64(aScatter, 29U)) + 14595540413313640042U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 37U)) + 3287990436916111762U) + aNonceWordL;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 19U)) + 12534369400200483704U) + aNonceWordE;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 27U)) + 2277312067930392274U;
            aOrbiterK = (aWandererB + RotL64(aCross, 6U)) + 10026320559261334353U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11258082063135659551U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1445958517675746990U;
            aOrbiterB = RotL64((aOrbiterB * 10062265337488757971U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 1011298251290970844U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 6487834862470043744U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15477913837027179675U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9966279022928268335U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10285993486057704393U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 15965714363201157535U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16005362468813966136U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 223843444699390781U;
            aOrbiterJ = RotL64((aOrbiterJ * 665392038954573081U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 18178876294968532775U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12490136112181806806U;
            aOrbiterI = RotL64((aOrbiterI * 16380841616662993709U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 8775696166557913635U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16464340319444310842U;
            aOrbiterC = RotL64((aOrbiterC * 18111632334728200721U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 6296039992673546227U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7152939277656436037U;
            aOrbiterG = RotL64((aOrbiterG * 15183918431501487319U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 14066791413416223271U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 5026743227399908016U;
            aOrbiterA = RotL64((aOrbiterA * 5891343232759075675U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12923870516588764609U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2509970166609982397U;
            aOrbiterE = RotL64((aOrbiterE * 10708677957633925007U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 15155802288437422950U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 15615656627428205711U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6199439196177598589U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17233751123865498186U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3550722402315312207U;
            aOrbiterK = RotL64((aOrbiterK * 2247546626523919155U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 51U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 4U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + aPhaseEWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 58U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterF, 21U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 36U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aCross, 21U) + RotL64(aOrbiterB, 47U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 3U)) + aOrbiterA);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 40U) + RotL64(aOrbiterC, 39U)) + aOrbiterE) + RotL64(aCarry, 43U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterE, 5U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14171U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 12427U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15746U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14159U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 44U)) ^ (RotL64(aCarry, 13U) + RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aCross, 13U)) + 16651241552253078315U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 47U)) + 4558144676982478003U;
            aOrbiterH = (((aWandererI + RotL64(aScatter, 21U)) + 8814884320080367550U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 13U)) + 16011579668555672117U) + aPhaseEOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 5U)) + 4738918668759862438U) + aNonceWordP;
            aOrbiterK = (aWandererB + RotL64(aCross, 40U)) + 12526083125540985108U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 8048723561746000552U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 23U)) + 1082218464034639039U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 57U)) + 8432043246965946816U;
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 26U)) + 9982080524048636852U) + aNonceWordM;
            aOrbiterG = (aWandererK + RotL64(aIngress, 3U)) + 6720069955755215919U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1019035028070247757U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7360619079463870467U;
            aOrbiterH = RotL64((aOrbiterH * 6623074813047915863U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10893918488381348474U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1390297670907738019U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11909657437658597735U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12512200589031203480U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14741471280748399540U;
            aOrbiterD = RotL64((aOrbiterD * 3012135242889901095U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8543897248359826770U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8545972622733791272U;
            aOrbiterB = RotL64((aOrbiterB * 11793879362775346821U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7049384618581928664U) + aNonceWordA;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14730773807906925408U;
            aOrbiterF = RotL64((aOrbiterF * 10711566871536755073U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11480717275652449986U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1135397594974536859U;
            aOrbiterE = RotL64((aOrbiterE * 6347492892938856497U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6897207625849516702U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 10920630712550287148U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 4140705091806993359U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1094056478999931332U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 6784487144549717207U;
            aOrbiterI = RotL64((aOrbiterI * 6295177724167067891U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 2224992798329560875U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11486442570446223696U;
            aOrbiterA = RotL64((aOrbiterA * 5680065455032616591U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14681556190496625711U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1809388635055225841U;
            aOrbiterJ = RotL64((aOrbiterJ * 3449474313001177557U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 4480846057441948619U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16651241552253078315U;
            aOrbiterG = RotL64((aOrbiterG * 10628778876898064085U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 41U)) + aOrbiterJ) + aNonceWordH);
            aWandererD = aWandererD + (((RotL64(aCross, 10U) + aOrbiterI) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 19U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 10U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterA, 29U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 12U) + aOrbiterA) + RotL64(aOrbiterH, 51U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 44U)) + aOrbiterH) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17276U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 17693U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20314U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((aIndex + 17610U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 51U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 36U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 77518479758428414U;
            aOrbiterC = ((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 13U)) + 4832061802166300011U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 39U)) + 11695291171006574112U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 54U)) + 7467412817843260094U) + aNonceWordM;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 47U)) + 17801484124471154757U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 3U)) + 5555455638503958639U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 5U)) + 5669470540733721606U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 14U)) + 3042388456327784163U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 11U)) + 2236734925228156691U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + 14459720401528685450U) + aNonceWordK;
            aOrbiterD = ((aWandererG + RotL64(aCross, 37U)) + 4814967631216658856U) + aNonceWordN;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16950679344449075945U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6262238639302011050U;
            aOrbiterE = RotL64((aOrbiterE * 9942659897425088183U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 3522256359074996724U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12524717897707074242U;
            aOrbiterF = RotL64((aOrbiterF * 6787771338063891989U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 13891759914865623828U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 11910250571469028666U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12311343917878428995U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2240189915640314069U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 5365912986308810837U;
            aOrbiterH = RotL64((aOrbiterH * 15133972552032469957U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9323732721344489753U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13087326560957916553U;
            aOrbiterK = RotL64((aOrbiterK * 14659491687401151733U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 16398238057564892809U) + aNonceWordH;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11517870519285159224U;
            aOrbiterB = RotL64((aOrbiterB * 1501848878469712681U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7758285512254776734U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17475149091906684720U;
            aOrbiterI = RotL64((aOrbiterI * 6015816725428299273U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2051631493975035243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11684740065349595315U;
            aOrbiterD = RotL64((aOrbiterD * 10918975496337269197U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10575473798991451167U) + aNonceWordD;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8267005776169272822U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 13166868678285963961U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6249698995716039231U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13808085811784323978U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3897731011582061983U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2739364646624876985U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 77518479758428414U;
            aOrbiterG = RotL64((aOrbiterG * 6977724811175035551U), 41U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 24U);
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 35U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 51U)) + aOrbiterD);
            aWandererB = aWandererB + ((RotL64(aIngress, 58U) + RotL64(aOrbiterE, 43U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 14U)) + aOrbiterC) + aNonceWordF) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 39U)) + aOrbiterF) + RotL64(aCarry, 37U)) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterE, 53U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterE, 6U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterE, 11U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24958U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23541U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24443U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23244U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 57U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 42U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 53U)) + 6361545377408870615U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 11U)) + 2967245486744774933U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 6U)) + 3836634268482850139U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 7691642115360086297U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 41U)) + 16479280384178279281U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 29U)) + 2901468732552539249U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 13U)) + 2600353867755647475U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aWandererF + RotL64(aCross, 3U)) + 5666596904781510956U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 48U)) + RotL64(aCarry, 47U)) + 16108791609267427553U;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 57U)) + 8389926875737312112U) + aPhaseEOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 1689501721163024426U) + aNonceWordH;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11721701506949917719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3963842745030140473U;
            aOrbiterF = RotL64((aOrbiterF * 6692473494944919373U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 8510538243472109368U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 18281865214102080387U;
            aOrbiterK = RotL64((aOrbiterK * 1351546966368884609U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2259725140963665123U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11652011949557979650U;
            aOrbiterI = RotL64((aOrbiterI * 11260100762113295037U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1116085424226174473U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4725260319270802912U;
            aOrbiterA = RotL64((aOrbiterA * 4697109059565450269U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7348945429843437036U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 1249234309180653260U;
            aOrbiterD = RotL64((aOrbiterD * 3136745255820405881U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12463505532573389603U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2304125977906510386U;
            aOrbiterC = RotL64((aOrbiterC * 9960816714791454421U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2178037443783425551U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11712110130079307683U;
            aOrbiterG = RotL64((aOrbiterG * 9797864956200779505U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10703510612147312252U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18155460326242413483U;
            aOrbiterB = RotL64((aOrbiterB * 6903953708987478723U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5753486645345036069U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2314216774606770444U;
            aOrbiterE = RotL64((aOrbiterE * 14002639533287566667U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9662599462788305323U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 3805101172359199209U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10669315962181581543U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 1073926575064224947U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6361545377408870615U;
            aOrbiterJ = RotL64((aOrbiterJ * 10685650563722188837U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 51U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 37U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 14U) + RotL64(aOrbiterH, 10U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + aPhaseEWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 37U)) + aNonceWordO) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterA, 19U));
            aWandererA = aWandererA + (((RotL64(aCross, 24U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + aNonceWordP);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterE, 56U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30602U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((aIndex + 31707U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32636U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 31996U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 14U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aPrevious, 37U)) + 14157904117287696136U;
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 30U)) + 7369512677371640676U) + aNonceWordN;
            aOrbiterF = (((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 8411250745902073798U) + aPhaseEOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aScatter, 27U)) + 5002041814539710275U;
            aOrbiterD = (aWandererK + RotL64(aIngress, 5U)) + 9538041410816283124U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 10U)) + 5210700103927513061U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 23U)) + 7600709399101287982U) + aNonceWordO;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 13U)) + 2366369466696580499U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 5544575244203019109U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 19U)) + 8710073749110329779U) + aPhaseEOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 21U)) + 15998211310115361630U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15354357553877376422U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10657523549259276169U;
            aOrbiterF = RotL64((aOrbiterF * 13695239532898311073U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10405750198355464768U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3465819693133515142U;
            aOrbiterD = RotL64((aOrbiterD * 14678343718277562799U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16724189641701408630U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3484340153620198872U;
            aOrbiterI = RotL64((aOrbiterI * 17247547677520703125U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7420442404884871126U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11138445997256757636U;
            aOrbiterK = RotL64((aOrbiterK * 11167543379937571127U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1428191560884663125U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16950093140800653985U;
            aOrbiterA = RotL64((aOrbiterA * 4423012306984814805U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17288299075036481960U) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 13793597915359681028U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 9639204979982125757U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 5017972942710079726U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12409957957614320964U;
            aOrbiterH = RotL64((aOrbiterH * 10273295741911545745U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12487994181992095174U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 1573393166996612118U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13364311829104520751U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 13227642825780350128U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 7961292096150889569U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16627209081334341289U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10312485102088913337U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3177620041478410950U;
            aOrbiterJ = RotL64((aOrbiterJ * 15918551366833593853U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2599092792737616563U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 14157904117287696136U;
            aOrbiterC = RotL64((aOrbiterC * 14883446269291639813U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 12U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterF, 21U)) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 39U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterB, 34U)) + aNonceWordL);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterG);
            aWandererC = aWandererC + ((((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 41U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 19U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 48U)) + aOrbiterH);
            aWandererD = aWandererD ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 13U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterK, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
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

void TwistExpander_VolleyBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB12C36666E66FD6BULL + 0xC614A8B2DCC02B1CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xD7CA0161653E85CBULL + 0xB915707A25D9CDCFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x90638002C4A31045ULL + 0xC4FC5A9760F182ABULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x96DAB3AAA0719645ULL + 0xF460D4E56FD97EC1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xDB63DFA8D966FF29ULL + 0xFEB75A747A0B173DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9E1096B93EADF07BULL + 0x91965F1ABFCC4A21ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF56EF1C47FB12553ULL + 0xC73FB6DCF0FA5E3AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xABA7A07C31BE0315ULL + 0xFE47B7360F2DEF24ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xE900DAA57466316FULL + 0x98C3209AB05A96EAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8BABA7C6543ABA3FULL + 0x98A1B5CFF8AC511FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD7FE2F4B7B132F7BULL + 0x9BADD5D6F9D7698DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xD55966B52BDF20D3ULL + 0xA5082F619ADD7C21ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFD53D37BC489633BULL + 0xFE8193DCB8C16641ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x987ACCD1661BB24FULL + 0x8ECF5B96AFEAE8A9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xABE2A8D82AB1C629ULL + 0xF147589506477414ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE8A75C050043A7CDULL + 0x8B905C7A122D87EBULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4924U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 117U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2257U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 2512U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 28U) ^ RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 19U)) + 14499676118633326000U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 17191273593018552288U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 60U)) + 4085176294948097737U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 11112671474158908186U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 47U)) + 8745787969012266485U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 21U)) + 18074049663777707948U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 2543758649719164688U;
            aOrbiterI = (aWandererI + RotL64(aCross, 37U)) + 4659584749412700523U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 41U)) + 974639159259871273U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererE + RotL64(aCross, 34U)) + 9211220687971081987U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 51U)) + 8567024626862182714U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5803002132294840900U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11968489432878148467U;
            aOrbiterE = RotL64((aOrbiterE * 4501441062617123165U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9470807228394903442U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1692347973120388469U;
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 16510815732690193145U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 755159406833096510U;
            aOrbiterB = RotL64((aOrbiterB * 14091736464659561165U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1518824876475937620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 701225390867330446U;
            aOrbiterF = RotL64((aOrbiterF * 12264618860580199927U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8425976693733003889U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7182176375442410367U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 8860605703761731859U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4546566785167467924U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2593340999038753749U;
            aOrbiterH = RotL64((aOrbiterH * 10152461487764567563U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 9756331608356622299U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5511625814747641978U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4806076157539829529U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8694400787420160733U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12648969491371382682U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5346585704222643759U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 15261238546696118531U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14236129054778329471U;
            aOrbiterC = RotL64((aOrbiterC * 11789581469516267749U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16251500056378064213U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 790320176607605195U;
            aOrbiterI = RotL64((aOrbiterI * 15706130623435648555U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17114773669444878655U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14499676118633326000U;
            aOrbiterJ = RotL64((aOrbiterJ * 8095707555083587081U), 5U);
            //
            aIngress = RotL64(aOrbiterC, 46U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 37U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 10U) + aOrbiterJ) + RotL64(aOrbiterF, 44U)) + aPhaseFWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 29U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 5U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 39U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 47U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 5U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterI, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 52U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterC, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 58U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7740U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8147U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10772U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10293U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 21U)) ^ (RotL64(aIngress, 38U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 5U)) + 7960325128608297381U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 51U)) + 12773836012104052042U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 11U)) + 3173972621347773016U) + aPhaseFOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 47U)) + 3708401356314308171U;
            aOrbiterD = (aWandererB + RotL64(aCross, 3U)) + 950774285720019449U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 13U)) + 4170092315705438265U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 17000449130864980747U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 35U)) + 8793910540062893860U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 60U)) + 520277969543516469U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 23U)) + 12762214857389827271U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 2932451184340207695U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11062179998786293839U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7919119215271524178U;
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1774988449597115155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 3799792889466518953U;
            aOrbiterA = RotL64((aOrbiterA * 17512791286490623455U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1815062051307896589U) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15260373951371654483U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2208604434669491625U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12867546628945676853U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 7772820973895846946U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 7581704643538761985U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14213957831821966834U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 16561105721170419454U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2540533987337175367U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16556502948339949526U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9706742922075498974U;
            aOrbiterK = RotL64((aOrbiterK * 8527361328901355457U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13455756934917486016U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9107769876332723454U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1722386100852683783U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15793099079168487016U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7968278803691283365U;
            aOrbiterI = RotL64((aOrbiterI * 11644765391940099387U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15068302421261745111U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 11373111908765197862U;
            aOrbiterH = RotL64((aOrbiterH * 17756438368103196771U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 6362100123286229887U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 528778333872160609U;
            aOrbiterF = RotL64((aOrbiterF * 17377710146983314215U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6116442644744391285U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7960325128608297381U;
            aOrbiterB = RotL64((aOrbiterB * 17826511435509927061U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 43U);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterG, 20U));
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + RotL64(aOrbiterC, 5U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 52U) + RotL64(aOrbiterE, 11U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterH, 43U));
            aWandererB = aWandererB + ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 51U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 60U)) + aOrbiterK) + aNonceWordA) + aPhaseFWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterG, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererE, 30U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12993U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 13653U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11442U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 15840U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 56U)) + (RotL64(aCross, 19U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aScatter, 29U)) + 3248574644570178787U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 4506961512959200024U;
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 57U)) + 8423739774540738590U) + aNonceWordO;
            aOrbiterA = (aWandererG + RotL64(aCross, 44U)) + 6593975869641735337U;
            aOrbiterG = ((aWandererC + RotL64(aScatter, 19U)) + 16441716090557369103U) + aNonceWordD;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 39U)) + 7936601450453207914U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 47U)) + 13333752583560167065U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 41U)) + 8013703284795432973U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 35U)) + 2349852779887439236U) + aPhaseFOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aCross, 57U)) + 5318539364763284138U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 41U)) + 11450957608502944376U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9058992558327552687U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 632095686920230926U;
            aOrbiterJ = RotL64((aOrbiterJ * 12460364388358520799U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 14734218428913777098U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16344357661370784442U;
            aOrbiterE = RotL64((aOrbiterE * 15049472842002138369U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2981145363531184308U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14176472085175714494U;
            aOrbiterK = RotL64((aOrbiterK * 2584623327412130939U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 11198457590069700889U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 952584436750426828U;
            aOrbiterG = RotL64((aOrbiterG * 1165713888651280355U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4311591763498985972U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 16194341833989936369U;
            aOrbiterD = RotL64((aOrbiterD * 9997934560195932575U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 7560794022401107431U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 10683789740265711603U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 15637823045351977883U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 11614366395125937178U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10750771385100564416U;
            aOrbiterF = RotL64((aOrbiterF * 4987921274272444283U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 2934697034132204529U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4646873794658020363U;
            aOrbiterA = RotL64((aOrbiterA * 10555456865641580175U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 7913681837683568905U) + aNonceWordM;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 17603563535330106340U;
            aOrbiterH = RotL64((aOrbiterH * 17882943067522319671U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15375641415139193079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 17059712718085411887U;
            aOrbiterC = RotL64((aOrbiterC * 13722089235751208215U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14022558453716067200U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3248574644570178787U;
            aOrbiterB = RotL64((aOrbiterB * 15249135451439374621U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 5U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterI, 34U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 30U) + aOrbiterA) + RotL64(aOrbiterH, 27U));
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 41U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterE, 46U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterB, 13U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aNonceWordA);
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21522U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17096U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16577U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18695U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 27U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererA + RotL64(aPrevious, 44U)) + 3105313968748067810U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 35U)) + 9977249451119627064U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 21U)) + 17941392803495349366U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 53U)) + 4279533326705471133U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 6U)) + 13983828966811580039U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 13U)) + 3983490984234810378U) + aNonceWordG;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 308786542215259956U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 8443607695364427037U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 11U)) + 14939626441464340668U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 23U)) + 9350693577306121110U) + aPhaseFOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 53U)) + 1717071159396961752U) + aNonceWordE;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 15911765265202100610U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14898546272333182767U;
            aOrbiterA = RotL64((aOrbiterA * 2674900543810733067U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 3560903518513465868U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5367062725726860234U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8521908836601319553U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15233321480618877327U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 9288449812290126074U;
            aOrbiterC = RotL64((aOrbiterC * 6815298520404038519U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5504840529511585676U) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6825598386801620046U;
            aOrbiterJ = RotL64((aOrbiterJ * 11666542445846250077U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6433024450721339470U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 97934156644929458U;
            aOrbiterK = RotL64((aOrbiterK * 8630530773006923215U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3260053604798744515U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16539416623243059076U;
            aOrbiterD = RotL64((aOrbiterD * 12199577351166064503U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 9814290051339038920U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 13280156404507444041U;
            aOrbiterG = RotL64((aOrbiterG * 15269010043398910061U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 11853942590993546833U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13207869904312989977U;
            aOrbiterE = RotL64((aOrbiterE * 15503461937625795969U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14536032167989376750U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 3693282775047432356U;
            aOrbiterH = RotL64((aOrbiterH * 5290349323647887877U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5803176485246280271U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16702526675475954730U;
            aOrbiterB = RotL64((aOrbiterB * 13695676754973145769U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 16454171963808313625U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3105313968748067810U;
            aOrbiterF = RotL64((aOrbiterF * 16572687178789102843U), 21U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 48U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 26U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 60U)) + aOrbiterB) + aNonceWordB) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterD, 53U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 27U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 5U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aScatter, 54U) + aOrbiterJ) + RotL64(aOrbiterG, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 12U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 48U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 46U));
            aCarry = aCarry + RotL64(aWandererE, 21U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22217U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 25002U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26233U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 24987U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 4U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 28U)) + 15045917390223766480U) + aNonceWordK;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 10763054007033668758U) + aNonceWordP;
            aOrbiterC = ((aWandererK + RotL64(aCross, 43U)) + 13190170142593666607U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 11U)) + 9657025731441167065U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 13U)) + 11433367178975954211U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 5U)) + 17904920143996810366U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 23U)) + 3244383020512113283U;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 3U)) + 6538815775171139091U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 46U)) + RotL64(aCarry, 13U)) + 7195368312757976343U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 18134430713910279374U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 57U)) + 6571776588427107976U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 11830778129647517758U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 9793702760907767365U;
            aOrbiterC = RotL64((aOrbiterC * 4096246227968677179U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2287235876793192036U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8951959188326141794U;
            aOrbiterI = RotL64((aOrbiterI * 9968356718110753845U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7583061790273240157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3571364625022806085U;
            aOrbiterJ = RotL64((aOrbiterJ * 6238360922735480669U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13869345563551689212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 277480328952975002U;
            aOrbiterA = RotL64((aOrbiterA * 1057564597096163085U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 4983735092494677578U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9490022869381030928U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12926352917961703123U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7928039573014765566U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6504190875809407084U;
            aOrbiterG = RotL64((aOrbiterG * 14648214826494826711U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2787985600176307413U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16308785053443116826U;
            aOrbiterH = RotL64((aOrbiterH * 17867565986311256691U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12788128335006767824U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1187040019537798339U;
            aOrbiterF = RotL64((aOrbiterF * 10834905007658184183U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10771230162770496645U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6542421559654716320U;
            aOrbiterD = RotL64((aOrbiterD * 16829492790597069373U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 702458690970201679U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2806140783487813070U;
            aOrbiterB = RotL64((aOrbiterB * 7415398198842270381U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 950611302199732036U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 15045917390223766480U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 9358017420417979347U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 12U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + aPhaseFWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 46U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aNonceWordB);
            aWandererJ = aWandererJ + ((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterF, 26U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 37U)) + aNonceWordA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterI, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 53U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 30U)) + aNonceWordH);
            aWandererD = aWandererD + ((RotL64(aScatter, 37U) + RotL64(aOrbiterK, 51U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aCross, 34U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 52U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererC, 10U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31938U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30168U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28152U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((aIndex + 32053U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 18U)) + 14624277139785904404U;
            aOrbiterH = (aWandererA + RotL64(aScatter, 51U)) + 6966977309498165611U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 205536824352530761U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 29U)) + 16629575265808255692U) + aNonceWordI;
            aOrbiterC = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 596881340147972746U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 21U)) + 11944412799107412650U) + aNonceWordP;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 10U)) + RotL64(aCarry, 23U)) + 4615021315668210206U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 13U)) + 8497630055977606216U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 5U)) + 11131601107309336885U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 37U)) + 5935883479805510099U) + aPhaseFOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 41U)) + 15629346719765798174U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 5279128339113651273U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16778365912440331821U;
            aOrbiterF = RotL64((aOrbiterF * 705421028266789241U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 16003052937645491524U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6723226158737614764U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 16690657664909260573U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 9785784358981219543U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 10055457337292292710U) ^ aNonceWordJ;
            aOrbiterJ = RotL64((aOrbiterJ * 17919129940751761111U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 11779163108592974175U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1177999477942202687U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13475069421684114643U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9190694445141492214U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15605342360346353457U;
            aOrbiterA = RotL64((aOrbiterA * 14547769706392595647U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 14877565450677523492U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1074095623308025684U;
            aOrbiterD = RotL64((aOrbiterD * 7884068939436891093U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12803174154216941583U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 8813356463693637033U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 4898237214617563167U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6063909634038581414U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15112191502834052566U;
            aOrbiterE = RotL64((aOrbiterE * 6780741782103553485U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13926459034757240311U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4324555954703597591U;
            aOrbiterG = RotL64((aOrbiterG * 18068922072149745351U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 7183063131331255506U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18072787091203847052U;
            aOrbiterH = RotL64((aOrbiterH * 12530396154012878153U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10143386327707219710U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14624277139785904404U;
            aOrbiterI = RotL64((aOrbiterI * 12100828883424264587U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 34U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 50U)) + aOrbiterG) + aNonceWordO);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 41U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 37U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 21U)) + aOrbiterC);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterC, 10U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterB, 27U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_VolleyBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xA6C5866023DF3FFBULL + 0xF48C6DF6D952693DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD117FC8E674A72B7ULL + 0xF5EBE24FB042BB2DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAD895A46A750646FULL + 0xE0368691EED1DF51ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8A8C6D13024C32B7ULL + 0xA8E3126B474774ACULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE9C6460DA75B5A57ULL + 0xE947538F0F95714DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC379E97AD8CE8767ULL + 0xC35F77C7EE60A16AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9BA8E1E341037823ULL + 0xF9129923F57B02E6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCDF10344D1CB7A1FULL + 0xC80454D77C93C73EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA64AB1C856EBBE2BULL + 0xB5CEBC91DB946C21ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC5B5FA5F3541BEA9ULL + 0xE968CAFD033E4BD5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8319B52B325B98CFULL + 0xC747129E4D25E227ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x878AF8DBF8B5A581ULL + 0x881E674FBEF83D01ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD8AC2BA98EF6E87FULL + 0xE8676E91371BF2F8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF08B0E836EFEBFBDULL + 0xB04F53D6ACFD6AFBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB3279722C4B1C1D3ULL + 0xFAAF6BC75D0E008EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFD2D9477167F25CDULL + 0x904CB2425E206C29ULL);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4656U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3550U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2661U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3455U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 44U) ^ RotL64(aIngress, 13U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 11U)) + 6163290588946759209U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 29U)) + 7342672468560105447U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 13U)) + 11574563167017282321U;
            aOrbiterG = (aWandererC + RotL64(aCross, 35U)) + 2254820206194758964U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 60U)) + 1469783447473099498U;
            aOrbiterE = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 14174828900676165088U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 35U)) + 16277954291890598132U;
            aOrbiterC = (((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 14845750668693136766U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (((aWandererG + RotL64(aCross, 43U)) + 150099699692047766U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 39U)) + 1200784917165131703U) + aNonceWordD;
            aOrbiterD = (aWandererK + RotL64(aScatter, 50U)) + 9469982764806754302U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10956702761701710182U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 7915506894975487807U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 8874108311712727983U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 17335794183733623213U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 557028996286989506U;
            aOrbiterE = RotL64((aOrbiterE * 3993359298602424281U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1597385667771002414U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 4376417959915162639U;
            aOrbiterJ = RotL64((aOrbiterJ * 4626236858205178149U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 549770198518993876U) + aNonceWordO;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 756554555648070919U;
            aOrbiterG = RotL64((aOrbiterG * 16272320259614325355U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 7298557532533152193U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3336802611342112013U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14679103452120080499U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 2314938232094714365U) + aNonceWordK;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 12215066333571149153U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10747052773052630601U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7762752719356805046U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6519429915769040078U;
            aOrbiterD = RotL64((aOrbiterD * 15548676502167938513U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7556691736109752918U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13731245903412646404U;
            aOrbiterB = RotL64((aOrbiterB * 15581965016668635409U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5910925625723735162U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16037704866415841869U;
            aOrbiterI = RotL64((aOrbiterI * 11628217027073824759U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12605882248192797360U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9579778913978981884U;
            aOrbiterC = RotL64((aOrbiterC * 5372577227818787957U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 6063171520266734946U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6163290588946759209U;
            aOrbiterK = RotL64((aOrbiterK * 291843698316138251U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 29U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterA, 24U));
            aWandererA = aWandererA + (((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterB, 51U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 43U)) + aOrbiterG) + aPhaseFWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterD, 5U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterG, 58U));
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 48U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererI, 54U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6121U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneD[((aIndex + 9297U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8321U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 5940U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 60U)) + (RotL64(aCross, 41U) ^ RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aCross, 46U)) + 4773124477323378268U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 43U)) + 16848723289435796005U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 41U)) + 13846642134917107058U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 53U)) + 6472057872482789939U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 35U)) + 2747019500690707226U) + aNonceWordB;
            aOrbiterA = ((((aWandererA + RotL64(aCross, 22U)) + RotL64(aCarry, 47U)) + 9003965289739733880U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 11U)) + 3013390651936257377U;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 29U)) + 3331004709895625067U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aScatter, 37U)) + 15355010435553517129U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 7709870658004280052U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 27U)) + RotL64(aCarry, 37U)) + 13568728443963926564U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12409548853419307131U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 969183352023661537U;
            aOrbiterH = RotL64((aOrbiterH * 5549220554838837145U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15370309834426476775U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 3896803894396631184U;
            aOrbiterG = RotL64((aOrbiterG * 11018830202891911603U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10848873633291935766U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 12885336509190543440U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1487357252619221365U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8252290890093788010U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 9201553615601641350U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 420321130559162915U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14014209645503188472U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4015071464301844550U;
            aOrbiterB = RotL64((aOrbiterB * 17444195018239904971U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16173085647514027347U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16916627014974363360U;
            aOrbiterE = RotL64((aOrbiterE * 7699587344277490953U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1591680303404522110U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16499606051269327916U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 814405848002794813U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 6932673635509444619U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8745681160108707944U;
            aOrbiterA = RotL64((aOrbiterA * 14565255558668084787U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 10387263947888920455U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2553335462317280031U;
            aOrbiterD = RotL64((aOrbiterD * 7253573275397985211U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17449861295444216249U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15716408844914738774U;
            aOrbiterF = RotL64((aOrbiterF * 10132631423215542589U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16974370193820578179U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 4773124477323378268U;
            aOrbiterK = RotL64((aOrbiterK * 8982190762960590543U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 58U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 27U)) + aOrbiterE) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterD, 53U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterG) + RotL64(aOrbiterD, 3U)) + aPhaseFWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterC, 18U)) + aNonceWordH);
            aWandererF = aWandererF ^ (((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterI, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterC, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterH, 23U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 24U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + aNonceWordP);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 6U));
            aCarry = aCarry + RotL64(aWandererD, 37U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12478U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12020U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15221U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12525U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 27U) ^ RotL64(aCarry, 54U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 18144572925667544139U) + aNonceWordH;
            aOrbiterK = (aWandererB + RotL64(aScatter, 29U)) + 5659758077574059728U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 3U)) + 6343330616999166392U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 6U)) + RotL64(aCarry, 5U)) + 17754639838410839447U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 57U)) + 9451843819849581729U) + aNonceWordF;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 51U)) + 7957854457197462212U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 21U)) + 1461994799722205010U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aScatter, 10U)) + 18002214276252170177U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + 14689869073147027164U) + aNonceWordC;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 3978104368003440293U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 47U)) + 8512135845221335386U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1477533446382953439U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2166717790929947990U;
            aOrbiterG = RotL64((aOrbiterG * 6538884492418324461U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8082437060686606995U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4363687722464700362U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7199165810993478887U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15782763348014924206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8572509150015960728U;
            aOrbiterK = RotL64((aOrbiterK * 3340528604891897779U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12248271773316742521U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9602078627638561949U;
            aOrbiterD = RotL64((aOrbiterD * 1860631869877427405U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17244849374768558859U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1030743048280579012U;
            aOrbiterF = RotL64((aOrbiterF * 10858949914285817051U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 17722342363541914280U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15667504059789880034U;
            aOrbiterI = RotL64((aOrbiterI * 15872269872168533709U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 12645332941998550794U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9938135244509986497U;
            aOrbiterE = RotL64((aOrbiterE * 16548185968987392957U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4024609904162105979U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6732064218696157303U;
            aOrbiterC = RotL64((aOrbiterC * 3815409766145891393U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14314117137220703583U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 15244765904057473814U;
            aOrbiterJ = RotL64((aOrbiterJ * 4034571710808047959U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 17441241682018169245U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11958974379114644873U;
            aOrbiterH = RotL64((aOrbiterH * 11315689206845170303U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8310839846793796473U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 18144572925667544139U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 11668203295511168011U), 3U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 19U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterG, 21U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 24U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererI = aWandererI + (((RotL64(aScatter, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterJ) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterB, 19U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + aPhaseFWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 53U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 26U) + aOrbiterI) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 38U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ aNonceWordI;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19440U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((aIndex + 16982U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18237U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18466U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 19U)) + (RotL64(aCross, 54U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 3236820517816085022U;
            aOrbiterB = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 741288875914097926U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 21U)) + 8417246926007729580U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 3U)) + 9715717805774537170U;
            aOrbiterC = (aWandererB + RotL64(aCross, 29U)) + 14360243844821619482U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 57U)) + 10760908100206775334U) + aNonceWordM;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 53U)) + 3434641779946167811U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 50U)) + 7885568822756234567U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 43U)) + 3041563437672051294U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 15761355327564963516U;
            aOrbiterH = (aWandererC + RotL64(aCross, 13U)) + 1158633562785937421U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9338581575871970653U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 9172038894262857354U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3110871165285625807U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14653924713599790081U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3854497592598563309U;
            aOrbiterC = RotL64((aOrbiterC * 11737111068815795303U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16286980180327600557U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5092583772591249756U;
            aOrbiterI = RotL64((aOrbiterI * 13955105624639442903U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4288397994175567333U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 15584236478994873104U;
            aOrbiterF = RotL64((aOrbiterF * 1860480595862755379U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5557463939827483792U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 2659814275753280856U;
            aOrbiterJ = RotL64((aOrbiterJ * 17702430405693184643U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6941807963525063449U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2040598555191211307U;
            aOrbiterA = RotL64((aOrbiterA * 14750544987531722765U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 347572666231116258U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 779304821185302523U;
            aOrbiterD = RotL64((aOrbiterD * 14180254150318109855U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 10632524582873079742U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9761308771280517212U;
            aOrbiterH = RotL64((aOrbiterH * 13926235411726048921U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2097439707055737964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2813977930321463948U;
            aOrbiterK = RotL64((aOrbiterK * 14983538728730662603U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6080592019313796689U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 5396623654821376409U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 15478858835919398677U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 8460497459575045342U) + aNonceWordA;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 3236820517816085022U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5530411244458067093U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 56U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterD, 37U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterC, 60U));
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + aOrbiterH) + RotL64(aOrbiterJ, 19U));
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 47U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterB, 5U));
            aWandererG = aWandererG + ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterA, 44U)) + aOrbiterJ) + RotL64(aCarry, 41U)) + aNonceWordF);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterF, 41U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 51U)) + aOrbiterE) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22596U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 23635U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26668U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((aIndex + 27013U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCross, 51U)) ^ (RotL64(aCarry, 23U) + RotL64(aPrevious, 10U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 27U)) + 7960325128608297381U) + aNonceWordM;
            aOrbiterA = (aWandererJ + RotL64(aCross, 23U)) + 12773836012104052042U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 27U)) + 3173972621347773016U;
            aOrbiterD = (aWandererI + RotL64(aIngress, 47U)) + 3708401356314308171U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 34U)) + RotL64(aCarry, 11U)) + 950774285720019449U) + aNonceWordH;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 11U)) + 4170092315705438265U) + aPhaseFOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 29U)) + 17000449130864980747U;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 8793910540062893860U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 21U)) + 520277969543516469U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 41U)) + 12762214857389827271U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 54U)) + 2932451184340207695U) + aNonceWordC;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 11062179998786293839U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 7919119215271524178U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 9053677007180081359U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1774988449597115155U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 3799792889466518953U;
            aOrbiterG = RotL64((aOrbiterG * 17512791286490623455U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1815062051307896589U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15260373951371654483U;
            aOrbiterE = RotL64((aOrbiterE * 2208604434669491625U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12867546628945676853U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7772820973895846946U;
            aOrbiterB = RotL64((aOrbiterB * 7581704643538761985U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14213957831821966834U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 16561105721170419454U;
            aOrbiterJ = RotL64((aOrbiterJ * 2540533987337175367U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16556502948339949526U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9706742922075498974U;
            aOrbiterD = RotL64((aOrbiterD * 8527361328901355457U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13455756934917486016U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9107769876332723454U;
            aOrbiterH = RotL64((aOrbiterH * 1722386100852683783U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15793099079168487016U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7968278803691283365U;
            aOrbiterI = RotL64((aOrbiterI * 11644765391940099387U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15068302421261745111U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11373111908765197862U;
            aOrbiterF = RotL64((aOrbiterF * 17756438368103196771U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6362100123286229887U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 528778333872160609U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17377710146983314215U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6116442644744391285U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 7960325128608297381U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17826511435509927061U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 10U));
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 44U) + aOrbiterA) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 23U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 41U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 56U)) + aOrbiterK);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 53U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 35U)) + aOrbiterD) + aNonceWordN);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + RotL64(aOrbiterJ, 4U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aNonceWordF) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29734U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31750U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29467U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 30979U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 26U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 35U)) + 3561491146322798260U;
            aOrbiterD = (aWandererC + RotL64(aCross, 40U)) + 7075025056181885339U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 9230910887904171613U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 19U)) + 4119781172609908917U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 17155609083870983149U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 27U)) + 2423018561430181695U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 44U)) + 12957280305617615744U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 2461704174772065813U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 11U)) + 7907123257849391997U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 23U)) + 7257868138318960007U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 47U)) + 16425903703085702285U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2990822664594079467U) + aNonceWordN;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5654819006718953817U;
            aOrbiterJ = RotL64((aOrbiterJ * 4465096036756887801U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12183676471235678779U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15026286960542123922U;
            aOrbiterC = RotL64((aOrbiterC * 17199049329995315279U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12169080607071830522U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2906296852254787499U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 6754514406846040163U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3029858695410344584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14406410317495954566U;
            aOrbiterI = RotL64((aOrbiterI * 9663780721657983421U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11048818178401163861U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13622063920319445043U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2516025554421589857U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2642646089141233277U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12761571777929273548U;
            aOrbiterE = RotL64((aOrbiterE * 5518252696078700127U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7753802695131502382U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8510425459525030222U;
            aOrbiterG = RotL64((aOrbiterG * 12412361423636026483U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13522645164493316722U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 1437430302489702713U;
            aOrbiterB = RotL64((aOrbiterB * 14019316635365783545U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14745189473423751499U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 16968328257002103715U;
            aOrbiterH = RotL64((aOrbiterH * 17915588590593471981U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 5001838243344386314U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13506188720092630563U;
            aOrbiterD = RotL64((aOrbiterD * 7010027510838271877U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16902624500530747723U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3561491146322798260U;
            aOrbiterA = RotL64((aOrbiterA * 95761172090277669U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 46U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterI, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterE, 26U));
            aWandererC = aWandererC + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererG = aWandererG + ((((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aNonceWordL) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterG, 41U));
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 58U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aCross, 44U) + aOrbiterJ) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterB, 23U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordA);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_VolleyBall_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4932U)) & S_BLOCK1], 41U) ^ RotL64(aKeyRowReadA[((aIndex + 1137U)) & W_KEY1], 20U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 5323U)) & W_KEY1], 28U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2934U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 27U)) ^ (RotL64(aCarry, 12U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 18U)) + RotL64(aCarry, 27U)) + 13687218104610230596U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 51U)) + 6841550124960692709U) + aPhaseCOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 47U)) + 17418968668458764131U;
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 8303537912696948204U) + aPhaseCOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 12376614417285936537U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 57U)) + 14215749063579232654U;
            aOrbiterF = (aWandererB + RotL64(aCross, 28U)) + 4111736931433665347U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 41U)) + 11250375934571631522U;
            aOrbiterD = (aWandererH + RotL64(aCross, 23U)) + 5367367837773331275U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15514089192382674434U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1475991716685034960U;
            aOrbiterB = RotL64((aOrbiterB * 17720681295551650891U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5531622777788629748U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 8363822215908303335U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17850203366840994883U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 3741256932685720414U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11634667238062155772U;
            aOrbiterK = RotL64((aOrbiterK * 15925089729784547403U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 18180546911210417155U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5123234656838556335U;
            aOrbiterD = RotL64((aOrbiterD * 15362857462853398025U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11215734271189250284U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16863747802158398092U;
            aOrbiterC = RotL64((aOrbiterC * 1828035970246160023U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9859050606636646323U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9331300036643654675U;
            aOrbiterE = RotL64((aOrbiterE * 2502263410556166281U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15028845665427209759U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8916444839488901676U;
            aOrbiterF = RotL64((aOrbiterF * 6646561894156038791U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8024631140949068570U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1116378858490660031U;
            aOrbiterA = RotL64((aOrbiterA * 4247798531910227367U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5066486214537899212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9346312092322423057U;
            aOrbiterH = RotL64((aOrbiterH * 13443190089768875191U), 51U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 40U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterF, 39U)) + aPhaseCWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 47U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterI, 27U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterI, 58U));
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 4U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 28U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 11945U)) & S_BLOCK1], 20U) ^ RotL64(mSource[((aIndex + 10242U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10262U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[((aIndex + 14066U)) & W_KEY1], 44U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 27U)) ^ (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 12027839670755583592U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 14U)) + 15380130703509859843U;
            aOrbiterK = (aWandererK + RotL64(aCross, 39U)) + 4590907433867798074U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 53U)) + 1754574023602519724U) + aPhaseCOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererG + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 9832756659564903767U) + aPhaseCOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 57U)) + 5035088494491470403U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 18U)) + RotL64(aCarry, 5U)) + 14199170923323644638U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 23U)) + 8325619421264440438U;
            aOrbiterB = (aWandererI + RotL64(aCross, 35U)) + 969534320779067977U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 270575869402913847U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13344806516599578910U;
            aOrbiterK = RotL64((aOrbiterK * 10193544126281901579U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15143147951139409101U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14425582489214169238U;
            aOrbiterG = RotL64((aOrbiterG * 16893787086337916355U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13951127523239064584U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 14177925225918293579U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13079514031864998485U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8258920744278218901U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 7408161179397242453U;
            aOrbiterE = RotL64((aOrbiterE * 975737128100519169U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8581481606764773468U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10078416198417433133U;
            aOrbiterB = RotL64((aOrbiterB * 1102721083915858247U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 18299772198826189580U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 18304668908084397946U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10589455451200578687U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 16729632621573817223U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13362300981585573239U;
            aOrbiterC = RotL64((aOrbiterC * 9824473895535518785U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8629682832849915380U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 6852852009091469641U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11912646687050011915U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7433098156961745198U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10931806208899417308U;
            aOrbiterD = RotL64((aOrbiterD * 14699197041038067483U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 53U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 48U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aIngress, 60U) + aOrbiterE) + RotL64(aOrbiterA, 3U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 20U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 12U) + RotL64(aOrbiterD, 60U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 39U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterG, 51U)) + aPhaseCWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 20331U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 22235U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19714U)) & W_KEY1], 56U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 23899U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 30U)) + 14008824488073394623U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 57U)) + 13317978415866411468U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 47U)) + 13209180141897453900U) + aPhaseCOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 19U)) + 11870521586865233578U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 11U)) + RotL64(aCarry, 11U)) + 8052156380448047385U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 43U)) + 12158131176743680605U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 23U)) + 14674467487607719347U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 18055496790566231147U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 52U)) + RotL64(aCarry, 43U)) + 3838105585041578784U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2839568255183054418U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 11933612922864258179U;
            aOrbiterF = RotL64((aOrbiterF * 7571964469321160347U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6289849094151630580U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 2640344350528492271U;
            aOrbiterG = RotL64((aOrbiterG * 16197726750829369365U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16306175266267657791U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3339898380394883600U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15017076663742800002U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8973064296077602496U;
            aOrbiterJ = RotL64((aOrbiterJ * 9309462227233615761U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17580319233338139859U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14063208878807603874U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16601475239075164585U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 13326130855721009942U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12843186026737544416U;
            aOrbiterD = RotL64((aOrbiterD * 4975848122837321619U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14102887715772847499U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14495942314329085733U;
            aOrbiterE = RotL64((aOrbiterE * 4236795312917583565U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 11564857125101669667U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 17435970784822000464U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1472691848852381173U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16561390130356833062U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 9952805588514363872U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3720874990001086597U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 27U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterG, 19U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterI, 52U)) + aOrbiterH) + aPhaseCWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterK, 23U));
            aWandererK = aWandererK + ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 3U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 56U)) + aOrbiterJ) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 11U)) + aOrbiterH) + aPhaseCWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererK, 38U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31544U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((aIndex + 28889U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29592U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 27987U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCarry, 27U)) ^ (RotL64(aIngress, 57U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 13333509828310369865U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aCross, 23U)) + 7645352517103840797U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 39U)) + 5310766306660062655U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 5165635069832352932U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 18U)) + 15684141764734281849U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 43U)) + 3327963374225061738U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 8625811794878848871U;
            aOrbiterH = (aWandererD + RotL64(aCross, 13U)) + 7598657468430485291U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 30U)) + 2881171216276746485U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 10237691227222918101U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6419254255884834497U;
            aOrbiterK = RotL64((aOrbiterK * 3816625473642865305U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 4238455444646479956U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14936613353493061492U;
            aOrbiterG = RotL64((aOrbiterG * 3544216916806292273U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 15324699725208372627U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9506640480601832011U;
            aOrbiterA = RotL64((aOrbiterA * 12819564111348390227U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3709149613660215641U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1724290199312754307U;
            aOrbiterE = RotL64((aOrbiterE * 12597580418257897965U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13191172833570139194U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3686087945377837886U;
            aOrbiterC = RotL64((aOrbiterC * 10883609557429936283U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 10418330386245397022U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5383531313632347245U;
            aOrbiterB = RotL64((aOrbiterB * 2987755379396160073U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7414716553072652212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 11301761123966206201U;
            aOrbiterH = RotL64((aOrbiterH * 1546727321088592187U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8570229732236388847U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 8773754460060264773U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3251360788932563495U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13636929800504199371U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5486599841558573720U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2867914211589815153U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 30U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterB, 36U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aPrevious, 44U) + RotL64(aOrbiterH, 23U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterB, 53U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterF, 43U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 14U)) + aOrbiterG) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_VolleyBall_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4719U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5322U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1531U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 1357U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 20U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 12029393034357490020U;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 27U)) + 4526754731580694987U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 17060419646421271853U;
            aOrbiterK = (aWandererB + RotL64(aCross, 30U)) + 4128488893837059683U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 19U)) + 12706894827547160110U) + aPhaseDOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12506324593645825056U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12581344490649250025U;
            aOrbiterA = RotL64((aOrbiterA * 16311882267466003291U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14357032418199130132U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15341977701796331249U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6332369248718076031U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7086602307544733241U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 12398300065276832486U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18157408831225635333U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2499745046076601988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7249361592814001829U;
            aOrbiterI = RotL64((aOrbiterI * 14597139848072319685U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3254456186337366437U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3472973415969046680U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14583566953969168353U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterI, 52U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE + ((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterD, 35U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterD, 23U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15780U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 15259U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9038U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((aIndex + 14935U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 19U)) + 1297415699043177788U) + aPhaseDOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 37U)) + 17583786534509260153U;
            aOrbiterE = (((aWandererD + RotL64(aScatter, 50U)) + RotL64(aCarry, 53U)) + 643197858925708798U) + aPhaseDOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 29U)) + 5062653766915694874U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 41U)) + 7034273638367180511U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 2026909726972916996U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 2785690475553211646U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6612792037861160393U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2910341716302991892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2834181605200829791U;
            aOrbiterD = RotL64((aOrbiterD * 1510617068750957651U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13323052600571281928U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10434901530315760460U;
            aOrbiterG = RotL64((aOrbiterG * 2042210188346767033U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 247903955625194782U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5196515747387257163U;
            aOrbiterC = RotL64((aOrbiterC * 1799024689023272275U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 7196305682377987476U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14777739876892587484U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 95220583948241581U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 22U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 3U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aCross, 37U) + RotL64(aOrbiterD, 22U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterE, 37U)) + aOrbiterD) + aPhaseDWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterF, 11U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 22504U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24226U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21718U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21679U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 12U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aScatter, 13U)) + 14179205183062705133U) + aPhaseDOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 210032324058740920U) + aPhaseDOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 7387115089142500152U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 17583362781238061430U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 34U)) + 4991442849150005943U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2891376254689854555U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 10523274382407446239U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17443994099359920915U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3861893764676218667U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 3366674459852093746U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14005994095369483813U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5898492634386601145U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7047353571244768721U;
            aOrbiterD = RotL64((aOrbiterD * 2257518291062508467U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14374108805453186316U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 8763667021501226510U;
            aOrbiterJ = RotL64((aOrbiterJ * 7694695426430267863U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18261523829316379575U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 650477532238860965U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8291758490821819851U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 3U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererK = aWandererK + ((((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 44U)) + aOrbiterE) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 57U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 46U));
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30759U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30538U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31896U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32403U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 60U) ^ RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 47U)) + 3550722402315312207U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 16724184551669522754U) + aPhaseDOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aCross, 19U)) + 981751330116773021U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 7891159229704944868U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 56U)) + RotL64(aCarry, 39U)) + 13618396711464799841U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5969291018449003648U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14595540413313640042U;
            aOrbiterF = RotL64((aOrbiterF * 8151104319012840963U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 3287990436916111762U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 12534369400200483704U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2345945228434740707U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2277312067930392274U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 10026320559261334353U;
            aOrbiterE = RotL64((aOrbiterE * 11020464940995912637U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 11258082063135659551U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 1445958517675746990U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10062265337488757971U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 1011298251290970844U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6487834862470043744U;
            aOrbiterC = RotL64((aOrbiterC * 15477913837027179675U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterE, 11U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 57U)) + aOrbiterE);
            aWandererK = aWandererK + ((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 48U)) + aOrbiterA) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterH, 39U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + RotL64(aWandererG, 40U);
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

void TwistExpander_VolleyBall_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2998U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 477U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6218U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 2942U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 35U)) ^ (RotL64(aCarry, 48U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 10404808878585437255U) + aPhaseEOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 11U)) + 10587858736301591439U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 19U)) + 1430530909801644435U;
            aOrbiterA = (aWandererA + RotL64(aCross, 27U)) + 9090938022430118902U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 53U)) + 12936604311751121235U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 3U)) + 1000583006020232032U;
            aOrbiterI = (aWandererD + RotL64(aCross, 57U)) + 12352532088997042232U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16723410947058502564U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16614089235313154270U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11530998303573027827U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4245553025593349277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 3353146318549477494U;
            aOrbiterG = RotL64((aOrbiterG * 14246377408238318091U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5935727336135635196U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10312187090293319667U;
            aOrbiterJ = RotL64((aOrbiterJ * 1395964500396711899U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12192843181244744484U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 2542570124502586365U;
            aOrbiterI = RotL64((aOrbiterI * 17222847847573534963U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3315472769469002444U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17512858811783071174U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9070400454074283765U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16633218007427888082U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 2502077714838858460U;
            aOrbiterA = RotL64((aOrbiterA * 970762420815997725U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 14792910273226469214U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15739513291150783151U;
            aOrbiterB = RotL64((aOrbiterB * 11896279674116906915U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 41U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 46U) + aOrbiterJ) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterG, 50U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterI, 29U)) + aOrbiterA);
            aWandererF = aWandererF + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererF, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 4U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12915U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 13822U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14220U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneB[((aIndex + 15409U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = (aWandererH + RotL64(aPrevious, 13U)) + 9471546960258473684U;
            aOrbiterG = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 21U)) + 18050235435948942244U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 3005107102671544641U;
            aOrbiterA = (aWandererF + RotL64(aCross, 30U)) + 17898396434573801850U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 47U)) + 15071602525497771648U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 5780119462702672108U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 53U)) + 13301326224151025687U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 18129323022260575961U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 1199228670638790709U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1780426336211781025U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1839199978088021020U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 4999517042246790165U;
            aOrbiterI = RotL64((aOrbiterI * 4585813675677234577U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8788607633376516299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15143903839930468749U;
            aOrbiterA = RotL64((aOrbiterA * 12735914889325422675U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16674732686428431869U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15908873150953195581U;
            aOrbiterG = RotL64((aOrbiterG * 18049755517524334107U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11204775359756474667U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2525984309543939465U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3988529812023791571U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4566345170476825512U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 14876612901557406267U;
            aOrbiterE = RotL64((aOrbiterE * 9047956948845135339U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14926290877038883931U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12710203178186614846U;
            aOrbiterH = RotL64((aOrbiterH * 14841163494801662515U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 60U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE + (((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterI, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 41U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 50U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 21U)) + aOrbiterI) + aPhaseEWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23507U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20155U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22711U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18689U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 44U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 18144572925667544139U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 5659758077574059728U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 10U)) + 6343330616999166392U) + aPhaseEOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 17754639838410839447U;
            aOrbiterD = (aWandererC + RotL64(aCross, 57U)) + 9451843819849581729U;
            aOrbiterF = (aWandererK + RotL64(aIngress, 19U)) + 7957854457197462212U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 27U)) + 1461994799722205010U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18002214276252170177U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14689869073147027164U;
            aOrbiterI = RotL64((aOrbiterI * 12242482963989582191U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 3978104368003440293U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 8512135845221335386U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10506667163729414667U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 1477533446382953439U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2166717790929947990U;
            aOrbiterH = RotL64((aOrbiterH * 6538884492418324461U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8082437060686606995U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4363687722464700362U;
            aOrbiterG = RotL64((aOrbiterG * 7199165810993478887U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 15782763348014924206U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8572509150015960728U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3340528604891897779U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12248271773316742521U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9602078627638561949U;
            aOrbiterF = RotL64((aOrbiterF * 1860631869877427405U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 17244849374768558859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 1030743048280579012U;
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 54U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterA);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 27U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 56U) + aOrbiterK) + RotL64(aOrbiterH, 44U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27729U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 26223U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30746U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((aIndex + 29558U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 12U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererG + RotL64(aPrevious, 12U)) + 7896237440058555694U;
            aOrbiterE = ((aWandererC + RotL64(aCross, 29U)) + 11870529476037558635U) + aPhaseEOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 9158983227801569448U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 4710172270996950329U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 5U)) + 14634482800356647630U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 8822207952170610891U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aIngress, 47U)) + 13755891414028982553U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4555293067488040719U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 2816805148093762081U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16838149138341713943U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2122631477965135190U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 4592922416380416071U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11644507904538573165U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7102471666524164715U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17274623547879474204U;
            aOrbiterE = RotL64((aOrbiterE * 5443572270546181789U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 938587316977094680U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 18258015823797023523U;
            aOrbiterK = RotL64((aOrbiterK * 6068819567674605919U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5809987756043471595U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5083075160112581620U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3313957222154937503U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 5960021727750946496U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5967477320950630150U;
            aOrbiterC = RotL64((aOrbiterC * 330964768256424655U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6578428711689296132U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 5601728218197771276U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9552559022315971847U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterD, 37U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 4U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterC, 57U)) + aPhaseEWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 35U);
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

void TwistExpander_VolleyBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5363U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((aIndex + 6513U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1438U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4078U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 38U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 37U)) + 3970829908171131502U;
            aOrbiterG = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 7040283759419531991U;
            aOrbiterK = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 21U)) + 11856292169397052901U) + aPhaseFOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 4U)) + RotL64(aCarry, 43U)) + 819598588791819022U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 47U)) + 2176451710970866848U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 6454704928613390494U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11792122387218053841U;
            aOrbiterK = RotL64((aOrbiterK * 17994898985794518565U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 9254780213489752211U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 16591812589999846482U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5425771603523423167U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 1471246223935074832U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1424843083106386453U;
            aOrbiterE = RotL64((aOrbiterE * 15020536982657410783U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1856469958050891629U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 6331743690452052712U;
            aOrbiterG = RotL64((aOrbiterG * 15327924647897459645U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10351075711345476487U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 9518585245330480185U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3792179827396760391U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 4U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 20U) + aOrbiterF) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererC, 58U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8307U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 12889U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9965U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10949U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 10U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 29U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aScatter, 27U)) + 6467297102954816305U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 19U)) + 7921154109831114952U) + aPhaseFOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (((aWandererG + RotL64(aCross, 50U)) + RotL64(aCarry, 5U)) + 5701131763215638919U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 10022999076719002684U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 27U)) + 4367135243038982316U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14445846824810383592U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7683697954545773253U;
            aOrbiterI = RotL64((aOrbiterI * 4832124801510084629U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 17517006750428030899U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2052484792684025476U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12463117571122469643U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6279463052085808926U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 679280153651813684U;
            aOrbiterD = RotL64((aOrbiterD * 3047031560593583881U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2939516520188460569U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1960616434964712325U;
            aOrbiterG = RotL64((aOrbiterG * 15145998415466343039U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12273819390719947361U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5685033154709449397U;
            aOrbiterE = RotL64((aOrbiterE * 9845666295874714959U), 39U);
            //
            aIngress = RotL64(aOrbiterI, 52U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 30U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterC, 27U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterI, 50U)) + RotL64(aCarry, 43U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 21317U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18892U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21209U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18528U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 24U)) + (RotL64(aPrevious, 39U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 22U)) + 12029393034357490020U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 4526754731580694987U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 17060419646421271853U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 43U)) + 4128488893837059683U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 12706894827547160110U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 12506324593645825056U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12581344490649250025U;
            aOrbiterE = RotL64((aOrbiterE * 16311882267466003291U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14357032418199130132U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15341977701796331249U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6332369248718076031U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 7086602307544733241U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 12398300065276832486U;
            aOrbiterK = RotL64((aOrbiterK * 18157408831225635333U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2499745046076601988U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 7249361592814001829U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14597139848072319685U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3254456186337366437U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3472973415969046680U;
            aOrbiterI = RotL64((aOrbiterI * 14583566953969168353U), 37U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 57U);
            aIngress = aIngress + (RotL64(aOrbiterH, 26U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 30U) + aOrbiterE) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterK) + RotL64(aOrbiterH, 22U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + RotL64(aOrbiterD, 51U)) + aOrbiterE) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterE, 3U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32482U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27136U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32654U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((aIndex + 28441U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 57U)) + (RotL64(aIngress, 26U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererE + RotL64(aScatter, 43U)) + 4751694786009671052U;
            aOrbiterD = (((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 57U)) + 16362725160370844224U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 6360885380915941057U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 5154536007972297036U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 57U)) + 9362540581874808253U) + aPhaseFOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13902493871525612934U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 10208452885367546542U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12067703239567933105U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3117030377279160998U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17286247690414027870U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4896931759653832095U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3930314320040949141U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7289525252391668404U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15452162299105112187U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3434167955466809185U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 17852573095128575663U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1485660158767033425U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 6137259687928853253U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13992510605237574698U;
            aOrbiterB = RotL64((aOrbiterB * 15346263295995333395U), 29U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 34U) + RotL64(aOrbiterB, 47U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterD, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 60U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterK, 35U)) + aPhaseFWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 44U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_VolleyBall_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6484U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2150U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6853U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3145U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 53U)) + (RotL64(aCarry, 26U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 16424657151168221875U) + aPhaseGOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 14U)) + 17150123681886380361U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aIngress, 5U)) + 16041993588694572757U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 9871185846434828537U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 11227236398354430757U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5399325217402192631U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 9248828789282890454U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6733832755349139621U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9041370494203701062U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14944424084524970764U;
            aOrbiterB = RotL64((aOrbiterB * 10283363059424655079U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5481938174456671041U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14783648629543752715U;
            aOrbiterF = RotL64((aOrbiterF * 7260164783191886395U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12355573914530445723U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9863991559011968318U;
            aOrbiterC = RotL64((aOrbiterC * 8495251211794343179U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16149688605937250965U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 106041828692026825U;
            aOrbiterA = RotL64((aOrbiterA * 12199934305374582599U), 21U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 20U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterA) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterC) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterD, 22U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 24U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 12958U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11416U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9310U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 13432U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 58U)) + RotL64(aCarry, 43U)) + 8020711767807230555U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 15368693777246341570U;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 5117523734225562401U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 3U)) + 13155269151097507808U) + aPhaseGOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 47U)) + 9879303753623578272U) + aPhaseGOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1165799257173794826U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 930641942062732091U;
            aOrbiterE = RotL64((aOrbiterE * 17151944851548731159U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11330571332221123153U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 2862963158282518899U;
            aOrbiterK = RotL64((aOrbiterK * 13782195862525974199U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 6019186399361476659U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1924419843785161958U;
            aOrbiterF = RotL64((aOrbiterF * 9485557122500346869U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 12618629043591380461U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9334176504266512405U;
            aOrbiterA = RotL64((aOrbiterA * 18239109235362925739U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16829692481030013551U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 5604784396927022709U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2833893610883508353U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 30U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 60U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 19U)) + aPhaseGWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 20578U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((aIndex + 19871U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17478U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22838U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 40U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 10915618884692072446U) + aPhaseGOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aCross, 27U)) + 12634922308499254909U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 13U)) + 6533934734564499389U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 56U)) + RotL64(aCarry, 13U)) + 6744203303756105181U;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 53U)) + 13086782386652045658U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5693840533331397822U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1803663542535024611U;
            aOrbiterI = RotL64((aOrbiterI * 8511046986156781857U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3597219300593287708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1429753448204448904U;
            aOrbiterH = RotL64((aOrbiterH * 10927459251773273143U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 17229017825587322715U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1137574712801062932U;
            aOrbiterJ = RotL64((aOrbiterJ * 3645832160939819415U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2401991077004083378U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 1332473247826139292U;
            aOrbiterE = RotL64((aOrbiterE * 15029831858261506447U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11730946340796899885U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 15319163439700390962U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1349242001887975499U), 23U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 23U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterI, 23U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aPrevious, 60U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 58U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 28650U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31792U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26239U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25895U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 12262991801139086177U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 7963038771924890197U) + aPhaseGOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 26U)) + 15540520327933568896U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 8745565892055020722U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 5U)) + 16619329199683755286U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 10865705026433867260U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 2743368697984518059U;
            aOrbiterJ = RotL64((aOrbiterJ * 2989232417816919375U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5556006271515473135U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 5355833281353498588U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4190140212757841511U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8313616108963479829U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 16657121016801866434U;
            aOrbiterH = RotL64((aOrbiterH * 331533349428472477U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16532226425013000833U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 5800465874932467232U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5966395771690704577U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17882948163883121328U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 15029375310296563175U;
            aOrbiterI = RotL64((aOrbiterI * 17021415832288477713U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterJ, 27U)) + aOrbiterG) + aPhaseGWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterG, 53U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterE, 4U)) + aPhaseGWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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

void TwistExpander_VolleyBall_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5874U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 2718U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7504U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8078U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 52U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 47U)) + 1087148170018530502U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 23U)) + 15530846874509311414U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 16987358651515511212U) + aPhaseHOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 12504143181007924259U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 34U)) + 393322117322732418U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14325937299241887166U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 9395262907017475742U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3442643798173589117U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 13658510441418344769U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6410754322737005336U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6932217611373076391U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9257290738538818434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7489828960857692286U;
            aOrbiterH = RotL64((aOrbiterH * 16519674788777989043U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4118778591214588387U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16619215231168796563U;
            aOrbiterA = RotL64((aOrbiterA * 14876884956536265157U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 11326283811003573430U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 1865401866017614604U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8378326058282460073U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 46U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 3U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 27U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterA, 53U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 19U)) + aOrbiterD) + RotL64(aCarry, 47U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 26U) + RotL64(aOrbiterA, 42U)) + aOrbiterH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12899U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15926U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12494U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14874U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 26U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererK + RotL64(aPrevious, 37U)) + 6654158889644956636U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 29U)) + 9045779659363991870U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 3888897662136993491U) + aPhaseHOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 6882016842864459345U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 46U)) + 15601891715956172291U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 5176811598629335350U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 12519945150889074325U;
            aOrbiterC = RotL64((aOrbiterC * 8721098129033306427U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4552583214397603278U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14225482701804864688U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8526052833180466359U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5485298070606280363U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11237713257388094289U;
            aOrbiterD = RotL64((aOrbiterD * 11032429223099413011U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 14340345895626142788U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16275167270553643347U;
            aOrbiterB = RotL64((aOrbiterB * 7308578867128951199U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 14041860597556520250U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 1436068974197066343U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3938460345031496843U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 54U);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterF, 44U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 50U) + RotL64(aOrbiterF, 3U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + aPhaseHWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24504U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20036U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19987U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20343U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 13U)) + 12535417189990029950U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 6204401443676390273U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 40U)) + RotL64(aCarry, 5U)) + 869613505613154672U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 15053590879563855802U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 53U)) + 13338989605204591428U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 18306470022403825392U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1150696349434090218U;
            aOrbiterA = RotL64((aOrbiterA * 1099447646821052165U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 13549541786420596437U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14302878430259588461U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16813606782134305513U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4660437084477165225U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1653628537860912069U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2624835201155303123U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5594199757006711631U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11008472193138708891U;
            aOrbiterH = RotL64((aOrbiterH * 13645764762027798301U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3668516817279364310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 128159531749679984U;
            aOrbiterK = RotL64((aOrbiterK * 4523246859249826987U), 5U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 5U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 30U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 20U) + aOrbiterA) + RotL64(aOrbiterI, 57U));
            aWandererK = aWandererK + (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 40U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 3U)) + aOrbiterI) + aPhaseHWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 58U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 24853U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 28781U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32338U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((aIndex + 32468U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 6U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 12027839670755583592U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 13U)) + 15380130703509859843U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 4590907433867798074U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 36U)) + RotL64(aCarry, 21U)) + 1754574023602519724U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aIngress, 57U)) + 9832756659564903767U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5035088494491470403U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14199170923323644638U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 4518257134117207121U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8325619421264440438U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 969534320779067977U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17767548306355264705U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 270575869402913847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13344806516599578910U;
            aOrbiterC = RotL64((aOrbiterC * 10193544126281901579U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15143147951139409101U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 14425582489214169238U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16893787086337916355U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13951127523239064584U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14177925225918293579U;
            aOrbiterD = RotL64((aOrbiterD * 13079514031864998485U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 18U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterH, 27U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterC, 51U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
