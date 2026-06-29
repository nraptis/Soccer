#include "TwistExpander_Cricket_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Cricket_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8697B24680041F93ULL + 0x984BC123011BDCF3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x8A8182ADC6CAF015ULL + 0xFDA6CC68F7BBB066ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xC737558BE57A2EDFULL + 0xD5A3B61F0AE150ADULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xB0A88003FE7AFB49ULL + 0xD82F85AF4BC2A387ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA8A61902F95F36DDULL + 0xA4C0DF1C5EFF5CC5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x8610A8E647F262E3ULL + 0xF68D706ECB6AB7A6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x9C00D5C72523B67BULL + 0xBA6CB6103B251CD4ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xBBA9FB7C66182E55ULL + 0x82ABC1A9CFCA791CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xDF10B193C04C1379ULL + 0xF0CED8E2752BAF83ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA063B36495768EB3ULL + 0xC7D289D8F4558E88ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF0AA0ABE459E9B4BULL + 0xDDE6E9CEA405084BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x8C3F5839D6079CC5ULL + 0xB255D7783DE8014AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9E4FB0505C60AC93ULL + 0xEA9004C27820F8BDULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xDE05B47F0A539E99ULL + 0xDB1DC7AA53AB15B9ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x882AB31399D415E7ULL + 0xCA73D6973BC3AF55ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB53D25FEFFF7F37BULL + 0xC9EAAB822AF4E19DULL);
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
            aIngress = RotL64(mSource[((aIndex + 4779U)) & S_BLOCK1], 37U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 52U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 2827U)) & S_BLOCK1], 57U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 1397U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aPrevious, 56U)) ^ (RotL64(aIngress, 43U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterD = (aWandererI + RotL64(aPrevious, 57U)) + 4068921616130916949U;
            aOrbiterE = (aWandererG + RotL64(aIngress, 35U)) + 12077715273915151726U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 42U)) + RotL64(aCarry, 27U)) + 16047546802670596833U;
            aOrbiterG = (aWandererD + RotL64(aCross, 37U)) + 9690277462716999763U;
            aOrbiterF = (aWandererC + RotL64(aIngress, 53U)) + 14484814700447992628U;
            aOrbiterC = (aWandererF + RotL64(aCross, 3U)) + 17089267243053958210U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 28U)) + 9138746214446211147U;
            aOrbiterB = (aWandererE + RotL64(aPrevious, 23U)) + 10181001536979097045U;
            aOrbiterJ = (((aWandererJ + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 6657458969093373191U) + aNonceWordP;
            aOrbiterH = ((((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 7515983477876590988U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererH + RotL64(aScatter, 39U)) + 3039935555863947600U) + aOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 16209389224740851136U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 725253312098083182U;
            aOrbiterI = RotL64((aOrbiterI * 17535989492095522597U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13307041115748941383U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7159572004825238263U) ^ aNonceWordC;
            aOrbiterC = RotL64((aOrbiterC * 4855009895002398449U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12027236743251643820U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 8717826175991286553U) ^ aOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1175614802543098451U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 4769096034227659937U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11201226563992939616U;
            aOrbiterJ = RotL64((aOrbiterJ * 15595355978388159931U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 17295978531215563256U) + aNonceWordK;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 11850923890626719833U;
            aOrbiterF = RotL64((aOrbiterF * 3854851059897397075U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 14139441565288097706U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 988684899382304485U;
            aOrbiterG = RotL64((aOrbiterG * 11929090869999700891U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 6159251276942253175U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 4849529993914550651U;
            aOrbiterE = RotL64((aOrbiterE * 18240712676783671317U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 6679745455842119497U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 15838404437552215214U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 17357853511591350887U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15853153471104458948U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 12542164757451566994U) ^ aOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12163611303899312043U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 14304233464055838869U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 4037999346933039765U;
            aOrbiterD = RotL64((aOrbiterD * 564236202758328407U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3582312827630995454U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 4068921616130916949U;
            aOrbiterB = RotL64((aOrbiterB * 1527829107415867363U), 35U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 19U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 36U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 50U) + aOrbiterJ) + RotL64(aOrbiterH, 39U));
            aWandererG = aWandererG + ((((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 50U)) + aOrbiterK) + RotL64(aCarry, 47U)) + aNonceWordJ);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterB, 13U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 21U)) + aOrbiterK) + aNonceWordE) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterI, 23U));
            aWandererA = aWandererA + (((RotL64(aCross, 37U) + aOrbiterF) + RotL64(aOrbiterE, 11U)) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 47U) + aOrbiterI) + RotL64(aOrbiterE, 28U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 57U)) + aOrbiterK) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterF, 37U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 52U) + RotL64(aOrbiterA, 5U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 53U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 3U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 9836U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 9453U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10104U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((aIndex + 6240U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 41U)) ^ (RotL64(aCarry, 23U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererK + RotL64(aCross, 13U)) + 16016931609704150191U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 57U)) + 14511433515861302636U;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 18U)) + RotL64(aCarry, 3U)) + 11691237442613269593U) + aNonceWordE;
            aOrbiterJ = (aWandererB + RotL64(aIngress, 11U)) + 16383220587320484649U;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 27U)) + 14293015313458219868U) + aNonceWordA;
            aOrbiterI = (aWandererJ + RotL64(aCross, 29U)) + 4407695248205526670U;
            aOrbiterH = ((aWandererF + RotL64(aPrevious, 35U)) + 1158323195324398372U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aWandererA + RotL64(aIngress, 54U)) + RotL64(aCarry, 35U)) + 6577683409653864555U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = ((aWandererC + RotL64(aCross, 51U)) + 171080079472863843U) + aNonceWordF;
            aOrbiterK = ((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 23U)) + 5766333425872228205U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 47U)) + 16173508656917582960U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 11781450063402219202U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 13033139686637576694U;
            aOrbiterF = RotL64((aOrbiterF * 4331137994135472025U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4006310759400926020U) + aNonceWordD;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13156817947481574467U;
            aOrbiterC = RotL64((aOrbiterC * 563189239835001483U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 12791290558893516411U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 989729955679243234U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8757228712495095017U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 838379839663022790U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 2830743864262313606U;
            aOrbiterA = RotL64((aOrbiterA * 10173947177104802797U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 2146646527331684652U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 4629168181742174906U;
            aOrbiterG = RotL64((aOrbiterG * 9046124907945045131U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1150129989168501777U) + aNonceWordH;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 619659995945229440U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13734821008174603409U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8120315647582116952U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 13754584116324996165U;
            aOrbiterD = RotL64((aOrbiterD * 12295486140772079747U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 6084566798869999580U) + aNonceWordB;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 5731665119233722504U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 5921510209025133639U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16134513471149338456U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 9841695976256666234U;
            aOrbiterE = RotL64((aOrbiterE * 7417023101762286049U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 2559042046155066240U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 14065288635273112125U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10464173719695109147U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 18228257734024217020U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 16016931609704150191U;
            aOrbiterK = RotL64((aOrbiterK * 2874343578276710555U), 37U);
            //
            aIngress = RotL64(aOrbiterB, 48U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterG, 37U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 13U) + RotL64(aOrbiterH, 53U)) + aOrbiterJ) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 48U)) + aNonceWordO);
            aWandererH = aWandererH + (((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterF, 35U)) + RotL64(aCarry, 41U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererK = aWandererK + ((RotL64(aIngress, 30U) + RotL64(aOrbiterC, 43U)) + aOrbiterI);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            aWandererB = aWandererB + (((((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterK, 20U)) + RotL64(aCarry, 23U)) + aNonceWordL) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterK, 11U));
            aWandererE = aWandererE + ((RotL64(aIngress, 39U) + aOrbiterD) + RotL64(aOrbiterB, 27U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 36U) + RotL64(aOrbiterF, 13U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 57U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (RotL64(aWandererB, 20U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 11046U)) & S_BLOCK1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 12740U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 13717U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 11283U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 43U)) ^ (RotL64(aPrevious, 26U) + RotL64(aCross, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = (aWandererK + RotL64(aIngress, 18U)) + 10404808878585437255U;
            aOrbiterG = (aWandererC + RotL64(aScatter, 41U)) + 10587858736301591439U;
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 35U)) + 1430530909801644435U) + aNonceWordO;
            aOrbiterA = ((aWandererF + RotL64(aCross, 37U)) + 9090938022430118902U) + aNonceWordK;
            aOrbiterD = ((aWandererJ + RotL64(aPrevious, 30U)) + RotL64(aCarry, 27U)) + 12936604311751121235U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 39U)) + RotL64(aCarry, 47U)) + 1000583006020232032U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aScatter, 3U)) + 12352532088997042232U) + aNonceWordG;
            aOrbiterB = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 43U)) + 16723410947058502564U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 27U)) + 16614089235313154270U;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 47U)) + 4245553025593349277U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 57U)) + 3353146318549477494U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5935727336135635196U) + aNonceWordM;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 10312187090293319667U) ^ aOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1395964500396711899U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 12192843181244744484U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterA) ^ 2542570124502586365U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 17222847847573534963U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3315472769469002444U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 17512858811783071174U;
            aOrbiterB = RotL64((aOrbiterB * 9070400454074283765U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16633218007427888082U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2502077714838858460U;
            aOrbiterD = RotL64((aOrbiterD * 970762420815997725U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 14792910273226469214U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15739513291150783151U;
            aOrbiterG = RotL64((aOrbiterG * 11896279674116906915U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 2192903544350345992U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 844428341223009295U;
            aOrbiterJ = RotL64((aOrbiterJ * 4768368713974002539U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 2998511458298901402U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7790789639864783373U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9173097618440495497U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4540735375055164995U) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 13700342877362633034U;
            aOrbiterI = RotL64((aOrbiterI * 14730797752841670505U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 16966725424259324323U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 5945539295893015935U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 12226268057062268981U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 12560355243513521281U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2104086086480258265U;
            aOrbiterE = RotL64((aOrbiterE * 17989755118752755577U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 4476697099257280568U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 10404808878585437255U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6245415417832089357U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 24U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 53U)) + aOrbiterJ) + aNonceWordF) + aWandererUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 3U) + aOrbiterA) + RotL64(aOrbiterF, 47U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 23U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aIngress, 6U) + RotL64(aOrbiterI, 19U)) + aOrbiterA) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterG, 57U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 35U)) + aOrbiterK) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 30U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 13U)) + aOrbiterB) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 42U) + aOrbiterA) + RotL64(aOrbiterE, 41U)) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + aOrbiterH) + RotL64(aOrbiterF, 5U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 26U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 60U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 19346U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneA[((aIndex + 16600U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 20173U)) & S_BLOCK1], 53U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 17890U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 18340U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCarry, 39U)) ^ (RotL64(aIngress, 19U) + RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterF = ((aWandererG + RotL64(aCross, 5U)) + RotL64(aCarry, 27U)) + 15383045568644941552U;
            aOrbiterH = (aWandererA + RotL64(aIngress, 19U)) + 17452811657750910067U;
            aOrbiterI = (aWandererJ + RotL64(aPrevious, 40U)) + 15660117718455155603U;
            aOrbiterA = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 43U)) + 10396441207743665753U) + aOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 27U)) + 3708971058200841442U;
            aOrbiterK = (aWandererB + RotL64(aPrevious, 23U)) + 7000673057768598750U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 57U)) + 9886354469011131596U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 37U)) + 16018065329058043467U) + aNonceWordL;
            aOrbiterC = (((aWandererE + RotL64(aPrevious, 51U)) + 5024756166109352320U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererI + RotL64(aScatter, 14U)) + 6587818720728886652U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 3652672354944162319U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 6307315649915348048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 16405347331742979258U;
            aOrbiterI = RotL64((aOrbiterI * 7183142442906743699U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5427299664054601957U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 4983381733483185898U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 14646556236306407673U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 10182995521328377487U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 8694282877540593550U;
            aOrbiterD = RotL64((aOrbiterD * 14614602561910403893U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 4085927978153269932U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 6176195962815240877U;
            aOrbiterB = RotL64((aOrbiterB * 16792916528959579875U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 6966742100601433005U) + aOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9920952446921247521U;
            aOrbiterA = RotL64((aOrbiterA * 1879821050131820933U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 11958734477518336014U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2058335903640404380U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6986170159285417789U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 77366119537297816U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterG) ^ 12072894199692855000U) ^ aOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 9083781120514635987U), 5U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterA) + 11874297832446385377U) + aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 13715562531763053196U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 12822488258322963187U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13664465415354326653U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10365386643010882315U;
            aOrbiterE = RotL64((aOrbiterE * 3687934567254955761U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 2003863843075564853U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8864134110143237364U;
            aOrbiterH = RotL64((aOrbiterH * 4586162015675320985U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 8055736412403126985U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 15383045568644941552U;
            aOrbiterG = RotL64((aOrbiterG * 5175405553995854715U), 23U);
            //
            aIngress = RotL64(aOrbiterB, 19U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterF, 36U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 60U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aScatter, 51U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterE) + RotL64(aOrbiterB, 27U)) + aNonceWordA);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 39U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 46U) + aOrbiterG) + RotL64(aOrbiterB, 14U));
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + RotL64(aOrbiterI, 57U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterC, 3U)) + aOrbiterI);
            aWandererK = aWandererK + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 39U) + aOrbiterA) + RotL64(aOrbiterE, 5U)) + aWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 48U) + RotL64(aOrbiterD, 11U)) + aOrbiterI) + aNonceWordO);
            aWandererB = aWandererB ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 30U)) + aOrbiterI) + aNonceWordD);
            aWandererH = aWandererH + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 23U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 20U));
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22293U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((aIndex + 25503U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(pSnow[((aIndex + 22148U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneA[((aIndex + 24173U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25030U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26839U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 19U) + RotL64(aCarry, 36U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = (aWandererB + RotL64(aScatter, 19U)) + 5173905450211892891U;
            aOrbiterJ = (aWandererE + RotL64(aIngress, 51U)) + 3555542451908039957U;
            aOrbiterF = (aWandererG + RotL64(aCross, 27U)) + 11559884700283861559U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 43U)) + RotL64(aCarry, 57U)) + 1352524329968738673U;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 10U)) + 8914206450420616349U) + aOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererA + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 2251523378498463946U;
            aOrbiterA = (((aWandererD + RotL64(aScatter, 41U)) + 9541575923299247038U) + aOrbiterAssignSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 23U)) + 1239854507907214595U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 29U)) + 17698101462598498934U;
            aOrbiterK = ((aWandererC + RotL64(aCross, 37U)) + 12305566971683256060U) + aNonceWordE;
            aOrbiterD = (((aWandererH + RotL64(aIngress, 34U)) + RotL64(aCarry, 51U)) + 13804545036303215569U) + aNonceWordF;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 10239749097704329264U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 4212214906286320308U;
            aOrbiterF = RotL64((aOrbiterF * 3661436621615751071U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12192418916967430783U) + aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterC) ^ 4475514289326450361U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 17497164630368757887U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 17376102613298827459U) + aNonceWordL;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 18129393209955439341U;
            aOrbiterH = RotL64((aOrbiterH * 6404089025014118979U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4014763724300253568U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 17325007199676828814U) ^ aNonceWordG;
            aOrbiterI = RotL64((aOrbiterI * 1420888274815627083U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 15480474849292388685U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14357924730184375449U;
            aOrbiterB = RotL64((aOrbiterB * 16723492259068034209U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4335731868597970070U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8296023680394303015U;
            aOrbiterC = RotL64((aOrbiterC * 14027415401430120543U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2807312426993262800U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 15510369660839648501U;
            aOrbiterD = RotL64((aOrbiterD * 18207954408298333959U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12597844696606519907U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7231012798553551535U;
            aOrbiterG = RotL64((aOrbiterG * 2841306785994479299U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 849663631945232360U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 4002310581470781194U;
            aOrbiterJ = RotL64((aOrbiterJ * 2148877014350721479U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 16067735571435654555U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4607980694199923842U;
            aOrbiterK = RotL64((aOrbiterK * 10401780756830017477U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 5346879191913449715U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 5173905450211892891U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15360571827429301833U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 26U));
            aIngress = aIngress + (RotL64(aOrbiterD, 11U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + RotL64(aOrbiterK, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 29U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 13U)) + aOrbiterJ) + aNonceWordO) + aWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aCross, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 18U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterA) + RotL64(aCarry, 39U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterK, 41U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterC, 27U)) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 21U) + aOrbiterA) + RotL64(aOrbiterI, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 6U) + aOrbiterE) + RotL64(aOrbiterC, 38U)) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 5U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 20U));
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererG, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 28690U)) & S_BLOCK1], 60U) ^ RotL64(pSnow[((aIndex + 29110U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 27701U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 30077U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 32161U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 32064U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 53U)) + (RotL64(aPrevious, 3U) + RotL64(aCarry, 22U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 29U)) + 11450949896247900941U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 39U)) + 3905542253538116335U) + aNonceWordL;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 10U)) + RotL64(aCarry, 19U)) + 9529740545977785305U;
            aOrbiterG = (aWandererH + RotL64(aPrevious, 47U)) + 1856876631533143492U;
            aOrbiterE = (aWandererF + RotL64(aCross, 23U)) + 84253466320181686U;
            aOrbiterA = ((aWandererJ + RotL64(aScatter, 13U)) + 12577480918745432444U) + aNonceWordJ;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 43U)) + 5625703170397704029U) + aOrbiterAssignSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = (aWandererB + RotL64(aIngress, 51U)) + 694608607323629282U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 4U)) + 3993981243536262204U) + aNonceWordI;
            aOrbiterK = (((aWandererC + RotL64(aCross, 29U)) + 4119215953484892051U) + aOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = ((aWandererG + RotL64(aScatter, 41U)) + RotL64(aCarry, 39U)) + 8785040118556157146U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16234403619456882890U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 10398727475672860610U;
            aOrbiterB = RotL64((aOrbiterB * 5086871400049644715U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 18327987141759096769U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 2645964788056875452U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8778681366114628045U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 2859452497983106129U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 7196557924940881076U;
            aOrbiterG = RotL64((aOrbiterG * 14415389907490256711U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 930127943984174668U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15673596916054795749U;
            aOrbiterD = RotL64((aOrbiterD * 7505660488733199479U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 16673140529110941163U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 2258448294877833760U) ^ aNonceWordH;
            aOrbiterH = RotL64((aOrbiterH * 1821550319748977445U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6870209259643931219U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12749790107942194104U;
            aOrbiterF = RotL64((aOrbiterF * 4871407285968611725U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 17131374134617173866U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6426448390733751612U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 12490559588384058417U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 15592826434339731146U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 14182944418026376183U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7218860482893476233U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17447476498234456596U) + aNonceWordK;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 972861017466618022U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 9610670431280153921U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 13185309156950240549U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14442284480744008537U;
            aOrbiterJ = RotL64((aOrbiterJ * 2907844852105175837U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 7816745313858811117U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 11450949896247900941U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 18317765298694454463U), 53U);
            //
            aIngress = RotL64(aOrbiterG, 39U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 30U));
            aIngress = aIngress + (RotL64(aOrbiterB, 51U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterA, 41U)) + aNonceWordF);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 37U));
            aWandererH = aWandererH + ((RotL64(aScatter, 28U) + aOrbiterF) + RotL64(aOrbiterI, 53U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 43U) + RotL64(aOrbiterJ, 12U)) + aOrbiterH) + aNonceWordE);
            aWandererC = aWandererC + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterE, 23U)) + aOrbiterB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 58U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 58U)) + aOrbiterD);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 29U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 24U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 21U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 48U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
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

