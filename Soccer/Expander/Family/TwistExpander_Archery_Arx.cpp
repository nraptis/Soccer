#include "TwistExpander_Archery_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Archery_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8C92D54579A6D593ULL + 0x9C710F9991F545C2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFA18FA54D831310DULL + 0xF5E60BDD250102FEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x84A5C2980FB13921ULL + 0xF5F08C61E74CEA22ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE8988F48E6C8CDCDULL + 0x85D4008275D7906EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x80FDE31721474C2BULL + 0xCEB327A462B28C4EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD39254357632B2B3ULL + 0x8660EEBC6014B269ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x97BA3220F2C6D8DFULL + 0xB7B24613C5774E4CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE91C04C4E66E5595ULL + 0xF885C70B5F368DE3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFAD57BA0C105226BULL + 0xDFE5E9CFDEEC3FFBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x89D205929C36C17FULL + 0xC042F6090EF3DF85ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x9FF35F02C167320FULL + 0xAA021C57DDA46E06ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xCE25D5227D3D4BF7ULL + 0xCB469498E2722189ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD8C736C660055E75ULL + 0xDE451E27C46D2885ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA434BF47C8C372BBULL + 0x99D4CA53C925C7DDULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE74702CA9E1DF4BFULL + 0xB74200AB988BE1F3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA50B3C4E4E582D37ULL + 0x96344793EF9E0162ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1693U)) & S_BLOCK1], 18U) ^ RotL64(pSnow[((aIndex + 3145U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 30U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1571U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 27U)) + (RotL64(aIngress, 57U) ^ RotL64(aCarry, 10U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 7651355040951791298U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 35U)) + 13988210277931659312U;
            aOrbiterI = (aWandererF + RotL64(aPrevious, 53U)) + 9846849412579537783U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 12746719939495876158U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 40U)) + 11498066185182895284U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 3U)) + 11101058955193080232U) + aNonceWordK;
            aOrbiterH = (aWandererJ + RotL64(aCross, 51U)) + 15513734459555672046U;
            aOrbiterJ = (((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 15711108675349394643U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 20U)) + 4771231759949468556U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 57U)) + 11449258010811305256U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 13U)) + 17036938391509986723U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6999245666776654250U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2106819066263369528U;
            aOrbiterI = RotL64((aOrbiterI * 13005885810757743129U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12716183358903477216U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16752724547046059889U;
            aOrbiterF = RotL64((aOrbiterF * 11475905692393034141U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17623077680983093163U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 6726003022297274986U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14709385877103232653U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2842410225096524740U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9235178377537910514U;
            aOrbiterA = RotL64((aOrbiterA * 11813751114775673845U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2619888019860844610U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6295481948199619613U;
            aOrbiterH = RotL64((aOrbiterH * 15429161806953951205U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9724921158061115570U) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 4070976180958458679U;
            aOrbiterD = RotL64((aOrbiterD * 6080566609081811453U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5864247978960125554U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7771249710071026757U;
            aOrbiterG = RotL64((aOrbiterG * 4787660062590737657U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 15006900854988166845U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2755659268987119046U;
            aOrbiterC = RotL64((aOrbiterC * 8043939381186802359U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1922321482806966418U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 13910818219761929659U;
            aOrbiterB = RotL64((aOrbiterB * 8895973123729951173U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7540972911473176026U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 5419023469522423893U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1380429266266313945U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2349651834739320824U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 7651355040951791298U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3713776056028698433U), 19U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 26U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 13U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterK, 50U)) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterC, 39U));
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterI, 10U)) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 30U) + aOrbiterG) + RotL64(aOrbiterD, 41U)) + aNonceWordE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 42U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6009U)) & S_BLOCK1], 42U) ^ RotL64(mSource[((aIndex + 7551U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8672U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7383U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 52U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererD + RotL64(aPrevious, 5U)) + 1898718075389870739U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 44U)) + 5631794889237247403U) + aOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererH + RotL64(aCross, 35U)) + 18219714659484524607U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 15419581386225732921U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 11U)) + 9125575431710198210U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aWandererE + RotL64(aCross, 3U)) + 12205871520544965505U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 38U)) + RotL64(aCarry, 35U)) + 7617534300497343422U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 47U)) + 18017579105368135814U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 13U)) + 10693882161946020042U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 19U)) + 11669615701700895306U) + aNonceWordL;
            aOrbiterH = (aWandererI + RotL64(aCross, 23U)) + 11045110212889232165U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 18019107802806469913U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12315940560472528716U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 4505122470351404065U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4899009736070044310U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17412253404253730364U;
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4826286251927854181U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4523455921321845084U;
            aOrbiterJ = RotL64((aOrbiterJ * 14534103906736598099U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4132514462154182215U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 7164745605985109269U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14107325508977225261U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6297434295807635654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8813887638672996646U;
            aOrbiterE = RotL64((aOrbiterE * 17495632530773158201U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11086381278955626084U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 5660733992573928887U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11248164458720777889U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 14851044686208609882U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12707776386060264479U;
            aOrbiterF = RotL64((aOrbiterF * 4470919091467313071U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11508023384209716657U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11752973809740920034U;
            aOrbiterG = RotL64((aOrbiterG * 10212754472298834769U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16746821150860017820U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 9659421716296641396U;
            aOrbiterI = RotL64((aOrbiterI * 7530071874978553673U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 3192309064305104593U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11409078048681398061U;
            aOrbiterA = RotL64((aOrbiterA * 14991409124701807765U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 315359495275427324U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1898718075389870739U;
            aOrbiterH = RotL64((aOrbiterH * 13126661894614781343U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 37U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterC, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 34U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterD, 23U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterG, 39U)) + aNonceWordC) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterF, 21U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 48U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 11U)) + aOrbiterA) + aNonceWordM);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 51U));
            aWandererH = aWandererH + ((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 56U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 44U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11898U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15608U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 14816U)) & S_BLOCK1], 28U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 13035U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 58U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aScatter, 27U)) + 14214886793361825363U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 17267959031078766320U) + aNonceWordO;
            aOrbiterF = (aWandererD + RotL64(aCross, 3U)) + 16436067429484887644U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 5U)) + 9885951769332633820U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 57U)) + 12971711341813893304U;
            aOrbiterI = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 199970353398450154U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 23U)) + 1237341696444162094U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 51U)) + 7991128854417613360U) + aNonceWordH;
            aOrbiterD = (((aWandererF + RotL64(aIngress, 43U)) + 14809029847149045833U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 46U)) + 2559509556915775947U) + aOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 11U)) + 14336829730147834160U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 8853631886733610440U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13346159398673246914U;
            aOrbiterF = RotL64((aOrbiterF * 13660497151446983393U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 12121095718571872976U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 16239781125815589804U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5157009090454962231U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9051377033794324106U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13805815136723461780U;
            aOrbiterK = RotL64((aOrbiterK * 571129481747181357U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 14849157800322754413U) + aNonceWordI;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18116651528452542634U;
            aOrbiterG = RotL64((aOrbiterG * 3638480428016835537U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4105057226952948599U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5911714320560994391U;
            aOrbiterE = RotL64((aOrbiterE * 1796514171654961389U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 4439149331729987587U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10278532228230163632U;
            aOrbiterH = RotL64((aOrbiterH * 17428224919864716517U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 2342456582668741750U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2360578572554664800U;
            aOrbiterJ = RotL64((aOrbiterJ * 1108428466956691925U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12132934875391401246U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17213278726790245812U;
            aOrbiterB = RotL64((aOrbiterB * 11904899990681410419U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7994340481560109811U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13735851271080138255U) ^ aOrbiterUpdateSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12387076892129731557U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 6682417543888875268U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15642799286975840550U;
            aOrbiterD = RotL64((aOrbiterD * 7861250716882028053U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9839299346094784067U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14214886793361825363U;
            aOrbiterC = RotL64((aOrbiterC * 2103132743364916037U), 39U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 14U);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 36U)) + aOrbiterE) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterJ, 27U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterD, 43U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 34U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterC, 51U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 21U) + RotL64(aOrbiterG, 3U)) + aOrbiterF) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 36U) + aOrbiterI) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 57U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18895U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21402U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17356U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 20509U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 3U)) + (RotL64(aPrevious, 23U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 5160910997561396461U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 14920764751058512062U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 47U)) + 6080952401749660022U) + aOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 29U)) + 17667234330526298627U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 12U)) + 760630072638686756U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 27U)) + 3504157162816997476U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 23U)) + 9489022223422585882U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 41U)) + 1149898536879968964U) + aNonceWordK;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 43U)) + 10492284328940025310U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 60U)) + 13213275606286399312U;
            aOrbiterB = (aWandererH + RotL64(aCross, 39U)) + 10557118912847180413U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 15618980209023994776U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5268600749854045564U) ^ aNonceWordN;
            aOrbiterJ = RotL64((aOrbiterJ * 3849660559223919613U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8011552687609649990U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3148133096349525066U;
            aOrbiterI = RotL64((aOrbiterI * 5245156554959620007U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12032847944237867285U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 14999005703490824673U;
            aOrbiterG = RotL64((aOrbiterG * 6631584955208646049U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 5426735969392906710U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3593177531650386729U;
            aOrbiterH = RotL64((aOrbiterH * 12997284886192717043U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 1701444719333347373U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15928731228196894960U;
            aOrbiterC = RotL64((aOrbiterC * 1919318226904213433U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5960179456039157036U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5716434224061596483U;
            aOrbiterF = RotL64((aOrbiterF * 3731976564761202801U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2136841536293340279U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12969550408652728526U;
            aOrbiterD = RotL64((aOrbiterD * 7612191387451455137U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 3641997570461447114U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 4677572491523684525U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 2730358077882211651U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2741372094325164504U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4998631511811832690U;
            aOrbiterA = RotL64((aOrbiterA * 10619395395977372695U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6260464862798783617U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16489087874167346533U;
            aOrbiterK = RotL64((aOrbiterK * 11278053967185244867U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7043760915859224327U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 5160910997561396461U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15260149870590431675U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterA, 5U)) + aNonceWordJ);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 27U)) + aOrbiterG) + aNonceWordF) + aWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 18U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterC, 37U)) + aOrbiterH);
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + aOrbiterH) + RotL64(aOrbiterE, 54U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 36U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 34U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23266U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneA[((aIndex + 23594U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24470U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 23844U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 41U)) + (RotL64(aCross, 53U) + RotL64(aPrevious, 14U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererJ + RotL64(aCross, 14U)) + 479672811032092393U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 29U)) + 18061121631394564425U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 41U)) + RotL64(aCarry, 3U)) + 14237400452740566065U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 6723123812257706134U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 11U)) + 4247997188026499248U) + aNonceWordF;
            aOrbiterD = ((aWandererH + RotL64(aCross, 29U)) + 1939107415066134869U) + aNonceWordO;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 6U)) + 3912640123546395979U;
            aOrbiterH = (aWandererB + RotL64(aScatter, 37U)) + 8295478436553964298U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 51U)) + 3218960600711526885U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 47U)) + 5874096203353388890U) + aOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 19U)) + 10294536533673023358U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 11268561953904130747U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 16693201256788898423U;
            aOrbiterK = RotL64((aOrbiterK * 16291987237693567209U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7550969634681894654U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 9501647424602245869U;
            aOrbiterD = RotL64((aOrbiterD * 11265865222096866605U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8881869255994319423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16770136406906800016U;
            aOrbiterH = RotL64((aOrbiterH * 1782039587385512923U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16185384746435761363U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13841034186650721627U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12000155593277035447U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15229062695864608309U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3576122704615303733U;
            aOrbiterC = RotL64((aOrbiterC * 2433987493885779279U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13898167174453181224U) + aNonceWordE;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 12878032061609524049U) ^ aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18104665741338251495U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 12719156051299028649U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 8640980843376950769U;
            aOrbiterF = RotL64((aOrbiterF * 10242616778390983333U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12133332160916004365U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 8743563985229104484U;
            aOrbiterA = RotL64((aOrbiterA * 4575129690615054691U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7362223873479167793U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4230720394788635807U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 3658720603716856293U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5095842824285329272U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7483469517256234638U;
            aOrbiterG = RotL64((aOrbiterG * 9782114499878763883U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17426017004856399653U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 479672811032092393U;
            aOrbiterB = RotL64((aOrbiterB * 14921028515589317919U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 10U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 30U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE + ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterK, 43U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 47U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 37U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 35U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 21U) + aOrbiterK) + RotL64(aOrbiterF, 3U));
            aWandererB = aWandererB + ((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + aWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterK, 6U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31120U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28932U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31986U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29486U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 57U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 42U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 23U)) + 15910560457440369082U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 29U)) + 17953072986407436888U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 54U)) + RotL64(aCarry, 47U)) + 15446940721193538669U) + aOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 41U)) + 3020785262774422009U;
            aOrbiterD = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 7001288645424994404U) + aNonceWordI;
            aOrbiterI = (aWandererA + RotL64(aIngress, 3U)) + 13385250665458462689U;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 6U)) + 4841895644623005949U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 27U)) + 13053476783239482065U;
            aOrbiterB = (((aWandererH + RotL64(aIngress, 35U)) + 641996979335975244U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = (aWandererD + RotL64(aScatter, 21U)) + 16211238020928688299U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 13U)) + 12715448751323279480U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 17784406727699995290U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16626339815786580778U;
            aOrbiterF = RotL64((aOrbiterF * 13940754474750138041U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9035070625716345139U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6085848172494001945U;
            aOrbiterD = RotL64((aOrbiterD * 10405728912339646693U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 1177103851507561053U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9040984343694325070U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 13334258224023902365U;
            aOrbiterJ = RotL64((aOrbiterJ * 4782523727707164869U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 1079824790138592518U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 14024082692012948652U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3219489374333737903U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 2966776524421278970U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 5510281854029308547U;
            aOrbiterB = RotL64((aOrbiterB * 9275402927591867297U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7126632329316720048U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1476827035602733472U;
            aOrbiterE = RotL64((aOrbiterE * 2217671289726794033U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6470212302133184965U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4172257438373147415U;
            aOrbiterG = RotL64((aOrbiterG * 4449314239630366533U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11445212164224402184U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 1779825157413363285U;
            aOrbiterH = RotL64((aOrbiterH * 15393425495668107155U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7561888690947559866U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14440989817038856852U;
            aOrbiterC = RotL64((aOrbiterC * 5799807036762859679U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10618807050937260814U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15910560457440369082U;
            aOrbiterA = RotL64((aOrbiterA * 10902491688248464465U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 12U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterK, 50U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aIngress, 18U) + RotL64(aOrbiterA, 53U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 41U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 11U)) + aOrbiterF) + aNonceWordO);
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 19U)) + aOrbiterE) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 13U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterH, 38U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererA, 24U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordH);
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

void TwistExpander_Archery_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFC9FD5B5835CE8F5ULL + 0xC4D23950D0D9B4E9ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBE8D953921C07893ULL + 0xA4EE8143BF0FCD56ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEF527D5A13DAD72DULL + 0xF40C6E0358547779ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xBB85AA659E0FB8C5ULL + 0x80490B16AF18556DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8711E1DDF18A384FULL + 0xACAD1C1F88371972ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA899B1FC4745FC13ULL + 0xBFF30D09EB45692BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF42BE6757DEA8599ULL + 0x899B2FE579B9C9A2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xF3EADAEE86088AB1ULL + 0xF18F81466C42A0BEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC97D6898AD4C7DEDULL + 0x884AB3AC83CEC1D6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBBCCC349388ADA1FULL + 0xD9737917B7254FF5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD2F1F1FEC7BC3B6DULL + 0xD6D19C3F59237D21ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xBAA7DA201A9A6355ULL + 0xEBD69D8AA61C9AA7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD9C63865D149DB03ULL + 0xE4F0A1B7535D5E74ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD19270148A2DDE91ULL + 0xB518A123677ABED9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xA5B2B01BCAB00A89ULL + 0xE660EB1ACB6ED718ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xB11BC6FE030A3B45ULL + 0x85E9A2E434912CC4ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2940U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4902U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6082U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5695U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 36U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aScatter, 27U)) + 10038936806177516123U;
            aOrbiterC = (aWandererB + RotL64(aCross, 14U)) + 1773168435195292638U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 10655711161526628072U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 3U)) + 14422295664639740437U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 43U)) + 4125228715513159576U;
            aOrbiterE = ((((aWandererK + RotL64(aCross, 46U)) + RotL64(aCarry, 3U)) + 3670449653158650845U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererG + RotL64(aIngress, 35U)) + 17553727567180813057U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 51U)) + 5111401772713882743U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererE + RotL64(aCross, 23U)) + 7688573124662314413U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 9438375825507814395U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14177477039902118886U;
            aOrbiterA = RotL64((aOrbiterA * 6467406626985022537U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16329942595859623928U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3990536794006836672U;
            aOrbiterE = RotL64((aOrbiterE * 579024714339065373U), 35U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterA) + 5072881436583180756U) + aOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16789727877867289997U;
            aOrbiterI = RotL64((aOrbiterI * 8766246302636197905U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17313956922306689438U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11530878396329822041U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11356860047841383129U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 3612616532321160196U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4172189825359187763U;
            aOrbiterG = RotL64((aOrbiterG * 12938945495299393177U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 8677279703778052804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1912172980909479362U;
            aOrbiterF = RotL64((aOrbiterF * 10053289257955474143U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1460085850227494500U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 12116763868122868147U;
            aOrbiterD = RotL64((aOrbiterD * 6076945628020280957U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 17571840610366424432U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15581362592611080868U;
            aOrbiterC = RotL64((aOrbiterC * 1129054058044872003U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14434700039977611666U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4534294602623329152U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 5860911553425182045U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 18U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererE = aWandererE + (((((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 12U)) + RotL64(aCarry, 23U)) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 52U) + aOrbiterG) + RotL64(aOrbiterA, 39U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterI);
            aWandererI = aWandererI + ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterC, 58U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 19U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterJ) + aNonceWordH);
            aWandererB = aWandererB ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16367U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 12951U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15250U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 9424U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aCross, 22U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererC + RotL64(aScatter, 23U)) + 13960289014350612206U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 3483331015269589730U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aIngress, 47U)) + 6873299241002444518U;
            aOrbiterG = (aWandererA + RotL64(aCross, 10U)) + 3562094007125534229U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 29U)) + 11422367439932782705U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 39U)) + 532453428514259816U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 19U)) + 17810941465810193088U) + aNonceWordB;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 11869759058631106331U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 6U)) + RotL64(aCarry, 5U)) + 8837581071876177566U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17185378327053837778U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7578253375676981500U;
            aOrbiterJ = RotL64((aOrbiterJ * 13371647568758721729U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17112646434432814442U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 14949096407295697881U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14770977858283051753U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4259590620758467836U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6534899413644542303U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7987609419215568661U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 2637407498893694243U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15819295597921425711U;
            aOrbiterE = RotL64((aOrbiterE * 5202015597375051399U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6373559542002699718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11694562937392022505U;
            aOrbiterD = RotL64((aOrbiterD * 9311557972331218597U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3308736483775453062U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 12749929710650475901U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 248428400724560945U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1569528215675579656U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 1044077933631689572U) ^ aNonceWordP;
            aOrbiterG = RotL64((aOrbiterG * 6443796233912755143U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8393422728124537471U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 2002732612516530754U) ^ aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13702146823622364279U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13469191942843147943U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7633171368709520560U;
            aOrbiterA = RotL64((aOrbiterA * 9713514012478203047U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 29U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 54U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 3U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 14U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 20U) + aOrbiterG) + RotL64(aOrbiterB, 53U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 35U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 44U)) + aOrbiterI) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 10U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 6U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterE, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 6U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 16674U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17201U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 24106U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16434U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 58U)) + (RotL64(aPrevious, 11U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aScatter, 10U)) + RotL64(aCarry, 5U)) + 16124889768301047791U;
            aOrbiterI = (aWandererK + RotL64(aCross, 29U)) + 11912338587186717280U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 23U)) + 8594012868813114354U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 43U)) + 18281043566156682815U) + aNonceWordG;
            aOrbiterC = (aWandererD + RotL64(aScatter, 39U)) + 16853106130200942302U;
            aOrbiterD = ((aWandererA + RotL64(aCross, 52U)) + 2611212958619673086U) + aOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 57U)) + 18039472325066855180U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 35U)) + 14495785571345122046U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 47U)) + 4556063793412832418U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 14896419970271244358U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 880028529183500036U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14228281807461251361U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2379557167489415783U) + aOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 11854373946064529806U;
            aOrbiterK = RotL64((aOrbiterK * 150755294320438887U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1487252775956449964U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 12777924204511625545U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 1366019527386994789U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15998631485222477969U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 8864212892296191613U;
            aOrbiterI = RotL64((aOrbiterI * 579242788050369815U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17069347835763226743U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7443008171694679791U;
            aOrbiterC = RotL64((aOrbiterC * 748894368884566607U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17334256152350782002U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 8986626119086556393U;
            aOrbiterD = RotL64((aOrbiterD * 2258172145924120235U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8528180968228358674U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12702290928064582589U;
            aOrbiterF = RotL64((aOrbiterF * 15673603224146737631U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7742438100860023610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3729687240959702198U;
            aOrbiterJ = RotL64((aOrbiterJ * 3756794766163746783U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 426129097367382096U) + aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16782175452274911213U;
            aOrbiterB = RotL64((aOrbiterB * 1041477289638333659U), 13U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 12U));
            aIngress = aIngress + RotL64(aOrbiterD, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterF, 24U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 24U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 57U)) + aNonceWordF);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 47U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + aWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterB, 43U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterB, 14U));
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterI, 53U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28625U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 32141U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24591U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32356U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCarry, 11U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererK + RotL64(aScatter, 19U)) + 4384716820085860551U;
            aOrbiterD = ((aWandererF + RotL64(aPrevious, 14U)) + RotL64(aCarry, 13U)) + 9715780315942116888U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 29U)) + 15963520052789178632U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 23U)) + 14346700690686392938U) + aNonceWordN;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 53U)) + 6005518012489966643U;
            aOrbiterH = (((aWandererE + RotL64(aCross, 42U)) + RotL64(aCarry, 27U)) + 2506732930310252119U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 5U)) + 16782163084851775826U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 823673076571076303U;
            aOrbiterA = (aWandererA + RotL64(aCross, 37U)) + 1634084509064077736U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1288134975466877686U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 2998220403162908444U) ^ aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4321412662318298283U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 220430672180734911U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10223923547068528867U;
            aOrbiterK = RotL64((aOrbiterK * 12577370238343872139U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 11696469696177647608U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6545430420379636963U;
            aOrbiterF = RotL64((aOrbiterF * 8387163146257553773U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 79691451831797107U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8971444023498649419U;
            aOrbiterI = RotL64((aOrbiterI * 7148919880477390009U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5624403902454498793U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9468064161002030997U;
            aOrbiterG = RotL64((aOrbiterG * 8243560528100864595U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 4619361544913629805U) + aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12682446273369750704U;
            aOrbiterH = RotL64((aOrbiterH * 10879074713156075641U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 8728730962617599223U) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9099675924074253030U;
            aOrbiterJ = RotL64((aOrbiterJ * 5525644236954497523U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3298303921318288541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5953276499411658358U;
            aOrbiterA = RotL64((aOrbiterA * 10565471305001292693U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6725769507592688539U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 1057277456510215817U;
            aOrbiterD = RotL64((aOrbiterD * 8269412198279297075U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 52U) + aOrbiterI) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + RotL64(aOrbiterA, 42U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterC, 37U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + aWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterK, 30U)) + aNonceWordJ) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 11U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterG, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 40U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordJ);
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

void TwistExpander_Archery_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCEDF8ECA5985C395ULL + 0xCC71F792F9A1E1F4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA861CD85960D757DULL + 0xEA98CE028458770AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x859252AC20B0FCDDULL + 0xE11569E88AB5BDEDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE8C008C67A962C39ULL + 0xBFA4892CFFFFD6D7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8A1230BC9DB3D223ULL + 0xD634CE9A3E36B31EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xECC8690B870D32ABULL + 0x9FD196491F7AD088ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9940B2E4E0BFDB67ULL + 0xE7BE23836991F1F7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD1B3E5AB18F69F9FULL + 0xF56F8FA51105C7D2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xEA439198817A0DE1ULL + 0xA820FD417366476BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAD7EDE0F10C381F1ULL + 0xBC8ECBD946E384DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE0CAD196C020B5F1ULL + 0xE7FED08B95680146ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x8C31721C9723FB33ULL + 0xB224F50DB8B4DBD0ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x91E90FECD7CFB033ULL + 0xD76B90BA760D799BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x93F8C2A26B0D90E9ULL + 0xCCB54A3CFA5EB4FFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC3AA6197CEE17B47ULL + 0xE6F8E2D7610F58BBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAF58FD76AA1A2D79ULL + 0xEB99137E73E97936ULL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3167U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneC[((aIndex + 2343U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3832U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 1179U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) + RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 37U) ^ RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 14499676118633326000U) + aNonceWordF;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 38U)) + RotL64(aCarry, 43U)) + 17191273593018552288U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aScatter, 47U)) + 4085176294948097737U;
            aOrbiterA = (((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 11112671474158908186U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aScatter, 5U)) + 8745787969012266485U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 18074049663777707948U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2543758649719164688U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7153845562786344373U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4659584749412700523U) + aNonceWordO;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 974639159259871273U;
            aOrbiterH = RotL64((aOrbiterH * 17918719351847605523U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 9211220687971081987U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8567024626862182714U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 7755874089832496393U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5803002132294840900U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11968489432878148467U;
            aOrbiterJ = RotL64((aOrbiterJ * 4501441062617123165U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9470807228394903442U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 1692347973120388469U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17433393164156231575U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 23U)) + aNonceWordL);
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 20U) + RotL64(aOrbiterH, 38U)) + aOrbiterI) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterH, 57U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9324U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((aIndex + 11333U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11235U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneB[((aIndex + 10195U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 58U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererH + RotL64(aScatter, 18U)) + RotL64(aCarry, 23U)) + 1557680213571812384U) + aNonceWordC;
            aOrbiterK = (((aWandererE + RotL64(aCross, 3U)) + 7387349725778021121U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 15379264067601586976U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 37U)) + 3730195724576043708U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 27U)) + 9637070085323827066U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 1170865717363676184U) + aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 2750833653175252030U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 1937822982381882775U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 15118992811225568305U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4974092922102988451U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10575977398702460975U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 10625719096296719514U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 855167122475471865U;
            aOrbiterI = RotL64((aOrbiterI * 7441090331293158773U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11322911068958340262U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4334591909425429835U;
            aOrbiterK = RotL64((aOrbiterK * 10059025861172038183U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14263701737208936392U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 678723206735649084U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10823239851733632227U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 18U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aCross, 52U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterI) + aNonceWordB);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 48U)) + aOrbiterH) + aNonceWordE);
            aWandererA = aWandererA + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 29U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 48U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19110U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21246U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23985U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18764U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCross, 4U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 23U)) + 18302975933754610273U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 13U)) + 16736972646771456082U) + aNonceWordM;
            aOrbiterD = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 47U)) + 17389406266488137442U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 46U)) + RotL64(aCarry, 3U)) + 5252511566486165539U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 57U)) + 5730715427422747640U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6412695646456045825U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 9539701605708994494U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6511935168278632407U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 18355107116412945722U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11735742491750132942U;
            aOrbiterJ = RotL64((aOrbiterJ * 18129835093627763685U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12363819388562658842U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 5861430292304371543U;
            aOrbiterF = RotL64((aOrbiterF * 12989055611235382695U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterK) + 15027487084595017708U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 7012850020745791926U) ^ aNonceWordA;
            aOrbiterC = RotL64((aOrbiterC * 15952928839355613939U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 11904871669287886120U) + aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 11199760114477343208U;
            aOrbiterK = RotL64((aOrbiterK * 7156374911847525867U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 6U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 53U)) + aOrbiterK) + aNonceWordN) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 38U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 56U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27159U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 25370U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28117U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((aIndex + 29882U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aPrevious, 29U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererB + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 9774364261626083532U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 54U)) + 18059001521926116420U) + aOrbiterAssignSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 10615626210406381148U) + aNonceWordF;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 10536484278007898620U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 5U)) + 13320663045139972700U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterG) + 17127001787268166583U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16742574590844166551U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17828964140627204983U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8347719720758228053U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 13502468705946051986U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 13822952083584784695U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3512687886188904904U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 495660316165795934U) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 6724596801190194913U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 5092722552034477356U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 15641128019608284015U;
            aOrbiterG = RotL64((aOrbiterG * 3621036395703527059U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 15421873776811085458U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17978775513204574125U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18359600395119440183U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterJ, 12U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 60U) + aOrbiterH) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterJ, 11U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 19U)) + aOrbiterH) + aNonceWordH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ aNonceWordH;
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

