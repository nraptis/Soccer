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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x955F06348D22AECDULL + 0xAF60D1EC9879BC65ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x878FC8F77A71576FULL + 0xD6E5590A091B0E29ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA98F161285F179F7ULL + 0xF64925BCAF0F2C96ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xD632BD2C95515219ULL + 0xB16848CDF791975FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFA65937EF0C8B92BULL + 0x9DB05B2A675CEE5DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xCBEF3B1614E783DFULL + 0xB5D4BC785E948B5CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8CD2BE8FDE4B2451ULL + 0x9612DD3E0983E162ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA094756BE8A98C15ULL + 0x855F2521262C5138ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA46556AA6436DD15ULL + 0xA1B6275A76B5020BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xD5B6FD7362E45C0DULL + 0xC982D40FC5B8949CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAE6FAE38315062D9ULL + 0xD467CB5D888AFCF8ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x84FE70D51FFF286DULL + 0xA2C784D393E5F437ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA98BBE8FBD5CFBF9ULL + 0xFA309122DF8DA7A2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC35C265C67650329ULL + 0x9D6B17DFCA018E09ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFAE4A433D995B6ABULL + 0x90C50EDE196065FEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE4CFBDA5590A44DFULL + 0xE48B46AA650B8865ULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 5437U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((aIndex + 4603U)) & S_BLOCK1], 46U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 5226U)) & S_BLOCK1], 18U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 3906U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 24U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 58U)) + 5568146815535263910U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 29U)) + 7736084960873834666U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 1336413621817562093U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 39U)) + RotL64(aCarry, 3U)) + 5218462026934984692U) + aOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 44U)) + 7048890985969555935U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 11U)) + 13415955213864702118U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 5U)) + 5657023257021528548U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 37U)) + 14338310943137497116U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 51U)) + 12305161641833950473U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 53U)) + RotL64(aCarry, 51U)) + 14514226578370459131U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 41U)) + 12692904083266024340U) + aNonceWordG;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 11012959130001327964U) + aNonceWordL;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7106471380403489078U;
            aOrbiterC = RotL64((aOrbiterC * 515626559384817223U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 3718101961355280891U) + aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13364192077222322664U;
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6720867800318913440U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14497243926965866546U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13595058589060114653U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5789056168233262435U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 14438482587495779937U) ^ aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10593535547917767263U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 313917798940179945U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15241845511889502917U;
            aOrbiterA = RotL64((aOrbiterA * 16483477103771326107U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3591957424821693032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1559050939014453558U;
            aOrbiterE = RotL64((aOrbiterE * 17933346117866604725U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15340590914441451383U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5538037287390050110U;
            aOrbiterB = RotL64((aOrbiterB * 4082576643144951473U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 4151270491894969214U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 263593701314144898U;
            aOrbiterF = RotL64((aOrbiterF * 10372046955804512457U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9025145270653080646U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6867950904094870056U;
            aOrbiterJ = RotL64((aOrbiterJ * 9975247022340627751U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3183454301841252109U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3054904157641290615U;
            aOrbiterG = RotL64((aOrbiterG * 4092317552439599475U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 1768555574434776135U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5568146815535263910U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12466957001078663927U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 23U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 30U));
            aIngress = aIngress + (RotL64(aOrbiterH, 27U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 44U)) + aOrbiterK) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 34U) + aOrbiterI) + RotL64(aOrbiterA, 29U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterA) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterF, 3U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterI, 6U)) + aOrbiterD) + aNonceWordE);
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 37U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterF, 23U));
            aWandererH = aWandererH + ((RotL64(aScatter, 56U) + RotL64(aOrbiterC, 51U)) + aOrbiterA);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterC, 13U));
            aWandererF = aWandererF + (((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9800U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 7107U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 9700U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10346U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 53U) ^ RotL64(aPrevious, 26U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 44U)) + RotL64(aCarry, 43U)) + 15904465836916519864U;
            aOrbiterA = ((aWandererD + RotL64(aCross, 23U)) + 17725629806317789307U) + aOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 57U)) + 13794170125914914828U) + aNonceWordC;
            aOrbiterE = (aWandererB + RotL64(aScatter, 41U)) + 2149055907476874332U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 13U)) + 5342047776745074649U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 39U)) + 8268148484060546838U;
            aOrbiterD = ((aWandererC + RotL64(aCross, 29U)) + RotL64(aCarry, 37U)) + 10821151364028563719U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 37U)) + 4294213820894407378U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 54U)) + 10884726101307943090U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 3U)) + 16432210042202444824U;
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 13U)) + 15196602644336228055U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14117787670220328165U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 219833877949480215U;
            aOrbiterG = RotL64((aOrbiterG * 10736293047771972173U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3326396981881473962U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14918513066311426279U;
            aOrbiterA = RotL64((aOrbiterA * 14269763278564574663U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11795234681370163206U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 3068267285352664813U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15746255933920904619U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterF) + 245233356957999496U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 709926406353796673U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 13627039596842073595U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5378105439430271038U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 10114555061122044430U) ^ aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5351295043424885549U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 13233010815716769713U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8231291294833548389U;
            aOrbiterB = RotL64((aOrbiterB * 10840516135212753869U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 7160760224172419829U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14767926435411546785U;
            aOrbiterE = RotL64((aOrbiterE * 1643485739468851073U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4464245330038080103U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15778166658285494712U;
            aOrbiterI = RotL64((aOrbiterI * 13980891936095282989U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2426340576450960905U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 6030631392508241438U;
            aOrbiterC = RotL64((aOrbiterC * 13921288910299408423U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 15990180955119402476U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 8707879851984546959U;
            aOrbiterH = RotL64((aOrbiterH * 13794027045755532979U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11665969506971636052U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15904465836916519864U;
            aOrbiterJ = RotL64((aOrbiterJ * 17042355185093585101U), 53U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 21U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 42U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 43U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aScatter, 42U) + RotL64(aOrbiterB, 27U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 6U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 41U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterJ, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 37U)) + aOrbiterG) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 60U)) + aOrbiterF) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterC, 23U)) + aNonceWordG);
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 40U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 42U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14221U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 13104U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 16358U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((aIndex + 11222U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 37U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererH + RotL64(aCross, 10U)) + 9471546960258473684U) + aOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aScatter, 41U)) + RotL64(aCarry, 29U)) + 18050235435948942244U;
            aOrbiterA = (aWandererK + RotL64(aPrevious, 53U)) + 3005107102671544641U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 27U)) + RotL64(aCarry, 41U)) + 17898396434573801850U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 35U)) + 15071602525497771648U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 57U)) + 5780119462702672108U;
            aOrbiterK = (aWandererJ + RotL64(aIngress, 21U)) + 13301326224151025687U;
            aOrbiterI = (aWandererG + RotL64(aCross, 29U)) + 18129323022260575961U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 23U)) + 1199228670638790709U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 38U)) + 1839199978088021020U;
            aOrbiterC = (((aWandererB + RotL64(aCross, 23U)) + 4999517042246790165U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8788607633376516299U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 15143903839930468749U;
            aOrbiterA = RotL64((aOrbiterA * 12735914889325422675U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 16674732686428431869U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 15908873150953195581U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 18049755517524334107U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11204775359756474667U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2525984309543939465U;
            aOrbiterD = RotL64((aOrbiterD * 3988529812023791571U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 4566345170476825512U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14876612901557406267U;
            aOrbiterG = RotL64((aOrbiterG * 9047956948845135339U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14926290877038883931U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12710203178186614846U;
            aOrbiterI = RotL64((aOrbiterI * 14841163494801662515U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 7315094513967387996U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11050116830482816766U;
            aOrbiterE = RotL64((aOrbiterE * 3702999495721152019U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4505368486032503953U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterH) ^ 17905748055257551092U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 14775870175093453197U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5728886950801376350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17998141690182325170U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 16008599930125391379U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4325978018819134558U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13526905108565989379U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14121321495714166291U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 10597169665474269506U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 7500801022830471869U;
            aOrbiterJ = RotL64((aOrbiterJ * 3702717219742363777U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 17063616328548689935U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9471546960258473684U;
            aOrbiterC = RotL64((aOrbiterC * 3029748230803396737U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 11U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterF, 37U));
            aWandererC = aWandererC + ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 46U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 56U) + aOrbiterE) + RotL64(aOrbiterB, 13U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 35U)) + aNonceWordM);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 11U) + aOrbiterA) + RotL64(aOrbiterB, 19U)) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 4U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterJ, 21U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 46U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17984U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 17786U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19424U)) & S_BLOCK1], 48U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 17049U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 4U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aCross, 39U)) + 3684295017013759987U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 37U)) + 6740408842457292881U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 44U)) + 4563975890702399441U) + aNonceWordB;
            aOrbiterE = (aWandererA + RotL64(aIngress, 47U)) + 797804144825287940U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 2763779540450101303U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 41U)) + 13211846164102089685U;
            aOrbiterB = (((aWandererD + RotL64(aCross, 12U)) + 15214578447281401982U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = (aWandererK + RotL64(aIngress, 29U)) + 13745208628754232427U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 21U)) + 17358621225969190747U;
            aOrbiterI = ((aWandererC + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 779739369960480023U;
            aOrbiterF = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 4370963533701407813U) + aNonceWordK;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6061333005507739975U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3589705340762734456U;
            aOrbiterH = RotL64((aOrbiterH * 16499293983611196967U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 10607697666369230567U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9356757995305239271U;
            aOrbiterC = RotL64((aOrbiterC * 10945513661439954731U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 10093033335903048138U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 11037328061699834100U;
            aOrbiterD = RotL64((aOrbiterD * 11189760551792389605U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 558431161176115540U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 17795680919453449358U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3910117359996283803U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 6096779391116214109U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 17594243286880690775U;
            aOrbiterK = RotL64((aOrbiterK * 12655610181937429915U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 15414704802398002423U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18040588240488602196U;
            aOrbiterJ = RotL64((aOrbiterJ * 16344249573086571225U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14636298592697156931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9677305688594936561U;
            aOrbiterI = RotL64((aOrbiterI * 8354776999961642997U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 16408025751875050713U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 10018342878801454965U;
            aOrbiterF = RotL64((aOrbiterF * 10349132962708124117U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1841090936357114866U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16142637455878447020U;
            aOrbiterG = RotL64((aOrbiterG * 10565394571714418033U), 47U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterF) + 4089676582910615502U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8749600984499831109U;
            aOrbiterA = RotL64((aOrbiterA * 3421055105090316521U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 11408932421005107097U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3684295017013759987U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7037953759624065417U), 21U);
            //
            aIngress = RotL64(aOrbiterH, 38U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 60U)) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aPrevious, 60U) + aOrbiterB) + RotL64(aOrbiterE, 23U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 21U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterB) + RotL64(aOrbiterF, 44U)) + aNonceWordD);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 35U) + aOrbiterA) + RotL64(aOrbiterC, 57U)) + aWandererUpdateSaltB[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 18U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 51U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 41U)) + aOrbiterJ) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterE);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 13U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 6U));
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 50U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 26605U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 24336U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22386U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneA[((aIndex + 25512U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 24U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 57U) ^ RotL64(aCarry, 43U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 3U)) + 16189787374324972735U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 51U)) + 17563763730956242224U) + aOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 58U)) + 10572803498593789385U) + aNonceWordM;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 35U)) + 7713105232072974166U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 29U)) + 10760839534772718139U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 47U)) + RotL64(aCarry, 35U)) + 13397069448391230253U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 41U)) + 4569255679998375682U;
            aOrbiterK = (aWandererD + RotL64(aCross, 19U)) + 9888769350817876949U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 11U)) + 11351796060878856300U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 56U)) + RotL64(aCarry, 21U)) + 18153775071965707204U;
            aOrbiterB = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 1282846411145853435U) + aOrbiterAssignSaltE[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16457743979262460660U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 173493260775251032U;
            aOrbiterA = RotL64((aOrbiterA * 4935807229040883505U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3927345926316409630U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5158769729850853623U;
            aOrbiterF = RotL64((aOrbiterF * 2446452358663812945U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12331351600010165154U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3940794200348684050U) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 13248997263062075043U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 11248514843822945425U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 1391497323278226522U;
            aOrbiterD = RotL64((aOrbiterD * 8376841806072565005U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13265623528678787307U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 2802033745265647317U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3437626962562016147U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 6938444301018051844U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1086544666755559028U;
            aOrbiterH = RotL64((aOrbiterH * 16039728388882079889U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 16156443117365816536U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3619942859562697142U;
            aOrbiterC = RotL64((aOrbiterC * 7589346043159112151U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 17681848914912743292U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8848238631758130416U;
            aOrbiterI = RotL64((aOrbiterI * 810402256099500607U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 6019192027793541890U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16917288363166352778U;
            aOrbiterB = RotL64((aOrbiterB * 17673667086593738207U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 5598218150530046752U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17285995539011279010U;
            aOrbiterE = RotL64((aOrbiterE * 15621233176885995065U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 12380627610747299268U) + aNonceWordI;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16189787374324972735U) ^ aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2144714828503219209U), 57U);
            //
            aIngress = RotL64(aOrbiterH, 11U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 20U));
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 53U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aNonceWordH);
            aWandererE = aWandererE + (((((RotL64(aCross, 23U) + RotL64(aOrbiterG, 35U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aNonceWordP) + aWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 42U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aNonceWordE);
            aWandererA = aWandererA + (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterE, 47U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 26U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aCross, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterI);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterI, 3U)) + aWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 57U)) + aOrbiterK);
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterC, 20U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 41U));
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + RotL64(aWandererG, 18U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28468U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29169U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 27832U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 30011U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 37U) ^ RotL64(aIngress, 24U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aPrevious, 53U)) + 77518479758428414U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 51U)) + 4832061802166300011U) + aNonceWordB;
            aOrbiterD = (aWandererD + RotL64(aCross, 43U)) + 11695291171006574112U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 41U)) + 7467412817843260094U;
            aOrbiterH = (aWandererH + RotL64(aPrevious, 24U)) + 17801484124471154757U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 27U)) + 5555455638503958639U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 5669470540733721606U) + aOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 3042388456327784163U;
            aOrbiterC = (aWandererE + RotL64(aPrevious, 13U)) + 2236734925228156691U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 56U)) + 14459720401528685450U) + aNonceWordF;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 4814967631216658856U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 16950679344449075945U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6262238639302011050U;
            aOrbiterD = RotL64((aOrbiterD * 9942659897425088183U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3522256359074996724U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 12524717897707074242U;
            aOrbiterH = RotL64((aOrbiterH * 6787771338063891989U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 13891759914865623828U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11910250571469028666U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12311343917878428995U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2240189915640314069U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 5365912986308810837U;
            aOrbiterK = RotL64((aOrbiterK * 15133972552032469957U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 9323732721344489753U) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13087326560957916553U;
            aOrbiterI = RotL64((aOrbiterI * 14659491687401151733U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16398238057564892809U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11517870519285159224U;
            aOrbiterC = RotL64((aOrbiterC * 1501848878469712681U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 7758285512254776734U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 17475149091906684720U;
            aOrbiterB = RotL64((aOrbiterB * 6015816725428299273U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2051631493975035243U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 11684740065349595315U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10918975496337269197U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10575473798991451167U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8267005776169272822U;
            aOrbiterE = RotL64((aOrbiterE * 13166868678285963961U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 6249698995716039231U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13808085811784323978U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 3897731011582061983U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2739364646624876985U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 77518479758428414U;
            aOrbiterF = RotL64((aOrbiterF * 6977724811175035551U), 35U);
            //
            aIngress = RotL64(aOrbiterA, 5U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 56U) + RotL64(aOrbiterG, 41U)) + aOrbiterD);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterC) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 5U)) + aOrbiterB) + aWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aScatter, 30U) + aOrbiterC) + RotL64(aOrbiterK, 34U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterE);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterK, 56U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordF);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x8C486758D411D6CFULL + 0xF8EC1EEEA331DC76ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDCD9C1DA6DF56B61ULL + 0xD812B70F26399E80ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBC06FD471529E959ULL + 0xBBBEC255C092493AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x9630F5684906B45DULL + 0x8FF547BE1F74630BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xBC30B619303E7AFFULL + 0xB1A3C1762EB41430ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xB57E3951A25A455DULL + 0xD5A8C310543D13D2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x95B600E09D62B3A5ULL + 0xA346454D630E1B5BULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB0DFBF7B63A44EE7ULL + 0x948419B565DC17C5ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD9CE7E2F0A901A95ULL + 0x94EB0D38C0061F2AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xB32D4BE3211271A7ULL + 0x98004D83B79BAF94ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x890F05C86B04C8F7ULL + 0xC592443B65B4CC11ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF9FA13B9FAF297FBULL + 0xBDA398E6A926A77AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9E55485E6A5B158DULL + 0xA3AF2C767B8C3F7EULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB8509B111500DAABULL + 0xB2E9A7476AA2C897ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xEB7C32A480907EFFULL + 0x9F81659B1E92A596ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB0C54F4E7E769909ULL + 0x8EE7B8890E4F4D68ULL);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 6807U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6914U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4482U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 6300U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 14U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 53U)) + RotL64(aCarry, 43U)) + 12690502671561165478U) + aNonceWordM;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 48U)) + 17519943923428102801U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 10705515807975331385U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 21U)) + 16586447272278538179U;
            aOrbiterC = (aWandererD + RotL64(aCross, 19U)) + 8006560996840971798U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 28U)) + 12928600185788857701U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 23U)) + 14240723153798267172U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 3U)) + 8636219177994872072U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 43U)) + 7586790235186467512U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1103807034179512424U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 7547526530239498693U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3360295583636013509U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8380239679344786397U) + aOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5690809173787433519U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 5354724308093372953U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8390902801141804609U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 3507306189192059486U;
            aOrbiterD = RotL64((aOrbiterD * 18336280496510253103U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6190745292098482871U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 8065418693975056902U;
            aOrbiterH = RotL64((aOrbiterH * 6414621418430102589U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12111755051718111803U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 7605877769709909297U;
            aOrbiterJ = RotL64((aOrbiterJ * 17525248694315944599U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5969794501112646237U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 5127559299360591476U;
            aOrbiterK = RotL64((aOrbiterK * 4521563633438853069U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 10593847754747739786U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4401750688524310121U;
            aOrbiterB = RotL64((aOrbiterB * 14265829318976633707U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 6927893132508779499U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4874009978647014479U;
            aOrbiterF = RotL64((aOrbiterF * 13340466017023540755U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13146693487138744677U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 3298472134223595298U) ^ aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2145005258008477281U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 42U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterD, 11U));
            aWandererK = aWandererK + (((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterF, 19U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 6U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterK, 41U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 47U)) + aOrbiterH) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + aNonceWordG);
            aWandererD = aWandererD + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 36U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 34U) + RotL64(aOrbiterE, 23U)) + aOrbiterB) + aWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 56U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 15515U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9730U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 14223U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 9390U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCross, 39U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 27U)) + RotL64(aCarry, 5U)) + 16189787374324972735U) + aOrbiterAssignSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aScatter, 23U)) + 17563763730956242224U) + aNonceWordK;
            aOrbiterC = ((aWandererA + RotL64(aCross, 18U)) + RotL64(aCarry, 47U)) + 10572803498593789385U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 39U)) + 7713105232072974166U) + aOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 47U)) + 10760839534772718139U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 43U)) + 13397069448391230253U;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 60U)) + RotL64(aCarry, 57U)) + 4569255679998375682U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 35U)) + 9888769350817876949U;
            aOrbiterD = (aWandererB + RotL64(aCross, 3U)) + 11351796060878856300U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 18153775071965707204U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1282846411145853435U;
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16457743979262460660U) + aNonceWordC;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 173493260775251032U) ^ aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4935807229040883505U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3927345926316409630U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 5158769729850853623U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 2446452358663812945U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 12331351600010165154U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3940794200348684050U;
            aOrbiterH = RotL64((aOrbiterH * 13248997263062075043U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11248514843822945425U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1391497323278226522U;
            aOrbiterD = RotL64((aOrbiterD * 8376841806072565005U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 13265623528678787307U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2802033745265647317U;
            aOrbiterF = RotL64((aOrbiterF * 3437626962562016147U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 6938444301018051844U) + aNonceWordP;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1086544666755559028U;
            aOrbiterK = RotL64((aOrbiterK * 16039728388882079889U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16156443117365816536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3619942859562697142U;
            aOrbiterA = RotL64((aOrbiterA * 7589346043159112151U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 17681848914912743292U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8848238631758130416U;
            aOrbiterG = RotL64((aOrbiterG * 810402256099500607U), 47U);
            //
            aIngress = RotL64(aOrbiterK, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 10U));
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 23U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 40U) + aOrbiterF) + RotL64(aOrbiterG, 47U)) + aNonceWordL);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterA, 4U)) + aWandererUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 35U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 41U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 35U) + RotL64(aOrbiterI, 18U)) + aOrbiterG) + aNonceWordA);
            aWandererI = aWandererI ^ ((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterK, 53U));
            aWandererF = aWandererF + ((((RotL64(aScatter, 10U) + aOrbiterJ) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 27U)) + aWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 56U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 17944U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21169U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17486U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22705U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 39U)) + (RotL64(aIngress, 52U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 29U)) + 4970414922752555648U;
            aOrbiterI = (((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 13U)) + 9462756592787669327U) + aNonceWordE;
            aOrbiterF = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 21U)) + 3948790686662213095U;
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 4U)) + 14542857212241578311U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 51U)) + 3387479009827029547U;
            aOrbiterK = (aWandererE + RotL64(aScatter, 13U)) + 1411421370057797877U;
            aOrbiterH = (aWandererB + RotL64(aIngress, 19U)) + 16894451466895681236U;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 12727136462290223542U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 36U)) + 4625389198191960525U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3471881403786164913U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 6433115856048534831U;
            aOrbiterF = RotL64((aOrbiterF * 9363233870194144053U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9825592965466157982U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1553125767261293088U;
            aOrbiterA = RotL64((aOrbiterA * 411535191177308781U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9951616357109647617U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11231080382787286889U;
            aOrbiterJ = RotL64((aOrbiterJ * 14024961994986659187U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13419663264017317947U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4835055642466215566U) ^ aNonceWordK;
            aOrbiterI = RotL64((aOrbiterI * 17898065852351759171U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14558747666410946768U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13120938960926874504U;
            aOrbiterD = RotL64((aOrbiterD * 5681766019285559739U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11910501376797343986U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15074100100781785300U;
            aOrbiterK = RotL64((aOrbiterK * 228976960937473851U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12415377930578091821U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 14882039078390681802U) ^ aOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13855446647753150713U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8094338361713756895U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5478280604704108822U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18062931724700600993U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 6977017654546871841U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 4131602217285988962U;
            aOrbiterC = RotL64((aOrbiterC * 11865422227883712419U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 6U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 52U) + RotL64(aOrbiterH, 14U)) + aOrbiterK);
            aWandererK = aWandererK + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterB, 37U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterA, 21U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterD, 5U));
            aWandererD = aWandererD + (((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aCross, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 48U)) + aNonceWordM) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 11U);
            aCarry = aCarry + RotL64(aIngress, 40U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27890U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28258U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29929U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneD[((aIndex + 26633U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererH + RotL64(aScatter, 27U)) + 12426357877879529292U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 10U)) + 12604900366173639176U;
            aOrbiterG = (aWandererI + RotL64(aPrevious, 35U)) + 13511119007338929401U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 21U)) + 9878720081166788060U) + aNonceWordN;
            aOrbiterE = (((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 15463195409806395076U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 41U)) + 6407922778852833423U) + aNonceWordE;
            aOrbiterH = (aWandererE + RotL64(aIngress, 5U)) + 7690427254160734016U;
            aOrbiterI = (aWandererB + RotL64(aCross, 43U)) + 18030974031722143619U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 39U)) + 17983938038322737041U) + aOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterD) + 16605512170117753884U) + aOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 681802273302348322U;
            aOrbiterG = RotL64((aOrbiterG * 14608920184802647123U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15550312921312083819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17824154101711884508U;
            aOrbiterE = RotL64((aOrbiterE * 7358612830654795357U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 1939207786756735430U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3132864634777826569U;
            aOrbiterH = RotL64((aOrbiterH * 13606281919426730325U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12822929773923954849U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 16576106045887115660U;
            aOrbiterF = RotL64((aOrbiterF * 16370914370769903051U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2398825881649235260U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 13700821892926092479U) ^ aOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10830623703416956043U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 2439833784883391606U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 15870638514107637833U;
            aOrbiterB = RotL64((aOrbiterB * 3797380922767479287U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 9165457123134229670U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8736642509192659417U;
            aOrbiterI = RotL64((aOrbiterI * 16219277537523484065U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9232719746484835693U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 7826680628853322541U;
            aOrbiterA = RotL64((aOrbiterA * 12578050118133526187U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14323652326982518782U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 2254524512851399313U) ^ aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4119339547645451149U), 47U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 14U));
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 51U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterG, 4U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aIngress, 42U) + aOrbiterJ) + RotL64(aOrbiterG, 39U)) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterG, 43U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterB, 29U)) + aOrbiterE) + aWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 23U) + aOrbiterI) + RotL64(aOrbiterB, 47U)) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 53U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 57U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 60U) + aOrbiterJ) + RotL64(aOrbiterF, 22U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordB;
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9D19739522133E67ULL + 0xF8F8924F1D53DD38ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCBA283B0AF5ECCAFULL + 0xAF162C385BE19076ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xEFD41A1B77EF0D0DULL + 0xBA4CDFCED7EBAF45ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEB1827833E3A5E41ULL + 0xCF6BD4C6B3324988ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA1C5D8683C05F635ULL + 0xF91C158155BBC9EBULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB095D9998212368BULL + 0xF54D302411A6AE27ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xDBC12512AFF5AF2FULL + 0x8D82F9BF7D3FB9F8ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA1BB04D92B939F69ULL + 0xCCE29D3CAED2F367ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDA44DCA67E5FFEB3ULL + 0xC70FBA13F1740071ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x84E43A97DEB5B8F1ULL + 0xD77AE95521E547F6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF8010765B02D7755ULL + 0xFCE7E64200672ADEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x87C04FD64069C60DULL + 0xCC5788D0B3A19163ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB88A20F6D86C9CC3ULL + 0xB31678A945765BCBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD97B1845A70BC685ULL + 0xD290C483B0DF89A8ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x83BB24688328138BULL + 0xEE2EC4AC9A46A0B0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC7F02348AE9E6E59ULL + 0xC8DC13CD726C63A2ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6294U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneC[((aIndex + 668U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3079U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1367U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) ^ RotL64(aCross, 57U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 28U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererI + RotL64(aIngress, 30U)) + RotL64(aCarry, 39U)) + 898812731947995389U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 57U)) + 8677347622525527167U) + aNonceWordD;
            aOrbiterF = ((aWandererF + RotL64(aCross, 39U)) + 770321564027567654U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 11020474858081526395U) + aNonceWordA;
            aOrbiterH = (aWandererA + RotL64(aScatter, 53U)) + 17289793580414993470U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10111912559295118444U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 8083622125544542011U;
            aOrbiterF = RotL64((aOrbiterF * 3610772128071340341U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7149858558922988240U) + aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 5919683821379905699U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16705119888884231567U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 6860902846079238714U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 15083517836867542075U;
            aOrbiterA = RotL64((aOrbiterA * 4686657139237578325U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 14852868368708376381U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 9860233289028878323U;
            aOrbiterE = RotL64((aOrbiterE * 13418143547952204667U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 772406119079116272U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterF) ^ 7971141501337627589U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 10168120622976358617U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 28U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterF) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 41U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aScatter, 44U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + aNonceWordE);
            aWandererI = aWandererI + (((((RotL64(aScatter, 53U) + RotL64(aOrbiterA, 52U)) + aOrbiterD) + RotL64(aCarry, 27U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + RotL64(aWandererF, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordC;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8972U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((aIndex + 15551U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13542U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 12842U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 10881271196314989997U) + aOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterA = (aWandererF + RotL64(aIngress, 34U)) + 6406461249988567558U;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 39U)) + 17255067918280095959U) + aOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 16690850682497718411U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 11U)) + 5576201059361086866U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11991259685693687554U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterE) ^ 14652535244217836909U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 18283959577075524171U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 1701789037170782122U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 953429054903473833U;
            aOrbiterF = RotL64((aOrbiterF * 13482379459700651427U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12064513610469714211U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 7993881398822002424U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11572884842788918377U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14421313768013320050U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 11112386845630998889U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11771526352030371669U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 17069630896535699015U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3308240081138623373U;
            aOrbiterC = RotL64((aOrbiterC * 10449509484417835159U), 39U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterK, 13U)) + RotL64(aCarry, 29U)) + aNonceWordN);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 40U) + RotL64(aOrbiterC, 57U)) + aOrbiterK) + aNonceWordI);
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 35U)) + aOrbiterE) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 44U)) + aOrbiterC) + aWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterA, 27U)) + aNonceWordO) + aWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordD);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20327U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneA[((aIndex + 20857U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 20728U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 16675U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 43U) ^ RotL64(aIngress, 56U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (((aWandererG + RotL64(aIngress, 35U)) + 16651241552253078315U) + aOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = ((((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 21U)) + 4558144676982478003U) + aOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aWandererI + RotL64(aPrevious, 27U)) + 8814884320080367550U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 48U)) + RotL64(aCarry, 57U)) + 16011579668555672117U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 4738918668759862438U) + aNonceWordN;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12526083125540985108U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8048723561746000552U;
            aOrbiterI = RotL64((aOrbiterI * 11914807994597963481U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 1082218464034639039U) + aNonceWordD;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8432043246965946816U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 7801965585991025451U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9982080524048636852U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 6720069955755215919U;
            aOrbiterK = RotL64((aOrbiterK * 1025046364205332059U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 1019035028070247757U) + aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7360619079463870467U) ^ aOrbiterUpdateSaltA[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6623074813047915863U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10893918488381348474U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterE) ^ 1390297670907738019U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 11909657437658597735U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 19U)) + aOrbiterD) + RotL64(aCarry, 3U)) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterK, 58U));
            aWandererI = aWandererI + (((((RotL64(aIngress, 13U) + aOrbiterK) + RotL64(aOrbiterG, 47U)) + RotL64(aCarry, 47U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterD, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererG, 44U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordM);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 25833U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneB[((aIndex + 31971U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32247U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((aIndex + 30251U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 52U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererD + RotL64(aScatter, 12U)) + 5510690816044082200U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 3U)) + 15967820875033940530U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 539348720848176221U;
            aOrbiterH = ((((aWandererB + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 15779318183635560817U) + aOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = (((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 11U)) + 14511058534424187469U) + aNonceWordB;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5811130556873428391U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1085928476499444025U;
            aOrbiterA = RotL64((aOrbiterA * 13965845678632598921U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6973335316600768130U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10747243745475009744U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17322489216048017061U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 1072260008981349754U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 2018772405352495753U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 10840562112080574241U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 1092091597048996547U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15103140149542167197U) ^ aOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 621856991658027989U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 13194619321108681542U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16749188603268621850U;
            aOrbiterG = RotL64((aOrbiterG * 9575408950550922039U), 11U);
            //
            aIngress = RotL64(aOrbiterH, 57U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 46U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aNonceWordC);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterE, 21U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterE, 44U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterA) + RotL64(aOrbiterH, 57U));
            aWandererD = aWandererD + ((((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + RotL64(aWandererI, 22U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordF);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
    std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCB837ED62EC98BB1ULL + 0xCB13A6C4A8833E76ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xA6DE7A9C049DF80BULL + 0x87D04DC30ECCFDE8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC76E580D25D0B081ULL + 0xE3B8B4431778DCF8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBBECB95EDBA31827ULL + 0xFE4D12E10C651B75ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD2133A5F3173C347ULL + 0xFE0A2FB649F7C1AAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xD1519E0D988E65EBULL + 0xDA8A5999519B8A33ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xC9AAFAC0CC2B7639ULL + 0xE5387EA37E9071F6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8EF58ECA0DF07F0BULL + 0xBE3CB8DD23D35596ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xF73E2B4C3DF0BF5DULL + 0xE23B7DAC4135A222ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xCCC9AD050FD0D8BBULL + 0xB67D411567A265C6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC3E79224241431C9ULL + 0xA25DCC360C939A68ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8B8E6188E485DC6DULL + 0xB786F99B0E1BBE1EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xFA69948B0F2B8853ULL + 0xA3BA1373E3745BD7ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x99D9B93FF4D72A2BULL + 0x8277A2AED3091CE4ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBB888AC6915FB643ULL + 0xA205E4531453D482ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF535F1ACDC1CB07BULL + 0xFAB42B9B28675D35ULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3776U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5157U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5163U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 1350U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 29U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aCarry, 60U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererG + RotL64(aIngress, 37U)) + 3105313968748067810U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aCross, 29U)) + 9977249451119627064U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 17941392803495349366U) + aNonceWordF;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 4279533326705471133U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 20U)) + 13983828966811580039U) + aNonceWordC;
            aOrbiterB = (aWandererE + RotL64(aScatter, 43U)) + 3983490984234810378U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 41U)) + 308786542215259956U) + aNonceWordM;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8443607695364427037U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14939626441464340668U;
            aOrbiterG = RotL64((aOrbiterG * 16793255020331774983U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9350693577306121110U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 1717071159396961752U;
            aOrbiterI = RotL64((aOrbiterI * 11062480662625054525U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15911765265202100610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14898546272333182767U;
            aOrbiterB = RotL64((aOrbiterB * 2674900543810733067U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 3560903518513465868U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 5367062725726860234U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 8521908836601319553U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15233321480618877327U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 9288449812290126074U;
            aOrbiterF = RotL64((aOrbiterF * 6815298520404038519U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5504840529511585676U) + aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 6825598386801620046U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11666542445846250077U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6433024450721339470U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 97934156644929458U;
            aOrbiterA = RotL64((aOrbiterA * 8630530773006923215U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterA, 29U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 43U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterG) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterF, 57U));
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 51U)) + aOrbiterF) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 5U)) + aOrbiterE) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aIngress, 5U) + RotL64(aOrbiterI, 30U)) + aOrbiterK) + RotL64(aCarry, 5U)) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterI, 39U)) + aOrbiterF);
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14072U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11349U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15902U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 15117U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 40U)) ^ (RotL64(aIngress, 53U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 19U)) + 13204735390996728477U) + aNonceWordF;
            aOrbiterH = (aWandererC + RotL64(aPrevious, 43U)) + 851171359595647173U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 16745304202825290723U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 562392736584913979U) + aOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 27U)) + 3244267012529053918U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordP;
            aOrbiterA = (aWandererB + RotL64(aScatter, 5U)) + 17282536111067869133U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 34U)) + RotL64(aCarry, 19U)) + 14851130066471729068U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterH) + 5256130407952363129U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 2904742485828362001U;
            aOrbiterJ = RotL64((aOrbiterJ * 12941135856735075457U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3723346325449225387U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5344621093694027341U;
            aOrbiterB = RotL64((aOrbiterB * 9044881458629673499U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12919263300833603026U) + aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17989801264160996071U;
            aOrbiterD = RotL64((aOrbiterD * 15468293047311883751U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5022175042377172157U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16684822380107847758U;
            aOrbiterH = RotL64((aOrbiterH * 2834049270263837537U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2740326510600876682U) + aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 13981423865219318820U;
            aOrbiterI = RotL64((aOrbiterI * 14593082145080056441U), 39U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterB) + 231945878229848395U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 14139797734944312580U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 6492256080432266407U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16704102101387552373U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8506734780526852552U;
            aOrbiterE = RotL64((aOrbiterE * 4684566118627414659U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 54U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterI, 60U)) + aOrbiterH);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 43U)) + aOrbiterJ) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 56U) + RotL64(aOrbiterI, 29U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterI, 53U)) + aNonceWordI);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 35U) + aOrbiterJ) + RotL64(aOrbiterD, 37U)) + RotL64(aCarry, 21U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterA, 11U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 54U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16609U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16772U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23431U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21212U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 53U)) + (RotL64(aIngress, 35U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererB + RotL64(aCross, 43U)) + 15910560457440369082U) + aNonceWordO;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 60U)) + 17953072986407436888U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aScatter, 21U)) + 15446940721193538669U;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 3020785262774422009U;
            aOrbiterG = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 7001288645424994404U) + aOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aScatter, 53U)) + 13385250665458462689U) + aNonceWordB;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 11U)) + 4841895644623005949U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 13053476783239482065U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 641996979335975244U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3697673197256549833U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16211238020928688299U) + aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 12715448751323279480U;
            aOrbiterJ = RotL64((aOrbiterJ * 2116880429675303291U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17784406727699995290U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterG) ^ 16626339815786580778U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 13940754474750138041U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9035070625716345139U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6085848172494001945U;
            aOrbiterF = RotL64((aOrbiterF * 10405728912339646693U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1177103851507561053U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 2281901691017816407U) ^ aOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3142197009403602497U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9040984343694325070U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 13334258224023902365U) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 4782523727707164869U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1079824790138592518U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14024082692012948652U;
            aOrbiterB = RotL64((aOrbiterB * 3219489374333737903U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterB, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ) + aWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterI, 53U));
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterI, 3U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 60U)) + aNonceWordG);
            aWandererA = aWandererA + ((((RotL64(aIngress, 54U) + aOrbiterI) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 19U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 48U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28696U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 29058U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30110U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29599U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 10U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 57U)) + 5906639480605353429U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 21U)) + 5293518570213287605U) + aOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = (aWandererH + RotL64(aScatter, 47U)) + 15383185501428521377U;
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 15364072512743978902U) + aNonceWordJ;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 35U)) + 4525473357144014271U) + aNonceWordG;
            aOrbiterH = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 27U)) + 10400911938125603074U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 41U)) + 16417506293824627550U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2419329331753341815U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14929222427923332069U) ^ aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11596261802662514979U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 16771573504983922586U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1863466450051787622U;
            aOrbiterH = RotL64((aOrbiterH * 2585626547126027053U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12895350137096692415U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 3700979086526298327U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 10279730254867618193U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 1977099106211282426U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 6144698304096915742U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5039822990560519609U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3858895556659724975U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1283646340363435327U;
            aOrbiterI = RotL64((aOrbiterI * 11622421841377018069U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6240532051889108891U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 757364889381634634U;
            aOrbiterJ = RotL64((aOrbiterJ * 943852137901972945U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5272945693977418174U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 6850528198786172283U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 1966383079897679953U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 13U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterB, 12U)) + RotL64(aCarry, 19U)) + aNonceWordA);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 30U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aNonceWordO);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterJ, 53U)) + aWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererI);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordC);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCF3C8DAC13085B85ULL + 0xF50F7E68094A5B6FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xEF64526339E4100BULL + 0xEF2F37EF70FDBB5CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x95B34A534C6F7C03ULL + 0xBE58556C77B2C408ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x819DBC55BE69A163ULL + 0x9EE235ECE5EF8E93ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB569A7E0C925473FULL + 0x87CAC60FA6F8D7F6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD1C69602DCD5F741ULL + 0xC867EA44AEEAE8D9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD116F64F7791DA59ULL + 0xD53903D7F7A26841ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xF3D919C342A4FED5ULL + 0xCAD487BAFB153AE0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x9699AE900380C40BULL + 0x9C9F3288CD15A11EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x81B4216B89EAE87BULL + 0xA40B6E452CC3C35EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xDDFD86DAFEEE44BFULL + 0x9451F519D7950BD1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB7DE2BC4CBB82F99ULL + 0xB8C3439A23E1D1BEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA2F2619408FB87A3ULL + 0x91F6DA562E2FC9C6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xAC9F1930698EB089ULL + 0x991FE9ACF13D601BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDCE7711309882AF5ULL + 0xBA359A440DFE774CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCBB5BA5D5DD29E1FULL + 0xFF720FC3ECBC1F77ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 7354U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4490U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 2510U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((aIndex + 2318U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 38U) ^ RotL64(aPrevious, 53U)) + (RotL64(aIngress, 3U) ^ RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererI + RotL64(aIngress, 13U)) + 6069475454765660321U) + aNonceWordO;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 57U)) + 11483704742497268068U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 11055697447388986418U;
            aOrbiterK = (aWandererJ + RotL64(aCross, 5U)) + 10897095046039997004U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 19U)) + 4731637118230457840U) + aNonceWordB;
            aOrbiterJ = (((aWandererF + RotL64(aIngress, 36U)) + RotL64(aCarry, 51U)) + 13855839187084986751U) + aOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 51U)) + 5328208115460188239U) + aOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12479538544291412985U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterB) ^ 10740165998792608231U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 14046827922294477379U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6492798157284955373U) + aOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 13056825957483891921U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 14882112110627751751U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 2068184064919194657U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 5656302738780746294U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16493021179127646345U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11193756120230763294U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17306750816837208999U;
            aOrbiterD = RotL64((aOrbiterD * 7949360041241439741U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 12952818800389361804U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15380412293642628312U;
            aOrbiterB = RotL64((aOrbiterB * 2914662289178925547U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7706090204767242996U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14598802276412649570U;
            aOrbiterK = RotL64((aOrbiterK * 4821408736292041399U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17819762117328075515U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6481384240915075101U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 4836701121865783029U), 21U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 43U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 60U) + aOrbiterF) + RotL64(aOrbiterJ, 37U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aCross, 39U) + RotL64(aOrbiterI, 28U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordM);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16316U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15721U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8516U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneB[((aIndex + 15747U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 21U)) + (RotL64(aCarry, 39U) + RotL64(aIngress, 52U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererG + RotL64(aScatter, 47U)) + 9914837590440975587U;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 6706125076401958051U) + aOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aWandererD + RotL64(aIngress, 29U)) + 16570817772679258409U;
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 19U)) + RotL64(aCarry, 3U)) + 6843705658115186948U) + aOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 11U)) + 16099930446791572351U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 35U)) + 5420550009556030459U;
            aOrbiterA = ((aWandererJ + RotL64(aCross, 39U)) + 5729549069420177477U) + aNonceWordE;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 15590601126188675834U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13044027390998620029U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 16845199115313444123U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11068338135659636772U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6584988841809544332U;
            aOrbiterE = RotL64((aOrbiterE * 1683336180438945439U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8516813219883915404U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10647314042912492785U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15559481057047148785U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 201691689889605304U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 15512161798401184003U;
            aOrbiterJ = RotL64((aOrbiterJ * 11473219183982564709U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3883760518944464145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13861805129175491145U;
            aOrbiterC = RotL64((aOrbiterC * 17194438894492581181U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 12019138626550801486U) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13030350224959652248U;
            aOrbiterD = RotL64((aOrbiterD * 11724200983306280107U), 47U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterH) + 2643807255422544248U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4127143302485631794U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5441038881111578487U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterE, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterH, 37U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 5U) + aOrbiterG) + RotL64(aOrbiterA, 43U)) + aNonceWordN) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 14U) + RotL64(aOrbiterE, 29U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterC) + RotL64(aOrbiterH, 21U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterJ, 6U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 21471U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19424U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 19867U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 18239U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 41U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 10U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = (aWandererF + RotL64(aIngress, 13U)) + 11700815697312060726U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 4U)) + 11808423452327465441U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 37U)) + RotL64(aCarry, 3U)) + 8670503858631730886U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 57U)) + 2400061067991988544U;
            aOrbiterJ = (((aWandererB + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 16163118178366229686U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = ((((aWandererD + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 3280178595904941068U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererI + RotL64(aPrevious, 47U)) + 3298683600817047727U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 16321624053445183574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 6730229877611375225U;
            aOrbiterG = RotL64((aOrbiterG * 2022290495153519279U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 10162830636713641322U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 15646771327759599256U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 15333053762177144775U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 14841751262270544102U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9545541117228834895U) ^ aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11529769874752969377U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 14676615635857599982U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1231768638470558855U;
            aOrbiterH = RotL64((aOrbiterH * 2716808508509014677U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 1945905595345404833U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1406171421638586846U;
            aOrbiterJ = RotL64((aOrbiterJ * 4577864352425476233U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 1970292335806697198U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12309719390375013297U;
            aOrbiterC = RotL64((aOrbiterC * 16540660957923687327U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5352135521358954576U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15465675376193501658U;
            aOrbiterA = RotL64((aOrbiterA * 16385761112921041387U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 41U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererB = aWandererB + ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 60U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterJ, 47U)) + aOrbiterK);
            aWandererG = aWandererG + (((((RotL64(aCross, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 37U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32197U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27833U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31193U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28534U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U)) + (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 20U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (((aWandererC + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 9751314027302668907U) + aNonceWordD;
            aOrbiterH = (((aWandererB + RotL64(aCross, 44U)) + RotL64(aCarry, 19U)) + 12175450995523107056U) + aOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 17519694958730119552U) + aNonceWordH;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 5U)) + 9093525527925682263U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 19U)) + 3713831321786810138U) + aNonceWordK;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 35U)) + 10108355209191835040U) + aOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererG + RotL64(aPrevious, 51U)) + 12956307447311314768U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1904298513945877359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4658049993308574460U;
            aOrbiterE = RotL64((aOrbiterE * 10482422152074338611U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9826333658248851902U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 12058666914724365134U) ^ aOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 964233873188373939U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2516574707110528099U) + aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 13335308331049750235U;
            aOrbiterH = RotL64((aOrbiterH * 5880227828760598587U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8230749255538495304U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 16536559486797811486U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 7097036838156464969U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12387639130570188998U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8459259798142872020U;
            aOrbiterD = RotL64((aOrbiterD * 8001346480955847013U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16083784052002800300U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 1957284290736468379U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 5046501301740813065U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 7349538179311335863U) + aNonceWordJ;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16395170077006105258U;
            aOrbiterJ = RotL64((aOrbiterJ * 4230485452156662763U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 47U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterH, 21U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 28U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 57U)) + aOrbiterH) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordH);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xDC533763D639E6AFULL + 0x872EEF464692C3B1ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC7DF99A8E22345D1ULL + 0xAD76CDAFF247AD49ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA4B6D35E36896E49ULL + 0x82441FE1DE09AFD4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE2F3A381AE25CA4DULL + 0x842ECBA091C5396BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xA32BB4C97963D88FULL + 0xFD136643C268DF55ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE819DAF15D9B977DULL + 0xA90426A6917DD5EAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA6BF2D14ADC739C3ULL + 0xE00EA0D8FC80710CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x8A4D13D12EE1DCDFULL + 0x96CD5337A427F600ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFAB37CC330B5D54FULL + 0x8A41EF46F2B613EDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE555EF920CBC7CF3ULL + 0xBDF360A4CB5BA9C3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC21E204AE668C83BULL + 0x85A4BC1481638F1AULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x81974E30A7B9B5B7ULL + 0xF1EF044213E46B98ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9892A01997424B61ULL + 0xC16FCCBE836DA14CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xEE3066E0DFDACF17ULL + 0xFB2C15FA36885BB0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC6A235E06B947CCBULL + 0xA62105A0BE0C8CD8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC49A1B6B6A4AD1E1ULL + 0x9ED2179AE572385AULL);
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 1692U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 5901U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4216U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 1334U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 14U) + RotL64(aIngress, 39U)) ^ (RotL64(aPrevious, 27U) ^ RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererG + RotL64(aScatter, 48U)) + 8975885703279267062U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 8664844915562660637U;
            aOrbiterB = (aWandererB + RotL64(aCross, 5U)) + 12281774799736296726U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 41U)) + 15347461352311329726U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 43U)) + 12967500561828907834U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 11U)) + 5002833859280402726U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 53U)) + 11908257536954668983U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((((aWandererF + RotL64(aPrevious, 30U)) + RotL64(aCarry, 3U)) + 17017174811949227162U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (aWandererC + RotL64(aIngress, 13U)) + 16851323125613931180U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 13469326957728686706U;
            aOrbiterA = (aWandererD + RotL64(aCross, 27U)) + 5228638551056105241U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11945166198089308564U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16268645041872996022U;
            aOrbiterB = RotL64((aOrbiterB * 5391448793718370911U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 14781204627695095701U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5365325354838101092U;
            aOrbiterD = RotL64((aOrbiterD * 8017284997946310807U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 563147416025715953U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 14660867395395625851U;
            aOrbiterG = RotL64((aOrbiterG * 4769458126865307103U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 3168989056355712105U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16179131669773665579U;
            aOrbiterJ = RotL64((aOrbiterJ * 5641461617066671723U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4160220074225527179U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8597134686962559111U;
            aOrbiterC = RotL64((aOrbiterC * 639572585431474015U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 16811551552456811661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 5827323970423386301U;
            aOrbiterK = RotL64((aOrbiterK * 9328247349730652021U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 15583234353262170227U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 2950816254621717748U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 1102417597476170143U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 4426165025104306337U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11871220132164971152U;
            aOrbiterE = RotL64((aOrbiterE * 2366168050042802207U), 51U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterC) + 3832424136113939717U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 17673885217916768611U;
            aOrbiterH = RotL64((aOrbiterH * 10887063696370811871U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 3479289844909914390U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 9498461576098567546U;
            aOrbiterI = RotL64((aOrbiterI * 8734492074299676555U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 10645314291190544864U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8975885703279267062U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16584086014947250551U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterI, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 30U));
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 41U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aScatter, 44U) + aOrbiterK) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 37U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterE, 53U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 43U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterA, 11U)) + aOrbiterK) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 24U) + aOrbiterC) + RotL64(aOrbiterE, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 34U)) + aOrbiterD) + aWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterF, 51U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterG, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 56U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9667U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneD[((aIndex + 10721U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11049U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((aIndex + 12326U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 11U)) + (RotL64(aIngress, 27U) + RotL64(aCross, 54U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererH + RotL64(aCross, 44U)) + 10881271196314989997U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 3U)) + 6406461249988567558U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 5U)) + 17255067918280095959U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 5U)) + 16690850682497718411U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 57U)) + 5576201059361086866U;
            aOrbiterF = ((((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 43U)) + 11991259685693687554U) + aOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 21U)) + 14652535244217836909U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 23U)) + 1701789037170782122U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 11U)) + 953429054903473833U;
            aOrbiterK = ((aWandererF + RotL64(aCross, 41U)) + 12064513610469714211U) + aNonceWordB;
            aOrbiterJ = (((aWandererD + RotL64(aPrevious, 51U)) + 7993881398822002424U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14421313768013320050U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11112386845630998889U;
            aOrbiterA = RotL64((aOrbiterA * 11771526352030371669U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17069630896535699015U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 3308240081138623373U;
            aOrbiterB = RotL64((aOrbiterB * 10449509484417835159U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17615529807112933619U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 11782807146851563541U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12992075832343669221U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 14401645829607611983U) + aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6736397344219993532U;
            aOrbiterE = RotL64((aOrbiterE * 1667287547938175641U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6446974060524700550U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7840991992443308254U;
            aOrbiterD = RotL64((aOrbiterD * 6891023544882740107U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 10362169906019794305U) + aNonceWordJ;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 4503700997923168911U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15066164494038852559U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13492041134973259041U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 14337899277551397976U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5966740718899290915U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13693100781608180748U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16177545026405910052U;
            aOrbiterF = RotL64((aOrbiterF * 6019231448444020563U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9641191118119415680U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 735491776764667034U;
            aOrbiterC = RotL64((aOrbiterC * 11305930862759869997U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2225714710491247284U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 16906789796765378455U;
            aOrbiterK = RotL64((aOrbiterK * 4341667316266234469U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9451961177946601088U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10881271196314989997U;
            aOrbiterJ = RotL64((aOrbiterJ * 10929686721061541543U), 19U);
            //
            aIngress = RotL64(aOrbiterH, 38U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterH, 6U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 37U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 40U) + aOrbiterG) + RotL64(aOrbiterA, 41U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + RotL64(aCarry, 39U)) + aWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 35U));
            aWandererH = aWandererH + (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterE, 21U)) + aNonceWordD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 27U)) + aOrbiterE) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterI) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterD, 3U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 50U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererE, 48U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordJ);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19326U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneA[((aIndex + 18075U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19541U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneC[((aIndex + 17794U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 44U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 43U)) + 3917730204724097072U) + aNonceWordI;
            aOrbiterE = (((aWandererK + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 1874642340716212824U) + aNonceWordG;
            aOrbiterK = (((aWandererI + RotL64(aCross, 5U)) + RotL64(aCarry, 23U)) + 6900165757434854160U) + aNonceWordC;
            aOrbiterC = (aWandererC + RotL64(aScatter, 13U)) + 12750946097023807161U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 54U)) + 6563216048479513594U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aPrevious, 41U)) + 14960240191349450795U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 47U)) + 16306180275951788289U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 27U)) + 6502066618271045547U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 60U)) + 6219852857850888738U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aPrevious, 29U)) + 2272931312452845850U;
            aOrbiterG = (aWandererG + RotL64(aCross, 21U)) + 3028929882263199463U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6067393030073568112U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10094809900437037258U;
            aOrbiterK = RotL64((aOrbiterK * 18095564940730322769U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5962414178157074575U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15755563045799129417U;
            aOrbiterA = RotL64((aOrbiterA * 3692603590609922031U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 6321455513889880590U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1197435601998121700U;
            aOrbiterE = RotL64((aOrbiterE * 17693996266260557625U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 12496949381666299968U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6357070235648527030U;
            aOrbiterH = RotL64((aOrbiterH * 2931486644220862433U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 8423760160877540210U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8090246492554850768U;
            aOrbiterD = RotL64((aOrbiterD * 2949407491181921633U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11436635942985063755U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17086363141014359856U;
            aOrbiterI = RotL64((aOrbiterI * 10504127577318206801U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 10734017887545474935U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 375515325165740779U;
            aOrbiterF = RotL64((aOrbiterF * 9980486695448151709U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 5217148491945389821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14696058217023530058U;
            aOrbiterC = RotL64((aOrbiterC * 11026674782236654799U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11869055287836412650U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16951500118659983436U;
            aOrbiterB = RotL64((aOrbiterB * 4304372681583055077U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7866300390953569803U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 18017335943787362993U;
            aOrbiterJ = RotL64((aOrbiterJ * 15683049583437004889U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2477944286851267725U) + aNonceWordP;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 3917730204724097072U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 6617615984203047419U), 39U);
            //
            aIngress = RotL64(aOrbiterK, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterJ, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 29U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterK, 60U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aNonceWordH);
            aWandererC = aWandererC ^ (((RotL64(aCross, 43U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + aNonceWordB);
            aWandererH = aWandererH + ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterB, 51U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 47U)) + aOrbiterG) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 58U) + aOrbiterA) + RotL64(aOrbiterF, 12U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterA, 21U));
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + aOrbiterI) + RotL64(aOrbiterA, 37U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 3U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 47U)) + aWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 14U) + aOrbiterG) + RotL64(aOrbiterD, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererD, 56U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27372U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32168U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30571U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 27704U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 28U)) ^ (RotL64(aPrevious, 41U) + RotL64(aCarry, 13U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 57U)) + 6068543441070417854U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 2995980468193441856U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aCross, 41U)) + 18020277482171594003U) + aNonceWordG;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 52U)) + RotL64(aCarry, 35U)) + 4293807434721230702U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 7980599111583893156U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 37U)) + 8593141111851052016U) + aNonceWordF;
            aOrbiterG = (aWandererA + RotL64(aCross, 11U)) + 5903487523900084325U;
            aOrbiterF = (aWandererH + RotL64(aPrevious, 39U)) + 15112035513447930209U;
            aOrbiterK = (aWandererF + RotL64(aIngress, 43U)) + 9854037263057006439U;
            aOrbiterE = (aWandererK + RotL64(aPrevious, 54U)) + 16759760289688823193U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 19U)) + 12622628933030601390U) + aOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1264668857268123425U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16302812053619101593U;
            aOrbiterD = RotL64((aOrbiterD * 18291400055836111547U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 16087995784896123610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7970269262800468363U;
            aOrbiterH = RotL64((aOrbiterH * 14924752223305807461U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 5331477046030959632U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 16534913204255550893U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1013433634373673565U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 11042821902537871209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 8069677512345031660U;
            aOrbiterG = RotL64((aOrbiterG * 13622218526054132397U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5737130058129936372U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 1076627182956662997U;
            aOrbiterF = RotL64((aOrbiterF * 14342191224014199929U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13911061091801078190U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 15397603151098990373U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1802890451633592245U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15137326716738637972U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 11248737008959896786U;
            aOrbiterE = RotL64((aOrbiterE * 90789374131547005U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 1847847987633923657U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10560748778679145431U;
            aOrbiterI = RotL64((aOrbiterI * 2919333327817231099U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2703726238610290251U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterK) ^ 12950671360471467310U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 7490327691501537047U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 10331504168520449467U) + aNonceWordI;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 1541527607705280906U;
            aOrbiterA = RotL64((aOrbiterA * 14197400812600186171U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9135056476214341809U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6068543441070417854U;
            aOrbiterJ = RotL64((aOrbiterJ * 14102524444094948875U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 18U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 36U) + aOrbiterC) + RotL64(aOrbiterG, 22U)) + aWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterD, 19U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterG, 57U)) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterB, 29U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + aOrbiterF) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            aWandererD = aWandererD + ((RotL64(aScatter, 41U) + aOrbiterH) + RotL64(aOrbiterB, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterA, 43U)) + aOrbiterI);
            aWandererG = aWandererG + ((((RotL64(aIngress, 34U) + RotL64(aOrbiterJ, 41U)) + aOrbiterB) + aNonceWordH) + aWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 28U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 41U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordA);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x95C5860D9F5CF2A5ULL + 0xCE91BCAE48BB875DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF2C10E82E99F3745ULL + 0xF3A8E759418F76B8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB94F0ECB5268AF71ULL + 0x8927CA2E05BB14A7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xADB2B1F62A7B2E11ULL + 0x838FBAF2DA389C4EULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xDEEB68DC3A1ECB83ULL + 0xAD192650DF86BD63ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB830DE3C4996C0ABULL + 0x850CE5B50D2B3622ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x99B92E4EE182E921ULL + 0xCD62FA80EC2EBFB4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x891573A10E5D9509ULL + 0xDBF37547474C5E34ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9476457EDB418E57ULL + 0xCCADA685D904BADAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFC455F02DCA11EA9ULL + 0xEDB45182F7E21601ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB1131D85C160D3D7ULL + 0xD09502691B304DEAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xB4C92CE45A43830DULL + 0xA4060838F7D9F61BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xAEC7D3E202E6D927ULL + 0x98CEF611565470D8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8058D334ABB54099ULL + 0xF978F532CD507AA6ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFE600D4A4B265EE3ULL + 0xD0762CF140FE5EE4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCE283240F87F6E21ULL + 0xECA70DC285FA3F4DULL);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 800U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3562U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 2507U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1583U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) + RotL64(aCarry, 13U)) ^ (RotL64(aCross, 30U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterK = ((aWandererD + RotL64(aCross, 5U)) + 18180797995100240808U) + aOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 57U)) + 6585906608223552885U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 53U)) + 14088708930575939855U) + aNonceWordF;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 34U)) + RotL64(aCarry, 23U)) + 468974153311516044U;
            aOrbiterH = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 12481951025619894110U) + aOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererK + RotL64(aIngress, 43U)) + 17227987923860711763U) + aNonceWordK;
            aOrbiterJ = (aWandererJ + RotL64(aScatter, 23U)) + 4373962756657477139U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 2077576476565420951U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 30U)) + 17435011300234663764U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 4118039398293246896U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13724716599855216683U;
            aOrbiterI = RotL64((aOrbiterI * 17556333902751079677U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 12391461204689596339U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 9900605191533799627U;
            aOrbiterD = RotL64((aOrbiterD * 13553565332531046301U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 972946858824366125U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 17247681919694541215U;
            aOrbiterG = RotL64((aOrbiterG * 2974639094630445643U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15442851427306771601U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7303586227288294037U;
            aOrbiterC = RotL64((aOrbiterC * 15406402525021428799U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12650358753454105119U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 1483710933373510492U;
            aOrbiterK = RotL64((aOrbiterK * 6531763256577221891U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 18065810162229740788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11311677121338794007U;
            aOrbiterB = RotL64((aOrbiterB * 15116367961682119467U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 2355285311890287611U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1287783821903407734U) ^ aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8054011680932255985U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9282654686791135654U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 15488608017745542551U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7858866274035085123U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 13296835576073421802U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 7127700236018338741U;
            aOrbiterH = RotL64((aOrbiterH * 11246173563106014149U), 39U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterI, 42U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 43U)) + aOrbiterI) + aWandererUpdateSaltC[((aIndex + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterC, 47U)) + aOrbiterI) + aNonceWordA);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterK, 19U));
            aWandererB = aWandererB + (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 28U)) + aOrbiterB) + aWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 39U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aCross, 60U) + aOrbiterD) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9602U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 7588U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9559U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6468U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 28U) + RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererC + RotL64(aIngress, 39U)) + 4068921616130916949U;
            aOrbiterI = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 11U)) + 12077715273915151726U) + aNonceWordK;
            aOrbiterB = ((aWandererD + RotL64(aCross, 21U)) + RotL64(aCarry, 51U)) + 16047546802670596833U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 11U)) + 9690277462716999763U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aIngress, 30U)) + 14484814700447992628U) + aNonceWordP;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 5U)) + 17089267243053958210U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 35U)) + 9138746214446211147U) + aOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 10181001536979097045U) + aNonceWordJ;
            aOrbiterC = (aWandererJ + RotL64(aCross, 58U)) + 6657458969093373191U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7515983477876590988U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3039935555863947600U) ^ aOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12511160550780270119U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16209389224740851136U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 725253312098083182U;
            aOrbiterA = RotL64((aOrbiterA * 17535989492095522597U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 13307041115748941383U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 7159572004825238263U;
            aOrbiterF = RotL64((aOrbiterF * 4855009895002398449U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 12027236743251643820U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterI) ^ 8717826175991286553U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 1175614802543098451U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4769096034227659937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11201226563992939616U;
            aOrbiterC = RotL64((aOrbiterC * 15595355978388159931U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 17295978531215563256U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11850923890626719833U;
            aOrbiterE = RotL64((aOrbiterE * 3854851059897397075U), 47U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14139441565288097706U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 988684899382304485U;
            aOrbiterH = RotL64((aOrbiterH * 11929090869999700891U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 6159251276942253175U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4849529993914550651U;
            aOrbiterJ = RotL64((aOrbiterJ * 18240712676783671317U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 6679745455842119497U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15838404437552215214U;
            aOrbiterI = RotL64((aOrbiterI * 17357853511591350887U), 43U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 46U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 52U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordF);
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + aWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 43U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 28U) + aOrbiterA) + RotL64(aOrbiterJ, 27U));
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterI) + RotL64(aOrbiterG, 56U)) + aWandererUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 23U)) + aOrbiterE);
            aWandererA = aWandererA + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterI, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterF, 47U));
            aWandererE = aWandererE + ((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 14649U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12330U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15748U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12534U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 44U) ^ RotL64(aCarry, 11U)) + (RotL64(aCross, 27U) ^ RotL64(aPrevious, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = ((aWandererI + RotL64(aScatter, 40U)) + RotL64(aCarry, 3U)) + 16651241552253078315U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 11U)) + 4558144676982478003U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 53U)) + 8814884320080367550U;
            aOrbiterJ = ((aWandererA + RotL64(aIngress, 57U)) + 16011579668555672117U) + aNonceWordK;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 27U)) + 4738918668759862438U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 23U)) + 12526083125540985108U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 35U)) + 8048723561746000552U) + aNonceWordF;
            aOrbiterE = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 19U)) + 1082218464034639039U) + aNonceWordL;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 28U)) + 8432043246965946816U) + aOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9982080524048636852U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6720069955755215919U;
            aOrbiterA = RotL64((aOrbiterA * 1025046364205332059U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1019035028070247757U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7360619079463870467U;
            aOrbiterC = RotL64((aOrbiterC * 6623074813047915863U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 10893918488381348474U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1390297670907738019U;
            aOrbiterJ = RotL64((aOrbiterJ * 11909657437658597735U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12512200589031203480U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14741471280748399540U;
            aOrbiterD = RotL64((aOrbiterD * 3012135242889901095U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 8543897248359826770U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8545972622733791272U;
            aOrbiterG = RotL64((aOrbiterG * 11793879362775346821U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 7049384618581928664U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14730773807906925408U;
            aOrbiterB = RotL64((aOrbiterB * 10711566871536755073U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11480717275652449986U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 1135397594974536859U;
            aOrbiterH = RotL64((aOrbiterH * 6347492892938856497U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6897207625849516702U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 10920630712550287148U;
            aOrbiterE = RotL64((aOrbiterE * 4140705091806993359U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 1094056478999931332U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 6784487144549717207U;
            aOrbiterK = RotL64((aOrbiterK * 6295177724167067891U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterD, 40U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterK, 30U)) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aCross, 42U) + RotL64(aOrbiterE, 47U)) + aOrbiterJ) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterJ, 35U)) + aNonceWordA);
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + aNonceWordP) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterC, 43U));
            aWandererK = aWandererK + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 57U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 39U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 54U) + RotL64(aOrbiterA, 26U)) + aOrbiterH) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordC);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16711U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18883U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18526U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17071U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 24U) + RotL64(aCross, 37U)) ^ (RotL64(aIngress, 11U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 43U)) + 479672811032092393U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 19U)) + 18061121631394564425U) + aNonceWordH;
            aOrbiterI = (((aWandererA + RotL64(aPrevious, 48U)) + RotL64(aCarry, 19U)) + 14237400452740566065U) + aNonceWordF;
            aOrbiterH = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 29U)) + 6723123812257706134U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 39U)) + 4247997188026499248U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 27U)) + 1939107415066134869U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = (aWandererH + RotL64(aIngress, 23U)) + 3912640123546395979U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 41U)) + 8295478436553964298U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 3U)) + 3218960600711526885U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5874096203353388890U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10294536533673023358U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 15561710414949058923U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11268561953904130747U) + aOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16693201256788898423U;
            aOrbiterK = RotL64((aOrbiterK * 16291987237693567209U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 7550969634681894654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 9501647424602245869U;
            aOrbiterE = RotL64((aOrbiterE * 11265865222096866605U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8881869255994319423U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 16770136406906800016U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1782039587385512923U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 16185384746435761363U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13841034186650721627U;
            aOrbiterH = RotL64((aOrbiterH * 12000155593277035447U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15229062695864608309U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 3576122704615303733U;
            aOrbiterC = RotL64((aOrbiterC * 2433987493885779279U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13898167174453181224U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12878032061609524049U;
            aOrbiterD = RotL64((aOrbiterD * 18104665741338251495U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12719156051299028649U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 8640980843376950769U) ^ aOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10242616778390983333U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12133332160916004365U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 8743563985229104484U;
            aOrbiterF = RotL64((aOrbiterF * 4575129690615054691U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 42U)) + aOrbiterE) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + RotL64(aOrbiterB, 11U)) + aOrbiterE) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 37U)) + aOrbiterK) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 19U) + aOrbiterB) + RotL64(aOrbiterF, 5U)) + RotL64(aCarry, 11U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterH, 46U));
            aWandererB = aWandererB + ((RotL64(aCross, 43U) + RotL64(aOrbiterD, 51U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterK, 19U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aScatter, 53U) + RotL64(aOrbiterH, 57U)) + aOrbiterA);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 58U) + RotL64(aOrbiterK, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 44U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24872U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneA[((aIndex + 27104U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24090U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 24966U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 21U) + RotL64(aIngress, 4U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aCross, 14U)) + 12632404972795375757U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererK + RotL64(aIngress, 47U)) + 5351879979055988456U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 3U)) + 3597737727467443413U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 41U)) + 2830846754917852318U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 17311925960294518018U;
            aOrbiterF = (((aWandererD + RotL64(aScatter, 35U)) + RotL64(aCarry, 23U)) + 2083584640523695383U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aWandererG + RotL64(aPrevious, 58U)) + 15049343611387010158U;
            aOrbiterB = (((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 51U)) + 6443050378205811147U) + aNonceWordO;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 51U)) + 6021965178697344070U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5080289878758029976U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 576927745306972983U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 16008958833683246115U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 4728489691382690859U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6184355840165758855U;
            aOrbiterF = RotL64((aOrbiterF * 1515043910404156423U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11220539885798595450U) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 11091438724966718214U) ^ aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8225347114759391961U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17184210490020062419U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2150997767099116408U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8058553821648892499U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 7021953562676903717U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17159676348343312834U;
            aOrbiterJ = RotL64((aOrbiterJ * 13877284519668483549U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 10367891770525239784U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11922478487264201233U;
            aOrbiterD = RotL64((aOrbiterD * 9195137452661956029U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17815162358981720634U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9582631251085100284U;
            aOrbiterG = RotL64((aOrbiterG * 11838992994130850483U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 872593750259572264U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 17832330100262167302U;
            aOrbiterK = RotL64((aOrbiterK * 1114416841510028467U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16601139856969287418U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 14931287111691324985U;
            aOrbiterA = RotL64((aOrbiterA * 16757174577841001179U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 44U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterG, 27U));
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 58U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterI, 52U)) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 57U)) + aOrbiterI) + RotL64(aCarry, 13U)) + aNonceWordD);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 12U) + aOrbiterI) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 46U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28717U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 31044U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32113U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((aIndex + 28337U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 39U) + RotL64(aCarry, 18U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 48U)) + 10915618884692072446U;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 43U)) + 12634922308499254909U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 6533934734564499389U) + aOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 6744203303756105181U;
            aOrbiterF = ((((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 19U)) + 13086782386652045658U) + aOrbiterAssignSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aWandererI + RotL64(aIngress, 53U)) + 5693840533331397822U;
            aOrbiterA = (aWandererK + RotL64(aScatter, 10U)) + 1803663542535024611U;
            aOrbiterH = (aWandererA + RotL64(aCross, 5U)) + 3597219300593287708U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 23U)) + 1429753448204448904U) + aNonceWordK;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 17229017825587322715U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1137574712801062932U;
            aOrbiterI = RotL64((aOrbiterI * 3645832160939819415U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2401991077004083378U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1332473247826139292U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15029831858261506447U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11730946340796899885U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15319163439700390962U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1349242001887975499U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 4744141870145159917U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 6067132201862688684U;
            aOrbiterH = RotL64((aOrbiterH * 6046100687757836027U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 14991509179286371800U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 4342608825699398682U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 10240526103933275875U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3727521409410742075U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3302027219498304367U;
            aOrbiterD = RotL64((aOrbiterD * 12153634588200479559U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 6039539483340398858U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 2902581519976937051U) ^ aNonceWordP;
            aOrbiterB = RotL64((aOrbiterB * 2057584328877854239U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12332784713738947242U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 13761272577223712786U) ^ aOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14930145045480030821U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 2947946397617043735U) + aNonceWordE;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11107014023853644521U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15030903626191481831U), 13U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 60U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterC, 21U));
            aWandererA = aWandererA + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterG, 47U)) + aWandererUpdateSaltD[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterB, 53U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + aOrbiterF) + RotL64(aOrbiterI, 14U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 35U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 19U) + RotL64(aOrbiterH, 39U)) + aOrbiterF) + RotL64(aCarry, 23U)) + aWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterF, 43U)) + aNonceWordC);
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterG) + RotL64(aOrbiterI, 29U)) + aNonceWordA);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 4U)) + aOrbiterD) + aNonceWordD);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordN);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x9BEF29E9AFBAF5EFULL + 0xD5EA0B72BE28EF21ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9E59627806C1D329ULL + 0xEB6C2CF7B232AEFEULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xF2AFA7E316C515B5ULL + 0xAABF1B1CF8A5FBC4ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBE943513A119A7AFULL + 0xCA070E78ED3A0742ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDCF74BCF699E5E81ULL + 0xE5DD5C4A283586E8ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x83D1EAFE96B8D98FULL + 0x888DFEB88529C21CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xDBCCF5CEEACB2A93ULL + 0xB04436DB668A2F71ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xDE1EBFFA20CC9C97ULL + 0xE49B6889F2A1B205ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA01204D38D30625BULL + 0xB2F521E09EB6BF9AULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBFCA40CFA7DE3C57ULL + 0x86ED49925831E879ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD4D03BEC3969D3EBULL + 0x84F4AFF4CC02E1E1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE910A6C621C07B31ULL + 0xE6E653B39FF248E9ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEE988A3070BB0085ULL + 0xA82D76EF3FD36CB1ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x926F92BBE001AE45ULL + 0xF547AE9105C96B2BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDC38A7A4C1BD5893ULL + 0xFAD9F90074D6ED0FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC32F62BC0CCDD021ULL + 0xBAAFC7C9AF7FDF47ULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1205U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 597U)) & W_KEY1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 2746U)) & W_KEY1], 18U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1717U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 40U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aScatter, 43U)) + 14624277139785904404U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 22U)) + RotL64(aCarry, 39U)) + 6966977309498165611U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 37U)) + RotL64(aCarry, 57U)) + 205536824352530761U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 29U)) + 16629575265808255692U) + aNonceWordL;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 3U)) + 596881340147972746U;
            aOrbiterJ = ((((aWandererF + RotL64(aScatter, 57U)) + RotL64(aCarry, 27U)) + 11944412799107412650U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 13U)) + 4615021315668210206U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 8497630055977606216U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11131601107309336885U;
            aOrbiterA = RotL64((aOrbiterA * 18028349768453554935U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5935883479805510099U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15629346719765798174U;
            aOrbiterB = RotL64((aOrbiterB * 8535523790685945275U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5279128339113651273U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16778365912440331821U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 705421028266789241U), 35U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterJ) + 16003052937645491524U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 6723226158737614764U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 16690657664909260573U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 9785784358981219543U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10055457337292292710U;
            aOrbiterI = RotL64((aOrbiterI * 17919129940751761111U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11779163108592974175U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 1177999477942202687U) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 13475069421684114643U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 9190694445141492214U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15605342360346353457U;
            aOrbiterK = RotL64((aOrbiterK * 14547769706392595647U), 29U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 41U);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterA, 44U));
            aWandererB = aWandererB + (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 11U)) + aOrbiterI) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterH, 51U)) + aPhaseAWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 36U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterK, 19U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterK, 27U)) + aOrbiterB) + aPhaseAWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 52U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 39U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 13U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10124U)) & S_BLOCK1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9403U)) & S_BLOCK1], 60U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8106U)) & W_KEY1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 6682U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 19U)) ^ (RotL64(aCarry, 37U) + RotL64(aPrevious, 54U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 3U)) + 1297415699043177788U) + aPhaseAOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 17583786534509260153U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 643197858925708798U) + aNonceWordP;
            aOrbiterB = (aWandererJ + RotL64(aCross, 21U)) + 5062653766915694874U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 11U)) + 7034273638367180511U;
            aOrbiterA = ((((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 2026909726972916996U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererF + RotL64(aScatter, 34U)) + 2785690475553211646U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 2910341716302991892U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2834181605200829791U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1510617068750957651U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13323052600571281928U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10434901530315760460U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 2042210188346767033U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 247903955625194782U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 5196515747387257163U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 1799024689023272275U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 7196305682377987476U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14777739876892587484U;
            aOrbiterD = RotL64((aOrbiterD * 95220583948241581U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 10609060796540136671U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8386027207212484155U;
            aOrbiterH = RotL64((aOrbiterH * 4855610536246556893U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 729659744301903424U) + aNonceWordN;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 2350564261412606157U;
            aOrbiterA = RotL64((aOrbiterA * 16713856782349084977U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 16611987556673864177U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1525195188708550503U;
            aOrbiterC = RotL64((aOrbiterC * 10045858602151004553U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterI, 29U)) + aOrbiterC) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aScatter, 40U) + aOrbiterA) + RotL64(aOrbiterF, 23U)) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 44U)) + aOrbiterI) + aPhaseAWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterD) + RotL64(aCarry, 57U)) + aNonceWordE);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 11U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererJ, 27U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15278U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14898U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14699U)) & W_KEY1], 41U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15916U)) & W_KEY1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 29U) + RotL64(aPrevious, 43U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 53U)) + 3621877681473089725U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 5U)) + 4451752751536414717U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 11371625415377772117U;
            aOrbiterB = (((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 6046792758881150619U) + aNonceWordN;
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 37U)) + 8213166120394461682U) + aPhaseAOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = ((aWandererI + RotL64(aCross, 44U)) + 4343156661140422645U) + aPhaseAOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 57U)) + 11105271483234947905U;
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 348904609985341372U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 12924652822526858767U;
            aOrbiterI = RotL64((aOrbiterI * 2801892489296408735U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 7461211697358520287U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 16551553555297890558U) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 16432952324635746293U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11908056404140782995U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9147367258259948715U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8876461054692728610U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 10546855952702525404U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 10071104785895309677U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4748636139110443794U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 783046909529525098U;
            aOrbiterH = RotL64((aOrbiterH * 8969157702460927215U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 16683965945838696665U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12385412690177109575U;
            aOrbiterG = RotL64((aOrbiterG * 10795062772707143187U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 8210546822184469023U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13146493623236979963U;
            aOrbiterE = RotL64((aOrbiterE * 13199947810161148155U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 51U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + RotL64(aOrbiterD, 47U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterG, 3U)) + aOrbiterI) + RotL64(aCarry, 3U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 60U) + aOrbiterB) + RotL64(aOrbiterI, 40U));
            aWandererD = aWandererD + (((((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 27U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordK) + aPhaseAWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 51U));
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererA);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 18476U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 17130U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19388U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 17342U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 29U) ^ RotL64(aCross, 13U)) + (RotL64(aPrevious, 60U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 5568146815535263910U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 7736084960873834666U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 11U)) + 1336413621817562093U) + aPhaseAOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 37U)) + 5218462026934984692U) + aNonceWordG;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 47U)) + 7048890985969555935U) + aNonceWordE;
            aOrbiterG = ((aWandererK + RotL64(aCross, 4U)) + 13415955213864702118U) + aPhaseAOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 39U)) + 5657023257021528548U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14338310943137497116U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 12305161641833950473U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11949964304435964395U), 29U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14514226578370459131U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12692904083266024340U;
            aOrbiterG = RotL64((aOrbiterG * 14800805065279908839U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11012959130001327964U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7106471380403489078U;
            aOrbiterC = RotL64((aOrbiterC * 515626559384817223U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 3718101961355280891U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 13364192077222322664U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1411328915372590283U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 6720867800318913440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14497243926965866546U;
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5789056168233262435U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 14438482587495779937U;
            aOrbiterI = RotL64((aOrbiterI * 10593535547917767263U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 313917798940179945U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 15241845511889502917U;
            aOrbiterF = RotL64((aOrbiterF * 16483477103771326107U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 46U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 37U)) + aOrbiterD) + RotL64(aCarry, 11U)) + aNonceWordD);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 57U) + RotL64(aOrbiterG, 13U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 20U)) + aOrbiterD) + aNonceWordA);
            aWandererA = aWandererA ^ ((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterB, 57U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 4U) + aOrbiterJ) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 43U)) + aOrbiterF);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterJ, 3U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 14U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24400U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneA[((aIndex + 26570U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24505U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 24933U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 13U) + RotL64(aIngress, 56U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 10726035965553989335U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 19U)) + 967354339530195662U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aScatter, 43U)) + 10834593005478605624U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aPrevious, 35U)) + 1012888282838656933U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 15283530351725183253U) + aNonceWordA;
            aOrbiterE = ((aWandererK + RotL64(aCross, 10U)) + 11724495956731703750U) + aNonceWordN;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 27U)) + 4288330117317505776U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 10894778070022873473U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 15563886747621617467U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17884709931569040065U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 11182488628562891937U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 10420140066310588580U;
            aOrbiterK = RotL64((aOrbiterK * 13898299782819948719U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11775138062167543111U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 16545391898578161683U;
            aOrbiterI = RotL64((aOrbiterI * 14588306527161321535U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 1550144656312299266U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 14903504853138279883U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 8003033561266164387U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 309935535526750396U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13991265868040011411U;
            aOrbiterD = RotL64((aOrbiterD * 2887531132228588441U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 1755976294857114222U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2259275858478396846U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7416165760067878161U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4838175912944552936U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12307900457200936013U;
            aOrbiterH = RotL64((aOrbiterH * 14719363144850838805U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterI, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 39U)) + aOrbiterG) + aNonceWordE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 57U)) + aOrbiterH) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 20U) + RotL64(aOrbiterD, 48U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterB, 29U)) + aNonceWordC);
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterG, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 42U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordE);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32408U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 29975U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29161U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((aIndex + 32495U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aPrevious, 11U)) ^ (RotL64(aIngress, 60U) + RotL64(aCross, 47U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterK = (aWandererD + RotL64(aCross, 48U)) + 4848316479321533394U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 35U)) + 6919360256662636195U) + aNonceWordK;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 53U)) + 9897013582181108544U;
            aOrbiterF = ((((aWandererK + RotL64(aIngress, 21U)) + RotL64(aCarry, 41U)) + 7319353809896158678U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 3U)) + 2848175435514849859U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 5U)) + 6967780718720437934U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 57U)) + 10143884766603388136U) + aPhaseAOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordD;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8675965006150972051U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 16350117755560994281U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15072308930382994425U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 17976597517118423760U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 1399631141355370237U;
            aOrbiterC = RotL64((aOrbiterC * 16537788276543236833U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 3590613762034716792U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 5134624314245932157U;
            aOrbiterB = RotL64((aOrbiterB * 13077589037975283371U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 10082236952942943654U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4015535035905433450U;
            aOrbiterH = RotL64((aOrbiterH * 4961808568701908559U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 611474103801573800U) + aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 5786708483794098001U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7694007039340089267U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 5201943497363274455U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9282160506938328489U;
            aOrbiterF = RotL64((aOrbiterF * 5368182164239021367U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 4932320527498940158U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11576526341731392916U;
            aOrbiterJ = RotL64((aOrbiterJ * 1712051774729439363U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 26U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + aNonceWordJ) + aPhaseAWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 13U) + aOrbiterC) + RotL64(aOrbiterF, 29U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 42U) + aOrbiterH) + RotL64(aOrbiterD, 5U)) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 57U)) + aOrbiterB) + aNonceWordH);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterF, 48U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordN);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xB6E22726016ED4C1ULL + 0xE105911B5494D49BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8E70BCB907528DEBULL + 0x810BE723E063DF77ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xBC8C6E3BFC85DF59ULL + 0xFD860E18CFDE05F0ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xEAC2D020D2803231ULL + 0xF5C4E4753CA50843ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF792537F03F33861ULL + 0x95C7340E06138867ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x838B65E3A04F9A03ULL + 0x8A867509A2285B49ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xAAD6618BBC93C439ULL + 0xC14EB905AB5279DDULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC73FDAFB808460CFULL + 0x8456D396BAD935ACULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xCB69670FE4EA723FULL + 0x9EE68FEA220C04DAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF608E197B3A37767ULL + 0xCE85667E7F37F189ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE70995FD9328DEBDULL + 0xEF240D0662C03DF7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x858A44D48D09CC2BULL + 0xAD614C3668527469ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAAFCB5C95AFA5DF5ULL + 0xD9DD4342EADD1E77ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x93714A97828794E9ULL + 0xAB1286BE7D098341ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB11369F62E82E8D3ULL + 0x802C61C4A5D94C82ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC05A7B3B718AE3C7ULL + 0xFA9D26E0CE1644DFULL);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4609U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4371U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1291U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2550U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 47U)) + 11450949896247900941U) + aNonceWordC;
            aOrbiterI = ((((aWandererE + RotL64(aCross, 4U)) + RotL64(aCarry, 11U)) + 3905542253538116335U) + aPhaseBOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1]) + aNonceWordM;
            aOrbiterK = (aWandererI + RotL64(aScatter, 13U)) + 9529740545977785305U;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 1856876631533143492U) + aNonceWordF;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 37U)) + 84253466320181686U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 12577480918745432444U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 5625703170397704029U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 13583960724598036659U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 694608607323629282U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3993981243536262204U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 2502835860198146381U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4119215953484892051U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 8785040118556157146U;
            aOrbiterB = RotL64((aOrbiterB * 17113521266125471625U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 16234403619456882890U) + aNonceWordA;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 10398727475672860610U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5086871400049644715U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 18327987141759096769U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2645964788056875452U;
            aOrbiterH = RotL64((aOrbiterH * 8778681366114628045U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterH, 3U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterK) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 41U)) + aOrbiterC);
            aWandererE = aWandererE + (((((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 37U)) + aNonceWordE) + aPhaseBWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 51U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + (RotL64(aWandererJ, 4U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordF;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6418U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9613U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5662U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5856U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 34U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterH = (((aWandererK + RotL64(aCross, 3U)) + 14499676118633326000U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 17191273593018552288U) + aNonceWordO;
            aOrbiterD = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 4085176294948097737U;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 44U)) + RotL64(aCarry, 5U)) + 11112671474158908186U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 23U)) + 8745787969012266485U) + aPhaseBOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18074049663777707948U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2543758649719164688U;
            aOrbiterD = RotL64((aOrbiterD * 7153845562786344373U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4659584749412700523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 974639159259871273U;
            aOrbiterF = RotL64((aOrbiterF * 17918719351847605523U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9211220687971081987U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterC) ^ 8567024626862182714U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 7755874089832496393U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 5803002132294840900U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11968489432878148467U;
            aOrbiterK = RotL64((aOrbiterK * 4501441062617123165U), 5U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 9470807228394903442U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 1692347973120388469U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 17433393164156231575U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aIngress, 4U) + RotL64(aOrbiterH, 35U)) + aOrbiterC) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterK, 57U));
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + RotL64(aOrbiterH, 19U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterC, 4U)) + aNonceWordF) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 38U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15689U)) & S_BLOCK1], 26U) ^ RotL64(aWorkLaneA[((aIndex + 13546U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15531U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((aIndex + 14560U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 6U) ^ RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = (((aWandererA + RotL64(aScatter, 34U)) + RotL64(aCarry, 3U)) + 10881271196314989997U) + aNonceWordJ;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 19U)) + 6406461249988567558U;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 17255067918280095959U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aWandererI + RotL64(aPrevious, 5U)) + 16690850682497718411U;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 13U)) + 5576201059361086866U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11991259685693687554U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 14652535244217836909U;
            aOrbiterB = RotL64((aOrbiterB * 18283959577075524171U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1701789037170782122U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 953429054903473833U;
            aOrbiterC = RotL64((aOrbiterC * 13482379459700651427U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 12064513610469714211U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 7993881398822002424U;
            aOrbiterA = RotL64((aOrbiterA * 11572884842788918377U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 14421313768013320050U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 11112386845630998889U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11771526352030371669U), 11U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 17069630896535699015U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3308240081138623373U) ^ aNonceWordB;
            aOrbiterK = RotL64((aOrbiterK * 10449509484417835159U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererA = aWandererA + ((((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterH, 52U)) + RotL64(aCarry, 37U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterC, 39U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 21U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseBWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterH, 29U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererA, 51U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 19149U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21277U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20759U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((aIndex + 17140U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 27U)) ^ (RotL64(aPrevious, 39U) + RotL64(aCross, 60U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterJ = (((aWandererH + RotL64(aPrevious, 21U)) + 13499155707765393469U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordG;
            aOrbiterE = (((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 41U)) + 3740324981823726185U) + aNonceWordD;
            aOrbiterK = ((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 5U)) + 5470765363949735652U;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 57U)) + 3446436171274452326U;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 5U)) + 1778929412631211933U) + aPhaseBOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14666308799855220954U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4548410236791175055U;
            aOrbiterK = RotL64((aOrbiterK * 6822908616815218501U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5829739767694190372U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 14319231414903675748U;
            aOrbiterJ = RotL64((aOrbiterJ * 4966501102515775601U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 1513851750246111405U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 1685620217748986019U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9286548037413609445U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 16284162182006054402U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 6271539598462003309U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13923286694131331137U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 12669312437565969473U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 11894755313393001665U;
            aOrbiterD = RotL64((aOrbiterD * 12556759675372354075U), 13U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 58U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + aOrbiterB) + RotL64(aOrbiterD, 6U)) + aNonceWordA);
            aWandererE = aWandererE + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 57U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterK, 29U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 6U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aPhaseBWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 27117U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 24959U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24881U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 24074U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 19U)) ^ (RotL64(aIngress, 53U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 5U)) + RotL64(aCarry, 19U)) + 3339283916456813609U;
            aOrbiterC = ((((aWandererH + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 11339086426180649584U) + aPhaseBOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (aWandererC + RotL64(aScatter, 13U)) + 16819191669329316585U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 8361916937762630725U) + aPhaseBOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 54U)) + 18031328374429899857U) + aNonceWordG;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 18261756894092897276U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4250319792907645666U;
            aOrbiterB = RotL64((aOrbiterB * 7053489184750217963U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 1492411503643460886U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17369549067879344180U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2947354306696216579U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 7301713524358676722U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2985193736033012535U;
            aOrbiterE = RotL64((aOrbiterE * 7473297294949338265U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14086975808140927408U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10390516547834639800U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11441293212275890819U), 43U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterE) + 18205555540941493267U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16967799565443938873U;
            aOrbiterI = RotL64((aOrbiterI * 3009081009044782443U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterF, 30U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + RotL64(aCarry, 5U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 21U)) + aOrbiterE) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterF, 3U)) + aOrbiterE) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 37U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 28048U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30851U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29324U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 32128U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 23U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 9471546960258473684U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 35U)) + 18050235435948942244U) + aPhaseBOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = (((aWandererH + RotL64(aIngress, 51U)) + RotL64(aCarry, 39U)) + 3005107102671544641U) + aPhaseBOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = (((aWandererD + RotL64(aScatter, 10U)) + RotL64(aCarry, 51U)) + 17898396434573801850U) + aNonceWordB;
            aOrbiterH = (aWandererK + RotL64(aCross, 43U)) + 15071602525497771648U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5780119462702672108U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 13301326224151025687U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 2868878978993219351U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 18129323022260575961U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 1199228670638790709U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1780426336211781025U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 1839199978088021020U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4999517042246790165U;
            aOrbiterG = RotL64((aOrbiterG * 4585813675677234577U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 8788607633376516299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15143903839930468749U;
            aOrbiterE = RotL64((aOrbiterE * 12735914889325422675U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16674732686428431869U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15908873150953195581U;
            aOrbiterH = RotL64((aOrbiterH * 18049755517524334107U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterG, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 51U)) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterK, 18U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 10U) + RotL64(aOrbiterF, 39U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + aNonceWordP);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordN;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xD70B36238BB34655ULL + 0xFCDE527A4CFBDE02ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC9469CDE970258D7ULL + 0xEE303C461BE03B9DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE02071461BBB7E35ULL + 0xAE9AE4F070A0CD61ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x98217482B7CA38FDULL + 0xFABAE6C387940764ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC15A9CE0A54D7905ULL + 0xF77BCEFADD8BEDCAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD1E14D9C585EBF8BULL + 0xB9FC9F994C0C1793ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF01989417F6B1435ULL + 0xDF9C8F41883C5EBEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x84230B188A2795EFULL + 0xFBB5347E1AF94E89ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x9C99540EC4185D95ULL + 0xBC6061DBE229EE3FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xC09AA18466FC0005ULL + 0x81EBDBCE13121CC6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xC78B71842EBFAEF3ULL + 0x858110EA41F8D406ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xE1AD156D5967610DULL + 0x95451FB3B84C4150ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF29F3EE09B28844DULL + 0xF4E60DA955B5FEC4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB06EAEECC97EE2C9ULL + 0x917EC81243E8FB3BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xA56C0EE2C4495AE7ULL + 0x848D41F1575F66D7ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD31A05CADB0BD9D5ULL + 0xD2EC88114C2EBE4DULL);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3980U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7478U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3423U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 4949U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 38U)) + 2974056819475622600U) + aPhaseCOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aScatter, 19U)) + 7345051759236356098U) + aNonceWordI;
            aOrbiterK = (aWandererG + RotL64(aCross, 11U)) + 12738468816846628882U;
            aOrbiterE = ((aWandererE + RotL64(aIngress, 27U)) + 7694520596043297922U) + aPhaseCOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 5530753590015084774U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 23U)) + 3776309161718383105U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 784780304358106404U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 8999942326995036509U) + aNonceWordG;
            aOrbiterC = (aWandererA + RotL64(aIngress, 60U)) + 5194986506064092779U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7920040007459652762U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11311997270710107937U;
            aOrbiterK = RotL64((aOrbiterK * 6227571709361790209U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5365231114813547251U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 8630110234623825263U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 2735881715888325759U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2358235238039571072U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18059414891616491807U;
            aOrbiterI = RotL64((aOrbiterI * 17150786106857185467U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14526050556461782864U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 6937282036603272474U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14954512365270028029U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10105832250694931310U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 3884223553012098137U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16340956813003906195U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10385284339549648087U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 1257633893341505930U;
            aOrbiterE = RotL64((aOrbiterE * 2669950791270500977U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5528890519572824318U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15664241747527713256U;
            aOrbiterH = RotL64((aOrbiterH * 16670884497088220497U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 14264122979415331887U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17985061405540198036U;
            aOrbiterB = RotL64((aOrbiterB * 2729487440173395133U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 1663986734997903415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3706166884286400587U;
            aOrbiterJ = RotL64((aOrbiterJ * 10549736618301955745U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 24U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 48U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 18U) + aOrbiterC) + RotL64(aOrbiterK, 27U)) + aNonceWordH);
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 39U)) + aOrbiterH) + aPhaseCWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterC, 43U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aScatter, 46U) + aOrbiterJ) + RotL64(aOrbiterC, 3U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererB = aWandererB + (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 20U)) + aOrbiterE) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8637U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneD[((aIndex + 13227U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10207U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((aIndex + 13420U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 10U) ^ RotL64(aIngress, 43U)) + (RotL64(aCarry, 57U) + RotL64(aPrevious, 27U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterI = ((((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 12849591986267890852U) + aPhaseCOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 6U)) + 8232614804696815750U;
            aOrbiterB = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 21U)) + 12141567259210877281U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 19U)) + 2928641981037885644U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 35U)) + 980733350554783938U) + aPhaseCOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 2683985177993350746U;
            aOrbiterK = ((aWandererK + RotL64(aCross, 43U)) + 14532148403815527355U) + aNonceWordF;
            aOrbiterA = (aWandererB + RotL64(aScatter, 29U)) + 7736296629433884203U;
            aOrbiterE = (aWandererA + RotL64(aCross, 13U)) + 10428437770166310549U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 18327174144859461029U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6810436935194432002U;
            aOrbiterB = RotL64((aOrbiterB * 2715987179577753597U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 12606153309690753435U) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17123256945895150555U;
            aOrbiterC = RotL64((aOrbiterC * 13469111258504672565U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9057777759026189541U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 16478485918911194442U;
            aOrbiterK = RotL64((aOrbiterK * 11054247078884894131U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 18064460487552100483U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11477276762421684083U;
            aOrbiterA = RotL64((aOrbiterA * 3886501230380184395U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 18318375441973295081U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 13849305985380030986U;
            aOrbiterE = RotL64((aOrbiterE * 12962140243967824959U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 10240409420338313641U) + aNonceWordJ;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18360586077779529086U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18196875422391501927U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 16801797158622424257U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4950305991208513887U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4437082499761416951U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 15790878572843321918U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 9808781805065559728U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9394280083159162953U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 11974996650410830731U) + aNonceWordD;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4955004489435232515U;
            aOrbiterJ = RotL64((aOrbiterJ * 13301966529515483085U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 52U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 48U) + RotL64(aOrbiterE, 41U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + aOrbiterI) + RotL64(aOrbiterA, 34U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC);
            aWandererA = aWandererA + (((((RotL64(aCross, 13U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordK) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterH, 29U));
            aWandererD = aWandererD + ((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterI, 14U)) + aOrbiterB);
            aWandererH = aWandererH + ((((RotL64(aScatter, 34U) + aOrbiterJ) + RotL64(aOrbiterE, 23U)) + RotL64(aCarry, 37U)) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 24U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20324U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19739U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18894U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((aIndex + 20954U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 51U)) + (RotL64(aCross, 23U) ^ RotL64(aPrevious, 36U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 39U)) + RotL64(aCarry, 35U)) + 3199575576585871314U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aCross, 34U)) + 2533378188975571824U;
            aOrbiterA = (aWandererE + RotL64(aIngress, 43U)) + 6819782112558312658U;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 12690060987724798497U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aScatter, 51U)) + 7088375139715629606U;
            aOrbiterF = (aWandererG + RotL64(aCross, 11U)) + 17785618677423695666U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 30U)) + RotL64(aCarry, 23U)) + 1714999280296491277U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 3U)) + 17611338506932491624U) + aNonceWordG;
            aOrbiterD = (aWandererB + RotL64(aIngress, 47U)) + 6475727359297421201U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2347744591204119530U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2739317903351401068U;
            aOrbiterA = RotL64((aOrbiterA * 15435029315209475631U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 8663535261373274338U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8205245127823536479U;
            aOrbiterB = RotL64((aOrbiterB * 13857005110466856439U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8916510616749754516U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 3944805940148512932U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 18082271583211389701U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14094751253118853302U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 14094299829196076311U;
            aOrbiterI = RotL64((aOrbiterI * 6370012560657108493U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3940673811518673802U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 3015106523254484839U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 9655401190755573379U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 15404103131982599922U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 1828655763233900875U;
            aOrbiterF = RotL64((aOrbiterF * 13024358077740310049U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1236981890899916502U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 18208975564570342697U;
            aOrbiterG = RotL64((aOrbiterG * 4577109989465876801U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17882273895471449661U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16196010765612713713U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15624856645134182005U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 14639250100311162559U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9139027997336903273U;
            aOrbiterD = RotL64((aOrbiterD * 1853126389565574293U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 53U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterI, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterC);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 35U)) + aOrbiterF) + aNonceWordJ);
            aWandererC = aWandererC + ((RotL64(aCross, 43U) + RotL64(aOrbiterC, 46U)) + aOrbiterF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 23U)) + aOrbiterD) + aPhaseCWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 37U) + RotL64(aOrbiterI, 27U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterD, 13U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 18U) + RotL64(aOrbiterB, 56U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 19U)) + aOrbiterK);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterI, 51U)) + aNonceWordO) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 4U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31526U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 29137U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28563U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 27480U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aIngress, 51U)) ^ (RotL64(aCross, 4U) + RotL64(aPrevious, 35U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterE = ((aWandererF + RotL64(aIngress, 51U)) + 13583136155674166402U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aScatter, 35U)) + 12830472187484919497U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 30U)) + 18081197909484522509U;
            aOrbiterA = (aWandererI + RotL64(aCross, 3U)) + 8680634051297891550U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 13939998767458656823U) + aNonceWordA;
            aOrbiterD = (aWandererG + RotL64(aCross, 19U)) + 1795730579103692594U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 44U)) + RotL64(aCarry, 47U)) + 17369751719734069999U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 39U)) + RotL64(aCarry, 35U)) + 224769585901248068U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 11U)) + 4133547085925268180U) + aPhaseCOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 7022512056309567391U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 10319484359046945495U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 3400140531307001933U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 10483878349412282069U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6481381149199985736U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 9701719367082506253U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13721077228796934509U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9704818014314175007U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 760445624027740287U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6253040047758584339U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16890211690273641226U;
            aOrbiterE = RotL64((aOrbiterE * 5622534399866057841U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 6216227831265032436U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 2023609047004658739U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3252332895698310147U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9201669637050388263U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5106927540934338576U;
            aOrbiterD = RotL64((aOrbiterD * 6368134569042291431U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10080368957861445998U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10784789383436485808U;
            aOrbiterK = RotL64((aOrbiterK * 3794918350254445939U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15426339824951793026U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 17637144549368340331U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10971293914614704441U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 9941300382181962134U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8118046374121322097U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8481945819050983127U), 19U);
            //
            aIngress = RotL64(aOrbiterI, 19U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 6U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 56U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 21U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aPhaseCWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 10U) + aOrbiterA) + RotL64(aOrbiterB, 43U));
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 51U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterD, 5U)) + aNonceWordE);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterB);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterK) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 14U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 14U) + aOrbiterK) + RotL64(aOrbiterH, 27U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 44U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordE);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB7AF4C92AD15D04FULL + 0xFA7A437F43AC0E25ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x99DF9CAE713A9369ULL + 0x9863346A5BB41040ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC7FBC1B1A0E61257ULL + 0x85C683BE5FBC652DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xE6E6284ED4777B53ULL + 0xE8232C63509CA6FDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB9BEA608A4021755ULL + 0xF690BCB41A9CDD09ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB81D45D60462F2E3ULL + 0x858E0D9533E49AE0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xA1B0996D04B94B6DULL + 0x87596AB695F17123ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x96B44298B7855B4BULL + 0xD209CDCA2F2200BAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA2231B3291CD82E7ULL + 0xCEA880A05F633464ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x87D6C8E90BE96A57ULL + 0xAE1C93445C9B534EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xC4949909770AEE51ULL + 0xFB9850DE9B32FE85ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x86808D5B2A68260DULL + 0xF19BC70A41B41417ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x9EDB9553B76A3DD1ULL + 0xF6CDA1F324847468ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF9A7D0D09C41F9EDULL + 0xB4AEF94298C04EAFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x82B82E062158E35DULL + 0xCD06677FA8BE3F19ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xC38684F977F82503ULL + 0x97945D33745BF785ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 486U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 2443U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4758U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4284U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 50U) + RotL64(aCarry, 37U)) + (RotL64(aCross, 3U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aIngress, 10U)) + 14157904117287696136U;
            aOrbiterC = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 53U)) + 7369512677371640676U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 27U)) + 8411250745902073798U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 5002041814539710275U) + aPhaseDOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererG + RotL64(aPrevious, 13U)) + 9538041410816283124U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 43U)) + 5210700103927513061U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 51U)) + 7600709399101287982U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 3U)) + 2366369466696580499U;
            aOrbiterH = (aWandererF + RotL64(aPrevious, 19U)) + 5544575244203019109U;
            aOrbiterG = (aWandererH + RotL64(aScatter, 41U)) + 8710073749110329779U;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 47U)) + 15998211310115361630U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15354357553877376422U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 10657523549259276169U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13695239532898311073U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10405750198355464768U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3465819693133515142U;
            aOrbiterB = RotL64((aOrbiterB * 14678343718277562799U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16724189641701408630U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3484340153620198872U;
            aOrbiterJ = RotL64((aOrbiterJ * 17247547677520703125U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7420442404884871126U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11138445997256757636U) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 11167543379937571127U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 1428191560884663125U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 16950093140800653985U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4423012306984814805U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17288299075036481960U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 13793597915359681028U;
            aOrbiterH = RotL64((aOrbiterH * 9639204979982125757U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5017972942710079726U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12409957957614320964U;
            aOrbiterD = RotL64((aOrbiterD * 10273295741911545745U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 12487994181992095174U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1573393166996612118U;
            aOrbiterC = RotL64((aOrbiterC * 13364311829104520751U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13227642825780350128U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7961292096150889569U;
            aOrbiterA = RotL64((aOrbiterA * 16627209081334341289U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 10312485102088913337U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3177620041478410950U;
            aOrbiterE = RotL64((aOrbiterE * 15918551366833593853U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2599092792737616563U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14157904117287696136U;
            aOrbiterG = RotL64((aOrbiterG * 14883446269291639813U), 53U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 28U);
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 39U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterF, 37U));
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ) + RotL64(aCarry, 43U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 50U) + aOrbiterE) + RotL64(aOrbiterD, 21U)) + aNonceWordO);
            aWandererA = aWandererA + (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterD, 18U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 5U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aPrevious, 29U) + aOrbiterD) + RotL64(aOrbiterH, 39U));
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterA, 51U)) + aNonceWordJ);
            aWandererH = aWandererH + ((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterC, 53U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + aNonceWordE) + aPhaseDWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterK, 60U)) + aPhaseDWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 42U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordP);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 7507U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((aIndex + 6483U)) & S_BLOCK1], 24U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9730U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((aIndex + 6794U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 35U)) ^ (RotL64(aCross, 53U) ^ RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererE + RotL64(aIngress, 44U)) + RotL64(aCarry, 57U)) + 12136097566601676613U;
            aOrbiterK = (aWandererH + RotL64(aPrevious, 47U)) + 7969431322248040056U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 41U)) + 10530676021510553889U;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 8740777303075445264U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 13U)) + 13249434169895564739U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 30U)) + 15529577005925628472U) + aNonceWordI;
            aOrbiterF = (aWandererD + RotL64(aScatter, 41U)) + 344627093687331562U;
            aOrbiterC = (aWandererK + RotL64(aCross, 27U)) + 8824277416519988893U;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 57U)) + 5636276438449709875U) + aNonceWordK;
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 37U)) + 2079413361031851552U) + aPhaseDOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 35U)) + 7807998179168655561U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 13589392896232029112U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10733011474804473996U;
            aOrbiterG = RotL64((aOrbiterG * 361749145931578805U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15934162328347805968U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7573511217796245232U;
            aOrbiterK = RotL64((aOrbiterK * 10694563909931636155U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4828475187337891975U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 13284974329890393113U;
            aOrbiterE = RotL64((aOrbiterE * 10831075817642374287U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 13173869918669643112U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterC) ^ 15841507674783398167U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 15632933198136963277U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14168272451055700516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 11134471485501999898U;
            aOrbiterB = RotL64((aOrbiterB * 8019507184494591705U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2611858916687822610U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 17863271539727513641U;
            aOrbiterH = RotL64((aOrbiterH * 4987884722174985677U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8874401993454249066U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 5131480593493950665U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8585874663602346121U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9366563022381918996U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7890729519928340296U;
            aOrbiterJ = RotL64((aOrbiterJ * 11428572374057899517U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 131774386529223292U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4108356674478240148U;
            aOrbiterC = RotL64((aOrbiterC * 2492753294539081613U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 7651738365157869789U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 2745458108574051004U;
            aOrbiterA = RotL64((aOrbiterA * 2175955806036373729U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 10492013124307434604U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12136097566601676613U;
            aOrbiterD = RotL64((aOrbiterD * 13128652803485742119U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 34U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 39U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterH, 36U)) + aPhaseDWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterA, 13U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aCross, 54U) + RotL64(aOrbiterF, 11U)) + aOrbiterE) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 57U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 27U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 38U)) + aOrbiterF) + aNonceWordD);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererC = aWandererC + ((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterH, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + RotL64(aWandererD, 34U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15012U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12760U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11683U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 15749U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 19U)) + 13333509828310369865U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 43U)) + 7645352517103840797U) + aNonceWordP;
            aOrbiterH = ((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 27U)) + 5310766306660062655U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 23U)) + 5165635069832352932U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = (aWandererB + RotL64(aScatter, 37U)) + 15684141764734281849U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 3U)) + 3327963374225061738U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 3U)) + 8625811794878848871U;
            aOrbiterD = (aWandererC + RotL64(aCross, 47U)) + 7598657468430485291U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 57U)) + 2881171216276746485U) + aNonceWordO;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 10237691227222918101U;
            aOrbiterK = (aWandererG + RotL64(aCross, 27U)) + 6419254255884834497U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4238455444646479956U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14936613353493061492U;
            aOrbiterH = RotL64((aOrbiterH * 3544216916806292273U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15324699725208372627U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 9506640480601832011U;
            aOrbiterG = RotL64((aOrbiterG * 12819564111348390227U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 3709149613660215641U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1724290199312754307U;
            aOrbiterF = RotL64((aOrbiterF * 12597580418257897965U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13191172833570139194U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 3686087945377837886U;
            aOrbiterC = RotL64((aOrbiterC * 10883609557429936283U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 10418330386245397022U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5383531313632347245U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 2987755379396160073U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7414716553072652212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 11301761123966206201U;
            aOrbiterA = RotL64((aOrbiterA * 1546727321088592187U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 8570229732236388847U) + aNonceWordG;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 8773754460060264773U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3251360788932563495U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 13636929800504199371U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5486599841558573720U;
            aOrbiterB = RotL64((aOrbiterB * 2867914211589815153U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 13277541451512422776U) + aNonceWordK;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 10409779509190185921U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1926650154570961573U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 7268295836403414306U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13815969853235433830U;
            aOrbiterJ = RotL64((aOrbiterJ * 11603750346752441535U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 9353249174240162324U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 13333509828310369865U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10381405217943841655U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 5U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 21U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterJ, 51U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterI, 24U)) + RotL64(aCarry, 39U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 3U)) + aOrbiterD) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterD, 39U)) + aOrbiterC) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterH, 29U)) + aNonceWordB);
            aWandererG = aWandererG ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 53U)) + aOrbiterI) + aNonceWordE);
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + aOrbiterE) + RotL64(aOrbiterG, 37U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterJ, 47U));
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterF, 34U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 36U));
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererB, 27U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 17440U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 18540U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17137U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneD[((aIndex + 19404U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 50U)) + (RotL64(aCross, 35U) ^ RotL64(aIngress, 19U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererD + RotL64(aCross, 26U)) + RotL64(aCarry, 57U)) + 4751694786009671052U;
            aOrbiterE = (aWandererC + RotL64(aIngress, 41U)) + 16362725160370844224U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 29U)) + 6360885380915941057U;
            aOrbiterC = (((aWandererK + RotL64(aScatter, 5U)) + 5154536007972297036U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (aWandererF + RotL64(aCross, 37U)) + 9362540581874808253U;
            aOrbiterF = (aWandererE + RotL64(aScatter, 21U)) + 13902493871525612934U;
            aOrbiterB = (((aWandererG + RotL64(aPrevious, 23U)) + RotL64(aCarry, 27U)) + 10208452885367546542U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aIngress, 19U)) + 3117030377279160998U) + aNonceWordO;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 17286247690414027870U;
            aOrbiterI = (aWandererI + RotL64(aCross, 11U)) + 3930314320040949141U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 60U)) + 7289525252391668404U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3434167955466809185U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17852573095128575663U;
            aOrbiterJ = RotL64((aOrbiterJ * 1485660158767033425U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 6137259687928853253U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 13992510605237574698U;
            aOrbiterK = RotL64((aOrbiterK * 15346263295995333395U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 6470556523400123474U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4333255670390099293U;
            aOrbiterF = RotL64((aOrbiterF * 11089933812030082647U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7700424876430257995U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16920736951239453071U;
            aOrbiterB = RotL64((aOrbiterB * 8920407493132380497U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 1635071690430295730U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 9966700845966398620U;
            aOrbiterD = RotL64((aOrbiterD * 17210048121896546867U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9833458070123027075U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1990346556486746432U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8704943923474148699U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 13339523466436517327U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 5018264760406215603U;
            aOrbiterI = RotL64((aOrbiterI * 2769197961801783627U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 123427497520755346U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 4535841104215792886U;
            aOrbiterH = RotL64((aOrbiterH * 1417676310539177131U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3525925567359163763U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 3273741481392187986U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 16116160744647235811U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 6230742908784102407U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7578784912496239362U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2614448818452560369U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 14669810330213234082U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4751694786009671052U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 9583151676882991817U), 19U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterB, 41U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 43U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterG, 52U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 19U));
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterG, 35U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 58U) + aOrbiterF) + RotL64(aOrbiterH, 27U)) + aPhaseDWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 3U)) + aNonceWordK) + aPhaseDWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 47U) + aOrbiterK) + RotL64(aOrbiterG, 29U));
            aWandererE = aWandererE + (((RotL64(aCross, 53U) + aOrbiterC) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 10U) + aOrbiterH) + RotL64(aOrbiterD, 54U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterE, 37U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 43U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23891U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneA[((aIndex + 23468U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26599U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneA[((aIndex + 25715U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 51U) + RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aScatter, 13U)) + 18180797995100240808U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 6U)) + 6585906608223552885U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 14088708930575939855U;
            aOrbiterG = (aWandererK + RotL64(aIngress, 53U)) + 468974153311516044U;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 41U)) + 12481951025619894110U;
            aOrbiterI = (((aWandererA + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 17227987923860711763U) + aPhaseDOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aIngress, 36U)) + 4373962756657477139U;
            aOrbiterH = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 2077576476565420951U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 39U)) + 17435011300234663764U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 51U)) + 4118039398293246896U) + aNonceWordD;
            aOrbiterE = (aWandererG + RotL64(aIngress, 23U)) + 13724716599855216683U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12391461204689596339U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 9900605191533799627U;
            aOrbiterK = RotL64((aOrbiterK * 13553565332531046301U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 972946858824366125U) + aNonceWordE;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 17247681919694541215U;
            aOrbiterI = RotL64((aOrbiterI * 2974639094630445643U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 15442851427306771601U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 7303586227288294037U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15406402525021428799U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 12650358753454105119U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 1483710933373510492U;
            aOrbiterJ = RotL64((aOrbiterJ * 6531763256577221891U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 18065810162229740788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 11311677121338794007U;
            aOrbiterB = RotL64((aOrbiterB * 15116367961682119467U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2355285311890287611U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 1287783821903407734U;
            aOrbiterG = RotL64((aOrbiterG * 8054011680932255985U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9282654686791135654U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15488608017745542551U;
            aOrbiterC = RotL64((aOrbiterC * 7858866274035085123U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 13296835576073421802U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 7127700236018338741U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11246173563106014149U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1365928843264598789U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 7777790578813003657U;
            aOrbiterE = RotL64((aOrbiterE * 10121688100505628161U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2104270617375082523U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 13363764449819651164U;
            aOrbiterF = RotL64((aOrbiterF * 2685452132715528975U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 2008038686059197988U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 18180797995100240808U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8978998151475372047U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 11U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 35U));
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterK, 13U));
            aWandererC = aWandererC + (((RotL64(aCross, 41U) + RotL64(aOrbiterB, 5U)) + aOrbiterG) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 18U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 26U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 11U)) + aOrbiterH);
            aWandererB = aWandererB + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterD, 21U)) + aPhaseDWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterC, 50U)) + aPhaseDWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + aNonceWordA);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterC, 3U));
            aWandererF = aWandererF + ((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 57U)) + aOrbiterF);
            aWandererG = aWandererG ^ (((RotL64(aCross, 38U) + RotL64(aOrbiterA, 53U)) + aOrbiterC) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 54U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 38U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordC);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28335U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27808U)) & S_BLOCK1], 30U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28251U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 29293U)) & S_BLOCK1], 12U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 29U) ^ RotL64(aCarry, 57U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 44U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterE = (aWandererK + RotL64(aPrevious, 47U)) + 701291026547470433U;
            aOrbiterK = (((aWandererD + RotL64(aIngress, 57U)) + 17283292650462111643U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = (aWandererI + RotL64(aCross, 54U)) + 9969124091931303406U;
            aOrbiterD = (aWandererA + RotL64(aScatter, 29U)) + 889176772718046988U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 19U)) + 6054541844643748084U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 43U)) + 14703226235143028132U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aCross, 14U)) + 7977975878522921062U) + aNonceWordG;
            aOrbiterC = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 16894322614172266274U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 35U)) + 12160451749345900570U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 10870847008043897470U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 37U)) + 8159920947172520247U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2440099120969517932U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2428396147731468007U;
            aOrbiterA = RotL64((aOrbiterA * 9363073341539598441U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 2213226274394673479U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7079731443427765333U;
            aOrbiterF = RotL64((aOrbiterF * 16918930776877030559U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 958896789550478970U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 10788682955708075458U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 913321215613559729U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2003386579317564870U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 8419686358774204999U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6547052526438697621U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6989167615157578904U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 17636634003643824148U;
            aOrbiterC = RotL64((aOrbiterC * 11038576417283732937U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13824962118933907859U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9543912892587859646U;
            aOrbiterI = RotL64((aOrbiterI * 14736710162285997415U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15729878041027706114U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9542137475454825463U;
            aOrbiterG = RotL64((aOrbiterG * 11420547128115090491U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5327302277575009955U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2707383132257428583U;
            aOrbiterB = RotL64((aOrbiterB * 6120763309390182129U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9008601903853562620U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11050463189491777908U;
            aOrbiterE = RotL64((aOrbiterE * 9178386878636430553U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14683684132116778056U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5390271065690907120U;
            aOrbiterK = RotL64((aOrbiterK * 17903005409098232619U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 5183407290520277451U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 701291026547470433U;
            aOrbiterD = RotL64((aOrbiterD * 16329261100139524239U), 37U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 14U));
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 6U) + aOrbiterJ) + RotL64(aOrbiterI, 24U)) + aNonceWordA);
            aWandererK = aWandererK + (((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterI, 29U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 51U) + aOrbiterC) + RotL64(aOrbiterI, 43U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterD, 5U)) + aOrbiterK) + aNonceWordF);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 12U)) + aOrbiterE) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 23U) + aOrbiterI) + RotL64(aOrbiterK, 37U)) + aPhaseDWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterF, 21U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH + (((RotL64(aScatter, 56U) + aOrbiterK) + RotL64(aOrbiterG, 27U)) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 57U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererD, 6U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordN;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBF8395190C3386D3ULL + 0xA2065C007FDCFE9DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9BB4ACD4160002CBULL + 0xF4E10FA899308DAFULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xECA87FC856E8DE39ULL + 0xB1591AD05D7507BCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x8F254E43D0F8047FULL + 0xAC68D01928E7A735ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB0F26A06780E8743ULL + 0xBFD443DEF02CABE6ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE81872A7A464C385ULL + 0x84BF5E3812C9217BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0x94B349B279A02EBDULL + 0xDBA4B1D491C74F5CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xD98B96500360DA0FULL + 0xAD00487B08F6547BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xA848E91F330F205DULL + 0x94EF6E96485BF4E3ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA4764C9E88FCC71DULL + 0x982B3B193AB22CABULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC2C558E954F21809ULL + 0xD56613B3B621E3C1ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA9A0B9D4D5017A2BULL + 0xC5ADD0391756FA12ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD32794F0D80C7C93ULL + 0xF43DB005222B2CBFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE5357EF45B989DAFULL + 0xE98F10FBCDB6D138ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE6184C8633527165ULL + 0x92128F5EA67BB9E3ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFA083C5AD523BAEBULL + 0xF7693C2BAABA23B8ULL);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 3978U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2745U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5097U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((aIndex + 1035U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 57U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 36U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterB = ((aWandererC + RotL64(aCross, 5U)) + RotL64(aCarry, 51U)) + 15726877954695761686U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 14187652171881943587U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 43U)) + 8420423151313882782U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 27U)) + RotL64(aCarry, 47U)) + 14942322692433259283U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 57U)) + 7272331475919796255U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aCross, 52U)) + 154504365041805840U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 13U)) + 17475491222554948786U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 21U)) + 5759181483165339605U) + aPhaseEOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererD + RotL64(aCross, 11U)) + 5993060214499322845U) + aNonceWordB;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 48U)) + 10901786237875941844U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 37U)) + 17135786595614068473U) + aNonceWordJ;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 5208202073886811165U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 6821452921018900631U;
            aOrbiterH = RotL64((aOrbiterH * 13119330055184115669U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 13348064837402206969U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8967943922403445136U;
            aOrbiterI = RotL64((aOrbiterI * 300168481725373093U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8130283784171430891U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6351113882502502876U;
            aOrbiterB = RotL64((aOrbiterB * 15960622823993072903U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6894708729226455769U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12065058511247133944U;
            aOrbiterD = RotL64((aOrbiterD * 5432601727436935831U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17138279326229372741U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 12987698199066890628U;
            aOrbiterJ = RotL64((aOrbiterJ * 12665716655177320977U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 13688833537574196675U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 4211971980434000618U;
            aOrbiterF = RotL64((aOrbiterF * 1374411763361518851U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10376917117582537592U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4807742522197923516U;
            aOrbiterA = RotL64((aOrbiterA * 15257251453302090961U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18038296468177121243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6879666349379745258U;
            aOrbiterC = RotL64((aOrbiterC * 15819475269715810555U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 5193656664432659624U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 680899397323387963U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 9857476056194621321U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1851929589073547860U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13093101559415170218U;
            aOrbiterE = RotL64((aOrbiterE * 13950928576652143737U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13695333301427028607U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15726877954695761686U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 960063676226172027U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterH, 41U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterE, 10U)) + aOrbiterA) + aNonceWordO);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 56U) + aOrbiterE) + RotL64(aOrbiterC, 47U));
            aWandererD = aWandererD + (((RotL64(aIngress, 51U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 39U)) + aOrbiterB);
            aWandererA = aWandererA + ((((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 35U)) + aPhaseEWandererUpdateSaltF[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterD, 3U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterI, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 24U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 18U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 42U));
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 58U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 7561U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneD[((aIndex + 6172U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8224U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5830U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 4U)) ^ (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 8975885703279267062U) + aNonceWordN;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 11U)) + 8664844915562660637U) + aPhaseEOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aCross, 5U)) + 12281774799736296726U;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 34U)) + 15347461352311329726U) + aPhaseEOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aScatter, 47U)) + 12967500561828907834U) + aNonceWordE;
            aOrbiterE = ((aWandererJ + RotL64(aPrevious, 3U)) + 5002833859280402726U) + aNonceWordL;
            aOrbiterD = (aWandererH + RotL64(aCross, 21U)) + 11908257536954668983U;
            aOrbiterG = (aWandererC + RotL64(aIngress, 23U)) + 17017174811949227162U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 50U)) + RotL64(aCarry, 27U)) + 16851323125613931180U;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 3U)) + 13469326957728686706U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 41U)) + 5228638551056105241U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11945166198089308564U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16268645041872996022U;
            aOrbiterI = RotL64((aOrbiterI * 5391448793718370911U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 14781204627695095701U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 5365325354838101092U;
            aOrbiterK = RotL64((aOrbiterK * 8017284997946310807U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 563147416025715953U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 14660867395395625851U;
            aOrbiterC = RotL64((aOrbiterC * 4769458126865307103U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3168989056355712105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 16179131669773665579U;
            aOrbiterD = RotL64((aOrbiterD * 5641461617066671723U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4160220074225527179U) + aNonceWordA;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 8597134686962559111U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 639572585431474015U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16811551552456811661U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5827323970423386301U;
            aOrbiterA = RotL64((aOrbiterA * 9328247349730652021U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 15583234353262170227U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2950816254621717748U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1102417597476170143U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 4426165025104306337U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 11871220132164971152U;
            aOrbiterE = RotL64((aOrbiterE * 2366168050042802207U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 3832424136113939717U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17673885217916768611U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 10887063696370811871U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3479289844909914390U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9498461576098567546U;
            aOrbiterB = RotL64((aOrbiterB * 8734492074299676555U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10645314291190544864U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8975885703279267062U;
            aOrbiterH = RotL64((aOrbiterH * 16584086014947250551U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 58U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterA, 48U)) + aOrbiterI) + aPhaseEWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterK, 13U));
            aWandererH = aWandererH + (((RotL64(aCross, 39U) + RotL64(aOrbiterD, 4U)) + aOrbiterJ) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterA, 53U)) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + RotL64(aOrbiterI, 29U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 28U) + aOrbiterG) + RotL64(aOrbiterI, 57U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 6U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererH);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 36U));
            aCarry = aCarry + RotL64(aWandererG, 41U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 16333U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((aIndex + 11353U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12125U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneC[((aIndex + 13456U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 52U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 966899917801652720U;
            aOrbiterH = (aWandererE + RotL64(aCross, 35U)) + 10996327672320748649U;
            aOrbiterA = (aWandererD + RotL64(aIngress, 13U)) + 4188171566846621107U;
            aOrbiterG = ((aWandererG + RotL64(aScatter, 5U)) + 5886209243097387959U) + aNonceWordK;
            aOrbiterK = ((aWandererH + RotL64(aCross, 60U)) + 14940428957136728111U) + aPhaseEOrbiterAssignSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 179187285531914832U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 6685351948936817752U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 47U)) + 1894506461704029700U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 11U)) + 4182760368636977082U;
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 3U)) + 12523318028514940790U;
            aOrbiterB = (aWandererF + RotL64(aCross, 54U)) + 5059306166973366892U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5890872367917643851U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 17747338389865221534U;
            aOrbiterA = RotL64((aOrbiterA * 5306740664798049267U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13906227834259884100U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 7152105382899756368U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 6772157117358310485U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17868101884759619240U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 11758843266314148347U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5919135169337501485U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13950566197090324859U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17278105609930477854U;
            aOrbiterK = RotL64((aOrbiterK * 11431842718945107359U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9556785965646738355U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 841298436857932987U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15077843186688841797U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 1951515285492133830U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15775839819330588437U;
            aOrbiterJ = RotL64((aOrbiterJ * 7902654031401620995U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5585458468816495436U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17258586689032223623U;
            aOrbiterE = RotL64((aOrbiterE * 1652050227399194271U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 5254132659445988836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15440741734777060925U;
            aOrbiterG = RotL64((aOrbiterG * 17445581079035134067U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 16770361602586485631U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 14902616717976301965U;
            aOrbiterF = RotL64((aOrbiterF * 7757713071544143453U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9521517757370835715U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18241677917767801049U;
            aOrbiterI = RotL64((aOrbiterI * 16977396965907931057U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14307634663160859644U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 966899917801652720U;
            aOrbiterB = RotL64((aOrbiterB * 17012361848398765251U), 29U);
            //
            aIngress = RotL64(aOrbiterC, 10U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 23U)) + aOrbiterD) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 10U)) + aOrbiterH);
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 27U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 5U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterB) + RotL64(aOrbiterG, 21U));
            aWandererE = aWandererE + ((((RotL64(aCross, 56U) + aOrbiterA) + RotL64(aOrbiterG, 14U)) + RotL64(aCarry, 27U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterK, 37U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterG, 39U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + aOrbiterH) + RotL64(aOrbiterB, 53U)) + aPhaseEWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterC, 41U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21737U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneB[((aIndex + 17605U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 20222U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 20149U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCross, 53U)) ^ (RotL64(aCarry, 20U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 27U)) + 1457104756581596530U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 43U)) + 6127240317844622874U) + aPhaseEOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererE + RotL64(aScatter, 22U)) + 16492290056044189421U;
            aOrbiterI = (aWandererF + RotL64(aCross, 13U)) + 10963676850938416468U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 47U)) + 4872917367399752405U;
            aOrbiterF = (aWandererI + RotL64(aCross, 3U)) + 15218882377875616148U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 53U)) + 5934166612122118251U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 14215280930872003003U;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 11U)) + RotL64(aCarry, 5U)) + 11428034799044600979U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 18U)) + 5453003654321728726U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 14273775120265649389U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 328723770018440271U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13032190719588211088U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 13363368478932798315U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 2386881543033598494U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 1649501123340887116U;
            aOrbiterD = RotL64((aOrbiterD * 11148976582360499033U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16462401546754210583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 1510579201823042227U;
            aOrbiterF = RotL64((aOrbiterF * 16287912400104043275U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 6889066000014251983U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 11324594596597724357U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15344987814648586023U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12237796033168436537U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 17306069670330000343U;
            aOrbiterB = RotL64((aOrbiterB * 3167451351403385259U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 14197284538008811658U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 4754134852883071927U;
            aOrbiterG = RotL64((aOrbiterG * 3484427259538998699U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 17201907781639753736U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8318419319239859855U;
            aOrbiterE = RotL64((aOrbiterE * 10320390501983802091U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16012488623961565780U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15583721012865354925U;
            aOrbiterH = RotL64((aOrbiterH * 10656414363201743961U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 14680351201973315018U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14483973292275372321U;
            aOrbiterA = RotL64((aOrbiterA * 9279222721410811027U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16324317860030681248U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7038506963317910910U;
            aOrbiterJ = RotL64((aOrbiterJ * 2960451734542956767U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12767672960346001218U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1457104756581596530U;
            aOrbiterI = RotL64((aOrbiterI * 1560375242310194691U), 21U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 29U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterJ, 10U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 35U)) + aOrbiterK);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterH, 23U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 13U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterC, 60U)) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aScatter, 60U) + RotL64(aOrbiterK, 11U)) + aOrbiterE) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterH, 51U)) + aNonceWordK);
            aWandererG = aWandererG + (((RotL64(aCross, 46U) + aOrbiterH) + RotL64(aOrbiterD, 29U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 27U) + aOrbiterG) + RotL64(aOrbiterF, 37U));
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterI, 58U)) + aOrbiterF) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 26U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererF, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordL;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25506U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 23727U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24445U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 22924U)) & S_BLOCK1], 44U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 11U)) + (RotL64(aCross, 53U) + RotL64(aIngress, 38U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = (aWandererD + RotL64(aPrevious, 39U)) + 4068921616130916949U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 27U)) + 12077715273915151726U;
            aOrbiterG = (aWandererC + RotL64(aCross, 60U)) + 16047546802670596833U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 51U)) + 9690277462716999763U;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 53U)) + 14484814700447992628U) + aPhaseEOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = (((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 17089267243053958210U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aScatter, 43U)) + 9138746214446211147U) + aNonceWordB;
            aOrbiterJ = (aWandererJ + RotL64(aPrevious, 3U)) + 10181001536979097045U;
            aOrbiterB = ((aWandererK + RotL64(aScatter, 34U)) + 6657458969093373191U) + aNonceWordH;
            aOrbiterC = ((aWandererB + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 7515983477876590988U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 39U)) + 3039935555863947600U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 16209389224740851136U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 725253312098083182U;
            aOrbiterG = RotL64((aOrbiterG * 17535989492095522597U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13307041115748941383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 7159572004825238263U;
            aOrbiterH = RotL64((aOrbiterH * 4855009895002398449U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12027236743251643820U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8717826175991286553U;
            aOrbiterJ = RotL64((aOrbiterJ * 1175614802543098451U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4769096034227659937U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11201226563992939616U;
            aOrbiterC = RotL64((aOrbiterC * 15595355978388159931U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17295978531215563256U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11850923890626719833U;
            aOrbiterF = RotL64((aOrbiterF * 3854851059897397075U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 14139441565288097706U) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 988684899382304485U;
            aOrbiterE = RotL64((aOrbiterE * 11929090869999700891U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6159251276942253175U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4849529993914550651U;
            aOrbiterK = RotL64((aOrbiterK * 18240712676783671317U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6679745455842119497U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15838404437552215214U;
            aOrbiterB = RotL64((aOrbiterB * 17357853511591350887U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15853153471104458948U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 12542164757451566994U;
            aOrbiterI = RotL64((aOrbiterI * 12163611303899312043U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 14304233464055838869U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 4037999346933039765U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 564236202758328407U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 3582312827630995454U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4068921616130916949U;
            aOrbiterA = RotL64((aOrbiterA * 1527829107415867363U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 21U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 38U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 19U)) + aOrbiterD);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 44U)) + aOrbiterA) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 42U) + aOrbiterB) + RotL64(aOrbiterA, 51U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterK, 21U)) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 13U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterE, 5U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 5U) + aOrbiterG) + RotL64(aOrbiterH, 26U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterC, 37U));
            aWandererH = aWandererH + (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 40U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 29613U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27966U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28166U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32766U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 47U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 60U) + RotL64(aIngress, 27U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (((aWandererI + RotL64(aPrevious, 37U)) + 15910560457440369082U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 17953072986407436888U) + aPhaseEOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 56U)) + 15446940721193538669U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 29U)) + 3020785262774422009U;
            aOrbiterF = (aWandererH + RotL64(aCross, 27U)) + 7001288645424994404U;
            aOrbiterA = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 57U)) + 13385250665458462689U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 39U)) + 4841895644623005949U;
            aOrbiterI = (aWandererB + RotL64(aScatter, 21U)) + 13053476783239482065U;
            aOrbiterG = (aWandererE + RotL64(aIngress, 35U)) + 641996979335975244U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 16211238020928688299U) + aNonceWordK;
            aOrbiterE = ((aWandererG + RotL64(aCross, 50U)) + 12715448751323279480U) + aNonceWordF;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 17784406727699995290U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16626339815786580778U;
            aOrbiterD = RotL64((aOrbiterD * 13940754474750138041U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 9035070625716345139U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 6085848172494001945U;
            aOrbiterF = RotL64((aOrbiterF * 10405728912339646693U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1177103851507561053U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2281901691017816407U;
            aOrbiterA = RotL64((aOrbiterA * 3142197009403602497U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 9040984343694325070U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13334258224023902365U) ^ aNonceWordM;
            aOrbiterB = RotL64((aOrbiterB * 4782523727707164869U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 1079824790138592518U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14024082692012948652U;
            aOrbiterI = RotL64((aOrbiterI * 3219489374333737903U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2966776524421278970U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 5510281854029308547U;
            aOrbiterG = RotL64((aOrbiterG * 9275402927591867297U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 7126632329316720048U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1476827035602733472U;
            aOrbiterJ = RotL64((aOrbiterJ * 2217671289726794033U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6470212302133184965U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 4172257438373147415U;
            aOrbiterE = RotL64((aOrbiterE * 4449314239630366533U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11445212164224402184U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1779825157413363285U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15393425495668107155U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7561888690947559866U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 14440989817038856852U;
            aOrbiterH = RotL64((aOrbiterH * 5799807036762859679U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 10618807050937260814U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 15910560457440369082U;
            aOrbiterK = RotL64((aOrbiterK * 10902491688248464465U), 5U);
            //
            aIngress = RotL64(aOrbiterH, 54U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterI, 26U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 20U) + aOrbiterG) + RotL64(aOrbiterC, 43U)) + aPhaseEWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 19U)) + aOrbiterJ);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterG, 47U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterD, 60U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterH, 51U));
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 11U)) + aOrbiterD);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 12U) + RotL64(aOrbiterF, 39U)) + aOrbiterA) + aNonceWordD) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 12U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 26U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordM);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCF1613E364A971F1ULL + 0x92E992C12EEDF904ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xFF5247ED9FA1EE07ULL + 0xC7150BCA890478E5ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEA25E66DE6254E93ULL + 0xBC3CCED1F7466972ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xCDED42F1F8F0965FULL + 0xDF827F8E1D18AB97ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE12A8CBC0CBBC619ULL + 0xDFA0E464E5B48029ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA9D97AC5916C196DULL + 0xC08E5228477E63CDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD8CD38724026B7E9ULL + 0xE35C09B3049907F9ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA826A80867E234B5ULL + 0x96D2C4E617C31D95ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE9454A792F3C5EFFULL + 0xBDE8E632EFB2C56FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8A222F79AEB61515ULL + 0x87A74FD765C67B11ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xA49F858937691DA3ULL + 0xD0F8F1E9BE0D4E77ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC13694B963AE916DULL + 0xF99D067DAFC78C6BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBCBB0B5E4383A4BFULL + 0xE575F8007BC6753AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xFDABF4376A338A9BULL + 0xD4AA4DB548C4F0C3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAB713C320FCF9F7DULL + 0xF89ECF277055BE65ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD4D6A9D79F89854DULL + 0xDE95DA594AC82111ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 1880U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 3748U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1400U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneA[((aIndex + 4008U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aIngress, 53U)) + (RotL64(aCross, 3U) ^ RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererF + RotL64(aIngress, 27U)) + 18319689184146942855U;
            aOrbiterI = (aWandererC + RotL64(aCross, 44U)) + 8041304130090501019U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 39U)) + 11347064191990897738U) + aNonceWordP;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 5U)) + RotL64(aCarry, 43U)) + 15242243470024447468U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 51U)) + 10619749107163611105U) + aNonceWordE;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 14795614276221947128U) + aPhaseFOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererK + RotL64(aScatter, 41U)) + 1578095288886372393U) + aNonceWordN;
            aOrbiterA = ((aWandererB + RotL64(aCross, 37U)) + 13593906305770501684U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aIngress, 3U)) + 8919815528334599172U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 58U)) + 17425548324720065145U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 53U)) + 11125018338392347335U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3779189180734244399U) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 10958224663276134041U;
            aOrbiterH = RotL64((aOrbiterH * 6206963519509783781U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4317305352561612995U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 4891139433808505355U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 11507024985663120317U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 5166074784835930965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 10080890270621589202U;
            aOrbiterD = RotL64((aOrbiterD * 13170894418184288695U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4501071771615514619U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6486573807774431753U;
            aOrbiterG = RotL64((aOrbiterG * 324029625116648669U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15714881857668975753U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 3506619392820235900U;
            aOrbiterB = RotL64((aOrbiterB * 5707033870161224499U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5295711072762443783U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11192836530396570648U;
            aOrbiterE = RotL64((aOrbiterE * 4361810118382207039U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 7993389678399774574U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 12551394763541226695U;
            aOrbiterJ = RotL64((aOrbiterJ * 11903486656172026403U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11553674370322129668U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 4459881583199320245U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2805857426321555685U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 3053507713574219459U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15458441755058850309U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7296609957819165877U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17429750026356459756U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 17114614857181230304U;
            aOrbiterA = RotL64((aOrbiterA * 10541235280918902739U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 8958993884028672039U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 18319689184146942855U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5430881344386342703U), 23U);
            //
            aIngress = RotL64(aOrbiterC, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterD, 58U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 23U));
            aIngress = aIngress + RotL64(aOrbiterG, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 43U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterE, 39U)) + aOrbiterH) + aNonceWordD);
            aWandererK = aWandererK ^ ((RotL64(aCross, 6U) + aOrbiterG) + RotL64(aOrbiterJ, 23U));
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 13U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterC, 56U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterC, 29U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 46U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterK, 51U));
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterE, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererJ);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordO);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8521U)) & S_BLOCK1], 54U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 6888U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8615U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((aIndex + 9577U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 5U) + RotL64(aCross, 40U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 37U)) + 8020711767807230555U;
            aOrbiterB = (aWandererC + RotL64(aScatter, 39U)) + 15368693777246341570U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 5117523734225562401U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 53U)) + 13155269151097507808U) + aNonceWordM;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + 9879303753623578272U) + aNonceWordA;
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 51U)) + RotL64(aCarry, 21U)) + 1165799257173794826U;
            aOrbiterJ = (aWandererA + RotL64(aCross, 60U)) + 930641942062732091U;
            aOrbiterK = ((aWandererB + RotL64(aScatter, 27U)) + 11330571332221123153U) + aNonceWordL;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 29U)) + 2862963158282518899U;
            aOrbiterI = ((aWandererI + RotL64(aScatter, 3U)) + 6019186399361476659U) + aPhaseFOrbiterAssignSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (((aWandererF + RotL64(aIngress, 14U)) + RotL64(aCarry, 43U)) + 1924419843785161958U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12618629043591380461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 9334176504266512405U;
            aOrbiterE = RotL64((aOrbiterE * 18239109235362925739U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16829692481030013551U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5604784396927022709U;
            aOrbiterB = RotL64((aOrbiterB * 2833893610883508353U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16124030106598549644U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16571659812830230677U;
            aOrbiterD = RotL64((aOrbiterD * 4668250364992383549U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 15171089673591843703U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 2826755560293849328U;
            aOrbiterJ = RotL64((aOrbiterJ * 9397017963457655287U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9976785768283589291U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 11845100564714691809U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4935139932585319251U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7318560453127859950U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 3039196878830506712U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 3140508261330698717U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 8850992055588337843U) + aNonceWordB;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4219373528176869146U;
            aOrbiterF = RotL64((aOrbiterF * 1310964742529956743U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1341474458715938799U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15937557372891732898U;
            aOrbiterH = RotL64((aOrbiterH * 11437307017920192915U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7512741986101399499U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 4304636545688233645U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 1948671766238131953U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11460886069492094055U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2019818350627642126U;
            aOrbiterI = RotL64((aOrbiterI * 9802784763505584769U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 3190374588085859096U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 8020711767807230555U;
            aOrbiterC = RotL64((aOrbiterC * 12055760672321414929U), 29U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 26U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterK, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 34U) + aOrbiterB) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 60U)) + aOrbiterB);
            aWandererK = aWandererK + ((((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + aNonceWordF) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 19U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterH, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterG, 37U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 48U));
            aWandererA = aWandererA + ((RotL64(aIngress, 14U) + RotL64(aOrbiterC, 39U)) + aOrbiterI);
            aWandererB = aWandererB ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterF, 5U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererC);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 12U));
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10953U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 15158U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 11534U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13316U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 11U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 53U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 37U)) + 9855743441035905047U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 39U)) + 8426286937143990276U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 11U)) + 7146752367170267002U;
            aOrbiterA = (aWandererF + RotL64(aCross, 26U)) + 12947210066678101726U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 23U)) + 15902163559925328965U) + aNonceWordP;
            aOrbiterF = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 23U)) + 8506649889346449469U) + aNonceWordD;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 8226286036430263052U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 41U)) + 2703047093452420216U;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 43U)) + 6769351326360139560U) + aNonceWordB;
            aOrbiterE = ((aWandererG + RotL64(aCross, 53U)) + 9857025533281333281U) + aPhaseFOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aWandererI + RotL64(aIngress, 4U)) + 238297452132277585U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 7203572312072908931U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12497027346166575632U;
            aOrbiterB = RotL64((aOrbiterB * 1703586436725662307U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 473851890609048879U) + aNonceWordF;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1664484956453886047U;
            aOrbiterF = RotL64((aOrbiterF * 8566500756326590209U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 4635095143004754116U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17695676150967345793U;
            aOrbiterG = RotL64((aOrbiterG * 5780416541584439301U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15628965269863402796U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9190117464399730235U;
            aOrbiterJ = RotL64((aOrbiterJ * 5586437438425999715U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17835918238346011086U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 4398005402429282682U) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 14828737209913317463U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10902589938246551273U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 15124274429081385923U;
            aOrbiterE = RotL64((aOrbiterE * 13524180348258805367U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8747233520702236018U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5445611443463112371U;
            aOrbiterD = RotL64((aOrbiterD * 10294109295823410447U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16296005217836151910U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6468336224317602364U;
            aOrbiterA = RotL64((aOrbiterA * 7369779919748367133U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 3827976387089403774U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7773383658122100111U;
            aOrbiterK = RotL64((aOrbiterK * 9784711300597525161U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 18273794621528918389U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8401424792700263455U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13003420427441089595U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11402828934846813949U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 9855743441035905047U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7339549576423555273U), 41U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 23U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 4U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterH, 41U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterF, 47U)) + aOrbiterB) + aNonceWordM);
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 11U)) + aOrbiterG);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 12U) + RotL64(aOrbiterF, 44U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 21U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterD, 53U)) + aNonceWordK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterE) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 18U));
            aWandererI = aWandererI + ((RotL64(aIngress, 47U) + aOrbiterA) + RotL64(aOrbiterF, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 20U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20892U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 21345U)) & S_BLOCK1], 22U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16623U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16764U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aIngress, 6U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = ((aWandererA + RotL64(aIngress, 26U)) + 5173905450211892891U) + aNonceWordC;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 41U)) + 3555542451908039957U;
            aOrbiterA = (((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 51U)) + 11559884700283861559U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aCross, 35U)) + 1352524329968738673U) + aNonceWordH;
            aOrbiterG = (aWandererD + RotL64(aScatter, 51U)) + 8914206450420616349U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 2251523378498463946U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 11U)) + 9541575923299247038U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 13U)) + 1239854507907214595U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 29U)) + 17698101462598498934U) + aPhaseFOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 23U)) + 12305566971683256060U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 18U)) + RotL64(aCarry, 13U)) + 13804545036303215569U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 10239749097704329264U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 4212214906286320308U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3661436621615751071U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12192418916967430783U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4475514289326450361U;
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 17376102613298827459U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18129393209955439341U;
            aOrbiterD = RotL64((aOrbiterD * 6404089025014118979U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4014763724300253568U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17325007199676828814U;
            aOrbiterC = RotL64((aOrbiterC * 1420888274815627083U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15480474849292388685U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 14357924730184375449U;
            aOrbiterJ = RotL64((aOrbiterJ * 16723492259068034209U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4335731868597970070U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 8296023680394303015U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14027415401430120543U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2807312426993262800U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15510369660839648501U;
            aOrbiterF = RotL64((aOrbiterF * 18207954408298333959U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 12597844696606519907U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7231012798553551535U;
            aOrbiterK = RotL64((aOrbiterK * 2841306785994479299U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 849663631945232360U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 4002310581470781194U;
            aOrbiterB = RotL64((aOrbiterB * 2148877014350721479U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 16067735571435654555U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 4607980694199923842U;
            aOrbiterE = RotL64((aOrbiterE * 10401780756830017477U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5346879191913449715U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 5173905450211892891U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 15360571827429301833U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 58U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 37U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + aPhaseFWandererUpdateSaltB[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 46U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 39U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 6U)) + aNonceWordK);
            aWandererD = aWandererD + ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterG) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 19U) + aOrbiterH) + RotL64(aOrbiterI, 57U)) + aNonceWordJ);
            aWandererF = aWandererF ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 12U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererI);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ aNonceWordH;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 24346U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((aIndex + 26023U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26867U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26185U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 3U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterC = (aWandererC + RotL64(aCross, 39U)) + 2177539223979303669U;
            aOrbiterE = (((aWandererI + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 3962004686551521471U) + aPhaseFOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 20U)) + 8457602312617147662U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aIngress, 51U)) + 18011802451816510632U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 29U)) + 9046101759168876832U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 3U)) + 11135620637431969597U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 53U)) + RotL64(aCarry, 35U)) + 15913029940697999701U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 18U)) + 16304193109948135982U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 23U)) + RotL64(aCarry, 27U)) + 13208892298820080981U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 11U)) + 4182377898949419225U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 13U)) + 13970137023071326151U) + aNonceWordC;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 8402396284835248583U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8859190834060657829U;
            aOrbiterB = RotL64((aOrbiterB * 13552418608113716117U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9760005337757990392U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14108277760135744897U;
            aOrbiterF = RotL64((aOrbiterF * 4474681104256093885U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12226316121949012350U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3456392186754113960U;
            aOrbiterD = RotL64((aOrbiterD * 8704729827929941215U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5004087958637038973U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 7176881295123125567U;
            aOrbiterJ = RotL64((aOrbiterJ * 15272157962928021009U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 10889800478505074438U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 13728832441482547824U;
            aOrbiterC = RotL64((aOrbiterC * 17588477761978646139U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17345665880706866772U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 301139993853297566U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 5812445396758354505U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 2061389844760610160U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13631862266139238355U;
            aOrbiterH = RotL64((aOrbiterH * 143613352104722701U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 10767186080827509622U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4893486019456886013U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 5194746459545610901U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 11264795916303477037U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 16013652139405432608U;
            aOrbiterA = RotL64((aOrbiterA * 14924257021089920495U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5209743554932653849U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 13160179712987277456U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5003755912040281427U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12440615920191945386U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 2177539223979303669U;
            aOrbiterG = RotL64((aOrbiterG * 3565122523239344029U), 43U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 28U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 11U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + aOrbiterB) + RotL64(aOrbiterI, 37U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterH, 23U)) + aOrbiterI) + aNonceWordG) + aPhaseFWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterB, 27U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterC, 10U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterH) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 3U)) + aOrbiterK) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aIngress, 37U) + aOrbiterF) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterA, 47U)) + aOrbiterD) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 40U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterA, 19U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 43U)) + aOrbiterD) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 39U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 18U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + RotL64(aWandererE, 37U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordP);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31759U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32765U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30261U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 29349U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 50U) + RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 13U)) + 13350544654542863236U) + aNonceWordG;
            aOrbiterA = ((aWandererE + RotL64(aCross, 47U)) + 12364346790125404372U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aIngress, 6U)) + RotL64(aCarry, 53U)) + 9738750172849512764U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 29U)) + 3781373837635491421U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 47U)) + 16635020317512702337U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 39U)) + 5383653921676231276U;
            aOrbiterG = (aWandererI + RotL64(aScatter, 29U)) + 10181959815492056493U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 37U)) + 10005510924273927017U) + aPhaseFOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 11U)) + 9524687662265740565U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 18U)) + 4259138552009771014U) + aNonceWordP;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 51U)) + 8973051213213726023U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 17602611840127337490U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 8218984546932905269U;
            aOrbiterI = RotL64((aOrbiterI * 17504305273683304231U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 18102186122213487888U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2629927500298092976U;
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 2491581597835795234U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9506602492971620955U;
            aOrbiterF = RotL64((aOrbiterF * 9559829640915637163U), 27U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterB) + 13422942713680612924U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1]) + aNonceWordF;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 15037354693234876601U) ^ aNonceWordC;
            aOrbiterG = RotL64((aOrbiterG * 12692376075738621447U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 12896066842192894694U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 2202952306291905855U;
            aOrbiterE = RotL64((aOrbiterE * 6779368532763429997U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 12160313482450599313U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 10812986281270407756U;
            aOrbiterD = RotL64((aOrbiterD * 7786608700746771809U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12474638293190144525U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 5882870951276225224U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 15532427302173572457U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3782896138051179209U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10965680631059882311U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14060923998307082385U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15650420683333746952U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4110674660963676864U;
            aOrbiterJ = RotL64((aOrbiterJ * 11724979274890265275U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 694817156953099464U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 4402927404825116007U;
            aOrbiterA = RotL64((aOrbiterA * 579586789292520113U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6849178151532923489U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 13350544654542863236U;
            aOrbiterK = RotL64((aOrbiterK * 2416097748778941523U), 47U);
            //
            aIngress = RotL64(aOrbiterH, 44U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 41U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 10U) + aOrbiterI) + RotL64(aOrbiterK, 58U));
            aWandererH = aWandererH + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 43U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 20U));
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterB, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + aPhaseFWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterB, 41U)) + aOrbiterD) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 39U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + aPhaseFWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordF ^ aNonceWordA);
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x947FD0295E576029ULL + 0xFFFB9F1AE2BAE0F5ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xC652DD9DE310A8C7ULL + 0x8BDA62B15E2AED8CULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCD9AA701CF511FC9ULL + 0xC2B50BCFF4882C3BULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x961ED2A3FDFCA78FULL + 0xF4060EAE8BE05B28ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDFFB0827D0B9D595ULL + 0xA1A7E9D9486A86F4ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE31662F16FE4EE19ULL + 0xEE7A2976E8A4A2A4ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA3917D3788636BF9ULL + 0xD5007A6A98368D71ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xB3F3BC4CA56D0B83ULL + 0x91BDF199606E66A0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xB23648C05E2AF263ULL + 0x8194E42F82595260ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x9CE0894B62D3FFFDULL + 0xEAC9ED223DCF3CDCULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x818DA4C650A0E381ULL + 0xA61A76F7A5E3707FULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD798C9706B87C40BULL + 0xBA1C6F5515A1EBF4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xBB0419F212C8CE4FULL + 0x98ED239DDFE5515BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC971C31AAE04ED59ULL + 0xFA4695F95B822DF7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC33CB2A732678055ULL + 0xABC41E9BA23896CDULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xC96BAD7FE6333CBBULL + 0x99D65D2115381577ULL);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4909U)) & S_BLOCK1], 46U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1571U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 159U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 778U)) & S_BLOCK1], 14U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 27U) ^ RotL64(aPrevious, 52U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 51U)) + 6469584119078165548U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 57U)) + 14329756366517987910U;
            aOrbiterE = ((aWandererE + RotL64(aScatter, 3U)) + 12890831797059772123U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 21U)) + 3164503807500018990U) + aNonceWordM;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 5U)) + 177531431387646836U;
            aOrbiterB = ((aWandererB + RotL64(aIngress, 24U)) + RotL64(aCarry, 57U)) + 3167421392893561015U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 47U)) + 2813174781844753460U) + aPhaseFOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 13U)) + 10953270419153249857U;
            aOrbiterD = ((aWandererH + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 16911518309710356951U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 43U)) + 6616750447844893150U) + aNonceWordK;
            aOrbiterF = (aWandererA + RotL64(aIngress, 19U)) + 10276741398025985982U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6206043608461213208U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 12021552904553405793U;
            aOrbiterE = RotL64((aOrbiterE * 10023362889960174909U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15283586234744144846U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5923238786775948571U;
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 11044014510971660078U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 9351141024085076044U;
            aOrbiterA = RotL64((aOrbiterA * 13316079344614432317U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 17703395981862992420U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 10154548848376027087U;
            aOrbiterK = RotL64((aOrbiterK * 12324478347590509035U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8836420852291617425U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 10193385413543886344U;
            aOrbiterG = RotL64((aOrbiterG * 824935982418585449U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8248580084535685190U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3910083671888152974U;
            aOrbiterD = RotL64((aOrbiterD * 17825311776715895927U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 12350341628569930642U) + aNonceWordP;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 2565977481575002842U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 18233446879833776677U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 9271041067874027417U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 14289254596554201861U;
            aOrbiterI = RotL64((aOrbiterI * 7985522692852251413U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 5981802134118235214U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 14047813418129636856U;
            aOrbiterJ = RotL64((aOrbiterJ * 15961435325216504877U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11808443842149398212U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 11380858372643695792U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 100198424024622179U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10385375464069162356U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6469584119078165548U;
            aOrbiterC = RotL64((aOrbiterC * 5263876933019848989U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 43U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 48U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aScatter, 52U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 41U)) + aOrbiterD) + aNonceWordD);
            aWandererI = aWandererI + ((RotL64(aCross, 11U) + RotL64(aOrbiterF, 34U)) + aOrbiterA);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 3U)) + aOrbiterA);
            aWandererA = aWandererA + ((((RotL64(aCross, 28U) + aOrbiterB) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltE[((aIndex + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 39U));
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 57U)) + aOrbiterE) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterC, 26U)) + aOrbiterJ) + aNonceWordN);
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + RotL64(aOrbiterH, 29U)) + aOrbiterG) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterK, 5U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 21U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererC, 14U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 9577U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10117U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 6691U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 5476U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 47U)) + (RotL64(aCarry, 60U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aIngress, 11U)) + 5960680319644404115U;
            aOrbiterA = (((aWandererG + RotL64(aScatter, 37U)) + 16050752633567034185U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 3U)) + 8447503223226854741U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 43U)) + 14176813813397917591U;
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 10534915376130006644U;
            aOrbiterD = (aWandererI + RotL64(aCross, 46U)) + 6866224454375302514U;
            aOrbiterB = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 57U)) + 16506374165041008396U) + aNonceWordA;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 35U)) + 7167814023968794098U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (aWandererB + RotL64(aIngress, 27U)) + 13870852197416596664U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 5U)) + 18064038854848993105U) + aNonceWordK;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 58U)) + RotL64(aCarry, 13U)) + 9869630811507771691U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 863613100452759380U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16597969741225436529U;
            aOrbiterK = RotL64((aOrbiterK * 2680793528887208903U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6575347108051310653U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 17062262265485019063U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7601045488473620019U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7193399224636409133U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 14146747818810433849U;
            aOrbiterH = RotL64((aOrbiterH * 5273185769989530041U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 9441449106442431427U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4303295336545399503U;
            aOrbiterB = RotL64((aOrbiterB * 8829695296836242587U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12604760768543193458U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 15779327512379787715U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 14000905201441272597U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15553000781122708728U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 17162740616060079717U;
            aOrbiterF = RotL64((aOrbiterF * 9458662233556750239U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 1032374679817715156U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 16413393156165548232U;
            aOrbiterC = RotL64((aOrbiterC * 549659738811935015U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14056855000013992045U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7399202019042538829U;
            aOrbiterD = RotL64((aOrbiterD * 6103508549612077695U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2218389473339103389U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4679497280975967770U;
            aOrbiterE = RotL64((aOrbiterE * 9228353578259815023U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7620538119914173747U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3118355627808424159U;
            aOrbiterG = RotL64((aOrbiterG * 12481319980496032783U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16787092219237931175U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5960680319644404115U;
            aOrbiterJ = RotL64((aOrbiterJ * 10727217147056112401U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterJ, 18U));
            aWandererD = aWandererD + (((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterC, 29U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterJ) + RotL64(aOrbiterD, 39U)) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 18U) + aOrbiterA) + RotL64(aOrbiterD, 5U)) + aPhaseFWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 43U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 34U)) + aOrbiterK);
            aWandererA = aWandererA + ((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterH, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 37U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 22U) + aOrbiterF) + RotL64(aOrbiterI, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterI, 27U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (RotL64(aWandererH, 57U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 44U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordL);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12562U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14136U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15115U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 12850U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 27U)) + (RotL64(aIngress, 11U) ^ RotL64(aCross, 58U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererJ + RotL64(aIngress, 47U)) + 479672811032092393U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 41U)) + 18061121631394564425U;
            aOrbiterK = (aWandererA + RotL64(aCross, 3U)) + 14237400452740566065U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 6723123812257706134U;
            aOrbiterD = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 39U)) + 4247997188026499248U) + aNonceWordN;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 29U)) + 1939107415066134869U) + aPhaseFOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 50U)) + 3912640123546395979U;
            aOrbiterC = (aWandererF + RotL64(aCross, 21U)) + 8295478436553964298U;
            aOrbiterA = (((aWandererK + RotL64(aIngress, 29U)) + 3218960600711526885U) + aPhaseFOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aWandererH + RotL64(aCross, 43U)) + 5874096203353388890U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 6U)) + 10294536533673023358U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11268561953904130747U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16693201256788898423U;
            aOrbiterK = RotL64((aOrbiterK * 16291987237693567209U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7550969634681894654U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 9501647424602245869U;
            aOrbiterF = RotL64((aOrbiterF * 11265865222096866605U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8881869255994319423U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 16770136406906800016U;
            aOrbiterI = RotL64((aOrbiterI * 1782039587385512923U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 16185384746435761363U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 13841034186650721627U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12000155593277035447U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 15229062695864608309U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 3576122704615303733U) ^ aNonceWordE;
            aOrbiterC = RotL64((aOrbiterC * 2433987493885779279U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13898167174453181224U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12878032061609524049U;
            aOrbiterH = RotL64((aOrbiterH * 18104665741338251495U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 12719156051299028649U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 8640980843376950769U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10242616778390983333U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12133332160916004365U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 8743563985229104484U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4575129690615054691U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 7362223873479167793U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4230720394788635807U;
            aOrbiterJ = RotL64((aOrbiterJ * 3658720603716856293U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5095842824285329272U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7483469517256234638U;
            aOrbiterA = RotL64((aOrbiterA * 9782114499878763883U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 17426017004856399653U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 479672811032092393U;
            aOrbiterB = RotL64((aOrbiterB * 14921028515589317919U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 50U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 4U));
            aIngress = aIngress + RotL64(aOrbiterD, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 14U) + aOrbiterJ) + RotL64(aOrbiterC, 21U));
            aWandererC = aWandererC + ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 50U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterC, 19U));
            aWandererA = aWandererA + ((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 39U)) + aOrbiterJ);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterE, 53U));
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterC, 13U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + aNonceWordD);
            aWandererD = aWandererD + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterC, 58U)) + aOrbiterB) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aIngress, 28U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17776U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 19789U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18105U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20059U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 54U)) + (RotL64(aIngress, 39U) ^ RotL64(aCarry, 11U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterE = ((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 1364174714924216027U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 41U)) + 13561796874229506613U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordG;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 11845572344206238305U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 57U)) + 15762708240326773763U) + aNonceWordE;
            aOrbiterI = (aWandererJ + RotL64(aIngress, 29U)) + 1157119665207900473U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 34U)) + 6823546624372055260U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aPrevious, 51U)) + 14465564210523945121U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 53U)) + 10667464548080807531U) + aNonceWordO;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 13445737493224316575U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 14U)) + 3009837893785957665U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 43U)) + 2886920524111083752U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10886177449328249656U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 15067759884678100433U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5724566815989860041U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 18307930462682331536U) + aNonceWordF;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8791864377579255801U;
            aOrbiterI = RotL64((aOrbiterI * 9265158882471421767U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 805797468642992351U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5743305867058244964U;
            aOrbiterC = RotL64((aOrbiterC * 16263000753351131717U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 17102025528234481273U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1841579177327486899U;
            aOrbiterB = RotL64((aOrbiterB * 3841603385577825265U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 2189493507896508972U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 18209567010094914374U;
            aOrbiterA = RotL64((aOrbiterA * 3737080408976852351U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6697069234216868330U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 927471474577415372U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10680760991009199309U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13155854301197725408U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1014625081915435892U;
            aOrbiterF = RotL64((aOrbiterF * 11592754232949990435U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 12697209921410914931U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11555096613655648647U;
            aOrbiterJ = RotL64((aOrbiterJ * 4598821388864997089U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9335308231651271690U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3160859883353473444U;
            aOrbiterE = RotL64((aOrbiterE * 4753600703924906409U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 15681189182414315768U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 3147692210581710663U;
            aOrbiterD = RotL64((aOrbiterD * 6271949093080510861U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5373388632562432117U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1364174714924216027U;
            aOrbiterH = RotL64((aOrbiterH * 4694926665965807945U), 53U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (RotL64(aOrbiterB, 52U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 43U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterE) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 47U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererB = aWandererB + (((((RotL64(aCross, 13U) + aOrbiterA) + RotL64(aOrbiterH, 36U)) + RotL64(aCarry, 13U)) + aNonceWordP) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterG, 53U));
            aWandererK = aWandererK + ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 19U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 24U) + aOrbiterF) + RotL64(aOrbiterK, 39U));
            aWandererF = aWandererF + (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 56U)) + aOrbiterF) + aPhaseFWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25450U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26705U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23500U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22041U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aIngress, 54U) + RotL64(aCross, 11U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 42U)) + 3199575576585871314U) + aPhaseFOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 2533378188975571824U;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 3U)) + 6819782112558312658U) + aPhaseFOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aScatter, 11U)) + 12690060987724798497U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 3U)) + 7088375139715629606U;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 53U)) + 17785618677423695666U;
            aOrbiterB = (aWandererD + RotL64(aCross, 5U)) + 1714999280296491277U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 48U)) + 17611338506932491624U) + aNonceWordD;
            aOrbiterE = (aWandererG + RotL64(aPrevious, 35U)) + 6475727359297421201U;
            aOrbiterI = (aWandererC + RotL64(aScatter, 37U)) + 2347744591204119530U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 23U)) + 2739317903351401068U) + aNonceWordE;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 8663535261373274338U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8205245127823536479U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13857005110466856439U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 8916510616749754516U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3944805940148512932U;
            aOrbiterC = RotL64((aOrbiterC * 18082271583211389701U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14094751253118853302U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14094299829196076311U;
            aOrbiterK = RotL64((aOrbiterK * 6370012560657108493U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 3940673811518673802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3015106523254484839U;
            aOrbiterI = RotL64((aOrbiterI * 9655401190755573379U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15404103131982599922U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 1828655763233900875U;
            aOrbiterH = RotL64((aOrbiterH * 13024358077740310049U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1236981890899916502U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 18208975564570342697U;
            aOrbiterG = RotL64((aOrbiterG * 4577109989465876801U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 17882273895471449661U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 16196010765612713713U;
            aOrbiterB = RotL64((aOrbiterB * 15624856645134182005U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14639250100311162559U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 9139027997336903273U;
            aOrbiterE = RotL64((aOrbiterE * 1853126389565574293U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 16848571995585465845U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15901000078517800358U;
            aOrbiterF = RotL64((aOrbiterF * 11617866400577762383U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9405166641274108606U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 6776079798531281127U;
            aOrbiterD = RotL64((aOrbiterD * 6914644957401512339U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 15056085197286596847U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 3199575576585871314U;
            aOrbiterJ = RotL64((aOrbiterJ * 15940936753708416817U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 43U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 14U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterI, 57U)) + aOrbiterE) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 43U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterH, 51U));
            aWandererG = aWandererG + (((RotL64(aCross, 6U) + RotL64(aOrbiterF, 27U)) + aOrbiterD) + RotL64(aCarry, 47U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterC, 29U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterJ, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + aNonceWordG) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 57U) + RotL64(aOrbiterB, 34U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 29638U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((aIndex + 27912U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32717U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32054U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 56U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 29U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererA + RotL64(aIngress, 56U)) + 16016931609704150191U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 29U)) + 14511433515861302636U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 27U)) + 11691237442613269593U) + aNonceWordL;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 47U)) + 16383220587320484649U) + aNonceWordO;
            aOrbiterA = (aWandererF + RotL64(aCross, 53U)) + 14293015313458219868U;
            aOrbiterB = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 5U)) + 4407695248205526670U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 21U)) + 1158323195324398372U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 6U)) + 6577683409653864555U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 19U)) + 171080079472863843U) + aPhaseFOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 29U)) + 5766333425872228205U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 41U)) + 16173508656917582960U) + aNonceWordF;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 11781450063402219202U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13033139686637576694U;
            aOrbiterJ = RotL64((aOrbiterJ * 4331137994135472025U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4006310759400926020U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13156817947481574467U;
            aOrbiterA = RotL64((aOrbiterA * 563189239835001483U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12791290558893516411U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 989729955679243234U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8757228712495095017U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 838379839663022790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2830743864262313606U;
            aOrbiterC = RotL64((aOrbiterC * 10173947177104802797U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2146646527331684652U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4629168181742174906U;
            aOrbiterK = RotL64((aOrbiterK * 9046124907945045131U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1150129989168501777U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 619659995945229440U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 13734821008174603409U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8120315647582116952U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13754584116324996165U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 12295486140772079747U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 6084566798869999580U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5731665119233722504U;
            aOrbiterE = RotL64((aOrbiterE * 5921510209025133639U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16134513471149338456U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 9841695976256666234U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7417023101762286049U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2559042046155066240U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14065288635273112125U;
            aOrbiterI = RotL64((aOrbiterI * 10464173719695109147U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18228257734024217020U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16016931609704150191U;
            aOrbiterG = RotL64((aOrbiterG * 2874343578276710555U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 11U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterB, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 58U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 56U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterB, 23U)) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterH, 41U)) + aOrbiterC) + aNonceWordD);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterI, 51U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 24U) + RotL64(aOrbiterI, 10U)) + aOrbiterK);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 43U) + aOrbiterF) + RotL64(aOrbiterB, 13U));
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererK = aWandererK ^ (((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterC, 27U)) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + RotL64(aOrbiterA, 44U)) + aOrbiterF) + aPhaseFWandererUpdateSaltB[((aIndex + 4U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 52U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordB);
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 707U)) & S_BLOCK1], 60U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 6524U)) & W_KEY1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 3221U)) & W_KEY1], 60U) ^ RotL64(mSource[((aIndex + 4242U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 37U)) + (RotL64(aIngress, 21U) ^ RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 10U)) + 3199575576585871314U) + aPhaseCOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 2533378188975571824U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 19U)) + 6819782112558312658U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 23U)) + 12690060987724798497U;
            aOrbiterC = (((aWandererG + RotL64(aIngress, 23U)) + RotL64(aCarry, 41U)) + 7088375139715629606U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 27U)) + 17785618677423695666U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 50U)) + 1714999280296491277U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 57U)) + 17611338506932491624U;
            aOrbiterG = (aWandererE + RotL64(aScatter, 37U)) + 6475727359297421201U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2347744591204119530U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2739317903351401068U;
            aOrbiterA = RotL64((aOrbiterA * 15435029315209475631U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8663535261373274338U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 8205245127823536479U;
            aOrbiterE = RotL64((aOrbiterE * 13857005110466856439U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8916510616749754516U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3944805940148512932U;
            aOrbiterF = RotL64((aOrbiterF * 18082271583211389701U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14094751253118853302U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 14094299829196076311U;
            aOrbiterG = RotL64((aOrbiterG * 6370012560657108493U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 3940673811518673802U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3015106523254484839U;
            aOrbiterH = RotL64((aOrbiterH * 9655401190755573379U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15404103131982599922U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 1828655763233900875U) ^ aPhaseCOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13024358077740310049U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 1236981890899916502U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 18208975564570342697U;
            aOrbiterK = RotL64((aOrbiterK * 4577109989465876801U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 17882273895471449661U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16196010765612713713U;
            aOrbiterB = RotL64((aOrbiterB * 15624856645134182005U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 14639250100311162559U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9139027997336903273U;
            aOrbiterC = RotL64((aOrbiterC * 1853126389565574293U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 6U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 39U));
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 52U) + aOrbiterC) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 29U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 60U)) + aOrbiterE);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterA, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterH, 47U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + aOrbiterK) + RotL64(aOrbiterF, 37U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 24U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterB, 24U)) + aPhaseCWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 52U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10390U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 14620U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 8741U)) & W_KEY1], 20U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 14650U)) & W_KEY1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 34U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 13U)) + 5171470532667965920U;
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 53U)) + 750549462358682403U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 3325689257577120525U) + aPhaseCOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 58U)) + 18031575461559790826U) + aPhaseCOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 47U)) + 13874739537012288677U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 39U)) + 4250029868785016865U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 23U)) + RotL64(aCarry, 5U)) + 8211158803112611161U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 28U)) + 1083939790236786027U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 3U)) + 3446525462376962464U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6973817815000417325U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15230876489676945543U;
            aOrbiterD = RotL64((aOrbiterD * 7737039082964537651U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9359727659738755880U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8775170107816327654U;
            aOrbiterJ = RotL64((aOrbiterJ * 6910680458261008653U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11958941755525038545U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 16966819714283167348U;
            aOrbiterA = RotL64((aOrbiterA * 16363457661846050749U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14556087985619763243U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17915047508377045221U;
            aOrbiterI = RotL64((aOrbiterI * 6727635453185130109U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 8578745677485367222U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7002181668717618866U;
            aOrbiterK = RotL64((aOrbiterK * 12329703532414955235U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3569939503066735457U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 2956247934282522184U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9946650822131152531U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 4285180013402474041U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5976239869535619811U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3458095419039067465U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 2424524955161695463U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6849595426583763537U;
            aOrbiterC = RotL64((aOrbiterC * 12727902040238318101U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 11414890686374886716U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5668287266836153445U;
            aOrbiterE = RotL64((aOrbiterE * 8011885266143066285U), 23U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 26U));
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 48U)) + aOrbiterI) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterI, 11U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 29U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 35U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 24U) + RotL64(aOrbiterI, 53U)) + aOrbiterJ);
            aWandererF = aWandererF + (((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterK, 18U)) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererB);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23256U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 23719U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16576U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[((aIndex + 19619U)) & W_KEY1], 6U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 36U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 6243113109470883144U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 53U)) + 3891552123999605832U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = (aWandererF + RotL64(aPrevious, 46U)) + 8758797898587019128U;
            aOrbiterH = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 35U)) + 1005891374086408851U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 27U)) + 3713426782180050764U;
            aOrbiterA = (aWandererH + RotL64(aScatter, 19U)) + 18358143862391573534U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 40U)) + 17504394029693712404U) + aPhaseCOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aWandererE + RotL64(aCross, 5U)) + 5312729289027417014U;
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 2560873623431186029U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16309322822806704211U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10195513918020652600U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14569219741824123715U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2552116263258744287U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7732784879810980089U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15041929399477790999U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 16499127570665381507U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10890036715535519036U;
            aOrbiterH = RotL64((aOrbiterH * 9065115450010475187U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 16288944603478791554U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14542766121469312846U;
            aOrbiterC = RotL64((aOrbiterC * 8435383464425875209U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 5973595239494084696U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 1820492719977197097U;
            aOrbiterD = RotL64((aOrbiterD * 16164917159141304405U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 10489529555776381736U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6392552206958240484U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11761477994533503307U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 10163241948999404556U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16054678853554707148U;
            aOrbiterK = RotL64((aOrbiterK * 10570418210789350091U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 3606021702108590330U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 16920568417324295852U;
            aOrbiterG = RotL64((aOrbiterG * 5222656554577625385U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13889995689147406315U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7908387312354285092U;
            aOrbiterJ = RotL64((aOrbiterJ * 7995682580514280949U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 44U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 39U) + RotL64(aOrbiterB, 54U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + aOrbiterC) + RotL64(aOrbiterD, 19U)) + aPhaseCWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 39U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterA, 47U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aPrevious, 22U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + RotL64(aCarry, 39U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 4U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 27U)) + aOrbiterG) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterG, 23U)) + aOrbiterJ);
            //
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (RotL64(aWandererD, 20U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28412U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 27560U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26680U)) & S_BLOCK1], 56U) ^ RotL64(mSource[((aIndex + 27919U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 41U)) ^ (RotL64(aCross, 26U) + RotL64(aPrevious, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererI + RotL64(aScatter, 19U)) + 17454559218352016650U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 41U)) + 8005709669325164803U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 4U)) + 13393741948412816357U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 3665865624348875553U;
            aOrbiterA = ((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 35U)) + 8334142570031883436U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 57U)) + RotL64(aCarry, 21U)) + 17226066128706139657U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 28U)) + 3319093033121522613U) + aPhaseCOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 47U)) + 6657535603401588798U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aScatter, 37U)) + 5469746182326331147U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17846791786050221418U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15939541003714896288U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1400351482213119809U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12076763190461077406U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3594038213596405284U;
            aOrbiterA = RotL64((aOrbiterA * 10244002692575821495U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 8301291631324464622U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 8460406137668390582U) ^ aPhaseCOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9117147929757711595U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7612394867020871200U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8525076134853103975U;
            aOrbiterH = RotL64((aOrbiterH * 5790440201072204659U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11929899088215090379U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7119509166360685726U;
            aOrbiterK = RotL64((aOrbiterK * 1662341427992528823U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5081078459225240607U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17149991983909906705U;
            aOrbiterB = RotL64((aOrbiterB * 950223374568067343U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8817303295675241994U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 7962039282652745113U;
            aOrbiterJ = RotL64((aOrbiterJ * 12773588587795522121U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 13596273086338032370U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 8186297702278180956U;
            aOrbiterI = RotL64((aOrbiterI * 6226504769888753861U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 1696277861691580263U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 17360461831507082959U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1651378456022210983U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterK, 30U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 18U) + aOrbiterK) + RotL64(aOrbiterE, 18U)) + RotL64(aCarry, 23U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterH, 5U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + aPhaseCWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterK, 39U)) + aPhaseCWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterF, 22U));
            aWandererE = aWandererE + ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 11U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 22U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 54U));
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererD);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3421U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7467U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4696U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5879U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterA = (((aWandererB + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 9654059367478508868U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 6473006635864677427U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 40U)) + 6944184481315853243U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 53U)) + RotL64(aCarry, 37U)) + 4061496421939102306U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 5U)) + 15791809275719085463U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 14050798802646323055U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 12072905924741758266U;
            aOrbiterB = RotL64((aOrbiterB * 4757104346636738119U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17639076509231343896U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12195388285571234715U;
            aOrbiterA = RotL64((aOrbiterA * 4317060502521195769U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4325404419499496529U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5910567888204238382U;
            aOrbiterC = RotL64((aOrbiterC * 11503787177122206937U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13092940059929942699U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 13381962590820308761U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6345904465930943295U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15622862439323440527U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 14027151901132249793U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2273573821630510087U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 38U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterE, 11U)) + aOrbiterH);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 20U)) + aOrbiterH) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 43U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 3U)) + aOrbiterA) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterC, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 8721U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneD[((aIndex + 13677U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10440U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((aIndex + 12695U)) & S_BLOCK1], 43U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 23U)) + 10881271196314989997U;
            aOrbiterE = (((aWandererH + RotL64(aPrevious, 60U)) + RotL64(aCarry, 3U)) + 6406461249988567558U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aCross, 35U)) + 17255067918280095959U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 5U)) + 16690850682497718411U) + aPhaseDOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 5576201059361086866U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 11991259685693687554U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 14652535244217836909U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 18283959577075524171U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1701789037170782122U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 953429054903473833U;
            aOrbiterB = RotL64((aOrbiterB * 13482379459700651427U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12064513610469714211U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 7993881398822002424U;
            aOrbiterI = RotL64((aOrbiterI * 11572884842788918377U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14421313768013320050U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 11112386845630998889U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11771526352030371669U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 17069630896535699015U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 3308240081138623373U;
            aOrbiterC = RotL64((aOrbiterC * 10449509484417835159U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 27U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 43U)) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 27U)) + aOrbiterG) + aPhaseDWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 28U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterB, 54U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24279U)) & S_BLOCK1], 34U) ^ RotL64(aOperationLaneA[((aIndex + 18618U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16616U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21848U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 24U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aIngress, 37U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererF + RotL64(aScatter, 23U)) + 7632760812370906911U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 6007174525479723089U) + aPhaseDOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 13U)) + 3362829642521821048U) + aPhaseDOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 3U)) + 18009548556107978286U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 34U)) + RotL64(aCarry, 39U)) + 17880909432272697327U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15961567935420752568U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 10136559064656837921U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14473810261421912849U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 17622019364405410277U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 6927494824421416306U;
            aOrbiterG = RotL64((aOrbiterG * 2686290883767829973U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7125170407794874847U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12342273503071032250U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 867417849555857179U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 14997696377476124836U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14874498694181230698U;
            aOrbiterJ = RotL64((aOrbiterJ * 4026127545746010937U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2549397729130885686U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4217995818662767955U;
            aOrbiterC = RotL64((aOrbiterC * 5525525344485251063U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 6U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterE, 39U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 29U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 58U) + RotL64(aOrbiterG, 39U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 47U) + aOrbiterC) + RotL64(aOrbiterE, 47U)) + RotL64(aCarry, 23U)) + aPhaseDWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 58U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 58U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 47U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 32439U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29129U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25811U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 31671U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 53U)) + (RotL64(aIngress, 11U) ^ RotL64(aCarry, 38U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererH + RotL64(aScatter, 11U)) + RotL64(aCarry, 37U)) + 14214886793361825363U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 3U)) + 17267959031078766320U;
            aOrbiterG = ((aWandererA + RotL64(aIngress, 3U)) + 16436067429484887644U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererB + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 9885951769332633820U;
            aOrbiterF = ((aWandererD + RotL64(aPrevious, 58U)) + 12971711341813893304U) + aPhaseDOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 199970353398450154U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1237341696444162094U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2850125642665515751U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 7991128854417613360U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 14809029847149045833U;
            aOrbiterB = RotL64((aOrbiterB * 5940857360838299105U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2559509556915775947U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14336829730147834160U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15103242520064900873U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 8853631886733610440U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13346159398673246914U;
            aOrbiterA = RotL64((aOrbiterA * 13660497151446983393U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12121095718571872976U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 16239781125815589804U;
            aOrbiterF = RotL64((aOrbiterF * 5157009090454962231U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 36U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 3U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 4U) + aOrbiterB) + RotL64(aOrbiterA, 39U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterC, 54U));
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 11U)) + aOrbiterF) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 6423U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((aIndex + 4594U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6209U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneA[((aIndex + 1077U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCarry, 56U)) ^ (RotL64(aIngress, 27U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 52U)) + 15316464782468770057U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 41U)) + 6642872057476351588U;
            aOrbiterB = ((aWandererA + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 660732654689529192U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 29U)) + RotL64(aCarry, 27U)) + 7235418086884000655U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 3U)) + 14784518476694580493U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aIngress, 11U)) + 12222433977933449375U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 35U)) + 8573001207708329927U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 16035256260815013172U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 15767726974121910203U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 719060452537759331U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17712217935322939971U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 13488963456923357159U;
            aOrbiterC = RotL64((aOrbiterC * 16785285630840310405U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 10222949131965611079U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1495561412321657209U;
            aOrbiterE = RotL64((aOrbiterE * 9706305581868526265U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 16156530750584361434U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7773792489045606309U;
            aOrbiterH = RotL64((aOrbiterH * 10730624207715601393U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 11544578291333360613U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 3665587867634242865U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4840528190844842595U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 15248434984650998090U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 15487979645426567581U;
            aOrbiterG = RotL64((aOrbiterG * 10868107809356766183U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6972347795052712690U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 16074994810010431338U;
            aOrbiterF = RotL64((aOrbiterF * 1262655238856775853U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 37U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterH) + RotL64(aOrbiterF, 29U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 43U) + aOrbiterE) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 29U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterG, 57U));
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterG, 18U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterH, 39U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 14U) + aOrbiterB) + RotL64(aOrbiterG, 11U)) + RotL64(aCarry, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererA, 56U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 9659U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneD[((aIndex + 11383U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 10681U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 15933U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 18U)) + (RotL64(aPrevious, 39U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = ((aWandererK + RotL64(aCross, 21U)) + RotL64(aCarry, 21U)) + 9630214189402543339U;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 4072576573737526819U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 15994787452709618869U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererE + RotL64(aScatter, 51U)) + 6403240137132259482U) + aPhaseEOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 29U)) + 10229266900170507720U;
            aOrbiterF = (aWandererF + RotL64(aPrevious, 60U)) + 5025294577989748989U;
            aOrbiterD = (aWandererA + RotL64(aIngress, 39U)) + 16696461238217956883U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9878318855341719119U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 16086635438116177346U;
            aOrbiterI = RotL64((aOrbiterI * 5585682357395705671U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 12295437783084203730U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 7681150419912842402U;
            aOrbiterK = RotL64((aOrbiterK * 7289497379725191451U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2639104034287637448U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12298170009332243573U;
            aOrbiterG = RotL64((aOrbiterG * 9397919591171238575U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3485932317267669626U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 16569551670038752475U;
            aOrbiterE = RotL64((aOrbiterE * 8139802826402217631U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 4448490103784103954U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14510534073046885941U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7777192047386438305U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4286195398675733451U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15790355933840266463U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13342257823027075501U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6362891510370156055U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15121822034579983174U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7268045994574844937U), 5U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 42U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 51U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + aOrbiterJ) + RotL64(aOrbiterG, 19U)) + aPhaseEWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 41U));
            aCarry = aCarry + (RotL64(aWandererF, 58U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 20838U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18541U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18284U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 17222U)) & S_BLOCK1], 38U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 58U)) + (RotL64(aCross, 11U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = ((aWandererG + RotL64(aScatter, 11U)) + 1898718075389870739U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aCross, 41U)) + RotL64(aCarry, 39U)) + 5631794889237247403U;
            aOrbiterK = ((aWandererH + RotL64(aIngress, 5U)) + RotL64(aCarry, 23U)) + 18219714659484524607U;
            aOrbiterE = (aWandererC + RotL64(aPrevious, 47U)) + 15419581386225732921U;
            aOrbiterC = (aWandererK + RotL64(aIngress, 53U)) + 9125575431710198210U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 18U)) + 12205871520544965505U;
            aOrbiterA = (((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 11U)) + 7617534300497343422U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18017579105368135814U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 10693882161946020042U;
            aOrbiterK = RotL64((aOrbiterK * 2326507900303932855U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11669615701700895306U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 11045110212889232165U;
            aOrbiterH = RotL64((aOrbiterH * 5965171269273719849U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 18019107802806469913U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 12315940560472528716U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4505122470351404065U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 4899009736070044310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 17412253404253730364U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10791901166391946485U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4826286251927854181U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4523455921321845084U;
            aOrbiterC = RotL64((aOrbiterC * 14534103906736598099U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4132514462154182215U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 7164745605985109269U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 14107325508977225261U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6297434295807635654U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 8813887638672996646U;
            aOrbiterA = RotL64((aOrbiterA * 17495632530773158201U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 5U);
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterA, 11U)) + aPhaseEWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterE) + RotL64(aOrbiterF, 29U));
            aWandererC = aWandererC + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 37U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aCross, 41U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 57U)) + aOrbiterH) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + aPhaseEWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 28U) + RotL64(aOrbiterB, 50U)) + aOrbiterK) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 19U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 52U));
            aCarry = aCarry + RotL64(aWandererG, 23U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 26181U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 25898U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30221U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30142U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 43U)) ^ (RotL64(aIngress, 22U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 57U)) + 1557680213571812384U;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 51U)) + 7387349725778021121U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 27U)) + 15379264067601586976U) + aPhaseEOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aPrevious, 13U)) + 3730195724576043708U;
            aOrbiterI = (aWandererD + RotL64(aIngress, 5U)) + 9637070085323827066U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 43U)) + RotL64(aCarry, 13U)) + 1170865717363676184U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 2750833653175252030U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 15118992811225568305U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4974092922102988451U;
            aOrbiterC = RotL64((aOrbiterC * 10575977398702460975U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 10625719096296719514U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 855167122475471865U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7441090331293158773U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 11322911068958340262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 4334591909425429835U;
            aOrbiterB = RotL64((aOrbiterB * 10059025861172038183U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 14263701737208936392U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 678723206735649084U;
            aOrbiterI = RotL64((aOrbiterI * 10823239851733632227U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 15652053114252065230U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1705225940224061401U;
            aOrbiterG = RotL64((aOrbiterG * 3626023093533713579U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 6826394665732900206U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 11902946775066981141U;
            aOrbiterK = RotL64((aOrbiterK * 18300629262162694137U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9802212958998591310U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14001358545610206524U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 13172645840788327099U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 37U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD + ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterK, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 4U) + aOrbiterB) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterB, 42U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 19U) + aOrbiterH) + RotL64(aOrbiterI, 35U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 34U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4243U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneC[((aIndex + 3118U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 3918U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneA[((aIndex + 2291U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = (((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 41U)) + 10805654776556844351U) + aPhaseFOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aIngress, 5U)) + 582794182442795335U;
            aOrbiterH = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 2858343650974681068U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 14U)) + 8189584049022064284U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 29U)) + RotL64(aCarry, 13U)) + 1565100751996962893U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8062028016947611891U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8280504280578451745U;
            aOrbiterH = RotL64((aOrbiterH * 5212851648135050483U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11326869194491655350U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1671695656567777163U;
            aOrbiterK = RotL64((aOrbiterK * 7511554500524257921U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 2349843105293943452U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 13015545152052004254U;
            aOrbiterC = RotL64((aOrbiterC * 1316662811685429983U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 16703354404749291869U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 8713231044374305801U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9242480982197688625U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11118401674497783533U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 14857556493734710364U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 3452566050389715195U), 27U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 29U);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 57U) + aOrbiterK) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 34U) + RotL64(aOrbiterC, 13U)) + aOrbiterK) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterJ, 47U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB + (((RotL64(aCross, 13U) + RotL64(aOrbiterH, 30U)) + aOrbiterK) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 39U));
            aCarry = aCarry + RotL64(aWandererB, 51U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 10647U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15640U)) & S_BLOCK1], 40U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13069U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8384U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 39U)) ^ (RotL64(aCross, 23U) ^ RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererI + RotL64(aIngress, 18U)) + RotL64(aCarry, 23U)) + 7896237440058555694U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 51U)) + 11870529476037558635U) + aPhaseFOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = (aWandererB + RotL64(aCross, 29U)) + 9158983227801569448U;
            aOrbiterD = (((aWandererA + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 4710172270996950329U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 14634482800356647630U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 8822207952170610891U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 13755891414028982553U;
            aOrbiterB = RotL64((aOrbiterB * 5173750624716006485U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 4555293067488040719U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2816805148093762081U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16838149138341713943U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 2122631477965135190U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 4592922416380416071U;
            aOrbiterC = RotL64((aOrbiterC * 11644507904538573165U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7102471666524164715U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 17274623547879474204U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5443572270546181789U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 938587316977094680U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 18258015823797023523U;
            aOrbiterD = RotL64((aOrbiterD * 6068819567674605919U), 23U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 39U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 13U) + aOrbiterF) + RotL64(aOrbiterB, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 41U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 3U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 60U) + RotL64(aOrbiterC, 35U)) + aOrbiterA) + RotL64(aCarry, 27U)) + aPhaseFWandererUpdateSaltA[((aIndex + 29U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 56U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 46U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 22531U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 17105U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 20900U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 21614U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aIngress, 21U)) + (RotL64(aCarry, 34U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 17711946802293254150U;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 16652362590489569378U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aIngress, 19U)) + 6972810344198183097U;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 41U)) + 13117100889782940546U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 52U)) + 13199305696782626591U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 992156184392760945U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 13791265442074543880U;
            aOrbiterB = RotL64((aOrbiterB * 1263919538622722673U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17057087245252294859U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 13444195995883541046U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 13067044288608808777U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6723678233676059420U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 7913379431208430475U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2295062944289127123U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 4481887195529300665U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 11892724101424384078U;
            aOrbiterC = RotL64((aOrbiterC * 3468639499716604111U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7700902083270424194U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 1888001433557140271U;
            aOrbiterA = RotL64((aOrbiterA * 8975562955027025349U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 47U));
            aIngress = aIngress + RotL64(aOrbiterC, 22U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterC, 57U));
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 12U)) + aPhaseFWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 6U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 41U)) + aOrbiterB) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 43U);
            aCarry = aCarry + RotL64(aIngress, 52U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31643U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneB[((aIndex + 24605U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26999U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 26774U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 52U)) + (RotL64(aIngress, 35U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 10038936806177516123U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 53U)) + 1773168435195292638U;
            aOrbiterC = ((aWandererE + RotL64(aIngress, 58U)) + 10655711161526628072U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererH + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 14422295664639740437U;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 21U)) + 4125228715513159576U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3670449653158650845U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17553727567180813057U;
            aOrbiterC = RotL64((aOrbiterC * 11814335762020146785U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 5111401772713882743U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 7688573124662314413U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10846442063022821393U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9438375825507814395U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14177477039902118886U;
            aOrbiterA = RotL64((aOrbiterA * 6467406626985022537U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16329942595859623928U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3990536794006836672U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 579024714339065373U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 5072881436583180756U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 16789727877867289997U;
            aOrbiterD = RotL64((aOrbiterD * 8766246302636197905U), 29U);
            //
            aIngress = RotL64(aOrbiterB, 57U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterK) + RotL64(aOrbiterB, 27U));
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + RotL64(aOrbiterC, 3U)) + aOrbiterA) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltE[((aIndex + 9U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterD, 50U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 34U) + aOrbiterC) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 41U));
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
    std::uint64_t aOrbiterE = 0; std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0;
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 4800U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3915U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4070U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((aIndex + 4407U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aCross, 5U)) + 6469584119078165548U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 47U)) + 14329756366517987910U;
            aOrbiterB = ((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 29U)) + 12890831797059772123U;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 57U)) + 3164503807500018990U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 177531431387646836U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 3167421392893561015U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 2813174781844753460U;
            aOrbiterB = RotL64((aOrbiterB * 9760688894575305115U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 10953270419153249857U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 16911518309710356951U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 13162785997686570445U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6616750447844893150U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10276741398025985982U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6824712685896987133U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6206043608461213208U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 12021552904553405793U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10023362889960174909U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15283586234744144846U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5923238786775948571U;
            aOrbiterA = RotL64((aOrbiterA * 8200882393521882651U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 57U);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 3U)) + aOrbiterH) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 19U) + aOrbiterB) + RotL64(aOrbiterI, 19U)) + aPhaseGWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 52U) + RotL64(aOrbiterH, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 50U));
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10085U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneC[((aIndex + 14594U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16132U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15514U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 10U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (((aWandererB + RotL64(aCross, 24U)) + RotL64(aCarry, 35U)) + 11700815697312060726U) + aPhaseGOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 5U)) + 11808423452327465441U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aPrevious, 37U)) + 8670503858631730886U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 2400061067991988544U;
            aOrbiterB = (aWandererH + RotL64(aCross, 13U)) + 16163118178366229686U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3280178595904941068U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 3298683600817047727U;
            aOrbiterD = RotL64((aOrbiterD * 9865649058799255343U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 16321624053445183574U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6730229877611375225U;
            aOrbiterB = RotL64((aOrbiterB * 2022290495153519279U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10162830636713641322U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15646771327759599256U;
            aOrbiterI = RotL64((aOrbiterI * 15333053762177144775U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14841751262270544102U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 9545541117228834895U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11529769874752969377U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 14676615635857599982U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 1231768638470558855U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2716808508509014677U), 51U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 40U));
            aIngress = aIngress + RotL64(aOrbiterD, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterD, 19U));
            aWandererD = aWandererD + ((((RotL64(aCross, 13U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + aPhaseGWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterE, 43U)) + aOrbiterI) + RotL64(aCarry, 21U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 34U) + aOrbiterB) + RotL64(aOrbiterI, 6U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 16826U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 24420U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24109U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 17595U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 23U)) + (RotL64(aIngress, 50U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 29U)) + 2617613537256538553U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 16642868916835132715U;
            aOrbiterC = ((aWandererA + RotL64(aIngress, 38U)) + RotL64(aCarry, 13U)) + 10860291124337073254U;
            aOrbiterI = (aWandererB + RotL64(aCross, 19U)) + 6432511273906902472U;
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 5U)) + RotL64(aCarry, 29U)) + 7505375005848241910U) + aPhaseGOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 11086616004678821329U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3298830587569881951U;
            aOrbiterC = RotL64((aOrbiterC * 4304047944073454489U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9775143140064220979U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 4147601326580823120U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13462244678782260871U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 12245920269898100415U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 8391940489176734499U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9119606167674098007U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17876893379544668477U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 18301882058180370541U;
            aOrbiterI = RotL64((aOrbiterI * 16680384667098921309U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 6869225862715140102U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 15404118372589259800U;
            aOrbiterK = RotL64((aOrbiterK * 5766851935950389915U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 12U) + RotL64(aOrbiterH, 60U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterA, 51U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 11U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aCross, 21U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterK, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 30512U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((aIndex + 27373U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26222U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneC[((aIndex + 27962U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 6U) ^ RotL64(aCarry, 35U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 58U)) + RotL64(aCarry, 5U)) + 966899917801652720U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 13U)) + RotL64(aCarry, 41U)) + 10996327672320748649U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 5U)) + 4188171566846621107U) + aPhaseGOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 5886209243097387959U;
            aOrbiterC = (aWandererI + RotL64(aCross, 23U)) + 14940428957136728111U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 179187285531914832U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 6685351948936817752U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15533370414711696803U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 1894506461704029700U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 4182760368636977082U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 972988091869133921U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 12523318028514940790U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5059306166973366892U;
            aOrbiterD = RotL64((aOrbiterD * 2857409765717296483U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5890872367917643851U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 17747338389865221534U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5306740664798049267U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 13906227834259884100U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7152105382899756368U;
            aOrbiterC = RotL64((aOrbiterC * 6772157117358310485U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterG, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 14U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterG, 12U)) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 43U) + aOrbiterI) + RotL64(aOrbiterK, 23U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterC, 37U)) + aOrbiterI) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterD, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterC, 51U)) + aPhaseGWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + RotL64(aWandererF, 23U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 4155U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5198U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7182U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneD[((aIndex + 2974U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 26U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = (((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 9471546960258473684U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 23U)) + 18050235435948942244U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aScatter, 41U)) + 3005107102671544641U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 17898396434573801850U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 56U)) + 15071602525497771648U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 5780119462702672108U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 13301326224151025687U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2868878978993219351U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18129323022260575961U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 1199228670638790709U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1780426336211781025U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1839199978088021020U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4999517042246790165U;
            aOrbiterF = RotL64((aOrbiterF * 4585813675677234577U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8788607633376516299U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15143903839930468749U;
            aOrbiterD = RotL64((aOrbiterD * 12735914889325422675U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 16674732686428431869U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 15908873150953195581U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18049755517524334107U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterG, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 3U)) + aOrbiterD) + aPhaseHWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 40U)) + aOrbiterC);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterF, 29U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 10876U)) & S_BLOCK1], 26U) ^ RotL64(aExpandLaneC[((aIndex + 12136U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12184U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12676U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 30U) + RotL64(aCarry, 57U)) ^ (RotL64(aPrevious, 43U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererH + RotL64(aScatter, 13U)) + 12046647397183218524U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 2760779375026461991U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 57U)) + 13735454443176855650U) + aPhaseHOrbiterAssignSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 4370377000586647724U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 28U)) + RotL64(aCarry, 39U)) + 14566322384189969094U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 5056565959818422786U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 8795403810686579209U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11205867337479457471U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 9625947666256011567U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 1703669290934254701U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5763881345676123583U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6664070663184147951U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2104148316797553431U;
            aOrbiterE = RotL64((aOrbiterE * 12887842067180975983U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1197910004222596145U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9922977170060903197U;
            aOrbiterH = RotL64((aOrbiterH * 13047828062605568603U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 2048376210852567829U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 12568990647075931409U;
            aOrbiterD = RotL64((aOrbiterD * 9860242601194210927U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterD, 21U);
            aIngress = aIngress + (RotL64(aOrbiterE, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 58U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterE, 48U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 27U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterD, 57U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 39U)) + aOrbiterA) + RotL64(aCarry, 43U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 23U) + aOrbiterH) + RotL64(aOrbiterE, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererG, 19U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 18088U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 20557U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21665U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21169U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 10U)) ^ (RotL64(aCarry, 39U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 12775735908960052604U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 14U)) + 11791373812080296887U) + aPhaseHOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 5537362877706057303U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = ((aWandererD + RotL64(aPrevious, 37U)) + RotL64(aCarry, 13U)) + 2023912048504189380U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 3U)) + 17668828109963766893U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 558908629933941224U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 1479633119685446888U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4447153373540811385U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15460320397843364063U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 10059749397555469054U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8671817118586065469U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 9987633811929693924U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 10087337844580228269U;
            aOrbiterJ = RotL64((aOrbiterJ * 13817142288940843815U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4446204415503364254U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15106063243302192717U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13273756657334709803U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9430197906134676162U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1226048679997253363U;
            aOrbiterC = RotL64((aOrbiterC * 14247538885252664127U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 14U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 21U)) + aOrbiterH);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 13U) + aOrbiterK) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterH, 56U));
            aWandererI = aWandererI + (((RotL64(aScatter, 42U) + RotL64(aOrbiterJ, 43U)) + aOrbiterK) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 26302U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 27182U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28693U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((aIndex + 27966U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 43U) + RotL64(aIngress, 56U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 43U)) + 12136097566601676613U) + aPhaseHOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterC = ((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 7969431322248040056U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 5U)) + 10530676021510553889U;
            aOrbiterI = ((aWandererF + RotL64(aCross, 28U)) + RotL64(aCarry, 39U)) + 8740777303075445264U;
            aOrbiterB = (((aWandererG + RotL64(aScatter, 51U)) + RotL64(aCarry, 19U)) + 13249434169895564739U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15529577005925628472U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 344627093687331562U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3226087371456521323U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8824277416519988893U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 5636276438449709875U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 222817930773618893U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 2079413361031851552U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 7807998179168655561U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 961456853699784753U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 13589392896232029112U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10733011474804473996U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 361749145931578805U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15934162328347805968U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 7573511217796245232U;
            aOrbiterB = RotL64((aOrbiterB * 10694563909931636155U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 50U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 48U)) + aOrbiterE) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + (((RotL64(aCross, 39U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 11U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