void TwistExpander_Cricket_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF62D5009028A8C05ULL + 0xB3ADD0A5AF73CC09ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x8264B4CB1906059DULL + 0xCE0F7F70942759D0ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC38479FA7F13F7DBULL + 0xBA37CDB2FF1D1D58ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x872A57C1EE11EB6BULL + 0xB93BB73F8046D736ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xA57736A17F5AF9A9ULL + 0xBF04DD3E1016803AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xFA71AC15C9FDE4E5ULL + 0x8C0DE08DBAFC90FDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE58222E890FFB50BULL + 0xC1DAA7B711513F56ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB9101CA9B3F2650BULL + 0xAC712A1452F7E924ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xB27348240D460511ULL + 0xE1E7311F40B90B0BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF8C30569E868794BULL + 0xC6B558F40195C4D3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE1F90B0AA5C99D03ULL + 0xC52D77B4E08174E7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xED9708D5E37A24EDULL + 0xF51DA207F060C497ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA396CE5EAA391CB1ULL + 0xC137AED712BFECDBULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xD090B4D6696A4667ULL + 0xABF999A9E55C2F1AULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDE061EA80AF4187DULL + 0xDF34C52F78C0B69CULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xFA66212BD3FECF29ULL + 0xCC10AC47493EB8F3ULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 4708U)) & S_BLOCK1], 26U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 5610U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 242U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 3357U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aPrevious, 3U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 3U)) + 12136097566601676613U;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 47U)) + 7969431322248040056U;
            aOrbiterK = (((aWandererF + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 10530676021510553889U) + aNonceWordK;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 8740777303075445264U) + aNonceWordO;
            aOrbiterI = (aWandererE + RotL64(aCross, 13U)) + 13249434169895564739U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 51U)) + 15529577005925628472U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 29U)) + RotL64(aCarry, 29U)) + 344627093687331562U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 35U)) + 8824277416519988893U) + aOrbiterAssignSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aWandererH + RotL64(aScatter, 42U)) + 5636276438449709875U) + aOrbiterAssignSaltD[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 2079413361031851552U) + aNonceWordG;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 7807998179168655561U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 961456853699784753U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13589392896232029112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 10733011474804473996U;
            aOrbiterH = RotL64((aOrbiterH * 361749145931578805U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15934162328347805968U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7573511217796245232U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10694563909931636155U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 4828475187337891975U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13284974329890393113U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10831075817642374287U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 13173869918669643112U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 15841507674783398167U;
            aOrbiterD = RotL64((aOrbiterD * 15632933198136963277U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14168272451055700516U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11134471485501999898U;
            aOrbiterB = RotL64((aOrbiterB * 8019507184494591705U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2611858916687822610U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17863271539727513641U;
            aOrbiterI = RotL64((aOrbiterI * 4987884722174985677U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 8874401993454249066U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 5131480593493950665U;
            aOrbiterG = RotL64((aOrbiterG * 8585874663602346121U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9366563022381918996U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 7890729519928340296U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11428572374057899517U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 35U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterI, 14U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterB, 48U)) + aOrbiterD);
            aWandererA = aWandererA + (((RotL64(aIngress, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterF) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterI, 13U)) + aWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterH, 5U)) + aOrbiterF) + aNonceWordM);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 53U)) + aOrbiterE) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 27U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterH, 42U)) + aOrbiterG) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + RotL64(aWandererG, 57U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 12888U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 13315U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 14043U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 10959U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneD[((aIndex + 12388U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCarry, 51U) ^ RotL64(aIngress, 24U)) ^ (RotL64(aCross, 39U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (aWandererG + RotL64(aScatter, 29U)) + 8604208734152026945U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 54U)) + 1374329953253889829U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 21U)) + 5779278910548228339U) + aOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aCross, 35U)) + 17670451230882805140U;
            aOrbiterC = (((aWandererJ + RotL64(aPrevious, 43U)) + RotL64(aCarry, 53U)) + 8193848740764866860U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererI + RotL64(aIngress, 5U)) + 15801168428145650104U) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aCross, 39U)) + RotL64(aCarry, 43U)) + 2584718176087499066U;
            aOrbiterJ = (((aWandererC + RotL64(aScatter, 60U)) + RotL64(aCarry, 29U)) + 14950366247822737997U) + aNonceWordM;
            aOrbiterB = (aWandererH + RotL64(aCross, 47U)) + 9779293225265670135U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8688968319288372383U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 13665723186950342601U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 292035540396910837U), 11U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterC) + 9395428688359973510U) + aOrbiterUpdateSaltA[((aIndex + 20U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2152719218018108418U;
            aOrbiterI = RotL64((aOrbiterI * 15271961483518392671U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1350324137411377992U) + aNonceWordF;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8729317951386057921U;
            aOrbiterG = RotL64((aOrbiterG * 6008790836417785083U), 3U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 6317310451893678411U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 10175620379041384281U;
            aOrbiterC = RotL64((aOrbiterC * 14079679617394330781U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1203082119358827708U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 523869107818193101U;
            aOrbiterK = RotL64((aOrbiterK * 4629501113595689157U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 4028324959540432983U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 15447631947468213912U;
            aOrbiterJ = RotL64((aOrbiterJ * 6037306615787729185U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 14225888694733041031U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterG) ^ 11925000696281947629U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 4337022940520411253U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 15015531024930608745U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 16752579225076943550U;
            aOrbiterF = RotL64((aOrbiterF * 15551083683579981439U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 2432733494869267901U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 10103430321388601485U;
            aOrbiterE = RotL64((aOrbiterE * 18372919379972432569U), 29U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterK, 44U);
            aIngress = aIngress + (RotL64(aOrbiterC, 27U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 37U));
            aIngress = aIngress + RotL64(aOrbiterA, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 52U) + aOrbiterJ) + RotL64(aOrbiterF, 42U));
            aWandererH = aWandererH + ((((RotL64(aCross, 29U) + RotL64(aOrbiterE, 11U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 3U) + aOrbiterC) + RotL64(aOrbiterA, 51U));
            aWandererF = aWandererF + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterG, 23U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 12U) + aOrbiterE) + RotL64(aOrbiterC, 30U)) + aNonceWordH) + aWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aNonceWordC);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + RotL64(aOrbiterK, 3U)) + aOrbiterI) + aNonceWordP);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterJ, 47U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 58U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererG, 20U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22222U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneD[((aIndex + 18280U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 23680U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 20578U)) & S_BLOCK1], 30U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19115U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 20907U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCross, 5U)) + (RotL64(aCarry, 42U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterE = (aWandererJ + RotL64(aPrevious, 5U)) + 4259993311776766595U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 11U)) + 2857813330021126753U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aScatter, 43U)) + 1345396841329442896U) + aNonceWordP;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 52U)) + 320992148982301024U) + aOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererD + RotL64(aScatter, 19U)) + 5619109532065293074U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 47U)) + 10380157329426706345U) + aNonceWordC;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 12449831150625409695U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 36U)) + RotL64(aCarry, 29U)) + 7847096607042268396U;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 43U)) + 11707184096803214678U) + aNonceWordB;
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9893643746186827088U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 333687403830908774U;
            aOrbiterB = RotL64((aOrbiterB * 17911256836121454271U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13837360705077441580U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4367119682175710689U;
            aOrbiterK = RotL64((aOrbiterK * 10295744669174603401U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 1193493435041306784U) + aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15062951612027370606U;
            aOrbiterA = RotL64((aOrbiterA * 2509383510565136549U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 16000173839235429105U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 15294482444605409961U;
            aOrbiterD = RotL64((aOrbiterD * 1031800997944302665U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 5720749055549773527U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 17248674962996093668U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 15730637462755795591U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16956840483882091059U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterJ) ^ 9637715107943515594U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterE = RotL64((aOrbiterE * 8878362378343603463U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 7147495779349862274U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 7508890985889484275U;
            aOrbiterC = RotL64((aOrbiterC * 17728368447504622035U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 4407738164617959366U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17027017782352660454U;
            aOrbiterG = RotL64((aOrbiterG * 417183060881259295U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 3174658601748235285U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 9779053567370714831U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6383245776181968033U), 47U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterD, 56U);
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aIngress, 22U) + RotL64(aOrbiterE, 4U)) + aOrbiterA) + aNonceWordF);
            aWandererJ = aWandererJ + (((RotL64(aCross, 43U) + aOrbiterJ) + RotL64(aOrbiterD, 27U)) + aNonceWordH);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterE, 39U));
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 5U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterH, 53U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterH, 43U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterG, 11U)) + aNonceWordM) + aWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 35U)) + aOrbiterE) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterH, 20U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 25070U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneC[((aIndex + 27978U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 30898U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30390U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31861U)) & S_BLOCK1], 18U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 26324U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 57U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterC = (aWandererH + RotL64(aScatter, 47U)) + 3248574644570178787U;
            aOrbiterF = (aWandererF + RotL64(aCross, 5U)) + 4506961512959200024U;
            aOrbiterB = ((aWandererG + RotL64(aIngress, 39U)) + RotL64(aCarry, 57U)) + 8423739774540738590U;
            aOrbiterD = (((aWandererJ + RotL64(aPrevious, 23U)) + 6593975869641735337U) + aOrbiterAssignSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterH = ((aWandererD + RotL64(aCross, 18U)) + 16441716090557369103U) + aOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 43U)) + 7936601450453207914U) + aNonceWordM;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 13333752583560167065U;
            aOrbiterK = (aWandererE + RotL64(aIngress, 57U)) + 8013703284795432973U;
            aOrbiterI = ((aWandererA + RotL64(aPrevious, 52U)) + RotL64(aCarry, 11U)) + 2349852779887439236U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5318539364763284138U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 11450957608502944376U;
            aOrbiterB = RotL64((aOrbiterB * 1957880366707810635U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9058992558327552687U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 632095686920230926U;
            aOrbiterH = RotL64((aOrbiterH * 12460364388358520799U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14734218428913777098U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 16344357661370784442U;
            aOrbiterJ = RotL64((aOrbiterJ * 15049472842002138369U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2981145363531184308U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 14176472085175714494U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 2584623327412130939U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 11198457590069700889U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 952584436750426828U) ^ aOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1165713888651280355U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 4311591763498985972U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16194341833989936369U;
            aOrbiterG = RotL64((aOrbiterG * 9997934560195932575U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 7560794022401107431U) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 10683789740265711603U) ^ aOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 15637823045351977883U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 11614366395125937178U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 10750771385100564416U;
            aOrbiterI = RotL64((aOrbiterI * 4987921274272444283U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 2934697034132204529U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 4646873794658020363U;
            aOrbiterD = RotL64((aOrbiterD * 10555456865641580175U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 14U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 27U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterG) + RotL64(aOrbiterK, 47U)) + aNonceWordN);
            aWandererD = aWandererD + (((RotL64(aIngress, 27U) + RotL64(aOrbiterF, 4U)) + aOrbiterB) + aNonceWordG);
            aWandererA = aWandererA ^ (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterI, 23U)) + aWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterK, 43U)) + aOrbiterF) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 41U) + aOrbiterG) + RotL64(aOrbiterC, 11U)) + aWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 47U) + RotL64(aOrbiterG, 51U)) + aOrbiterF) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 23U) + aOrbiterD) + RotL64(aOrbiterK, 58U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 52U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + RotL64(aCarry, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererA, 24U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Cricket_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterE = 0;
    std::uint64_t aOrbiterF = 0; std::uint64_t aOrbiterH = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;
    std::uint64_t aOrbiterK = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDA14BA26AECA60BFULL + 0xE21FD87C373BB583ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xD8273EADC68AF12DULL + 0xA506795BC4FD8709ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0x950FBB6B5DF33675ULL + 0x8722C9D75C2A80D3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x937EDDB1FCC43021ULL + 0xA120ED39E63B3AF5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA6FA84A8974F01DBULL + 0x8E3D94BC0EB49262ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xE9B69278DF36C9EDULL + 0xD2D9E6629708D77DULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x8619C1CEFDCE0FDBULL + 0x81F70BF4EF21FE93ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x98E87C507914D4ADULL + 0xBD9045D5635B70E7ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xA44A13180AD9BCA1ULL + 0xDDDD933EC929ED5CULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xBA75868168B6F5CFULL + 0x9D64544BCDD1D83DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8D8A01315DB05A8FULL + 0xEFDBB4487DEC8970ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xD9205A67289C3EC5ULL + 0xCC59057B048E56EDULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0x990E3C11649E02A3ULL + 0x9D0D0F91550DD461ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE1C0764BAEBEE079ULL + 0x9CFE5F83D7FAF537ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x8CAB2F96496608F3ULL + 0xF4E99FB1C2EEED26ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xA84BAE1DD96A0FE9ULL + 0xD549E3A70E5380C2ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneC, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneB, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1648U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((aIndex + 8122U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 6703U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2043U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4385U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 6U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererC + RotL64(aIngress, 5U)) + 10726035965553989335U) + aNonceWordA;
            aOrbiterC = ((((aWandererH + RotL64(aCross, 13U)) + RotL64(aCarry, 39U)) + 967354339530195662U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 42U)) + 10834593005478605624U;
            aOrbiterH = ((((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 57U)) + 1012888282838656933U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 19U)) + 15283530351725183253U) + aNonceWordD;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11724495956731703750U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 4288330117317505776U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2738997410474076757U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 10894778070022873473U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15563886747621617467U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 17884709931569040065U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 11182488628562891937U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 10420140066310588580U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 13898299782819948719U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 11775138062167543111U) + aNonceWordO;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 16545391898578161683U) ^ aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14588306527161321535U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1550144656312299266U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 14903504853138279883U;
            aOrbiterH = RotL64((aOrbiterH * 8003033561266164387U), 47U);
            //
            aIngress = RotL64(aOrbiterA, 18U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterH, 46U)) + RotL64(aCarry, 37U)) + aNonceWordP);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterH, 19U)) + aOrbiterB);
            aWandererH = aWandererH + (((((RotL64(aPrevious, 6U) + RotL64(aOrbiterJ, 37U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aNonceWordI) + aWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterJ, 3U)) + aWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterB, 27U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererA, 52U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13478U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneC[((aIndex + 13959U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13613U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8597U)) & S_BLOCK1], 10U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 15979U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 11245U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 13U) ^ RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterK = (aWandererB + RotL64(aIngress, 37U)) + 10805654776556844351U;
            aOrbiterH = ((aWandererE + RotL64(aScatter, 29U)) + 582794182442795335U) + aNonceWordP;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 2858343650974681068U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 8189584049022064284U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterF = ((((aWandererJ + RotL64(aScatter, 20U)) + RotL64(aCarry, 57U)) + 1565100751996962893U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 8062028016947611891U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8280504280578451745U) ^ aOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5212851648135050483U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11326869194491655350U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 1671695656567777163U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 7511554500524257921U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 2349843105293943452U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13015545152052004254U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 1316662811685429983U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 16703354404749291869U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8713231044374305801U) ^ aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9242480982197688625U), 13U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 11118401674497783533U) + aNonceWordJ;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14857556493734710364U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 3452566050389715195U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 54U) + aOrbiterH) + RotL64(aOrbiterK, 43U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterI, 58U)) + RotL64(aCarry, 27U)) + aNonceWordL);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterK, 27U)) + aWandererUpdateSaltC[((aIndex + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 41U) + aOrbiterF) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 57U)) + aNonceWordK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterJ, 19U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 38U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererI, 57U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 3
        // ingress from: aWorkLaneB, aOperationLaneD, aFireLaneA
        // ingress directions: aWorkLaneB forward forced, aOperationLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneA, aOperationLaneB, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aOperationLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20948U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneD[((aIndex + 22194U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19093U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19943U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 18486U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 21331U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 44U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterJ = ((((aWandererK + RotL64(aIngress, 56U)) + RotL64(aCarry, 53U)) + 8767379393098711499U) + aOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (((aWandererC + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 7168159491580816433U) + aOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 37U)) + 9879279829061883406U) + aNonceWordP;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 43U)) + 10537167136053399303U) + aNonceWordJ;
            aOrbiterI = (aWandererB + RotL64(aCross, 5U)) + 2839070018069188936U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 13844278063968429732U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 11278946626186474646U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6601953972456332355U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11798425216660557799U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7618446090703335192U;
            aOrbiterF = RotL64((aOrbiterF * 7168757300685156779U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 695423597006983660U) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 14344728202803488813U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5168825904902285909U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11656100506575697086U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 10384358779985773937U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 247494692039140973U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 17585001605131977341U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterK) ^ 9964478171465522911U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 13484044854790175315U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterB, 41U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterJ, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterF, 21U)) + aOrbiterB) + aNonceWordI);
            aWandererC = aWandererC + (((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterK, 12U)) + RotL64(aCarry, 11U)) + aNonceWordF) + aWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterI, 37U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterJ) + RotL64(aCarry, 29U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 29U)) + aOrbiterI) + aWandererUpdateSaltB[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 29284U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 28955U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30614U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31533U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 28682U)) & S_BLOCK1], 19U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 29355U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 28619U)) & S_BLOCK1], 29U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 40U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterF = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 3U)) + 6973892330986118220U) + aNonceWordA;
            aOrbiterH = (((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 35U)) + 9886813896272094864U) + aNonceWordK;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 37U)) + 10996306582517553173U) + aOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 8490648283899856223U) + aNonceWordO;
            aOrbiterE = (((aWandererB + RotL64(aScatter, 18U)) + 105141713530704655U) + aOrbiterAssignSaltD[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordE;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3114337422810562588U) + aOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 980857684690886131U) ^ aNonceWordN;
            aOrbiterA = RotL64((aOrbiterA * 17407927633910728721U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6562042345807072665U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 15665371138706353619U) ^ aNonceWordP;
            aOrbiterF = RotL64((aOrbiterF * 8086237578564620623U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 18113013571374375028U) + aNonceWordB;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 17405346422601997299U;
            aOrbiterE = RotL64((aOrbiterE * 11162604605443005253U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 5130876096426182506U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 1813821672299154629U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15478100342425611875U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 15793814882743306728U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 13925299440495476399U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12049601510660117401U), 53U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterF, 53U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterE) + RotL64(aOrbiterF, 57U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 29U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aNonceWordD) + aWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 6U) + RotL64(aOrbiterH, 37U)) + aOrbiterA) + aNonceWordJ);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterH, 12U));
            aWandererB = aWandererB + (((((RotL64(aIngress, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterK) + RotL64(aCarry, 19U)) + aNonceWordL) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 35U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 11U));
            aCarry = aCarry + RotL64(aWandererA, 48U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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

void TwistExpander_Cricket_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x8A310179382F90E1ULL + 0xC544EB2F76E5EC46ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x910C9E9DCD964A95ULL + 0xBDA8DEC0339A5AEDULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBDAB071808622A1BULL + 0xFA2A33735F7F2071ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x8E8335F9B789154FULL + 0xCB11057D38430AEDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xB5CEFFD3C3E930BDULL + 0xEB2E898BEA81576AULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xA0318CF18AAE90FFULL + 0xD1DC6F41B0EFAB46ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xAD8D4EE5C3437B7DULL + 0xCBF461EF758CF523ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xC80998A32AC7C207ULL + 0xC6EAE8BE455CCB0CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF5FABEBF104E8A2BULL + 0xCE98DE5C2299AE61ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8019B7B836024BB9ULL + 0x88F7E0615E92B724ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xAD8B909B1C9F2A5FULL + 0x98810EA1623A07A7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x9E3A197C1F70AC25ULL + 0xAB1767D5F16CBCF7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xCC2F08D46AD6C623ULL + 0xC2C53F91FB6383C8ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8169220F4BA7DE17ULL + 0xA3198F24D0E20861ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x919BFDC80A09A679ULL + 0x9AA9E4E7E5FC1FA6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8D61BBA68A0FE6C1ULL + 0xD2C0EA7B9AC923A2ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aOperationLaneA, aWorkLaneA, aFireLaneB, aOperationLaneB, aWorkLaneB, aOperationLaneC, aFireLaneA, aWorkLaneC, aOperationLaneD, aFireLaneD
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aOperationLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 5506U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneB[((aIndex + 2566U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 614U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3864U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 7263U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7009U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 48U) + RotL64(aIngress, 19U)) ^ (RotL64(aCross, 5U) ^ RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 51U)) + 12029393034357490020U) + aNonceWordH;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 57U)) + RotL64(aCarry, 53U)) + 4526754731580694987U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 13U)) + 17060419646421271853U) + aNonceWordK;
            aOrbiterB = ((((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 41U)) + 4128488893837059683U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordB;
            aOrbiterA = (aWandererF + RotL64(aCross, 6U)) + 12706894827547160110U;
            aOrbiterK = ((((aWandererC + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 12506324593645825056U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordI;
            aOrbiterG = (aWandererG + RotL64(aPrevious, 19U)) + 12581344490649250025U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 14357032418199130132U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 15341977701796331249U) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 6332369248718076031U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7086602307544733241U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 12398300065276832486U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18157408831225635333U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 2499745046076601988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7249361592814001829U;
            aOrbiterG = RotL64((aOrbiterG * 14597139848072319685U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3254456186337366437U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 3472973415969046680U;
            aOrbiterB = RotL64((aOrbiterB * 14583566953969168353U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 7905718972111691591U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 15941413652144021522U;
            aOrbiterJ = RotL64((aOrbiterJ * 3473779492962783565U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 10583964125960308762U) + aOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterE) ^ 13659925272340853715U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterA = RotL64((aOrbiterA * 16708294803316630743U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 9487054537489454887U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterJ) ^ 13287757570441887517U) ^ aOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 17351439045329892107U), 13U);
            //
            aIngress = RotL64(aOrbiterG, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterK, 13U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterG, 51U)) + aOrbiterK) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 4U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 11U)) + aOrbiterE);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 29U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 21U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + aNonceWordC);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 4U) + aOrbiterA) + RotL64(aOrbiterJ, 35U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 21U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 54U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererC, 29U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aOperationLaneB
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 12202U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 13833U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 13595U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8215U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8314U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aOperationLaneB[((aIndex + 16381U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aIngress, 53U)) ^ (RotL64(aCarry, 13U) + RotL64(aPrevious, 26U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterG = ((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 10915618884692072446U;
            aOrbiterK = (((aWandererA + RotL64(aPrevious, 11U)) + RotL64(aCarry, 23U)) + 12634922308499254909U) + aNonceWordN;
            aOrbiterB = ((((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 6533934734564499389U) + aOrbiterAssignSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordE;
            aOrbiterJ = (aWandererK + RotL64(aCross, 57U)) + 6744203303756105181U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 41U)) + 13086782386652045658U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 48U)) + 5693840533331397822U) + aNonceWordG;
            aOrbiterE = (((aWandererH + RotL64(aCross, 23U)) + 1803663542535024611U) + aOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordB;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3597219300593287708U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1429753448204448904U;
            aOrbiterB = RotL64((aOrbiterB * 10927459251773273143U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17229017825587322715U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 1137574712801062932U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 3645832160939819415U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2401991077004083378U) + aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 1332473247826139292U;
            aOrbiterJ = RotL64((aOrbiterJ * 15029831858261506447U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 11730946340796899885U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 15319163439700390962U;
            aOrbiterI = RotL64((aOrbiterI * 1349242001887975499U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 4744141870145159917U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6067132201862688684U) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 6046100687757836027U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 14991509179286371800U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 4342608825699398682U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 10240526103933275875U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 3727521409410742075U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 3302027219498304367U;
            aOrbiterC = RotL64((aOrbiterC * 12153634588200479559U), 35U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterB, 37U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 50U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 51U)) + aOrbiterB) + aNonceWordD) + aWandererUpdateSaltB[((aIndex + 12U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 60U)) + aOrbiterG) + aNonceWordF);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 19U)) + aOrbiterC);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 41U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (RotL64(aWandererI, 19U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 24U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneC
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aFireLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 17332U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneD[((aIndex + 17424U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 22390U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24431U)) & S_BLOCK1], 60U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 18506U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 21954U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 53U) + RotL64(aCross, 34U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((aWandererA + RotL64(aScatter, 37U)) + 2225397913940961213U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 8342544893601343643U) + aNonceWordN;
            aOrbiterD = ((aWandererG + RotL64(aCross, 19U)) + 162922186381417187U) + aNonceWordL;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 43U)) + RotL64(aCarry, 35U)) + 11660218373710972210U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 11U)) + 14909034764605802354U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 16776955237009701511U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 30U)) + 5834487809188925253U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1498492772767040320U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4161765458781579617U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15535994410289065281U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 10511923076962447765U) + aOrbiterUpdateSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 8575954471692620021U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 12526744988828982731U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6536325446331340573U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1790628986900286346U;
            aOrbiterA = RotL64((aOrbiterA * 5262997114200816715U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 2623814807619278590U) + aOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 11676970995834706612U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 10057461115132434901U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 13836786354224256591U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 6293096163612129260U;
            aOrbiterC = RotL64((aOrbiterC * 8977954126326217153U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 4271144764978661248U) + aNonceWordA;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 15938494256992560202U;
            aOrbiterI = RotL64((aOrbiterI * 10004841288382726739U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11038155227307702976U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 12408749795071243930U;
            aOrbiterF = RotL64((aOrbiterF * 5527720475032868855U), 35U);
            //
            aIngress = RotL64(aOrbiterI, 22U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 21U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + RotL64(aOrbiterB, 53U)) + aOrbiterC) + RotL64(aCarry, 39U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 50U) + RotL64(aOrbiterE, 43U)) + aOrbiterD) + aNonceWordC);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterE) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 19U)) + aNonceWordG);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterA, 35U)) + aOrbiterI) + aWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 57U) + aOrbiterC) + RotL64(aOrbiterE, 29U)) + aNonceWordK) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterC, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 28U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererI, 39U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 27606U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 25942U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 28536U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27492U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27525U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28996U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aIngress, 48U)) + (RotL64(aCarry, 5U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 13U)) + RotL64(aCarry, 27U)) + 15904465836916519864U) + aOrbiterAssignSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 17725629806317789307U) + aNonceWordA;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 53U)) + RotL64(aCarry, 51U)) + 13794170125914914828U;
            aOrbiterF = ((aWandererG + RotL64(aScatter, 23U)) + 2149055907476874332U) + aNonceWordD;
            aOrbiterJ = (aWandererE + RotL64(aCross, 35U)) + 5342047776745074649U;
            aOrbiterD = (((aWandererD + RotL64(aIngress, 4U)) + 8268148484060546838U) + aOrbiterAssignSaltE[((aIndex + 3U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 29U)) + 10821151364028563719U) + aNonceWordH;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 4294213820894407378U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 10884726101307943090U;
            aOrbiterG = RotL64((aOrbiterG * 1116128870387229159U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 16432210042202444824U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 15196602644336228055U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12680438355124070237U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 14117787670220328165U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 219833877949480215U;
            aOrbiterE = RotL64((aOrbiterE * 10736293047771972173U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3326396981881473962U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14918513066311426279U;
            aOrbiterD = RotL64((aOrbiterD * 14269763278564574663U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 11795234681370163206U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 3068267285352664813U;
            aOrbiterB = RotL64((aOrbiterB * 15746255933920904619U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 245233356957999496U) + aNonceWordO;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 709926406353796673U;
            aOrbiterF = RotL64((aOrbiterF * 13627039596842073595U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 5378105439430271038U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 10114555061122044430U) ^ aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 5351295043424885549U), 43U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 23U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterG, 11U)) + aOrbiterE) + aWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 26U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 39U)) + aNonceWordC);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterE, 27U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterB, 57U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterI, 51U));
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 53U) + aOrbiterD) + RotL64(aOrbiterE, 36U)) + aNonceWordK) + aWandererUpdateSaltD[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 43U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 36U) ^ aWandererI);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Cricket_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xEBA4840A9FDF7239ULL + 0xCD3714F9CFFA1B1FULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xE820BF9C4F91B447ULL + 0xA0A2815E49B2110DULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xA2B42393ED1D0F45ULL + 0xAB6AAA21384DB93FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBA29D45A36A15BB5ULL + 0xF003096066B263C0ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xB42174D1ABB279C5ULL + 0xEEC61CE3F2B6DEC9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xC775B2C05A86A2B7ULL + 0xE0C30A596DA2EB48ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF0D28E393122AC35ULL + 0x8C41F903CFB16790ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA8D80E16C213A6C1ULL + 0xB1D1A66E5321AA7DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xFFA541B2DFD16CF1ULL + 0xC062A59B084E9D17ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xA26F5530EC292E05ULL + 0xE1EA4E92529582B3ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD2D9CFB86E8A4C03ULL + 0xA2A0BFE4647252D3ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC21624C3915B1473ULL + 0x80D9E4285427C95FULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC3DDDB70E1D7A917ULL + 0x8D878064FCC2DC4CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB6105FCA0584F803ULL + 0xD47BF13170EBB306ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCB5EBCAE0E724C27ULL + 0xE5E47BF8F78E4364ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA7C3B49763A2D0ADULL + 0xF61E6BF63E4B8225ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aOperationLaneB, aExpandLaneA, aFireLaneC, aFireLaneD, aExpandLaneB, aFireLaneB, aOperationLaneC, aExpandLaneC, aOperationLaneA, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6260U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneB[((aIndex + 3732U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 1301U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 5019U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 3156U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 5414U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCross, 11U) + RotL64(aIngress, 23U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterH = ((aWandererJ + RotL64(aPrevious, 11U)) + 13650869943246163567U) + aNonceWordC;
            aOrbiterB = ((aWandererI + RotL64(aIngress, 30U)) + RotL64(aCarry, 3U)) + 3435284932011770999U;
            aOrbiterA = ((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 51U)) + 12388155658186776579U;
            aOrbiterI = (((aWandererB + RotL64(aScatter, 53U)) + RotL64(aCarry, 23U)) + 2374345913955712039U) + aOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 37U)) + 6095094526980292156U) + aNonceWordJ;
            aOrbiterD = (aWandererF + RotL64(aCross, 21U)) + 4965147025852444174U;
            aOrbiterG = ((aWandererC + RotL64(aIngress, 3U)) + 3261881216269075298U) + aOrbiterAssignSaltE[(((31U - aIndex) + 29U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 4939780217097329222U) + aNonceWordE;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3019862009792676287U;
            aOrbiterA = RotL64((aOrbiterA * 2452316208025448747U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 901910626217143974U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 3647055146712366383U) ^ aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 1792602402476450009U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 7731765438957392967U) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 13409819457393479741U;
            aOrbiterK = RotL64((aOrbiterK * 3345078200262410715U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5415832109107794258U) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8876738832313114471U;
            aOrbiterH = RotL64((aOrbiterH * 1304277600444504135U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 17135570542519390359U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 2373193062766802082U;
            aOrbiterD = RotL64((aOrbiterD * 4213691513185791519U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16318403285501718552U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 8456043288604687045U) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 10556964529144571683U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 10572534930284516528U) + aOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14616251186735204677U;
            aOrbiterI = RotL64((aOrbiterI * 2048651204265459805U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 47U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltF[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + RotL64(aOrbiterI, 27U)) + aOrbiterG) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 54U) + aOrbiterB) + RotL64(aOrbiterD, 51U)) + aNonceWordM);
            aWandererF = aWandererF + ((((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterG, 57U)) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 44U)) + aOrbiterD) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + RotL64(aOrbiterB, 35U)) + aOrbiterH) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 56U));
            aCarry = aCarry + (RotL64(aWandererA, 13U) ^ aWandererG);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererB, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneD
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8694U)) & S_BLOCK1], 34U) ^ RotL64(aWorkLaneC[((aIndex + 10018U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 16036U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16315U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 11730U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 9065U)) & S_BLOCK1], 12U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 24U) + RotL64(aPrevious, 39U)) ^ (RotL64(aCross, 5U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 39U)) + 479672811032092393U;
            aOrbiterK = (((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 23U)) + 18061121631394564425U) + aNonceWordP;
            aOrbiterH = (((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 5U)) + 14237400452740566065U) + aNonceWordL;
            aOrbiterJ = (((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 37U)) + 6723123812257706134U) + aOrbiterAssignSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aPrevious, 22U)) + 4247997188026499248U) + aOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererF + RotL64(aCross, 3U)) + 1939107415066134869U;
            aOrbiterC = (aWandererH + RotL64(aIngress, 29U)) + 3912640123546395979U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 8295478436553964298U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 3218960600711526885U;
            aOrbiterH = RotL64((aOrbiterH * 15443507655470278069U), 21U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 5874096203353388890U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 10294536533673023358U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15561710414949058923U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 11268561953904130747U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16693201256788898423U;
            aOrbiterG = RotL64((aOrbiterG * 16291987237693567209U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 7550969634681894654U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 9501647424602245869U;
            aOrbiterJ = RotL64((aOrbiterJ * 11265865222096866605U), 53U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 8881869255994319423U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16770136406906800016U;
            aOrbiterK = RotL64((aOrbiterK * 1782039587385512923U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 16185384746435761363U) + aNonceWordA;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13841034186650721627U) ^ aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12000155593277035447U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 15229062695864608309U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3576122704615303733U;
            aOrbiterE = RotL64((aOrbiterE * 2433987493885779279U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aCross, 57U) + aOrbiterA) + RotL64(aOrbiterK, 41U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 47U)) + aOrbiterH);
            aWandererA = aWandererA + (((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterH) + aWandererUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + aNonceWordK) + aWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 13U) + aOrbiterC) + RotL64(aOrbiterH, 18U)) + RotL64(aCarry, 41U)) + aNonceWordC);
            aWandererD = aWandererD ^ (((RotL64(aCross, 37U) + aOrbiterK) + RotL64(aOrbiterE, 57U)) + aNonceWordD);
            aWandererF = aWandererF + (((RotL64(aPrevious, 6U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 52U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 3U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneC
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 20643U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((aIndex + 19168U)) & S_BLOCK1], 20U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19970U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17803U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22777U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 19555U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 6U) + RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterB = (((aWandererE + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 11998579547770778580U) + aOrbiterAssignSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aIngress, 13U)) + 8409465187298704610U;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 43U)) + 3470222286110333500U) + aOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 5704486785203069994U) + aNonceWordC;
            aOrbiterK = (aWandererJ + RotL64(aCross, 29U)) + 10334944660253279633U;
            aOrbiterF = (aWandererB + RotL64(aScatter, 6U)) + 7626852700722567477U;
            aOrbiterH = ((aWandererA + RotL64(aIngress, 57U)) + 14631310754943209743U) + aNonceWordB;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 807160297237854120U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5624154783624196107U;
            aOrbiterA = RotL64((aOrbiterA * 2404066593958052159U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 4971444394698940423U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 6340057638461027062U;
            aOrbiterF = RotL64((aOrbiterF * 12027586111086798629U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 9003019862787819481U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 13632057463595873033U;
            aOrbiterC = RotL64((aOrbiterC * 12575202147280216765U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 12766104026871797746U) + aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 4062118445824915939U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13130770039048080701U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5258212525426469978U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9956946981015983939U) ^ aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8106382657040497669U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 10837606223056473999U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13292864885504191134U;
            aOrbiterK = RotL64((aOrbiterK * 4445739587553669471U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 166087925900318658U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6786842221885441388U;
            aOrbiterB = RotL64((aOrbiterB * 4411147600413147773U), 41U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterK, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 19U));
            aIngress = aIngress + RotL64(aOrbiterB, 6U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aIngress, 3U) + RotL64(aOrbiterC, 30U)) + aOrbiterB) + RotL64(aCarry, 21U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterF, 57U)) + aOrbiterG) + aNonceWordI) + aWandererUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aCross, 43U) + RotL64(aOrbiterB, 47U)) + aOrbiterA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 58U) + RotL64(aOrbiterC, 11U)) + aOrbiterA) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 37U) + RotL64(aOrbiterF, 37U)) + aOrbiterK) + RotL64(aCarry, 39U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterK, 23U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterA, 3U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererF, 60U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneA forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28809U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 27558U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 25856U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30025U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26483U)) & S_BLOCK1], 60U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 31396U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCarry, 54U)) ^ (RotL64(aCross, 37U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterH = (aWandererI + RotL64(aCross, 41U)) + 15036852811491820366U;
            aOrbiterJ = (((aWandererG + RotL64(aIngress, 13U)) + RotL64(aCarry, 41U)) + 305637140752898475U) + aNonceWordK;
            aOrbiterC = (((aWandererC + RotL64(aScatter, 19U)) + 11948631574496129610U) + aOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 53U)) + 5321623592482991426U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1]) + aNonceWordA;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 26U)) + RotL64(aCarry, 11U)) + 4075270159062690728U;
            aOrbiterI = (aWandererF + RotL64(aIngress, 3U)) + 15111580500356908928U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 7244150695504160363U) + aNonceWordO;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 5131563519577488862U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 5881954992088651371U;
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12780935808751507998U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12599159643925470226U;
            aOrbiterF = RotL64((aOrbiterF * 17690046932587062701U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9466589929741834066U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6093158735705189789U;
            aOrbiterJ = RotL64((aOrbiterJ * 7453778295800853653U), 51U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterF) + 17461243886150519249U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordN;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 15456408913739900718U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 16093292401746174671U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11260643903290392780U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7870342756041882616U;
            aOrbiterA = RotL64((aOrbiterA * 2431528656086173419U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 134484990005888936U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10626896209992890407U;
            aOrbiterH = RotL64((aOrbiterH * 12034131076645285597U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 14031164129515132292U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1771835705730244212U;
            aOrbiterI = RotL64((aOrbiterI * 186981668443596623U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterI, 29U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 21U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aNonceWordF);
            aWandererC = aWandererC + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 3U)) + aNonceWordD);
            aWandererF = aWandererF ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + aNonceWordI);
            aWandererA = aWandererA + ((RotL64(aCross, 41U) + aOrbiterI) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 34U) + RotL64(aOrbiterA, 5U)) + aOrbiterF) + aWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 58U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aWandererUpdateSaltF[((aIndex + 11U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 54U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererG, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Cricket_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDAC00C79E3EEAE65ULL + 0xA52B5D663E6C0525ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDE1135ADFB936C21ULL + 0xBB27604592214BA1ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xBD50C4F0CDD89445ULL + 0xE5187F1F63A7D662ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0x84F3299F54D20597ULL + 0xC7A5477CDC034833ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x933B7C5FF2C81271ULL + 0xCC0E34DF1E572922ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x810C1B74033436A1ULL + 0xA81B1AE0A4FDB39FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xCAE84D3F48A94FAFULL + 0xD2B928F5790A25BAULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xD1133D5F92690DFDULL + 0xC8BCF517220CF88BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x909260839CDEF56DULL + 0xFABCDE1263052619ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0x8FB884348BC92653ULL + 0x89804FB8C2011662ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF68E8F89D8C8D0A5ULL + 0xD0EB4F099DE1A67BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xBEE88F7EBAAD02D1ULL + 0xFB0F68D468E86519ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xA1599873FC840F91ULL + 0xC8E733563D1489BAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x8665991939AB5421ULL + 0xFC4B6176C0F692EEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFB7095DB5146AACFULL + 0xF85257E2D033AB88ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBC4406FC256FE571ULL + 0xD64A571E2A732A27ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aWorkLaneC, aOperationLaneA, aFireLaneD, aFireLaneA, aOperationLaneB, aFireLaneC, aWorkLaneD, aOperationLaneC, aWorkLaneA, aWorkLaneB
        // write to: aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // kdf_b_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aWorkLaneC
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2834U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneB[((aIndex + 7668U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 6702U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 731U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 1809U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 6521U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 29U)) + (RotL64(aCross, 6U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterC = (((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 27U)) + 12136097566601676613U) + aNonceWordD;
            aOrbiterH = ((aWandererE + RotL64(aPrevious, 34U)) + 7969431322248040056U) + aOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aWandererK + RotL64(aIngress, 19U)) + 10530676021510553889U;
            aOrbiterE = (aWandererF + RotL64(aCross, 29U)) + 8740777303075445264U;
            aOrbiterJ = (((aWandererA + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 13249434169895564739U) + aNonceWordE;
            aOrbiterD = (aWandererB + RotL64(aCross, 21U)) + 15529577005925628472U;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 57U)) + 344627093687331562U;
            aOrbiterF = ((aWandererD + RotL64(aScatter, 11U)) + 8824277416519988893U) + aNonceWordN;
            aOrbiterI = ((aWandererG + RotL64(aIngress, 60U)) + 5636276438449709875U) + aNonceWordH;
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 53U)) + 2079413361031851552U) + aOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = ((aWandererI + RotL64(aCross, 47U)) + RotL64(aCarry, 43U)) + 7807998179168655561U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13589392896232029112U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10733011474804473996U;
            aOrbiterB = RotL64((aOrbiterB * 361749145931578805U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 15934162328347805968U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7573511217796245232U;
            aOrbiterD = RotL64((aOrbiterD * 10694563909931636155U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 4828475187337891975U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 13284974329890393113U;
            aOrbiterC = RotL64((aOrbiterC * 10831075817642374287U), 51U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 13173869918669643112U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 15841507674783398167U;
            aOrbiterI = RotL64((aOrbiterI * 15632933198136963277U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 14168272451055700516U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11134471485501999898U;
            aOrbiterJ = RotL64((aOrbiterJ * 8019507184494591705U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 2611858916687822610U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 17863271539727513641U;
            aOrbiterG = RotL64((aOrbiterG * 4987884722174985677U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 8874401993454249066U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5131480593493950665U;
            aOrbiterF = RotL64((aOrbiterF * 8585874663602346121U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9366563022381918996U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 7890729519928340296U;
            aOrbiterE = RotL64((aOrbiterE * 11428572374057899517U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 131774386529223292U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 4108356674478240148U;
            aOrbiterA = RotL64((aOrbiterA * 2492753294539081613U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7651738365157869789U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 2745458108574051004U;
            aOrbiterK = RotL64((aOrbiterK * 2175955806036373729U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10492013124307434604U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12136097566601676613U;
            aOrbiterH = RotL64((aOrbiterH * 13128652803485742119U), 41U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 39U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 6U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 37U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 56U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 19U)) + aOrbiterC) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterE, 35U));
            aWandererA = aWandererA + ((RotL64(aIngress, 23U) + aOrbiterB) + RotL64(aOrbiterD, 51U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 37U)) + aOrbiterH) + aWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 30U) + aOrbiterI) + RotL64(aOrbiterJ, 27U)) + aWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 58U)) + aOrbiterD) + aNonceWordF);
            aWandererF = aWandererF + (((RotL64(aIngress, 5U) + RotL64(aOrbiterF, 39U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterH, 53U)) + aOrbiterG);
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 54U) + aOrbiterI) + RotL64(aOrbiterC, 43U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + (RotL64(aWandererC, 58U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 29U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 34U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 13122U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneC[((aIndex + 11894U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 13964U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 11012U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 12252U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 12481U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 3U)) + (RotL64(aPrevious, 22U) ^ RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (aWandererG + RotL64(aIngress, 29U)) + 16189787374324972735U;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 39U)) + 17563763730956242224U) + aNonceWordF;
            aOrbiterI = ((aWandererJ + RotL64(aScatter, 56U)) + RotL64(aCarry, 39U)) + 10572803498593789385U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 3U)) + 7713105232072974166U) + aNonceWordJ;
            aOrbiterA = (aWandererH + RotL64(aScatter, 23U)) + 10760839534772718139U;
            aOrbiterJ = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 47U)) + 13397069448391230253U;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 19U)) + 4569255679998375682U) + aOrbiterAssignSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 54U)) + 9888769350817876949U) + aOrbiterAssignSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = (((aWandererD + RotL64(aIngress, 27U)) + RotL64(aCarry, 5U)) + 11351796060878856300U) + aNonceWordL;
            aOrbiterB = (aWandererK + RotL64(aScatter, 35U)) + 18153775071965707204U;
            aOrbiterG = (aWandererE + RotL64(aCross, 5U)) + 1282846411145853435U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 16457743979262460660U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 173493260775251032U;
            aOrbiterI = RotL64((aOrbiterI * 4935807229040883505U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 3927345926316409630U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5158769729850853623U;
            aOrbiterJ = RotL64((aOrbiterJ * 2446452358663812945U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12331351600010165154U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3940794200348684050U;
            aOrbiterE = RotL64((aOrbiterE * 13248997263062075043U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 11248514843822945425U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1391497323278226522U;
            aOrbiterK = RotL64((aOrbiterK * 8376841806072565005U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 13265623528678787307U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 2802033745265647317U;
            aOrbiterD = RotL64((aOrbiterD * 3437626962562016147U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 6938444301018051844U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterJ) ^ 1086544666755559028U) ^ aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 16039728388882079889U), 27U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16156443117365816536U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3619942859562697142U;
            aOrbiterA = RotL64((aOrbiterA * 7589346043159112151U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 17681848914912743292U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 8848238631758130416U) ^ aNonceWordI;
            aOrbiterH = RotL64((aOrbiterH * 810402256099500607U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6019192027793541890U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 16917288363166352778U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 17673667086593738207U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5598218150530046752U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 17285995539011279010U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15621233176885995065U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 12380627610747299268U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 16189787374324972735U) ^ aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2144714828503219209U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 51U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((((RotL64(aCross, 4U) + RotL64(aOrbiterB, 23U)) + aOrbiterE) + RotL64(aCarry, 47U)) + aNonceWordM);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterJ, 29U)) + aOrbiterF);
            aWandererG = aWandererG + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 5U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterC, 51U));
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + aOrbiterA) + RotL64(aOrbiterF, 40U)) + aNonceWordO);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 47U));
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 48U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 20U));
            aWandererD = aWandererD + (((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterG, 27U)) + aNonceWordD);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 53U) ^ aWandererF);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererH, 51U);
            aCarry = aCarry + RotL64(aIngress, 44U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aFireLaneC
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24069U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 21813U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 17055U)) & S_BLOCK1], 34U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19559U)) & S_BLOCK1], 56U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19423U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 18391U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U)) ^ (RotL64(aCarry, 20U) + RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = (aWandererK + RotL64(aIngress, 47U)) + 10915618884692072446U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 56U)) + 12634922308499254909U) + aNonceWordF;
            aOrbiterE = (((aWandererF + RotL64(aScatter, 29U)) + RotL64(aCarry, 39U)) + 6533934734564499389U) + aOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aCross, 43U)) + RotL64(aCarry, 57U)) + 6744203303756105181U;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 29U)) + 13086782386652045658U;
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 13U)) + 5693840533331397822U) + aOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aPrevious, 3U)) + 1803663542535024611U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 41U)) + 3597219300593287708U) + aNonceWordM;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 53U)) + 1429753448204448904U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 20U)) + 17229017825587322715U) + aNonceWordC;
            aOrbiterK = (aWandererC + RotL64(aScatter, 51U)) + 1137574712801062932U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 2401991077004083378U) + aOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 1332473247826139292U;
            aOrbiterE = RotL64((aOrbiterE * 15029831858261506447U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11730946340796899885U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 15319163439700390962U;
            aOrbiterJ = RotL64((aOrbiterJ * 1349242001887975499U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4744141870145159917U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 6067132201862688684U;
            aOrbiterD = RotL64((aOrbiterD * 6046100687757836027U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 14991509179286371800U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 4342608825699398682U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 10240526103933275875U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 3727521409410742075U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 3302027219498304367U;
            aOrbiterF = RotL64((aOrbiterF * 12153634588200479559U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6039539483340398858U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 2902581519976937051U;
            aOrbiterC = RotL64((aOrbiterC * 2057584328877854239U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 12332784713738947242U) + aNonceWordB;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 13761272577223712786U) ^ aOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14930145045480030821U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 2947946397617043735U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11107014023853644521U;
            aOrbiterB = RotL64((aOrbiterB * 15030903626191481831U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 6212403196992771516U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 16107261731677426470U;
            aOrbiterK = RotL64((aOrbiterK * 13764822942405295129U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8414111492161335472U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3625937496991123221U;
            aOrbiterA = RotL64((aOrbiterA * 1736741235159600739U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 5466667339391480293U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 10915618884692072446U;
            aOrbiterH = RotL64((aOrbiterH * 14719282928172086707U), 27U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterE, 26U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 29U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterD, 43U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            aWandererG = aWandererG + ((RotL64(aCross, 34U) + aOrbiterJ) + RotL64(aOrbiterC, 60U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterF, 5U)) + aNonceWordE);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 23U) + aOrbiterI) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 35U)) + aWandererUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterH, 27U));
            aWandererE = aWandererE + (((((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 35U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aNonceWordA) + aWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterC, 39U)) + aOrbiterE);
            aWandererI = aWandererI + ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 48U) + RotL64(aOrbiterA, 41U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + aOrbiterB) + RotL64(aOrbiterG, 46U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 14U));
            aCarry = aCarry + (RotL64(aWandererA, 27U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneA
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aWorkLaneB
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29585U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 29287U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 26699U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 26678U)) & S_BLOCK1], 36U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 30097U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26466U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 10U)) ^ (RotL64(aCross, 41U) + RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = (aWandererD + RotL64(aScatter, 4U)) + 3612110001869385068U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 21U)) + RotL64(aCarry, 51U)) + 16340824141280225936U) + aOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = ((aWandererF + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 15222338965130765231U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 37U)) + 6649270508107155041U) + aNonceWordD;
            aOrbiterD = (aWandererK + RotL64(aCross, 19U)) + 768217258655426384U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 41U)) + RotL64(aCarry, 43U)) + 4481855259658861851U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 13U)) + 18318041934562434016U) + aNonceWordJ;
            aOrbiterF = (aWandererH + RotL64(aScatter, 34U)) + 4212457153804401807U;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 23U)) + 16143621095636987628U;
            aOrbiterB = (aWandererI + RotL64(aPrevious, 29U)) + 2095664232866642086U;
            aOrbiterK = ((aWandererC + RotL64(aScatter, 51U)) + 4339527736737366572U) + aOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 13679353177869884790U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11582168502846418236U) ^ aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 135539430034462861U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 10451330452898542191U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 12951448817640617841U;
            aOrbiterD = RotL64((aOrbiterD * 4141870904192742091U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 15389161934419370747U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 4754886272708253014U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 16638243718191281597U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11746389873929280688U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 12042680172517298768U;
            aOrbiterC = RotL64((aOrbiterC * 3814780289755857543U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 2648103752465009244U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 451594673632597973U;
            aOrbiterA = RotL64((aOrbiterA * 8496763663271072425U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 5696534794094099710U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14609435045257077395U;
            aOrbiterJ = RotL64((aOrbiterJ * 14658408563237468407U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11599395126850950133U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 12699598504604446664U;
            aOrbiterF = RotL64((aOrbiterF * 14313494063098111823U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9398465148537154745U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 12139736860648011256U;
            aOrbiterE = RotL64((aOrbiterE * 15257503229375247987U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5390816291244486383U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2797988892316486895U;
            aOrbiterH = RotL64((aOrbiterH * 14668138881285892065U), 27U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 18356290434261054712U) + aOrbiterUpdateSaltF[((aIndex + 18U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 16582824574485822826U) ^ aNonceWordK;
            aOrbiterK = RotL64((aOrbiterK * 7207935384746719969U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 9858803484150150915U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 3612110001869385068U;
            aOrbiterB = RotL64((aOrbiterB * 2862887443435821143U), 51U);
            //
            aIngress = RotL64(aOrbiterB, 28U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 5U));
            aIngress = aIngress + (RotL64(aOrbiterF, 11U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 37U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 10U) + RotL64(aOrbiterG, 11U)) + aOrbiterB) + aWandererUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterB) + RotL64(aCarry, 37U)) + aNonceWordC);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterG, 41U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 50U)) + aOrbiterD);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + aOrbiterH) + RotL64(aOrbiterE, 19U));
            aWandererH = aWandererH + ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterK, 57U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 51U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ);
            aWandererK = aWandererK + (((RotL64(aPrevious, 53U) + RotL64(aOrbiterE, 23U)) + aOrbiterC) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterJ, 35U)) + aOrbiterH) + aWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 4U)) + aOrbiterG) + aNonceWordG);
            //
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Cricket_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xF46D9F4D4D558E09ULL + 0xC3BF3DFB67282294ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x9790953631EE1393ULL + 0xD44DF35614A71746ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xF7577A386184A239ULL + 0xCFC41D776791844FULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0x97BD2849D7152F21ULL + 0xA836B0870478C23FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE641EFC3ADC6BA93ULL + 0xD23544BFF9F6E92FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xFDA0470EBF3706B7ULL + 0xD33EBB5B4744200CULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x99D569A8F5A4C321ULL + 0xB1D855FCB79DE110ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xC7BE10F77597DB6DULL + 0xE764865EE696F5E6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xDA59C670A374B439ULL + 0xA8E3B8721F760683ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xAAB246AF5B0F7D33ULL + 0xE7ABD4BB4FF24D50ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xE40CCABD1FD9657BULL + 0x8AF82C165DF80277ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x95E715805737D72DULL + 0xCB9CA6F4DA7BC091ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9675184D2BB564D5ULL + 0xE32D8A9CA3291144ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDF520BCA0ED2CC53ULL + 0x91CF7EF8E850F175ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xBF3C2AA6D5B71687ULL + 0xCCF607DF1B9CEC49ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xA93DA145B623DB8DULL + 0x86F32CA82C8723EBULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneA, aOperationLaneC, aOperationLaneD, aFireLaneD, aExpandLaneA, aWorkLaneC, aWorkLaneD, aExpandLaneB, aWorkLaneA, aFireLaneC, aExpandLaneC, aWorkLaneB, aFireLaneB
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneD
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3948U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 4283U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 4211U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 2286U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 5977U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 5943U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aIngress, 60U)) ^ (RotL64(aCross, 13U) + RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 19U)) + RotL64(aCarry, 39U)) + 6342299552323486695U;
            aOrbiterF = (aWandererA + RotL64(aCross, 3U)) + 12692748514781367538U;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 8202639945493229155U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 24U)) + 4439975701793231639U) + aOrbiterAssignSaltF[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (aWandererE + RotL64(aIngress, 47U)) + 16774235182859553759U;
            aOrbiterC = (aWandererI + RotL64(aCross, 41U)) + 8764155413335405667U;
            aOrbiterB = ((aWandererD + RotL64(aScatter, 29U)) + RotL64(aCarry, 27U)) + 7167848811974967685U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 14U)) + 16768278912125334220U) + aOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = ((aWandererF + RotL64(aCross, 53U)) + 9090838954826296201U) + aNonceWordP;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7644075729758006298U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 17326182797908071215U;
            aOrbiterA = RotL64((aOrbiterA * 2408330168749256075U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 16158809721888137555U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 8029938783858263694U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12628072435324195483U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8716553521415553404U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 7012599977009208840U;
            aOrbiterK = RotL64((aOrbiterK * 8775355876188948851U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13250558696578541499U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 13705957059101025396U;
            aOrbiterG = RotL64((aOrbiterG * 16889495686487056367U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2796775206291902461U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 13741676263512390669U;
            aOrbiterE = RotL64((aOrbiterE * 10455782033465595947U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1691908360612389252U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 4114939415206031540U;
            aOrbiterF = RotL64((aOrbiterF * 2797401802892718297U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 2374911514440738727U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 12377616933668803091U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 2505164835116651215U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 681094033415259645U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 13841322124900463362U;
            aOrbiterJ = RotL64((aOrbiterJ * 4210414203856902329U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 18082983557580381338U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15731122225678626778U;
            aOrbiterC = RotL64((aOrbiterC * 7785999919955613789U), 11U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 34U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterA, 43U));
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 21U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterA, 60U)) + RotL64(aCarry, 43U)) + aWandererUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 56U) + aOrbiterE) + RotL64(aOrbiterK, 5U)) + aNonceWordI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 39U) + RotL64(aOrbiterJ, 37U)) + aOrbiterE) + aNonceWordK) + aWandererUpdateSaltF[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aNonceWordM);
            aWandererK = aWandererK + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 56U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordO);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterG, 27U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterB, 43U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterC, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 54U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 13699U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneC[((aIndex + 10393U)) & S_BLOCK1], 42U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12813U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8883U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 13696U)) & S_BLOCK1], 38U));
            aCross ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10730U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 3U)) + (RotL64(aCross, 35U) ^ RotL64(aPrevious, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 43U)) + 13880995121909552664U;
            aOrbiterJ = ((aWandererB + RotL64(aPrevious, 36U)) + 14534942818069300546U) + aOrbiterAssignSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aWandererA + RotL64(aScatter, 27U)) + 17745973100886007133U;
            aOrbiterH = (((aWandererJ + RotL64(aIngress, 11U)) + 2249805580771946872U) + aOrbiterAssignSaltC[(((31U - aIndex) + 4U)) & S_SALT1]) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 4460116116396439410U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 5U)) + 3378683994078106878U;
            aOrbiterI = ((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 3992996501048809123U;
            aOrbiterC = ((aWandererC + RotL64(aIngress, 58U)) + 12057768808864451929U) + aNonceWordM;
            aOrbiterB = ((aWandererF + RotL64(aCross, 19U)) + 4115362079047921130U) + aNonceWordN;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15297384955502206698U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 17623548383481905636U;
            aOrbiterG = RotL64((aOrbiterG * 7487278217901483685U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 3559213898000162417U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 12311605719074507335U;
            aOrbiterA = RotL64((aOrbiterA * 3982199462062847697U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 14807313864347885885U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 11222085523291581822U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12580941911587215653U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 916681229436292462U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2441350114032314686U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 7336079498999018067U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7361470539894653271U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12153585147213579808U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3040327545467672961U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 13566300726101613579U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14875254144748509128U;
            aOrbiterC = RotL64((aOrbiterC * 13699179902908972403U), 29U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterC) + 9268158535644002904U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 14144295981814993491U;
            aOrbiterH = RotL64((aOrbiterH * 12739937231684038161U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13861225650900541642U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 12620513474052058164U) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 18141974182442267181U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14163773386433257965U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 5725700029399455855U;
            aOrbiterB = RotL64((aOrbiterB * 10446930901088908809U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterI, 27U);
            aIngress = aIngress + (RotL64(aOrbiterK, 19U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterC, 42U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + RotL64(aOrbiterE, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterB, 42U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 24U) + RotL64(aOrbiterE, 23U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 37U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + RotL64(aOrbiterA, 47U)) + aOrbiterG) + aNonceWordG);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 30U)) + aOrbiterE) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 5U)) + aOrbiterB) + aNonceWordF);
            aWandererA = aWandererA ^ ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterK, 19U)) + aNonceWordA) + aWandererUpdateSaltD[((aIndex + 13U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 28U) + RotL64(aOrbiterA, 11U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterG, 51U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 37U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 10U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aWorkLaneA
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 21813U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((aIndex + 23138U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 24178U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16892U)) & S_BLOCK1], 23U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20700U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aFireLaneC[((aIndex + 23054U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 41U) ^ RotL64(aCarry, 56U)) + (RotL64(aIngress, 29U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterD = (((aWandererK + RotL64(aPrevious, 39U)) + 16189787374324972735U) + aOrbiterAssignSaltD[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (((aWandererD + RotL64(aIngress, 57U)) + RotL64(aCarry, 37U)) + 17563763730956242224U) + aNonceWordA;
            aOrbiterC = (aWandererJ + RotL64(aScatter, 43U)) + 10572803498593789385U;
            aOrbiterF = ((aWandererE + RotL64(aCross, 34U)) + 7713105232072974166U) + aNonceWordB;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 51U)) + RotL64(aCarry, 29U)) + 10760839534772718139U) + aOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererC + RotL64(aCross, 11U)) + RotL64(aCarry, 57U)) + 13397069448391230253U;
            aOrbiterH = (aWandererG + RotL64(aIngress, 47U)) + 4569255679998375682U;
            aOrbiterA = (aWandererB + RotL64(aScatter, 26U)) + 9888769350817876949U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 19U)) + 11351796060878856300U) + aNonceWordJ;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 18153775071965707204U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1282846411145853435U;
            aOrbiterC = RotL64((aOrbiterC * 12294455920906257823U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 16457743979262460660U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 173493260775251032U;
            aOrbiterB = RotL64((aOrbiterB * 4935807229040883505U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3927345926316409630U) + aNonceWordG;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 5158769729850853623U) ^ aNonceWordD;
            aOrbiterA = RotL64((aOrbiterA * 2446452358663812945U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 12331351600010165154U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 3940794200348684050U;
            aOrbiterI = RotL64((aOrbiterI * 13248997263062075043U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 11248514843822945425U) + aOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1391497323278226522U;
            aOrbiterH = RotL64((aOrbiterH * 8376841806072565005U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 13265623528678787307U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 2802033745265647317U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3437626962562016147U), 51U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 6938444301018051844U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1086544666755559028U;
            aOrbiterJ = RotL64((aOrbiterJ * 16039728388882079889U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 16156443117365816536U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 3619942859562697142U;
            aOrbiterE = RotL64((aOrbiterE * 7589346043159112151U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 17681848914912743292U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 8848238631758130416U) ^ aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 810402256099500607U), 23U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (RotL64(aOrbiterH, 11U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 18U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 21U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterE, 46U)) + aNonceWordI);
            aWandererJ = aWandererJ + (((RotL64(aCross, 47U) + aOrbiterA) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + aOrbiterI) + RotL64(aOrbiterF, 53U));
            aWandererE = aWandererE + ((((RotL64(aCross, 43U) + aOrbiterD) + RotL64(aOrbiterH, 3U)) + aNonceWordF) + aWandererUpdateSaltC[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + aNonceWordE) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aIngress, 11U) + RotL64(aOrbiterF, 39U)) + aOrbiterJ);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 5U) + aOrbiterE) + RotL64(aOrbiterA, 57U));
            aWandererF = aWandererF + ((RotL64(aCross, 24U) + aOrbiterH) + RotL64(aOrbiterA, 30U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 41U));
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererG, 10U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererD, 13U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29050U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((aIndex + 30552U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 32692U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25243U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 26138U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 25475U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCarry, 52U)) ^ (RotL64(aCross, 35U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterC = ((aWandererD + RotL64(aScatter, 41U)) + 17264605017518259932U) + aNonceWordD;
            aOrbiterK = (((aWandererC + RotL64(aIngress, 12U)) + RotL64(aCarry, 3U)) + 15209184354580778643U) + aOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = (aWandererF + RotL64(aCross, 5U)) + 3299527965014731384U;
            aOrbiterA = ((aWandererB + RotL64(aPrevious, 51U)) + 16293096431816127821U) + aNonceWordL;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 37U)) + 11031983436878828337U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 57U)) + 9188018632448236358U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 19U)) + RotL64(aCarry, 37U)) + 13420816400363406556U) + aNonceWordO;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 23U)) + RotL64(aCarry, 47U)) + 2485063384097917101U;
            aOrbiterI = (((aWandererE + RotL64(aCross, 46U)) + 3089135816938128264U) + aOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1]) + aNonceWordG;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 10730544971770435788U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 10431767565618874806U;
            aOrbiterD = RotL64((aOrbiterD * 4723078464590561545U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14883796491656899074U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 13465877783538483706U;
            aOrbiterB = RotL64((aOrbiterB * 14311686051108108503U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 13322163435314643713U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 3307316600284371955U;
            aOrbiterA = RotL64((aOrbiterA * 12337846092069506365U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 4950101626975919939U) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2596253994220103666U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 7181706961838582889U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 17961706029559914243U) + aOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 10321902557977495175U) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 16189559888625084711U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 18146616411403012772U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 8414050129421955787U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 14879448948196182863U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 11739172334166341121U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7936637782633487291U;
            aOrbiterE = RotL64((aOrbiterE * 14940929920543800413U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 3160044627483874242U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 16816384076887379704U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5052772186568301951U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8101560104988710226U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 8851416379738817624U;
            aOrbiterF = RotL64((aOrbiterF * 16767420038937389027U), 19U);
            //
            aIngress = RotL64(aOrbiterF, 19U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterE, 23U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 42U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterA, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aPrevious, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 23U)) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((((RotL64(aScatter, 11U) + RotL64(aOrbiterD, 12U)) + aOrbiterK) + aNonceWordN) + aWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + RotL64(aOrbiterE, 47U)) + aOrbiterB);
            aWandererH = aWandererH ^ (((RotL64(aCross, 52U) + RotL64(aOrbiterD, 19U)) + aOrbiterF) + aNonceWordE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 5U) + RotL64(aOrbiterA, 5U)) + aOrbiterJ) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 41U)) + aOrbiterK);
            aWandererF = aWandererF + ((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterI, 30U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 46U) + aOrbiterC) + RotL64(aOrbiterB, 53U)) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 57U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 28U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 5U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Cricket_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xA11E9A356D3CFD1FULL + 0xB6157EFA72F2F6A2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xBFF86DD7C30B1CC5ULL + 0x986547378D3EBA47ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xE07FC57C39B8CFD9ULL + 0xEECDED63EF9FD4F8ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9EB3527897019F67ULL + 0xE12A825A2D55CD26ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0x9FDEFB1B75116A77ULL + 0xCE24228D4D897334ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xAC984444BE6D67C1ULL + 0xF9418C596EE03D1BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x87B81DB07959A593ULL + 0xF6C98BD2B9E91517ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBD11557D6AB30C25ULL + 0xCEAD656851AB7D2AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD9F2AE79D507B15DULL + 0x9537DB8F0DE9CDBAULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xD35B6B8E9DB3C693ULL + 0xA2AFDF033741D018ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEE74388250D5C1FDULL + 0x826FFACCA022D001ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x88E673DF9919125FULL + 0x8E410E4818789AA7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xF7D73CD95A3AF233ULL + 0xF9065DFC0AE29B3DULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xC331F6310BCAF329ULL + 0xF8EC886B1116E4A7ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xEA60343A346414E9ULL + 0xBE4EB1E4C6594EFFULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xBBF6C6756B1F8A6BULL + 0xE022A784D879E55EULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneD, aWorkLaneC, aWorkLaneD, aFireLaneA, aExpandLaneA, aOperationLaneB, aFireLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneA, aExpandLaneC, aFireLaneC, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneA
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 239U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 582U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 719U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 2423U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 8098U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 2985U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aIngress, 10U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererK + RotL64(aScatter, 3U)) + 18180797995100240808U) + aNonceWordI;
            aOrbiterE = ((aWandererF + RotL64(aPrevious, 26U)) + 6585906608223552885U) + aNonceWordN;
            aOrbiterG = (((aWandererE + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 14088708930575939855U) + aOrbiterAssignSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterI = (((aWandererC + RotL64(aCross, 41U)) + RotL64(aCarry, 21U)) + 468974153311516044U) + aOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aIngress, 57U)) + 12481951025619894110U;
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 17227987923860711763U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 19U)) + 4373962756657477139U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 2077576476565420951U) + aOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17435011300234663764U;
            aOrbiterG = RotL64((aOrbiterG * 8910133867294004711U), 13U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4118039398293246896U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 13724716599855216683U;
            aOrbiterF = RotL64((aOrbiterF * 17556333902751079677U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 12391461204689596339U) + aNonceWordB;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 9900605191533799627U;
            aOrbiterB = RotL64((aOrbiterB * 13553565332531046301U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 972946858824366125U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17247681919694541215U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2974639094630445643U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15442851427306771601U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 7303586227288294037U;
            aOrbiterE = RotL64((aOrbiterE * 15406402525021428799U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 12650358753454105119U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1483710933373510492U;
            aOrbiterD = RotL64((aOrbiterD * 6531763256577221891U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 18065810162229740788U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 11311677121338794007U;
            aOrbiterC = RotL64((aOrbiterC * 15116367961682119467U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 13U);
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterB, 3U)) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterG, 19U));
            aWandererI = aWandererI + ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterB, 29U)) + aOrbiterI) + aWandererUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aScatter, 23U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + aWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterD, 41U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + RotL64(aOrbiterE, 48U)) + aOrbiterF) + RotL64(aCarry, 21U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 14U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aFireLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aFireLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 9853U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneC[((aIndex + 14585U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 12411U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 15100U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10440U)) & S_BLOCK1], 6U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 10655U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aPrevious, 20U)) + (RotL64(aIngress, 3U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 37U)) + RotL64(aCarry, 29U)) + 6654158889644956636U;
            aOrbiterJ = ((aWandererK + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 9045779659363991870U;
            aOrbiterH = (((aWandererF + RotL64(aIngress, 3U)) + 3888897662136993491U) + aOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1]) + aNonceWordM;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 11U)) + 6882016842864459345U) + aNonceWordP;
            aOrbiterI = (aWandererB + RotL64(aScatter, 50U)) + 15601891715956172291U;
            aOrbiterA = ((aWandererH + RotL64(aCross, 29U)) + 5176811598629335350U) + aNonceWordN;
            aOrbiterD = (((aWandererG + RotL64(aIngress, 57U)) + RotL64(aCarry, 43U)) + 12519945150889074325U) + aOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4552583214397603278U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterF) ^ 14225482701804864688U) ^ aOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8526052833180466359U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5485298070606280363U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 11237713257388094289U;
            aOrbiterF = RotL64((aOrbiterF * 11032429223099413011U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 14340345895626142788U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 16275167270553643347U;
            aOrbiterI = RotL64((aOrbiterI * 7308578867128951199U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 14041860597556520250U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 1436068974197066343U;
            aOrbiterJ = RotL64((aOrbiterJ * 3938460345031496843U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11483155566419547004U) + aOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 4608508534724289325U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 13461385011638899485U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 2389196334288832895U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 4062682330273866602U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8787682133271101901U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5655656046585592034U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7977947821249746880U;
            aOrbiterA = RotL64((aOrbiterA * 10082104644185964787U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 41U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 48U));
            aIngress = aIngress + RotL64(aOrbiterE, 29U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 12U)) + aNonceWordE);
            aWandererB = aWandererB + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 37U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aNonceWordF);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 54U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + aWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterE, 43U)) + aOrbiterF) + aWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 43U) + RotL64(aOrbiterJ, 53U)) + aOrbiterF) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 21U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 12U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneC
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24316U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((aIndex + 18677U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 22413U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17041U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20023U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 19026U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 50U)) ^ (RotL64(aCross, 23U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = (aWandererK + RotL64(aCross, 41U)) + 3236820517816085022U;
            aOrbiterF = (((aWandererJ + RotL64(aPrevious, 58U)) + RotL64(aCarry, 37U)) + 741288875914097926U) + aNonceWordM;
            aOrbiterG = ((((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 8417246926007729580U) + aOrbiterAssignSaltD[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordC;
            aOrbiterC = (aWandererE + RotL64(aScatter, 11U)) + 9715717805774537170U;
            aOrbiterH = (((aWandererH + RotL64(aCross, 47U)) + RotL64(aCarry, 23U)) + 14360243844821619482U) + aNonceWordP;
            aOrbiterI = (aWandererD + RotL64(aScatter, 3U)) + 10760908100206775334U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 35U)) + 3434641779946167811U) + aOrbiterAssignSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 7885568822756234567U) + aOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 3041563437672051294U;
            aOrbiterG = RotL64((aOrbiterG * 11440300917533482297U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15761355327564963516U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 1158633562785937421U) ^ aNonceWordE;
            aOrbiterE = RotL64((aOrbiterE * 15511324886867188235U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9338581575871970653U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9172038894262857354U;
            aOrbiterC = RotL64((aOrbiterC * 3110871165285625807U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 14653924713599790081U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterG) ^ 3854497592598563309U) ^ aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 11737111068815795303U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 16286980180327600557U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 5092583772591249756U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 13955105624639442903U), 29U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 4288397994175567333U) + aNonceWordL;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 15584236478994873104U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 1860480595862755379U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5557463939827483792U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 2659814275753280856U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17702430405693184643U), 57U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterC, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterG, 3U)) + aNonceWordD);
            aWandererH = aWandererH + ((((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 4U) + aOrbiterI) + RotL64(aOrbiterG, 53U));
            aWandererI = aWandererI + (((((RotL64(aPrevious, 35U) + aOrbiterF) + RotL64(aOrbiterE, 60U)) + RotL64(aCarry, 39U)) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 16U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 27U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 14U));
            aCarry = aCarry + (RotL64(aWandererK, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererH, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneD
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneD backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30496U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 27311U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27832U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32259U)) & S_BLOCK1], 39U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 26384U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 28551U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 53U)) + (RotL64(aCross, 5U) + RotL64(aIngress, 22U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (aWandererK + RotL64(aCross, 53U)) + 13924571355038625040U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 16328300979357156658U;
            aOrbiterD = (((aWandererD + RotL64(aScatter, 3U)) + 3947771961206012461U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordP;
            aOrbiterF = (((aWandererJ + RotL64(aIngress, 44U)) + RotL64(aCarry, 37U)) + 15428284250569311285U) + aOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 5777369485254032486U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 19U)) + 16813320300717644673U) + aNonceWordI;
            aOrbiterB = ((aWandererF + RotL64(aCross, 35U)) + 16689933050200758251U) + aNonceWordF;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1856422419049390708U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18214498743831925517U;
            aOrbiterD = RotL64((aOrbiterD * 10744120577560529379U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 18278550878494094923U) + aOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 797712062039591797U;
            aOrbiterJ = RotL64((aOrbiterJ * 7212998747080137625U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 15854849439012341347U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 996882939768167773U;
            aOrbiterB = RotL64((aOrbiterB * 14936703950807908575U), 27U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterJ) + 3005829974130671692U) + aOrbiterUpdateSaltE[((aIndex + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8793495343509953906U;
            aOrbiterH = RotL64((aOrbiterH * 14065479348374612031U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 7710453029930631112U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 9511995836117707047U;
            aOrbiterI = RotL64((aOrbiterI * 7250766204781428201U), 5U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 670902975693341744U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9045820304668279777U;
            aOrbiterE = RotL64((aOrbiterE * 18373074917532639027U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 12417212387607119470U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12816983560669985622U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 8406003970221889847U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 46U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterD, 41U)) + aNonceWordC) + aWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 57U) + aOrbiterD) + RotL64(aOrbiterB, 60U)) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 12U) + aOrbiterF) + RotL64(aOrbiterB, 21U)) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterH);
            aWandererC = aWandererC ^ ((((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterI, 53U)) + aNonceWordO) + aWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aIngress, 5U) + aOrbiterJ) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 23U)) + aNonceWordE);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 23U) + aOrbiterJ) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererK);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Cricket_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD352CDE75ED1394FULL + 0xD1029954AE4F8878ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xD4D313033C7F5467ULL + 0xB79516B82FB8425BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xB625726A92BCB9C1ULL + 0xE3607DFBD15DB2CDULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xB02BDF88788B9345ULL + 0xB1DD18E0996E233FULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFA19458CC1E4C359ULL + 0x8FB3B54B1224790FULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x965F77B5BF0DBB37ULL + 0xDA3D991BE4B1C880ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xA7E5444CF6745ED3ULL + 0xAE30100D5A53447EULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9A6DC6DBC5CDD6D1ULL + 0x845CBFCAF8C09C1BULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA2974C96E54B7119ULL + 0x93EC4C51D9492ED1ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xB60646AD52A7E8D1ULL + 0xA54FF42F6543B48CULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x97888633246780ADULL + 0xE7B4777AD3B9B9EAULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xC7A775CF70D0D199ULL + 0x97B0E4E8BF7CF34AULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xF3D5526ED00CB1FFULL + 0xA8EC4A0124D2EB33ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xDBE088E9D0A3C3A7ULL + 0x9E7AC7A914A71FA3ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xFFC1CC598BD61C25ULL + 0xFF07A1DBEF7DB0BEULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xE20352BC6314CAB7ULL + 0xCC56DFF607E34702ULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 464U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 2714U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1964U)) & W_KEY1], 39U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2662U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 47U) ^ RotL64(aIngress, 60U)) + (RotL64(aPrevious, 29U) + RotL64(aCross, 13U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterD = (((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 53U)) + 11998579547770778580U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 8409465187298704610U;
            aOrbiterG = (aWandererG + RotL64(aIngress, 5U)) + 3470222286110333500U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 19U)) + 5704486785203069994U) + aNonceWordF;
            aOrbiterK = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 10334944660253279633U) + aNonceWordH;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 44U)) + 7626852700722567477U) + aNonceWordE;
            aOrbiterI = (((aWandererF + RotL64(aCross, 29U)) + 14631310754943209743U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordC;
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 807160297237854120U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5624154783624196107U;
            aOrbiterG = RotL64((aOrbiterG * 2404066593958052159U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 4971444394698940423U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6340057638461027062U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12027586111086798629U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 9003019862787819481U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 13632057463595873033U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12575202147280216765U), 5U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterI) + 12766104026871797746U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 4062118445824915939U;
            aOrbiterK = RotL64((aOrbiterK * 13130770039048080701U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 5258212525426469978U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9956946981015983939U) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 8106382657040497669U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10837606223056473999U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13292864885504191134U;
            aOrbiterE = RotL64((aOrbiterE * 4445739587553669471U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 166087925900318658U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 6786842221885441388U;
            aOrbiterI = RotL64((aOrbiterI * 4411147600413147773U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterI, 19U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 46U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + RotL64(aOrbiterJ, 27U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 35U));
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterH, 56U)) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + aPhaseEWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 50U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + RotL64(aCarry, 27U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterG, 47U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 41U)) + aOrbiterD) + aNonceWordO) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterK, 13U)) + aNonceWordM);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 44U));
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 51U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 2903U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4277U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5300U)) & W_KEY1], 12U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4951U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 13U) + RotL64(aCarry, 27U)) ^ (RotL64(aCross, 57U) ^ RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererK + RotL64(aIngress, 5U)) + 13204735390996728477U) + aPhaseEOrbiterAssignSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 11U)) + RotL64(aCarry, 19U)) + 851171359595647173U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 35U)) + 16745304202825290723U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterA = (((aWandererC + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 562392736584913979U) + aNonceWordD;
            aOrbiterF = (aWandererD + RotL64(aPrevious, 43U)) + 3244267012529053918U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 21U)) + 17282536111067869133U) + aNonceWordE;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 28U)) + RotL64(aCarry, 39U)) + 14851130066471729068U) + aNonceWordO;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5256130407952363129U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 2904742485828362001U) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 12941135856735075457U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 3723346325449225387U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5344621093694027341U;
            aOrbiterF = RotL64((aOrbiterF * 9044881458629673499U), 37U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 12919263300833603026U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 17989801264160996071U) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 15468293047311883751U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 5022175042377172157U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16684822380107847758U;
            aOrbiterB = RotL64((aOrbiterB * 2834049270263837537U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 2740326510600876682U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 13981423865219318820U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 14593082145080056441U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 231945878229848395U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 14139797734944312580U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6492256080432266407U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 16704102101387552373U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8506734780526852552U;
            aOrbiterI = RotL64((aOrbiterI * 4684566118627414659U), 53U);
            //
            aIngress = RotL64(aOrbiterI, 53U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 47U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 34U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterD, 13U)) + aNonceWordI);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 43U) + aOrbiterB) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 43U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterA, 57U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 5U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterA, 47U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aScatter, 5U) + aOrbiterI) + RotL64(aOrbiterF, 24U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 18U) + RotL64(aOrbiterH, 35U)) + aOrbiterI) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 57U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7074U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadB[((aIndex + 6593U)) & W_KEY1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7420U)) & W_KEY1], 12U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6214U)) & S_BLOCK1], 51U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5921U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCross, 10U)) + (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 51U)) + 966899917801652720U) + aNonceWordC;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 57U)) + 10996327672320748649U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 39U)) + 4188171566846621107U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 29U)) + 5886209243097387959U) + aNonceWordP;
            aOrbiterA = ((aWandererH + RotL64(aCross, 36U)) + RotL64(aCarry, 13U)) + 14940428957136728111U;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 51U)) + 179187285531914832U) + aNonceWordG;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 23U)) + 6685351948936817752U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 1894506461704029700U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 4182760368636977082U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 972988091869133921U), 35U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterK) + 12523318028514940790U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5059306166973366892U;
            aOrbiterA = RotL64((aOrbiterA * 2857409765717296483U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 5890872367917643851U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 17747338389865221534U;
            aOrbiterG = RotL64((aOrbiterG * 5306740664798049267U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 13906227834259884100U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 7152105382899756368U;
            aOrbiterH = RotL64((aOrbiterH * 6772157117358310485U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 17868101884759619240U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11758843266314148347U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5919135169337501485U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 13950566197090324859U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17278105609930477854U) ^ aNonceWordO;
            aOrbiterE = RotL64((aOrbiterE * 11431842718945107359U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 9556785965646738355U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 841298436857932987U) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 15077843186688841797U), 21U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterE, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 43U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 35U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterC, 21U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterA, 3U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterH) + aNonceWordL) + aPhaseEWandererUpdateSaltC[((aIndex + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterC, 27U)) + aNonceWordA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 3U) + RotL64(aOrbiterK, 20U)) + aOrbiterJ) + RotL64(aCarry, 27U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 44U) + RotL64(aOrbiterG, 39U)) + aOrbiterH);
            aWandererE = aWandererE + ((((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 11U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + aOrbiterE) + RotL64(aOrbiterC, 53U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 42U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererJ, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 8432U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 8957U)) & W_KEY1], 42U));
            aIngress ^= (RotL64(mSource[((aIndex + 8857U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9261U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8871U)) & W_KEY1], 21U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9191U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 20U)) ^ (RotL64(aIngress, 3U) ^ RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 11U)) + RotL64(aCarry, 53U)) + 17081642665820489793U) + aNonceWordN;
            aOrbiterE = (aWandererI + RotL64(aIngress, 3U)) + 14468854040067229623U;
            aOrbiterB = (aWandererC + RotL64(aCross, 43U)) + 2249450222593057429U;
            aOrbiterD = (aWandererE + RotL64(aScatter, 60U)) + 14964389079511378664U;
            aOrbiterC = ((((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 35U)) + 17003491054252360650U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 12710882240582032588U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 21U)) + 9887078182156755359U) + aPhaseFOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 7665284531810584704U;
            aOrbiterB = (((aOrbiterB ^ aOrbiterF) ^ 7304284015511876717U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 6193179739025093929U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 5517927023543751734U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17704756310857362759U;
            aOrbiterE = RotL64((aOrbiterE * 15826832172923213591U), 35U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 11347400363019508578U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 11696395232760991243U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9725231749679442003U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 10875780291242873583U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7808740614343437672U;
            aOrbiterF = RotL64((aOrbiterF * 8889516201913716283U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3145390996141902032U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16080636485642732615U;
            aOrbiterD = RotL64((aOrbiterD * 7445756373012217305U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 3929263288176983844U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 18210228766683996806U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13178080076505449091U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 13948962323541421431U) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 3037683309790156893U;
            aOrbiterH = RotL64((aOrbiterH * 13406672352222636739U), 41U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 3U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 27U));
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aPrevious, 11U) + aOrbiterD) + RotL64(aOrbiterH, 39U)) + aNonceWordK) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 36U) + aOrbiterE) + RotL64(aOrbiterB, 23U)) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 53U)) + aOrbiterF);
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 60U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aCross, 51U) + aOrbiterC) + RotL64(aOrbiterG, 3U));
            aWandererA = aWandererA + ((((RotL64(aIngress, 5U) + aOrbiterE) + RotL64(aOrbiterC, 13U)) + RotL64(aCarry, 5U)) + aPhaseFWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 11121U)) & S_BLOCK1], 13U) ^ RotL64(aKeyRowReadA[((aIndex + 11949U)) & W_KEY1], 43U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 12074U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 11520U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 12541U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11346U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11186U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aIngress, 54U)) ^ (RotL64(aPrevious, 21U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterH = ((aWandererE + RotL64(aScatter, 19U)) + 3238389262925516513U) + aNonceWordP;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 57U)) + RotL64(aCarry, 13U)) + 12381787182611386995U;
            aOrbiterE = ((((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 51U)) + 7883885539305181549U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (((aWandererF + RotL64(aPrevious, 5U)) + RotL64(aCarry, 37U)) + 1185413044597727092U) + aNonceWordJ;
            aOrbiterJ = (aWandererA + RotL64(aScatter, 41U)) + 15219353497204773135U;
            aOrbiterD = (aWandererH + RotL64(aCross, 47U)) + 7533774715626734082U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 30U)) + 2599930450937763464U) + aPhaseFOrbiterAssignSaltE[((aIndex + 29U)) & S_SALT1];
            //
            aOrbiterH = (((aOrbiterH + aOrbiterK) + 16074720663961214284U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 15483613196360051221U;
            aOrbiterE = RotL64((aOrbiterE * 11717479088020532861U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9396557867081376268U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterF) ^ 9668459976852660245U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterJ = RotL64((aOrbiterJ * 11748505665890567063U), 5U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 9037269914643207212U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16936742640861088240U;
            aOrbiterD = RotL64((aOrbiterD * 1040172193161012227U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 16481274825758546398U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 481851372837611166U;
            aOrbiterF = RotL64((aOrbiterF * 2225030139210599207U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 13608921517203544108U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16930740723286214636U;
            aOrbiterH = RotL64((aOrbiterH * 2605108503821980865U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 902242902582149908U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 1510861213079342977U;
            aOrbiterK = RotL64((aOrbiterK * 3309753895727400707U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 7116243600304980310U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6631412278359709602U;
            aOrbiterB = RotL64((aOrbiterB * 11452627691392637463U), 37U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 51U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 36U));
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterE, 13U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 41U) + aOrbiterF) + RotL64(aOrbiterB, 5U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterK, 53U)) + aOrbiterJ) + aNonceWordN);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 19U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((((RotL64(aCross, 4U) + aOrbiterH) + RotL64(aOrbiterE, 36U)) + aNonceWordL) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 21U) + aOrbiterJ) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterF, 29U)) + aNonceWordA);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererF, 44U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 14724U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 14990U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14184U)) & W_KEY1], 48U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15544U)) & W_KEY1], 57U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15530U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16042U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15243U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 24U)) + (RotL64(aCross, 43U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = ((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 47U)) + 2786079456995203065U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 13U)) + 7237256119153857253U;
            aOrbiterG = ((aWandererA + RotL64(aScatter, 29U)) + 9310834010563647604U) + aNonceWordB;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 43U)) + 17361734905706517877U) + aNonceWordA;
            aOrbiterF = (((aWandererI + RotL64(aScatter, 35U)) + RotL64(aCarry, 3U)) + 15837111231884647451U) + aPhaseFOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 19U)) + 18065431964418026445U;
            aOrbiterC = ((((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 21U)) + 3029123922999952652U) + aPhaseFOrbiterAssignSaltD[((aIndex + 28U)) & S_SALT1]) + aNonceWordF;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 5166926595573507837U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 1918425684273807598U) ^ aNonceWordL;
            aOrbiterG = RotL64((aOrbiterG * 16616641579714896719U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 4724551751012661440U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 1818014487579644390U;
            aOrbiterI = RotL64((aOrbiterI * 14904092108647864911U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6670090372241084216U) + aNonceWordI;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8485757110007268693U;
            aOrbiterJ = RotL64((aOrbiterJ * 11876760095108618363U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 4928130251509514742U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 2528788422725346792U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 1855982047967756661U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 2860387120895147503U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 12927802338151379368U;
            aOrbiterF = RotL64((aOrbiterF * 8876144125458603029U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 18029699867733207083U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13361836994951253312U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 5349767426256597073U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 11957294454794128079U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 3755417922063414648U;
            aOrbiterB = RotL64((aOrbiterB * 13896364063651241401U), 41U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterI, 27U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aPrevious, 21U) + aOrbiterC) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 27U) + aOrbiterG) + RotL64(aOrbiterF, 27U)) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + RotL64(aOrbiterB, 53U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 41U) + aOrbiterI) + RotL64(aOrbiterA, 21U));
            aWandererE = aWandererE + (((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterF, 41U)) + aNonceWordG);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 10U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 12U)) + RotL64(aCarry, 3U)) + aPhaseFWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererH, 26U));
            aCarry = aCarry + (RotL64(aWandererK, 43U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererA, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17152U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 17743U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(mSource[((aIndex + 17916U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneA[((aIndex + 19017U)) & S_BLOCK1], 53U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17186U)) & W_KEY1], 53U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16973U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18910U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 23U) + RotL64(aCarry, 53U)) ^ (RotL64(aPrevious, 39U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererI + RotL64(aPrevious, 51U)) + 9855743441035905047U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererG + RotL64(aCross, 57U)) + 8426286937143990276U) + aNonceWordC;
            aOrbiterA = ((aWandererH + RotL64(aIngress, 27U)) + 7146752367170267002U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 57U)) + 12947210066678101726U) + aNonceWordG;
            aOrbiterH = ((aWandererB + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 15902163559925328965U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 42U)) + 8506649889346449469U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 5U)) + RotL64(aCarry, 13U)) + 8226286036430263052U) + aNonceWordN;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2703047093452420216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 6769351326360139560U;
            aOrbiterA = RotL64((aOrbiterA * 5318104980014706265U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 9857025533281333281U) + aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 238297452132277585U) ^ aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 12974709749856065985U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7203572312072908931U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 12497027346166575632U;
            aOrbiterC = RotL64((aOrbiterC * 1703586436725662307U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 473851890609048879U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 1664484956453886047U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 8566500756326590209U), 43U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 4635095143004754116U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17695676150967345793U;
            aOrbiterE = RotL64((aOrbiterE * 5780416541584439301U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 15628965269863402796U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 9190117464399730235U;
            aOrbiterG = RotL64((aOrbiterG * 5586437438425999715U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 17835918238346011086U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4398005402429282682U) ^ aNonceWordD;
            aOrbiterF = RotL64((aOrbiterF * 14828737209913317463U), 29U);
            //
            aIngress = RotL64(aOrbiterA, 51U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + RotL64(aOrbiterC, 6U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aScatter, 35U) + RotL64(aOrbiterH, 11U)) + aOrbiterF) + RotL64(aCarry, 11U));
            aWandererI = aWandererI ^ (((RotL64(aIngress, 60U) + RotL64(aOrbiterC, 19U)) + aOrbiterA) + aNonceWordH);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterG, 57U)) + aOrbiterC) + aPhaseGWandererUpdateSaltD[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterE, 5U));
            aWandererH = aWandererH + ((((RotL64(aIngress, 11U) + aOrbiterC) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 47U)) + aPhaseGWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 29U)) + aOrbiterE) + aNonceWordP);
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + aOrbiterF) + RotL64(aOrbiterI, 42U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererH, 38U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19255U)) & S_BLOCK1], 27U) ^ RotL64(mSource[((aIndex + 21298U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19815U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneA[((aIndex + 19964U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 20657U)) & W_KEY1], 22U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 19284U)) & W_KEY1], 43U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21445U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19256U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 23U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 52U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (aWandererH + RotL64(aPrevious, 19U)) + 9751314027302668907U;
            aOrbiterH = ((aWandererD + RotL64(aIngress, 51U)) + 12175450995523107056U) + aNonceWordJ;
            aOrbiterF = ((aWandererG + RotL64(aCross, 39U)) + 17519694958730119552U) + aPhaseGOrbiterAssignSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 11U)) + 9093525527925682263U;
            aOrbiterB = ((aWandererJ + RotL64(aIngress, 30U)) + RotL64(aCarry, 21U)) + 3713831321786810138U;
            aOrbiterG = ((((aWandererK + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 10108355209191835040U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordO;
            aOrbiterA = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 53U)) + 12956307447311314768U) + aNonceWordA;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 1904298513945877359U) + aNonceWordE;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 4658049993308574460U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 10482422152074338611U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 9826333658248851902U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 12058666914724365134U;
            aOrbiterB = RotL64((aOrbiterB * 964233873188373939U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2516574707110528099U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 13335308331049750235U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 5880227828760598587U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 8230749255538495304U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16536559486797811486U) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 7097036838156464969U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 12387639130570188998U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 8459259798142872020U;
            aOrbiterH = RotL64((aOrbiterH * 8001346480955847013U), 21U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 16083784052002800300U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1957284290736468379U;
            aOrbiterK = RotL64((aOrbiterK * 5046501301740813065U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 7349538179311335863U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16395170077006105258U;
            aOrbiterA = RotL64((aOrbiterA * 4230485452156662763U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 27U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 11U)) + aOrbiterK);
            aWandererI = aWandererI + ((((RotL64(aIngress, 19U) + RotL64(aOrbiterG, 30U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseGWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterA, 57U)) + aOrbiterJ) + aNonceWordP);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterA, 51U)) + aOrbiterG);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 11U) + aOrbiterH) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 37U)) + aNonceWordL);
            aWandererH = aWandererH ^ ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 23U)) + aOrbiterF) + aNonceWordD) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 60U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + (RotL64(aWandererK, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 22103U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 24148U)) & W_KEY1], 19U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23800U)) & W_KEY1], 29U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23831U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22975U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22532U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 24553U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 22870U)) & S_BLOCK1], 6U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 22U) ^ RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 21U)) + 479672811032092393U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 18061121631394564425U) + aNonceWordH;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 14237400452740566065U) + aPhaseGOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 13U)) + 6723123812257706134U) + aPhaseGOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 23U)) + 4247997188026499248U) + aNonceWordL;
            aOrbiterG = ((aWandererA + RotL64(aCross, 42U)) + 1939107415066134869U) + aNonceWordB;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 51U)) + 3912640123546395979U) + aNonceWordD;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 8295478436553964298U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 3218960600711526885U;
            aOrbiterH = RotL64((aOrbiterH * 15443507655470278069U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5874096203353388890U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10294536533673023358U;
            aOrbiterG = RotL64((aOrbiterG * 15561710414949058923U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 11268561953904130747U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16693201256788898423U;
            aOrbiterK = RotL64((aOrbiterK * 16291987237693567209U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 7550969634681894654U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 9501647424602245869U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11265865222096866605U), 13U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterG) + 8881869255994319423U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 16770136406906800016U;
            aOrbiterI = RotL64((aOrbiterI * 1782039587385512923U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 16185384746435761363U) + aPhaseGOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13841034186650721627U;
            aOrbiterC = RotL64((aOrbiterC * 12000155593277035447U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 15229062695864608309U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3576122704615303733U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 2433987493885779279U), 37U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 37U);
            aIngress = aIngress + (RotL64(aOrbiterG, 4U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 53U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aIngress, 13U) + RotL64(aOrbiterE, 11U)) + aOrbiterG) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 29U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterC, 43U)) + aOrbiterK) + aNonceWordP);
            aWandererG = aWandererG + (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterH, 23U));
            aWandererA = aWandererA + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterG, 58U)) + aPhaseGWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterI) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + RotL64(aWandererD, 39U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26656U)) & S_BLOCK1], 23U) ^ RotL64(aKeyRowReadA[((aIndex + 24861U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 27023U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((aIndex + 24762U)) & S_BLOCK1], 48U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 25744U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26327U)) & S_BLOCK1], 60U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26301U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneD[((aIndex + 27227U)) & S_BLOCK1], 13U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCross, 27U)) + (RotL64(aIngress, 60U) ^ RotL64(aCarry, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + 8604208734152026945U) + aNonceWordO;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 11U)) + 1374329953253889829U) + aNonceWordH;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 53U)) + 5779278910548228339U;
            aOrbiterD = (((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 35U)) + 17670451230882805140U) + aNonceWordK;
            aOrbiterK = (((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 21U)) + 8193848740764866860U) + aNonceWordG;
            aOrbiterJ = ((aWandererF + RotL64(aCross, 5U)) + 15801168428145650104U) + aPhaseHOrbiterAssignSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aWandererI + RotL64(aIngress, 41U)) + 2584718176087499066U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 14950366247822737997U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 9779293225265670135U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11625969538497982117U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8688968319288372383U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 13665723186950342601U;
            aOrbiterJ = RotL64((aOrbiterJ * 292035540396910837U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 9395428688359973510U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 2152719218018108418U) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 15271961483518392671U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 1350324137411377992U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8729317951386057921U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 6008790836417785083U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 6317310451893678411U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10175620379041384281U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14079679617394330781U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 1203082119358827708U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 523869107818193101U) ^ aNonceWordL;
            aOrbiterC = RotL64((aOrbiterC * 4629501113595689157U), 13U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 4028324959540432983U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 15447631947468213912U) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 6037306615787729185U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 11U);
            aIngress = aIngress + (RotL64(aOrbiterA, 29U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 43U));
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 37U) + aOrbiterD) + RotL64(aOrbiterC, 19U));
            aWandererB = aWandererB + (((((RotL64(aScatter, 11U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 37U)) + aNonceWordB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 53U) + aOrbiterB) + RotL64(aOrbiterA, 13U));
            aWandererI = aWandererI + ((((RotL64(aCross, 27U) + aOrbiterA) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterK, 58U)) + aNonceWordJ);
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + RotL64(aOrbiterD, 47U)) + aOrbiterJ) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 44U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 11U));
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 58U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 29904U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((aIndex + 28097U)) & S_BLOCK1], 35U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29343U)) & W_KEY1], 14U) ^ RotL64(aFireLaneC[((aIndex + 27741U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29269U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28082U)) & S_BLOCK1], 47U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29782U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneB[((aIndex + 28067U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 51U) + RotL64(aCarry, 4U)) + (RotL64(aIngress, 39U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((((aWandererA + RotL64(aScatter, 28U)) + RotL64(aCarry, 27U)) + 13960289014350612206U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordK;
            aOrbiterF = (aWandererJ + RotL64(aCross, 51U)) + 3483331015269589730U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 51U)) + 6873299241002444518U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 43U)) + RotL64(aCarry, 13U)) + 3562094007125534229U) + aPhaseHOrbiterAssignSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterC = (aWandererF + RotL64(aPrevious, 19U)) + 11422367439932782705U;
            aOrbiterJ = ((aWandererD + RotL64(aCross, 57U)) + 532453428514259816U) + aNonceWordP;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 37U)) + 17810941465810193088U) + aNonceWordO;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 11869759058631106331U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 8837581071876177566U;
            aOrbiterH = RotL64((aOrbiterH * 15329827515970522213U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 17185378327053837778U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 7578253375676981500U;
            aOrbiterG = RotL64((aOrbiterG * 13371647568758721729U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 17112646434432814442U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 14949096407295697881U;
            aOrbiterE = RotL64((aOrbiterE * 14770977858283051753U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 4259590620758467836U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 6534899413644542303U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7987609419215568661U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2637407498893694243U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 15819295597921425711U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 5202015597375051399U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6373559542002699718U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 11694562937392022505U;
            aOrbiterJ = RotL64((aOrbiterJ * 9311557972331218597U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3308736483775453062U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12749929710650475901U;
            aOrbiterF = RotL64((aOrbiterF * 248428400724560945U), 27U);
            //
            aIngress = RotL64(aOrbiterF, 10U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterC, 35U));
            aIngress = aIngress + RotL64(aOrbiterG, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterG) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + aNonceWordA) + aPhaseHWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterF, 41U)) + RotL64(aCarry, 43U)) + aNonceWordN);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 28U) + RotL64(aOrbiterH, 19U)) + aOrbiterF);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 48U)) + aOrbiterG) + aNonceWordL) + aPhaseHWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 34U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererA, 39U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32603U)) & S_BLOCK1], 30U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32112U)) & W_KEY1], 21U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30352U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32344U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32309U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 31866U)) & W_KEY1], 39U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 40U) + RotL64(aIngress, 27U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = ((aWandererH + RotL64(aCross, 29U)) + 8020711767807230555U) + aNonceWordJ;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 57U)) + 15368693777246341570U) + aNonceWordB;
            aOrbiterC = (((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 27U)) + 5117523734225562401U) + aNonceWordL;
            aOrbiterA = ((aWandererI + RotL64(aIngress, 40U)) + RotL64(aCarry, 3U)) + 13155269151097507808U;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 51U)) + RotL64(aCarry, 43U)) + 9879303753623578272U) + aNonceWordD;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 23U)) + 1165799257173794826U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererA + RotL64(aScatter, 11U)) + 930641942062732091U) + aPhaseHOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11330571332221123153U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 2862963158282518899U) ^ aNonceWordI;
            aOrbiterC = RotL64((aOrbiterC * 13782195862525974199U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 6019186399361476659U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 1924419843785161958U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 9485557122500346869U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12618629043591380461U) + aNonceWordC;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9334176504266512405U;
            aOrbiterG = RotL64((aOrbiterG * 18239109235362925739U), 23U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterA) + 16829692481030013551U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 5604784396927022709U;
            aOrbiterF = RotL64((aOrbiterF * 2833893610883508353U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 16124030106598549644U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16571659812830230677U;
            aOrbiterA = RotL64((aOrbiterA * 4668250364992383549U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 15171089673591843703U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 2826755560293849328U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 22U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9397017963457655287U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9976785768283589291U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 11845100564714691809U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4935139932585319251U), 51U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 41U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterG, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterC) + RotL64(aCarry, 27U)) + aNonceWordN);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 30U) + RotL64(aOrbiterC, 27U)) + aOrbiterF);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterC, 3U)) + aOrbiterE) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 51U)) + aOrbiterC) + aNonceWordP);
            aWandererA = aWandererA + (((RotL64(aCross, 21U) + RotL64(aOrbiterH, 42U)) + aOrbiterJ) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 11U) + aOrbiterF) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK + (((RotL64(aIngress, 53U) + RotL64(aOrbiterA, 19U)) + aOrbiterH) + aNonceWordE);
            //
            aCarry = aCarry + (RotL64(aWandererA, 10U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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

void TwistExpander_Cricket_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xE3B1879C2A78FB63ULL + 0x8419E3CC03AC46D3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xEBB1D8C1AD2265D5ULL + 0xA5E3AE2B851513F8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xB901128EE557A39DULL + 0xEE7EC68815327959ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA5EFF2F63A2F301FULL + 0xEE798A6D79CCEBEDULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xDBBE263CFB15B2CDULL + 0xD1624A283F0E77F9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x875CA47185E08757ULL + 0xE1B6AA6A8302E2B1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE0595FC8F99CCDA7ULL + 0xE577FCE834A194A3ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xB975507083D5055FULL + 0xE37435A091B4D909ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xD4D448544D35BA77ULL + 0x85C29BE16FEA2662ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x965387525E29874BULL + 0x80EF3C218361B860ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xB0E69E0FCE3C234DULL + 0xAA74DE5886C3AAA2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC61D34EEE45CC81BULL + 0xA6D6F3BD1F319A2DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xBCB3DCAD7341A4CFULL + 0xE8026F8575773BEFULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xF307F2707123F6D5ULL + 0xC88EF9603D60B319ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xB4AC860F5D9280DBULL + 0xFBE4663A42C58BBBULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA3B036A02B957DA5ULL + 0xB7D28EA1C08E6143ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneC, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneB, aInvestLaneB, aFireLaneA, aOperationLaneA, aFireLaneD, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneA, aInvestLaneB, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // seed_loop_a loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneC
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1417U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneB[((aIndex + 4842U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 4108U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3826U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 353U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCross, 51U)) + (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 6U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((aWandererA + RotL64(aCross, 37U)) + 17264605017518259932U) + aNonceWordI;
            aOrbiterE = ((((aWandererJ + RotL64(aScatter, 23U)) + RotL64(aCarry, 51U)) + 15209184354580778643U) + aPhaseAOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordP;
            aOrbiterD = ((((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 3299527965014731384U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aWandererK + RotL64(aPrevious, 57U)) + 16293096431816127821U;
            aOrbiterH = (((aWandererB + RotL64(aCross, 48U)) + RotL64(aCarry, 5U)) + 11031983436878828337U) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9188018632448236358U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13420816400363406556U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 10958221259662190519U), 3U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 2485063384097917101U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 3089135816938128264U) ^ aNonceWordE;
            aOrbiterF = RotL64((aOrbiterF * 8813152992957361153U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 10730544971770435788U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 10431767565618874806U;
            aOrbiterB = RotL64((aOrbiterB * 4723078464590561545U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 14883796491656899074U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterH) ^ 13465877783538483706U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 14311686051108108503U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 13322163435314643713U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3307316600284371955U) ^ aNonceWordL;
            aOrbiterH = RotL64((aOrbiterH * 12337846092069506365U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 21U);
            aIngress = aIngress + (RotL64(aOrbiterF, 4U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 5U) + RotL64(aOrbiterH, 30U)) + aOrbiterE) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aIngress, 27U) + RotL64(aOrbiterE, 21U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 13U)) + aOrbiterF) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 56U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererJ, 46U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 5U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 6096U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneC[((aIndex + 9717U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 6746U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8475U)) & S_BLOCK1], 18U) ^ RotL64(aExpandLaneD[((aIndex + 5993U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 23U)) ^ (RotL64(aCross, 10U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterH = (((aWandererE + RotL64(aIngress, 29U)) + RotL64(aCarry, 39U)) + 17668251151213543491U) + aNonceWordO;
            aOrbiterB = ((aWandererK + RotL64(aCross, 3U)) + 16101602509895104517U) + aNonceWordA;
            aOrbiterF = ((((aWandererA + RotL64(aScatter, 42U)) + RotL64(aCarry, 19U)) + 9083915270773304935U) + aPhaseAOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 53U)) + 12810720730318214811U;
            aOrbiterI = (((aWandererF + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 18113428002071925621U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterH = ((aOrbiterH + aOrbiterB) + 1582208899354109878U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 4180688104819188154U;
            aOrbiterF = RotL64((aOrbiterF * 3391785441902730815U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8954598189262820611U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 15360094153175355879U;
            aOrbiterB = RotL64((aOrbiterB * 8177798855402983685U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 8383954114668216260U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 15626783326234049197U;
            aOrbiterH = RotL64((aOrbiterH * 15058420415480073793U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 10609978564404958066U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 17656516608997517984U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 4590620354119899777U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 760077259110786536U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterB) ^ 3597338735888033063U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordJ;
            aOrbiterG = RotL64((aOrbiterG * 6548831472863517621U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterB, 13U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 53U));
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterF, 19U)) + aNonceWordD);
            aWandererE = aWandererE + ((((RotL64(aCross, 53U) + RotL64(aOrbiterI, 27U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + aNonceWordB);
            aWandererK = aWandererK + (((((RotL64(aScatter, 21U) + RotL64(aOrbiterB, 60U)) + aOrbiterH) + RotL64(aCarry, 37U)) + aNonceWordL) + aPhaseAWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 30U) + aOrbiterF) + RotL64(aOrbiterI, 5U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 48U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_a loop 3
        // ingress from: aInvestLaneB, aExpandLaneD, aFireLaneA
        // ingress directions: aInvestLaneB forward forced, aExpandLaneD forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneA, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneA backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11969U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((aIndex + 13523U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14244U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 13459U)) & S_BLOCK1], 21U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14459U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 11914U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCross, 44U) + RotL64(aPrevious, 11U)) ^ (RotL64(aCarry, 23U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterB = ((((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 43U)) + 14499676118633326000U) + aPhaseAOrbiterAssignSaltB[((aIndex + 9U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 27U)) + 17191273593018552288U) + aNonceWordN;
            aOrbiterC = (aWandererF + RotL64(aCross, 19U)) + 4085176294948097737U;
            aOrbiterG = (((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 11U)) + 11112671474158908186U) + aNonceWordB;
            aOrbiterE = (((aWandererD + RotL64(aPrevious, 11U)) + 8745787969012266485U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 18074049663777707948U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 2543758649719164688U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 7153845562786344373U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 4659584749412700523U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 974639159259871273U) ^ aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17918719351847605523U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9211220687971081987U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 8567024626862182714U;
            aOrbiterD = RotL64((aOrbiterD * 7755874089832496393U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 5803002132294840900U) + aNonceWordG;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11968489432878148467U;
            aOrbiterB = RotL64((aOrbiterB * 4501441062617123165U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 9470807228394903442U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 1692347973120388469U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 17433393164156231575U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 12U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterC, 37U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((((RotL64(aIngress, 54U) + aOrbiterC) + RotL64(aOrbiterG, 43U)) + RotL64(aCarry, 43U)) + aNonceWordC) + aPhaseAWandererUpdateSaltF[((aIndex + 18U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 21U)) + aOrbiterE) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aScatter, 13U) + aOrbiterE) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 57U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 35U) + aOrbiterD) + RotL64(aOrbiterC, 53U)) + aNonceWordO) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterC, 6U)) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 11U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 39U);
            aCarry = aCarry + RotL64(aIngress, 48U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 19289U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneA[((aIndex + 17238U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 20659U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 18425U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18170U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16554U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 44U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (((aWandererB + RotL64(aPrevious, 48U)) + 6521330037475130256U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterH = ((((aWandererD + RotL64(aCross, 57U)) + RotL64(aCarry, 47U)) + 12611880456055428940U) + aPhaseAOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1]) + aNonceWordN;
            aOrbiterI = ((aWandererJ + RotL64(aIngress, 27U)) + RotL64(aCarry, 3U)) + 12061611078130934708U;
            aOrbiterA = ((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 29U)) + 1558112410801116984U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 5U)) + 10509115227850160786U;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 4045915960688792066U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordG;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1196541286513243082U;
            aOrbiterI = RotL64((aOrbiterI * 5454309408259753479U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 15564991032722373702U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4897765238703641798U;
            aOrbiterC = RotL64((aOrbiterC * 9693901276712946763U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 12327429514907752733U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 6189189797708711636U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterE = RotL64((aOrbiterE * 9017615866338877651U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 6374267075282018852U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1888758503831341439U;
            aOrbiterA = RotL64((aOrbiterA * 74387714918264257U), 3U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterC) + 14956857689299491800U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14879361107223331957U;
            aOrbiterH = RotL64((aOrbiterH * 9166712966729591953U), 35U);
            //
            aIngress = RotL64(aOrbiterE, 27U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterC, 53U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterC, 27U));
            aWandererJ = aWandererJ ^ ((((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 13U)) + aOrbiterI) + aNonceWordI) + aPhaseAWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 42U) + RotL64(aOrbiterA, 57U)) + aOrbiterI) + RotL64(aCarry, 39U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterE, 47U)) + aOrbiterH) + aNonceWordP);
            aWandererF = aWandererF + (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterE, 36U)) + RotL64(aCarry, 21U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 21U));
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererB, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 25688U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneA[((aIndex + 22291U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 24377U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22304U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 27235U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22058U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = (((aWandererI + RotL64(aIngress, 57U)) + 3255291173184001106U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 19U)) + 15308468160116255528U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aPrevious, 3U)) + RotL64(aCarry, 57U)) + 18186972408589866656U;
            aOrbiterA = (((aWandererJ + RotL64(aCross, 14U)) + RotL64(aCarry, 43U)) + 4439324265978331914U) + aNonceWordM;
            aOrbiterC = (aWandererC + RotL64(aScatter, 43U)) + 13099263173016322486U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 7041561081767500660U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 6196422612687812971U) ^ aNonceWordF;
            aOrbiterB = RotL64((aOrbiterB * 13359900204297781063U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 7664260932541281413U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17802347823020441056U;
            aOrbiterJ = RotL64((aOrbiterJ * 2220679459017369255U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 4253107484061190446U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 13799496534030645312U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 9167675060053848207U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 14252892847595951926U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 5663527578664291422U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1]) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 18314294235895182465U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 11148755959699137661U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 17036900929333594592U) ^ aPhaseAOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 16041243617369003291U), 51U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 52U) + aOrbiterB) + RotL64(aOrbiterC, 58U)) + aPhaseAWandererUpdateSaltD[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 3U) + RotL64(aOrbiterA, 19U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordP);
            aWandererI = aWandererI ^ ((((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 43U)) + aOrbiterC) + aNonceWordD) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 29U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterA, 5U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 11U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererA, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27432U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneA[((aIndex + 28510U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 28015U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27982U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 32612U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 30330U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aIngress, 51U)) ^ (RotL64(aCross, 39U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 57U)) + 1297415699043177788U;
            aOrbiterF = (((aWandererF + RotL64(aCross, 57U)) + 17583786534509260153U) + aPhaseAOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1]) + aNonceWordD;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 5U)) + 643197858925708798U) + aNonceWordG;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 28U)) + RotL64(aCarry, 19U)) + 5062653766915694874U) + aNonceWordL;
            aOrbiterJ = ((((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 5U)) + 7034273638367180511U) + aPhaseAOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 2026909726972916996U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 2785690475553211646U;
            aOrbiterI = RotL64((aOrbiterI * 6612792037861160393U), 21U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterG) + 2910341716302991892U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 2834181605200829791U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1510617068750957651U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 13323052600571281928U) + aNonceWordK;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 10434901530315760460U;
            aOrbiterC = RotL64((aOrbiterC * 2042210188346767033U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 247903955625194782U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5196515747387257163U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1799024689023272275U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 7196305682377987476U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14777739876892587484U;
            aOrbiterJ = RotL64((aOrbiterJ * 95220583948241581U), 53U);
            //
            aIngress = RotL64(aOrbiterF, 13U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 52U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aIngress, 42U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererF = aWandererF + ((((RotL64(aScatter, 53U) + aOrbiterC) + RotL64(aOrbiterF, 30U)) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 57U)) + aOrbiterG) + aNonceWordI);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 21U)) + RotL64(aCarry, 53U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 11U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aNonceWordF) + aPhaseAWandererUpdateSaltF[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 21U));
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 5U);
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