void TwistExpander_Archery_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xDB793221D245CA91ULL + 0x96E9E39E32A388B3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC0FF7C60B63EA427ULL + 0xB34E32F1B7ACBD8CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xFA62369524396307ULL + 0xCC7335F8A5FCB20EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB64E326E662C0157ULL + 0xEEFC0CC4DC6CE41DULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x8309BC30191F4001ULL + 0x8470B71BCBC24E64ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9CD1A10DB29423A1ULL + 0xCEB951FE16E7C969ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA3731C76821FBA1BULL + 0xF5BB0A810E40967EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x9CD99827E47B8519ULL + 0xE0E2704171655E6CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB0670C3FBB4F8097ULL + 0xCDF25A48BB729565ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA597C9A5A5840193ULL + 0xA02490F1873BE01BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB99C3D92550D440DULL + 0xB21AE96F1C92087AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFE915BE23C5289EDULL + 0xFE5F64F5C3D8B007ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x8C24CE9404169BF5ULL + 0xAED7A5A2044C8E28ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC4E87582FC395845ULL + 0xDFEE13D70DEF7192ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC35C2882CC09BD01ULL + 0xE7631ABB3AE8C5D3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC8774366DD76A657ULL + 0xD365110024C5DD2AULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6146U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 4435U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3277U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6260U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 3U)) + 14157904117287696136U) + aNonceWordE;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 7369512677371640676U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 29U)) + 8411250745902073798U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 35U)) + 5002041814539710275U) + aOrbiterAssignSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aPrevious, 5U)) + 9538041410816283124U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 51U)) + 5210700103927513061U) + aNonceWordG;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 27U)) + 7600709399101287982U) + aOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 2366369466696580499U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5544575244203019109U;
            aOrbiterH = RotL64((aOrbiterH * 16231219246786333057U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8710073749110329779U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15998211310115361630U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15275657696897688955U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15354357553877376422U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 10657523549259276169U;
            aOrbiterC = RotL64((aOrbiterC * 13695239532898311073U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10405750198355464768U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterH) ^ 3465819693133515142U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 14678343718277562799U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16724189641701408630U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3484340153620198872U;
            aOrbiterG = RotL64((aOrbiterG * 17247547677520703125U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 7420442404884871126U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11138445997256757636U;
            aOrbiterB = RotL64((aOrbiterB * 11167543379937571127U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1428191560884663125U) + aOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 16950093140800653985U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 4423012306984814805U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 27U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 54U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 47U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + aWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterK, 11U)) + aOrbiterG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordN);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterK, 26U)) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 12U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 40U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 12243U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 15970U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10840U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 14750U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 47U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 9774364261626083532U) + aNonceWordA;
            aOrbiterF = ((aWandererG + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 18059001521926116420U;
            aOrbiterD = (aWandererC + RotL64(aIngress, 11U)) + 10615626210406381148U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 58U)) + 10536484278007898620U) + aOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 19U)) + 13320663045139972700U) + aNonceWordB;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 37U)) + 17127001787268166583U;
            aOrbiterB = ((((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 35U)) + 16742574590844166551U) + aOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 8347719720758228053U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 13502468705946051986U) ^ aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 13822952083584784695U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3512687886188904904U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 495660316165795934U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6724596801190194913U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 5092722552034477356U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 15641128019608284015U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3621036395703527059U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15421873776811085458U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17978775513204574125U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 18359600395119440183U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16617179197537669849U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1931805387534012528U;
            aOrbiterA = RotL64((aOrbiterA * 3400139345857733775U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 9544923119559308431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12930999400470173353U;
            aOrbiterH = RotL64((aOrbiterH * 16791006919271490005U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13673733276226249890U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2032263473309124738U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 3088728329261360607U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 20U)) + aOrbiterH) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 47U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 3U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterA, 13U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 39U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterK, 27U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19836U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 17140U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18042U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 17591U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aPrevious, 20U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 11U)) + 9107326720193244489U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aCross, 19U)) + 10868585484401664145U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 13637736741437846622U) + aNonceWordP;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 44U)) + 6130725216183918844U) + aNonceWordN;
            aOrbiterA = (((aWandererH + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 2063834478521338187U) + aOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 8564870627911949158U;
            aOrbiterJ = (aWandererC + RotL64(aIngress, 53U)) + 6524015751064086390U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 9874937766875388236U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14723718409522680894U;
            aOrbiterK = RotL64((aOrbiterK * 17379140128833323431U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13767059954741528279U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6387608251033722169U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6601902195707980693U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5391425980008431000U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 11524218415655093779U;
            aOrbiterH = RotL64((aOrbiterH * 12508457981779189389U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 155510463350385905U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 10554591788433641311U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 5412084824127934293U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 8662160162966241542U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5092555636369853727U;
            aOrbiterA = RotL64((aOrbiterA * 433807340167635499U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7163345798448796101U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 695089002178413267U;
            aOrbiterE = RotL64((aOrbiterE * 17302689458565434475U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 5409173939213468972U) + aNonceWordA;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15349690077393827541U;
            aOrbiterJ = RotL64((aOrbiterJ * 10984681254001609841U), 35U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 41U)) + aOrbiterA) + aNonceWordB);
            aWandererA = aWandererA + ((RotL64(aCross, 54U) + aOrbiterA) + RotL64(aOrbiterH, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + aOrbiterD) + RotL64(aOrbiterE, 19U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 47U) + RotL64(aOrbiterJ, 10U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterD, 3U)) + aNonceWordD) + aWandererUpdateSaltE[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterK, 51U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordP;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 27103U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 29593U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29646U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((aIndex + 24609U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aCross, 60U)) + 16183871922837164759U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 7002058258090219055U) + aNonceWordE;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 11U)) + RotL64(aCarry, 11U)) + 5650868611888303705U) + aNonceWordA;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 41U)) + 11899839660943876690U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 15349649504488111111U) + aOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aIngress, 3U)) + 14060149569086744970U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 27U)) + 12920917574225030112U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2831994965175330135U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 18312543585028439192U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 11618182708195744321U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 11657562205118394239U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 10850792819281246052U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10663100544207879337U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 17810371216216125323U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7963413941144223128U;
            aOrbiterG = RotL64((aOrbiterG * 534217972450595401U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 5498715358793875584U) + aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9256727548911651373U;
            aOrbiterD = RotL64((aOrbiterD * 10498848323914000989U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 17246360111302191699U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18309978718113983369U;
            aOrbiterE = RotL64((aOrbiterE * 18267472694666221077U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 3100998994319502921U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 8129301860291235970U;
            aOrbiterC = RotL64((aOrbiterC * 17847033539279176187U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1889641029473279114U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16538494307002917945U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8081488217920885783U), 21U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (RotL64(aOrbiterG, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + aNonceWordJ) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 47U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 12U) + aOrbiterK) + RotL64(aOrbiterG, 21U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 10U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 20U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Archery_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAEC7AE518E2A13F5ULL + 0xF4E189B0DE664008ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xB843E85505DAE3FBULL + 0xD9D19B6BD86C9915ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC25BD7CA5BA3CAFBULL + 0xC67F19F074DEC12EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9F5B06CE5338D25DULL + 0xAE2605853187D46FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFCA61A90DEFC0BDFULL + 0xA01B33260FB77BDCULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xECE6CABA9283E1A7ULL + 0x87156B044788325EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA389DD0C81F1A8DFULL + 0xE134019A79BEAA0AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xBD2D387642E42CE1ULL + 0xEFE269C458041F37ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA6DC80E66666DAF3ULL + 0xC510AB454514F577ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE39F3B6FDF80A26BULL + 0xA64FBF1F90583407ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x98AA9A2492B7F89FULL + 0xF63EA8D7D99D12CEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xF7AA8CDCBA491C49ULL + 0xD485ED25D8779CDCULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE6BE51F8B9741F33ULL + 0x98976C3338389A20ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8029B02963E25CF3ULL + 0xD97C9BAC05159722ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xEFCA55155D510D91ULL + 0xF02A0321BE704202ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xD657FA6A896CF195ULL + 0x84C843A7DB75F250ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 283U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 1440U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4731U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 3645U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 22U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 7948891781097675369U;
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 13928362874228230226U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 19U)) + 10776180542602258926U) + aOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aIngress, 60U)) + RotL64(aCarry, 39U)) + 5735115172149470447U) + aNonceWordC;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 11U)) + 5353591822981766987U) + aNonceWordG;
            aOrbiterK = (aWandererK + RotL64(aScatter, 5U)) + 562301708107268570U;
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 35U)) + 10467810247578364868U) + aNonceWordL;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14541630141152308564U) + aNonceWordK;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2350076897065139429U) ^ aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12222554362482034393U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17519109078651162228U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6061035173339902910U;
            aOrbiterG = RotL64((aOrbiterG * 10021905773432907835U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15654836633731000065U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13723521735153718904U;
            aOrbiterK = RotL64((aOrbiterK * 14459516479283070563U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 2849680038315532197U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 17336102435576647923U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 7671010488872356142U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11485114338165600777U;
            aOrbiterE = RotL64((aOrbiterE * 4162584865462407791U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8759060657343458985U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 11009137869375286581U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 8741417343929809115U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15792999392743144135U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6180808423175992479U;
            aOrbiterH = RotL64((aOrbiterH * 13681230339693676907U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 41U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + aOrbiterA) + RotL64(aOrbiterE, 10U)) + aNonceWordF);
            aWandererI = aWandererI + ((((RotL64(aIngress, 12U) + aOrbiterK) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 21U)) + aNonceWordI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterK, 37U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterE) + RotL64(aCarry, 57U)) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 57U)) + aOrbiterK) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 8329U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14442U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 15676U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 8944U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 35U)) ^ (RotL64(aCross, 11U) ^ RotL64(aPrevious, 56U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererI + RotL64(aIngress, 44U)) + 14214886793361825363U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aCross, 11U)) + 17267959031078766320U) + aOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 16436067429484887644U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 9885951769332633820U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 5U)) + 12971711341813893304U) + aNonceWordO;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 199970353398450154U;
            aOrbiterH = (aWandererD + RotL64(aCross, 37U)) + 1237341696444162094U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 7991128854417613360U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14809029847149045833U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 5940857360838299105U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 2559509556915775947U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14336829730147834160U;
            aOrbiterE = RotL64((aOrbiterE * 15103242520064900873U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8853631886733610440U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 13346159398673246914U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13660497151446983393U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12121095718571872976U) + aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterC) ^ 16239781125815589804U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 5157009090454962231U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9051377033794324106U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 13805815136723461780U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 571129481747181357U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14849157800322754413U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 18116651528452542634U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3638480428016835537U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 4105057226952948599U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 5911714320560994391U;
            aOrbiterH = RotL64((aOrbiterH * 1796514171654961389U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 5U);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 19U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aNonceWordM);
            aWandererK = aWandererK + ((RotL64(aIngress, 60U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterD, 6U)) + aNonceWordB);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 53U)) + aNonceWordI) + aWandererUpdateSaltC[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23292U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17511U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18448U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 22980U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 47U) ^ RotL64(aCarry, 60U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 6916817163240024692U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 35U)) + 14554930751292077817U) + aOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 1098305064484336101U) + aNonceWordH;
            aOrbiterB = (aWandererA + RotL64(aScatter, 60U)) + 12192821172420471527U;
            aOrbiterG = (aWandererI + RotL64(aCross, 21U)) + 2435134991707318845U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 47U)) + 1896745368738512624U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aPrevious, 3U)) + 1114996424222923873U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 9839135798371512656U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8037967239603177043U;
            aOrbiterI = RotL64((aOrbiterI * 7848951103759663025U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 15185468738487237432U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4912098316394854543U;
            aOrbiterJ = RotL64((aOrbiterJ * 3072785550384399929U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 13142688607850380888U) + aNonceWordF;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4507379759608945839U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2989332387754215967U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 7299006009652289342U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5390655277207053627U;
            aOrbiterB = RotL64((aOrbiterB * 10973744708856143715U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6744737023577785725U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 15539737698867067285U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 4686092035261336911U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13329866734681377952U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13284937458969166257U;
            aOrbiterH = RotL64((aOrbiterH * 3965985432462699445U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8695002088915702168U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3858059421620839286U) ^ aNonceWordK;
            aOrbiterF = RotL64((aOrbiterF * 9559783727301092937U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 21U);
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 10U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 30U) + RotL64(aOrbiterB, 37U)) + aOrbiterH) + aNonceWordJ);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 21U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterH) + aNonceWordP);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + aWandererUpdateSaltE[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28728U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29278U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27675U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 29897U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 10U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 4773124477323378268U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 13U)) + 16848723289435796005U) + aNonceWordJ;
            aOrbiterE = (((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 51U)) + 13846642134917107058U) + aNonceWordM;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 19U)) + 6472057872482789939U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 5U)) + 2747019500690707226U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 41U)) + 9003965289739733880U) + aOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 3013390651936257377U) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 3331004709895625067U) + aOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15355010435553517129U;
            aOrbiterE = RotL64((aOrbiterE * 8322759117004876831U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7709870658004280052U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13568728443963926564U;
            aOrbiterC = RotL64((aOrbiterC * 6736090830113688981U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 12409548853419307131U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 969183352023661537U;
            aOrbiterA = RotL64((aOrbiterA * 5549220554838837145U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15370309834426476775U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3896803894396631184U) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 11018830202891911603U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10848873633291935766U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12885336509190543440U;
            aOrbiterK = RotL64((aOrbiterK * 1487357252619221365U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8252290890093788010U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9201553615601641350U;
            aOrbiterJ = RotL64((aOrbiterJ * 420321130559162915U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14014209645503188472U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4015071464301844550U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17444195018239904971U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterJ, 50U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 51U)) + aOrbiterC) + aNonceWordB);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererF = aWandererF + ((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterC, 34U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + aWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Archery_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE5F3A54EE8AF381DULL + 0xC2C97CB06CDA1282ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFA36267C657B68A5ULL + 0xDEA7F386B2759D71ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD32251E3769C2307ULL + 0xB38CD9C0C7BDA4BBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA8C6F6A0BE24EB51ULL + 0xEAA082EB63E7202AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xFB8E52FAA79982A3ULL + 0x817F93741A993E1EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD9BBE8F7B00379E9ULL + 0x9920E5E2AD03303DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB54DF0E6BB9E702DULL + 0xB1A55B0F0B2B313CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEB74B8F4B25F9DFFULL + 0xE444E033CE6DE883ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBF9F7F32B6E8E425ULL + 0x9B0A8EEAF90BADACULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBAB6D884BC2E98DFULL + 0xA57D374E534AC6AEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD8046B3F60987479ULL + 0xB0363F2D3411FBA9ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9D6C0E755D31F8A5ULL + 0x978317685B696E63ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xD2ECA5E1D9A44FD9ULL + 0x95B62A72D7D247F0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE1F6FC3503CBB3B3ULL + 0xE236E68B369DFB1FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBCE995AF35190F8BULL + 0x8D26F28DF22B0601ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA9EA0690C8DC9D55ULL + 0xB4A5D5A031838548ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2509U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5497U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2863U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneA[((aIndex + 7924U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 28U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 57U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererH + RotL64(aIngress, 57U)) + 10336802574069791273U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 11U)) + 169025388197058936U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 43U)) + 6541354188379168846U) + aNonceWordB;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 27U)) + 16223920526599306104U) + aNonceWordM;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 53U)) + 12756613707692514808U;
            aOrbiterA = ((((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 57U)) + 5082475548176484035U) + aOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (aWandererC + RotL64(aCross, 21U)) + 4907435526952698526U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 19U)) + 14236627073831834337U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 41U)) + 11502511046130497584U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 30U)) + 3679044835550219497U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aPrevious, 5U)) + 11254838916686736746U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 10582608424233200966U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 10449735026385340313U;
            aOrbiterJ = RotL64((aOrbiterJ * 7363770199734997411U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 4628253464169957835U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17664454668473204465U;
            aOrbiterA = RotL64((aOrbiterA * 4234720298731378527U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3798386391743884889U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1379331161819246587U;
            aOrbiterK = RotL64((aOrbiterK * 13086160171095077295U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9816600392407327227U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16781971616348376878U;
            aOrbiterB = RotL64((aOrbiterB * 12503867584828289879U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 4807797577690520554U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2492057261148595922U;
            aOrbiterH = RotL64((aOrbiterH * 9453302540675483005U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7909676419643119585U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 256053568910383007U;
            aOrbiterD = RotL64((aOrbiterD * 11965085163352053161U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16179914439220412472U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3968867762761955845U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7473632378251893139U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 7474832923901283742U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4736994731050735779U;
            aOrbiterG = RotL64((aOrbiterG * 9839654409121414047U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 596484364660389193U) + aOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13822222274464306169U;
            aOrbiterI = RotL64((aOrbiterI * 1723502278319885511U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16307920280681985443U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3505106171801702915U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 8479675421552861243U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 4987142580981135150U) + aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10336802574069791273U;
            aOrbiterC = RotL64((aOrbiterC * 2670706512498539705U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 54U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 11U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterC, 34U)) + aOrbiterK) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterA, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterB, 39U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterB, 47U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 23U) + aOrbiterI) + RotL64(aOrbiterC, 6U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 10U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 41U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9285U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8384U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15778U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 10560U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 53U)) + (RotL64(aCross, 4U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererB + RotL64(aPrevious, 22U)) + 17470880031634374199U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 27U)) + 757565846006937746U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 11U)) + 9419282475801345674U;
            aOrbiterK = (((aWandererI + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 2014248014107898196U) + aOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 15113928519446490441U;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 56U)) + 7346126964886259935U;
            aOrbiterG = (aWandererA + RotL64(aCross, 53U)) + 5594123113093162359U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 5659237263369402005U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 19U)) + 11565709683423969703U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 37U)) + 16782863743534856287U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aIngress, 51U)) + 13499100900072115907U) + aNonceWordI;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11414447651044205242U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 7545993795121430538U;
            aOrbiterF = RotL64((aOrbiterF * 10758488381206257261U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 11778229237616454988U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2544793391976514665U;
            aOrbiterE = RotL64((aOrbiterE * 4021060413798523299U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 9972156716619459164U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17651030383827445664U;
            aOrbiterB = RotL64((aOrbiterB * 6742914240706775487U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17439147296849134543U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10021926927948343656U;
            aOrbiterG = RotL64((aOrbiterG * 18139540407315440909U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 9309867875882669289U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14951424455944346337U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10569523948169951309U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 2166343974068770659U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 11386993629011562026U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 3091639433512536097U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 5747849744680120960U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 4019290369160113026U;
            aOrbiterK = RotL64((aOrbiterK * 5567515306039646735U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3820540009554769592U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 8210747198363020939U;
            aOrbiterJ = RotL64((aOrbiterJ * 16215133106542452509U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 3006494852696036003U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2736305345451919450U;
            aOrbiterH = RotL64((aOrbiterH * 11993452696344358247U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6148431711118275178U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6986633012691940738U;
            aOrbiterA = RotL64((aOrbiterA * 15672039482523804893U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7837859154831245165U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 17470880031634374199U;
            aOrbiterI = RotL64((aOrbiterI * 2153299273348512243U), 27U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 41U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 29U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 46U) + aOrbiterC) + RotL64(aOrbiterD, 14U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterF, 47U));
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterB, 23U)) + aNonceWordK);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterB, 19U));
            aWandererH = aWandererH + ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterF, 52U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 11U)) + aWandererUpdateSaltE[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aNonceWordC);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23908U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20853U)) & S_BLOCK1], 28U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18476U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 21512U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 27U) ^ RotL64(aCross, 43U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 57U)) + 6068543441070417854U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 21U)) + 2995980468193441856U;
            aOrbiterC = (aWandererK + RotL64(aCross, 46U)) + 18020277482171594003U;
            aOrbiterH = ((aWandererI + RotL64(aScatter, 27U)) + 4293807434721230702U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 35U)) + 7980599111583893156U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 53U)) + 8593141111851052016U) + aOrbiterAssignSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 13U)) + 5903487523900084325U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 37U)) + 15112035513447930209U) + aNonceWordM;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 41U)) + 9854037263057006439U;
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 37U)) + 16759760289688823193U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 18U)) + RotL64(aCarry, 51U)) + 12622628933030601390U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1264668857268123425U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16302812053619101593U;
            aOrbiterC = RotL64((aOrbiterC * 18291400055836111547U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16087995784896123610U) + aOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 7970269262800468363U) ^ aOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14924752223305807461U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5331477046030959632U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 16534913204255550893U;
            aOrbiterB = RotL64((aOrbiterB * 1013433634373673565U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11042821902537871209U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8069677512345031660U;
            aOrbiterE = RotL64((aOrbiterE * 13622218526054132397U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5737130058129936372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1076627182956662997U;
            aOrbiterF = RotL64((aOrbiterF * 14342191224014199929U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13911061091801078190U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15397603151098990373U;
            aOrbiterG = RotL64((aOrbiterG * 1802890451633592245U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 15137326716738637972U) + aNonceWordB;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11248737008959896786U;
            aOrbiterJ = RotL64((aOrbiterJ * 90789374131547005U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1847847987633923657U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10560748778679145431U;
            aOrbiterH = RotL64((aOrbiterH * 2919333327817231099U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2703726238610290251U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 12950671360471467310U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7490327691501537047U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10331504168520449467U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1541527607705280906U;
            aOrbiterA = RotL64((aOrbiterA * 14197400812600186171U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9135056476214341809U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 6068543441070417854U;
            aOrbiterD = RotL64((aOrbiterD * 14102524444094948875U), 41U);
            //
            aIngress = RotL64(aOrbiterA, 43U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 37U));
            aIngress = aIngress + (RotL64(aOrbiterF, 24U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 14U)) + aOrbiterK);
            aWandererI = aWandererI ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 39U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterI, 27U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 21U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterA, 5U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 12U) + aOrbiterH) + RotL64(aOrbiterD, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterK, 11U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 54U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 23U)) + aOrbiterC) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 52U));
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 24757U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((aIndex + 32148U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27730U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26772U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 41U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererC + RotL64(aPrevious, 50U)) + 13481227414590594621U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 11U)) + 17425964381118918026U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 4792004356135956581U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + 11926849936000639098U) + aNonceWordI;
            aOrbiterA = (((aWandererD + RotL64(aIngress, 5U)) + 990697329347742142U) + aOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 53U)) + 9307721505373076588U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 26U)) + 17605732738841908719U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 13U)) + 13110764518634187439U) + aNonceWordE;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 29U)) + 17970109897810645911U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 37U)) + 10273133817644703654U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 19U)) + 11239046688920468137U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8355821483275763145U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15522151127786049345U;
            aOrbiterI = RotL64((aOrbiterI * 4844278537850520413U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5381663179722418112U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9551368011768104906U;
            aOrbiterA = RotL64((aOrbiterA * 14202470972121732997U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 16264476585232221270U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 7721417776432288282U;
            aOrbiterF = RotL64((aOrbiterF * 10267770327791051869U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 339418090653475277U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3247926250495935511U;
            aOrbiterC = RotL64((aOrbiterC * 16824669543765729097U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3390560045236418590U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3894024951542543635U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10599637790900418767U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3878539166189668154U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 5617705593218220843U) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 82771190372750823U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12320861089148474544U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 14943790251625519550U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 13758322022902008313U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 18119213517612562775U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1413193144229486646U;
            aOrbiterJ = RotL64((aOrbiterJ * 14562375280658115687U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14810150213456844196U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 8468712395797520201U;
            aOrbiterG = RotL64((aOrbiterG * 8167911669632436949U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 13501570100536254566U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 15409772061478100850U;
            aOrbiterK = RotL64((aOrbiterK * 955182899606655851U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 8621805947309982779U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 13481227414590594621U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9591362493722704105U), 13U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 40U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 14U) + aOrbiterE) + RotL64(aOrbiterJ, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 58U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterK, 47U)) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 43U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 6U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            aWandererK = aWandererK + ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 30U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterF, 13U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterC, 23U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordH);
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

void TwistExpander_Archery_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF6F21A27EA8354AFULL + 0xC2C9F00AFC38B98CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x87E13DE698B75C9DULL + 0xF8EA2FB4CAE82CC4ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x895FE4244E69F6EDULL + 0xF188BAC8E5EEF300ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xEB06995FA0DDECDFULL + 0xABBCA2C923B24AE3ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE5FF86A6A5AB2A95ULL + 0xB6FFAB4B467B856FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xAF21F13F33A0282FULL + 0x8CD8B678FE15E10EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xBFC281A536AE4E7BULL + 0xCDDCE4B6DF293459ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x90CA44CD3CB6F70BULL + 0xD1B5464F08877F92ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC9BC5F86CBAF803DULL + 0xF544C6E67266C68FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA1DA2947AE2CEDD1ULL + 0xB7A4CAE4D2A1E475ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x98EDA39B58D25DBFULL + 0x8E4064E9C323861AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xE8D404942E07E577ULL + 0x89163ABBC7FB4555ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xDAE94969EEF4307FULL + 0xCCCEFCC14BF8A800ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x87E064950D7643C1ULL + 0xF77E32B3DDDAF898ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD1782B25EF992E53ULL + 0x8E1CAC9CB919BA0BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xEFD94BE9469D9BFFULL + 0xCEACCB11839AC974ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1966U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3460U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3226U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((aIndex + 681U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 54U)) ^ (RotL64(aIngress, 41U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererG + RotL64(aScatter, 57U)) + 15316464782468770057U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 13U)) + 6642872057476351588U;
            aOrbiterH = (aWandererF + RotL64(aCross, 41U)) + 660732654689529192U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 4U)) + RotL64(aCarry, 43U)) + 7235418086884000655U;
            aOrbiterF = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 29U)) + 14784518476694580493U) + aOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 13U)) + 12222433977933449375U;
            aOrbiterE = (aWandererD + RotL64(aPrevious, 47U)) + 8573001207708329927U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 52U)) + 16035256260815013172U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 29U)) + 15767726974121910203U) + aNonceWordF;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 17712217935322939971U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 13488963456923357159U;
            aOrbiterH = RotL64((aOrbiterH * 16785285630840310405U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10222949131965611079U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 1495561412321657209U;
            aOrbiterG = RotL64((aOrbiterG * 9706305581868526265U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16156530750584361434U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7773792489045606309U) ^ aOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10730624207715601393U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 11544578291333360613U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 3665587867634242865U;
            aOrbiterB = RotL64((aOrbiterB * 4840528190844842595U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15248434984650998090U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15487979645426567581U;
            aOrbiterI = RotL64((aOrbiterI * 10868107809356766183U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6972347795052712690U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16074994810010431338U;
            aOrbiterA = RotL64((aOrbiterA * 1262655238856775853U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16851139687900415292U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 14630026837021552812U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9577900853521254603U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14236330619137368169U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17778707026111136216U) ^ aOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16239561893843454747U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9390961969105999083U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1174881758316573228U;
            aOrbiterF = RotL64((aOrbiterF * 6602061268277529311U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 54U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterA, 27U)) + aOrbiterB) + aNonceWordH) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 24U) + aOrbiterH) + RotL64(aOrbiterB, 4U)) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 57U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 23U)) + aOrbiterE) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterG) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 6U) + RotL64(aOrbiterE, 46U)) + aOrbiterH) + aWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordN);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9529U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((aIndex + 5839U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6606U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 8263U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 27U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 13915875634607599122U) + aOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererB + RotL64(aIngress, 21U)) + 1695770381382411673U) + aOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aPrevious, 60U)) + 3709105579778295511U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 3U)) + 7673376335333251804U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 11U)) + 8814147709738503518U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 13451412605350381172U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 41U)) + 6447870234069609538U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 3U)) + 13419487997946496825U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 36U)) + 5478309847615220345U) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3635184969215610049U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12527903812035294828U;
            aOrbiterH = RotL64((aOrbiterH * 12540800512035534967U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1684685110885338814U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12860354576326835090U;
            aOrbiterF = RotL64((aOrbiterF * 12743745087733307255U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9081823570147481835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 14369321778210049109U;
            aOrbiterI = RotL64((aOrbiterI * 17865953349448767035U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 11518132079084873250U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11893535026126957389U) ^ aOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15751374986135615095U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7084079180579206226U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 2999676609847603277U;
            aOrbiterB = RotL64((aOrbiterB * 14602698397511266403U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17683445810614029153U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11576460512964896969U) ^ aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5243651036457051155U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13429800604736567949U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 14661785761747367546U;
            aOrbiterD = RotL64((aOrbiterD * 4765843989277333421U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12837164345582888950U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6222666313184669392U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17402483466567712319U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5358647039491079457U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12459911673401497180U;
            aOrbiterA = RotL64((aOrbiterA * 13605465035256188065U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 22U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 30U)) + aOrbiterA);
            aWandererH = aWandererH + (((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 3U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterD, 37U)) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 19U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterD, 24U)) + aNonceWordG) + aWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14259U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 15410U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 12834U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 12657U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 42U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererF + RotL64(aScatter, 23U)) + 1457104756581596530U) + aNonceWordC;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 36U)) + 6127240317844622874U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aWandererD + RotL64(aCross, 27U)) + 16492290056044189421U;
            aOrbiterJ = ((aWandererH + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 10963676850938416468U;
            aOrbiterG = ((((aWandererJ + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 4872917367399752405U) + aOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = ((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 43U)) + 15218882377875616148U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 43U)) + 5934166612122118251U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 3U)) + 14215280930872003003U;
            aOrbiterK = (aWandererG + RotL64(aScatter, 47U)) + 11428034799044600979U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5453003654321728726U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14273775120265649389U;
            aOrbiterA = RotL64((aOrbiterA * 5139018128323795309U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 328723770018440271U) + aNonceWordP;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13032190719588211088U) ^ aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13363368478932798315U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2386881543033598494U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 1649501123340887116U;
            aOrbiterJ = RotL64((aOrbiterJ * 11148976582360499033U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16462401546754210583U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1510579201823042227U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 16287912400104043275U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6889066000014251983U) + aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11324594596597724357U;
            aOrbiterG = RotL64((aOrbiterG * 15344987814648586023U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12237796033168436537U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 17306069670330000343U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 3167451351403385259U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14197284538008811658U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4754134852883071927U;
            aOrbiterE = RotL64((aOrbiterE * 3484427259538998699U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 17201907781639753736U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8318419319239859855U;
            aOrbiterI = RotL64((aOrbiterI * 10320390501983802091U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16012488623961565780U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15583721012865354925U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10656414363201743961U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 28U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 39U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterF, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 51U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 23U)) + aOrbiterF) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterA, 3U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aIngress, 26U) + aOrbiterA) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 46U)) + aOrbiterG);
            aWandererF = aWandererF + (((((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterD, 19U)) + RotL64(aCarry, 37U)) + aNonceWordG) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 57U)) + aOrbiterI);
            aWandererE = aWandererE + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterJ, 34U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + RotL64(aWandererH, 30U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17952U)) & S_BLOCK1], 42U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18357U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19079U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18886U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 23U) ^ RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 5295352595333316211U;
            aOrbiterG = ((aWandererB + RotL64(aIngress, 60U)) + 2341795367042042605U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 10122175780504033663U;
            aOrbiterK = (aWandererF + RotL64(aCross, 47U)) + 10084612804696198554U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 51U)) + 16470424309851045971U;
            aOrbiterB = (aWandererK + RotL64(aPrevious, 5U)) + 656016130975227994U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 56U)) + 15313268829659834317U) + aNonceWordP;
            aOrbiterD = (((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 29U)) + 3795220914993923394U) + aOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aScatter, 35U)) + 14044442220988813825U) + aNonceWordH;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3804224626734584802U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7980006306010255693U;
            aOrbiterA = RotL64((aOrbiterA * 13958505239726088561U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13746830564584711549U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11852212099729274845U;
            aOrbiterE = RotL64((aOrbiterE * 2164880979318247855U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9083223471018084847U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 13706723820703853346U;
            aOrbiterC = RotL64((aOrbiterC * 11361854103656219887U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1713819986642275223U) + aNonceWordF;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1382000168233902914U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 3894160765130198157U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 4540474625764565485U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1756168174375757220U;
            aOrbiterK = RotL64((aOrbiterK * 12739160208010092017U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1409297070183609309U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6082750101445444357U;
            aOrbiterB = RotL64((aOrbiterB * 17438740230251860935U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1113239890859479202U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10932192439503964363U) ^ aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 5915660289913324281U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3732595033748508428U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 5117760372351117286U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2671510075176315761U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 7399968659654088641U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14835608167871904147U;
            aOrbiterG = RotL64((aOrbiterG * 8312521710415756159U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 18U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterK, 57U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + RotL64(aOrbiterD, 53U)) + aOrbiterB) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterC) + aNonceWordO);
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 18U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 41U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 47U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterG, 36U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 6U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24831U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((aIndex + 25736U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26742U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 23305U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 38U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCross, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererE + RotL64(aIngress, 14U)) + 15910560457440369082U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 17953072986407436888U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 57U)) + 15446940721193538669U;
            aOrbiterG = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 3020785262774422009U) + aNonceWordA;
            aOrbiterC = (aWandererA + RotL64(aIngress, 41U)) + 7001288645424994404U;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 47U)) + 13385250665458462689U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aScatter, 18U)) + 4841895644623005949U;
            aOrbiterB = (aWandererK + RotL64(aCross, 29U)) + 13053476783239482065U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 35U)) + RotL64(aCarry, 43U)) + 641996979335975244U) + aOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16211238020928688299U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 12715448751323279480U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2116880429675303291U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 17784406727699995290U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13940754474750138041U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 9035070625716345139U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6085848172494001945U;
            aOrbiterB = RotL64((aOrbiterB * 10405728912339646693U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 1177103851507561053U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2281901691017816407U;
            aOrbiterI = RotL64((aOrbiterI * 3142197009403602497U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9040984343694325070U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13334258224023902365U;
            aOrbiterD = RotL64((aOrbiterD * 4782523727707164869U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 1079824790138592518U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 14024082692012948652U) ^ aNonceWordN;
            aOrbiterG = RotL64((aOrbiterG * 3219489374333737903U), 47U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterD) + 2966776524421278970U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 5510281854029308547U;
            aOrbiterH = RotL64((aOrbiterH * 9275402927591867297U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7126632329316720048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1476827035602733472U;
            aOrbiterJ = RotL64((aOrbiterJ * 2217671289726794033U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6470212302133184965U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 4172257438373147415U;
            aOrbiterC = RotL64((aOrbiterC * 4449314239630366533U), 23U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 48U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordB) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 47U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterB, 53U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 6U) + aOrbiterA) + RotL64(aOrbiterD, 18U)) + aNonceWordJ);
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterD, 43U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 37U)) + aOrbiterE) + RotL64(aCarry, 41U)) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterC, 5U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 58U) + aOrbiterG) + RotL64(aOrbiterH, 12U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30432U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 31764U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27835U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29345U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 42U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((((aWandererB + RotL64(aIngress, 58U)) + RotL64(aCarry, 37U)) + 12535417189990029950U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aWandererA + RotL64(aScatter, 11U)) + 6204401443676390273U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 39U)) + RotL64(aCarry, 3U)) + 869613505613154672U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 15053590879563855802U) + aNonceWordP;
            aOrbiterB = (aWandererI + RotL64(aScatter, 43U)) + 13338989605204591428U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 18U)) + 18306470022403825392U) + aNonceWordC;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 23U)) + 1150696349434090218U;
            aOrbiterD = (aWandererH + RotL64(aCross, 3U)) + 13549541786420596437U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 47U)) + 14302878430259588461U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 4660437084477165225U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1653628537860912069U;
            aOrbiterK = RotL64((aOrbiterK * 2624835201155303123U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 5594199757006711631U) + aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 11008472193138708891U;
            aOrbiterB = RotL64((aOrbiterB * 13645764762027798301U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3668516817279364310U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 128159531749679984U;
            aOrbiterG = RotL64((aOrbiterG * 4523246859249826987U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6378674346113979108U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11438762460659123362U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 2733309638158283953U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 10624263004446482910U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterK) ^ 12546839706919241411U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 11468326687628079347U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8466639576503293921U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5828694979857951504U;
            aOrbiterA = RotL64((aOrbiterA * 7835487310289634515U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16496305151014092976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 589464613876410567U;
            aOrbiterF = RotL64((aOrbiterF * 13190816610718051897U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 4168532743415647825U) + aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 15944887793736489375U;
            aOrbiterE = RotL64((aOrbiterE * 17273403561158196717U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11642456814106259483U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1609897693632334867U;
            aOrbiterI = RotL64((aOrbiterI * 12912773555616819941U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 38U) + RotL64(aOrbiterE, 12U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 23U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + aOrbiterA) + RotL64(aOrbiterG, 35U));
            aWandererF = aWandererF + ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + RotL64(aCarry, 41U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 60U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + aNonceWordE) + aWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 30U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordA);
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

void TwistExpander_Archery_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x94BD5F89D77FBC85ULL + 0xE1AF1E6D8428496AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCB74A5909C9CAD59ULL + 0x916824058DE40EBBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF24CD366FFC46E77ULL + 0xB49A1F252C62BB2EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB76DF099C1C16FF7ULL + 0xCFCFB86CFB82697EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA62D6647A41492E3ULL + 0xBD2465D0C6DDA28AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9882EED4D7981EDFULL + 0x8B459A7B06D4DFADULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xBA537CB33C9FDB7DULL + 0xF398EADB2EF4C003ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF5ABFC50BF882E13ULL + 0xD6390BE7C0DD7276ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x83D0505044F6379BULL + 0xD486B2F83A456D7FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC73D89ADC7FB0297ULL + 0x8F23535D0990B7DEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x9A42C071618A5013ULL + 0xBE389A25BBE04A5FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x84788276AC2791BDULL + 0xE6F71AF9DF74BBA2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xC66AB11C9BA841EDULL + 0x884FAAF316B9F4C8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xDA52232BF17363DDULL + 0xA887E8857B9418D8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xED889A113C138ACFULL + 0x8141FB8319C464E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE8A0A0CB82A36563ULL + 0xAB7D30E8D143D21BULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2749U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4551U)) & W_KEY1], 46U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3898U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 44U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) ^ RotL64(aCross, 27U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + 5088525177670191619U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 9966456257813932112U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 57U)) + 7707646574027146307U;
            aOrbiterA = (aWandererG + RotL64(aCross, 28U)) + 75480203757681173U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 37U)) + 384659134071835163U) + aNonceWordA;
            aOrbiterH = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 3158769775373307778U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 41U)) + 17360830943513941272U) + aPhaseAOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5317278822721604586U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 1371427105215954781U;
            aOrbiterB = RotL64((aOrbiterB * 10956603063464438611U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 3162710551223553423U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 5332921933853550756U;
            aOrbiterF = RotL64((aOrbiterF * 11709546145149357887U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 10572462410297815854U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 10234389605554817892U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 2130374833440291193U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13421365517991380605U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 10186643614984034083U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8554471709467808453U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 4742438973260817120U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 6081590345899008846U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7069396301823124931U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15360092808493795340U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12186413069553132646U;
            aOrbiterA = RotL64((aOrbiterA * 3815981440611914267U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16756221656224451552U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 12232880965861373143U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 14196910735715726471U), 29U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 51U)) + aOrbiterB);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 11U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + aPhaseAWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterF, 13U)) + aOrbiterI) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterF, 4U)) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterK) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aCross, 18U) + RotL64(aOrbiterF, 37U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10338U)) & S_BLOCK1], 54U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10185U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 10632U)) & W_KEY1], 12U) ^ RotL64(aKeyRowReadB[((aIndex + 5908U)) & W_KEY1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 6U) ^ RotL64(aCarry, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aCross, 43U)) + 12027839670755583592U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 29U)) + 15380130703509859843U) + aNonceWordB;
            aOrbiterA = (aWandererI + RotL64(aScatter, 3U)) + 4590907433867798074U;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 1754574023602519724U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 9832756659564903767U;
            aOrbiterD = (((aWandererH + RotL64(aCross, 19U)) + 5035088494491470403U) + aPhaseAOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 58U)) + RotL64(aCarry, 37U)) + 14199170923323644638U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterK) + 8325619421264440438U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 969534320779067977U;
            aOrbiterA = RotL64((aOrbiterA * 17767548306355264705U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 270575869402913847U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13344806516599578910U;
            aOrbiterB = RotL64((aOrbiterB * 10193544126281901579U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15143147951139409101U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14425582489214169238U;
            aOrbiterC = RotL64((aOrbiterC * 16893787086337916355U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13951127523239064584U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 14177925225918293579U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13079514031864998485U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8258920744278218901U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7408161179397242453U;
            aOrbiterI = RotL64((aOrbiterI * 975737128100519169U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8581481606764773468U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10078416198417433133U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1102721083915858247U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 18299772198826189580U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18304668908084397946U;
            aOrbiterE = RotL64((aOrbiterE * 10589455451200578687U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 41U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 14U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + aPhaseAWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterA, 3U));
            aWandererI = aWandererI + (((RotL64(aCross, 19U) + RotL64(aOrbiterB, 20U)) + aOrbiterD) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterA, 47U));
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 50U) + aOrbiterD) + RotL64(aOrbiterA, 57U));
            aWandererG = aWandererG + (((((RotL64(aCross, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordD) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 36U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordM;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15334U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 12828U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14339U)) & W_KEY1], 34U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 13435U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = (((aWandererA + RotL64(aIngress, 21U)) + 16200278595895089008U) + aPhaseAOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 1029614154810465897U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 53U)) + 7129562468705441295U;
            aOrbiterK = ((((aWandererH + RotL64(aScatter, 6U)) + RotL64(aCarry, 57U)) + 14388903902433951274U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordC;
            aOrbiterF = (aWandererB + RotL64(aCross, 43U)) + 1013568949315967455U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 35U)) + 3128823373497815651U;
            aOrbiterD = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 27U)) + 14525694606889470589U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14443983602196782887U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 12244220415328641190U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 15052949098014803181U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 10477159225338766614U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2842870123078131566U;
            aOrbiterC = RotL64((aOrbiterC * 11522265477555954071U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 8621138818955849917U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5038396344400303181U;
            aOrbiterG = RotL64((aOrbiterG * 14636756322207385447U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 2768613802894372496U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 2027754864051410015U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 2461322540050569287U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2848088309172056399U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15017458513904884651U;
            aOrbiterF = RotL64((aOrbiterF * 9926904679902843055U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 9079797279596336139U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15424866642305110811U;
            aOrbiterJ = RotL64((aOrbiterJ * 12912331089970158845U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13751764050290602740U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 7694557131324740282U;
            aOrbiterD = RotL64((aOrbiterD * 14980807690491467023U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererB = aWandererB + (((((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterK, 22U)) + RotL64(aCarry, 3U)) + aNonceWordI) + aPhaseAWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterA, 37U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 54U) + aOrbiterG) + RotL64(aOrbiterK, 3U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterJ) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterK) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 21686U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((aIndex + 21667U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18085U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 18332U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 23U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = ((aWandererK + RotL64(aIngress, 23U)) + 5906639480605353429U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (((aWandererA + RotL64(aScatter, 35U)) + 5293518570213287605U) + aPhaseAOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 51U)) + 15383185501428521377U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 58U)) + 15364072512743978902U) + aNonceWordM;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 23U)) + 4525473357144014271U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 35U)) + 10400911938125603074U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 16417506293824627550U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2419329331753341815U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14929222427923332069U;
            aOrbiterD = RotL64((aOrbiterD * 11596261802662514979U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16771573504983922586U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 1863466450051787622U;
            aOrbiterI = RotL64((aOrbiterI * 2585626547126027053U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12895350137096692415U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3700979086526298327U;
            aOrbiterA = RotL64((aOrbiterA * 10279730254867618193U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 1977099106211282426U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 6144698304096915742U;
            aOrbiterE = RotL64((aOrbiterE * 5039822990560519609U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 3858895556659724975U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1283646340363435327U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11622421841377018069U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6240532051889108891U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 757364889381634634U;
            aOrbiterJ = RotL64((aOrbiterJ * 943852137901972945U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 5272945693977418174U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6850528198786172283U;
            aOrbiterC = RotL64((aOrbiterC * 1966383079897679953U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + aOrbiterE) + RotL64(aOrbiterI, 21U));
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterE);
            aWandererC = aWandererC + ((((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 27U) + aOrbiterE) + RotL64(aOrbiterA, 52U)) + aNonceWordH) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + aNonceWordL);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterE, 37U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22238U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneA[((aIndex + 22310U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21961U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27177U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 56U)) ^ (RotL64(aIngress, 13U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = (((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 6361545377408870615U) + aNonceWordK;
            aOrbiterK = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 2967245486744774933U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 3836634268482850139U;
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 18U)) + 7691642115360086297U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 3U)) + 16479280384178279281U) + aNonceWordO;
            aOrbiterF = (aWandererF + RotL64(aCross, 27U)) + 2901468732552539249U;
            aOrbiterI = (aWandererH + RotL64(aPrevious, 41U)) + 2600353867755647475U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5666596904781510956U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 16108791609267427553U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8904649663479834199U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8389926875737312112U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1689501721163024426U;
            aOrbiterC = RotL64((aOrbiterC * 6517194895779049139U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 11721701506949917719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3963842745030140473U;
            aOrbiterH = RotL64((aOrbiterH * 6692473494944919373U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8510538243472109368U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 18281865214102080387U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 1351546966368884609U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 2259725140963665123U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 11652011949557979650U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterB = RotL64((aOrbiterB * 11260100762113295037U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1116085424226174473U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4725260319270802912U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4697109059565450269U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7348945429843437036U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 1249234309180653260U;
            aOrbiterI = RotL64((aOrbiterI * 3136745255820405881U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 22U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 44U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 41U)) + aOrbiterB) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterF, 26U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 19U) + aOrbiterI) + RotL64(aOrbiterG, 57U)) + aNonceWordJ) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 5U)) + aOrbiterG);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterI, 19U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 18U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31324U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32155U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28593U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 32336U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 52U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aScatter, 11U)) + 1708250618750199233U;
            aOrbiterH = ((aWandererG + RotL64(aIngress, 57U)) + 12009147777553691142U) + aNonceWordN;
            aOrbiterF = (aWandererB + RotL64(aCross, 51U)) + 8393982703399156592U;
            aOrbiterE = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 47U)) + 3247327098356831221U) + aPhaseAOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 43U)) + RotL64(aCarry, 5U)) + 3403590155376353737U;
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 18197244558104735044U) + aNonceWordP;
            aOrbiterB = (((aWandererF + RotL64(aCross, 18U)) + 3096253642040701606U) + aPhaseAOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8012692688785412179U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 17531946907545680745U;
            aOrbiterF = RotL64((aOrbiterF * 16510602981731506381U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 17687695944270225817U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 16147773866007628769U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16926442582711557877U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 18244641303026196497U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8839160526348897457U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14268021129087663397U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10599266240854068246U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 2056723540756216155U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13311591601230386375U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4629354220460621284U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9505955649473204942U;
            aOrbiterI = RotL64((aOrbiterI * 17775391885312236187U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 17078153810088721310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 9470436761716263000U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 5431855497250357229U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3305863413630104742U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 14377172434239576161U;
            aOrbiterH = RotL64((aOrbiterH * 6880176890091033423U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 50U);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 41U)) + aPhaseAWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + aNonceWordG);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 51U) + aOrbiterB) + RotL64(aOrbiterF, 35U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterK, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterF, 4U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 44U) + aOrbiterI) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 27U)) + aNonceWordJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 4U);
            aCarry = aCarry ^ aNonceWordP;
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

