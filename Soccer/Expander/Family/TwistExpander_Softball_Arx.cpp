#include "TwistExpander_Softball_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Softball_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDE036DA4C7078F99ULL + 0xEA835C80751A4955ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xCA0779D2F464AD99ULL + 0xB0D1F02B7CE2B532ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xFB4856E6BBA6A1E1ULL + 0xE0BFF54C2F44E390ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF6C08A1086F0AF2DULL + 0x912E8C2CF142B765ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9AB793E1C628951DULL + 0xBE4E0731E0A1797DULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x9F0E693DB5B1A7E3ULL + 0xED641FCC9C8671F3ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC73A7B24E40E5DDFULL + 0xAE9628DF50A6E2EEULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDA8C7B75C21FB123ULL + 0xF62B08D4C412D971ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x99C38A01E255B0E1ULL + 0xDAB2C112A18565CBULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xE15AC1C9CB0562B1ULL + 0xB8F84D39C79365FAULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xADB0E6339878ACBDULL + 0xA8AF4E09EAAEEE28ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDED23084913C3E87ULL + 0xFA1F000A85809234ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xD29A3CDE17208507ULL + 0x82CF7DFDCA454112ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCA04FAEA7496DA19ULL + 0x87984F292082C239ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE4FBD141A14038E7ULL + 0x9E5240230FA1D12AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC01A976F8BB7FD37ULL + 0xBE077C1194061D2EULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 1224U)) & S_BLOCK1], 23U) ^ RotL64(pSnow[((aIndex + 4595U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 2029U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 4250U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 29U) + RotL64(aIngress, 58U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 6342299552323486695U;
            aOrbiterK = ((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 21U)) + 12692748514781367538U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 27U)) + 8202639945493229155U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 51U)) + 4439975701793231639U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 44U)) + 16774235182859553759U) + aNonceWordN;
            aOrbiterB = (aWandererB + RotL64(aScatter, 13U)) + 8764155413335405667U;
            aOrbiterH = (aWandererK + RotL64(aPrevious, 23U)) + 7167848811974967685U;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 35U)) + 16768278912125334220U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 47U)) + 9090838954826296201U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 37U)) + 7644075729758006298U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 58U)) + 17326182797908071215U) + aNonceWordP;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 16158809721888137555U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8029938783858263694U;
            aOrbiterI = RotL64((aOrbiterI * 12628072435324195483U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 8716553521415553404U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7012599977009208840U;
            aOrbiterB = RotL64((aOrbiterB * 8775355876188948851U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13250558696578541499U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 13705957059101025396U;
            aOrbiterE = RotL64((aOrbiterE * 16889495686487056367U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2796775206291902461U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13741676263512390669U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10455782033465595947U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1691908360612389252U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 4114939415206031540U;
            aOrbiterH = RotL64((aOrbiterH * 2797401802892718297U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2374911514440738727U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 12377616933668803091U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 2505164835116651215U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 681094033415259645U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13841322124900463362U;
            aOrbiterA = RotL64((aOrbiterA * 4210414203856902329U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 18082983557580381338U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15731122225678626778U;
            aOrbiterK = RotL64((aOrbiterK * 7785999919955613789U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2084336993254383330U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 3600882019682875370U;
            aOrbiterD = RotL64((aOrbiterD * 2977569829649654329U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 11436602278656592334U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5775886971784627864U;
            aOrbiterF = RotL64((aOrbiterF * 6765942246225582787U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 17120308925134658794U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6342299552323486695U;
            aOrbiterJ = RotL64((aOrbiterJ * 5788669985396507227U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 51U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 6U));
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 37U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterA) + aNonceWordM);
            aWandererB = aWandererB + ((RotL64(aScatter, 52U) + RotL64(aOrbiterF, 13U)) + aOrbiterH);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 37U) + aOrbiterE) + RotL64(aOrbiterJ, 39U)) + aNonceWordC) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterC) + RotL64(aOrbiterF, 46U));
            aWandererK = aWandererK + (((RotL64(aIngress, 19U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterI) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 27U)) + aOrbiterI) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 20U)) + aOrbiterF) + aNonceWordA);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 26U) + RotL64(aOrbiterK, 57U)) + aOrbiterD) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = aCarry ^ aNonceWordL;
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8351U)) & S_BLOCK1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5485U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(pSnow[((S_BLOCK1 - aIndex + 8388U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 8063U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 27U) + RotL64(aIngress, 56U)) ^ (RotL64(aCarry, 41U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (aWandererH + RotL64(aIngress, 46U)) + 785861751704720606U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 23U)) + 15968088718435606299U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 57U)) + 1393976526590347151U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 43U)) + 17240750947292745884U;
            aOrbiterC = ((aWandererK + RotL64(aCross, 21U)) + 4921576136163183137U) + aOrbiterAssignSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = (aWandererC + RotL64(aPrevious, 11U)) + 3334047873553153032U;
            aOrbiterF = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 15086509978458408698U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 892391205397581998U) + aNonceWordB;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 6U)) + 2965686403183767521U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 51U)) + 14632215393655706170U;
            aOrbiterI = (aWandererA + RotL64(aIngress, 13U)) + 15740589515342377322U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 11131164813943086445U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 6988080581278900960U;
            aOrbiterE = RotL64((aOrbiterE * 6412189142344044255U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 16021254613117657178U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6183615599897921154U;
            aOrbiterK = RotL64((aOrbiterK * 9976411093264211033U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12533992547026652747U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3104325358982904219U) ^ aNonceWordM;
            aOrbiterC = RotL64((aOrbiterC * 14977348108778147265U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3878525937957474644U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = (((aOrbiterF ^ aOrbiterH) ^ 2120435259884368445U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 15964718652193073177U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14928658302694194856U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 9121310461310309348U;
            aOrbiterA = RotL64((aOrbiterA * 17304439784647477491U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3715693239100476493U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 7336577492932262490U) ^ aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11074754160002665253U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2312452827448455675U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4322756069651934618U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6908893297397073539U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 4962079617577705818U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 5072727464750706525U;
            aOrbiterD = RotL64((aOrbiterD * 4947670001221089155U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4553791875259778686U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15823770920225774233U;
            aOrbiterH = RotL64((aOrbiterH * 409663191536830375U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9468608484284459072U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8658861660659699947U;
            aOrbiterJ = RotL64((aOrbiterJ * 2933359123761406353U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 14453429515273506170U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 785861751704720606U;
            aOrbiterI = RotL64((aOrbiterI * 3544627380583668815U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 54U);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterA, 43U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + aWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 6U) + aOrbiterF) + RotL64(aOrbiterC, 46U)) + aNonceWordE);
            aWandererF = aWandererF + (((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterA, 41U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 13U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 30U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterB, 11U)) + aOrbiterE);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 37U) + aOrbiterI) + RotL64(aOrbiterJ, 48U));
            aWandererB = aWandererB + (((RotL64(aIngress, 47U) + RotL64(aOrbiterK, 39U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 22U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterI, 57U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 21U)) + aOrbiterH) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 26U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11369U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11649U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(mSource[((S_BLOCK1 - aIndex + 11880U)) & S_BLOCK1], 57U) ^ RotL64(pSnow[((aIndex + 15713U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 4U) + RotL64(aCarry, 21U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 37U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererJ + RotL64(aIngress, 37U)) + 4068921616130916949U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 53U)) + 12077715273915151726U) + aNonceWordP;
            aOrbiterB = ((aWandererI + RotL64(aCross, 60U)) + 16047546802670596833U) + aNonceWordM;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 23U)) + 9690277462716999763U) + aNonceWordA;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 57U)) + 14484814700447992628U;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 43U)) + 17089267243053958210U;
            aOrbiterI = (aWandererC + RotL64(aCross, 42U)) + 9138746214446211147U;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 29U)) + RotL64(aCarry, 35U)) + 10181001536979097045U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 39U)) + 6657458969093373191U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aCross, 51U)) + RotL64(aCarry, 11U)) + 7515983477876590988U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 47U)) + 3039935555863947600U) + aOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 16209389224740851136U) + aNonceWordG;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 725253312098083182U) ^ aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17535989492095522597U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13307041115748941383U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7159572004825238263U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4855009895002398449U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12027236743251643820U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8717826175991286553U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1175614802543098451U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4769096034227659937U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11201226563992939616U;
            aOrbiterJ = RotL64((aOrbiterJ * 15595355978388159931U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17295978531215563256U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 11850923890626719833U;
            aOrbiterD = RotL64((aOrbiterD * 3854851059897397075U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 14139441565288097706U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 988684899382304485U;
            aOrbiterK = RotL64((aOrbiterK * 11929090869999700891U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 6159251276942253175U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 4849529993914550651U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 18240712676783671317U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 6679745455842119497U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15838404437552215214U;
            aOrbiterG = RotL64((aOrbiterG * 17357853511591350887U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 15853153471104458948U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12542164757451566994U;
            aOrbiterI = RotL64((aOrbiterI * 12163611303899312043U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 14304233464055838869U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 4037999346933039765U;
            aOrbiterA = RotL64((aOrbiterA * 564236202758328407U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3582312827630995454U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4068921616130916949U;
            aOrbiterF = RotL64((aOrbiterF * 1527829107415867363U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 11U);
            aIngress = aIngress + (RotL64(aOrbiterK, 22U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aIngress, 58U) + aOrbiterC) + RotL64(aOrbiterK, 19U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 27U) + aOrbiterK) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 35U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 11U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 34U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 46U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 41U)) + aOrbiterD);
            aWandererA = aWandererA + ((((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordJ);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 58U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aIngress, 41U) + aOrbiterA) + RotL64(aOrbiterF, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 58U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererI);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordO);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 20658U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((aIndex + 17271U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21535U)) & S_BLOCK1], 29U) ^ RotL64(mSource[((aIndex + 17999U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCarry, 23U)) + (RotL64(aIngress, 54U) + RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 13U)) + 3339283916456813609U;
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 43U)) + 11339086426180649584U) + aOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aCross, 47U)) + 16819191669329316585U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 27U)) + 8361916937762630725U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 11U)) + 18031328374429899857U) + aNonceWordP;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 44U)) + RotL64(aCarry, 19U)) + 18261756894092897276U;
            aOrbiterG = ((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 51U)) + 4250319792907645666U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 41U)) + 1492411503643460886U) + aNonceWordI;
            aOrbiterH = (aWandererH + RotL64(aScatter, 29U)) + 17369549067879344180U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 54U)) + 7301713524358676722U) + aOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 39U)) + 2985193736033012535U) + aNonceWordA;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14086975808140927408U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10390516547834639800U;
            aOrbiterJ = RotL64((aOrbiterJ * 11441293212275890819U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 18205555540941493267U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16967799565443938873U;
            aOrbiterA = RotL64((aOrbiterA * 3009081009044782443U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 9209505304067579944U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3522631966146762306U;
            aOrbiterK = RotL64((aOrbiterK * 3441982898533162599U), 19U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterA) + 8811497120829041188U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 14707301680850257294U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11383709499376464085U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 10080595991787801029U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 6822892187784299166U;
            aOrbiterE = RotL64((aOrbiterE * 7417016898027778287U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1981637172055758689U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16463077485583119324U;
            aOrbiterH = RotL64((aOrbiterH * 2876782050665869121U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8383837717361569465U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2788511294985017326U;
            aOrbiterF = RotL64((aOrbiterF * 2809163242875130677U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3529607472855930041U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8850940802020173766U) ^ aOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7821450253655655943U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7469160295100147267U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16973986572163482061U;
            aOrbiterB = RotL64((aOrbiterB * 15660743778376905023U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12371372942863279718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 12098525148034303633U;
            aOrbiterD = RotL64((aOrbiterD * 11234127652230231751U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 5138683482859889480U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 3339283916456813609U) ^ aNonceWordL;
            aOrbiterI = RotL64((aOrbiterI * 10975353228235695455U), 13U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 43U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 56U));
            aIngress = aIngress + RotL64(aOrbiterD, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aCross, 37U) + aOrbiterG) + RotL64(aOrbiterE, 41U)) + aWandererUpdateSaltC[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 6U) + aOrbiterH) + RotL64(aOrbiterK, 57U)) + aNonceWordE);
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 23U)) + aOrbiterF);
            aWandererC = aWandererC + (((((RotL64(aCross, 11U) + RotL64(aOrbiterG, 10U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordF) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererH = aWandererH + ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterD, 44U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterH, 53U)) + aOrbiterB);
            aWandererB = aWandererB + ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 22786U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22759U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25629U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22451U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCross, 37U)) + (RotL64(aPrevious, 57U) + RotL64(aCarry, 24U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aPrevious, 53U)) + 439898681482066326U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 57U)) + 17362083676671776094U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 6418499837265155024U) + aNonceWordH;
            aOrbiterE = ((aWandererH + RotL64(aCross, 29U)) + 17262244253027454972U) + aOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 3U)) + RotL64(aCarry, 19U)) + 2382066162993139503U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 37U)) + 14345808395587174135U;
            aOrbiterD = (aWandererF + RotL64(aIngress, 46U)) + 7534743166385552851U;
            aOrbiterB = (aWandererA + RotL64(aCross, 41U)) + 16994453324688523966U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 13U)) + 7079553728544045092U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 35U)) + 3562822704508440641U) + aOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aPrevious, 50U)) + 13990892681975857821U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 1796728922368577238U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6605161260520067178U;
            aOrbiterI = RotL64((aOrbiterI * 8147537646591674091U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13994083795942328918U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 6144523182899107711U;
            aOrbiterC = RotL64((aOrbiterC * 4153879991344611283U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12247462325297436642U) + aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1065809332002012789U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5496601177032953251U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 10147919864511540753U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17138553441127273354U;
            aOrbiterJ = RotL64((aOrbiterJ * 5773875596275267871U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2653924016109573974U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 6254416952351699582U;
            aOrbiterH = RotL64((aOrbiterH * 12756861659704947257U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 813046408080197079U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 9624466135414123483U) ^ aOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6960320253124395015U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 972586705850825744U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 155283774901960223U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 9928051687724257041U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 18200100644751360406U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 1168426822045686004U;
            aOrbiterA = RotL64((aOrbiterA * 5867027156069481313U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2271564377169233643U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 1896317305868283986U;
            aOrbiterK = RotL64((aOrbiterK * 8080751157990019287U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 10209708407397294552U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 947585551223387294U;
            aOrbiterG = RotL64((aOrbiterG * 15339472308062247067U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12313594490465462211U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 439898681482066326U;
            aOrbiterF = RotL64((aOrbiterF * 12336632799055203705U), 41U);
            //
            aIngress = RotL64(aOrbiterF, 30U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 11U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 56U)) + aOrbiterF);
            aWandererA = aWandererA ^ ((RotL64(aCross, 6U) + aOrbiterI) + RotL64(aOrbiterC, 19U));
            aWandererF = aWandererF + (((RotL64(aIngress, 43U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + aNonceWordA);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 41U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterK, 21U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 27U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 31219U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 30180U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29626U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((aIndex + 28773U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 37U) + RotL64(aCarry, 10U)) ^ (RotL64(aCross, 51U) + RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aPrevious, 43U)) + 3236820517816085022U) + aNonceWordE;
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 47U)) + 741288875914097926U) + aNonceWordA;
            aOrbiterB = ((aWandererG + RotL64(aCross, 18U)) + 8417246926007729580U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 29U)) + 9715717805774537170U;
            aOrbiterF = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 14360243844821619482U;
            aOrbiterD = (aWandererF + RotL64(aScatter, 37U)) + 10760908100206775334U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 39U)) + 3434641779946167811U) + aOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aPrevious, 53U)) + 7885568822756234567U;
            aOrbiterE = (((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 37U)) + 3041563437672051294U) + aNonceWordC;
            aOrbiterC = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 47U)) + 15761355327564963516U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 12U)) + 1158633562785937421U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 9338581575871970653U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9172038894262857354U;
            aOrbiterB = RotL64((aOrbiterB * 3110871165285625807U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14653924713599790081U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3854497592598563309U;
            aOrbiterF = RotL64((aOrbiterF * 11737111068815795303U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 16286980180327600557U) + aNonceWordL;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5092583772591249756U) ^ aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13955105624639442903U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4288397994175567333U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15584236478994873104U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1860480595862755379U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5557463939827483792U) + aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 2659814275753280856U;
            aOrbiterG = RotL64((aOrbiterG * 17702430405693184643U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6941807963525063449U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2040598555191211307U;
            aOrbiterE = RotL64((aOrbiterE * 14750544987531722765U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 347572666231116258U) + aOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 779304821185302523U;
            aOrbiterC = RotL64((aOrbiterC * 14180254150318109855U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 10632524582873079742U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 9761308771280517212U;
            aOrbiterI = RotL64((aOrbiterI * 13926235411726048921U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2097439707055737964U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2813977930321463948U;
            aOrbiterA = RotL64((aOrbiterA * 14983538728730662603U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6080592019313796689U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5396623654821376409U;
            aOrbiterJ = RotL64((aOrbiterJ * 15478858835919398677U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8460497459575045342U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 3236820517816085022U;
            aOrbiterK = RotL64((aOrbiterK * 5530411244458067093U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 58U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterI, 34U));
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 3U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterE, 51U));
            aWandererE = aWandererE + ((RotL64(aIngress, 11U) + aOrbiterH) + RotL64(aOrbiterJ, 21U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 28U) + aOrbiterE) + RotL64(aOrbiterK, 53U));
            aWandererD = aWandererD + (((RotL64(aIngress, 39U) + aOrbiterC) + RotL64(aOrbiterE, 13U)) + aNonceWordH);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 5U)) + aOrbiterA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 51U)) + aWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterB, 37U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 56U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 10U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 37U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Softball_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB859BE7BF63937F9ULL + 0xE8E469D7B3B93D75ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xB8AC878149B87DE5ULL + 0xC24BEDD0BECCB10BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xEED88D58AC97C561ULL + 0xFE6445944C7F8F79ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9127BA2DB1C66765ULL + 0xDE782E412E21C43AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8E6E267D8E1A86D3ULL + 0xB3F1C8EF9D79241BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xDE7CFBC21A3A415FULL + 0xE64EFC3A317F68CCULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD1967183A80B0BC7ULL + 0xC9D8B63A19A8B570ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xAF9AEEB976B5DB89ULL + 0xCEE2FC4EF38819C2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x974A12EF8069B749ULL + 0xA972BF062B0C2D19ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF575F3C411DCEE6FULL + 0xD72901E7DE3A14B3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF845510B9E1E2DC7ULL + 0x81BCFA69D30D2A2BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFAF15B325240F1EFULL + 0xC6B14867AF7E8134ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xAB32EA5DAFA1FB53ULL + 0xBDBC9352D997DB41ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC7F60B3C780EC463ULL + 0x8344DBC2CF7F2641ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xAE3B87C31919F02DULL + 0xAB75410EBA1B2389ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xD4DBEF2D51453BCFULL + 0xAE5924E01FEE8BE3ULL);
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 8147U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneC[((aIndex + 5450U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4188U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 2604U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 22U) + RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererC + RotL64(aCross, 35U)) + 3248574644570178787U;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 4506961512959200024U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 47U)) + 8423739774540738590U) + aNonceWordE;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 6593975869641735337U) + aOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aCross, 30U)) + 16441716090557369103U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 43U)) + 7936601450453207914U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 5U)) + 13333752583560167065U) + aNonceWordO;
            aOrbiterE = (aWandererB + RotL64(aScatter, 13U)) + 8013703284795432973U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 18U)) + 2349852779887439236U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5318539364763284138U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 11450957608502944376U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 1957880366707810635U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 9058992558327552687U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 632095686920230926U;
            aOrbiterB = RotL64((aOrbiterB * 12460364388358520799U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14734218428913777098U) + aNonceWordM;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 16344357661370784442U) ^ aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15049472842002138369U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 2981145363531184308U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 14176472085175714494U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2584623327412130939U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11198457590069700889U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 952584436750426828U;
            aOrbiterA = RotL64((aOrbiterA * 1165713888651280355U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4311591763498985972U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16194341833989936369U;
            aOrbiterC = RotL64((aOrbiterC * 9997934560195932575U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7560794022401107431U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10683789740265711603U;
            aOrbiterG = RotL64((aOrbiterG * 15637823045351977883U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11614366395125937178U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10750771385100564416U) ^ aOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4987921274272444283U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2934697034132204529U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4646873794658020363U;
            aOrbiterF = RotL64((aOrbiterF * 10555456865641580175U), 39U);
            //
            aIngress = RotL64(aOrbiterB, 18U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterC, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterE, 27U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 11U)) + aOrbiterB) + aNonceWordJ) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 48U) + aOrbiterG) + RotL64(aOrbiterD, 40U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterB, 57U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterD) + RotL64(aCarry, 51U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 30U) + aOrbiterF) + RotL64(aOrbiterH, 3U)) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 52U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererC, 24U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordG);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 13068U)) & S_BLOCK1], 42U) ^ RotL64(aExpandLaneD[((aIndex + 13494U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 11605U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 13766U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 3U) ^ RotL64(aCross, 34U)) + (RotL64(aCarry, 21U) + RotL64(aIngress, 53U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (((aWandererG + RotL64(aScatter, 26U)) + 479672811032092393U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 18061121631394564425U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 35U)) + 14237400452740566065U;
            aOrbiterK = (aWandererB + RotL64(aCross, 39U)) + 6723123812257706134U;
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 19U)) + 4247997188026499248U) + aOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aIngress, 13U)) + 1939107415066134869U;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 58U)) + RotL64(aCarry, 47U)) + 3912640123546395979U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 43U)) + RotL64(aCarry, 3U)) + 8295478436553964298U;
            aOrbiterB = (aWandererJ + RotL64(aPrevious, 47U)) + 3218960600711526885U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 5874096203353388890U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10294536533673023358U;
            aOrbiterD = RotL64((aOrbiterD * 15561710414949058923U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 11268561953904130747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16693201256788898423U;
            aOrbiterH = RotL64((aOrbiterH * 16291987237693567209U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 7550969634681894654U) + aNonceWordH;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 9501647424602245869U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11265865222096866605U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8881869255994319423U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 16770136406906800016U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1782039587385512923U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16185384746435761363U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13841034186650721627U;
            aOrbiterB = RotL64((aOrbiterB * 12000155593277035447U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 15229062695864608309U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3576122704615303733U;
            aOrbiterA = RotL64((aOrbiterA * 2433987493885779279U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13898167174453181224U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12878032061609524049U;
            aOrbiterK = RotL64((aOrbiterK * 18104665741338251495U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 12719156051299028649U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8640980843376950769U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10242616778390983333U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12133332160916004365U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 8743563985229104484U) ^ aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4575129690615054691U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 14U));
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 29U)) + aWandererUpdateSaltD[((aIndex + 22U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 18U) + aOrbiterI) + RotL64(aOrbiterH, 30U));
            aWandererI = aWandererI + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterC, 53U)) + aOrbiterI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 23U)) + aOrbiterC) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 60U) + RotL64(aOrbiterH, 5U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterJ) + RotL64(aOrbiterB, 60U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 13U)) + aNonceWordI);
            aWandererE = aWandererE + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterK, 39U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 19577U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 17037U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16890U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneC[((aIndex + 22003U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) ^ RotL64(aIngress, 5U)) + (RotL64(aCarry, 35U) + RotL64(aPrevious, 48U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterC = (aWandererE + RotL64(aPrevious, 35U)) + 5576732410244514238U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 53U)) + 2833808925935929629U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 13U)) + 3670188682914544792U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererC + RotL64(aScatter, 6U)) + RotL64(aCarry, 51U)) + 15759072378887814995U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 23U)) + 13934007231137439994U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 43U)) + 11022225696007690512U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 16989177104453635790U;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 27U)) + 9256930045263527091U) + aNonceWordA;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 58U)) + RotL64(aCarry, 3U)) + 17788596104417068290U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17044369456673337625U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1310908395523250343U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16305084373037705921U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12067065689034065422U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15130844248737512262U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 9409499577465934107U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14532689204495587494U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 8198147292120244178U) ^ aOrbiterUpdateSaltE[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1418356389507740991U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5485494458627163347U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10830008207150307611U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 6526039534042499457U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 17770065502486618029U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 6397859353395335459U;
            aOrbiterF = RotL64((aOrbiterF * 14286997752368893825U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 5128700697381508319U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7103394110057060499U;
            aOrbiterD = RotL64((aOrbiterD * 5053680689949149633U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16024401282261796979U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 12818445221897253410U;
            aOrbiterB = RotL64((aOrbiterB * 11450004517784155405U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 13386978409145916350U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 16740821954556699503U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5376430209628515105U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 313978038530994953U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1355733685461795345U;
            aOrbiterG = RotL64((aOrbiterG * 15955927322082619735U), 39U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 58U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 39U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 47U)) + aOrbiterG) + aNonceWordD) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 35U));
            aWandererD = aWandererD + ((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterF, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 18U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterK, 53U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 46U) + RotL64(aOrbiterG, 13U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 18U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererB);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30849U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29007U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordL;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28319U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 29481U)) & S_BLOCK1], 36U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 27U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererK + RotL64(aPrevious, 23U)) + 7948891781097675369U;
            aOrbiterI = ((aWandererE + RotL64(aCross, 29U)) + RotL64(aCarry, 5U)) + 13928362874228230226U;
            aOrbiterF = ((((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 57U)) + 10776180542602258926U) + aOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordA;
            aOrbiterC = (aWandererF + RotL64(aScatter, 37U)) + 5735115172149470447U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 42U)) + 5353591822981766987U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 47U)) + 562301708107268570U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 53U)) + 10467810247578364868U) + aNonceWordH;
            aOrbiterH = ((aWandererH + RotL64(aCross, 13U)) + 14541630141152308564U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterK = ((aWandererD + RotL64(aScatter, 6U)) + RotL64(aCarry, 41U)) + 2350076897065139429U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17519109078651162228U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 6061035173339902910U) ^ aOrbiterUpdateSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10021905773432907835U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15654836633731000065U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13723521735153718904U;
            aOrbiterE = RotL64((aOrbiterE * 14459516479283070563U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 2849680038315532197U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 17336102435576647923U;
            aOrbiterB = RotL64((aOrbiterB * 10984689101753586739U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 7671010488872356142U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 11485114338165600777U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4162584865462407791U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 8759060657343458985U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 11009137869375286581U) ^ aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8741417343929809115U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 15792999392743144135U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 6180808423175992479U;
            aOrbiterG = RotL64((aOrbiterG * 13681230339693676907U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 361487389591183005U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15292753806514404853U;
            aOrbiterH = RotL64((aOrbiterH * 17478232597253311153U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 14929153438443362045U) + aNonceWordK;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7904556383593914086U;
            aOrbiterK = RotL64((aOrbiterK * 2484130486635511403U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 3793180909904286848U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 10391957637467171320U;
            aOrbiterI = RotL64((aOrbiterI * 505484041943467117U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterK, 50U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + aOrbiterA) + RotL64(aOrbiterH, 60U));
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 21U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 35U)) + aOrbiterH) + aWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 47U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterI, 39U)) + aOrbiterC) + aNonceWordC);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterI, 12U));
            aWandererH = aWandererH + (((RotL64(aIngress, 5U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + RotL64(aCarry, 47U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 24U) + RotL64(aOrbiterE, 43U)) + aOrbiterK) + aWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 10U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererG, 53U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordO);
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

void TwistExpander_Softball_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAC0571502E0D4081ULL + 0x9C83432A8621E9C7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBD9CD997C830497BULL + 0xFC06060248892DA8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xCB8A0E85768F8189ULL + 0xD8BC1F59E9567537ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB21A8D4D514BEBE5ULL + 0xEB51AAA7C1FCF602ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xCB918EF4B0BED63DULL + 0x95D7FA9E11A3C1E5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x81B6069238E4F8B5ULL + 0xB5D6D66A680A7865ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x99E10BA2CF01F5D5ULL + 0xC80AAD95B65735F5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA03E4EC7F6B89EE5ULL + 0xDD21431171C2C8B8ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x9F89188310E2651DULL + 0x88E8102E8AAA4D32ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9A799E859F8ECA39ULL + 0x9EBC7F02655C0D14ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xEAD2B43BCEC7FB0DULL + 0xD001B1BA0AC055AAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFAFF8ED35546F785ULL + 0xF77DD59152F1359FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xB307E47059CCCB0DULL + 0xAE3419B4FAEAE773ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8D500F3CC80CCE73ULL + 0xCBD9E8AC99A9151BULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x98120EFFC1FEFEC1ULL + 0xF9BF00DFD759F7B5ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD43931BE6E8361ABULL + 0xDB904EAC1CEED072ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 5796U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7743U)) & S_BLOCK1], 18U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4771U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 2169U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 20U)) + (RotL64(aCross, 57U) ^ RotL64(aIngress, 41U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 57U)) + 5171470532667965920U;
            aOrbiterK = (((aWandererC + RotL64(aCross, 57U)) + 750549462358682403U) + aOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 35U)) + RotL64(aCarry, 29U)) + 3325689257577120525U;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 11U)) + 18031575461559790826U) + aOrbiterAssignSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aWandererK + RotL64(aCross, 48U)) + 13874739537012288677U;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterK) + 4250029868785016865U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8211158803112611161U;
            aOrbiterH = RotL64((aOrbiterH * 9205801383408193959U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 1083939790236786027U) + aNonceWordG;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3446525462376962464U;
            aOrbiterE = RotL64((aOrbiterE * 13603702473750888213U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6973817815000417325U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15230876489676945543U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7737039082964537651U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9359727659738755880U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8775170107816327654U) ^ aOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6910680458261008653U), 29U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterC) + 11958941755525038545U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16966819714283167348U;
            aOrbiterD = RotL64((aOrbiterD * 16363457661846050749U), 5U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 57U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 37U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + aNonceWordI);
            aWandererG = aWandererG ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterD, 52U)) + aWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aNonceWordF);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 11U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + RotL64(aWandererK, 19U);
            aCarry = aCarry + RotL64(aIngress, 52U);
            aCarry = aCarry ^ aNonceWordD;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 16101U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 10976U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8581U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneB[((aIndex + 14483U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) + RotL64(aCross, 4U)) ^ (RotL64(aIngress, 21U) + RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterG = (((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 27U)) + 17668251151213543491U) + aNonceWordF;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 16101602509895104517U;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 37U)) + 9083915270773304935U) + aOrbiterAssignSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aScatter, 60U)) + RotL64(aCarry, 13U)) + 12810720730318214811U) + aNonceWordH;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + 18113428002071925621U) + aOrbiterAssignSaltD[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 1582208899354109878U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 4180688104819188154U;
            aOrbiterJ = RotL64((aOrbiterJ * 3391785441902730815U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8954598189262820611U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15360094153175355879U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8177798855402983685U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8383954114668216260U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 15626783326234049197U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 15058420415480073793U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 10609978564404958066U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 17656516608997517984U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4590620354119899777U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 760077259110786536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3597338735888033063U;
            aOrbiterH = RotL64((aOrbiterH * 6548831472863517621U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + RotL64(aOrbiterA, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 3U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 56U) + RotL64(aOrbiterG, 23U)) + aOrbiterH) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterA, 36U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererI, 48U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordD);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23278U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 22968U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 23203U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 19717U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 54U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 21U)) + 4752759164691497960U) + aNonceWordH;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 3U)) + 12088872623537639782U) + aOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aCross, 21U)) + 3734943577379734227U) + aNonceWordG;
            aOrbiterC = ((((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 35U)) + 8854778183012444234U) + aOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = (aWandererI + RotL64(aCross, 56U)) + 16948373492893967275U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 7962415690046184385U) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 1872682375669714454U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 959061892772099785U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterB) + 7776801806943853566U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 16665439117257230732U;
            aOrbiterJ = RotL64((aOrbiterJ * 6866375628213114965U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 11088186766134265676U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10850237991780969350U;
            aOrbiterB = RotL64((aOrbiterB * 7547414856143095121U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 6464817712131305812U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 244557182884209844U;
            aOrbiterC = RotL64((aOrbiterC * 2394270354887582889U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 13261563971157415841U) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2323811103717827362U;
            aOrbiterD = RotL64((aOrbiterD * 11483723582415081925U), 11U);
            //
            aIngress = RotL64(aOrbiterB, 30U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aIngress, 30U) + aOrbiterJ) + RotL64(aOrbiterB, 57U)) + aNonceWordC);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 19U) + aOrbiterF) + RotL64(aOrbiterD, 29U)) + RotL64(aCarry, 21U)) + aNonceWordP) + aWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterC, 5U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 44U)) + aOrbiterF) + aWandererUpdateSaltA[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31880U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneB[((aIndex + 25245U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 26357U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((aIndex + 25523U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 6U) ^ RotL64(aIngress, 35U)) + (RotL64(aPrevious, 21U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = ((aWandererA + RotL64(aScatter, 36U)) + 11039986441331892533U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 21U)) + 6256024955965426119U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 9857443189988995666U;
            aOrbiterC = ((((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 53U)) + 11900944813380998208U) + aOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1]) + aNonceWordO;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 21U)) + 8422577734978875541U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3100835100713928724U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11871553509810206993U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15501681886909921677U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 17614749493763417027U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 3638372131856199916U;
            aOrbiterI = RotL64((aOrbiterI * 480683274898147025U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 6582275259281025770U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17016882418498941958U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4269869255230867823U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1747214688658984715U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 9356088987044015278U;
            aOrbiterG = RotL64((aOrbiterG * 16221733545319753695U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4056238112133473456U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 16013150119949532998U;
            aOrbiterJ = RotL64((aOrbiterJ * 12913648646318115315U), 35U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterG, 18U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + aWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterD, 56U)) + aOrbiterC);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 48U) + RotL64(aOrbiterJ, 11U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aNonceWordP);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterG, 29U)) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = aCarry ^ aNonceWordA;
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

void TwistExpander_Softball_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xFD523651B41C4A05ULL + 0xAEF396EA3CE8FABFULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x87B923FA8A1F0795ULL + 0x8C90E0F482088F4FULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x82AEDBDCC075A657ULL + 0x88F220F5A50D3167ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAE925938D47499D5ULL + 0xFABA16CAF4870ADDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xD16A517C373B148DULL + 0x8D0AAD4CF4CCD7A5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9403A2B9ED8A565BULL + 0xFA8A42ADBFAAFDB6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB236DA50F8E76C85ULL + 0x9F1715433EFE65B7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xED3DE6FD42618861ULL + 0xC62277B373533655ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xCB5E2FB1CAF6D63BULL + 0xC62BFC95731B104EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xEFDD0521813F4ED5ULL + 0x9F6D880090A2F706ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD95DC25F08D69399ULL + 0xE967AEB8B9B82C0CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC7B8F6789868ABC1ULL + 0xC32CAB36628F39DFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFA3B82120B4E8565ULL + 0x9D10F39C8C8EE9D3ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFDDD4799273D1233ULL + 0xCEEAE0F346BD646DULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xBD58AB07DE8F6E13ULL + 0xF4F0C01234DBE119ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0x9FD4D7F769B35873ULL + 0x9FF318687ABBDC82ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2987U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 5768U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6112U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 451U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aIngress, 57U)) + (RotL64(aCarry, 43U) ^ RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererH + RotL64(aIngress, 12U)) + RotL64(aCarry, 19U)) + 11274974230580265396U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 41U)) + 16658438747342741547U) + aNonceWordA;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 47U)) + 16612986966106053844U) + aOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = ((aWandererA + RotL64(aCross, 27U)) + 9329502236843231290U) + aOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aScatter, 5U)) + 14088261356708344656U;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 19U)) + RotL64(aCarry, 5U)) + 13692608802007789581U) + aNonceWordE;
            aOrbiterH = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 37U)) + 6824473946645682398U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 2072915876348570040U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 7420507753044460759U) ^ aOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13239288539564571257U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4677557318688502593U) + aOrbiterUpdateSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 15081678577055628459U;
            aOrbiterK = RotL64((aOrbiterK * 16659305295251177155U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 7026792817486507482U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14871665922943969918U;
            aOrbiterE = RotL64((aOrbiterE * 694073180313083145U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 6807734532159292872U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 17882797335141303280U) ^ aNonceWordJ;
            aOrbiterH = RotL64((aOrbiterH * 15439872930381050291U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 9233542707022629190U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1205501586581350876U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 2596053290311090589U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 10878718669747466677U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8066049063548639241U;
            aOrbiterD = RotL64((aOrbiterD * 3031382633089381605U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 861295180226875235U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9134969787937288583U;
            aOrbiterF = RotL64((aOrbiterF * 7565008208670843555U), 53U);
            //
            aIngress = RotL64(aOrbiterE, 19U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterA, 34U)) + aOrbiterE) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterC, 53U)) + aOrbiterA) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 41U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aCross, 54U) + aOrbiterH) + RotL64(aOrbiterK, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 19U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 28U));
            aCarry = aCarry + RotL64(aWandererA, 53U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 13475U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13944U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 15478U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((aIndex + 9118U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 13U) + RotL64(aCross, 27U)) ^ (RotL64(aIngress, 60U) + RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 39U)) + 8020711767807230555U) + aOrbiterAssignSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 15368693777246341570U) + aNonceWordA;
            aOrbiterI = (aWandererG + RotL64(aScatter, 5U)) + 5117523734225562401U;
            aOrbiterA = (aWandererB + RotL64(aIngress, 57U)) + 13155269151097507808U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 14U)) + RotL64(aCarry, 35U)) + 9879303753623578272U;
            aOrbiterJ = (((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 3U)) + 1165799257173794826U) + aOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 29U)) + 930641942062732091U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11330571332221123153U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2862963158282518899U;
            aOrbiterI = RotL64((aOrbiterI * 13782195862525974199U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 6019186399361476659U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1924419843785161958U;
            aOrbiterH = RotL64((aOrbiterH * 9485557122500346869U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 12618629043591380461U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 9334176504266512405U;
            aOrbiterA = RotL64((aOrbiterA * 18239109235362925739U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 16829692481030013551U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 5604784396927022709U;
            aOrbiterE = RotL64((aOrbiterE * 2833893610883508353U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 16124030106598549644U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16571659812830230677U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4668250364992383549U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15171089673591843703U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 2826755560293849328U;
            aOrbiterJ = RotL64((aOrbiterJ * 9397017963457655287U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 9976785768283589291U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 11845100564714691809U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4935139932585319251U), 23U);
            //
            aIngress = RotL64(aOrbiterK, 35U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterJ, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterE, 13U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 12U) + aOrbiterA) + RotL64(aOrbiterE, 51U)) + aNonceWordI) + aWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterH, 29U)) + RotL64(aCarry, 53U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterA, 39U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterD, 21U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 58U)) + aOrbiterD) + aNonceWordJ) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 57U) + RotL64(aOrbiterA, 3U)) + aOrbiterI);
            //
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 42U));
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23716U)) & S_BLOCK1], 20U) ^ RotL64(aWorkLaneA[((aIndex + 18763U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 23366U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19571U)) & S_BLOCK1], 26U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 35U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 47U) ^ RotL64(aIngress, 60U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterD = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 3U)) + 2177539223979303669U;
            aOrbiterC = ((aWandererG + RotL64(aCross, 37U)) + 3962004686551521471U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 13U)) + 8457602312617147662U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 60U)) + 18011802451816510632U) + aNonceWordB;
            aOrbiterI = (aWandererD + RotL64(aCross, 47U)) + 9046101759168876832U;
            aOrbiterJ = (((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 41U)) + 11135620637431969597U) + aOrbiterAssignSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 27U)) + RotL64(aCarry, 19U)) + 15913029940697999701U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16304193109948135982U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13208892298820080981U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 15093751072618884859U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 4182377898949419225U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 13970137023071326151U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9075061559681739865U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8402396284835248583U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8859190834060657829U;
            aOrbiterD = RotL64((aOrbiterD * 13552418608113716117U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 9760005337757990392U) + aOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14108277760135744897U;
            aOrbiterG = RotL64((aOrbiterG * 4474681104256093885U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 12226316121949012350U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3456392186754113960U;
            aOrbiterI = RotL64((aOrbiterI * 8704729827929941215U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5004087958637038973U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7176881295123125567U;
            aOrbiterJ = RotL64((aOrbiterJ * 15272157962928021009U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 10889800478505074438U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 13728832441482547824U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 17588477761978646139U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aCross, 20U) + aOrbiterF) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterI, 47U));
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 29U)) + aOrbiterG) + aNonceWordO) + aWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterJ, 21U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 53U)) + aNonceWordF);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 60U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordE;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 30133U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27905U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30508U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneD[((aIndex + 28610U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 3U)) + (RotL64(aCarry, 27U) ^ RotL64(aIngress, 54U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererD + RotL64(aScatter, 51U)) + 9471546960258473684U) + aNonceWordL;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 14U)) + 18050235435948942244U) + aNonceWordE;
            aOrbiterF = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 35U)) + 3005107102671544641U) + aOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 17898396434573801850U) + aOrbiterAssignSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (((aWandererA + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 15071602525497771648U) + aNonceWordG;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 35U)) + 5780119462702672108U;
            aOrbiterB = (aWandererI + RotL64(aCross, 41U)) + 13301326224151025687U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 18129323022260575961U) + aNonceWordH;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1199228670638790709U) ^ aOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1780426336211781025U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 1839199978088021020U) + aOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4999517042246790165U;
            aOrbiterD = RotL64((aOrbiterD * 4585813675677234577U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8788607633376516299U) + aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 15143903839930468749U;
            aOrbiterJ = RotL64((aOrbiterJ * 12735914889325422675U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16674732686428431869U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 15908873150953195581U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18049755517524334107U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 11204775359756474667U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 2525984309543939465U;
            aOrbiterH = RotL64((aOrbiterH * 3988529812023791571U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4566345170476825512U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14876612901557406267U;
            aOrbiterE = RotL64((aOrbiterE * 9047956948845135339U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14926290877038883931U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 12710203178186614846U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 14841163494801662515U), 41U);
            //
            aIngress = RotL64(aOrbiterB, 35U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 10U) + aOrbiterE) + RotL64(aOrbiterJ, 3U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 30U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterH, 57U)) + aWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterE, 21U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 28U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordJ;
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

void TwistExpander_Softball_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB1503269BAA85743ULL + 0xCC301E7289CF04E4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x95DDFB438377EFBFULL + 0xA14031BEF3C3FF46ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA7141BB6760006D5ULL + 0xBE42E3258E540127ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xFA7315E9729B38D5ULL + 0xFF4D402F7F61490FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x983BF4330C6FC73FULL + 0x8ED1CF0C09FE2C77ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xD23AD0978589D567ULL + 0xF7320CD8C6039A47ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD451DFD860BDC537ULL + 0xFAD06852F3D1342CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD1E0BE91B2D9BD6DULL + 0x957AEE9833AE8455ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFBC39B49FEB0249DULL + 0xEFEB7D007F018809ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD9AD302CA88FFF09ULL + 0x928919847352A985ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD915E2613F7FEA2DULL + 0x88822C7E5426D7C4ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x99B2FCCB640142A3ULL + 0x9AE51135B657EC3EULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE46E7018444D437FULL + 0xDA0BD7A92F4F0598ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xB57D8AAD1C63809BULL + 0xFB4887B8683BF9CFULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB9C8110B68E17303ULL + 0x97226D3C89F2F1F6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA1E1FDE6F9F5047FULL + 0xB8E97C76B42F0097ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 1203U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneC[((aIndex + 365U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1958U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 4675U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 58U)) + (RotL64(aIngress, 13U) ^ RotL64(aCarry, 27U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (((aWandererI + RotL64(aCross, 11U)) + 9435962834163239322U) + aOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aWandererB + RotL64(aIngress, 53U)) + 10524704356081318973U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 7403401305665208680U;
            aOrbiterA = (aWandererA + RotL64(aPrevious, 43U)) + 7525414805023556493U;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 3U)) + 1116686470029070951U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 43U)) + 13257612299137802420U) + aNonceWordL;
            aOrbiterC = (aWandererC + RotL64(aCross, 18U)) + 9181543003986598283U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 9739384852307501107U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 11308402900229016057U;
            aOrbiterF = RotL64((aOrbiterF * 12690186771773188967U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 14935167593705272337U) + aOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7171824007631943535U;
            aOrbiterJ = RotL64((aOrbiterJ * 4839974427616194289U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8068411284829563567U) + aOrbiterUpdateSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 12350207458513447578U;
            aOrbiterB = RotL64((aOrbiterB * 813973258659041895U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17039236343991574134U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 18291683592714999632U;
            aOrbiterC = RotL64((aOrbiterC * 7771718817924840713U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 6239616841884430968U) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10604527977569876774U;
            aOrbiterI = RotL64((aOrbiterI * 6972820410084939637U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 1707724300671717658U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3802268808625297647U;
            aOrbiterA = RotL64((aOrbiterA * 11296811630387191563U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 9423064323799920219U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 242153923313096551U) ^ aOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 12117679073775630197U), 57U);
            //
            aIngress = RotL64(aOrbiterA, 37U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aCross, 51U) + aOrbiterI) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 11U)) + aOrbiterB);
            aWandererD = aWandererD + ((((RotL64(aScatter, 13U) + RotL64(aOrbiterI, 57U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 26U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 27U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 34U) + aOrbiterA) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererK, 52U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordD);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 13928U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneD[((aIndex + 13186U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 12295U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 8740U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 60U) + RotL64(aPrevious, 39U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = (aWandererD + RotL64(aPrevious, 41U)) + 2672739400294801233U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 47U)) + 8475624545015101850U) + aNonceWordP;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 60U)) + RotL64(aCarry, 21U)) + 1252755112289831257U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 7938039507649183387U;
            aOrbiterE = ((((aWandererF + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 8167413146948861022U) + aOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aWandererG + RotL64(aScatter, 21U)) + 17712313989694374353U) + aOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 35U)) + 7637042279892596975U) + aNonceWordC;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 15770412950033467341U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 3951812021898608685U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6623127125223204737U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8656983621098246507U) + aOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 17943342344730687317U;
            aOrbiterJ = RotL64((aOrbiterJ * 16495519451034883813U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 3087677463651608668U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16493240011924342788U;
            aOrbiterI = RotL64((aOrbiterI * 16898479041530771871U), 41U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 7750923317452683057U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 2185924841611106546U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 708072658250726381U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 14676868738946722416U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6849098251696302393U;
            aOrbiterE = RotL64((aOrbiterE * 2599806275837778069U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 17817755047153606419U) + aNonceWordA;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9900465270314068757U;
            aOrbiterB = RotL64((aOrbiterB * 9267925873983176685U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11380000891112113701U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15930503831156546113U;
            aOrbiterG = RotL64((aOrbiterG * 14450535035065393845U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterG, 29U);
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterB, 60U)) + aOrbiterG) + aWandererUpdateSaltB[((aIndex + 26U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aPrevious, 19U) + RotL64(aOrbiterI, 5U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordK) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterA, 19U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterJ, 13U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 28U) + aOrbiterB) + RotL64(aOrbiterC, 29U)) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aIngress, 39U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterE, 35U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 42U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererK, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17300U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22553U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16397U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 19571U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 23U)) ^ (RotL64(aCross, 4U) ^ RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterB = ((aWandererK + RotL64(aScatter, 21U)) + RotL64(aCarry, 39U)) + 12692813903177772178U;
            aOrbiterF = (((aWandererI + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 7112496446691277899U) + aNonceWordM;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 48U)) + 2112247138290568813U) + aOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aWandererH + RotL64(aIngress, 57U)) + 3699421080882855947U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 27U)) + 13761832028354380922U) + aNonceWordA;
            aOrbiterG = ((((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 3U)) + 9243822514887600214U) + aOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 5U)) + 6863833516853046129U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8863897995943098018U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 13346785686701467520U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18074843497158380703U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 15309543066305531619U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 17515530938817919111U) ^ aOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16625193986319048245U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 760493237816424254U) + aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 7282586354117620860U;
            aOrbiterB = RotL64((aOrbiterB * 2327153408185290635U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 4129706068526969105U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 7020175432730888755U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 10095158356907592239U), 29U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 9102258982216515596U) + aNonceWordD;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 10822031305361453690U;
            aOrbiterI = RotL64((aOrbiterI * 2036205056490578491U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12571477440964330246U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 8436347026653095199U;
            aOrbiterG = RotL64((aOrbiterG * 17930734781213681573U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 14214789872073941940U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12915911919403385001U;
            aOrbiterC = RotL64((aOrbiterC * 13161681603528031511U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterF, 57U)) + aNonceWordL) + aWandererUpdateSaltC[((aIndex + 23U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterI, 30U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterI, 19U)) + aOrbiterB) + RotL64(aCarry, 21U)) + aNonceWordJ);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterB, 43U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 53U) + aOrbiterI) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 20U) + aOrbiterE) + RotL64(aOrbiterC, 37U)) + aNonceWordN);
            aWandererB = aWandererB + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 24973U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((aIndex + 31806U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29381U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 28710U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 57U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordM;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterF = (aWandererA + RotL64(aIngress, 35U)) + 1866656689936219099U;
            aOrbiterD = ((((aWandererB + RotL64(aScatter, 51U)) + RotL64(aCarry, 53U)) + 2312314528139448289U) + aOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererD + RotL64(aCross, 28U)) + RotL64(aCarry, 5U)) + 3554037526469185237U;
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 19U)) + 405707755060974111U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 43U)) + 1862976326004007697U;
            aOrbiterH = (aWandererC + RotL64(aScatter, 11U)) + 12992483065443288263U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 3U)) + 3793854946371595197U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 4244007978867369382U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 10280867500312580308U;
            aOrbiterE = RotL64((aOrbiterE * 13729899124177931289U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 472563452959164242U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 12041770406895816553U;
            aOrbiterH = RotL64((aOrbiterH * 17811798500132002631U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterF) + 6118634015704900486U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 13637107920449233307U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17712028184714868053U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 16673735670669318830U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8602681273646630496U;
            aOrbiterI = RotL64((aOrbiterI * 6995213887710749241U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7683264695930369476U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 9146674871199188218U;
            aOrbiterF = RotL64((aOrbiterF * 7403427067419261981U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3012935612827493084U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1259789268731661945U;
            aOrbiterC = RotL64((aOrbiterC * 2372843620327050137U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5623690455471160780U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 18355567776031865462U) ^ aOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9553862670107886679U), 29U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 11U);
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterF, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((((RotL64(aCross, 57U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 39U)) + aWandererUpdateSaltD[((aIndex + 25U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            aWandererA = aWandererA + ((RotL64(aScatter, 43U) + RotL64(aOrbiterG, 37U)) + aOrbiterH);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 26U) + RotL64(aOrbiterF, 60U)) + aOrbiterE) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterF);
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aNonceWordD) + aWandererUpdateSaltA[((aIndex + 17U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterC, 51U)) + aOrbiterI) + RotL64(aCarry, 11U)) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordP);
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

void TwistExpander_Softball_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xBC7D0DD9A37667A1ULL + 0xD76152CDBDCB1F66ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8EBEF95828A09AF3ULL + 0x9A053786055ABF5AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB9036FA6CDE0C4FDULL + 0xC75894A97CFECB37ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA365177D2AAB2425ULL + 0xFCEFD42EBE9902A4ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA6BEAC29529E159FULL + 0x81532CD39B5464E9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x8956DD2817FE56FBULL + 0xBC43A2EE24D1BB06ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xEE9FEC58AF3406A7ULL + 0xD0AD0A515A8314D3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD0C5AAB76AB2D4B7ULL + 0xB7E9E00915680167ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB1C9CF71086E3757ULL + 0xFB2BE68448A57E34ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9E68918638FF0DD9ULL + 0xD5DCE1F4704FB4DBULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x862E29E91B1C4A31ULL + 0xECE9A9F01B050B98ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD20EE6849ACBB1AFULL + 0xD1BE3D718C2A8AB5ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xECA7505D3598B4C5ULL + 0xB7731DAD4B91E85CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x98D0DC8CF42E8291ULL + 0xADB6DF98C3985173ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xCA9A2C38ECBE82E1ULL + 0xB62317816FDE0041ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xFE4F75A085DE8D1DULL + 0x805675050F846B31ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 441U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 360U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 2688U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 4119U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 28U) ^ RotL64(aCarry, 57U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = (aWandererA + RotL64(aScatter, 20U)) + 8866844335448071821U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 37U)) + 15159698739856430085U) + aNonceWordC;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 51U)) + 9582805772989594633U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 23U)) + RotL64(aCarry, 39U)) + 1438538239931588373U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 51U)) + 10862044156620436139U) + aOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aIngress, 53U)) + 13682173320058164615U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aScatter, 27U)) + 8351013291045977592U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 35U)) + 15777857431516633916U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 41U)) + 16178966745333885377U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 58U)) + RotL64(aCarry, 27U)) + 9031889187993001617U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 43U)) + 6308472367425865347U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 642109145903321046U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 9186268569255318035U) ^ aOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 10714674348507516749U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6091345356803675860U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13218507921880873749U;
            aOrbiterF = RotL64((aOrbiterF * 15415157927185637717U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 4266652275234474616U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 4391422098164506195U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17634679403195085867U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5160682323243635577U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10351728852161347404U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11105410036471745951U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 3950932176454814023U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9536466386833427441U;
            aOrbiterH = RotL64((aOrbiterH * 18064984243491293435U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9927425919978776529U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 6819384090527481081U) ^ aNonceWordE;
            aOrbiterD = RotL64((aOrbiterD * 18032965969184368561U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 1646274931424218507U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 16166524473976135097U;
            aOrbiterE = RotL64((aOrbiterE * 11672192658072663849U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11252501968059485262U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16847854447987609067U;
            aOrbiterB = RotL64((aOrbiterB * 6326299154627028295U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 16723218285355036446U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13870211254243048975U;
            aOrbiterK = RotL64((aOrbiterK * 10203222183774624097U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 11401147367366049493U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 4266628469244269926U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2409934496621365221U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11578385782347296942U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8866844335448071821U;
            aOrbiterG = RotL64((aOrbiterG * 6456956795450036515U), 5U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 28U);
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 41U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 47U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 42U) + aOrbiterA) + RotL64(aOrbiterJ, 44U));
            aWandererF = aWandererF + (((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 23U)) + aOrbiterD) + RotL64(aCarry, 41U)) + aNonceWordF) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterG, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterB, 51U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterI, 37U)) + aOrbiterE) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterD);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterE, 12U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + RotL64(aCarry, 37U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 10U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererH);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 12092U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneD[((aIndex + 16265U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13874U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 12535U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 53U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 24U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 22U)) + 7270044678408187242U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aPrevious, 57U)) + 10192278965379756766U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 51U)) + 17568666746676060748U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 43U)) + 14312927531124963037U) + aNonceWordH;
            aOrbiterF = (aWandererB + RotL64(aIngress, 41U)) + 9825825726152087706U;
            aOrbiterD = (aWandererD + RotL64(aScatter, 53U)) + 9696778570255265896U;
            aOrbiterE = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 17657841352013417228U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 47U)) + 16207815085909628439U;
            aOrbiterC = (aWandererH + RotL64(aCross, 12U)) + 1752979206374514227U;
            aOrbiterB = ((((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 10456310689643905854U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 43U)) + 16127830548663742550U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 2940917376003930842U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7353596864777649953U;
            aOrbiterA = RotL64((aOrbiterA * 7499468723171042005U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12725092740446150705U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 5791296650856037010U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 760379251950502133U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 1200130368046206150U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterD) ^ 16689604428598558547U) ^ aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterF = RotL64((aOrbiterF * 13815324235939996623U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 14359561591103730856U) + aNonceWordM;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3975025843599045263U;
            aOrbiterE = RotL64((aOrbiterE * 5025047888533298617U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14017901732955607601U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 10431526786489555196U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10181915874476132407U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 7320527073559849223U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 15333411223710709907U;
            aOrbiterJ = RotL64((aOrbiterJ * 3488684905528068775U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 14302474063321663801U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2104154521019935187U;
            aOrbiterH = RotL64((aOrbiterH * 12944382959742278055U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5167600586916325228U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4566823109447208716U;
            aOrbiterD = RotL64((aOrbiterD * 9997799807454267443U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12475580453805083495U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15461491763911887974U;
            aOrbiterI = RotL64((aOrbiterI * 13548865386159287481U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 11000532703581114393U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 7815822789941347770U;
            aOrbiterB = RotL64((aOrbiterB * 1476638214324946775U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2166336159928211562U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 7270044678408187242U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10648564933168714815U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 29U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterK, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 44U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterF, 51U)) + aNonceWordI);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterH, 37U)) + aWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterA, 19U)) + aNonceWordF);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 54U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC) + RotL64(aCarry, 11U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 29U)) + aOrbiterG);
            aWandererC = aWandererC + ((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 23U)) + aOrbiterK);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterD, 57U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterE, 4U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterH, 21U)) + aWandererUpdateSaltF[((aIndex + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 26U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 37U));
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 24568U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneA[((aIndex + 17785U)) & S_BLOCK1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21778U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 17136U)) & S_BLOCK1], 24U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 5U)) + (RotL64(aCross, 56U) ^ RotL64(aIngress, 21U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = (aWandererB + RotL64(aIngress, 43U)) + 6381335981879993247U;
            aOrbiterB = (aWandererI + RotL64(aCross, 27U)) + 15595429101600023172U;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 11U)) + 5449234297249826461U;
            aOrbiterG = (aWandererK + RotL64(aScatter, 47U)) + 11213734849329731168U;
            aOrbiterK = (aWandererF + RotL64(aCross, 13U)) + 16438473952464514248U;
            aOrbiterD = ((aWandererE + RotL64(aScatter, 38U)) + 7357872882115186976U) + aOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 394402075160738643U) + aOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 11112941985410283532U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 3U)) + 14955125011182736212U) + aNonceWordA;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 56U)) + 14770727009821304070U) + aNonceWordO;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 41U)) + RotL64(aCarry, 29U)) + 11286366598129204910U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7358400908565425780U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 15635109923749114761U;
            aOrbiterF = RotL64((aOrbiterF * 12415152149408700329U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 13826842523738623579U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 1072811298828325231U;
            aOrbiterD = RotL64((aOrbiterD * 9662800288646215083U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4017334196009350776U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 8812213572751410831U;
            aOrbiterB = RotL64((aOrbiterB * 12744171921566782795U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6723457786170634403U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 9785583533999417673U) ^ aOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7776915427605471097U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10265132640322153964U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8435670887514808087U;
            aOrbiterH = RotL64((aOrbiterH * 2706263045620662131U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4303823386961718326U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4214384238167491037U;
            aOrbiterI = RotL64((aOrbiterI * 8490707334221154005U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 8740835037840799136U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 5988815405391206280U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17838555472135715929U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 15539461383052981747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 3743772525784217714U;
            aOrbiterG = RotL64((aOrbiterG * 6352086797545969187U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16283379107488103386U) + aOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2677085736169305444U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 5034373635279045467U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 16961352880910247821U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7475807604144212417U;
            aOrbiterC = RotL64((aOrbiterC * 5016987646810330727U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10187131329357526073U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6381335981879993247U;
            aOrbiterJ = RotL64((aOrbiterJ * 15277168748093112841U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterG, 22U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 44U)) + aOrbiterA);
            aWandererA = aWandererA + ((RotL64(aCross, 13U) + RotL64(aOrbiterC, 35U)) + aOrbiterI);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 27U)) + aOrbiterE) + aNonceWordD);
            aWandererK = aWandererK + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterB, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 10U) + aOrbiterB) + RotL64(aOrbiterK, 11U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 30U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterH) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterD) + RotL64(aOrbiterI, 53U)) + aNonceWordG);
            aWandererB = aWandererB + ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 37U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 52U) + aOrbiterC) + RotL64(aOrbiterE, 51U)) + aWandererUpdateSaltA[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 56U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 29U));
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 40U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 26642U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 26440U)) & S_BLOCK1], 26U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 31972U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 26468U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 21U)) ^ (RotL64(aPrevious, 37U) + RotL64(aCarry, 4U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterI = (aWandererF + RotL64(aScatter, 3U)) + 5041131702736607991U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 9295010428212681446U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 26U)) + RotL64(aCarry, 35U)) + 6235875895358766017U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 29U)) + 2622227802531866918U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 37U)) + 3888894734834524972U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 21U)) + 241682012014701753U;
            aOrbiterK = (aWandererA + RotL64(aIngress, 5U)) + 15758000422451568079U;
            aOrbiterJ = (aWandererE + RotL64(aCross, 60U)) + 2061944548396976912U;
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 57U)) + 8177144990755754531U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 554978075608818497U;
            aOrbiterB = ((aWandererD + RotL64(aCross, 19U)) + 250408260560714933U) + aNonceWordF;
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 8700027645880997552U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10026130047465480902U;
            aOrbiterG = RotL64((aOrbiterG * 12417270861933696623U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 9785843014096326696U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 9998582683258411251U;
            aOrbiterC = RotL64((aOrbiterC * 7197956237569462269U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 13817734599383455151U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6647207154174092691U;
            aOrbiterE = RotL64((aOrbiterE * 1578528131687283531U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 4957715980509035719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4994885315786213197U;
            aOrbiterK = RotL64((aOrbiterK * 5676683798126497011U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 5072908311783966503U) + aOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 5535039946192891515U;
            aOrbiterJ = RotL64((aOrbiterJ * 2989412783482309753U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6594577050344146271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8750154123258714856U;
            aOrbiterD = RotL64((aOrbiterD * 6942158167127532003U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3514769314840874873U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterK) ^ 8626045200273524281U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 4315441782689789689U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 8524870284841706517U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1841819423572964209U;
            aOrbiterB = RotL64((aOrbiterB * 9802481758007234681U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12668382464510772517U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 6330331402801670515U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 9096920618612750935U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 10346986196055766087U) + aOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10932918162471200996U;
            aOrbiterA = RotL64((aOrbiterA * 6863632877625141567U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6264557195446069146U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5041131702736607991U;
            aOrbiterH = RotL64((aOrbiterH * 4978591546106895045U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 51U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterG, 13U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterI, 24U)) + aOrbiterK) + aWandererUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterE, 27U)) + aOrbiterC) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 57U) + aOrbiterD) + RotL64(aOrbiterC, 11U));
            aWandererG = aWandererG + (((RotL64(aIngress, 37U) + aOrbiterB) + RotL64(aOrbiterH, 48U)) + aNonceWordC);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 5U));
            aWandererC = aWandererC + (((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 19U)) + aOrbiterF) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 50U) + aOrbiterH) + RotL64(aOrbiterG, 21U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 34U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ aNonceWordK;
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

void TwistExpander_Softball_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF9DE9560CFC439B9ULL + 0xAEB994B54FB79694ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8F3328B869439983ULL + 0xB745D4F8C6362E8BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xA71BA8795FE2D909ULL + 0xB1640241AA0E3A11ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF8EF452D8AA182A9ULL + 0x83C20108AE12F0C7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD7FF4C08229BCA7DULL + 0xF1E52589B935C439ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBD507AD870592905ULL + 0xDD362AF9298FA30DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xB814E90BF3755C9BULL + 0x84C4863767BF3497ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFACFFE7ED0AA2BC1ULL + 0xEC2D0EBF910A2A9BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xEAA068F92A78FE99ULL + 0xC73AF0D4967FE00EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xE81231B5D2DD777DULL + 0xDD0DEDFFBA36D521ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x85B3B071BF3E7C19ULL + 0xBF8F9FE535F46DBEULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xFE22D40B210F5DA3ULL + 0xA3D53A58A739A3A1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xD41A4B7C307116E3ULL + 0x878E34BC4B255D57ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA48FFA26A0E6E5BFULL + 0xDD3B108272E8450FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB6A8E177F9217F8FULL + 0xC99DFD60EBC4DF59ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEC205FEDA8AA8F9BULL + 0xA9FBEE8CBC832595ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 4464U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((aIndex + 1660U)) & S_BLOCK1], 34U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 3448U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneA[((aIndex + 3717U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 34U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererJ + RotL64(aScatter, 57U)) + 6467297102954816305U;
            aOrbiterF = ((((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 7921154109831114952U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 24U)) + RotL64(aCarry, 57U)) + 5701131763215638919U;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 11U)) + 10022999076719002684U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 3U)) + 4367135243038982316U) + aNonceWordF;
            aOrbiterC = (aWandererA + RotL64(aScatter, 29U)) + 14445846824810383592U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 19U)) + 7683697954545773253U) + aOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 17517006750428030899U;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 40U)) + 2052484792684025476U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6279463052085808926U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 679280153651813684U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3047031560593583881U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2939516520188460569U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 1960616434964712325U;
            aOrbiterC = RotL64((aOrbiterC * 15145998415466343039U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 12273819390719947361U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5685033154709449397U;
            aOrbiterA = RotL64((aOrbiterA * 9845666295874714959U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9314494172199500653U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15757631834636427621U;
            aOrbiterJ = RotL64((aOrbiterJ * 15483543888965744529U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 10878078046389399574U) + aOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3583495913766365232U;
            aOrbiterH = RotL64((aOrbiterH * 2913540984990155225U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7385544065754622301U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 16839599460207922881U;
            aOrbiterI = RotL64((aOrbiterI * 240651605910592561U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13038163804940349251U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterC) ^ 2587538594933924000U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 3091149760401278671U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 13109518583364738004U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2447689055742474261U;
            aOrbiterF = RotL64((aOrbiterF * 12100180201235703193U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5752044906692668618U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 6637725371036522120U;
            aOrbiterK = RotL64((aOrbiterK * 6021986525167161115U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterF, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 27U) + aOrbiterB) + RotL64(aOrbiterC, 51U)) + aNonceWordN);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 19U)) + aWandererUpdateSaltB[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterA, 23U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aCross, 57U) + RotL64(aOrbiterF, 42U)) + aOrbiterK) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 47U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 13U)) + aOrbiterD) + RotL64(aCarry, 37U)) + aNonceWordO);
            aWandererH = aWandererH ^ (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterA, 57U)) + aWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 20U) + aOrbiterC) + RotL64(aOrbiterF, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterH, 36U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + RotL64(aWandererA, 23U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5464U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9764U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 9532U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6375U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 23U)) + (RotL64(aCarry, 39U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aDomainWordScatter));
            //
            aOrbiterA = ((aWandererK + RotL64(aCross, 34U)) + RotL64(aCarry, 3U)) + 6361545377408870615U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 13U)) + 2967245486744774933U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aWandererC + RotL64(aIngress, 57U)) + 3836634268482850139U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 3U)) + 7691642115360086297U;
            aOrbiterF = (aWandererG + RotL64(aCross, 21U)) + 16479280384178279281U;
            aOrbiterB = (aWandererH + RotL64(aIngress, 46U)) + 2901468732552539249U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 51U)) + RotL64(aCarry, 11U)) + 2600353867755647475U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 41U)) + RotL64(aCarry, 47U)) + 5666596904781510956U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 29U)) + 16108791609267427553U) + aOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8389926875737312112U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 1689501721163024426U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 6517194895779049139U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11721701506949917719U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3963842745030140473U;
            aOrbiterF = RotL64((aOrbiterF * 6692473494944919373U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8510538243472109368U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 18281865214102080387U;
            aOrbiterE = RotL64((aOrbiterE * 1351546966368884609U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2259725140963665123U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterC) ^ 11652011949557979650U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 11260100762113295037U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1116085424226174473U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4725260319270802912U) ^ aOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 4697109059565450269U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7348945429843437036U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 1249234309180653260U) ^ aOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3136745255820405881U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12463505532573389603U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2304125977906510386U;
            aOrbiterK = RotL64((aOrbiterK * 9960816714791454421U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2178037443783425551U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11712110130079307683U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9797864956200779505U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 10703510612147312252U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 18155460326242413483U;
            aOrbiterC = RotL64((aOrbiterC * 6903953708987478723U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 23U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterC, 50U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((((RotL64(aPrevious, 3U) + aOrbiterC) + RotL64(aOrbiterD, 35U)) + aNonceWordI) + aWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 28U) + aOrbiterI) + RotL64(aOrbiterE, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 10U)) + aOrbiterA);
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterF, 39U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterI, 51U)) + aOrbiterC) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 56U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 43U));
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordI);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 11876U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15538U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13752U)) & S_BLOCK1], 42U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13843U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 38U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 53U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterJ = ((aWandererK + RotL64(aPrevious, 13U)) + 5906639480605353429U) + aOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterA = (aWandererB + RotL64(aCross, 43U)) + 5293518570213287605U;
            aOrbiterE = (aWandererI + RotL64(aIngress, 6U)) + 15383185501428521377U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 51U)) + 15364072512743978902U) + aOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aWandererG + RotL64(aCross, 39U)) + 4525473357144014271U;
            aOrbiterI = (aWandererD + RotL64(aPrevious, 29U)) + 10400911938125603074U;
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 41U)) + 16417506293824627550U) + aNonceWordK;
            aOrbiterC = (((aWandererF + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 2419329331753341815U) + aNonceWordM;
            aOrbiterF = (((aWandererE + RotL64(aPrevious, 56U)) + RotL64(aCarry, 11U)) + 14929222427923332069U) + aNonceWordN;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 16771573504983922586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 1863466450051787622U;
            aOrbiterE = RotL64((aOrbiterE * 2585626547126027053U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 12895350137096692415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 3700979086526298327U;
            aOrbiterJ = RotL64((aOrbiterJ * 10279730254867618193U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 1977099106211282426U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6144698304096915742U;
            aOrbiterH = RotL64((aOrbiterH * 5039822990560519609U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3858895556659724975U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1283646340363435327U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11622421841377018069U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 6240532051889108891U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 757364889381634634U;
            aOrbiterK = RotL64((aOrbiterK * 943852137901972945U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 5272945693977418174U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 6850528198786172283U;
            aOrbiterI = RotL64((aOrbiterI * 1966383079897679953U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 14431587733859573714U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 16124590257870999553U;
            aOrbiterG = RotL64((aOrbiterG * 7755796211433191143U), 23U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterJ) + 14912695018110241411U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 11098623474413346520U;
            aOrbiterC = RotL64((aOrbiterC * 15167688959990872051U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 3484847683376368686U) + aNonceWordD;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 2295388097292719800U;
            aOrbiterF = RotL64((aOrbiterF * 1240808318176106909U), 19U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 22U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + aOrbiterF) + RotL64(aOrbiterJ, 3U));
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterA, 35U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterJ, 24U)) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 37U) + RotL64(aOrbiterC, 51U)) + aOrbiterH);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterE, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 53U) + aOrbiterE) + RotL64(aOrbiterA, 30U));
            aWandererE = aWandererE + (((((RotL64(aScatter, 18U) + aOrbiterI) + RotL64(aOrbiterA, 13U)) + RotL64(aCarry, 43U)) + aNonceWordJ) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterH, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 6U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 30U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 16899U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21161U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16424U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 17528U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aCross, 57U) + RotL64(aIngress, 11U)) + (RotL64(aPrevious, 42U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = ((aWandererG + RotL64(aIngress, 3U)) + 16160838483846078448U) + aOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aWandererI + RotL64(aPrevious, 35U)) + 15404960896190227946U;
            aOrbiterF = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 16904160594024977199U;
            aOrbiterG = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 11U)) + 17790460246821031802U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 46U)) + RotL64(aCarry, 3U)) + 16395168254086971959U;
            aOrbiterC = (aWandererC + RotL64(aIngress, 27U)) + 7484373204039901786U;
            aOrbiterB = (aWandererF + RotL64(aCross, 41U)) + 18026814691322913510U;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 57U)) + 15244817793136966450U) + aOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 14U)) + 5795491730356335666U) + aNonceWordP;
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 3163873518027801504U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2690791759507349172U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16677948635136515083U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17898067251167087906U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8028010015006604239U;
            aOrbiterA = RotL64((aOrbiterA * 5601629670521300241U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 7304739457289910555U) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 6476837815096530043U;
            aOrbiterB = RotL64((aOrbiterB * 16380545138701113267U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14242499233467960602U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 17305645693017634630U;
            aOrbiterH = RotL64((aOrbiterH * 14442976693206929569U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9772864059444171908U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 7897200728282156408U) ^ aOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 816306719390807411U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4890999319172950996U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 8165132649356094963U) ^ aOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17297706071263690189U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9342923520083533265U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7213639583505088067U;
            aOrbiterK = RotL64((aOrbiterK * 1349251979649428909U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 4079475132684197272U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 3350998022472827283U;
            aOrbiterJ = RotL64((aOrbiterJ * 948841791460066265U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 2479140576609216238U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 7703147534931674972U;
            aOrbiterD = RotL64((aOrbiterD * 11419116495223970801U), 3U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 3U);
            aIngress = aIngress + (RotL64(aOrbiterC, 10U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterF, 56U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterF) + aNonceWordN) + aWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 47U) + aOrbiterG) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB + ((RotL64(aScatter, 18U) + RotL64(aOrbiterF, 27U)) + aOrbiterD);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + aWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterG) + RotL64(aOrbiterA, 5U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 36U) + aOrbiterC) + RotL64(aOrbiterB, 36U)) + RotL64(aCarry, 3U)) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (RotL64(aWandererC, 6U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23429U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneA[((aIndex + 21985U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24731U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 26092U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseA((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 5U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 22U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterH = (aWandererK + RotL64(aScatter, 35U)) + 11998579547770778580U;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 47U)) + 8409465187298704610U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 58U)) + 3470222286110333500U) + aNonceWordN;
            aOrbiterI = (aWandererD + RotL64(aIngress, 53U)) + 5704486785203069994U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 29U)) + 10334944660253279633U) + aNonceWordB;
            aOrbiterC = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 7626852700722567477U) + aOrbiterAssignSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aIngress, 3U)) + 14631310754943209743U;
            aOrbiterA = (((aWandererE + RotL64(aCross, 22U)) + RotL64(aCarry, 21U)) + 807160297237854120U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 39U)) + 5624154783624196107U) + aNonceWordE;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4971444394698940423U) + aOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 6340057638461027062U;
            aOrbiterE = RotL64((aOrbiterE * 12027586111086798629U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9003019862787819481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12766104026871797746U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterD) ^ 4062118445824915939U) ^ aOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterA = RotL64((aOrbiterA * 13130770039048080701U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 5258212525426469978U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 9956946981015983939U;
            aOrbiterF = RotL64((aOrbiterF * 8106382657040497669U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10837606223056473999U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 13292864885504191134U;
            aOrbiterH = RotL64((aOrbiterH * 4445739587553669471U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 166087925900318658U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterE) ^ 6786842221885441388U) ^ aOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 4411147600413147773U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 16888086378070246404U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 5240855484445974002U;
            aOrbiterD = RotL64((aOrbiterD * 402652898573422271U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6874866669211571608U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 732890824978127460U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 3776365957702257453U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5541380495707308058U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17947326584411475765U;
            aOrbiterG = RotL64((aOrbiterG * 10920952349981652899U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 24U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 43U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 43U)) + aOrbiterH) + aNonceWordA);
            aWandererF = aWandererF + ((((RotL64(aScatter, 5U) + RotL64(aOrbiterE, 60U)) + aOrbiterI) + aNonceWordH) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterF) + RotL64(aOrbiterC, 27U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 37U)) + aOrbiterE) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aScatter, 51U) + aOrbiterC) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 30U) + aOrbiterD) + RotL64(aOrbiterK, 47U)) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterF, 6U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 54U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 28329U)) & S_BLOCK1], 52U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30035U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28682U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28338U)) & S_BLOCK1], 30U));
            aCross = TwistMix64::DiffuseC((aCross ^ aDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCarry, 39U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 52U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aDomainWordScatter));
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 47U)) + 966899917801652720U) + aNonceWordL;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 39U)) + 10996327672320748649U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 4188171566846621107U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 52U)) + 5886209243097387959U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = (aWandererI + RotL64(aScatter, 43U)) + 14940428957136728111U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 3U)) + 179187285531914832U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 35U)) + 6685351948936817752U) + aOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 30U)) + RotL64(aCarry, 39U)) + 1894506461704029700U;
            aOrbiterC = (((aWandererE + RotL64(aIngress, 57U)) + RotL64(aCarry, 3U)) + 4182760368636977082U) + aNonceWordJ;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 12523318028514940790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 5059306166973366892U;
            aOrbiterG = RotL64((aOrbiterG * 2857409765717296483U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5890872367917643851U) + aNonceWordM;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17747338389865221534U;
            aOrbiterD = RotL64((aOrbiterD * 5306740664798049267U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 13906227834259884100U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7152105382899756368U;
            aOrbiterA = RotL64((aOrbiterA * 6772157117358310485U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17868101884759619240U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 11758843266314148347U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5919135169337501485U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13950566197090324859U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17278105609930477854U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11431842718945107359U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9556785965646738355U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 841298436857932987U;
            aOrbiterE = RotL64((aOrbiterE * 15077843186688841797U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 1951515285492133830U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 15775839819330588437U;
            aOrbiterB = RotL64((aOrbiterB * 7902654031401620995U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 5585458468816495436U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 17258586689032223623U) ^ aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1652050227399194271U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 5254132659445988836U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 15440741734777060925U;
            aOrbiterK = RotL64((aOrbiterK * 17445581079035134067U), 47U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 48U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + (RotL64(aOrbiterI, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 39U));
            aIngress = aIngress + RotL64(aOrbiterK, 26U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterE, 6U));
            aWandererE = aWandererE + ((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterH, 19U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterA, 43U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 18U) + RotL64(aOrbiterD, 23U)) + aOrbiterH) + RotL64(aCarry, 39U)) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 23U) + aOrbiterC) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK + (((((RotL64(aCross, 11U) + RotL64(aOrbiterI, 39U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 7U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterK, 13U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 29U) + aOrbiterB) + RotL64(aOrbiterG, 52U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterB, 57U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + RotL64(aWandererC, 38U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = aCarry ^ aNonceWordD;
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

void TwistExpander_Softball_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0x9EB8A366B048B29FULL + 0xCF7B262144FA283FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDAEBCAEF775A58E5ULL + 0xE7C258DC425ED9C7ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x8B301F6E23FBED09ULL + 0xB5E042D7DEA48209ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xAB4786752988CB13ULL + 0x8F23B03B82B328D6ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xC3D6BF0F1DE28AFDULL + 0xB5D120C930188A0FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFA17F3B1853C342FULL + 0x9A14794CE7BB1317ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAFD11AE752E18139ULL + 0xB3D0732C66BC98E5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE3FD46AE54B1E3DBULL + 0xECD6BC20A90D51FEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF9CC7AF9A03920ABULL + 0x934E7D64469B2F03ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE873D86B814416D1ULL + 0xF36E41F401B248C4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xB26ACA2A3BA4FFDFULL + 0x9CB7018D5DE12F05ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xD3677E8388F4DC0FULL + 0xD5D34E41B3744A6DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE8051CEA62E76A59ULL + 0xBB36D3318DBECBEBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF743A1C54D518AD1ULL + 0xFA495AB28B57A6D7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xB75BEEE6C5135F2FULL + 0x980C3E015F370611ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFE552DB76807BB55ULL + 0xC5A2AD9FA22EFB02ULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 4979U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4497U)) & W_KEY1], 42U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 1693U)) & W_KEY1], 41U) ^ RotL64(mSource[((aIndex + 2289U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aCross, 14U) + RotL64(aIngress, 43U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (((aWandererI + RotL64(aIngress, 39U)) + RotL64(aCarry, 13U)) + 4068921616130916949U) + aNonceWordP;
            aOrbiterC = (((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 12077715273915151726U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aPrevious, 47U)) + 16047546802670596833U;
            aOrbiterD = (aWandererA + RotL64(aCross, 27U)) + 9690277462716999763U;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 19U)) + 14484814700447992628U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 10U)) + RotL64(aCarry, 43U)) + 17089267243053958210U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aScatter, 3U)) + 9138746214446211147U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 10181001536979097045U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6657458969093373191U;
            aOrbiterE = RotL64((aOrbiterE * 4311019792293202747U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 7515983477876590988U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 3039935555863947600U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12511160550780270119U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 16209389224740851136U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 725253312098083182U;
            aOrbiterA = RotL64((aOrbiterA * 17535989492095522597U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 13307041115748941383U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 7159572004825238263U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4855009895002398449U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12027236743251643820U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8717826175991286553U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1175614802543098451U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4769096034227659937U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 11201226563992939616U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 15595355978388159931U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 17295978531215563256U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 11850923890626719833U;
            aOrbiterC = RotL64((aOrbiterC * 3854851059897397075U), 13U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 27U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterD) + RotL64(aOrbiterK, 51U));
            aWandererI = aWandererI + (((RotL64(aScatter, 57U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aPhaseAWandererUpdateSaltE[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 26U) + RotL64(aOrbiterE, 19U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterK, 43U)) + aOrbiterC) + aNonceWordM);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 60U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ) + aPhaseAWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 34U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6697U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10765U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 9750U)) & W_KEY1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 10139U)) & W_KEY1], 54U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 10U)) ^ (RotL64(aIngress, 57U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterC = ((aWandererB + RotL64(aIngress, 35U)) + 785861751704720606U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aCross, 53U)) + RotL64(aCarry, 35U)) + 15968088718435606299U) + aNonceWordG;
            aOrbiterB = ((aWandererI + RotL64(aScatter, 27U)) + 1393976526590347151U) + aPhaseAOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 13U)) + 17240750947292745884U) + aNonceWordI;
            aOrbiterE = (aWandererG + RotL64(aCross, 46U)) + 4921576136163183137U;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 21U)) + RotL64(aCarry, 53U)) + 3334047873553153032U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 15086509978458408698U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 892391205397581998U) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 2965686403183767521U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 709160942482770225U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 14632215393655706170U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 15740589515342377322U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15677716942904794913U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 11131164813943086445U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 6988080581278900960U;
            aOrbiterK = RotL64((aOrbiterK * 6412189142344044255U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 16021254613117657178U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 6183615599897921154U;
            aOrbiterH = RotL64((aOrbiterH * 9976411093264211033U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 12533992547026652747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 3104325358982904219U;
            aOrbiterE = RotL64((aOrbiterE * 14977348108778147265U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3878525937957474644U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2120435259884368445U;
            aOrbiterI = RotL64((aOrbiterI * 15964718652193073177U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 14928658302694194856U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 9121310461310309348U;
            aOrbiterJ = RotL64((aOrbiterJ * 17304439784647477491U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 11U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 44U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aCross, 57U) + RotL64(aOrbiterK, 22U)) + aOrbiterE) + RotL64(aCarry, 11U)) + aNonceWordM);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + aNonceWordD);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterH, 29U)) + aOrbiterE) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterE) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterH, 41U)) + aNonceWordO);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + aPhaseAWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 4U) + aOrbiterJ) + RotL64(aOrbiterB, 13U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 16243U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11007U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 16080U)) & W_KEY1], 6U) ^ RotL64(aKeyRowReadB[((aIndex + 10991U)) & W_KEY1], 47U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 6U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterI = (aWandererA + RotL64(aIngress, 47U)) + 2168513956284366370U;
            aOrbiterE = (aWandererK + RotL64(aCross, 19U)) + 10290361969974613111U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 15673836275828498050U;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 5U)) + 16600540024145812236U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 5U)) + 9428052101528111892U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((((aWandererH + RotL64(aCross, 56U)) + RotL64(aCarry, 35U)) + 12763657928312763377U) + aPhaseAOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 13U)) + 10751286982008662485U) + aNonceWordO;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 1708230173038057979U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 4011389705422783816U;
            aOrbiterB = RotL64((aOrbiterB * 11692237130784795961U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11704428328093077714U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2055336619674699284U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6374289210096410907U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1870865272102705804U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 3574214263751923179U;
            aOrbiterI = RotL64((aOrbiterI * 13132083406834413563U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 984611970726966186U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 15207945449947643672U;
            aOrbiterD = RotL64((aOrbiterD * 9539470161576639981U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 4181398506373973169U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15222345431506025949U;
            aOrbiterK = RotL64((aOrbiterK * 6925143692628659467U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 15023513452326240962U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 14965669361708810699U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 587008860996713147U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7985755518735406360U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 225592097619240187U;
            aOrbiterH = RotL64((aOrbiterH * 2313509354133400439U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterB, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 3U)) + aNonceWordN);
            aWandererK = aWandererK + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 12U)) + aOrbiterK) + RotL64(aCarry, 51U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterB, 37U)) + aNonceWordD) + aPhaseAWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + RotL64(aCarry, 37U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 30U) + aOrbiterI) + RotL64(aOrbiterB, 57U));
            aWandererI = aWandererI + ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterE, 43U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterK) + RotL64(aOrbiterD, 51U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 46U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ aNonceWordM;
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 19986U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20159U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordH;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19595U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 17573U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 54U) ^ RotL64(aCross, 29U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 13U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterG = ((aWandererH + RotL64(aScatter, 37U)) + RotL64(aCarry, 23U)) + 13915875634607599122U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 43U)) + 1695770381382411673U;
            aOrbiterB = (((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 35U)) + 3709105579778295511U) + aNonceWordM;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 50U)) + 7673376335333251804U) + aPhaseAOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = (aWandererE + RotL64(aScatter, 13U)) + 8814147709738503518U;
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 3U)) + RotL64(aCarry, 47U)) + 13451412605350381172U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aIngress, 19U)) + 6447870234069609538U) + aNonceWordG;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 13419487997946496825U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5478309847615220345U;
            aOrbiterB = RotL64((aOrbiterB * 12953043149543448765U), 57U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterI) + 3635184969215610049U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 12527903812035294828U;
            aOrbiterE = RotL64((aOrbiterE * 12540800512035534967U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 1684685110885338814U) + aNonceWordL;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 12860354576326835090U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 12743745087733307255U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 9081823570147481835U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14369321778210049109U;
            aOrbiterI = RotL64((aOrbiterI * 17865953349448767035U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11518132079084873250U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 11893535026126957389U;
            aOrbiterG = RotL64((aOrbiterG * 15751374986135615095U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 7084079180579206226U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 2999676609847603277U;
            aOrbiterF = RotL64((aOrbiterF * 14602698397511266403U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17683445810614029153U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 11576460512964896969U;
            aOrbiterD = RotL64((aOrbiterD * 5243651036457051155U), 11U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 30U));
            aIngress = aIngress + RotL64(aOrbiterB, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterD, 43U));
            aWandererI = aWandererI + (((((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 53U)) + aNonceWordN) + aPhaseAWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 41U) + aOrbiterE) + RotL64(aOrbiterF, 36U)) + aPhaseAWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 48U) + aOrbiterB) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterI, 21U)) + aNonceWordP);
            aWandererD = aWandererD + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 11U)) + aOrbiterG);
            aWandererK = aWandererK ^ (((RotL64(aCross, 13U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererD, 12U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23405U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneA[((aIndex + 23065U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 23824U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27235U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 18U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterH = (aWandererB + RotL64(aScatter, 10U)) + 11698283336767769359U;
            aOrbiterG = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 13297826354831483872U) + aNonceWordH;
            aOrbiterB = ((((aWandererE + RotL64(aIngress, 3U)) + RotL64(aCarry, 19U)) + 15254999058287530795U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 41U)) + 17474166585085346567U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 35U)) + 15684783498452840289U) + aPhaseAOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 53U)) + 5061229733465216486U;
            aOrbiterA = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 15370981279168377944U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 17966672773619554092U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 14685092893994491068U;
            aOrbiterB = RotL64((aOrbiterB * 1627758964162892429U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12798804186209406389U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 2848444181474221574U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13730480364920876877U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 8551142075919636146U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 8833198159158950723U;
            aOrbiterD = RotL64((aOrbiterD * 7650289040764974737U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7351473160893666232U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14204899612487622222U;
            aOrbiterG = RotL64((aOrbiterG * 6317485031956448029U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 7008985178526543258U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 13576796403863120356U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 13745839827679114077U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 5769784656937900699U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14075925808204936705U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 5844894088757604713U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 17818667502858010896U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 16016922065572683130U;
            aOrbiterA = RotL64((aOrbiterA * 7525645833898085373U), 23U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterG, 21U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 35U)) + aOrbiterA);
            aWandererF = aWandererF + ((RotL64(aIngress, 12U) + aOrbiterD) + RotL64(aOrbiterG, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterH, 44U)) + aPhaseAWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterC) + RotL64(aCarry, 19U)) + aNonceWordA) + aPhaseAWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterF, 19U)) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterF, 11U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterB) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererF, 24U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = aCarry ^ (aNonceWordP ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordH;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 27634U)) & S_BLOCK1], 50U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30564U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseADomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31858U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((aIndex + 29169U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseADomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 54U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseADomainWordScatter));
            //
            aOrbiterF = (((aWandererD + RotL64(aScatter, 5U)) + RotL64(aCarry, 11U)) + 12311607308490066301U) + aPhaseAOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 54U)) + 13100864684740679846U) + aNonceWordI;
            aOrbiterA = (aWandererF + RotL64(aCross, 23U)) + 13697304189274329704U;
            aOrbiterJ = (aWandererH + RotL64(aPrevious, 29U)) + 9047976902871216732U;
            aOrbiterB = ((aWandererJ + RotL64(aCross, 35U)) + RotL64(aCarry, 53U)) + 2147897579538537888U;
            aOrbiterH = ((aWandererB + RotL64(aScatter, 43U)) + 2072444829390996142U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = (((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 2129307836981020908U) + aNonceWordN;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 10663145333751112064U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 15019844390503785459U) ^ aNonceWordL;
            aOrbiterA = RotL64((aOrbiterA * 7442321463110790449U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5460865577557928142U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 15806522559993224197U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8722932687972240099U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 6361113778657833389U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8306013884615042570U;
            aOrbiterH = RotL64((aOrbiterH * 8234258702656728667U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4038420580499706912U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11908091484457158973U;
            aOrbiterC = RotL64((aOrbiterC * 3964111175645156719U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 11133912466611921250U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2469227904206936928U;
            aOrbiterF = RotL64((aOrbiterF * 2704438771198001599U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13234017916788297295U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 9061117693840451988U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 3637440416741459419U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12013423690843812324U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 14371779015144617412U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3359568073302062667U), 21U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + RotL64(aOrbiterH, 23U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterJ, 47U));
            aWandererB = aWandererB + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererD = aWandererD + ((RotL64(aCross, 14U) + aOrbiterE) + RotL64(aOrbiterH, 35U));
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 47U) + aOrbiterF) + RotL64(aOrbiterE, 41U)) + aNonceWordC) + aPhaseAWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 60U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 48U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = aCarry ^ aNonceWordD;
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Softball_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE980A2EA12BD1F07ULL + 0xD34B0D476A39CAF7ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x83C21DC5CEB781F1ULL + 0xFFC5A4BF953CE277ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB3F92B5429F8A27DULL + 0x88262820E8088FFDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB4DC25C8DD752151ULL + 0xA9D3F0D59688EE42ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB1D2DC0726769AB1ULL + 0x97BE78ECE7279266ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE60D17202821526DULL + 0xE673B5923C680D1DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD4DF0A5A64374DB3ULL + 0xD16E9CEE41921F0AULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xEFA4332CC6E5BCDBULL + 0xC75862690828AD74ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xD0BC786EEFD5EA07ULL + 0xF5987A2AC698AEF5ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC5CAE6B72DB97D39ULL + 0x87134A0881C7DC04ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE8AB80E7584D7ACDULL + 0xAC45C9B290EA30BAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xAA9F36486D22FC21ULL + 0xE4118DB51627ACAAULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xDBA1DD251504C631ULL + 0xEDB28DE3CABCAF04ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x98DE1CC2FD69F639ULL + 0x9DECDDC487E8C28EULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xC259AEC3A2433153ULL + 0xFD7BD2BF264B8F9AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xF413359B0CEB8C0DULL + 0x95A93F7F937C22A7ULL);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 4726U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((aIndex + 2797U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 1703U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 3593U)) & S_BLOCK1], 39U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 6U) + RotL64(aPrevious, 21U)) ^ (RotL64(aIngress, 39U) ^ RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordD;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterK = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 19U)) + 7948891781097675369U) + aNonceWordK;
            aOrbiterJ = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 5U)) + 13928362874228230226U) + aPhaseBOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 3U)) + 10776180542602258926U) + aPhaseBOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 57U)) + 5735115172149470447U) + aNonceWordD;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 36U)) + 5353591822981766987U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 562301708107268570U) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10467810247578364868U;
            aOrbiterC = RotL64((aOrbiterC * 10449089554007059823U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14541630141152308564U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2350076897065139429U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12222554362482034393U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 17519109078651162228U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6061035173339902910U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10021905773432907835U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15654836633731000065U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13723521735153718904U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 14459516479283070563U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 2849680038315532197U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17336102435576647923U) ^ aNonceWordN;
            aOrbiterF = RotL64((aOrbiterF * 10984689101753586739U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 43U)) + aOrbiterC);
            aWandererA = aWandererA + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 27U)) + aOrbiterF) + RotL64(aCarry, 5U)) + aNonceWordF) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 52U)) + aOrbiterK);
            aWandererH = aWandererH + ((((RotL64(aCross, 14U) + RotL64(aOrbiterK, 35U)) + aOrbiterF) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterC, 5U)) + aNonceWordC) + aPhaseBWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 13U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 22U);
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8324U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10313U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5567U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7702U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 20U) ^ RotL64(aCarry, 47U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = ((aWandererE + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 14008824488073394623U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 38U)) + RotL64(aCarry, 57U)) + 13317978415866411468U;
            aOrbiterC = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 37U)) + 13209180141897453900U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aIngress, 29U)) + 11870521586865233578U) + aNonceWordF;
            aOrbiterE = ((aWandererA + RotL64(aCross, 21U)) + 8052156380448047385U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 12158131176743680605U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 14674467487607719347U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 18372548574199176503U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 18055496790566231147U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3838105585041578784U;
            aOrbiterE = RotL64((aOrbiterE * 1075709247574580091U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 2839568255183054418U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 11933612922864258179U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 7571964469321160347U), 13U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterE) + 6289849094151630580U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 2640344350528492271U;
            aOrbiterK = RotL64((aOrbiterK * 16197726750829369365U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 16306175266267657791U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 3339898380394883600U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 57U);
            //
            aIngress = RotL64(aOrbiterC, 35U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 24U));
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 38U)) + aOrbiterI) + aNonceWordH);
            aWandererE = aWandererE + ((((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterC, 53U)) + RotL64(aCarry, 21U)) + aNonceWordI);
            aWandererA = aWandererA ^ ((((RotL64(aPrevious, 41U) + aOrbiterC) + RotL64(aOrbiterH, 5U)) + aNonceWordA) + aPhaseBWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterI, 13U)) + RotL64(aCarry, 37U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 12U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + aPhaseBWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 48U));
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordB ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 15910U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11356U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15383U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 12106U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 11U)) ^ (RotL64(aPrevious, 48U) ^ RotL64(aCross, 35U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterG = ((aWandererK + RotL64(aScatter, 57U)) + 12849591986267890852U) + aNonceWordC;
            aOrbiterB = (((aWandererH + RotL64(aCross, 6U)) + RotL64(aCarry, 13U)) + 8232614804696815750U) + aNonceWordJ;
            aOrbiterA = (((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 12141567259210877281U) + aPhaseBOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aIngress, 21U)) + RotL64(aCarry, 29U)) + 2928641981037885644U;
            aOrbiterF = (((aWandererA + RotL64(aCross, 37U)) + 980733350554783938U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2683985177993350746U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14532148403815527355U;
            aOrbiterA = RotL64((aOrbiterA * 15985362037094864225U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7736296629433884203U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 10428437770166310549U;
            aOrbiterB = RotL64((aOrbiterB * 326634742742373401U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 18327174144859461029U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 6810436935194432002U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2715987179577753597U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 12606153309690753435U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 17123256945895150555U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13469111258504672565U), 11U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 9057777759026189541U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16478485918911194442U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11054247078884894131U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 26U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 13U));
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterA, 19U)) + aOrbiterF) + aNonceWordD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 23U) + aOrbiterF) + RotL64(aOrbiterH, 40U)) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + aPhaseBWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 46U) + aOrbiterB) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 39U)) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererD, 43U));
            aCarry = aCarry + RotL64(aWandererG, 5U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = aCarry ^ aNonceWordB;
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 21392U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19277U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20138U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 18966U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 26U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 43U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterI = (aWandererE + RotL64(aPrevious, 35U)) + 5510690816044082200U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 23U)) + RotL64(aCarry, 13U)) + 15967820875033940530U) + aNonceWordF;
            aOrbiterK = ((((aWandererD + RotL64(aScatter, 52U)) + RotL64(aCarry, 35U)) + 539348720848176221U) + aPhaseBOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1]) + aNonceWordA;
            aOrbiterB = (((aWandererJ + RotL64(aCross, 3U)) + RotL64(aCarry, 47U)) + 15779318183635560817U) + aPhaseBOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 43U)) + 14511058534424187469U) + aNonceWordE;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5811130556873428391U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 1085928476499444025U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 13965845678632598921U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6973335316600768130U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10747243745475009744U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17322489216048017061U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 1072260008981349754U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 2018772405352495753U;
            aOrbiterB = RotL64((aOrbiterB * 10840562112080574241U), 35U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 1092091597048996547U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 15103140149542167197U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 621856991658027989U), 5U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 13194619321108681542U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16749188603268621850U;
            aOrbiterH = RotL64((aOrbiterH * 9575408950550922039U), 19U);
            //
            aIngress = RotL64(aOrbiterC, 14U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + RotL64(aCarry, 3U)) + aPhaseBWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 46U) + aOrbiterK) + RotL64(aOrbiterB, 60U));
            aWandererA = aWandererA + ((RotL64(aCross, 57U) + aOrbiterC) + RotL64(aOrbiterI, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 35U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 29U) + RotL64(aOrbiterI, 19U)) + aOrbiterH) + RotL64(aCarry, 27U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordO ^ aNonceWordI);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25966U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 25534U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordJ;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 25132U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24904U)) & S_BLOCK1], 42U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 12U) + RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 29U) + RotL64(aCross, 57U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterE = ((aWandererK + RotL64(aIngress, 51U)) + 13333509828310369865U) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aPrevious, 5U)) + 7645352517103840797U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aScatter, 24U)) + RotL64(aCarry, 29U)) + 5310766306660062655U) + aPhaseBOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 5165635069832352932U) + aNonceWordG;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 35U)) + RotL64(aCarry, 41U)) + 15684141764734281849U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 3327963374225061738U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8625811794878848871U;
            aOrbiterD = RotL64((aOrbiterD * 16327750494894125333U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7598657468430485291U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 2881171216276746485U;
            aOrbiterH = RotL64((aOrbiterH * 3331350584102843605U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10237691227222918101U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 6419254255884834497U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3816625473642865305U), 3U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterH) + 4238455444646479956U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 14936613353493061492U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3544216916806292273U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 15324699725208372627U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9506640480601832011U;
            aOrbiterG = RotL64((aOrbiterG * 12819564111348390227U), 23U);
            //
            aIngress = RotL64(aOrbiterE, 53U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 39U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + aNonceWordH);
            aWandererE = aWandererE + (((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 48U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK + (((((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterG, 5U)) + RotL64(aCarry, 5U)) + aNonceWordM) + aPhaseBWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 11U) + RotL64(aOrbiterE, 13U)) + aOrbiterH) + aNonceWordF) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = aCarry ^ aNonceWordJ;
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30513U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 31609U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseBDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 29337U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32673U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseBDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 38U) + RotL64(aPrevious, 51U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 23U));
            aScatter = aScatter ^ aNonceWordI;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseBDomainWordScatter));
            //
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 19U)) + 479672811032092393U;
            aOrbiterI = (((aWandererG + RotL64(aIngress, 57U)) + 18061121631394564425U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 14237400452740566065U;
            aOrbiterJ = ((((aWandererC + RotL64(aCross, 19U)) + RotL64(aCarry, 35U)) + 6723123812257706134U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 30U)) + 4247997188026499248U) + aNonceWordJ;
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 1939107415066134869U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3912640123546395979U;
            aOrbiterC = RotL64((aOrbiterC * 9779626695085572877U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 8295478436553964298U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3218960600711526885U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15443507655470278069U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 5874096203353388890U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 10294536533673023358U;
            aOrbiterA = RotL64((aOrbiterA * 15561710414949058923U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11268561953904130747U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 16693201256788898423U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 16291987237693567209U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 7550969634681894654U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 9501647424602245869U) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 11265865222096866605U), 43U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 20U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordK);
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterI, 51U)) + aNonceWordB) + aPhaseBWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterI) + RotL64(aOrbiterE, 39U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterE, 60U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + aNonceWordM) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Softball_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xB9CC735D724E13EBULL + 0x8A41AD3759BE6E56ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xC7BCDB69651FDBA9ULL + 0xB9E61AB27C8CAFFAULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC013232A3B974C33ULL + 0xA1C7E151DCAF221FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9F91828F87680255ULL + 0x8904B2E59144C523ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0x864D94442B842871ULL + 0xAD0AA4044F9A0152ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8EB58A7A63361543ULL + 0x938DFF350FC66FB2ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x972C3062E8EDF19DULL + 0xEBE75F121F3808C1ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xCF25488B80C1683BULL + 0xBCCCC5FD23DA8718ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC81D45D4A2955AF5ULL + 0xC070D079289EF223ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB54FEA01C358F8F7ULL + 0xABD60989773A9E40ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8B72F8202ECBC715ULL + 0xE0735A5AEF030933ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8214A972461EB369ULL + 0xB07EC1CE020666EEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0x920F9F23F440EFDBULL + 0xC5E948FE24EC73EEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x9AB778C38CC04825ULL + 0xCE3F44C872020FE2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFB5F2ACC6C7CD3A3ULL + 0x9C4A329C251E7223ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xAA4D03A8ABE7A981ULL + 0xFF1879A5D47C638DULL);
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 495U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 7893U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 4636U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 4375U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCross, 53U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 19U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 56U)) + RotL64(aCarry, 29U)) + 15188686795415908074U;
            aOrbiterI = ((aWandererA + RotL64(aScatter, 41U)) + 17310049041983079779U) + aNonceWordP;
            aOrbiterA = (aWandererB + RotL64(aCross, 27U)) + 8246925977992441471U;
            aOrbiterE = (((aWandererE + RotL64(aIngress, 19U)) + 8644260919918112781U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (((aWandererG + RotL64(aScatter, 23U)) + RotL64(aCarry, 5U)) + 13401663736874819483U) + aPhaseCOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aCross, 47U)) + RotL64(aCarry, 41U)) + 7940358935238314973U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 10U)) + 13278990328548007839U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 35U)) + 11346868298353840706U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 5U)) + 2374077904806833579U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 6978903378645019166U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11951633297870965212U;
            aOrbiterA = RotL64((aOrbiterA * 12778236598654492185U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 17398460995357409673U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 1215437945597836770U) ^ aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9322970054123481621U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1878751468043972239U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 5343002808239712390U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 11878640995447558811U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9884918450053276861U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15894599082080422550U;
            aOrbiterH = RotL64((aOrbiterH * 8359936745539546131U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 13917339232771145459U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18101134009493720683U;
            aOrbiterJ = RotL64((aOrbiterJ * 15835859435306756387U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 3830086372356903769U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 15894394599564584010U;
            aOrbiterE = RotL64((aOrbiterE * 9513921913446609263U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 5127590955274245812U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9410946933309720054U;
            aOrbiterB = RotL64((aOrbiterB * 14507476989423060561U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 15544384157294987085U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 998801294460434123U;
            aOrbiterI = RotL64((aOrbiterI * 5946968142746472745U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16442095194965452163U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 14294936349037516932U;
            aOrbiterF = RotL64((aOrbiterF * 14655345374740882581U), 5U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 47U);
            aIngress = aIngress + (RotL64(aOrbiterC, 34U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + RotL64(aOrbiterJ, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 37U) + RotL64(aOrbiterH, 29U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 52U) + RotL64(aOrbiterB, 35U)) + aOrbiterC) + aNonceWordN);
            aWandererF = aWandererF + ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterJ, 6U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterF, 53U)) + aPhaseCWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 27U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 23U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 57U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 12U) + aOrbiterI) + RotL64(aOrbiterF, 18U));
            aWandererC = aWandererC + ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterI, 43U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererE, 38U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = aCarry ^ (aNonceWordH ^ aNonceWordJ);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 14576U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9846U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordM;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8656U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14773U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 18U) + RotL64(aCross, 53U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererA + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 5510690816044082200U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 34U)) + 15967820875033940530U) + aNonceWordB;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 5U)) + 539348720848176221U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 15779318183635560817U) + aPhaseCOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aWandererC + RotL64(aScatter, 41U)) + 14511058534424187469U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 24U)) + RotL64(aCarry, 53U)) + 5811130556873428391U;
            aOrbiterA = (aWandererB + RotL64(aCross, 29U)) + 1085928476499444025U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 19U)) + 6973335316600768130U) + aNonceWordI;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 53U)) + 10747243745475009744U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 1072260008981349754U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 2018772405352495753U;
            aOrbiterG = RotL64((aOrbiterG * 10840562112080574241U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 1092091597048996547U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15103140149542167197U;
            aOrbiterH = RotL64((aOrbiterH * 621856991658027989U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13194619321108681542U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 16749188603268621850U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9575408950550922039U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 7427959503086895166U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 9895804051379551393U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2701997336201570715U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 4526020800679774259U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4484850928870048176U;
            aOrbiterF = RotL64((aOrbiterF * 17556987520625677313U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1837404844299040155U) + aNonceWordL;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15213208978489570694U;
            aOrbiterD = RotL64((aOrbiterD * 7062740584650274133U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 9615231781751396800U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 15872192167825648096U;
            aOrbiterC = RotL64((aOrbiterC * 2900526493682580729U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12530672039655918903U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10617836782870315804U;
            aOrbiterB = RotL64((aOrbiterB * 9716778004909794973U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 550750725406860977U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 3498554352021622907U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 9846933294851238495U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 5U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 44U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterK, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 23U) + aOrbiterA) + RotL64(aOrbiterG, 44U));
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aNonceWordA) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 56U) + RotL64(aOrbiterF, 19U)) + aOrbiterG);
            aWandererH = aWandererH ^ ((((RotL64(aCross, 29U) + RotL64(aOrbiterD, 23U)) + aOrbiterI) + aNonceWordK) + aPhaseCWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 47U) + aOrbiterC) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterC, 27U));
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterD, 57U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterI, 3U));
            aWandererB = aWandererB + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 52U)) + aOrbiterD) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 38U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18592U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneA[((aIndex + 22902U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordB;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24346U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 18769U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 58U)) + (RotL64(aPrevious, 13U) + RotL64(aCross, 27U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 5U)) + 2915859148137000694U) + aNonceWordH;
            aOrbiterB = (aWandererH + RotL64(aCross, 56U)) + 210680583721444425U;
            aOrbiterK = ((aWandererA + RotL64(aIngress, 19U)) + 6668118118775650387U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 27U)) + 15794200818099010989U) + aNonceWordF;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 6565076707062828369U) + aNonceWordO;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 48U)) + RotL64(aCarry, 3U)) + 16323164497808856719U;
            aOrbiterE = ((aWandererK + RotL64(aCross, 23U)) + 7965435318816716560U) + aPhaseCOrbiterAssignSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aScatter, 39U)) + RotL64(aCarry, 13U)) + 7390281030573369017U;
            aOrbiterH = (aWandererG + RotL64(aCross, 43U)) + 2269738866911824875U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 9664014216039993873U) + aNonceWordC;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18284857398028357633U;
            aOrbiterK = RotL64((aOrbiterK * 8402008251343393737U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 367667619795303009U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7935945060956274197U;
            aOrbiterA = RotL64((aOrbiterA * 5481786693511955209U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 16683666162337789540U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10655658270998102390U;
            aOrbiterF = RotL64((aOrbiterF * 15231596813382239841U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8307037916581540297U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3247742749860703524U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15052136713218656641U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10446792483683818139U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16374602929344972364U;
            aOrbiterJ = RotL64((aOrbiterJ * 12599903932725787599U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 2411334498322777183U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 1093701164116833765U;
            aOrbiterI = RotL64((aOrbiterI * 13129220206835381729U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 17018480952982840635U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17348395690080029814U;
            aOrbiterE = RotL64((aOrbiterE * 6212591395713433257U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16111252311283623152U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 12776492920397785951U;
            aOrbiterG = RotL64((aOrbiterG * 6136009241593081821U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12214538600808144816U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10043377462096783363U;
            aOrbiterH = RotL64((aOrbiterH * 14639467375095185877U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 3U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 56U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 29U)) + aOrbiterK) + RotL64(aCarry, 57U)) + aPhaseCWandererUpdateSaltB[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 36U) + aOrbiterG) + RotL64(aOrbiterE, 37U));
            aWandererB = aWandererB + ((RotL64(aScatter, 41U) + RotL64(aOrbiterF, 14U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterB, 47U)) + aOrbiterK);
            aWandererK = aWandererK + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterK, 51U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordK);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterE, 5U));
            aWandererD = aWandererD + ((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterI, 58U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterA, 21U)) + aPhaseCWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (RotL64(aWandererD, 46U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + RotL64(aWandererK, 13U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 29617U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31940U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseCDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30478U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 32681U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseCDomainWordCross));
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aIngress, 51U)) + (RotL64(aCarry, 34U) + RotL64(aPrevious, 21U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseCDomainWordScatter));
            //
            aOrbiterD = ((aWandererE + RotL64(aCross, 21U)) + RotL64(aCarry, 5U)) + 6069475454765660321U;
            aOrbiterB = (aWandererG + RotL64(aPrevious, 6U)) + 11483704742497268068U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 47U)) + 11055697447388986418U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 51U)) + 10897095046039997004U) + aNonceWordG;
            aOrbiterK = ((aWandererI + RotL64(aCross, 39U)) + 4731637118230457840U) + aPhaseCOrbiterAssignSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aIngress, 29U)) + 13855839187084986751U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 5328208115460188239U;
            aOrbiterG = ((aWandererA + RotL64(aPrevious, 43U)) + RotL64(aCarry, 23U)) + 12479538544291412985U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 58U)) + 10740165998792608231U) + aPhaseCOrbiterAssignSaltF[((aIndex + 25U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 6492798157284955373U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 13056825957483891921U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 14882112110627751751U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2068184064919194657U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 5656302738780746294U;
            aOrbiterK = RotL64((aOrbiterK * 16493021179127646345U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 11193756120230763294U) + aPhaseCOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17306750816837208999U;
            aOrbiterJ = RotL64((aOrbiterJ * 7949360041241439741U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 12952818800389361804U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 15380412293642628312U;
            aOrbiterD = RotL64((aOrbiterD * 2914662289178925547U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7706090204767242996U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14598802276412649570U;
            aOrbiterH = RotL64((aOrbiterH * 4821408736292041399U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 17819762117328075515U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 6481384240915075101U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 4836701121865783029U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 754936290510338717U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15510875946573720154U;
            aOrbiterG = RotL64((aOrbiterG * 2994718968852184303U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9245381722813944586U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2629847912019726214U;
            aOrbiterI = RotL64((aOrbiterI * 6718795794951106961U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 3909987749797113773U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9277056074757335265U;
            aOrbiterB = RotL64((aOrbiterB * 11580847505996697115U), 21U);
            //
            aIngress = RotL64(aOrbiterF, 39U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 26U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterD, 30U));
            aWandererG = aWandererG ^ (((RotL64(aIngress, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 23U)) + aPhaseCWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 60U) + aOrbiterF) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 41U) + aOrbiterJ) + RotL64(aOrbiterI, 47U));
            aWandererK = aWandererK + ((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 52U)) + aOrbiterH);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aNonceWordI);
            aWandererA = aWandererA + ((((RotL64(aCross, 11U) + RotL64(aOrbiterB, 13U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 54U) + RotL64(aOrbiterF, 19U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterD, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererG, 54U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordG;
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

void TwistExpander_Softball_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE4A7F1670B3D8B79ULL + 0xF53DDC1328B2E984ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF978164F1053F80FULL + 0xB4221CF7E97DE1D8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x8BEF4825D601CFA3ULL + 0xDFE81FA94510C4B7ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xC1679DA2E00246D7ULL + 0xB4E567DB1A0AA965ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE9CD5931D9DBDC1FULL + 0x98613DC2B579DCF2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA75B03A5BCC328B5ULL + 0xCCB0B63F1F57971BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x864976C7BCED4039ULL + 0x81F7A40B822338DFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8D3DCBB14B2A6A87ULL + 0x915300664074A753ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0x8B17AB8BAC6A32B7ULL + 0xE3E463B2C8ACFC40ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xC4497C27E6FCB545ULL + 0xA79B913AABB4FF1BULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xDB13205C9E261D4FULL + 0x8307F980F3525FA5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xF2741F6ECCB81B57ULL + 0xDC4E98D066D42B69ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE8916FF52A83C41DULL + 0xF1ECA296A0CB1CA6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x8221516BCEE41B07ULL + 0xE086610F54A83CA1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xE86BC8492D0ED947ULL + 0xA77E3C053013FAC8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x818E920B6FEE4A5FULL + 0xD04DF76793862FD0ULL);
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
            aIngress = aIngress ^ aNonceWordG;
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 2004U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 4771U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5235U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneA[((aIndex + 2128U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 58U) + RotL64(aPrevious, 29U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordL;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 41U)) + 6469584119078165548U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 13U)) + 14329756366517987910U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 29U)) + 12890831797059772123U;
            aOrbiterG = ((aWandererC + RotL64(aCross, 38U)) + 3164503807500018990U) + aPhaseDOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aWandererD + RotL64(aIngress, 35U)) + 177531431387646836U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 3167421392893561015U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 23U)) + 2813174781844753460U) + aNonceWordB;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 48U)) + RotL64(aCarry, 51U)) + 10953270419153249857U;
            aOrbiterA = (aWandererK + RotL64(aCross, 53U)) + 16911518309710356951U;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 5U)) + 6616750447844893150U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aScatter, 19U)) + 10276741398025985982U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 6206043608461213208U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12021552904553405793U;
            aOrbiterJ = RotL64((aOrbiterJ * 10023362889960174909U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15283586234744144846U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5923238786775948571U;
            aOrbiterK = RotL64((aOrbiterK * 8200882393521882651U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11044014510971660078U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 9351141024085076044U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 13316079344614432317U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17703395981862992420U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 10154548848376027087U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12324478347590509035U), 41U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 8836420852291617425U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10193385413543886344U;
            aOrbiterF = RotL64((aOrbiterF * 824935982418585449U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 8248580084535685190U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3910083671888152974U;
            aOrbiterA = RotL64((aOrbiterA * 17825311776715895927U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 12350341628569930642U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 2565977481575002842U;
            aOrbiterD = RotL64((aOrbiterD * 18233446879833776677U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9271041067874027417U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 14289254596554201861U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7985522692852251413U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5981802134118235214U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14047813418129636856U;
            aOrbiterI = RotL64((aOrbiterI * 15961435325216504877U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 11808443842149398212U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 11380858372643695792U;
            aOrbiterE = RotL64((aOrbiterE * 100198424024622179U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterD) + 10385375464069162356U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 6469584119078165548U;
            aOrbiterB = RotL64((aOrbiterB * 5263876933019848989U), 39U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((((RotL64(aCross, 44U) + aOrbiterF) + RotL64(aOrbiterA, 54U)) + aNonceWordE) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 21U) + aOrbiterA) + RotL64(aOrbiterC, 35U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 35U) + aOrbiterD) + RotL64(aOrbiterJ, 37U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 47U)) + aOrbiterE);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 18U));
            aWandererI = aWandererI + ((RotL64(aCross, 26U) + RotL64(aOrbiterG, 11U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterA, 41U)) + aNonceWordP);
            aWandererH = aWandererH + (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 13U)) + aOrbiterG);
            aWandererJ = aWandererJ + (((RotL64(aCross, 51U) + RotL64(aOrbiterB, 3U)) + aOrbiterJ) + RotL64(aCarry, 47U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 5U)) + aOrbiterE) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererK);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordC;
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 6946U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 9863U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7907U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8387U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 60U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCarry, 39U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterJ = (aWandererE + RotL64(aCross, 23U)) + 14157904117287696136U;
            aOrbiterC = (aWandererG + RotL64(aIngress, 43U)) + 7369512677371640676U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 37U)) + 8411250745902073798U) + aPhaseDOrbiterAssignSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 21U)) + 5002041814539710275U) + aNonceWordO;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 47U)) + RotL64(aCarry, 41U)) + 9538041410816283124U) + aNonceWordL;
            aOrbiterG = (aWandererH + RotL64(aCross, 52U)) + 5210700103927513061U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 35U)) + 7600709399101287982U) + aPhaseDOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aScatter, 29U)) + 2366369466696580499U;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 3U)) + 5544575244203019109U;
            aOrbiterB = (aWandererI + RotL64(aCross, 21U)) + 8710073749110329779U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 40U)) + RotL64(aCarry, 47U)) + 15998211310115361630U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 15354357553877376422U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 10657523549259276169U;
            aOrbiterK = RotL64((aOrbiterK * 13695239532898311073U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 10405750198355464768U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 3465819693133515142U;
            aOrbiterC = RotL64((aOrbiterC * 14678343718277562799U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 16724189641701408630U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3484340153620198872U;
            aOrbiterD = RotL64((aOrbiterD * 17247547677520703125U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 7420442404884871126U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 11138445997256757636U;
            aOrbiterE = RotL64((aOrbiterE * 11167543379937571127U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1428191560884663125U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16950093140800653985U;
            aOrbiterF = RotL64((aOrbiterF * 4423012306984814805U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17288299075036481960U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13793597915359681028U;
            aOrbiterJ = RotL64((aOrbiterJ * 9639204979982125757U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 5017972942710079726U) + aNonceWordH;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12409957957614320964U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10273295741911545745U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 12487994181992095174U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 1573393166996612118U;
            aOrbiterG = RotL64((aOrbiterG * 13364311829104520751U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 13227642825780350128U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7961292096150889569U;
            aOrbiterA = RotL64((aOrbiterA * 16627209081334341289U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 10312485102088913337U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3177620041478410950U;
            aOrbiterB = RotL64((aOrbiterB * 15918551366833593853U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2599092792737616563U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 14157904117287696136U;
            aOrbiterI = RotL64((aOrbiterI * 14883446269291639813U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 57U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 22U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterH, 47U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterG, 41U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterE, 53U)) + aPhaseDWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 14U)) + aOrbiterA);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 19U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 3U)) + aOrbiterC);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aPhaseDWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterE, 60U)) + aNonceWordD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + aOrbiterG) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterK, 11U)) + aOrbiterF);
            aWandererF = aWandererF + (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 42U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 34U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordL ^ aNonceWordH);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 15308U)) & S_BLOCK1], 26U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 12977U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordP;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 15008U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13649U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 20U) + RotL64(aCross, 41U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 23U)) + RotL64(aCarry, 23U)) + 2101601659597850213U;
            aOrbiterA = (aWandererA + RotL64(aCross, 58U)) + 2759794072560720121U;
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 51U)) + 9443562552411269339U) + aNonceWordM;
            aOrbiterH = (aWandererH + RotL64(aScatter, 35U)) + 10801360546699857975U;
            aOrbiterE = (aWandererC + RotL64(aCross, 37U)) + 8020716394829332019U;
            aOrbiterI = (aWandererK + RotL64(aPrevious, 54U)) + 1021894212367773801U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 57U)) + 13346855534622490176U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = (aWandererE + RotL64(aScatter, 5U)) + 16359309548462953836U;
            aOrbiterJ = ((aWandererG + RotL64(aCross, 41U)) + 12642446944680783519U) + aNonceWordF;
            aOrbiterC = (((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 11U)) + 8197424982767553380U) + aPhaseDOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aIngress, 21U)) + 14346334610901859094U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 14171304260534233539U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 334531601308283605U;
            aOrbiterG = RotL64((aOrbiterG * 5012968232749075075U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10707856298471572695U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 18364775750091914766U;
            aOrbiterI = RotL64((aOrbiterI * 15735143943129143265U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8531394793118363836U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 15352876929406908882U;
            aOrbiterA = RotL64((aOrbiterA * 475199047053777179U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 567682016232278157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 2068146551757663119U;
            aOrbiterE = RotL64((aOrbiterE * 1557877740957797555U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7776122587613256525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16430938890724272256U;
            aOrbiterK = RotL64((aOrbiterK * 4540270493783593257U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11912000645055436094U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 16800749242578741498U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17804584625034241737U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 5909199180260499150U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 5751089915336865588U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15376689503142397927U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3478216857728853008U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 18007567146937338241U;
            aOrbiterH = RotL64((aOrbiterH * 6620498877303917855U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17454259424163653490U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6276120962018305311U;
            aOrbiterF = RotL64((aOrbiterF * 7560618224285018801U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3839336239901666431U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6230149015045237670U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 1838983748994340883U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17552095486612766544U) + aNonceWordI;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 2101601659597850213U;
            aOrbiterD = RotL64((aOrbiterD * 2915330118061857271U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (RotL64(aOrbiterH, 43U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 27U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aCross, 21U) + aOrbiterJ) + RotL64(aOrbiterE, 18U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 39U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 30U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterD, 29U));
            aWandererE = aWandererE + ((((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterK, 41U)) + aNonceWordJ) + aPhaseDWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterF, 50U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aIngress, 41U) + RotL64(aOrbiterJ, 47U)) + aOrbiterC) + aNonceWordC);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 60U) + aOrbiterB) + RotL64(aOrbiterE, 21U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 37U)) + aOrbiterI) + aNonceWordN) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 10U));
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = aCarry ^ aNonceWordO;
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 18141U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 20126U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20033U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 17116U)) & S_BLOCK1], 18U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 36U) + RotL64(aCarry, 57U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterF = (((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 11U)) + 8375305456876489425U) + aPhaseDOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aPrevious, 39U)) + 16193562952772453047U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + RotL64(aCarry, 5U)) + 18088652458594816223U;
            aOrbiterI = (((aWandererC + RotL64(aScatter, 21U)) + RotL64(aCarry, 35U)) + 767344788620249944U) + aPhaseDOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 37U)) + 7705194930396368752U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 34U)) + 3829736891311272834U) + aNonceWordC;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 51U)) + 9881681671347640061U;
            aOrbiterE = ((aWandererA + RotL64(aPrevious, 43U)) + 1721196560190164264U) + aNonceWordI;
            aOrbiterK = (aWandererE + RotL64(aCross, 13U)) + 3002652618388454213U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 5U)) + 9811621464004005202U;
            aOrbiterD = (aWandererK + RotL64(aScatter, 11U)) + 5652598941069986530U;
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 6250499348327316328U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16025054277615264530U;
            aOrbiterB = RotL64((aOrbiterB * 16446892258704281903U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 13800298546867243172U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12256104592865905782U;
            aOrbiterH = RotL64((aOrbiterH * 16983140179497142713U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 17817225416918329229U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17738671327352776217U;
            aOrbiterA = RotL64((aOrbiterA * 393488251327705063U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 6816031224188400541U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16989563985059237014U;
            aOrbiterJ = RotL64((aOrbiterJ * 8677884225771717797U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16891524847268207549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 1833508573940405571U;
            aOrbiterE = RotL64((aOrbiterE * 9709196587703979539U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12729999421507068973U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 6839758643521968957U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16350557395881283975U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 8524167125469267428U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14741523560290472617U;
            aOrbiterC = RotL64((aOrbiterC * 4367850822282205897U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 10983798459868424892U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5649250846622078964U;
            aOrbiterD = RotL64((aOrbiterD * 7149612714806023987U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8587302028325090061U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17457129226030333666U;
            aOrbiterF = RotL64((aOrbiterF * 18107356450566915215U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 15600113588474915690U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 6595247491374683783U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1432432381540098765U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 13246325856585534283U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8375305456876489425U;
            aOrbiterI = RotL64((aOrbiterI * 8331406038795786099U), 53U);
            //
            aIngress = RotL64(aOrbiterC, 19U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 23U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterD, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + RotL64(aCarry, 35U)) + aNonceWordD) + aPhaseDWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 23U)) + aOrbiterG) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 37U)) + aOrbiterF);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + RotL64(aOrbiterK, 43U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 54U) + RotL64(aOrbiterD, 54U)) + aOrbiterJ);
            aWandererF = aWandererF + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterD, 21U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 29U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererC = aWandererC + ((RotL64(aCross, 51U) + aOrbiterG) + RotL64(aOrbiterI, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 24U) + aOrbiterK) + RotL64(aOrbiterG, 11U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterG, 56U)) + aOrbiterJ) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererG, 28U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererB, 47U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 37U) ^ aWandererH);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 21U));
            aCarry = aCarry + RotL64(aWandererE, 5U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = aCarry ^ (aNonceWordC ^ aNonceWordL);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 24219U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 26966U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 24889U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25306U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 39U) ^ RotL64(aCarry, 21U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 6U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 23U)) + 14686411261024919129U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 5U)) + 7514582233957632005U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 47U)) + 6520710480103365552U;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 1983621978676188036U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 29U)) + 9003524602590749672U) + aPhaseDOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aCross, 37U)) + 6428568234045228995U;
            aOrbiterH = (aWandererD + RotL64(aPrevious, 39U)) + 8656552687136446989U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 50U)) + 16916248288415922490U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 47U)) + 9740237548002535784U) + aNonceWordK;
            aOrbiterE = (aWandererA + RotL64(aCross, 21U)) + 907561000814618339U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 57U)) + 4751108900841197631U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 167774899400732287U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11907484918310854962U;
            aOrbiterB = RotL64((aOrbiterB * 7213139491146402985U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14910318613649863924U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 14882888155751455276U;
            aOrbiterC = RotL64((aOrbiterC * 11394136445442060201U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 16175942562693781908U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 11022373758481651102U;
            aOrbiterI = RotL64((aOrbiterI * 6836331461393816027U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 12548405399045031548U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10850926364556828443U;
            aOrbiterE = RotL64((aOrbiterE * 16231561687709867431U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13391684887911141790U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 14648937281264822988U;
            aOrbiterG = RotL64((aOrbiterG * 6533299316940026059U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8298658887198526821U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 13822977698661348891U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17769262972278410937U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 7505646847564645719U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 3238749538197209166U;
            aOrbiterH = RotL64((aOrbiterH * 15394286542600778567U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 15853506915123709257U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8426329899401071248U;
            aOrbiterD = RotL64((aOrbiterD * 1330397096577715113U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 14848635392815613098U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3549927798350175044U;
            aOrbiterF = RotL64((aOrbiterF * 1899044682313056949U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1798973117197750802U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13056711228618953977U;
            aOrbiterA = RotL64((aOrbiterA * 9102877396419306689U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 1395893547965799281U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14686411261024919129U;
            aOrbiterJ = RotL64((aOrbiterJ * 17075377081365066067U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 56U));
            aIngress = aIngress + (RotL64(aOrbiterA, 39U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterE) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 39U)) + aOrbiterC);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterE, 13U)) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 6U) + RotL64(aOrbiterB, 36U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 11U)) + aOrbiterD) + aNonceWordI);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + aOrbiterC) + RotL64(aOrbiterI, 3U)) + aNonceWordL);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 51U)) + aOrbiterH) + aNonceWordB) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 5U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterK, 44U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 38U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 28U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordL;
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 28865U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31664U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseDDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 28733U)) & S_BLOCK1], 52U) ^ RotL64(aOperationLaneB[((aIndex + 28426U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseDDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 6U)) + (RotL64(aCross, 19U) + RotL64(aPrevious, 37U));
            aScatter = aScatter ^ aNonceWordO;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseDDomainWordScatter));
            //
            aOrbiterH = (((aWandererD + RotL64(aPrevious, 41U)) + 5906639480605353429U) + aPhaseDOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterC = (aWandererB + RotL64(aScatter, 29U)) + 5293518570213287605U;
            aOrbiterF = ((aWandererK + RotL64(aCross, 51U)) + RotL64(aCarry, 19U)) + 15383185501428521377U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 23U)) + 15364072512743978902U;
            aOrbiterA = (aWandererH + RotL64(aCross, 27U)) + 4525473357144014271U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 58U)) + 10400911938125603074U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 16417506293824627550U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 13U)) + 2419329331753341815U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 19U)) + 14929222427923332069U;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 10U)) + RotL64(aCarry, 41U)) + 16771573504983922586U) + aPhaseDOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 43U)) + 1863466450051787622U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12895350137096692415U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 3700979086526298327U;
            aOrbiterF = RotL64((aOrbiterF * 10279730254867618193U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 1977099106211282426U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 6144698304096915742U;
            aOrbiterA = RotL64((aOrbiterA * 5039822990560519609U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 3858895556659724975U) + aNonceWordM;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 1283646340363435327U;
            aOrbiterK = RotL64((aOrbiterK * 11622421841377018069U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6240532051889108891U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 757364889381634634U;
            aOrbiterB = RotL64((aOrbiterB * 943852137901972945U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5272945693977418174U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 6850528198786172283U;
            aOrbiterD = RotL64((aOrbiterD * 1966383079897679953U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 14431587733859573714U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16124590257870999553U;
            aOrbiterJ = RotL64((aOrbiterJ * 7755796211433191143U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 14912695018110241411U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 11098623474413346520U;
            aOrbiterE = RotL64((aOrbiterE * 15167688959990872051U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 3484847683376368686U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2295388097292719800U;
            aOrbiterI = RotL64((aOrbiterI * 1240808318176106909U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 923199510066894111U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 311875852510926196U;
            aOrbiterH = RotL64((aOrbiterH * 9797881750305289335U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 3543141837224843684U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 12889943043568922084U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8682278766727990427U), 37U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 6105656539077757510U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5906639480605353429U;
            aOrbiterG = RotL64((aOrbiterG * 9555916235293954383U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 56U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 34U) + aOrbiterF) + RotL64(aOrbiterA, 13U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterE, 21U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 54U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterB, 27U)) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterI, 19U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 24U)) + aOrbiterH) + aPhaseDWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aNonceWordH);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ aNonceWordA;
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Softball_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD237529939F804DDULL + 0xA34027AF22ABF7BDULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xF1485D81492234E3ULL + 0x95EF45A29272128EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xAA7B085F1CC82FC1ULL + 0x936FEC3AD5648AC8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xABDDEBC5C46882E9ULL + 0x8B48ABA21B3B97E2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA300031A78039CDBULL + 0xF88C33205DC49726ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xA987E4842E5BA67BULL + 0xA90FA93240F918AAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xDD2401BD8E01672BULL + 0xA10C50ED3A190457ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xE86E62C645F84C39ULL + 0xEFB9E46723077E4BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBCD0A0369FB9E5DBULL + 0xE3CC3F6D61500DFCULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xDF204B119C5789F5ULL + 0xD30729CE8ADBA8AEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x9DE62D0DC213313BULL + 0xD2243EEA924BE94DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xEC18D7F36783C25FULL + 0xF0FDCF27F20C8E99ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xEC65D121BE755B0DULL + 0xD4F81CC9B60CA4F4ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xD5BE6A94CDCB9F83ULL + 0xC05BF121572D1A07ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xC2D235C3AB582BBFULL + 0x847E01B355FCE96FULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF3CB7E2FC9EC64DDULL + 0x93545F4EAFD2F350ULL);
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 2049U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneC[((aIndex + 2575U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 1275U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5429U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordP;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterJ = (aWandererB + RotL64(aCross, 21U)) + 3255291173184001106U;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 43U)) + RotL64(aCarry, 13U)) + 15308468160116255528U;
            aOrbiterD = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 18186972408589866656U) + aNonceWordC;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 5U)) + 4439324265978331914U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 10U)) + 13099263173016322486U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 51U)) + 7041561081767500660U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aScatter, 39U)) + 6196422612687812971U) + aPhaseEOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aCross, 23U)) + 7664260932541281413U) + aNonceWordP;
            aOrbiterC = ((aWandererF + RotL64(aPrevious, 29U)) + 17802347823020441056U) + aNonceWordD;
            aOrbiterE = (aWandererE + RotL64(aCross, 56U)) + 4253107484061190446U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 41U)) + RotL64(aCarry, 47U)) + 13799496534030645312U;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterF) + 14252892847595951926U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 5663527578664291422U;
            aOrbiterD = RotL64((aOrbiterD * 18314294235895182465U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 11148755959699137661U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 17036900929333594592U;
            aOrbiterK = RotL64((aOrbiterK * 16041243617369003291U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 2403828181385259549U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 17813580350434928194U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 13666780980793857831U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5623611126885414523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 7293224381174846969U;
            aOrbiterA = RotL64((aOrbiterA * 7032561584670788117U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10602620906929686163U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 18015916257203385982U;
            aOrbiterG = RotL64((aOrbiterG * 10684090189688871993U), 35U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 13592915735376305773U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 13995866908043417505U;
            aOrbiterC = RotL64((aOrbiterC * 3802175869395887331U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 8200465989447697618U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9866671660800629464U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2138851839905326265U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11557528777230608777U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 131060617338185060U;
            aOrbiterF = RotL64((aOrbiterF * 11068705423012265209U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 13404720733342982167U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 13128574378042136042U;
            aOrbiterI = RotL64((aOrbiterI * 5805270317312187011U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15879295432652112238U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9433361543323748909U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3592390041363796221U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 6262775775981534941U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3255291173184001106U;
            aOrbiterE = RotL64((aOrbiterE * 2748492753337241005U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 51U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 48U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 50U) + aOrbiterB) + RotL64(aOrbiterA, 24U)) + RotL64(aCarry, 29U)) + aNonceWordA);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ);
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 53U)) + aOrbiterG) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 58U) + RotL64(aOrbiterH, 3U)) + aOrbiterD);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH + ((RotL64(aCross, 35U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 56U)) + aOrbiterA);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterG);
            aWandererI = aWandererI + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 27U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (RotL64(aWandererH, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 23U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = aCarry ^ aNonceWordH;
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
            aIngress = aIngress ^ aNonceWordN;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10253U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10052U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7443U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10239U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 36U)) + (RotL64(aPrevious, 23U) + RotL64(aCross, 51U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererE + RotL64(aCross, 41U)) + 4970414922752555648U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 21U)) + 9462756592787669327U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 3948790686662213095U;
            aOrbiterF = (aWandererA + RotL64(aPrevious, 3U)) + 14542857212241578311U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 53U)) + 3387479009827029547U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 23U)) + 1411421370057797877U;
            aOrbiterE = (((aWandererD + RotL64(aCross, 50U)) + RotL64(aCarry, 5U)) + 16894451466895681236U) + aNonceWordP;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 35U)) + 12727136462290223542U) + aPhaseEOrbiterAssignSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterA = (aWandererJ + RotL64(aIngress, 47U)) + 4625389198191960525U;
            aOrbiterC = (aWandererF + RotL64(aPrevious, 5U)) + 3471881403786164913U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 14U)) + 6433115856048534831U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9825592965466157982U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1553125767261293088U;
            aOrbiterI = RotL64((aOrbiterI * 411535191177308781U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 9951616357109647617U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11231080382787286889U;
            aOrbiterJ = RotL64((aOrbiterJ * 14024961994986659187U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 13419663264017317947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4835055642466215566U;
            aOrbiterB = RotL64((aOrbiterB * 17898065852351759171U), 21U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 14558747666410946768U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 13120938960926874504U;
            aOrbiterE = RotL64((aOrbiterE * 5681766019285559739U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11910501376797343986U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 15074100100781785300U;
            aOrbiterA = RotL64((aOrbiterA * 228976960937473851U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12415377930578091821U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterD) ^ 14882039078390681802U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 13855446647753150713U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8094338361713756895U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5478280604704108822U;
            aOrbiterF = RotL64((aOrbiterF * 18062931724700600993U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 6977017654546871841U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 4131602217285988962U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11865422227883712419U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 9619228479582032318U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13506679497441415586U;
            aOrbiterG = RotL64((aOrbiterG * 5789932662418992799U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10180259475831448124U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4721628773773094283U;
            aOrbiterC = RotL64((aOrbiterC * 10834196399754443771U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 7898137727558813688U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 4970414922752555648U;
            aOrbiterD = RotL64((aOrbiterD * 6651835668618579479U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 48U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterC) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 37U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 35U)) + aOrbiterC);
            aWandererF = aWandererF ^ ((RotL64(aCross, 19U) + aOrbiterJ) + RotL64(aOrbiterH, 24U));
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 37U)) + aNonceWordE);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 27U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterE, 29U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterD, 21U)) + aPhaseEWandererUpdateSaltA[((aIndex + 26U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterG, 48U));
            aWandererI = aWandererI + ((((RotL64(aCross, 50U) + aOrbiterE) + RotL64(aOrbiterG, 57U)) + aNonceWordF) + aPhaseEWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 12U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordN ^ aNonceWordH);
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
            aIngress = aIngress ^ aNonceWordJ;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 12686U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneA[((aIndex + 11946U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordN;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 14664U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((aIndex + 12419U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 40U) + RotL64(aCross, 23U)) + (RotL64(aCarry, 57U) ^ RotL64(aIngress, 11U));
            aScatter = aScatter ^ aNonceWordE;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + 6069475454765660321U) + aNonceWordP;
            aOrbiterD = (aWandererH + RotL64(aCross, 41U)) + 11483704742497268068U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 38U)) + 11055697447388986418U;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 27U)) + 10897095046039997004U) + aNonceWordA;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 5U)) + 4731637118230457840U;
            aOrbiterK = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 3U)) + 13855839187084986751U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 47U)) + 5328208115460188239U) + aNonceWordF;
            aOrbiterJ = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 12479538544291412985U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aPrevious, 35U)) + 10740165998792608231U;
            aOrbiterE = (aWandererD + RotL64(aCross, 27U)) + 6492798157284955373U;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 14U)) + 13056825957483891921U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 2068184064919194657U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 5656302738780746294U;
            aOrbiterC = RotL64((aOrbiterC * 16493021179127646345U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 11193756120230763294U) + aNonceWordB;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 17306750816837208999U;
            aOrbiterK = RotL64((aOrbiterK * 7949360041241439741U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 12952818800389361804U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 15380412293642628312U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 2914662289178925547U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 7706090204767242996U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 14598802276412649570U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4821408736292041399U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 17819762117328075515U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 6481384240915075101U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4836701121865783029U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 754936290510338717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15510875946573720154U;
            aOrbiterE = RotL64((aOrbiterE * 2994718968852184303U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 9245381722813944586U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 2629847912019726214U;
            aOrbiterF = RotL64((aOrbiterF * 6718795794951106961U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3909987749797113773U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9277056074757335265U;
            aOrbiterG = RotL64((aOrbiterG * 11580847505996697115U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 12577180954515966707U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9144513680789115458U;
            aOrbiterA = RotL64((aOrbiterA * 8880777678193004979U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 1544232962956974411U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 2658275904714859636U;
            aOrbiterI = RotL64((aOrbiterI * 1926083316365175327U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 5733515391293514025U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6069475454765660321U;
            aOrbiterB = RotL64((aOrbiterB * 9627476106108146391U), 3U);
            //
            aIngress = RotL64(aOrbiterE, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (RotL64(aOrbiterF, 39U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 11U) + aOrbiterB) + RotL64(aOrbiterH, 37U));
            aWandererD = aWandererD + (((RotL64(aCross, 52U) + aOrbiterB) + RotL64(aOrbiterC, 60U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 5U)) + aOrbiterF);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 23U)) + aOrbiterJ) + RotL64(aCarry, 3U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 47U)) + aOrbiterG);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterI, 11U)) + aNonceWordE);
            aWandererK = aWandererK + ((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererA = aWandererA ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 40U)) + aOrbiterK) + aNonceWordK);
            aWandererG = aWandererG + ((((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + aNonceWordD) + aPhaseEWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 20U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = aCarry ^ (aNonceWordG ^ aNonceWordA);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 17092U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 20439U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19824U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((aIndex + 18937U)) & S_BLOCK1], 11U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 21U)) + (RotL64(aPrevious, 47U) ^ RotL64(aCarry, 6U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterC = (aWandererH + RotL64(aCross, 28U)) + 16016931609704150191U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 19U)) + 14511433515861302636U;
            aOrbiterB = (aWandererC + RotL64(aIngress, 41U)) + 11691237442613269593U;
            aOrbiterF = (aWandererJ + RotL64(aScatter, 35U)) + 16383220587320484649U;
            aOrbiterH = (aWandererK + RotL64(aCross, 48U)) + 14293015313458219868U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 39U)) + 4407695248205526670U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 43U)) + 1158323195324398372U) + aNonceWordB;
            aOrbiterI = ((aWandererF + RotL64(aScatter, 37U)) + RotL64(aCarry, 41U)) + 6577683409653864555U;
            aOrbiterG = ((((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 51U)) + 171080079472863843U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 19U)) + 5766333425872228205U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 23U)) + 16173508656917582960U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 11781450063402219202U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 13033139686637576694U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 4331137994135472025U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 4006310759400926020U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 13156817947481574467U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 563189239835001483U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12791290558893516411U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 989729955679243234U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8757228712495095017U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 838379839663022790U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 2830743864262313606U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10173947177104802797U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 2146646527331684652U) + aNonceWordN;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4629168181742174906U;
            aOrbiterI = RotL64((aOrbiterI * 9046124907945045131U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1150129989168501777U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 619659995945229440U;
            aOrbiterG = RotL64((aOrbiterG * 13734821008174603409U), 21U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 8120315647582116952U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 13754584116324996165U;
            aOrbiterD = RotL64((aOrbiterD * 12295486140772079747U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 6084566798869999580U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5731665119233722504U;
            aOrbiterA = RotL64((aOrbiterA * 5921510209025133639U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16134513471149338456U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 9841695976256666234U;
            aOrbiterC = RotL64((aOrbiterC * 7417023101762286049U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 2559042046155066240U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 14065288635273112125U;
            aOrbiterJ = RotL64((aOrbiterJ * 10464173719695109147U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 18228257734024217020U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 16016931609704150191U;
            aOrbiterF = RotL64((aOrbiterF * 2874343578276710555U), 5U);
            //
            aIngress = RotL64(aOrbiterE, 42U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 51U));
            aIngress = aIngress + (RotL64(aOrbiterC, 19U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 41U) + aOrbiterF) + RotL64(aOrbiterD, 51U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 10U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 39U)) + aOrbiterI);
            aWandererD = aWandererD ^ ((((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 47U)) + aOrbiterE) + aNonceWordJ) + aPhaseEWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 35U)) + aOrbiterK) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 10U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 57U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 21U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterD, 37U));
            aWandererK = aWandererK + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterD, 4U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 57U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (RotL64(aWandererC, 46U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = aCarry ^ aNonceWordG;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 25519U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 25978U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordG;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26367U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 26261U)) & S_BLOCK1], 50U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 57U) + RotL64(aPrevious, 18U)) ^ (RotL64(aCross, 35U) ^ RotL64(aIngress, 5U));
            aScatter = aScatter ^ aNonceWordN;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterH = (aWandererC + RotL64(aPrevious, 60U)) + 12262991801139086177U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 35U)) + 7963038771924890197U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 23U)) + RotL64(aCarry, 53U)) + 15540520327933568896U) + aNonceWordF;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 39U)) + 8745565892055020722U) + aPhaseEOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aCross, 47U)) + 16619329199683755286U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 21U)) + 10865705026433867260U;
            aOrbiterK = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 35U)) + 2743368697984518059U;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 29U)) + 5556006271515473135U) + aNonceWordH;
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 6U)) + 5355833281353498588U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aWandererB + RotL64(aCross, 43U)) + RotL64(aCarry, 13U)) + 8313616108963479829U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 11U)) + 16657121016801866434U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 16532226425013000833U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5800465874932467232U;
            aOrbiterF = RotL64((aOrbiterF * 5966395771690704577U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 17882948163883121328U) + aNonceWordI;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 15029375310296563175U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17021415832288477713U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 10170682648007918739U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 11829089574189398773U;
            aOrbiterB = RotL64((aOrbiterB * 15755874363488568849U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 1746524867389196322U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 10217423427886742775U;
            aOrbiterD = RotL64((aOrbiterD * 9166162099575333519U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 1338457710729082656U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 1319981417675542556U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 9518448254565489715U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3985281993069194761U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7281264481139915593U;
            aOrbiterC = RotL64((aOrbiterC * 13498446162967276739U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 17394503335338855566U) + aNonceWordL;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1430703546991948227U;
            aOrbiterK = RotL64((aOrbiterK * 1623206122475721175U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 472559435062214929U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8065899137826178995U;
            aOrbiterG = RotL64((aOrbiterG * 13287499768933229539U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3377996409668333322U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 10456089146891981998U;
            aOrbiterI = RotL64((aOrbiterI * 12037044781049717633U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 5246784368779537905U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 8518987022368391332U;
            aOrbiterJ = RotL64((aOrbiterJ * 4046763804695058779U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 7791883487780325967U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12262991801139086177U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3409890579914160747U), 21U);
            //
            aIngress = RotL64(aOrbiterJ, 13U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterE, 34U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aCross, 18U) + RotL64(aOrbiterB, 3U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 37U) + RotL64(aOrbiterK, 21U)) + aOrbiterC) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 5U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 29U)) + aOrbiterB) + RotL64(aCarry, 51U)) + aNonceWordK);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 40U)) + aOrbiterI);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aPhaseEWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterA, 37U)) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 58U) + RotL64(aOrbiterA, 13U)) + aOrbiterK);
            aWandererG = aWandererG + ((RotL64(aScatter, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 11U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterD, 44U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + RotL64(aWandererB, 6U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordI;
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 30111U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 28021U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseEDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordC;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30153U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28490U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseEDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 34U)) + (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U));
            aScatter = aScatter ^ aNonceWordF;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseEDomainWordScatter));
            //
            aOrbiterG = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 29U)) + 8101351470141807662U;
            aOrbiterE = (aWandererH + RotL64(aCross, 60U)) + 6965474099521076705U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 11U)) + 6803828268885684784U) + aPhaseEOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 3U)) + 13454235922950972488U;
            aOrbiterH = (aWandererJ + RotL64(aCross, 41U)) + 11678091885751244777U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 43U)) + 5307134544628507141U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 37U)) + RotL64(aCarry, 53U)) + 4873703518950429353U;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 5U)) + 8542156221858586039U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererK + RotL64(aCross, 19U)) + 3993726182905296513U) + aNonceWordE;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 13U)) + 12113047622035464386U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 46U)) + 1944244448665721151U) + aNonceWordB;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 12914188029425467576U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 2486762763475327024U;
            aOrbiterC = RotL64((aOrbiterC * 12319769994433811617U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 14580191602982245481U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 12093414832400135066U;
            aOrbiterH = RotL64((aOrbiterH * 12720286833215690663U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 13623906997320021065U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 9977356009806428696U;
            aOrbiterF = RotL64((aOrbiterF * 2005536391712733499U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3694954095397810851U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11453812627797091638U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13730420725113907161U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 542311345544726351U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 3024285045990499484U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 5153745952148205645U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15397664082460849530U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 10716856680110815056U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13947203772929252823U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 833342121331428547U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1111339940097269219U;
            aOrbiterK = RotL64((aOrbiterK * 17991642769781175473U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9312963978841402871U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8225496710723213204U;
            aOrbiterI = RotL64((aOrbiterI * 894499195498817065U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7947419530949269753U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 5028446114139808517U;
            aOrbiterG = RotL64((aOrbiterG * 5593084899736787263U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 9818957208200746975U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 17549192719666647522U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4705007748877441833U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 16389708540378477737U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8101351470141807662U;
            aOrbiterJ = RotL64((aOrbiterJ * 9858235486537441981U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 5U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterI, 52U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 47U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterH, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 46U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 23U) + aOrbiterK) + RotL64(aOrbiterH, 3U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 14U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterG, 39U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 44U) + RotL64(aOrbiterG, 37U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterH, 19U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterK, 35U));
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + RotL64(aCarry, 13U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + aOrbiterE) + RotL64(aOrbiterK, 12U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 53U) + aOrbiterJ) + RotL64(aOrbiterA, 41U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererI);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 6U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 39U));
            aCarry = aCarry + RotL64(aWandererK, 60U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordO;
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

void TwistExpander_Softball_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xF01AB55030200FF1ULL + 0x8DAB863DD85E9017ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xB4A6B808CEC898D1ULL + 0xAD44FB4E18603460ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA10B4BD2F5293C9DULL + 0x916E34D4AED85FADULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xDC300CD64AC729A7ULL + 0xCAE486D3A599FD2AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xE18FDB2455F77415ULL + 0xD4133D607EB0BD1AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x9262A6D8D9E36DD3ULL + 0xA2DCAEFC1E04547AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF0E5E0622C9D0B4BULL + 0xCF0B0193D6795515ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xF0C411FB330C6C75ULL + 0xB797A574BC603414ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xE608FE2F5E0FEB47ULL + 0xA732CEE121C78E46ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xF6E83D94329E41CFULL + 0xD687853079494C60ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF8A4179759D21F11ULL + 0x87976FD6A59B3C55ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8A417543989E56DDULL + 0xE48697C8BE7EBEEFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x8B6B6DEEEA2FBD3BULL + 0xD37567710ED1C92BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xAD39FF5148CDE1DBULL + 0x8C380F62D13C9F4FULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x98BE101BDA55B22FULL + 0xD0AE75248537B6A4ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x93CF4B815E7197A1ULL + 0xF6939A771F0014E5ULL);
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
            aIngress = aIngress ^ aNonceWordB;
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 3341U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3739U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 1580U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 2919U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 58U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 23U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 42U)) + 12027839670755583592U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 15380130703509859843U;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 19U)) + 4590907433867798074U) + aNonceWordG;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 39U)) + 1754574023602519724U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 46U)) + 9832756659564903767U;
            aOrbiterK = ((((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 5035088494491470403U) + aPhaseFOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 53U)) + 14199170923323644638U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aWandererK + RotL64(aPrevious, 27U)) + 8325619421264440438U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 21U)) + 969534320779067977U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 51U)) + 270575869402913847U;
            aOrbiterJ = (aWandererD + RotL64(aIngress, 3U)) + 13344806516599578910U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15143147951139409101U) + aNonceWordM;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 14425582489214169238U;
            aOrbiterI = RotL64((aOrbiterI * 16893787086337916355U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 13951127523239064584U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14177925225918293579U;
            aOrbiterK = RotL64((aOrbiterK * 13079514031864998485U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 8258920744278218901U) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 7408161179397242453U;
            aOrbiterD = RotL64((aOrbiterD * 975737128100519169U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 8581481606764773468U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10078416198417433133U;
            aOrbiterB = RotL64((aOrbiterB * 1102721083915858247U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 18299772198826189580U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18304668908084397946U;
            aOrbiterA = RotL64((aOrbiterA * 10589455451200578687U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 16729632621573817223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13362300981585573239U;
            aOrbiterG = RotL64((aOrbiterG * 9824473895535518785U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8629682832849915380U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 6852852009091469641U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11912646687050011915U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 7433098156961745198U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 10931806208899417308U;
            aOrbiterH = RotL64((aOrbiterH * 14699197041038067483U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 629604718211675247U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 1487372736719237118U;
            aOrbiterF = RotL64((aOrbiterF * 705192821277928909U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3567439893461603384U) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 11143068753134694333U;
            aOrbiterE = RotL64((aOrbiterE * 15529326960229305389U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 14242098279913980463U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 12027839670755583592U;
            aOrbiterC = RotL64((aOrbiterC * 6630014752150544153U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 27U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 58U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aScatter, 24U) + RotL64(aOrbiterI, 57U)) + aOrbiterK);
            aWandererA = aWandererA + (((RotL64(aPrevious, 51U) + aOrbiterH) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterF) + aNonceWordK) + aPhaseFWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterA, 27U)) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 21U) + aOrbiterE) + RotL64(aOrbiterI, 10U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterB, 19U)) + aOrbiterG);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + aOrbiterC) + RotL64(aOrbiterK, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterE);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 23U)) + aOrbiterK);
            aWandererE = aWandererE + ((RotL64(aScatter, 58U) + aOrbiterH) + RotL64(aOrbiterG, 5U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterH, 54U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 29U));
            aCarry = aCarry + (RotL64(aWandererA, 38U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = aCarry ^ (aNonceWordD ^ aNonceWordN);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ aNonceWordD;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 5465U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9979U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 6671U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneB[((aIndex + 10541U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCross, 50U) + RotL64(aPrevious, 5U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterJ = (aWandererK + RotL64(aScatter, 3U)) + 10404808878585437255U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 6U)) + 10587858736301591439U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 43U)) + 1430530909801644435U;
            aOrbiterH = (aWandererF + RotL64(aCross, 21U)) + 9090938022430118902U;
            aOrbiterA = ((aWandererI + RotL64(aScatter, 13U)) + 12936604311751121235U) + aNonceWordI;
            aOrbiterC = (aWandererD + RotL64(aIngress, 27U)) + 1000583006020232032U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 51U)) + 12352532088997042232U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterG = (aWandererC + RotL64(aCross, 29U)) + 16723410947058502564U;
            aOrbiterI = (((aWandererG + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 16614089235313154270U) + aPhaseFOrbiterAssignSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 35U)) + 4245553025593349277U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 60U)) + RotL64(aCarry, 57U)) + 3353146318549477494U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 5935727336135635196U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 10312187090293319667U;
            aOrbiterD = RotL64((aOrbiterD * 1395964500396711899U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 12192843181244744484U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2542570124502586365U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17222847847573534963U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 3315472769469002444U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 17512858811783071174U;
            aOrbiterA = RotL64((aOrbiterA * 9070400454074283765U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 16633218007427888082U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2502077714838858460U;
            aOrbiterK = RotL64((aOrbiterK * 970762420815997725U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 14792910273226469214U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 15739513291150783151U;
            aOrbiterI = RotL64((aOrbiterI * 11896279674116906915U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2192903544350345992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 844428341223009295U;
            aOrbiterJ = RotL64((aOrbiterJ * 4768368713974002539U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 2998511458298901402U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 7790789639864783373U;
            aOrbiterH = RotL64((aOrbiterH * 9173097618440495497U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4540735375055164995U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13700342877362633034U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14730797752841670505U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 16966725424259324323U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 5945539295893015935U) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 12226268057062268981U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12560355243513521281U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2104086086480258265U;
            aOrbiterB = RotL64((aOrbiterB * 17989755118752755577U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 4476697099257280568U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 10404808878585437255U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6245415417832089357U), 13U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterJ, 18U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aPrevious, 60U) + RotL64(aOrbiterD, 29U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 11U)) + aOrbiterG) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterK, 23U)) + aNonceWordG);
            aWandererE = aWandererE + ((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterI, 53U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 60U)) + aOrbiterJ);
            aWandererG = aWandererG + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterH, 5U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 43U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterG, 48U));
            aWandererF = aWandererF + ((RotL64(aCross, 26U) + aOrbiterC) + RotL64(aOrbiterE, 19U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 30U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 18U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordA;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 13748U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 14640U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordF;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16071U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 14747U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 53U)) + (RotL64(aIngress, 24U) ^ RotL64(aCarry, 41U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 42U)) + RotL64(aCarry, 41U)) + 5697928251815176134U) + aNonceWordJ;
            aOrbiterC = (aWandererA + RotL64(aScatter, 47U)) + 337587740689259575U;
            aOrbiterK = (aWandererG + RotL64(aIngress, 39U)) + 4927686903263973950U;
            aOrbiterH = ((aWandererF + RotL64(aCross, 5U)) + RotL64(aCarry, 19U)) + 3742409032569801033U;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 54U)) + 1608092659172197650U;
            aOrbiterG = (aWandererH + RotL64(aCross, 51U)) + 15848744267145717509U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 15300174177963339253U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 37U)) + 14162868453323648628U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 19U)) + 12020167069983729869U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aScatter, 13U)) + 16259538291658723956U) + aNonceWordC;
            aOrbiterF = (aWandererD + RotL64(aIngress, 21U)) + 8516686212464112245U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 3722184575520553132U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 5663609293306386784U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14364218128780764749U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 15265344442454471986U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3050323350098829515U;
            aOrbiterG = RotL64((aOrbiterG * 5890624677162388135U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 1093356813820599238U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 15167726103772238440U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5719466863561311069U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15170797965325981472U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17826286701992981628U;
            aOrbiterD = RotL64((aOrbiterD * 11186808881726573677U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 14710892030473425181U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 397194787697553904U;
            aOrbiterB = RotL64((aOrbiterB * 14368930300818752833U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1273724124862533034U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 13018397560392545616U;
            aOrbiterI = RotL64((aOrbiterI * 4644812473262395329U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 9638716186445643730U) + aNonceWordO;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 7255587739807843785U;
            aOrbiterA = RotL64((aOrbiterA * 6055682981584011189U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9272350563697399628U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 1040729335295009339U;
            aOrbiterH = RotL64((aOrbiterH * 17825687660830291443U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 12128124729613601747U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2285238815562202219U;
            aOrbiterE = RotL64((aOrbiterE * 15398840993074390573U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 6339113298619163493U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 5911895708485037040U;
            aOrbiterJ = RotL64((aOrbiterJ * 3271006139923200439U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7601399508218901328U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5697928251815176134U;
            aOrbiterF = RotL64((aOrbiterF * 8184257916861355735U), 19U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 39U);
            aIngress = aIngress + (RotL64(aOrbiterF, 18U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 60U)) + aOrbiterF);
            aWandererD = aWandererD + ((RotL64(aScatter, 18U) + aOrbiterB) + RotL64(aOrbiterK, 43U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterI, 27U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 41U) + aOrbiterH) + RotL64(aOrbiterK, 35U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 53U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + RotL64(aOrbiterI, 56U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterA, 3U));
            aWandererF = aWandererF + ((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterC, 11U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterC, 29U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterG, 39U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordM) + aPhaseFWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterC, 37U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 13U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = aCarry ^ (aNonceWordA ^ aNonceWordK);
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
            aIngress = aIngress ^ aNonceWordC;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17188U)) & S_BLOCK1], 4U) ^ RotL64(aWorkLaneB[((aIndex + 20002U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16810U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((aIndex + 20420U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 56U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 39U));
            aScatter = aScatter ^ aNonceWordB;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterI = (aWandererH + RotL64(aPrevious, 43U)) + 7825479804710770560U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 19U)) + 5298124167101358123U;
            aOrbiterE = (aWandererC + RotL64(aCross, 37U)) + 17774541024369233726U;
            aOrbiterJ = ((((aWandererD + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 7679371833537454082U) + aPhaseFOrbiterAssignSaltC[((aIndex + 4U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (((aWandererB + RotL64(aIngress, 22U)) + RotL64(aCarry, 39U)) + 5385914900748772224U) + aNonceWordH;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 5U)) + 3879781930908486531U) + aNonceWordF;
            aOrbiterG = (aWandererK + RotL64(aScatter, 39U)) + 659110346638873236U;
            aOrbiterB = (aWandererA + RotL64(aCross, 29U)) + 10749021728538539749U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 3U)) + 3631252455767429457U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterF = (aWandererF + RotL64(aIngress, 26U)) + 2271978810960685021U;
            aOrbiterA = (aWandererG + RotL64(aCross, 57U)) + 5963558780692551176U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 974909966119198104U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 9296998242911152296U;
            aOrbiterE = RotL64((aOrbiterE * 2613629915877957661U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 2245318466901521959U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13391076374843288568U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18094558036982107419U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6184487746594236737U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 1563385912137291418U;
            aOrbiterC = RotL64((aOrbiterC * 4805455299959232321U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 1744840092006498629U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 2100927276837188416U;
            aOrbiterG = RotL64((aOrbiterG * 3541788262067077997U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 9998911862807246338U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 12239948725635220096U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 7098620484129489129U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 3307447094994950246U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 12746613971448298932U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9463975886346934681U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11577488293733790649U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 191108997585598809U;
            aOrbiterF = RotL64((aOrbiterF * 9574978681405356871U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18096145693841273722U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 10026281133603934071U;
            aOrbiterA = RotL64((aOrbiterA * 17261343107314203471U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2346682418062064668U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2996178204018644206U;
            aOrbiterI = RotL64((aOrbiterI * 2552965800703390909U), 19U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterA) + 15085425896818988223U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 1589593231782852588U) ^ aNonceWordD;
            aOrbiterH = RotL64((aOrbiterH * 1535556765195388675U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17170695588248383518U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 7825479804710770560U;
            aOrbiterJ = RotL64((aOrbiterJ * 7434218282170150533U), 51U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterB, 39U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 27U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 48U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 41U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterB, 37U)) + aOrbiterJ) + aNonceWordP);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + aOrbiterK) + RotL64(aOrbiterI, 4U)) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 23U) + aOrbiterF) + RotL64(aOrbiterA, 13U)) + aPhaseFWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 10U) + aOrbiterD) + RotL64(aOrbiterE, 29U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 23U)) + aOrbiterC);
            aWandererH = aWandererH + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 54U)) + aOrbiterC) + aNonceWordI) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterD);
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 26U) + aOrbiterG) + RotL64(aOrbiterA, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 37U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 5U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererI, 28U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordJ;
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
            aIngress = aIngress ^ aNonceWordP;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 25566U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 26179U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordD;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24542U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23578U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 54U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 3U) + RotL64(aPrevious, 19U));
            aScatter = aScatter ^ aNonceWordA;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 37U)) + 17081642665820489793U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (((aWandererB + RotL64(aCross, 34U)) + RotL64(aCarry, 47U)) + 14468854040067229623U) + aNonceWordH;
            aOrbiterJ = (aWandererA + RotL64(aIngress, 21U)) + 2249450222593057429U;
            aOrbiterD = (aWandererG + RotL64(aPrevious, 11U)) + 14964389079511378664U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 39U)) + 17003491054252360650U) + aNonceWordI;
            aOrbiterC = (aWandererI + RotL64(aPrevious, 47U)) + 12710882240582032588U;
            aOrbiterA = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 9887078182156755359U;
            aOrbiterB = (aWandererJ + RotL64(aScatter, 43U)) + 7665284531810584704U;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 23U)) + RotL64(aCarry, 53U)) + 7304284015511876717U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 51U)) + 5517927023543751734U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 60U)) + 17704756310857362759U) + aPhaseFOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 11347400363019508578U) + aNonceWordE;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11696395232760991243U;
            aOrbiterJ = RotL64((aOrbiterJ * 9725231749679442003U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 10875780291242873583U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7808740614343437672U;
            aOrbiterC = RotL64((aOrbiterC * 8889516201913716283U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 3145390996141902032U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 16080636485642732615U;
            aOrbiterB = RotL64((aOrbiterB * 7445756373012217305U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 3929263288176983844U) + aNonceWordN;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 18210228766683996806U;
            aOrbiterF = RotL64((aOrbiterF * 13178080076505449091U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13948962323541421431U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3037683309790156893U;
            aOrbiterH = RotL64((aOrbiterH * 13406672352222636739U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17827265198532699474U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7270895262023504864U;
            aOrbiterD = RotL64((aOrbiterD * 13467417362477308167U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6431243064980879185U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 6680205390976259885U;
            aOrbiterA = RotL64((aOrbiterA * 10421386694108590789U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15910655919164357152U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 8046213498216027383U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18061867495824063553U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2521111689480478597U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 13892876610454681741U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17776392934374483875U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16009217514890880809U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 1221573458193626679U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 73477765605619369U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9275704218554025797U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17081642665820489793U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 5613316790159527375U), 41U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 23U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 34U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterI, 13U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 58U) + aOrbiterI) + RotL64(aOrbiterD, 27U));
            aWandererH = aWandererH + ((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 39U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 19U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterJ, 30U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + aPhaseFWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 42U) + RotL64(aOrbiterD, 53U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 37U)) + aOrbiterF) + aNonceWordG);
            aWandererI = aWandererI + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterD, 34U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 42U));
            aCarry = aCarry + RotL64(aWandererK, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = aCarry ^ (aNonceWordI ^ aNonceWordB);
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
            aIngress = aIngress ^ aNonceWordE;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30901U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((aIndex + 32531U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordI;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30576U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneB[((aIndex + 31226U)) & S_BLOCK1], 28U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCarry, 11U)) + (RotL64(aIngress, 23U) ^ RotL64(aCross, 58U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterK = (aWandererA + RotL64(aPrevious, 51U)) + 964165145848253292U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 57U)) + 10645976767204934746U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aIngress, 13U)) + 8241612229349212650U) + aNonceWordA;
            aOrbiterE = (aWandererG + RotL64(aCross, 35U)) + 4159196033256913347U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 48U)) + 7194795864620233507U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 21U)) + 7638928444536778384U) + aNonceWordF;
            aOrbiterG = ((aWandererK + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 11819105916503968109U;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 3U)) + 18052213302858186237U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 10U)) + 8663575313970041570U) + aNonceWordL;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 5U)) + 16644136720439299786U) + aPhaseFOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = ((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 13U)) + 16930316530442679864U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 16251107616988250593U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 7171986193609401665U;
            aOrbiterC = RotL64((aOrbiterC * 3543709971414550087U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17885046834432626644U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7757069274715713557U;
            aOrbiterI = RotL64((aOrbiterI * 15766885299397923879U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 2212805322061155615U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 6368539134638838822U;
            aOrbiterD = RotL64((aOrbiterD * 13383744883433594259U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 5264326094252925613U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6126345334815012938U;
            aOrbiterG = RotL64((aOrbiterG * 17180934809764905307U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 13826731214018407061U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 6621261811613643620U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 2823596473596114171U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 5964406317285863781U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 2167324450276308078U;
            aOrbiterF = RotL64((aOrbiterF * 1098346374733634905U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 16740710162977859724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8236083581048717923U;
            aOrbiterB = RotL64((aOrbiterB * 4364887787000704039U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 13967473987446124012U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5136051802217149813U) ^ aNonceWordO;
            aOrbiterH = RotL64((aOrbiterH * 13997246005108872883U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 5842999397215390366U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 8621394946580065499U;
            aOrbiterK = RotL64((aOrbiterK * 11658023035736362355U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 18086875424872976900U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7429246355923896047U;
            aOrbiterJ = RotL64((aOrbiterJ * 5077079237334961761U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 18123753993386959014U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 964165145848253292U;
            aOrbiterE = RotL64((aOrbiterE * 3178072569980307307U), 13U);
            //
            aIngress = RotL64(aOrbiterD, 6U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 51U));
            aIngress = aIngress + RotL64(aOrbiterA, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + RotL64(aCarry, 43U)) + aNonceWordB);
            aWandererI = aWandererI ^ ((RotL64(aCross, 52U) + aOrbiterG) + RotL64(aOrbiterC, 41U));
            aWandererA = aWandererA + ((RotL64(aPrevious, 39U) + aOrbiterG) + RotL64(aOrbiterE, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 12U));
            aWandererB = aWandererB + ((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterG, 37U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 5U) + RotL64(aOrbiterF, 5U)) + aOrbiterG) + aNonceWordJ) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 3U)) + aOrbiterB) + aNonceWordM);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterK, 18U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 23U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 51U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 39U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 26U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordJ ^ aNonceWordK);
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

void TwistExpander_Softball_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xCB6EAD6B91A56F53ULL + 0x85D4D229B9DD3723ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xA386AF5D6FA0D487ULL + 0xA1B8B2584672114EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB96FB4E31865B7FBULL + 0x902982DC4F30F385ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x82F58BF5EF031491ULL + 0xD8618950DFB07204ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB7C7ADB2F3945987ULL + 0x9C99856E2100733BULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xEB5DA6350A4AAC1DULL + 0xE6E260D39AE7F41BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xECD5A4F50227B51BULL + 0x8FE309B367246617ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xE2F9BC8DC6A15FEBULL + 0x9C5C27F7F2D1CFC0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFBED4F631B389ED5ULL + 0xDC128E4407F2DFCFULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x9F28418BCB904C95ULL + 0xF60FC0DBA6EE0314ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x81AD8094702D40C5ULL + 0xA0C2221D234390ACULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCC33966BDCA1774FULL + 0x8CEDD553CD53E28DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x95E5B807546539E9ULL + 0xD7F1EB875C6A7BE6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF5458471ED8B1643ULL + 0xF81ACE41D318DAEAULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x80F7FD8C4A8D7B93ULL + 0xE1274E69FD5B280EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xAF2D9C9E24235F73ULL + 0xFFB3FD41149E3F30ULL);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 4938U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3033U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordO;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5329U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 3005U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 18U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 3U));
            aScatter = aScatter ^ aNonceWordK;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterF = (aWandererC + RotL64(aCross, 27U)) + 10915618884692072446U;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 11U)) + 12634922308499254909U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 51U)) + 6533934734564499389U) + aNonceWordE;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 6744203303756105181U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 41U)) + 13086782386652045658U) + aNonceWordP;
            aOrbiterI = (aWandererI + RotL64(aScatter, 18U)) + 5693840533331397822U;
            aOrbiterE = (aWandererJ + RotL64(aCross, 47U)) + 1803663542535024611U;
            aOrbiterD = ((((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 43U)) + 3597219300593287708U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordF;
            aOrbiterB = (aWandererB + RotL64(aCross, 39U)) + 1429753448204448904U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 53U)) + 17229017825587322715U;
            aOrbiterC = (((aWandererF + RotL64(aPrevious, 56U)) + RotL64(aCarry, 53U)) + 1137574712801062932U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2401991077004083378U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1332473247826139292U;
            aOrbiterA = RotL64((aOrbiterA * 15029831858261506447U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 11730946340796899885U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 15319163439700390962U;
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4744141870145159917U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterE) ^ 6067132201862688684U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 6046100687757836027U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14991509179286371800U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4342608825699398682U;
            aOrbiterG = RotL64((aOrbiterG * 10240526103933275875U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3727521409410742075U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 3302027219498304367U;
            aOrbiterE = RotL64((aOrbiterE * 12153634588200479559U), 37U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6039539483340398858U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2902581519976937051U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2057584328877854239U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 12332784713738947242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 13761272577223712786U;
            aOrbiterC = RotL64((aOrbiterC * 14930145045480030821U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 2947946397617043735U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 11107014023853644521U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15030903626191481831U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6212403196992771516U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 16107261731677426470U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 13764822942405295129U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8414111492161335472U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3625937496991123221U;
            aOrbiterD = RotL64((aOrbiterD * 1736741235159600739U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5466667339391480293U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 10915618884692072446U;
            aOrbiterJ = RotL64((aOrbiterJ * 14719282928172086707U), 5U);
            //
            aIngress = RotL64(aOrbiterJ, 44U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (RotL64(aOrbiterI, 41U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterG, 51U));
            aWandererE = aWandererE + ((((RotL64(aIngress, 54U) + aOrbiterA) + RotL64(aOrbiterE, 27U)) + RotL64(aCarry, 11U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterI, 10U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterK, 21U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 41U)) + aOrbiterJ);
            aWandererH = aWandererH + ((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterD, 39U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 29U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterE) + RotL64(aOrbiterC, 24U));
            aWandererC = aWandererC + ((RotL64(aIngress, 52U) + RotL64(aOrbiterH, 19U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 29U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 57U));
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 6U);
            aCarry = aCarry ^ aNonceWordF;
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
            aIngress = aIngress ^ aNonceWordA;
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 10674U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneD[((aIndex + 8846U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 7337U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 8115U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 53U)) ^ (RotL64(aPrevious, 38U) ^ RotL64(aCarry, 23U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseC((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = (((aWandererH + RotL64(aCross, 53U)) + RotL64(aCarry, 43U)) + 13350544654542863236U) + aNonceWordF;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 6U)) + RotL64(aCarry, 21U)) + 12364346790125404372U;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 57U)) + 9738750172849512764U) + aNonceWordL;
            aOrbiterC = (aWandererD + RotL64(aIngress, 11U)) + 3781373837635491421U;
            aOrbiterH = (aWandererE + RotL64(aCross, 27U)) + 16635020317512702337U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 37U)) + 5383653921676231276U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 57U)) + 10181959815492056493U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 35U)) + 10005510924273927017U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 21U)) + 9524687662265740565U) + aNonceWordG;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 4U)) + 4259138552009771014U) + aPhaseFOrbiterAssignSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 47U)) + 8973051213213726023U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 17602611840127337490U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8218984546932905269U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17504305273683304231U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 18102186122213487888U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 2629927500298092976U;
            aOrbiterE = RotL64((aOrbiterE * 6983280164448292723U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2491581597835795234U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9506602492971620955U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9559829640915637163U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 13422942713680612924U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15037354693234876601U;
            aOrbiterB = RotL64((aOrbiterB * 12692376075738621447U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12896066842192894694U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 2202952306291905855U;
            aOrbiterJ = RotL64((aOrbiterJ * 6779368532763429997U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12160313482450599313U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 10812986281270407756U;
            aOrbiterA = RotL64((aOrbiterA * 7786608700746771809U), 39U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 12474638293190144525U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5882870951276225224U;
            aOrbiterC = RotL64((aOrbiterC * 15532427302173572457U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3782896138051179209U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 10965680631059882311U;
            aOrbiterG = RotL64((aOrbiterG * 14060923998307082385U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15650420683333746952U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 4110674660963676864U;
            aOrbiterK = RotL64((aOrbiterK * 11724979274890265275U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 694817156953099464U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4402927404825116007U;
            aOrbiterF = RotL64((aOrbiterF * 579586789292520113U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 6849178151532923489U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13350544654542863236U;
            aOrbiterI = RotL64((aOrbiterI * 2416097748778941523U), 11U);
            //
            aIngress = RotL64(aOrbiterD, 3U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 43U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 58U));
            aIngress = aIngress + (RotL64(aOrbiterI, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 26U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 47U)) + aOrbiterE) + aNonceWordB);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 39U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 11U)) + aOrbiterD);
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterD, 19U)) + aNonceWordE) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterA, 44U)) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterI, 5U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + RotL64(aCarry, 47U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 50U) + aOrbiterE) + RotL64(aOrbiterH, 57U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterB, 42U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = aCarry ^ (aNonceWordE ^ aNonceWordF);
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
            aIngress = aIngress ^ aNonceWordF;
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 12658U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 11512U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordE;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 15891U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 14059U)) & S_BLOCK1], 22U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCross, 41U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 29U));
            aScatter = aScatter ^ aNonceWordJ;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererE + RotL64(aPrevious, 13U)) + 966899917801652720U;
            aOrbiterF = (((aWandererK + RotL64(aIngress, 39U)) + 10996327672320748649U) + aPhaseFOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aWandererC + RotL64(aCross, 24U)) + 4188171566846621107U;
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 5886209243097387959U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aIngress, 43U)) + 14940428957136728111U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 3U)) + 179187285531914832U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 27U)) + 6685351948936817752U;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 58U)) + 1894506461704029700U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 41U)) + 4182760368636977082U;
            aOrbiterH = (aWandererF + RotL64(aCross, 51U)) + 12523318028514940790U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 43U)) + 5059306166973366892U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 5890872367917643851U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 17747338389865221534U;
            aOrbiterC = RotL64((aOrbiterC * 5306740664798049267U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13906227834259884100U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7152105382899756368U;
            aOrbiterK = RotL64((aOrbiterK * 6772157117358310485U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 17868101884759619240U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11758843266314148347U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5919135169337501485U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 13950566197090324859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 17278105609930477854U;
            aOrbiterA = RotL64((aOrbiterA * 11431842718945107359U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 9556785965646738355U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 841298436857932987U;
            aOrbiterI = RotL64((aOrbiterI * 15077843186688841797U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 1951515285492133830U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 15775839819330588437U;
            aOrbiterH = RotL64((aOrbiterH * 7902654031401620995U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 5585458468816495436U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 17258586689032223623U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1652050227399194271U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5254132659445988836U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 15440741734777060925U;
            aOrbiterJ = RotL64((aOrbiterJ * 17445581079035134067U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16770361602586485631U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14902616717976301965U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7757713071544143453U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 9521517757370835715U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 18241677917767801049U;
            aOrbiterD = RotL64((aOrbiterD * 16977396965907931057U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14307634663160859644U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 966899917801652720U;
            aOrbiterG = RotL64((aOrbiterG * 17012361848398765251U), 43U);
            //
            aIngress = RotL64(aOrbiterB, 39U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 34U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + (RotL64(aOrbiterH, 29U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterE) + RotL64(aOrbiterG, 39U));
            aWandererA = aWandererA + (((RotL64(aCross, 50U) + RotL64(aOrbiterB, 41U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterH, 4U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 21U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + aPhaseFWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterK, 19U)) + aOrbiterD) + RotL64(aCarry, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 37U)) + aOrbiterE);
            aWandererF = aWandererF + ((RotL64(aCross, 35U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterD, 57U)) + aNonceWordN);
            aWandererD = aWandererD + ((RotL64(aCross, 46U) + aOrbiterA) + RotL64(aOrbiterE, 34U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterK) + RotL64(aOrbiterJ, 13U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 46U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 28U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 21U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ aNonceWordN;
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
            aIngress = aIngress ^ aNonceWordM;
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 17054U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16962U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordK;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 17070U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 21416U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseB((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 11U) + RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 23U));
            aScatter = aScatter ^ aNonceWordG;
            aScatter = TwistMix64::DiffuseA((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterG = (aWandererB + RotL64(aCross, 35U)) + 10805654776556844351U;
            aOrbiterK = ((aWandererE + RotL64(aPrevious, 3U)) + RotL64(aCarry, 5U)) + 582794182442795335U;
            aOrbiterE = (((aWandererI + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 2858343650974681068U) + aNonceWordF;
            aOrbiterH = (aWandererG + RotL64(aScatter, 23U)) + 8189584049022064284U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 27U)) + 1565100751996962893U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 19U)) + 8062028016947611891U;
            aOrbiterD = (aWandererA + RotL64(aPrevious, 46U)) + 8280504280578451745U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 5U)) + 11326869194491655350U) + aNonceWordB;
            aOrbiterI = (aWandererC + RotL64(aPrevious, 39U)) + 1671695656567777163U;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 37U)) + 2349843105293943452U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererJ + RotL64(aCross, 50U)) + 13015545152052004254U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16703354404749291869U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 8713231044374305801U;
            aOrbiterE = RotL64((aOrbiterE * 9242480982197688625U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 11118401674497783533U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 14857556493734710364U;
            aOrbiterA = RotL64((aOrbiterA * 3452566050389715195U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 12953419670951660965U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12666121730825089017U;
            aOrbiterF = RotL64((aOrbiterF * 14049925256934142519U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11075249639473053423U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9374217688244187867U;
            aOrbiterD = RotL64((aOrbiterD * 5261156325627117877U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 17608340953291367867U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13159437499327086340U;
            aOrbiterB = RotL64((aOrbiterB * 4882100944453534805U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4304700511322366815U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 10172544755256706767U;
            aOrbiterI = RotL64((aOrbiterI * 4013006212154771797U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 17340067939877432472U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 14130447570008179105U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8178075071208718915U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 2652532710498072378U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 10384945384238518296U;
            aOrbiterJ = RotL64((aOrbiterJ * 17137694272394304045U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15292159041119433363U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12103644911645285108U;
            aOrbiterG = RotL64((aOrbiterG * 4565615406415614103U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16307525158627275744U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3786908390177579447U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6592585847755318801U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13595883419843505634U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 10805654776556844351U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10956465099104915639U), 51U);
            //
            aIngress = RotL64(aOrbiterE, 34U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (RotL64(aOrbiterK, 29U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterH, 56U));
            aWandererH = aWandererH + ((RotL64(aIngress, 30U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererC = aWandererC ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + aOrbiterJ) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 5U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterB, 21U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 6U) + aOrbiterI) + RotL64(aOrbiterE, 43U));
            aWandererE = aWandererE + ((((RotL64(aCross, 57U) + RotL64(aOrbiterC, 29U)) + aOrbiterA) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 41U)) + aOrbiterG);
            aWandererG = aWandererG + ((((RotL64(aIngress, 51U) + aOrbiterC) + RotL64(aOrbiterD, 37U)) + aNonceWordD) + aPhaseFWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 46U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 60U));
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = aCarry ^ aNonceWordI;
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
            aIngress = aIngress ^ aNonceWordK;
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 23404U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 22070U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26156U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneA[((aIndex + 24752U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aCarry, 37U) + RotL64(aIngress, 53U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 6U));
            aScatter = aScatter ^ aNonceWordH;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterB = (aWandererG + RotL64(aPrevious, 18U)) + 5960680319644404115U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 57U)) + 16050752633567034185U;
            aOrbiterC = (aWandererC + RotL64(aCross, 37U)) + 8447503223226854741U;
            aOrbiterD = (aWandererB + RotL64(aScatter, 21U)) + 14176813813397917591U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 39U)) + 10534915376130006644U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 47U)) + RotL64(aCarry, 11U)) + 6866224454375302514U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 35U)) + 16506374165041008396U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 4U)) + RotL64(aCarry, 19U)) + 7167814023968794098U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 27U)) + 13870852197416596664U;
            aOrbiterF = ((((aWandererH + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 18064038854848993105U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aWandererA + RotL64(aCross, 23U)) + 9869630811507771691U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 863613100452759380U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 16597969741225436529U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 2680793528887208903U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 6575347108051310653U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17062262265485019063U;
            aOrbiterK = RotL64((aOrbiterK * 7601045488473620019U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7193399224636409133U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14146747818810433849U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5273185769989530041U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 9441449106442431427U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4303295336545399503U;
            aOrbiterF = RotL64((aOrbiterF * 8829695296836242587U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12604760768543193458U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 15779327512379787715U;
            aOrbiterB = RotL64((aOrbiterB * 14000905201441272597U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15553000781122708728U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 17162740616060079717U;
            aOrbiterD = RotL64((aOrbiterD * 9458662233556750239U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1032374679817715156U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 16413393156165548232U;
            aOrbiterJ = RotL64((aOrbiterJ * 549659738811935015U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14056855000013992045U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7399202019042538829U;
            aOrbiterG = RotL64((aOrbiterG * 6103508549612077695U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2218389473339103389U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 4679497280975967770U;
            aOrbiterE = RotL64((aOrbiterE * 9228353578259815023U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7620538119914173747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 3118355627808424159U;
            aOrbiterH = RotL64((aOrbiterH * 12481319980496032783U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16787092219237931175U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5960680319644404115U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 10727217147056112401U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 23U)) + aOrbiterD);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 46U) + RotL64(aOrbiterH, 47U)) + aOrbiterE) + aPhaseFWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 41U)) + aOrbiterE) + aNonceWordE);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA);
            aWandererG = aWandererG + ((RotL64(aScatter, 37U) + RotL64(aOrbiterG, 11U)) + aOrbiterJ);
            aWandererH = aWandererH ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterK, 44U)) + aOrbiterG) + aPhaseFWandererUpdateSaltE[((aIndex + 11U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterF, 37U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aNonceWordB);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 44U) + aOrbiterD) + RotL64(aOrbiterE, 53U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterC, 5U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 39U) + aOrbiterH) + RotL64(aOrbiterJ, 58U));
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + RotL64(aCarry, 47U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (RotL64(aWandererC, 34U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 18U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = aCarry ^ (aNonceWordK ^ aNonceWordE);
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
            aIngress = aIngress ^ aNonceWordO;
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 32383U)) & S_BLOCK1], 28U) ^ RotL64(aExpandLaneB[((aIndex + 30202U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC((aIngress ^ aPhaseFDomainWordIngress));
            //
            aCross = 0U;
            aCross = aCross ^ aNonceWordA;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 30778U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((aIndex + 29171U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseC((aCross ^ aPhaseFDomainWordCross));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 4U) ^ RotL64(aCross, 37U));
            aScatter = aScatter ^ aNonceWordC;
            aScatter = TwistMix64::DiffuseB((aScatter ^ aPhaseFDomainWordScatter));
            //
            aOrbiterA = ((aWandererE + RotL64(aScatter, 43U)) + 7651355040951791298U) + aNonceWordG;
            aOrbiterC = (aWandererC + RotL64(aIngress, 29U)) + 13988210277931659312U;
            aOrbiterB = (aWandererB + RotL64(aPrevious, 56U)) + 9846849412579537783U;
            aOrbiterH = ((aWandererH + RotL64(aCross, 3U)) + 12746719939495876158U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 11498066185182895284U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aScatter, 19U)) + RotL64(aCarry, 39U)) + 11101058955193080232U) + aNonceWordC;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 39U)) + 15513734459555672046U) + aNonceWordH;
            aOrbiterG = (aWandererA + RotL64(aCross, 47U)) + 15711108675349394643U;
            aOrbiterJ = (aWandererD + RotL64(aScatter, 35U)) + 4771231759949468556U;
            aOrbiterD = (aWandererK + RotL64(aCross, 58U)) + 11449258010811305256U;
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 23U)) + RotL64(aCarry, 3U)) + 17036938391509986723U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6999245666776654250U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 2106819066263369528U;
            aOrbiterB = RotL64((aOrbiterB * 13005885810757743129U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 12716183358903477216U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 16752724547046059889U;
            aOrbiterE = RotL64((aOrbiterE * 11475905692393034141U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 17623077680983093163U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 6726003022297274986U;
            aOrbiterI = RotL64((aOrbiterI * 14709385877103232653U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2842410225096524740U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9235178377537910514U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11813751114775673845U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 2619888019860844610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 6295481948199619613U;
            aOrbiterG = RotL64((aOrbiterG * 15429161806953951205U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9724921158061115570U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 4070976180958458679U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 6080566609081811453U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 5864247978960125554U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 7771249710071026757U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4787660062590737657U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 15006900854988166845U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 2755659268987119046U;
            aOrbiterF = RotL64((aOrbiterF * 8043939381186802359U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 1922321482806966418U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 13910818219761929659U;
            aOrbiterA = RotL64((aOrbiterA * 8895973123729951173U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7540972911473176026U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 5419023469522423893U;
            aOrbiterC = RotL64((aOrbiterC * 1380429266266313945U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 2349651834739320824U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 7651355040951791298U;
            aOrbiterH = RotL64((aOrbiterH * 3713776056028698433U), 3U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 21U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((((RotL64(aIngress, 36U) + RotL64(aOrbiterC, 23U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 21U) + RotL64(aOrbiterB, 28U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterG, 41U)) + aNonceWordN);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 39U)) + aOrbiterG);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 41U) + aOrbiterD) + RotL64(aOrbiterJ, 21U)) + aPhaseFWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 10U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aCross, 14U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterE, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 35U)) + aOrbiterH);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterH, 19U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordB);
            //
            aCarry = aCarry + (RotL64(aWandererD, 50U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererJ, 43U));
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 6U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = aCarry ^ (aNonceWordM ^ aNonceWordI);
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

void TwistExpander_Softball_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(mSource[((aIndex + 7082U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 2060U)) & W_KEY1], 22U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadB[(((2047U - aIndex) + 6239U)) & W_KEY1], 20U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4015U)) & S_BLOCK1], 41U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 53U)) ^ (RotL64(aCross, 40U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = ((aWandererA + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 2558105147674438050U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 47U)) + 15856662514774702561U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 3U)) + 13346869226246584582U;
            aOrbiterD = (aWandererE + RotL64(aCross, 43U)) + 7632111846116243973U;
            aOrbiterA = (aWandererH + RotL64(aIngress, 28U)) + 2102101361626976279U;
            aOrbiterB = ((aWandererC + RotL64(aScatter, 39U)) + 5605968705067851563U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (((aWandererG + RotL64(aCross, 57U)) + RotL64(aCarry, 19U)) + 6842483186584326681U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 51U)) + RotL64(aCarry, 5U)) + 5559797213819425064U;
            aOrbiterF = (aWandererJ + RotL64(aIngress, 24U)) + 12422313931331576759U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 2751024420047872601U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 11031320239359798610U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8607639453141148025U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 14366375309473793217U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 11971479429768505316U;
            aOrbiterB = RotL64((aOrbiterB * 10063001532313098203U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3947595951884469542U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 17882767922372770896U;
            aOrbiterE = RotL64((aOrbiterE * 3361906348965810211U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 513871456983509223U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 5951677013597794294U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8508629569649935293U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 437626309049021931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 466674061172005705U;
            aOrbiterC = RotL64((aOrbiterC * 1310502572084891157U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 12362602809233133718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 10525852878882195702U;
            aOrbiterD = RotL64((aOrbiterD * 17755022180514914325U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 17927000184308583095U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 566723721423470052U;
            aOrbiterJ = RotL64((aOrbiterJ * 17710534355278632573U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9504585484034413577U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 4614306037721859929U;
            aOrbiterG = RotL64((aOrbiterG * 170807293799483539U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 1463218357720031588U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4036696102163560633U;
            aOrbiterA = RotL64((aOrbiterA * 15389914226155130065U), 23U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 30U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 13U)) + aOrbiterF) + RotL64(aCarry, 19U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 60U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aPrevious, 28U) + aOrbiterA) + RotL64(aOrbiterC, 19U)) + aPhaseCWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterG, 5U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aIngress, 21U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterE, 52U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterJ, 47U)) + aPhaseCWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterG) + RotL64(aOrbiterJ, 35U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterD) + RotL64(aCarry, 41U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererE, 53U) ^ aWandererJ);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 10764U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 10002U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 15056U)) & W_KEY1], 22U) ^ RotL64(aKeyRowReadB[((aIndex + 15164U)) & W_KEY1], 13U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 43U) + RotL64(aIngress, 60U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterE = (aWandererI + RotL64(aScatter, 58U)) + 14157904117287696136U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 43U)) + 7369512677371640676U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 21U)) + 8411250745902073798U;
            aOrbiterK = (aWandererG + RotL64(aPrevious, 27U)) + 5002041814539710275U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 34U)) + 9538041410816283124U;
            aOrbiterG = ((aWandererD + RotL64(aCross, 39U)) + 5210700103927513061U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 19U)) + 7600709399101287982U;
            aOrbiterA = ((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 35U)) + 2366369466696580499U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 5544575244203019109U) + aPhaseCOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 8710073749110329779U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 15998211310115361630U) ^ aPhaseCOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15275657696897688955U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 15354357553877376422U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 10657523549259276169U;
            aOrbiterB = RotL64((aOrbiterB * 13695239532898311073U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 10405750198355464768U) + aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 3465819693133515142U;
            aOrbiterC = RotL64((aOrbiterC * 14678343718277562799U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 16724189641701408630U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3484340153620198872U;
            aOrbiterA = RotL64((aOrbiterA * 17247547677520703125U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 7420442404884871126U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11138445997256757636U;
            aOrbiterH = RotL64((aOrbiterH * 11167543379937571127U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 1428191560884663125U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16950093140800653985U;
            aOrbiterE = RotL64((aOrbiterE * 4423012306984814805U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 17288299075036481960U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13793597915359681028U;
            aOrbiterK = RotL64((aOrbiterK * 9639204979982125757U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 5017972942710079726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 12409957957614320964U;
            aOrbiterG = RotL64((aOrbiterG * 10273295741911545745U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 12487994181992095174U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 1573393166996612118U;
            aOrbiterI = RotL64((aOrbiterI * 13364311829104520751U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 37U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 5U));
            aIngress = aIngress + (RotL64(aOrbiterA, 57U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 36U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererF = aWandererF + (((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterB, 41U));
            aWandererH = aWandererH + ((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterK, 19U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 34U)) + aOrbiterG);
            aWandererG = aWandererG + (((RotL64(aPrevious, 13U) + aOrbiterB) + RotL64(aOrbiterH, 23U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterC, 47U)) + aPhaseCWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 18U) + RotL64(aOrbiterE, 13U)) + aOrbiterF) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterB, 30U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 60U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 17516U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23699U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aKeyRowReadA[(((2047U - aIndex) + 17758U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21650U)) & W_KEY1], 48U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 39U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = (aWandererK + RotL64(aCross, 21U)) + 898812731947995389U;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 8677347622525527167U) + aPhaseCOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aIngress, 5U)) + 770321564027567654U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 57U)) + 11020474858081526395U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 46U)) + RotL64(aCarry, 19U)) + 17289793580414993470U;
            aOrbiterE = (aWandererJ + RotL64(aScatter, 35U)) + 10111912559295118444U;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 53U)) + 8083622125544542011U;
            aOrbiterK = (aWandererE + RotL64(aCross, 27U)) + 7149858558922988240U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 60U)) + 5919683821379905699U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 6860902846079238714U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15083517836867542075U;
            aOrbiterD = RotL64((aOrbiterD * 4686657139237578325U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 14852868368708376381U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9860233289028878323U;
            aOrbiterH = RotL64((aOrbiterH * 13418143547952204667U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 772406119079116272U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 7971141501337627589U) ^ aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10168120622976358617U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 8478568022896691911U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4027604850785607101U;
            aOrbiterF = RotL64((aOrbiterF * 4826627523578901467U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 17199331557841535430U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 7515957656979776361U;
            aOrbiterI = RotL64((aOrbiterI * 5468950152869656599U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17138249294921502391U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 16236812863923234668U;
            aOrbiterE = RotL64((aOrbiterE * 2925542836624164807U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 16941524155859123682U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11240343728857342866U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 7281012444214294659U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 15163914964139858328U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 6673576554415729652U;
            aOrbiterK = RotL64((aOrbiterK * 1558880328574736975U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5399050402101642989U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11806006719060024615U;
            aOrbiterG = RotL64((aOrbiterG * 15782156615926092159U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 41U);
            aIngress = aIngress + (RotL64(aOrbiterD, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 6U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 12U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 10U) + RotL64(aOrbiterF, 23U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterB, 43U)) + aOrbiterK);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 27U));
            aWandererA = aWandererA + ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterE, 3U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 56U)) + aOrbiterH) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 56U) + RotL64(aOrbiterD, 51U)) + aOrbiterK) + RotL64(aCarry, 43U)) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterF, 19U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 6U));
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 30484U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30758U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29221U)) & S_BLOCK1], 22U) ^ RotL64(mSource[((aIndex + 28012U)) & S_BLOCK1], 37U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) + RotL64(aPrevious, 51U)) ^ (RotL64(aIngress, 23U) + RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 47U)) + 4259993311776766595U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aScatter, 53U)) + 2857813330021126753U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 40U)) + 1345396841329442896U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = (aWandererH + RotL64(aIngress, 35U)) + 320992148982301024U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 23U)) + 5619109532065293074U;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 5U)) + 10380157329426706345U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 13U)) + 12449831150625409695U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 19U)) + 7847096607042268396U;
            aOrbiterF = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 11707184096803214678U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9893643746186827088U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 333687403830908774U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 17911256836121454271U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 13837360705077441580U) + aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4367119682175710689U;
            aOrbiterA = RotL64((aOrbiterA * 10295744669174603401U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 1193493435041306784U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15062951612027370606U;
            aOrbiterI = RotL64((aOrbiterI * 2509383510565136549U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16000173839235429105U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 15294482444605409961U;
            aOrbiterH = RotL64((aOrbiterH * 1031800997944302665U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 5720749055549773527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17248674962996093668U;
            aOrbiterK = RotL64((aOrbiterK * 15730637462755795591U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 16956840483882091059U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 9637715107943515594U;
            aOrbiterC = RotL64((aOrbiterC * 8878362378343603463U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 7147495779349862274U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7508890985889484275U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17728368447504622035U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4407738164617959366U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17027017782352660454U;
            aOrbiterF = RotL64((aOrbiterF * 417183060881259295U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 3174658601748235285U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9779053567370714831U;
            aOrbiterJ = RotL64((aOrbiterJ * 6383245776181968033U), 19U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 48U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 43U));
            aIngress = aIngress + RotL64(aOrbiterI, 10U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aCross, 44U) + RotL64(aOrbiterG, 10U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterI, 5U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ) + aPhaseCWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 57U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 23U)) + aPhaseCWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + aOrbiterH) + RotL64(aOrbiterC, 47U));
            aWandererG = aWandererG + (((RotL64(aIngress, 28U) + aOrbiterC) + RotL64(aOrbiterA, 35U)) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterH, 53U)) + aOrbiterD);
            aWandererI = aWandererI + ((RotL64(aScatter, 39U) + aOrbiterF) + RotL64(aOrbiterI, 14U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererJ, 30U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Softball_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 3822U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 3662U)) & S_BLOCK1], 36U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 325U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((aIndex + 3912U)) & S_BLOCK1], 10U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCarry, 26U)) + (RotL64(aIngress, 53U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererJ + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 966899917801652720U;
            aOrbiterJ = (((aWandererK + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 10996327672320748649U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aCross, 40U)) + 4188171566846621107U) + aPhaseDOrbiterAssignSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 11U)) + 5886209243097387959U;
            aOrbiterF = (aWandererI + RotL64(aCross, 57U)) + 14940428957136728111U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 179187285531914832U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6685351948936817752U;
            aOrbiterB = RotL64((aOrbiterB * 15533370414711696803U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1894506461704029700U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4182760368636977082U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 972988091869133921U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 12523318028514940790U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 5059306166973366892U;
            aOrbiterI = RotL64((aOrbiterI * 2857409765717296483U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 5890872367917643851U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17747338389865221534U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5306740664798049267U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 13906227834259884100U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7152105382899756368U;
            aOrbiterF = RotL64((aOrbiterF * 6772157117358310485U), 43U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 30U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 41U)) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterB, 11U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + aOrbiterE) + RotL64(aOrbiterI, 51U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 21U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneA[((aIndex + 11559U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((aIndex + 12161U)) & S_BLOCK1], 27U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 10515U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneB[((aIndex + 11270U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 43U)) + (RotL64(aCross, 24U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 5U)) + 5906639480605353429U) + aPhaseDOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterJ = ((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 23U)) + 5293518570213287605U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 35U)) + 15383185501428521377U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 15364072512743978902U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aPrevious, 14U)) + 4525473357144014271U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 10400911938125603074U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16417506293824627550U;
            aOrbiterC = RotL64((aOrbiterC * 8303380456072515611U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2419329331753341815U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 14929222427923332069U;
            aOrbiterF = RotL64((aOrbiterF * 11596261802662514979U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16771573504983922586U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 1863466450051787622U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 2585626547126027053U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12895350137096692415U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 3700979086526298327U;
            aOrbiterJ = RotL64((aOrbiterJ * 10279730254867618193U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 1977099106211282426U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 6144698304096915742U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5039822990560519609U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 6U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 28U) + aOrbiterH) + RotL64(aOrbiterJ, 12U));
            aWandererB = aWandererB + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 23U)) + aOrbiterC);
            aWandererI = aWandererI + ((((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterG, 3U)) + RotL64(aCarry, 29U)) + aPhaseDWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterC, 39U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 60U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneB[((aIndex + 23740U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 21202U)) & S_BLOCK1], 41U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 17772U)) & S_BLOCK1], 22U) ^ RotL64(aExpandLaneC[((aIndex + 20711U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCarry, 23U)) ^ (RotL64(aIngress, 11U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 12U)) + 6733949564325516029U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterB = (((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 5U)) + 7304098437143918796U) + aPhaseDOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 3923949518391777800U;
            aOrbiterC = ((aWandererD + RotL64(aScatter, 57U)) + RotL64(aCarry, 39U)) + 14243591003388927124U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 3U)) + 18329498724605410406U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 13118172167747037249U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 5272025143849174212U;
            aOrbiterA = RotL64((aOrbiterA * 9935990954321437743U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16075917179214318424U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15263590648674658399U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9918239923411740337U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 13730046728289525921U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 7703141464499623408U;
            aOrbiterD = RotL64((aOrbiterD * 5886009900621521987U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 1382279753822135359U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 2973369221699098292U;
            aOrbiterC = RotL64((aOrbiterC * 7440242040663550631U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 11578274119583013219U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 3419411247737896674U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 17814942652262802991U), 35U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 27U) + RotL64(aOrbiterK, 13U)) + aOrbiterA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 56U) + RotL64(aOrbiterB, 52U)) + aOrbiterD) + aPhaseDWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterK, 21U)) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterD);
            aWandererC = aWandererC + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 35U)) + aOrbiterA) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 29U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = aIngress ^ (RotL64(aOperationLaneC[((aIndex + 27729U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneB[((aIndex + 27903U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 27515U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((aIndex + 28855U)) & S_BLOCK1], 23U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 41U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 13U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 30U)) + RotL64(aCarry, 51U)) + 14157904117287696136U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 5U)) + 7369512677371640676U) + aPhaseDOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 19U)) + 8411250745902073798U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aPrevious, 53U)) + RotL64(aCarry, 39U)) + 5002041814539710275U;
            aOrbiterF = (aWandererE + RotL64(aIngress, 21U)) + 9538041410816283124U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterA) + 5210700103927513061U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7600709399101287982U;
            aOrbiterC = RotL64((aOrbiterC * 6777896926889560889U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 2366369466696580499U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5544575244203019109U;
            aOrbiterJ = RotL64((aOrbiterJ * 16231219246786333057U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8710073749110329779U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15998211310115361630U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15275657696897688955U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 15354357553877376422U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10657523549259276169U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13695239532898311073U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 10405750198355464768U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 3465819693133515142U;
            aOrbiterF = RotL64((aOrbiterF * 14678343718277562799U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 47U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + RotL64(aOrbiterA, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterH, 41U)) + aOrbiterF);
            aWandererE = aWandererE + ((((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 29U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 38U) + RotL64(aOrbiterC, 6U)) + aOrbiterA);
            aWandererG = aWandererG + (((RotL64(aCross, 29U) + RotL64(aOrbiterJ, 21U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 43U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + RotL64(aWandererC, 56U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Softball_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aOperationLaneD[((aIndex + 554U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneC[((aIndex + 5891U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 965U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 315U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 47U)) + (RotL64(aIngress, 19U) ^ RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 1866656689936219099U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 19U)) + 2312314528139448289U;
            aOrbiterI = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 3554037526469185237U;
            aOrbiterJ = ((aWandererD + RotL64(aScatter, 43U)) + 405707755060974111U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 1862976326004007697U) + aPhaseEOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 11U)) + 12992483065443288263U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 58U)) + 3793854946371595197U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4244007978867369382U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 10280867500312580308U;
            aOrbiterI = RotL64((aOrbiterI * 13729899124177931289U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 472563452959164242U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 12041770406895816553U;
            aOrbiterC = RotL64((aOrbiterC * 17811798500132002631U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6118634015704900486U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 13637107920449233307U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17712028184714868053U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 16673735670669318830U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8602681273646630496U;
            aOrbiterA = RotL64((aOrbiterA * 6995213887710749241U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 7683264695930369476U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9146674871199188218U;
            aOrbiterK = RotL64((aOrbiterK * 7403427067419261981U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 3012935612827493084U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 1259789268731661945U;
            aOrbiterJ = RotL64((aOrbiterJ * 2372843620327050137U), 41U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 5623690455471160780U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 18355567776031865462U;
            aOrbiterG = RotL64((aOrbiterG * 9553862670107886679U), 23U);
            //
            aIngress = RotL64(aOrbiterG, 40U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 47U)) + aOrbiterE);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterK, 27U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 20U) + RotL64(aOrbiterC, 19U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aScatter, 39U) + aOrbiterK) + RotL64(aOrbiterC, 10U)) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 53U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterA, 3U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + aOrbiterA) + RotL64(aOrbiterJ, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 14U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 8230U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((aIndex + 13892U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 8269U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 11866U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 26U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 21U)) + 17711946802293254150U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 13U)) + 16652362590489569378U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 5U)) + 6972810344198183097U;
            aOrbiterI = (((aWandererD + RotL64(aIngress, 51U)) + RotL64(aCarry, 35U)) + 13117100889782940546U) + aPhaseEOrbiterAssignSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aCross, 37U)) + 13199305696782626591U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 28U)) + 992156184392760945U;
            aOrbiterA = (aWandererF + RotL64(aIngress, 57U)) + 13791265442074543880U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 17057087245252294859U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13444195995883541046U;
            aOrbiterG = RotL64((aOrbiterG * 13067044288608808777U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 6723678233676059420U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 7913379431208430475U;
            aOrbiterK = RotL64((aOrbiterK * 2295062944289127123U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4481887195529300665U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11892724101424384078U;
            aOrbiterI = RotL64((aOrbiterI * 3468639499716604111U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 7700902083270424194U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1888001433557140271U;
            aOrbiterJ = RotL64((aOrbiterJ * 8975562955027025349U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 14996753906788986929U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 939004845422123765U;
            aOrbiterB = RotL64((aOrbiterB * 2507090308972292313U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11922230289291941807U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 15681187459741147199U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10124947739653819101U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 9119043713532718155U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8327697433992362166U;
            aOrbiterA = RotL64((aOrbiterA * 11157657162184304567U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 6U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterF) + RotL64(aCarry, 37U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 29U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltD[((aIndex + 10U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterJ, 5U)) + aOrbiterK);
            aWandererD = aWandererD + ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterB, 56U)) + aOrbiterA) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 23891U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 22214U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24382U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22775U)) & S_BLOCK1], 20U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 20U) ^ RotL64(aIngress, 35U)) + (RotL64(aCarry, 5U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 47U)) + 5295352595333316211U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 39U)) + 2341795367042042605U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 22U)) + 10122175780504033663U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 10084612804696198554U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 3U)) + 16470424309851045971U) + aPhaseEOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aIngress, 57U)) + 656016130975227994U;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 15313268829659834317U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 3795220914993923394U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 14044442220988813825U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3270650852546606835U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3804224626734584802U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 7980006306010255693U;
            aOrbiterB = RotL64((aOrbiterB * 13958505239726088561U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 13746830564584711549U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11852212099729274845U;
            aOrbiterE = RotL64((aOrbiterE * 2164880979318247855U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9083223471018084847U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 13706723820703853346U;
            aOrbiterG = RotL64((aOrbiterG * 11361854103656219887U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1713819986642275223U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 1382000168233902914U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3894160765130198157U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 4540474625764565485U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1756168174375757220U;
            aOrbiterC = RotL64((aOrbiterC * 12739160208010092017U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 1409297070183609309U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6082750101445444357U;
            aOrbiterK = RotL64((aOrbiterK * 17438740230251860935U), 5U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 29U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 53U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterD, 35U)) + aOrbiterC) + aPhaseEWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterG, 21U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterK);
            aWandererI = aWandererI + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 12U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 60U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + RotL64(aOrbiterB, 57U)) + aOrbiterH) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 29U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererI, 5U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 32438U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 24961U)) & S_BLOCK1], 54U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25438U)) & S_BLOCK1], 46U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 25152U)) & S_BLOCK1], 19U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 47U) + RotL64(aIngress, 34U)) ^ (RotL64(aCarry, 3U) ^ RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 47U)) + RotL64(aCarry, 39U)) + 3621877681473089725U;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 35U)) + 4451752751536414717U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aCross, 23U)) + 11371625415377772117U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 6046792758881150619U;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 53U)) + 8213166120394461682U;
            aOrbiterH = (aWandererF + RotL64(aIngress, 41U)) + 4343156661140422645U;
            aOrbiterD = (aWandererH + RotL64(aScatter, 29U)) + 11105271483234947905U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 348904609985341372U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 12924652822526858767U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2801892489296408735U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7461211697358520287U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16551553555297890558U;
            aOrbiterH = RotL64((aOrbiterH * 16432952324635746293U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 11908056404140782995U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9147367258259948715U;
            aOrbiterK = RotL64((aOrbiterK * 10777628928376261667U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 8876461054692728610U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 10546855952702525404U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10071104785895309677U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 4748636139110443794U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 783046909529525098U;
            aOrbiterA = RotL64((aOrbiterA * 8969157702460927215U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 16683965945838696665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12385412690177109575U;
            aOrbiterB = RotL64((aOrbiterB * 10795062772707143187U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8210546822184469023U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13146493623236979963U;
            aOrbiterD = RotL64((aOrbiterD * 13199947810161148155U), 29U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 35U);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterE, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 51U) + RotL64(aOrbiterH, 37U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + RotL64(aOrbiterG, 27U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 53U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + RotL64(aOrbiterE, 43U)) + aOrbiterB);
            aWandererF = aWandererF + ((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 21U)) + aOrbiterG);
            aWandererH = aWandererH ^ (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterK, 13U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterE, 60U)) + aPhaseEWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Softball_Arx::Twist_D(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 5492U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1793U)) & S_BLOCK1], 10U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6236U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8031U)) & S_BLOCK1], 48U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 26U) ^ RotL64(aCarry, 53U)) ^ (RotL64(aIngress, 13U) + RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererE + RotL64(aCross, 13U)) + RotL64(aCarry, 3U)) + 1364174714924216027U;
            aOrbiterE = (aWandererF + RotL64(aScatter, 3U)) + 13561796874229506613U;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 51U)) + 11845572344206238305U) + aPhaseFOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 21U)) + 15762708240326773763U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 26U)) + RotL64(aCarry, 47U)) + 1157119665207900473U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 6823546624372055260U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 14465564210523945121U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10957323253786161255U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10667464548080807531U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 13445737493224316575U;
            aOrbiterK = RotL64((aOrbiterK * 12137295000900795711U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 3009837893785957665U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 2886920524111083752U;
            aOrbiterB = RotL64((aOrbiterB * 15308180928967762543U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 10886177449328249656U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 15067759884678100433U;
            aOrbiterE = RotL64((aOrbiterE * 5724566815989860041U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 18307930462682331536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 8791864377579255801U;
            aOrbiterI = RotL64((aOrbiterI * 9265158882471421767U), 57U);
            //
            aIngress = RotL64(aOrbiterG, 58U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterB, 10U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterI, 43U)) + aOrbiterE);
            aWandererF = aWandererF + ((((RotL64(aScatter, 21U) + aOrbiterG) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 41U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aPhaseFWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterK, 35U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 15915U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((aIndex + 9116U)) & S_BLOCK1], 4U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 16320U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 8214U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 6U)) ^ (RotL64(aCross, 43U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererI + RotL64(aScatter, 30U)) + 11210042748013785976U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 13U)) + RotL64(aCarry, 47U)) + 4584747303233477454U;
            aOrbiterJ = (aWandererH + RotL64(aIngress, 3U)) + 8878765929792969517U;
            aOrbiterC = (((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 2172232330280041122U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 8378937026022264016U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8683007464695824208U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 9564352997357118134U;
            aOrbiterJ = RotL64((aOrbiterJ * 17869948990449143305U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 11713878436769887528U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 8052917623074021077U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7450115139081623477U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 7720597162792145185U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2602847785328475621U;
            aOrbiterI = RotL64((aOrbiterI * 14065077077207224525U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 17813669222300509724U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 8724263063156573013U;
            aOrbiterH = RotL64((aOrbiterH * 3632927017737834359U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6882429835961613492U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 13213313479525717359U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2411431247725974895U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + RotL64(aOrbiterJ, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 11U) + aOrbiterI) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterI, 39U)) + aOrbiterC);
            aWandererC = aWandererC + ((((RotL64(aCross, 51U) + aOrbiterJ) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 35U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterA, 57U)) + aPhaseFWandererUpdateSaltE[((aIndex + 23U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 20U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererI, 3U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 18596U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20527U)) & S_BLOCK1], 52U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18575U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 20342U)) & S_BLOCK1], 58U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aPrevious, 53U)) ^ (RotL64(aCross, 3U) + RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererE + RotL64(aCross, 29U)) + 826930775230515406U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (((aWandererH + RotL64(aIngress, 19U)) + RotL64(aCarry, 51U)) + 5137814617363250861U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 6U)) + RotL64(aCarry, 11U)) + 14761561947426681616U;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 43U)) + RotL64(aCarry, 27U)) + 12773023438753662590U;
            aOrbiterD = (aWandererC + RotL64(aCross, 51U)) + 7331345852207096322U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3899381212671247460U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 10072004147620068599U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5663583566047763435U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 3424585039401897560U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 8246760141625966321U;
            aOrbiterJ = RotL64((aOrbiterJ * 11478879365443736383U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 3655992860610853290U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11154618022505863898U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4791494171286145231U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 15629361991059709973U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 10842068502278489664U;
            aOrbiterG = RotL64((aOrbiterG * 17223002513104960799U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 5571312349016336686U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 589313823745748879U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 1356685926549786027U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterG, 28U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aScatter, 43U) + aOrbiterG) + RotL64(aOrbiterC, 40U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 5U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterD, 53U));
            aWandererJ = aWandererJ + (((RotL64(aCross, 58U) + RotL64(aOrbiterC, 21U)) + aOrbiterJ) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 29U)) + aOrbiterA) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererC, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 31159U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((aIndex + 28210U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 30390U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 30894U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 43U)) + (RotL64(aCarry, 24U) + RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 4U)) + 7075016829833562104U) + aPhaseFOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 8783765886115517036U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 41U)) + 2996723892384565829U;
            aOrbiterH = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 9494134707342189476U;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 57U)) + 5052642981395679904U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 8766787055127962238U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4467211954388738079U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8599295330343804047U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 8030255604633658608U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 16962408063455702251U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11171737929747471631U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3768222186567699076U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 14930990410207899871U;
            aOrbiterH = RotL64((aOrbiterH * 10930005786146268241U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 14179761938395502502U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 1879084742719898108U;
            aOrbiterA = RotL64((aOrbiterA * 16783034788172670121U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5535012408925981515U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12792553516710295939U;
            aOrbiterB = RotL64((aOrbiterB * 8577530993755159329U), 39U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 50U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterK, 3U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterH) + RotL64(aOrbiterB, 50U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 13U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            aWandererD = aWandererD + ((((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterH, 27U)) + RotL64(aCarry, 57U)) + aPhaseFWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 50U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 3U));
            aCarry = aCarry + RotL64(aWandererF, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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

void TwistExpander_Softball_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterD = 0; std::uint64_t aOrbiterE = 0;
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
        // read from: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = 0U;
            aIngress = aIngress ^ (RotL64(aWorkLaneA[((aIndex + 6852U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 3579U)) & S_BLOCK1], 12U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4128U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneD[((aIndex + 2423U)) & S_BLOCK1], 46U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 35U) + RotL64(aIngress, 20U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 21U)) + 2672739400294801233U) + aPhaseGOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 8475624545015101850U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 1252755112289831257U;
            aOrbiterE = ((aWandererB + RotL64(aScatter, 46U)) + 7938039507649183387U) + aPhaseGOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aPrevious, 19U)) + 8167413146948861022U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 17712313989694374353U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 7637042279892596975U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13056020836704050293U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15770412950033467341U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3951812021898608685U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6623127125223204737U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 8656983621098246507U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17943342344730687317U;
            aOrbiterE = RotL64((aOrbiterE * 16495519451034883813U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 3087677463651608668U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16493240011924342788U;
            aOrbiterI = RotL64((aOrbiterI * 16898479041530771871U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 7750923317452683057U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 2185924841611106546U;
            aOrbiterF = RotL64((aOrbiterF * 708072658250726381U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterI, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererD = aWandererD + ((((RotL64(aIngress, 39U) + aOrbiterF) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 37U)) + aPhaseGWandererUpdateSaltF[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            aWandererI = aWandererI + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterB) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 11U) + aOrbiterB) + RotL64(aOrbiterE, 36U)) + aPhaseGWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 60U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneB[((aIndex + 10556U)) & S_BLOCK1], 38U) ^ RotL64(aWorkLaneC[((aIndex + 8288U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 12645U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneA[((aIndex + 16169U)) & S_BLOCK1], 4U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aIngress, 11U)) ^ (RotL64(aCross, 41U) ^ RotL64(aPrevious, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererA + RotL64(aIngress, 27U)) + 4204560462077827182U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 13U)) + 6572370199668594039U;
            aOrbiterJ = (((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 15958999876732622825U) + aPhaseGOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 54U)) + RotL64(aCarry, 57U)) + 9969349486879280377U;
            aOrbiterE = (aWandererB + RotL64(aIngress, 43U)) + 15450238998293956181U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 9128619863683138259U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5691270563628979565U;
            aOrbiterJ = RotL64((aOrbiterJ * 2170424734274640859U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 5901029710568933106U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10442738941988588834U;
            aOrbiterE = RotL64((aOrbiterE * 7386621444831603817U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3508116020325721993U) + aPhaseGOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 13221917083569767259U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6845108555710135357U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11627915460377128176U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 17858261365514253433U;
            aOrbiterI = RotL64((aOrbiterI * 7535577636975884641U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4294837988806295989U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 11242915481585070249U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17540688242763829319U), 13U);
            //
            aIngress = RotL64(aOrbiterB, 54U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 29U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 48U) + aOrbiterE) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 39U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 5U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 26U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + aOrbiterB) + RotL64(aOrbiterJ, 37U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 53U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneC[((aIndex + 17480U)) & S_BLOCK1], 22U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 18800U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22113U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 17902U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 20U)) + (RotL64(aIngress, 57U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = (((aWandererF + RotL64(aCross, 29U)) + RotL64(aCarry, 53U)) + 3236820517816085022U) + aPhaseGOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aIngress, 60U)) + RotL64(aCarry, 21U)) + 741288875914097926U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 21U)) + 8417246926007729580U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 9715717805774537170U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 37U)) + 14360243844821619482U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 10760908100206775334U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 3434641779946167811U;
            aOrbiterD = RotL64((aOrbiterD * 3305698324169010803U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7885568822756234567U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 3041563437672051294U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11440300917533482297U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 15761355327564963516U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1158633562785937421U;
            aOrbiterE = RotL64((aOrbiterE * 15511324886867188235U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 9338581575871970653U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9172038894262857354U;
            aOrbiterK = RotL64((aOrbiterK * 3110871165285625807U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 14653924713599790081U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 3854497592598563309U;
            aOrbiterF = RotL64((aOrbiterF * 11737111068815795303U), 29U);
            //
            aIngress = RotL64(aOrbiterK, 39U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 60U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterK, 60U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterJ, 19U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aCross, 5U) + RotL64(aOrbiterK, 29U)) + aOrbiterF) + RotL64(aCarry, 3U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 38U));
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aWorkLaneD[((aIndex + 32042U)) & S_BLOCK1], 10U) ^ RotL64(aExpandLaneA[((aIndex + 27027U)) & S_BLOCK1], 35U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 26575U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30735U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 21U) ^ RotL64(aIngress, 34U)) + (RotL64(aPrevious, 5U) + RotL64(aCarry, 47U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 27U)) + RotL64(aCarry, 43U)) + 964165145848253292U;
            aOrbiterF = (aWandererF + RotL64(aScatter, 54U)) + 10645976767204934746U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 43U)) + RotL64(aCarry, 57U)) + 8241612229349212650U) + aPhaseGOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 13U)) + 4159196033256913347U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 13U)) + 7194795864620233507U) + aPhaseGOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7638928444536778384U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 11819105916503968109U;
            aOrbiterC = RotL64((aOrbiterC * 9052440449038441625U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 18052213302858186237U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8663575313970041570U;
            aOrbiterD = RotL64((aOrbiterD * 14131073322476609161U), 39U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 16644136720439299786U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16930316530442679864U;
            aOrbiterI = RotL64((aOrbiterI * 2650922074098320859U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16251107616988250593U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 7171986193609401665U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3543709971414550087U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17885046834432626644U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 7757069274715713557U;
            aOrbiterG = RotL64((aOrbiterG * 15766885299397923879U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 18U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterG, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 60U) + aOrbiterF) + RotL64(aOrbiterC, 12U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 21U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterI, 47U)) + aPhaseGWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 37U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 27U) + aOrbiterI) + RotL64(aOrbiterD, 57U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 12U));
            aCarry = aCarry + RotL64(aWandererH, 21U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Softball_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = aIngress ^ (RotL64(aExpandLaneA[((aIndex + 3806U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 792U)) & S_BLOCK1], 14U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7900U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4209U)) & S_BLOCK1], 53U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 54U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterH = (aWandererA + RotL64(aPrevious, 54U)) + 14157904117287696136U;
            aOrbiterD = (aWandererC + RotL64(aScatter, 27U)) + 7369512677371640676U;
            aOrbiterK = (((aWandererK + RotL64(aCross, 19U)) + RotL64(aCarry, 57U)) + 8411250745902073798U) + aPhaseHOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aIngress, 5U)) + RotL64(aCarry, 29U)) + 5002041814539710275U;
            aOrbiterJ = (((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 13U)) + 9538041410816283124U) + aPhaseHOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 5210700103927513061U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7600709399101287982U;
            aOrbiterK = RotL64((aOrbiterK * 6777896926889560889U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 2366369466696580499U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5544575244203019109U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 16231219246786333057U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8710073749110329779U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15998211310115361630U;
            aOrbiterA = RotL64((aOrbiterA * 15275657696897688955U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 15354357553877376422U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10657523549259276169U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 13695239532898311073U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10405750198355464768U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3465819693133515142U;
            aOrbiterJ = RotL64((aOrbiterJ * 14678343718277562799U), 57U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 52U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + aOrbiterK) + RotL64(aOrbiterH, 13U)) + aPhaseHWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 24U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 41U));
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 54U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 41U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneB[((aIndex + 13691U)) & S_BLOCK1], 20U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 9203U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 14343U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14545U)) & S_BLOCK1], 34U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 23U) + RotL64(aIngress, 5U)) + (RotL64(aPrevious, 48U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererG + RotL64(aCross, 14U)) + 964165145848253292U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterJ = (aWandererC + RotL64(aIngress, 37U)) + 10645976767204934746U;
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 8241612229349212650U;
            aOrbiterH = (((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 4159196033256913347U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererB + RotL64(aIngress, 57U)) + RotL64(aCarry, 47U)) + 7194795864620233507U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7638928444536778384U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 11819105916503968109U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9052440449038441625U), 51U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 18052213302858186237U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 8663575313970041570U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14131073322476609161U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16644136720439299786U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16930316530442679864U;
            aOrbiterD = RotL64((aOrbiterD * 2650922074098320859U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 16251107616988250593U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 7171986193609401665U;
            aOrbiterJ = RotL64((aOrbiterJ * 3543709971414550087U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 17885046834432626644U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7757069274715713557U;
            aOrbiterH = RotL64((aOrbiterH * 15766885299397923879U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 38U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 54U) + RotL64(aOrbiterJ, 46U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aIngress, 5U) + aOrbiterD) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 3U));
            aWandererH = aWandererH ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterB, 37U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 3U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterH, 13U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 38U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneC[((aIndex + 22914U)) & S_BLOCK1], 12U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19001U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21800U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 20312U)) & S_BLOCK1], 40U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aIngress, 21U)) ^ (RotL64(aCarry, 38U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterE = ((aWandererA + RotL64(aIngress, 4U)) + 13481227414590594621U) + aPhaseHOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aCross, 37U)) + 17425964381118918026U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 4792004356135956581U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 11926849936000639098U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 57U)) + RotL64(aCarry, 51U)) + 990697329347742142U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 9307721505373076588U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 17605732738841908719U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13123627214143336281U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13110764518634187439U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17970109897810645911U;
            aOrbiterA = RotL64((aOrbiterA * 10395095143998920213U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 10273133817644703654U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 11239046688920468137U;
            aOrbiterE = RotL64((aOrbiterE * 5197802934333553327U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 8355821483275763145U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15522151127786049345U;
            aOrbiterI = RotL64((aOrbiterI * 4844278537850520413U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5381663179722418112U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 9551368011768104906U;
            aOrbiterD = RotL64((aOrbiterD * 14202470972121732997U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 23U);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 52U) + aOrbiterA) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 39U)) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterC, 48U)) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 13U)) + aOrbiterC);
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterD, 5U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererA, 56U);
            aCarry = aCarry + RotL64(aIngress, 43U);
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
            aIngress = aIngress ^ (RotL64(aExpandLaneD[((aIndex + 30659U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneA[((aIndex + 25703U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = 0U;
            aCross = aCross ^ (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27846U)) & S_BLOCK1], 58U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 27586U)) & S_BLOCK1], 3U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 3U) ^ RotL64(aIngress, 37U)) ^ (RotL64(aPrevious, 52U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 23U)) + 13333509828310369865U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 57U)) + 7645352517103840797U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 4U)) + 5310766306660062655U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 5165635069832352932U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 57U)) + 15684141764734281849U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3327963374225061738U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 8625811794878848871U;
            aOrbiterH = RotL64((aOrbiterH * 16327750494894125333U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 7598657468430485291U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 2881171216276746485U;
            aOrbiterI = RotL64((aOrbiterI * 3331350584102843605U), 19U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 10237691227222918101U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 6419254255884834497U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3816625473642865305U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 4238455444646479956U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 14936613353493061492U;
            aOrbiterK = RotL64((aOrbiterK * 3544216916806292273U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15324699725208372627U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 9506640480601832011U;
            aOrbiterJ = RotL64((aOrbiterJ * 12819564111348390227U), 5U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 27U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 39U) + aOrbiterC) + RotL64(aOrbiterH, 52U)) + aPhaseHWandererUpdateSaltC[((aIndex + 16U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 21U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 19U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aPrevious, 56U) + RotL64(aOrbiterK, 11U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 52U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