void TwistExpander_Cricket_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xBB3B8A69B167C619ULL + 0xEF589FF318C75D75ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE48160C7C426040BULL + 0xBE47E40F7803EA89ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xC31E535BD2131D17ULL + 0xECF981D930A5421EULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9FDDD3E2B2799B79ULL + 0xB7F57E78D972C92CULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xFE562E79968C37DBULL + 0xE06469A673CDDFA5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x803A23AD1AB1EDE5ULL + 0xF12268F54A7F9ADDULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xD1EA164842521543ULL + 0xF3EDA08C97D82A95ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xD7686EB2F8E0D33DULL + 0xCF2961BADB5308FAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC507DAAE4EC3E849ULL + 0xF674CC1A230E7C17ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xAA7ADC7CE0F78F21ULL + 0xBAB612422277597DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xD63ADD43D56FBCEBULL + 0xED84BBF794869D1DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xE0B8021450481AC5ULL + 0xC005410491962BA8ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xCBBF472416286767ULL + 0x8C8EC5092A164FCEULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xBF9B848C1B4EB131ULL + 0x8BF8BB177FD89273ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x975A486FC9AD6D2DULL + 0xDBD2FEE1AF38883BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xE6CA0D245E220B7FULL + 0xFEB3A058BBCE3707ULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aFireLaneA, aInvestLaneC, aExpandLaneB, aExpandLaneC, aInvestLaneD, aFireLaneC, aWorkLaneA, aFireLaneB, aWorkLaneB, aExpandLaneD, aWorkLaneC, aFireLaneD
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2489U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((aIndex + 3444U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 3691U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 872U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1484U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 3082U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aIngress, 11U)) + (RotL64(aCross, 41U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererE + RotL64(aCross, 58U)) + 3550722402315312207U) + aNonceWordH;
            aOrbiterF = ((aWandererK + RotL64(aPrevious, 41U)) + 16724184551669522754U) + aNonceWordE;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 981751330116773021U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 47U)) + RotL64(aCarry, 39U)) + 7891159229704944868U) + aNonceWordD;
            aOrbiterE = (aWandererC + RotL64(aCross, 21U)) + 13618396711464799841U;
            aOrbiterJ = (aWandererH + RotL64(aScatter, 52U)) + 5969291018449003648U;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 14595540413313640042U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aIngress, 11U)) + 3287990436916111762U) + aPhaseBOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aWandererA + RotL64(aCross, 27U)) + 12534369400200483704U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 2277312067930392274U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 10026320559261334353U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 11020464940995912637U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 11258082063135659551U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1445958517675746990U;
            aOrbiterJ = RotL64((aOrbiterJ * 10062265337488757971U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterA) + 1011298251290970844U) + aNonceWordP;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6487834862470043744U;
            aOrbiterF = RotL64((aOrbiterF * 15477913837027179675U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 9966279022928268335U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 10285993486057704393U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15965714363201157535U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16005362468813966136U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 223843444699390781U;
            aOrbiterD = RotL64((aOrbiterD * 665392038954573081U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 18178876294968532775U) + aNonceWordL;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 12490136112181806806U;
            aOrbiterA = RotL64((aOrbiterA * 16380841616662993709U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8775696166557913635U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 16464340319444310842U;
            aOrbiterB = RotL64((aOrbiterB * 18111632334728200721U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 6296039992673546227U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7152939277656436037U;
            aOrbiterH = RotL64((aOrbiterH * 15183918431501487319U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 14066791413416223271U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 5026743227399908016U;
            aOrbiterI = RotL64((aOrbiterI * 5891343232759075675U), 57U);
            //
            aIngress = RotL64(aOrbiterE, 60U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 41U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 41U) + aOrbiterJ) + RotL64(aOrbiterD, 18U)) + aNonceWordJ);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterJ, 47U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aPhaseBWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 51U)) + aOrbiterI) + RotL64(aCarry, 37U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 26U) + RotL64(aOrbiterF, 35U)) + aOrbiterD);
            aWandererC = aWandererC + (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterH) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 5U) + aOrbiterB) + RotL64(aOrbiterH, 43U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterA, 26U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 12U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aNonceWordN) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 35U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 30U));
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneB
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 6279U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 8997U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 9630U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 5956U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8172U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9691U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5498U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 11U) ^ RotL64(aPrevious, 27U)) ^ (RotL64(aCarry, 41U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterD = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 1457104756581596530U;
            aOrbiterI = ((aWandererE + RotL64(aPrevious, 23U)) + 6127240317844622874U) + aNonceWordJ;
            aOrbiterE = ((aWandererI + RotL64(aCross, 27U)) + RotL64(aCarry, 37U)) + 16492290056044189421U;
            aOrbiterA = ((aWandererC + RotL64(aIngress, 35U)) + 10963676850938416468U) + aPhaseBOrbiterAssignSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aCross, 10U)) + 4872917367399752405U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 39U)) + 15218882377875616148U) + aNonceWordO;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 51U)) + 5934166612122118251U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = (aWandererB + RotL64(aPrevious, 3U)) + 14215280930872003003U;
            aOrbiterB = ((aWandererF + RotL64(aIngress, 60U)) + RotL64(aCarry, 21U)) + 11428034799044600979U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 5453003654321728726U) + aNonceWordI;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14273775120265649389U;
            aOrbiterE = RotL64((aOrbiterE * 5139018128323795309U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 328723770018440271U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 13032190719588211088U;
            aOrbiterD = RotL64((aOrbiterD * 13363368478932798315U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2386881543033598494U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1649501123340887116U;
            aOrbiterC = RotL64((aOrbiterC * 11148976582360499033U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 16462401546754210583U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1510579201823042227U;
            aOrbiterK = RotL64((aOrbiterK * 16287912400104043275U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 6889066000014251983U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 11324594596597724357U) ^ aNonceWordP;
            aOrbiterA = RotL64((aOrbiterA * 15344987814648586023U), 41U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 12237796033168436537U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 17306069670330000343U;
            aOrbiterH = RotL64((aOrbiterH * 3167451351403385259U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 14197284538008811658U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 4754134852883071927U;
            aOrbiterF = RotL64((aOrbiterF * 3484427259538998699U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17201907781639753736U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 8318419319239859855U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 10320390501983802091U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 16012488623961565780U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 15583721012865354925U;
            aOrbiterB = RotL64((aOrbiterB * 10656414363201743961U), 5U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 41U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 24U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aCross, 34U) + RotL64(aOrbiterD, 13U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + aOrbiterC) + RotL64(aOrbiterB, 41U));
            aWandererE = aWandererE + (((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 52U)) + aOrbiterA) + aNonceWordB);
            aWandererC = aWandererC + (((RotL64(aIngress, 52U) + RotL64(aOrbiterE, 29U)) + aOrbiterF) + aNonceWordN);
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 57U) + aOrbiterE) + RotL64(aOrbiterH, 47U)) + aNonceWordK) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + RotL64(aOrbiterC, 37U)) + aOrbiterE) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 60U)) + aOrbiterD);
            aWandererG = aWandererG + ((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterK, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 51U) ^ aWandererJ);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 48U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + RotL64(aWandererC, 39U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneC
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 12414U)) & S_BLOCK1], 56U) ^ RotL64(aOperationLaneA[((aIndex + 12992U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 13690U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13100U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 13247U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 39U)) ^ (RotL64(aCarry, 11U) + RotL64(aIngress, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererF + RotL64(aPrevious, 47U)) + 12136097566601676613U) + aNonceWordL;
            aOrbiterB = (((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 27U)) + 7969431322248040056U) + aNonceWordC;
            aOrbiterC = ((aWandererI + RotL64(aScatter, 60U)) + 10530676021510553889U) + aPhaseBOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 53U)) + 8740777303075445264U;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 13249434169895564739U) + aNonceWordJ;
            aOrbiterJ = (((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 51U)) + 15529577005925628472U) + aPhaseBOrbiterAssignSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aIngress, 36U)) + 344627093687331562U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 5U)) + 8824277416519988893U) + aNonceWordA;
            aOrbiterG = (aWandererJ + RotL64(aScatter, 29U)) + 5636276438449709875U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 2079413361031851552U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 7807998179168655561U;
            aOrbiterC = RotL64((aOrbiterC * 961456853699784753U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 13589392896232029112U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 10733011474804473996U;
            aOrbiterH = RotL64((aOrbiterH * 361749145931578805U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterC) + 15934162328347805968U) + aNonceWordB;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 7573511217796245232U;
            aOrbiterA = RotL64((aOrbiterA * 10694563909931636155U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4828475187337891975U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 13284974329890393113U;
            aOrbiterJ = RotL64((aOrbiterJ * 10831075817642374287U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 13173869918669643112U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 15841507674783398167U) ^ aNonceWordD;
            aOrbiterI = RotL64((aOrbiterI * 15632933198136963277U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 14168272451055700516U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 11134471485501999898U;
            aOrbiterK = RotL64((aOrbiterK * 8019507184494591705U), 19U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterG) + 2611858916687822610U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 17863271539727513641U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4987884722174985677U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 8874401993454249066U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5131480593493950665U;
            aOrbiterB = RotL64((aOrbiterB * 8585874663602346121U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 9366563022381918996U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterK) ^ 7890729519928340296U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11428572374057899517U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 34U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterB, 29U));
            aIngress = aIngress + RotL64(aOrbiterG, 50U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterI, 13U));
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterC, 43U)) + aNonceWordG);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + RotL64(aOrbiterG, 57U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 47U)) + aOrbiterA) + RotL64(aCarry, 51U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 39U) + aOrbiterB) + RotL64(aOrbiterF, 26U));
            aWandererF = aWandererF + (((RotL64(aCross, 11U) + aOrbiterK) + RotL64(aOrbiterI, 51U)) + aPhaseBWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterH, 35U));
            aWandererB = aWandererB + ((((RotL64(aPrevious, 30U) + aOrbiterC) + RotL64(aOrbiterJ, 21U)) + RotL64(aCarry, 3U)) + aNonceWordE);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 43U) + aOrbiterH) + RotL64(aOrbiterF, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 52U) ^ aWandererB);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 47U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16523U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneC[((aIndex + 17836U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18035U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20011U)) & S_BLOCK1], 44U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16456U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 6U) + RotL64(aPrevious, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterE = ((aWandererD + RotL64(aIngress, 4U)) + 13053031069776604052U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 29U)) + 1331396630251085122U) + aNonceWordJ;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 13U)) + 15879286043343942393U) + aNonceWordB;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 13U)) + 13590365633321406830U;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 57U)) + 14569235423040242618U) + aNonceWordK;
            aOrbiterD = (aWandererB + RotL64(aPrevious, 34U)) + 11397370636618371560U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 3455933494593971847U;
            aOrbiterB = ((((aWandererI + RotL64(aScatter, 39U)) + RotL64(aCarry, 43U)) + 1307153376443784593U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererF + RotL64(aIngress, 47U)) + 10688618762584786871U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 17746248451153600096U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 8512568600755410158U;
            aOrbiterK = RotL64((aOrbiterK * 16648320170768234063U), 43U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 8950230550112591092U) + aNonceWordP;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17790968369472845496U;
            aOrbiterJ = RotL64((aOrbiterJ * 5104988920132008913U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 12583323865381967534U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 11243927099685293887U;
            aOrbiterG = RotL64((aOrbiterG * 12867003042486433971U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 9690268715525781389U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 7466066217365074653U;
            aOrbiterH = RotL64((aOrbiterH * 17565696765505320889U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 3673528673209875118U) + aNonceWordA;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14079103852360952255U;
            aOrbiterD = RotL64((aOrbiterD * 17449228863409999629U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 6747836856132250630U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 5027692924422297153U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 2492421273167124437U), 27U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 11370341866003395776U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14013204893442579282U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6602239957997240785U), 37U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3436953430697936790U) + aNonceWordE;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6399073534839993637U;
            aOrbiterE = RotL64((aOrbiterE * 14186050072610021241U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 7054057507823631422U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 5752085719673338095U;
            aOrbiterB = RotL64((aOrbiterB * 13252660162476029593U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 11U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterB, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aCross, 57U) + aOrbiterK) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 37U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 60U)) + aNonceWordO);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 37U) + aOrbiterF) + RotL64(aOrbiterJ, 51U)) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterH, 19U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 43U) + aOrbiterH) + RotL64(aOrbiterA, 23U));
            aWandererH = aWandererH + ((RotL64(aCross, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 11U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 22U) + aOrbiterA) + RotL64(aOrbiterG, 47U)) + aNonceWordG);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 5U) + RotL64(aOrbiterA, 30U)) + aOrbiterB) + aNonceWordL);
            //
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 30U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 34U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 5
        // ingress from: aWorkLaneB, aInvestLaneD, aExpandLaneD
        // ingress directions: aWorkLaneB forward forced, aInvestLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aWorkLaneA, aInvestLaneC
        // cross directions: aWorkLaneA backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23664U)) & S_BLOCK1], 53U) ^ RotL64(aInvestLaneD[((aIndex + 26961U)) & S_BLOCK1], 36U));
            aIngress ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 25196U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23738U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25607U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 39U) + RotL64(aCarry, 57U)) ^ (RotL64(aCross, 12U) ^ RotL64(aPrevious, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 60U)) + 12980104182836602177U) + aPhaseBOrbiterAssignSaltA[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 43U)) + 3172622203188863995U) + aNonceWordO;
            aOrbiterK = ((aWandererI + RotL64(aCross, 23U)) + 1170974132219980203U) + aPhaseBOrbiterAssignSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 19U)) + 6035201940965047490U) + aNonceWordJ;
            aOrbiterJ = (aWandererC + RotL64(aCross, 13U)) + 18033907118424996722U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 5U)) + 14604813424800580304U) + aNonceWordI;
            aOrbiterI = ((aWandererK + RotL64(aScatter, 28U)) + RotL64(aCarry, 13U)) + 13720232492851066035U;
            aOrbiterA = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 23U)) + 3902659710585257448U) + aNonceWordF;
            aOrbiterF = ((aWandererD + RotL64(aCross, 35U)) + RotL64(aCarry, 39U)) + 8331560652661619868U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 4485014147538689794U) + aNonceWordC;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 168202636924512424U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 13711020666131492091U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16227825670092707848U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4792781933944671365U) ^ aPhaseBOrbiterUpdateSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15859849676231455283U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 12636865372722601282U) + aNonceWordK;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 18198291399585556632U;
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 51U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 3650053185419807206U) + aNonceWordP;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 5897288963905408776U;
            aOrbiterA = RotL64((aOrbiterA * 3706949366974086151U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 9922308113622901726U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 13352279749091561510U;
            aOrbiterD = RotL64((aOrbiterD * 4025213180483632557U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 14969461950939646117U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 10231661776135056651U) ^ aPhaseBOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11284575051455238501U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10621934544068320859U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 6029116920305246887U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 6087523725059376905U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 12887482425168671195U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 8351351557123783853U;
            aOrbiterJ = RotL64((aOrbiterJ * 3839381627914762245U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5405938210926464973U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 385145802287899406U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8330751480464271445U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 35U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 39U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterE, 35U));
            aWandererI = aWandererI + ((((RotL64(aCross, 10U) + RotL64(aOrbiterJ, 19U)) + aOrbiterF) + RotL64(aCarry, 19U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 47U)) + aOrbiterD) + aNonceWordA);
            aWandererE = aWandererE + (((((RotL64(aIngress, 23U) + RotL64(aOrbiterA, 12U)) + aOrbiterJ) + RotL64(aCarry, 57U)) + aNonceWordE) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterE, 43U));
            aWandererF = aWandererF + ((RotL64(aScatter, 58U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG + ((((RotL64(aIngress, 39U) + RotL64(aOrbiterG, 6U)) + aOrbiterF) + aNonceWordD) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 23U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 14U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 43U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererE, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneD
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28832U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneA[((aIndex + 31410U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31443U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31653U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31909U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 54U) + RotL64(aIngress, 29U)) ^ (RotL64(aPrevious, 3U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (aWandererC + RotL64(aScatter, 29U)) + 2101601659597850213U;
            aOrbiterG = (((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 2759794072560720121U) + aNonceWordE;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 35U)) + RotL64(aCarry, 39U)) + 9443562552411269339U;
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 18U)) + 10801360546699857975U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 43U)) + 8020716394829332019U) + aNonceWordP;
            aOrbiterF = (((aWandererK + RotL64(aCross, 13U)) + 1021894212367773801U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 39U)) + RotL64(aCarry, 13U)) + 13346855534622490176U;
            aOrbiterH = ((aWandererD + RotL64(aScatter, 53U)) + 16359309548462953836U) + aNonceWordN;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 24U)) + 12642446944680783519U) + aPhaseBOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 8197424982767553380U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 14346334610901859094U;
            aOrbiterI = RotL64((aOrbiterI * 16982899923227935679U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 14171304260534233539U) + aNonceWordD;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 334531601308283605U;
            aOrbiterA = RotL64((aOrbiterA * 5012968232749075075U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 10707856298471572695U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 18364775750091914766U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 15735143943129143265U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 8531394793118363836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 15352876929406908882U;
            aOrbiterG = RotL64((aOrbiterG * 475199047053777179U), 53U);
            //
            aOrbiterI = (((aOrbiterI + aOrbiterH) + 567682016232278157U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (((aOrbiterF ^ aOrbiterI) ^ 2068146551757663119U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 1557877740957797555U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7776122587613256525U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16430938890724272256U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 4540270493783593257U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 11912000645055436094U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 16800749242578741498U;
            aOrbiterJ = RotL64((aOrbiterJ * 17804584625034241737U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 5909199180260499150U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 5751089915336865588U;
            aOrbiterH = RotL64((aOrbiterH * 15376689503142397927U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3478216857728853008U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 18007567146937338241U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 6620498877303917855U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 60U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 60U)) + aOrbiterG);
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 57U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterJ, 39U)) + aNonceWordL);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterK) + aNonceWordM) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterA, 43U)) + aOrbiterC) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 39U) + aOrbiterF) + RotL64(aOrbiterJ, 53U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterH, 12U)) + aNonceWordI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 34U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aNonceWordF);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererG);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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

