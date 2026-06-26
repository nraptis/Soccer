#include "TwistExpander_PickleBall_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_PickleBall_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x937EAB0BD1F0C1A9ULL + 0xAAECBF3CA8B58F6BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC8A2EC5BEF5595FBULL + 0x94431D3B9CA789F5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB29D9E86A0CBDBE7ULL + 0x8AB0D5C682384285ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF806658B7E0C8BF7ULL + 0xCFE241D9AF0AE54DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC2DCB78E21BB81F5ULL + 0x86EA6C65C6D1FF1CULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF7C382CCCBF16FD9ULL + 0xB6DEFA71AC99E60AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC57A21F13250724BULL + 0xF9DD2A350D121406ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE1058F199E536FA5ULL + 0xD8EE2F4F5716445EULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 41U) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2306U)) & S_BLOCK1], 4U) ^ RotL64(mSnow[((aIndex + 4715U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordC, 11U));
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 3629U)) & S_BLOCK1], 51U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 3592U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 58U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 3U)) + 14624277139785904404U) + RotL64(aNonceWordD, 45U);
            aOrbiterG = (aWandererK + RotL64(aCross, 39U)) + 6966977309498165611U;
            aOrbiterC = (aWandererF + RotL64(aScatter, 27U)) + 205536824352530761U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 60U)) + 16629575265808255692U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 3U)) + 596881340147972746U) + aOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 11944412799107412650U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 11U)) + 4615021315668210206U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 8497630055977606216U) + RotL64(aNonceWordG, 51U);
            aOrbiterA = (aWandererI + RotL64(aPrevious, 41U)) + 11131601107309336885U;
            aOrbiterB = (aWandererA + RotL64(aScatter, 37U)) + 5935883479805510099U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 56U)) + 15629346719765798174U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5279128339113651273U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16778365912440331821U;
            aOrbiterC = RotL64((aOrbiterC * 705421028266789241U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16003052937645491524U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6723226158737614764U;
            aOrbiterE = RotL64((aOrbiterE * 16690657664909260573U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9785784358981219543U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 10055457337292292710U;
            aOrbiterH = RotL64((aOrbiterH * 17919129940751761111U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11779163108592974175U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 1177999477942202687U) ^ aOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13475069421684114643U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9190694445141492214U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 15605342360346353457U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14547769706392595647U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 14877565450677523492U) + RotL64(aNonceWordA, 36U);
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 1074095623308025684U;
            aOrbiterA = RotL64((aOrbiterA * 7884068939436891093U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 12803174154216941583U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 8813356463693637033U;
            aOrbiterI = RotL64((aOrbiterI * 4898237214617563167U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6063909634038581414U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 15112191502834052566U) ^ RotL64(aNonceWordF, 57U);
            aOrbiterG = RotL64((aOrbiterG * 6780741782103553485U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13926459034757240311U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4324555954703597591U;
            aOrbiterF = RotL64((aOrbiterF * 18068922072149745351U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7183063131331255506U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 18072787091203847052U;
            aOrbiterD = RotL64((aOrbiterD * 12530396154012878153U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10143386327707219710U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 14624277139785904404U;
            aOrbiterB = RotL64((aOrbiterB * 12100828883424264587U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 39U) + aOrbiterC) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterA, 43U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterG, 21U)) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 4U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordB, 11U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + RotL64(aNonceWordE, 43U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + RotL64(aCarry, 47U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterI, 13U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterC, 58U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 6U) + RotL64(aOrbiterB, 29U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterE, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 26U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordF, 56U)) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 8840U)) & S_BLOCK1], 47U) ^ RotL64(mSnow[((aIndex + 8226U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordG, 47U)) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9967U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((aIndex + 5517U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 22U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 5568146815535263910U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + RotL64(aNonceWordA, 21U);
            aOrbiterK = (aWandererD + RotL64(aIngress, 51U)) + 7736084960873834666U;
            aOrbiterB = (aWandererF + RotL64(aCross, 23U)) + 1336413621817562093U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 19U)) + 5218462026934984692U) + RotL64(aNonceWordB, 5U);
            aOrbiterD = (aWandererI + RotL64(aScatter, 29U)) + 7048890985969555935U;
            aOrbiterA = (aWandererA + RotL64(aCross, 40U)) + 13415955213864702118U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 5U)) + 5657023257021528548U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 41U)) + 14338310943137497116U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 12305161641833950473U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 43U)) + 14514226578370459131U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 26U)) + 12692904083266024340U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11012959130001327964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7106471380403489078U;
            aOrbiterB = RotL64((aOrbiterB * 515626559384817223U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3718101961355280891U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13364192077222322664U) ^ RotL64(aNonceWordE, 13U);
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 6720867800318913440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 14497243926965866546U;
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5789056168233262435U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14438482587495779937U;
            aOrbiterE = RotL64((aOrbiterE * 10593535547917767263U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 313917798940179945U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15241845511889502917U;
            aOrbiterJ = RotL64((aOrbiterJ * 16483477103771326107U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3591957424821693032U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 1559050939014453558U;
            aOrbiterG = RotL64((aOrbiterG * 17933346117866604725U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 15340590914441451383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 5538037287390050110U;
            aOrbiterC = RotL64((aOrbiterC * 4082576643144951473U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4151270491894969214U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 263593701314144898U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10372046955804512457U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 9025145270653080646U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]) + RotL64(aNonceWordF, 55U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6867950904094870056U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9975247022340627751U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3183454301841252109U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3054904157641290615U) ^ aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4092317552439599475U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 1768555574434776135U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5568146815535263910U;
            aOrbiterI = RotL64((aOrbiterI * 12466957001078663927U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 10U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 44U) + RotL64(aOrbiterI, 53U)) + aOrbiterB);
            aWandererF = aWandererF + (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 47U)) + aOrbiterB) + RotL64(aNonceWordH, 17U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterJ, 6U)) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 37U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 60U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 5U)) + RotL64(aNonceWordD, 60U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterH, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordG, 37U)) ^ RotL64(aNonceWordD, 5U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 11254U)) & S_BLOCK1], 13U) ^ RotL64(mSnow[((S_BLOCK1 - aIndex + 13250U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 3U) ^ RotL64(aNonceWordH, 52U)) ^ RotL64(aNonceWordA, 27U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15023U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13082U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererC + RotL64(aIngress, 11U)) + 6381335981879993247U;
            aOrbiterB = (aWandererD + RotL64(aScatter, 23U)) + 15595429101600023172U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 50U)) + 5449234297249826461U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 11213734849329731168U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 11U)) + 16438473952464514248U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + 7357872882115186976U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 394402075160738643U) + RotL64(aNonceWordF, 29U);
            aOrbiterE = ((aWandererA + RotL64(aCross, 13U)) + 11112941985410283532U) + RotL64(aNonceWordE, 61U);
            aOrbiterC = ((aWandererE + RotL64(aIngress, 5U)) + 14955125011182736212U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aCross, 39U)) + 14770727009821304070U;
            aOrbiterJ = (aWandererI + RotL64(aScatter, 18U)) + 11286366598129204910U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 7358400908565425780U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 15635109923749114761U;
            aOrbiterK = RotL64((aOrbiterK * 12415152149408700329U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13826842523738623579U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1072811298828325231U;
            aOrbiterG = RotL64((aOrbiterG * 9662800288646215083U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4017334196009350776U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 8812213572751410831U) ^ RotL64(aNonceWordG, 41U);
            aOrbiterB = RotL64((aOrbiterB * 12744171921566782795U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 6723457786170634403U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9785583533999417673U;
            aOrbiterH = RotL64((aOrbiterH * 7776915427605471097U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10265132640322153964U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8435670887514808087U;
            aOrbiterE = RotL64((aOrbiterE * 2706263045620662131U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 4303823386961718326U) + RotL64(aNonceWordA, 43U);
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4214384238167491037U;
            aOrbiterA = RotL64((aOrbiterA * 8490707334221154005U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8740835037840799136U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5988815405391206280U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17838555472135715929U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15539461383052981747U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3743772525784217714U;
            aOrbiterD = RotL64((aOrbiterD * 6352086797545969187U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16283379107488103386U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2677085736169305444U;
            aOrbiterF = RotL64((aOrbiterF * 5034373635279045467U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16961352880910247821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7475807604144212417U;
            aOrbiterC = RotL64((aOrbiterC * 5016987646810330727U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10187131329357526073U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6381335981879993247U;
            aOrbiterJ = RotL64((aOrbiterJ * 15277168748093112841U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 52U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 19U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterA, 28U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterH, 43U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 37U));
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 34U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + RotL64(aNonceWordH, 21U));
            aWandererI = aWandererI + ((RotL64(aIngress, 54U) + aOrbiterF) + RotL64(aOrbiterG, 3U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterE, 47U)) + RotL64(aNonceWordD, 44U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 12U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 58U) ^ RotL64(aNonceWordC, 11U)) ^ RotL64(aNonceWordD, 43U));
            aIngress = aIngress ^ (RotL64(mSnow[((aIndex + 19376U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18522U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 23U) ^ RotL64(aNonceWordB, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21451U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19791U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 26U)) ^ (RotL64(aCross, 13U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 38U)) + RotL64(aCarry, 21U)) + 1888427424966603593U;
            aOrbiterK = (aWandererI + RotL64(aIngress, 19U)) + 5436761445660415091U;
            aOrbiterC = (aWandererH + RotL64(aScatter, 53U)) + 17322876217962143270U;
            aOrbiterB = (aWandererA + RotL64(aCross, 11U)) + 9728299982740564979U;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 48U)) + RotL64(aCarry, 5U)) + 301720335271716921U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 43U)) + 8069685428854814396U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 41U)) + 1973715500949100991U) + RotL64(aNonceWordA, 35U);
            aOrbiterE = ((aWandererB + RotL64(aCross, 3U)) + 87666408799854155U) + aOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 12195436904339035245U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 35U)) + 4578742069143400295U) + RotL64(aNonceWordE, 25U);
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 57U)) + 7828776048774876484U) + aOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 17203146364542781833U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16913369550858890466U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13534417587921978507U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 9632761514552265402U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9106637671877341286U;
            aOrbiterD = RotL64((aOrbiterD * 9073709119482640391U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15423680889126750876U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6087310684583331882U;
            aOrbiterH = RotL64((aOrbiterH * 8964465129744898619U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5420955876411796789U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14166807419730848032U;
            aOrbiterI = RotL64((aOrbiterI * 442659738632823751U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 8118312450347026824U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4253043584558403086U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5651748455190536467U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 8810774678371762700U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12218479555589447835U;
            aOrbiterF = RotL64((aOrbiterF * 11026364205248516355U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11389930523582876358U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16334420553471379915U;
            aOrbiterG = RotL64((aOrbiterG * 13830132212033904777U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 18201289372553710279U) + RotL64(aNonceWordD, 57U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7196540389657785361U;
            aOrbiterJ = RotL64((aOrbiterJ * 13058135202554889791U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2601046573550065116U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 2243003381737071984U) ^ aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) ^ RotL64(aNonceWordC, 58U);
            aOrbiterA = RotL64((aOrbiterA * 10518763530499878945U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6058992247656841580U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 10083863011670540073U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17908394295613117155U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 8505005026063156940U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1888427424966603593U;
            aOrbiterB = RotL64((aOrbiterB * 18298382581929885653U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + RotL64(aNonceWordB, 41U));
            aWandererI = aWandererI + (((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterD, 41U)) + RotL64(aNonceWordH, 45U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 37U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 60U) + aOrbiterJ) + RotL64(aOrbiterG, 50U)) + aWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 53U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterC, 21U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 48U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aCross, 21U) + aOrbiterI) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterH, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 54U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 25865U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 22427U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 43U) ^ RotL64(aNonceWordG, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23354U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26329U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 8367680518550579791U;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 10U)) + RotL64(aCarry, 29U)) + 11491674725611181241U;
            aOrbiterI = (aWandererB + RotL64(aCross, 39U)) + 16673861720782164214U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 23U)) + 9786610124108350855U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 27U)) + 5745080601557577637U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 3U)) + 1959402215131684684U) + aOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 57U)) + 6121650036079196522U) + RotL64(aNonceWordC, 21U);
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 21U)) + 12016309761037342392U) + RotL64(aNonceWordA, 61U);
            aOrbiterE = (aWandererE + RotL64(aCross, 30U)) + 5986936646177049603U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 1000367700904043468U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aScatter, 51U)) + 17425288243569101032U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4856917474950325209U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16312111093223166419U;
            aOrbiterI = RotL64((aOrbiterI * 11046477664487805241U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 456110002032422270U) + RotL64(aNonceWordD, 10U);
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11393724374787795662U;
            aOrbiterD = RotL64((aOrbiterD * 1176984359123668389U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8378176867715697176U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 8086186452345234815U;
            aOrbiterK = RotL64((aOrbiterK * 8450438271765985235U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8470349167474173245U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2528229938740192694U;
            aOrbiterH = RotL64((aOrbiterH * 8717790851266520943U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13247168811545753141U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 8745293957516815264U;
            aOrbiterF = RotL64((aOrbiterF * 14270617180621072619U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6165915500564961987U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12015407798844173213U;
            aOrbiterA = RotL64((aOrbiterA * 3913451986559154153U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 545006684939922156U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16366753936267185001U;
            aOrbiterC = RotL64((aOrbiterC * 6495185976430013201U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3097605623436091728U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 15950167830259022926U) ^ RotL64(aNonceWordH, 55U);
            aOrbiterE = RotL64((aOrbiterE * 4415538963984293323U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 8356327899232213426U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 10183421678251169945U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9474380650337109299U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16327340177970834683U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7086901180933495535U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1276521829484494857U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 13421211370092080006U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8367680518550579791U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12256662446176946163U), 21U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 58U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 21U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 41U)) + aOrbiterD);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + RotL64(aNonceWordB, 45U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterF, 50U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterF, 21U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterI) + RotL64(aNonceWordG, 59U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 5U) + RotL64(aOrbiterE, 39U)) + aOrbiterI) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterC, 44U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererK, 38U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordH, 51U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 32270U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27899U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 20U) ^ RotL64(aNonceWordC, 57U)) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31741U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 30765U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererA + RotL64(aIngress, 54U)) + 15383045568644941552U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 17452811657750910067U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 23U)) + 15660117718455155603U;
            aOrbiterG = (aWandererI + RotL64(aCross, 27U)) + 10396441207743665753U;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 57U)) + 3708971058200841442U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 13U)) + 7000673057768598750U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 44U)) + 9886354469011131596U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + RotL64(aNonceWordD, 5U);
            aOrbiterE = (((aWandererH + RotL64(aCross, 11U)) + 16018065329058043467U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordA, 51U);
            aOrbiterB = (aWandererD + RotL64(aIngress, 3U)) + 5024756166109352320U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 6587818720728886652U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 11U)) + 3652672354944162319U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6307315649915348048U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16405347331742979258U;
            aOrbiterF = RotL64((aOrbiterF * 7183142442906743699U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 5427299664054601957U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4983381733483185898U;
            aOrbiterH = RotL64((aOrbiterH * 14646556236306407673U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 10182995521328377487U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8694282877540593550U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterA = RotL64((aOrbiterA * 14614602561910403893U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 4085927978153269932U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6176195962815240877U;
            aOrbiterD = RotL64((aOrbiterD * 16792916528959579875U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6966742100601433005U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9920952446921247521U;
            aOrbiterE = RotL64((aOrbiterE * 1879821050131820933U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 11958734477518336014U) + aOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2058335903640404380U;
            aOrbiterB = RotL64((aOrbiterB * 6986170159285417789U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 77366119537297816U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12072894199692855000U;
            aOrbiterK = RotL64((aOrbiterK * 9083781120514635987U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11874297832446385377U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13715562531763053196U;
            aOrbiterI = RotL64((aOrbiterI * 12822488258322963187U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13664465415354326653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 10365386643010882315U;
            aOrbiterC = RotL64((aOrbiterC * 3687934567254955761U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2003863843075564853U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8864134110143237364U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4586162015675320985U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 8055736412403126985U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15383045568644941552U) ^ RotL64(aNonceWordG, 60U);
            aOrbiterG = RotL64((aOrbiterG * 5175405553995854715U), 3U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 11U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 4U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterC);
            aWandererF = aWandererF + ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 37U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererI = aWandererI + (((RotL64(aPrevious, 20U) + RotL64(aOrbiterD, 19U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 35U)) + aOrbiterF) + RotL64(aNonceWordE, 17U));
            aWandererC = aWandererC + ((((RotL64(aCross, 41U) + RotL64(aOrbiterG, 14U)) + aOrbiterF) + RotL64(aCarry, 35U)) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 21U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 34U) + aOrbiterE) + RotL64(aOrbiterJ, 41U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterK, 46U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 27U)) + aOrbiterD) + RotL64(aNonceWordF, 59U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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

void TwistExpander_PickleBall_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x92791C7EA745FE9DULL + 0x9D11275AD261E347ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEFC71DF10FA28577ULL + 0xC7A8A9936D2E5B89ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xACDCC5A9C03776ABULL + 0xFCC6C1A3A12B21C1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8C2F680CD14061F1ULL + 0xD5B89E95BB89E568ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA7AD25A9D7994EDBULL + 0x901060921ACA4D8DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xC3B10007FB13CF45ULL + 0x9329B7F7B10C285CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF5FD28B84A8FD465ULL + 0xBA373CFD4AEEE403ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA54D85585779D4CFULL + 0xB68F75C7EF4BB611ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 41U) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1233U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 818U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 41U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordA, 30U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5231U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4746U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aIngress, 3U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererG + RotL64(aIngress, 51U)) + 8402620908307642697U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 60U)) + 11347672014525086047U) + RotL64(aNonceWordD, 59U);
            aOrbiterB = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 2816462912503401876U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 39U)) + RotL64(aCarry, 53U)) + 6940159795470696093U;
            aOrbiterI = (aWandererD + RotL64(aCross, 23U)) + 9134692490095883851U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 35U)) + 4999455497008026526U;
            aOrbiterK = ((((aWandererE + RotL64(aScatter, 11U)) + RotL64(aCarry, 21U)) + 5992451460350651332U) + aOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordC, 45U);
            aOrbiterA = (aWandererK + RotL64(aPrevious, 3U)) + 3417087346651371924U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 18U)) + 3612773820086198270U) + aOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 463398077083428570U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11249391303705089012U) ^ aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7106735772303292983U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17027535139825739501U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 568131384979596481U;
            aOrbiterG = RotL64((aOrbiterG * 5683451044852895957U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4793712537158004047U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 10415170179135963622U) ^ aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13729564030210361415U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2391473979460065630U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4240058362680064261U;
            aOrbiterE = RotL64((aOrbiterE * 12375884373396400889U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9963957011090031698U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3325305624067445525U;
            aOrbiterF = RotL64((aOrbiterF * 3128542681461806309U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2094945647665114693U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10703615640774042674U;
            aOrbiterH = RotL64((aOrbiterH * 12641986098450423751U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3768738815518590289U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15021301790376706827U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14445850924223550339U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 10571246886181608316U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 5130325144599151793U) ^ RotL64(aNonceWordF, 37U);
            aOrbiterC = RotL64((aOrbiterC * 3185251943547657467U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 8617523421720966373U) + RotL64(aNonceWordG, 17U);
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16574597770835250074U;
            aOrbiterI = RotL64((aOrbiterI * 1759209403428937799U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 11U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 14U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterE) + RotL64(aNonceWordB, 40U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 28U)) + aOrbiterH) + aWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 19U)) + RotL64(aNonceWordE, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 28U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererG = aWandererG + (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 58U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterA, 35U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 43U) ^ RotL64(aNonceWordG, 35U)) ^ RotL64(aNonceWordB, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10313U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 8528U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordA, 37U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9838U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 12220U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aPrevious, 39U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 19U)) + 11480359716598965890U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 53U)) + 15431182525482873419U) + RotL64(aNonceWordD, 37U);
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 39U)) + 11360504974812776707U) + RotL64(aNonceWordF, 25U);
            aOrbiterI = (aWandererH + RotL64(aIngress, 13U)) + 9292576416573382769U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 44U)) + RotL64(aCarry, 19U)) + 1549257414531028975U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 5347769463033129317U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 23U)) + 17019199177478377234U) + aOrbiterAssignSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 16558106007323125094U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 58U)) + 3976182233825939422U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2889047161195954395U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 2241831345026962605U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5757458560979927857U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12850802412140579294U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13541744735436450160U;
            aOrbiterD = RotL64((aOrbiterD * 906089290000537439U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2085863085516538212U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 2969034221711544086U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7768528124408400403U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6482666944512391472U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16969153556875844613U;
            aOrbiterH = RotL64((aOrbiterH * 9483462388353216219U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 5161314086757363678U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7150282484670673211U;
            aOrbiterF = RotL64((aOrbiterF * 8522427002337918663U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5465304381272305847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2344610773390354017U;
            aOrbiterG = RotL64((aOrbiterG * 17010258514288089191U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8335906578006588582U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13668796013474193793U;
            aOrbiterI = RotL64((aOrbiterI * 8228000547141147777U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9663362594301419686U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 3683773739120343413U) ^ RotL64(aNonceWordH, 54U);
            aOrbiterJ = RotL64((aOrbiterJ * 8319320803406104749U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2538583190438044942U) + RotL64(aNonceWordB, 13U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 4454069062219406996U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16329554225309389599U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 46U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + RotL64(aOrbiterJ, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 24U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterH, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterF, 53U)) + RotL64(aNonceWordA, 45U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 46U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 57U)) + RotL64(aNonceWordE, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterJ);
            aWandererC = aWandererC + ((RotL64(aIngress, 27U) + aOrbiterF) + RotL64(aOrbiterJ, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 14U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 20U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 58U) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 18704U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 24175U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 47U) ^ RotL64(aNonceWordH, 60U)) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20165U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21315U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCross, 4U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 3U)) + 17470880031634374199U) + aOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 19U)) + 757565846006937746U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 30U)) + 9419282475801345674U) + RotL64(aNonceWordG, 16U);
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 37U)) + 2014248014107898196U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aCross, 57U)) + 15113928519446490441U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 23U)) + 7346126964886259935U) + RotL64(aNonceWordE, 29U);
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 5594123113093162359U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 5659237263369402005U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 52U)) + RotL64(aCarry, 57U)) + 11565709683423969703U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 16782863743534856287U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13499100900072115907U;
            aOrbiterE = RotL64((aOrbiterE * 5567729598873214433U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 11414447651044205242U) + aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7545993795121430538U;
            aOrbiterG = RotL64((aOrbiterG * 10758488381206257261U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11778229237616454988U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 2544793391976514665U) ^ RotL64(aNonceWordB, 15U);
            aOrbiterK = RotL64((aOrbiterK * 4021060413798523299U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9972156716619459164U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17651030383827445664U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6742914240706775487U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17439147296849134543U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 10021926927948343656U;
            aOrbiterF = RotL64((aOrbiterF * 18139540407315440909U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9309867875882669289U) + RotL64(aNonceWordH, 43U);
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 14951424455944346337U;
            aOrbiterC = RotL64((aOrbiterC * 10569523948169951309U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2166343974068770659U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11386993629011562026U;
            aOrbiterI = RotL64((aOrbiterI * 3091639433512536097U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5747849744680120960U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4019290369160113026U;
            aOrbiterH = RotL64((aOrbiterH * 5567515306039646735U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3820540009554769592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8210747198363020939U;
            aOrbiterJ = RotL64((aOrbiterJ * 16215133106542452509U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 38U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 18U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 53U)) + aOrbiterK) + RotL64(aNonceWordD, 7U));
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + RotL64(aNonceWordA, 49U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 60U) + RotL64(aOrbiterJ, 41U)) + aOrbiterC);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 60U)) + aOrbiterA) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 4U) ^ RotL64(aNonceWordB, 19U)) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31317U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31801U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31735U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27964U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 36U)) + (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 53U)) + 14499676118633326000U;
            aOrbiterH = (aWandererC + RotL64(aCross, 23U)) + 17191273593018552288U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 4085176294948097737U) + RotL64(aNonceWordB, 30U);
            aOrbiterF = (aWandererI + RotL64(aIngress, 3U)) + 11112671474158908186U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 60U)) + 8745787969012266485U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 29U)) + 18074049663777707948U;
            aOrbiterG = ((((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 2543758649719164688U) + aOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 35U);
            aOrbiterA = ((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 4659584749412700523U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 34U)) + 974639159259871273U) + aOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9211220687971081987U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8567024626862182714U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7755874089832496393U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5803002132294840900U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 11968489432878148467U) ^ aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4501441062617123165U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 9470807228394903442U) + RotL64(aNonceWordG, 53U);
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 1692347973120388469U;
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16510815732690193145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 755159406833096510U;
            aOrbiterI = RotL64((aOrbiterI * 14091736464659561165U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1518824876475937620U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 701225390867330446U;
            aOrbiterF = RotL64((aOrbiterF * 12264618860580199927U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8425976693733003889U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 7182176375442410367U) ^ RotL64(aNonceWordE, 39U);
            aOrbiterJ = RotL64((aOrbiterJ * 8860605703761731859U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4546566785167467924U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2593340999038753749U;
            aOrbiterA = RotL64((aOrbiterA * 10152461487764567563U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 9756331608356622299U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5511625814747641978U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4806076157539829529U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8694400787420160733U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12648969491371382682U;
            aOrbiterH = RotL64((aOrbiterH * 5346585704222643759U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 18U) + RotL64(aOrbiterC, 24U)) + aOrbiterJ) + RotL64(aNonceWordH, 47U));
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + RotL64(aOrbiterG, 51U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + RotL64(aNonceWordC, 13U));
            aWandererK = aWandererK + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterD, 57U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 52U) + RotL64(aOrbiterI, 40U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_PickleBall_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD9B46B791E42B943ULL + 0x89E6611AD25EB25AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8E598A2324E1369DULL + 0x96542F73F3961B11ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF0BB7BAE759DB5BDULL + 0x8D3E03301D6D80A8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xCE5D936173ECBEA1ULL + 0xD68AE04F090CC127ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD5817B8DAFFC6137ULL + 0xB17BFBF8EA0C8CB2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8A06A38C6C1A0EF1ULL + 0xCC115A5983ECD8A0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8C903F68E0CDB08DULL + 0xB19A17841DC8F23BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA6CE441EAD130369ULL + 0xBBBEDC8F8D7988D2ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordF, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6740U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2198U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 50U) ^ RotL64(aNonceWordC, 29U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5107U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1595U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 36U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 11274974230580265396U) + RotL64(aNonceWordC, 31U);
            aOrbiterA = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 16658438747342741547U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (((aWandererF + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 16612986966106053844U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 41U)) + 9329502236843231290U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 27U)) + 14088261356708344656U) + RotL64(aNonceWordG, 55U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13692608802007789581U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6824473946645682398U;
            aOrbiterK = RotL64((aOrbiterK * 13619437545775237601U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2072915876348570040U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13239288539564571257U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4677557318688502593U) + RotL64(aNonceWordH, 8U);
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15081678577055628459U;
            aOrbiterB = RotL64((aOrbiterB * 16659305295251177155U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7026792817486507482U) + aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14871665922943969918U;
            aOrbiterA = RotL64((aOrbiterA * 694073180313083145U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6807734532159292872U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 17882797335141303280U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]) ^ RotL64(aNonceWordB, 25U);
            aOrbiterD = RotL64((aOrbiterD * 15439872930381050291U), 11U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterB) + RotL64(aOrbiterA, 43U)) + RotL64(aNonceWordE, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterD) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 44U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aNonceWordA, 61U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 23U)) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 35U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordD, 20U)) ^ RotL64(aNonceWordF, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14198U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 14805U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordE, 54U)) ^ RotL64(aNonceWordA, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 15035U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8396U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 39U)) + (RotL64(aIngress, 60U) ^ RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 40U)) + RotL64(aCarry, 5U)) + 2225397913940961213U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 8342544893601343643U) + RotL64(aNonceWordH, 37U);
            aOrbiterF = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 29U)) + 162922186381417187U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aIngress, 57U)) + 11660218373710972210U) + RotL64(aNonceWordB, 55U);
            aOrbiterC = (aWandererJ + RotL64(aCross, 21U)) + 14909034764605802354U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 16776955237009701511U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + RotL64(aNonceWordD, 29U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5834487809188925253U;
            aOrbiterF = RotL64((aOrbiterF * 4458820879204327709U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1498492772767040320U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 4161765458781579617U;
            aOrbiterC = RotL64((aOrbiterC * 15535994410289065281U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10511923076962447765U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8575954471692620021U) ^ aOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 6536325446331340573U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + RotL64(aNonceWordC, 61U);
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 1790628986900286346U) ^ aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5262997114200816715U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2623814807619278590U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11676970995834706612U;
            aOrbiterA = RotL64((aOrbiterA * 10057461115132434901U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 18U)) + aOrbiterA) + RotL64(aNonceWordA, 5U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 27U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterE, 41U));
            aWandererG = aWandererG + ((((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordG, 36U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + aWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 14U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 29U) ^ RotL64(aNonceWordF, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 17517U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17672U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordC, 14U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23710U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 18748U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 252059974543142812U;
            aOrbiterE = ((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 11690823093681457368U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 58U)) + RotL64(aCarry, 53U)) + 13282189752890971123U) + RotL64(aNonceWordF, 30U);
            aOrbiterB = (((aWandererE + RotL64(aCross, 19U)) + 9507416294305708435U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + RotL64(aNonceWordH, 29U);
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 3U)) + 14053038174390776539U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 14605253312318725009U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 18138286582677863671U) ^ RotL64(aNonceWordD, 53U);
            aOrbiterA = RotL64((aOrbiterA * 10595905899691011321U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8530091235978489988U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 14381731677571170073U;
            aOrbiterE = RotL64((aOrbiterE * 11675896999665768253U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13316413456378978456U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3910529530149320706U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16000139333493588429U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6302070286831566901U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12324134652758551396U) ^ RotL64(aNonceWordG, 31U);
            aOrbiterB = RotL64((aOrbiterB * 17136438281540250165U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 4773478557638475048U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4031153435446078944U;
            aOrbiterF = RotL64((aOrbiterF * 3876928995240982769U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 48U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((((RotL64(aScatter, 58U) + aOrbiterA) + RotL64(aOrbiterF, 11U)) + RotL64(aNonceWordB, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + RotL64(aCarry, 27U)) + RotL64(aNonceWordE, 21U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 21U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordD, 6U) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30246U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31092U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordC, 34U)) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28724U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24719U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 5U)) ^ (RotL64(aPrevious, 22U) + RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 4179952823252098240U;
            aOrbiterK = ((((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 21U)) + 3745613452332101749U) + aOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1]) + RotL64(aNonceWordH, 61U);
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 11U)) + 2955689793395307176U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 5639060180251322019U) + RotL64(aNonceWordC, 39U);
            aOrbiterC = ((aWandererG + RotL64(aScatter, 28U)) + 7901969163853586463U) + aOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2242166787816318119U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5239936443960750064U;
            aOrbiterE = RotL64((aOrbiterE * 2752853245379816327U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13939136954732185558U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 17058884136712717463U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7222348891215482977U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18148618660054585941U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7022023484530327814U) ^ RotL64(aNonceWordA, 15U);
            aOrbiterH = RotL64((aOrbiterH * 650100011311048589U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 7722084537340095637U) + RotL64(aNonceWordF, 59U);
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11764151879690934182U;
            aOrbiterK = RotL64((aOrbiterK * 12264384877711365655U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16412785901758144708U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9666718667728274824U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10865799822751771795U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 39U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + RotL64(aCarry, 35U)) + RotL64(aNonceWordB, 38U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 18U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterC, 27U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aNonceWordE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + RotL64(aWandererF, 46U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_PickleBall_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D8F982206B89829ULL + 0x82FE5670744AC39DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE21CA37B0E5024B3ULL + 0xD5D498D4E1C01EF3ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE5A4186A4F1FA975ULL + 0xD7646F47B980FD7CULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE92A6EC30D82DE7BULL + 0x987FC97A62EB3700ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCDB910DF5B1F2481ULL + 0xD2A5CEA9E5E2CDD4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC294D1B4838D000BULL + 0x82EC003E935175A2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x9631FC2568273F35ULL + 0xB239B8BE58637D3BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD20F817D08AEAF7DULL + 0x994BF837C0E32CDFULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 38U) ^ RotL64(aNonceWordD, 57U)) ^ RotL64(aNonceWordC, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5819U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((aIndex + 4498U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 11U)) ^ RotL64(aNonceWordF, 24U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5659U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3139U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 13U) + RotL64(aPrevious, 26U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 7632760812370906911U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 53U)) + 6007174525479723089U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 43U)) + 3362829642521821048U;
            aOrbiterI = (aWandererG + RotL64(aCross, 27U)) + 18009548556107978286U;
            aOrbiterJ = ((((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 17880909432272697327U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordD, 17U);
            aOrbiterC = (aWandererF + RotL64(aCross, 60U)) + 15961567935420752568U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 47U)) + 10136559064656837921U) + RotL64(aNonceWordB, 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 17622019364405410277U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6927494824421416306U;
            aOrbiterF = RotL64((aOrbiterF * 2686290883767829973U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 7125170407794874847U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12342273503071032250U;
            aOrbiterJ = RotL64((aOrbiterJ * 867417849555857179U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14997696377476124836U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14874498694181230698U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4026127545746010937U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2549397729130885686U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4217995818662767955U;
            aOrbiterE = RotL64((aOrbiterE * 5525525344485251063U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4706089044415442525U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 17983900172670031015U;
            aOrbiterA = RotL64((aOrbiterA * 541552737180932879U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1904937798143929988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10620877287033139483U;
            aOrbiterI = RotL64((aOrbiterI * 16711012562024287213U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 15681091173163181525U) + RotL64(aNonceWordA, 44U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 2655543246639000084U) ^ RotL64(aNonceWordG, 57U);
            aOrbiterG = RotL64((aOrbiterG * 16686375598149755947U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (RotL64(aOrbiterF, 60U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 58U)) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + RotL64(aNonceWordF, 31U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterF, 43U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 29U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 51U));
            aWandererA = aWandererA + (((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + RotL64(aNonceWordH, 45U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 38U) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14964U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11536U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 20U) ^ RotL64(aNonceWordH, 47U)) ^ RotL64(aNonceWordF, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10363U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11170U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCarry, 24U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 6U)) + 8767379393098711499U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 7168159491580816433U;
            aOrbiterD = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 9879279829061883406U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 29U)) + 10537167136053399303U) + RotL64(aNonceWordF, 38U);
            aOrbiterG = (aWandererF + RotL64(aScatter, 23U)) + 2839070018069188936U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 13844278063968429732U) + RotL64(aNonceWordD, 43U);
            aOrbiterF = (aWandererA + RotL64(aCross, 53U)) + 11278946626186474646U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11798425216660557799U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 7618446090703335192U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7168757300685156779U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 695423597006983660U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14344728202803488813U) ^ aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5168825904902285909U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 11656100506575697086U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 10384358779985773937U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 247494692039140973U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17585001605131977341U) + RotL64(aNonceWordB, 27U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 9964478171465522911U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13484044854790175315U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2710943171829692624U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17809072853457153057U;
            aOrbiterG = RotL64((aOrbiterG * 16341884203303271365U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12814092033910687774U) + RotL64(aNonceWordG, 45U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1743186323268668740U;
            aOrbiterJ = RotL64((aOrbiterJ * 11150822630624332557U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 10750472346626754704U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15925901217078035356U;
            aOrbiterF = RotL64((aOrbiterF * 9276504171291801637U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 26U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 37U)) + RotL64(aNonceWordC, 37U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 20U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterH) + RotL64(aOrbiterD, 44U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 5U)) + aOrbiterA) + RotL64(aNonceWordA, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 21U)) + aOrbiterG) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordB, 58U)) ^ RotL64(aNonceWordF, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18721U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 19630U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordA, 28U)) ^ RotL64(aNonceWordG, 3U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19399U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20377U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 40U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aPrevious, 21U)) + 964165145848253292U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 10645976767204934746U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 41U)) + 8241612229349212650U) + RotL64(aNonceWordB, 43U);
            aOrbiterK = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 4159196033256913347U;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 7194795864620233507U) + aOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aIngress, 3U)) + 7638928444536778384U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 54U)) + 11819105916503968109U) + aOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1]) + RotL64(aNonceWordC, 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18052213302858186237U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8663575313970041570U;
            aOrbiterH = RotL64((aOrbiterH * 14131073322476609161U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16644136720439299786U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 16930316530442679864U;
            aOrbiterA = RotL64((aOrbiterA * 2650922074098320859U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16251107616988250593U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7171986193609401665U;
            aOrbiterI = RotL64((aOrbiterI * 3543709971414550087U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17885046834432626644U) + aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7757069274715713557U;
            aOrbiterK = RotL64((aOrbiterK * 15766885299397923879U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2212805322061155615U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6368539134638838822U) ^ RotL64(aNonceWordA, 27U);
            aOrbiterF = RotL64((aOrbiterF * 13383744883433594259U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 5264326094252925613U) + aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6126345334815012938U) ^ RotL64(aNonceWordE, 9U);
            aOrbiterC = RotL64((aOrbiterC * 17180934809764905307U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13826731214018407061U) + aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 6621261811613643620U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2823596473596114171U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterA) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 36U) + RotL64(aOrbiterF, 43U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + RotL64(aNonceWordH, 48U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterC, 37U)) + RotL64(aNonceWordG, 35U));
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 6U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 19U) ^ RotL64(aNonceWordA, 37U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27466U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28557U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordF, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27450U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 30408U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aCross, 53U)) + 12632404972795375757U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 5351879979055988456U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 41U)) + 3597737727467443413U) + RotL64(aNonceWordE, 51U);
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 2830846754917852318U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 26U)) + 17311925960294518018U) + aOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 24U);
            aOrbiterA = ((aWandererG + RotL64(aScatter, 19U)) + 2083584640523695383U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aCross, 43U)) + 15049343611387010158U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 6443050378205811147U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6021965178697344070U;
            aOrbiterJ = RotL64((aOrbiterJ * 6054064448935006741U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5080289878758029976U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 576927745306972983U;
            aOrbiterA = RotL64((aOrbiterA * 16008958833683246115U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4728489691382690859U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6184355840165758855U) ^ RotL64(aNonceWordH, 23U);
            aOrbiterD = RotL64((aOrbiterD * 1515043910404156423U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 11220539885798595450U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11091438724966718214U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8225347114759391961U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17184210490020062419U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 2150997767099116408U) ^ RotL64(aNonceWordC, 49U);
            aOrbiterI = RotL64((aOrbiterI * 8058553821648892499U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7021953562676903717U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 17159676348343312834U) ^ aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13877284519668483549U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10367891770525239784U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11922478487264201233U;
            aOrbiterH = RotL64((aOrbiterH * 9195137452661956029U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 21U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 10U));
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + RotL64(aOrbiterD, 26U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterK, 3U));
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 53U)) + aOrbiterD) + RotL64(aCarry, 53U)) + RotL64(aNonceWordA, 25U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + RotL64(aNonceWordG, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_PickleBall_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC7A24980233060ADULL + 0xE6AB4CFB05EED0E2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF976647F932A1A4DULL + 0xEDC4D10341607A81ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xBE02F206531F488FULL + 0xD83032AD9F8BEAD1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF7F83E1B0BF57657ULL + 0xB0EF6B30BCC754FBULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC79718F43CD14959ULL + 0x9AC0BC0BF9A30F4EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9A6AEF3880598DC9ULL + 0xB49287B9093441D6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF607319B406ACEE3ULL + 0xA9477E3CB52F2DB6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBA35547A52B2E73BULL + 0xF0D8DFA80C1685FEULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 21U) ^ RotL64(aNonceWordH, 47U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3059U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 460U)) & S_BLOCK1], 6U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordA, 11U)) ^ RotL64(aNonceWordB, 28U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 977U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7913U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCarry, 34U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 13687218104610230596U) + RotL64(aNonceWordD, 55U);
            aOrbiterF = ((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 6841550124960692709U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 17418968668458764131U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 3U)) + 8303537912696948204U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 19U)) + 12376614417285936537U) + RotL64(aNonceWordE, 24U);
            aOrbiterK = (aWandererJ + RotL64(aScatter, 34U)) + 14215749063579232654U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 27U)) + 4111736931433665347U) + aOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11250375934571631522U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5367367837773331275U;
            aOrbiterA = RotL64((aOrbiterA * 7262723007545807179U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15514089192382674434U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1475991716685034960U;
            aOrbiterJ = RotL64((aOrbiterJ * 17720681295551650891U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5531622777788629748U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8363822215908303335U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17850203366840994883U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3741256932685720414U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11634667238062155772U) ^ RotL64(aNonceWordH, 53U);
            aOrbiterH = RotL64((aOrbiterH * 15925089729784547403U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 18180546911210417155U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5123234656838556335U) ^ RotL64(aNonceWordF, 3U);
            aOrbiterD = RotL64((aOrbiterD * 15362857462853398025U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11215734271189250284U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16863747802158398092U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1828035970246160023U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9859050606636646323U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9331300036643654675U;
            aOrbiterF = RotL64((aOrbiterF * 2502263410556166281U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 27U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 11U));
            aWandererF = aWandererF + (((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterI, 47U)) + aOrbiterK) + RotL64(aNonceWordA, 21U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 41U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + RotL64(aNonceWordG, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 6U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 21U) ^ RotL64(aNonceWordC, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10253U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneD[((aIndex + 11786U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 3U) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13960U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((aIndex + 10101U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 41U)) + (RotL64(aIngress, 29U) + RotL64(aCross, 58U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 53U)) + 6381335981879993247U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 37U)) + 15595429101600023172U;
            aOrbiterG = ((((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 5449234297249826461U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordD, 51U);
            aOrbiterH = ((aWandererC + RotL64(aIngress, 29U)) + 11213734849329731168U) + RotL64(aNonceWordG, 35U);
            aOrbiterF = ((aWandererH + RotL64(aScatter, 60U)) + RotL64(aCarry, 5U)) + 16438473952464514248U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 43U)) + 7357872882115186976U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 3U)) + 394402075160738643U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11112941985410283532U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 14955125011182736212U) ^ RotL64(aNonceWordB, 9U);
            aOrbiterG = RotL64((aOrbiterG * 10711684773326395603U), 53U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterF) + 14770727009821304070U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordH, 12U);
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 11286366598129204910U;
            aOrbiterC = RotL64((aOrbiterC * 15884310771003021989U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7358400908565425780U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15635109923749114761U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12415152149408700329U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 13826842523738623579U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1072811298828325231U;
            aOrbiterD = RotL64((aOrbiterD * 9662800288646215083U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4017334196009350776U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 8812213572751410831U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12744171921566782795U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6723457786170634403U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 9785583533999417673U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7776915427605471097U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10265132640322153964U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8435670887514808087U;
            aOrbiterB = RotL64((aOrbiterB * 2706263045620662131U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 19U);
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterG, 27U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 5U)) + aOrbiterF) + RotL64(aCarry, 3U)) + RotL64(aNonceWordC, 59U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterC, 34U));
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 41U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 13U)) + aOrbiterG) + RotL64(aNonceWordE, 45U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterI, 21U)) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 4U) ^ RotL64(aNonceWordF, 57U)) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23030U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19190U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordE, 57U) ^ RotL64(aNonceWordG, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20836U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19674U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 23U)) + (RotL64(aIngress, 40U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererF + RotL64(aScatter, 57U)) + 11521331427196538632U;
            aOrbiterJ = (((aWandererH + RotL64(aCross, 6U)) + 16653824187682957632U) + aOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 35U);
            aOrbiterB = (aWandererG + RotL64(aPrevious, 51U)) + 11654676587350088289U;
            aOrbiterH = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 8010313317412193584U) + RotL64(aNonceWordA, 28U);
            aOrbiterC = (aWandererE + RotL64(aScatter, 35U)) + 1108775560502907471U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 243952321439823521U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 2324945800401240403U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9257554497543369657U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 16701314607244592540U) ^ RotL64(aNonceWordB, 7U);
            aOrbiterB = RotL64((aOrbiterB * 8790054741039817107U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3900445848034341782U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 7652316487347103658U;
            aOrbiterJ = RotL64((aOrbiterJ * 11480123491361589799U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 14980368605272070578U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2001165460948764796U;
            aOrbiterA = RotL64((aOrbiterA * 8110980921827107649U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1911044015666991050U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11366207111147818339U;
            aOrbiterH = RotL64((aOrbiterH * 17234439040652553865U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16469329744002456607U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8062793687044950815U;
            aOrbiterC = RotL64((aOrbiterC * 5856142259851144369U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 15364721421972807872U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8979915611483540231U) ^ RotL64(aNonceWordC, 5U);
            aOrbiterI = RotL64((aOrbiterI * 10899377466171153383U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7654234623563110457U) + aOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1526832460342135008U;
            aOrbiterK = RotL64((aOrbiterK * 12766083052650723051U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterK, 41U)) + RotL64(aNonceWordG, 9U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 44U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterC, 35U)) + RotL64(aNonceWordD, 15U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 3U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterH, 47U));
            aWandererE = aWandererE + (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 60U)) + aOrbiterJ) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 28U) ^ RotL64(aNonceWordB, 47U)) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28108U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29987U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 37U) ^ RotL64(aNonceWordH, 54U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28371U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 28704U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 4U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aScatter, 12U)) + 8975885703279267062U) + RotL64(aNonceWordG, 7U);
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 13U)) + 8664844915562660637U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 12281774799736296726U) + RotL64(aNonceWordE, 5U);
            aOrbiterG = ((aWandererB + RotL64(aIngress, 19U)) + 15347461352311329726U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 57U)) + 12967500561828907834U) + aOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 5002833859280402726U;
            aOrbiterH = (aWandererE + RotL64(aCross, 41U)) + 11908257536954668983U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 17017174811949227162U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16851323125613931180U;
            aOrbiterJ = RotL64((aOrbiterJ * 12446990992858763577U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13469326957728686706U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5228638551056105241U) ^ RotL64(aNonceWordC, 12U);
            aOrbiterF = RotL64((aOrbiterF * 13369947664646167255U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11945166198089308564U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16268645041872996022U;
            aOrbiterD = RotL64((aOrbiterD * 5391448793718370911U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14781204627695095701U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 5365325354838101092U) ^ RotL64(aNonceWordF, 55U);
            aOrbiterI = RotL64((aOrbiterI * 8017284997946310807U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 563147416025715953U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 14660867395395625851U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4769458126865307103U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3168989056355712105U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16179131669773665579U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5641461617066671723U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4160220074225527179U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8597134686962559111U;
            aOrbiterH = RotL64((aOrbiterH * 639572585431474015U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 27U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 41U));
            aWandererD = aWandererD + (((RotL64(aCross, 19U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterB, 26U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 26U) + RotL64(aOrbiterB, 47U)) + aOrbiterD) + RotL64(aNonceWordH, 31U));
            aWandererH = aWandererH ^ ((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterG, 19U)) + RotL64(aNonceWordB, 21U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 36U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 43U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_PickleBall_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCAF6014570C8BEF9ULL + 0x89E080F185FC8C49ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA78B8FF46469D077ULL + 0x8F08509C93E0DBFEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC80A3DABA2D9199DULL + 0x901F5C0051951B05ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9EFBB8E3C06B6515ULL + 0xE60FE804D083B9FAULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE1E02B09B4596733ULL + 0xD9F81C14462C7FC1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x81B62E40E0657911ULL + 0x981469FF3F8A3A49ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xC30958165DCF0E89ULL + 0xAED195B2B0729738ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE413E69959D5CD1BULL + 0x88299B8658F7498DULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 23U) ^ RotL64(aNonceWordE, 43U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4969U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1377U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 40U) ^ RotL64(aNonceWordH, 53U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7289U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 7720U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aIngress, 43U)) ^ (RotL64(aPrevious, 11U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aCross, 51U)) + 18180797995100240808U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 4U)) + 6585906608223552885U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 14088708930575939855U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 53U)) + 468974153311516044U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 21U)) + 12481951025619894110U) + aOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 57U)) + 17227987923860711763U;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 6U)) + 4373962756657477139U) + RotL64(aNonceWordB, 3U);
            aOrbiterD = (((aWandererF + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 2077576476565420951U) + RotL64(aNonceWordC, 19U);
            aOrbiterC = (aWandererG + RotL64(aScatter, 23U)) + 17435011300234663764U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 43U)) + 4118039398293246896U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 29U)) + 13724716599855216683U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12391461204689596339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9900605191533799627U;
            aOrbiterB = RotL64((aOrbiterB * 13553565332531046301U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 972946858824366125U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17247681919694541215U) ^ RotL64(aNonceWordF, 43U);
            aOrbiterI = RotL64((aOrbiterI * 2974639094630445643U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15442851427306771601U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7303586227288294037U;
            aOrbiterA = RotL64((aOrbiterA * 15406402525021428799U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12650358753454105119U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1483710933373510492U;
            aOrbiterH = RotL64((aOrbiterH * 6531763256577221891U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 18065810162229740788U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11311677121338794007U;
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2355285311890287611U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1287783821903407734U;
            aOrbiterC = RotL64((aOrbiterC * 8054011680932255985U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9282654686791135654U) + RotL64(aNonceWordH, 9U);
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15488608017745542551U;
            aOrbiterF = RotL64((aOrbiterF * 7858866274035085123U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 13296835576073421802U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 7127700236018338741U) ^ aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11246173563106014149U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1365928843264598789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7777790578813003657U;
            aOrbiterE = RotL64((aOrbiterE * 10121688100505628161U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 2104270617375082523U) + aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13363764449819651164U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2685452132715528975U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2008038686059197988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 18180797995100240808U;
            aOrbiterG = RotL64((aOrbiterG * 8978998151475372047U), 37U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 28U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 48U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 40U) + aOrbiterC) + RotL64(aOrbiterK, 11U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 13U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 18U)) + aOrbiterI);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterB, 53U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aNonceWordD, 28U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterA, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 21U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aScatter, 54U) + aOrbiterC) + RotL64(aOrbiterH, 57U)) + RotL64(aNonceWordG, 11U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 13U) ^ RotL64(aNonceWordD, 47U)) ^ RotL64(aNonceWordH, 57U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 14285U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9031U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordC, 29U)) ^ RotL64(aNonceWordF, 13U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9525U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 12053U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 19U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aCross, 3U)) + 5576732410244514238U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 58U)) + 2833808925935929629U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 51U)) + 3670188682914544792U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 11U)) + 15759072378887814995U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 41U)) + 13934007231137439994U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 41U)) + 11022225696007690512U) + RotL64(aNonceWordA, 3U);
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 16989177104453635790U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 9256930045263527091U) + RotL64(aNonceWordH, 13U);
            aOrbiterD = (aWandererE + RotL64(aPrevious, 44U)) + 17788596104417068290U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 53U)) + 17044369456673337625U;
            aOrbiterE = (aWandererK + RotL64(aCross, 5U)) + 1310908395523250343U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 12067065689034065422U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 15130844248737512262U;
            aOrbiterG = RotL64((aOrbiterG * 9409499577465934107U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 14532689204495587494U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 8198147292120244178U) ^ RotL64(aNonceWordE, 17U);
            aOrbiterB = RotL64((aOrbiterB * 1418356389507740991U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5485494458627163347U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10830008207150307611U;
            aOrbiterC = RotL64((aOrbiterC * 6526039534042499457U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 17770065502486618029U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6397859353395335459U;
            aOrbiterH = RotL64((aOrbiterH * 14286997752368893825U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 5128700697381508319U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7103394110057060499U) ^ RotL64(aNonceWordG, 47U);
            aOrbiterD = RotL64((aOrbiterD * 5053680689949149633U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16024401282261796979U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12818445221897253410U;
            aOrbiterJ = RotL64((aOrbiterJ * 11450004517784155405U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13386978409145916350U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16740821954556699503U;
            aOrbiterI = RotL64((aOrbiterI * 5376430209628515105U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 313978038530994953U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1355733685461795345U;
            aOrbiterF = RotL64((aOrbiterF * 15955927322082619735U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12590581077253956064U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2298195367575496005U;
            aOrbiterA = RotL64((aOrbiterA * 17512801361187006363U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11847450675712272468U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5914296379577670282U;
            aOrbiterK = RotL64((aOrbiterK * 14574813500616811367U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 16901317262621287065U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5576732410244514238U) ^ aOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4514943876091531567U), 27U);
            //
            aIngress = RotL64(aOrbiterH, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 12U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterC) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 27U)) + aOrbiterK);
            aWandererG = aWandererG ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterE) + aWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterH, 48U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterF, 37U)) + aOrbiterD) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 3U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterI) + RotL64(aNonceWordC, 24U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 24U)) + aOrbiterC) + RotL64(aNonceWordD, 29U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 50U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 26U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 42U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 51U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19698U)) & S_BLOCK1], 36U) ^ RotL64(aOperationLaneA[((aIndex + 20120U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 57U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordF, 44U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19624U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 21271U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 39U)) ^ (RotL64(aPrevious, 24U) + RotL64(aCarry, 11U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererD + RotL64(aCross, 39U)) + 12136097566601676613U) + RotL64(aNonceWordD, 43U);
            aOrbiterB = (aWandererA + RotL64(aPrevious, 41U)) + 7969431322248040056U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 27U)) + 10530676021510553889U) + aOrbiterAssignSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aIngress, 19U)) + 8740777303075445264U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 13249434169895564739U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 50U)) + RotL64(aCarry, 11U)) + 15529577005925628472U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 11U)) + 344627093687331562U;
            aOrbiterH = (aWandererI + RotL64(aCross, 29U)) + 8824277416519988893U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 57U)) + 5636276438449709875U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 6U)) + 2079413361031851552U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 19U)) + 7807998179168655561U) + RotL64(aNonceWordF, 4U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13589392896232029112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10733011474804473996U;
            aOrbiterK = RotL64((aOrbiterK * 361749145931578805U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15934162328347805968U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 7573511217796245232U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]) ^ RotL64(aNonceWordA, 61U);
            aOrbiterJ = RotL64((aOrbiterJ * 10694563909931636155U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 4828475187337891975U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13284974329890393113U;
            aOrbiterB = RotL64((aOrbiterB * 10831075817642374287U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13173869918669643112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 15841507674783398167U;
            aOrbiterG = RotL64((aOrbiterG * 15632933198136963277U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 14168272451055700516U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11134471485501999898U) ^ RotL64(aNonceWordH, 57U);
            aOrbiterH = RotL64((aOrbiterH * 8019507184494591705U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 2611858916687822610U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 17863271539727513641U;
            aOrbiterA = RotL64((aOrbiterA * 4987884722174985677U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8874401993454249066U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5131480593493950665U;
            aOrbiterC = RotL64((aOrbiterC * 8585874663602346121U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 9366563022381918996U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7890729519928340296U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11428572374057899517U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 131774386529223292U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 4108356674478240148U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2492753294539081613U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7651738365157869789U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2745458108574051004U;
            aOrbiterI = RotL64((aOrbiterI * 2175955806036373729U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10492013124307434604U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12136097566601676613U;
            aOrbiterD = RotL64((aOrbiterD * 13128652803485742119U), 43U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 20U));
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 10U)) + aOrbiterF) + RotL64(aNonceWordE, 35U));
            aWandererH = aWandererH + (((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterC, 37U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterH, 18U)) + aWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 39U)) + aOrbiterH);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + RotL64(aNonceWordB, 17U));
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 34U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 11U) ^ RotL64(aNonceWordD, 39U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29145U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 28390U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 14U) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24592U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((aIndex + 26129U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 53U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 26U)) + RotL64(aCarry, 37U)) + 13350544654542863236U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 37U)) + 12364346790125404372U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 47U)) + 9738750172849512764U) + aOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 19U)) + 3781373837635491421U) + RotL64(aNonceWordC, 35U);
            aOrbiterK = ((aWandererB + RotL64(aCross, 57U)) + 16635020317512702337U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 4U)) + RotL64(aCarry, 41U)) + 5383653921676231276U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 23U)) + 10181959815492056493U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 39U)) + 10005510924273927017U) + RotL64(aNonceWordB, 59U);
            aOrbiterF = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 9524687662265740565U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 13U)) + 4259138552009771014U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 51U)) + 8973051213213726023U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17602611840127337490U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8218984546932905269U;
            aOrbiterD = RotL64((aOrbiterD * 17504305273683304231U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 18102186122213487888U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 2629927500298092976U) ^ RotL64(aNonceWordG, 30U);
            aOrbiterK = RotL64((aOrbiterK * 6983280164448292723U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2491581597835795234U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9506602492971620955U;
            aOrbiterJ = RotL64((aOrbiterJ * 9559829640915637163U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13422942713680612924U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15037354693234876601U;
            aOrbiterE = RotL64((aOrbiterE * 12692376075738621447U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12896066842192894694U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2202952306291905855U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6779368532763429997U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 12160313482450599313U) + RotL64(aNonceWordE, 47U);
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10812986281270407756U;
            aOrbiterF = RotL64((aOrbiterF * 7786608700746771809U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12474638293190144525U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5882870951276225224U;
            aOrbiterI = RotL64((aOrbiterI * 15532427302173572457U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3782896138051179209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10965680631059882311U;
            aOrbiterB = RotL64((aOrbiterB * 14060923998307082385U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15650420683333746952U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4110674660963676864U;
            aOrbiterA = RotL64((aOrbiterA * 11724979274890265275U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 694817156953099464U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4402927404825116007U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 579586789292520113U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 6849178151532923489U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13350544654542863236U;
            aOrbiterH = RotL64((aOrbiterH * 2416097748778941523U), 27U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterF, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterA, 58U)) + aWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterA, 21U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 47U)) + aOrbiterB) + RotL64(aNonceWordH, 5U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aCross, 18U) + aOrbiterK) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 35U)) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterE, 56U)) + RotL64(aNonceWordD, 55U)) + aWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 20U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEB76FAA9294EBB3FULL + 0xBBC4EFB88C3B70CAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBDCFA7EC08A96CBBULL + 0xD0F08D6BCD454B5EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA7A5FC69194FF4D5ULL + 0x915D70C71D9F6899ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9AE85C443221FB4DULL + 0x9D71909E3A5EA90BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9913A28CB3F8E6DFULL + 0xCE52143318828A9DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA37E782B4B3817D9ULL + 0xCB2E777014AC1C3DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD0EBB3FAB872DAADULL + 0x97521A0B71C2EBDFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA0B5488B541F8FA3ULL + 0x87953EB5673B9AD2ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 24U) ^ RotL64(aNonceWordD, 13U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1453U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((aIndex + 5280U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 3U) ^ RotL64(aNonceWordA, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4316U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4100U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 14U) ^ RotL64(aCarry, 29U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 12046647397183218524U;
            aOrbiterG = (((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 2760779375026461991U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 13735454443176855650U) + RotL64(aNonceWordH, 13U);
            aOrbiterE = ((aWandererE + RotL64(aCross, 52U)) + RotL64(aCarry, 35U)) + 4370377000586647724U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 11U)) + 14566322384189969094U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 39U)) + 5056565959818422786U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aScatter, 23U)) + 8795403810686579209U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 60U)) + 9625947666256011567U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 47U)) + 1703669290934254701U) + RotL64(aNonceWordF, 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6664070663184147951U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2104148316797553431U;
            aOrbiterI = RotL64((aOrbiterI * 12887842067180975983U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 1197910004222596145U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]) + RotL64(aNonceWordA, 9U);
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 9922977170060903197U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13047828062605568603U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2048376210852567829U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12568990647075931409U;
            aOrbiterF = RotL64((aOrbiterF * 9860242601194210927U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 15026894775772902751U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3439447160137900629U;
            aOrbiterH = RotL64((aOrbiterH * 1813754963043785165U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6532671388552829796U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 17261098369835997661U) ^ RotL64(aNonceWordB, 16U);
            aOrbiterJ = RotL64((aOrbiterJ * 568292591215203521U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3171300991007459947U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5935563269327662024U;
            aOrbiterE = RotL64((aOrbiterE * 11271790283157765003U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14290941734320455612U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12371794745736518824U;
            aOrbiterD = RotL64((aOrbiterD * 12208762336145168647U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 8782840145467637373U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 4067525421190366741U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6671002797916227485U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 11854812920571789853U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 17564890418553131451U;
            aOrbiterK = RotL64((aOrbiterK * 16657184504366731805U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + RotL64(aOrbiterB, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 20U) + aOrbiterK) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterE, 22U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + RotL64(aCarry, 51U)) + RotL64(aNonceWordC, 53U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + aWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 14U) + aOrbiterI) + RotL64(aOrbiterD, 51U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 26U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + RotL64(aNonceWordD, 35U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 20U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordB, 29U)) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 7592U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5664U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 38U) ^ RotL64(aNonceWordC, 51U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10771U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8090U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 42U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererB + RotL64(aCross, 35U)) + 18180797995100240808U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 11U)) + 6585906608223552885U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 50U)) + 14088708930575939855U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aIngress, 57U)) + 468974153311516044U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 3U)) + 12481951025619894110U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 39U)) + 17227987923860711763U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 4373962756657477139U) + RotL64(aNonceWordC, 8U);
            aOrbiterC = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 2077576476565420951U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 30U)) + 17435011300234663764U) + RotL64(aNonceWordF, 59U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4118039398293246896U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13724716599855216683U;
            aOrbiterG = RotL64((aOrbiterG * 17556333902751079677U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12391461204689596339U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9900605191533799627U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13553565332531046301U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 972946858824366125U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 17247681919694541215U) ^ aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2974639094630445643U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15442851427306771601U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7303586227288294037U;
            aOrbiterC = RotL64((aOrbiterC * 15406402525021428799U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12650358753454105119U) + aOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 1483710933373510492U) ^ RotL64(aNonceWordD, 9U);
            aOrbiterB = RotL64((aOrbiterB * 6531763256577221891U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 18065810162229740788U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 11311677121338794007U;
            aOrbiterK = RotL64((aOrbiterK * 15116367961682119467U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2355285311890287611U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 1287783821903407734U) ^ RotL64(aNonceWordG, 39U);
            aOrbiterD = RotL64((aOrbiterD * 8054011680932255985U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9282654686791135654U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15488608017745542551U;
            aOrbiterI = RotL64((aOrbiterI * 7858866274035085123U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13296835576073421802U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7127700236018338741U;
            aOrbiterJ = RotL64((aOrbiterJ * 11246173563106014149U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (RotL64(aOrbiterD, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 40U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 56U) + aOrbiterD) + RotL64(aOrbiterG, 10U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterF) + RotL64(aNonceWordH, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 27U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 58U)) + RotL64(aNonceWordA, 49U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterB, 3U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 6U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 12U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 51U) ^ RotL64(aNonceWordH, 41U)) ^ RotL64(aNonceWordA, 4U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13498U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 11810U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 3U) ^ RotL64(aNonceWordB, 30U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14324U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13188U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 54U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 10812151398716051703U) + RotL64(aNonceWordD, 17U);
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 37U)) + 18202551453336003710U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 48U)) + 9434410809101973752U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 19U)) + 12955829998028534045U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aCross, 43U)) + 12271740641929640181U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 57U)) + 14009351527014534752U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 47U)) + 4316296955679133450U) + RotL64(aNonceWordH, 13U);
            aOrbiterH = (aWandererF + RotL64(aScatter, 12U)) + 16473324966997442872U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 23U)) + 15735123324965019802U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17656375090484080236U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16066325053456055298U;
            aOrbiterG = RotL64((aOrbiterG * 17912970706985130327U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 12908968778503516903U) + aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 12761433987676836197U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1023329467480907925U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 12737513138040664509U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14535795767570998392U) ^ RotL64(aNonceWordC, 53U);
            aOrbiterI = RotL64((aOrbiterI * 15560519667062222269U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14370908061811284364U) + RotL64(aNonceWordG, 20U);
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7001358781208669795U;
            aOrbiterC = RotL64((aOrbiterC * 11641248025734015835U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7298578161120090849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10498302152357484629U;
            aOrbiterF = RotL64((aOrbiterF * 13144110412179037175U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 11447343228638006767U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 18284143620422655675U;
            aOrbiterD = RotL64((aOrbiterD * 572862190073605651U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5918253208127360199U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3910541329178205943U;
            aOrbiterB = RotL64((aOrbiterB * 4550654545328228103U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10357053096941367910U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5610891501128498748U;
            aOrbiterH = RotL64((aOrbiterH * 8676370811772047449U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9049881176058575811U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6307599924966452216U;
            aOrbiterK = RotL64((aOrbiterK * 5551444450572055895U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 58U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 60U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterI, 19U)) + RotL64(aNonceWordB, 23U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 28U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterH) + RotL64(aNonceWordE, 11U)) + aWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterD, 5U)) + aOrbiterK);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 34U)) + aOrbiterF) + RotL64(aCarry, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 42U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 47U) ^ RotL64(aNonceWordG, 23U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19428U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17290U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 5U) ^ RotL64(aNonceWordF, 47U)) ^ RotL64(aNonceWordA, 36U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19785U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 19711U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 12U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererI + RotL64(aScatter, 18U)) + RotL64(aCarry, 3U)) + 4204560462077827182U) + aOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 23U)) + 6572370199668594039U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aWandererA + RotL64(aPrevious, 5U)) + 15958999876732622825U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 37U)) + 9969349486879280377U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 57U)) + 15450238998293956181U) + RotL64(aNonceWordF, 51U);
            aOrbiterF = ((aWandererG + RotL64(aCross, 28U)) + RotL64(aCarry, 37U)) + 9128619863683138259U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 11U)) + 5691270563628979565U) + RotL64(aNonceWordE, 48U);
            aOrbiterA = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 5901029710568933106U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 41U)) + 10442738941988588834U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3508116020325721993U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13221917083569767259U;
            aOrbiterB = RotL64((aOrbiterB * 6845108555710135357U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11627915460377128176U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17858261365514253433U;
            aOrbiterD = RotL64((aOrbiterD * 7535577636975884641U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4294837988806295989U) + RotL64(aNonceWordC, 21U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 11242915481585070249U;
            aOrbiterI = RotL64((aOrbiterI * 17540688242763829319U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13030663829236027109U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7451948220723185149U;
            aOrbiterK = RotL64((aOrbiterK * 5191778587712222029U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5575508866505031037U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5161096033789876794U) ^ RotL64(aNonceWordH, 55U);
            aOrbiterH = RotL64((aOrbiterH * 16843827915802461797U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3980482740649505122U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 11188906150207270241U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 408550837615188413U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4435504916461645189U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9970252853543702833U;
            aOrbiterA = RotL64((aOrbiterA * 5829143716916091997U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3766347619186305854U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 11004616087340082895U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14469267845747063735U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17600791542296175812U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2556224430252009744U;
            aOrbiterJ = RotL64((aOrbiterJ * 14469426539907112137U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 12U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 12U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 23U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 35U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterI, 5U)) + RotL64(aNonceWordA, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterB, 28U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordB, 31U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 40U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 52U) ^ RotL64(aNonceWordH, 13U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22959U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 25122U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 19U) ^ RotL64(aNonceWordA, 43U)) ^ RotL64(aNonceWordB, 54U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25456U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 24824U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 28U) ^ RotL64(aPrevious, 41U)) + (RotL64(aIngress, 53U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 51U)) + 14157904117287696136U) + RotL64(aNonceWordF, 60U);
            aOrbiterE = (((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 7369512677371640676U) + aOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 8411250745902073798U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 34U)) + RotL64(aCarry, 35U)) + 5002041814539710275U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 21U)) + 9538041410816283124U) + RotL64(aNonceWordG, 49U);
            aOrbiterJ = (aWandererB + RotL64(aIngress, 11U)) + 5210700103927513061U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 39U)) + 7600709399101287982U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 56U)) + 2366369466696580499U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 43U)) + 5544575244203019109U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8710073749110329779U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15998211310115361630U;
            aOrbiterI = RotL64((aOrbiterI * 15275657696897688955U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15354357553877376422U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10657523549259276169U;
            aOrbiterJ = RotL64((aOrbiterJ * 13695239532898311073U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 10405750198355464768U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 3465819693133515142U) ^ RotL64(aNonceWordB, 13U);
            aOrbiterH = RotL64((aOrbiterH * 14678343718277562799U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16724189641701408630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3484340153620198872U;
            aOrbiterG = RotL64((aOrbiterG * 17247547677520703125U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7420442404884871126U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11138445997256757636U;
            aOrbiterC = RotL64((aOrbiterC * 11167543379937571127U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 1428191560884663125U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 16950093140800653985U) ^ RotL64(aNonceWordE, 11U);
            aOrbiterA = RotL64((aOrbiterA * 4423012306984814805U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17288299075036481960U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13793597915359681028U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9639204979982125757U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 5017972942710079726U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 12409957957614320964U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10273295741911545745U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 12487994181992095174U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 1573393166996612118U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13364311829104520751U), 29U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 52U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterJ) + RotL64(aNonceWordC, 57U));
            aWandererC = aWandererC + ((((RotL64(aCross, 54U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aNonceWordD, 47U)) + aWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ);
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 6U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterA, 51U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aCross, 43U) + RotL64(aOrbiterH, 23U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterH, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 21U) ^ RotL64(aNonceWordA, 56U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29252U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32171U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 19U) ^ RotL64(aNonceWordB, 11U)) ^ RotL64(aNonceWordF, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30829U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27395U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 42U)) + (RotL64(aIngress, 11U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 44U)) + 9654059367478508868U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 13U)) + 6473006635864677427U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1]) + RotL64(aNonceWordD, 57U);
            aOrbiterA = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 6944184481315853243U;
            aOrbiterI = (aWandererA + RotL64(aCross, 3U)) + 4061496421939102306U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 27U)) + 15791809275719085463U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 13U)) + 14050798802646323055U;
            aOrbiterK = (aWandererD + RotL64(aCross, 51U)) + 12072905924741758266U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 19U)) + 17639076509231343896U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 53U)) + 12195388285571234715U) + RotL64(aNonceWordC, 49U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4325404419499496529U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5910567888204238382U;
            aOrbiterA = RotL64((aOrbiterA * 11503787177122206937U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13092940059929942699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 13381962590820308761U) ^ RotL64(aNonceWordB, 9U);
            aOrbiterH = RotL64((aOrbiterH * 6345904465930943295U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15622862439323440527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14027151901132249793U;
            aOrbiterK = RotL64((aOrbiterK * 2273573821630510087U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4584410023907605157U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15763755180625487157U;
            aOrbiterF = RotL64((aOrbiterF * 6755736130607297639U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 17023059745666559199U) + aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5298529579288492971U) ^ RotL64(aNonceWordH, 30U);
            aOrbiterD = RotL64((aOrbiterD * 2483562793328357721U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 2870152867331654736U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12017191100173748848U;
            aOrbiterJ = RotL64((aOrbiterJ * 9958191466506480519U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15899529176182436062U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 16482713846343388735U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 719465695044265601U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12943393531812774449U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9881108254540483225U;
            aOrbiterB = RotL64((aOrbiterB * 8011108108007885059U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3532054586199716750U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7142230313294797435U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14154176174768868421U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterK) + RotL64(aOrbiterI, 10U)) + RotL64(aNonceWordG, 5U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 23U)) + aOrbiterJ) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 52U) + aOrbiterH) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterD, 5U));
            aWandererE = aWandererE + (((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterA, 43U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 30U) + aOrbiterE) + RotL64(aOrbiterA, 28U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + RotL64(aNonceWordF, 55U));
            aWandererC = aWandererC + ((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 30U));
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_PickleBall_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x89125C6143300AEBULL + 0xBE13FF855733DD8DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x89CC16EC41AF02EBULL + 0xF8F8F385D5B02809ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xDEE223B5911FC863ULL + 0xDB18E3357263AA44ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xFC69A2A7200CD829ULL + 0xFB83DE9C0E42861BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x8FA1DDE49EF7A2A3ULL + 0xC6F176957A7A54F1ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB11FBD079F6BD213ULL + 0xF562E0707074EE91ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF682B26809DDAEE3ULL + 0xAE01AA5CD57AE436ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xFBE56D0E03EA7063ULL + 0xA0092D5865426EB7ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 38U) ^ RotL64(aNonceWordE, 23U));
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 3406U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 1560U)) & W_KEY1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordG, 51U)) ^ RotL64(aNonceWordD, 24U));
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 4379U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 1357U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 20U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 2915859148137000694U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 47U)) + 210680583721444425U;
            aOrbiterC = ((aWandererJ + RotL64(aCross, 11U)) + 6668118118775650387U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aScatter, 47U)) + 15794200818099010989U) + aPhaseAOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + RotL64(aNonceWordB, 11U);
            aOrbiterE = (aWandererE + RotL64(aIngress, 3U)) + 6565076707062828369U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 29U)) + 16323164497808856719U) + RotL64(aNonceWordC, 19U);
            aOrbiterD = ((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 7965435318816716560U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7390281030573369017U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2269738866911824875U;
            aOrbiterC = RotL64((aOrbiterC * 1198697877998135567U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9664014216039993873U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 18284857398028357633U;
            aOrbiterE = RotL64((aOrbiterE * 8402008251343393737U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 367667619795303009U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7935945060956274197U;
            aOrbiterG = RotL64((aOrbiterG * 5481786693511955209U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 16683666162337789540U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10655658270998102390U;
            aOrbiterD = RotL64((aOrbiterD * 15231596813382239841U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 8307037916581540297U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 3247742749860703524U) ^ RotL64(aNonceWordA, 49U);
            aOrbiterK = RotL64((aOrbiterK * 15052136713218656641U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10446792483683818139U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16374602929344972364U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12599903932725787599U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 2411334498322777183U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 1093701164116833765U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ RotL64(aNonceWordF, 37U);
            aOrbiterH = RotL64((aOrbiterH * 13129220206835381729U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 43U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 22U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterI, 29U)) + aPhaseAWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aPhaseAWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterG, 11U));
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterD, 60U)) + RotL64(aNonceWordE, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 51U)) + aOrbiterE) + RotL64(aNonceWordG, 44U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 38U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 22U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordH, 5U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6035U)) & S_BLOCK1], 51U) ^ RotL64(mSource[((aIndex + 8805U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 4U) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8592U)) & W_KEY1], 51U) ^ RotL64(aKeyRowReadB[((aIndex + 7011U)) & W_KEY1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 41U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 28U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 5U)) + 12222235191147985484U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 21U)) + 16367317014523328414U) + aPhaseAOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 3511378091284703789U) + RotL64(aNonceWordD, 49U);
            aOrbiterE = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 15247492830966725949U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 50U)) + RotL64(aCarry, 5U)) + 7745995913390407897U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 41U)) + 6463593307540108810U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 27U)) + 1101669311005268630U) + RotL64(aNonceWordB, 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12988052764067518580U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17717179747434679772U;
            aOrbiterH = RotL64((aOrbiterH * 10820310705487638793U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 11662190906682400416U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 6563014073547628748U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16967910471722117761U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13099094932059419219U) + RotL64(aNonceWordA, 8U);
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16342730862261868847U;
            aOrbiterE = RotL64((aOrbiterE * 10988124108686164829U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16855346813127524624U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6570063128502306944U;
            aOrbiterJ = RotL64((aOrbiterJ * 4571570049463124831U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 11328352033809240501U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11640986648833160901U;
            aOrbiterF = RotL64((aOrbiterF * 2895830492089678919U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2675226158571501666U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17700531248266458165U;
            aOrbiterA = RotL64((aOrbiterA * 2231403813970188657U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterE) + 7729597396731910874U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordH, 7U);
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15172374484412053756U;
            aOrbiterB = RotL64((aOrbiterB * 149009041406406517U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 3U)) + aPhaseAWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 47U));
            aWandererF = aWandererF + ((RotL64(aIngress, 20U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterE) + RotL64(aNonceWordE, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererE = aWandererE + (((((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 40U)) + aOrbiterH) + RotL64(aCarry, 19U)) + RotL64(aNonceWordG, 39U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 58U) ^ RotL64(aNonceWordG, 3U)) ^ RotL64(aNonceWordA, 11U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11911U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16332U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordE, 29U));
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 11057U)) & W_KEY1], 21U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 11248U)) & W_KEY1], 38U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 24U)) ^ (RotL64(aCross, 11U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aScatter, 36U)) + 10404808878585437255U;
            aOrbiterG = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 10587858736301591439U) + RotL64(aNonceWordH, 58U);
            aOrbiterF = (aWandererK + RotL64(aPrevious, 27U)) + 1430530909801644435U;
            aOrbiterC = (aWandererE + RotL64(aCross, 21U)) + 9090938022430118902U;
            aOrbiterD = (((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 12936604311751121235U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aPrevious, 53U)) + 1000583006020232032U;
            aOrbiterJ = ((((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 12352532088997042232U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + RotL64(aNonceWordF, 17U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16723410947058502564U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 16614089235313154270U;
            aOrbiterF = RotL64((aOrbiterF * 11530998303573027827U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 4245553025593349277U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3353146318549477494U;
            aOrbiterG = RotL64((aOrbiterG * 14246377408238318091U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 5935727336135635196U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10312187090293319667U;
            aOrbiterK = RotL64((aOrbiterK * 1395964500396711899U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12192843181244744484U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2542570124502586365U;
            aOrbiterC = RotL64((aOrbiterC * 17222847847573534963U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 3315472769469002444U) + RotL64(aNonceWordE, 23U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 17512858811783071174U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9070400454074283765U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 16633218007427888082U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2502077714838858460U;
            aOrbiterA = RotL64((aOrbiterA * 970762420815997725U), 57U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 14792910273226469214U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + RotL64(aNonceWordD, 51U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15739513291150783151U;
            aOrbiterJ = RotL64((aOrbiterJ * 11896279674116906915U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 5U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 50U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aPhaseAWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 37U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterC, 21U)) + RotL64(aNonceWordG, 9U)) + aPhaseAWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterJ, 44U));
            aWandererK = aWandererK + (((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterC, 57U)) + RotL64(aNonceWordC, 43U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 11U) ^ RotL64(aNonceWordA, 40U)) ^ RotL64(aNonceWordG, 57U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20487U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21599U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 29U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordH, 44U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20602U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18749U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 24U)) + (RotL64(aCarry, 53U) + RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 12809562813316740345U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 17084212535326321199U) + RotL64(aNonceWordC, 9U);
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 28U)) + 16074921689983846769U;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 14027986153007120145U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 57U)) + 7633455951809250227U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 5U)) + 340989348513370174U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aCross, 43U)) + 5307820377645020116U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + RotL64(aNonceWordG, 15U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5605285015771527274U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5293500434746182790U;
            aOrbiterJ = RotL64((aOrbiterJ * 17674669610895537063U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7263156475892261811U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 10672879570907433005U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2506338667179450741U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 16659226780900986107U) + RotL64(aNonceWordE, 34U);
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9774892622769850665U;
            aOrbiterD = RotL64((aOrbiterD * 7487477727543183211U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10728057184108279042U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 5032485856947407217U;
            aOrbiterF = RotL64((aOrbiterF * 16651577903809154285U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14642241075374862345U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8386481273395203518U;
            aOrbiterB = RotL64((aOrbiterB * 11649977733867003445U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2874153265304098104U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 11519900149177261000U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2010158758971864505U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 8885690878540115768U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordF, 27U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 4482143389870987714U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7105332459437434281U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 60U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 27U) + RotL64(aOrbiterD, 41U)) + aOrbiterI) + RotL64(aNonceWordA, 39U)) + aPhaseAWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 18U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterB, 53U)) + aPhaseAWandererUpdateSaltC[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + RotL64(aNonceWordD, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterI) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterC, 5U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 43U) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26807U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24851U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 36U) ^ RotL64(aNonceWordH, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24369U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 25992U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 38U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererJ + RotL64(aIngress, 35U)) + 4773124477323378268U;
            aOrbiterE = (((aWandererB + RotL64(aCross, 12U)) + RotL64(aCarry, 19U)) + 16848723289435796005U) + RotL64(aNonceWordC, 22U);
            aOrbiterD = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 13846642134917107058U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 6472057872482789939U) + aPhaseAOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aScatter, 3U)) + 2747019500690707226U) + aPhaseAOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1]) + RotL64(aNonceWordF, 23U);
            aOrbiterI = (aWandererI + RotL64(aIngress, 53U)) + 9003965289739733880U;
            aOrbiterF = (aWandererF + RotL64(aCross, 41U)) + 3013390651936257377U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 3331004709895625067U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15355010435553517129U;
            aOrbiterD = RotL64((aOrbiterD * 8322759117004876831U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7709870658004280052U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13568728443963926564U;
            aOrbiterK = RotL64((aOrbiterK * 6736090830113688981U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12409548853419307131U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 969183352023661537U;
            aOrbiterB = RotL64((aOrbiterB * 5549220554838837145U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15370309834426476775U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3896803894396631184U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11018830202891911603U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 10848873633291935766U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12885336509190543440U) ^ RotL64(aNonceWordA, 5U);
            aOrbiterG = RotL64((aOrbiterG * 1487357252619221365U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 8252290890093788010U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) + RotL64(aNonceWordB, 17U);
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 9201553615601641350U;
            aOrbiterI = RotL64((aOrbiterI * 420321130559162915U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14014209645503188472U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 4015071464301844550U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17444195018239904971U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterG, 58U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 37U)) + aOrbiterF) + RotL64(aCarry, 23U)) + RotL64(aNonceWordE, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterE, 51U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 29U)) + aOrbiterD) + RotL64(aNonceWordG, 51U)) + aPhaseAWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 36U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 51U) ^ RotL64(aNonceWordC, 23U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27386U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32486U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordH, 44U)) ^ RotL64(aNonceWordF, 21U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27329U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27484U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 51U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 21U)) + 4384716820085860551U;
            aOrbiterG = (aWandererE + RotL64(aCross, 58U)) + 9715780315942116888U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 35U)) + RotL64(aCarry, 23U)) + 15963520052789178632U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 3U)) + 14346700690686392938U) + aPhaseAOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 6005518012489966643U;
            aOrbiterB = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 2506732930310252119U) + RotL64(aNonceWordC, 41U);
            aOrbiterA = (((aWandererI + RotL64(aScatter, 13U)) + 16782163084851775826U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + RotL64(aNonceWordF, 17U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 823673076571076303U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 1634084509064077736U) ^ RotL64(aNonceWordD, 43U);
            aOrbiterH = RotL64((aOrbiterH * 1128407326773234517U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 1288134975466877686U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2998220403162908444U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4321412662318298283U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 220430672180734911U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10223923547068528867U;
            aOrbiterB = RotL64((aOrbiterB * 12577370238343872139U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 11696469696177647608U) + RotL64(aNonceWordB, 23U);
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6545430420379636963U;
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 79691451831797107U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8971444023498649419U;
            aOrbiterD = RotL64((aOrbiterD * 7148919880477390009U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 5624403902454498793U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9468064161002030997U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8243560528100864595U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4619361544913629805U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12682446273369750704U;
            aOrbiterG = RotL64((aOrbiterG * 10879074713156075641U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 51U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aNonceWordG, 49U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 23U)) + RotL64(aNonceWordE, 28U)) + aPhaseAWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterG, 43U));
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterH, 19U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_PickleBall_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEA0180568116CB0FULL + 0x90B6C6C290AFCE77ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC61C91804AF53861ULL + 0xEE37FC041A4DF871ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBC0A404BB9AD0E19ULL + 0x856DB94D502BEDD6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB19918D83D5A9C73ULL + 0xC6ED06F55B85013AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE48E135C26939FB5ULL + 0xFB25464BC0981962ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE35A14CE5DE86F0FULL + 0xBE24E0D72826F903ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xCC701F0822BD2201ULL + 0xCC8D904B5443374DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8AEA2A5CDE2903A9ULL + 0x99670AF9E4015709ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 37U) ^ RotL64(aNonceWordF, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2915U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((aIndex + 5146U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 40U) ^ RotL64(aNonceWordB, 57U)) ^ RotL64(aNonceWordE, 11U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5223U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1567U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aIngress, 39U)) ^ (RotL64(aCarry, 27U) + RotL64(aPrevious, 14U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (aWandererF + RotL64(aScatter, 27U)) + 8506388683755208267U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 4U)) + RotL64(aCarry, 41U)) + 2179323259055019735U) + aPhaseBOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = ((((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 3345902531140983016U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordB, 19U);
            aOrbiterF = ((aWandererK + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 17456139311481306584U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 39U)) + 14587864088462311164U) + RotL64(aNonceWordD, 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 13178947246650647057U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 12866578138946916962U) ^ RotL64(aNonceWordF, 56U);
            aOrbiterI = RotL64((aOrbiterI * 121991325166969319U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13098524333655118173U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15451329483787541982U;
            aOrbiterC = RotL64((aOrbiterC * 13580376920467431451U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9494299579678389385U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15581954810375490643U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13670002280188424825U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4487042505730624892U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2774455928791636186U) ^ RotL64(aNonceWordA, 25U);
            aOrbiterE = RotL64((aOrbiterE * 15847933919136777451U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12435319582397755819U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 10077180055177766823U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3924363471701748703U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 18U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + RotL64(aCarry, 21U)) + RotL64(aNonceWordG, 59U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 46U) + aOrbiterC) + RotL64(aOrbiterF, 5U)) + RotL64(aNonceWordC, 9U)) + aPhaseBWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterE, 48U)) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterD, 21U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 13U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordG, 34U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5746U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5907U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 39U) ^ RotL64(aNonceWordH, 21U)) ^ RotL64(aNonceWordA, 50U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7664U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 6424U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 20U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = (aWandererB + RotL64(aPrevious, 11U)) + 12809562813316740345U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 17084212535326321199U;
            aOrbiterD = (((aWandererI + RotL64(aScatter, 52U)) + RotL64(aCarry, 41U)) + 16074921689983846769U) + RotL64(aNonceWordE, 15U);
            aOrbiterG = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 14027986153007120145U) + aPhaseBOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aScatter, 3U)) + 7633455951809250227U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + RotL64(aNonceWordD, 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 340989348513370174U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 5307820377645020116U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8402492604131262157U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 5605285015771527274U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5293500434746182790U;
            aOrbiterK = RotL64((aOrbiterK * 17674669610895537063U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 7263156475892261811U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 10672879570907433005U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1]) ^ RotL64(aNonceWordG, 39U);
            aOrbiterF = RotL64((aOrbiterF * 2506338667179450741U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16659226780900986107U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 9774892622769850665U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7487477727543183211U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10728057184108279042U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 5032485856947407217U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1]) ^ RotL64(aNonceWordF, 19U);
            aOrbiterG = RotL64((aOrbiterG * 16651577903809154285U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterF, 40U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 53U) + RotL64(aOrbiterG, 5U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterD) + RotL64(aNonceWordB, 35U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 34U) + aOrbiterF) + RotL64(aOrbiterA, 40U)) + RotL64(aCarry, 29U)) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererI = aWandererI + (((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 13U)) + aOrbiterK) + RotL64(aNonceWordC, 28U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 27U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordG, 43U)) ^ RotL64(aNonceWordC, 35U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11676U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 13414U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 20U) ^ RotL64(aNonceWordE, 57U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15402U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((aIndex + 13639U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 56U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (((aWandererC + RotL64(aCross, 13U)) + 252059974543142812U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordD, 37U);
            aOrbiterK = ((aWandererI + RotL64(aScatter, 56U)) + RotL64(aCarry, 53U)) + 11690823093681457368U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 19U)) + 13282189752890971123U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 9507416294305708435U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 35U)) + 14053038174390776539U) + RotL64(aNonceWordF, 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14605253312318725009U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 18138286582677863671U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10595905899691011321U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8530091235978489988U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14381731677571170073U) ^ RotL64(aNonceWordG, 47U);
            aOrbiterK = RotL64((aOrbiterK * 11675896999665768253U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 13316413456378978456U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3910529530149320706U) ^ RotL64(aNonceWordA, 23U);
            aOrbiterI = RotL64((aOrbiterI * 16000139333493588429U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6302070286831566901U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12324134652758551396U;
            aOrbiterJ = RotL64((aOrbiterJ * 17136438281540250165U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4773478557638475048U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4031153435446078944U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3876928995240982769U), 3U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 36U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aNonceWordH, 13U));
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + RotL64(aOrbiterC, 41U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 50U)) + aOrbiterJ) + RotL64(aNonceWordB, 24U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 20U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordA, 20U)) ^ RotL64(aNonceWordG, 11U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16643U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 17617U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordH, 19U)) ^ RotL64(aNonceWordD, 39U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19271U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 17141U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 20U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aScatter, 39U)) + 13960289014350612206U) + aPhaseBOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 24U)) + 3483331015269589730U) + RotL64(aNonceWordB, 36U);
            aOrbiterB = ((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 6873299241002444518U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 13U)) + 3562094007125534229U;
            aOrbiterG = ((((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 11422367439932782705U) + aPhaseBOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + RotL64(aNonceWordF, 31U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 532453428514259816U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 17810941465810193088U;
            aOrbiterB = RotL64((aOrbiterB * 2830829128884590275U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11869759058631106331U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 8837581071876177566U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15329827515970522213U), 3U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 17185378327053837778U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + RotL64(aNonceWordE, 61U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7578253375676981500U) ^ RotL64(aNonceWordD, 27U);
            aOrbiterF = RotL64((aOrbiterF * 13371647568758721729U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 17112646434432814442U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 14949096407295697881U;
            aOrbiterH = RotL64((aOrbiterH * 14770977858283051753U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 4259590620758467836U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 6534899413644542303U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7987609419215568661U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 11U)) + aOrbiterE);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + (((((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterF, 58U)) + RotL64(aCarry, 41U)) + RotL64(aNonceWordA, 13U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterB, 47U)) + RotL64(aNonceWordC, 49U));
            aWandererI = aWandererI + (((RotL64(aScatter, 30U) + RotL64(aOrbiterF, 35U)) + aOrbiterG) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 19U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordD, 37U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23340U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 21850U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 41U) ^ RotL64(aNonceWordF, 57U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26392U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((aIndex + 23943U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 13350544654542863236U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aIngress, 48U)) + 12364346790125404372U) + RotL64(aNonceWordB, 48U);
            aOrbiterI = ((((aWandererK + RotL64(aScatter, 11U)) + RotL64(aCarry, 51U)) + 9738750172849512764U) + aPhaseBOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1]) + RotL64(aNonceWordH, 53U);
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 3781373837635491421U;
            aOrbiterB = (aWandererI + RotL64(aCross, 3U)) + 16635020317512702337U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5383653921676231276U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10181959815492056493U;
            aOrbiterI = RotL64((aOrbiterI * 14784636206508715141U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 10005510924273927017U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9524687662265740565U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13687380438646756931U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4259138552009771014U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8973051213213726023U) ^ RotL64(aNonceWordG, 19U);
            aOrbiterH = RotL64((aOrbiterH * 12625091476068190979U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 17602611840127337490U) + RotL64(aNonceWordF, 35U);
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8218984546932905269U;
            aOrbiterK = RotL64((aOrbiterK * 17504305273683304231U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18102186122213487888U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2629927500298092976U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6983280164448292723U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 57U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterK) + RotL64(aNonceWordA, 21U));
            aWandererK = aWandererK + (((((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 27U)) + RotL64(aNonceWordD, 39U)) + aPhaseBWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 14U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + aPhaseBWandererUpdateSaltB[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 37U) ^ RotL64(aNonceWordE, 10U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30483U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 30600U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordF, 30U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30503U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31417U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 40U) ^ RotL64(aIngress, 57U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 13333509828310369865U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 43U)) + 7645352517103840797U) + RotL64(aNonceWordF, 40U);
            aOrbiterI = (((aWandererJ + RotL64(aIngress, 53U)) + 5310766306660062655U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordG, 7U);
            aOrbiterK = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 5U)) + 5165635069832352932U;
            aOrbiterJ = (((aWandererC + RotL64(aIngress, 10U)) + RotL64(aCarry, 41U)) + 15684141764734281849U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 3327963374225061738U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 8625811794878848871U) ^ RotL64(aNonceWordC, 25U);
            aOrbiterI = RotL64((aOrbiterI * 16327750494894125333U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7598657468430485291U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 2881171216276746485U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3331350584102843605U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10237691227222918101U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 6419254255884834497U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3816625473642865305U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4238455444646479956U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterI) ^ 14936613353493061492U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]) ^ RotL64(aNonceWordB, 47U);
            aOrbiterK = RotL64((aOrbiterK * 3544216916806292273U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 15324699725208372627U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9506640480601832011U;
            aOrbiterJ = RotL64((aOrbiterJ * 12819564111348390227U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + RotL64(aNonceWordD, 51U));
            aWandererJ = aWandererJ + (((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 56U)) + aOrbiterD) + RotL64(aCarry, 11U)) + RotL64(aNonceWordH, 39U)) + aPhaseBWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 27U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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

void TwistExpander_PickleBall_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA7E2B2FF7C12BC85ULL + 0xD035E19EBDCE1F6CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xED6747B333477489ULL + 0xC5B7184F6F9771FBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB9F34719F2F51E53ULL + 0x9911079840561D33ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xEE5B6C917B328F49ULL + 0xD85CE7F10ED8E699ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBAC82A7623E76AFBULL + 0xE9215E2AAF22D877ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9057421DFE688AADULL + 0xFE146B90C437B80DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x87DFE6EE9BA2B345ULL + 0xC1012EB539AB3C1EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xFC2EB993188BD9D9ULL + 0xFF085B9429531B38ULL);
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
            aIngress = aIngress ^ (RotL64(aNonceWordH, 28U) ^ RotL64(aNonceWordE, 43U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 426U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5523U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 35U) ^ RotL64(aNonceWordA, 19U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2019U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((aIndex + 2693U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 34U) + RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 7825479804710770560U) + RotL64(aNonceWordF, 21U);
            aOrbiterG = (aWandererC + RotL64(aIngress, 14U)) + 5298124167101358123U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 27U)) + 17774541024369233726U;
            aOrbiterC = (aWandererI + RotL64(aCross, 39U)) + 7679371833537454082U;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 29U)) + 5385914900748772224U) + aPhaseCOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 47U)) + 3879781930908486531U;
            aOrbiterJ = (aWandererF + RotL64(aScatter, 52U)) + 659110346638873236U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 10749021728538539749U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 23U)) + 3631252455767429457U) + aPhaseCOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1]) + RotL64(aNonceWordA, 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2271978810960685021U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5963558780692551176U) ^ RotL64(aNonceWordC, 15U);
            aOrbiterH = RotL64((aOrbiterH * 4772055335210781149U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 974909966119198104U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9296998242911152296U;
            aOrbiterB = RotL64((aOrbiterB * 2613629915877957661U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2245318466901521959U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13391076374843288568U;
            aOrbiterI = RotL64((aOrbiterI * 18094558036982107419U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6184487746594236737U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 1563385912137291418U;
            aOrbiterE = RotL64((aOrbiterE * 4805455299959232321U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 1744840092006498629U) + RotL64(aNonceWordG, 34U);
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2100927276837188416U;
            aOrbiterA = RotL64((aOrbiterA * 3541788262067077997U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9998911862807246338U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 12239948725635220096U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7098620484129489129U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3307447094994950246U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12746613971448298932U;
            aOrbiterJ = RotL64((aOrbiterJ * 9463975886346934681U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11577488293733790649U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 191108997585598809U;
            aOrbiterG = RotL64((aOrbiterG * 9574978681405356871U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 18096145693841273722U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10026281133603934071U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17261343107314203471U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 34U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 37U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterF, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterA, 40U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 13U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 42U) + RotL64(aOrbiterE, 35U)) + aOrbiterH) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 5U)) + RotL64(aNonceWordD, 59U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterG, 30U));
            aWandererG = aWandererG ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aNonceWordB, 61U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 12U) + aOrbiterH) + RotL64(aOrbiterF, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 54U));
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 29U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordG, 13U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14266U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((aIndex + 15110U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 13U) ^ RotL64(aNonceWordH, 30U)) ^ RotL64(aNonceWordA, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11637U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 9778U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 13U)) + (RotL64(aIngress, 26U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 9133751643283278896U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 39U)) + 8971581804375380408U;
            aOrbiterB = (aWandererA + RotL64(aCross, 58U)) + 12559650383714566592U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 23U)) + RotL64(aCarry, 43U)) + 15753206088872859163U) + aPhaseCOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 47U)) + 7640756270450762350U) + RotL64(aNonceWordH, 11U);
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 11U)) + 7340073357551376125U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 5270256573644196046U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 5U)) + 3567367996479995928U) + RotL64(aNonceWordA, 4U);
            aOrbiterF = (aWandererK + RotL64(aCross, 34U)) + 11939634537492733738U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7051817732424527120U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1730487669951837941U;
            aOrbiterB = RotL64((aOrbiterB * 15191634337956285841U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 18009252467909454817U) + RotL64(aNonceWordE, 25U);
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 2361024272031696442U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15215151562500226027U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15902755877642960397U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 12243517544704116184U) ^ RotL64(aNonceWordG, 35U);
            aOrbiterC = RotL64((aOrbiterC * 2576071074148141447U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16846181962302186187U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 636121425116506681U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17075030673338779993U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 6887385655828217318U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3705834550934775862U;
            aOrbiterF = RotL64((aOrbiterF * 11275428284929594435U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 11165142437077969438U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 6426659930331618269U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17170640810530893705U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12629082390899315789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4277510580069574724U;
            aOrbiterA = RotL64((aOrbiterA * 9829125163412708305U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 13814834144170469978U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 3698381854100295826U;
            aOrbiterJ = RotL64((aOrbiterJ * 5126359230872258015U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 11623170635983579937U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7247413650388803796U;
            aOrbiterI = RotL64((aOrbiterI * 3403219499465560059U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 37U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 40U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterC, 50U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 37U)) + RotL64(aNonceWordB, 51U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 3U)) + aOrbiterH) + aPhaseCWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB) + RotL64(aNonceWordC, 45U));
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterE, 58U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 21U)) + aOrbiterF) + aPhaseCWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 50U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererD, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordC, 14U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20041U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23818U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 13U) ^ RotL64(aNonceWordH, 4U)) ^ RotL64(aNonceWordD, 57U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 21736U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19088U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 56U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aCross, 51U)) + 6973892330986118220U) + RotL64(aNonceWordF, 13U);
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 9886813896272094864U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 34U)) + 10996306582517553173U) + RotL64(aNonceWordC, 49U);
            aOrbiterK = (((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 8490648283899856223U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 57U)) + 105141713530704655U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 39U)) + 3114337422810562588U) + aPhaseCOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aCross, 6U)) + RotL64(aCarry, 13U)) + 980857684690886131U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 6562042345807072665U;
            aOrbiterI = (aWandererB + RotL64(aCross, 11U)) + 15665371138706353619U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 18113013571374375028U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + RotL64(aNonceWordD, 39U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17405346422601997299U;
            aOrbiterD = RotL64((aOrbiterD * 11162604605443005253U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5130876096426182506U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 1813821672299154629U) ^ RotL64(aNonceWordE, 47U);
            aOrbiterJ = RotL64((aOrbiterJ * 15478100342425611875U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 15793814882743306728U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13925299440495476399U;
            aOrbiterK = RotL64((aOrbiterK * 12049601510660117401U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9924458846049579438U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7810034662781768090U;
            aOrbiterH = RotL64((aOrbiterH * 10310594595026622513U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12812586478656872854U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5709576448057435237U;
            aOrbiterE = RotL64((aOrbiterE * 9101555233909853025U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7839807649914541516U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4717944526755429647U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8515229146471335721U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3933911971504256022U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 4814079680865379831U;
            aOrbiterG = RotL64((aOrbiterG * 15100740696230557391U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18352577312212175569U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9670612998448920742U;
            aOrbiterA = RotL64((aOrbiterA * 5743579439303300553U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 72737302703035726U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10032869372369626210U;
            aOrbiterI = RotL64((aOrbiterI * 7449905669249993731U), 29U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 44U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterA, 14U)) + RotL64(aCarry, 35U)) + RotL64(aNonceWordG, 46U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 29U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 47U)) + aOrbiterC) + aPhaseCWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 10U) + RotL64(aOrbiterC, 35U)) + aOrbiterK);
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 4U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterG, 51U)) + RotL64(aNonceWordA, 59U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 37U) + aOrbiterK) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 56U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordA, 35U) ^ RotL64(aNonceWordB, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27221U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27940U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordF, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28585U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25825U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 23U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = (((aWandererD + RotL64(aCross, 51U)) + 3248574644570178787U) + aPhaseCOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1]) + RotL64(aNonceWordC, 29U);
            aOrbiterG = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 35U)) + 4506961512959200024U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 8423739774540738590U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 34U)) + 6593975869641735337U;
            aOrbiterC = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 16441716090557369103U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 29U)) + 7936601450453207914U;
            aOrbiterI = (((aWandererG + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 13333752583560167065U) + RotL64(aNonceWordG, 17U);
            aOrbiterK = (aWandererI + RotL64(aScatter, 60U)) + 8013703284795432973U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 13U)) + 2349852779887439236U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5318539364763284138U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11450957608502944376U;
            aOrbiterE = RotL64((aOrbiterE * 1957880366707810635U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9058992558327552687U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 632095686920230926U;
            aOrbiterC = RotL64((aOrbiterC * 12460364388358520799U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 14734218428913777098U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16344357661370784442U;
            aOrbiterI = RotL64((aOrbiterI * 15049472842002138369U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2981145363531184308U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14176472085175714494U) ^ RotL64(aNonceWordD, 21U);
            aOrbiterH = RotL64((aOrbiterH * 2584623327412130939U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11198457590069700889U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 952584436750426828U;
            aOrbiterB = RotL64((aOrbiterB * 1165713888651280355U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 4311591763498985972U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16194341833989936369U;
            aOrbiterA = RotL64((aOrbiterA * 9997934560195932575U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7560794022401107431U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 10683789740265711603U;
            aOrbiterK = RotL64((aOrbiterK * 15637823045351977883U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11614366395125937178U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10750771385100564416U;
            aOrbiterD = RotL64((aOrbiterD * 4987921274272444283U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2934697034132204529U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 4646873794658020363U) ^ RotL64(aNonceWordB, 47U);
            aOrbiterG = RotL64((aOrbiterG * 10555456865641580175U), 35U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 10U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 53U)) + aOrbiterD) + RotL64(aNonceWordE, 40U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterD, 40U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterA, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + RotL64(aNonceWordH, 27U));
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 19U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterE, 4U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 18U) + aOrbiterD) + RotL64(aOrbiterH, 11U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 54U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_PickleBall_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB44D9646CDC07E27ULL + 0x94E9154444D891DDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x91C1632A82A2F7BBULL + 0x8F7D5F1B7B694832ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x985A702EAC5A2943ULL + 0xE9055220899F7E48ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBEA6D17481212DA9ULL + 0xE93C97E1D9922598ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8AD13AC2EE16C2D5ULL + 0xB3077CF8FB82F994ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAE1BA1BB6DB55E5FULL + 0xAAD3145FFC2BAD44ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9AEC5EEC38665FE3ULL + 0xEAEC04EBA05E3ED1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xED84018E54948D59ULL + 0xD58AF382F10D8AABULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordC, 27U)) ^ RotL64(aNonceWordE, 53U));
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 126U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1647U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 50U) ^ RotL64(aNonceWordG, 37U)) ^ RotL64(aNonceWordB, 29U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1384U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2972U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 52U)) ^ (RotL64(aCross, 37U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = ((aWandererF + RotL64(aScatter, 21U)) + 8604208734152026945U) + aPhaseDOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aPrevious, 3U)) + 1374329953253889829U;
            aOrbiterA = (aWandererB + RotL64(aCross, 13U)) + 5779278910548228339U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 44U)) + 17670451230882805140U;
            aOrbiterB = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 11U)) + 8193848740764866860U) + RotL64(aNonceWordC, 55U);
            aOrbiterG = ((aWandererE + RotL64(aIngress, 57U)) + 15801168428145650104U) + RotL64(aNonceWordF, 43U);
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 2584718176087499066U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 54U)) + RotL64(aCarry, 47U)) + 14950366247822737997U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 41U)) + 9779293225265670135U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 11U)) + 8688968319288372383U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aCross, 5U)) + 13665723186950342601U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9395428688359973510U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2152719218018108418U;
            aOrbiterA = RotL64((aOrbiterA * 15271961483518392671U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1350324137411377992U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8729317951386057921U;
            aOrbiterG = RotL64((aOrbiterG * 6008790836417785083U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6317310451893678411U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 10175620379041384281U;
            aOrbiterF = RotL64((aOrbiterF * 14079679617394330781U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1203082119358827708U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 523869107818193101U;
            aOrbiterH = RotL64((aOrbiterH * 4629501113595689157U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 4028324959540432983U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15447631947468213912U;
            aOrbiterJ = RotL64((aOrbiterJ * 6037306615787729185U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 14225888694733041031U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 11925000696281947629U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1]) ^ RotL64(aNonceWordB, 47U);
            aOrbiterC = RotL64((aOrbiterC * 4337022940520411253U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 15015531024930608745U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 16752579225076943550U;
            aOrbiterK = RotL64((aOrbiterK * 15551083683579981439U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2432733494869267901U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 10103430321388601485U;
            aOrbiterD = RotL64((aOrbiterD * 18372919379972432569U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 15943360147468638325U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9782703760233558733U) ^ RotL64(aNonceWordA, 19U);
            aOrbiterB = RotL64((aOrbiterB * 685056980418243879U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18345087852012669037U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 8897505040792027675U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14333687539092412967U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 7402581293947129667U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8604208734152026945U;
            aOrbiterI = RotL64((aOrbiterI * 9965525485538037673U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterK, 4U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 27U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 52U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 27U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterA, 41U)) + RotL64(aNonceWordG, 25U));
            aWandererE = aWandererE + ((RotL64(aCross, 54U) + aOrbiterJ) + RotL64(aOrbiterC, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterG, 30U));
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterI, 39U));
            aWandererB = aWandererB + ((RotL64(aIngress, 36U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + RotL64(aNonceWordE, 36U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + RotL64(aWandererE, 34U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordF, 53U)) ^ RotL64(aNonceWordG, 44U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 5549U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 5784U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 11U) ^ RotL64(aNonceWordE, 26U));
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5729U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7929U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 44U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterI = (((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 15045917390223766480U) + aPhaseDOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 10763054007033668758U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 37U)) + 13190170142593666607U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 9657025731441167065U;
            aOrbiterK = (aWandererJ + RotL64(aScatter, 57U)) + 11433367178975954211U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 14U)) + 17904920143996810366U;
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 23U)) + 3244383020512113283U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 21U)) + 6538815775171139091U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 53U)) + 7195368312757976343U) + RotL64(aNonceWordH, 20U);
            aOrbiterF = (aWandererC + RotL64(aCross, 11U)) + 18134430713910279374U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 60U)) + RotL64(aCarry, 41U)) + 6571776588427107976U) + RotL64(aNonceWordA, 25U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11830778129647517758U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 9793702760907767365U;
            aOrbiterA = RotL64((aOrbiterA * 4096246227968677179U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2287235876793192036U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8951959188326141794U;
            aOrbiterD = RotL64((aOrbiterD * 9968356718110753845U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 7583061790273240157U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 3571364625022806085U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6238360922735480669U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13869345563551689212U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 277480328952975002U) ^ RotL64(aNonceWordD, 53U);
            aOrbiterE = RotL64((aOrbiterE * 1057564597096163085U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4983735092494677578U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 9490022869381030928U;
            aOrbiterB = RotL64((aOrbiterB * 12926352917961703123U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7928039573014765566U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterJ) ^ 6504190875809407084U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordE, 13U);
            aOrbiterI = RotL64((aOrbiterI * 14648214826494826711U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2787985600176307413U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16308785053443116826U;
            aOrbiterC = RotL64((aOrbiterC * 17867565986311256691U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12788128335006767824U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1187040019537798339U;
            aOrbiterG = RotL64((aOrbiterG * 10834905007658184183U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10771230162770496645U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 6542421559654716320U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16829492790597069373U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 702458690970201679U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2806140783487813070U;
            aOrbiterF = RotL64((aOrbiterF * 7415398198842270381U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 950611302199732036U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15045917390223766480U;
            aOrbiterJ = RotL64((aOrbiterJ * 9358017420417979347U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 24U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 60U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + aPhaseDWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 26U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 43U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 3U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterB, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 19U)) + aOrbiterK);
            aWandererF = aWandererF + ((((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 43U)) + aOrbiterC) + RotL64(aCarry, 39U)) + RotL64(aNonceWordG, 49U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 57U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterK) + RotL64(aOrbiterA, 12U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 29U)) + RotL64(aNonceWordB, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 11U));
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 38U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 39U) ^ RotL64(aNonceWordB, 28U)) ^ RotL64(aNonceWordE, 19U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14071U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 10983U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordC, 27U)) ^ RotL64(aNonceWordA, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14207U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 15471U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCross, 21U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 21U)) + 15383045568644941552U) + RotL64(aNonceWordA, 7U);
            aOrbiterJ = (((aWandererK + RotL64(aScatter, 26U)) + RotL64(aCarry, 37U)) + 17452811657750910067U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aCross, 3U)) + 15660117718455155603U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 35U)) + 10396441207743665753U;
            aOrbiterH = (aWandererB + RotL64(aCross, 51U)) + 3708971058200841442U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 7000673057768598750U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 60U)) + 9886354469011131596U) + aPhaseDOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 57U)) + 16018065329058043467U) + RotL64(aNonceWordC, 47U);
            aOrbiterF = (aWandererC + RotL64(aPrevious, 13U)) + 5024756166109352320U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 43U)) + RotL64(aCarry, 3U)) + 6587818720728886652U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 39U)) + 3652672354944162319U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6307315649915348048U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 16405347331742979258U;
            aOrbiterA = RotL64((aOrbiterA * 7183142442906743699U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 5427299664054601957U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 4983381733483185898U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14646556236306407673U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10182995521328377487U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8694282877540593550U;
            aOrbiterJ = RotL64((aOrbiterJ * 14614602561910403893U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4085927978153269932U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6176195962815240877U;
            aOrbiterH = RotL64((aOrbiterH * 16792916528959579875U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6966742100601433005U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9920952446921247521U;
            aOrbiterD = RotL64((aOrbiterD * 1879821050131820933U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 11958734477518336014U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2058335903640404380U;
            aOrbiterE = RotL64((aOrbiterE * 6986170159285417789U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 77366119537297816U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 12072894199692855000U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1]) ^ RotL64(aNonceWordB, 37U);
            aOrbiterG = RotL64((aOrbiterG * 9083781120514635987U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11874297832446385377U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13715562531763053196U;
            aOrbiterB = RotL64((aOrbiterB * 12822488258322963187U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 13664465415354326653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 10365386643010882315U;
            aOrbiterK = RotL64((aOrbiterK * 3687934567254955761U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2003863843075564853U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8864134110143237364U;
            aOrbiterF = RotL64((aOrbiterF * 4586162015675320985U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 8055736412403126985U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + RotL64(aNonceWordH, 24U);
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15383045568644941552U;
            aOrbiterC = RotL64((aOrbiterC * 5175405553995854715U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 27U);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 60U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterA, 58U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 12U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 23U)) + RotL64(aNonceWordF, 45U));
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 43U)) + aOrbiterE) + aPhaseDWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + RotL64(aNonceWordD, 25U));
            aWandererI = aWandererI + ((RotL64(aCross, 34U) + aOrbiterC) + RotL64(aOrbiterG, 38U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + aOrbiterE) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 14U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordB, 43U) ^ RotL64(aNonceWordC, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 21767U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20630U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordH, 21U) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20261U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17046U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 35U)) + (RotL64(aPrevious, 50U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterD = (aWandererB + RotL64(aIngress, 37U)) + 13924571355038625040U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 39U)) + 16328300979357156658U) + RotL64(aNonceWordD, 27U);
            aOrbiterB = (aWandererJ + RotL64(aCross, 47U)) + 3947771961206012461U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 15428284250569311285U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 42U)) + 5777369485254032486U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 27U)) + 16813320300717644673U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 3U)) + 16689933050200758251U) + aPhaseDOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 57U)) + 1856422419049390708U) + aPhaseDOrbiterAssignSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 27U)) + 18214498743831925517U;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 53U)) + 18278550878494094923U) + RotL64(aNonceWordF, 23U);
            aOrbiterG = ((aWandererA + RotL64(aCross, 24U)) + RotL64(aCarry, 43U)) + 797712062039591797U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 15854849439012341347U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 996882939768167773U;
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 3005829974130671692U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8793495343509953906U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14065479348374612031U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7710453029930631112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 9511995836117707047U;
            aOrbiterK = RotL64((aOrbiterK * 7250766204781428201U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 670902975693341744U) + RotL64(aNonceWordA, 41U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9045820304668279777U;
            aOrbiterC = RotL64((aOrbiterC * 18373074917532639027U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12417212387607119470U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 12816983560669985622U;
            aOrbiterF = RotL64((aOrbiterF * 8406003970221889847U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 17245432086377688540U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 6806521945548502014U;
            aOrbiterI = RotL64((aOrbiterI * 11335859481858640857U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 8947500746292365294U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4468060468522895852U;
            aOrbiterE = RotL64((aOrbiterE * 7022481284816599797U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 9892975931958803992U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 3042599331526937836U;
            aOrbiterG = RotL64((aOrbiterG * 3308512896171443645U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 12991568221485810891U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8551331172836260315U;
            aOrbiterD = RotL64((aOrbiterD * 4509997595920847057U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 183547209633334407U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17275712817092769452U;
            aOrbiterJ = RotL64((aOrbiterJ * 15677355290000929085U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 12743863879392372723U) + RotL64(aNonceWordC, 4U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13924571355038625040U;
            aOrbiterH = RotL64((aOrbiterH * 11966689345179279407U), 27U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 24U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 36U) + aOrbiterF) + RotL64(aOrbiterB, 44U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 39U)) + aOrbiterK);
            aWandererH = aWandererH + ((RotL64(aPrevious, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + RotL64(aNonceWordG, 21U));
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 42U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 11U)) + aOrbiterB) + RotL64(aNonceWordE, 53U));
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 3U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 40U) + aOrbiterE) + RotL64(aOrbiterI, 57U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordF, 29U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22230U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 25764U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordH, 37U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24549U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneA[((aIndex + 24895U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aPrevious, 11U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererI + RotL64(aIngress, 12U)) + 5573188770530340913U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 1431772230889897111U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 3U)) + 4809192776429682319U;
            aOrbiterH = (aWandererB + RotL64(aCross, 43U)) + 5576603692574369341U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 19U)) + 2720143226007220386U) + RotL64(aNonceWordC, 15U);
            aOrbiterI = (aWandererA + RotL64(aCross, 41U)) + 17220328778565331629U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 9629485808442089423U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 46U)) + 1136998437010390983U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 11893390497814523841U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 29U)) + 1764986431917532370U) + aPhaseDOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 27U)) + 1741014798007010376U) + RotL64(aNonceWordD, 55U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12221368453236547044U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7694538641172350430U) ^ RotL64(aNonceWordH, 51U);
            aOrbiterA = RotL64((aOrbiterA * 8439120733670016501U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 17472344518811560603U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 3308740700728172984U) ^ RotL64(aNonceWordB, 29U);
            aOrbiterI = RotL64((aOrbiterI * 15290400462887712083U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9535358833412446771U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11192312491731312451U;
            aOrbiterK = RotL64((aOrbiterK * 17405609148475445743U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14850451970047190039U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11932493299452443256U;
            aOrbiterD = RotL64((aOrbiterD * 7964808728820467795U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5972619895614731870U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17174497535809891690U;
            aOrbiterF = RotL64((aOrbiterF * 15471084511364572533U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17412894714378898351U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 14675615208706549810U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7864845089606499769U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16116792108013658523U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9702262005960966336U;
            aOrbiterE = RotL64((aOrbiterE * 970452849653781703U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17337264966818542841U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 7004462033775827275U;
            aOrbiterC = RotL64((aOrbiterC * 11943575980344402681U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 17499850384482055438U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1839357713256560566U;
            aOrbiterB = RotL64((aOrbiterB * 12943750650487416281U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8144238113917577524U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 888195876227325908U;
            aOrbiterJ = RotL64((aOrbiterJ * 7941506708630993709U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5081763359501717653U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5573188770530340913U;
            aOrbiterG = RotL64((aOrbiterG * 9699901099898698965U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 56U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterD, 5U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 43U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 57U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterK) + RotL64(aNonceWordE, 31U)) + aPhaseDWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 56U) + aOrbiterG) + RotL64(aOrbiterC, 3U));
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterD, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 38U)) + aOrbiterF) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterG, 47U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 11U));
            aWandererD = aWandererD + (((RotL64(aCross, 30U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterA, 60U)) + aOrbiterB) + RotL64(aNonceWordA, 40U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 50U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 35U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 56U) ^ RotL64(aNonceWordD, 47U)) ^ RotL64(aNonceWordH, 3U));
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29300U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 27357U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 27U) ^ RotL64(aNonceWordC, 53U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28201U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((aIndex + 31012U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 34U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterC = ((((aWandererK + RotL64(aIngress, 12U)) + RotL64(aCarry, 11U)) + 6361545377408870615U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + RotL64(aNonceWordF, 49U);
            aOrbiterI = (aWandererE + RotL64(aScatter, 29U)) + 2967245486744774933U;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 27U)) + 3836634268482850139U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 7691642115360086297U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 16479280384178279281U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 57U)) + 2901468732552539249U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 43U)) + 2600353867755647475U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1]) + RotL64(aNonceWordB, 55U);
            aOrbiterJ = (aWandererA + RotL64(aCross, 3U)) + 5666596904781510956U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 37U)) + 16108791609267427553U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 60U)) + 8389926875737312112U;
            aOrbiterF = (aWandererH + RotL64(aCross, 35U)) + 1689501721163024426U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11721701506949917719U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 3963842745030140473U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6692473494944919373U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 8510538243472109368U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 18281865214102080387U;
            aOrbiterK = RotL64((aOrbiterK * 1351546966368884609U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 2259725140963665123U) + RotL64(aNonceWordH, 17U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11652011949557979650U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11260100762113295037U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1116085424226174473U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4725260319270802912U;
            aOrbiterA = RotL64((aOrbiterA * 4697109059565450269U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7348945429843437036U) + RotL64(aNonceWordC, 59U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1249234309180653260U;
            aOrbiterJ = RotL64((aOrbiterJ * 3136745255820405881U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 12463505532573389603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 2304125977906510386U;
            aOrbiterH = RotL64((aOrbiterH * 9960816714791454421U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2178037443783425551U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11712110130079307683U;
            aOrbiterB = RotL64((aOrbiterB * 9797864956200779505U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 10703510612147312252U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18155460326242413483U;
            aOrbiterF = RotL64((aOrbiterF * 6903953708987478723U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5753486645345036069U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2314216774606770444U;
            aOrbiterC = RotL64((aOrbiterC * 14002639533287566667U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9662599462788305323U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3805101172359199209U;
            aOrbiterI = RotL64((aOrbiterI * 10669315962181581543U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 1073926575064224947U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 6361545377408870615U;
            aOrbiterD = RotL64((aOrbiterD * 10685650563722188837U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 54U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + RotL64(aCarry, 23U)) + RotL64(aNonceWordD, 50U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterA) + RotL64(aOrbiterJ, 11U));
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 21U)) + aOrbiterJ) + RotL64(aNonceWordG, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterH, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 14U) + aOrbiterI) + RotL64(aOrbiterC, 39U));
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 60U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 13U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 36U) + aOrbiterG) + RotL64(aOrbiterB, 35U));
            aWandererK = aWandererK + (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 30U)) + aOrbiterB) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 26U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 56U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_PickleBall_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC46D041586BD94E9ULL + 0xA985B6DA29240D4FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA8D321C9B2660A39ULL + 0xC438AFD5F43FEFDDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8D30F78A0D2B9927ULL + 0xE41B70CCA49D4B39ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xC1D925625CD699A3ULL + 0xCAFE750F3F3C2532ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xF60AA69904EFADD1ULL + 0xBB3C8B994610A7FCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE866FE57882FDEC7ULL + 0xD5BA303E251C9A00ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xFF06863F0B235D45ULL + 0xA6B373DD2E263A48ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF76EA5EA640ECE57ULL + 0xD200DFF9E7D24190ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordE, 43U) ^ RotL64(aNonceWordB, 35U)) ^ RotL64(aNonceWordH, 19U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 593U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneC[((aIndex + 836U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordA, 51U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordG, 5U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4781U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 3650U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 27U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 35U)) + 1364174714924216027U;
            aOrbiterF = (aWandererH + RotL64(aCross, 10U)) + 13561796874229506613U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 13U)) + 11845572344206238305U) + RotL64(aNonceWordF, 53U);
            aOrbiterB = (((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 15762708240326773763U) + RotL64(aNonceWordC, 19U);
            aOrbiterE = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 1157119665207900473U) + aPhaseEOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 13U)) + 6823546624372055260U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 23U)) + 14465564210523945121U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 10667464548080807531U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 5U)) + 13445737493224316575U;
            aOrbiterK = (aWandererC + RotL64(aCross, 56U)) + 3009837893785957665U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 41U)) + 2886920524111083752U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 10886177449328249656U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 15067759884678100433U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5724566815989860041U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 18307930462682331536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8791864377579255801U;
            aOrbiterI = RotL64((aOrbiterI * 9265158882471421767U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 805797468642992351U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5743305867058244964U;
            aOrbiterH = RotL64((aOrbiterH * 16263000753351131717U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17102025528234481273U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1841579177327486899U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3841603385577825265U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2189493507896508972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 18209567010094914374U;
            aOrbiterA = RotL64((aOrbiterA * 3737080408976852351U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 6697069234216868330U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordB, 55U);
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 927471474577415372U;
            aOrbiterD = RotL64((aOrbiterD * 10680760991009199309U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 13155854301197725408U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1014625081915435892U;
            aOrbiterG = RotL64((aOrbiterG * 11592754232949990435U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12697209921410914931U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11555096613655648647U;
            aOrbiterF = RotL64((aOrbiterF * 4598821388864997089U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 9335308231651271690U) + RotL64(aNonceWordD, 5U);
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3160859883353473444U;
            aOrbiterE = RotL64((aOrbiterE * 4753600703924906409U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15681189182414315768U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3147692210581710663U;
            aOrbiterC = RotL64((aOrbiterC * 6271949093080510861U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 5373388632562432117U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1364174714924216027U;
            aOrbiterK = RotL64((aOrbiterK * 4694926665965807945U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterH, 51U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 58U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 43U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 37U)) + aOrbiterD) + aPhaseEWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 42U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 47U) + aOrbiterA) + RotL64(aOrbiterC, 18U));
            aWandererE = aWandererE + ((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterB, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterE, 21U)) + RotL64(aNonceWordE, 30U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterE, 41U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterF, 13U)) + aOrbiterE) + RotL64(aNonceWordH, 43U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterB, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordF, 57U) ^ RotL64(aNonceWordD, 21U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9656U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8869U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 34U) ^ RotL64(aNonceWordG, 13U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7205U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 5726U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 39U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 1708250618750199233U;
            aOrbiterC = (aWandererJ + RotL64(aIngress, 46U)) + 12009147777553691142U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 43U)) + 8393982703399156592U;
            aOrbiterB = (aWandererF + RotL64(aCross, 13U)) + 3247327098356831221U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 53U)) + 3403590155376353737U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 56U)) + 18197244558104735044U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 5U)) + 3096253642040701606U) + RotL64(aNonceWordF, 19U);
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 8012692688785412179U;
            aOrbiterK = (((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 35U)) + 17531946907545680745U) + aPhaseEOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aIngress, 21U)) + 17687695944270225817U) + RotL64(aNonceWordH, 27U);
            aOrbiterA = ((aWandererI + RotL64(aScatter, 51U)) + 16147773866007628769U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18244641303026196497U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 8839160526348897457U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14268021129087663397U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10599266240854068246U) + RotL64(aNonceWordG, 43U);
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2056723540756216155U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13311591601230386375U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4629354220460621284U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9505955649473204942U) ^ RotL64(aNonceWordB, 57U);
            aOrbiterI = RotL64((aOrbiterI * 17775391885312236187U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17078153810088721310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9470436761716263000U;
            aOrbiterF = RotL64((aOrbiterF * 5431855497250357229U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3305863413630104742U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14377172434239576161U;
            aOrbiterK = RotL64((aOrbiterK * 6880176890091033423U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 415687827894226513U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 16975319836893760993U;
            aOrbiterD = RotL64((aOrbiterD * 6597144958013976445U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12707054129431596074U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8974182792497231239U;
            aOrbiterB = RotL64((aOrbiterB * 7874658957269462717U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 10826131924322955095U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4168545139712703154U;
            aOrbiterE = RotL64((aOrbiterE * 10305904857550051705U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 4539070253658625193U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3737870219498561326U;
            aOrbiterJ = RotL64((aOrbiterJ * 13130847633918921393U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11563084648810555040U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7410695535361901473U;
            aOrbiterH = RotL64((aOrbiterH * 7540855656023807389U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6687453696858775037U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1708250618750199233U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13104250803527718135U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 21U));
            aWandererA = aWandererA + ((RotL64(aCross, 56U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 23U) + aOrbiterG) + RotL64(aOrbiterK, 36U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + RotL64(aNonceWordE, 41U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 39U)) + RotL64(aNonceWordA, 14U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterG) + RotL64(aOrbiterC, 54U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 6U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 39U) ^ RotL64(aNonceWordD, 13U)) ^ RotL64(aNonceWordB, 29U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15227U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 15418U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordC, 13U) ^ RotL64(aNonceWordH, 5U)) ^ RotL64(aNonceWordG, 50U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14386U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((aIndex + 11152U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 24U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 60U)) + 18180797995100240808U) + RotL64(aNonceWordC, 19U);
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 57U)) + 6585906608223552885U) + RotL64(aNonceWordG, 54U);
            aOrbiterD = (aWandererJ + RotL64(aCross, 43U)) + 14088708930575939855U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 468974153311516044U;
            aOrbiterE = (aWandererC + RotL64(aCross, 47U)) + 12481951025619894110U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 3U)) + 17227987923860711763U) + aPhaseEOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 11U)) + 4373962756657477139U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 2077576476565420951U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aPrevious, 23U)) + 17435011300234663764U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 13U)) + 4118039398293246896U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 36U)) + RotL64(aCarry, 27U)) + 13724716599855216683U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12391461204689596339U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9900605191533799627U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13553565332531046301U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 972946858824366125U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17247681919694541215U;
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15442851427306771601U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7303586227288294037U;
            aOrbiterK = RotL64((aOrbiterK * 15406402525021428799U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 12650358753454105119U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1483710933373510492U;
            aOrbiterE = RotL64((aOrbiterE * 6531763256577221891U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 18065810162229740788U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11311677121338794007U) ^ RotL64(aNonceWordF, 35U);
            aOrbiterC = RotL64((aOrbiterC * 15116367961682119467U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2355285311890287611U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 1287783821903407734U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8054011680932255985U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9282654686791135654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15488608017745542551U;
            aOrbiterH = RotL64((aOrbiterH * 7858866274035085123U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 13296835576073421802U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7127700236018338741U;
            aOrbiterF = RotL64((aOrbiterF * 11246173563106014149U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1365928843264598789U) + RotL64(aNonceWordE, 15U);
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7777790578813003657U;
            aOrbiterJ = RotL64((aOrbiterJ * 10121688100505628161U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2104270617375082523U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13363764449819651164U;
            aOrbiterB = RotL64((aOrbiterB * 2685452132715528975U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2008038686059197988U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 18180797995100240808U;
            aOrbiterI = RotL64((aOrbiterI * 8978998151475372047U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 18U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 37U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 35U)) + aPhaseEWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 38U) + aOrbiterA) + RotL64(aOrbiterJ, 3U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterF, 46U)) + RotL64(aNonceWordA, 9U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterH, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 40U) + aOrbiterG) + RotL64(aOrbiterB, 19U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 39U)) + aOrbiterE) + RotL64(aNonceWordH, 37U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterC, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 60U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 54U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 3U) ^ RotL64(aNonceWordF, 19U)) ^ RotL64(aNonceWordD, 28U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16952U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 18237U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 27U) ^ RotL64(aNonceWordH, 57U)) ^ RotL64(aNonceWordC, 47U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 18132U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneD[((aIndex + 18631U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 47U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 37U)) + 3236820517816085022U) + aPhaseEOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 3U)) + 741288875914097926U) + RotL64(aNonceWordG, 52U);
            aOrbiterB = (((aWandererE + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 8417246926007729580U) + RotL64(aNonceWordB, 49U);
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 12U)) + RotL64(aCarry, 47U)) + 9715717805774537170U;
            aOrbiterF = (aWandererK + RotL64(aCross, 47U)) + 14360243844821619482U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 41U)) + 10760908100206775334U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 27U)) + 3434641779946167811U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 29U)) + 7885568822756234567U;
            aOrbiterG = (aWandererA + RotL64(aScatter, 44U)) + 3041563437672051294U;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 57U)) + 15761355327564963516U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 21U)) + 1158633562785937421U) + aPhaseEOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 9338581575871970653U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9172038894262857354U;
            aOrbiterB = RotL64((aOrbiterB * 3110871165285625807U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14653924713599790081U) + RotL64(aNonceWordF, 57U);
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 3854497592598563309U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11737111068815795303U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16286980180327600557U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 5092583772591249756U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13955105624639442903U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4288397994175567333U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15584236478994873104U;
            aOrbiterK = RotL64((aOrbiterK * 1860480595862755379U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5557463939827483792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 2659814275753280856U;
            aOrbiterE = RotL64((aOrbiterE * 17702430405693184643U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6941807963525063449U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterD) ^ 2040598555191211307U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) ^ RotL64(aNonceWordA, 55U);
            aOrbiterG = RotL64((aOrbiterG * 14750544987531722765U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 347572666231116258U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 779304821185302523U;
            aOrbiterH = RotL64((aOrbiterH * 14180254150318109855U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 10632524582873079742U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9761308771280517212U;
            aOrbiterA = RotL64((aOrbiterA * 13926235411726048921U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2097439707055737964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2813977930321463948U;
            aOrbiterC = RotL64((aOrbiterC * 14983538728730662603U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6080592019313796689U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5396623654821376409U;
            aOrbiterI = RotL64((aOrbiterI * 15478858835919398677U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8460497459575045342U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3236820517816085022U;
            aOrbiterJ = RotL64((aOrbiterJ * 5530411244458067093U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 56U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterF, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 40U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterH, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterG, 39U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterF, 50U)) + RotL64(aNonceWordD, 19U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 27U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 47U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD) + RotL64(aCarry, 29U)) + RotL64(aNonceWordC, 7U)) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterE, 60U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 27U) + RotL64(aOrbiterH, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 30U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 30U) ^ RotL64(aNonceWordC, 41U)) ^ RotL64(aNonceWordE, 3U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 21990U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22489U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordB, 27U));
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25523U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26817U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) + RotL64(aCross, 37U)) ^ (RotL64(aCarry, 53U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererK + RotL64(aScatter, 57U)) + 4622023259121087483U;
            aOrbiterD = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 10253505250223501352U;
            aOrbiterH = (((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 17133877904420462669U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 11U)) + 6162827793741796700U;
            aOrbiterK = (aWandererC + RotL64(aCross, 19U)) + 9610986424765907615U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 60U)) + 11210747154264753754U;
            aOrbiterE = (aWandererF + RotL64(aIngress, 43U)) + 16554205219580654546U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 53U)) + 10352576357413766388U) + RotL64(aNonceWordC, 5U);
            aOrbiterF = (aWandererJ + RotL64(aIngress, 23U)) + 3651845783283479752U;
            aOrbiterA = (((aWandererH + RotL64(aPrevious, 30U)) + RotL64(aCarry, 47U)) + 18145542190463500476U) + aPhaseEOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aScatter, 5U)) + 5415609566767162857U) + RotL64(aNonceWordA, 25U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2033734872464201570U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3507213117125813345U;
            aOrbiterH = RotL64((aOrbiterH * 5453058336688881113U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8716253393049851856U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 695984869565941856U;
            aOrbiterJ = RotL64((aOrbiterJ * 8377921610764044735U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 7661578828878284931U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 906654265099155956U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8117625377607536949U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6050049984731254612U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 17882717590338190821U;
            aOrbiterA = RotL64((aOrbiterA * 10807367411402733215U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4996521991532815957U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 4246460672800604436U;
            aOrbiterC = RotL64((aOrbiterC * 12047466401960824903U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8700148116452518842U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10039050281847466206U;
            aOrbiterI = RotL64((aOrbiterI * 11884791271239660157U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4513844680425845372U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 3037563127442815153U) ^ RotL64(aNonceWordD, 39U);
            aOrbiterE = RotL64((aOrbiterE * 18363509277992292407U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1005237931570968724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1373258132025712065U;
            aOrbiterF = RotL64((aOrbiterF * 10458020799382532395U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 12759144329395682277U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 5139371668116336931U) ^ RotL64(aNonceWordB, 18U);
            aOrbiterB = RotL64((aOrbiterB * 10761543179345026943U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3211005174890625715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 18045286961878287418U;
            aOrbiterD = RotL64((aOrbiterD * 4536094526540761611U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 4454078771279674978U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4622023259121087483U;
            aOrbiterK = RotL64((aOrbiterK * 8991756794989027019U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterG, 36U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 21U)) + aOrbiterA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererI = aWandererI + ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterE, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterF, 53U));
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterG, 30U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterD, 11U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 21U)) + RotL64(aNonceWordE, 23U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterH) + RotL64(aNonceWordF, 57U)) + aPhaseEWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 24U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 34U) ^ RotL64(aNonceWordC, 53U));
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31030U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30598U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 13U) ^ RotL64(aNonceWordG, 41U)) ^ RotL64(aNonceWordA, 3U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30048U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29272U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 53U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 51U)) + 11700815697312060726U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 43U)) + RotL64(aCarry, 21U)) + 11808423452327465441U;
            aOrbiterA = (aWandererE + RotL64(aCross, 35U)) + 8670503858631730886U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 5U)) + 2400061067991988544U) + RotL64(aNonceWordA, 45U);
            aOrbiterH = (aWandererH + RotL64(aScatter, 40U)) + 16163118178366229686U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 3280178595904941068U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 3U)) + 3298683600817047727U) + aPhaseEOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + 16321624053445183574U) + aPhaseEOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aCross, 60U)) + 6730229877611375225U) + RotL64(aNonceWordD, 51U);
            aOrbiterK = (aWandererI + RotL64(aIngress, 53U)) + 10162830636713641322U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 27U)) + 15646771327759599256U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14841751262270544102U) + RotL64(aNonceWordG, 38U);
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9545541117228834895U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11529769874752969377U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14676615635857599982U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1231768638470558855U;
            aOrbiterH = RotL64((aOrbiterH * 2716808508509014677U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1945905595345404833U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1406171421638586846U;
            aOrbiterG = RotL64((aOrbiterG * 4577864352425476233U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 1970292335806697198U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12309719390375013297U;
            aOrbiterJ = RotL64((aOrbiterJ * 16540660957923687327U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5352135521358954576U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 15465675376193501658U;
            aOrbiterB = RotL64((aOrbiterB * 16385761112921041387U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2842123638916600369U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 3544764287036748668U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3360772950777850115U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6038297172906492282U) + RotL64(aNonceWordF, 43U);
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10249342332287140970U;
            aOrbiterK = RotL64((aOrbiterK * 16701083081566042277U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1662076777040529446U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1949705569959740274U;
            aOrbiterD = RotL64((aOrbiterD * 11340691546658994529U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13934194245417822360U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 5720408806425535958U;
            aOrbiterI = RotL64((aOrbiterI * 15237561081637415383U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2209251362417210658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4917447930929521699U;
            aOrbiterE = RotL64((aOrbiterE * 17489570156694692569U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14817115766683623486U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11700815697312060726U;
            aOrbiterF = RotL64((aOrbiterF * 16982411053956669181U), 27U);
            //
            aIngress = RotL64(aOrbiterJ, 10U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterD, 48U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + RotL64(aNonceWordH, 15U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterC, 5U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterE, 46U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterJ, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 21U)) + aOrbiterG) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI);
            aWandererB = aWandererB + ((((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 43U)) + RotL64(aNonceWordB, 39U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 46U));
            aCarry = aCarry + (RotL64(aWandererF, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_PickleBall_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xFADE9A65880C0105ULL + 0xC81B543FEFB123A2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF3EF0A7F62B0324DULL + 0xA15E17889D51CA32ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xDC652681DCABC3FDULL + 0xA28B8EB7586C8787ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE86FD5A96E33D249ULL + 0xD1C0ED364D72D868ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x849B0C0B5C6FE739ULL + 0xD97B0E66E147EEBEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xE6D371E5A93EAC29ULL + 0xDF644140DBE1F81DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB1AD1793592B9DC1ULL + 0xF106C636CFD55914ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x86647247080B7353ULL + 0xB86177D25BBEBDB6ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordG, 47U) ^ RotL64(aNonceWordC, 27U)) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 422U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneC[((aIndex + 4123U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordF, 5U) ^ RotL64(aNonceWordB, 39U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 687U)) & S_BLOCK1], 48U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1445U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 18U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 17081642665820489793U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 41U)) + 14468854040067229623U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 18U)) + 2249450222593057429U) + RotL64(aNonceWordC, 55U);
            aOrbiterJ = (aWandererF + RotL64(aIngress, 29U)) + 14964389079511378664U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 35U)) + 17003491054252360650U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 12710882240582032588U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 5U)) + 9887078182156755359U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 47U)) + 7665284531810584704U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 13U)) + 7304284015511876717U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 53U)) + 5517927023543751734U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 44U)) + 17704756310857362759U) + RotL64(aNonceWordD, 17U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 11347400363019508578U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11696395232760991243U;
            aOrbiterF = RotL64((aOrbiterF * 9725231749679442003U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 10875780291242873583U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 7808740614343437672U;
            aOrbiterE = RotL64((aOrbiterE * 8889516201913716283U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 3145390996141902032U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16080636485642732615U;
            aOrbiterI = RotL64((aOrbiterI * 7445756373012217305U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3929263288176983844U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18210228766683996806U;
            aOrbiterJ = RotL64((aOrbiterJ * 13178080076505449091U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13948962323541421431U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3037683309790156893U;
            aOrbiterB = RotL64((aOrbiterB * 13406672352222636739U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 17827265198532699474U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 7270895262023504864U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13467417362477308167U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6431243064980879185U) + RotL64(aNonceWordA, 45U);
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6680205390976259885U;
            aOrbiterH = RotL64((aOrbiterH * 10421386694108590789U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15910655919164357152U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8046213498216027383U;
            aOrbiterD = RotL64((aOrbiterD * 18061867495824063553U), 57U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 2521111689480478597U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + RotL64(aNonceWordB, 9U);
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13892876610454681741U;
            aOrbiterG = RotL64((aOrbiterG * 17776392934374483875U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 16009217514890880809U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1221573458193626679U;
            aOrbiterC = RotL64((aOrbiterC * 73477765605619369U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 9275704218554025797U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17081642665820489793U;
            aOrbiterK = RotL64((aOrbiterK * 5613316790159527375U), 35U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 22U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterG, 50U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 34U) + RotL64(aOrbiterA, 57U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterC, 48U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 29U) + RotL64(aOrbiterA, 41U)) + aOrbiterB) + RotL64(aCarry, 13U)) + RotL64(aNonceWordH, 10U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 35U)) + aOrbiterH);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 43U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterH, 28U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + RotL64(aNonceWordE, 27U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterK) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 24U) + aOrbiterK) + RotL64(aOrbiterD, 23U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererJ);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordD, 30U) ^ RotL64(aNonceWordF, 43U)) ^ RotL64(aNonceWordA, 57U));
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10037U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6116U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordB, 39U) ^ RotL64(aNonceWordH, 28U));
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9027U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6128U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 12U)) + (RotL64(aIngress, 29U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 3U)) + RotL64(aCarry, 27U)) + 6024062041314952357U) + RotL64(aNonceWordD, 55U);
            aOrbiterA = (aWandererE + RotL64(aIngress, 53U)) + 18340757093658015585U;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 56U)) + RotL64(aCarry, 23U)) + 11911120493880346751U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 17428074353884654439U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 37U)) + 12790849760814795936U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 11U)) + 12633397052172117800U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 5U)) + 11946150433665237945U;
            aOrbiterB = (aWandererB + RotL64(aCross, 23U)) + 16842157900909419285U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 13U)) + 14186235783224155962U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 35U)) + 13284904542579767591U) + RotL64(aNonceWordG, 37U);
            aOrbiterH = ((aWandererH + RotL64(aCross, 48U)) + 11609181965078844357U) + aPhaseFOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 9628562297095374984U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7850281529011259759U;
            aOrbiterE = RotL64((aOrbiterE * 17611485102925470357U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 257458718073794527U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10693404545773519306U;
            aOrbiterA = RotL64((aOrbiterA * 14821443722828498323U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3430519236533871460U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6183054506953198055U;
            aOrbiterK = RotL64((aOrbiterK * 6121082743789970911U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2905610989884221654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 4472163910775333862U;
            aOrbiterD = RotL64((aOrbiterD * 7770678426310856745U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16870142883133769663U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterI = RotL64((aOrbiterI * 9740854430251597879U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 16904169913507057108U) + RotL64(aNonceWordC, 41U);
            aOrbiterG = (((aOrbiterG ^ aOrbiterH) ^ 4773518591580333357U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) ^ RotL64(aNonceWordB, 34U);
            aOrbiterG = RotL64((aOrbiterG * 5306070307776061267U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6528141733853494275U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11254806909313951442U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6316669786405548827U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 6857506858448143407U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2855763534355983644U;
            aOrbiterC = RotL64((aOrbiterC * 16881334940165182415U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12328391751024624740U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 16475072086109949522U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15218626930666825883U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15505670341076785424U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 6972128419331939330U;
            aOrbiterJ = RotL64((aOrbiterJ * 12206069109180246067U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7151546362283646210U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6024062041314952357U;
            aOrbiterH = RotL64((aOrbiterH * 10243806128059850493U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 35U)) + aOrbiterH) + RotL64(aNonceWordE, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterF, 20U));
            aWandererD = aWandererD + (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 51U)) + aOrbiterK) + RotL64(aNonceWordF, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 23U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 24U) + RotL64(aOrbiterF, 47U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 37U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 28U)) + aOrbiterD) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterD, 13U));
            aWandererB = aWandererB + ((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 12U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 60U) ^ RotL64(aNonceWordG, 5U)) ^ RotL64(aNonceWordD, 41U));
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13028U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13243U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordH, 60U) ^ RotL64(aNonceWordE, 47U)) ^ RotL64(aNonceWordF, 5U));
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 14535U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 13696U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 47U)) + 964165145848253292U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 37U)) + 10645976767204934746U) + RotL64(aNonceWordC, 17U);
            aOrbiterE = ((aWandererK + RotL64(aIngress, 28U)) + RotL64(aCarry, 11U)) + 8241612229349212650U;
            aOrbiterB = (aWandererC + RotL64(aCross, 13U)) + 4159196033256913347U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 57U)) + 7194795864620233507U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 53U)) + 7638928444536778384U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 43U)) + 11819105916503968109U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aCross, 5U)) + 18052213302858186237U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 60U)) + 8663575313970041570U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 35U)) + 16644136720439299786U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 23U)) + 16930316530442679864U) + RotL64(aNonceWordA, 59U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16251107616988250593U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 7171986193609401665U) ^ RotL64(aNonceWordD, 36U);
            aOrbiterE = RotL64((aOrbiterE * 3543709971414550087U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17885046834432626644U) + RotL64(aNonceWordH, 41U);
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 7757069274715713557U;
            aOrbiterA = RotL64((aOrbiterA * 15766885299397923879U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2212805322061155615U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6368539134638838822U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13383744883433594259U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5264326094252925613U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6126345334815012938U;
            aOrbiterI = RotL64((aOrbiterI * 17180934809764905307U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13826731214018407061U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 6621261811613643620U;
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 5964406317285863781U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2167324450276308078U;
            aOrbiterK = RotL64((aOrbiterK * 1098346374733634905U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16740710162977859724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8236083581048717923U;
            aOrbiterH = RotL64((aOrbiterH * 4364887787000704039U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 13967473987446124012U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5136051802217149813U;
            aOrbiterB = RotL64((aOrbiterB * 13997246005108872883U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5842999397215390366U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8621394946580065499U;
            aOrbiterD = RotL64((aOrbiterD * 11658023035736362355U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 18086875424872976900U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7429246355923896047U;
            aOrbiterG = RotL64((aOrbiterG * 5077079237334961761U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 18123753993386959014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 964165145848253292U;
            aOrbiterC = RotL64((aOrbiterC * 3178072569980307307U), 37U);
            //
            aIngress = RotL64(aOrbiterA, 12U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 4U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aNonceWordB, 27U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 58U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 39U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterD) + RotL64(aNonceWordF, 49U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterJ, 21U));
            aWandererB = aWandererB + ((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 13U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 56U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterJ, 43U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 3U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordH, 30U) ^ RotL64(aNonceWordG, 11U)) ^ RotL64(aNonceWordF, 39U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16568U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18681U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordC, 22U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17522U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18431U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 39U)) + (RotL64(aCarry, 11U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aScatter, 21U)) + 12669015908335980355U;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 24U)) + 5438715179868613192U;
            aOrbiterG = ((aWandererI + RotL64(aIngress, 39U)) + 13172104448184536460U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 13421421503244744803U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 53U)) + 13327113302994856582U) + RotL64(aNonceWordG, 35U);
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 57U)) + 4671768205922454413U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 5355759962838579929U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 51U)) + 6691720614265406851U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 37U)) + 7063906424700911378U;
            aOrbiterA = (aWandererD + RotL64(aCross, 43U)) + 17328616394166672263U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 46U)) + RotL64(aCarry, 29U)) + 1542940602574207068U) + RotL64(aNonceWordB, 6U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 7203866278803132454U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]) + RotL64(aNonceWordF, 47U);
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 993485696233139264U;
            aOrbiterG = RotL64((aOrbiterG * 11609009908810366447U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 15659679028507488331U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 18321361454094675842U;
            aOrbiterF = RotL64((aOrbiterF * 3966860765622641843U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9633319822696783352U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3496559332232402963U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7772060229838162977U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 1918349708324205526U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7701088402761359134U;
            aOrbiterB = RotL64((aOrbiterB * 9649485438465644795U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6006824348814439686U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 18088375375347012557U;
            aOrbiterK = RotL64((aOrbiterK * 12801082943086128385U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12816533373478543584U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17951880253818836433U;
            aOrbiterI = RotL64((aOrbiterI * 8935839101517220201U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11311632024372748238U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9891349164779752351U;
            aOrbiterA = RotL64((aOrbiterA * 11405973752233193209U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 711130292000437038U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17818800917771709681U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10567029732245868263U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10188714200240109442U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9745615081760948652U;
            aOrbiterC = RotL64((aOrbiterC * 9321909462220134035U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6508703788527163965U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7536038073603467381U;
            aOrbiterJ = RotL64((aOrbiterJ * 12015514242701199813U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2793951597846756844U) + RotL64(aNonceWordH, 31U);
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 12669015908335980355U;
            aOrbiterE = RotL64((aOrbiterE * 7355285540199760689U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 23U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 58U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 56U) + aOrbiterJ) + RotL64(aOrbiterH, 39U));
            aWandererB = aWandererB + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 53U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterC, 35U));
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 30U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aScatter, 50U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + RotL64(aNonceWordA, 45U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aNonceWordE, 9U));
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 46U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererF, 42U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordA, 29U) ^ RotL64(aNonceWordE, 13U)) ^ RotL64(aNonceWordC, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23018U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26952U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordD, 39U) ^ RotL64(aNonceWordF, 12U)) ^ RotL64(aNonceWordH, 3U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25576U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((aIndex + 26219U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 5U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 18U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererA + RotL64(aIngress, 43U)) + 17668251151213543491U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + 16101602509895104517U) + aPhaseFOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 35U)) + 9083915270773304935U;
            aOrbiterB = (aWandererH + RotL64(aCross, 39U)) + 12810720730318214811U;
            aOrbiterI = (aWandererG + RotL64(aPrevious, 13U)) + 18113428002071925621U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 58U)) + 1582208899354109878U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + RotL64(aNonceWordC, 55U);
            aOrbiterG = (aWandererI + RotL64(aCross, 5U)) + 4180688104819188154U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 8954598189262820611U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 21U)) + 15360094153175355879U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 56U)) + RotL64(aCarry, 13U)) + 8383954114668216260U;
            aOrbiterF = (((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 15626783326234049197U) + RotL64(aNonceWordE, 46U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10609978564404958066U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 17656516608997517984U) ^ RotL64(aNonceWordB, 17U);
            aOrbiterD = RotL64((aOrbiterD * 4590620354119899777U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 760077259110786536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3597338735888033063U;
            aOrbiterH = RotL64((aOrbiterH * 6548831472863517621U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4431777844935985157U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10710423172154671296U;
            aOrbiterJ = RotL64((aOrbiterJ * 16267496318491473315U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10240882795242085185U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7826053487019825891U;
            aOrbiterA = RotL64((aOrbiterA * 15053729937684375907U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9418883403715727353U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 11507423614799075545U;
            aOrbiterE = RotL64((aOrbiterE * 16189463984557044693U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 11545217316421066655U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 617921402135485341U;
            aOrbiterB = RotL64((aOrbiterB * 8182920764965471653U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14456933220749921009U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7990243583564535387U;
            aOrbiterG = RotL64((aOrbiterG * 5994900368027985469U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14023633125757654751U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11319146808574958827U;
            aOrbiterK = RotL64((aOrbiterK * 13676159969338309307U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14161653180846538446U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17993503892528842342U;
            aOrbiterF = RotL64((aOrbiterF * 12184170842617942651U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 10449311783872638478U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 17210495321003036773U) ^ RotL64(aNonceWordG, 21U);
            aOrbiterC = RotL64((aOrbiterC * 17591257107603354151U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 14586515403314763393U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 17668251151213543491U;
            aOrbiterI = RotL64((aOrbiterI * 9367185933291003363U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 18U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + RotL64(aNonceWordD, 11U));
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterF, 50U)) + aPhaseFWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 35U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 36U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererA = aWandererA + (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 39U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterI, 14U)) + RotL64(aNonceWordH, 43U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 56U) + RotL64(aOrbiterI, 27U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + RotL64(aWandererI, 37U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordC, 53U) ^ RotL64(aNonceWordH, 26U)) ^ RotL64(aNonceWordF, 41U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30500U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((aIndex + 28118U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordD, 3U) ^ RotL64(aNonceWordE, 58U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28297U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27732U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 60U)) + (RotL64(aPrevious, 37U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 34U)) + 15045917390223766480U;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 10763054007033668758U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 13190170142593666607U;
            aOrbiterF = (aWandererF + RotL64(aCross, 23U)) + 9657025731441167065U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 41U)) + 11433367178975954211U) + RotL64(aNonceWordA, 25U);
            aOrbiterC = (aWandererA + RotL64(aIngress, 51U)) + 17904920143996810366U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 14U)) + 3244383020512113283U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 29U)) + 6538815775171139091U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 27U)) + 7195368312757976343U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 39U)) + 18134430713910279374U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 6571776588427107976U) + RotL64(aNonceWordB, 7U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11830778129647517758U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9793702760907767365U;
            aOrbiterA = RotL64((aOrbiterA * 4096246227968677179U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2287235876793192036U) + RotL64(aNonceWordF, 45U);
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 8951959188326141794U;
            aOrbiterD = RotL64((aOrbiterD * 9968356718110753845U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7583061790273240157U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3571364625022806085U;
            aOrbiterC = RotL64((aOrbiterC * 6238360922735480669U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13869345563551689212U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 277480328952975002U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) ^ RotL64(aNonceWordG, 30U);
            aOrbiterE = RotL64((aOrbiterE * 1057564597096163085U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4983735092494677578U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 9490022869381030928U;
            aOrbiterH = RotL64((aOrbiterH * 12926352917961703123U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7928039573014765566U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6504190875809407084U;
            aOrbiterG = RotL64((aOrbiterG * 14648214826494826711U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2787985600176307413U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16308785053443116826U;
            aOrbiterK = RotL64((aOrbiterK * 17867565986311256691U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12788128335006767824U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1187040019537798339U;
            aOrbiterI = RotL64((aOrbiterI * 10834905007658184183U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 10771230162770496645U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6542421559654716320U;
            aOrbiterB = RotL64((aOrbiterB * 16829492790597069373U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 702458690970201679U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2806140783487813070U;
            aOrbiterJ = RotL64((aOrbiterJ * 7415398198842270381U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 950611302199732036U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 15045917390223766480U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9358017420417979347U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 56U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 27U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 24U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 18U) + aOrbiterC) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterB, 3U));
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 21U)) + aOrbiterA) + RotL64(aNonceWordH, 9U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 36U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 20U) + aOrbiterA) + RotL64(aOrbiterB, 5U));
            aWandererA = aWandererA + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 27U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 29U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + RotL64(aCarry, 13U)) + RotL64(aNonceWordD, 17U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_PickleBall_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE5F7CA1966985FBBULL + 0xDEE276C8B8F4D070ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9BF110B73159D6A3ULL + 0x893CAA8BFE50B78DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBA44F999A836FCB7ULL + 0x98F834514BDE5444ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9DE8AE217296306BULL + 0xE0157433A50EFF6FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xBD01BD115294B7C1ULL + 0xFD2EBA00CF6204B2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB6626B8529F7EE1BULL + 0xADF9110BD87A7A33ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xEC6EFD42804A392FULL + 0xBC230C59646FCC59ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x830C867D969469DBULL + 0x8E570D8C9E973393ULL);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 29U) ^ RotL64(aNonceWordD, 3U)) ^ RotL64(aNonceWordC, 43U));
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5186U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4286U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 11U) ^ RotL64(aNonceWordB, 46U)) ^ RotL64(aNonceWordG, 19U));
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2357U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 1830U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 21U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 41U)) + 18319689184146942855U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 58U)) + RotL64(aCarry, 3U)) + 8041304130090501019U;
            aOrbiterA = (aWandererA + RotL64(aCross, 13U)) + 11347064191990897738U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 27U)) + 15242243470024447468U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 37U)) + 10619749107163611105U;
            aOrbiterC = (aWandererD + RotL64(aCross, 51U)) + 14795614276221947128U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 53U)) + 1578095288886372393U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 43U)) + 13593906305770501684U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 8919815528334599172U) + RotL64(aNonceWordE, 57U);
            aOrbiterB = ((aWandererE + RotL64(aIngress, 23U)) + 17425548324720065145U) + RotL64(aNonceWordF, 3U);
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 30U)) + RotL64(aCarry, 57U)) + 11125018338392347335U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3779189180734244399U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10958224663276134041U;
            aOrbiterA = RotL64((aOrbiterA * 6206963519509783781U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4317305352561612995U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterD) ^ 4891139433808505355U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) ^ RotL64(aNonceWordH, 36U);
            aOrbiterC = RotL64((aOrbiterC * 11507024985663120317U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5166074784835930965U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10080890270621589202U;
            aOrbiterI = RotL64((aOrbiterI * 13170894418184288695U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4501071771615514619U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6486573807774431753U;
            aOrbiterD = RotL64((aOrbiterD * 324029625116648669U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15714881857668975753U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 3506619392820235900U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) ^ RotL64(aNonceWordA, 39U);
            aOrbiterG = RotL64((aOrbiterG * 5707033870161224499U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5295711072762443783U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11192836530396570648U;
            aOrbiterE = RotL64((aOrbiterE * 4361810118382207039U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7993389678399774574U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12551394763541226695U;
            aOrbiterK = RotL64((aOrbiterK * 11903486656172026403U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11553674370322129668U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 4459881583199320245U;
            aOrbiterJ = RotL64((aOrbiterJ * 2805857426321555685U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 3053507713574219459U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15458441755058850309U;
            aOrbiterH = RotL64((aOrbiterH * 7296609957819165877U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17429750026356459756U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17114614857181230304U;
            aOrbiterF = RotL64((aOrbiterF * 10541235280918902739U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8958993884028672039U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 18319689184146942855U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5430881344386342703U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 24U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 26U));
            aWandererB = aWandererB + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 37U)) + aOrbiterH);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterI, 19U)) + aPhaseFWandererUpdateSaltE[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterK) + RotL64(aCarry, 29U)) + RotL64(aNonceWordG, 13U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 37U) + aOrbiterG) + RotL64(aOrbiterJ, 53U)) + RotL64(aNonceWordC, 19U));
            aWandererA = aWandererA + ((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterD, 14U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 24U) + aOrbiterC) + RotL64(aOrbiterD, 39U));
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + RotL64(aOrbiterK, 51U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 11U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 3U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordG, 43U) ^ RotL64(aNonceWordA, 35U));
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7995U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneD[((aIndex + 9698U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 35U) ^ RotL64(aNonceWordF, 5U)) ^ RotL64(aNonceWordD, 43U));
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5923U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((aIndex + 6379U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 29U)) ^ (RotL64(aCarry, 54U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 17225673071833726819U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 41U)) + 10301458382103627331U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 23U)) + 3960233050857362414U) + RotL64(aNonceWordC, 23U);
            aOrbiterG = ((aWandererG + RotL64(aIngress, 21U)) + 17768665685046605837U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 14471018461213959767U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 5U)) + 10730597892721340453U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 53U)) + 14863394003122760542U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 37U)) + 9948587274816688296U;
            aOrbiterD = (aWandererE + RotL64(aPrevious, 29U)) + 3573569431435100993U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 43U)) + RotL64(aCarry, 3U)) + 8153670675740450590U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 14U)) + 16438856577722561424U) + RotL64(aNonceWordD, 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 15765587867581925041U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1082039522061775213U;
            aOrbiterH = RotL64((aOrbiterH * 17023740047246402641U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4202521649260798876U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15877659681260461141U;
            aOrbiterJ = RotL64((aOrbiterJ * 11369910758551088173U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2551560426129646123U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 3005102326163906320U;
            aOrbiterK = RotL64((aOrbiterK * 4241583192662435107U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 1675501058857208089U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12774812270956702043U;
            aOrbiterI = RotL64((aOrbiterI * 5488437008504905105U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1044886020922563597U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4857445127457225171U;
            aOrbiterD = RotL64((aOrbiterD * 13223560654459705259U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11548725551787560962U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 2434677823189765161U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4283026044563670969U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 9606875320524736294U) + RotL64(aNonceWordH, 41U);
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 13732615866277657704U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3905528919281629775U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 13921743663803299567U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13350829301153929899U;
            aOrbiterB = RotL64((aOrbiterB * 11858642286713079795U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9473349030551400156U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 7446792050826434742U;
            aOrbiterE = RotL64((aOrbiterE * 6619682184124713031U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 17970527747978977453U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2326714817603921480U;
            aOrbiterA = RotL64((aOrbiterA * 14581676978186226887U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7875511075130474136U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17225673071833726819U) ^ RotL64(aNonceWordA, 28U);
            aOrbiterF = RotL64((aOrbiterF * 1196024136909896027U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 21U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 30U) + aOrbiterC) + RotL64(aOrbiterJ, 53U)) + RotL64(aNonceWordF, 39U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterB, 20U));
            aWandererI = aWandererI + ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 37U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterH, 51U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aCross, 27U) + RotL64(aOrbiterD, 47U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + RotL64(aNonceWordB, 15U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 23U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 20U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordB, 57U) ^ RotL64(aNonceWordH, 35U)) ^ RotL64(aNonceWordF, 23U));
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12960U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneA[((aIndex + 11447U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordA, 3U) ^ RotL64(aNonceWordD, 11U));
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15246U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11857U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 12U) + RotL64(aIngress, 27U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 5171470532667965920U) + RotL64(aNonceWordC, 15U);
            aOrbiterD = ((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 750549462358682403U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 46U)) + 3325689257577120525U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 39U)) + 18031575461559790826U) + RotL64(aNonceWordD, 61U);
            aOrbiterB = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 13874739537012288677U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 4250029868785016865U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 41U)) + 8211158803112611161U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 29U)) + 1083939790236786027U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 53U)) + 3446525462376962464U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 3U)) + 6973817815000417325U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 26U)) + 15230876489676945543U) + aPhaseFOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9359727659738755880U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 8775170107816327654U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6910680458261008653U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11958941755525038545U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16966819714283167348U;
            aOrbiterG = RotL64((aOrbiterG * 16363457661846050749U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14556087985619763243U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17915047508377045221U;
            aOrbiterD = RotL64((aOrbiterD * 6727635453185130109U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 8578745677485367222U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7002181668717618866U;
            aOrbiterB = RotL64((aOrbiterB * 12329703532414955235U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3569939503066735457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2956247934282522184U;
            aOrbiterI = RotL64((aOrbiterI * 9946650822131152531U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4285180013402474041U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5976239869535619811U;
            aOrbiterA = RotL64((aOrbiterA * 3458095419039067465U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 2424524955161695463U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 6849595426583763537U) ^ RotL64(aNonceWordE, 23U);
            aOrbiterC = RotL64((aOrbiterC * 12727902040238318101U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 11414890686374886716U) + RotL64(aNonceWordH, 20U);
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5668287266836153445U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8011885266143066285U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9976985606260445887U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 9223940029500676834U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8508023992488499955U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4480967907876921958U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5132766654502526597U;
            aOrbiterF = RotL64((aOrbiterF * 321625389942019245U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 12921555132452983464U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 5171470532667965920U;
            aOrbiterK = RotL64((aOrbiterK * 9710487797420618879U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 39U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 50U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterB, 11U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterI, 47U)) + RotL64(aNonceWordG, 25U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 60U)) + aOrbiterD) + RotL64(aNonceWordB, 11U));
            aWandererC = aWandererC + ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterG, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + aOrbiterH) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 58U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterG, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 39U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererK, 4U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + RotL64(aWandererB, 48U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aNonceWordE, 53U) ^ RotL64(aNonceWordA, 19U));
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20087U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 20232U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordG, 50U) ^ RotL64(aNonceWordD, 41U)) ^ RotL64(aNonceWordH, 11U));
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18192U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20290U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aIngress, 37U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererF + RotL64(aPrevious, 37U)) + 5480870806135400132U;
            aOrbiterB = ((((aWandererI + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 8034874599430768743U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) + RotL64(aNonceWordC, 43U);
            aOrbiterI = (aWandererE + RotL64(aIngress, 39U)) + 4006919843736863767U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 29U)) + 2988069748674633718U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 35U)) + 12347295651973135786U;
            aOrbiterG = ((aWandererG + RotL64(aCross, 58U)) + 14152683894431568192U) + RotL64(aNonceWordF, 19U);
            aOrbiterD = (aWandererH + RotL64(aScatter, 3U)) + 15765143815254196598U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 43U)) + 10473067082331244233U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 1089466925383677249U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 27U)) + 13215039929873682230U;
            aOrbiterF = (aWandererA + RotL64(aCross, 11U)) + 3957997712247961479U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10023907397941685546U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14593012591254614353U;
            aOrbiterI = RotL64((aOrbiterI * 17111300092082154687U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 13353797968154036726U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9259966668512102858U;
            aOrbiterE = RotL64((aOrbiterE * 8326732574268308221U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 10757861831070349321U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10530223113483866178U;
            aOrbiterG = RotL64((aOrbiterG * 11269177745265396583U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 7554320926405521865U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 6978052067277966996U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 18020134738536217801U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1053695861967171420U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15980734683539854451U;
            aOrbiterK = RotL64((aOrbiterK * 3208466640010555357U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17041258393808061556U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12846551858751995530U;
            aOrbiterC = RotL64((aOrbiterC * 9303891433380993639U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 14617434286683320666U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3999309956180741302U;
            aOrbiterJ = RotL64((aOrbiterJ * 15037707937050015205U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13452627760403094126U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2633241575260427158U;
            aOrbiterF = RotL64((aOrbiterF * 2638570213290747581U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 15575035993965639421U) + RotL64(aNonceWordD, 27U);
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7829837426112185905U) ^ RotL64(aNonceWordG, 42U);
            aOrbiterH = RotL64((aOrbiterH * 17059814556114938275U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 12565466096663867876U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 4845209979900289818U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14990494169374347835U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 13472490162287247012U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5480870806135400132U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9150331893094034245U), 47U);
            //
            aIngress = RotL64(aOrbiterB, 53U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 48U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 38U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseFWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + RotL64(aNonceWordA, 15U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + RotL64(aNonceWordB, 25U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 13U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterK, 23U));
            aWandererC = aWandererC + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 54U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 44U) + aOrbiterF) + RotL64(aOrbiterB, 19U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 52U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
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
            aIngress = aIngress ^ ((RotL64(aNonceWordF, 27U) ^ RotL64(aNonceWordB, 48U)) ^ RotL64(aNonceWordD, 3U));
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26670U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneA[((aIndex + 21846U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ ((RotL64(aNonceWordE, 3U) ^ RotL64(aNonceWordH, 21U)) ^ RotL64(aNonceWordA, 47U));
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26061U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26326U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 13U)) + 701291026547470433U;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 51U)) + 17283292650462111643U;
            aOrbiterC = (((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 41U)) + 9969124091931303406U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aScatter, 11U)) + 889176772718046988U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 26U)) + 6054541844643748084U) + aPhaseFOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aScatter, 13U)) + 14703226235143028132U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 47U)) + 7977975878522921062U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 53U)) + 16894322614172266274U) + RotL64(aNonceWordH, 53U);
            aOrbiterE = (aWandererD + RotL64(aIngress, 3U)) + 12160451749345900570U;
            aOrbiterJ = (aWandererG + RotL64(aCross, 44U)) + 10870847008043897470U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 8159920947172520247U) + RotL64(aNonceWordG, 45U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2440099120969517932U) + RotL64(aNonceWordE, 11U);
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2428396147731468007U;
            aOrbiterC = RotL64((aOrbiterC * 9363073341539598441U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2213226274394673479U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7079731443427765333U;
            aOrbiterI = RotL64((aOrbiterI * 16918930776877030559U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 958896789550478970U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10788682955708075458U;
            aOrbiterF = RotL64((aOrbiterF * 913321215613559729U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 2003386579317564870U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8419686358774204999U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6547052526438697621U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6989167615157578904U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 17636634003643824148U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11038576417283732937U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13824962118933907859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9543912892587859646U;
            aOrbiterD = RotL64((aOrbiterD * 14736710162285997415U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 15729878041027706114U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9542137475454825463U;
            aOrbiterK = RotL64((aOrbiterK * 11420547128115090491U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5327302277575009955U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2707383132257428583U;
            aOrbiterE = RotL64((aOrbiterE * 6120763309390182129U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9008601903853562620U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11050463189491777908U;
            aOrbiterG = RotL64((aOrbiterG * 9178386878636430553U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14683684132116778056U) + RotL64(aNonceWordA, 17U);
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5390271065690907120U;
            aOrbiterH = RotL64((aOrbiterH * 17903005409098232619U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5183407290520277451U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 701291026547470433U;
            aOrbiterA = RotL64((aOrbiterA * 16329261100139524239U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 39U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ) + RotL64(aCarry, 39U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 50U)) + aOrbiterI) + RotL64(aNonceWordD, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 10U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 13U)) + aOrbiterB);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterI, 23U)) + aOrbiterF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 56U) + aOrbiterI) + RotL64(aOrbiterC, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 60U)) + aOrbiterH) + RotL64(aNonceWordC, 20U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 24U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aNonceWordC, 54U) ^ RotL64(aNonceWordF, 37U));
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28536U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28310U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aNonceWordG, 53U) ^ RotL64(aNonceWordH, 5U));
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27433U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 31705U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 50U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 15920462086654025436U;
            aOrbiterF = (((aWandererC + RotL64(aPrevious, 39U)) + RotL64(aCarry, 37U)) + 487844076858004017U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 54U)) + RotL64(aCarry, 43U)) + 14502883786442630566U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 37U)) + 3787107318658233674U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 3U)) + 12548777544693755491U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aIngress, 5U)) + 4907309444075181683U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 43U)) + 18342396700266492072U) + RotL64(aNonceWordD, 20U);
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 23U)) + 13503051997624242670U;
            aOrbiterH = (aWandererB + RotL64(aCross, 27U)) + 17845742460521374571U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 19U)) + 8640887211877858169U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 52U)) + 5273913123709097537U) + RotL64(aNonceWordE, 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17756844173695563883U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6713055830729302951U;
            aOrbiterG = RotL64((aOrbiterG * 2832836748513174311U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 5106468334224035972U) + RotL64(aNonceWordA, 7U);
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10228769728713526172U;
            aOrbiterB = RotL64((aOrbiterB * 9760310686414358435U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7687649520668883142U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7757480627354711605U) ^ RotL64(aNonceWordH, 61U);
            aOrbiterC = RotL64((aOrbiterC * 7222553727737349209U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10876291698508634557U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8149278085586014186U;
            aOrbiterD = RotL64((aOrbiterD * 8577133863470695381U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15592893988925610485U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 8639028256640537165U;
            aOrbiterE = RotL64((aOrbiterE * 1880655276432963955U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 475660347892196219U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1903736092401853832U;
            aOrbiterH = RotL64((aOrbiterH * 8486318978769094799U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12463250192809450953U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 7253918448601703982U;
            aOrbiterJ = RotL64((aOrbiterJ * 3821034106528009129U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5171661020093804486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11627344933828324146U;
            aOrbiterI = RotL64((aOrbiterI * 5388047063152043277U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6206801139131132815U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 9221302203943031377U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12912049016813367241U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1798857939965423979U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5476854168685641232U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3884216989250294213U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2816659151953455230U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 15920462086654025436U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17843161654734820613U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterF, 36U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 44U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + RotL64(aNonceWordC, 23U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterB, 5U)) + aOrbiterJ);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterD);
            aWandererK = aWandererK + ((((RotL64(aCross, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + RotL64(aNonceWordB, 5U));
            aWandererH = aWandererH + ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 41U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 10U)) + aOrbiterA) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4273U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 5734U)) & W_KEY1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2232U)) & W_KEY1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1902U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 35U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterF = ((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 12669015908335980355U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 35U)) + 5438715179868613192U;
            aOrbiterE = (aWandererK + RotL64(aCross, 10U)) + 13172104448184536460U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 47U)) + 13421421503244744803U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 11U)) + 13327113302994856582U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 4671768205922454413U) + aPhaseCOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aIngress, 26U)) + 5355759962838579929U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 51U)) + 6691720614265406851U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 21U)) + 7063906424700911378U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 17328616394166672263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1542940602574207068U;
            aOrbiterE = RotL64((aOrbiterE * 8981679306319627975U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7203866278803132454U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 993485696233139264U;
            aOrbiterA = RotL64((aOrbiterA * 11609009908810366447U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15659679028507488331U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 18321361454094675842U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3966860765622641843U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9633319822696783352U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3496559332232402963U;
            aOrbiterI = RotL64((aOrbiterI * 7772060229838162977U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 1918349708324205526U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7701088402761359134U;
            aOrbiterF = RotL64((aOrbiterF * 9649485438465644795U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 6006824348814439686U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 18088375375347012557U;
            aOrbiterC = RotL64((aOrbiterC * 12801082943086128385U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12816533373478543584U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17951880253818836433U;
            aOrbiterG = RotL64((aOrbiterG * 8935839101517220201U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11311632024372748238U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9891349164779752351U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11405973752233193209U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 711130292000437038U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 17818800917771709681U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10567029732245868263U), 43U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterG, 19U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 34U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 53U)) + aPhaseCWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aCross, 24U) + aOrbiterJ) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 53U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterE, 5U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 13U)) + aOrbiterF) + RotL64(aCarry, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 43U) + aOrbiterE) + RotL64(aOrbiterF, 46U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8652U)) & S_BLOCK1], 13U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 8483U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 12571U)) & W_KEY1], 26U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 9265U)) & W_KEY1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCross, 39U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = (((aWandererF + RotL64(aScatter, 46U)) + RotL64(aCarry, 39U)) + 17936518874386450467U) + aPhaseCOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 29U)) + 13722737841589910344U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 11774969167948715796U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 5U)) + 3640101505680493777U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 39U)) + 1369495382725650822U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 51U)) + 11827310354654653345U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aCross, 13U)) + 186037671377175394U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 19U)) + 11428829344234627340U;
            aOrbiterE = (aWandererG + RotL64(aCross, 56U)) + 2275016369870029068U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 15471646673734798328U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12172082573115640145U;
            aOrbiterH = RotL64((aOrbiterH * 9629417882787847753U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6626736341348283154U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12220614992483863623U;
            aOrbiterD = RotL64((aOrbiterD * 8137086205714097487U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13157102324253760215U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4143587482368093601U;
            aOrbiterC = RotL64((aOrbiterC * 5060677690991506895U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 11007575246013796426U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11721585930088637162U;
            aOrbiterG = RotL64((aOrbiterG * 15009627907125738519U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 5720789204450196217U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 3094696226821431648U;
            aOrbiterE = RotL64((aOrbiterE * 4412033981712165541U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 14675830108100986773U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9444071495289719645U;
            aOrbiterB = RotL64((aOrbiterB * 10983136361953366557U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 5106753847015199956U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7585421898593510010U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 140996914192351011U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11746948407655524690U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16336323220286344483U;
            aOrbiterF = RotL64((aOrbiterF * 6590417628835864497U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 8030445186765781136U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 276034088015165891U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7626025612710225099U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterH, 44U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterA, 24U));
            aWandererF = aWandererF + (((RotL64(aIngress, 48U) + RotL64(aOrbiterA, 29U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 43U)) + aOrbiterH);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 51U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 54U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterB, 5U));
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterF, 60U)) + aPhaseCWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterC, 11U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16547U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 22059U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21846U)) & W_KEY1], 36U) ^ RotL64(aKeyRowReadB[((aIndex + 17843U)) & W_KEY1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 47U)) ^ (RotL64(aCross, 6U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererJ + RotL64(aIngress, 53U)) + 8604208734152026945U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 42U)) + 1374329953253889829U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 5U)) + 5779278910548228339U) + aPhaseCOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aPrevious, 47U)) + 17670451230882805140U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 29U)) + 8193848740764866860U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 18U)) + RotL64(aCarry, 43U)) + 15801168428145650104U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 13U)) + 2584718176087499066U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aPrevious, 37U)) + 14950366247822737997U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 9779293225265670135U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 8688968319288372383U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 13665723186950342601U;
            aOrbiterF = RotL64((aOrbiterF * 292035540396910837U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9395428688359973510U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 2152719218018108418U;
            aOrbiterD = RotL64((aOrbiterD * 15271961483518392671U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1350324137411377992U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8729317951386057921U;
            aOrbiterE = RotL64((aOrbiterE * 6008790836417785083U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6317310451893678411U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 10175620379041384281U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14079679617394330781U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1203082119358827708U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 523869107818193101U;
            aOrbiterC = RotL64((aOrbiterC * 4629501113595689157U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4028324959540432983U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15447631947468213912U;
            aOrbiterJ = RotL64((aOrbiterJ * 6037306615787729185U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14225888694733041031U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 11925000696281947629U;
            aOrbiterK = RotL64((aOrbiterK * 4337022940520411253U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15015531024930608745U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16752579225076943550U;
            aOrbiterI = RotL64((aOrbiterI * 15551083683579981439U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2432733494869267901U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10103430321388601485U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18372919379972432569U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterF, 36U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterK, 23U)) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 18U) + aOrbiterD) + RotL64(aOrbiterB, 47U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 52U)) + aOrbiterI);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 46U) + aOrbiterE) + RotL64(aOrbiterC, 13U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 20U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24870U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 25140U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32646U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((aIndex + 25439U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCarry, 57U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 24U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aIngress, 18U)) + RotL64(aCarry, 37U)) + 16802219662864902427U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 11U)) + 14332033461409490629U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 41U)) + 8781794298640286845U) + aPhaseCOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aScatter, 29U)) + 8459933908074937264U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 1883580287986004426U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 23U)) + 17500258188004626118U;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 7934811305150872870U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 35U)) + 6380363892361098905U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 6U)) + 12623079132626676910U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10455208121949202703U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8805532707916767629U;
            aOrbiterD = RotL64((aOrbiterD * 666082374369701881U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9161544391400377699U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3501434325829663268U;
            aOrbiterF = RotL64((aOrbiterF * 7933545151293799637U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 651783304096081996U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 441505031509930622U;
            aOrbiterC = RotL64((aOrbiterC * 8045355432310956143U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 1771159983581326424U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15227946417377695989U;
            aOrbiterG = RotL64((aOrbiterG * 1563141188972797601U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4153717524193279095U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4404521756523902829U;
            aOrbiterI = RotL64((aOrbiterI * 1410342912973206203U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 6231945075461813285U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3864780227164426690U;
            aOrbiterH = RotL64((aOrbiterH * 18031353247480673617U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1509699687948576558U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17316114302489411191U;
            aOrbiterB = RotL64((aOrbiterB * 15490661284980281585U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2250572827340157410U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 6403966113144372915U;
            aOrbiterJ = RotL64((aOrbiterJ * 726441947009132383U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2329903609147403156U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 2486330017319455238U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17427461345935191757U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 46U) + aOrbiterC) + RotL64(aOrbiterG, 6U)) + RotL64(aCarry, 29U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 39U)) + aOrbiterJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC + ((RotL64(aScatter, 19U) + aOrbiterD) + RotL64(aOrbiterH, 60U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + aOrbiterG) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 43U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2601U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4415U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4104U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 12U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 27U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererE + RotL64(aScatter, 28U)) + 14686411261024919129U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 7514582233957632005U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 6520710480103365552U) + aPhaseDOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 39U)) + 1983621978676188036U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 39U)) + 9003524602590749672U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 6428568234045228995U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 8656552687136446989U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16297456077021607301U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16916248288415922490U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 9740237548002535784U;
            aOrbiterB = RotL64((aOrbiterB * 7970729853948983849U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 907561000814618339U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4751108900841197631U;
            aOrbiterK = RotL64((aOrbiterK * 4545395964730641957U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 167774899400732287U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 11907484918310854962U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7213139491146402985U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 14910318613649863924U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14882888155751455276U;
            aOrbiterC = RotL64((aOrbiterC * 11394136445442060201U), 3U);
            //
            aIngress = RotL64(aOrbiterK, 38U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 58U) + aOrbiterK) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 5U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 58U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11883U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15705U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8244U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 8500U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 22U)) ^ (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererB + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 13915875634607599122U) + aPhaseDOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aPrevious, 6U)) + RotL64(aCarry, 35U)) + 1695770381382411673U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 53U)) + 3709105579778295511U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 19U)) + 7673376335333251804U) + aPhaseDOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 8814147709738503518U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 13451412605350381172U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6447870234069609538U;
            aOrbiterB = RotL64((aOrbiterB * 4016219229618539433U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13419487997946496825U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 5478309847615220345U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12953043149543448765U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 3635184969215610049U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12527903812035294828U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12540800512035534967U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1684685110885338814U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12860354576326835090U;
            aOrbiterH = RotL64((aOrbiterH * 12743745087733307255U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9081823570147481835U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 14369321778210049109U;
            aOrbiterE = RotL64((aOrbiterE * 17865953349448767035U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 54U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aScatter, 10U) + aOrbiterE) + RotL64(aOrbiterH, 54U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17290U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 20461U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20016U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 21549U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 14U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 41U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = (aWandererG + RotL64(aCross, 53U)) + 77518479758428414U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 3U)) + 4832061802166300011U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (((aWandererE + RotL64(aIngress, 40U)) + RotL64(aCarry, 43U)) + 11695291171006574112U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 7467412817843260094U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 17801484124471154757U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5555455638503958639U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5669470540733721606U;
            aOrbiterC = RotL64((aOrbiterC * 17219613748084498879U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3042388456327784163U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2236734925228156691U;
            aOrbiterG = RotL64((aOrbiterG * 10076582424701705531U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 14459720401528685450U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4814967631216658856U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 18288097536171386643U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 16950679344449075945U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 6262238639302011050U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9942659897425088183U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3522256359074996724U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12524717897707074242U;
            aOrbiterI = RotL64((aOrbiterI * 6787771338063891989U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aIngress, 57U) + aOrbiterG) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 27U)) + aOrbiterI);
            aWandererG = aWandererG + ((RotL64(aCross, 23U) + aOrbiterA) + RotL64(aOrbiterG, 5U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterB, 36U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 36U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31847U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 27118U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28683U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 26284U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 40U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aCross, 14U)) + 17454559218352016650U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 8005709669325164803U) + aPhaseDOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 53U)) + 13393741948412816357U) + aPhaseDOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 41U)) + 3665865624348875553U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 29U)) + 8334142570031883436U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 17226066128706139657U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 3319093033121522613U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17961784341097933029U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6657535603401588798U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5469746182326331147U;
            aOrbiterD = RotL64((aOrbiterD * 11315450342347794329U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17846791786050221418U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 15939541003714896288U;
            aOrbiterJ = RotL64((aOrbiterJ * 1400351482213119809U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12076763190461077406U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 3594038213596405284U;
            aOrbiterH = RotL64((aOrbiterH * 10244002692575821495U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8301291631324464622U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 8460406137668390582U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9117147929757711595U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 3U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterJ, 29U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 60U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 22U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 591U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((aIndex + 2953U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1240U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 6195U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 3U)) + (RotL64(aCross, 51U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 35U)) + 1393781663398437180U) + aPhaseEOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 17414594746688585273U;
            aOrbiterA = (((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 3U)) + 2823888497053071250U) + aPhaseEOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 44U)) + RotL64(aCarry, 37U)) + 17032631958617884859U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 51U)) + 15222697630461125019U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 23U)) + 15737414920751551780U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 13U)) + 1357196111055783001U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5315122321649251691U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7893744655508595974U;
            aOrbiterA = RotL64((aOrbiterA * 17863000246694319149U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 16721939414324611738U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3444375866323610848U;
            aOrbiterJ = RotL64((aOrbiterJ * 10874157227815775661U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 1825716513674511632U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 15582066843912467318U;
            aOrbiterH = RotL64((aOrbiterH * 12765146555943757373U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15673590949193923915U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13887365046280406413U;
            aOrbiterC = RotL64((aOrbiterC * 3169061375011420121U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 12730414371734709356U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 4819112390640821927U;
            aOrbiterE = RotL64((aOrbiterE * 8782547948627685451U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3089925954422937464U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7180179304678622530U;
            aOrbiterK = RotL64((aOrbiterK * 16118051565147747413U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17030269962085008657U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6675917351883004046U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14134335325316949687U), 51U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 51U);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 44U));
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterC, 54U));
            aWandererD = aWandererD + ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterE, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 35U)) + aOrbiterG);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 12U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11967U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneD[((aIndex + 9196U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9728U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 13712U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 7960325128608297381U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 13U)) + 12773836012104052042U;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 3173972621347773016U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 51U)) + 3708401356314308171U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 43U)) + 950774285720019449U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 5U)) + 4170092315705438265U;
            aOrbiterI = ((aWandererD + RotL64(aPrevious, 36U)) + RotL64(aCarry, 47U)) + 17000449130864980747U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8793910540062893860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 520277969543516469U;
            aOrbiterF = RotL64((aOrbiterF * 4150613128885828229U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12762214857389827271U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2932451184340207695U;
            aOrbiterH = RotL64((aOrbiterH * 7513337346940091655U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11062179998786293839U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 7919119215271524178U;
            aOrbiterB = RotL64((aOrbiterB * 9053677007180081359U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 1774988449597115155U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3799792889466518953U;
            aOrbiterJ = RotL64((aOrbiterJ * 17512791286490623455U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1815062051307896589U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15260373951371654483U;
            aOrbiterC = RotL64((aOrbiterC * 2208604434669491625U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12867546628945676853U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 7772820973895846946U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7581704643538761985U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 14213957831821966834U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16561105721170419454U;
            aOrbiterI = RotL64((aOrbiterI * 2540533987337175367U), 53U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 37U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 51U));
            aWandererC = aWandererC + ((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterB, 11U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererH = aWandererH + ((((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 19U)) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 58U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24227U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17446U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20299U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneC[((aIndex + 16801U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 3U)) + (RotL64(aIngress, 47U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 46U)) + RotL64(aCarry, 3U)) + 3973833383430652211U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 5U)) + 5760227042747169187U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 4923009065139227286U) + aPhaseEOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aScatter, 37U)) + 1477807307009107590U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 27U)) + 5707194514329007301U;
            aOrbiterH = (aWandererG + RotL64(aCross, 11U)) + 5340439728375269724U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 17080457898946572387U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 281559150259472813U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 16160633048230910560U;
            aOrbiterD = RotL64((aOrbiterD * 16883442583309073785U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9003989610509592121U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10579322462808454333U;
            aOrbiterJ = RotL64((aOrbiterJ * 100832431598087235U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15059383289528723069U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 10417647757852880956U;
            aOrbiterI = RotL64((aOrbiterI * 1457919230286043137U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 14484665027393813330U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12344463053485837974U;
            aOrbiterF = RotL64((aOrbiterF * 5762654194001525041U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5826453246659297805U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12547902286376986223U;
            aOrbiterA = RotL64((aOrbiterA * 2982850000322672789U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 9637855144278126174U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2132744427444501938U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5911587798564836199U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9248933938130311231U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 13274297928717090383U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2901398809555237563U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 56U));
            aIngress = aIngress + RotL64(aOrbiterI, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 50U) + aOrbiterJ) + RotL64(aOrbiterD, 13U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 26U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 53U)) + aOrbiterH);
            aWandererI = aWandererI + ((RotL64(aCross, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28114U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32371U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27254U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32131U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCross, 44U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aIngress, 53U)) + 13687218104610230596U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 41U)) + 6841550124960692709U;
            aOrbiterE = (aWandererD + RotL64(aCross, 29U)) + 17418968668458764131U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 43U)) + RotL64(aCarry, 21U)) + 8303537912696948204U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 14U)) + 12376614417285936537U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aScatter, 3U)) + 14215749063579232654U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 5U)) + 4111736931433665347U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11250375934571631522U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 5367367837773331275U;
            aOrbiterE = RotL64((aOrbiterE * 7262723007545807179U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15514089192382674434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1475991716685034960U;
            aOrbiterH = RotL64((aOrbiterH * 17720681295551650891U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5531622777788629748U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 8363822215908303335U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17850203366840994883U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3741256932685720414U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11634667238062155772U;
            aOrbiterC = RotL64((aOrbiterC * 15925089729784547403U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 18180546911210417155U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 5123234656838556335U;
            aOrbiterI = RotL64((aOrbiterI * 15362857462853398025U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11215734271189250284U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16863747802158398092U;
            aOrbiterG = RotL64((aOrbiterG * 1828035970246160023U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9859050606636646323U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 9331300036643654675U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2502263410556166281U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterG, 13U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterE, 4U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterF);
            aWandererF = aWandererF ^ (((RotL64(aCross, 60U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 18U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_PickleBall_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3575U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneC[((aIndex + 7180U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3482U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 7469U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 6U)) ^ (RotL64(aCross, 37U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 2330952702412094686U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 7820188225935060799U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 38U)) + 9347644591709839145U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 2288624878446846870U) + aPhaseFOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aIngress, 5U)) + 9358977729492824128U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 1858511275052455039U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13715478509322292552U;
            aOrbiterK = RotL64((aOrbiterK * 15552121744869003235U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16413396625604260455U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17714322215518432705U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1904184102419934333U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16188315436202861122U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5564445841368207813U;
            aOrbiterE = RotL64((aOrbiterE * 14125834616162835983U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 13717068949900594673U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14143659432287313765U;
            aOrbiterD = RotL64((aOrbiterD * 17281441046722262917U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5729546141908425670U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4297827922736712074U;
            aOrbiterH = RotL64((aOrbiterH * 13631630436759768885U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterH, 3U)) + RotL64(aCarry, 11U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterE, 11U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 40U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterE, 39U));
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 56U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + RotL64(aWandererK, 14U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9285U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11849U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13386U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 10431U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 47U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 28U)) + 966899917801652720U;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 10996327672320748649U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 4188171566846621107U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 5886209243097387959U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 19U)) + 14940428957136728111U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 179187285531914832U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 6685351948936817752U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15533370414711696803U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1894506461704029700U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4182760368636977082U;
            aOrbiterF = RotL64((aOrbiterF * 972988091869133921U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12523318028514940790U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 5059306166973366892U;
            aOrbiterE = RotL64((aOrbiterE * 2857409765717296483U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 5890872367917643851U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 17747338389865221534U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5306740664798049267U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13906227834259884100U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7152105382899756368U;
            aOrbiterA = RotL64((aOrbiterA * 6772157117358310485U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 40U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 14U) + aOrbiterF) + RotL64(aOrbiterE, 26U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + RotL64(aCarry, 29U)) + aPhaseFWandererUpdateSaltF[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 43U)) + aOrbiterD) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 30U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20497U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22432U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19763U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 19964U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 37U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 20U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 1142447269198373880U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererD + RotL64(aScatter, 21U)) + 10581460640040336191U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 11U)) + 14703062773878202900U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 41U)) + 15737525756286914746U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aPrevious, 44U)) + 16178774478273186999U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2514897053906809160U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13702496607592508464U;
            aOrbiterA = RotL64((aOrbiterA * 16540143680974064057U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 18030885275418337965U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5241783876161655984U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10970981186787227937U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 2807052676283587925U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8022804576763271327U;
            aOrbiterD = RotL64((aOrbiterD * 11727096043219370577U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15597099852232205860U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 1538435607932096400U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7900752511710516981U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11147868774413615365U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9325213746830411568U;
            aOrbiterE = RotL64((aOrbiterE * 561819005818948769U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterF, 27U)) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterE, 46U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 3U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererE, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25989U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31274U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32679U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 31693U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 37U)) + RotL64(aCarry, 43U)) + 4752759164691497960U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 11U)) + 12088872623537639782U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 56U)) + 3734943577379734227U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 8854778183012444234U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 57U)) + 16948373492893967275U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7962415690046184385U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1872682375669714454U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 959061892772099785U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 7776801806943853566U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16665439117257230732U;
            aOrbiterF = RotL64((aOrbiterF * 6866375628213114965U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 11088186766134265676U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10850237991780969350U;
            aOrbiterC = RotL64((aOrbiterC * 7547414856143095121U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6464817712131305812U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 244557182884209844U;
            aOrbiterI = RotL64((aOrbiterI * 2394270354887582889U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13261563971157415841U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 2323811103717827362U;
            aOrbiterE = RotL64((aOrbiterE * 11483723582415081925U), 11U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterA, 29U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 39U) + aOrbiterE) + RotL64(aOrbiterC, 12U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + RotL64(aWandererK, 10U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 3425U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneB[((aIndex + 4573U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 222U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 4716U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) ^ RotL64(aCross, 51U)) + (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 23U)) + 3612110001869385068U) + aPhaseGOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aPrevious, 27U)) + 16340824141280225936U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 44U)) + RotL64(aCarry, 5U)) + 15222338965130765231U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 35U)) + 6649270508107155041U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 19U)) + 768217258655426384U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 4481855259658861851U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 18318041934562434016U;
            aOrbiterH = RotL64((aOrbiterH * 14913761339765234979U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4212457153804401807U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16143621095636987628U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6576072860505961427U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2095664232866642086U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4339527736737366572U;
            aOrbiterI = RotL64((aOrbiterI * 17503569508822244125U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13679353177869884790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11582168502846418236U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 135539430034462861U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 10451330452898542191U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 12951448817640617841U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4141870904192742091U), 27U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + aPhaseGWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 57U) + aOrbiterI) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 39U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 5U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 20U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10835U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 15551U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13527U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16377U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 39U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 29U)) + RotL64(aCarry, 27U)) + 9220392006207660113U;
            aOrbiterC = (aWandererK + RotL64(aCross, 54U)) + 11305018553489132882U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 5860373868073513684U) + aPhaseGOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 12319586170883987589U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aScatter, 37U)) + 14072333614354649021U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9332158529453194608U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3860569321145958686U;
            aOrbiterJ = RotL64((aOrbiterJ * 907977527866467591U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8119005668901240093U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13918259792880333239U;
            aOrbiterE = RotL64((aOrbiterE * 5441062406822088853U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 6938856216758228704U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 3960905839118710604U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16203746868670689793U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6043879193734253929U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15691425268831319195U;
            aOrbiterC = RotL64((aOrbiterC * 7189195135654636271U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 14912209933584715274U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 16180183395910618923U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3942858974766467849U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 52U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererB = aWandererB + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + aPhaseGWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 44U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 28U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 17245U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((aIndex + 18621U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17204U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20662U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 48U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (aWandererI + RotL64(aScatter, 27U)) + 6163290588946759209U;
            aOrbiterF = (((aWandererK + RotL64(aCross, 12U)) + RotL64(aCarry, 39U)) + 7342672468560105447U) + aPhaseGOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 11574563167017282321U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 2254820206194758964U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 35U)) + 1469783447473099498U) + aPhaseGOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14174828900676165088U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16277954291890598132U;
            aOrbiterJ = RotL64((aOrbiterJ * 4608888834164373691U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14845750668693136766U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 150099699692047766U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7644895634421086357U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1200784917165131703U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9469982764806754302U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17851969334511301943U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 10956702761701710182U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 7915506894975487807U;
            aOrbiterG = RotL64((aOrbiterG * 8874108311712727983U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 17335794183733623213U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 557028996286989506U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3993359298602424281U), 3U);
            //
            aIngress = RotL64(aOrbiterF, 24U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 5U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 4U)) + RotL64(aCarry, 19U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 56U) + aOrbiterG) + RotL64(aOrbiterK, 35U)) + aPhaseGWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 27578U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 28156U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28155U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 25576U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 48U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererB + RotL64(aPrevious, 3U)) + 4773124477323378268U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 37U)) + 16848723289435796005U) + aPhaseGOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 39U)) + RotL64(aCarry, 13U)) + 13846642134917107058U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 6472057872482789939U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 48U)) + 2747019500690707226U) + aPhaseGOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 9003965289739733880U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 3013390651936257377U;
            aOrbiterF = RotL64((aOrbiterF * 11081353600889943167U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 3331004709895625067U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 15355010435553517129U;
            aOrbiterI = RotL64((aOrbiterI * 8322759117004876831U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7709870658004280052U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13568728443963926564U;
            aOrbiterH = RotL64((aOrbiterH * 6736090830113688981U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12409548853419307131U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 969183352023661537U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5549220554838837145U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 15370309834426476775U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3896803894396631184U;
            aOrbiterB = RotL64((aOrbiterB * 11018830202891911603U), 3U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 5U);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 37U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 58U) + RotL64(aOrbiterB, 21U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aPhaseGWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterD, 60U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aIngress, 37U) + aOrbiterI) + RotL64(aOrbiterH, 13U)) + RotL64(aCarry, 5U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 13U) + aOrbiterD) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
        // read from: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2794U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((aIndex + 2731U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8192U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 3257U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 11U)) + 3339283916456813609U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aCross, 29U)) + 11339086426180649584U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 16819191669329316585U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 8361916937762630725U;
            aOrbiterI = (aWandererH + RotL64(aIngress, 19U)) + 18031328374429899857U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 18261756894092897276U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4250319792907645666U;
            aOrbiterA = RotL64((aOrbiterA * 7053489184750217963U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1492411503643460886U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 17369549067879344180U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2947354306696216579U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7301713524358676722U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2985193736033012535U;
            aOrbiterG = RotL64((aOrbiterG * 7473297294949338265U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14086975808140927408U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10390516547834639800U;
            aOrbiterE = RotL64((aOrbiterE * 11441293212275890819U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 18205555540941493267U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16967799565443938873U;
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 21U);
            //
            aIngress = RotL64(aOrbiterK, 57U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererB = aWandererB + ((((RotL64(aCross, 20U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterK, 19U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterG, 30U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 28U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14198U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneC[((aIndex + 11549U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10064U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9948U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 20U) + RotL64(aCross, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 57U)) + 6068543441070417854U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 12U)) + 2995980468193441856U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 35U)) + 18020277482171594003U) + aPhaseHOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 41U)) + 4293807434721230702U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 7980599111583893156U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8593141111851052016U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5903487523900084325U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2508618861111356699U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15112035513447930209U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9854037263057006439U;
            aOrbiterB = RotL64((aOrbiterB * 396276470208637283U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16759760289688823193U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 12622628933030601390U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2151912984825538321U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1264668857268123425U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16302812053619101593U;
            aOrbiterJ = RotL64((aOrbiterJ * 18291400055836111547U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16087995784896123610U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7970269262800468363U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14924752223305807461U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 14U);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 3U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterF, 27U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterJ, 53U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 40U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 13U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18278U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 22694U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17038U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24048U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererG + RotL64(aIngress, 54U)) + RotL64(aCarry, 35U)) + 15813325389431304548U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aPrevious, 41U)) + 2223874171125403602U;
            aOrbiterH = (aWandererH + RotL64(aCross, 27U)) + 5510483568496824130U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 21U)) + 15474152493495661876U) + aPhaseHOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 16846339705130829195U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1289670576865739669U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 18017354919647006944U;
            aOrbiterH = RotL64((aOrbiterH * 13103155460891498469U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 8539685539928984921U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 3333721400836704048U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3745286323481400085U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 2261560416623815491U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4377786131746816567U;
            aOrbiterG = RotL64((aOrbiterG * 9164777834392621157U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18047393176583722719U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 8184724021940434631U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9800116157750921119U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10469895939183324807U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14543391765109879223U;
            aOrbiterJ = RotL64((aOrbiterJ * 4817987697437667225U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 23U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 40U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterC, 41U)) + aOrbiterH) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterJ, 51U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 11U)) + aOrbiterE) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 4U) + aOrbiterC) + RotL64(aOrbiterG, 30U));
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererA, 27U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 29878U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneA[((aIndex + 29857U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24869U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25974U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 18U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (aWandererD + RotL64(aPrevious, 19U)) + 17470880031634374199U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 4U)) + RotL64(aCarry, 43U)) + 757565846006937746U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 37U)) + 9419282475801345674U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 19U)) + 2014248014107898196U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 15113928519446490441U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7346126964886259935U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5594123113093162359U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18043634828891483403U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5659237263369402005U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11565709683423969703U;
            aOrbiterA = RotL64((aOrbiterA * 16731289017588574671U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16782863743534856287U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13499100900072115907U;
            aOrbiterC = RotL64((aOrbiterC * 5567729598873214433U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11414447651044205242U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 7545993795121430538U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10758488381206257261U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11778229237616454988U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2544793391976514665U;
            aOrbiterB = RotL64((aOrbiterB * 4021060413798523299U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 29U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 56U)) + aOrbiterA) + aPhaseHWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 48U) + RotL64(aOrbiterC, 41U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 52U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