void TwistExpander_Archery_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x8AFDBE855EA08AD3ULL + 0xA59188E93742D01AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEC7EE66376681DC7ULL + 0x81D45125E2045F96ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xAF4B5C6E3FA3BA3BULL + 0x9A883C5D06D0352BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEBFF922E92054A15ULL + 0x857C75861F4496CDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x9CBC8D7AA3485CD7ULL + 0x905222CECF28451EULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x985C8C3378F314E3ULL + 0xEDB482E9DDF8B5E6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8413A4495ADB55A5ULL + 0xAB031E625DAE3D40ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8B22D7FEDFBC3E7FULL + 0xA8C1EF16FB51637AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xAD1A47B797C048A3ULL + 0xFEE202D08058A4F0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF811BF6E38F0DE59ULL + 0xA198B3ACA821C7F5ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x86086DF3BDFE7011ULL + 0xF3979145A33B67F0ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xBB32A831A5E70263ULL + 0xBBA7836533789FD6ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB03394B9C2DC511BULL + 0xA3DAC3C2D33AF609ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x901E43BF090C640DULL + 0x91C354C4E85F633EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFCBAB4C76BF888C1ULL + 0xC5E72F1F26C02311ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFC35CEBED11A6CB7ULL + 0xCEC811666A633681ULL);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4801U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2249U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5431U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 3888U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 36U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 3917730204724097072U) + aPhaseBOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 19U)) + 1874642340716212824U) + aNonceWordJ;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 29U)) + 6900165757434854160U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 5U)) + 12750946097023807161U) + aPhaseBOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 19U)) + 6563216048479513594U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 14960240191349450795U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterJ) ^ 16306180275951788289U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 12077366095522790283U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6502066618271045547U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6219852857850888738U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10892297250334325283U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2272931312452845850U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 3028929882263199463U;
            aOrbiterF = RotL64((aOrbiterF * 11005324285856805069U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 6067393030073568112U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 10094809900437037258U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18095564940730322769U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5962414178157074575U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 15755563045799129417U;
            aOrbiterC = RotL64((aOrbiterC * 3692603590609922031U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 43U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 44U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + aNonceWordB);
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterG, 21U)) + aOrbiterE) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 36U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aPhaseBWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 34U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8344U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9946U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7351U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 6364U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 4U) ^ RotL64(aIngress, 51U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 39U)) + 13278949403988203974U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererK + RotL64(aCross, 29U)) + 9213599924054673756U) + aPhaseBOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 41U)) + 1255746482932381798U) + aNonceWordI;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 11575321997144516122U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 20U)) + RotL64(aCarry, 53U)) + 15881587525529432437U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9846195809864862707U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12319815691858217670U;
            aOrbiterB = RotL64((aOrbiterB * 14271546305640811091U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterE) + 16322617427294439587U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 16332130810525887437U;
            aOrbiterC = RotL64((aOrbiterC * 7588076439690559343U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4920951156015336794U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16767126455124552329U;
            aOrbiterJ = RotL64((aOrbiterJ * 4440352337076842603U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12553595911087945223U) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1437522202135436142U;
            aOrbiterI = RotL64((aOrbiterI * 2001992794165550905U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 12313100454852227143U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 2761983020631055729U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 3874839760378039509U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 44U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordE) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 48U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererD = aWandererD + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 36U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterE, 23U)) + aNonceWordP) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13266U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneA[((aIndex + 12358U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12487U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14393U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 40U)) + (RotL64(aIngress, 21U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterF = ((((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 13854738573712660276U) + aPhaseBOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 19U)) + RotL64(aCarry, 11U)) + 16835460633412286294U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 37U)) + 6785859293758091931U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 58U)) + RotL64(aCarry, 51U)) + 126317283127992659U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 27U)) + 7568963536291415413U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12294016745653004819U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterF) ^ 18269588932920281147U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 9031152619272892317U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5872406424994751026U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7764434758831474129U;
            aOrbiterI = RotL64((aOrbiterI * 3772146788188420071U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 4804168969415573371U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 959601763507651280U;
            aOrbiterF = RotL64((aOrbiterF * 4647396592804833217U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9257644462479293048U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 14332699366894494579U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8829304078930625541U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10487012596470786004U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterI) ^ 612729229562321440U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 11380387280507726003U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 34U);
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aCross, 19U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 57U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + aNonceWordG) + aPhaseBWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterA, 21U)) + aOrbiterB) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 4U) + RotL64(aOrbiterB, 10U)) + aOrbiterD) + RotL64(aCarry, 23U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 16701U)) & S_BLOCK1], 6U) ^ RotL64(aWorkLaneB[((aIndex + 17168U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16431U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16929U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 18U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 58U)) + 2974056819475622600U) + aNonceWordC;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 37U)) + 7345051759236356098U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 21U)) + 12738468816846628882U;
            aOrbiterF = (((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 21U)) + 7694520596043297922U) + aNonceWordJ;
            aOrbiterG = (((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 5530753590015084774U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3776309161718383105U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 784780304358106404U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1503119308251871519U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8999942326995036509U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 5194986506064092779U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15070787038006135963U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7920040007459652762U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 11311997270710107937U;
            aOrbiterF = RotL64((aOrbiterF * 6227571709361790209U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5365231114813547251U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8630110234623825263U) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 2735881715888325759U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2358235238039571072U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18059414891616491807U;
            aOrbiterG = RotL64((aOrbiterG * 17150786106857185467U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + aNonceWordD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterK) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterK, 52U)) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 29U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordK;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24529U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 22165U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26633U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21903U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 30U)) + (RotL64(aCross, 43U) + RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 24U)) + RotL64(aCarry, 3U)) + 4204560462077827182U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 6572370199668594039U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 53U)) + 15958999876732622825U) + aNonceWordC;
            aOrbiterC = ((((aWandererC + RotL64(aIngress, 43U)) + RotL64(aCarry, 39U)) + 9969349486879280377U) + aPhaseBOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererA + RotL64(aScatter, 13U)) + 15450238998293956181U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9128619863683138259U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 5691270563628979565U;
            aOrbiterA = RotL64((aOrbiterA * 2170424734274640859U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5901029710568933106U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10442738941988588834U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 7386621444831603817U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 3508116020325721993U) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13221917083569767259U;
            aOrbiterG = RotL64((aOrbiterG * 6845108555710135357U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 11627915460377128176U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 17858261365514253433U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7535577636975884641U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4294837988806295989U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11242915481585070249U;
            aOrbiterC = RotL64((aOrbiterC * 17540688242763829319U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 11U) + aOrbiterF) + RotL64(aOrbiterI, 3U)) + aNonceWordF);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 19U) + aOrbiterI) + RotL64(aOrbiterG, 53U)) + aNonceWordD);
            aWandererC = aWandererC + ((((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterC, 24U)) + RotL64(aCarry, 35U)) + aPhaseBWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 28U) + RotL64(aOrbiterF, 11U)) + aOrbiterG) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 54U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30994U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((aIndex + 31228U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27805U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 28184U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 50U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererB + RotL64(aPrevious, 27U)) + 7270044678408187242U) + aPhaseBOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 5U)) + 10192278965379756766U;
            aOrbiterF = (((aWandererI + RotL64(aIngress, 38U)) + RotL64(aCarry, 53U)) + 17568666746676060748U) + aNonceWordA;
            aOrbiterG = (aWandererE + RotL64(aCross, 57U)) + 14312927531124963037U;
            aOrbiterC = ((((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 21U)) + 9825825726152087706U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 9696778570255265896U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17657841352013417228U;
            aOrbiterF = RotL64((aOrbiterF * 17562220176018833833U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 16207815085909628439U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1752979206374514227U;
            aOrbiterD = RotL64((aOrbiterD * 14182667540650694199U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10456310689643905854U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16127830548663742550U;
            aOrbiterH = RotL64((aOrbiterH * 4355938404839045417U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 2940917376003930842U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 7353596864777649953U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 7499468723171042005U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 12725092740446150705U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5791296650856037010U;
            aOrbiterC = RotL64((aOrbiterC * 760379251950502133U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((((RotL64(aCross, 22U) + aOrbiterD) + RotL64(aOrbiterH, 43U)) + aNonceWordI) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA + (((((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 51U)) + aNonceWordM) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            aWandererB = aWandererB + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 13U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterH, 58U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Archery_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x98B63868CC8FF0EBULL + 0x9BF7B9D95CDFFFA0ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xAD7DED1EBCF8189BULL + 0xF64D8DAC3BEA7018ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD44024561B40E18FULL + 0xDB0DCAADCB7CE9BDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA556D81CC0C17A1FULL + 0xE14ED9901445B5D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x95F0289A7909212BULL + 0x8B7AD73ADD3BE5BFULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC9356356E3AA19FBULL + 0xCC05BD3CB0623881ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x99A097269F6B5337ULL + 0x8776D35B1EF5A728ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9C884C59F920EC99ULL + 0xE8C05E9D5FBEE6E8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x80136083FAAB4EE1ULL + 0xE26801C3618096D1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE67942C2FC6096C1ULL + 0xF66556D9D1F46D13ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x956D48FB7F0D1FD9ULL + 0xF2C773763181381FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB949DA1039B694BDULL + 0x9B4D86A254AEE909ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x8EC7451FE13CF161ULL + 0x8013066CD0F75BE3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8A93907102928CBBULL + 0xF5115C52D17773E9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xC0B1061B8EC237C1ULL + 0xC2FB44CCE0722C20ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xE2287B1315C5AED9ULL + 0xD48C579AACBC96AAULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7760U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((aIndex + 7781U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6573U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 6719U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 26U)) ^ (RotL64(aCarry, 5U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 19U)) + 12311607308490066301U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 60U)) + RotL64(aCarry, 3U)) + 13100864684740679846U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 27U)) + 13697304189274329704U) + aNonceWordB;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 19U)) + 9047976902871216732U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aCross, 35U)) + 2147897579538537888U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 2072444829390996142U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 54U)) + 2129307836981020908U) + aNonceWordJ;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 10663145333751112064U;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 13U)) + 15019844390503785459U) + aPhaseCOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 5460865577557928142U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15806522559993224197U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8722932687972240099U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6361113778657833389U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 8306013884615042570U;
            aOrbiterA = RotL64((aOrbiterA * 8234258702656728667U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4038420580499706912U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11908091484457158973U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 3964111175645156719U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 11133912466611921250U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 2469227904206936928U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2704438771198001599U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13234017916788297295U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9061117693840451988U;
            aOrbiterJ = RotL64((aOrbiterJ * 3637440416741459419U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12013423690843812324U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 14371779015144617412U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3359568073302062667U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10044883414565441442U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14334898081890462218U;
            aOrbiterI = RotL64((aOrbiterI * 4878939077928220019U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 13788962593988366125U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8377887372059713516U;
            aOrbiterF = RotL64((aOrbiterF * 1925913354197206851U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 4584439257847749371U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 13335592911357756498U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 6515028218115896375U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 29U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (RotL64(aOrbiterD, 26U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 60U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aPhaseCWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 6U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 47U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 41U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aIngress, 12U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 54U)) + aNonceWordE);
            aWandererE = aWandererE + (((RotL64(aCross, 23U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererF, 60U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14844U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 15866U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14141U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 15110U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 26U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 47U)) + 17936518874386450467U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 13U)) + RotL64(aCarry, 13U)) + 13722737841589910344U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 58U)) + 11774969167948715796U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 3U)) + 3640101505680493777U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 23U)) + 1369495382725650822U) + aNonceWordG;
            aOrbiterE = ((aWandererF + RotL64(aCross, 19U)) + 11827310354654653345U) + aNonceWordO;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 36U)) + RotL64(aCarry, 21U)) + 186037671377175394U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 43U)) + 11428829344234627340U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 47U)) + 2275016369870029068U) + aPhaseCOrbiterAssignSaltE[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15471646673734798328U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 12172082573115640145U;
            aOrbiterJ = RotL64((aOrbiterJ * 9629417882787847753U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 6626736341348283154U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterF) ^ 12220614992483863623U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 8137086205714097487U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13157102324253760215U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 4143587482368093601U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 5060677690991506895U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11007575246013796426U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11721585930088637162U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 15009627907125738519U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5720789204450196217U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 3094696226821431648U;
            aOrbiterK = RotL64((aOrbiterK * 4412033981712165541U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 14675830108100986773U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9444071495289719645U;
            aOrbiterB = RotL64((aOrbiterB * 10983136361953366557U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5106753847015199956U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 7585421898593510010U;
            aOrbiterF = RotL64((aOrbiterF * 140996914192351011U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11746948407655524690U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16336323220286344483U;
            aOrbiterE = RotL64((aOrbiterE * 6590417628835864497U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8030445186765781136U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 276034088015165891U;
            aOrbiterC = RotL64((aOrbiterC * 7626025612710225099U), 47U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 12U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterE, 44U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 14U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + aNonceWordC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterK) + aNonceWordI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 53U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterF) + aPhaseCWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + aOrbiterJ) + RotL64(aOrbiterK, 3U)) + aNonceWordE);
            aWandererF = aWandererF + ((((RotL64(aCross, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterK, 58U));
            aWandererK = aWandererK + ((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18889U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneA[((aIndex + 19006U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 19464U)) & S_BLOCK1], 4U) ^ RotL64(aOperationLaneC[((aIndex + 21777U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 23U)) + (RotL64(aPrevious, 35U) + RotL64(aCarry, 51U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 19U)) + 3621877681473089725U) + aNonceWordJ;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 4451752751536414717U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 23U)) + 11371625415377772117U) + aPhaseCOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 27U)) + 6046792758881150619U) + aPhaseCOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 12U)) + RotL64(aCarry, 5U)) + 8213166120394461682U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 51U)) + 4343156661140422645U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 27U)) + 11105271483234947905U;
            aOrbiterB = (aWandererG + RotL64(aCross, 47U)) + 348904609985341372U;
            aOrbiterK = (aWandererI + RotL64(aScatter, 56U)) + 12924652822526858767U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 7461211697358520287U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16551553555297890558U;
            aOrbiterE = RotL64((aOrbiterE * 16432952324635746293U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11908056404140782995U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 9147367258259948715U;
            aOrbiterH = RotL64((aOrbiterH * 10777628928376261667U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 8876461054692728610U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 10546855952702525404U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10071104785895309677U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 4748636139110443794U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 783046909529525098U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 8969157702460927215U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16683965945838696665U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12385412690177109575U;
            aOrbiterC = RotL64((aOrbiterC * 10795062772707143187U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8210546822184469023U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13146493623236979963U;
            aOrbiterF = RotL64((aOrbiterF * 13199947810161148155U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 13857628148804187115U) + aNonceWordP;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 7241297989337473475U;
            aOrbiterG = RotL64((aOrbiterG * 16223448508809614229U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 773904571213804946U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 7660676598236419707U;
            aOrbiterB = RotL64((aOrbiterB * 14467390638468925567U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 16822672435156055469U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 6514707119190640433U;
            aOrbiterK = RotL64((aOrbiterK * 7097496727567460535U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterF, 38U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 43U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterK, 56U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 5U)) + aOrbiterJ);
            aWandererB = aWandererB + ((((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 19U)) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterC, 29U)) + aOrbiterA);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + aOrbiterC) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterC, 41U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterF, 60U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32353U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28339U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29852U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 26387U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterG = (aWandererF + RotL64(aScatter, 57U)) + 11698283336767769359U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 10U)) + 13297826354831483872U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 51U)) + 15254999058287530795U) + aPhaseCOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 19U)) + 17474166585085346567U) + aPhaseCOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 15684783498452840289U) + aNonceWordF;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 5061229733465216486U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 23U)) + 15370981279168377944U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 42U)) + RotL64(aCarry, 5U)) + 17966672773619554092U;
            aOrbiterD = ((aWandererK + RotL64(aCross, 27U)) + 14685092893994491068U) + aNonceWordA;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12798804186209406389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2848444181474221574U;
            aOrbiterI = RotL64((aOrbiterI * 13730480364920876877U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8551142075919636146U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8833198159158950723U;
            aOrbiterE = RotL64((aOrbiterE * 7650289040764974737U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7351473160893666232U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14204899612487622222U;
            aOrbiterB = RotL64((aOrbiterB * 6317485031956448029U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7008985178526543258U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13576796403863120356U;
            aOrbiterG = RotL64((aOrbiterG * 13745839827679114077U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 5769784656937900699U) + aNonceWordL;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14075925808204936705U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5844894088757604713U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17818667502858010896U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16016922065572683130U;
            aOrbiterA = RotL64((aOrbiterA * 7525645833898085373U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1582458237855075977U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 10830440354527138227U;
            aOrbiterH = RotL64((aOrbiterH * 10499386926982228251U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10653964151654643772U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11218475491129483859U;
            aOrbiterD = RotL64((aOrbiterD * 3338108067044357141U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9863649760189649255U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13790281439048354358U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4682098083538482849U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + RotL64(aOrbiterF, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterF, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 53U)) + aOrbiterE);
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 36U) + RotL64(aOrbiterH, 58U)) + aOrbiterB) + aNonceWordN);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterE, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterI, 21U)) + aOrbiterG) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 14U)) + aNonceWordP);
            aWandererD = aWandererD + ((((RotL64(aScatter, 48U) + aOrbiterE) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Archery_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xFB14BE5AD1BDE8A3ULL + 0xD5250E5EFA9A983FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8F2C28BD695C2785ULL + 0xF878B2B1F79AA978ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA3D52E8D94B5192DULL + 0x80A00D503DFF8273ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB2E6494D9332E479ULL + 0x9BDDD6C815E7BB9AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBE073B876D023919ULL + 0xFD2DF75C7C3C8B4BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9B511AE04541B2EDULL + 0xCEA71BCEFBCC82EFULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x978F43823DCCDA17ULL + 0xE49FA3DE3BEFA537ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD4C57A12D914A163ULL + 0xAA567DD660D11070ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE5A044C389297937ULL + 0xE2CD74D1FBA8C3DEULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xA4F0358D219A126FULL + 0xA6A0B8964386D496ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xACFAF3168554898FULL + 0xDD7F84878F402B4EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x89C41F83221E30FFULL + 0xB0F22830254A890AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA877FCBD372BC669ULL + 0xB2A7779FF3B5AC67ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDAFE426D23E5503DULL + 0xF69C1B054EC2599DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF3A8C9BA8BE1A519ULL + 0xA775551126E9F4FBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x82934EF9FB8F84DDULL + 0x993A53BFD62ECFAEULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5026U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 1557U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1802U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1472U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 29U)) ^ (RotL64(aPrevious, 10U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aIngress, 27U)) + 9630214189402543339U;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 3U)) + 4072576573737526819U;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 15994787452709618869U) + aNonceWordN;
            aOrbiterH = ((aWandererF + RotL64(aCross, 44U)) + 6403240137132259482U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 47U)) + 10229266900170507720U) + aNonceWordO;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 23U)) + 5025294577989748989U) + aNonceWordC;
            aOrbiterI = (aWandererA + RotL64(aCross, 29U)) + 16696461238217956883U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 36U)) + 9878318855341719119U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 16086635438116177346U;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 41U)) + 12295437783084203730U) + aPhaseDOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aScatter, 19U)) + 7681150419912842402U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2639104034287637448U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12298170009332243573U;
            aOrbiterC = RotL64((aOrbiterC * 9397919591171238575U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 3485932317267669626U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16569551670038752475U;
            aOrbiterK = RotL64((aOrbiterK * 8139802826402217631U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 4448490103784103954U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14510534073046885941U;
            aOrbiterF = RotL64((aOrbiterF * 7777192047386438305U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4286195398675733451U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15790355933840266463U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13342257823027075501U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 6362891510370156055U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15121822034579983174U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 7268045994574844937U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13817341015719915628U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14113474087906143783U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12838910141533126059U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 9988301252236121106U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 11287477288382171758U;
            aOrbiterG = RotL64((aOrbiterG * 4979297247881426383U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9491727010910328644U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 7961202721830514030U;
            aOrbiterB = RotL64((aOrbiterB * 16300364540313620767U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10058066852293995222U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 541563830282750968U;
            aOrbiterJ = RotL64((aOrbiterJ * 1516823517052019845U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7791201128863372861U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterC) ^ 8334318157449352359U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 2924838607279239375U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 6861081455774799715U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 9630214189402543339U;
            aOrbiterE = RotL64((aOrbiterE * 10837610668580336781U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + RotL64(aOrbiterF, 30U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + aNonceWordI) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterE, 60U)) + aOrbiterH);
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterA, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 42U) + RotL64(aOrbiterI, 35U)) + aOrbiterE);
            aWandererH = aWandererH + ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterD, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterG, 21U)) + aNonceWordG);
            aWandererC = aWandererC + (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 38U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 53U) + aOrbiterI) + RotL64(aOrbiterB, 41U));
            aWandererK = aWandererK + (((RotL64(aCross, 27U) + RotL64(aOrbiterH, 11U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterD, 23U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9473U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 10622U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6981U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((aIndex + 5749U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 42U) + RotL64(aIngress, 13U)) + (RotL64(aCross, 57U) ^ RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aScatter, 13U)) + 8988572360732005217U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 39U)) + 17889613225105985335U) + aNonceWordD;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 27U)) + 15563478320513948626U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (((aWandererA + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 3441351228410524816U) + aPhaseDOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 11U)) + 4425592689451435346U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 37U)) + 12733160231627305928U;
            aOrbiterC = (aWandererC + RotL64(aCross, 30U)) + 3574152157304607854U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 15167631896729808783U;
            aOrbiterI = (aWandererG + RotL64(aCross, 41U)) + 15822667973915417055U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 37U)) + 17181685481076577637U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 6U)) + 9979204751408873468U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 1334240485667164762U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9190066751460137016U;
            aOrbiterD = RotL64((aOrbiterD * 14585141844653660363U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15465215829109246336U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2305208282453624419U;
            aOrbiterH = RotL64((aOrbiterH * 10257861974108363283U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16951510027310993926U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11117938943423526901U;
            aOrbiterF = RotL64((aOrbiterF * 7805486716716924787U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12461379120662979432U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11719697049048823897U;
            aOrbiterC = RotL64((aOrbiterC * 14880996802304818757U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 6843357278142933570U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12727898578324702374U;
            aOrbiterI = RotL64((aOrbiterI * 9786435451654365097U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 18127999660067652233U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 11754709060558683082U;
            aOrbiterG = RotL64((aOrbiterG * 12798744012150745847U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 16940151146420516184U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 12924950783056761895U;
            aOrbiterJ = RotL64((aOrbiterJ * 8898170377271926745U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14829713915929878471U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 840466047621042565U;
            aOrbiterA = RotL64((aOrbiterA * 10748511630509529489U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 11469637840333471085U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 5561780312837795893U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11935079844970978957U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1059834104159730610U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10122108814456766430U) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 2184693583782179921U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14857099570072635006U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8988572360732005217U;
            aOrbiterK = RotL64((aOrbiterK * 14409836741925393077U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterH, 21U));
            aWandererE = aWandererE + ((RotL64(aIngress, 22U) + RotL64(aOrbiterI, 52U)) + aOrbiterH);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 39U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aNonceWordP);
            aWandererG = aWandererG ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aPhaseDWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + aPhaseDWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + aOrbiterB) + RotL64(aOrbiterA, 44U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 14496U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((aIndex + 13782U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12227U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 12423U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) + (RotL64(aCross, 21U) + RotL64(aPrevious, 40U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = (aWandererA + RotL64(aPrevious, 10U)) + 11698283336767769359U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 5U)) + 13297826354831483872U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 21U)) + 15254999058287530795U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 47U)) + 17474166585085346567U) + aNonceWordF;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 15684783498452840289U;
            aOrbiterB = (aWandererB + RotL64(aIngress, 19U)) + 5061229733465216486U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 11U)) + 15370981279168377944U) + aPhaseDOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 35U)) + 17966672773619554092U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 21U)) + 14685092893994491068U;
            aOrbiterA = (aWandererC + RotL64(aScatter, 41U)) + 12798804186209406389U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 24U)) + 2848444181474221574U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8551142075919636146U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8833198159158950723U;
            aOrbiterK = RotL64((aOrbiterK * 7650289040764974737U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7351473160893666232U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 14204899612487622222U;
            aOrbiterB = RotL64((aOrbiterB * 6317485031956448029U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7008985178526543258U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 13576796403863120356U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13745839827679114077U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5769784656937900699U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14075925808204936705U;
            aOrbiterH = RotL64((aOrbiterH * 5844894088757604713U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17818667502858010896U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16016922065572683130U;
            aOrbiterE = RotL64((aOrbiterE * 7525645833898085373U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1582458237855075977U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10830440354527138227U;
            aOrbiterA = RotL64((aOrbiterA * 10499386926982228251U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 10653964151654643772U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 11218475491129483859U;
            aOrbiterG = RotL64((aOrbiterG * 3338108067044357141U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9863649760189649255U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13790281439048354358U;
            aOrbiterD = RotL64((aOrbiterD * 4682098083538482849U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 14846954923718136337U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 522207783972623813U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14299798934454852811U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 426829715716262697U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 7482977730216354509U;
            aOrbiterC = RotL64((aOrbiterC * 6317437989422015173U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10736099808538972990U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 11698283336767769359U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 17230175904095995929U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 24U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterG, 27U)) + aNonceWordA) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aNonceWordI) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 18U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 35U)) + aOrbiterF);
            aWandererK = aWandererK + ((RotL64(aCross, 60U) + RotL64(aOrbiterE, 39U)) + aOrbiterK);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + aNonceWordB);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 57U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 24U) + aOrbiterI) + RotL64(aOrbiterD, 23U));
            aWandererC = aWandererC + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterI, 60U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 26U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 11U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 24U));
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17519U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16605U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17025U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19620U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 19U)) ^ (RotL64(aCross, 35U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 20U)) + 3105313968748067810U;
            aOrbiterC = (aWandererC + RotL64(aCross, 29U)) + 9977249451119627064U;
            aOrbiterD = (aWandererB + RotL64(aIngress, 11U)) + 17941392803495349366U;
            aOrbiterH = (aWandererH + RotL64(aScatter, 23U)) + 4279533326705471133U;
            aOrbiterJ = (((aWandererI + RotL64(aPrevious, 39U)) + 13983828966811580039U) + aPhaseDOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = ((aWandererK + RotL64(aCross, 47U)) + RotL64(aCarry, 37U)) + 3983490984234810378U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 57U)) + RotL64(aCarry, 53U)) + 308786542215259956U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 41U)) + RotL64(aCarry, 11U)) + 8443607695364427037U;
            aOrbiterG = (aWandererA + RotL64(aPrevious, 50U)) + 14939626441464340668U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 37U)) + 9350693577306121110U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 13U)) + 1717071159396961752U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15911765265202100610U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 14898546272333182767U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 2674900543810733067U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3560903518513465868U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5367062725726860234U;
            aOrbiterJ = RotL64((aOrbiterJ * 8521908836601319553U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15233321480618877327U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9288449812290126074U;
            aOrbiterF = RotL64((aOrbiterF * 6815298520404038519U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5504840529511585676U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 6825598386801620046U;
            aOrbiterA = RotL64((aOrbiterA * 11666542445846250077U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6433024450721339470U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 97934156644929458U;
            aOrbiterI = RotL64((aOrbiterI * 8630530773006923215U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 3260053604798744515U) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 16539416623243059076U;
            aOrbiterG = RotL64((aOrbiterG * 12199577351166064503U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 9814290051339038920U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13280156404507444041U;
            aOrbiterK = RotL64((aOrbiterK * 15269010043398910061U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11853942590993546833U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13207869904312989977U;
            aOrbiterE = RotL64((aOrbiterE * 15503461937625795969U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14536032167989376750U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3693282775047432356U;
            aOrbiterB = RotL64((aOrbiterB * 5290349323647887877U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5803176485246280271U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16702526675475954730U;
            aOrbiterC = RotL64((aOrbiterC * 13695676754973145769U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 16454171963808313625U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 3105313968748067810U;
            aOrbiterH = RotL64((aOrbiterH * 16572687178789102843U), 37U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterE, 42U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 27U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterC, 42U));
            aWandererF = aWandererF + ((RotL64(aScatter, 30U) + aOrbiterK) + RotL64(aOrbiterA, 11U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterD, 5U)) + aOrbiterH) + aNonceWordM);
            aWandererD = aWandererD + ((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterF, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 19U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterJ, 3U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 34U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aPrevious, 51U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordG);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24783U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 26419U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26672U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 24614U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 19U)) + (RotL64(aPrevious, 53U) + RotL64(aCarry, 38U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 35U)) + 9888431329297626900U) + aNonceWordE;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 19U)) + 2937735167534624403U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 54U)) + 17626022970343789617U;
            aOrbiterA = (aWandererA + RotL64(aCross, 13U)) + 5665660859333693743U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 47U)) + 1060537034632076669U) + aNonceWordA;
            aOrbiterE = (aWandererG + RotL64(aIngress, 51U)) + 743777763907175800U;
            aOrbiterG = (aWandererB + RotL64(aCross, 11U)) + 5744905970181808845U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 6U)) + 3545351394494002180U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = (aWandererK + RotL64(aIngress, 27U)) + 4877547088414106007U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 11669378338379598445U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 2961072441706158212U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 13984945589234919765U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1433097875470903205U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 451996840039906781U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 716415411025451152U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8542286150858297810U;
            aOrbiterE = RotL64((aOrbiterE * 9139015340823332449U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12932391786479661299U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 14005503313299177013U;
            aOrbiterK = RotL64((aOrbiterK * 802663466907819743U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9382792812676318046U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 5138554251079724724U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6386016499265056247U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 8522380066269546172U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11825536408101906458U;
            aOrbiterB = RotL64((aOrbiterB * 17042837108792016849U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 15504062350899452495U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1219010998820336744U;
            aOrbiterA = RotL64((aOrbiterA * 10650635772711590803U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6442717843380349632U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1047843426279085117U;
            aOrbiterG = RotL64((aOrbiterG * 4074561571072878005U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10611039527108679173U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 5092816736177358221U;
            aOrbiterC = RotL64((aOrbiterC * 14342779343820140833U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12327496881352988530U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 6405703847824845457U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12094143526751620113U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8906613392335197542U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5962698890029858689U;
            aOrbiterD = RotL64((aOrbiterD * 9136193803330500489U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2610083915800734277U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9888431329297626900U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3794133356691218671U), 47U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (RotL64(aOrbiterI, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterA, 30U));
            aWandererI = aWandererI + ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 53U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterK, 43U)) + aOrbiterH) + aPhaseDWandererUpdateSaltD[((aIndex + 16U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD + ((((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 5U)) + aNonceWordM);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 47U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aIngress, 4U) + RotL64(aOrbiterB, 57U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterE, 35U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + aOrbiterC) + RotL64(aOrbiterH, 50U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 41U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 44U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 57U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28263U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 28060U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30950U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27772U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 56U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 6069475454765660321U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 51U)) + 11483704742497268068U;
            aOrbiterH = (aWandererE + RotL64(aCross, 24U)) + 11055697447388986418U;
            aOrbiterD = ((((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 10897095046039997004U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 53U)) + 4731637118230457840U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aPrevious, 3U)) + 13855839187084986751U;
            aOrbiterI = (aWandererB + RotL64(aCross, 27U)) + 5328208115460188239U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 47U)) + 12479538544291412985U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 37U)) + 10740165998792608231U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 5U)) + 6492798157284955373U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 58U)) + 13056825957483891921U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2068184064919194657U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 5656302738780746294U;
            aOrbiterH = RotL64((aOrbiterH * 16493021179127646345U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11193756120230763294U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 17306750816837208999U;
            aOrbiterG = RotL64((aOrbiterG * 7949360041241439741U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 12952818800389361804U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15380412293642628312U;
            aOrbiterF = RotL64((aOrbiterF * 2914662289178925547U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7706090204767242996U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 14598802276412649570U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4821408736292041399U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 17819762117328075515U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 6481384240915075101U;
            aOrbiterB = RotL64((aOrbiterB * 4836701121865783029U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 754936290510338717U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15510875946573720154U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2994718968852184303U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 9245381722813944586U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2629847912019726214U;
            aOrbiterJ = RotL64((aOrbiterJ * 6718795794951106961U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3909987749797113773U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 9277056074757335265U;
            aOrbiterC = RotL64((aOrbiterC * 11580847505996697115U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12577180954515966707U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9144513680789115458U;
            aOrbiterK = RotL64((aOrbiterK * 8880777678193004979U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 1544232962956974411U) + aNonceWordK;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2658275904714859636U;
            aOrbiterE = RotL64((aOrbiterE * 1926083316365175327U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5733515391293514025U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6069475454765660321U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 9627476106108146391U), 3U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 39U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 57U)) + aOrbiterD);
            aWandererC = aWandererC + ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 50U)) + aOrbiterJ);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterC) + aNonceWordF);
            aWandererB = aWandererB + ((RotL64(aIngress, 24U) + RotL64(aOrbiterK, 37U)) + aOrbiterH);
            aWandererG = aWandererG ^ ((((RotL64(aCross, 11U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + aNonceWordI) + aPhaseDWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 13U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 43U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 42U) + aOrbiterJ) + RotL64(aOrbiterG, 22U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC) + aPhaseDWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 41U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 13U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordD);
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

void TwistExpander_Archery_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD578B72E7507D275ULL + 0x97D84D9B7CED90E3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x86CF0F30768DDC3BULL + 0xE377FAEA8F307638ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC8C8F6CB32D46C25ULL + 0xEE42CDA6C3527EE5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x850E6CFDB9887F5BULL + 0xF07A305854B777BCULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC5B661F7EEF6BB8FULL + 0xB2D2B30F1A78CA37ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xC701A792656D6F07ULL + 0xD3C382E67B962BD1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xB8DE3C97744A1B09ULL + 0xCBA759062D08C584ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xEF7D625AD76E20C5ULL + 0xE7D083C15803F48EULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xACB60E74246DD837ULL + 0xFBA1834DD6AC88E3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x96FC25689CA8912BULL + 0xAF25CE78BF82623AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB3C25FC447D63BF3ULL + 0xE337D5A2AB1C0B67ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB68FED8851D6C187ULL + 0xD9B247BDCF426AF3ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xB818ED72B7CAA0B1ULL + 0xC7D357C727EF58E8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBE4C54E1B05AE217ULL + 0x8239C39949F3FCF7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xD07D937A7E69B36FULL + 0xBC542EA8CF264D0EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF8FCC144B0FEE137ULL + 0xAF4F5AEE3ACDD93AULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1554U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 3464U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 4156U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 1150U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aIngress, 27U)) + 9041099828460168106U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 53U)) + 12883711604096848454U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 23U)) + 17420968786226443079U) + aNonceWordO;
            aOrbiterH = (((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 3448213891716125104U) + aNonceWordF;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 29U)) + 11866455977445336560U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 47U)) + 4119356835384495905U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aPrevious, 38U)) + 2186212599698637068U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 21U)) + 6506144898969301620U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 11U)) + 12556800923644051626U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 5U)) + 4075551535185182945U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 42U)) + RotL64(aCarry, 13U)) + 17877694808492008749U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 5553428900598223316U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14362304852277160675U;
            aOrbiterE = RotL64((aOrbiterE * 11415103199856419303U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9174200302876075831U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16110739511917638547U;
            aOrbiterI = RotL64((aOrbiterI * 7004356839428657949U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 10189881974519849402U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 2128076632642616677U;
            aOrbiterC = RotL64((aOrbiterC * 8860453653433114929U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18133523799074400083U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9916472958834153766U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3454601168808001733U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10274457562795569227U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 14134814273275356425U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15912501063665343159U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6394306369514735480U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4825761192736485643U;
            aOrbiterA = RotL64((aOrbiterA * 12534544147331805643U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5672807934779206275U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3881953574159390421U;
            aOrbiterB = RotL64((aOrbiterB * 7448770570912161095U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12012232712634303203U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14176392925893052596U;
            aOrbiterD = RotL64((aOrbiterD * 11288668529893084583U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 307148402076391033U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15380446373458263079U;
            aOrbiterJ = RotL64((aOrbiterJ * 15228462337097647933U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4654312690816676129U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10818029316701301859U;
            aOrbiterG = RotL64((aOrbiterG * 16245734506125913215U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7340370713289840635U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 9041099828460168106U;
            aOrbiterK = RotL64((aOrbiterK * 1807356802142268373U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 27U)) + aOrbiterF) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 23U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterA) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 6U) + aOrbiterK) + RotL64(aOrbiterH, 14U)) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 41U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 51U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 46U) + aOrbiterI) + RotL64(aOrbiterJ, 21U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 29U) + aOrbiterA) + RotL64(aOrbiterF, 36U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 54U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 5854U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneD[((aIndex + 10480U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 9815U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((aIndex + 9475U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 11U)) + (RotL64(aPrevious, 40U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererE + RotL64(aScatter, 3U)) + 8975885703279267062U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 50U)) + 8664844915562660637U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 47U)) + 12281774799736296726U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 11U)) + 15347461352311329726U) + aNonceWordE;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 37U)) + 12967500561828907834U) + aNonceWordH;
            aOrbiterG = (aWandererA + RotL64(aIngress, 5U)) + 5002833859280402726U;
            aOrbiterD = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 11908257536954668983U) + aNonceWordG;
            aOrbiterE = (aWandererH + RotL64(aCross, 35U)) + 17017174811949227162U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 53U)) + 16851323125613931180U) + aPhaseEOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aPrevious, 53U)) + 13469326957728686706U;
            aOrbiterB = (aWandererI + RotL64(aCross, 28U)) + 5228638551056105241U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11945166198089308564U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16268645041872996022U;
            aOrbiterK = RotL64((aOrbiterK * 5391448793718370911U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14781204627695095701U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5365325354838101092U;
            aOrbiterI = RotL64((aOrbiterI * 8017284997946310807U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 563147416025715953U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14660867395395625851U;
            aOrbiterJ = RotL64((aOrbiterJ * 4769458126865307103U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3168989056355712105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 16179131669773665579U;
            aOrbiterD = RotL64((aOrbiterD * 5641461617066671723U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4160220074225527179U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8597134686962559111U;
            aOrbiterH = RotL64((aOrbiterH * 639572585431474015U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16811551552456811661U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 5827323970423386301U;
            aOrbiterF = RotL64((aOrbiterF * 9328247349730652021U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 15583234353262170227U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2950816254621717748U;
            aOrbiterA = RotL64((aOrbiterA * 1102417597476170143U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4426165025104306337U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11871220132164971152U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2366168050042802207U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3832424136113939717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17673885217916768611U;
            aOrbiterE = RotL64((aOrbiterE * 10887063696370811871U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 3479289844909914390U) + aNonceWordI;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9498461576098567546U;
            aOrbiterC = RotL64((aOrbiterC * 8734492074299676555U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10645314291190544864U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8975885703279267062U;
            aOrbiterB = RotL64((aOrbiterB * 16584086014947250551U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 44U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 34U) + aOrbiterG) + RotL64(aOrbiterE, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 28U)) + aOrbiterK) + aNonceWordK);
            aWandererD = aWandererD + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aNonceWordP) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterE) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 5U)) + aOrbiterJ);
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterC, 23U)) + aOrbiterB) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 56U) + aOrbiterK) + RotL64(aOrbiterJ, 20U)) + RotL64(aCarry, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterB, 39U));
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 14U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordK);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 15254U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11036U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14177U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((aIndex + 16139U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aIngress, 5U)) + 6069475454765660321U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aScatter, 27U)) + 11483704742497268068U;
            aOrbiterE = (aWandererI + RotL64(aCross, 56U)) + 11055697447388986418U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 13U)) + 10897095046039997004U) + aNonceWordE;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 4731637118230457840U;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 3U)) + 13855839187084986751U) + aPhaseEOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 5328208115460188239U;
            aOrbiterK = (aWandererD + RotL64(aCross, 47U)) + 12479538544291412985U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 53U)) + 10740165998792608231U;
            aOrbiterH = (aWandererH + RotL64(aCross, 39U)) + 6492798157284955373U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 24U)) + 13056825957483891921U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2068184064919194657U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5656302738780746294U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16493021179127646345U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 11193756120230763294U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 17306750816837208999U;
            aOrbiterF = RotL64((aOrbiterF * 7949360041241439741U), 39U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12952818800389361804U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15380412293642628312U;
            aOrbiterB = RotL64((aOrbiterB * 2914662289178925547U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7706090204767242996U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 14598802276412649570U;
            aOrbiterC = RotL64((aOrbiterC * 4821408736292041399U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17819762117328075515U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 6481384240915075101U;
            aOrbiterK = RotL64((aOrbiterK * 4836701121865783029U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 754936290510338717U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15510875946573720154U;
            aOrbiterH = RotL64((aOrbiterH * 2994718968852184303U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9245381722813944586U) + aNonceWordB;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2629847912019726214U;
            aOrbiterD = RotL64((aOrbiterD * 6718795794951106961U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 3909987749797113773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9277056074757335265U;
            aOrbiterG = RotL64((aOrbiterG * 11580847505996697115U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12577180954515966707U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9144513680789115458U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8880777678193004979U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1544232962956974411U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2658275904714859636U;
            aOrbiterA = RotL64((aOrbiterA * 1926083316365175327U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5733515391293514025U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6069475454765660321U;
            aOrbiterI = RotL64((aOrbiterI * 9627476106108146391U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 53U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 22U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterE, 24U)) + aOrbiterG);
            aWandererB = aWandererB + (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 43U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 37U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterE, 11U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterI, 3U));
            aWandererE = aWandererE + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterF) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 34U) + aOrbiterH) + RotL64(aOrbiterB, 30U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 18444U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18465U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20489U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((aIndex + 18073U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 52U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 19U) + RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aCross, 10U)) + 14214886793361825363U) + aNonceWordO;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 37U)) + RotL64(aCarry, 19U)) + 17267959031078766320U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 29U)) + 16436067429484887644U;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 23U)) + 9885951769332633820U) + aNonceWordA;
            aOrbiterK = (aWandererH + RotL64(aIngress, 41U)) + 12971711341813893304U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 19U)) + 199970353398450154U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 57U)) + 1237341696444162094U;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 47U)) + 7991128854417613360U;
            aOrbiterD = (((aWandererG + RotL64(aCross, 50U)) + RotL64(aCarry, 53U)) + 14809029847149045833U) + aNonceWordK;
            aOrbiterI = (aWandererB + RotL64(aPrevious, 53U)) + 2559509556915775947U;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 14336829730147834160U) + aPhaseEOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 8853631886733610440U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 13346159398673246914U;
            aOrbiterG = RotL64((aOrbiterG * 13660497151446983393U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12121095718571872976U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16239781125815589804U;
            aOrbiterK = RotL64((aOrbiterK * 5157009090454962231U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9051377033794324106U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 13805815136723461780U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 571129481747181357U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 14849157800322754413U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 18116651528452542634U;
            aOrbiterB = RotL64((aOrbiterB * 3638480428016835537U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 4105057226952948599U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5911714320560994391U;
            aOrbiterJ = RotL64((aOrbiterJ * 1796514171654961389U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4439149331729987587U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 10278532228230163632U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17428224919864716517U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2342456582668741750U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 2360578572554664800U;
            aOrbiterI = RotL64((aOrbiterI * 1108428466956691925U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12132934875391401246U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17213278726790245812U;
            aOrbiterC = RotL64((aOrbiterC * 11904899990681410419U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7994340481560109811U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 13735851271080138255U;
            aOrbiterE = RotL64((aOrbiterE * 12387076892129731557U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6682417543888875268U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15642799286975840550U;
            aOrbiterH = RotL64((aOrbiterH * 7861250716882028053U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9839299346094784067U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14214886793361825363U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2103132743364916037U), 11U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 50U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 51U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterE, 48U)) + aPhaseEWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterH, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterD, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            aWandererB = aWandererB + ((RotL64(aIngress, 47U) + RotL64(aOrbiterG, 13U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 54U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 26U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererK = aWandererK + ((((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 41U)) + aPhaseEWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 39U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24319U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 22698U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25653U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25734U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 35U)) + (RotL64(aIngress, 5U) + RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 44U)) + 5721224134332887360U) + aPhaseEOrbiterAssignSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererH + RotL64(aIngress, 29U)) + 6892749729775049095U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 13U)) + 3884839462099556836U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 39U)) + 4365431706830216193U) + aNonceWordJ;
            aOrbiterB = (aWandererE + RotL64(aScatter, 23U)) + 15501528746571578773U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 27U)) + 4505911326320650606U) + aPhaseEOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 34U)) + 1865129050927879580U) + aNonceWordH;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 51U)) + 2011737665969640369U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 21U)) + RotL64(aCarry, 57U)) + 611672935827062688U) + aNonceWordC;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 663547038310431047U;
            aOrbiterD = (aWandererF + RotL64(aCross, 53U)) + 5468932264754299556U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 17920294117231191705U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 486058453837528110U;
            aOrbiterC = RotL64((aOrbiterC * 8851102552244026737U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 2789178451938129313U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 420772587981211184U;
            aOrbiterG = RotL64((aOrbiterG * 17402987842294006667U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16196774774442181825U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 16264169656793713547U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6900221986041638783U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 10207659833859860796U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8593749091183323678U;
            aOrbiterK = RotL64((aOrbiterK * 10696776033512404927U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7224922076047787384U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15366267474865172373U;
            aOrbiterF = RotL64((aOrbiterF * 10134187073321814217U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4235342515820080294U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5239480080426950612U;
            aOrbiterI = RotL64((aOrbiterI * 12077621553561927079U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 10891752830598395582U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7797358829694471108U;
            aOrbiterH = RotL64((aOrbiterH * 7621206775460997431U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3755715857903753416U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3172069024987421726U;
            aOrbiterJ = RotL64((aOrbiterJ * 16048490837178650865U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8623351347363497301U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 5895306804546658158U;
            aOrbiterD = RotL64((aOrbiterD * 1568542219600635919U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5026075347235960113U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3706258841140585921U;
            aOrbiterA = RotL64((aOrbiterA * 4911715089264902109U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6753904207571971217U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5721224134332887360U;
            aOrbiterB = RotL64((aOrbiterB * 4531182106796534951U), 53U);
            //
            aIngress = RotL64(aOrbiterD, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 46U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterH, 27U));
            aWandererC = aWandererC + ((RotL64(aScatter, 44U) + aOrbiterI) + RotL64(aOrbiterC, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 60U)) + aOrbiterJ) + aNonceWordO);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 13U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterA, 47U)) + aNonceWordE);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + RotL64(aOrbiterG, 37U)) + aOrbiterI);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 60U) + RotL64(aOrbiterJ, 58U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 39U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 43U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 48U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 31283U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneB[((aIndex + 29073U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30233U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 27886U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aCross, 5U)) + 785861751704720606U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 15968088718435606299U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 3U)) + 1393976526590347151U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 27U)) + 17240750947292745884U;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 57U)) + 4921576136163183137U) + aNonceWordA;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 47U)) + 3334047873553153032U) + aNonceWordJ;
            aOrbiterB = ((aWandererA + RotL64(aCross, 52U)) + RotL64(aCarry, 21U)) + 15086509978458408698U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 43U)) + 892391205397581998U;
            aOrbiterE = (((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 2965686403183767521U) + aPhaseEOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 29U)) + 14632215393655706170U;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 34U)) + 15740589515342377322U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11131164813943086445U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6988080581278900960U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6412189142344044255U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 16021254613117657178U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6183615599897921154U;
            aOrbiterK = RotL64((aOrbiterK * 9976411093264211033U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 12533992547026652747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3104325358982904219U;
            aOrbiterG = RotL64((aOrbiterG * 14977348108778147265U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3878525937957474644U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2120435259884368445U;
            aOrbiterB = RotL64((aOrbiterB * 15964718652193073177U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14928658302694194856U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 9121310461310309348U) ^ aNonceWordK;
            aOrbiterD = RotL64((aOrbiterD * 17304439784647477491U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3715693239100476493U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7336577492932262490U;
            aOrbiterE = RotL64((aOrbiterE * 11074754160002665253U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 2312452827448455675U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4322756069651934618U;
            aOrbiterF = RotL64((aOrbiterF * 6908893297397073539U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4962079617577705818U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5072727464750706525U;
            aOrbiterJ = RotL64((aOrbiterJ * 4947670001221089155U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4553791875259778686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15823770920225774233U;
            aOrbiterH = RotL64((aOrbiterH * 409663191536830375U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9468608484284459072U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8658861660659699947U;
            aOrbiterA = RotL64((aOrbiterA * 2933359123761406353U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14453429515273506170U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 785861751704720606U;
            aOrbiterC = RotL64((aOrbiterC * 3544627380583668815U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 48U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterI, 51U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterG, 24U));
            aWandererK = aWandererK + (((((RotL64(aCross, 12U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 21U)) + aNonceWordO) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterI) + RotL64(aOrbiterD, 13U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 43U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 37U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 26U) + aOrbiterB) + RotL64(aOrbiterG, 35U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererH, 26U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 60U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Archery_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDCEB3E2FDB9C58EBULL + 0xEBD1D87C9F4DF95DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x931006C4CBBE1B85ULL + 0xA8DDE930E7792102ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x932676D3C9C438E1ULL + 0xF4E76E65893BFC16ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA0DDBAC688F7F78FULL + 0x9C84A983C261798BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xAFE11FA5B9BAE6A5ULL + 0xA2A861E91BA05847ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9AB9409ECE87D7B1ULL + 0xABFA435703C0E1E8ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAB69F3F45BF7EF37ULL + 0xC122438A4FA69E17ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB98D82905AC0ACCDULL + 0x8AC70D8505D315F1ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB967B9F5C4F484E5ULL + 0xF776EDA383B6079CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA078B93F3FF6E1AFULL + 0xC404B39608E5E221ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xD6F8D55902B403A7ULL + 0xFBB8B9510C66EA0BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x9D2B30B51089256BULL + 0xC9D59012E143B443ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA0D7388E0EAAA2B1ULL + 0xBB2B9E0D07B0A54BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBE1A0FD2C3108639ULL + 0x8E83CF0A7F26A239ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xFF7B20534E9EF4D1ULL + 0xC7387169150C1BBEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x91D60F9AFB995381ULL + 0xC24A72A5596CF902ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 2784U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1266U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2424U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneA[((aIndex + 1866U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 27U) + RotL64(aIngress, 42U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 35U)) + 252059974543142812U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 56U)) + 11690823093681457368U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 19U)) + 13282189752890971123U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 3U)) + 9507416294305708435U;
            aOrbiterD = ((aWandererI + RotL64(aCross, 47U)) + 14053038174390776539U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aIngress, 21U)) + 14605253312318725009U) + aPhaseFOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 13U)) + 18138286582677863671U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 19U)) + 8530091235978489988U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 40U)) + RotL64(aCarry, 53U)) + 14381731677571170073U) + aNonceWordF;
            aOrbiterA = (aWandererB + RotL64(aScatter, 29U)) + 13316413456378978456U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 43U)) + 3910529530149320706U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6302070286831566901U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 12324134652758551396U;
            aOrbiterF = RotL64((aOrbiterF * 17136438281540250165U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4773478557638475048U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 4031153435446078944U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 3876928995240982769U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3114794895962903899U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 3552936509969106796U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16823186892738820299U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5828754613946145627U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17985241114076114558U;
            aOrbiterI = RotL64((aOrbiterI * 1986669631395606833U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 11319331046368072261U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 6104267020171882160U;
            aOrbiterG = RotL64((aOrbiterG * 12525117969211576177U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 7662668379725735125U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6583034411403600735U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 262095656452193889U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 5569865728026310280U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4176065898330374039U;
            aOrbiterB = RotL64((aOrbiterB * 11305749530796963967U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 13677146592276526676U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 2734371113158117596U;
            aOrbiterK = RotL64((aOrbiterK * 13146444882662731975U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14890607377967461739U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3110674898918355049U;
            aOrbiterD = RotL64((aOrbiterD * 9637837600671200315U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15329760212453783067U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 18214263442264013242U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 9139354822936682953U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 6727267537859989206U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 252059974543142812U;
            aOrbiterA = RotL64((aOrbiterA * 9559128226993261041U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterC, 51U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterE, 38U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterD, 47U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 58U) + aOrbiterD) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterB, 27U)) + aNonceWordC) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 11U) + RotL64(aOrbiterG, 23U)) + aOrbiterE) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 13U)) + aOrbiterJ) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aIngress, 4U) + aOrbiterF) + RotL64(aOrbiterE, 10U)) + aNonceWordN);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 21U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9640U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((aIndex + 6245U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7968U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 7847U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 4U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 17081642665820489793U) + aNonceWordH;
            aOrbiterF = (aWandererI + RotL64(aCross, 36U)) + 14468854040067229623U;
            aOrbiterH = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 51U)) + 2249450222593057429U) + aNonceWordN;
            aOrbiterA = (aWandererG + RotL64(aIngress, 11U)) + 14964389079511378664U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 47U)) + 17003491054252360650U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 19U)) + 12710882240582032588U;
            aOrbiterE = (aWandererA + RotL64(aIngress, 53U)) + 9887078182156755359U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 51U)) + 7665284531810584704U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 60U)) + 7304284015511876717U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 39U)) + 5517927023543751734U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 41U)) + 17704756310857362759U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11347400363019508578U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11696395232760991243U;
            aOrbiterH = RotL64((aOrbiterH * 9725231749679442003U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 10875780291242873583U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7808740614343437672U;
            aOrbiterF = RotL64((aOrbiterF * 8889516201913716283U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3145390996141902032U) + aNonceWordC;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 16080636485642732615U;
            aOrbiterC = RotL64((aOrbiterC * 7445756373012217305U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3929263288176983844U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 18210228766683996806U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13178080076505449091U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 13948962323541421431U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterK) ^ 3037683309790156893U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 13406672352222636739U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 17827265198532699474U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 7270895262023504864U;
            aOrbiterI = RotL64((aOrbiterI * 13467417362477308167U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6431243064980879185U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 6680205390976259885U;
            aOrbiterA = RotL64((aOrbiterA * 10421386694108590789U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15910655919164357152U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8046213498216027383U;
            aOrbiterJ = RotL64((aOrbiterJ * 18061867495824063553U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 2521111689480478597U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13892876610454681741U;
            aOrbiterD = RotL64((aOrbiterD * 17776392934374483875U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 16009217514890880809U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1221573458193626679U;
            aOrbiterK = RotL64((aOrbiterK * 73477765605619369U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9275704218554025797U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17081642665820489793U;
            aOrbiterG = RotL64((aOrbiterG * 5613316790159527375U), 51U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 58U);
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 24U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterA, 27U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterH, 37U)) + aPhaseFWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 54U) + RotL64(aOrbiterE, 5U)) + aOrbiterB) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterG, 42U));
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 57U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterE, 29U)) + aNonceWordI) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 39U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterF, 39U)) + aNonceWordB);
            aWandererH = aWandererH + (((RotL64(aScatter, 44U) + RotL64(aOrbiterG, 3U)) + aOrbiterK) + aNonceWordM);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 27U) + aOrbiterD) + RotL64(aOrbiterB, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 52U)) + aOrbiterJ) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + RotL64(aWandererE, 30U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15055U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 12071U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15263U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13698U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) + RotL64(aPrevious, 14U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 44U)) + RotL64(aCarry, 41U)) + 9751314027302668907U;
            aOrbiterC = (aWandererE + RotL64(aCross, 19U)) + 12175450995523107056U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 35U)) + 17519694958730119552U) + aNonceWordC;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 23U)) + 9093525527925682263U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 3713831321786810138U;
            aOrbiterB = (((aWandererB + RotL64(aScatter, 12U)) + RotL64(aCarry, 47U)) + 10108355209191835040U) + aNonceWordM;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 5U)) + 12956307447311314768U) + aPhaseFOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererC + RotL64(aIngress, 21U)) + 1904298513945877359U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aWandererG + RotL64(aPrevious, 39U)) + 4658049993308574460U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 57U)) + 9826333658248851902U;
            aOrbiterK = (aWandererH + RotL64(aIngress, 41U)) + 12058666914724365134U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 2516574707110528099U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13335308331049750235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5880227828760598587U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 8230749255538495304U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16536559486797811486U;
            aOrbiterB = RotL64((aOrbiterB * 7097036838156464969U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 12387639130570188998U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 8459259798142872020U;
            aOrbiterC = RotL64((aOrbiterC * 8001346480955847013U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16083784052002800300U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1957284290736468379U;
            aOrbiterD = RotL64((aOrbiterD * 5046501301740813065U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7349538179311335863U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16395170077006105258U;
            aOrbiterI = RotL64((aOrbiterI * 4230485452156662763U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 3317652065873784068U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5517155804799120700U;
            aOrbiterA = RotL64((aOrbiterA * 9789270651974719183U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5568525912112200094U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9334250662962319598U;
            aOrbiterE = RotL64((aOrbiterE * 5034887614541768961U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5641394627075994165U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13524971148931512745U;
            aOrbiterG = RotL64((aOrbiterG * 3699457147759854357U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15124425790244392471U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 7896294947517723306U;
            aOrbiterF = RotL64((aOrbiterF * 7526632360108129915U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 15241686066829586263U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 12099799118961857495U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10456171163074630861U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17529688916595727188U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 9751314027302668907U;
            aOrbiterK = RotL64((aOrbiterK * 521888849578281715U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterH, 27U));
            aWandererB = aWandererB + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + aNonceWordL);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 53U));
            aWandererH = aWandererH + ((RotL64(aCross, 46U) + aOrbiterB) + RotL64(aOrbiterE, 56U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterI, 39U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterB, 51U)) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 5U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterD, 12U)) + aPhaseFWandererUpdateSaltF[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 54U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20640U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17023U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18870U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 18577U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aPrevious, 19U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 35U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aPrevious, 37U)) + 15549114274303128055U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 56U)) + 16466750056388063241U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 41U)) + 12209449840836787142U;
            aOrbiterF = ((aWandererE + RotL64(aScatter, 51U)) + 14551496099734294336U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aCross, 43U)) + 6266576428679808622U;
            aOrbiterA = (aWandererD + RotL64(aScatter, 3U)) + 16892841575635668152U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 13U)) + 7375966221423362125U) + aPhaseFOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 11926105302821753530U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 47U)) + 16219253791550461124U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 34U)) + 7299056065319248160U) + aNonceWordL;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 27U)) + 15234001484933728439U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 6615802589932632120U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 5481176858895819247U;
            aOrbiterI = RotL64((aOrbiterI * 3604590158551984877U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 17220507586542139380U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14137921473739415340U;
            aOrbiterB = RotL64((aOrbiterB * 10634645686035907603U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16981960446540932787U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10897565927079518588U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 418843936329303571U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 2746889569299593263U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4894117146736361379U;
            aOrbiterG = RotL64((aOrbiterG * 2656750612042673191U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18294823016957137777U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 86828501068883383U;
            aOrbiterJ = RotL64((aOrbiterJ * 11432686669235402365U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6322053762209547826U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6754524552483363820U;
            aOrbiterD = RotL64((aOrbiterD * 1746163087826694641U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7306452650619361017U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12717201204443785828U;
            aOrbiterH = RotL64((aOrbiterH * 6121251603905574991U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 10422327053543898585U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14786413282036348183U;
            aOrbiterK = RotL64((aOrbiterK * 8713024293107068275U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 4599182534559908397U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 5080179685914177581U;
            aOrbiterE = RotL64((aOrbiterE * 14984675846207762951U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6527649204956325409U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8327234966110052920U;
            aOrbiterC = RotL64((aOrbiterC * 9343969092668123661U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7845497893651522069U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15549114274303128055U;
            aOrbiterF = RotL64((aOrbiterF * 15263427406359082909U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 51U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 44U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 27U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterA, 54U)) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterH, 41U));
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 52U) + RotL64(aOrbiterK, 23U)) + aOrbiterJ);
            aWandererE = aWandererE + (((((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 37U)) + aOrbiterA) + RotL64(aCarry, 37U)) + aNonceWordK) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterK, 50U)) + aNonceWordI);
            aWandererI = aWandererI + ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterK, 19U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 30U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 37U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordP;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23362U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 25797U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23534U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 24572U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) + RotL64(aCarry, 4U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 13U)) + 8685374557928800912U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 47U)) + 3482312691892161229U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 30U)) + RotL64(aCarry, 57U)) + 6948130297389161165U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 57U)) + 5506385663788942690U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 51U)) + 17859982009307397161U) + aPhaseFOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aIngress, 37U)) + 9178488809207094043U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 47U)) + 1835479501226057169U;
            aOrbiterI = (aWandererA + RotL64(aCross, 6U)) + 5368101733632614939U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 41U)) + 9050459666576835422U) + aNonceWordP;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 5U)) + 9042186993119635078U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 11U)) + 17528342580198295025U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6495418332558436882U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 8834495762667327342U;
            aOrbiterK = RotL64((aOrbiterK * 10783141541937645995U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 4364314196965690905U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 6357485231062120459U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 289429584586504995U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3321488322626415347U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10817330671781848737U;
            aOrbiterI = RotL64((aOrbiterI * 15875919466358823335U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17974092279281611763U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2871472057292789157U;
            aOrbiterH = RotL64((aOrbiterH * 16104199340711015181U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 15187929795092006849U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 13482063681546475923U;
            aOrbiterG = RotL64((aOrbiterG * 14466266308157364963U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6232152545071397380U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17488906002621373262U;
            aOrbiterB = RotL64((aOrbiterB * 4719340606442742577U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 12444819880507588549U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 13808941689757772497U;
            aOrbiterD = RotL64((aOrbiterD * 6541360905282412317U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8049361354387692374U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7137831335606542401U;
            aOrbiterF = RotL64((aOrbiterF * 11022231291507235007U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7230759462019420058U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3923744511976096944U;
            aOrbiterA = RotL64((aOrbiterA * 9953869624243563101U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15967667946023263856U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 8677583624693910669U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10737731876339973717U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1604347321263511013U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 8685374557928800912U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14103365695918844461U), 11U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterB, 23U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 40U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 30U) + aOrbiterJ) + RotL64(aOrbiterF, 38U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 27U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterF) + RotL64(aOrbiterH, 13U));
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 19U)) + aOrbiterF);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterA, 11U)) + aPhaseFWandererUpdateSaltB[((aIndex + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + aOrbiterC) + RotL64(aOrbiterJ, 51U)) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 47U)) + aOrbiterA);
            aWandererC = aWandererC ^ (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + aPhaseFWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterE, 54U)) + RotL64(aCarry, 53U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 4U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31077U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29615U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27692U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31429U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = (aWandererD + RotL64(aIngress, 28U)) + 3917730204724097072U;
            aOrbiterJ = (((aWandererK + RotL64(aCross, 41U)) + 1874642340716212824U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterC = (aWandererB + RotL64(aScatter, 39U)) + 6900165757434854160U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 5U)) + 12750946097023807161U) + aNonceWordO;
            aOrbiterA = (aWandererG + RotL64(aCross, 3U)) + 6563216048479513594U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 14960240191349450795U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 47U)) + 16306180275951788289U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 51U)) + 6502066618271045547U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 13U)) + 6219852857850888738U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 43U)) + RotL64(aCarry, 47U)) + 2272931312452845850U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 3028929882263199463U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 6067393030073568112U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10094809900437037258U;
            aOrbiterC = RotL64((aOrbiterC * 18095564940730322769U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5962414178157074575U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15755563045799129417U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3692603590609922031U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6321455513889880590U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1197435601998121700U;
            aOrbiterG = RotL64((aOrbiterG * 17693996266260557625U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12496949381666299968U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6357070235648527030U;
            aOrbiterF = RotL64((aOrbiterF * 2931486644220862433U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8423760160877540210U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 8090246492554850768U;
            aOrbiterK = RotL64((aOrbiterK * 2949407491181921633U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 11436635942985063755U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17086363141014359856U;
            aOrbiterD = RotL64((aOrbiterD * 10504127577318206801U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10734017887545474935U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 375515325165740779U;
            aOrbiterI = RotL64((aOrbiterI * 9980486695448151709U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 5217148491945389821U) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 14696058217023530058U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11026674782236654799U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11869055287836412650U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 16951500118659983436U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4304372681583055077U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 7866300390953569803U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 18017335943787362993U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15683049583437004889U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2477944286851267725U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 3917730204724097072U;
            aOrbiterB = RotL64((aOrbiterB * 6617615984203047419U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 24U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 19U)) + aOrbiterH) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + aNonceWordP);
            aWandererF = aWandererF + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterF, 3U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 44U) + aOrbiterC) + RotL64(aOrbiterH, 50U));
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterD, 11U)) + aOrbiterI) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterB, 43U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterA, 21U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterI, 46U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + aOrbiterB) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterJ, 39U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 37U)) + aOrbiterF) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 22U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 34U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 11U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_Archery_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xA49B286C189887B1ULL + 0x9C0626A75CAFF3E3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xCAE0C38DAAE770B7ULL + 0xC98FC1EF4C5855DEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE6C5DD073C68C7EDULL + 0x8403DE696E55FAC6ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBFEC755A17848685ULL + 0xEAFE959798857862ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x954037DEEC302207ULL + 0xB040FB463C30D057ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF8695A6AD3A26611ULL + 0x854C5066D7426D4BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xFAAC706283D5FF99ULL + 0xD5C31C9ECD052D8EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB08FC95BDEEC7629ULL + 0xCBA604635CB4A602ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD7FB4F247F846D05ULL + 0xE16F7420EA413C23ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCB8F72900F5D8B4DULL + 0xD16E759C219F4EA7ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF7C14D901FE11539ULL + 0xC86FB027C919EB44ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDD5B93FC3A835643ULL + 0x84DEE322B66100F5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xAB4B80E0847ED4B7ULL + 0xB1A5A77539A098D2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE53389C99641929BULL + 0xDBB4BDB5DFB55DB8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xED0C939A8DAF4F63ULL + 0xBFBABC1095793828ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBAB43FAF7C324D8DULL + 0xB6DE07928C5BB658ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 5413U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((aIndex + 4392U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1744U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3105U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) + RotL64(aPrevious, 6U)) ^ (RotL64(aCarry, 57U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 34U)) + 4384716820085860551U) + aNonceWordJ;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 21U)) + 9715780315942116888U) + aNonceWordB;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 39U)) + 15963520052789178632U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 14346700690686392938U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 47U)) + 6005518012489966643U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 14U)) + 2506732930310252119U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aCross, 37U)) + 16782163084851775826U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 51U)) + 823673076571076303U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 19U)) + 1634084509064077736U) + aPhaseFOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aCross, 27U)) + RotL64(aCarry, 35U)) + 1288134975466877686U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 2998220403162908444U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 220430672180734911U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10223923547068528867U;
            aOrbiterF = RotL64((aOrbiterF * 12577370238343872139U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 11696469696177647608U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6545430420379636963U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8387163146257553773U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 79691451831797107U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8971444023498649419U;
            aOrbiterH = RotL64((aOrbiterH * 7148919880477390009U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 5624403902454498793U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 9468064161002030997U;
            aOrbiterK = RotL64((aOrbiterK * 8243560528100864595U), 23U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 4619361544913629805U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 12682446273369750704U;
            aOrbiterI = RotL64((aOrbiterI * 10879074713156075641U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8728730962617599223U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9099675924074253030U;
            aOrbiterJ = RotL64((aOrbiterJ * 5525644236954497523U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3298303921318288541U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 5953276499411658358U;
            aOrbiterE = RotL64((aOrbiterE * 10565471305001292693U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6725769507592688539U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1057277456510215817U;
            aOrbiterD = RotL64((aOrbiterD * 8269412198279297075U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11317925732206917722U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 17814749417006079067U;
            aOrbiterG = RotL64((aOrbiterG * 4369209051015735925U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 9258362135343403308U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4873837345446960113U;
            aOrbiterB = RotL64((aOrbiterB * 14223381466269503273U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 7863380865835889675U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4384716820085860551U;
            aOrbiterC = RotL64((aOrbiterC * 2003891033298374621U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 43U);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 26U)) + aOrbiterG) + aNonceWordG) + aPhaseFWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 29U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 23U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterG, 53U)) + aOrbiterH) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterB, 50U)) + aOrbiterK);
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterG, 47U)) + aOrbiterK) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterH, 39U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10568U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 5853U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6205U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5704U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCarry, 3U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = ((aWandererC + RotL64(aCross, 34U)) + RotL64(aCarry, 13U)) + 13174219512651137892U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 2715455762789269341U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 43U)) + 1338018183235594313U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 3U)) + 16566866551729552930U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 6901845297307236726U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 21U)) + 2476078302049201718U) + aNonceWordE;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 26U)) + 15531109473927052260U) + aPhaseFOrbiterAssignSaltF[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 51U)) + 4087849380858572351U;
            aOrbiterE = (((aWandererE + RotL64(aCross, 53U)) + 5167830630098599644U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererI + RotL64(aIngress, 19U)) + 7275995452428627217U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 13U)) + 14794340370010024117U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8509217403041662849U) + aNonceWordF;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 2321522025240806996U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 113568101672878697U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5676672952755594051U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 2304681269233504384U;
            aOrbiterA = RotL64((aOrbiterA * 15731441084605554497U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8383399721062437300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13181984036942227666U;
            aOrbiterK = RotL64((aOrbiterK * 1648761328771932069U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13602604532551684210U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12725687663616352843U;
            aOrbiterC = RotL64((aOrbiterC * 4684699861686199753U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5831790822416009806U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4535048543735457407U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12076777878870257053U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10617608605149381858U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5244225377862618630U) ^ aNonceWordG;
            aOrbiterG = RotL64((aOrbiterG * 15307177251167023999U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18229989093139888456U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 9728120630096192811U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 16052574428163231023U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1312233443099767304U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8043115602160128619U;
            aOrbiterB = RotL64((aOrbiterB * 9365756845731616963U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 4679339316686216023U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 211799535650113758U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1478368466990144107U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13307123762743628190U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7093673238704478497U;
            aOrbiterJ = RotL64((aOrbiterJ * 13273906568866802561U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16396459072175632290U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 13174219512651137892U;
            aOrbiterH = RotL64((aOrbiterH * 7581008806810219369U), 39U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (RotL64(aOrbiterG, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 58U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 46U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterG, 39U));
            aWandererC = aWandererC + (((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterI, 47U)) + aNonceWordC) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 24U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG + ((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterH, 35U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterE, 6U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 13637U)) & S_BLOCK1], 30U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 15996U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 13051U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneC[((aIndex + 12266U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 41U)) + (RotL64(aCarry, 4U) ^ RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 13583136155674166402U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 18U)) + 12830472187484919497U) + aNonceWordB;
            aOrbiterJ = (aWandererJ + RotL64(aCross, 43U)) + 18081197909484522509U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 11U)) + 8680634051297891550U) + aNonceWordE;
            aOrbiterI = (aWandererH + RotL64(aScatter, 51U)) + 13939998767458656823U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 30U)) + 1795730579103692594U;
            aOrbiterA = ((aWandererE + RotL64(aCross, 57U)) + 17369751719734069999U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 224769585901248068U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 5U)) + 4133547085925268180U) + aNonceWordP;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 47U)) + 7022512056309567391U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererB + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 10319484359046945495U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10483878349412282069U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6481381149199985736U;
            aOrbiterJ = RotL64((aOrbiterJ * 9701719367082506253U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 13721077228796934509U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 9704818014314175007U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 760445624027740287U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6253040047758584339U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16890211690273641226U;
            aOrbiterF = RotL64((aOrbiterF * 5622534399866057841U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6216227831265032436U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2023609047004658739U;
            aOrbiterI = RotL64((aOrbiterI * 3252332895698310147U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9201669637050388263U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 5106927540934338576U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6368134569042291431U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10080368957861445998U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 10784789383436485808U;
            aOrbiterG = RotL64((aOrbiterG * 3794918350254445939U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15426339824951793026U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 17637144549368340331U;
            aOrbiterB = RotL64((aOrbiterB * 10971293914614704441U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 9941300382181962134U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8118046374121322097U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8481945819050983127U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 5138086185042567633U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7279942739248982986U;
            aOrbiterA = RotL64((aOrbiterA * 12911998308338410917U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 12135610639038562853U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 12945353426409788798U;
            aOrbiterH = RotL64((aOrbiterH * 7434977715954413699U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 7534876598022096222U) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13583136155674166402U;
            aOrbiterE = RotL64((aOrbiterE * 8194058098043157015U), 27U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterB, 26U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterE, 47U));
            aWandererC = aWandererC + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 18U)) + aOrbiterJ) + aNonceWordN) + aPhaseFWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 3U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE + ((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 23U)) + aOrbiterG);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterI, 37U)) + aOrbiterH);
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererK);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordO);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17753U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19005U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17148U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((aIndex + 17723U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 4U) + RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aIngress, 41U)) + 3612110001869385068U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 13U)) + 16340824141280225936U) + aNonceWordO;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 3U)) + 15222338965130765231U) + aNonceWordC;
            aOrbiterB = ((aWandererK + RotL64(aPrevious, 37U)) + 6649270508107155041U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 35U)) + 768217258655426384U) + aNonceWordI;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 4481855259658861851U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 50U)) + 18318041934562434016U;
            aOrbiterE = (((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 41U)) + 4212457153804401807U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aPrevious, 29U)) + 16143621095636987628U;
            aOrbiterI = (aWandererF + RotL64(aScatter, 47U)) + 2095664232866642086U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 54U)) + 4339527736737366572U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 13679353177869884790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 11582168502846418236U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 135539430034462861U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 10451330452898542191U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12951448817640617841U;
            aOrbiterD = RotL64((aOrbiterD * 4141870904192742091U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15389161934419370747U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 4754886272708253014U;
            aOrbiterA = RotL64((aOrbiterA * 16638243718191281597U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11746389873929280688U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 12042680172517298768U;
            aOrbiterG = RotL64((aOrbiterG * 3814780289755857543U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 2648103752465009244U) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 451594673632597973U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8496763663271072425U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5696534794094099710U) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14609435045257077395U;
            aOrbiterF = RotL64((aOrbiterF * 14658408563237468407U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11599395126850950133U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 12699598504604446664U;
            aOrbiterI = RotL64((aOrbiterI * 14313494063098111823U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9398465148537154745U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 12139736860648011256U;
            aOrbiterC = RotL64((aOrbiterC * 15257503229375247987U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5390816291244486383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 2797988892316486895U;
            aOrbiterH = RotL64((aOrbiterH * 14668138881285892065U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18356290434261054712U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 16582824574485822826U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 7207935384746719969U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9858803484150150915U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3612110001869385068U;
            aOrbiterB = RotL64((aOrbiterB * 2862887443435821143U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aCross, 26U) + aOrbiterG) + RotL64(aOrbiterA, 27U)) + aNonceWordG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterF, 21U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 18U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 13U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 40U) + RotL64(aOrbiterE, 60U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aNonceWordE) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 56U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + RotL64(aWandererA, 20U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22003U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 22319U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 22927U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25054U)) & S_BLOCK1], 52U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 11U)) + (RotL64(aCross, 26U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererK + RotL64(aCross, 27U)) + 14686411261024919129U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 7514582233957632005U;
            aOrbiterB = (aWandererH + RotL64(aScatter, 23U)) + 6520710480103365552U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 1983621978676188036U;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 18U)) + 9003524602590749672U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 6428568234045228995U;
            aOrbiterH = (aWandererB + RotL64(aCross, 47U)) + 8656552687136446989U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 37U)) + 16916248288415922490U;
            aOrbiterI = (aWandererI + RotL64(aCross, 41U)) + 9740237548002535784U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 5U)) + 907561000814618339U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 34U)) + 4751108900841197631U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 167774899400732287U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11907484918310854962U;
            aOrbiterB = RotL64((aOrbiterB * 7213139491146402985U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 14910318613649863924U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14882888155751455276U;
            aOrbiterD = RotL64((aOrbiterD * 11394136445442060201U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16175942562693781908U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 11022373758481651102U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 6836331461393816027U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12548405399045031548U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10850926364556828443U;
            aOrbiterA = RotL64((aOrbiterA * 16231561687709867431U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 13391684887911141790U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14648937281264822988U;
            aOrbiterG = RotL64((aOrbiterG * 6533299316940026059U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8298658887198526821U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13822977698661348891U;
            aOrbiterE = RotL64((aOrbiterE * 17769262972278410937U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7505646847564645719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3238749538197209166U;
            aOrbiterH = RotL64((aOrbiterH * 15394286542600778567U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15853506915123709257U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8426329899401071248U;
            aOrbiterI = RotL64((aOrbiterI * 1330397096577715113U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14848635392815613098U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 3549927798350175044U;
            aOrbiterJ = RotL64((aOrbiterJ * 1899044682313056949U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1798973117197750802U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 13056711228618953977U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9102877396419306689U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1395893547965799281U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 14686411261024919129U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17075377081365066067U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 34U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + RotL64(aOrbiterI, 24U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterH, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterH, 21U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterH, 18U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 29U)) + aOrbiterB);
            aWandererH = aWandererH ^ ((RotL64(aCross, 18U) + aOrbiterB) + RotL64(aOrbiterD, 27U));
            aWandererD = aWandererD + ((RotL64(aScatter, 43U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 10U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 47U)) + aOrbiterC) + aNonceWordO) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 35U)) + aOrbiterG) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 42U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31939U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28633U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31816U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31277U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCross, 29U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 43U)) + RotL64(aCarry, 11U)) + 5160910997561396461U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 57U)) + 14920764751058512062U;
            aOrbiterG = (aWandererJ + RotL64(aCross, 41U)) + 6080952401749660022U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 39U)) + 17667234330526298627U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 4U)) + 760630072638686756U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 35U)) + 3504157162816997476U) + aNonceWordD;
            aOrbiterK = ((aWandererI + RotL64(aIngress, 23U)) + 9489022223422585882U) + aPhaseFOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 27U)) + 1149898536879968964U;
            aOrbiterD = ((aWandererD + RotL64(aPrevious, 50U)) + RotL64(aCarry, 21U)) + 10492284328940025310U;
            aOrbiterA = (((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 13213275606286399312U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererE + RotL64(aIngress, 29U)) + 10557118912847180413U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15618980209023994776U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 5268600749854045564U;
            aOrbiterG = RotL64((aOrbiterG * 3849660559223919613U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8011552687609649990U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 3148133096349525066U;
            aOrbiterI = RotL64((aOrbiterI * 5245156554959620007U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12032847944237867285U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14999005703490824673U;
            aOrbiterC = RotL64((aOrbiterC * 6631584955208646049U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5426735969392906710U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 3593177531650386729U;
            aOrbiterK = RotL64((aOrbiterK * 12997284886192717043U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1701444719333347373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15928731228196894960U;
            aOrbiterE = RotL64((aOrbiterE * 1919318226904213433U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5960179456039157036U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 5716434224061596483U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3731976564761202801U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2136841536293340279U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 12969550408652728526U;
            aOrbiterA = RotL64((aOrbiterA * 7612191387451455137U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3641997570461447114U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4677572491523684525U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2730358077882211651U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2741372094325164504U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 4998631511811832690U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10619395395977372695U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 6260464862798783617U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16489087874167346533U;
            aOrbiterB = RotL64((aOrbiterB * 11278053967185244867U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 7043760915859224327U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5160910997561396461U;
            aOrbiterH = RotL64((aOrbiterH * 15260149870590431675U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterE, 53U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterF, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 6U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 19U));
            aIngress = aIngress + RotL64(aOrbiterG, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterA) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterH, 54U)) + aPhaseFWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterH, 57U)) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterI, 23U)) + aNonceWordJ);
            aWandererI = aWandererI + ((RotL64(aIngress, 48U) + aOrbiterF) + RotL64(aOrbiterA, 19U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterJ) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 27U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 10U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 34U) + aOrbiterJ) + RotL64(aOrbiterI, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererA, 20U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordC);
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

void TwistExpander_Archery_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 2784U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 7051U)) & W_KEY1], 10U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6263U)) & W_KEY1], 57U) ^ RotL64(mSource[((aIndex + 5231U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 13U) ^ RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 27U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererA + RotL64(aCross, 5U)) + 6381335981879993247U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 14U)) + 15595429101600023172U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 35U)) + 5449234297249826461U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 11213734849329731168U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 27U)) + RotL64(aCarry, 3U)) + 16438473952464514248U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 60U)) + 7357872882115186976U;
            aOrbiterE = ((aWandererI + RotL64(aIngress, 23U)) + 394402075160738643U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 11112941985410283532U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 51U)) + 14955125011182736212U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14770727009821304070U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 11286366598129204910U;
            aOrbiterA = RotL64((aOrbiterA * 15884310771003021989U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 7358400908565425780U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 15635109923749114761U;
            aOrbiterD = RotL64((aOrbiterD * 12415152149408700329U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13826842523738623579U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1072811298828325231U;
            aOrbiterF = RotL64((aOrbiterF * 9662800288646215083U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4017334196009350776U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8812213572751410831U;
            aOrbiterG = RotL64((aOrbiterG * 12744171921566782795U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 6723457786170634403U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 9785583533999417673U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7776915427605471097U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 10265132640322153964U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 8435670887514808087U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2706263045620662131U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4303823386961718326U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 4214384238167491037U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8490707334221154005U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8740835037840799136U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5988815405391206280U;
            aOrbiterB = RotL64((aOrbiterB * 17838555472135715929U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 15539461383052981747U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3743772525784217714U;
            aOrbiterJ = RotL64((aOrbiterJ * 6352086797545969187U), 47U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 24U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 19U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 20U) + aOrbiterB) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterF, 51U)) + aOrbiterC) + RotL64(aCarry, 35U)) + aPhaseCWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 43U)) + aOrbiterE) + aPhaseCWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 14U) + RotL64(aOrbiterI, 60U)) + aOrbiterG);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererE = aWandererE + ((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterE, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 47U));
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterE) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 12U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 9333U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 10034U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15393U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 8212U)) & W_KEY1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 37U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererD + RotL64(aScatter, 57U)) + 479672811032092393U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 18061121631394564425U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aWandererG + RotL64(aIngress, 48U)) + 14237400452740566065U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 6723123812257706134U;
            aOrbiterG = (aWandererF + RotL64(aScatter, 5U)) + 4247997188026499248U;
            aOrbiterB = (aWandererH + RotL64(aPrevious, 23U)) + 1939107415066134869U;
            aOrbiterA = ((aWandererK + RotL64(aCross, 53U)) + 3912640123546395979U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aIngress, 34U)) + 8295478436553964298U;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 29U)) + 3218960600711526885U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 5874096203353388890U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10294536533673023358U;
            aOrbiterF = RotL64((aOrbiterF * 15561710414949058923U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 11268561953904130747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16693201256788898423U;
            aOrbiterG = RotL64((aOrbiterG * 16291987237693567209U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7550969634681894654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 9501647424602245869U;
            aOrbiterA = RotL64((aOrbiterA * 11265865222096866605U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 8881869255994319423U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16770136406906800016U;
            aOrbiterH = RotL64((aOrbiterH * 1782039587385512923U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 16185384746435761363U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13841034186650721627U;
            aOrbiterC = RotL64((aOrbiterC * 12000155593277035447U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 15229062695864608309U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 3576122704615303733U;
            aOrbiterE = RotL64((aOrbiterE * 2433987493885779279U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13898167174453181224U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12878032061609524049U;
            aOrbiterJ = RotL64((aOrbiterJ * 18104665741338251495U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 12719156051299028649U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8640980843376950769U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10242616778390983333U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 12133332160916004365U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 8743563985229104484U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4575129690615054691U), 3U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 48U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterC, 57U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterH, 22U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterE, 51U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterG, 39U)) + aPhaseCWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterH, 27U));
            aWandererE = aWandererE + (((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 11U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 18U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 19878U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 23240U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20357U)) & W_KEY1], 57U) ^ RotL64(aKeyRowReadB[((aIndex + 20314U)) & W_KEY1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 5U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererB + RotL64(aScatter, 46U)) + RotL64(aCarry, 23U)) + 13583136155674166402U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 29U)) + 12830472187484919497U) + aPhaseCOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 3U)) + 18081197909484522509U;
            aOrbiterF = (aWandererD + RotL64(aIngress, 41U)) + 8680634051297891550U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 34U)) + RotL64(aCarry, 47U)) + 13939998767458656823U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 57U)) + 1795730579103692594U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aCross, 19U)) + 17369751719734069999U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 13U)) + 224769585901248068U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 4133547085925268180U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 7022512056309567391U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10319484359046945495U;
            aOrbiterB = RotL64((aOrbiterB * 3400140531307001933U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10483878349412282069U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 6481381149199985736U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9701719367082506253U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13721077228796934509U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 9704818014314175007U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 760445624027740287U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6253040047758584339U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 16890211690273641226U;
            aOrbiterI = RotL64((aOrbiterI * 5622534399866057841U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6216227831265032436U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2023609047004658739U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3252332895698310147U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9201669637050388263U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 5106927540934338576U;
            aOrbiterE = RotL64((aOrbiterE * 6368134569042291431U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10080368957861445998U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 10784789383436485808U;
            aOrbiterC = RotL64((aOrbiterC * 3794918350254445939U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 15426339824951793026U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17637144549368340331U;
            aOrbiterA = RotL64((aOrbiterA * 10971293914614704441U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9941300382181962134U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8118046374121322097U;
            aOrbiterD = RotL64((aOrbiterD * 8481945819050983127U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 34U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 60U) + aOrbiterC) + RotL64(aOrbiterB, 13U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterK, 3U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterH, 52U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterA, 39U));
            aWandererD = aWandererD + (((RotL64(aScatter, 52U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterC, 57U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterH, 22U)) + aOrbiterK) + aPhaseCWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 48U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 28U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30345U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27064U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29448U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((aIndex + 32176U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 19U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 10U)) + 2786079456995203065U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 57U)) + 7237256119153857253U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aCross, 19U)) + RotL64(aCarry, 23U)) + 9310834010563647604U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 29U)) + 17361734905706517877U) + aPhaseCOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 5U)) + 15837111231884647451U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 48U)) + RotL64(aCarry, 47U)) + 18065431964418026445U;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 37U)) + 3029123922999952652U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 41U)) + 5166926595573507837U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 57U)) + 1918425684273807598U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 4724551751012661440U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 1818014487579644390U;
            aOrbiterH = RotL64((aOrbiterH * 14904092108647864911U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6670090372241084216U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 8485757110007268693U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11876760095108618363U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 4928130251509514742U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 2528788422725346792U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1855982047967756661U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 2860387120895147503U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12927802338151379368U;
            aOrbiterG = RotL64((aOrbiterG * 8876144125458603029U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 18029699867733207083U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13361836994951253312U;
            aOrbiterK = RotL64((aOrbiterK * 5349767426256597073U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11957294454794128079U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3755417922063414648U;
            aOrbiterC = RotL64((aOrbiterC * 13896364063651241401U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 18001157153447913032U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 16214145724690286854U;
            aOrbiterA = RotL64((aOrbiterA * 5874139687703360515U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 3860958772090975562U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 12395621524459640173U;
            aOrbiterD = RotL64((aOrbiterD * 722817135977510161U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3402035664910754484U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2139099117325745602U;
            aOrbiterB = RotL64((aOrbiterB * 14008983756425796029U), 57U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 39U);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 26U));
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterI, 39U)) + aPhaseCWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 4U) + aOrbiterA) + RotL64(aOrbiterD, 28U));
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + RotL64(aOrbiterD, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 23U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 47U) + aOrbiterG) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterG, 5U)) + aOrbiterH) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 18U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + RotL64(aWandererH, 41U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Archery_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4130U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 6068U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1829U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneA[((aIndex + 240U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 20U)) + (RotL64(aCarry, 37U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aScatter, 47U)) + 15920462086654025436U;
            aOrbiterG = (aWandererI + RotL64(aCross, 39U)) + 487844076858004017U;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 51U)) + 14502883786442630566U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 11U)) + 3787107318658233674U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 28U)) + RotL64(aCarry, 29U)) + 12548777544693755491U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4907309444075181683U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 18342396700266492072U;
            aOrbiterA = RotL64((aOrbiterA * 14842961036061482089U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13503051997624242670U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 17845742460521374571U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1366356786138085155U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8640887211877858169U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5273913123709097537U;
            aOrbiterK = RotL64((aOrbiterK * 1661149444148461791U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 17756844173695563883U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6713055830729302951U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2832836748513174311U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5106468334224035972U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 10228769728713526172U;
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 37U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 11U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 37U)) + aOrbiterD);
            aWandererG = aWandererG + ((((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 46U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterD, 27U)) + aOrbiterK);
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterG, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + RotL64(aWandererG, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11485U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((aIndex + 9364U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 8829U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11197U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 11U)) ^ (RotL64(aCross, 36U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 29U)) + 16451272412693907816U;
            aOrbiterA = (((aWandererK + RotL64(aScatter, 37U)) + RotL64(aCarry, 3U)) + 10099485419723255462U) + aPhaseDOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 18U)) + 17668900099534923192U;
            aOrbiterC = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 19U)) + 5497093724143181753U) + aPhaseDOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 43U)) + 10354044773550071706U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 12728258851198019099U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 4144050505314242618U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13629477513971467419U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14133805325480076530U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 308863673210602899U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2672613556981540433U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11741180130160569753U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 12926863156769180448U;
            aOrbiterD = RotL64((aOrbiterD * 9726030996091054939U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 211920854786494259U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 13234608842479411078U;
            aOrbiterA = RotL64((aOrbiterA * 2556747209733759467U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9164711974854618892U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6667377062281954219U;
            aOrbiterC = RotL64((aOrbiterC * 2603737166987437649U), 57U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 4U) + RotL64(aOrbiterD, 13U)) + aOrbiterA) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 5U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + RotL64(aOrbiterC, 48U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 57U)) + aOrbiterA) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23031U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((aIndex + 20540U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21412U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17481U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (((aWandererA + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 9630214189402543339U) + aPhaseDOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aCross, 38U)) + RotL64(aCarry, 41U)) + 4072576573737526819U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aScatter, 21U)) + 15994787452709618869U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 11U)) + 6403240137132259482U;
            aOrbiterJ = ((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 10229266900170507720U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5025294577989748989U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16696461238217956883U;
            aOrbiterG = RotL64((aOrbiterG * 15993828976234917577U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9878318855341719119U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16086635438116177346U;
            aOrbiterK = RotL64((aOrbiterK * 5585682357395705671U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 12295437783084203730U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 7681150419912842402U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7289497379725191451U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 2639104034287637448U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 12298170009332243573U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9397919591171238575U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3485932317267669626U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16569551670038752475U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8139802826402217631U), 51U);
            //
            aIngress = RotL64(aOrbiterJ, 30U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 29U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 37U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 38U) + aOrbiterD) + RotL64(aOrbiterE, 21U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 53U) + aOrbiterD) + RotL64(aOrbiterJ, 56U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30628U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31306U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27166U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 32121U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 56U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 51U)) + 2177539223979303669U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 40U)) + 3962004686551521471U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 35U)) + 8457602312617147662U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 18011802451816510632U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 29U)) + 9046101759168876832U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 11135620637431969597U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15913029940697999701U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 646524659942693491U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16304193109948135982U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13208892298820080981U;
            aOrbiterC = RotL64((aOrbiterC * 15093751072618884859U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 4182377898949419225U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13970137023071326151U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9075061559681739865U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8402396284835248583U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 8859190834060657829U;
            aOrbiterK = RotL64((aOrbiterK * 13552418608113716117U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 9760005337757990392U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14108277760135744897U;
            aOrbiterI = RotL64((aOrbiterI * 4474681104256093885U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 13U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 38U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 46U) + aOrbiterC) + RotL64(aOrbiterI, 13U)) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 37U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 5U) + aOrbiterK) + RotL64(aOrbiterB, 21U));
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterK, 3U)) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 46U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Archery_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 7850U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 722U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4128U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 3574U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) + RotL64(aPrevious, 38U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 6381335981879993247U;
            aOrbiterG = (aWandererK + RotL64(aCross, 51U)) + 15595429101600023172U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 43U)) + RotL64(aCarry, 5U)) + 5449234297249826461U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 29U)) + RotL64(aCarry, 53U)) + 11213734849329731168U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 13U)) + 16438473952464514248U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 4U)) + 7357872882115186976U) + aPhaseEOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 57U)) + 394402075160738643U) + aPhaseEOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11112941985410283532U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 14955125011182736212U;
            aOrbiterB = RotL64((aOrbiterB * 10711684773326395603U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 14770727009821304070U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11286366598129204910U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15884310771003021989U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 7358400908565425780U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15635109923749114761U;
            aOrbiterK = RotL64((aOrbiterK * 12415152149408700329U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13826842523738623579U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 1072811298828325231U;
            aOrbiterD = RotL64((aOrbiterD * 9662800288646215083U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4017334196009350776U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8812213572751410831U;
            aOrbiterI = RotL64((aOrbiterI * 12744171921566782795U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 6723457786170634403U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9785583533999417673U;
            aOrbiterH = RotL64((aOrbiterH * 7776915427605471097U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10265132640322153964U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8435670887514808087U;
            aOrbiterG = RotL64((aOrbiterG * 2706263045620662131U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 51U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + RotL64(aOrbiterK, 5U)) + aOrbiterG) + RotL64(aCarry, 43U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 51U)) + aOrbiterH) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 21U)) + aOrbiterH);
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 40U)) + aOrbiterG);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterI, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 23U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 4U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 11419U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((aIndex + 14256U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 11988U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15370U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 42U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 41U)) + 5568146815535263910U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 47U)) + 7736084960873834666U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 19U)) + 1336413621817562093U) + aPhaseEOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 27U)) + 5218462026934984692U) + aPhaseEOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aCross, 13U)) + 7048890985969555935U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 13415955213864702118U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 27U)) + RotL64(aCarry, 13U)) + 5657023257021528548U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14338310943137497116U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 12305161641833950473U;
            aOrbiterI = RotL64((aOrbiterI * 11949964304435964395U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14514226578370459131U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12692904083266024340U;
            aOrbiterB = RotL64((aOrbiterB * 14800805065279908839U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 11012959130001327964U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7106471380403489078U;
            aOrbiterK = RotL64((aOrbiterK * 515626559384817223U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 3718101961355280891U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 13364192077222322664U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1411328915372590283U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6720867800318913440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 14497243926965866546U;
            aOrbiterA = RotL64((aOrbiterA * 13595058589060114653U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5789056168233262435U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 14438482587495779937U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10593535547917767263U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 313917798940179945U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 15241845511889502917U;
            aOrbiterF = RotL64((aOrbiterF * 16483477103771326107U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterI, 42U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterB, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 3U) + RotL64(aOrbiterB, 19U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterA, 11U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterE, 44U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 39U) + aOrbiterK) + RotL64(aOrbiterB, 5U));
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterD, 35U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 19087U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22619U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 22508U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((aIndex + 18450U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 10U)) ^ (RotL64(aIngress, 51U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 4622023259121087483U) + aPhaseEOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 13U)) + 10253505250223501352U;
            aOrbiterG = (aWandererB + RotL64(aScatter, 5U)) + 17133877904420462669U;
            aOrbiterF = ((aWandererD + RotL64(aCross, 41U)) + 6162827793741796700U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (aWandererE + RotL64(aIngress, 35U)) + 9610986424765907615U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 21U)) + 11210747154264753754U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 54U)) + RotL64(aCarry, 53U)) + 16554205219580654546U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10352576357413766388U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3651845783283479752U;
            aOrbiterG = RotL64((aOrbiterG * 1011289824180799641U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18145542190463500476U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 5415609566767162857U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6474184559323816389U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2033734872464201570U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 3507213117125813345U;
            aOrbiterK = RotL64((aOrbiterK * 5453058336688881113U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8716253393049851856U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 695984869565941856U;
            aOrbiterF = RotL64((aOrbiterF * 8377921610764044735U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 7661578828878284931U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 906654265099155956U;
            aOrbiterE = RotL64((aOrbiterE * 8117625377607536949U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6050049984731254612U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17882717590338190821U;
            aOrbiterI = RotL64((aOrbiterI * 10807367411402733215U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4996521991532815957U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 4246460672800604436U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12047466401960824903U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + RotL64(aOrbiterF, 53U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterE, 39U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 60U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 27U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterE, 5U));
            aWandererG = aWandererG + (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29721U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26915U)) & S_BLOCK1], 50U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27534U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 31694U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 18U)) + (RotL64(aPrevious, 47U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererC + RotL64(aIngress, 37U)) + 12311607308490066301U;
            aOrbiterI = (((aWandererK + RotL64(aScatter, 58U)) + RotL64(aCarry, 35U)) + 13100864684740679846U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 51U)) + 13697304189274329704U;
            aOrbiterC = (aWandererD + RotL64(aCross, 3U)) + 9047976902871216732U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 2147897579538537888U) + aPhaseEOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 2072444829390996142U;
            aOrbiterA = (aWandererG + RotL64(aCross, 29U)) + 2129307836981020908U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10663145333751112064U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 15019844390503785459U;
            aOrbiterF = RotL64((aOrbiterF * 7442321463110790449U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5460865577557928142U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15806522559993224197U;
            aOrbiterG = RotL64((aOrbiterG * 8722932687972240099U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6361113778657833389U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8306013884615042570U;
            aOrbiterI = RotL64((aOrbiterI * 8234258702656728667U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 4038420580499706912U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 11908091484457158973U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3964111175645156719U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11133912466611921250U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 2469227904206936928U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2704438771198001599U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13234017916788297295U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 9061117693840451988U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3637440416741459419U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12013423690843812324U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14371779015144617412U;
            aOrbiterA = RotL64((aOrbiterA * 3359568073302062667U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 51U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterD, 5U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 28U)) + aOrbiterG) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterF, 43U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
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

void TwistExpander_Archery_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4642U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3941U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3247U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((aIndex + 3220U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (((aWandererJ + RotL64(aCross, 48U)) + RotL64(aCarry, 5U)) + 6163290588946759209U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aIngress, 19U)) + 7342672468560105447U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 41U)) + 11574563167017282321U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 19U)) + 2254820206194758964U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 11U)) + 1469783447473099498U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14174828900676165088U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16277954291890598132U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4608888834164373691U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14845750668693136766U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 150099699692047766U;
            aOrbiterB = RotL64((aOrbiterB * 7644895634421086357U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 1200784917165131703U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9469982764806754302U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17851969334511301943U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10956702761701710182U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7915506894975487807U;
            aOrbiterK = RotL64((aOrbiterK * 8874108311712727983U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17335794183733623213U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 557028996286989506U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3993359298602424281U), 3U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 46U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 35U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterF, 48U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9802U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 12659U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10101U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((aIndex + 13111U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 57U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + 4751694786009671052U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 16362725160370844224U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 14U)) + RotL64(aCarry, 41U)) + 6360885380915941057U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 5154536007972297036U;
            aOrbiterJ = ((aWandererC + RotL64(aCross, 47U)) + 9362540581874808253U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13902493871525612934U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 10208452885367546542U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12067703239567933105U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3117030377279160998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 17286247690414027870U;
            aOrbiterJ = RotL64((aOrbiterJ * 4896931759653832095U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3930314320040949141U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 7289525252391668404U;
            aOrbiterI = RotL64((aOrbiterI * 15452162299105112187U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3434167955466809185U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17852573095128575663U;
            aOrbiterF = RotL64((aOrbiterF * 1485660158767033425U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6137259687928853253U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13992510605237574698U;
            aOrbiterA = RotL64((aOrbiterA * 15346263295995333395U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aPhaseFWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 42U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 13U) + aOrbiterJ) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererE, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16841U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 16723U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17968U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21713U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 29U)) + (RotL64(aCarry, 41U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 12980104182836602177U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 3172622203188863995U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aWandererD + RotL64(aIngress, 43U)) + 1170974132219980203U;
            aOrbiterH = ((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 47U)) + 6035201940965047490U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 29U)) + 18033907118424996722U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14604813424800580304U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13720232492851066035U;
            aOrbiterD = RotL64((aOrbiterD * 8927246214721284759U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 3902659710585257448U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8331560652661619868U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11418103770615560205U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4485014147538689794U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 168202636924512424U;
            aOrbiterF = RotL64((aOrbiterF * 13711020666131492091U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16227825670092707848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4792781933944671365U;
            aOrbiterH = RotL64((aOrbiterH * 15859849676231455283U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12636865372722601282U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 18198291399585556632U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18155803890313399795U), 13U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 37U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 40U) + RotL64(aOrbiterC, 13U)) + aOrbiterH) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterD, 4U)) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28658U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((aIndex + 32419U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25113U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25577U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCross, 43U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 5573188770530340913U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 27U)) + 1431772230889897111U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aCross, 19U)) + 4809192776429682319U;
            aOrbiterG = (((aWandererH + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 5576603692574369341U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 60U)) + RotL64(aCarry, 35U)) + 2720143226007220386U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 17220328778565331629U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 9629485808442089423U;
            aOrbiterB = RotL64((aOrbiterB * 18349580416082045015U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1136998437010390983U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 11893390497814523841U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5329621622743089531U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1764986431917532370U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1741014798007010376U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13414914086049500731U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12221368453236547044U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7694538641172350430U;
            aOrbiterD = RotL64((aOrbiterD * 8439120733670016501U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 17472344518811560603U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 3308740700728172984U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15290400462887712083U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 5U)) + aOrbiterD);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 50U)) + aOrbiterB) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererH, 34U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 43U);
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

void TwistExpander_Archery_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6190U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5433U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3559U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneD[((aIndex + 4469U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 785861751704720606U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 15968088718435606299U) + aPhaseGOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 57U)) + 1393976526590347151U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 13U)) + 17240750947292745884U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 22U)) + 4921576136163183137U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3334047873553153032U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 15086509978458408698U;
            aOrbiterC = RotL64((aOrbiterC * 2162818176367899893U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 892391205397581998U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2965686403183767521U;
            aOrbiterI = RotL64((aOrbiterI * 709160942482770225U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 14632215393655706170U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 15740589515342377322U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15677716942904794913U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11131164813943086445U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 6988080581278900960U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6412189142344044255U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 16021254613117657178U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 6183615599897921154U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9976411093264211033U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 22U) + RotL64(aOrbiterF, 21U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterC, 5U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aCarry, 11U)) + aPhaseGWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 60U)) + aOrbiterE);
            aWandererH = aWandererH + ((((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15719U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12300U)) & S_BLOCK1], 56U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8347U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 11342U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 60U)) + (RotL64(aCross, 11U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 5960680319644404115U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 3U)) + RotL64(aCarry, 11U)) + 16050752633567034185U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 28U)) + 8447503223226854741U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = (((aWandererG + RotL64(aIngress, 37U)) + RotL64(aCarry, 53U)) + 14176813813397917591U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 11U)) + 10534915376130006644U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6866224454375302514U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16506374165041008396U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1326855300197233833U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 7167814023968794098U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 13870852197416596664U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 17015971222069856463U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 18064038854848993105U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 9869630811507771691U;
            aOrbiterA = RotL64((aOrbiterA * 13723164383800461387U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 863613100452759380U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 16597969741225436529U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2680793528887208903U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6575347108051310653U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17062262265485019063U;
            aOrbiterK = RotL64((aOrbiterK * 7601045488473620019U), 27U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 5U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterI, 47U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 30U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 20U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 44U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 18219U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19070U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23246U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23589U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 56U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 29U) + RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 9446153639709651566U;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 10550762260670758167U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 58U)) + 7062634922142578383U;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 37U)) + RotL64(aCarry, 37U)) + 9178499097812764515U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 11U)) + 6887103379773525538U) + aPhaseGOrbiterAssignSaltD[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 6239750312052010257U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 17645022614523287959U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14448140327044053545U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 3639618183259408272U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3131737117548745095U;
            aOrbiterE = RotL64((aOrbiterE * 6585057380704940395U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7253994382396406554U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 15217993711938379561U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17853313384747259923U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12594152227603630033U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11250170200489647869U;
            aOrbiterB = RotL64((aOrbiterB * 546800378327864723U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 12936942656624279424U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 10990736056052106149U;
            aOrbiterC = RotL64((aOrbiterC * 7123916809953459187U), 29U);
            //
            aIngress = RotL64(aOrbiterG, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterB, 5U)) + aOrbiterC);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterE, 13U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD + (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 30U)) + aOrbiterH) + aPhaseGWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30461U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29860U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28452U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31005U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 54U)) ^ (RotL64(aCarry, 11U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 39U)) + 3973833383430652211U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 30U)) + RotL64(aCarry, 23U)) + 5760227042747169187U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 5U)) + 4923009065139227286U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 39U)) + 1477807307009107590U) + aPhaseGOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aCross, 21U)) + 5707194514329007301U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 5340439728375269724U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 17080457898946572387U;
            aOrbiterF = RotL64((aOrbiterF * 17719588880215414933U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 281559150259472813U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16160633048230910560U;
            aOrbiterE = RotL64((aOrbiterE * 16883442583309073785U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9003989610509592121U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10579322462808454333U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 100832431598087235U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 15059383289528723069U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10417647757852880956U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1457919230286043137U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14484665027393813330U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12344463053485837974U;
            aOrbiterD = RotL64((aOrbiterD * 5762654194001525041U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 11U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererD = aWandererD + (((RotL64(aIngress, 56U) + RotL64(aOrbiterD, 29U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterE, 21U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 6U)) + aOrbiterF) + aPhaseGWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 48U);
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

void TwistExpander_Archery_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 2141U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 7222U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 252U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneD[((aIndex + 3614U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) + RotL64(aCarry, 42U)) ^ (RotL64(aCross, 29U) ^ RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 53U)) + 13333509828310369865U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 4U)) + RotL64(aCarry, 51U)) + 7645352517103840797U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 21U)) + 5310766306660062655U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 39U)) + 5165635069832352932U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 23U)) + 15684141764734281849U) + aPhaseHOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 3327963374225061738U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8625811794878848871U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16327750494894125333U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 7598657468430485291U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 2881171216276746485U;
            aOrbiterD = RotL64((aOrbiterD * 3331350584102843605U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10237691227222918101U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 6419254255884834497U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3816625473642865305U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 4238455444646479956U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 14936613353493061492U;
            aOrbiterK = RotL64((aOrbiterK * 3544216916806292273U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 15324699725208372627U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9506640480601832011U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12819564111348390227U), 35U);
            //
            aIngress = RotL64(aOrbiterJ, 37U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 26U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aIngress, 46U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + aOrbiterG) + RotL64(aOrbiterD, 43U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + RotL64(aOrbiterJ, 51U)) + aOrbiterH) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + RotL64(aWandererI, 21U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 14940U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14382U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12911U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 8712U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 38U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 3U)) + 12809562813316740345U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 17084212535326321199U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 16074921689983846769U;
            aOrbiterE = (((aWandererI + RotL64(aCross, 26U)) + RotL64(aCarry, 11U)) + 14027986153007120145U) + aPhaseHOrbiterAssignSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 57U)) + 7633455951809250227U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 340989348513370174U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5307820377645020116U;
            aOrbiterB = RotL64((aOrbiterB * 8402492604131262157U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 5605285015771527274U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5293500434746182790U;
            aOrbiterD = RotL64((aOrbiterD * 17674669610895537063U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7263156475892261811U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10672879570907433005U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2506338667179450741U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16659226780900986107U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9774892622769850665U;
            aOrbiterF = RotL64((aOrbiterF * 7487477727543183211U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10728057184108279042U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5032485856947407217U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16651577903809154285U), 13U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterD, 18U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterE, 41U)) + aOrbiterB);
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterF) + RotL64(aOrbiterE, 21U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 52U) + RotL64(aOrbiterD, 53U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + RotL64(aOrbiterH, 30U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 20587U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17214U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23470U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneB[((aIndex + 22954U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 53U)) + (RotL64(aCarry, 22U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = ((aWandererK + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 17074147006464019918U;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 21U)) + 10559516626129419928U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 3U)) + 13280363679503946221U;
            aOrbiterB = ((aWandererG + RotL64(aCross, 30U)) + RotL64(aCarry, 21U)) + 17657115422132457413U;
            aOrbiterG = (((aWandererI + RotL64(aScatter, 43U)) + RotL64(aCarry, 35U)) + 13325837013304973008U) + aPhaseHOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 3059707750486106037U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 4529045702503050852U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12889277842182219673U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 10726578475550904292U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 14832537837996659885U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 808060368961520519U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 220094417441809246U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 15343130035105342194U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7984652435043810845U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 16592263353426409884U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15649290906447931918U;
            aOrbiterB = RotL64((aOrbiterB * 8405875177836650731U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11437410545843708269U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5859769136073011444U;
            aOrbiterG = RotL64((aOrbiterG * 1065016088086441107U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 36U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 28U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseHWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterK, 53U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 51U) + aOrbiterA) + RotL64(aOrbiterH, 18U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererD, 38U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 27574U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29402U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26793U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31148U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 35U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 43U)) + 5480870806135400132U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 21U)) + 8034874599430768743U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 3U)) + 4006919843736863767U) + aPhaseHOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 2988069748674633718U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 58U)) + 12347295651973135786U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14152683894431568192U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 15765143815254196598U;
            aOrbiterE = RotL64((aOrbiterE * 8948877544291035189U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 10473067082331244233U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1089466925383677249U;
            aOrbiterG = RotL64((aOrbiterG * 17334888609179149753U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 13215039929873682230U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 3957997712247961479U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7631186240013784703U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 10023907397941685546U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14593012591254614353U;
            aOrbiterF = RotL64((aOrbiterF * 17111300092082154687U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 13353797968154036726U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9259966668512102858U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8326732574268308221U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 4U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterH, 48U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 37U)) + aOrbiterF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 58U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererA, 19U);
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