void TwistExpander_Cricket_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCFF3F0E8A2DB252BULL + 0xBC4FD37FE341D552ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xDA831E2EAFDEF2CBULL + 0x90FC8AFDE5F2288AULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x82241F66A7B6484FULL + 0x85D23617653C0DD5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xA14E17128F865BDFULL + 0xD2D49F70F9A2DEC5ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9212800C025F7599ULL + 0x9EFE13A5BF1FF842ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0x9E34252CCDBD9D03ULL + 0x82F8EACFF2163CABULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC61DB70ECDC2B071ULL + 0x94AE99797F712CDFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xCD14D1D363AAA461ULL + 0xD126E6B3374FA830ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC3036B8D68404DCFULL + 0xEBA5A535EBE5C452ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBAF4C8FA84FEE735ULL + 0xACBD2CBCEB3DDC1FULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xA80597DB05D71851ULL + 0xA3BFF29625957EB7ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xC55490C54DF9F271ULL + 0xDFC1D8314B7C0504ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE10FFA5CE8013D33ULL + 0xA78D608406E1ECB6ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xA11AB8158970F95BULL + 0xA74E782CEB31E515ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE77D95906F2FBB8BULL + 0xC0C012E1FCE2AEBCULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xA8801B72639FB949ULL + 0xCDA12AD1EB2B9033ULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 517U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneB[((aIndex + 3684U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 1207U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3606U)) & S_BLOCK1], 24U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3256U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 1884U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCross, 20U)) ^ (RotL64(aIngress, 41U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererB + RotL64(aIngress, 36U)) + RotL64(aCarry, 51U)) + 9435962834163239322U) + aPhaseDOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 13U)) + 10524704356081318973U) + aNonceWordA;
            aOrbiterA = (aWandererH + RotL64(aCross, 43U)) + 7403401305665208680U;
            aOrbiterE = ((aWandererI + RotL64(aScatter, 21U)) + RotL64(aCarry, 3U)) + 7525414805023556493U;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 53U)) + 1116686470029070951U) + aPhaseDOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 29U)) + 13257612299137802420U) + aNonceWordN;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 3U)) + 9181543003986598283U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 9739384852307501107U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 11308402900229016057U;
            aOrbiterA = RotL64((aOrbiterA * 12690186771773188967U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14935167593705272337U) + aNonceWordK;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7171824007631943535U;
            aOrbiterG = RotL64((aOrbiterG * 4839974427616194289U), 13U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 8068411284829563567U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = (((aOrbiterE ^ aOrbiterB) ^ 12350207458513447578U) ^ aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterE = RotL64((aOrbiterE * 813973258659041895U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17039236343991574134U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 18291683592714999632U;
            aOrbiterD = RotL64((aOrbiterD * 7771718817924840713U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 6239616841884430968U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 10604527977569876774U;
            aOrbiterK = RotL64((aOrbiterK * 6972820410084939637U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 1707724300671717658U) + aNonceWordG;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 3802268808625297647U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 11296811630387191563U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 9423064323799920219U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 242153923313096551U;
            aOrbiterB = RotL64((aOrbiterB * 12117679073775630197U), 35U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aScatter, 27U) + aOrbiterB) + RotL64(aOrbiterK, 48U)) + RotL64(aCarry, 57U)) + aPhaseDWandererUpdateSaltA[((aIndex + 7U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 3U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + aNonceWordE);
            aWandererF = aWandererF + ((RotL64(aIngress, 10U) + aOrbiterA) + RotL64(aOrbiterB, 35U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + aNonceWordJ);
            aWandererG = aWandererG + ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterG, 3U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 57U)) + aOrbiterJ) + aPhaseDWandererUpdateSaltF[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + aOrbiterK) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 46U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 23U));
            aCarry = aCarry + RotL64(aWandererF, 29U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 8212U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneC[((aIndex + 9094U)) & S_BLOCK1], 19U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 5632U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 6847U)) & S_BLOCK1], 37U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 10887U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 7736U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 8024U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 14U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterI = ((aWandererE + RotL64(aIngress, 29U)) + 6521330037475130256U) + aNonceWordP;
            aOrbiterC = ((aWandererH + RotL64(aCross, 23U)) + RotL64(aCarry, 39U)) + 12611880456055428940U;
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 5U)) + 12061611078130934708U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 1558112410801116984U;
            aOrbiterD = (aWandererD + RotL64(aCross, 35U)) + 10509115227850160786U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 58U)) + 4045915960688792066U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 51U)) + 1196541286513243082U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordJ;
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15564991032722373702U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 4897765238703641798U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 9693901276712946763U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 12327429514907752733U) + aNonceWordD;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 6189189797708711636U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9017615866338877651U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 6374267075282018852U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 1888758503831341439U;
            aOrbiterE = RotL64((aOrbiterE * 74387714918264257U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 14956857689299491800U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 14879361107223331957U;
            aOrbiterC = RotL64((aOrbiterC * 9166712966729591953U), 57U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 16086885494838105042U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 8069724185844303923U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 8878470736758734353U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10854345917959911439U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7078313614360332089U;
            aOrbiterI = RotL64((aOrbiterI * 9864025732292844871U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 15083669236062255011U) + aNonceWordB;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 594879695916679116U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9852515479152735283U), 43U);
            //
            aIngress = RotL64(aOrbiterI, 27U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 36U));
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aScatter, 35U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 51U)) + aOrbiterD);
            aWandererK = aWandererK + (((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 28U)) + aOrbiterF) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterC, 11U)) + aOrbiterI);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 5U)) + aOrbiterI) + aNonceWordG) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aCross, 26U) + aOrbiterD) + RotL64(aOrbiterF, 35U)) + aNonceWordC);
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 43U)) + aOrbiterA) + aPhaseDWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 41U) ^ aWandererE);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15063U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 11796U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 16364U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 14421U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 13203U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCross, 6U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterG = (aWandererC + RotL64(aScatter, 5U)) + 11274974230580265396U;
            aOrbiterK = (((aWandererH + RotL64(aPrevious, 20U)) + 16658438747342741547U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordN;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 43U)) + 16612986966106053844U) + aNonceWordD;
            aOrbiterF = (((aWandererE + RotL64(aCross, 37U)) + RotL64(aCarry, 27U)) + 9329502236843231290U) + aNonceWordO;
            aOrbiterB = ((aWandererA + RotL64(aScatter, 53U)) + RotL64(aCarry, 13U)) + 14088261356708344656U;
            aOrbiterD = (((aWandererI + RotL64(aIngress, 11U)) + 13692608802007789581U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 27U)) + RotL64(aCarry, 53U)) + 6824473946645682398U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 2072915876348570040U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 7420507753044460759U) ^ aPhaseDOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 13239288539564571257U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 4677557318688502593U) + aNonceWordH;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 15081678577055628459U;
            aOrbiterK = RotL64((aOrbiterK * 16659305295251177155U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 7026792817486507482U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14871665922943969918U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 694073180313083145U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 6807734532159292872U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 17882797335141303280U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 15439872930381050291U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9233542707022629190U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 1205501586581350876U;
            aOrbiterB = RotL64((aOrbiterB * 2596053290311090589U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 10878718669747466677U) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 8066049063548639241U) ^ aPhaseDOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3031382633089381605U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 861295180226875235U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 9134969787937288583U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 7565008208670843555U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 19U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 60U));
            aIngress = aIngress + (RotL64(aOrbiterF, 37U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterF, 11U)) + aOrbiterK) + RotL64(aCarry, 13U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + aOrbiterG) + RotL64(aOrbiterB, 47U));
            aWandererH = aWandererH + (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterK) + RotL64(aCarry, 53U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterB, 20U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aPrevious, 13U) + aOrbiterA) + RotL64(aOrbiterJ, 53U)) + aNonceWordG);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 37U) + RotL64(aOrbiterF, 29U)) + aOrbiterB) + aNonceWordE) + aPhaseDWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterA, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 52U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 20716U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneA[((aIndex + 21709U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 20658U)) & S_BLOCK1], 26U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 20006U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneD[((aIndex + 19358U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 41U) ^ RotL64(aPrevious, 28U)) + (RotL64(aIngress, 13U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 5U)) + RotL64(aCarry, 23U)) + 16424657151168221875U;
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 50U)) + 17150123681886380361U) + aNonceWordP;
            aOrbiterB = (aWandererH + RotL64(aCross, 57U)) + 16041993588694572757U;
            aOrbiterD = ((((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 43U)) + 9871185846434828537U) + aPhaseDOrbiterAssignSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordC;
            aOrbiterH = (((aWandererJ + RotL64(aCross, 41U)) + RotL64(aCarry, 57U)) + 11227236398354430757U) + aNonceWordK;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 19U)) + 5399325217402192631U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 11U)) + 9248828789282890454U) + aNonceWordH;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 9041370494203701062U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 14944424084524970764U;
            aOrbiterB = RotL64((aOrbiterB * 10283363059424655079U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5481938174456671041U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14783648629543752715U;
            aOrbiterC = RotL64((aOrbiterC * 7260164783191886395U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 12355573914530445723U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 9863991559011968318U) ^ aNonceWordG;
            aOrbiterJ = RotL64((aOrbiterJ * 8495251211794343179U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16149688605937250965U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 106041828692026825U) ^ aNonceWordB;
            aOrbiterF = RotL64((aOrbiterF * 12199934305374582599U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 8076098639554567792U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = (((aOrbiterA ^ aOrbiterJ) ^ 11155119311895580013U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterA = RotL64((aOrbiterA * 1495180896564818647U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 6847612160595917702U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 16094377920388017367U;
            aOrbiterH = RotL64((aOrbiterH * 4875801863643206333U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13584719866672696684U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 13446209321646234607U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9945349065094781529U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterJ, 21U);
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterB, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterB, 29U)) + RotL64(aCarry, 13U));
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterD, 57U)) + aNonceWordF) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + aNonceWordM);
            aWandererJ = aWandererJ + ((RotL64(aCross, 35U) + aOrbiterH) + RotL64(aOrbiterA, 51U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 4U) + aOrbiterC) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 4U)) + aOrbiterD) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 22093U)) & S_BLOCK1], 53U) ^ RotL64(aSnowLaneB[((aIndex + 25909U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 24090U)) & S_BLOCK1], 38U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 21953U)) & S_BLOCK1], 50U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 26834U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 54U)) ^ (RotL64(aIngress, 5U) ^ RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 53U)) + 14157904117287696136U;
            aOrbiterC = (((aWandererG + RotL64(aPrevious, 12U)) + RotL64(aCarry, 19U)) + 7369512677371640676U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aIngress, 21U)) + 8411250745902073798U) + aPhaseDOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = (aWandererC + RotL64(aCross, 47U)) + 5002041814539710275U;
            aOrbiterK = (aWandererD + RotL64(aScatter, 27U)) + 9538041410816283124U;
            aOrbiterF = ((aWandererA + RotL64(aCross, 37U)) + 5210700103927513061U) + aNonceWordK;
            aOrbiterG = (((aWandererB + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 7600709399101287982U) + aNonceWordB;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2366369466696580499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 5544575244203019109U;
            aOrbiterA = RotL64((aOrbiterA * 16231219246786333057U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 8710073749110329779U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 15998211310115361630U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 15275657696897688955U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15354357553877376422U) + aNonceWordM;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10657523549259276169U;
            aOrbiterG = RotL64((aOrbiterG * 13695239532898311073U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10405750198355464768U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 3465819693133515142U;
            aOrbiterI = RotL64((aOrbiterI * 14678343718277562799U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 16724189641701408630U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3484340153620198872U;
            aOrbiterJ = RotL64((aOrbiterJ * 17247547677520703125U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 7420442404884871126U) + aNonceWordF;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 11138445997256757636U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11167543379937571127U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 1428191560884663125U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 16950093140800653985U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4423012306984814805U), 13U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 30U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 53U));
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterC, 23U)) + RotL64(aCarry, 53U)) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterC);
            aWandererA = aWandererA + (((RotL64(aCross, 50U) + aOrbiterC) + RotL64(aOrbiterJ, 29U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + aPhaseDWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + aNonceWordC);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 5U) + aOrbiterK) + RotL64(aOrbiterI, 11U));
            aWandererH = aWandererH + ((((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 60U)) + RotL64(aCarry, 5U)) + aPhaseDWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererH, 14U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + RotL64(aWandererC, 35U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 30142U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneA[((aIndex + 27854U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 29559U)) & S_BLOCK1], 6U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 27741U)) & S_BLOCK1], 4U) ^ RotL64(aExpandLaneB[((aIndex + 27402U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 20U)) ^ (RotL64(aPrevious, 5U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterA = (aWandererG + RotL64(aIngress, 19U)) + 9914837590440975587U;
            aOrbiterE = ((((aWandererB + RotL64(aPrevious, 50U)) + RotL64(aCarry, 23U)) + 6706125076401958051U) + aPhaseDOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterH = (aWandererH + RotL64(aCross, 37U)) + 16570817772679258409U;
            aOrbiterI = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 41U)) + 6843705658115186948U) + aNonceWordN;
            aOrbiterF = (((aWandererE + RotL64(aCross, 27U)) + RotL64(aCarry, 57U)) + 16099930446791572351U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 43U)) + 5420550009556030459U) + aNonceWordM;
            aOrbiterJ = ((aWandererC + RotL64(aIngress, 3U)) + 5729549069420177477U) + aNonceWordD;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 15590601126188675834U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13044027390998620029U;
            aOrbiterH = RotL64((aOrbiterH * 16845199115313444123U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 11068338135659636772U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 6584988841809544332U;
            aOrbiterF = RotL64((aOrbiterF * 1683336180438945439U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8516813219883915404U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10647314042912492785U;
            aOrbiterG = RotL64((aOrbiterG * 15559481057047148785U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 201691689889605304U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 15512161798401184003U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11473219183982564709U), 13U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterH) + 3883760518944464145U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 13861805129175491145U;
            aOrbiterI = RotL64((aOrbiterI * 17194438894492581181U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 12019138626550801486U) + aNonceWordH;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13030350224959652248U;
            aOrbiterA = RotL64((aOrbiterA * 11724200983306280107U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 2643807255422544248U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 4127143302485631794U) ^ aNonceWordF;
            aOrbiterJ = RotL64((aOrbiterJ * 5441038881111578487U), 19U);
            //
            aIngress = RotL64(aOrbiterA, 23U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aScatter, 6U) + RotL64(aOrbiterJ, 13U)) + aOrbiterH) + aNonceWordI);
            aWandererC = aWandererC + ((((RotL64(aIngress, 29U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterF) + RotL64(aOrbiterA, 23U)) + aNonceWordJ);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 3U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterE, 37U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 53U)) + aOrbiterJ);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + aOrbiterA) + RotL64(aOrbiterI, 30U));
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 34U));
            aCarry = aCarry + RotL64(aWandererJ, 41U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Cricket_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xD3B70DBD9CC64D77ULL + 0xDF20F19DF718CC30ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x82A85FA521A63FEBULL + 0xF2509033AF581B21ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9F8064C5E6A98C09ULL + 0xD3D54643A144CE0AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xBB15B4212E125943ULL + 0xBFA24F22B1BDB977ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xFB6D9F08DA117CE5ULL + 0xF3278F1F96712F17ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x89A162148CFAF8D1ULL + 0x91ACBB44AF28A933ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xD7962D3C46F745CBULL + 0xBD63FCB04E8D9BDBULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xC38E1D98535FB259ULL + 0xA69AA837657D6D64ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEEF2F7B095D06833ULL + 0xB1AA1FA2EDB158A4ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xED7AC243236F3DC3ULL + 0x804176925A9FF905ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xCCE3C3EC9D2D0413ULL + 0xFBFB0CA273D11E36ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xDC3816BAA3C2D447ULL + 0xDD77C3A83B77153DULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA5F1F083B353C67DULL + 0xAD53360AC7D23684ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x8E50515D4DF16419ULL + 0xECE828CB4D3A6CFBULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x900D7F67B792FA85ULL + 0xB97F22274D595571ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x842F75ACB6D7E13FULL + 0xB75CDCCBA001C7EAULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 86U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneB[((aIndex + 1506U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 4479U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 3138U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 3910U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 6U) ^ RotL64(aCarry, 37U)) + (RotL64(aIngress, 23U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 27U)) + 8506388683755208267U) + aPhaseEOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aWandererH + RotL64(aScatter, 21U)) + 2179323259055019735U) + aNonceWordB;
            aOrbiterG = ((aWandererE + RotL64(aCross, 60U)) + RotL64(aCarry, 21U)) + 3345902531140983016U;
            aOrbiterJ = (aWandererI + RotL64(aPrevious, 19U)) + 17456139311481306584U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 51U)) + 14587864088462311164U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterE = (aWandererF + RotL64(aScatter, 13U)) + 13178947246650647057U;
            aOrbiterB = (aWandererB + RotL64(aCross, 23U)) + 12866578138946916962U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 44U)) + RotL64(aCarry, 39U)) + 13098524333655118173U) + aNonceWordA;
            aOrbiterK = (aWandererG + RotL64(aCross, 47U)) + 15451329483787541982U;
            aOrbiterD = ((aWandererJ + RotL64(aScatter, 35U)) + RotL64(aCarry, 35U)) + 9494299579678389385U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 5U)) + 15581954810375490643U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4487042505730624892U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 2774455928791636186U;
            aOrbiterG = RotL64((aOrbiterG * 15847933919136777451U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12435319582397755819U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 10077180055177766823U;
            aOrbiterE = RotL64((aOrbiterE * 3924363471701748703U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 10391963896910956455U) + aNonceWordN;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 6149237416725301794U;
            aOrbiterC = RotL64((aOrbiterC * 10115917698918612823U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 15673402771629639978U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 14729117178956592426U;
            aOrbiterI = RotL64((aOrbiterI * 9070464269215820531U), 47U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 14492001279368870240U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 6278248084483259952U;
            aOrbiterK = RotL64((aOrbiterK * 16731228350971263873U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15727518866499740411U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 8652631010810965473U) ^ aNonceWordM;
            aOrbiterJ = RotL64((aOrbiterJ * 9508484121620912715U), 51U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterJ) + 13660890300188313775U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 14699253534935936300U;
            aOrbiterD = RotL64((aOrbiterD * 3978135617259934869U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1621689916308271346U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 5651399428852950385U;
            aOrbiterA = RotL64((aOrbiterA * 12220143634120124133U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9833573729127477238U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11171647423058940388U;
            aOrbiterF = RotL64((aOrbiterF * 9692915620701425697U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 10346908196429120039U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 11972183669378621435U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12364429258926549335U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11063215816236490488U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8506388683755208267U;
            aOrbiterH = RotL64((aOrbiterH * 11514304191652750181U), 53U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 57U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterI, 27U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 3U));
            aIngress = aIngress + RotL64(aOrbiterC, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 35U)) + aOrbiterG);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterE, 19U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterC, 11U)) + aNonceWordC);
            aWandererG = aWandererG ^ (((RotL64(aCross, 29U) + RotL64(aOrbiterC, 3U)) + aOrbiterF) + aNonceWordH);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterJ, 23U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 5U) + RotL64(aOrbiterH, 44U)) + aOrbiterF);
            aWandererA = aWandererA + (((RotL64(aIngress, 44U) + RotL64(aOrbiterF, 5U)) + aOrbiterD) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterH, 21U)) + aOrbiterK);
            aWandererB = aWandererB + ((((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterI, 39U)) + RotL64(aCarry, 39U)) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 57U) + aOrbiterG) + RotL64(aOrbiterB, 56U)) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 24U) + aOrbiterA) + RotL64(aOrbiterK, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 11U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererI);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 58U));
            aCarry = aCarry + (RotL64(aWandererH, 19U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 6836U)) & S_BLOCK1], 30U) ^ RotL64(aInvestLaneC[((aIndex + 8830U)) & S_BLOCK1], 39U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 6737U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10231U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 9664U)) & S_BLOCK1], 11U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10145U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 7827U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 19U)) + (RotL64(aPrevious, 36U) ^ RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 10U)) + RotL64(aCarry, 27U)) + 13350544654542863236U;
            aOrbiterF = (aWandererD + RotL64(aCross, 29U)) + 12364346790125404372U;
            aOrbiterI = (((aWandererC + RotL64(aPrevious, 53U)) + RotL64(aCarry, 47U)) + 9738750172849512764U) + aNonceWordN;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 39U)) + 3781373837635491421U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 41U)) + 16635020317512702337U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 39U)) + 5383653921676231276U;
            aOrbiterJ = (((aWandererK + RotL64(aPrevious, 57U)) + 10181959815492056493U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = (aWandererH + RotL64(aCross, 24U)) + 10005510924273927017U;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 47U)) + 9524687662265740565U) + aPhaseEOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aIngress, 3U)) + 4259138552009771014U;
            aOrbiterK = (aWandererB + RotL64(aCross, 35U)) + 8973051213213726023U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 17602611840127337490U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8218984546932905269U;
            aOrbiterI = RotL64((aOrbiterI * 17504305273683304231U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 18102186122213487888U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 2629927500298092976U;
            aOrbiterH = RotL64((aOrbiterH * 6983280164448292723U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2491581597835795234U) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 9506602492971620955U;
            aOrbiterB = RotL64((aOrbiterB * 9559829640915637163U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 13422942713680612924U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 15037354693234876601U;
            aOrbiterC = RotL64((aOrbiterC * 12692376075738621447U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12896066842192894694U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 2202952306291905855U;
            aOrbiterG = RotL64((aOrbiterG * 6779368532763429997U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 12160313482450599313U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 10812986281270407756U;
            aOrbiterF = RotL64((aOrbiterF * 7786608700746771809U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 12474638293190144525U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 5882870951276225224U;
            aOrbiterD = RotL64((aOrbiterD * 15532427302173572457U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 3782896138051179209U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 10965680631059882311U;
            aOrbiterJ = RotL64((aOrbiterJ * 14060923998307082385U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 15650420683333746952U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 4110674660963676864U;
            aOrbiterE = RotL64((aOrbiterE * 11724979274890265275U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 694817156953099464U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 4402927404825116007U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 579586789292520113U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 6849178151532923489U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterH) ^ 13350544654542863236U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterK = RotL64((aOrbiterK * 2416097748778941523U), 35U);
            //
            aIngress = RotL64(aOrbiterF, 18U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + aPhaseEWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + RotL64(aCarry, 5U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterI, 46U)) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aScatter, 41U) + aOrbiterB) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterE, 39U)) + aOrbiterJ);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterK);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterE, 5U)) + aOrbiterF) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 56U)) + aOrbiterI) + aNonceWordG);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterI);
            aWandererH = aWandererH + ((RotL64(aIngress, 46U) + aOrbiterF) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 23U)) + aOrbiterK) + aNonceWordI);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 39U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererD, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + (RotL64(aWandererG, 30U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 14222U)) & S_BLOCK1], 43U) ^ RotL64(aInvestLaneA[((aIndex + 14882U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 13186U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 12851U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((aIndex + 12382U)) & S_BLOCK1], 44U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 54U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterF = ((aWandererI + RotL64(aCross, 10U)) + 3105313968748067810U) + aNonceWordH;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 19U)) + RotL64(aCarry, 51U)) + 9977249451119627064U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 41U)) + 17941392803495349366U) + aPhaseEOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aIngress, 35U)) + 4279533326705471133U) + aNonceWordI;
            aOrbiterH = (aWandererD + RotL64(aCross, 27U)) + 13983828966811580039U;
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 3U)) + RotL64(aCarry, 37U)) + 3983490984234810378U) + aPhaseEOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = (aWandererG + RotL64(aScatter, 37U)) + 308786542215259956U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 29U)) + 8443607695364427037U;
            aOrbiterA = (aWandererH + RotL64(aCross, 21U)) + 14939626441464340668U;
            aOrbiterI = (((aWandererF + RotL64(aPrevious, 54U)) + RotL64(aCarry, 27U)) + 9350693577306121110U) + aNonceWordO;
            aOrbiterD = ((aWandererB + RotL64(aScatter, 13U)) + 1717071159396961752U) + aNonceWordB;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 15911765265202100610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 14898546272333182767U;
            aOrbiterJ = RotL64((aOrbiterJ * 2674900543810733067U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3560903518513465868U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 5367062725726860234U;
            aOrbiterF = RotL64((aOrbiterF * 8521908836601319553U), 51U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 15233321480618877327U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9288449812290126074U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6815298520404038519U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 5504840529511585676U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6825598386801620046U;
            aOrbiterE = RotL64((aOrbiterE * 11666542445846250077U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6433024450721339470U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 97934156644929458U;
            aOrbiterK = RotL64((aOrbiterK * 8630530773006923215U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 3260053604798744515U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 16539416623243059076U;
            aOrbiterC = RotL64((aOrbiterC * 12199577351166064503U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 9814290051339038920U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13280156404507444041U;
            aOrbiterI = RotL64((aOrbiterI * 15269010043398910061U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11853942590993546833U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13207869904312989977U) ^ aNonceWordG;
            aOrbiterD = RotL64((aOrbiterD * 15503461937625795969U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14536032167989376750U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 3693282775047432356U;
            aOrbiterG = RotL64((aOrbiterG * 5290349323647887877U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5803176485246280271U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 16702526675475954730U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 13695676754973145769U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16454171963808313625U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 3105313968748067810U;
            aOrbiterA = RotL64((aOrbiterA * 16572687178789102843U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 18U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterE, 38U)) + aNonceWordE);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 20U) + aOrbiterE) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 47U)) + aNonceWordC) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 51U)) + aOrbiterJ);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 13U) + aOrbiterC) + RotL64(aOrbiterG, 57U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterF, 21U)) + aOrbiterI) + aPhaseEWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + aOrbiterD) + RotL64(aOrbiterE, 30U)) + aNonceWordK);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterI, 53U)) + aNonceWordF);
            aWandererK = aWandererK + ((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 43U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 35U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + RotL64(aOrbiterG, 23U)) + aOrbiterA) + RotL64(aCarry, 27U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 46U) + RotL64(aOrbiterB, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 60U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererB, 35U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 22U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 20497U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((aIndex + 18524U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16773U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 16671U)) & S_BLOCK1], 19U) ^ RotL64(aInvestLaneD[((aIndex + 18706U)) & S_BLOCK1], 28U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 6U)) ^ (RotL64(aCarry, 19U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterI = ((((aWandererE + RotL64(aIngress, 46U)) + RotL64(aCarry, 53U)) + 10726035965553989335U) + aPhaseEOrbiterAssignSaltB[((aIndex + 23U)) & S_SALT1]) + aNonceWordB;
            aOrbiterH = (aWandererG + RotL64(aPrevious, 23U)) + 967354339530195662U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 10834593005478605624U;
            aOrbiterB = (((aWandererH + RotL64(aScatter, 57U)) + RotL64(aCarry, 47U)) + 1012888282838656933U) + aNonceWordG;
            aOrbiterK = (((aWandererF + RotL64(aCross, 54U)) + RotL64(aCarry, 35U)) + 15283530351725183253U) + aNonceWordP;
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 43U)) + 11724495956731703750U) + aNonceWordA;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 21U)) + 4288330117317505776U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aWandererJ + RotL64(aIngress, 51U)) + 10894778070022873473U;
            aOrbiterC = (aWandererB + RotL64(aScatter, 11U)) + 15563886747621617467U;
            aOrbiterD = (aWandererK + RotL64(aPrevious, 37U)) + 11182488628562891937U;
            aOrbiterF = (aWandererA + RotL64(aIngress, 29U)) + 10420140066310588580U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11775138062167543111U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 16545391898578161683U;
            aOrbiterJ = RotL64((aOrbiterJ * 14588306527161321535U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 1550144656312299266U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 14903504853138279883U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8003033561266164387U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 309935535526750396U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 13991265868040011411U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2887531132228588441U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 1755976294857114222U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2259275858478396846U;
            aOrbiterI = RotL64((aOrbiterI * 7416165760067878161U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 4838175912944552936U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12307900457200936013U;
            aOrbiterD = RotL64((aOrbiterD * 14719363144850838805U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 18025411832912225805U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 981375022769564523U;
            aOrbiterF = RotL64((aOrbiterF * 15869361544011831483U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 3174014054982742562U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 8119692378748963609U;
            aOrbiterC = RotL64((aOrbiterC * 3072354179707448489U), 53U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 14502863160788675807U) + aNonceWordI;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 1207582534593709516U;
            aOrbiterB = RotL64((aOrbiterB * 3045412087535529357U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 5838011917777875072U) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 434594114594643600U;
            aOrbiterE = RotL64((aOrbiterE * 1591023655239709931U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 15711060039063734443U) + aNonceWordN;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 8307150522686198490U;
            aOrbiterH = RotL64((aOrbiterH * 2082452039297764679U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 5805686529930815226U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 10726035965553989335U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 5563221485243331689U), 47U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterF, 42U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterB, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aCross, 52U) + aOrbiterD) + RotL64(aOrbiterB, 13U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 39U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterH, 3U)) + aOrbiterB);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 58U)) + aOrbiterF);
            aWandererI = aWandererI + (((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterG, 5U)) + aPhaseEWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 56U) + aOrbiterF) + RotL64(aOrbiterI, 53U)) + aNonceWordC);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + RotL64(aCarry, 37U)) + aNonceWordF);
            aWandererK = aWandererK ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aNonceWordL);
            aWandererD = aWandererD + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 56U)) + aOrbiterF) + RotL64(aCarry, 5U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterA) + RotL64(aOrbiterG, 41U));
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 39U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererH, 35U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23850U)) & S_BLOCK1], 53U) ^ RotL64(aFireLaneB[((aIndex + 25175U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 21976U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 22795U)) & S_BLOCK1], 10U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 25720U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 25165U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCarry, 5U)) + (RotL64(aCross, 36U) ^ RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterB = (aWandererE + RotL64(aIngress, 13U)) + 11210042748013785976U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 23U)) + 4584747303233477454U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 8878765929792969517U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 51U)) + 2172232330280041122U;
            aOrbiterF = (((aWandererD + RotL64(aCross, 44U)) + RotL64(aCarry, 37U)) + 8378937026022264016U) + aNonceWordL;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 3U)) + 8683007464695824208U;
            aOrbiterC = ((aWandererF + RotL64(aIngress, 21U)) + RotL64(aCarry, 11U)) + 9564352997357118134U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 53U)) + 11713878436769887528U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aCross, 58U)) + 8052917623074021077U) + aNonceWordG;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 39U)) + 7720597162792145185U;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 41U)) + 2602847785328475621U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            //
            aOrbiterB = (((aOrbiterB + aOrbiterA) + 17813669222300509724U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordE;
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 8724263063156573013U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3632927017737834359U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6882429835961613492U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 13213313479525717359U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2411431247725974895U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2401526093648669573U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 3616448566579979749U;
            aOrbiterH = RotL64((aOrbiterH * 13323155103752121393U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 18268262471839710401U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5116424918948694752U;
            aOrbiterG = RotL64((aOrbiterG * 7641143782996332069U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 11405305689555640431U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12427591396711015574U;
            aOrbiterF = RotL64((aOrbiterF * 8112834135715541223U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 16960781161508084626U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 12382604781005282628U;
            aOrbiterI = RotL64((aOrbiterI * 17196168631120103115U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 10054839091354729292U) + aNonceWordH;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 4167641616532985407U;
            aOrbiterC = RotL64((aOrbiterC * 919291747187787625U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14383737233143309039U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 16258779988369405932U;
            aOrbiterA = RotL64((aOrbiterA * 8348773195366160215U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 4777263172049970723U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 12498046021142146499U;
            aOrbiterK = RotL64((aOrbiterK * 5941015011162130901U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 7435001955334177144U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 4100235545173125433U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 5046572784117638909U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 1981704568071298614U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11210042748013785976U;
            aOrbiterJ = RotL64((aOrbiterJ * 17889749044418386565U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 19U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterD, 14U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 39U));
            aIngress = aIngress + (RotL64(aOrbiterC, 41U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 11U));
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterC, 60U)) + aOrbiterD);
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + aOrbiterH) + RotL64(aOrbiterJ, 21U)) + aNonceWordJ) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterF, 11U)) + aOrbiterJ);
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 3U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterK, 42U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aIngress, 51U) + RotL64(aOrbiterD, 39U)) + aOrbiterE);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterH, 35U)) + aNonceWordD);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 37U)) + aOrbiterE) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aCross, 56U) + RotL64(aOrbiterG, 3U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 20U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 11U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + RotL64(aWandererD, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28921U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((aIndex + 27969U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 27463U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28551U)) & S_BLOCK1], 14U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31413U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aIngress, 3U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterC = ((((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 18180797995100240808U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 57U)) + 6585906608223552885U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aPrevious, 50U)) + 14088708930575939855U;
            aOrbiterK = ((aWandererF + RotL64(aIngress, 37U)) + RotL64(aCarry, 23U)) + 468974153311516044U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 43U)) + 12481951025619894110U) + aNonceWordG;
            aOrbiterI = (aWandererB + RotL64(aIngress, 21U)) + 17227987923860711763U;
            aOrbiterH = (aWandererI + RotL64(aScatter, 40U)) + 4373962756657477139U;
            aOrbiterJ = (aWandererC + RotL64(aCross, 29U)) + 2077576476565420951U;
            aOrbiterE = (aWandererH + RotL64(aIngress, 27U)) + 17435011300234663764U;
            aOrbiterD = (aWandererA + RotL64(aCross, 3U)) + 4118039398293246896U;
            aOrbiterF = (((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 51U)) + 13724716599855216683U) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12391461204689596339U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 9900605191533799627U;
            aOrbiterB = RotL64((aOrbiterB * 13553565332531046301U), 11U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 972946858824366125U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17247681919694541215U;
            aOrbiterI = RotL64((aOrbiterI * 2974639094630445643U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15442851427306771601U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 7303586227288294037U;
            aOrbiterH = RotL64((aOrbiterH * 15406402525021428799U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 12650358753454105119U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 1483710933373510492U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 6531763256577221891U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 18065810162229740788U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 11311677121338794007U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 15116367961682119467U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 2355285311890287611U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 1287783821903407734U;
            aOrbiterF = RotL64((aOrbiterF * 8054011680932255985U), 27U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterB) + 9282654686791135654U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 15488608017745542551U;
            aOrbiterD = RotL64((aOrbiterD * 7858866274035085123U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 13296835576073421802U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7127700236018338741U;
            aOrbiterE = RotL64((aOrbiterE * 11246173563106014149U), 19U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 1365928843264598789U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 7777790578813003657U;
            aOrbiterJ = RotL64((aOrbiterJ * 10121688100505628161U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 2104270617375082523U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 13363764449819651164U;
            aOrbiterA = RotL64((aOrbiterA * 2685452132715528975U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 2008038686059197988U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 18180797995100240808U;
            aOrbiterG = RotL64((aOrbiterG * 8978998151475372047U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 47U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterE, 41U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterC, 10U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + aOrbiterH) + RotL64(aOrbiterB, 10U));
            aWandererA = aWandererA + (((RotL64(aCross, 47U) + RotL64(aOrbiterC, 39U)) + aOrbiterG) + RotL64(aCarry, 21U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterB, 21U));
            aWandererE = aWandererE + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterF, 41U)) + aOrbiterI) + aNonceWordE) + aPhaseEWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 21U) + aOrbiterG) + RotL64(aOrbiterJ, 47U)) + aNonceWordM);
            aWandererK = aWandererK + (((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterH, 44U)) + aNonceWordB);
            aWandererB = aWandererB ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterD, 3U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aScatter, 60U) + aOrbiterK) + RotL64(aOrbiterH, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 53U) + aOrbiterH) + RotL64(aOrbiterD, 13U)) + aPhaseEWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 5U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (RotL64(aWandererD, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 40U));
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 23U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Cricket_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xE9691BF5616B4DD9ULL + 0xF8BADC293FEE334AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xBB72DABE5CEF168DULL + 0xF8DF292F910FEB63ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC51B878315C0B587ULL + 0xEF95516CE004331DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE87F349055987319ULL + 0x84F06AF9AB693FE8ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9058B5BEF9485777ULL + 0x93382DCB25B601E3ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB796763710403F61ULL + 0xA50F97A967A55B6AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xADF38201DAF41371ULL + 0xA9EEE0331E1C8DDFULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x9505F18C96E6D2B9ULL + 0x9F5874E0A81F9C7AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xBA2DE2112C6A343BULL + 0xD79EB24CC003E38BULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF34D43FABA5E545BULL + 0xD0AC21E295AFB5F4ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8A2F6808914DB85BULL + 0xDAAFFFA7E541B839ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFDD3E120F73D935BULL + 0x80CD20F7048EC188ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF29A342E52489941ULL + 0xB36BEFAFEA3D0D69ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xCCC763D20F96C49DULL + 0xF423C08A43DFF722ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xE9961FF00111F07DULL + 0xFAADF360574ECFB6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x8DA4E24F14FA843BULL + 0xCE17F2D23CF4FE04ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aInvestLaneA, aOperationLaneC, aOperationLaneD, aSnowLaneA, aSnowLaneC, aInvestLaneC, aInvestLaneB, aSnowLaneD, aWorkLaneC, aExpandLaneA, aInvestLaneD, aExpandLaneB, aSnowLaneB, aExpandLaneC, aWorkLaneD
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aInvestLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aSnowLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aSnowLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 811U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneB[((aIndex + 1478U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 5217U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 3383U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4445U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aSnowLaneA[((aIndex + 3905U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 57U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 12U) + RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 39U)) + RotL64(aCarry, 5U)) + 3621877681473089725U) + aNonceWordP;
            aOrbiterG = ((aWandererB + RotL64(aCross, 18U)) + 4451752751536414717U) + aNonceWordA;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 23U)) + 11371625415377772117U) + aNonceWordH;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 21U)) + 6046792758881150619U;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 43U)) + 8213166120394461682U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 51U)) + 4343156661140422645U) + aPhaseFOrbiterAssignSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterB = (aWandererC + RotL64(aPrevious, 35U)) + 11105271483234947905U;
            aOrbiterA = ((aWandererF + RotL64(aCross, 10U)) + RotL64(aCarry, 29U)) + 348904609985341372U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 5U)) + 12924652822526858767U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 7461211697358520287U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 16551553555297890558U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 16432952324635746293U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 11908056404140782995U) + aNonceWordN;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 9147367258259948715U;
            aOrbiterD = RotL64((aOrbiterD * 10777628928376261667U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8876461054692728610U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10546855952702525404U;
            aOrbiterB = RotL64((aOrbiterB * 10071104785895309677U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 4748636139110443794U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 783046909529525098U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8969157702460927215U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16683965945838696665U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12385412690177109575U;
            aOrbiterE = RotL64((aOrbiterE * 10795062772707143187U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 8210546822184469023U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 13146493623236979963U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13199947810161148155U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13857628148804187115U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 7241297989337473475U;
            aOrbiterA = RotL64((aOrbiterA * 16223448508809614229U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 773904571213804946U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7660676598236419707U;
            aOrbiterI = RotL64((aOrbiterI * 14467390638468925567U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 16822672435156055469U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6514707119190640433U;
            aOrbiterF = RotL64((aOrbiterF * 7097496727567460535U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 43U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 30U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 52U) + RotL64(aOrbiterG, 24U)) + aOrbiterE) + aNonceWordE) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 57U) + RotL64(aOrbiterK, 29U)) + aOrbiterB) + aNonceWordL);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterF, 53U)) + aNonceWordM);
            aWandererC = aWandererC + (((RotL64(aCross, 13U) + aOrbiterK) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterF) + RotL64(aOrbiterI, 43U));
            aWandererH = aWandererH + ((RotL64(aCross, 22U) + aOrbiterA) + RotL64(aOrbiterB, 6U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterA) + aNonceWordF);
            aWandererD = aWandererD + (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterA, 19U)) + aOrbiterJ) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 13U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneC
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 10481U)) & S_BLOCK1], 38U) ^ RotL64(aOperationLaneC[((aIndex + 5492U)) & S_BLOCK1], 5U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7007U)) & S_BLOCK1], 29U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 9352U)) & S_BLOCK1], 47U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10709U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7766U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10294U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 35U)) ^ (RotL64(aPrevious, 23U) + RotL64(aCarry, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterC = ((aWandererG + RotL64(aPrevious, 60U)) + RotL64(aCarry, 27U)) + 1457104756581596530U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 27U)) + 6127240317844622874U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 16492290056044189421U;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 43U)) + RotL64(aCarry, 43U)) + 10963676850938416468U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 19U)) + 4872917367399752405U) + aNonceWordJ;
            aOrbiterI = (aWandererJ + RotL64(aScatter, 39U)) + 15218882377875616148U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 48U)) + 5934166612122118251U) + aPhaseFOrbiterAssignSaltA[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 11U)) + 14215280930872003003U) + aNonceWordC;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 3U)) + 11428034799044600979U) + aNonceWordH;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 5453003654321728726U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 14273775120265649389U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5139018128323795309U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 328723770018440271U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 13032190719588211088U;
            aOrbiterG = RotL64((aOrbiterG * 13363368478932798315U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 2386881543033598494U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 1649501123340887116U;
            aOrbiterK = RotL64((aOrbiterK * 11148976582360499033U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 16462401546754210583U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 1510579201823042227U;
            aOrbiterI = RotL64((aOrbiterI * 16287912400104043275U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6889066000014251983U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 11324594596597724357U;
            aOrbiterJ = RotL64((aOrbiterJ * 15344987814648586023U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 12237796033168436537U) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 17306069670330000343U;
            aOrbiterF = RotL64((aOrbiterF * 3167451351403385259U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 14197284538008811658U) + aNonceWordG;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 4754134852883071927U;
            aOrbiterD = RotL64((aOrbiterD * 3484427259538998699U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 17201907781639753736U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterJ) ^ 8318419319239859855U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterC = RotL64((aOrbiterC * 10320390501983802091U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16012488623961565780U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15583721012865354925U;
            aOrbiterA = RotL64((aOrbiterA * 10656414363201743961U), 29U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 22U);
            aIngress = aIngress + (RotL64(aOrbiterK, 5U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 37U));
            aIngress = aIngress + (RotL64(aOrbiterC, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + aOrbiterH) + RotL64(aOrbiterI, 23U)) + aPhaseFWandererUpdateSaltA[((aIndex + 27U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 53U) + aOrbiterH) + RotL64(aOrbiterG, 57U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterF, 3U)) + RotL64(aCarry, 41U)) + aNonceWordO);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 52U)) + aOrbiterK);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterJ);
            aWandererD = aWandererD ^ (((RotL64(aCross, 43U) + aOrbiterH) + RotL64(aOrbiterC, 27U)) + aNonceWordP);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 35U)) + aOrbiterC) + RotL64(aCarry, 57U)) + aNonceWordA);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 21U) + aOrbiterF) + RotL64(aOrbiterG, 43U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 30U) + aOrbiterD) + RotL64(aOrbiterH, 10U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 46U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 23U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 43U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 3U));
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aWorkLaneC
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aWorkLaneC forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12039U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneA[((aIndex + 13153U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aWorkLaneC[((aIndex + 12839U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 11089U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((aIndex + 15536U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCross, 23U)) ^ (RotL64(aIngress, 35U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterA = (aWandererF + RotL64(aIngress, 56U)) + 18180797995100240808U;
            aOrbiterJ = ((aWandererB + RotL64(aCross, 23U)) + 6585906608223552885U) + aNonceWordO;
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 3U)) + 14088708930575939855U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aWandererD + RotL64(aScatter, 47U)) + 468974153311516044U;
            aOrbiterG = (aWandererA + RotL64(aIngress, 30U)) + 12481951025619894110U;
            aOrbiterI = (((aWandererE + RotL64(aScatter, 19U)) + RotL64(aCarry, 57U)) + 17227987923860711763U) + aNonceWordJ;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 11U)) + RotL64(aCarry, 27U)) + 4373962756657477139U;
            aOrbiterB = ((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 2077576476565420951U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 39U)) + 17435011300234663764U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 4118039398293246896U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 13724716599855216683U;
            aOrbiterK = RotL64((aOrbiterK * 17556333902751079677U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 12391461204689596339U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 9900605191533799627U;
            aOrbiterG = RotL64((aOrbiterG * 13553565332531046301U), 51U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterI) + 972946858824366125U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordD;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 17247681919694541215U;
            aOrbiterD = RotL64((aOrbiterD * 2974639094630445643U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 15442851427306771601U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 7303586227288294037U;
            aOrbiterF = RotL64((aOrbiterF * 15406402525021428799U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12650358753454105119U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1483710933373510492U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6531763256577221891U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 18065810162229740788U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 11311677121338794007U;
            aOrbiterJ = RotL64((aOrbiterJ * 15116367961682119467U), 41U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2355285311890287611U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 1287783821903407734U;
            aOrbiterA = RotL64((aOrbiterA * 8054011680932255985U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 9282654686791135654U) + aNonceWordF;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15488608017745542551U;
            aOrbiterB = RotL64((aOrbiterB * 7858866274035085123U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13296835576073421802U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 7127700236018338741U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11246173563106014149U), 11U);
            //
            aIngress = RotL64(aOrbiterA, 40U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterE, 43U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 57U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + ((RotL64(aIngress, 39U) + aOrbiterI) + RotL64(aOrbiterE, 60U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterA, 3U));
            aWandererG = aWandererG + ((RotL64(aScatter, 34U) + RotL64(aOrbiterI, 51U)) + aOrbiterF);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterB, 47U)) + aNonceWordN);
            aWandererB = aWandererB + ((((RotL64(aCross, 53U) + aOrbiterD) + RotL64(aOrbiterA, 56U)) + RotL64(aCarry, 5U)) + aNonceWordG);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 23U));
            aWandererA = aWandererA + (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterG, 29U)) + aPhaseFWandererUpdateSaltE[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 60U) + aOrbiterD) + RotL64(aOrbiterF, 43U));
            aWandererJ = aWandererJ + ((((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 37U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererG, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 13U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneD
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19946U)) & S_BLOCK1], 19U) ^ RotL64(aSnowLaneC[((aIndex + 18787U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 20741U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 21675U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((aIndex + 19875U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 41U) + RotL64(aIngress, 29U)) + (RotL64(aCross, 10U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererF + RotL64(aScatter, 12U)) + RotL64(aCarry, 47U)) + 6342299552323486695U;
            aOrbiterI = ((aWandererA + RotL64(aIngress, 57U)) + 12692748514781367538U) + aNonceWordL;
            aOrbiterE = (aWandererK + RotL64(aCross, 47U)) + 8202639945493229155U;
            aOrbiterC = ((aWandererD + RotL64(aPrevious, 5U)) + 4439975701793231639U) + aPhaseFOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 43U)) + 16774235182859553759U) + aNonceWordK;
            aOrbiterA = (((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 8764155413335405667U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 51U)) + 7167848811974967685U;
            aOrbiterK = ((aWandererE + RotL64(aIngress, 20U)) + RotL64(aCarry, 27U)) + 16768278912125334220U;
            aOrbiterB = (aWandererI + RotL64(aCross, 39U)) + 9090838954826296201U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7644075729758006298U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17326182797908071215U;
            aOrbiterE = RotL64((aOrbiterE * 2408330168749256075U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 16158809721888137555U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8029938783858263694U) ^ aNonceWordA;
            aOrbiterH = RotL64((aOrbiterH * 12628072435324195483U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 8716553521415553404U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 7012599977009208840U;
            aOrbiterF = RotL64((aOrbiterF * 8775355876188948851U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 13250558696578541499U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 13705957059101025396U;
            aOrbiterA = RotL64((aOrbiterA * 16889495686487056367U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2796775206291902461U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 13741676263512390669U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10455782033465595947U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1691908360612389252U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 4114939415206031540U;
            aOrbiterJ = RotL64((aOrbiterJ * 2797401802892718297U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2374911514440738727U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12377616933668803091U;
            aOrbiterI = RotL64((aOrbiterI * 2505164835116651215U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 681094033415259645U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 13841322124900463362U;
            aOrbiterK = RotL64((aOrbiterK * 4210414203856902329U), 21U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 18082983557580381338U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15731122225678626778U;
            aOrbiterB = RotL64((aOrbiterB * 7785999919955613789U), 47U);
            //
            aIngress = RotL64(aOrbiterJ, 30U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 19U));
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 29U) + RotL64(aOrbiterA, 51U)) + aOrbiterB) + RotL64(aCarry, 11U)) + aNonceWordP);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 23U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 60U) + RotL64(aOrbiterF, 18U)) + aOrbiterI) + aNonceWordC) + aPhaseFWandererUpdateSaltD[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterH, 35U));
            aWandererA = aWandererA + ((((RotL64(aPrevious, 19U) + aOrbiterC) + RotL64(aOrbiterI, 27U)) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterB, 3U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterI);
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterE, 39U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aScatter, 50U) + RotL64(aOrbiterB, 14U)) + aOrbiterI) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 56U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererE, 13U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aSnowLaneB
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aSnowLaneB forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26487U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneD[((aIndex + 22361U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 25796U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23456U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 27245U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aPrevious, 39U)) ^ (RotL64(aCarry, 10U) + RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (aWandererB + RotL64(aPrevious, 51U)) + 9446153639709651566U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 35U)) + 10550762260670758167U;
            aOrbiterA = (aWandererI + RotL64(aScatter, 6U)) + 7062634922142578383U;
            aOrbiterD = (aWandererF + RotL64(aCross, 19U)) + 9178499097812764515U;
            aOrbiterK = (((aWandererE + RotL64(aPrevious, 47U)) + 6887103379773525538U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 47U)) + 6239750312052010257U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 12U)) + 17645022614523287959U;
            aOrbiterG = (((aWandererH + RotL64(aScatter, 43U)) + RotL64(aCarry, 37U)) + 3639618183259408272U) + aNonceWordM;
            aOrbiterF = ((((aWandererC + RotL64(aIngress, 29U)) + RotL64(aCarry, 23U)) + 3131737117548745095U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordA;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 7253994382396406554U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 15217993711938379561U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17853313384747259923U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12594152227603630033U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 11250170200489647869U;
            aOrbiterK = RotL64((aOrbiterK * 546800378327864723U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 12936942656624279424U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10990736056052106149U;
            aOrbiterB = RotL64((aOrbiterB * 7123916809953459187U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 12787293075893090465U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17154990205620778151U;
            aOrbiterJ = RotL64((aOrbiterJ * 10031369940028159521U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1270827262969060301U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 17337623431665013136U;
            aOrbiterI = RotL64((aOrbiterI * 1517262088236356107U), 13U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 830330490987911853U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 6828309232554560547U;
            aOrbiterH = RotL64((aOrbiterH * 9742464176986145819U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 11470087853413986203U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 10470148870747884420U;
            aOrbiterF = RotL64((aOrbiterF * 6766079738799967443U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 18315536891901859637U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12264670822285914271U;
            aOrbiterG = RotL64((aOrbiterG * 5841574505408674119U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 10931842095884524879U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 11134871340959676257U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11714837622285605745U), 51U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterA, 18U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 3U));
            aIngress = aIngress + RotL64(aOrbiterH, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 14U) + aOrbiterK) + RotL64(aOrbiterD, 23U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterH, 39U)) + aNonceWordC);
            aWandererH = aWandererH ^ ((((RotL64(aScatter, 47U) + aOrbiterH) + RotL64(aOrbiterD, 35U)) + aNonceWordO) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aIngress, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 6U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 43U) + aOrbiterJ) + RotL64(aOrbiterF, 51U));
            aWandererC = aWandererC + (((RotL64(aIngress, 3U) + RotL64(aOrbiterA, 57U)) + aOrbiterG) + RotL64(aCarry, 11U));
            aWandererF = aWandererF ^ ((RotL64(aScatter, 34U) + aOrbiterB) + RotL64(aOrbiterA, 47U));
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterI, 30U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterF, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneD
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 30125U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 30288U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 30904U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30581U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29321U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 57U)) ^ (RotL64(aCarry, 19U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 43U)) + 9751314027302668907U) + aNonceWordN;
            aOrbiterD = ((aWandererF + RotL64(aScatter, 5U)) + RotL64(aCarry, 39U)) + 12175450995523107056U;
            aOrbiterE = (aWandererC + RotL64(aCross, 60U)) + 17519694958730119552U;
            aOrbiterC = (((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 57U)) + 9093525527925682263U) + aNonceWordI;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 27U)) + RotL64(aCarry, 13U)) + 3713831321786810138U;
            aOrbiterG = ((aWandererK + RotL64(aScatter, 51U)) + 10108355209191835040U) + aNonceWordD;
            aOrbiterF = ((aWandererA + RotL64(aIngress, 38U)) + 12956307447311314768U) + aPhaseFOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aCross, 23U)) + 1904298513945877359U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 19U)) + 4658049993308574460U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 9826333658248851902U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 12058666914724365134U;
            aOrbiterE = RotL64((aOrbiterE * 964233873188373939U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 2516574707110528099U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 13335308331049750235U;
            aOrbiterD = RotL64((aOrbiterD * 5880227828760598587U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 8230749255538495304U;
            aOrbiterF = (((aOrbiterF ^ aOrbiterG) ^ 16536559486797811486U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterF = RotL64((aOrbiterF * 7097036838156464969U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 12387639130570188998U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 8459259798142872020U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8001346480955847013U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16083784052002800300U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 1957284290736468379U;
            aOrbiterK = RotL64((aOrbiterK * 5046501301740813065U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7349538179311335863U;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16395170077006105258U;
            aOrbiterG = RotL64((aOrbiterG * 4230485452156662763U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 3317652065873784068U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5517155804799120700U;
            aOrbiterJ = RotL64((aOrbiterJ * 9789270651974719183U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5568525912112200094U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 9334250662962319598U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 5034887614541768961U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 5641394627075994165U) + aNonceWordA;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 13524971148931512745U;
            aOrbiterC = RotL64((aOrbiterC * 3699457147759854357U), 21U);
            //
            aIngress = RotL64(aOrbiterD, 29U) ^ aOrbiterF;
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterG, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterC, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aCross, 19U) + RotL64(aOrbiterE, 21U)) + aOrbiterF) + RotL64(aCarry, 43U)) + aNonceWordF);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 53U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + aNonceWordE);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterK, 48U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 60U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + RotL64(aOrbiterK, 13U)) + aOrbiterC);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterC, 39U)) + aOrbiterD) + aPhaseFWandererUpdateSaltC[((aIndex + 8U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aScatter, 47U) + aOrbiterJ) + RotL64(aOrbiterC, 44U)) + RotL64(aCarry, 53U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 4U) + aOrbiterD) + RotL64(aOrbiterA, 57U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 11U) + aOrbiterF) + RotL64(aOrbiterA, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 26U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 3U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Cricket_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xE55C6A2C635F12A9ULL + 0xDFAB111083296FB3ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x8E9A95881B6970F1ULL + 0xD8A2A24E40E392F9ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF70F29C29136260DULL + 0x8D063F2DE12AD332ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xA9B9B6EF6307B2F3ULL + 0xD18754A74CC6DE59ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8CB55F0D6368A881ULL + 0xA0C8A5771125CDF9ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF6AF71602F8DBE5BULL + 0xFB7683AC5D558001ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xED54C418542AC50DULL + 0xCEE89E6AD9D6B645ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xADB14501AE8012C5ULL + 0xE462A771C0150A19ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC7E725CFB09ED47DULL + 0xD4FE03FE174A52E0ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x9702F2F04C03AA31ULL + 0x855AD5BD5D24FB64ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEF2141BB4B7E7E0FULL + 0xFB15F0AB2F63803DULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC2AFE50F9B7F3D91ULL + 0x902B8206A0D5F6A1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xCACA54F432354947ULL + 0x86324B5E0DD58901ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xF37BA062E4DB6F01ULL + 0x9FBE2D2A16E31438ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xE9B301F3A623F5E9ULL + 0x932FFC02826D1189ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF808CF91E4C5A1A9ULL + 0xBF385474F1DEB6D3ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aFireLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneA, aWorkLaneA, aInvestLaneC, aInvestLaneD, aWorkLaneB, aFireLaneD, aExpandLaneA, aFireLaneC, aExpandLaneB, aInvestLaneB, aExpandLaneC, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aFireLaneA
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aFireLaneA forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 762U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 851U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 198U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 3731U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 244U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 3763U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 38U) + RotL64(aCarry, 3U)) + (RotL64(aPrevious, 51U) ^ RotL64(aCross, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterI = ((aWandererA + RotL64(aCross, 27U)) + RotL64(aCarry, 39U)) + 5173905450211892891U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 35U)) + 3555542451908039957U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 11U)) + 11559884700283861559U) + aNonceWordH;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 12U)) + RotL64(aCarry, 27U)) + 1352524329968738673U) + aNonceWordC;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 43U)) + 8914206450420616349U) + aNonceWordJ;
            aOrbiterD = (aWandererF + RotL64(aCross, 53U)) + 2251523378498463946U;
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 5U)) + 9541575923299247038U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 1239854507907214595U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 17698101462598498934U;
            aOrbiterE = RotL64((aOrbiterE * 2304948713665996433U), 29U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterK) + 12305566971683256060U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1]) + aNonceWordI;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 13804545036303215569U;
            aOrbiterF = RotL64((aOrbiterF * 10359543704152744971U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 10239749097704329264U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 4212214906286320308U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3661436621615751071U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12192418916967430783U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 4475514289326450361U) ^ aNonceWordO;
            aOrbiterG = RotL64((aOrbiterG * 17497164630368757887U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17376102613298827459U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 18129393209955439341U;
            aOrbiterK = RotL64((aOrbiterK * 6404089025014118979U), 13U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 4014763724300253568U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 17325007199676828814U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 1420888274815627083U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 15480474849292388685U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 14357924730184375449U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16723492259068034209U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 37U));
            aIngress = aIngress + (RotL64(aOrbiterI, 29U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 13U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterE, 4U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterA) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterA, 41U));
            aWandererC = aWandererC + ((((RotL64(aCross, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterA) + RotL64(aCarry, 11U)) + aNonceWordE);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 21U)) + aOrbiterD) + aNonceWordN);
            aWandererA = aWandererA + ((RotL64(aPrevious, 36U) + aOrbiterG) + RotL64(aOrbiterF, 29U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 40U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererI, 5U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aInvestLaneC
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneD
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6302U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneC[((aIndex + 6749U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 9901U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 6460U)) & S_BLOCK1], 57U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 10710U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 6707U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7714U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 27U) ^ RotL64(aCross, 57U)) + (RotL64(aCarry, 43U) + RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterA = ((aWandererI + RotL64(aCross, 29U)) + 17711946802293254150U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 56U)) + 16652362590489569378U) + aNonceWordO;
            aOrbiterF = ((aWandererK + RotL64(aIngress, 47U)) + RotL64(aCarry, 29U)) + 6972810344198183097U;
            aOrbiterG = (((aWandererC + RotL64(aScatter, 3U)) + RotL64(aCarry, 41U)) + 13117100889782940546U) + aNonceWordD;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 11U)) + RotL64(aCarry, 13U)) + 13199305696782626591U;
            aOrbiterI = (aWandererB + RotL64(aCross, 23U)) + 992156184392760945U;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 39U)) + 13791265442074543880U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17057087245252294859U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 13444195995883541046U;
            aOrbiterF = RotL64((aOrbiterF * 13067044288608808777U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 6723678233676059420U;
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 7913379431208430475U;
            aOrbiterD = RotL64((aOrbiterD * 2295062944289127123U), 19U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterD) + 4481887195529300665U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1]) + aNonceWordC;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 11892724101424384078U;
            aOrbiterI = RotL64((aOrbiterI * 3468639499716604111U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 7700902083270424194U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 1888001433557140271U;
            aOrbiterE = RotL64((aOrbiterE * 8975562955027025349U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 14996753906788986929U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 939004845422123765U) ^ aNonceWordA;
            aOrbiterG = RotL64((aOrbiterG * 2507090308972292313U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 11922230289291941807U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 15681187459741147199U;
            aOrbiterA = RotL64((aOrbiterA * 10124947739653819101U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 9119043713532718155U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8327697433992362166U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 11157657162184304567U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 57U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 28U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 51U));
            aIngress = aIngress + RotL64(aOrbiterI, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 29U) + aOrbiterI) + RotL64(aOrbiterF, 56U)) + aNonceWordN) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + RotL64(aCarry, 11U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 5U) + aOrbiterF) + RotL64(aOrbiterG, 29U));
            aWandererE = aWandererE + (((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 47U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterB);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + aOrbiterE) + RotL64(aOrbiterD, 19U));
            aWandererB = aWandererB ^ ((((RotL64(aPrevious, 19U) + aOrbiterA) + RotL64(aOrbiterF, 39U)) + aNonceWordI) + aPhaseHWandererUpdateSaltA[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 3U));
            aCarry = aCarry + (RotL64(aWandererB, 46U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 11U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 3
        // ingress from: aWorkLaneB, aSnowLaneA, aFireLaneD
        // ingress directions: aWorkLaneB forward forced, aSnowLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneA, aSnowLaneC
        // cross directions: aWorkLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 11153U)) & S_BLOCK1], 37U) ^ RotL64(aSnowLaneA[((aIndex + 11717U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 12873U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 16308U)) & S_BLOCK1], 46U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12916U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 13U) ^ RotL64(aIngress, 60U)) + (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 57U)) + RotL64(aCarry, 53U)) + 3550722402315312207U) + aPhaseHOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterE = ((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 11U)) + 16724184551669522754U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 981751330116773021U) + aNonceWordO;
            aOrbiterB = (((aWandererA + RotL64(aIngress, 26U)) + 7891159229704944868U) + aPhaseHOrbiterAssignSaltB[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = (aWandererE + RotL64(aScatter, 19U)) + 13618396711464799841U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 35U)) + 5969291018449003648U;
            aOrbiterF = (aWandererD + RotL64(aCross, 13U)) + 14595540413313640042U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 3287990436916111762U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 12534369400200483704U;
            aOrbiterD = RotL64((aOrbiterD * 2345945228434740707U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 2277312067930392274U) + aNonceWordJ;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10026320559261334353U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 11020464940995912637U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 11258082063135659551U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1445958517675746990U;
            aOrbiterI = RotL64((aOrbiterI * 10062265337488757971U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 1011298251290970844U) + aNonceWordE;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6487834862470043744U;
            aOrbiterH = RotL64((aOrbiterH * 15477913837027179675U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9966279022928268335U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 10285993486057704393U;
            aOrbiterB = RotL64((aOrbiterB * 15965714363201157535U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 16005362468813966136U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterF) ^ 223843444699390781U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 665392038954573081U), 43U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterA) + 18178876294968532775U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1]) + aNonceWordN;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12490136112181806806U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 16380841616662993709U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 5U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterB, 29U)) + aPhaseHWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 29U) + aOrbiterA) + RotL64(aOrbiterE, 3U)) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 51U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 58U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 35U)) + aOrbiterA) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + aNonceWordM) + aPhaseHWandererUpdateSaltC[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterF, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 10U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 19298U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneA[((aIndex + 20590U)) & S_BLOCK1], 58U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 21234U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20744U)) & S_BLOCK1], 56U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 18857U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 21U) + RotL64(aCross, 35U)) + (RotL64(aCarry, 47U) ^ RotL64(aIngress, 6U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterC = (((aWandererB + RotL64(aIngress, 46U)) + 4204560462077827182U) + aPhaseHOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 6572370199668594039U) + aNonceWordE;
            aOrbiterB = ((aWandererF + RotL64(aPrevious, 3U)) + RotL64(aCarry, 11U)) + 15958999876732622825U;
            aOrbiterG = ((aWandererD + RotL64(aScatter, 57U)) + 9969349486879280377U) + aNonceWordB;
            aOrbiterF = ((aWandererG + RotL64(aPrevious, 37U)) + 15450238998293956181U) + aPhaseHOrbiterAssignSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (((aWandererI + RotL64(aIngress, 29U)) + RotL64(aCarry, 37U)) + 9128619863683138259U) + aNonceWordN;
            aOrbiterH = (aWandererE + RotL64(aScatter, 19U)) + 5691270563628979565U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5901029710568933106U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 10442738941988588834U) ^ aNonceWordO;
            aOrbiterB = RotL64((aOrbiterB * 7386621444831603817U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 3508116020325721993U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 13221917083569767259U;
            aOrbiterK = RotL64((aOrbiterK * 6845108555710135357U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 11627915460377128176U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterE) ^ 17858261365514253433U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 7535577636975884641U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 4294837988806295989U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 24U)) & S_SALT1]) + aNonceWordF;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 11242915481585070249U;
            aOrbiterH = RotL64((aOrbiterH * 17540688242763829319U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 13030663829236027109U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7451948220723185149U;
            aOrbiterF = RotL64((aOrbiterF * 5191778587712222029U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 5575508866505031037U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 5161096033789876794U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16843827915802461797U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3980482740649505122U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 11188906150207270241U) ^ aNonceWordJ;
            aOrbiterE = RotL64((aOrbiterE * 408550837615188413U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 37U) ^ aOrbiterH;
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 46U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aCross, 57U) + RotL64(aOrbiterK, 28U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + aOrbiterH) + RotL64(aOrbiterK, 47U)) + aNonceWordC);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterE) + RotL64(aCarry, 5U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterE, 11U)) + aPhaseHWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 12U) + aOrbiterH) + RotL64(aOrbiterC, 35U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 21U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aNonceWordP) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aPrevious, 47U) + aOrbiterB) + RotL64(aOrbiterG, 21U)) + RotL64(aCarry, 23U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 30U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_h loop 5
        // ingress from: aExpandLaneB, aWorkLaneB, aInvestLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneB forward forced, aInvestLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23260U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneB[((aIndex + 26373U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 22375U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 26589U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((aIndex + 22403U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCross, 40U)) ^ (RotL64(aPrevious, 13U) ^ RotL64(aCarry, 27U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterG = ((aWandererC + RotL64(aPrevious, 28U)) + 12809562813316740345U) + aNonceWordM;
            aOrbiterI = ((aWandererK + RotL64(aCross, 13U)) + 17084212535326321199U) + aPhaseHOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aIngress, 53U)) + RotL64(aCarry, 23U)) + 16074921689983846769U;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 14027986153007120145U) + aNonceWordI;
            aOrbiterD = ((aWandererF + RotL64(aIngress, 43U)) + 7633455951809250227U) + aPhaseHOrbiterAssignSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 35U)) + 340989348513370174U;
            aOrbiterA = ((aWandererD + RotL64(aScatter, 21U)) + 5307820377645020116U) + aNonceWordC;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 5605285015771527274U) + aPhaseHOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 5293500434746182790U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17674669610895537063U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 7263156475892261811U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 10672879570907433005U;
            aOrbiterG = RotL64((aOrbiterG * 2506338667179450741U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 16659226780900986107U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 9774892622769850665U;
            aOrbiterF = RotL64((aOrbiterF * 7487477727543183211U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10728057184108279042U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 5032485856947407217U;
            aOrbiterI = RotL64((aOrbiterI * 16651577903809154285U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14642241075374862345U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8386481273395203518U;
            aOrbiterD = RotL64((aOrbiterD * 11649977733867003445U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2874153265304098104U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11519900149177261000U;
            aOrbiterH = RotL64((aOrbiterH * 2010158758971864505U), 27U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 8885690878540115768U) + aNonceWordK;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 4482143389870987714U;
            aOrbiterA = RotL64((aOrbiterA * 7105332459437434281U), 21U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterH, 37U);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterG, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 43U) + aOrbiterI) + RotL64(aOrbiterA, 13U));
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + aOrbiterH) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 47U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterH) + RotL64(aOrbiterG, 50U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterI) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterH, 29U)) + aOrbiterD) + aNonceWordO) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 57U) + RotL64(aOrbiterG, 57U)) + aOrbiterF) + aNonceWordB);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 6U) + aOrbiterG) + RotL64(aOrbiterB, 3U)) + aNonceWordF);
            //
            aCarry = aCarry + (RotL64(aWandererB, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererK, 23U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 41U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28277U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 29525U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 27446U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29311U)) & S_BLOCK1], 13U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31794U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 39U) + RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterJ = (((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 4622023259121087483U) + aNonceWordF;
            aOrbiterB = ((aWandererJ + RotL64(aPrevious, 29U)) + RotL64(aCarry, 39U)) + 10253505250223501352U;
            aOrbiterF = (((aWandererF + RotL64(aIngress, 60U)) + 17133877904420462669U) + aPhaseHOrbiterAssignSaltF[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterI = (aWandererI + RotL64(aScatter, 41U)) + 6162827793741796700U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 19U)) + RotL64(aCarry, 19U)) + 9610986424765907615U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 11U)) + 11210747154264753754U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 3U)) + 16554205219580654546U) + aPhaseHOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 10352576357413766388U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 3651845783283479752U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1011289824180799641U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 18145542190463500476U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 5415609566767162857U;
            aOrbiterA = RotL64((aOrbiterA * 6474184559323816389U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 2033734872464201570U) + aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 3507213117125813345U) ^ aNonceWordG;
            aOrbiterB = RotL64((aOrbiterB * 5453058336688881113U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 8716253393049851856U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 695984869565941856U;
            aOrbiterK = RotL64((aOrbiterK * 8377921610764044735U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7661578828878284931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 906654265099155956U;
            aOrbiterI = RotL64((aOrbiterI * 8117625377607536949U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 6050049984731254612U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 17882717590338190821U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10807367411402733215U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 4996521991532815957U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4246460672800604436U;
            aOrbiterJ = RotL64((aOrbiterJ * 12047466401960824903U), 51U);
            //
            aIngress = RotL64(aOrbiterI, 50U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 3U)) + aOrbiterE);
            aWandererE = aWandererE + ((RotL64(aIngress, 29U) + aOrbiterB) + RotL64(aOrbiterJ, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 53U) + aOrbiterA) + RotL64(aOrbiterK, 53U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterF) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 41U) + aOrbiterE) + RotL64(aOrbiterI, 38U));
            aWandererC = aWandererC + (((((RotL64(aScatter, 20U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + RotL64(aCarry, 43U)) + aNonceWordM) + aPhaseHWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 11U)) + aOrbiterB) + aNonceWordO) + aPhaseHWandererUpdateSaltC[((aIndex + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 36U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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

void TwistExpander_Cricket_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseBWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseBSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltF;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 540U)) & W_KEY1], 23U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 1868U)) & W_KEY1], 34U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 2730U)) & W_KEY1], 60U) ^ RotL64(mSource[((aIndex + 1340U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 22U)) ^ (RotL64(aIngress, 5U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = ((aWandererJ + RotL64(aCross, 44U)) + 12632404972795375757U) + aPhaseAOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aWandererF + RotL64(aScatter, 5U)) + 5351879979055988456U;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 35U)) + 3597737727467443413U;
            aOrbiterF = (aWandererI + RotL64(aIngress, 11U)) + 2830846754917852318U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 51U)) + 17311925960294518018U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 53U)) + 2083584640523695383U;
            aOrbiterA = (((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 27U)) + 15049343611387010158U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = (aWandererB + RotL64(aIngress, 39U)) + 6443050378205811147U;
            aOrbiterD = (aWandererK + RotL64(aCross, 48U)) + 6021965178697344070U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 5080289878758029976U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 576927745306972983U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16008958833683246115U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 4728489691382690859U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 6184355840165758855U;
            aOrbiterC = RotL64((aOrbiterC * 1515043910404156423U), 53U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 11220539885798595450U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 11091438724966718214U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8225347114759391961U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 17184210490020062419U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 2150997767099116408U;
            aOrbiterG = RotL64((aOrbiterG * 8058553821648892499U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 7021953562676903717U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17159676348343312834U;
            aOrbiterE = RotL64((aOrbiterE * 13877284519668483549U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10367891770525239784U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11922478487264201233U;
            aOrbiterK = RotL64((aOrbiterK * 9195137452661956029U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 17815162358981720634U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 9582631251085100284U;
            aOrbiterD = RotL64((aOrbiterD * 11838992994130850483U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 872593750259572264U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 17832330100262167302U;
            aOrbiterJ = RotL64((aOrbiterJ * 1114416841510028467U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 16601139856969287418U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 14931287111691324985U;
            aOrbiterF = RotL64((aOrbiterF * 16757174577841001179U), 3U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + (RotL64(aOrbiterK, 11U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 52U) + RotL64(aOrbiterD, 18U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 51U)) + aOrbiterA) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterA, 57U)) + aOrbiterE);
            aWandererB = aWandererB + ((((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterD, 39U)) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 12U) + aOrbiterF) + RotL64(aOrbiterC, 47U)) + aPhaseAWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + aOrbiterJ) + RotL64(aOrbiterK, 14U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 43U));
            aWandererH = aWandererH + ((RotL64(aCross, 57U) + RotL64(aOrbiterA, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + RotL64(aWandererB, 47U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 4227U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 4786U)) & W_KEY1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2838U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 4083U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 53U)) ^ (RotL64(aCarry, 6U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = (aWandererH + RotL64(aPrevious, 20U)) + 3236820517816085022U;
            aOrbiterK = (aWandererB + RotL64(aScatter, 47U)) + 741288875914097926U;
            aOrbiterI = ((aWandererJ + RotL64(aCross, 53U)) + 8417246926007729580U) + aPhaseAOrbiterAssignSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aIngress, 39U)) + 9715717805774537170U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aScatter, 29U)) + 14360243844821619482U;
            aOrbiterE = ((aWandererG + RotL64(aPrevious, 57U)) + RotL64(aCarry, 5U)) + 10760908100206775334U;
            aOrbiterB = (aWandererK + RotL64(aIngress, 35U)) + 3434641779946167811U;
            aOrbiterD = ((aWandererD + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 7885568822756234567U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 6U)) + RotL64(aCarry, 51U)) + 3041563437672051294U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 15761355327564963516U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 1158633562785937421U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 15511324886867188235U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9338581575871970653U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 9172038894262857354U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3110871165285625807U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14653924713599790081U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 3854497592598563309U;
            aOrbiterB = RotL64((aOrbiterB * 11737111068815795303U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16286980180327600557U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 5092583772591249756U;
            aOrbiterJ = RotL64((aOrbiterJ * 13955105624639442903U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 4288397994175567333U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15584236478994873104U;
            aOrbiterG = RotL64((aOrbiterG * 1860480595862755379U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 5557463939827483792U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 2659814275753280856U;
            aOrbiterE = RotL64((aOrbiterE * 17702430405693184643U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6941807963525063449U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2040598555191211307U;
            aOrbiterC = RotL64((aOrbiterC * 14750544987531722765U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 347572666231116258U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 779304821185302523U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14180254150318109855U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10632524582873079742U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9761308771280517212U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 13926235411726048921U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 24U) ^ aOrbiterD;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 43U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 13U));
            aIngress = aIngress + RotL64(aOrbiterB, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterC, 51U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterD, 3U));
            aWandererA = aWandererA + ((RotL64(aCross, 35U) + aOrbiterJ) + RotL64(aOrbiterG, 47U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterK, 34U));
            aWandererK = aWandererK + ((((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 13U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterE, 57U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 57U) + aOrbiterF) + RotL64(aOrbiterG, 27U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterC, 20U)) + aOrbiterG);
            aWandererI = aWandererI + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterB, 43U)) + aOrbiterC) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererH, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 57U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 7535U)) & S_BLOCK1], 6U) ^ RotL64(aKeyRowReadB[((aIndex + 6693U)) & W_KEY1], 39U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6117U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5590U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 5506U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aIngress, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aPrevious, 51U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererF + RotL64(aScatter, 47U)) + 1888427424966603593U) + aPhaseAOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 23U)) + 5436761445660415091U;
            aOrbiterH = ((aWandererK + RotL64(aCross, 11U)) + RotL64(aCarry, 35U)) + 17322876217962143270U;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 60U)) + 9728299982740564979U;
            aOrbiterA = ((aWandererC + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 301720335271716921U;
            aOrbiterF = (aWandererA + RotL64(aCross, 29U)) + 8069685428854814396U;
            aOrbiterD = ((aWandererG + RotL64(aIngress, 3U)) + RotL64(aCarry, 47U)) + 1973715500949100991U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 56U)) + 87666408799854155U) + aPhaseAOrbiterAssignSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = (aWandererH + RotL64(aIngress, 39U)) + 12195436904339035245U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4578742069143400295U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 7828776048774876484U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 4047964518501081039U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 17203146364542781833U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16913369550858890466U;
            aOrbiterF = RotL64((aOrbiterF * 13534417587921978507U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 9632761514552265402U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 9106637671877341286U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 9073709119482640391U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 15423680889126750876U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6087310684583331882U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8964465129744898619U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5420955876411796789U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 14166807419730848032U;
            aOrbiterC = RotL64((aOrbiterC * 442659738632823751U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8118312450347026824U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 4253043584558403086U;
            aOrbiterA = RotL64((aOrbiterA * 5651748455190536467U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 8810774678371762700U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12218479555589447835U;
            aOrbiterI = RotL64((aOrbiterI * 11026364205248516355U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 11389930523582876358U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 16334420553471379915U;
            aOrbiterG = RotL64((aOrbiterG * 13830132212033904777U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 18201289372553710279U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 7196540389657785361U;
            aOrbiterJ = RotL64((aOrbiterJ * 13058135202554889791U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 30U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 35U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 57U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 29U) + aOrbiterD) + RotL64(aOrbiterG, 35U)) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 6U)) + aOrbiterH) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterA, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aCross, 3U) + RotL64(aOrbiterD, 43U)) + aOrbiterK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererG = aWandererG + ((RotL64(aPrevious, 35U) + aOrbiterI) + RotL64(aOrbiterD, 58U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 24U) + aOrbiterA) + RotL64(aOrbiterJ, 39U));
            aWandererF = aWandererF + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aPhaseAWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererF, 19U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererJ, 37U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererC, 27U);
            aCarry = aCarry + RotL64(aIngress, 12U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9521U)) & S_BLOCK1], 19U) ^ RotL64(aKeyRowReadB[((aIndex + 8240U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(mSource[((aIndex + 8846U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 8195U)) & S_BLOCK1], 3U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8968U)) & W_KEY1], 23U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 9512U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 39U) ^ RotL64(aCarry, 23U)) ^ (RotL64(aCross, 5U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 5U)) + 14008824488073394623U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 51U)) + RotL64(aCarry, 57U)) + 13317978415866411468U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 60U)) + RotL64(aCarry, 27U)) + 13209180141897453900U;
            aOrbiterK = (aWandererF + RotL64(aPrevious, 43U)) + 11870521586865233578U;
            aOrbiterF = (aWandererH + RotL64(aScatter, 21U)) + 8052156380448047385U;
            aOrbiterE = (aWandererK + RotL64(aIngress, 39U)) + 12158131176743680605U;
            aOrbiterH = ((aWandererD + RotL64(aCross, 11U)) + RotL64(aCarry, 37U)) + 14674467487607719347U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 34U)) + 18055496790566231147U;
            aOrbiterA = ((aWandererG + RotL64(aScatter, 47U)) + 3838105585041578784U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2839568255183054418U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 11933612922864258179U;
            aOrbiterD = RotL64((aOrbiterD * 7571964469321160347U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 6289849094151630580U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 2640344350528492271U;
            aOrbiterE = RotL64((aOrbiterE * 16197726750829369365U), 43U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 16306175266267657791U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 3339898380394883600U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7105436590182982373U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15017076663742800002U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8973064296077602496U;
            aOrbiterG = RotL64((aOrbiterG * 9309462227233615761U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 17580319233338139859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 14063208878807603874U;
            aOrbiterA = RotL64((aOrbiterA * 16601475239075164585U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 13326130855721009942U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12843186026737544416U;
            aOrbiterK = RotL64((aOrbiterK * 4975848122837321619U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 14102887715772847499U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 14495942314329085733U;
            aOrbiterF = RotL64((aOrbiterF * 4236795312917583565U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 11564857125101669667U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 17435970784822000464U;
            aOrbiterJ = RotL64((aOrbiterJ * 1472691848852381173U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 16561390130356833062U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 9952805588514363872U;
            aOrbiterC = RotL64((aOrbiterC * 3720874990001086597U), 47U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterJ, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 22U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterC, 41U));
            aIngress = aIngress + RotL64(aOrbiterK, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aScatter, 35U) + aOrbiterF) + RotL64(aOrbiterA, 29U)) + aPhaseBWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 41U) + RotL64(aOrbiterK, 24U)) + aOrbiterF) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 18U) + aOrbiterA) + RotL64(aOrbiterC, 41U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 35U)) + aOrbiterC);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 3U)) + aOrbiterJ);
            aWandererE = aWandererE + (((RotL64(aPrevious, 11U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 24U) + aOrbiterH) + RotL64(aOrbiterE, 47U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterE, 57U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 57U) + RotL64(aOrbiterC, 10U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererI, 22U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 37U));
            aCarry = aCarry + RotL64(aWandererD, 27U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 12975U)) & S_BLOCK1], 56U) ^ RotL64(aKeyRowReadA[((aIndex + 11890U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 11371U)) & W_KEY1], 3U) ^ RotL64(mSource[((aIndex + 12355U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneB[((aIndex + 13032U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13585U)) & S_BLOCK1], 4U) ^ RotL64(aInvestLaneA[((aIndex + 11512U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 34U)) ^ (RotL64(aCarry, 47U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererI + RotL64(aCross, 5U)) + 8866844335448071821U;
            aOrbiterB = ((aWandererA + RotL64(aIngress, 29U)) + RotL64(aCarry, 21U)) + 15159698739856430085U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 13U)) + RotL64(aCarry, 47U)) + 9582805772989594633U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = (aWandererJ + RotL64(aPrevious, 23U)) + 1438538239931588373U;
            aOrbiterI = (aWandererE + RotL64(aIngress, 18U)) + 10862044156620436139U;
            aOrbiterF = (aWandererB + RotL64(aCross, 57U)) + 13682173320058164615U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 51U)) + 8351013291045977592U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 39U)) + 15777857431516633916U;
            aOrbiterG = (((aWandererG + RotL64(aCross, 44U)) + RotL64(aCarry, 35U)) + 16178966745333885377U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 3U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 9031889187993001617U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 6308472367425865347U;
            aOrbiterH = RotL64((aOrbiterH * 17118710301967158153U), 5U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 642109145903321046U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 9186268569255318035U;
            aOrbiterF = RotL64((aOrbiterF * 10714674348507516749U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 6091345356803675860U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 13218507921880873749U;
            aOrbiterA = RotL64((aOrbiterA * 15415157927185637717U), 35U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 4266652275234474616U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4391422098164506195U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 17634679403195085867U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 5160682323243635577U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10351728852161347404U;
            aOrbiterB = RotL64((aOrbiterB * 11105410036471745951U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 3950932176454814023U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 9536466386833427441U;
            aOrbiterG = RotL64((aOrbiterG * 18064984243491293435U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 9927425919978776529U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 6819384090527481081U;
            aOrbiterD = RotL64((aOrbiterD * 18032965969184368561U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 1646274931424218507U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 16166524473976135097U;
            aOrbiterC = RotL64((aOrbiterC * 11672192658072663849U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 11252501968059485262U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 16847854447987609067U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 6326299154627028295U), 51U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 53U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 44U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterI, 53U)) + aOrbiterC);
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterE, 39U)) + aOrbiterB) + RotL64(aCarry, 53U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 34U) + aOrbiterD) + RotL64(aOrbiterG, 5U)) + aPhaseBWandererUpdateSaltE[((aIndex + 12U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aScatter, 57U) + aOrbiterI) + RotL64(aOrbiterH, 14U)) + RotL64(aCarry, 21U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 21U) + aOrbiterE) + RotL64(aOrbiterG, 19U));
            aWandererD = aWandererD + ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 47U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterF, 23U)) + aOrbiterB);
            aWandererG = aWandererG + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 29U)) + aOrbiterC);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 50U) + RotL64(aOrbiterE, 60U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 27U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15142U)) & S_BLOCK1], 48U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14419U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14486U)) & W_KEY1], 27U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 15936U)) & W_KEY1], 43U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15459U)) & S_BLOCK1], 35U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 15127U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15044U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 35U) ^ RotL64(aCarry, 52U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererF + RotL64(aScatter, 3U)) + 5295352595333316211U;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 13U)) + 2341795367042042605U;
            aOrbiterI = ((aWandererB + RotL64(aIngress, 24U)) + RotL64(aCarry, 13U)) + 10122175780504033663U;
            aOrbiterA = ((aWandererI + RotL64(aCross, 19U)) + 10084612804696198554U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 37U)) + 16470424309851045971U;
            aOrbiterG = ((aWandererK + RotL64(aPrevious, 47U)) + RotL64(aCarry, 21U)) + 656016130975227994U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 58U)) + 15313268829659834317U) + aPhaseBOrbiterAssignSaltA[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterD = ((aWandererD + RotL64(aScatter, 51U)) + RotL64(aCarry, 39U)) + 3795220914993923394U;
            aOrbiterC = (aWandererE + RotL64(aCross, 43U)) + 14044442220988813825U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 3804224626734584802U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7980006306010255693U;
            aOrbiterI = RotL64((aOrbiterI * 13958505239726088561U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13746830564584711549U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 11852212099729274845U;
            aOrbiterJ = RotL64((aOrbiterJ * 2164880979318247855U), 23U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 9083223471018084847U) + aPhaseBOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 13706723820703853346U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 11361854103656219887U), 5U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 1713819986642275223U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 1382000168233902914U;
            aOrbiterG = RotL64((aOrbiterG * 3894160765130198157U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 4540474625764565485U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 1756168174375757220U;
            aOrbiterD = RotL64((aOrbiterD * 12739160208010092017U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1409297070183609309U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 6082750101445444357U;
            aOrbiterB = RotL64((aOrbiterB * 17438740230251860935U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1113239890859479202U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10932192439503964363U;
            aOrbiterC = RotL64((aOrbiterC * 5915660289913324281U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 3732595033748508428U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterH) ^ 5117760372351117286U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 2671510075176315761U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 7399968659654088641U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14835608167871904147U;
            aOrbiterK = RotL64((aOrbiterK * 8312521710415756159U), 11U);
            //
            aIngress = RotL64(aOrbiterI, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 57U));
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 34U));
            aIngress = aIngress + RotL64(aOrbiterD, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 6U) + RotL64(aOrbiterB, 48U)) + aOrbiterK);
            aWandererE = aWandererE + ((((RotL64(aIngress, 53U) + RotL64(aOrbiterG, 57U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aPhaseBWandererUpdateSaltD[((aIndex + 20U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 57U) + aOrbiterB) + RotL64(aOrbiterH, 41U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 53U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterK, 23U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aPrevious, 28U) + aOrbiterA) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 23U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 47U) + aOrbiterB) + RotL64(aOrbiterJ, 29U)) + aPhaseBWandererUpdateSaltA[((aIndex + 22U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aCross, 43U) + aOrbiterB) + RotL64(aOrbiterI, 36U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterC, 19U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererB, 10U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererC, 43U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 35U));
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17188U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 16442U)) & W_KEY1], 35U));
            aIngress ^= (RotL64(mSource[((aIndex + 17055U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18543U)) & S_BLOCK1], 44U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 16476U)) & W_KEY1], 35U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17304U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 18880U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 3U) + RotL64(aIngress, 23U)) + (RotL64(aCarry, 40U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = (aWandererJ + RotL64(aPrevious, 13U)) + 17912271996338180948U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 51U)) + 13259276608841847058U;
            aOrbiterD = ((aWandererF + RotL64(aCross, 43U)) + RotL64(aCarry, 29U)) + 16225936008657276089U;
            aOrbiterB = (aWandererI + RotL64(aIngress, 24U)) + 2243058962151834071U;
            aOrbiterI = (aWandererE + RotL64(aScatter, 5U)) + 10637439274127347861U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 43U)) + 15312219216405992627U;
            aOrbiterG = ((aWandererD + RotL64(aPrevious, 29U)) + RotL64(aCarry, 5U)) + 2393933972129878613U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 39U)) + 4327069337247976513U) + aPhaseCOrbiterAssignSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aScatter, 60U)) + 8307656353434167837U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 17299145556933889336U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 14458100581172798164U;
            aOrbiterD = RotL64((aOrbiterD * 16543734663677070509U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6410095654927998067U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 6168964796264687686U;
            aOrbiterA = RotL64((aOrbiterA * 16218071040190475953U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 3667999465041020730U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 16021552859323602007U;
            aOrbiterG = RotL64((aOrbiterG * 6427266472526362663U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 12941668202330045095U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4222032891850449934U;
            aOrbiterK = RotL64((aOrbiterK * 17292856787431308097U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 1346342592002730785U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16860611785008118820U;
            aOrbiterH = RotL64((aOrbiterH * 384963420804756607U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 3193572711804730241U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 5866881282680588589U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 9226331800853634597U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 17180332731328479126U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10222097519535882241U;
            aOrbiterB = RotL64((aOrbiterB * 9422887302872778795U), 19U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 8863502179821584859U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 14872318155712512999U;
            aOrbiterE = RotL64((aOrbiterE * 11830641277356873233U), 3U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16478790641892781150U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 8414944141232294781U;
            aOrbiterC = RotL64((aOrbiterC * 17443775794621154023U), 23U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (RotL64(aOrbiterH, 53U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterK, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterB, 34U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterB, 43U));
            aWandererF = aWandererF + (((RotL64(aCross, 23U) + RotL64(aOrbiterH, 51U)) + aOrbiterA) + aPhaseCWandererUpdateSaltC[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 50U) + aOrbiterI) + RotL64(aOrbiterC, 47U)) + aPhaseCWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterE, 58U)) + RotL64(aCarry, 41U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterG, 27U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 5U) + RotL64(aOrbiterE, 11U)) + aOrbiterI) + RotL64(aCarry, 27U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 37U) + aOrbiterG) + RotL64(aOrbiterB, 3U));
            aWandererC = aWandererC + ((RotL64(aCross, 44U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererE, 4U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 23U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 19U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19142U)) & S_BLOCK1], 50U) ^ RotL64(mSource[((aIndex + 21525U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 19703U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 20022U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19272U)) & W_KEY1], 29U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20072U)) & W_KEY1], 10U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19676U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21746U)) & S_BLOCK1], 47U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 52U) + RotL64(aCross, 23U)) ^ (RotL64(aCarry, 35U) + RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererC + RotL64(aCross, 12U)) + 2168513956284366370U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererB + RotL64(aIngress, 41U)) + 10290361969974613111U) + aPhaseCOrbiterAssignSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aScatter, 51U)) + RotL64(aCarry, 27U)) + 15673836275828498050U;
            aOrbiterA = ((aWandererG + RotL64(aPrevious, 3U)) + RotL64(aCarry, 43U)) + 16600540024145812236U;
            aOrbiterK = (aWandererK + RotL64(aIngress, 29U)) + 9428052101528111892U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 23U)) + 12763657928312763377U;
            aOrbiterB = (aWandererE + RotL64(aScatter, 37U)) + 10751286982008662485U;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 47U)) + 1708230173038057979U;
            aOrbiterC = ((aWandererF + RotL64(aCross, 56U)) + RotL64(aCarry, 11U)) + 4011389705422783816U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 11704428328093077714U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 2055336619674699284U) ^ aPhaseCOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6374289210096410907U), 57U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1870865272102705804U) + aPhaseCOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 3574214263751923179U;
            aOrbiterI = RotL64((aOrbiterI * 13132083406834413563U), 39U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 984611970726966186U) + aPhaseCOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 15207945449947643672U;
            aOrbiterB = RotL64((aOrbiterB * 9539470161576639981U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 4181398506373973169U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15222345431506025949U;
            aOrbiterA = RotL64((aOrbiterA * 6925143692628659467U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15023513452326240962U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14965669361708810699U;
            aOrbiterF = RotL64((aOrbiterF * 587008860996713147U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7985755518735406360U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 225592097619240187U;
            aOrbiterK = RotL64((aOrbiterK * 2313509354133400439U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3659537916566939383U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 17043668033610689611U;
            aOrbiterC = RotL64((aOrbiterC * 10797634709118100773U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 10217321522161675848U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8013663869536146842U;
            aOrbiterH = RotL64((aOrbiterH * 2293233079384777175U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 13762445330867496042U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2692400019659269106U;
            aOrbiterD = RotL64((aOrbiterD * 167704184292219399U), 21U);
            //
            aIngress = RotL64(aOrbiterI, 3U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterC, 24U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + RotL64(aOrbiterH, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterK, 41U));
            aWandererE = aWandererE + ((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 23U)) + aOrbiterK);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 42U) + aOrbiterA) + RotL64(aOrbiterD, 27U)) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 51U) + aOrbiterK) + RotL64(aOrbiterD, 46U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 3U)) + aOrbiterC);
            aWandererF = aWandererF + ((((RotL64(aIngress, 23U) + aOrbiterA) + RotL64(aOrbiterI, 11U)) + RotL64(aCarry, 51U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + aOrbiterA) + RotL64(aOrbiterK, 37U));
            aWandererI = aWandererI + (((RotL64(aCross, 58U) + RotL64(aOrbiterF, 53U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 58U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 41U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 57U));
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererK);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 51U));
            aCarry = aCarry + RotL64(aWandererF, 37U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23492U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadA[((aIndex + 23563U)) & W_KEY1], 39U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22739U)) & W_KEY1], 47U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23165U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 22597U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24112U)) & S_BLOCK1], 60U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 22520U)) & S_BLOCK1], 27U) ^ RotL64(aInvestLaneB[((aIndex + 22852U)) & S_BLOCK1], 5U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 38U) ^ RotL64(aIngress, 21U)) + (RotL64(aPrevious, 51U) + RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = (aWandererD + RotL64(aScatter, 47U)) + 3684295017013759987U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 5U)) + 6740408842457292881U;
            aOrbiterK = (((aWandererI + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 4563975890702399441U) + aPhaseCOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aCross, 12U)) + 797804144825287940U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 2763779540450101303U;
            aOrbiterA = ((aWandererJ + RotL64(aIngress, 37U)) + 13211846164102089685U) + aPhaseCOrbiterAssignSaltC[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 13U)) + 15214578447281401982U;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 58U)) + 13745208628754232427U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 19U)) + 17358621225969190747U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 779739369960480023U) + aPhaseCOrbiterUpdateSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 4370963533701407813U;
            aOrbiterK = RotL64((aOrbiterK * 3123135216876641039U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6061333005507739975U) + aPhaseCOrbiterUpdateSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3589705340762734456U;
            aOrbiterA = RotL64((aOrbiterA * 16499293983611196967U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10607697666369230567U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 9356757995305239271U;
            aOrbiterH = RotL64((aOrbiterH * 10945513661439954731U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 10093033335903048138U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 11037328061699834100U;
            aOrbiterG = RotL64((aOrbiterG * 11189760551792389605U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 558431161176115540U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 17795680919453449358U) ^ aPhaseCOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 3910117359996283803U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6096779391116214109U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 17594243286880690775U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12655610181937429915U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 15414704802398002423U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 18040588240488602196U;
            aOrbiterE = RotL64((aOrbiterE * 16344249573086571225U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 14636298592697156931U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 9677305688594936561U;
            aOrbiterI = RotL64((aOrbiterI * 8354776999961642997U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 16408025751875050713U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 10018342878801454965U;
            aOrbiterF = RotL64((aOrbiterF * 10349132962708124117U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterI, 38U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 51U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterJ, 47U));
            aIngress = aIngress + RotL64(aOrbiterD, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aScatter, 10U) + aOrbiterG) + RotL64(aOrbiterJ, 27U));
            aWandererC = aWandererC + (((RotL64(aIngress, 43U) + RotL64(aOrbiterF, 37U)) + aOrbiterJ) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterH, 57U)) + aPhaseCWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterA, 44U)) + aPhaseCWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterJ, 23U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 60U) + RotL64(aOrbiterA, 51U)) + aOrbiterD);
            aWandererD = aWandererD + (((RotL64(aCross, 39U) + aOrbiterG) + RotL64(aOrbiterE, 19U)) + RotL64(aCarry, 21U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterE, 6U)) + aOrbiterD);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 19U));
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererJ, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25306U)) & S_BLOCK1], 42U) ^ RotL64(aKeyRowReadA[((aIndex + 24757U)) & W_KEY1], 57U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 26526U)) & S_BLOCK1], 11U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26798U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24956U)) & W_KEY1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 26660U)) & S_BLOCK1], 52U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 27120U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneB[((aIndex + 26518U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 11U) ^ RotL64(aCarry, 60U)) + (RotL64(aIngress, 39U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 11410829607777684449U;
            aOrbiterE = (aWandererH + RotL64(aScatter, 23U)) + 7502698839700975347U;
            aOrbiterK = (aWandererA + RotL64(aCross, 39U)) + 13267685058252106173U;
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 58U)) + RotL64(aCarry, 51U)) + 238242706996630625U;
            aOrbiterD = ((aWandererK + RotL64(aPrevious, 43U)) + 8184695499511454281U) + aPhaseDOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 47U)) + 12767823220461985403U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 35U)) + 12293198423143850330U;
            aOrbiterC = ((aWandererC + RotL64(aCross, 18U)) + RotL64(aCarry, 5U)) + 11149495229952495939U;
            aOrbiterA = (aWandererG + RotL64(aScatter, 29U)) + 7556992689338382800U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 3431338808774134649U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 16863099140844995099U;
            aOrbiterK = RotL64((aOrbiterK * 752376661101787919U), 39U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 17872458049880677604U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 16760153457252546974U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11225037229069712805U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 3115544493537438408U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 4359882942759752958U;
            aOrbiterF = RotL64((aOrbiterF * 561477566995575801U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 13387113067202396536U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 12955690074544490161U;
            aOrbiterH = RotL64((aOrbiterH * 12449941770827974511U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 15614054443728226807U) + aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1939441328066616114U;
            aOrbiterI = RotL64((aOrbiterI * 4484917074808974359U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 4599016263007782537U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9962305629016158048U;
            aOrbiterD = RotL64((aOrbiterD * 1496184427500037279U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 8428467674122750557U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 3938884087806393439U;
            aOrbiterA = RotL64((aOrbiterA * 12810531094050481761U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 6018636830758044658U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 1510372000641305416U;
            aOrbiterC = RotL64((aOrbiterC * 9002834928626918247U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 17592782466215337843U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 8119921507606870360U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1299795061644535485U), 11U);
            //
            aIngress = RotL64(aOrbiterG, 58U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterD, 35U));
            aIngress = aIngress + RotL64(aOrbiterC, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 39U) + aOrbiterA) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 51U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 10U) + aOrbiterC) + RotL64(aOrbiterD, 6U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 53U) + RotL64(aOrbiterK, 57U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 43U) + aOrbiterF) + RotL64(aOrbiterD, 51U)) + aPhaseDWandererUpdateSaltD[((aIndex + 21U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterE, 11U));
            aWandererA = aWandererA + ((RotL64(aCross, 22U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterG, 22U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 35U) + RotL64(aOrbiterF, 43U)) + aOrbiterC) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 43U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 53U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 27641U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((aIndex + 28604U)) & S_BLOCK1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29350U)) & W_KEY1], 5U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 29443U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29706U)) & W_KEY1], 11U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27550U)) & S_BLOCK1], 56U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28977U)) & S_BLOCK1], 3U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28914U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCarry, 13U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererG + RotL64(aIngress, 46U)) + RotL64(aCarry, 43U)) + 4751694786009671052U;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 57U)) + 16362725160370844224U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererA + RotL64(aScatter, 53U)) + 6360885380915941057U) + aPhaseDOrbiterAssignSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = (aWandererD + RotL64(aCross, 19U)) + 5154536007972297036U;
            aOrbiterD = (aWandererE + RotL64(aIngress, 39U)) + 9362540581874808253U;
            aOrbiterG = (aWandererB + RotL64(aPrevious, 24U)) + 13902493871525612934U;
            aOrbiterH = (aWandererC + RotL64(aCross, 3U)) + 10208452885367546542U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 3117030377279160998U;
            aOrbiterI = ((aWandererK + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 17286247690414027870U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 3930314320040949141U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 7289525252391668404U) ^ aPhaseDOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15452162299105112187U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3434167955466809185U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 17852573095128575663U;
            aOrbiterD = RotL64((aOrbiterD * 1485660158767033425U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6137259687928853253U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 13992510605237574698U;
            aOrbiterH = RotL64((aOrbiterH * 15346263295995333395U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6470556523400123474U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 4333255670390099293U;
            aOrbiterB = RotL64((aOrbiterB * 11089933812030082647U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7700424876430257995U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 16920736951239453071U;
            aOrbiterG = RotL64((aOrbiterG * 8920407493132380497U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 1635071690430295730U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 9966700845966398620U;
            aOrbiterF = RotL64((aOrbiterF * 17210048121896546867U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9833458070123027075U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterD) ^ 1990346556486746432U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 8704943923474148699U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 13339523466436517327U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 5018264760406215603U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2769197961801783627U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 123427497520755346U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 4535841104215792886U;
            aOrbiterI = RotL64((aOrbiterI * 1417676310539177131U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterG, 53U);
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterB, 10U));
            aIngress = aIngress + RotL64(aOrbiterH, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterD, 47U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterD, 41U)) + aOrbiterH) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 36U) + RotL64(aOrbiterF, 57U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterA, 28U)) + aOrbiterI);
            aWandererG = aWandererG ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterA);
            aWandererK = aWandererK + ((RotL64(aIngress, 47U) + RotL64(aOrbiterA, 3U)) + aOrbiterG);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterG, 11U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterF, 51U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterE, 18U)) + aOrbiterB) + aPhaseDWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererA, 29U));
            aCarry = aCarry + (RotL64(aWandererE, 47U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 24U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 3U));
            aCarry = aCarry + RotL64(aWandererC, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 32470U)) & S_BLOCK1], 53U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 30179U)) & W_KEY1], 40U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31675U)) & S_BLOCK1], 37U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31310U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30966U)) & S_BLOCK1], 21U) ^ RotL64(aKeyRowReadB[((aIndex + 32623U)) & W_KEY1], 46U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 27U) + RotL64(aCarry, 60U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 13U)) + RotL64(aCarry, 19U)) + 8685374557928800912U;
            aOrbiterD = (aWandererJ + RotL64(aCross, 48U)) + 3482312691892161229U;
            aOrbiterK = (aWandererF + RotL64(aScatter, 23U)) + 6948130297389161165U;
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 3U)) + RotL64(aCarry, 51U)) + 5506385663788942690U) + aPhaseDOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aWandererI + RotL64(aIngress, 39U)) + 17859982009307397161U;
            aOrbiterA = (aWandererE + RotL64(aCross, 60U)) + 9178488809207094043U;
            aOrbiterJ = ((aWandererG + RotL64(aPrevious, 35U)) + 1835479501226057169U) + aPhaseDOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aScatter, 53U)) + RotL64(aCarry, 11U)) + 5368101733632614939U;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 19U)) + 9050459666576835422U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 9042186993119635078U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 17528342580198295025U;
            aOrbiterK = RotL64((aOrbiterK * 14316671546614386775U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 6495418332558436882U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8834495762667327342U;
            aOrbiterA = RotL64((aOrbiterA * 10783141541937645995U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 4364314196965690905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6357485231062120459U;
            aOrbiterJ = RotL64((aOrbiterJ * 289429584586504995U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 3321488322626415347U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 10817330671781848737U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 15875919466358823335U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17974092279281611763U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 2871472057292789157U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 16104199340711015181U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 15187929795092006849U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13482063681546475923U;
            aOrbiterH = RotL64((aOrbiterH * 14466266308157364963U), 39U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 6232152545071397380U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 17488906002621373262U;
            aOrbiterE = RotL64((aOrbiterE * 4719340606442742577U), 35U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 12444819880507588549U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 13808941689757772497U;
            aOrbiterI = RotL64((aOrbiterI * 6541360905282412317U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 8049361354387692374U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 7137831335606542401U;
            aOrbiterG = RotL64((aOrbiterG * 11022231291507235007U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 52U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 39U));
            aIngress = aIngress + (RotL64(aOrbiterI, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterE, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            aWandererE = aWandererE + ((RotL64(aCross, 60U) + aOrbiterK) + RotL64(aOrbiterJ, 43U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 58U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 29U) + aOrbiterH) + RotL64(aOrbiterA, 47U)) + aPhaseDWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterH, 53U)) + aPhaseDWandererUpdateSaltE[((aIndex + 20U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aScatter, 51U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 12U) + aOrbiterD) + RotL64(aOrbiterI, 4U));
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterK, 39U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 41U) + aOrbiterI) + RotL64(aOrbiterB, 19U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 26U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 23U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Cricket_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneC, aInvestLaneD, aFireLaneA, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 117U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 1330U)) & S_BLOCK1], 34U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 4936U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 51U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneD[((aIndex + 4063U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 6U)) + (RotL64(aCross, 37U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 41U)) + RotL64(aCarry, 43U)) + 10881271196314989997U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 50U)) + RotL64(aCarry, 11U)) + 6406461249988567558U;
            aOrbiterK = ((aWandererK + RotL64(aIngress, 29U)) + 17255067918280095959U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aScatter, 5U)) + 16690850682497718411U;
            aOrbiterI = (aWandererG + RotL64(aCross, 57U)) + 5576201059361086866U;
            aOrbiterH = ((aWandererC + RotL64(aScatter, 11U)) + 11991259685693687554U) + aPhaseEOrbiterAssignSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 57U)) + 14652535244217836909U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 1701789037170782122U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 953429054903473833U;
            aOrbiterK = RotL64((aOrbiterK * 13482379459700651427U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 12064513610469714211U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 7993881398822002424U;
            aOrbiterI = RotL64((aOrbiterI * 11572884842788918377U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14421313768013320050U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 11112386845630998889U;
            aOrbiterE = RotL64((aOrbiterE * 11771526352030371669U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 17069630896535699015U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 3308240081138623373U;
            aOrbiterD = RotL64((aOrbiterD * 10449509484417835159U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 17615529807112933619U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11782807146851563541U;
            aOrbiterH = RotL64((aOrbiterH * 12992075832343669221U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 14401645829607611983U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 6736397344219993532U;
            aOrbiterJ = RotL64((aOrbiterJ * 1667287547938175641U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 6446974060524700550U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 7840991992443308254U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6891023544882740107U), 51U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterE, 13U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterI, 41U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 47U)) + aOrbiterK);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 28U) + aOrbiterD) + RotL64(aOrbiterF, 3U));
            aWandererD = aWandererD + ((((RotL64(aCross, 3U) + aOrbiterH) + RotL64(aOrbiterD, 11U)) + RotL64(aCarry, 57U)) + aPhaseEWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 56U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 29U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterJ, 21U)) + aOrbiterF);
            //
            aCarry = aCarry + (RotL64(aWandererD, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererJ, 18U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 53U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5947U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 8730U)) & S_BLOCK1], 26U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 7741U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 9428U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneD[((aIndex + 8932U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 35U)) + (RotL64(aPrevious, 21U) ^ RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = (aWandererK + RotL64(aScatter, 53U)) + 6342299552323486695U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 12692748514781367538U;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 37U)) + RotL64(aCarry, 21U)) + 8202639945493229155U;
            aOrbiterC = (aWandererA + RotL64(aIngress, 60U)) + 4439975701793231639U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 43U)) + 16774235182859553759U) + aPhaseEOrbiterAssignSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterE = (((aWandererE + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 8764155413335405667U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aWandererI + RotL64(aCross, 11U)) + 7167848811974967685U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 16768278912125334220U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 9090838954826296201U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5459329624017272077U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 7644075729758006298U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 17326182797908071215U;
            aOrbiterJ = RotL64((aOrbiterJ * 2408330168749256075U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 16158809721888137555U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 8029938783858263694U;
            aOrbiterB = RotL64((aOrbiterB * 12628072435324195483U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 8716553521415553404U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 7012599977009208840U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8775355876188948851U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 13250558696578541499U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 13705957059101025396U;
            aOrbiterE = RotL64((aOrbiterE * 16889495686487056367U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 2796775206291902461U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13741676263512390669U;
            aOrbiterG = RotL64((aOrbiterG * 10455782033465595947U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 1691908360612389252U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 4114939415206031540U;
            aOrbiterD = RotL64((aOrbiterD * 2797401802892718297U), 11U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterE, 53U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterB, 29U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterG, 47U));
            aWandererK = aWandererK + ((((RotL64(aCross, 5U) + RotL64(aOrbiterJ, 20U)) + aOrbiterB) + RotL64(aCarry, 27U)) + aPhaseEWandererUpdateSaltE[((aIndex + 27U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 30U) + aOrbiterE) + RotL64(aOrbiterC, 39U)) + aPhaseEWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterB, 53U)) + RotL64(aCarry, 11U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterB);
            aWandererE = aWandererE + ((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterJ, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterG, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 35U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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
            aIngress = (RotL64(aInvestLaneD[((aIndex + 14637U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 11152U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15334U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 11220U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 11185U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aExpandLaneA[((aIndex + 13818U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 54U) + RotL64(aCross, 35U)) ^ (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 60U)) + RotL64(aCarry, 57U)) + 6361545377408870615U;
            aOrbiterF = (aWandererB + RotL64(aPrevious, 21U)) + 2967245486744774933U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 3836634268482850139U;
            aOrbiterI = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 7691642115360086297U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterE = (aWandererG + RotL64(aCross, 35U)) + 16479280384178279281U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 5U)) + 2901468732552539249U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = (aWandererA + RotL64(aIngress, 47U)) + 2600353867755647475U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5666596904781510956U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 16108791609267427553U;
            aOrbiterC = RotL64((aOrbiterC * 8904649663479834199U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterE) + 8389926875737312112U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 1689501721163024426U;
            aOrbiterB = RotL64((aOrbiterB * 6517194895779049139U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 11721701506949917719U;
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 3963842745030140473U;
            aOrbiterE = RotL64((aOrbiterE * 6692473494944919373U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 8510538243472109368U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterD) ^ 18281865214102080387U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1351546966368884609U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 2259725140963665123U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterC) ^ 11652011949557979650U;
            aOrbiterJ = RotL64((aOrbiterJ * 11260100762113295037U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 1116085424226174473U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterF) ^ 4725260319270802912U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 4697109059565450269U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 7348945429843437036U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 1249234309180653260U;
            aOrbiterF = RotL64((aOrbiterF * 3136745255820405881U), 37U);
            //
            aIngress = RotL64(aOrbiterD, 41U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 12U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aCross, 6U) + RotL64(aOrbiterD, 29U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + aOrbiterI) + RotL64(aOrbiterE, 51U)) + RotL64(aCarry, 35U));
            aWandererA = aWandererA ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterI, 43U)) + aOrbiterJ);
            aWandererG = aWandererG + ((((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 51U)) + aPhaseEWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + RotL64(aOrbiterF, 57U)) + aOrbiterD);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterC, 12U)) + aOrbiterD);
            //
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererF, 57U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererC, 22U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneB
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 18728U)) & S_BLOCK1], 5U) ^ RotL64(aInvestLaneC[((aIndex + 19483U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21363U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16805U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 19016U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 18203U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCross, 60U) + RotL64(aPrevious, 13U)) + (RotL64(aIngress, 47U) ^ RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = ((aWandererD + RotL64(aIngress, 4U)) + RotL64(aCarry, 13U)) + 6381335981879993247U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 47U)) + 15595429101600023172U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 57U)) + 5449234297249826461U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterG = (aWandererH + RotL64(aCross, 13U)) + 11213734849329731168U;
            aOrbiterK = ((aWandererJ + RotL64(aPrevious, 35U)) + RotL64(aCarry, 35U)) + 16438473952464514248U;
            aOrbiterB = (aWandererI + RotL64(aScatter, 53U)) + 7357872882115186976U;
            aOrbiterC = (aWandererA + RotL64(aCross, 29U)) + 394402075160738643U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 11112941985410283532U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 14955125011182736212U;
            aOrbiterJ = RotL64((aOrbiterJ * 10711684773326395603U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 14770727009821304070U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 11286366598129204910U;
            aOrbiterH = RotL64((aOrbiterH * 15884310771003021989U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 7358400908565425780U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 15635109923749114761U;
            aOrbiterB = RotL64((aOrbiterB * 12415152149408700329U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13826842523738623579U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 1072811298828325231U;
            aOrbiterC = RotL64((aOrbiterC * 9662800288646215083U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 4017334196009350776U) + aPhaseEOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8812213572751410831U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12744171921566782795U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6723457786170634403U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9785583533999417673U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7776915427605471097U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 10265132640322153964U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 8435670887514808087U;
            aOrbiterK = RotL64((aOrbiterK * 2706263045620662131U), 13U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterH, 41U);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterC, 30U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterG) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterK, 43U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 29U) + RotL64(aOrbiterK, 57U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterC, 36U)) + aOrbiterI);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + RotL64(aOrbiterH, 51U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 27U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 13U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 30U) ^ aWandererG);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 57U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24920U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 26994U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 24398U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 22458U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25472U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 22181U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCarry, 5U)) ^ (RotL64(aIngress, 35U) ^ RotL64(aCross, 56U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aCross, 21U)) + RotL64(aCarry, 57U)) + 10805654776556844351U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 37U)) + 582794182442795335U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 51U)) + RotL64(aCarry, 37U)) + 2858343650974681068U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = (aWandererA + RotL64(aScatter, 11U)) + 8189584049022064284U;
            aOrbiterI = (aWandererE + RotL64(aPrevious, 3U)) + 1565100751996962893U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 60U)) + 8062028016947611891U) + aPhaseEOrbiterAssignSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 21U)) + 8280504280578451745U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 11326869194491655350U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 1671695656567777163U;
            aOrbiterG = RotL64((aOrbiterG * 7511554500524257921U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2349843105293943452U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 13015545152052004254U;
            aOrbiterI = RotL64((aOrbiterI * 1316662811685429983U), 41U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 16703354404749291869U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 8713231044374305801U;
            aOrbiterD = RotL64((aOrbiterD * 9242480982197688625U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11118401674497783533U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 14857556493734710364U;
            aOrbiterB = RotL64((aOrbiterB * 3452566050389715195U), 11U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 12953419670951660965U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12666121730825089017U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14049925256934142519U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11075249639473053423U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 9374217688244187867U;
            aOrbiterH = RotL64((aOrbiterH * 5261156325627117877U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 17608340953291367867U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 13159437499327086340U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4882100944453534805U), 3U);
            //
            aIngress = RotL64(aOrbiterH, 18U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterI, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aCross, 51U) + RotL64(aOrbiterH, 51U)) + aOrbiterC) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 57U) + aOrbiterC) + RotL64(aOrbiterI, 58U));
            aWandererE = aWandererE + (((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 23U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 37U) + RotL64(aOrbiterH, 41U)) + aOrbiterI);
            aWandererI = aWandererI + (((RotL64(aIngress, 13U) + aOrbiterD) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 37U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 5U)) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 30U) + RotL64(aOrbiterJ, 29U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 37U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererG, 28U));
            aCarry = aCarry + (RotL64(aWandererI, 13U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28441U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 28247U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 32698U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 29123U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28059U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 31084U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 37U) ^ RotL64(aCarry, 24U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererC + RotL64(aCross, 47U)) + 18144572925667544139U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 60U)) + 5659758077574059728U;
            aOrbiterC = (((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 6343330616999166392U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 53U)) + 17754639838410839447U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 53U)) + 9451843819849581729U;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 5U)) + 7957854457197462212U) + aPhaseEOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 11U)) + 1461994799722205010U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 18002214276252170177U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14689869073147027164U;
            aOrbiterC = RotL64((aOrbiterC * 12242482963989582191U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3978104368003440293U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8512135845221335386U;
            aOrbiterF = RotL64((aOrbiterF * 10506667163729414667U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 1477533446382953439U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2166717790929947990U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6538884492418324461U), 43U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 8082437060686606995U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 4363687722464700362U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 7199165810993478887U), 37U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 15782763348014924206U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8572509150015960728U;
            aOrbiterD = RotL64((aOrbiterD * 3340528604891897779U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 12248271773316742521U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 9602078627638561949U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1860631869877427405U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 17244849374768558859U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 1030743048280579012U;
            aOrbiterI = RotL64((aOrbiterI * 10858949914285817051U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 3U);
            aIngress = aIngress + (RotL64(aOrbiterF, 30U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterI, 39U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 20U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 23U) + aOrbiterF) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 51U)) + aOrbiterF);
            aWandererG = aWandererG + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterC, 3U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 53U) + aOrbiterF) + RotL64(aOrbiterK, 29U));
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 57U)) + aOrbiterC) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 60U) + RotL64(aOrbiterI, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 50U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererA, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Cricket_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneA, aOperationLaneC, aOperationLaneD, aInvestLaneC, aSnowLaneA, aExpandLaneD, aInvestLaneA, aSnowLaneB, aExpandLaneB, aWorkLaneA, aInvestLaneB, aWorkLaneB, aInvestLaneD, aWorkLaneC, aExpandLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneA
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneC backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 691U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 5091U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 4416U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5400U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1855U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 997U)) & S_BLOCK1], 4U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCarry, 21U) + RotL64(aIngress, 39U)) + (RotL64(aCross, 52U) ^ RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererJ + RotL64(aScatter, 58U)) + 8793908991006073956U;
            aOrbiterA = (aWandererI + RotL64(aCross, 3U)) + 2932916283348441943U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 41U)) + 11069042087940968262U;
            aOrbiterD = ((aWandererH + RotL64(aPrevious, 23U)) + 14369628676782894441U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererA + RotL64(aIngress, 41U)) + 8602903272780978282U;
            aOrbiterC = (aWandererK + RotL64(aScatter, 35U)) + 3827036107178568820U;
            aOrbiterG = ((aWandererE + RotL64(aCross, 37U)) + 8905245209036772489U) + aPhaseFOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aWandererG + RotL64(aPrevious, 51U)) + 13331387530760017893U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 9880107580289737823U;
            aOrbiterH = (aWandererD + RotL64(aIngress, 60U)) + 10199619040626900278U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 21U)) + RotL64(aCarry, 23U)) + 2466307560891374281U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 13973403407981259448U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 2851460278409385243U;
            aOrbiterF = RotL64((aOrbiterF * 11226902976321781743U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 10365453393815690776U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2382382358987358791U;
            aOrbiterC = RotL64((aOrbiterC * 481563628980705781U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5058198848163792422U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 10500434740387593487U;
            aOrbiterI = RotL64((aOrbiterI * 5946747708776079787U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11289798395177667084U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 14327152153231286666U;
            aOrbiterG = RotL64((aOrbiterG * 18155778059595245561U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 8065137263811956313U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 3865153574847924816U;
            aOrbiterA = RotL64((aOrbiterA * 9495741102667755161U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 18102279969722473375U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 6306428427188742325U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17826782872351406167U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 16953348204663693724U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 11950791817032898613U;
            aOrbiterB = RotL64((aOrbiterB * 1498946055469611133U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 11980823193543752994U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17845490308799454871U;
            aOrbiterK = RotL64((aOrbiterK * 16385153013485463791U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5566398755702887071U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 10308378271388889968U;
            aOrbiterE = RotL64((aOrbiterE * 142732084484961281U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6717846700455219260U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 8297225372883997017U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14102812043481327907U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 12249337046267666603U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterC) ^ 8793908991006073956U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5851229209188473467U), 11U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterG, 47U);
            aIngress = aIngress + (RotL64(aOrbiterE, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterB, 23U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 12U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterJ, 39U));
            aIngress = aIngress + RotL64(aOrbiterC, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aScatter, 27U) + aOrbiterK) + RotL64(aOrbiterD, 41U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 3U) + aOrbiterH) + RotL64(aOrbiterA, 53U));
            aWandererH = aWandererH + ((RotL64(aCross, 60U) + aOrbiterF) + RotL64(aOrbiterJ, 21U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterC, 23U));
            aWandererG = aWandererG + (((RotL64(aIngress, 35U) + RotL64(aOrbiterG, 43U)) + aOrbiterI) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 19U) + aOrbiterG) + RotL64(aOrbiterA, 29U));
            aWandererB = aWandererB + ((RotL64(aScatter, 43U) + aOrbiterC) + RotL64(aOrbiterB, 56U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 48U) + aOrbiterI) + RotL64(aOrbiterK, 51U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 13U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + aPhaseFWandererUpdateSaltD[((aIndex + 14U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterJ, 35U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 11U) + aOrbiterE) + RotL64(aOrbiterA, 48U)) + RotL64(aCarry, 53U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 42U));
            aCarry = aCarry + (RotL64(aWandererD, 57U) ^ aWandererA);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererH, 53U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererI, 46U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererC, 35U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneD
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10348U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneC[((aIndex + 10867U)) & S_BLOCK1], 57U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 5614U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 10162U)) & S_BLOCK1], 38U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10882U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7030U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 8030U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 56U) + RotL64(aCarry, 37U)) ^ (RotL64(aCross, 5U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aScatter, 5U)) + 16424657151168221875U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 56U)) + RotL64(aCarry, 37U)) + 17150123681886380361U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 13U)) + RotL64(aCarry, 29U)) + 16041993588694572757U;
            aOrbiterA = ((aWandererK + RotL64(aPrevious, 23U)) + 9871185846434828537U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = (aWandererJ + RotL64(aScatter, 27U)) + 11227236398354430757U;
            aOrbiterD = ((aWandererE + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 5399325217402192631U;
            aOrbiterG = ((aWandererH + RotL64(aIngress, 11U)) + 9248828789282890454U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 41U)) + 9041370494203701062U;
            aOrbiterF = (aWandererG + RotL64(aScatter, 47U)) + 14944424084524970764U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 39U)) + 5481938174456671041U;
            aOrbiterC = (aWandererF + RotL64(aIngress, 37U)) + 14783648629543752715U;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 12355573914530445723U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 9863991559011968318U;
            aOrbiterH = RotL64((aOrbiterH * 8495251211794343179U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 16149688605937250965U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 106041828692026825U;
            aOrbiterD = RotL64((aOrbiterD * 12199934305374582599U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 8076098639554567792U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 11155119311895580013U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1495180896564818647U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 6847612160595917702U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 16094377920388017367U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4875801863643206333U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 13584719866672696684U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 13446209321646234607U;
            aOrbiterJ = RotL64((aOrbiterJ * 9945349065094781529U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 15829806645369560988U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 12573767256739062550U;
            aOrbiterB = RotL64((aOrbiterB * 5649504278826069077U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 3850030870300393809U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11857593987748189858U;
            aOrbiterI = RotL64((aOrbiterI * 15942863910931814193U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 5505918410521728373U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 12949653497121247860U;
            aOrbiterK = RotL64((aOrbiterK * 90944913639560027U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 2448323375614082955U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4386059032042654583U;
            aOrbiterA = RotL64((aOrbiterA * 11730132905525317201U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 108129028178045299U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 18292666533864994149U;
            aOrbiterE = RotL64((aOrbiterE * 2599590507178673531U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10771402979550786312U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16424657151168221875U;
            aOrbiterC = RotL64((aOrbiterC * 6255743082177474607U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 43U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterD, 23U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 6U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + RotL64(aOrbiterA, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aPrevious, 37U) + aOrbiterE) + RotL64(aOrbiterD, 41U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 13U) + aOrbiterH) + RotL64(aOrbiterI, 30U));
            aWandererG = aWandererG + ((RotL64(aIngress, 19U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterF, 53U)) + aOrbiterC);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 51U) + aOrbiterD) + RotL64(aOrbiterB, 39U)) + aPhaseFWandererUpdateSaltF[((aIndex + 20U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 42U) + RotL64(aOrbiterI, 37U)) + aOrbiterB);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterG, 44U));
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 35U)) + aOrbiterG) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + RotL64(aOrbiterH, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltE[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 54U) + RotL64(aOrbiterA, 13U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 51U));
            aCarry = aCarry + (RotL64(aWandererA, 46U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererD, 5U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 39U));
            aCarry = aCarry + RotL64(aWandererK, 12U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aExpandLaneB
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aExpandLaneB forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 12280U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((aIndex + 13298U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 13339U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16327U)) & S_BLOCK1], 51U) ^ RotL64(aOperationLaneC[((aIndex + 11442U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 48U) + RotL64(aIngress, 35U)) ^ (RotL64(aCross, 21U) + RotL64(aPrevious, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 57U)) + 2168513956284366370U;
            aOrbiterG = (aWandererD + RotL64(aPrevious, 41U)) + 10290361969974613111U;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 53U)) + 15673836275828498050U;
            aOrbiterI = (aWandererG + RotL64(aIngress, 26U)) + 16600540024145812236U;
            aOrbiterH = ((aWandererC + RotL64(aPrevious, 39U)) + 9428052101528111892U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 37U)) + 12763657928312763377U) + aPhaseFOrbiterAssignSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterF = (aWandererI + RotL64(aScatter, 43U)) + 10751286982008662485U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 3U)) + 1708230173038057979U;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 23U)) + 4011389705422783816U;
            aOrbiterA = (aWandererA + RotL64(aCross, 60U)) + 11704428328093077714U;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 21U)) + 2055336619674699284U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 1870865272102705804U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 3574214263751923179U;
            aOrbiterE = RotL64((aOrbiterE * 13132083406834413563U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 984611970726966186U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15207945449947643672U;
            aOrbiterH = RotL64((aOrbiterH * 9539470161576639981U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 4181398506373973169U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15222345431506025949U;
            aOrbiterF = RotL64((aOrbiterF * 6925143692628659467U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15023513452326240962U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 14965669361708810699U) ^ aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 587008860996713147U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 7985755518735406360U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 225592097619240187U;
            aOrbiterB = RotL64((aOrbiterB * 2313509354133400439U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 3659537916566939383U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 17043668033610689611U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10797634709118100773U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 10217321522161675848U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 8013663869536146842U;
            aOrbiterD = RotL64((aOrbiterD * 2293233079384777175U), 37U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 13762445330867496042U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 2692400019659269106U;
            aOrbiterJ = RotL64((aOrbiterJ * 167704184292219399U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 18232551682424867647U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 14785847596876239854U;
            aOrbiterG = RotL64((aOrbiterG * 4569180925037758487U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5910282247522389536U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 16556038638738871204U;
            aOrbiterI = RotL64((aOrbiterI * 18356922295088260901U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 141620663839815754U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2168513956284366370U;
            aOrbiterC = RotL64((aOrbiterC * 8605382725635471683U), 47U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 23U);
            aIngress = aIngress + (RotL64(aOrbiterF, 56U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterG, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 27U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterH, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 6U) + RotL64(aOrbiterC, 23U)) + aOrbiterF);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + aOrbiterC) + RotL64(aOrbiterI, 35U));
            aWandererG = aWandererG + (((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 51U)) + aOrbiterF) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterD, 28U));
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererD = aWandererD + (((RotL64(aCross, 37U) + RotL64(aOrbiterC, 37U)) + aOrbiterB) + RotL64(aCarry, 23U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 60U) + aOrbiterH) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH + (((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 21U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterA, 26U)) + aOrbiterK);
            aWandererC = aWandererC + ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterG, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 13U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17756U)) & S_BLOCK1], 22U) ^ RotL64(aSnowLaneA[((aIndex + 17781U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 19437U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 19190U)) & S_BLOCK1], 47U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 18707U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 21U) ^ RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 38U) + RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (((aWandererC + RotL64(aPrevious, 13U)) + RotL64(aCarry, 19U)) + 12849591986267890852U) + aPhaseFOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aCross, 41U)) + 8232614804696815750U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 27U)) + RotL64(aCarry, 11U)) + 12141567259210877281U;
            aOrbiterD = (aWandererG + RotL64(aScatter, 51U)) + 2928641981037885644U;
            aOrbiterI = (aWandererH + RotL64(aCross, 37U)) + 980733350554783938U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 34U)) + 2683985177993350746U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aWandererJ + RotL64(aIngress, 11U)) + 14532148403815527355U;
            aOrbiterH = ((aWandererF + RotL64(aScatter, 53U)) + RotL64(aCarry, 29U)) + 7736296629433884203U;
            aOrbiterE = (aWandererI + RotL64(aCross, 19U)) + 10428437770166310549U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 22U)) + 18327174144859461029U;
            aOrbiterK = (aWandererD + RotL64(aPrevious, 5U)) + 6810436935194432002U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 12606153309690753435U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 17123256945895150555U;
            aOrbiterB = RotL64((aOrbiterB * 13469111258504672565U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9057777759026189541U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 16478485918911194442U;
            aOrbiterA = RotL64((aOrbiterA * 11054247078884894131U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 18064460487552100483U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 11477276762421684083U;
            aOrbiterG = RotL64((aOrbiterG * 3886501230380184395U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 18318375441973295081U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 13849305985380030986U;
            aOrbiterC = RotL64((aOrbiterC * 12962140243967824959U), 21U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10240409420338313641U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 18360586077779529086U) ^ aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 18196875422391501927U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 16801797158622424257U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 4950305991208513887U;
            aOrbiterI = RotL64((aOrbiterI * 4437082499761416951U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 15790878572843321918U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 9808781805065559728U;
            aOrbiterD = RotL64((aOrbiterD * 9394280083159162953U), 51U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 11974996650410830731U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4955004489435232515U;
            aOrbiterK = RotL64((aOrbiterK * 13301966529515483085U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 1187569634223338864U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 5351017164244226367U;
            aOrbiterH = RotL64((aOrbiterH * 14735674576470803699U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 9587142385246940125U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 16253850371962732943U;
            aOrbiterJ = RotL64((aOrbiterJ * 3408021872390904463U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 14990060157351237661U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 12849591986267890852U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2158106726261981983U), 39U);
            //
            aIngress = RotL64(aOrbiterG, 47U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 24U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 13U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterK, 53U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((RotL64(aCross, 54U) + RotL64(aOrbiterC, 50U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 39U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 41U) + aOrbiterG) + RotL64(aOrbiterI, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 37U) + aOrbiterA) + RotL64(aOrbiterJ, 57U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 35U)) + aOrbiterB) + RotL64(aCarry, 41U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 21U)) + aOrbiterK);
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterD, 47U)) + aOrbiterG) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterA, 29U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aIngress, 43U) + aOrbiterJ) + RotL64(aOrbiterG, 54U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 30U) + aOrbiterH) + RotL64(aOrbiterI, 23U));
            aWandererE = aWandererE + ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 27U)) + aOrbiterE);
            //
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 35U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 22U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 23219U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 22265U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 22656U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25099U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 24233U)) & S_BLOCK1], 60U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 24U) ^ RotL64(aCross, 39U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCarry, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererB + RotL64(aScatter, 19U)) + 3917730204724097072U;
            aOrbiterC = (aWandererK + RotL64(aPrevious, 21U)) + 1874642340716212824U;
            aOrbiterG = (aWandererJ + RotL64(aIngress, 27U)) + 6900165757434854160U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 14U)) + RotL64(aCarry, 23U)) + 12750946097023807161U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 3U)) + 6563216048479513594U) + aPhaseFOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aIngress, 37U)) + 14960240191349450795U) + aPhaseFOrbiterAssignSaltF[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aCross, 11U)) + 16306180275951788289U;
            aOrbiterE = ((aWandererC + RotL64(aScatter, 39U)) + RotL64(aCarry, 53U)) + 6502066618271045547U;
            aOrbiterH = (aWandererH + RotL64(aIngress, 34U)) + 6219852857850888738U;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 2272931312452845850U;
            aOrbiterB = (aWandererG + RotL64(aScatter, 57U)) + 3028929882263199463U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 6067393030073568112U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10094809900437037258U;
            aOrbiterG = RotL64((aOrbiterG * 18095564940730322769U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 5962414178157074575U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15755563045799129417U;
            aOrbiterK = RotL64((aOrbiterK * 3692603590609922031U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6321455513889880590U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 1197435601998121700U;
            aOrbiterI = RotL64((aOrbiterI * 17693996266260557625U), 21U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 12496949381666299968U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterK) ^ 6357070235648527030U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2931486644220862433U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 8423760160877540210U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8090246492554850768U;
            aOrbiterA = RotL64((aOrbiterA * 2949407491181921633U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11436635942985063755U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 17086363141014359856U;
            aOrbiterH = RotL64((aOrbiterH * 10504127577318206801U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 10734017887545474935U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 375515325165740779U;
            aOrbiterE = RotL64((aOrbiterE * 9980486695448151709U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 5217148491945389821U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 14696058217023530058U;
            aOrbiterD = RotL64((aOrbiterD * 11026674782236654799U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11869055287836412650U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 16951500118659983436U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4304372681583055077U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 7866300390953569803U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18017335943787362993U;
            aOrbiterJ = RotL64((aOrbiterJ * 15683049583437004889U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 2477944286851267725U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 3917730204724097072U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 10U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6617615984203047419U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 47U);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 44U));
            aIngress = aIngress + RotL64(aOrbiterE, 23U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 6U) + aOrbiterB) + RotL64(aOrbiterJ, 57U));
            aWandererB = aWandererB ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterH, 3U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterH, 13U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterI) + RotL64(aOrbiterH, 26U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aCross, 18U) + aOrbiterD) + RotL64(aOrbiterI, 29U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 5U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aIngress, 23U) + RotL64(aOrbiterJ, 51U)) + aOrbiterK) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aPhaseFWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 11U) + RotL64(aOrbiterE, 21U)) + aOrbiterB) + RotL64(aCarry, 19U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterE, 24U));
            aWandererH = aWandererH + ((RotL64(aScatter, 27U) + RotL64(aOrbiterB, 39U)) + aOrbiterA);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 28U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererE, 43U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 34U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererD, 57U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 31035U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 27843U)) & S_BLOCK1], 24U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 30506U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31701U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneB[((aIndex + 30980U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCross, 5U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterH = ((aWandererF + RotL64(aCross, 41U)) + RotL64(aCarry, 5U)) + 6654158889644956636U;
            aOrbiterK = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 13U)) + 9045779659363991870U;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 52U)) + 3888897662136993491U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 11U)) + 6882016842864459345U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 15601891715956172291U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 35U)) + 5176811598629335350U) + aPhaseFOrbiterAssignSaltC[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = (aWandererJ + RotL64(aIngress, 13U)) + 12519945150889074325U;
            aOrbiterC = (aWandererB + RotL64(aCross, 21U)) + 4552583214397603278U;
            aOrbiterG = ((aWandererH + RotL64(aPrevious, 43U)) + 14225482701804864688U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = (aWandererK + RotL64(aIngress, 18U)) + 5485298070606280363U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 39U)) + 11237713257388094289U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 14340345895626142788U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 16275167270553643347U;
            aOrbiterE = RotL64((aOrbiterE * 7308578867128951199U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 14041860597556520250U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 1436068974197066343U;
            aOrbiterI = RotL64((aOrbiterI * 3938460345031496843U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 11483155566419547004U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 4608508534724289325U;
            aOrbiterD = RotL64((aOrbiterD * 13461385011638899485U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 2389196334288832895U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 4062682330273866602U;
            aOrbiterB = RotL64((aOrbiterB * 8787682133271101901U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 5655656046585592034U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7977947821249746880U;
            aOrbiterK = RotL64((aOrbiterK * 10082104644185964787U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 11653718118543974168U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 5456429682072377614U;
            aOrbiterF = RotL64((aOrbiterF * 12504180638665296649U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12457179652004203574U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterE) ^ 445821754230182952U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16043092621697786393U), 19U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 12429505513284703263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12480745784412363537U;
            aOrbiterH = RotL64((aOrbiterH * 643617210585287593U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6952219750393303609U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13965647644550998416U;
            aOrbiterJ = RotL64((aOrbiterJ * 5395755018020115073U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 5602193483992512507U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 9593414134773695959U;
            aOrbiterC = RotL64((aOrbiterC * 2186313187456153775U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 16469843418561148995U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 6654158889644956636U) ^ aPhaseFOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17490973872858383001U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterF, 57U);
            aIngress = aIngress + (RotL64(aOrbiterE, 21U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + (RotL64(aOrbiterG, 18U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + RotL64(aOrbiterB, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 24U) + aOrbiterB) + RotL64(aOrbiterE, 3U));
            aWandererF = aWandererF + ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterF, 46U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterH, 57U));
            aWandererC = aWandererC + ((RotL64(aCross, 21U) + RotL64(aOrbiterG, 23U)) + aOrbiterA);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 18U) + RotL64(aOrbiterB, 19U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aCross, 11U) + aOrbiterJ) + RotL64(aOrbiterG, 51U)) + RotL64(aCarry, 23U));
            aWandererD = aWandererD ^ ((RotL64(aScatter, 35U) + aOrbiterG) + RotL64(aOrbiterE, 5U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 51U) + RotL64(aOrbiterK, 21U)) + aOrbiterJ) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 3U) + aOrbiterI) + RotL64(aOrbiterB, 37U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD);
            aWandererG = aWandererG ^ (((RotL64(aScatter, 13U) + aOrbiterA) + RotL64(aOrbiterE, 28U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 44U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererH, 47U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Cricket_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 2487U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneB[((aIndex + 6014U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 5828U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4998U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 6076U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 1475U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 51U) ^ RotL64(aCarry, 19U)) + (RotL64(aPrevious, 39U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = ((aWandererF + RotL64(aIngress, 11U)) + 11700815697312060726U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aCross, 53U)) + RotL64(aCarry, 27U)) + 11808423452327465441U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 44U)) + 8670503858631730886U;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 19U)) + RotL64(aCarry, 41U)) + 2400061067991988544U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 27U)) + RotL64(aCarry, 53U)) + 16163118178366229686U) + aPhaseGOrbiterAssignSaltF[((aIndex + 18U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterB) + 3280178595904941068U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 3298683600817047727U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9865649058799255343U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 16321624053445183574U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 6730229877611375225U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2022290495153519279U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 10162830636713641322U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 15646771327759599256U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15333053762177144775U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14841751262270544102U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 9545541117228834895U;
            aOrbiterB = RotL64((aOrbiterB * 11529769874752969377U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 14676615635857599982U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1231768638470558855U;
            aOrbiterC = RotL64((aOrbiterC * 2716808508509014677U), 51U);
            //
            aIngress = RotL64(aOrbiterC, 29U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 19U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterJ, 5U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 3U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + RotL64(aCarry, 39U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 35U) + aOrbiterB) + RotL64(aOrbiterC, 56U));
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 47U)) + aOrbiterC) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 3U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 12551U)) & S_BLOCK1], 56U) ^ RotL64(aWorkLaneC[((aIndex + 14911U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aInvestLaneB[((aIndex + 14690U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13538U)) & S_BLOCK1], 41U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9666U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 14760U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 52U)) + (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererC + RotL64(aPrevious, 47U)) + 3650233661228036955U;
            aOrbiterG = (((aWandererE + RotL64(aScatter, 5U)) + RotL64(aCarry, 51U)) + 11607036400067735729U) + aPhaseGOrbiterAssignSaltB[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterB = (((aWandererD + RotL64(aCross, 22U)) + RotL64(aCarry, 19U)) + 3899614406903883035U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterH = ((aWandererJ + RotL64(aIngress, 57U)) + RotL64(aCarry, 35U)) + 8159156925629965143U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 35U)) + 7148903913967261270U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9161665622287517848U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 2981535013474059469U;
            aOrbiterB = RotL64((aOrbiterB * 4434815231517266013U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 15812469008200319549U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 14687469489893270300U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 14142363399696670451U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 6025209349511417063U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 12964750392311112676U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12955480283032701843U), 11U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6572355895765394340U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3542300121890027981U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11201491178181273935U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6477175684045398359U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 1081388388827929314U;
            aOrbiterC = RotL64((aOrbiterC * 8752188637514143529U), 19U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 29U));
            aIngress = aIngress + RotL64(aOrbiterH, 18U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 57U)) + aOrbiterG) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterH) + RotL64(aOrbiterB, 47U)) + RotL64(aCarry, 5U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterK, 10U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 13U) + aOrbiterH) + RotL64(aOrbiterK, 23U)) + RotL64(aCarry, 27U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 34U) + aOrbiterK) + RotL64(aOrbiterC, 39U)) + aPhaseGWandererUpdateSaltF[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 13U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 60U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 19207U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 18227U)) & S_BLOCK1], 48U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 21731U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 23493U)) & S_BLOCK1], 53U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 22857U)) & S_BLOCK1], 44U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 24442U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 19U) + RotL64(aPrevious, 54U)) ^ (RotL64(aCarry, 35U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 57U)) + 16124889768301047791U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aWandererK + RotL64(aIngress, 11U)) + 11912338587186717280U;
            aOrbiterF = ((aWandererA + RotL64(aScatter, 44U)) + RotL64(aCarry, 43U)) + 8594012868813114354U;
            aOrbiterK = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 27U)) + 18281043566156682815U;
            aOrbiterH = ((aWandererC + RotL64(aIngress, 3U)) + 16853106130200942302U) + aPhaseGOrbiterAssignSaltC[((aIndex + 15U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 2611212958619673086U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 18039472325066855180U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10213999643376367785U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 14495785571345122046U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 4556063793412832418U;
            aOrbiterI = RotL64((aOrbiterI * 13166927543135467627U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 14896419970271244358U) + aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 880028529183500036U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14228281807461251361U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 2379557167489415783U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 11854373946064529806U;
            aOrbiterH = RotL64((aOrbiterH * 150755294320438887U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 1487252775956449964U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 12777924204511625545U;
            aOrbiterD = RotL64((aOrbiterD * 1366019527386994789U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterI, 26U);
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 28U) + aOrbiterH) + RotL64(aOrbiterK, 43U));
            aWandererC = aWandererC + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 21U)) + aOrbiterH) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 5U) + aOrbiterI) + RotL64(aOrbiterF, 13U));
            aWandererK = aWandererK + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 56U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererI = aWandererI ^ (((RotL64(aCross, 51U) + RotL64(aOrbiterI, 35U)) + aOrbiterD) + aPhaseGWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 48U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 57U));
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 28052U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneA[((aIndex + 26536U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 31983U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 29053U)) & S_BLOCK1], 18U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 32750U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 30225U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 6U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterF = (aWandererB + RotL64(aCross, 53U)) + 7632760812370906911U;
            aOrbiterE = ((aWandererK + RotL64(aIngress, 19U)) + 6007174525479723089U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 35U)) + 3362829642521821048U;
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 28U)) + RotL64(aCarry, 3U)) + 18009548556107978286U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 19U)) + 17880909432272697327U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 15961567935420752568U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 10136559064656837921U;
            aOrbiterA = RotL64((aOrbiterA * 14473810261421912849U), 11U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17622019364405410277U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 6927494824421416306U;
            aOrbiterI = RotL64((aOrbiterI * 2686290883767829973U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 7125170407794874847U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12342273503071032250U;
            aOrbiterG = RotL64((aOrbiterG * 867417849555857179U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14997696377476124836U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 14874498694181230698U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4026127545746010937U), 47U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 2549397729130885686U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4217995818662767955U) ^ aPhaseGOrbiterUpdateSaltB[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5525525344485251063U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterA, 47U);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ (((RotL64(aCross, 43U) + aOrbiterI) + RotL64(aOrbiterG, 3U)) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 23U) + RotL64(aOrbiterI, 46U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aPhaseGWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterE, 11U));
            aWandererG = aWandererG + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterA, 57U)) + aOrbiterE) + RotL64(aCarry, 3U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + aOrbiterI) + RotL64(aOrbiterE, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererK, 14U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 39U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererG, 3U);
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

void TwistExpander_Cricket_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 8094U)) & S_BLOCK1], 44U) ^ RotL64(aExpandLaneB[((aIndex + 7840U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 6200U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 5926U)) & S_BLOCK1], 58U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4537U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 3123U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 51U) + RotL64(aPrevious, 19U)) ^ (RotL64(aIngress, 3U) + RotL64(aCarry, 36U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterK = ((aWandererI + RotL64(aIngress, 47U)) + RotL64(aCarry, 21U)) + 2168513956284366370U;
            aOrbiterE = (((aWandererA + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 10290361969974613111U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterC = (((aWandererH + RotL64(aCross, 39U)) + RotL64(aCarry, 5U)) + 15673836275828498050U) + aPhaseHOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterB = (aWandererD + RotL64(aScatter, 11U)) + 16600540024145812236U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 56U)) + 9428052101528111892U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 12763657928312763377U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10751286982008662485U;
            aOrbiterC = RotL64((aOrbiterC * 6169084301655877217U), 5U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterK) + 1708230173038057979U) + aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 4011389705422783816U;
            aOrbiterE = RotL64((aOrbiterE * 11692237130784795961U), 37U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 11704428328093077714U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 2055336619674699284U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6374289210096410907U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 1870865272102705804U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 3574214263751923179U;
            aOrbiterK = RotL64((aOrbiterK * 13132083406834413563U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 984611970726966186U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 15207945449947643672U) ^ aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9539470161576639981U), 19U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 14U));
            aIngress = aIngress + RotL64(aOrbiterK, 27U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aScatter, 46U) + aOrbiterB) + RotL64(aOrbiterE, 50U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + RotL64(aCarry, 13U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererD = aWandererD ^ (((RotL64(aCross, 57U) + aOrbiterF) + RotL64(aOrbiterK, 5U)) + aPhaseHWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererA = aWandererA + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterK, 29U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterB, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererH, 11U) ^ aWandererA);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 19U));
            aCarry = aCarry + RotL64(aWandererI, 27U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 13793U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((aIndex + 11262U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10310U)) & S_BLOCK1], 28U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 15045U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 13248U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 10408U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 24U) ^ RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 24U)) + 2672739400294801233U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = (aWandererB + RotL64(aCross, 11U)) + 8475624545015101850U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 3U)) + RotL64(aCarry, 23U)) + 1252755112289831257U;
            aOrbiterA = (((aWandererE + RotL64(aPrevious, 47U)) + RotL64(aCarry, 51U)) + 7938039507649183387U) + aPhaseHOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = ((aWandererF + RotL64(aCross, 37U)) + RotL64(aCarry, 11U)) + 8167413146948861022U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 17712313989694374353U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 7637042279892596975U;
            aOrbiterI = RotL64((aOrbiterI * 13056020836704050293U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 15770412950033467341U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3951812021898608685U;
            aOrbiterD = RotL64((aOrbiterD * 6623127125223204737U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 8656983621098246507U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17943342344730687317U;
            aOrbiterF = RotL64((aOrbiterF * 16495519451034883813U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 3087677463651608668U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 16493240011924342788U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16898479041530771871U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 7750923317452683057U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 2185924841611106546U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 708072658250726381U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterD, 34U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + (((RotL64(aCross, 29U) + aOrbiterI) + RotL64(aOrbiterF, 12U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterI, 37U)) + aPhaseHWandererUpdateSaltB[((aIndex + 11U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 52U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + aPhaseHWandererUpdateSaltE[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterH, 47U)) + aOrbiterA);
            aWandererC = aWandererC + (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 51U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 57U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 18U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 20350U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((aIndex + 16845U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 23741U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23274U)) & S_BLOCK1], 47U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 19845U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 20817U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCarry, 5U)) + (RotL64(aCross, 21U) ^ RotL64(aPrevious, 56U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (aWandererG + RotL64(aScatter, 57U)) + 12980104182836602177U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 39U)) + 3172622203188863995U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = (((aWandererH + RotL64(aCross, 44U)) + RotL64(aCarry, 21U)) + 1170974132219980203U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aIngress, 21U)) + 6035201940965047490U;
            aOrbiterI = ((aWandererE + RotL64(aScatter, 29U)) + RotL64(aCarry, 57U)) + 18033907118424996722U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 14604813424800580304U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 13720232492851066035U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 8927246214721284759U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 3902659710585257448U;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 8331560652661619868U;
            aOrbiterI = RotL64((aOrbiterI * 11418103770615560205U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4485014147538689794U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 168202636924512424U;
            aOrbiterA = RotL64((aOrbiterA * 13711020666131492091U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 16227825670092707848U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 4792781933944671365U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 15859849676231455283U), 39U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterI) + 12636865372722601282U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 18198291399585556632U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 18155803890313399795U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterA, 37U);
            aIngress = aIngress + (RotL64(aOrbiterI, 12U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 58U) + aOrbiterA) + RotL64(aOrbiterI, 56U));
            aWandererG = aWandererG + (((RotL64(aCross, 47U) + aOrbiterI) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 51U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterE, 23U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 39U) + aOrbiterD) + RotL64(aOrbiterI, 35U)) + RotL64(aCarry, 19U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 21U) + aOrbiterD) + RotL64(aOrbiterA, 5U)) + aPhaseHWandererUpdateSaltD[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 23U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 56U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 26425U)) & S_BLOCK1], 5U) ^ RotL64(aWorkLaneA[((aIndex + 28168U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 25385U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32762U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 31126U)) & S_BLOCK1], 10U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 28529U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aPrevious, 57U) ^ RotL64(aCross, 28U)) + (RotL64(aIngress, 13U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterK = (aWandererG + RotL64(aCross, 21U)) + 1210605127156905516U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 5U)) + 11964595428173569519U) + aPhaseHOrbiterAssignSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterH = (((aWandererJ + RotL64(aPrevious, 60U)) + RotL64(aCarry, 23U)) + 16277319029916258482U) + aPhaseHOrbiterAssignSaltB[((aIndex + 22U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aIngress, 35U)) + RotL64(aCarry, 5U)) + 12369497463101824572U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 47U)) + RotL64(aCarry, 35U)) + 6201248574067068202U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1727477025667206661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1404510627789806851U;
            aOrbiterH = RotL64((aOrbiterH * 4810039298122529021U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 6948213591282018925U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6688865181284421478U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12619122841662247279U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterK) + 3351130769402360855U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 12681032488906270823U;
            aOrbiterC = RotL64((aOrbiterC * 3680893896579741263U), 11U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 3591412591193726763U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 16153817571210878589U;
            aOrbiterB = RotL64((aOrbiterB * 4165137036092246349U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 3808228354421006630U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 1427373776207504205U;
            aOrbiterK = RotL64((aOrbiterK * 4534374093769595531U), 19U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterB, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 29U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 40U)) + aOrbiterK);
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 53U)) + aOrbiterB) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aCross, 41U) + RotL64(aOrbiterH, 3U)) + aOrbiterB) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 5U));
            aCarry = aCarry + RotL64(aWandererH, 29U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
