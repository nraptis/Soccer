#include "TwistExpander_Lacrosse_Arx.hpp"
#include "TwistFunctional.hpp"
#include "TwistMix32.hpp"
#include "TwistMix64.hpp"

#include <cstdint>

void TwistExpander_Lacrosse_Arx::KDF_A_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xDA88C2E8DAB1A1ABULL + 0x9B7F6E65BA10F07AULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF2F5ACD22327279DULL + 0x95DA84361D46D4ECULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF21BFD82131EA0DDULL + 0xA46BFBD4892B9569ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xBEEA1DA7ACF4A383ULL + 0xFF7B834370A2052BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE57F16261D390DD9ULL + 0xCE44684FD59459DEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xECB366B920E6E01FULL + 0x979A9CD467EBF19BULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xB49704E9897D2595ULL + 0xDC979C5347B3843DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xDB269E1A0D5B911BULL + 0xAAB5283877A2ADB2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xBDF52F1C39EC601FULL + 0xDBD453612DF0AB32ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xA43A0D0DEF7DCE73ULL + 0x91220837ED9763E6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xD6B6A7D4C50948B7ULL + 0x9E836541C75C1146ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0x8E85940F733FFB1BULL + 0xE479E0355CB95940ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE7F1E026125E076DULL + 0xAEBF701787C3CBA0ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xE64458A4E5E0A57DULL + 0xD5D2DE4EF200CDC0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x86FE8F5B20564957ULL + 0x9603C8B21B82CB84ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xB5F8C2F7BA0FC259ULL + 0xE5748FE6A9802CC5ULL);
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
            aIngress = RotL64(mSource[((aIndex + 878U)) & S_BLOCK1], 19U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 1129U)) & S_BLOCK1], 10U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 1127U)) & S_BLOCK1], 58U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 203U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aPrevious, 43U) + RotL64(aCross, 28U)) + (RotL64(aCarry, 13U) ^ RotL64(aIngress, 57U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 10U)) + 15904465836916519864U) + aNonceWordA;
            aOrbiterG = (aWandererC + RotL64(aIngress, 3U)) + 17725629806317789307U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 35U)) + 13794170125914914828U) + aNonceWordM;
            aOrbiterI = (((aWandererF + RotL64(aCross, 19U)) + RotL64(aCarry, 11U)) + 2149055907476874332U) + aOrbiterAssignSaltD[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = ((aWandererK + RotL64(aIngress, 13U)) + RotL64(aCarry, 3U)) + 5342047776745074649U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 39U)) + 8268148484060546838U) + aNonceWordF;
            aOrbiterC = ((((aWandererJ + RotL64(aScatter, 51U)) + RotL64(aCarry, 23U)) + 10821151364028563719U) + aOrbiterAssignSaltA[((aIndex + 8U)) & S_SALT1]) + aNonceWordN;
            aOrbiterK = (aWandererB + RotL64(aCross, 21U)) + 4294213820894407378U;
            aOrbiterA = (aWandererD + RotL64(aPrevious, 43U)) + 10884726101307943090U;
            aOrbiterB = (aWandererG + RotL64(aIngress, 24U)) + 16432210042202444824U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 53U)) + 15196602644336228055U;
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 14117787670220328165U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 219833877949480215U;
            aOrbiterD = RotL64((aOrbiterD * 10736293047771972173U), 53U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 3326396981881473962U;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14918513066311426279U;
            aOrbiterF = RotL64((aOrbiterF * 14269763278564574663U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11795234681370163206U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 3068267285352664813U;
            aOrbiterG = RotL64((aOrbiterG * 15746255933920904619U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 245233356957999496U) + aNonceWordH;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 709926406353796673U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 13627039596842073595U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5378105439430271038U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 10114555061122044430U) ^ aNonceWordB;
            aOrbiterI = RotL64((aOrbiterI * 5351295043424885549U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13233010815716769713U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8231291294833548389U) ^ aNonceWordE;
            aOrbiterK = RotL64((aOrbiterK * 10840516135212753869U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 7160760224172419829U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14767926435411546785U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1643485739468851073U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterJ) + 4464245330038080103U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 15778166658285494712U) ^ aNonceWordC;
            aOrbiterB = RotL64((aOrbiterB * 13980891936095282989U), 51U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2426340576450960905U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 6030631392508241438U;
            aOrbiterJ = RotL64((aOrbiterJ * 13921288910299408423U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 15990180955119402476U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 8707879851984546959U;
            aOrbiterA = RotL64((aOrbiterA * 13794027045755532979U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 11665969506971636052U) + aOrbiterUpdateSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 15904465836916519864U;
            aOrbiterH = RotL64((aOrbiterH * 17042355185093585101U), 37U);
            //
            aIngress = RotL64(aOrbiterH, 35U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 51U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 21U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterJ, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 18U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterK, 28U)) + aOrbiterA) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterF, 19U)) + aNonceWordJ);
            aWandererC = aWandererC + (((RotL64(aCross, 44U) + RotL64(aOrbiterH, 57U)) + aOrbiterD) + aWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterJ, 47U)) + aOrbiterI) + aNonceWordL);
            aWandererK = aWandererK + ((RotL64(aCross, 53U) + RotL64(aOrbiterG, 39U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 21U) + aOrbiterI) + RotL64(aOrbiterH, 13U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterG, 43U)) + aWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 51U) + aOrbiterG) + RotL64(aOrbiterI, 26U)) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aIngress, 10U) + aOrbiterC) + RotL64(aOrbiterD, 41U)) + RotL64(aCarry, 57U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterD, 5U)) + aNonceWordG);
            aWandererG = aWandererG + ((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 54U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererJ, 29U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererF, 56U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 9433U)) & S_BLOCK1], 11U) ^ RotL64(mSource[((aIndex + 6544U)) & S_BLOCK1], 48U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 7996U)) & S_BLOCK1], 51U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 5610U)) & S_BLOCK1], 20U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 60U) ^ RotL64(aCarry, 29U)) + (RotL64(aPrevious, 11U) ^ RotL64(aCross, 47U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterJ = ((aWandererC + RotL64(aPrevious, 44U)) + RotL64(aCarry, 23U)) + 17454559218352016650U;
            aOrbiterK = (aWandererH + RotL64(aScatter, 41U)) + 8005709669325164803U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 27U)) + 13393741948412816357U) + aNonceWordN;
            aOrbiterD = (aWandererJ + RotL64(aIngress, 53U)) + 3665865624348875553U;
            aOrbiterE = ((aWandererE + RotL64(aCross, 6U)) + 8334142570031883436U) + aOrbiterAssignSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterG = ((aWandererK + RotL64(aScatter, 35U)) + RotL64(aCarry, 5U)) + 17226066128706139657U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 21U)) + 3319093033121522613U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 19U)) + 6657535603401588798U;
            aOrbiterB = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 11U)) + 5469746182326331147U;
            aOrbiterA = (((aWandererA + RotL64(aIngress, 23U)) + 17846791786050221418U) + aOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordH;
            aOrbiterH = (aWandererI + RotL64(aScatter, 57U)) + 15939541003714896288U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 12076763190461077406U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 3594038213596405284U) ^ aNonceWordM;
            aOrbiterI = RotL64((aOrbiterI * 10244002692575821495U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8301291631324464622U) + aOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 8460406137668390582U;
            aOrbiterJ = RotL64((aOrbiterJ * 9117147929757711595U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7612394867020871200U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 8525076134853103975U;
            aOrbiterE = RotL64((aOrbiterE * 5790440201072204659U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 11929899088215090379U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7119509166360685726U;
            aOrbiterK = RotL64((aOrbiterK * 1662341427992528823U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 5081078459225240607U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 17149991983909906705U;
            aOrbiterD = RotL64((aOrbiterD * 950223374568067343U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8817303295675241994U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 7962039282652745113U) ^ aNonceWordC;
            aOrbiterA = RotL64((aOrbiterA * 12773588587795522121U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 13596273086338032370U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 8186297702278180956U;
            aOrbiterG = RotL64((aOrbiterG * 6226504769888753861U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 1696277861691580263U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 17360461831507082959U;
            aOrbiterH = RotL64((aOrbiterH * 1651378456022210983U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 1384868996572650981U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2039624849777183290U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 13148024378138271937U), 5U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 14530407348595669913U) + aOrbiterUpdateSaltC[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 18023931565754525034U;
            aOrbiterC = RotL64((aOrbiterC * 18025122652259338105U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 11245556671533878373U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 17454559218352016650U;
            aOrbiterF = RotL64((aOrbiterF * 15665798947106818229U), 23U);
            //
            aIngress = RotL64(aOrbiterH, 47U) ^ aOrbiterG;
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 14U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aIngress, 56U) + aOrbiterK) + RotL64(aOrbiterC, 5U));
            aWandererC = aWandererC + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterD, 60U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 3U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aCross, 23U) + RotL64(aOrbiterG, 23U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterF, 37U)) + aOrbiterA);
            aWandererJ = aWandererJ + (((RotL64(aCross, 34U) + RotL64(aOrbiterB, 43U)) + aOrbiterD) + RotL64(aCarry, 35U));
            aWandererB = aWandererB ^ ((((RotL64(aScatter, 3U) + aOrbiterG) + RotL64(aOrbiterD, 12U)) + aNonceWordL) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 35U)) + aOrbiterC);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterB, 51U)) + aOrbiterE) + aNonceWordJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 37U) + RotL64(aOrbiterA, 41U)) + aOrbiterC);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterE, 21U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 26U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + (RotL64(aWandererG, 11U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererA, 37U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererE, 51U);
            aCarry = aCarry + RotL64(aIngress, 24U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 14952U)) & S_BLOCK1], 19U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 15036U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(pSnow[((S_BLOCK1 - aIndex + 12980U)) & S_BLOCK1], 3U) ^ RotL64(aWorkLaneA[((aIndex + 11318U)) & S_BLOCK1], 56U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 53U)) ^ (RotL64(aIngress, 4U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 13U)) + 9654059367478508868U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = (aWandererD + RotL64(aScatter, 37U)) + 6473006635864677427U;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 29U)) + RotL64(aCarry, 27U)) + 6944184481315853243U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 60U)) + 4061496421939102306U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 11U)) + 15791809275719085463U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 19U)) + 14050798802646323055U) + aNonceWordG;
            aOrbiterJ = (aWandererF + RotL64(aCross, 21U)) + 12072905924741758266U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 3U)) + 17639076509231343896U;
            aOrbiterH = ((aWandererH + RotL64(aPrevious, 43U)) + RotL64(aCarry, 47U)) + 12195388285571234715U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 23U)) + RotL64(aCarry, 51U)) + 4325404419499496529U) + aNonceWordB;
            aOrbiterA = (((aWandererI + RotL64(aCross, 6U)) + 5910567888204238382U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordK;
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 13092940059929942699U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 13381962590820308761U;
            aOrbiterD = RotL64((aOrbiterD * 6345904465930943295U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 15622862439323440527U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 14027151901132249793U) ^ aNonceWordC;
            aOrbiterF = RotL64((aOrbiterF * 2273573821630510087U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 4584410023907605157U) + aNonceWordO;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 15763755180625487157U;
            aOrbiterE = RotL64((aOrbiterE * 6755736130607297639U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 17023059745666559199U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5298529579288492971U;
            aOrbiterC = RotL64((aOrbiterC * 2483562793328357721U), 53U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 2870152867331654736U) + aOrbiterUpdateSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 12017191100173748848U;
            aOrbiterH = RotL64((aOrbiterH * 9958191466506480519U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 15899529176182436062U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 16482713846343388735U;
            aOrbiterG = RotL64((aOrbiterG * 719465695044265601U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12943393531812774449U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 9881108254540483225U;
            aOrbiterB = RotL64((aOrbiterB * 8011108108007885059U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 3532054586199716750U) + aNonceWordA;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 7142230313294797435U;
            aOrbiterK = RotL64((aOrbiterK * 14154176174768868421U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 733958394016131587U) + aOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 2060800099014517137U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 12988885554457108631U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 2278498033811574812U) + aOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15342071118593803929U;
            aOrbiterI = RotL64((aOrbiterI * 7842196613533603835U), 21U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 12987212219357101955U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9654059367478508868U;
            aOrbiterA = RotL64((aOrbiterA * 11796100167917742307U), 37U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 51U));
            aIngress = aIngress + (RotL64(aOrbiterK, 37U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterD, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 5U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 21U) + aOrbiterJ) + RotL64(aOrbiterB, 46U)) + aNonceWordJ) + aWandererUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterE, 21U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterA, 35U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aCross, 48U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + RotL64(aCarry, 29U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 57U) + aOrbiterD) + RotL64(aOrbiterI, 19U));
            aWandererG = aWandererG + ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 11U)) + aOrbiterK);
            aWandererA = aWandererA ^ ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterG, 23U));
            aWandererH = aWandererH + (((RotL64(aIngress, 12U) + aOrbiterI) + RotL64(aOrbiterK, 44U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + aOrbiterF) + RotL64(aOrbiterI, 27U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 51U));
            aCarry = aCarry + (RotL64(aWandererH, 30U) ^ aWandererA);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererG);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererK, 23U));
            aCarry = aCarry + RotL64(aWandererD, 4U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 18068U)) & S_BLOCK1], 28U) ^ RotL64(aWorkLaneA[((aIndex + 17374U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordF));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 18310U)) & S_BLOCK1], 3U) ^ RotL64(pSnow[((S_BLOCK1 - aIndex + 21040U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19398U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 57U) + RotL64(aCarry, 13U)) ^ (RotL64(aPrevious, 29U) ^ RotL64(aCross, 42U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterI = (aWandererE + RotL64(aPrevious, 27U)) + 16124889768301047791U;
            aOrbiterH = (aWandererK + RotL64(aCross, 34U)) + 11912338587186717280U;
            aOrbiterC = (aWandererB + RotL64(aIngress, 13U)) + 8594012868813114354U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 23U)) + RotL64(aCarry, 23U)) + 18281043566156682815U;
            aOrbiterE = ((aWandererD + RotL64(aPrevious, 21U)) + RotL64(aCarry, 47U)) + 16853106130200942302U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 39U)) + 2611212958619673086U) + aOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aScatter, 29U)) + 18039472325066855180U;
            aOrbiterK = ((((aWandererJ + RotL64(aIngress, 52U)) + RotL64(aCarry, 41U)) + 14495785571345122046U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordM;
            aOrbiterD = (aWandererI + RotL64(aPrevious, 43U)) + 4556063793412832418U;
            aOrbiterG = ((aWandererF + RotL64(aIngress, 5U)) + 14896419970271244358U) + aNonceWordB;
            aOrbiterB = (aWandererG + RotL64(aCross, 57U)) + 880028529183500036U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 2379557167489415783U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11854373946064529806U;
            aOrbiterC = RotL64((aOrbiterC * 150755294320438887U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 1487252775956449964U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 12777924204511625545U;
            aOrbiterI = RotL64((aOrbiterI * 1366019527386994789U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 15998631485222477969U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8864212892296191613U;
            aOrbiterH = RotL64((aOrbiterH * 579242788050369815U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 17069347835763226743U) + aOrbiterUpdateSaltA[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7443008171694679791U;
            aOrbiterK = RotL64((aOrbiterK * 748894368884566607U), 43U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 17334256152350782002U) + aOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 8986626119086556393U;
            aOrbiterG = RotL64((aOrbiterG * 2258172145924120235U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 8528180968228358674U) + aNonceWordG;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12702290928064582589U;
            aOrbiterA = RotL64((aOrbiterA * 15673603224146737631U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7742438100860023610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 3729687240959702198U;
            aOrbiterJ = RotL64((aOrbiterJ * 3756794766163746783U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 426129097367382096U) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 16782175452274911213U;
            aOrbiterB = RotL64((aOrbiterB * 1041477289638333659U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 5942016166948841079U) + aOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 5260815086125551703U;
            aOrbiterD = RotL64((aOrbiterD * 1603799103692438147U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 11732742583346900772U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 17182924380693084401U;
            aOrbiterE = RotL64((aOrbiterE * 14858685629471497071U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 8539335803784852017U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 16124889768301047791U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6607245691919237755U), 39U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterC, 13U);
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 29U));
            aIngress = aIngress + (RotL64(aOrbiterB, 20U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 11U));
            aIngress = aIngress + RotL64(aOrbiterG, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 34U) + RotL64(aOrbiterE, 5U)) + aOrbiterK) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterC, 14U));
            aWandererH = aWandererH + (((RotL64(aIngress, 41U) + RotL64(aOrbiterF, 37U)) + aOrbiterG) + RotL64(aCarry, 13U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterB, 51U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterH) + RotL64(aOrbiterE, 39U)) + aWandererUpdateSaltF[((aIndex + 24U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 58U)) + aOrbiterI) + aNonceWordK);
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterA) + RotL64(aCarry, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 51U) + aOrbiterH) + RotL64(aOrbiterJ, 21U));
            aWandererF = aWandererF + ((RotL64(aScatter, 11U) + RotL64(aOrbiterJ, 29U)) + aOrbiterE);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 13U) + aOrbiterG) + RotL64(aOrbiterA, 47U)) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aCross, 6U) + RotL64(aOrbiterC, 27U)) + aOrbiterA) + aNonceWordC);
            //
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 35U));
            aCarry = aCarry + (RotL64(aWandererD, 47U) ^ aWandererJ);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 41U));
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 50U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 22954U)) & S_BLOCK1], 5U) ^ RotL64(mSource[((aIndex + 25301U)) & S_BLOCK1], 23U));
            aIngress ^= (RotL64(pSnow[((aIndex + 25852U)) & S_BLOCK1], 14U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27007U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 26182U)) & S_BLOCK1], 36U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 26010U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 26U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterG = ((aWandererI + RotL64(aCross, 21U)) + RotL64(aCarry, 35U)) + 6361545377408870615U;
            aOrbiterE = (aWandererF + RotL64(aPrevious, 23U)) + 2967245486744774933U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 50U)) + 3836634268482850139U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 39U)) + 7691642115360086297U;
            aOrbiterK = (aWandererA + RotL64(aCross, 19U)) + 16479280384178279281U;
            aOrbiterI = ((aWandererK + RotL64(aIngress, 53U)) + 2901468732552539249U) + aOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aScatter, 47U)) + 2600353867755647475U) + aOrbiterAssignSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 26U)) + 5666596904781510956U) + aNonceWordF;
            aOrbiterB = (((aWandererJ + RotL64(aScatter, 41U)) + RotL64(aCarry, 41U)) + 16108791609267427553U) + aNonceWordL;
            aOrbiterH = ((aWandererH + RotL64(aIngress, 35U)) + RotL64(aCarry, 3U)) + 8389926875737312112U;
            aOrbiterD = (aWandererB + RotL64(aCross, 13U)) + 1689501721163024426U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 11721701506949917719U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 3963842745030140473U;
            aOrbiterJ = RotL64((aOrbiterJ * 6692473494944919373U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterK) + 8510538243472109368U) + aNonceWordN;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 18281865214102080387U) ^ aNonceWordJ;
            aOrbiterI = RotL64((aOrbiterI * 1351546966368884609U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 2259725140963665123U) + aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 11652011949557979650U;
            aOrbiterG = RotL64((aOrbiterG * 11260100762113295037U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 1116085424226174473U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4725260319270802912U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 4697109059565450269U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 7348945429843437036U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1249234309180653260U;
            aOrbiterE = RotL64((aOrbiterE * 3136745255820405881U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 12463505532573389603U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 2304125977906510386U;
            aOrbiterH = RotL64((aOrbiterH * 9960816714791454421U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 2178037443783425551U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 11712110130079307683U;
            aOrbiterF = RotL64((aOrbiterF * 9797864956200779505U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 10703510612147312252U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 18155460326242413483U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 6903953708987478723U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 5753486645345036069U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 2314216774606770444U;
            aOrbiterA = RotL64((aOrbiterA * 14002639533287566667U), 53U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterB) + 9662599462788305323U) + aNonceWordO;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 3805101172359199209U;
            aOrbiterC = RotL64((aOrbiterC * 10669315962181581543U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 1073926575064224947U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 6361545377408870615U;
            aOrbiterB = RotL64((aOrbiterB * 10685650563722188837U), 29U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 51U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 57U)) + aOrbiterG) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + aOrbiterA) + RotL64(aOrbiterH, 34U)) + aNonceWordI);
            aWandererE = aWandererE + (((RotL64(aIngress, 41U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + aWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + aOrbiterB) + RotL64(aOrbiterK, 5U)) + aNonceWordP);
            aWandererK = aWandererK + ((RotL64(aPrevious, 46U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterG, 23U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterI, 41U));
            aWandererD = aWandererD ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterF, 19U)) + aOrbiterD) + aNonceWordH);
            aWandererB = aWandererB + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 44U)) + aOrbiterK);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterJ, 39U)) + aOrbiterC);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 51U) + RotL64(aOrbiterE, 11U)) + aOrbiterB) + RotL64(aCarry, 53U)) + aNonceWordK) + aWandererUpdateSaltE[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererI, 14U) ^ aWandererC);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 54U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 29887U)) & S_BLOCK1], 27U) ^ RotL64(pSnow[((aIndex + 30467U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31664U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 31670U)) & S_BLOCK1], 47U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 27702U)) & S_BLOCK1], 58U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 27981U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 56U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (aWandererB + RotL64(aCross, 29U)) + 13960289014350612206U;
            aOrbiterI = (aWandererG + RotL64(aScatter, 37U)) + 3483331015269589730U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 18U)) + 6873299241002444518U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aIngress, 5U)) + RotL64(aCarry, 27U)) + 3562094007125534229U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 23U)) + 11422367439932782705U) + aNonceWordO;
            aOrbiterK = (aWandererC + RotL64(aIngress, 47U)) + 532453428514259816U;
            aOrbiterB = ((((aWandererH + RotL64(aCross, 51U)) + RotL64(aCarry, 53U)) + 17810941465810193088U) + aOrbiterAssignSaltB[((aIndex + 28U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = (((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 13U)) + 11869759058631106331U) + aNonceWordC;
            aOrbiterG = (aWandererE + RotL64(aIngress, 42U)) + 8837581071876177566U;
            aOrbiterD = ((aWandererD + RotL64(aScatter, 39U)) + 17185378327053837778U) + aNonceWordE;
            aOrbiterF = (aWandererJ + RotL64(aPrevious, 27U)) + 7578253375676981500U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17112646434432814442U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 14949096407295697881U;
            aOrbiterE = RotL64((aOrbiterE * 14770977858283051753U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 4259590620758467836U) + aOrbiterUpdateSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 6534899413644542303U) ^ aOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7987609419215568661U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 2637407498893694243U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15819295597921425711U;
            aOrbiterI = RotL64((aOrbiterI * 5202015597375051399U), 37U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 6373559542002699718U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 11694562937392022505U;
            aOrbiterD = RotL64((aOrbiterD * 9311557972331218597U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 3308736483775453062U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 12749929710650475901U;
            aOrbiterB = RotL64((aOrbiterB * 248428400724560945U), 39U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 1569528215675579656U) + aOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 1044077933631689572U;
            aOrbiterA = RotL64((aOrbiterA * 6443796233912755143U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 8393422728124537471U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 2002732612516530754U;
            aOrbiterH = RotL64((aOrbiterH * 13702146823622364279U), 13U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13469191942843147943U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 7633171368709520560U;
            aOrbiterG = RotL64((aOrbiterG * 9713514012478203047U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 4023206337737491091U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 15990323932023596968U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 4816480271959713463U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 837005729394899591U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 9692088757104339973U;
            aOrbiterC = RotL64((aOrbiterC * 17971548293495807419U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 18039464962413134616U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 13960289014350612206U;
            aOrbiterF = RotL64((aOrbiterF * 931609478642506411U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 27U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 35U));
            aIngress = aIngress + RotL64(aOrbiterK, 48U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 28U)) + aOrbiterG);
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 53U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 54U) + aOrbiterC) + RotL64(aOrbiterE, 13U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterI);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterG, 26U)) + aOrbiterB);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + RotL64(aOrbiterG, 43U)) + aOrbiterF) + aWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 35U)) + aOrbiterA);
            aWandererH = aWandererH + ((((RotL64(aCross, 41U) + RotL64(aOrbiterK, 41U)) + aOrbiterH) + RotL64(aCarry, 21U)) + aNonceWordB);
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 47U) + RotL64(aOrbiterK, 19U)) + aOrbiterG) + aNonceWordP);
            aWandererB = aWandererB + ((((RotL64(aScatter, 3U) + RotL64(aOrbiterH, 57U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 30U) + RotL64(aOrbiterD, 21U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererE, 60U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 43U));
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererB, 37U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xF3370BA2E1597345ULL + 0x888C008405C40076ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xDF86E04003A768D3ULL + 0xBA198A0F652E7F4EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xCF414D18A8AA0BABULL + 0xC76111225D1CBA3AULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF01B389E09AB5713ULL + 0xAAA3F72B4F9659C7ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xD002A0A1D7EEA8F7ULL + 0xB36F010D7A2DAE61ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0x8EA9716B9C7FC677ULL + 0x9276188D25DCD8A0ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xC958D578EC5F7411ULL + 0xDC89D94DDE64758DULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xA1CE1771AEF07B97ULL + 0xED396AB1FEF485C4ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xE72F3AEA97F1275FULL + 0x89221F97FD94CB37ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x8D98764A7E26118DULL + 0x91455A1653335925ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0xC9AB6E31FFF20DF1ULL + 0x8BE48F7073197189ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0x801510E52D39CD97ULL + 0xD28DAE7B417D2B0BULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9E3F195CA4C55607ULL + 0xB0FBA8E1C3D67D5AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xBC15D0070B175D47ULL + 0x85599BDBABC5BB06ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF6641183E528F447ULL + 0xAE74C77782ADEEA1ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xF1034C16BC714D9FULL + 0xF2623220BEC4A42FULL);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 6413U)) & S_BLOCK1], 60U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 1660U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordN));
            //
            aCross = RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 3867U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneD[((aIndex + 7942U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCarry, 20U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 53U) ^ RotL64(aIngress, 37U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterJ = ((aWandererK + RotL64(aCross, 27U)) + 14499676118633326000U) + aNonceWordO;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 10U)) + 17191273593018552288U) + aOrbiterAssignSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterA = (aWandererI + RotL64(aIngress, 51U)) + 4085176294948097737U;
            aOrbiterE = (((aWandererA + RotL64(aScatter, 19U)) + RotL64(aCarry, 27U)) + 11112671474158908186U) + aOrbiterAssignSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 37U)) + 8745787969012266485U) + aNonceWordL;
            aOrbiterD = (aWandererG + RotL64(aCross, 57U)) + 18074049663777707948U;
            aOrbiterC = (aWandererE + RotL64(aScatter, 14U)) + 2543758649719164688U;
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 23U)) + RotL64(aCarry, 5U)) + 4659584749412700523U;
            aOrbiterG = (aWandererD + RotL64(aIngress, 39U)) + 974639159259871273U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 9211220687971081987U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8567024626862182714U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 7755874089832496393U), 19U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterK) + 5803002132294840900U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 11968489432878148467U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 4501441062617123165U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 9470807228394903442U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 1692347973120388469U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 17433393164156231575U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 16510815732690193145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 755159406833096510U;
            aOrbiterC = RotL64((aOrbiterC * 14091736464659561165U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 1518824876475937620U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 701225390867330446U;
            aOrbiterI = RotL64((aOrbiterI * 12264618860580199927U), 35U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 8425976693733003889U) + aOrbiterUpdateSaltE[((aIndex + 12U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 7182176375442410367U;
            aOrbiterG = RotL64((aOrbiterG * 8860605703761731859U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 4546566785167467924U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 2593340999038753749U;
            aOrbiterK = RotL64((aOrbiterK * 10152461487764567563U), 27U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 9756331608356622299U) + aOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5511625814747641978U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4806076157539829529U), 47U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 8694400787420160733U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12648969491371382682U;
            aOrbiterE = RotL64((aOrbiterE * 5346585704222643759U), 43U);
            //
            aIngress = RotL64(aOrbiterJ, 50U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 57U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 35U));
            aIngress = aIngress + RotL64(aOrbiterA, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 12U)) + aOrbiterJ);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 58U) + aOrbiterJ) + RotL64(aOrbiterF, 23U)) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 39U) + aOrbiterE) + RotL64(aOrbiterK, 37U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterC, 41U)) + aNonceWordC);
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 53U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterI, 19U)) + aOrbiterA);
            aWandererE = aWandererE + ((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterC, 47U));
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterJ, 5U)) + aOrbiterD) + aNonceWordF) + aWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 54U) + RotL64(aOrbiterK, 30U)) + aOrbiterA) + aNonceWordA);
            //
            aCarry = aCarry + (RotL64(aWandererK, 57U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (RotL64(aWandererE, 41U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 27U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererJ, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16019U)) & S_BLOCK1], 48U) ^ RotL64(aFireLaneB[((aIndex + 9481U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 15719U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11199U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 15234U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 23U)) + (RotL64(aCross, 36U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterF = ((aWandererJ + RotL64(aIngress, 29U)) + 2330952702412094686U) + aNonceWordE;
            aOrbiterK = ((((aWandererI + RotL64(aPrevious, 47U)) + RotL64(aCarry, 23U)) + 7820188225935060799U) + aOrbiterAssignSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordL;
            aOrbiterB = (aWandererC + RotL64(aCross, 6U)) + 9347644591709839145U;
            aOrbiterE = ((aWandererH + RotL64(aScatter, 41U)) + 2288624878446846870U) + aNonceWordK;
            aOrbiterI = (aWandererF + RotL64(aCross, 53U)) + 9358977729492824128U;
            aOrbiterA = ((aWandererA + RotL64(aScatter, 37U)) + RotL64(aCarry, 57U)) + 1858511275052455039U;
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 21U)) + 13715478509322292552U) + aOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 58U)) + RotL64(aCarry, 43U)) + 16413396625604260455U;
            aOrbiterC = ((aWandererK + RotL64(aScatter, 11U)) + 17714322215518432705U) + aNonceWordP;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 16188315436202861122U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5564445841368207813U;
            aOrbiterB = RotL64((aOrbiterB * 14125834616162835983U), 57U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 13717068949900594673U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 14143659432287313765U;
            aOrbiterA = RotL64((aOrbiterA * 17281441046722262917U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 5729546141908425670U) + aOrbiterUpdateSaltC[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4297827922736712074U;
            aOrbiterI = RotL64((aOrbiterI * 13631630436759768885U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 829520109395163673U) + aNonceWordJ;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 11547160328525174295U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 4759690159673049775U), 39U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 2907177944512117206U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11100346409065275671U;
            aOrbiterK = RotL64((aOrbiterK * 17927994356809011637U), 19U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterJ) + 1344592529249949068U) + aOrbiterUpdateSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6470438516791143572U;
            aOrbiterE = RotL64((aOrbiterE * 13339390828725370475U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 5217751823741520847U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5371275223586938039U;
            aOrbiterG = RotL64((aOrbiterG * 12318403075523724125U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14218103150268532919U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 1367628876596800571U;
            aOrbiterC = RotL64((aOrbiterC * 13777531272321533137U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2372041991018455610U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 9870744274890595581U;
            aOrbiterJ = RotL64((aOrbiterJ * 12093443117747395585U), 13U);
            //
            aIngress = RotL64(aOrbiterA, 3U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterI, 47U));
            aIngress = aIngress + (RotL64(aOrbiterG, 54U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 43U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 35U) + aOrbiterI) + RotL64(aOrbiterA, 46U)) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 53U) + aOrbiterE) + RotL64(aOrbiterI, 41U)) + RotL64(aCarry, 3U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterI, 53U));
            aWandererD = aWandererD + (((RotL64(aScatter, 48U) + aOrbiterI) + RotL64(aOrbiterG, 19U)) + aWandererUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 3U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aWandererUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererJ = aWandererJ + ((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterG, 57U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterF, 14U)) + aNonceWordI);
            aWandererA = aWandererA + (((RotL64(aScatter, 40U) + RotL64(aOrbiterB, 3U)) + aOrbiterI) + RotL64(aCarry, 35U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterC, 23U)) + aOrbiterG);
            //
            aCarry = aCarry + (RotL64(aWandererF, 3U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererA, 60U) ^ aWandererD);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 11U));
            aCarry = aCarry + (RotL64(aWandererC, 51U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererK, 57U);
            aCarry = aCarry + RotL64(aIngress, 36U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 22403U)) & S_BLOCK1], 39U) ^ RotL64(aFireLaneD[((aIndex + 17409U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 22167U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 18343U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21459U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22626U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 35U) ^ RotL64(aPrevious, 10U)) + (RotL64(aIngress, 51U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererD + RotL64(aIngress, 30U)) + 6361545377408870615U) + aOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = (((aWandererC + RotL64(aCross, 3U)) + RotL64(aCarry, 27U)) + 2967245486744774933U) + aNonceWordG;
            aOrbiterF = (aWandererG + RotL64(aScatter, 11U)) + 3836634268482850139U;
            aOrbiterJ = (aWandererA + RotL64(aPrevious, 51U)) + 7691642115360086297U;
            aOrbiterE = (aWandererE + RotL64(aIngress, 18U)) + 16479280384178279281U;
            aOrbiterB = ((aWandererI + RotL64(aPrevious, 23U)) + RotL64(aCarry, 13U)) + 2901468732552539249U;
            aOrbiterK = ((aWandererH + RotL64(aCross, 43U)) + 2600353867755647475U) + aNonceWordP;
            aOrbiterD = ((((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 5666596904781510956U) + aOrbiterAssignSaltC[((aIndex + 25U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererF + RotL64(aIngress, 35U)) + 16108791609267427553U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8389926875737312112U) + aNonceWordC;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 1689501721163024426U;
            aOrbiterF = RotL64((aOrbiterF * 6517194895779049139U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 11721701506949917719U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 3963842745030140473U) ^ aOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6692473494944919373U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8510538243472109368U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 18281865214102080387U;
            aOrbiterH = RotL64((aOrbiterH * 1351546966368884609U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 2259725140963665123U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 11652011949557979650U;
            aOrbiterA = RotL64((aOrbiterA * 11260100762113295037U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 1116085424226174473U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 4725260319270802912U) ^ aNonceWordI;
            aOrbiterE = RotL64((aOrbiterE * 4697109059565450269U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 7348945429843437036U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterB) ^ 1249234309180653260U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterK = RotL64((aOrbiterK * 3136745255820405881U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 12463505532573389603U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 2304125977906510386U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 9960816714791454421U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 2178037443783425551U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11712110130079307683U;
            aOrbiterD = RotL64((aOrbiterD * 9797864956200779505U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 10703510612147312252U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 18155460326242413483U;
            aOrbiterG = RotL64((aOrbiterG * 6903953708987478723U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterJ, 51U);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterH, 4U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterB, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ ((RotL64(aScatter, 18U) + aOrbiterJ) + RotL64(aOrbiterK, 3U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterA, 39U)) + RotL64(aCarry, 3U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterG, 27U)) + aOrbiterE);
            aWandererA = aWandererA + ((((RotL64(aCross, 43U) + RotL64(aOrbiterF, 43U)) + aOrbiterE) + aNonceWordN) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 56U));
            aWandererE = aWandererE + ((((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 13U)) + aNonceWordL);
            aWandererC = aWandererC ^ (((RotL64(aIngress, 47U) + aOrbiterE) + RotL64(aOrbiterA, 35U)) + aNonceWordF);
            aWandererH = aWandererH + (((RotL64(aPrevious, 54U) + aOrbiterG) + RotL64(aOrbiterD, 23U)) + aWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterK, 14U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 24U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererD, 37U) ^ aWandererE);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 29U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 28121U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneC[((aIndex + 25343U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 26576U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 28508U)) & S_BLOCK1], 13U) ^ RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30640U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 26152U)) & S_BLOCK1], 24U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aPrevious, 54U) + RotL64(aCross, 11U)) ^ (RotL64(aIngress, 23U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterE = ((((aWandererB + RotL64(aIngress, 47U)) + RotL64(aCarry, 5U)) + 9041099828460168106U) + aOrbiterAssignSaltA[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererJ + RotL64(aCross, 35U)) + 12883711604096848454U) + aNonceWordB;
            aOrbiterI = (aWandererA + RotL64(aPrevious, 30U)) + 17420968786226443079U;
            aOrbiterF = (aWandererD + RotL64(aScatter, 39U)) + 3448213891716125104U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 57U)) + 11866455977445336560U) + aOrbiterAssignSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterC = ((aWandererE + RotL64(aScatter, 43U)) + RotL64(aCarry, 23U)) + 4119356835384495905U;
            aOrbiterH = (((aWandererG + RotL64(aCross, 19U)) + RotL64(aCarry, 43U)) + 2186212599698637068U) + aNonceWordC;
            aOrbiterD = (aWandererH + RotL64(aIngress, 6U)) + 6506144898969301620U;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 13U)) + 12556800923644051626U) + aNonceWordL;
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 4075551535185182945U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 17877694808492008749U;
            aOrbiterI = RotL64((aOrbiterI * 901315308379887473U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 5553428900598223316U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 14362304852277160675U;
            aOrbiterE = RotL64((aOrbiterE * 11415103199856419303U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 9174200302876075831U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16110739511917638547U;
            aOrbiterH = RotL64((aOrbiterH * 7004356839428657949U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 10189881974519849402U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 2128076632642616677U;
            aOrbiterC = RotL64((aOrbiterC * 8860453653433114929U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 18133523799074400083U) + aOrbiterUpdateSaltE[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 9916472958834153766U;
            aOrbiterG = RotL64((aOrbiterG * 3454601168808001733U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 10274457562795569227U) + aNonceWordJ;
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 14134814273275356425U;
            aOrbiterF = RotL64((aOrbiterF * 15912501063665343159U), 23U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterC) + 6394306369514735480U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 4825761192736485643U;
            aOrbiterK = RotL64((aOrbiterK * 12534544147331805643U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 5672807934779206275U) + aOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3881953574159390421U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7448770570912161095U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 12012232712634303203U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 14176392925893052596U;
            aOrbiterD = RotL64((aOrbiterD * 11288668529893084583U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterC, 26U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterG, 23U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterI);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterE, 11U));
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aIngress, 10U) + RotL64(aOrbiterD, 60U)) + aOrbiterF) + aNonceWordP);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterI, 37U)) + aOrbiterH) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aCross, 19U) + RotL64(aOrbiterK, 47U)) + aOrbiterI) + RotL64(aCarry, 51U)) + aNonceWordN);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterF, 51U)) + aOrbiterA);
            aWandererB = aWandererB + ((RotL64(aCross, 51U) + RotL64(aOrbiterC, 21U)) + aOrbiterE);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterD, 41U));
            aWandererH = aWandererH + (((RotL64(aIngress, 37U) + RotL64(aOrbiterE, 6U)) + aOrbiterA) + aNonceWordA);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 56U) + aOrbiterF) + RotL64(aOrbiterG, 29U)) + aNonceWordH);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 23U) + aOrbiterD) + RotL64(aOrbiterG, 13U)) + RotL64(aCarry, 41U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererI, 48U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererE, 13U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0;

    // [kdf-a arx]
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xABE911D9FA23B86DULL + 0xAB0D942AD197462CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9EF19F1E768FE68BULL + 0xA739BF0240E51EFBULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xF97EEEB1D3D89609ULL + 0x91142F0711FD32DCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xF2843FA6C64ACDF9ULL + 0x929A9BD557C8A3B1ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseB(pNonce * 0xE865CDFD33868681ULL + 0xDFDCE401D0284284ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD090E3A195DF9AFBULL + 0xE3815A7803D9D3D1ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0x91BC894331DDFBBBULL + 0xC19486933371AC99ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xE1755022FFE7FADFULL + 0xED353139AED69EAEULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC1E1DE4133868727ULL + 0xEACD52F699A19D6FULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x8C437C87F871B953ULL + 0xD23632D9894533DEULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE461270DE03116B9ULL + 0x88FF5128ADCD9C93ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x996681522E08B733ULL + 0xF26C75C8AC75A9F7ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xFAE61882136EB5CDULL + 0xF52DC8178EEF0CA5ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xB1ED672D798CCF83ULL + 0xB7135C727312564CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x8519F6DDB571DFA1ULL + 0xDFCA5A67A670B9C2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8B82530BA24EE535ULL + 0xBCAEAB7FCD97318CULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aFireLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aFireLaneA, aWorkLaneC, aFireLaneB
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 3897U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneB[((aIndex + 2169U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 361U)) & S_BLOCK1], 53U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 4749U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneD[((aIndex + 3084U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 29U)) + (RotL64(aCarry, 41U) ^ RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = (((aWandererC + RotL64(aCross, 22U)) + RotL64(aCarry, 57U)) + 1042610313571524121U) + aNonceWordL;
            aOrbiterG = ((aWandererJ + RotL64(aPrevious, 13U)) + 3505725321008825582U) + aOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 5U)) + 12584654563843782991U) + aNonceWordA;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 47U)) + 6645399144515770935U) + aOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterF = (((aWandererD + RotL64(aPrevious, 35U)) + RotL64(aCarry, 19U)) + 3608978423753715584U) + aNonceWordP;
            //
            aOrbiterB = ((aOrbiterB + aOrbiterG) + 8089198857670370983U) + aNonceWordI;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 15207251813516399879U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7596841660069752069U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 9579268660105824516U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16055044469473802812U) ^ aOrbiterUpdateSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2269649280637188723U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 583811872609805949U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterJ) ^ 7027491967970873942U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 12686754713465826139U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 18256061823189677508U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12708429127816136937U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 12593886633108075321U), 27U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 12169216645156306078U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 12694325407567795065U;
            aOrbiterF = RotL64((aOrbiterF * 3711789483877261899U), 41U);
            //
            aIngress = RotL64(aOrbiterJ, 47U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 58U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + RotL64(aOrbiterB, 41U)) + aOrbiterI);
            aWandererH = aWandererH + (((((RotL64(aIngress, 54U) + aOrbiterJ) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 57U)) + aNonceWordC) + aWandererUpdateSaltB[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 3U) + aOrbiterJ) + RotL64(aOrbiterF, 30U)) + aNonceWordM);
            aWandererK = aWandererK + (((((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 53U)) + aOrbiterJ) + RotL64(aCarry, 19U)) + aNonceWordF) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 35U) + aOrbiterG) + RotL64(aOrbiterF, 3U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 24U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 2
        // ingress from: aWorkLaneA, aOperationLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aOperationLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aOperationLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 15524U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((aIndex + 12113U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 8591U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 13235U)) & S_BLOCK1], 57U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 9581U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 16046U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 52U) ^ RotL64(aCarry, 39U)) + (RotL64(aCross, 3U) + RotL64(aIngress, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererG + RotL64(aScatter, 13U)) + 10915618884692072446U) + aNonceWordL;
            aOrbiterE = (((aWandererH + RotL64(aIngress, 37U)) + RotL64(aCarry, 13U)) + 12634922308499254909U) + aOrbiterAssignSaltD[((aIndex + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 56U)) + RotL64(aCarry, 53U)) + 6533934734564499389U;
            aOrbiterC = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 39U)) + 6744203303756105181U) + aNonceWordA;
            aOrbiterD = ((aWandererC + RotL64(aScatter, 27U)) + 13086782386652045658U) + aOrbiterAssignSaltC[((aIndex + 21U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5693840533331397822U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 1803663542535024611U) ^ aNonceWordE;
            aOrbiterI = RotL64((aOrbiterI * 8511046986156781857U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 3597219300593287708U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 1429753448204448904U) ^ aOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10927459251773273143U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 17229017825587322715U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 1137574712801062932U) ^ aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 3645832160939819415U), 51U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterI) + 2401991077004083378U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordB;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 1332473247826139292U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 15029831858261506447U), 23U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 11730946340796899885U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 15319163439700390962U;
            aOrbiterD = RotL64((aOrbiterD * 1349242001887975499U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 60U);
            aIngress = aIngress + (RotL64(aOrbiterI, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 37U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 35U) + aOrbiterB) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 35U)) + aNonceWordJ);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterE, 29U)) + aOrbiterC) + aWandererUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 3U) + RotL64(aOrbiterE, 13U)) + aOrbiterD) + RotL64(aCarry, 53U));
            aWandererH = aWandererH ^ (((RotL64(aScatter, 26U) + RotL64(aOrbiterC, 52U)) + aOrbiterI) + aNonceWordC);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 43U) + RotL64(aOrbiterD, 43U)) + aOrbiterI) + aNonceWordM) + aWandererUpdateSaltA[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 21U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 37U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 21116U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneD[((aIndex + 19786U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 19391U)) & S_BLOCK1], 46U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19778U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 20550U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aOperationLaneC[((aIndex + 17032U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 11U) + RotL64(aCross, 38U)) ^ (RotL64(aIngress, 53U) + RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = (((aWandererJ + RotL64(aScatter, 4U)) + RotL64(aCarry, 53U)) + 6771552164800695068U) + aNonceWordO;
            aOrbiterC = ((aWandererC + RotL64(aCross, 21U)) + 12131763371571322040U) + aOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterB = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 23U)) + 3326182381395522013U;
            aOrbiterF = (((aWandererB + RotL64(aPrevious, 37U)) + 12288775097697156383U) + aOrbiterAssignSaltB[((aIndex + 27U)) & S_SALT1]) + aNonceWordE;
            aOrbiterA = ((aWandererA + RotL64(aCross, 57U)) + RotL64(aCarry, 3U)) + 5195948373449796741U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterC) + 14404044002250137144U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 11142382920035825426U;
            aOrbiterB = RotL64((aOrbiterB * 8134413822789107595U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 2967149520256475485U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 1470907369577818097U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9398653295177725883U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 9231668148004163910U) + aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (((aOrbiterG ^ aOrbiterF) ^ 13078929163913892386U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterG = RotL64((aOrbiterG * 7509829068700523627U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 9485274692075657877U) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12216951187543631673U;
            aOrbiterF = RotL64((aOrbiterF * 6571066246507310805U), 11U);
            //
            aOrbiterA = (((aOrbiterA + aOrbiterG) + 6933334652581744234U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordP;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 17260276102423580920U;
            aOrbiterC = RotL64((aOrbiterC * 7796879893790990605U), 51U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 3U);
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterC, 52U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aCross, 53U) + aOrbiterG) + RotL64(aOrbiterC, 5U)) + aWandererUpdateSaltE[((aIndex + 25U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 13U)) + aOrbiterG) + RotL64(aCarry, 19U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 19U) + aOrbiterC) + RotL64(aOrbiterB, 43U)) + aNonceWordG);
            aWandererA = aWandererA + (((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterB, 54U)) + RotL64(aCarry, 51U)) + aNonceWordK) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 27U) + aOrbiterF) + RotL64(aOrbiterA, 23U));
            //
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + RotL64(aWandererJ, 4U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_c loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneB
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneB, aOperationLaneC, aOperationLaneD, aOperationLaneA
        // cross directions: aWorkLaneB backward forced, aOperationLaneC backward forced, aOperationLaneD backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 30187U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneA[((aIndex + 29295U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 30681U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32282U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 27296U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 30426U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 28527U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 40U) + RotL64(aPrevious, 13U)) ^ (RotL64(aCarry, 27U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterA = ((aWandererC + RotL64(aScatter, 24U)) + RotL64(aCarry, 41U)) + 1210605127156905516U;
            aOrbiterJ = ((aWandererF + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 11964595428173569519U;
            aOrbiterH = ((((aWandererI + RotL64(aCross, 53U)) + RotL64(aCarry, 5U)) + 16277319029916258482U) + aOrbiterAssignSaltA[(((31U - aIndex) + 12U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = (aWandererE + RotL64(aIngress, 13U)) + 12369497463101824572U;
            aOrbiterC = (((aWandererG + RotL64(aScatter, 3U)) + 6201248574067068202U) + aOrbiterAssignSaltE[((aIndex + 4U)) & S_SALT1]) + aNonceWordL;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 1727477025667206661U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 1404510627789806851U;
            aOrbiterH = RotL64((aOrbiterH * 4810039298122529021U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 6948213591282018925U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6688865181284421478U) ^ aOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12619122841662247279U), 37U);
            //
            aOrbiterG = (((aOrbiterG + aOrbiterC) + 3351130769402360855U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 12681032488906270823U;
            aOrbiterA = RotL64((aOrbiterA * 3680893896579741263U), 51U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 3591412591193726763U) + aNonceWordD;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 16153817571210878589U) ^ aOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4165137036092246349U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 3808228354421006630U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 1427373776207504205U) ^ aOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 4534374093769595531U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (RotL64(aOrbiterA, 26U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aIngress, 56U) + aOrbiterG) + RotL64(aOrbiterH, 10U)) + RotL64(aCarry, 19U)) + aNonceWordI);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 19U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + aWandererUpdateSaltB[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterH, 53U)) + aWandererUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 35U) + aOrbiterA) + RotL64(aOrbiterC, 43U));
            aWandererC = aWandererC + ((((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 5U)) + aNonceWordB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (RotL64(aWandererE, 36U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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

void TwistExpander_Lacrosse_Arx::KDF_A_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xAE690F0902EDB001ULL + 0xFE5161868271446CULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xABABA623164166EDULL + 0xA43EECAA2D895E38ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA2899928E4C0CD7FULL + 0xE40D51BE192210F5ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xE90E3A91CB8D5DB5ULL + 0xF89DAFCFF6010B7BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xABAF386B82EB8C7FULL + 0xD368D51C837C7052ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xBC827F9AACC75F79ULL + 0xD8C034D4CDBE5254ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseC(pNonce * 0xF5BF3BBAF9D12043ULL + 0x91BA55B5324AA4E6ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xA3FACAA0B436D967ULL + 0xB286DA7FAFB59DE0ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xEB9101E247CE774FULL + 0x9659848C899F23F6ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xDB4C916D94323FC3ULL + 0xE31E446C6C8A5506ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xF3F9E02B9AC15345ULL + 0xBF5732DEFBCA5156ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xC9F2796EDD2E6C69ULL + 0x947B5CE7EAF8A313ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xEDEA063A1ACA945FULL + 0xBF6575CA5570B650ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD2EA3AEC9E22D95DULL + 0xE37C27C19341A501ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x9B4C7BDF1DB1E09FULL + 0x9CD2E519E9F056F6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xCBA8FB82D81D6EA5ULL + 0x91503DE3C3A39199ULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aOperationLaneB, aExpandLaneC, aExpandLaneD, aFireLaneA, aWorkLaneA, aFireLaneD, aFireLaneC, aWorkLaneB, aOperationLaneD, aOperationLaneA, aWorkLaneC, aOperationLaneC, aFireLaneB
        // write to: aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // kdf_a_loop_d loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aOperationLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 7202U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneB[((aIndex + 4567U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 6590U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1232U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5117U)) & S_BLOCK1], 37U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 7952U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aIngress, 52U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 3U) + RotL64(aPrevious, 35U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 41U)) + 1952750591494698524U) + aOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = ((((aWandererI + RotL64(aPrevious, 35U)) + RotL64(aCarry, 27U)) + 4488270851303332830U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordO;
            aOrbiterB = ((aWandererA + RotL64(aCross, 54U)) + RotL64(aCarry, 41U)) + 2738763375328927635U;
            aOrbiterK = (((aWandererC + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 6728843649480454340U) + aNonceWordN;
            aOrbiterD = ((aWandererE + RotL64(aIngress, 19U)) + 10490717875258865358U) + aNonceWordG;
            aOrbiterG = (aWandererB + RotL64(aCross, 3U)) + 1429288737812910205U;
            aOrbiterA = ((aWandererF + RotL64(aPrevious, 11U)) + 2761375016998907636U) + aNonceWordE;
            //
            aOrbiterE = (((aOrbiterE + aOrbiterI) + 1088988605204499835U) + aOrbiterUpdateSaltD[((aIndex + 14U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 6829840407300289709U;
            aOrbiterB = RotL64((aOrbiterB * 13101432880030791787U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 9267240337867690471U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8120113021183975703U;
            aOrbiterI = RotL64((aOrbiterI * 14296504593187173107U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 1340980511302566784U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 11874452169979878835U) ^ aOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 8638486178860092537U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 1872314794140971426U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 6013952618696225751U) ^ aOrbiterUpdateSaltC[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 7994863587373565715U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 3644011378086236002U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 8501867691997891731U;
            aOrbiterE = RotL64((aOrbiterE * 7115282675461711509U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 2493546555198066143U) + aNonceWordH;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 5179240189571799179U;
            aOrbiterG = RotL64((aOrbiterG * 1267579130962756135U), 41U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 11273348247858394197U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4577476419423118925U) ^ aNonceWordF;
            aOrbiterD = RotL64((aOrbiterD * 8427261005061162673U), 27U);
            //
            aIngress = RotL64(aOrbiterB, 5U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 41U));
            aIngress = aIngress + RotL64(aOrbiterD, 54U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + (((RotL64(aScatter, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterK) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 54U)) + aOrbiterK) + aNonceWordM);
            aWandererC = aWandererC + ((((RotL64(aPrevious, 53U) + aOrbiterA) + RotL64(aOrbiterI, 41U)) + aNonceWordA) + aWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 19U) + aOrbiterD) + RotL64(aOrbiterB, 13U));
            aWandererB = aWandererB + (((((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterE, 21U)) + RotL64(aCarry, 13U)) + aNonceWordB) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 47U)) + aOrbiterI);
            aWandererF = aWandererF + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterD, 35U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 5U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 58U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 11U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 2
        // ingress from: aWorkLaneA, aExpandLaneC, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aExpandLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneC
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 10735U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 10674U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 16241U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12930U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 11194U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 16332U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCarry, 5U)) ^ (RotL64(aCross, 43U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterK = ((aWandererC + RotL64(aCross, 41U)) + 6069475454765660321U) + aNonceWordB;
            aOrbiterJ = (((aWandererE + RotL64(aScatter, 28U)) + RotL64(aCarry, 39U)) + 11483704742497268068U) + aOrbiterAssignSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + 11055697447388986418U) + aNonceWordL;
            aOrbiterG = ((aWandererF + RotL64(aPrevious, 21U)) + 10897095046039997004U) + aOrbiterAssignSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aIngress, 51U)) + 4731637118230457840U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 11U)) + RotL64(aCarry, 51U)) + 13855839187084986751U) + aNonceWordM;
            aOrbiterF = ((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 5328208115460188239U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 12479538544291412985U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 10740165998792608231U;
            aOrbiterA = RotL64((aOrbiterA * 14046827922294477379U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6492798157284955373U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 13056825957483891921U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14882112110627751751U), 23U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 2068184064919194657U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5656302738780746294U;
            aOrbiterD = RotL64((aOrbiterD * 16493021179127646345U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 11193756120230763294U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 17306750816837208999U) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 7949360041241439741U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12952818800389361804U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 15380412293642628312U) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 2914662289178925547U), 57U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 7706090204767242996U) + aOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 14598802276412649570U) ^ aNonceWordJ;
            aOrbiterF = RotL64((aOrbiterF * 4821408736292041399U), 5U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17819762117328075515U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6481384240915075101U;
            aOrbiterE = RotL64((aOrbiterE * 4836701121865783029U), 11U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 43U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (RotL64(aOrbiterG, 3U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterJ, 35U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 53U) + aOrbiterG) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 39U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterA, 36U));
            aWandererD = aWandererD + ((((RotL64(aCross, 47U) + RotL64(aOrbiterG, 43U)) + aOrbiterE) + RotL64(aCarry, 3U)) + aNonceWordN);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 10U) + RotL64(aOrbiterD, 29U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterK, 57U)) + aNonceWordO);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterK, 23U)) + aWandererUpdateSaltA[((aIndex + 15U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aIngress, 35U) + aOrbiterK) + RotL64(aOrbiterJ, 3U)) + aNonceWordP);
            //
            aCarry = aCarry + (RotL64(aWandererC, 52U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererE, 29U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererF, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 3
        // ingress from: aWorkLaneB, aExpandLaneD, aOperationLaneD
        // ingress directions: aWorkLaneB forward forced, aExpandLaneD forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aExpandLaneB, aOperationLaneA
        // cross directions: aWorkLaneA backward forced, aExpandLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 24204U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((aIndex + 19674U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 24098U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18702U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 20552U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aOperationLaneA[((aIndex + 17492U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 37U)) + (RotL64(aPrevious, 5U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterF = (((aWandererG + RotL64(aIngress, 53U)) + RotL64(aCarry, 13U)) + 15726877954695761686U) + aNonceWordA;
            aOrbiterG = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 39U)) + 14187652171881943587U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 13U)) + 8420423151313882782U) + aNonceWordH;
            aOrbiterJ = ((((aWandererH + RotL64(aPrevious, 27U)) + RotL64(aCarry, 27U)) + 14942322692433259283U) + aOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordF;
            aOrbiterK = (((aWandererK + RotL64(aIngress, 43U)) + 7272331475919796255U) + aOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 5U)) + 154504365041805840U;
            aOrbiterH = (aWandererF + RotL64(aScatter, 20U)) + 17475491222554948786U;
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 5759181483165339605U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 5993060214499322845U;
            aOrbiterD = RotL64((aOrbiterD * 10799489831896153301U), 35U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10901786237875941844U) + aOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17135786595614068473U;
            aOrbiterJ = RotL64((aOrbiterJ * 15923538730142047043U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 5208202073886811165U) + aNonceWordC;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 6821452921018900631U) ^ aNonceWordN;
            aOrbiterC = RotL64((aOrbiterC * 13119330055184115669U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 13348064837402206969U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 8967943922403445136U) ^ aOrbiterUpdateSaltB[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 300168481725373093U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 8130283784171430891U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 6351113882502502876U) ^ aNonceWordD;
            aOrbiterG = RotL64((aOrbiterG * 15960622823993072903U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 6894708729226455769U) + aNonceWordP;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 12065058511247133944U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5432601727436935831U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 17138279326229372741U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 12987698199066890628U;
            aOrbiterF = RotL64((aOrbiterF * 12665716655177320977U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterH, 27U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 41U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((RotL64(aScatter, 50U) + RotL64(aOrbiterJ, 11U)) + aOrbiterK);
            aWandererF = aWandererF ^ ((((RotL64(aPrevious, 35U) + aOrbiterC) + RotL64(aOrbiterH, 48U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aIngress, 57U) + RotL64(aOrbiterJ, 27U)) + aOrbiterC);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterJ, 19U)) + aOrbiterG);
            aWandererK = aWandererK + (((RotL64(aPrevious, 29U) + RotL64(aOrbiterG, 39U)) + aOrbiterD) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ ((((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterC, 57U)) + aNonceWordI) + aWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererE = aWandererE + ((((RotL64(aIngress, 11U) + aOrbiterF) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 51U)) + aNonceWordK);
            //
            aCarry = aCarry + (RotL64(aWandererI, 18U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererE, 27U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // kdf_a_loop_d loop 4
        // ingress from: aWorkLaneC, aWorkLaneA, aOperationLaneC
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aWorkLaneB, aExpandLaneC, aFireLaneB
        // cross directions: aWorkLaneB backward forced, aExpandLaneC backward forced, aFireLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 25119U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneA[((aIndex + 30094U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 25275U)) & S_BLOCK1], 44U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 31678U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32766U)) & S_BLOCK1], 26U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 26947U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 41U)) ^ (RotL64(aPrevious, 56U) + RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = ((aWandererH + RotL64(aIngress, 35U)) + 7075016829833562104U) + aNonceWordG;
            aOrbiterD = ((((aWandererK + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 8783765886115517036U) + aOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordA;
            aOrbiterH = (((aWandererF + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 2996723892384565829U) + aOrbiterAssignSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 9494134707342189476U) + aNonceWordH;
            aOrbiterF = (aWandererC + RotL64(aIngress, 54U)) + 5052642981395679904U;
            aOrbiterC = (aWandererD + RotL64(aScatter, 19U)) + 8766787055127962238U;
            aOrbiterJ = (aWandererI + RotL64(aCross, 13U)) + 4467211954388738079U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 8030255604633658608U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 16962408063455702251U;
            aOrbiterH = RotL64((aOrbiterH * 11171737929747471631U), 29U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 3768222186567699076U) + aNonceWordN;
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 14930990410207899871U) ^ aOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10930005786146268241U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 14179761938395502502U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 1879084742719898108U) ^ aOrbiterUpdateSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16783034788172670121U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 5535012408925981515U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 12792553516710295939U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 8577530993755159329U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 8979253163346099252U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 5559189896063990740U;
            aOrbiterJ = RotL64((aOrbiterJ * 8832485423727331621U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 13937564337299044079U) + aNonceWordC;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 2393376759689394948U) ^ aOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2352815657830413941U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 12647519563697356479U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 10946871249960389549U) ^ aNonceWordL;
            aOrbiterK = RotL64((aOrbiterK * 6272580371881237173U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterH, 4U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 11U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 35U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 21U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aIngress, 3U) + aOrbiterA) + RotL64(aOrbiterJ, 52U)) + RotL64(aCarry, 35U)) + aNonceWordI);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 29U) + RotL64(aOrbiterJ, 37U)) + aOrbiterC) + aWandererUpdateSaltB[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 13U)) + aOrbiterK) + aWandererUpdateSaltE[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterF, 21U)) + aNonceWordF);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 27U)) + RotL64(aCarry, 23U)) + aNonceWordD);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterF, 3U)) + aOrbiterH);
            aWandererH = aWandererH + ((RotL64(aCross, 10U) + aOrbiterD) + RotL64(aOrbiterA, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 11U) ^ aWandererB);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 34U));
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 5U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_A(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x843803385B2A2CDBULL + 0xB3F9AC1D0B34FDC2ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0x9389F5E42A39D877ULL + 0xCA4FA710E0858B42ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xD4441272A9B88CBBULL + 0xAC047FF67FDE83CBULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xD4BF7B134A5BBAEFULL + 0xBB987BE0FCEA2952ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xCB640875DB00342DULL + 0xBFC94F4DA1043819ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB35CD660CD599CFBULL + 0xD07DC7F4B067867AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD3C571E5EA53DE1BULL + 0xA12536CF936AF5D7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x8233924D4B134167ULL + 0xA794C0F4EE22058FULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xFB0772E3D0A99E23ULL + 0xE76C230F2D6085CDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF734FD5F764FC209ULL + 0xC1BBB6C185388BD6ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF651D652962EC6F9ULL + 0xA179E4034BB425A5ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xFC4ED775D40D3751ULL + 0x8FAA93F6B8B8C311ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9CD2F02260BD45DBULL + 0xD07EC9C5C0BE28DAULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xD32E6BB0B5593857ULL + 0xC95A2A34E0A2D725ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xD89DC7A8603FB307ULL + 0xBC84B2A67C05C9A2ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseA(pNonce * 0xD67DF65EBB97BD41ULL + 0xC517DB3653BEEC81ULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aFireLaneD, aWorkLaneC, aWorkLaneD, aFireLaneC, aExpandLaneA, aOperationLaneD, aOperationLaneB, aExpandLaneB, aFireLaneB, aOperationLaneA, aExpandLaneC, aOperationLaneC, aFireLaneA
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_a loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aFireLaneD
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aFireLaneD forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aFireLaneC
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 5436U)) & S_BLOCK1], 48U) ^ RotL64(aWorkLaneB[((aIndex + 6381U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 3840U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 3374U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1152U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 5162U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCarry, 23U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererK + RotL64(aCross, 5U)) + 18144572925667544139U) + aNonceWordI;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 41U)) + RotL64(aCarry, 11U)) + 5659758077574059728U) + aOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterD = (((aWandererJ + RotL64(aIngress, 23U)) + RotL64(aCarry, 53U)) + 6343330616999166392U) + aNonceWordL;
            aOrbiterH = (aWandererI + RotL64(aScatter, 58U)) + 17754639838410839447U;
            aOrbiterI = ((aWandererC + RotL64(aCross, 51U)) + RotL64(aCarry, 29U)) + 9451843819849581729U;
            aOrbiterJ = ((aWandererE + RotL64(aScatter, 29U)) + 7957854457197462212U) + aNonceWordC;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 11U)) + 1461994799722205010U) + aOrbiterAssignSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 18002214276252170177U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 14689869073147027164U;
            aOrbiterD = RotL64((aOrbiterD * 12242482963989582191U), 11U);
            //
            aOrbiterH = (((aOrbiterH + aOrbiterI) + 3978104368003440293U) + aOrbiterUpdateSaltB[((aIndex + 11U)) & S_SALT1]) + aNonceWordH;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 8512135845221335386U;
            aOrbiterF = RotL64((aOrbiterF * 10506667163729414667U), 47U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterJ) + 1477533446382953439U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordO;
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 2166717790929947990U;
            aOrbiterI = RotL64((aOrbiterI * 6538884492418324461U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 8082437060686606995U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4363687722464700362U;
            aOrbiterK = RotL64((aOrbiterK * 7199165810993478887U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 15782763348014924206U) + aOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 8572509150015960728U;
            aOrbiterJ = RotL64((aOrbiterJ * 3340528604891897779U), 37U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 12248271773316742521U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 9602078627638561949U;
            aOrbiterH = RotL64((aOrbiterH * 1860631869877427405U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 17244849374768558859U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1030743048280579012U) ^ aOrbiterUpdateSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10858949914285817051U), 5U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterF, 3U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 19U));
            aIngress = aIngress + RotL64(aOrbiterC, 57U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF) + RotL64(aCarry, 29U)) + aNonceWordP);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterC, 13U)) + aWandererUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterK, 43U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 58U) + aOrbiterK) + RotL64(aOrbiterF, 36U)) + aNonceWordN);
            aWandererH = aWandererH + ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterK, 27U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 19U)) + aOrbiterH) + aWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aPrevious, 3U) + aOrbiterD) + RotL64(aOrbiterF, 51U));
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 38U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererH, 27U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 13U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aOperationLaneD
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aOperationLaneD forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneB
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 10699U)) & S_BLOCK1], 50U) ^ RotL64(aWorkLaneC[((aIndex + 12455U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aOperationLaneD[((aIndex + 15011U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 11427U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 10254U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 13458U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 23U)) + (RotL64(aCross, 43U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererF + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 1708250618750199233U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 26U)) + RotL64(aCarry, 5U)) + 12009147777553691142U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 19U)) + 8393982703399156592U) + aOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = ((((aWandererA + RotL64(aScatter, 5U)) + RotL64(aCarry, 41U)) + 3247327098356831221U) + aOrbiterAssignSaltE[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aWandererJ + RotL64(aCross, 41U)) + 3403590155376353737U;
            aOrbiterE = (aWandererK + RotL64(aScatter, 35U)) + 18197244558104735044U;
            aOrbiterA = ((aWandererE + RotL64(aIngress, 51U)) + 3096253642040701606U) + aNonceWordK;
            //
            aOrbiterI = (((aOrbiterI + aOrbiterK) + 8012692688785412179U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 17531946907545680745U;
            aOrbiterH = RotL64((aOrbiterH * 16510602981731506381U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 17687695944270225817U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16147773866007628769U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16926442582711557877U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 18244641303026196497U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 8839160526348897457U;
            aOrbiterE = RotL64((aOrbiterE * 14268021129087663397U), 21U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 10599266240854068246U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 2056723540756216155U;
            aOrbiterA = RotL64((aOrbiterA * 13311591601230386375U), 3U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 4629354220460621284U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 9505955649473204942U;
            aOrbiterK = RotL64((aOrbiterK * 17775391885312236187U), 29U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 17078153810088721310U) + aNonceWordD;
            aOrbiterI = ((aOrbiterI ^ aOrbiterE) ^ 9470436761716263000U) ^ aNonceWordA;
            aOrbiterI = RotL64((aOrbiterI * 5431855497250357229U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 3305863413630104742U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 14377172434239576161U;
            aOrbiterJ = RotL64((aOrbiterJ * 6880176890091033423U), 41U);
            //
            aIngress = RotL64(aOrbiterE, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterC, 42U)) + aOrbiterI);
            aWandererA = aWandererA + (((RotL64(aIngress, 26U) + aOrbiterH) + RotL64(aOrbiterA, 11U)) + aNonceWordL);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 3U)) + aOrbiterJ);
            aWandererD = aWandererD + (((RotL64(aCross, 57U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((((RotL64(aScatter, 5U) + aOrbiterA) + RotL64(aOrbiterI, 29U)) + aNonceWordH) + aWandererUpdateSaltB[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + RotL64(aCarry, 43U));
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterI, 23U)) + aOrbiterK) + aWandererUpdateSaltF[((aIndex + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererI, 30U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 51U));
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aOperationLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aOperationLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 16758U)) & S_BLOCK1], 29U) ^ RotL64(aWorkLaneD[((aIndex + 21085U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 22854U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 19371U)) & S_BLOCK1], 57U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 20120U)) & S_BLOCK1], 43U));
            aCross ^= RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19676U)) & S_BLOCK1], 26U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 41U)) + (RotL64(aPrevious, 12U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterA = (aWandererG + RotL64(aPrevious, 3U)) + 8367680518550579791U;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 11U)) + RotL64(aCarry, 37U)) + 11491674725611181241U;
            aOrbiterJ = (aWandererD + RotL64(aCross, 39U)) + 16673861720782164214U;
            aOrbiterK = ((((aWandererJ + RotL64(aScatter, 47U)) + RotL64(aCarry, 53U)) + 9786610124108350855U) + aOrbiterAssignSaltB[((aIndex + 18U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = ((((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 3U)) + 5745080601557577637U) + aOrbiterAssignSaltA[((aIndex + 21U)) & S_SALT1]) + aNonceWordG;
            aOrbiterB = ((aWandererC + RotL64(aPrevious, 26U)) + 1959402215131684684U) + aNonceWordJ;
            aOrbiterI = (aWandererF + RotL64(aScatter, 53U)) + 6121650036079196522U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 12016309761037342392U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterA) ^ 5986936646177049603U) ^ aNonceWordK;
            aOrbiterJ = RotL64((aOrbiterJ * 3585650475703294895U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 1000367700904043468U) + aNonceWordI;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 17425288243569101032U;
            aOrbiterK = RotL64((aOrbiterK * 2174614006719048535U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 4856917474950325209U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16312111093223166419U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11046477664487805241U), 27U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 456110002032422270U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11393724374787795662U;
            aOrbiterB = RotL64((aOrbiterB * 1176984359123668389U), 37U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 8378176867715697176U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 8086186452345234815U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 8450438271765985235U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 8470349167474173245U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 2528229938740192694U;
            aOrbiterC = RotL64((aOrbiterC * 8717790851266520943U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 13247168811545753141U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 8745293957516815264U;
            aOrbiterA = RotL64((aOrbiterA * 14270617180621072619U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterB, 57U);
            aIngress = aIngress + (RotL64(aOrbiterC, 20U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterJ, 43U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterK, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterK, 21U)) + aOrbiterD) + aWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 53U) + aOrbiterJ) + RotL64(aOrbiterB, 11U)) + RotL64(aCarry, 37U)) + aNonceWordO) + aWandererUpdateSaltD[((aIndex + 15U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 47U) + aOrbiterI) + RotL64(aOrbiterC, 42U)) + aNonceWordM);
            aWandererD = aWandererD + (((RotL64(aCross, 11U) + aOrbiterC) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 13U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterJ, 35U)) + aOrbiterK) + aNonceWordB);
            aWandererK = aWandererK + (((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 57U)) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 20U) + RotL64(aOrbiterA, 51U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 29U));
            aCarry = aCarry + (RotL64(aWandererC, 23U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + RotL64(aWandererF, 51U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_a loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aOperationLaneC
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aOperationLaneC forward/backward random
        // cross from: aExpandLaneB, aWorkLaneC, aFireLaneA
        // cross directions: aExpandLaneB backward forced, aWorkLaneC backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25574U)) & S_BLOCK1], 40U) ^ RotL64(aExpandLaneA[((aIndex + 28765U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneC[((aIndex + 26650U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordO));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31758U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 31664U)) & S_BLOCK1], 47U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 28612U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 36U)) ^ (RotL64(aCarry, 51U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterH = ((aWandererH + RotL64(aIngress, 47U)) + 9654059367478508868U) + aNonceWordC;
            aOrbiterI = (((aWandererE + RotL64(aPrevious, 23U)) + RotL64(aCarry, 41U)) + 6473006635864677427U) + aNonceWordN;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 41U)) + RotL64(aCarry, 3U)) + 6944184481315853243U) + aOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterG = (aWandererB + RotL64(aCross, 53U)) + 4061496421939102306U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 35U)) + 15791809275719085463U) + aNonceWordF;
            aOrbiterB = ((aWandererK + RotL64(aIngress, 6U)) + 14050798802646323055U) + aNonceWordI;
            aOrbiterD = (((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 23U)) + 12072905924741758266U) + aOrbiterAssignSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterI) + 17639076509231343896U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 12195388285571234715U;
            aOrbiterA = RotL64((aOrbiterA * 4317060502521195769U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 4325404419499496529U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5910567888204238382U;
            aOrbiterB = RotL64((aOrbiterB * 11503787177122206937U), 41U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 13092940059929942699U) + aNonceWordK;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13381962590820308761U;
            aOrbiterD = RotL64((aOrbiterD * 6345904465930943295U), 57U);
            //
            aOrbiterD = (((aOrbiterD + aOrbiterG) + 15622862439323440527U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14027151901132249793U;
            aOrbiterE = RotL64((aOrbiterE * 2273573821630510087U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4584410023907605157U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 15763755180625487157U;
            aOrbiterG = RotL64((aOrbiterG * 6755736130607297639U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17023059745666559199U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5298529579288492971U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 2483562793328357721U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2870152867331654736U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterE) ^ 12017191100173748848U) ^ aOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1]) ^ aNonceWordB;
            aOrbiterH = RotL64((aOrbiterH * 9958191466506480519U), 27U);
            //
            aIngress = RotL64(aOrbiterG, 57U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 43U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterA, 50U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 57U)) + aOrbiterB);
            aWandererI = aWandererI + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 43U)) + aOrbiterG) + RotL64(aCarry, 35U)) + aNonceWordM);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterA, 3U)) + aOrbiterI) + aWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 57U) + RotL64(aOrbiterI, 23U)) + aOrbiterD) + RotL64(aCarry, 53U)) + aNonceWordE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + RotL64(aOrbiterG, 10U)) + aOrbiterA) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 51U)) + aOrbiterB) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 12U) + RotL64(aOrbiterE, 37U)) + aOrbiterB);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 11U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 36U));
            aCarry = aCarry + (RotL64(aWandererH, 41U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 19U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCB48C8DAF96C7A09ULL + 0xC42BD424EBF62A0BULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0x94FE6D9751EEAAD3ULL + 0x86294D89BFCD5225ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA11AD84E431999E5ULL + 0x94614558D02A2587ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE045D1AC4ED78261ULL + 0xCA9E415A04F73330ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xF4BE731A1FBC3CE5ULL + 0xE2702A46F5C32196ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xB8976623A40F3355ULL + 0xD23C92999BA38714ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x984B28E0EB3FB851ULL + 0xAE15131B3C94B9F7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB114C2E80BD98F7FULL + 0xC0A37DA9EA117FFAULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0x98A13588716B5793ULL + 0x8AF1A3D7ACF86045ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xFA2071E87D9EF04BULL + 0xA6FD99416C0E4C8EULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x93E2EA8E40AAC475ULL + 0xA15252ECBB309EADULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xAF954F8C8C6EA5D3ULL + 0xE698C0DD94359877ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB328AFBB424187EFULL + 0xC9C0BC40EF501FABULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0x89EFB928AED1736DULL + 0xE800C7EE306E0241ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xB79E26CA1D19837FULL + 0xC37C4B523B099F2BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xEA8F31F701A98C43ULL + 0xF78C49F7A672CB3DULL);
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aWorkLaneC, aOperationLaneA, aFireLaneC, aFireLaneA, aOperationLaneB, aWorkLaneA, aWorkLaneB, aOperationLaneC, aWorkLaneD, aFireLaneD
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 4320U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneB[((aIndex + 4971U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 7678U)) & S_BLOCK1], 18U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 6005U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 4439U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 6164U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 19U) + RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 50U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterG = ((aWandererH + RotL64(aIngress, 35U)) + 5171470532667965920U) + aNonceWordB;
            aOrbiterJ = (aWandererI + RotL64(aCross, 21U)) + 750549462358682403U;
            aOrbiterC = ((((aWandererE + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 3325689257577120525U) + aOrbiterAssignSaltE[(((31U - aIndex) + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterD = ((aWandererA + RotL64(aPrevious, 23U)) + 18031575461559790826U) + aOrbiterAssignSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aCross, 3U)) + 13874739537012288677U;
            aOrbiterF = ((aWandererC + RotL64(aIngress, 26U)) + RotL64(aCarry, 43U)) + 4250029868785016865U;
            aOrbiterI = ((aWandererG + RotL64(aPrevious, 19U)) + RotL64(aCarry, 37U)) + 8211158803112611161U;
            aOrbiterK = ((aWandererD + RotL64(aScatter, 11U)) + 1083939790236786027U) + aNonceWordG;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 57U)) + 3446525462376962464U) + aNonceWordM;
            aOrbiterB = (aWandererK + RotL64(aIngress, 28U)) + 6973817815000417325U;
            aOrbiterA = (aWandererB + RotL64(aPrevious, 13U)) + 15230876489676945543U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 9359727659738755880U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 8775170107816327654U) ^ aOrbiterUpdateSaltE[((aIndex + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6910680458261008653U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterG) + 11958941755525038545U) + aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 16966819714283167348U;
            aOrbiterH = RotL64((aOrbiterH * 16363457661846050749U), 29U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 14556087985619763243U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17915047508377045221U;
            aOrbiterF = RotL64((aOrbiterF * 6727635453185130109U), 23U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 8578745677485367222U) + aNonceWordO;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 7002181668717618866U;
            aOrbiterK = RotL64((aOrbiterK * 12329703532414955235U), 37U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 3569939503066735457U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 2956247934282522184U;
            aOrbiterI = RotL64((aOrbiterI * 9946650822131152531U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 4285180013402474041U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 5976239869535619811U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 3458095419039067465U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 2424524955161695463U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6849595426583763537U;
            aOrbiterE = RotL64((aOrbiterE * 12727902040238318101U), 27U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 11414890686374886716U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 5668287266836153445U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 8011885266143066285U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 9976985606260445887U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterI) ^ 9223940029500676834U) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 8508023992488499955U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 4480967907876921958U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 5132766654502526597U;
            aOrbiterD = RotL64((aOrbiterD * 321625389942019245U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 12921555132452983464U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5171470532667965920U;
            aOrbiterG = RotL64((aOrbiterG * 9710487797420618879U), 51U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterI, 22U);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (RotL64(aOrbiterC, 11U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 37U) + aOrbiterK) + RotL64(aOrbiterI, 27U)) + aWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 53U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aIngress, 4U) + aOrbiterK) + RotL64(aOrbiterH, 60U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterG, 11U));
            aWandererH = aWandererH + ((((RotL64(aScatter, 43U) + RotL64(aOrbiterF, 23U)) + aOrbiterC) + RotL64(aCarry, 5U)) + aWandererUpdateSaltC[((aIndex + 9U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aCross, 23U) + RotL64(aOrbiterF, 29U)) + aOrbiterI) + aNonceWordF);
            aWandererI = aWandererI + (((RotL64(aIngress, 41U) + RotL64(aOrbiterB, 46U)) + aOrbiterA) + RotL64(aCarry, 19U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 51U) + aOrbiterE) + RotL64(aOrbiterG, 53U));
            aWandererC = aWandererC + (((RotL64(aScatter, 39U) + aOrbiterA) + RotL64(aOrbiterD, 43U)) + aNonceWordP);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aNonceWordL);
            aWandererK = aWandererK + (((RotL64(aPrevious, 14U) + RotL64(aOrbiterB, 19U)) + aOrbiterG) + aNonceWordJ);
            //
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererD, 21U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererF, 12U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererG, 53U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 47U));
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 2
        // ingress from: aOperationLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aOperationLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward forced, aFireLaneA backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 8552U)) & S_BLOCK1], 41U) ^ RotL64(aExpandLaneC[((aIndex + 12579U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 15597U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8532U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8727U)) & S_BLOCK1], 23U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 11558U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 27U)) + (RotL64(aCross, 56U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterD = (aWandererH + RotL64(aIngress, 47U)) + 14214886793361825363U;
            aOrbiterK = ((aWandererD + RotL64(aCross, 20U)) + 17267959031078766320U) + aNonceWordP;
            aOrbiterB = (aWandererA + RotL64(aPrevious, 51U)) + 16436067429484887644U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 39U)) + 9885951769332633820U) + aNonceWordM;
            aOrbiterH = (aWandererK + RotL64(aCross, 57U)) + 12971711341813893304U;
            aOrbiterF = (aWandererF + RotL64(aIngress, 13U)) + 199970353398450154U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 26U)) + 1237341696444162094U;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 5U)) + RotL64(aCarry, 47U)) + 7991128854417613360U) + aNonceWordC;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 3U)) + 14809029847149045833U;
            aOrbiterC = (((aWandererJ + RotL64(aScatter, 11U)) + RotL64(aCarry, 19U)) + 2559509556915775947U) + aOrbiterAssignSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterI = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 14336829730147834160U) + aOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8853631886733610440U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 13346159398673246914U;
            aOrbiterB = RotL64((aOrbiterB * 13660497151446983393U), 53U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 12121095718571872976U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterG) ^ 16239781125815589804U) ^ aOrbiterUpdateSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5157009090454962231U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 9051377033794324106U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13805815136723461780U;
            aOrbiterE = RotL64((aOrbiterE * 571129481747181357U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 14849157800322754413U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 18116651528452542634U;
            aOrbiterJ = RotL64((aOrbiterJ * 3638480428016835537U), 35U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 4105057226952948599U) + aOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5911714320560994391U;
            aOrbiterA = RotL64((aOrbiterA * 1796514171654961389U), 39U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 4439149331729987587U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 10278532228230163632U;
            aOrbiterG = RotL64((aOrbiterG * 17428224919864716517U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 2342456582668741750U) + aNonceWordK;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 2360578572554664800U;
            aOrbiterI = RotL64((aOrbiterI * 1108428466956691925U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 12132934875391401246U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 17213278726790245812U;
            aOrbiterF = RotL64((aOrbiterF * 11904899990681410419U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7994340481560109811U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13735851271080138255U;
            aOrbiterD = RotL64((aOrbiterD * 12387076892129731557U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 6682417543888875268U) + aOrbiterUpdateSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 15642799286975840550U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 7861250716882028053U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9839299346094784067U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14214886793361825363U;
            aOrbiterH = RotL64((aOrbiterH * 2103132743364916037U), 11U);
            //
            aIngress = RotL64(aOrbiterJ, 27U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 21U));
            aIngress = aIngress + (RotL64(aOrbiterK, 10U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterD, 53U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aScatter, 60U) + RotL64(aOrbiterE, 50U)) + aOrbiterH);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aWandererUpdateSaltD[((aIndex + 12U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aIngress, 43U) + RotL64(aOrbiterG, 37U)) + aOrbiterB);
            aWandererK = aWandererK ^ ((((RotL64(aPrevious, 21U) + RotL64(aOrbiterI, 21U)) + aOrbiterA) + aNonceWordN) + aWandererUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterA, 13U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 19U) + aOrbiterF) + RotL64(aOrbiterK, 39U)) + aNonceWordI);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterF, 11U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterF, 58U)) + aOrbiterD) + aNonceWordH);
            aWandererH = aWandererH + ((((RotL64(aIngress, 37U) + RotL64(aOrbiterJ, 23U)) + aOrbiterE) + RotL64(aCarry, 19U)) + aNonceWordJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterF, 43U)) + aOrbiterA);
            aWandererB = aWandererB + (((RotL64(aScatter, 23U) + RotL64(aOrbiterH, 47U)) + aOrbiterF) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 39U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 26U) ^ aWandererH);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 21U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 37U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 3
        // ingress from: aOperationLaneB, aExpandLaneD, aWorkLaneA
        // ingress directions: aOperationLaneB forward forced, aExpandLaneD forward forced, aWorkLaneA forward/backward random
        // cross from: aOperationLaneA, aExpandLaneB, aWorkLaneB
        // cross directions: aOperationLaneA backward forced, aExpandLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aOperationLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23167U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneD[((aIndex + 23049U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23533U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordI));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 19375U)) & S_BLOCK1], 48U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 22038U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 16473U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 36U) + RotL64(aCross, 23U)) ^ (RotL64(aPrevious, 53U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 57U)) + 3621877681473089725U) + aNonceWordG;
            aOrbiterA = (aWandererG + RotL64(aPrevious, 29U)) + 4451752751536414717U;
            aOrbiterJ = ((aWandererC + RotL64(aScatter, 27U)) + 11371625415377772117U) + aNonceWordD;
            aOrbiterD = ((aWandererA + RotL64(aIngress, 39U)) + RotL64(aCarry, 5U)) + 6046792758881150619U;
            aOrbiterE = ((aWandererH + RotL64(aCross, 3U)) + RotL64(aCarry, 57U)) + 8213166120394461682U;
            aOrbiterK = (aWandererD + RotL64(aIngress, 10U)) + 4343156661140422645U;
            aOrbiterF = (aWandererI + RotL64(aPrevious, 47U)) + 11105271483234947905U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 348904609985341372U) + aNonceWordO;
            aOrbiterC = (aWandererF + RotL64(aIngress, 13U)) + 12924652822526858767U;
            aOrbiterB = (((aWandererK + RotL64(aCross, 23U)) + 7461211697358520287U) + aOrbiterAssignSaltA[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordL;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 42U)) + 16551553555297890558U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 11908056404140782995U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 9147367258259948715U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 10777628928376261667U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 8876461054692728610U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 10546855952702525404U;
            aOrbiterG = RotL64((aOrbiterG * 10071104785895309677U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 4748636139110443794U) + aOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 783046909529525098U;
            aOrbiterF = RotL64((aOrbiterF * 8969157702460927215U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 16683965945838696665U) + aNonceWordM;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 12385412690177109575U;
            aOrbiterC = RotL64((aOrbiterC * 10795062772707143187U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 8210546822184469023U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 13146493623236979963U;
            aOrbiterB = RotL64((aOrbiterB * 13199947810161148155U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 13857628148804187115U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 7241297989337473475U) ^ aOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 16223448508809614229U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 773904571213804946U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 7660676598236419707U;
            aOrbiterI = RotL64((aOrbiterI * 14467390638468925567U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 16822672435156055469U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 6514707119190640433U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 7097496727567460535U), 41U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 17784153215885060832U;
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 16027189961519690419U;
            aOrbiterD = RotL64((aOrbiterD * 3248782394761733169U), 23U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterD) + 821916530432611671U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 8764650990196504963U;
            aOrbiterH = RotL64((aOrbiterH * 6269514974278082251U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 5987370764866753332U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3621877681473089725U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 14763908964222787377U), 53U);
            //
            aIngress = RotL64(aOrbiterH, 60U) ^ aOrbiterC;
            aIngress = aIngress + (RotL64(aOrbiterG, 13U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 47U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterE, 21U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aCross, 6U) + aOrbiterK) + RotL64(aOrbiterA, 29U)) + aNonceWordH);
            aWandererJ = aWandererJ + ((RotL64(aScatter, 23U) + RotL64(aOrbiterJ, 3U)) + aOrbiterC);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterI, 41U)) + aNonceWordK);
            aWandererC = aWandererC + ((RotL64(aIngress, 11U) + RotL64(aOrbiterA, 56U)) + aOrbiterE);
            aWandererI = aWandererI ^ ((RotL64(aCross, 41U) + aOrbiterK) + RotL64(aOrbiterH, 35U));
            aWandererK = aWandererK + ((RotL64(aPrevious, 39U) + aOrbiterF) + RotL64(aOrbiterI, 27U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterH, 21U)) + aOrbiterC);
            aWandererB = aWandererB + (((RotL64(aScatter, 37U) + aOrbiterB) + RotL64(aOrbiterK, 19U)) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterD, 23U)) + aNonceWordB);
            aWandererF = aWandererF + (((((RotL64(aPrevious, 60U) + RotL64(aOrbiterG, 39U)) + aOrbiterJ) + RotL64(aCarry, 29U)) + aNonceWordP) + aWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 21U) + RotL64(aOrbiterC, 48U)) + aOrbiterB) + aWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 56U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererH, 29U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (RotL64(aWandererK, 37U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererB, 54U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aOperationLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_b loop 4
        // ingress from: aOperationLaneC, aOperationLaneA, aWorkLaneD
        // ingress directions: aOperationLaneC forward forced, aOperationLaneA forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneB, aExpandLaneC, aFireLaneD
        // cross directions: aOperationLaneB backward forced, aExpandLaneC backward forced, aFireLaneD backward/forward random
        // write to: aOperationLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29127U)) & S_BLOCK1], 18U) ^ RotL64(aOperationLaneA[((aIndex + 31736U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 26530U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31876U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 27921U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 32065U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 41U) ^ RotL64(aCross, 11U)) + (RotL64(aCarry, 23U) + RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterD = ((aWandererH + RotL64(aScatter, 50U)) + 12809562813316740345U) + aNonceWordB;
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 29U)) + RotL64(aCarry, 57U)) + 17084212535326321199U;
            aOrbiterE = ((aWandererF + RotL64(aCross, 11U)) + 16074921689983846769U) + aNonceWordG;
            aOrbiterJ = (aWandererK + RotL64(aIngress, 21U)) + 14027986153007120145U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 35U)) + 7633455951809250227U) + aNonceWordC;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 43U)) + 340989348513370174U;
            aOrbiterH = (((aWandererE + RotL64(aScatter, 41U)) + RotL64(aCarry, 37U)) + 5307820377645020116U) + aOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 19U)) + 5605285015771527274U) + aOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterI = (aWandererJ + RotL64(aIngress, 3U)) + 5293500434746182790U;
            aOrbiterG = (aWandererA + RotL64(aCross, 57U)) + 7263156475892261811U;
            aOrbiterC = (aWandererI + RotL64(aScatter, 26U)) + 10672879570907433005U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterB) + 16659226780900986107U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterD) ^ 9774892622769850665U) ^ aOrbiterUpdateSaltA[((aIndex + 4U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 10728057184108279042U) + aOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 5032485856947407217U;
            aOrbiterK = RotL64((aOrbiterK * 16651577903809154285U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14642241075374862345U) + aNonceWordJ;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 8386481273395203518U;
            aOrbiterH = RotL64((aOrbiterH * 11649977733867003445U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 2874153265304098104U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 11519900149177261000U;
            aOrbiterA = RotL64((aOrbiterA * 2010158758971864505U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterH) + 8885690878540115768U) + aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 4482143389870987714U;
            aOrbiterG = RotL64((aOrbiterG * 7105332459437434281U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 17469068567801886615U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5121422018622394837U;
            aOrbiterC = RotL64((aOrbiterC * 14823827133212643467U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 3130788210672745618U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 6139244627510113216U;
            aOrbiterF = RotL64((aOrbiterF * 2640754184921507389U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 10488511756324474710U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 1760223670304953696U;
            aOrbiterD = RotL64((aOrbiterD * 4007062295003769311U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 2232708414171096783U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17497492434939621063U;
            aOrbiterJ = RotL64((aOrbiterJ * 9850565931511937725U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8199114561613022892U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 15432482434863050835U;
            aOrbiterB = RotL64((aOrbiterB * 14271143436318169871U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 14991531324947777062U;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 12809562813316740345U;
            aOrbiterI = RotL64((aOrbiterI * 4487021480964944879U), 5U);
            //
            aIngress = RotL64(aOrbiterF, 21U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterI, 35U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 18U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 47U));
            aIngress = aIngress + (RotL64(aOrbiterA, 13U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterE, 5U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 34U) + RotL64(aOrbiterB, 29U)) + aOrbiterC) + aNonceWordA) + aWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 60U)) + aOrbiterG) + RotL64(aCarry, 41U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterA, 3U));
            aWandererD = aWandererD + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererB = aWandererB ^ (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 39U)) + aOrbiterD) + aNonceWordD);
            aWandererG = aWandererG + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterH, 42U)) + aOrbiterK);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 41U) + aOrbiterC) + RotL64(aOrbiterF, 51U)) + aWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aCross, 44U) + RotL64(aOrbiterI, 53U)) + aOrbiterE) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 21U) + RotL64(aOrbiterH, 27U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aIngress, 27U) + aOrbiterK) + RotL64(aOrbiterF, 57U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterI, 11U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 46U));
            aCarry = aCarry + (RotL64(aWandererH, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 13U));
            aCarry = aCarry + (RotL64(aWandererD, 30U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 43U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Lacrosse_Arx::KDF_B_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xADA1BD0D18043B45ULL + 0xD06D5D946A4E9BEAULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0x9FEEC137B4C81911ULL + 0xF7A126DC3A33F921ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC1E1BF06EE3C67F3ULL + 0xEAC3BF2049B0D449ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xA780587D45C013D1ULL + 0xBAC8A31A6D6EE70AULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xCF2F9E2FE0FE4B69ULL + 0xCE9F2923096263D5ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xB1278F6A95F2ED97ULL + 0xC2FDD1DF4F5A23F9ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0x9B425EAD7638EF33ULL + 0xA9E55B54F146FF80ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0x834D7237DAAABC93ULL + 0xF9489B46E1CBBDF2ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xF2BD9E3DBFCCEB23ULL + 0x9F660A6204747D42ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xF4958FE413D6872DULL + 0x907DF7C33297D058ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xFFF2094AED86EE8FULL + 0xBB46144863C2FC9BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xABAC8D54BD8DCC03ULL + 0xAF643F2B4ADBC9E4ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xF7BD3B8A9A992725ULL + 0xEB72C8F83E6F3677ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xE3F7A1A5712E317DULL + 0xB055006977B10355ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xF8D2A5F32615FECDULL + 0xBFB6645C0CFABB81ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xAA8FFFD18BBDF48FULL + 0xD1BBA24C87E20970ULL);
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
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneD, aOperationLaneC, aOperationLaneD, aWorkLaneC, aExpandLaneA, aFireLaneD, aFireLaneA, aExpandLaneB, aFireLaneB, aWorkLaneB, aExpandLaneC, aWorkLaneA, aFireLaneC
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aWorkLaneC
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aWorkLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 7828U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneB[((aIndex + 2696U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 1716U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 297U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 4705U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aWorkLaneC[((aIndex + 5962U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 39U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = (aWandererA + RotL64(aIngress, 47U)) + 16424657151168221875U;
            aOrbiterC = ((aWandererB + RotL64(aCross, 56U)) + 17150123681886380361U) + aNonceWordB;
            aOrbiterK = ((aWandererK + RotL64(aPrevious, 19U)) + 16041993588694572757U) + aOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterA = ((aWandererG + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 9871185846434828537U;
            aOrbiterB = (aWandererI + RotL64(aCross, 11U)) + 11227236398354430757U;
            aOrbiterF = (((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 3U)) + 5399325217402192631U) + aNonceWordP;
            aOrbiterH = (aWandererH + RotL64(aScatter, 27U)) + 9248828789282890454U;
            aOrbiterJ = (((aWandererJ + RotL64(aPrevious, 51U)) + 9041370494203701062U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordE;
            aOrbiterI = ((aWandererF + RotL64(aCross, 38U)) + RotL64(aCarry, 41U)) + 14944424084524970764U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 5481938174456671041U) + aNonceWordK;
            aOrbiterK = (((aOrbiterK ^ aOrbiterG) ^ 14783648629543752715U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordF;
            aOrbiterK = RotL64((aOrbiterK * 7260164783191886395U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12355573914530445723U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9863991559011968318U;
            aOrbiterF = RotL64((aOrbiterF * 8495251211794343179U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 16149688605937250965U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 106041828692026825U;
            aOrbiterC = RotL64((aOrbiterC * 12199934305374582599U), 53U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 8076098639554567792U) + aOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 11155119311895580013U;
            aOrbiterI = RotL64((aOrbiterI * 1495180896564818647U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 6847612160595917702U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 16094377920388017367U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 4875801863643206333U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 13584719866672696684U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 13446209321646234607U;
            aOrbiterB = RotL64((aOrbiterB * 9945349065094781529U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterH) + 15829806645369560988U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 12573767256739062550U;
            aOrbiterG = RotL64((aOrbiterG * 5649504278826069077U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3850030870300393809U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 11857593987748189858U) ^ aOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 15942863910931814193U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 5505918410521728373U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 12949653497121247860U;
            aOrbiterH = RotL64((aOrbiterH * 90944913639560027U), 41U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterA, 51U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterK, 23U));
            aIngress = aIngress + RotL64(aOrbiterF, 54U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 19U) + aOrbiterG) + RotL64(aOrbiterB, 19U));
            aWandererA = aWandererA ^ (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 57U)) + aOrbiterJ) + aNonceWordG);
            aWandererJ = aWandererJ + ((RotL64(aIngress, 14U) + aOrbiterB) + RotL64(aOrbiterA, 35U));
            aWandererG = aWandererG ^ (((RotL64(aScatter, 35U) + aOrbiterK) + RotL64(aOrbiterF, 28U)) + aNonceWordN);
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + RotL64(aOrbiterK, 39U)) + aOrbiterJ) + RotL64(aCarry, 21U)) + aNonceWordD);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 23U) + RotL64(aOrbiterC, 43U)) + aOrbiterI) + aWandererUpdateSaltF[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 58U) + RotL64(aOrbiterJ, 11U)) + aOrbiterH) + RotL64(aCarry, 43U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterH, 23U)) + aOrbiterC) + aWandererUpdateSaltC[((aIndex + 13U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aScatter, 51U) + RotL64(aOrbiterG, 52U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererG, 57U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererA);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 44U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererD, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 2
        // ingress from: aExpandLaneA, aOperationLaneC, aFireLaneD
        // ingress directions: aExpandLaneA forward forced, aOperationLaneC forward forced, aFireLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneD, aFireLaneA
        // cross directions: aOperationLaneA backward forced, aOperationLaneD backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11064U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneC[((aIndex + 10852U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 11714U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 14535U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 8756U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 13509U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCross, 19U) ^ RotL64(aIngress, 54U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterK = (aWandererK + RotL64(aCross, 19U)) + 6469584119078165548U;
            aOrbiterE = (aWandererG + RotL64(aScatter, 35U)) + 14329756366517987910U;
            aOrbiterC = ((aWandererH + RotL64(aIngress, 29U)) + 12890831797059772123U) + aOrbiterAssignSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aPrevious, 14U)) + RotL64(aCarry, 47U)) + 3164503807500018990U) + aNonceWordH;
            aOrbiterG = (aWandererF + RotL64(aIngress, 23U)) + 177531431387646836U;
            aOrbiterF = (((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 29U)) + 3167421392893561015U) + aOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterB = ((aWandererD + RotL64(aCross, 57U)) + 2813174781844753460U) + aNonceWordL;
            aOrbiterJ = (aWandererC + RotL64(aPrevious, 39U)) + 10953270419153249857U;
            aOrbiterD = ((aWandererE + RotL64(aCross, 52U)) + RotL64(aCarry, 13U)) + 16911518309710356951U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 6616750447844893150U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 10276741398025985982U;
            aOrbiterC = RotL64((aOrbiterC * 6824712685896987133U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 6206043608461213208U;
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12021552904553405793U;
            aOrbiterG = RotL64((aOrbiterG * 10023362889960174909U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 15283586234744144846U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5923238786775948571U;
            aOrbiterB = RotL64((aOrbiterB * 8200882393521882651U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 11044014510971660078U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9351141024085076044U;
            aOrbiterF = RotL64((aOrbiterF * 13316079344614432317U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 17703395981862992420U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 10154548848376027087U) ^ aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 12324478347590509035U), 23U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 8836420852291617425U) + aOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 10193385413543886344U;
            aOrbiterE = RotL64((aOrbiterE * 824935982418585449U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 8248580084535685190U) + aOrbiterUpdateSaltD[((aIndex + 20U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 3910083671888152974U) ^ aNonceWordI;
            aOrbiterK = RotL64((aOrbiterK * 17825311776715895927U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 12350341628569930642U) + aNonceWordO;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 2565977481575002842U) ^ aNonceWordD;
            aOrbiterD = RotL64((aOrbiterD * 18233446879833776677U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9271041067874027417U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 14289254596554201861U) ^ aOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7985522692852251413U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterC, 3U);
            aIngress = aIngress + (RotL64(aOrbiterK, 26U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterB, 47U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 19U));
            aIngress = aIngress + RotL64(aOrbiterF, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((RotL64(aPrevious, 4U) + aOrbiterD) + RotL64(aOrbiterK, 28U));
            aWandererK = aWandererK ^ ((((RotL64(aCross, 47U) + RotL64(aOrbiterB, 23U)) + aOrbiterC) + aNonceWordC) + aWandererUpdateSaltD[((aIndex + 3U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 29U) + RotL64(aOrbiterG, 19U)) + aOrbiterF);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterG, 13U)) + aNonceWordF);
            aWandererE = aWandererE + ((((RotL64(aScatter, 10U) + RotL64(aOrbiterC, 5U)) + aOrbiterF) + RotL64(aCarry, 47U)) + aNonceWordK);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 37U)) + aOrbiterJ);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 39U) + RotL64(aOrbiterG, 41U)) + aOrbiterJ) + RotL64(aCarry, 35U)) + aNonceWordN) + aWandererUpdateSaltB[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 47U)) + aOrbiterA);
            aWandererJ = aWandererJ + ((RotL64(aPrevious, 19U) + RotL64(aOrbiterA, 56U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (RotL64(aWandererK, 60U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 5U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 29U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererF, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 3
        // ingress from: aExpandLaneB, aOperationLaneD, aFireLaneB
        // ingress directions: aExpandLaneB forward forced, aOperationLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneA, aOperationLaneB, aWorkLaneB
        // cross directions: aExpandLaneA backward forced, aOperationLaneB backward forced, aWorkLaneB backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24423U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneD[((aIndex + 24148U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 22276U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17189U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 23262U)) & S_BLOCK1], 30U));
            aCross ^= RotL64(aWorkLaneB[((aIndex + 24159U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 23U) + RotL64(aCross, 4U)) + (RotL64(aIngress, 51U) ^ RotL64(aCarry, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterD = (aWandererC + RotL64(aPrevious, 47U)) + 10915618884692072446U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 27U)) + RotL64(aCarry, 3U)) + 12634922308499254909U;
            aOrbiterC = (((aWandererA + RotL64(aIngress, 60U)) + 6533934734564499389U) + aOrbiterAssignSaltE[((aIndex + 26U)) & S_SALT1]) + aNonceWordO;
            aOrbiterH = (aWandererD + RotL64(aScatter, 37U)) + 6744203303756105181U;
            aOrbiterK = (((aWandererF + RotL64(aIngress, 41U)) + RotL64(aCarry, 27U)) + 13086782386652045658U) + aNonceWordD;
            aOrbiterJ = (aWandererE + RotL64(aPrevious, 19U)) + 5693840533331397822U;
            aOrbiterF = (aWandererK + RotL64(aScatter, 56U)) + 1803663542535024611U;
            aOrbiterG = ((aWandererI + RotL64(aCross, 23U)) + 3597219300593287708U) + aNonceWordP;
            aOrbiterA = (((aWandererB + RotL64(aScatter, 11U)) + RotL64(aCarry, 43U)) + 1429753448204448904U) + aOrbiterAssignSaltF[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 17229017825587322715U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 1137574712801062932U;
            aOrbiterC = RotL64((aOrbiterC * 3645832160939819415U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2401991077004083378U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterH) ^ 1332473247826139292U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 15029831858261506447U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 11730946340796899885U) + aNonceWordF;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 15319163439700390962U;
            aOrbiterE = RotL64((aOrbiterE * 1349242001887975499U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4744141870145159917U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 6067132201862688684U) ^ aOrbiterUpdateSaltD[((aIndex + 8U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 6046100687757836027U), 43U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14991509179286371800U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 4342608825699398682U) ^ aOrbiterUpdateSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10240526103933275875U), 39U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 3727521409410742075U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 3302027219498304367U) ^ aNonceWordE;
            aOrbiterA = RotL64((aOrbiterA * 12153634588200479559U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 6039539483340398858U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 2902581519976937051U;
            aOrbiterK = RotL64((aOrbiterK * 2057584328877854239U), 21U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 12332784713738947242U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 13761272577223712786U;
            aOrbiterJ = RotL64((aOrbiterJ * 14930145045480030821U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 2947946397617043735U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 11107014023853644521U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 15030903626191481831U), 57U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 26U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 19U));
            aIngress = aIngress + (RotL64(aOrbiterG, 57U) ^ aOrbiterD);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterK, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterE, 58U)) + aOrbiterC);
            aWandererC = aWandererC + ((RotL64(aScatter, 27U) + RotL64(aOrbiterK, 53U)) + aOrbiterD);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 12U) + RotL64(aOrbiterK, 41U)) + aOrbiterJ);
            aWandererI = aWandererI + ((RotL64(aCross, 23U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 39U) + RotL64(aOrbiterC, 47U)) + aOrbiterD) + aNonceWordI);
            aWandererD = aWandererD + ((((RotL64(aCross, 5U) + RotL64(aOrbiterH, 3U)) + aOrbiterG) + RotL64(aCarry, 39U)) + aNonceWordK);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 19U) + aOrbiterK) + RotL64(aOrbiterF, 14U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterJ, 21U)) + aOrbiterE) + RotL64(aCarry, 13U)) + aWandererUpdateSaltE[((aIndex + 3U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 46U) + aOrbiterF) + RotL64(aOrbiterG, 37U)) + aWandererUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 27U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererB, 54U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // kdf_b_loop_c loop 4
        // ingress from: aExpandLaneC, aExpandLaneA, aWorkLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aWorkLaneA forward/backward random
        // cross from: aExpandLaneB, aOperationLaneC, aFireLaneC
        // cross directions: aExpandLaneB backward forced, aOperationLaneC backward forced, aFireLaneC backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25351U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneA[((aIndex + 27493U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneA[((aIndex + 28913U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28341U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 29779U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 28214U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 35U) + RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererK + RotL64(aPrevious, 51U)) + RotL64(aCarry, 39U)) + 12690502671561165478U) + aNonceWordF;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 19U)) + 17519943923428102801U) + aNonceWordA;
            aOrbiterB = ((aWandererE + RotL64(aCross, 29U)) + 10705515807975331385U) + aOrbiterAssignSaltA[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterA = (((aWandererD + RotL64(aIngress, 47U)) + RotL64(aCarry, 11U)) + 16586447272278538179U) + aNonceWordK;
            aOrbiterC = ((aWandererB + RotL64(aScatter, 34U)) + RotL64(aCarry, 27U)) + 8006560996840971798U;
            aOrbiterK = ((aWandererJ + RotL64(aIngress, 11U)) + 12928600185788857701U) + aNonceWordH;
            aOrbiterE = (aWandererA + RotL64(aPrevious, 57U)) + 14240723153798267172U;
            aOrbiterH = (aWandererG + RotL64(aCross, 39U)) + 8636219177994872072U;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 4U)) + 7586790235186467512U) + aOrbiterAssignSaltB[(((31U - aIndex) + 28U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 1103807034179512424U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 7547526530239498693U) ^ aOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3360295583636013509U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8380239679344786397U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 5690809173787433519U;
            aOrbiterC = RotL64((aOrbiterC * 5354724308093372953U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 8390902801141804609U) + aNonceWordM;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 3507306189192059486U) ^ aOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 18336280496510253103U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6190745292098482871U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8065418693975056902U;
            aOrbiterH = RotL64((aOrbiterH * 6414621418430102589U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 12111755051718111803U) + aNonceWordJ;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 7605877769709909297U;
            aOrbiterI = RotL64((aOrbiterI * 17525248694315944599U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 5969794501112646237U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5127559299360591476U;
            aOrbiterD = RotL64((aOrbiterD * 4521563633438853069U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10593847754747739786U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 4401750688524310121U;
            aOrbiterG = RotL64((aOrbiterG * 14265829318976633707U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 6927893132508779499U;
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 4874009978647014479U;
            aOrbiterA = RotL64((aOrbiterA * 13340466017023540755U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 13146693487138744677U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterI) ^ 3298472134223595298U) ^ aOrbiterUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2145005258008477281U), 43U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterK, 39U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 4U));
            aIngress = aIngress + RotL64(aOrbiterG, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 18U)) + aOrbiterC) + RotL64(aCarry, 43U)) + aNonceWordC) + aWandererUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 47U) + aOrbiterG) + RotL64(aOrbiterC, 39U));
            aWandererJ = aWandererJ + ((((RotL64(aCross, 28U) + RotL64(aOrbiterI, 57U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aNonceWordI);
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterB, 29U)) + aOrbiterD) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + aWandererUpdateSaltF[((aIndex + 8U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 43U) + RotL64(aOrbiterB, 34U)) + aOrbiterK);
            aWandererI = aWandererI + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterB, 13U)) + aOrbiterE);
            aWandererD = aWandererD ^ (((RotL64(aCross, 38U) + aOrbiterH) + RotL64(aOrbiterD, 43U)) + aNonceWordD);
            aWandererA = aWandererA + ((RotL64(aScatter, 57U) + aOrbiterH) + RotL64(aOrbiterG, 53U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererG, 27U));
            aCarry = aCarry + (RotL64(aWandererB, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererJ, 35U));
            aCarry = aCarry + RotL64(aWandererI, 11U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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

void TwistExpander_Lacrosse_Arx::KDF_B_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC28F904118F5A8ABULL + 0xD3C93CA178F49B59ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xE4AF595789766A87ULL + 0xFF7CD9249316401BULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseB(pNonce * 0xA50EA8901DE0D3F5ULL + 0xB614332B6B72AA85ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x9AEC96B55343B411ULL + 0xF6FE1AD2877F2AA2ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB6AF82307BF4CD6FULL + 0xB594B28667566494ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE2536591AE88571DULL + 0xCA0FC4ED6A8A054FULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD30829AE9257DD01ULL + 0xACFB5AB80E5C12C7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xA5488E23C9542495ULL + 0x8CB0C3DA1A548DA6ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8E4CF16A6647031DULL + 0x9D29384DAAD63F14ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseA(pNonce * 0xE7221EFC9C6E8BE9ULL + 0x9924D47E2FE976E8ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xF19A88F627C8C14BULL + 0xA7D9C2A657ACFB5BULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xA70B5ED67B870449ULL + 0xF9C3410EDD8318DEULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xA2869BFB8CC61227ULL + 0xCBCAB0F72443448FULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xFAD69DB5CA22EFB1ULL + 0xE8717ED7C52B29E2ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x951DFE212215F193ULL + 0xE51F12582F7A7099ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x8E9BC22EF50F0A7BULL + 0xB87454A6E289259AULL);
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
        // read from: aWorkLaneA, aWorkLaneB, aOperationLaneA, aWorkLaneC, aWorkLaneD, aOperationLaneD, aExpandLaneA, aFireLaneB, aOperationLaneC, aExpandLaneB, aOperationLaneB, aFireLaneA, aExpandLaneC, aFireLaneC, aFireLaneD
        // write to: aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // kdf_b_loop_d loop 1
        // ingress from: aWorkLaneA, aWorkLaneB, aOperationLaneA
        // ingress directions: aWorkLaneA forward forced, aWorkLaneB forward forced, aOperationLaneA forward/backward random
        // cross from: aWorkLaneC, aWorkLaneD, aOperationLaneD
        // cross directions: aWorkLaneC backward forced, aWorkLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 6348U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneB[((aIndex + 4147U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aOperationLaneA[((aIndex + 6267U)) & S_BLOCK1], 14U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1290U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 7920U)) & S_BLOCK1], 20U));
            aCross ^= RotL64(aOperationLaneD[((aIndex + 5183U)) & S_BLOCK1], 29U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCarry, 19U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 36U) ^ RotL64(aIngress, 5U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterK = ((aWandererE + RotL64(aScatter, 30U)) + 8101351470141807662U) + aOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterG = ((aWandererJ + RotL64(aIngress, 57U)) + 6965474099521076705U) + aOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterI = (((aWandererB + RotL64(aPrevious, 3U)) + RotL64(aCarry, 27U)) + 6803828268885684784U) + aNonceWordH;
            aOrbiterC = (((aWandererG + RotL64(aCross, 47U)) + RotL64(aCarry, 47U)) + 13454235922950972488U) + aNonceWordC;
            aOrbiterE = ((aWandererA + RotL64(aScatter, 11U)) + 11678091885751244777U) + aNonceWordI;
            aOrbiterJ = ((aWandererD + RotL64(aPrevious, 19U)) + 5307134544628507141U) + aNonceWordA;
            aOrbiterD = ((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 4873703518950429353U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 8542156221858586039U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 3993726182905296513U) ^ aOrbiterUpdateSaltA[((aIndex + 22U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11331376012938127609U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 12113047622035464386U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 1944244448665721151U) ^ aNonceWordD;
            aOrbiterK = RotL64((aOrbiterK * 7010050836758762003U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 12914188029425467576U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 2486762763475327024U;
            aOrbiterE = RotL64((aOrbiterE * 12319769994433811617U), 43U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 14580191602982245481U) + aOrbiterUpdateSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 12093414832400135066U;
            aOrbiterG = RotL64((aOrbiterG * 12720286833215690663U), 27U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 13623906997320021065U) + aOrbiterUpdateSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 9977356009806428696U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 2005536391712733499U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 3694954095397810851U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 11453812627797091638U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 13730420725113907161U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterC) + 542311345544726351U) + aNonceWordM;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 3024285045990499484U) ^ aOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5153745952148205645U), 51U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterE, 56U));
            aIngress = aIngress + (RotL64(aOrbiterC, 3U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterG, 37U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aCross, 35U) + RotL64(aOrbiterD, 51U)) + aOrbiterI) + RotL64(aCarry, 5U)) + aWandererUpdateSaltE[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 5U) + RotL64(aOrbiterD, 43U)) + aOrbiterJ);
            aWandererA = aWandererA + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterC, 5U)) + aOrbiterE);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + aOrbiterJ) + RotL64(aOrbiterG, 57U)) + aWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aPrevious, 60U) + aOrbiterE) + RotL64(aOrbiterI, 37U)) + RotL64(aCarry, 23U)) + aNonceWordG);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + aOrbiterK) + RotL64(aOrbiterJ, 14U));
            aWandererG = aWandererG + (((RotL64(aIngress, 19U) + RotL64(aOrbiterC, 27U)) + aOrbiterJ) + aNonceWordK);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 29U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 34U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererD, 39U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 2
        // ingress from: aExpandLaneA, aWorkLaneC, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aWorkLaneC forward forced, aFireLaneB forward/backward random
        // cross from: aWorkLaneA, aWorkLaneD, aOperationLaneC
        // cross directions: aWorkLaneA backward forced, aWorkLaneD backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 15674U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneC[((aIndex + 11291U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 11205U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aDomainWordIngress) ^ aNonceWordM));
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 9125U)) & S_BLOCK1], 40U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 9523U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12961U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCarry, 29U) + RotL64(aPrevious, 58U)) ^ (RotL64(aCross, 41U) + RotL64(aIngress, 13U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterJ = ((aWandererJ + RotL64(aCross, 13U)) + 12615321415808640429U) + aOrbiterAssignSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererI + RotL64(aScatter, 57U)) + 15712784676459931207U) + aNonceWordJ;
            aOrbiterC = (aWandererD + RotL64(aPrevious, 19U)) + 11013335427004930046U;
            aOrbiterA = (((aWandererH + RotL64(aIngress, 39U)) + RotL64(aCarry, 53U)) + 8298733856304768806U) + aNonceWordC;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 27U)) + RotL64(aCarry, 3U)) + 6207732959150824216U) + aOrbiterAssignSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterB = ((aWandererE + RotL64(aIngress, 5U)) + 9769864876127544038U) + aNonceWordF;
            aOrbiterE = ((aWandererF + RotL64(aScatter, 50U)) + RotL64(aCarry, 41U)) + 10782181918651152563U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 5790454015845620939U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 15606578025386733803U;
            aOrbiterC = RotL64((aOrbiterC * 7079287329365566355U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 5522352539991175304U) + aOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 5993355818572869649U) ^ aOrbiterUpdateSaltE[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 15221467311057431139U), 5U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10864534396947622047U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 12090053126235913528U;
            aOrbiterB = RotL64((aOrbiterB * 7250801471645972261U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 14191181677234981396U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterC) ^ 2258570108233924592U) ^ aNonceWordP;
            aOrbiterE = RotL64((aOrbiterE * 8307541155393855209U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 8448114811381534603U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 2702389315763499817U;
            aOrbiterA = RotL64((aOrbiterA * 6710443836432274393U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 17202184076718780200U) + aOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterB) ^ 150549910056015002U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 195034681254956335U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 4910512055808124967U) + aOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 4783477997418403079U;
            aOrbiterG = RotL64((aOrbiterG * 861977492146512865U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + RotL64(aOrbiterA, 56U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((((RotL64(aIngress, 27U) + aOrbiterJ) + RotL64(aOrbiterC, 35U)) + aNonceWordI) + aWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 60U) + RotL64(aOrbiterB, 20U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 41U) + aOrbiterA) + RotL64(aOrbiterC, 3U)) + RotL64(aCarry, 29U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererE = aWandererE + ((((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 43U)) + aNonceWordN) + aWandererUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 53U)) + aOrbiterE);
            aWandererI = aWandererI + (((RotL64(aPrevious, 11U) + aOrbiterG) + RotL64(aOrbiterA, 29U)) + RotL64(aCarry, 57U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 5U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererA, 19U) ^ aWandererH);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 51U));
            aCarry = aCarry + RotL64(aWandererF, 10U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // kdf_b_loop_d loop 3
        // ingress from: aExpandLaneB, aWorkLaneD, aOperationLaneB
        // ingress directions: aExpandLaneB forward forced, aWorkLaneD forward forced, aOperationLaneB forward/backward random
        // cross from: aExpandLaneA, aWorkLaneB, aFireLaneA
        // cross directions: aExpandLaneA backward forced, aWorkLaneB backward forced, aFireLaneA backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 18232U)) & S_BLOCK1], 43U) ^ RotL64(aWorkLaneD[((aIndex + 20164U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aOperationLaneB[((aIndex + 17769U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 22948U)) & S_BLOCK1], 19U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16762U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aFireLaneA[((aIndex + 21561U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 60U) + RotL64(aCross, 29U)) ^ (RotL64(aCarry, 43U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterF = ((aWandererD + RotL64(aCross, 5U)) + RotL64(aCarry, 5U)) + 17454559218352016650U;
            aOrbiterH = ((aWandererI + RotL64(aIngress, 21U)) + 8005709669325164803U) + aNonceWordP;
            aOrbiterG = (((aWandererG + RotL64(aScatter, 57U)) + 13393741948412816357U) + aOrbiterAssignSaltB[(((31U - aIndex) + 16U)) & S_SALT1]) + aNonceWordB;
            aOrbiterC = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 35U)) + 3665865624348875553U;
            aOrbiterB = (((aWandererC + RotL64(aIngress, 47U)) + RotL64(aCarry, 53U)) + 8334142570031883436U) + aOrbiterAssignSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = ((aWandererF + RotL64(aScatter, 28U)) + 17226066128706139657U) + aNonceWordF;
            aOrbiterE = ((aWandererJ + RotL64(aCross, 35U)) + 3319093033121522613U) + aNonceWordK;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 6657535603401588798U) + aNonceWordL;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 5469746182326331147U;
            aOrbiterG = RotL64((aOrbiterG * 11315450342347794329U), 41U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 17846791786050221418U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterC) ^ 15939541003714896288U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1400351482213119809U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterF) + 12076763190461077406U) + aOrbiterUpdateSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 3594038213596405284U) ^ aOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 10244002692575821495U), 53U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8301291631324464622U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterE) ^ 8460406137668390582U) ^ aNonceWordJ;
            aOrbiterB = RotL64((aOrbiterB * 9117147929757711595U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7612394867020871200U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8525076134853103975U;
            aOrbiterE = RotL64((aOrbiterE * 5790440201072204659U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 11929899088215090379U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 7119509166360685726U;
            aOrbiterF = RotL64((aOrbiterF * 1662341427992528823U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 5081078459225240607U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 17149991983909906705U) ^ aOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 950223374568067343U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 12U));
            aIngress = aIngress + (RotL64(aOrbiterE, 29U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterH, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aIngress, 5U) + aOrbiterC) + RotL64(aOrbiterE, 23U)) + aNonceWordM);
            aWandererI = aWandererI + (((RotL64(aCross, 60U) + aOrbiterC) + RotL64(aOrbiterG, 29U)) + RotL64(aCarry, 3U));
            aWandererD = aWandererD ^ ((((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 41U)) + aOrbiterA) + aNonceWordA) + aWandererUpdateSaltB[((aIndex + 29U)) & S_SALT1]);
            aWandererF = aWandererF + ((((RotL64(aScatter, 37U) + aOrbiterE) + RotL64(aOrbiterA, 5U)) + RotL64(aCarry, 53U)) + aWandererUpdateSaltC[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterF) + RotL64(aOrbiterB, 48U));
            aWandererJ = aWandererJ + ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 11U)) + aOrbiterH);
            aWandererH = aWandererH ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterE, 57U)) + aOrbiterB) + aNonceWordI);
            //
            aCarry = aCarry + (RotL64(aWandererD, 35U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 5U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 26U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 25202U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneA[((aIndex + 24937U)) & S_BLOCK1], 21U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 32518U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 25382U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 25611U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aFireLaneD[((aIndex + 31709U)) & S_BLOCK1], 52U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aPrevious, 18U) + RotL64(aCarry, 51U)) + (RotL64(aIngress, 3U) ^ RotL64(aCross, 39U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 35U)) + RotL64(aCarry, 23U)) + 13960289014350612206U;
            aOrbiterI = ((aWandererD + RotL64(aCross, 21U)) + 3483331015269589730U) + aNonceWordH;
            aOrbiterA = (aWandererA + RotL64(aIngress, 4U)) + 6873299241002444518U;
            aOrbiterD = (((aWandererK + RotL64(aScatter, 13U)) + RotL64(aCarry, 35U)) + 3562094007125534229U) + aNonceWordI;
            aOrbiterC = (((aWandererF + RotL64(aCross, 27U)) + 11422367439932782705U) + aOrbiterAssignSaltA[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 43U)) + 532453428514259816U) + aNonceWordP;
            aOrbiterJ = (((aWandererE + RotL64(aIngress, 53U)) + RotL64(aCarry, 47U)) + 17810941465810193088U) + aOrbiterAssignSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 11869759058631106331U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8837581071876177566U;
            aOrbiterA = RotL64((aOrbiterA * 15329827515970522213U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 17185378327053837778U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 7578253375676981500U;
            aOrbiterD = RotL64((aOrbiterD * 13371647568758721729U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 17112646434432814442U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 14949096407295697881U) ^ aOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 14770977858283051753U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 4259590620758467836U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 6534899413644542303U) ^ aOrbiterUpdateSaltA[((aIndex + 12U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7987609419215568661U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 2637407498893694243U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 15819295597921425711U;
            aOrbiterC = RotL64((aOrbiterC * 5202015597375051399U), 41U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterC) + 6373559542002699718U) + aOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 11694562937392022505U;
            aOrbiterF = RotL64((aOrbiterF * 9311557972331218597U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 3308736483775453062U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterA) ^ 12749929710650475901U) ^ aOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 248428400724560945U), 5U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterA, 50U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + (((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterI, 21U)) + RotL64(aCarry, 57U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterJ, 41U)) + aOrbiterF);
            aWandererE = aWandererE + ((RotL64(aCross, 13U) + RotL64(aOrbiterE, 27U)) + aOrbiterD);
            aWandererF = aWandererF ^ ((((RotL64(aScatter, 37U) + RotL64(aOrbiterF, 13U)) + aOrbiterC) + aNonceWordO) + aWandererUpdateSaltF[((aIndex + 21U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterF, 47U)) + aOrbiterI) + aNonceWordJ);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + aOrbiterI) + RotL64(aOrbiterE, 35U)) + aWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererD = aWandererD + ((((RotL64(aCross, 51U) + RotL64(aOrbiterA, 4U)) + aOrbiterD) + RotL64(aCarry, 13U)) + aNonceWordC);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 27U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 22U));
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 37U);
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

void TwistExpander_Lacrosse_Arx::Seed_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseEOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseESalts.mOrbiterAssign.mSaltD;
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
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterAssignSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterAssign.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseFOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mOrbiterUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseFWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseFSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseGOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseGSalts.mOrbiterAssign.mSaltB;
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
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseGWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseGSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterAssignSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterAssign.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseHOrbiterUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseHSalts.mOrbiterUpdate.mSaltF;
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xC6561EFDBCDA5893ULL + 0xB640A5846DD0C13EULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xA4C048716D130671ULL + 0xB2C1B31CAA0D3C3EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xC8ECF7E8171DD3A1ULL + 0xE9318B6DE6DE1BFCULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0x926CC38AB854B8E9ULL + 0x8C8F4A5677547794ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xE53C64B80F25E33FULL + 0xA996B9ED5D6D3670ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xE5FB3E4C099C9EFDULL + 0x8FAA73D81AB87E75ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xE8F7245B87143C5DULL + 0xC3223A42FFC0109FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0x9240633F9677D73BULL + 0xAF3F89427FA7B94DULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xFF7660D36D41E2ABULL + 0xC13ABC9C8359B427ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x98FD0841CEFF111FULL + 0xBF798F13DCAB5C8DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0xEB1BECDD294536DBULL + 0xC61E57FC7B9A702EULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB7DF5995B1819657ULL + 0xFC2B48862A247C26ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0x9FA04646DE037379ULL + 0xE46590D20BE54530ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0xC6C29BF9849E4557ULL + 0xAA47D18189633EF0ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0x95C48A054910E009ULL + 0xF12334D336E585D8ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xDB8E9F8E30E51CE7ULL + 0x8ADF7EE56B61D68DULL);
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 1050U)) & W_KEY1], 4U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 277U)) & W_KEY1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1384U)) & W_KEY1], 41U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 2239U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 11U) ^ RotL64(aPrevious, 29U)) + (RotL64(aCross, 41U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 29U)) + 13350544654542863236U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 21U)) + 12364346790125404372U;
            aOrbiterG = ((aWandererJ + RotL64(aScatter, 57U)) + RotL64(aCarry, 5U)) + 9738750172849512764U;
            aOrbiterH = (((aWandererC + RotL64(aCross, 41U)) + 3781373837635491421U) + aPhaseEOrbiterAssignSaltF[((aIndex + 10U)) & S_SALT1]) + aNonceWordD;
            aOrbiterE = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 27U)) + 16635020317512702337U;
            aOrbiterB = (((aWandererF + RotL64(aCross, 51U)) + RotL64(aCarry, 51U)) + 5383653921676231276U) + aNonceWordC;
            aOrbiterA = (aWandererE + RotL64(aPrevious, 14U)) + 10181959815492056493U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 10005510924273927017U) + aNonceWordK;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 9524687662265740565U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13687380438646756931U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 4259138552009771014U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 8973051213213726023U;
            aOrbiterE = RotL64((aOrbiterE * 12625091476068190979U), 13U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 17602611840127337490U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 8218984546932905269U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 17504305273683304231U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 18102186122213487888U) + aNonceWordP;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2629927500298092976U;
            aOrbiterB = RotL64((aOrbiterB * 6983280164448292723U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 2491581597835795234U;
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 9506602492971620955U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterJ = RotL64((aOrbiterJ * 9559829640915637163U), 21U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 13422942713680612924U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 15037354693234876601U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12692376075738621447U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 12896066842192894694U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 2202952306291905855U;
            aOrbiterC = RotL64((aOrbiterC * 6779368532763429997U), 57U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterC, 5U);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterH, 13U));
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererF = aWandererF + ((RotL64(aCross, 29U) + aOrbiterC) + RotL64(aOrbiterJ, 23U));
            aWandererE = aWandererE ^ (((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterE, 57U)) + aNonceWordL);
            aWandererH = aWandererH + ((((RotL64(aIngress, 13U) + RotL64(aOrbiterB, 13U)) + aOrbiterG) + RotL64(aCarry, 23U)) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 37U)) + aOrbiterH) + aPhaseEWandererUpdateSaltA[((aIndex + 24U)) & S_SALT1]);
            aWandererK = aWandererK + ((((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 35U)) + aNonceWordF);
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 60U) + aOrbiterA) + RotL64(aOrbiterB, 30U)) + aNonceWordH);
            aWandererC = aWandererC + ((RotL64(aIngress, 47U) + RotL64(aOrbiterE, 43U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 6U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererJ, 53U));
            aCarry = aCarry + RotL64(aWandererE, 27U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5051U)) & S_BLOCK1], 24U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 2881U)) & W_KEY1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 5133U)) & W_KEY1], 51U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5033U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aCross, 47U) ^ RotL64(aPrevious, 35U)) ^ (RotL64(aIngress, 60U) + RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (aWandererE + RotL64(aScatter, 35U)) + 1888427424966603593U;
            aOrbiterJ = ((((aWandererG + RotL64(aIngress, 11U)) + RotL64(aCarry, 35U)) + 5436761445660415091U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 24U)) & S_SALT1]) + aNonceWordN;
            aOrbiterD = ((aWandererJ + RotL64(aCross, 21U)) + 17322876217962143270U) + aNonceWordO;
            aOrbiterE = ((aWandererC + RotL64(aPrevious, 27U)) + RotL64(aCarry, 47U)) + 9728299982740564979U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 3U)) + 301720335271716921U) + aNonceWordJ;
            aOrbiterF = (((aWandererH + RotL64(aPrevious, 51U)) + 8069685428854814396U) + aPhaseEOrbiterAssignSaltB[((aIndex + 20U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aWandererB + RotL64(aCross, 44U)) + RotL64(aCarry, 23U)) + 1973715500949100991U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterJ) + 87666408799854155U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 12195436904339035245U;
            aOrbiterD = RotL64((aOrbiterD * 15427739165893738105U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 4578742069143400295U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 7828776048774876484U;
            aOrbiterK = RotL64((aOrbiterK * 4047964518501081039U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 17203146364542781833U) + aNonceWordP;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 16913369550858890466U;
            aOrbiterE = RotL64((aOrbiterE * 13534417587921978507U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 9632761514552265402U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 9106637671877341286U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 9073709119482640391U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15423680889126750876U) + aNonceWordG;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 6087310684583331882U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 8964465129744898619U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 5420955876411796789U;
            aOrbiterA = (((aOrbiterA ^ aOrbiterH) ^ 14166807419730848032U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordA;
            aOrbiterA = RotL64((aOrbiterA * 442659738632823751U), 29U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterF) + 8118312450347026824U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 4253043584558403086U;
            aOrbiterJ = RotL64((aOrbiterJ * 5651748455190536467U), 39U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 43U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 3U));
            aIngress = aIngress + (RotL64(aOrbiterH, 57U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterK, 20U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 23U) + aOrbiterE) + RotL64(aOrbiterF, 47U)) + aNonceWordB) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 5U) + RotL64(aOrbiterF, 53U)) + aOrbiterD);
            aWandererG = aWandererG + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 14U)) + aOrbiterJ) + RotL64(aCarry, 23U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterE) + RotL64(aOrbiterK, 41U));
            aWandererH = aWandererH + (((RotL64(aPrevious, 35U) + aOrbiterK) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 41U));
            aWandererB = aWandererB ^ ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterE, 21U)) + aNonceWordH) + aPhaseEWandererUpdateSaltD[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aCross, 14U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererC, 35U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 46U));
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererB, 41U);
            aCarry = aCarry + RotL64(aIngress, 3U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 6989U)) & S_BLOCK1], 35U) ^ RotL64(aKeyRowReadB[((aIndex + 7043U)) & W_KEY1], 22U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 6058U)) & W_KEY1], 27U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 5503U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 5490U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aCross, 56U) ^ RotL64(aIngress, 5U)) + (RotL64(aPrevious, 43U) ^ RotL64(aCarry, 29U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererC + RotL64(aScatter, 11U)) + 5480870806135400132U) + aNonceWordD;
            aOrbiterD = ((((aWandererJ + RotL64(aPrevious, 39U)) + RotL64(aCarry, 51U)) + 8034874599430768743U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (aWandererK + RotL64(aCross, 29U)) + 4006919843736863767U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 5U)) + 2988069748674633718U;
            aOrbiterH = (((aWandererH + RotL64(aScatter, 19U)) + RotL64(aCarry, 3U)) + 12347295651973135786U) + aNonceWordN;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 60U)) + RotL64(aCarry, 37U)) + 14152683894431568192U;
            aOrbiterI = ((aWandererA + RotL64(aCross, 47U)) + 15765143815254196598U) + aPhaseEOrbiterAssignSaltA[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 10473067082331244233U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1089466925383677249U) ^ aNonceWordG;
            aOrbiterF = RotL64((aOrbiterF * 17334888609179149753U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13215039929873682230U) + aNonceWordF;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 3957997712247961479U;
            aOrbiterA = RotL64((aOrbiterA * 7631186240013784703U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 10023907397941685546U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 14593012591254614353U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17111300092082154687U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 13353797968154036726U;
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 9259966668512102858U;
            aOrbiterG = RotL64((aOrbiterG * 8326732574268308221U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 10757861831070349321U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10530223113483866178U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 11269177745265396583U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 7554320926405521865U) + aNonceWordH;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 6978052067277966996U;
            aOrbiterH = RotL64((aOrbiterH * 18020134738536217801U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1053695861967171420U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 15980734683539854451U) ^ aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 3208466640010555357U), 11U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterG, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + ((RotL64(aIngress, 35U) + RotL64(aOrbiterH, 37U)) + aOrbiterI);
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 53U) + aOrbiterH) + RotL64(aOrbiterF, 5U)) + aNonceWordA);
            aWandererB = aWandererB + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterF, 47U)) + aOrbiterG) + RotL64(aCarry, 19U)) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 12U) + aOrbiterF) + RotL64(aOrbiterC, 13U)) + aNonceWordC);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterD) + RotL64(aOrbiterI, 30U)) + RotL64(aCarry, 37U)) + aNonceWordB);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterA, 57U));
            aWandererK = aWandererK + (((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterA, 19U)) + aPhaseEWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererA, 28U) ^ aWandererD);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 13U));
            aCarry = aCarry + RotL64(aWandererC, 53U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 9226U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadB[((aIndex + 8206U)) & W_KEY1], 13U));
            aIngress ^= (RotL64(mSource[((aIndex + 9158U)) & S_BLOCK1], 24U) ^ RotL64(aWorkLaneA[((aIndex + 8687U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 8961U)) & W_KEY1], 57U) ^ RotL64(aWorkLaneB[((aIndex + 8382U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCarry, 14U) ^ RotL64(aPrevious, 43U)) + (RotL64(aIngress, 27U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (((aWandererK + RotL64(aScatter, 51U)) + 15910560457440369082U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterH = ((((aWandererA + RotL64(aIngress, 20U)) + RotL64(aCarry, 53U)) + 17953072986407436888U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1]) + aNonceWordM;
            aOrbiterA = ((aWandererF + RotL64(aCross, 35U)) + RotL64(aCarry, 41U)) + 15446940721193538669U;
            aOrbiterK = ((aWandererI + RotL64(aPrevious, 11U)) + RotL64(aCarry, 21U)) + 3020785262774422009U;
            aOrbiterI = (aWandererH + RotL64(aScatter, 27U)) + 7001288645424994404U;
            aOrbiterE = (aWandererC + RotL64(aCross, 5U)) + 13385250665458462689U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 43U)) + 4841895644623005949U) + aNonceWordF;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 13053476783239482065U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 641996979335975244U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 3697673197256549833U), 21U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterA) + 16211238020928688299U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12715448751323279480U;
            aOrbiterK = RotL64((aOrbiterK * 2116880429675303291U), 47U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 17784406727699995290U) + aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 16626339815786580778U;
            aOrbiterH = RotL64((aOrbiterH * 13940754474750138041U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 9035070625716345139U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 6085848172494001945U;
            aOrbiterI = RotL64((aOrbiterI * 10405728912339646693U), 57U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 1177103851507561053U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 2281901691017816407U;
            aOrbiterD = RotL64((aOrbiterD * 3142197009403602497U), 11U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 9040984343694325070U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 13334258224023902365U) ^ aNonceWordB;
            aOrbiterB = RotL64((aOrbiterB * 4782523727707164869U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 1079824790138592518U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 14024082692012948652U) ^ aNonceWordN;
            aOrbiterE = RotL64((aOrbiterE * 3219489374333737903U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 43U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterI, 22U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterB, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 11U)) + aOrbiterA) + aNonceWordK);
            aWandererC = aWandererC + (((RotL64(aCross, 53U) + RotL64(aOrbiterK, 27U)) + aOrbiterD) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 39U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            aWandererH = aWandererH + (((RotL64(aIngress, 19U) + RotL64(aOrbiterE, 35U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 13U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + aPhaseFWandererUpdateSaltA[((aIndex + 28U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aIngress, 26U) + aOrbiterB) + RotL64(aOrbiterH, 43U)) + aNonceWordH);
            aWandererK = aWandererK ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterE, 58U)) + aOrbiterK) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 60U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererC, 47U));
            aCarry = aCarry + RotL64(aWandererF, 3U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aWorkLaneD[((aIndex + 12748U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 12840U)) & W_KEY1], 37U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13063U)) & W_KEY1], 19U) ^ RotL64(mSource[((aIndex + 11229U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10992U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 13631U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneC[((aIndex + 11438U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aPrevious, 5U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 28U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterG = (((aWandererG + RotL64(aPrevious, 60U)) + 964165145848253292U) + aPhaseFOrbiterAssignSaltC[((aIndex + 13U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aWandererC + RotL64(aIngress, 35U)) + 10645976767204934746U;
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 53U)) + RotL64(aCarry, 27U)) + 8241612229349212650U) + aPhaseFOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1];
            aOrbiterF = ((aWandererE + RotL64(aCross, 13U)) + 4159196033256913347U) + aNonceWordO;
            aOrbiterC = ((aWandererD + RotL64(aIngress, 41U)) + RotL64(aCarry, 39U)) + 7194795864620233507U;
            aOrbiterK = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 51U)) + 7638928444536778384U) + aNonceWordF;
            aOrbiterJ = ((aWandererI + RotL64(aPrevious, 27U)) + 11819105916503968109U) + aNonceWordG;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 18052213302858186237U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 8663575313970041570U) ^ aNonceWordB;
            aOrbiterD = RotL64((aOrbiterD * 14131073322476609161U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16644136720439299786U;
            aOrbiterC = (aOrbiterC ^ aOrbiterF) ^ 16930316530442679864U;
            aOrbiterC = RotL64((aOrbiterC * 2650922074098320859U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 16251107616988250593U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 7171986193609401665U;
            aOrbiterG = RotL64((aOrbiterG * 3543709971414550087U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 17885046834432626644U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 7757069274715713557U) ^ aNonceWordN;
            aOrbiterB = RotL64((aOrbiterB * 15766885299397923879U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 2212805322061155615U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 24U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 6368539134638838822U;
            aOrbiterF = RotL64((aOrbiterF * 13383744883433594259U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 5264326094252925613U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 6126345334815012938U;
            aOrbiterK = RotL64((aOrbiterK * 17180934809764905307U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 13826731214018407061U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterD) ^ 6621261811613643620U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterJ = RotL64((aOrbiterJ * 2823596473596114171U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 37U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterD, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 3U));
            aIngress = aIngress + RotL64(aOrbiterF, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 13U) + RotL64(aOrbiterJ, 12U)) + aOrbiterF) + aNonceWordI);
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 35U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 27U) + aOrbiterD) + RotL64(aOrbiterJ, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 21U) + aOrbiterG) + RotL64(aOrbiterD, 51U)) + RotL64(aCarry, 43U));
            aWandererE = aWandererE ^ (((RotL64(aCross, 5U) + RotL64(aOrbiterB, 41U)) + aOrbiterC) + aNonceWordH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 56U) + RotL64(aOrbiterC, 29U)) + aOrbiterK) + aPhaseFWandererUpdateSaltC[((aIndex + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 51U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 44U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 11U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 23U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 15895U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneC[((aIndex + 15025U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14213U)) & W_KEY1], 5U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16338U)) & W_KEY1], 39U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 14390U)) & S_BLOCK1], 30U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 16312U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 13960U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aCarry, 5U) ^ RotL64(aIngress, 56U)) ^ (RotL64(aCross, 27U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterB = ((aWandererD + RotL64(aCross, 29U)) + 5173905450211892891U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterJ = (((aWandererB + RotL64(aScatter, 37U)) + RotL64(aCarry, 5U)) + 3555542451908039957U) + aNonceWordJ;
            aOrbiterD = (aWandererJ + RotL64(aPrevious, 3U)) + 11559884700283861559U;
            aOrbiterF = ((aWandererF + RotL64(aIngress, 13U)) + RotL64(aCarry, 43U)) + 1352524329968738673U;
            aOrbiterH = (aWandererA + RotL64(aCross, 47U)) + 8914206450420616349U;
            aOrbiterC = ((aWandererK + RotL64(aIngress, 56U)) + 2251523378498463946U) + aNonceWordI;
            aOrbiterE = (((aWandererC + RotL64(aPrevious, 21U)) + RotL64(aCarry, 19U)) + 9541575923299247038U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1239854507907214595U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 17698101462598498934U;
            aOrbiterD = RotL64((aOrbiterD * 2304948713665996433U), 41U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 12305566971683256060U) + aNonceWordC;
            aOrbiterH = (((aOrbiterH ^ aOrbiterJ) ^ 13804545036303215569U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 15U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterH = RotL64((aOrbiterH * 10359543704152744971U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 10239749097704329264U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 4212214906286320308U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3661436621615751071U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 12192418916967430783U) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 4475514289326450361U;
            aOrbiterJ = RotL64((aOrbiterJ * 17497164630368757887U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 17376102613298827459U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 18129393209955439341U;
            aOrbiterB = RotL64((aOrbiterB * 6404089025014118979U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 4014763724300253568U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 17325007199676828814U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 1420888274815627083U), 21U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 15480474849292388685U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 14357924730184375449U;
            aOrbiterE = RotL64((aOrbiterE * 16723492259068034209U), 3U);
            //
            aIngress = RotL64(aOrbiterD, 57U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (RotL64(aOrbiterH, 35U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterF, 19U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 35U) + RotL64(aOrbiterF, 57U)) + aOrbiterC) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 58U) + aOrbiterH) + RotL64(aOrbiterD, 12U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((((RotL64(aScatter, 27U) + aOrbiterJ) + RotL64(aOrbiterF, 43U)) + aNonceWordK) + aPhaseFWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 41U) + aOrbiterB) + RotL64(aOrbiterJ, 37U)) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterF) + RotL64(aOrbiterH, 21U)) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + aNonceWordM);
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 51U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 10U) ^ aWandererA);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 37U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererC, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 16510U)) & S_BLOCK1], 5U) ^ RotL64(aKeyRowReadA[((aIndex + 17972U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(mSource[((aIndex + 16675U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 18658U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17160U)) & W_KEY1], 52U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 16431U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 17365U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aIngress, 34U) + RotL64(aCross, 51U)) ^ (RotL64(aPrevious, 19U) ^ RotL64(aCarry, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterK = (((aWandererC + RotL64(aScatter, 29U)) + 7896237440058555694U) + aPhaseGOrbiterAssignSaltE[((aIndex + 20U)) & S_SALT1]) + aNonceWordL;
            aOrbiterG = (((aWandererF + RotL64(aPrevious, 21U)) + RotL64(aCarry, 35U)) + 11870529476037558635U) + aNonceWordN;
            aOrbiterI = (((aWandererD + RotL64(aCross, 41U)) + RotL64(aCarry, 11U)) + 9158983227801569448U) + aNonceWordE;
            aOrbiterJ = (aWandererJ + RotL64(aIngress, 5U)) + 4710172270996950329U;
            aOrbiterD = (aWandererH + RotL64(aPrevious, 58U)) + 14634482800356647630U;
            aOrbiterF = (aWandererB + RotL64(aCross, 51U)) + 8822207952170610891U;
            aOrbiterA = (((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 51U)) + 13755891414028982553U) + aPhaseGOrbiterAssignSaltD[((aIndex + 11U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 4555293067488040719U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 2816805148093762081U;
            aOrbiterI = RotL64((aOrbiterI * 16838149138341713943U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 2122631477965135190U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 4592922416380416071U) ^ aPhaseGOrbiterUpdateSaltD[((aIndex + 26U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 11644507904538573165U), 5U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 7102471666524164715U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 17274623547879474204U) ^ aNonceWordA;
            aOrbiterK = RotL64((aOrbiterK * 5443572270546181789U), 41U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterA) + 938587316977094680U) + aNonceWordJ;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 18258015823797023523U) ^ aNonceWordK;
            aOrbiterG = RotL64((aOrbiterG * 6068819567674605919U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterI) + 5809987756043471595U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 5083075160112581620U;
            aOrbiterJ = RotL64((aOrbiterJ * 3313957222154937503U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 5960021727750946496U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5967477320950630150U) ^ aPhaseGOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 330964768256424655U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterD) + 6578428711689296132U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 5601728218197771276U;
            aOrbiterF = RotL64((aOrbiterF * 9552559022315971847U), 35U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterF, 35U);
            aIngress = aIngress + (RotL64(aOrbiterG, 47U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterJ, 54U));
            aIngress = aIngress + RotL64(aOrbiterD, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterK, 3U)) + aNonceWordM) + aPhaseGWandererUpdateSaltF[((aIndex + 7U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 35U)) + aOrbiterA) + aNonceWordO);
            aWandererB = aWandererB + (((RotL64(aIngress, 51U) + aOrbiterG) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 13U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterG, 29U)) + aOrbiterJ);
            aWandererD = aWandererD + ((((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterI, 57U)) + RotL64(aCarry, 35U)) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 36U) + RotL64(aOrbiterA, 21U)) + aOrbiterD) + aNonceWordH);
            aWandererI = aWandererI + ((RotL64(aIngress, 57U) + RotL64(aOrbiterA, 46U)) + aOrbiterF);
            //
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + (RotL64(aWandererI, 11U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererC, 4U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererH, 39U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19516U)) & S_BLOCK1], 39U) ^ RotL64(mSource[((aIndex + 21629U)) & S_BLOCK1], 30U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20128U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 20650U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordB));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 19772U)) & W_KEY1], 39U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 21174U)) & W_KEY1], 27U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 19706U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 20621U)) & S_BLOCK1], 54U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aPrevious, 5U) ^ RotL64(aCross, 22U)) + (RotL64(aIngress, 41U) + RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterD = ((aWandererC + RotL64(aIngress, 39U)) + 8988572360732005217U) + aNonceWordI;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 30U)) + 17889613225105985335U) + aNonceWordG;
            aOrbiterA = (((aWandererB + RotL64(aPrevious, 21U)) + 15563478320513948626U) + aPhaseGOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1]) + aNonceWordO;
            aOrbiterG = (((aWandererK + RotL64(aCross, 5U)) + RotL64(aCarry, 11U)) + 3441351228410524816U) + aNonceWordK;
            aOrbiterB = ((aWandererD + RotL64(aPrevious, 53U)) + RotL64(aCarry, 35U)) + 4425592689451435346U;
            aOrbiterC = ((aWandererE + RotL64(aScatter, 11U)) + 12733160231627305928U) + aPhaseGOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = ((aWandererA + RotL64(aIngress, 47U)) + RotL64(aCarry, 51U)) + 3574152157304607854U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 15167631896729808783U) + aPhaseGOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 15822667973915417055U;
            aOrbiterA = RotL64((aOrbiterA * 5155661648455308057U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 17181685481076577637U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9979204751408873468U) ^ aNonceWordN;
            aOrbiterD = RotL64((aOrbiterD * 8244434774754786565U), 3U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 1334240485667164762U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 9190066751460137016U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 14585141844653660363U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 15465215829109246336U) + aPhaseGOrbiterUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 2305208282453624419U) ^ aPhaseGOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10257861974108363283U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 16951510027310993926U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11117938943423526901U;
            aOrbiterC = RotL64((aOrbiterC * 7805486716716924787U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12461379120662979432U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 11719697049048823897U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 14880996802304818757U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 6843357278142933570U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterF) ^ 12727898578324702374U) ^ aNonceWordH;
            aOrbiterG = RotL64((aOrbiterG * 9786435451654365097U), 23U);
            //
            aIngress = RotL64(aOrbiterI, 5U) ^ aOrbiterA;
            aIngress = aIngress + (RotL64(aOrbiterG, 23U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterB, 57U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aCross, 58U) + RotL64(aOrbiterI, 3U)) + aOrbiterF) + aNonceWordP);
            aWandererE = aWandererE + (((RotL64(aIngress, 21U) + aOrbiterD) + RotL64(aOrbiterG, 42U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + aOrbiterA) + RotL64(aOrbiterG, 29U)) + aNonceWordA);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 37U) + RotL64(aOrbiterA, 19U)) + aOrbiterI) + RotL64(aCarry, 3U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aCross, 11U) + RotL64(aOrbiterC, 35U)) + aOrbiterI) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aIngress, 51U) + RotL64(aOrbiterI, 11U)) + aOrbiterB);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 29U) + aOrbiterF) + RotL64(aOrbiterC, 51U));
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 4U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererE, 35U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererD, 19U);
            aCarry = aCarry + RotL64(aIngress, 23U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 23435U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadA[((aIndex + 23457U)) & W_KEY1], 28U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 23527U)) & W_KEY1], 37U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 22842U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseGDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23488U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22719U)) & S_BLOCK1], 4U));
            aCross ^= (RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 21942U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 23176U)) & S_BLOCK1], 21U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseGDomainWordCross) ^ aNonceWordD));
            //
            aScatter = (RotL64(aIngress, 5U) + RotL64(aCross, 18U)) + (RotL64(aCarry, 57U) ^ RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseGDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterG = ((aWandererI + RotL64(aIngress, 13U)) + 9855743441035905047U) + aPhaseGOrbiterAssignSaltA[((aIndex + 25U)) & S_SALT1];
            aOrbiterA = ((aWandererE + RotL64(aScatter, 21U)) + RotL64(aCarry, 19U)) + 8426286937143990276U;
            aOrbiterJ = ((aWandererJ + RotL64(aPrevious, 47U)) + 7146752367170267002U) + aNonceWordF;
            aOrbiterD = (((aWandererD + RotL64(aCross, 27U)) + RotL64(aCarry, 43U)) + 12947210066678101726U) + aNonceWordI;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 3U)) + 15902163559925328965U;
            aOrbiterE = ((aWandererA + RotL64(aIngress, 3U)) + 8506649889346449469U) + aPhaseGOrbiterAssignSaltF[((aIndex + 22U)) & S_SALT1];
            aOrbiterK = ((aWandererF + RotL64(aCross, 40U)) + 8226286036430263052U) + aNonceWordL;
            //
            aOrbiterG = (((aOrbiterG + aOrbiterA) + 2703047093452420216U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 6769351326360139560U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 5318104980014706265U), 19U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 9857025533281333281U) + aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 238297452132277585U) ^ aNonceWordM;
            aOrbiterD = RotL64((aOrbiterD * 12974709749856065985U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 7203572312072908931U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 12497027346166575632U;
            aOrbiterA = RotL64((aOrbiterA * 1703586436725662307U), 5U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterF) + 473851890609048879U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 1664484956453886047U;
            aOrbiterG = RotL64((aOrbiterG * 8566500756326590209U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 4635095143004754116U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17695676150967345793U;
            aOrbiterF = RotL64((aOrbiterF * 5780416541584439301U), 47U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 15628965269863402796U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 9190117464399730235U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5586437438425999715U), 53U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17835918238346011086U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 4398005402429282682U;
            aOrbiterE = RotL64((aOrbiterE * 14828737209913317463U), 27U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterF, 23U);
            aIngress = aIngress + (RotL64(aOrbiterA, 44U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterJ, 3U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 43U) + RotL64(aOrbiterK, 41U)) + aOrbiterD);
            aWandererB = aWandererB + ((((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterF, 47U)) + RotL64(aCarry, 13U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterK, 11U)) + aOrbiterJ) + aNonceWordC);
            aWandererJ = aWandererJ + (((((RotL64(aCross, 37U) + aOrbiterD) + RotL64(aOrbiterE, 5U)) + RotL64(aCarry, 37U)) + aNonceWordJ) + aPhaseGWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterD, 57U)) + aPhaseGWandererUpdateSaltA[((aIndex + 16U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aPrevious, 50U) + RotL64(aOrbiterF, 18U)) + aOrbiterG);
            aWandererD = aWandererD ^ ((RotL64(aCross, 11U) + aOrbiterA) + RotL64(aOrbiterF, 27U));
            //
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererF);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 58U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 5U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 25189U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 26623U)) & W_KEY1], 11U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 25838U)) & S_BLOCK1], 23U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 24915U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 24949U)) & W_KEY1], 23U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 25196U)) & S_BLOCK1], 44U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 25620U)) & S_BLOCK1], 11U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 27186U)) & S_BLOCK1], 57U));
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCross, 35U) + RotL64(aIngress, 5U)) ^ (RotL64(aCarry, 52U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterH = ((aWandererB + RotL64(aPrevious, 51U)) + RotL64(aCarry, 51U)) + 13924571355038625040U;
            aOrbiterF = ((aWandererF + RotL64(aScatter, 3U)) + 16328300979357156658U) + aNonceWordP;
            aOrbiterE = (((aWandererI + RotL64(aCross, 23U)) + RotL64(aCarry, 13U)) + 3947771961206012461U) + aNonceWordG;
            aOrbiterG = ((aWandererK + RotL64(aIngress, 57U)) + 15428284250569311285U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterD = (aWandererJ + RotL64(aScatter, 43U)) + 5777369485254032486U;
            aOrbiterA = (((aWandererC + RotL64(aIngress, 14U)) + RotL64(aCarry, 39U)) + 16813320300717644673U) + aPhaseHOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aWandererE + RotL64(aCross, 37U)) + 16689933050200758251U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 1856422419049390708U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterH) ^ 18214498743831925517U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10744120577560529379U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 18278550878494094923U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 797712062039591797U;
            aOrbiterG = RotL64((aOrbiterG * 7212998747080137625U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 15854849439012341347U) + aNonceWordI;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 996882939768167773U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14936703950807908575U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 3005829974130671692U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterJ) ^ 8793495343509953906U) ^ aNonceWordH;
            aOrbiterA = RotL64((aOrbiterA * 14065479348374612031U), 51U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 7710453029930631112U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 9511995836117707047U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 7250766204781428201U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 670902975693341744U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 9045820304668279777U;
            aOrbiterF = RotL64((aOrbiterF * 18373074917532639027U), 11U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 12417212387607119470U) + aNonceWordL;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 12816983560669985622U;
            aOrbiterJ = RotL64((aOrbiterJ * 8406003970221889847U), 43U);
            //
            aIngress = RotL64(aOrbiterA, 39U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 58U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterE, 13U));
            aIngress = aIngress + RotL64(aOrbiterH, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aIngress, 35U) + aOrbiterF) + RotL64(aOrbiterG, 19U)) + RotL64(aCarry, 11U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 3U)) + aOrbiterA) + aPhaseHWandererUpdateSaltD[((aIndex + 27U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 29U)) + aOrbiterH) + aNonceWordM);
            aWandererI = aWandererI ^ (((RotL64(aCross, 13U) + RotL64(aOrbiterD, 41U)) + aOrbiterG) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aScatter, 3U) + aOrbiterE) + RotL64(aOrbiterJ, 48U)) + aNonceWordO);
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 21U) + RotL64(aOrbiterJ, 13U)) + aOrbiterD) + aNonceWordA);
            aWandererK = aWandererK + ((((RotL64(aPrevious, 44U) + RotL64(aOrbiterA, 35U)) + aOrbiterJ) + RotL64(aCarry, 23U)) + aNonceWordN);
            //
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererB);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 39U));
            aCarry = aCarry + (RotL64(aWandererF, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererJ, 57U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28702U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneD[((aIndex + 29514U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 27707U)) & W_KEY1], 28U) ^ RotL64(aFireLaneC[((aIndex + 28554U)) & S_BLOCK1], 39U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 29449U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 29142U)) & S_BLOCK1], 43U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 29185U)) & S_BLOCK1], 34U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 28456U)) & S_BLOCK1], 51U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aPrevious, 37U) ^ RotL64(aCarry, 10U)) + (RotL64(aCross, 23U) + RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterC = (((aWandererA + RotL64(aScatter, 57U)) + RotL64(aCarry, 11U)) + 11410829607777684449U) + aNonceWordL;
            aOrbiterD = (aWandererC + RotL64(aPrevious, 22U)) + 7502698839700975347U;
            aOrbiterB = (aWandererG + RotL64(aCross, 29U)) + 13267685058252106173U;
            aOrbiterH = (((aWandererK + RotL64(aIngress, 41U)) + RotL64(aCarry, 37U)) + 238242706996630625U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = ((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 8184695499511454281U;
            aOrbiterK = (((aWandererE + RotL64(aIngress, 35U)) + 12767823220461985403U) + aPhaseHOrbiterAssignSaltA[((aIndex + 12U)) & S_SALT1]) + aNonceWordK;
            aOrbiterG = (aWandererJ + RotL64(aPrevious, 11U)) + 12293198423143850330U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterD) + 11149495229952495939U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 7556992689338382800U;
            aOrbiterB = RotL64((aOrbiterB * 18232398462716803063U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 3431338808774134649U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 16863099140844995099U;
            aOrbiterD = RotL64((aOrbiterD * 752376661101787919U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 17872458049880677604U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 16760153457252546974U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 11225037229069712805U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 3115544493537438408U) + aNonceWordM;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 4359882942759752958U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 561477566995575801U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 13387113067202396536U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 12955690074544490161U) ^ aPhaseHOrbiterUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 12449941770827974511U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 15614054443728226807U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 1939441328066616114U;
            aOrbiterK = RotL64((aOrbiterK * 4484917074808974359U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 4599016263007782537U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 9962305629016158048U;
            aOrbiterE = RotL64((aOrbiterE * 1496184427500037279U), 11U);
            //
            aIngress = aOrbiterG ^ RotL64(aOrbiterK, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 46U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 23U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterG, 57U)) + aOrbiterB) + aNonceWordA);
            aWandererC = aWandererC + ((((RotL64(aScatter, 21U) + aOrbiterH) + RotL64(aOrbiterK, 29U)) + RotL64(aCarry, 11U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 5U) + aOrbiterB) + RotL64(aOrbiterD, 13U)) + aNonceWordC);
            aWandererA = aWandererA + ((RotL64(aIngress, 46U) + aOrbiterG) + RotL64(aOrbiterD, 22U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 11U) + aOrbiterG) + RotL64(aOrbiterC, 47U)) + aNonceWordD);
            aWandererE = aWandererE + (((RotL64(aIngress, 37U) + aOrbiterE) + RotL64(aOrbiterB, 5U)) + RotL64(aCarry, 47U));
            aWandererJ = aWandererJ ^ (((RotL64(aPrevious, 53U) + aOrbiterD) + RotL64(aOrbiterH, 41U)) + aPhaseHWandererUpdateSaltC[((aIndex + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 60U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 11U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30924U)) & S_BLOCK1], 29U) ^ RotL64(aKeyRowReadA[((aIndex + 30780U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 31630U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 31223U)) & S_BLOCK1], 37U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30545U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 32014U)) & W_KEY1], 19U));
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aPrevious, 34U) ^ RotL64(aCarry, 19U)) + (RotL64(aCross, 5U) ^ RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterB = (((aWandererH + RotL64(aIngress, 53U)) + RotL64(aCarry, 39U)) + 9041099828460168106U) + aNonceWordM;
            aOrbiterH = ((aWandererC + RotL64(aCross, 60U)) + 12883711604096848454U) + aPhaseHOrbiterAssignSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = ((aWandererG + RotL64(aScatter, 37U)) + RotL64(aCarry, 51U)) + 17420968786226443079U;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 5U)) + 3448213891716125104U;
            aOrbiterE = (((aWandererK + RotL64(aCross, 43U)) + RotL64(aCarry, 19U)) + 11866455977445336560U) + aPhaseHOrbiterAssignSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterJ = (aWandererI + RotL64(aScatter, 21U)) + 4119356835384495905U;
            aOrbiterF = ((aWandererE + RotL64(aPrevious, 13U)) + 2186212599698637068U) + aNonceWordE;
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 6506144898969301620U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 12556800923644051626U;
            aOrbiterD = RotL64((aOrbiterD * 15961043406612913121U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 4075551535185182945U;
            aOrbiterE = (aOrbiterE ^ aOrbiterD) ^ 17877694808492008749U;
            aOrbiterE = RotL64((aOrbiterE * 901315308379887473U), 43U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5553428900598223316U) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 14362304852277160675U;
            aOrbiterC = RotL64((aOrbiterC * 11415103199856419303U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 9174200302876075831U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 16110739511917638547U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7004356839428657949U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 10189881974519849402U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 2128076632642616677U;
            aOrbiterB = RotL64((aOrbiterB * 8860453653433114929U), 37U);
            //
            aOrbiterE = (((aOrbiterE + aOrbiterF) + 18133523799074400083U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordK;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 9916472958834153766U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 25U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 3454601168808001733U), 13U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 10274457562795569227U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 14134814273275356425U;
            aOrbiterF = RotL64((aOrbiterF * 15912501063665343159U), 57U);
            //
            aIngress = RotL64(aOrbiterF, 35U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterD, 5U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterH, 23U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((((RotL64(aScatter, 29U) + aOrbiterE) + RotL64(aOrbiterB, 53U)) + aNonceWordP) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 10U) + RotL64(aOrbiterH, 28U)) + aOrbiterC);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 41U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aCross, 23U) + aOrbiterB) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 11U));
            aWandererH = aWandererH ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterH, 35U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 3U)) + aOrbiterJ) + RotL64(aCarry, 53U)) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 19U)) + aOrbiterF) + aNonceWordO);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 40U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (RotL64(aWandererE, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererH, 13U);
            aCarry = aCarry + RotL64(aIngress, 4U);
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

void TwistExpander_Lacrosse_Arx::Seed_B(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0x84DF57DC4007D5D7ULL + 0x84C9CAD5241FBF99ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDD6C94E848F109D7ULL + 0xAE3AA198A394EF84ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xD5166E5245D75C5BULL + 0xE89F7C755A7F0FFAULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xAD464CA0668D42D9ULL + 0xFD9B31C68AE58CDEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x9403809EF52DF24FULL + 0xC9CC6A9E62D4F7BAULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseC(pNonce * 0xF62F03889FB2AB43ULL + 0xC6E0096F891DD49EULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA40C232916D97829ULL + 0xD7950AC24B72998FULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseC(pNonce * 0xB71348D22017DA83ULL + 0xFAA2CBBB8022BA32ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xCAE235AD5897AC9DULL + 0xD30917BCADB63576ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xD98C1CBA865C44DFULL + 0x9389E8CCA00B527AULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseA(pNonce * 0x8DF98A2D2A74AADFULL + 0xC0286DE5EAC76A14ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xDEC5AB8303F392C5ULL + 0xAE2E3AE4A57B7023ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xC1EAD54E123B1A69ULL + 0xE81C8D3886D7FAF2ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xEEAF3C55E833703FULL + 0x9B1EC3114D3C6546ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0xCB7839B11D53B8D5ULL + 0xC32F49673EC7E57AULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0x9A0279C4BB36025DULL + 0xCD1691485A6BB9D2ULL);
    // GSeedRunSeed_B seed_loop_a (start)
    {
        // GSeedRunSeed_B seed_loop_a lane group
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneD, aExpandLaneC, aExpandLaneD, aInvestLaneA, aFireLaneC, aInvestLaneB, aFireLaneA, aOperationLaneA, aFireLaneB, aOperationLaneB, aOperationLaneC
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1510U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneB[((aIndex + 4575U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 2201U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 169U)) & S_BLOCK1], 3U) ^ RotL64(aExpandLaneD[((aIndex + 3114U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 5U) + RotL64(aIngress, 50U)) ^ (RotL64(aCarry, 37U) ^ RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterF = ((aWandererB + RotL64(aScatter, 3U)) + RotL64(aCarry, 13U)) + 826930775230515406U;
            aOrbiterK = (((aWandererD + RotL64(aPrevious, 35U)) + 5137814617363250861U) + aPhaseAOrbiterAssignSaltB[((aIndex + 15U)) & S_SALT1]) + aNonceWordN;
            aOrbiterJ = ((aWandererI + RotL64(aIngress, 21U)) + 14761561947426681616U) + aPhaseAOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (((aWandererC + RotL64(aCross, 56U)) + RotL64(aCarry, 43U)) + 12773023438753662590U) + aNonceWordM;
            aOrbiterH = (((aWandererE + RotL64(aIngress, 11U)) + RotL64(aCarry, 29U)) + 7331345852207096322U) + aNonceWordP;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3899381212671247460U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 10072004147620068599U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 5663583566047763435U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 3424585039401897560U) + aNonceWordC;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 8246760141625966321U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11478879365443736383U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 3655992860610853290U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterJ) ^ 11154618022505863898U) ^ aNonceWordK;
            aOrbiterH = RotL64((aOrbiterH * 4791494171286145231U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 15629361991059709973U;
            aOrbiterF = (aOrbiterF ^ aOrbiterE) ^ 10842068502278489664U;
            aOrbiterF = RotL64((aOrbiterF * 17223002513104960799U), 57U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterF) + 5571312349016336686U) + aNonceWordA;
            aOrbiterK = ((aOrbiterK ^ aOrbiterH) ^ 589313823745748879U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1356685926549786027U), 29U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterF, 34U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterE, 23U));
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((((RotL64(aPrevious, 24U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + RotL64(aCarry, 47U)) + aPhaseAWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 51U)) + aOrbiterE);
            aWandererE = aWandererE + (((RotL64(aScatter, 3U) + RotL64(aOrbiterE, 5U)) + aOrbiterH) + aNonceWordI);
            aWandererI = aWandererI ^ ((RotL64(aCross, 43U) + aOrbiterF) + RotL64(aOrbiterJ, 23U));
            aWandererD = aWandererD + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterE, 14U)) + aOrbiterF) + RotL64(aCarry, 11U)) + aNonceWordF) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 43U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererD, 3U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aInvestLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_a loop 2
        // ingress from: aInvestLaneA, aExpandLaneC, aFireLaneC
        // ingress directions: aInvestLaneA forward forced, aExpandLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aExpandLaneA, aExpandLaneD
        // cross directions: aExpandLaneA backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneA[((aIndex + 7589U)) & S_BLOCK1], 39U) ^ RotL64(aExpandLaneC[((aIndex + 10120U)) & S_BLOCK1], 56U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 10736U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordI));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 8862U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 10835U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCross, 6U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCarry, 19U) ^ RotL64(aIngress, 39U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterC = (aWandererC + RotL64(aIngress, 43U)) + 6771552164800695068U;
            aOrbiterF = (((aWandererK + RotL64(aScatter, 53U)) + RotL64(aCarry, 53U)) + 12131763371571322040U) + aNonceWordN;
            aOrbiterI = ((((aWandererB + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 3326182381395522013U) + aPhaseAOrbiterAssignSaltD[((aIndex + 13U)) & S_SALT1]) + aNonceWordE;
            aOrbiterB = (((aWandererI + RotL64(aPrevious, 12U)) + RotL64(aCarry, 27U)) + 12288775097697156383U) + aNonceWordC;
            aOrbiterA = (((aWandererJ + RotL64(aIngress, 27U)) + 5195948373449796741U) + aPhaseAOrbiterAssignSaltA[((aIndex + 28U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 14404044002250137144U) + aNonceWordB;
            aOrbiterI = ((aOrbiterI ^ aOrbiterC) ^ 11142382920035825426U) ^ aNonceWordP;
            aOrbiterI = RotL64((aOrbiterI * 8134413822789107595U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 2967149520256475485U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 1470907369577818097U;
            aOrbiterA = RotL64((aOrbiterA * 9398653295177725883U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 9231668148004163910U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterC = (((aOrbiterC ^ aOrbiterB) ^ 13078929163913892386U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 29U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterC = RotL64((aOrbiterC * 7509829068700523627U), 35U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 9485274692075657877U) + aPhaseAOrbiterUpdateSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterI) ^ 12216951187543631673U) ^ aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6571066246507310805U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 6933334652581744234U;
            aOrbiterB = (aOrbiterB ^ aOrbiterA) ^ 17260276102423580920U;
            aOrbiterB = RotL64((aOrbiterB * 7796879893790990605U), 43U);
            //
            aIngress = RotL64(aOrbiterF, 37U) ^ aOrbiterI;
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterC, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aCross, 39U) + RotL64(aOrbiterB, 35U)) + aOrbiterA) + aNonceWordM) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB + ((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 54U)) + aOrbiterC) + RotL64(aCarry, 39U)) + aNonceWordJ);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + RotL64(aOrbiterA, 11U)) + aOrbiterC);
            aWandererK = aWandererK + (((((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterA, 43U)) + RotL64(aCarry, 19U)) + aNonceWordD) + aPhaseAWandererUpdateSaltB[((aIndex + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 5U) + aOrbiterI) + RotL64(aOrbiterB, 27U)) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererK, 21U);
            aCarry = aCarry + RotL64(aIngress, 5U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 15640U)) & S_BLOCK1], 46U) ^ RotL64(aExpandLaneD[((aIndex + 13359U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 14797U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 14951U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14575U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 16194U)) & S_BLOCK1], 43U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 53U) ^ RotL64(aPrevious, 3U)) ^ (RotL64(aIngress, 18U) + RotL64(aCarry, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterC = ((aWandererH + RotL64(aIngress, 43U)) + 3612110001869385068U) + aNonceWordI;
            aOrbiterB = ((((aWandererK + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 16340824141280225936U) + aPhaseAOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1]) + aNonceWordL;
            aOrbiterK = (aWandererC + RotL64(aPrevious, 3U)) + 15222338965130765231U;
            aOrbiterA = (((aWandererF + RotL64(aScatter, 24U)) + RotL64(aCarry, 41U)) + 6649270508107155041U) + aNonceWordN;
            aOrbiterD = (((aWandererI + RotL64(aPrevious, 13U)) + RotL64(aCarry, 29U)) + 768217258655426384U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 4481855259658861851U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 18318041934562434016U) ^ aNonceWordJ;
            aOrbiterK = RotL64((aOrbiterK * 14913761339765234979U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 4212457153804401807U) + aPhaseAOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 16143621095636987628U;
            aOrbiterD = RotL64((aOrbiterD * 6576072860505961427U), 37U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterC) + 2095664232866642086U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterB = (((aOrbiterB ^ aOrbiterD) ^ 4339527736737366572U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 28U)) & S_SALT1]) ^ aNonceWordK;
            aOrbiterB = RotL64((aOrbiterB * 17503569508822244125U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 13679353177869884790U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11582168502846418236U;
            aOrbiterC = RotL64((aOrbiterC * 135539430034462861U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 10451330452898542191U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12951448817640617841U;
            aOrbiterA = RotL64((aOrbiterA * 4141870904192742091U), 29U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 54U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 5U));
            aIngress = aIngress + RotL64(aOrbiterB, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC + (((((RotL64(aScatter, 11U) + RotL64(aOrbiterK, 13U)) + aOrbiterC) + RotL64(aCarry, 3U)) + aNonceWordA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 26U) + RotL64(aOrbiterC, 4U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterD, 51U));
            aWandererF = aWandererF ^ (((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterK, 29U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((((RotL64(aCross, 47U) + aOrbiterB) + RotL64(aOrbiterC, 37U)) + RotL64(aCarry, 39U)) + aNonceWordH);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererH, 40U));
            aCarry = aCarry + (RotL64(aWandererK, 5U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererI, 53U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21743U)) & S_BLOCK1], 13U) ^ RotL64(aInvestLaneA[((aIndex + 19736U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 20592U)) & S_BLOCK1], 60U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17373U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 18714U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 19851U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 3U)) + (RotL64(aCross, 35U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterE = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 35U)) + 13714409587461539863U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aCross, 19U)) + 14101156723903265839U) + aPhaseAOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordE;
            aOrbiterF = (((aWandererH + RotL64(aIngress, 10U)) + RotL64(aCarry, 21U)) + 7063754562895369001U) + aNonceWordF;
            aOrbiterK = ((aWandererG + RotL64(aPrevious, 51U)) + 12320578575245519386U) + aNonceWordM;
            aOrbiterB = (((aWandererA + RotL64(aCross, 43U)) + RotL64(aCarry, 53U)) + 11744826789631008424U) + aNonceWordK;
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 8744816505096675597U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 10405435520084528645U) ^ aNonceWordI;
            aOrbiterF = RotL64((aOrbiterF * 13279521344071568023U), 53U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterF) + 1463157688070683543U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 12379603577919617703U;
            aOrbiterK = RotL64((aOrbiterK * 14858901470015109311U), 13U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterK) + 1343439118031348146U) + aPhaseAOrbiterUpdateSaltE[((aIndex + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 16118850268070235540U;
            aOrbiterB = RotL64((aOrbiterB * 11184386483735388257U), 27U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterB) + 14116264435819277136U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5251698273012432109U) ^ aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 1495818611622063967U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterE) + 14806408656041403829U) + aNonceWordP;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 11569345414052398227U;
            aOrbiterD = RotL64((aOrbiterD * 9913158908301414861U), 35U);
            //
            aIngress = RotL64(aOrbiterK, 30U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterB, 5U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterE, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ (((RotL64(aIngress, 12U) + RotL64(aOrbiterB, 51U)) + aOrbiterK) + aNonceWordB);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 39U) + aOrbiterB) + RotL64(aOrbiterE, 13U)) + RotL64(aCarry, 21U)) + aNonceWordH);
            aWandererA = aWandererA ^ (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterD, 41U)) + aPhaseAWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 5U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aNonceWordO) + aPhaseAWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 29U) + RotL64(aOrbiterF, 30U)) + aOrbiterB) + aNonceWordG);
            //
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererJ, 3U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 24382U)) & S_BLOCK1], 6U) ^ RotL64(aOperationLaneA[((aIndex + 23915U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27275U)) & S_BLOCK1], 37U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26124U)) & S_BLOCK1], 21U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 25950U)) & S_BLOCK1], 5U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 25708U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aIngress, 10U) + RotL64(aCarry, 41U)) ^ (RotL64(aCross, 53U) + RotL64(aPrevious, 29U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterC = ((((aWandererJ + RotL64(aIngress, 5U)) + RotL64(aCarry, 21U)) + 15316464782468770057U) + aPhaseAOrbiterAssignSaltA[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordD;
            aOrbiterJ = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 51U)) + 6642872057476351588U;
            aOrbiterF = ((aWandererG + RotL64(aCross, 35U)) + 660732654689529192U) + aNonceWordE;
            aOrbiterD = (((aWandererE + RotL64(aPrevious, 14U)) + RotL64(aCarry, 39U)) + 7235418086884000655U) + aNonceWordN;
            aOrbiterB = (((aWandererF + RotL64(aIngress, 27U)) + 14784518476694580493U) + aPhaseAOrbiterAssignSaltD[((aIndex + 23U)) & S_SALT1]) + aNonceWordH;
            //
            aOrbiterC = (((aOrbiterC + aOrbiterJ) + 12222433977933449375U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1]) + aNonceWordM;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 8573001207708329927U;
            aOrbiterF = RotL64((aOrbiterF * 17771120145431297541U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 16035256260815013172U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 15767726974121910203U) ^ aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 719060452537759331U), 11U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 17712217935322939971U) + aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 13488963456923357159U) ^ aNonceWordA;
            aOrbiterD = RotL64((aOrbiterD * 16785285630840310405U), 51U);
            //
            aOrbiterB = (((aOrbiterB + aOrbiterF) + 10222949131965611079U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 6U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 1495561412321657209U) ^ aNonceWordJ;
            aOrbiterC = RotL64((aOrbiterC * 9706305581868526265U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16156530750584361434U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 7773792489045606309U;
            aOrbiterB = RotL64((aOrbiterB * 10730624207715601393U), 23U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterD, 53U);
            aIngress = aIngress + (RotL64(aOrbiterC, 13U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 38U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ ^ (((RotL64(aCross, 3U) + aOrbiterC) + RotL64(aOrbiterJ, 11U)) + aNonceWordP);
            aWandererE = aWandererE + ((((RotL64(aScatter, 37U) + aOrbiterJ) + RotL64(aOrbiterB, 35U)) + RotL64(aCarry, 57U)) + aPhaseAWandererUpdateSaltB[((aIndex + 18U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 44U)) + aOrbiterC) + aNonceWordI);
            aWandererG = aWandererG + (((RotL64(aIngress, 14U) + RotL64(aOrbiterF, 3U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 53U) + aOrbiterF) + RotL64(aOrbiterD, 23U)) + aPhaseAWandererUpdateSaltE[(((31U - aIndex) + 21U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 24U) ^ aWandererF);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 3U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 29030U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneA[((aIndex + 32614U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aExpandLaneB[((aIndex + 29342U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseADomainWordIngress) ^ aNonceWordH));
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 27766U)) & S_BLOCK1], 5U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 30364U)) & S_BLOCK1], 56U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 29690U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseADomainWordCross) ^ aNonceWordM));
            //
            aScatter = (RotL64(aCarry, 41U) ^ RotL64(aPrevious, 57U)) + (RotL64(aIngress, 29U) ^ RotL64(aCross, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseADomainWordScatter) ^ aNonceWordN));
            //
            aOrbiterK = (((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 5U)) + 2101601659597850213U) + aNonceWordL;
            aOrbiterH = (((aWandererG + RotL64(aScatter, 52U)) + RotL64(aCarry, 21U)) + 2759794072560720121U) + aPhaseAOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterG = (((aWandererC + RotL64(aCross, 3U)) + 9443562552411269339U) + aPhaseAOrbiterAssignSaltF[((aIndex + 15U)) & S_SALT1]) + aNonceWordG;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 21U)) + RotL64(aCarry, 37U)) + 10801360546699857975U) + aNonceWordK;
            aOrbiterE = ((aWandererA + RotL64(aCross, 13U)) + 8020716394829332019U) + aNonceWordN;
            //
            aOrbiterK = (((aOrbiterK + aOrbiterH) + 1021894212367773801U) + aPhaseAOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1]) + aNonceWordD;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 13346855534622490176U;
            aOrbiterG = RotL64((aOrbiterG * 12668950387932320985U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 16359309548462953836U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 12642446944680783519U) ^ aPhaseAOrbiterUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 12197935153255283321U), 21U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 8197424982767553380U) + aNonceWordE;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 14346334610901859094U;
            aOrbiterK = RotL64((aOrbiterK * 16982899923227935679U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 14171304260534233539U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 334531601308283605U) ^ aPhaseAOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 5012968232749075075U), 37U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 10707856298471572695U) + aPhaseAOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 18364775750091914766U;
            aOrbiterE = RotL64((aOrbiterE * 15735143943129143265U), 57U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterK, 11U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 47U));
            aIngress = aIngress + RotL64(aOrbiterH, 23U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterK, 21U)) + aOrbiterF);
            aWandererG = aWandererG + ((((RotL64(aCross, 23U) + RotL64(aOrbiterK, 56U)) + aOrbiterG) + RotL64(aCarry, 13U)) + aPhaseAWandererUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aPrevious, 13U) + aOrbiterE) + RotL64(aOrbiterH, 37U)) + aNonceWordP) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aScatter, 3U) + aOrbiterF) + RotL64(aOrbiterH, 11U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererF = aWandererF ^ ((RotL64(aCross, 50U) + aOrbiterG) + RotL64(aOrbiterH, 47U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 11U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererC, 27U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererG, 3U);
            aCarry = aCarry + RotL64(aIngress, 41U);
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

void TwistExpander_Lacrosse_Arx::Seed_C(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseB(pNonce * 0xD2171A79D36CF88FULL + 0xC2490927A6DE94F4ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xFE21F13C95CB47A3ULL + 0xAC1243779C4CF60EULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xE96624DF7E64B101ULL + 0xABD8B6982B91982DULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseB(pNonce * 0xF682AC7749067A4BULL + 0xAFB12D04F4FDFA65ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0x8394988F327126B1ULL + 0xF82BBCE90BE9BA01ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xA7847A7C984562C5ULL + 0xD8964EEBCB3A2F37ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD3AD1E26BDAD8B7BULL + 0xE2751C9B3E053980ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xADC39306EEA63ACBULL + 0xB321F423676A1301ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xA2B5BABA3D8C549BULL + 0xFF8DF830F9C9355EULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0xBDCD434C82039DE3ULL + 0xC7101BE3B7AD817DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseC(pNonce * 0x8CFC14107A39C881ULL + 0x930F11128698EBC2ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseA(pNonce * 0xFEC20980C7DF06F3ULL + 0xB2075F6C535CF123ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xE5EF72090F33033FULL + 0xB0C7EAAF1AA8FC7CULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseA(pNonce * 0x93574B7B274548C5ULL + 0xDD85988E935F24ABULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseA(pNonce * 0xFF2236C0607BBDF1ULL + 0xE801F965A1C2480DULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xFF2961E115A7BDDDULL + 0xED78F731CFE70DFBULL);
    // GSeedRunSeed_C seed_loop_b (start)
    {
        // GSeedRunSeed_C seed_loop_b lane group
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneB, aOperationLaneC, aOperationLaneD, aFireLaneB, aInvestLaneC, aExpandLaneA, aExpandLaneC, aInvestLaneD, aFireLaneD, aWorkLaneA, aFireLaneC, aWorkLaneB, aExpandLaneD, aWorkLaneC, aFireLaneA
        // write to: aInvestLaneC, aInvestLaneD, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // seed_loop_b loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneB
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneB forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aFireLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aFireLaneB backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2880U)) & S_BLOCK1], 40U) ^ RotL64(aOperationLaneB[((aIndex + 5212U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 342U)) & S_BLOCK1], 11U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 5337U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1062U)) & S_BLOCK1], 11U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 5148U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 37U) ^ RotL64(aPrevious, 54U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordF));
            //
            aOrbiterK = (((aWandererJ + RotL64(aPrevious, 47U)) + RotL64(aCarry, 27U)) + 13583136155674166402U) + aPhaseBOrbiterAssignSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aScatter, 35U)) + 12830472187484919497U;
            aOrbiterB = ((aWandererI + RotL64(aCross, 10U)) + 18081197909484522509U) + aNonceWordH;
            aOrbiterF = (aWandererF + RotL64(aIngress, 5U)) + 8680634051297891550U;
            aOrbiterA = ((aWandererB + RotL64(aCross, 53U)) + RotL64(aCarry, 53U)) + 13939998767458656823U;
            aOrbiterG = (aWandererK + RotL64(aPrevious, 57U)) + 1795730579103692594U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 17369751719734069999U) + aNonceWordI;
            aOrbiterI = (aWandererD + RotL64(aIngress, 40U)) + 224769585901248068U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 29U)) + 4133547085925268180U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 23U)) & S_SALT1];
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7022512056309567391U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 10319484359046945495U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 3400140531307001933U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 10483878349412282069U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 6481381149199985736U;
            aOrbiterA = RotL64((aOrbiterA * 9701719367082506253U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 13721077228796934509U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterA) ^ 9704818014314175007U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 760445624027740287U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 6253040047758584339U;
            aOrbiterK = (((aOrbiterK ^ aOrbiterC) ^ 16890211690273641226U) ^ aPhaseBOrbiterUpdateSaltC[((aIndex + 18U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterK = RotL64((aOrbiterK * 5622534399866057841U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6216227831265032436U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 2023609047004658739U;
            aOrbiterE = RotL64((aOrbiterE * 3252332895698310147U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 9201669637050388263U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 5106927540934338576U;
            aOrbiterD = RotL64((aOrbiterD * 6368134569042291431U), 35U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 10080368957861445998U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 10784789383436485808U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 3794918350254445939U), 47U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 15426339824951793026U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 17637144549368340331U;
            aOrbiterI = RotL64((aOrbiterI * 10971293914614704441U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterC) + 9941300382181962134U) + aPhaseBOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterI) ^ 8118046374121322097U;
            aOrbiterF = RotL64((aOrbiterF * 8481945819050983127U), 3U);
            //
            aIngress = RotL64(aOrbiterG, 51U) ^ aOrbiterB;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 24U));
            aIngress = aIngress + (RotL64(aOrbiterK, 27U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 21U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterD, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 57U)) + aOrbiterG);
            aWandererD = aWandererD + (((RotL64(aScatter, 39U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + RotL64(aCarry, 5U));
            aWandererJ = aWandererJ ^ ((((RotL64(aIngress, 10U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + aNonceWordF) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 44U)) + aOrbiterB);
            aWandererI = aWandererI ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterC, 19U)) + aOrbiterE) + aNonceWordD);
            aWandererB = aWandererB + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterD, 39U)) + aOrbiterF) + RotL64(aCarry, 43U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterA, 5U)) + aOrbiterF);
            aWandererH = aWandererH + (((RotL64(aIngress, 51U) + RotL64(aOrbiterK, 35U)) + aOrbiterI) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterG, 10U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 23U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 51U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + RotL64(aWandererK, 30U);
            aCarry = aCarry + RotL64(aIngress, 35U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aInvestLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 2
        // ingress from: aInvestLaneC, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aInvestLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aExpandLaneC
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aExpandLaneC backward/forward random
        // write to: aInvestLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneC[((aIndex + 5688U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 7258U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 7291U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6200U)) & S_BLOCK1], 58U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 7379U)) & S_BLOCK1], 21U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9094U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 7370U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 35U)) + (RotL64(aCross, 5U) ^ RotL64(aPrevious, 47U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterG = (aWandererF + RotL64(aPrevious, 51U)) + 11521331427196538632U;
            aOrbiterK = ((aWandererB + RotL64(aCross, 29U)) + RotL64(aCarry, 3U)) + 16653824187682957632U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 19U)) + 11654676587350088289U) + aNonceWordG;
            aOrbiterJ = ((aWandererH + RotL64(aIngress, 35U)) + 8010313317412193584U) + aPhaseBOrbiterAssignSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = (aWandererG + RotL64(aPrevious, 56U)) + 1108775560502907471U;
            aOrbiterI = (aWandererI + RotL64(aScatter, 3U)) + 243952321439823521U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 41U)) + RotL64(aCarry, 11U)) + 2324945800401240403U;
            aOrbiterH = ((aWandererJ + RotL64(aCross, 13U)) + 9257554497543369657U) + aPhaseBOrbiterAssignSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (((aWandererD + RotL64(aPrevious, 60U)) + RotL64(aCarry, 37U)) + 16701314607244592540U) + aNonceWordH;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3900445848034341782U;
            aOrbiterE = (aOrbiterE ^ aOrbiterG) ^ 7652316487347103658U;
            aOrbiterE = RotL64((aOrbiterE * 11480123491361589799U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 14980368605272070578U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 2001165460948764796U;
            aOrbiterC = RotL64((aOrbiterC * 8110980921827107649U), 21U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterE) + 1911044015666991050U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 11366207111147818339U;
            aOrbiterI = RotL64((aOrbiterI * 17234439040652553865U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16469329744002456607U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 8062793687044950815U;
            aOrbiterG = RotL64((aOrbiterG * 5856142259851144369U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 15364721421972807872U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 8979915611483540231U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10899377466171153383U), 47U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 7654234623563110457U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterH) ^ 1526832460342135008U) ^ aNonceWordD;
            aOrbiterJ = RotL64((aOrbiterJ * 12766083052650723051U), 51U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 1596625448797520938U) + aNonceWordP;
            aOrbiterA = ((aOrbiterA ^ aOrbiterE) ^ 15723912914858523080U) ^ aNonceWordF;
            aOrbiterA = RotL64((aOrbiterA * 6003857787643420337U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 7664226719746532168U;
            aOrbiterH = (aOrbiterH ^ aOrbiterD) ^ 13767298788411473401U;
            aOrbiterH = RotL64((aOrbiterH * 15663266144965532019U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 8371251860069346385U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10143279934304029980U;
            aOrbiterD = RotL64((aOrbiterD * 12764966547132248131U), 13U);
            //
            aIngress = RotL64(aOrbiterJ, 10U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterA, 3U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterH, 37U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterE, 47U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterC, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererD = aWandererD ^ ((RotL64(aCross, 27U) + aOrbiterJ) + RotL64(aOrbiterG, 19U));
            aWandererH = aWandererH + ((RotL64(aPrevious, 53U) + RotL64(aOrbiterD, 34U)) + aOrbiterE);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 14U) + RotL64(aOrbiterC, 29U)) + aOrbiterK);
            aWandererF = aWandererF + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterJ, 57U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 39U) + RotL64(aOrbiterE, 3U)) + aOrbiterC) + aNonceWordM);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 24U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordB);
            aWandererB = aWandererB ^ (((RotL64(aIngress, 3U) + aOrbiterG) + RotL64(aOrbiterH, 51U)) + aNonceWordN);
            aWandererA = aWandererA + ((((RotL64(aCross, 58U) + RotL64(aOrbiterA, 39U)) + aOrbiterI) + RotL64(aCarry, 53U)) + aNonceWordK);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 47U) + aOrbiterH) + RotL64(aOrbiterI, 47U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 14U));
            aCarry = aCarry + (RotL64(aWandererD, 19U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererK, 51U) ^ aWandererH);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererA, 5U);
            aCarry = aCarry + RotL64(aIngress, 43U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_b loop 3
        // ingress from: aInvestLaneD, aOperationLaneA, aFireLaneD
        // ingress directions: aInvestLaneD forward forced, aOperationLaneA forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneC, aOperationLaneC
        // cross directions: aInvestLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 11066U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneA[((aIndex + 13599U)) & S_BLOCK1], 6U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 14498U)) & S_BLOCK1], 23U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordC));
            //
            aCross = RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13064U)) & S_BLOCK1], 24U) ^ RotL64(aOperationLaneC[((aIndex + 15417U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordF));
            //
            aScatter = (RotL64(aPrevious, 53U) + RotL64(aCarry, 41U)) ^ (RotL64(aIngress, 18U) + RotL64(aCross, 5U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = ((aWandererG + RotL64(aScatter, 24U)) + 7825479804710770560U) + aPhaseBOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 57U)) + 5298124167101358123U;
            aOrbiterE = ((aWandererK + RotL64(aPrevious, 39U)) + RotL64(aCarry, 41U)) + 17774541024369233726U;
            aOrbiterK = ((aWandererB + RotL64(aIngress, 35U)) + 7679371833537454082U) + aNonceWordL;
            aOrbiterH = (aWandererJ + RotL64(aCross, 47U)) + 5385914900748772224U;
            aOrbiterF = (aWandererC + RotL64(aPrevious, 29U)) + 3879781930908486531U;
            aOrbiterJ = (((aWandererA + RotL64(aScatter, 13U)) + RotL64(aCarry, 3U)) + 659110346638873236U) + aPhaseBOrbiterAssignSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aIngress, 3U)) + 10749021728538539749U) + aNonceWordG;
            aOrbiterC = ((aWandererI + RotL64(aCross, 20U)) + RotL64(aCarry, 29U)) + 3631252455767429457U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 2271978810960685021U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5963558780692551176U) ^ aNonceWordH;
            aOrbiterE = RotL64((aOrbiterE * 4772055335210781149U), 11U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterE) + 974909966119198104U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 15U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 9296998242911152296U;
            aOrbiterH = RotL64((aOrbiterH * 2613629915877957661U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 2245318466901521959U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13391076374843288568U;
            aOrbiterA = RotL64((aOrbiterA * 18094558036982107419U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6184487746594236737U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 1563385912137291418U;
            aOrbiterF = RotL64((aOrbiterF * 4805455299959232321U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 1744840092006498629U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 2100927276837188416U;
            aOrbiterI = RotL64((aOrbiterI * 3541788262067077997U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 9998911862807246338U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 12239948725635220096U;
            aOrbiterK = RotL64((aOrbiterK * 7098620484129489129U), 3U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterK) + 3307447094994950246U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 12746613971448298932U;
            aOrbiterJ = RotL64((aOrbiterJ * 9463975886346934681U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 11577488293733790649U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 191108997585598809U) ^ aNonceWordD;
            aOrbiterC = RotL64((aOrbiterC * 9574978681405356871U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 18096145693841273722U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterJ) ^ 10026281133603934071U) ^ aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17261343107314203471U), 19U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 41U);
            aIngress = aIngress + (RotL64(aOrbiterI, 50U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterJ, 57U) ^ aOrbiterK);
            aIngress = aIngress + (RotL64(aOrbiterF, 21U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterA, 53U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + (((RotL64(aScatter, 60U) + aOrbiterI) + RotL64(aOrbiterF, 39U)) + aNonceWordN);
            aWandererI = aWandererI ^ ((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterE, 28U));
            aWandererC = aWandererC + (((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterI, 19U)) + aPhaseBWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterJ, 35U));
            aWandererB = aWandererB + (((RotL64(aIngress, 44U) + RotL64(aOrbiterA, 43U)) + aOrbiterD) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ (((RotL64(aCross, 53U) + RotL64(aOrbiterC, 51U)) + aOrbiterF) + aNonceWordK);
            aWandererH = aWandererH + ((((RotL64(aScatter, 29U) + aOrbiterD) + RotL64(aOrbiterH, 13U)) + aNonceWordP) + aPhaseBWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 5U) + aOrbiterK) + RotL64(aOrbiterI, 24U));
            aWandererK = aWandererK + ((((RotL64(aCross, 23U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 27U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererA, 6U) ^ aWandererB);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 43U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 47U));
            aCarry = aCarry + RotL64(aWandererH, 19U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 4
        // ingress from: aWorkLaneA, aInvestLaneC, aFireLaneC
        // ingress directions: aWorkLaneA forward forced, aInvestLaneC forward forced, aFireLaneC forward/backward random
        // cross from: aInvestLaneD, aOperationLaneD
        // cross directions: aInvestLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 16450U)) & S_BLOCK1], 52U) ^ RotL64(aInvestLaneC[((aIndex + 17543U)) & S_BLOCK1], 41U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 20209U)) & S_BLOCK1], 5U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordB));
            //
            aCross = RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 16790U)) & S_BLOCK1], 58U) ^ RotL64(aOperationLaneD[((aIndex + 17089U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aPrevious, 38U) + RotL64(aCarry, 51U)) ^ (RotL64(aIngress, 23U) ^ RotL64(aCross, 3U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterK = (((aWandererJ + RotL64(aIngress, 34U)) + RotL64(aCarry, 47U)) + 3621877681473089725U) + aPhaseBOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 53U)) + RotL64(aCarry, 21U)) + 4451752751536414717U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 23U)) + RotL64(aCarry, 39U)) + 11371625415377772117U) + aNonceWordD;
            aOrbiterB = ((aWandererF + RotL64(aScatter, 3U)) + 6046792758881150619U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aPrevious, 29U)) + 8213166120394461682U;
            aOrbiterD = ((aWandererK + RotL64(aScatter, 46U)) + 4343156661140422645U) + aNonceWordH;
            aOrbiterI = (aWandererD + RotL64(aIngress, 41U)) + 11105271483234947905U;
            aOrbiterC = ((aWandererI + RotL64(aCross, 11U)) + 348904609985341372U) + aNonceWordK;
            aOrbiterH = (aWandererB + RotL64(aPrevious, 57U)) + 12924652822526858767U;
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 7461211697358520287U;
            aOrbiterG = (((aOrbiterG ^ aOrbiterK) ^ 16551553555297890558U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterG = RotL64((aOrbiterG * 16432952324635746293U), 11U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11908056404140782995U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterB) ^ 9147367258259948715U) ^ aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 10777628928376261667U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 8876461054692728610U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 10546855952702525404U;
            aOrbiterD = RotL64((aOrbiterD * 10071104785895309677U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 4748636139110443794U) + aNonceWordN;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterI) ^ 783046909529525098U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 27U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 8969157702460927215U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 16683965945838696665U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 12385412690177109575U;
            aOrbiterB = RotL64((aOrbiterB * 10795062772707143187U), 43U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 8210546822184469023U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 13146493623236979963U;
            aOrbiterK = RotL64((aOrbiterK * 13199947810161148155U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterH) + 13857628148804187115U) + aNonceWordF;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 7241297989337473475U;
            aOrbiterC = RotL64((aOrbiterC * 16223448508809614229U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 773904571213804946U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 7660676598236419707U;
            aOrbiterH = RotL64((aOrbiterH * 14467390638468925567U), 47U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16822672435156055469U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterH) ^ 6514707119190640433U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7097496727567460535U), 5U);
            //
            aIngress = RotL64(aOrbiterB, 13U) ^ aOrbiterC;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 48U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterC, 10U)) + aOrbiterB) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aCross, 60U) + RotL64(aOrbiterI, 5U)) + aOrbiterB) + aNonceWordO);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 43U) + aOrbiterB) + RotL64(aOrbiterJ, 47U)) + RotL64(aCarry, 11U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 11U) + aOrbiterA) + RotL64(aOrbiterH, 53U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 35U)) + aOrbiterC) + aNonceWordC);
            aWandererI = aWandererI ^ (((RotL64(aIngress, 19U) + aOrbiterK) + RotL64(aOrbiterB, 57U)) + aNonceWordL);
            aWandererE = aWandererE + ((RotL64(aPrevious, 26U) + aOrbiterH) + RotL64(aOrbiterG, 18U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 47U) + RotL64(aOrbiterD, 43U)) + aOrbiterB) + aPhaseBWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aScatter, 51U) + aOrbiterJ) + RotL64(aOrbiterA, 23U)) + aNonceWordM);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 19U) ^ aWandererE);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererD, 38U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererC);
            aCarry = aCarry + RotL64(aWandererH, 43U);
            aCarry = aCarry + RotL64(aIngress, 29U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 26921U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneD[((aIndex + 26250U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 24241U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 25918U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((aIndex + 25899U)) & S_BLOCK1], 6U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aIngress, 40U) ^ RotL64(aCross, 3U)) + (RotL64(aCarry, 53U) + RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordO));
            //
            aOrbiterJ = (aWandererC + RotL64(aCross, 52U)) + 13350544654542863236U;
            aOrbiterD = (aWandererG + RotL64(aIngress, 35U)) + 12364346790125404372U;
            aOrbiterE = ((aWandererB + RotL64(aPrevious, 5U)) + 9738750172849512764U) + aPhaseBOrbiterAssignSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (((aWandererK + RotL64(aScatter, 57U)) + 3781373837635491421U) + aPhaseBOrbiterAssignSaltE[((aIndex + 12U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererI + RotL64(aCross, 19U)) + RotL64(aCarry, 47U)) + 16635020317512702337U;
            aOrbiterA = ((aWandererA + RotL64(aIngress, 14U)) + RotL64(aCarry, 39U)) + 5383653921676231276U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 29U)) + RotL64(aCarry, 19U)) + 10181959815492056493U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 47U)) + 10005510924273927017U) + aNonceWordJ;
            aOrbiterF = (aWandererE + RotL64(aIngress, 23U)) + 9524687662265740565U;
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 4259138552009771014U) + aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 8973051213213726023U) ^ aNonceWordG;
            aOrbiterE = RotL64((aOrbiterE * 12625091476068190979U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 17602611840127337490U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 8218984546932905269U) ^ aPhaseBOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17504305273683304231U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18102186122213487888U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 2629927500298092976U;
            aOrbiterK = RotL64((aOrbiterK * 6983280164448292723U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 2491581597835795234U) + aNonceWordA;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 9506602492971620955U;
            aOrbiterA = RotL64((aOrbiterA * 9559829640915637163U), 35U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 13422942713680612924U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterI) ^ 15037354693234876601U) ^ aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12692376075738621447U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12896066842192894694U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 2202952306291905855U) ^ aPhaseBOrbiterUpdateSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6779368532763429997U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 12160313482450599313U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 10812986281270407756U;
            aOrbiterJ = RotL64((aOrbiterJ * 7786608700746771809U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 12474638293190144525U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterB) ^ 5882870951276225224U) ^ aNonceWordN;
            aOrbiterI = RotL64((aOrbiterI * 15532427302173572457U), 23U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 3782896138051179209U) + aNonceWordC;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10965680631059882311U;
            aOrbiterH = RotL64((aOrbiterH * 14060923998307082385U), 19U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterK, 21U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterF, 18U));
            aIngress = aIngress + (RotL64(aOrbiterB, 39U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterD, 43U) ^ aOrbiterE);
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aScatter, 19U) + aOrbiterJ) + RotL64(aOrbiterE, 36U)) + aNonceWordF) + aPhaseBWandererUpdateSaltE[((aIndex + 16U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterD, 13U)) + aOrbiterB);
            aWandererK = aWandererK + (((RotL64(aCross, 41U) + RotL64(aOrbiterJ, 57U)) + aOrbiterK) + RotL64(aCarry, 51U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 57U) + aOrbiterK) + RotL64(aOrbiterF, 3U)) + aNonceWordL);
            aWandererF = aWandererF + (((RotL64(aScatter, 46U) + aOrbiterI) + RotL64(aOrbiterB, 21U)) + RotL64(aCarry, 3U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterE) + RotL64(aOrbiterB, 29U));
            aWandererD = aWandererD + (((RotL64(aCross, 5U) + aOrbiterA) + RotL64(aOrbiterE, 40U)) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aIngress, 13U) + RotL64(aOrbiterH, 47U)) + aOrbiterB);
            aWandererA = aWandererA + (((RotL64(aPrevious, 28U) + aOrbiterE) + RotL64(aOrbiterF, 51U)) + aNonceWordO);
            //
            aCarry = aCarry + (RotL64(aWandererG, 43U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 26U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (RotL64(aWandererD, 53U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererF, 11U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_b loop 6
        // ingress from: aWorkLaneC, aWorkLaneA, aFireLaneA
        // ingress directions: aWorkLaneC forward forced, aWorkLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aWorkLaneB, aOperationLaneB
        // cross directions: aWorkLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aWorkLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32744U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 29441U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31764U)) & S_BLOCK1], 40U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseBDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 32596U)) & S_BLOCK1], 12U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 32311U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseBDomainWordCross) ^ aNonceWordP));
            //
            aScatter = (RotL64(aIngress, 35U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 48U) + RotL64(aPrevious, 23U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseBDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterA = ((aWandererA + RotL64(aScatter, 28U)) + 4068921616130916949U) + aNonceWordN;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 47U)) + 12077715273915151726U;
            aOrbiterC = (aWandererJ + RotL64(aCross, 57U)) + 16047546802670596833U;
            aOrbiterK = ((aWandererD + RotL64(aIngress, 19U)) + 9690277462716999763U) + aPhaseBOrbiterAssignSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterG = ((((aWandererC + RotL64(aPrevious, 51U)) + RotL64(aCarry, 23U)) + 14484814700447992628U) + aPhaseBOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1]) + aNonceWordG;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 6U)) + 17089267243053958210U) + aNonceWordA;
            aOrbiterF = ((aWandererI + RotL64(aIngress, 35U)) + RotL64(aCarry, 41U)) + 9138746214446211147U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 23U)) + RotL64(aCarry, 57U)) + 10181001536979097045U;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 11U)) + 6657458969093373191U) + aNonceWordL;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 7515983477876590988U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 3039935555863947600U;
            aOrbiterC = RotL64((aOrbiterC * 12511160550780270119U), 43U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 16209389224740851136U) + aNonceWordC;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 725253312098083182U;
            aOrbiterJ = RotL64((aOrbiterJ * 17535989492095522597U), 35U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 13307041115748941383U) + aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 7159572004825238263U;
            aOrbiterF = RotL64((aOrbiterF * 4855009895002398449U), 11U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 12027236743251643820U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterB) ^ 8717826175991286553U) ^ aPhaseBOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 1175614802543098451U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 4769096034227659937U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11201226563992939616U;
            aOrbiterB = RotL64((aOrbiterB * 15595355978388159931U), 3U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17295978531215563256U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 11850923890626719833U;
            aOrbiterK = RotL64((aOrbiterK * 3854851059897397075U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 14139441565288097706U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 988684899382304485U;
            aOrbiterH = RotL64((aOrbiterH * 11929090869999700891U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6159251276942253175U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 4849529993914550651U) ^ aNonceWordB;
            aOrbiterA = RotL64((aOrbiterA * 18240712676783671317U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 6679745455842119497U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15838404437552215214U;
            aOrbiterI = RotL64((aOrbiterI * 17357853511591350887U), 47U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterH;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererA = aWandererA + ((RotL64(aCross, 18U) + aOrbiterC) + RotL64(aOrbiterF, 19U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 14U)) + aOrbiterG) + aPhaseBWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterF) + RotL64(aOrbiterK, 53U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterH, 35U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aScatter, 57U) + aOrbiterA) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 57U)) + aPhaseBWandererUpdateSaltC[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterB, 46U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aIngress, 51U) + RotL64(aOrbiterJ, 57U)) + aOrbiterA) + RotL64(aCarry, 29U)) + aNonceWordI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 4U) + RotL64(aOrbiterI, 27U)) + aOrbiterK);
            //
            aCarry = aCarry + (RotL64(aWandererB, 41U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 35U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererJ, 51U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererD, 11U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererC, 38U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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

void TwistExpander_Lacrosse_Arx::Seed_D(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xC9CF64F6BDE75C85ULL + 0xD087E78360FA5B7DULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xCC4F120398F33053ULL + 0xBC732F0644135258ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0xD52C56C7B633E325ULL + 0x93419B52B5AEA5F3ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xE9A20B0C69CCEFC3ULL + 0x876D8D3B5839F4FEULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xB5DA9E4B812FEC09ULL + 0x8C56B5B01C709AF2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x82B61C5C42E529B5ULL + 0xB664924BBDF5DFBAULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xF4E15E22FA2F390FULL + 0xF90305F6B49C2AC5ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xFC51AB57DF6D9B93ULL + 0xB8EEE45CD8813AA3ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseB(pNonce * 0xC0D3265A168F95A7ULL + 0xD827343B7CAB04EDULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0x92F33DC5B0497171ULL + 0xB38A9115C35B3444ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0x8CFB42248BC9F16FULL + 0xCA9658A0E854CF15ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0xCE54037E19E2908FULL + 0xB8C7C9256BA5E5E1ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xA81E25C54CF0C0C9ULL + 0x975724FFF62C2F7AULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseC(pNonce * 0xE2570940A7FBD2E7ULL + 0xF7613E527B13D3BEULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseB(pNonce * 0x8B95FF266C47C315ULL + 0xD2D7647E53FB2B7EULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseC(pNonce * 0xCF98E0DAAA14102FULL + 0xFD579B9B8310542EULL);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 2536U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneB[((aIndex + 3415U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 2845U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4620U)) & S_BLOCK1], 53U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 5447U)) & S_BLOCK1], 13U));
            aCross ^= RotL64(aInvestLaneB[((aIndex + 982U)) & S_BLOCK1], 40U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 11U) + RotL64(aCross, 39U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 58U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterH = ((((aWandererC + RotL64(aPrevious, 57U)) + RotL64(aCarry, 39U)) + 12122689833405846292U) + aPhaseDOrbiterAssignSaltD[((aIndex + 7U)) & S_SALT1]) + aNonceWordG;
            aOrbiterK = ((aWandererF + RotL64(aCross, 42U)) + 9640400270962766788U) + aNonceWordF;
            aOrbiterC = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 53U)) + 9141937998266739071U;
            aOrbiterA = ((aWandererB + RotL64(aIngress, 35U)) + RotL64(aCarry, 13U)) + 12899395770434090537U;
            aOrbiterJ = (((aWandererG + RotL64(aPrevious, 3U)) + 13457918115408031842U) + aPhaseDOrbiterAssignSaltE[((aIndex + 25U)) & S_SALT1]) + aNonceWordB;
            aOrbiterF = (aWandererE + RotL64(aCross, 21U)) + 15134784483576000943U;
            aOrbiterI = (aWandererK + RotL64(aScatter, 11U)) + 12540961268790055438U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 6306886773092764230U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 13573343491337243121U) ^ aNonceWordP;
            aOrbiterC = RotL64((aOrbiterC * 15893457012357368707U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 8545588657348974413U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 10891410570357275120U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 26U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 5399310978367842841U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterH) + 2877137119767060151U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 17U)) & S_SALT1]) + aNonceWordH;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 9178097682386595144U;
            aOrbiterJ = RotL64((aOrbiterJ * 3524486002084427513U), 43U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 15528007881855616978U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterI) ^ 11368419529245281435U) ^ aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 12433207037378339309U), 51U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 5932738914934356645U) + aNonceWordM;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 5551842263864055419U;
            aOrbiterA = RotL64((aOrbiterA * 16093776759971522681U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 3824433359595690603U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 17184628855571662441U;
            aOrbiterF = RotL64((aOrbiterF * 691208053136187317U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 8724462245014132623U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 7481349499528092352U;
            aOrbiterI = RotL64((aOrbiterI * 8212182934509617583U), 37U);
            //
            aIngress = RotL64(aOrbiterF, 57U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterA, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 36U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterJ, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ (((RotL64(aScatter, 35U) + aOrbiterI) + RotL64(aOrbiterH, 3U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aCross, 13U) + RotL64(aOrbiterI, 41U)) + aOrbiterJ);
            aWandererC = aWandererC ^ ((((RotL64(aIngress, 23U) + RotL64(aOrbiterC, 60U)) + aOrbiterF) + aNonceWordJ) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 58U) + RotL64(aOrbiterA, 19U)) + aOrbiterK) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ (((RotL64(aIngress, 41U) + RotL64(aOrbiterI, 35U)) + aOrbiterK) + aNonceWordK);
            aWandererF = aWandererF + ((((RotL64(aCross, 51U) + RotL64(aOrbiterJ, 29U)) + aOrbiterC) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererG = aWandererG ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterA, 53U)) + aOrbiterI);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererK, 6U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererH, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererF, 53U);
            aCarry = aCarry + RotL64(aIngress, 14U);
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
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10660U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneC[((aIndex + 5942U)) & S_BLOCK1], 43U));
            aIngress ^= (RotL64(aExpandLaneD[((aIndex + 10587U)) & S_BLOCK1], 28U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7522U)) & S_BLOCK1], 19U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordG));
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 6593U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6459U)) & S_BLOCK1], 22U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 7799U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aPrevious, 35U) + RotL64(aCarry, 11U)) ^ (RotL64(aCross, 23U) + RotL64(aIngress, 58U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = (((aWandererH + RotL64(aIngress, 11U)) + 18319689184146942855U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterC = ((aWandererE + RotL64(aPrevious, 47U)) + 8041304130090501019U) + aNonceWordI;
            aOrbiterG = ((((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 51U)) + 11347064191990897738U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 20U)) & S_SALT1]) + aNonceWordH;
            aOrbiterK = ((aWandererJ + RotL64(aScatter, 5U)) + RotL64(aCarry, 19U)) + 15242243470024447468U;
            aOrbiterA = ((aWandererF + RotL64(aIngress, 19U)) + RotL64(aCarry, 5U)) + 10619749107163611105U;
            aOrbiterJ = ((aWandererA + RotL64(aCross, 27U)) + 14795614276221947128U) + aNonceWordL;
            aOrbiterE = (aWandererI + RotL64(aScatter, 36U)) + 1578095288886372393U;
            //
            aOrbiterB = (((aOrbiterB + aOrbiterC) + 13593906305770501684U) + aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 23U)) & S_SALT1]) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 8919815528334599172U;
            aOrbiterG = RotL64((aOrbiterG * 2033810402808238127U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 17425548324720065145U) + aNonceWordM;
            aOrbiterB = ((aOrbiterB ^ aOrbiterK) ^ 11125018338392347335U) ^ aNonceWordA;
            aOrbiterB = RotL64((aOrbiterB * 4377887040461528587U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 3779189180734244399U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 10958224663276134041U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 6206963519509783781U), 13U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 4317305352561612995U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4891139433808505355U;
            aOrbiterA = RotL64((aOrbiterA * 11507024985663120317U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 5166074784835930965U;
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 10080890270621589202U;
            aOrbiterK = RotL64((aOrbiterK * 13170894418184288695U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4501071771615514619U) + aPhaseDOrbiterUpdateSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterJ) ^ 6486573807774431753U;
            aOrbiterE = RotL64((aOrbiterE * 324029625116648669U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 15714881857668975753U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterA) ^ 3506619392820235900U) ^ aNonceWordB;
            aOrbiterC = RotL64((aOrbiterC * 5707033870161224499U), 5U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterG, 19U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterB, 60U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + RotL64(aOrbiterA, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 35U) + aOrbiterC) + RotL64(aOrbiterE, 27U));
            aWandererF = aWandererF + ((((RotL64(aCross, 60U) + aOrbiterJ) + RotL64(aOrbiterA, 57U)) + RotL64(aCarry, 37U)) + aNonceWordD);
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + RotL64(aOrbiterG, 11U)) + aOrbiterE);
            aWandererI = aWandererI + ((((RotL64(aPrevious, 11U) + aOrbiterK) + RotL64(aOrbiterA, 19U)) + RotL64(aCarry, 11U)) + aPhaseDWandererUpdateSaltB[((aIndex + 14U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 29U) + RotL64(aOrbiterJ, 5U)) + aOrbiterG);
            aWandererE = aWandererE + ((((RotL64(aIngress, 43U) + RotL64(aOrbiterB, 50U)) + aOrbiterG) + aNonceWordP) + aPhaseDWandererUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + aOrbiterK) + RotL64(aOrbiterG, 43U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 42U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 37U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererE, 23U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aSnowLaneB[((aIndex + 13783U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneA[((aIndex + 15898U)) & S_BLOCK1], 38U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 15255U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 16350U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneC[((aIndex + 12248U)) & S_BLOCK1], 30U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 5U) ^ RotL64(aCross, 23U)) ^ (RotL64(aCarry, 57U) + RotL64(aPrevious, 40U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterC = (((aWandererB + RotL64(aIngress, 3U)) + RotL64(aCarry, 11U)) + 5721224134332887360U) + aNonceWordA;
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 22U)) + RotL64(aCarry, 53U)) + 6892749729775049095U;
            aOrbiterA = (((aWandererI + RotL64(aScatter, 13U)) + 3884839462099556836U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 5U)) & S_SALT1]) + aNonceWordM;
            aOrbiterG = ((aWandererJ + RotL64(aCross, 43U)) + 4365431706830216193U) + aPhaseDOrbiterAssignSaltB[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterD = (aWandererE + RotL64(aPrevious, 35U)) + 15501528746571578773U;
            aOrbiterK = (aWandererK + RotL64(aScatter, 51U)) + 4505911326320650606U;
            aOrbiterF = ((aWandererF + RotL64(aCross, 57U)) + RotL64(aCarry, 27U)) + 1865129050927879580U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 2011737665969640369U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 611672935827062688U;
            aOrbiterA = RotL64((aOrbiterA * 12873671551304596619U), 57U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 663547038310431047U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 5468932264754299556U;
            aOrbiterK = RotL64((aOrbiterK * 11968657455484578525U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 17920294117231191705U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 486058453837528110U;
            aOrbiterE = RotL64((aOrbiterE * 8851102552244026737U), 41U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 2789178451938129313U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterE) ^ 420772587981211184U;
            aOrbiterG = RotL64((aOrbiterG * 17402987842294006667U), 47U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16196774774442181825U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterD = (((aOrbiterD ^ aOrbiterA) ^ 16264169656793713547U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 6900221986041638783U), 19U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterK) + 10207659833859860796U) + aNonceWordD;
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 8593749091183323678U) ^ aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10696776033512404927U), 35U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 7224922076047787384U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 15366267474865172373U;
            aOrbiterC = RotL64((aOrbiterC * 10134187073321814217U), 3U);
            //
            aIngress = RotL64(aOrbiterC, 20U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterE, 53U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + RotL64(aOrbiterD, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterF, 60U)) + aNonceWordI) + aPhaseDWandererUpdateSaltF[(((31U - aIndex) + 16U)) & S_SALT1]);
            aWandererB = aWandererB + (((((RotL64(aPrevious, 42U) + aOrbiterA) + RotL64(aOrbiterG, 53U)) + RotL64(aCarry, 35U)) + aNonceWordP) + aPhaseDWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterA, 13U)) + aOrbiterC);
            aWandererF = aWandererF + (((RotL64(aScatter, 35U) + RotL64(aOrbiterE, 5U)) + aOrbiterA) + aNonceWordH);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterA, 21U)) + aOrbiterD);
            aWandererJ = aWandererJ + (((RotL64(aCross, 5U) + aOrbiterD) + RotL64(aOrbiterG, 37U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ ((RotL64(aScatter, 57U) + RotL64(aOrbiterK, 47U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererJ, 34U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 53U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererI, 29U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 21001U)) & S_BLOCK1], 29U) ^ RotL64(aSnowLaneA[((aIndex + 21463U)) & S_BLOCK1], 40U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 19488U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21589U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneD[((aIndex + 21701U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aPrevious, 37U) + RotL64(aCarry, 5U)) ^ (RotL64(aCross, 57U) ^ RotL64(aIngress, 24U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 34U)) + 13174219512651137892U) + aPhaseDOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1]) + aNonceWordJ;
            aOrbiterK = (aWandererD + RotL64(aCross, 23U)) + 2715455762789269341U;
            aOrbiterC = (aWandererE + RotL64(aIngress, 3U)) + 1338018183235594313U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 51U)) + RotL64(aCarry, 35U)) + 16566866551729552930U;
            aOrbiterH = (aWandererC + RotL64(aCross, 57U)) + 6901845297307236726U;
            aOrbiterF = ((((aWandererI + RotL64(aIngress, 41U)) + RotL64(aCarry, 23U)) + 2476078302049201718U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordB;
            aOrbiterG = (((aWandererA + RotL64(aPrevious, 13U)) + RotL64(aCarry, 11U)) + 15531109473927052260U) + aNonceWordA;
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 4087849380858572351U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1]) + aNonceWordG;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5167830630098599644U;
            aOrbiterC = RotL64((aOrbiterC * 1982835131228146099U), 5U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterJ) + 7275995452428627217U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 14794340370010024117U;
            aOrbiterK = RotL64((aOrbiterK * 8779497557416568379U), 27U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 8509217403041662849U) + aNonceWordC;
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 2321522025240806996U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 28U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 113568101672878697U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 5676672952755594051U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 2304681269233504384U;
            aOrbiterF = RotL64((aOrbiterF * 15731441084605554497U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 8383399721062437300U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 13181984036942227666U;
            aOrbiterA = RotL64((aOrbiterA * 1648761328771932069U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 13602604532551684210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 12725687663616352843U;
            aOrbiterJ = RotL64((aOrbiterJ * 4684699861686199753U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 5831790822416009806U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 4535048543735457407U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12076777878870257053U), 35U);
            //
            aIngress = RotL64(aOrbiterC, 27U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 3U));
            aIngress = aIngress + (RotL64(aOrbiterF, 57U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterK, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterJ, 13U)) + aNonceWordN);
            aWandererK = aWandererK + (((RotL64(aIngress, 21U) + aOrbiterK) + RotL64(aOrbiterA, 47U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 28U) + aOrbiterJ) + RotL64(aOrbiterK, 53U));
            aWandererE = aWandererE + ((((RotL64(aPrevious, 41U) + RotL64(aOrbiterG, 39U)) + aOrbiterF) + RotL64(aCarry, 3U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterG, 4U)) + aOrbiterH);
            aWandererD = aWandererD + (((RotL64(aIngress, 13U) + aOrbiterH) + RotL64(aOrbiterK, 27U)) + aPhaseDWandererUpdateSaltE[((aIndex + 24U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 35U) + RotL64(aOrbiterJ, 19U)) + aOrbiterA) + aNonceWordL);
            //
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 24U));
            aCarry = aCarry + (RotL64(aWandererI, 47U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererK, 35U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 25928U)) & S_BLOCK1], 4U) ^ RotL64(aSnowLaneB[((aIndex + 22377U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25382U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordL));
            //
            aCross = RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 26685U)) & S_BLOCK1], 20U) ^ RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 21946U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 3U) + RotL64(aPrevious, 29U)) ^ (RotL64(aIngress, 54U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordD));
            //
            aOrbiterJ = ((aWandererC + RotL64(aCross, 39U)) + 15036852811491820366U) + aNonceWordF;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 58U)) + RotL64(aCarry, 41U)) + 305637140752898475U;
            aOrbiterC = (((aWandererJ + RotL64(aIngress, 19U)) + 11948631574496129610U) + aPhaseDOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1]) + aNonceWordD;
            aOrbiterH = (((aWandererA + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 5321623592482991426U) + aNonceWordN;
            aOrbiterD = ((aWandererI + RotL64(aCross, 13U)) + 4075270159062690728U) + aNonceWordG;
            aOrbiterI = (aWandererH + RotL64(aScatter, 3U)) + 15111580500356908928U;
            aOrbiterA = (((aWandererE + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 7244150695504160363U) + aPhaseDOrbiterAssignSaltA[((aIndex + 14U)) & S_SALT1];
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 5131563519577488862U) + aPhaseDOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1]) + aNonceWordE;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 5881954992088651371U;
            aOrbiterC = RotL64((aOrbiterC * 2424421828597294607U), 19U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterD) + 12780935808751507998U) + aPhaseDOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 12599159643925470226U;
            aOrbiterJ = RotL64((aOrbiterJ * 17690046932587062701U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9466589929741834066U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 6093158735705189789U;
            aOrbiterA = RotL64((aOrbiterA * 7453778295800853653U), 57U);
            //
            aOrbiterC = (((aOrbiterC + aOrbiterH) + 17461243886150519249U) + aPhaseDOrbiterUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]) + aNonceWordB;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 15456408913739900718U;
            aOrbiterI = RotL64((aOrbiterI * 16093292401746174671U), 29U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 11260643903290392780U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 7870342756041882616U;
            aOrbiterK = RotL64((aOrbiterK * 2431528656086173419U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 134484990005888936U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 10626896209992890407U) ^ aNonceWordH;
            aOrbiterD = RotL64((aOrbiterD * 12034131076645285597U), 35U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 14031164129515132292U) + aPhaseDOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 1771835705730244212U;
            aOrbiterH = RotL64((aOrbiterH * 186981668443596623U), 5U);
            //
            aIngress = RotL64(aOrbiterA, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (RotL64(aOrbiterC, 57U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterD, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterH, 35U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aScatter, 12U) + RotL64(aOrbiterK, 47U)) + aOrbiterH);
            aWandererA = aWandererA + ((((RotL64(aCross, 47U) + aOrbiterD) + RotL64(aOrbiterA, 3U)) + RotL64(aCarry, 39U)) + aNonceWordO);
            aWandererI = aWandererI ^ ((((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 39U)) + aOrbiterK) + aNonceWordC) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC) + RotL64(aCarry, 57U));
            aWandererJ = aWandererJ ^ ((((RotL64(aCross, 35U) + RotL64(aOrbiterI, 28U)) + aOrbiterD) + aNonceWordA) + aPhaseDWandererUpdateSaltA[((aIndex + 8U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 21U) + aOrbiterH) + RotL64(aOrbiterC, 11U)) + aNonceWordP);
            aWandererH = aWandererH ^ ((RotL64(aIngress, 27U) + aOrbiterA) + RotL64(aOrbiterI, 19U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererB, 38U));
            aCarry = aCarry + (RotL64(aWandererC, 21U) ^ aWandererE);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererH, 5U));
            aCarry = aCarry + RotL64(aWandererI, 47U);
            aCarry = aCarry + RotL64(aIngress, 56U);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 32637U)) & S_BLOCK1], 60U) ^ RotL64(aInvestLaneA[((aIndex + 30929U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 30276U)) & S_BLOCK1], 27U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseDDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 31231U)) & S_BLOCK1], 54U) ^ RotL64(aExpandLaneB[((aIndex + 27521U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseDDomainWordCross) ^ aNonceWordE));
            //
            aScatter = (RotL64(aCross, 27U) ^ RotL64(aIngress, 39U)) + (RotL64(aCarry, 51U) + RotL64(aPrevious, 10U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseDDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterJ = (((aWandererF + RotL64(aCross, 6U)) + 5041131702736607991U) + aPhaseDOrbiterAssignSaltB[((aIndex + 14U)) & S_SALT1]) + aNonceWordO;
            aOrbiterD = ((aWandererK + RotL64(aIngress, 57U)) + RotL64(aCarry, 29U)) + 9295010428212681446U;
            aOrbiterF = ((aWandererB + RotL64(aPrevious, 13U)) + RotL64(aCarry, 3U)) + 6235875895358766017U;
            aOrbiterH = ((aWandererG + RotL64(aScatter, 47U)) + 2622227802531866918U) + aNonceWordL;
            aOrbiterK = ((aWandererC + RotL64(aPrevious, 19U)) + 3888894734834524972U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterI = ((aWandererE + RotL64(aScatter, 39U)) + RotL64(aCarry, 51U)) + 241682012014701753U;
            aOrbiterG = (aWandererI + RotL64(aCross, 29U)) + 15758000422451568079U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 2061944548396976912U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 8177144990755754531U) ^ aNonceWordA;
            aOrbiterF = RotL64((aOrbiterF * 12702392689484397947U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 554978075608818497U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 250408260560714933U;
            aOrbiterJ = RotL64((aOrbiterJ * 1295379390497107727U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 8700027645880997552U;
            aOrbiterD = (aOrbiterD ^ aOrbiterK) ^ 10026130047465480902U;
            aOrbiterD = RotL64((aOrbiterD * 12417270861933696623U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 9785843014096326696U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9998582683258411251U;
            aOrbiterG = RotL64((aOrbiterG * 7197956237569462269U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 13817734599383455151U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 6647207154174092691U) ^ aPhaseDOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1578528131687283531U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 4957715980509035719U;
            aOrbiterH = (((aOrbiterH ^ aOrbiterI) ^ 4994885315786213197U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 25U)) & S_SALT1]) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 5676683798126497011U), 29U);
            //
            aOrbiterF = (((aOrbiterF + aOrbiterG) + 5072908311783966503U) + aPhaseDOrbiterUpdateSaltF[((aIndex + 6U)) & S_SALT1]) + aNonceWordB;
            aOrbiterK = (((aOrbiterK ^ aOrbiterF) ^ 5535039946192891515U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordM;
            aOrbiterK = RotL64((aOrbiterK * 2989412783482309753U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 47U);
            aIngress = aIngress + (RotL64(aOrbiterH, 41U) ^ aOrbiterG);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterD, 60U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + ((((RotL64(aScatter, 37U) + aOrbiterD) + RotL64(aOrbiterJ, 46U)) + RotL64(aCarry, 23U)) + aNonceWordJ);
            aWandererB = aWandererB ^ (((RotL64(aCross, 44U) + RotL64(aOrbiterI, 13U)) + aOrbiterK) + aPhaseDWandererUpdateSaltF[((aIndex + 29U)) & S_SALT1]);
            aWandererK = aWandererK + ((RotL64(aPrevious, 5U) + aOrbiterI) + RotL64(aOrbiterF, 19U));
            aWandererF = aWandererF ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterG, 53U)) + aOrbiterI);
            aWandererC = aWandererC + (((RotL64(aPrevious, 29U) + aOrbiterG) + RotL64(aOrbiterD, 29U)) + aNonceWordF);
            aWandererE = aWandererE ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + aNonceWordI);
            aWandererI = aWandererI + (((((RotL64(aIngress, 19U) + aOrbiterH) + RotL64(aOrbiterJ, 5U)) + RotL64(aCarry, 39U)) + aNonceWordH) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererI, 41U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererB, 6U) ^ aWandererF);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + RotL64(aWandererK, 35U);
            aCarry = aCarry + RotL64(aIngress, 19U);
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

void TwistExpander_Lacrosse_Arx::Seed_E(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0x859443F2AD9CC445ULL + 0x8DB6C8271AC4B367ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseB(pNonce * 0xDF9FBD7E1DF97959ULL + 0x8ADD6961568101D8ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseA(pNonce * 0x89220FB1FF5A383FULL + 0xC1BBF57FB0F08B79ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseA(pNonce * 0xF5766793E67EBFC1ULL + 0xF53B36ABCBD84A23ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xA0D86A1413D77F49ULL + 0xD0267B9B930C47AEULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseA(pNonce * 0xD26F126FAA1FDDBDULL + 0x96D2A0F5A2842B2AULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xF022E4765EFFFA79ULL + 0xC02A17B8C26ED46CULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0x8F992122DA12915DULL + 0xEBE1538241D5825AULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseA(pNonce * 0xC13A0CD9ADE9C0A5ULL + 0xCEB9F5B9A631BCC9ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xF7A7486CB04E1469ULL + 0xC4ED1CBEE1950199ULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xFFF987EB549C8ACBULL + 0xA913ADB6B8684154ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xF9A241F5C4BEB459ULL + 0xA71112825C5977D2ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseA(pNonce * 0xE3D5B12D92587CF1ULL + 0xE535B0C8260B69C9ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0x98C13F0E75D5208FULL + 0x9A1C2568F5CD7CE1ULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xF2ED4EA2A1007403ULL + 0xA04D6FC3418549E6ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xB10EB389BDE3AB49ULL + 0xA1980D46B328608AULL);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 1838U)) & S_BLOCK1], 40U) ^ RotL64(aInvestLaneB[((aIndex + 2635U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 936U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 3463U)) & S_BLOCK1], 46U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 4714U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aFireLaneB[((aIndex + 4894U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCarry, 53U)) + (RotL64(aCross, 36U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordL));
            //
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 5U)) + RotL64(aCarry, 3U)) + 8975885703279267062U) + aNonceWordA;
            aOrbiterF = ((aWandererB + RotL64(aIngress, 10U)) + RotL64(aCarry, 47U)) + 8664844915562660637U;
            aOrbiterH = (((aWandererJ + RotL64(aScatter, 27U)) + RotL64(aCarry, 23U)) + 12281774799736296726U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aCross, 29U)) + 15347461352311329726U) + aPhaseEOrbiterAssignSaltC[((aIndex + 27U)) & S_SALT1]) + aNonceWordI;
            aOrbiterJ = (aWandererG + RotL64(aScatter, 53U)) + 12967500561828907834U;
            aOrbiterA = (aWandererK + RotL64(aIngress, 13U)) + 5002833859280402726U;
            aOrbiterE = (aWandererI + RotL64(aPrevious, 23U)) + 11908257536954668983U;
            aOrbiterB = (aWandererC + RotL64(aCross, 56U)) + 17017174811949227162U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 35U)) + 16851323125613931180U;
            aOrbiterI = ((aWandererD + RotL64(aIngress, 21U)) + 13469326957728686706U) + aNonceWordE;
            aOrbiterK = (aWandererE + RotL64(aScatter, 47U)) + 5228638551056105241U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11945166198089308564U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 16268645041872996022U;
            aOrbiterH = RotL64((aOrbiterH * 5391448793718370911U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 14781204627695095701U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 5365325354838101092U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 16U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 8017284997946310807U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 563147416025715953U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 14660867395395625851U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4769458126865307103U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3168989056355712105U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 16179131669773665579U;
            aOrbiterF = RotL64((aOrbiterF * 5641461617066671723U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 4160220074225527179U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 8597134686962559111U) ^ aNonceWordO;
            aOrbiterC = RotL64((aOrbiterC * 639572585431474015U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16811551552456811661U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5827323970423386301U;
            aOrbiterG = RotL64((aOrbiterG * 9328247349730652021U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 15583234353262170227U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 2950816254621717748U) ^ aNonceWordD;
            aOrbiterB = RotL64((aOrbiterB * 1102417597476170143U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4426165025104306337U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11871220132164971152U;
            aOrbiterJ = RotL64((aOrbiterJ * 2366168050042802207U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 3832424136113939717U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17673885217916768611U;
            aOrbiterK = RotL64((aOrbiterK * 10887063696370811871U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterE) + 3479289844909914390U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 9498461576098567546U) ^ aNonceWordH;
            aOrbiterI = RotL64((aOrbiterI * 8734492074299676555U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 10645314291190544864U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 8975885703279267062U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 11U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 16584086014947250551U), 39U);
            //
            aIngress = RotL64(aOrbiterJ, 35U) ^ aOrbiterE;
            aIngress = aIngress + (RotL64(aOrbiterG, 20U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterI, 11U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterA, 54U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 18U) + RotL64(aOrbiterG, 21U)) + aOrbiterB);
            aWandererG = aWandererG + (((RotL64(aCross, 51U) + aOrbiterA) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 21U) + aOrbiterD) + RotL64(aOrbiterH, 11U));
            aWandererH = aWandererH + ((RotL64(aScatter, 47U) + aOrbiterD) + RotL64(aOrbiterK, 37U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 58U) + RotL64(aOrbiterE, 6U)) + aOrbiterK) + aNonceWordC);
            aWandererD = aWandererD + (((RotL64(aScatter, 13U) + RotL64(aOrbiterJ, 35U)) + aOrbiterB) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 29U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((((RotL64(aIngress, 41U) + aOrbiterC) + RotL64(aOrbiterJ, 57U)) + aNonceWordF) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 29U) + RotL64(aOrbiterI, 41U)) + aOrbiterG) + aNonceWordL);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 39U)) + aOrbiterE);
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterE, 23U)) + aOrbiterJ) + RotL64(aCarry, 13U)) + aNonceWordG);
            aWandererI = aWandererI ^ ((RotL64(aCross, 3U) + RotL64(aOrbiterK, 30U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererD, 6U) ^ aWandererC);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 23U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererJ, 37U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererE, 39U));
            aCarry = aCarry + RotL64(aWandererA, 12U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
            aIngress = (RotL64(aFireLaneA[((aIndex + 9239U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 7597U)) & S_BLOCK1], 11U));
            aIngress ^= (RotL64(aInvestLaneD[((aIndex + 9075U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 10623U)) & S_BLOCK1], 43U));
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordL));
            //
            aCross = (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 10883U)) & S_BLOCK1], 58U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 7535U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 6335U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aIngress, 23U) ^ RotL64(aCarry, 10U)) ^ (RotL64(aCross, 57U) + RotL64(aPrevious, 39U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordE));
            //
            aOrbiterC = (aWandererB + RotL64(aIngress, 37U)) + 18319689184146942855U;
            aOrbiterE = (aWandererC + RotL64(aScatter, 39U)) + 8041304130090501019U;
            aOrbiterB = ((aWandererA + RotL64(aPrevious, 29U)) + 11347064191990897738U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aCross, 43U)) + 15242243470024447468U;
            aOrbiterF = (aWandererG + RotL64(aIngress, 41U)) + 10619749107163611105U;
            aOrbiterG = ((aWandererE + RotL64(aScatter, 10U)) + RotL64(aCarry, 51U)) + 14795614276221947128U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 51U)) + 1578095288886372393U;
            aOrbiterH = (((aWandererI + RotL64(aCross, 47U)) + 13593906305770501684U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1]) + aNonceWordA;
            aOrbiterI = ((aWandererH + RotL64(aPrevious, 21U)) + RotL64(aCarry, 29U)) + 8919815528334599172U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 18U)) + RotL64(aCarry, 3U)) + 17425548324720065145U) + aNonceWordD;
            aOrbiterK = (aWandererD + RotL64(aIngress, 35U)) + 11125018338392347335U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 3779189180734244399U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 10958224663276134041U;
            aOrbiterB = RotL64((aOrbiterB * 6206963519509783781U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterF) + 4317305352561612995U) + aNonceWordE;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 4891139433808505355U) ^ aNonceWordG;
            aOrbiterC = RotL64((aOrbiterC * 11507024985663120317U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 5166074784835930965U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 10080890270621589202U) ^ aNonceWordN;
            aOrbiterH = RotL64((aOrbiterH * 13170894418184288695U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterI) + 4501071771615514619U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 6486573807774431753U;
            aOrbiterE = RotL64((aOrbiterE * 324029625116648669U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterC) + 15714881857668975753U;
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3506619392820235900U;
            aOrbiterA = RotL64((aOrbiterA * 5707033870161224499U), 41U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 5295711072762443783U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 11192836530396570648U;
            aOrbiterD = RotL64((aOrbiterD * 4361810118382207039U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 7993389678399774574U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 12551394763541226695U;
            aOrbiterG = RotL64((aOrbiterG * 11903486656172026403U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 11553674370322129668U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 4459881583199320245U;
            aOrbiterF = RotL64((aOrbiterF * 2805857426321555685U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterH) + 3053507713574219459U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 15458441755058850309U;
            aOrbiterI = RotL64((aOrbiterI * 7296609957819165877U), 39U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 17429750026356459756U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 17114614857181230304U;
            aOrbiterK = RotL64((aOrbiterK * 10541235280918902739U), 35U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterB) + 8958993884028672039U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 18319689184146942855U;
            aOrbiterJ = RotL64((aOrbiterJ * 5430881344386342703U), 11U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 46U);
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterK, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterA, 35U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + RotL64(aOrbiterC, 13U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 27U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 43U) + aOrbiterJ) + RotL64(aOrbiterH, 47U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 21U) + RotL64(aOrbiterD, 35U)) + aOrbiterI);
            aWandererH = aWandererH + (((RotL64(aCross, 34U) + RotL64(aOrbiterC, 18U)) + aOrbiterK) + aNonceWordO);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterG, 23U)) + aOrbiterI);
            aWandererA = aWandererA + ((RotL64(aScatter, 47U) + RotL64(aOrbiterG, 5U)) + aOrbiterC);
            aWandererK = aWandererK ^ ((((RotL64(aCross, 51U) + RotL64(aOrbiterK, 11U)) + aOrbiterG) + aNonceWordF) + aPhaseEWandererUpdateSaltF[((aIndex + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aIngress, 29U) + aOrbiterI) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aScatter, 4U) + aOrbiterB) + RotL64(aOrbiterC, 21U));
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterF, 54U)) + aOrbiterH);
            aWandererE = aWandererE ^ (((RotL64(aCross, 37U) + RotL64(aOrbiterE, 51U)) + aOrbiterK) + aPhaseEWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 50U) ^ aWandererF);
            aCarry = aCarry + (RotL64(aWandererH, 39U) ^ aWandererE);
            aCarry = aCarry + (RotL64(aWandererG, 35U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererC, 37U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererB, 21U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererA, 43U);
            aCarry = aCarry + RotL64(aIngress, 48U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 13003U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneA[((aIndex + 12620U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11172U)) & S_BLOCK1], 30U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordG));
            //
            aCross = RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 11858U)) & S_BLOCK1], 41U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 12115U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 3U) ^ RotL64(aPrevious, 41U)) + (RotL64(aCarry, 24U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordI));
            //
            aOrbiterA = (aWandererJ + RotL64(aIngress, 51U)) + 12029393034357490020U;
            aOrbiterB = (((aWandererA + RotL64(aPrevious, 54U)) + 4526754731580694987U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererK + RotL64(aCross, 21U)) + 17060419646421271853U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterF = ((aWandererC + RotL64(aScatter, 19U)) + RotL64(aCarry, 21U)) + 4128488893837059683U;
            aOrbiterC = ((aWandererI + RotL64(aIngress, 13U)) + RotL64(aCarry, 53U)) + 12706894827547160110U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 11U)) + 12506324593645825056U;
            aOrbiterI = ((aWandererH + RotL64(aCross, 6U)) + RotL64(aCarry, 47U)) + 12581344490649250025U;
            aOrbiterH = (aWandererG + RotL64(aScatter, 43U)) + 14357032418199130132U;
            aOrbiterD = (aWandererD + RotL64(aPrevious, 57U)) + 15341977701796331249U;
            aOrbiterG = (aWandererF + RotL64(aIngress, 29U)) + 7086602307544733241U;
            aOrbiterJ = ((aWandererE + RotL64(aCross, 39U)) + 12398300065276832486U) + aNonceWordI;
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 2499745046076601988U;
            aOrbiterK = (aOrbiterK ^ aOrbiterA) ^ 7249361592814001829U;
            aOrbiterK = RotL64((aOrbiterK * 14597139848072319685U), 29U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterK) + 3254456186337366437U) + aNonceWordF;
            aOrbiterC = ((aOrbiterC ^ aOrbiterF) ^ 3472973415969046680U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 14583566953969168353U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 7905718972111691591U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 15941413652144021522U;
            aOrbiterH = RotL64((aOrbiterH * 3473779492962783565U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 10583964125960308762U) + aNonceWordK;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 13659925272340853715U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 22U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 16708294803316630743U), 23U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 9487054537489454887U) + aNonceWordJ;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 13287757570441887517U;
            aOrbiterA = RotL64((aOrbiterA * 17351439045329892107U), 39U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 15279245465808571942U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 12424999114621745879U;
            aOrbiterG = RotL64((aOrbiterG * 2274918760256527137U), 43U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 13915392738892970475U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 13797668053788805126U;
            aOrbiterB = RotL64((aOrbiterB * 13752161103680525317U), 5U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterJ) + 14344766585550401077U) + aPhaseEOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterD) ^ 13727554194373146727U;
            aOrbiterI = RotL64((aOrbiterI * 17164450431362670223U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 1332966642432651232U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 938583742533681467U) ^ aNonceWordB;
            aOrbiterJ = RotL64((aOrbiterJ * 13323340043936037549U), 57U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterC) + 5659239372701978244U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 8501778564909302938U;
            aOrbiterD = RotL64((aOrbiterD * 15629932660749672503U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 1698500835332753591U;
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 12029393034357490020U;
            aOrbiterF = RotL64((aOrbiterF * 18176507271635640153U), 11U);
            //
            aIngress = RotL64(aOrbiterE, 57U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterI, 14U));
            aIngress = aIngress + (RotL64(aOrbiterA, 47U) ^ aOrbiterG);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterC, 23U));
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterD, 4U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + aOrbiterH) + RotL64(aOrbiterE, 42U)) + aNonceWordM) + aPhaseEWandererUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 5U) + aOrbiterA) + RotL64(aOrbiterH, 29U));
            aWandererH = aWandererH + (((RotL64(aCross, 42U) + aOrbiterD) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 27U) + RotL64(aOrbiterJ, 37U)) + aOrbiterG) + aNonceWordO);
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + aOrbiterG) + RotL64(aOrbiterD, 57U)) + aNonceWordC);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterI, 5U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterH) + RotL64(aOrbiterD, 47U)) + RotL64(aCarry, 3U));
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 47U) + aOrbiterD) + RotL64(aOrbiterB, 19U));
            aWandererC = aWandererC + (((RotL64(aIngress, 14U) + RotL64(aOrbiterI, 11U)) + aOrbiterE) + aNonceWordD);
            aWandererB = aWandererB ^ ((RotL64(aCross, 39U) + RotL64(aOrbiterJ, 52U)) + aOrbiterD);
            aWandererI = aWandererI + (((RotL64(aScatter, 29U) + aOrbiterA) + RotL64(aOrbiterK, 21U)) + aPhaseEWandererUpdateSaltD[((aIndex + 9U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererK, 46U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 53U));
            aCarry = aCarry + (RotL64(aWandererJ, 35U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 51U) ^ aWandererG);
            aCarry = aCarry + RotL64(aWandererA, 26U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aOperationLaneA[((aIndex + 21089U)) & S_BLOCK1], 44U) ^ RotL64(aFireLaneA[((aIndex + 17967U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 20423U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 18376U)) & S_BLOCK1], 51U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 19125U)) & S_BLOCK1], 42U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 56U)) + (RotL64(aCross, 37U) ^ RotL64(aPrevious, 21U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterI = ((aWandererC + RotL64(aIngress, 24U)) + 12809562813316740345U) + aPhaseEOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterD = (aWandererH + RotL64(aCross, 51U)) + 17084212535326321199U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 29U)) + 16074921689983846769U) + aNonceWordK;
            aOrbiterC = (aWandererB + RotL64(aPrevious, 53U)) + 14027986153007120145U;
            aOrbiterG = ((aWandererG + RotL64(aIngress, 27U)) + RotL64(aCarry, 39U)) + 7633455951809250227U;
            aOrbiterK = (aWandererA + RotL64(aScatter, 43U)) + 340989348513370174U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 11U)) + RotL64(aCarry, 43U)) + 5307820377645020116U;
            aOrbiterH = (((aWandererI + RotL64(aPrevious, 38U)) + 5605285015771527274U) + aPhaseEOrbiterAssignSaltC[((aIndex + 3U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 3U)) + 5293500434746182790U) + aNonceWordP;
            aOrbiterJ = (aWandererF + RotL64(aPrevious, 19U)) + 7263156475892261811U;
            aOrbiterA = ((aWandererE + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 10672879570907433005U;
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 16659226780900986107U;
            aOrbiterE = (((aOrbiterE ^ aOrbiterI) ^ 9774892622769850665U) ^ aPhaseEOrbiterUpdateSaltE[((aIndex + 9U)) & S_SALT1]) ^ aNonceWordD;
            aOrbiterE = RotL64((aOrbiterE * 7487477727543183211U), 19U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterG) + 10728057184108279042U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 5032485856947407217U;
            aOrbiterK = RotL64((aOrbiterK * 16651577903809154285U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterF) + 14642241075374862345U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 8386481273395203518U;
            aOrbiterC = RotL64((aOrbiterC * 11649977733867003445U), 13U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 2874153265304098104U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 11519900149177261000U;
            aOrbiterB = RotL64((aOrbiterB * 2010158758971864505U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 8885690878540115768U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterE) ^ 4482143389870987714U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 7105332459437434281U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 17469068567801886615U) + aNonceWordH;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5121422018622394837U;
            aOrbiterD = RotL64((aOrbiterD * 14823827133212643467U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 3130788210672745618U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterK) ^ 6139244627510113216U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 2640754184921507389U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 10488511756324474710U;
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1760223670304953696U;
            aOrbiterF = RotL64((aOrbiterF * 4007062295003769311U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 2232708414171096783U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 17497492434939621063U;
            aOrbiterG = RotL64((aOrbiterG * 9850565931511937725U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 8199114561613022892U;
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 15432482434863050835U;
            aOrbiterA = RotL64((aOrbiterA * 14271143436318169871U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 14991531324947777062U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 12809562813316740345U) ^ aNonceWordF;
            aOrbiterI = RotL64((aOrbiterI * 4487021480964944879U), 35U);
            //
            aIngress = RotL64(aOrbiterD, 21U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterI, 38U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterA, 53U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterG, 57U));
            aIngress = aIngress + RotL64(aOrbiterJ, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aIngress, 21U) + RotL64(aOrbiterI, 47U)) + aOrbiterA);
            aWandererD = aWandererD ^ (((RotL64(aScatter, 43U) + RotL64(aOrbiterE, 11U)) + aOrbiterH) + aNonceWordL);
            aWandererF = aWandererF + ((RotL64(aPrevious, 13U) + RotL64(aOrbiterK, 5U)) + aOrbiterA);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 46U) + RotL64(aOrbiterG, 24U)) + aOrbiterD) + aNonceWordC) + aPhaseEWandererUpdateSaltE[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 43U)) + aOrbiterH) + RotL64(aCarry, 53U)) + aNonceWordO);
            aWandererB = aWandererB ^ ((RotL64(aScatter, 27U) + RotL64(aOrbiterC, 19U)) + aOrbiterB);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterH, 53U)) + aOrbiterK) + RotL64(aCarry, 35U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 5U) + aOrbiterH) + RotL64(aOrbiterG, 35U));
            aWandererK = aWandererK + ((RotL64(aIngress, 39U) + aOrbiterJ) + RotL64(aOrbiterC, 56U));
            aWandererA = aWandererA ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 41U)) + aOrbiterF) + aPhaseEWandererUpdateSaltC[((aIndex + 29U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aPrevious, 18U) + aOrbiterB) + RotL64(aOrbiterD, 3U)) + aNonceWordN);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 14U));
            aCarry = aCarry + (RotL64(aWandererI, 29U) ^ aWandererC);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 27U));
            aCarry = aCarry + (RotL64(aWandererG, 37U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererK, 22U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererB, 35U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23051U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneB[((aIndex + 24598U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 25824U)) & S_BLOCK1], 52U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordD));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 26413U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 22811U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aInvestLaneA[((aIndex + 27052U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCarry, 57U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aCross, 43U) + RotL64(aPrevious, 24U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordM));
            //
            aOrbiterH = (aWandererK + RotL64(aIngress, 3U)) + 7896237440058555694U;
            aOrbiterG = ((aWandererH + RotL64(aScatter, 13U)) + 11870529476037558635U) + aNonceWordG;
            aOrbiterI = ((aWandererB + RotL64(aPrevious, 50U)) + 9158983227801569448U) + aPhaseEOrbiterAssignSaltF[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aWandererF + RotL64(aCross, 11U)) + 4710172270996950329U;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 53U)) + 14634482800356647630U;
            aOrbiterA = ((aWandererG + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 8822207952170610891U;
            aOrbiterF = ((aWandererI + RotL64(aScatter, 47U)) + RotL64(aCarry, 13U)) + 13755891414028982553U;
            aOrbiterE = ((aWandererJ + RotL64(aIngress, 29U)) + 4555293067488040719U) + aNonceWordA;
            aOrbiterD = (((aWandererC + RotL64(aPrevious, 34U)) + RotL64(aCarry, 5U)) + 2816805148093762081U) + aNonceWordB;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 37U)) + 2122631477965135190U) + aNonceWordJ;
            aOrbiterK = ((aWandererE + RotL64(aCross, 21U)) + 4592922416380416071U) + aPhaseEOrbiterAssignSaltD[(((31U - aIndex) + 19U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7102471666524164715U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 17274623547879474204U;
            aOrbiterI = RotL64((aOrbiterI * 5443572270546181789U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 938587316977094680U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 18258015823797023523U;
            aOrbiterA = RotL64((aOrbiterA * 6068819567674605919U), 39U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 5809987756043471595U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 5083075160112581620U) ^ aPhaseEOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 3313957222154937503U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 5960021727750946496U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 5967477320950630150U;
            aOrbiterG = RotL64((aOrbiterG * 330964768256424655U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 6578428711689296132U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 5601728218197771276U;
            aOrbiterH = RotL64((aOrbiterH * 9552559022315971847U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7923809409017855241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 16479366540906497019U;
            aOrbiterB = RotL64((aOrbiterB * 7118578387798460919U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 17000467091738009736U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 6801634573655508028U;
            aOrbiterF = RotL64((aOrbiterF * 10584635770060137089U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 123668445682719574U;
            aOrbiterC = (aOrbiterC ^ aOrbiterB) ^ 14462802805503986316U;
            aOrbiterC = RotL64((aOrbiterC * 12398236364304875941U), 35U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterI) + 2433338393261685871U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 26U)) & S_SALT1]) + aNonceWordI;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 13869012262404991729U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 12443261517483942937U), 27U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 4832421585086516998U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 11284414949564414958U;
            aOrbiterJ = RotL64((aOrbiterJ * 1586650935440790991U), 21U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterH) + 17872556812561387030U) + aNonceWordO;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 7896237440058555694U) ^ aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16784165278693056013U), 57U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterB, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterK, 58U));
            aIngress = aIngress + (RotL64(aOrbiterH, 3U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 21U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterA, 27U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererB = aWandererB + ((RotL64(aScatter, 27U) + RotL64(aOrbiterJ, 3U)) + aOrbiterF);
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 47U) + aOrbiterF) + RotL64(aOrbiterD, 5U));
            aWandererA = aWandererA + (((RotL64(aIngress, 5U) + RotL64(aOrbiterJ, 60U)) + aOrbiterI) + RotL64(aCarry, 53U));
            aWandererD = aWandererD ^ ((RotL64(aCross, 29U) + aOrbiterE) + RotL64(aOrbiterI, 37U));
            aWandererH = aWandererH + (((RotL64(aIngress, 40U) + RotL64(aOrbiterF, 19U)) + aOrbiterA) + aPhaseEWandererUpdateSaltB[((aIndex + 9U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 23U) + aOrbiterH) + RotL64(aOrbiterC, 27U));
            aWandererF = aWandererF + ((RotL64(aCross, 13U) + aOrbiterG) + RotL64(aOrbiterC, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 51U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + aNonceWordE);
            aWandererC = aWandererC + ((((RotL64(aCross, 43U) + RotL64(aOrbiterI, 21U)) + aOrbiterH) + RotL64(aCarry, 29U)) + aNonceWordL);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 38U) + aOrbiterK) + RotL64(aOrbiterA, 13U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterF, 58U)) + aOrbiterH) + aNonceWordM) + aPhaseEWandererUpdateSaltF[((aIndex + 27U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererG, 51U) ^ aWandererF);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererC, 36U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 19U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 41U));
            aCarry = aCarry + RotL64(aWandererJ, 23U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 27487U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 32299U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aFireLaneD[((aIndex + 31722U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseEDomainWordIngress) ^ aNonceWordH));
            //
            aCross = RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31733U)) & S_BLOCK1], 39U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 30359U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseEDomainWordCross) ^ aNonceWordA));
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aPrevious, 36U)) ^ (RotL64(aCross, 53U) + RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseEDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterB = (((aWandererI + RotL64(aScatter, 3U)) + 12262991801139086177U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordP;
            aOrbiterG = (aWandererC + RotL64(aPrevious, 23U)) + 7963038771924890197U;
            aOrbiterF = ((aWandererB + RotL64(aCross, 21U)) + 15540520327933568896U) + aNonceWordD;
            aOrbiterA = ((aWandererD + RotL64(aIngress, 5U)) + RotL64(aCarry, 53U)) + 8745565892055020722U;
            aOrbiterE = ((aWandererG + RotL64(aCross, 26U)) + RotL64(aCarry, 11U)) + 16619329199683755286U;
            aOrbiterH = (aWandererJ + RotL64(aIngress, 57U)) + 10865705026433867260U;
            aOrbiterD = ((aWandererA + RotL64(aScatter, 51U)) + 2743368697984518059U) + aNonceWordI;
            aOrbiterK = (aWandererE + RotL64(aPrevious, 41U)) + 5556006271515473135U;
            aOrbiterJ = (aWandererF + RotL64(aCross, 37U)) + 5355833281353498588U;
            aOrbiterI = ((aWandererH + RotL64(aScatter, 29U)) + RotL64(aCarry, 23U)) + 8313616108963479829U;
            aOrbiterC = (((aWandererK + RotL64(aPrevious, 54U)) + 16657121016801866434U) + aPhaseEOrbiterAssignSaltB[(((31U - aIndex) + 15U)) & S_SALT1]) + aNonceWordO;
            //
            aOrbiterB = (aOrbiterB + aOrbiterG) + 16532226425013000833U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5800465874932467232U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5966395771690704577U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 17882948163883121328U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterA) ^ 15029375310296563175U) ^ aNonceWordG;
            aOrbiterH = RotL64((aOrbiterH * 17021415832288477713U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10170682648007918739U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 11829089574189398773U;
            aOrbiterK = RotL64((aOrbiterK * 15755874363488568849U), 29U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 1746524867389196322U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 10217423427886742775U;
            aOrbiterI = RotL64((aOrbiterI * 9166162099575333519U), 3U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterJ) + 1338457710729082656U) + aNonceWordK;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 1319981417675542556U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 9518448254565489715U), 11U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 3985281993069194761U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7281264481139915593U;
            aOrbiterA = RotL64((aOrbiterA * 13498446162967276739U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterK) + 17394503335338855566U) + aNonceWordN;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 1430703546991948227U;
            aOrbiterG = RotL64((aOrbiterG * 1623206122475721175U), 37U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 472559435062214929U) + aNonceWordL;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8065899137826178995U;
            aOrbiterE = RotL64((aOrbiterE * 13287499768933229539U), 51U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 3377996409668333322U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 10456089146891981998U;
            aOrbiterB = RotL64((aOrbiterB * 12037044781049717633U), 53U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 5246784368779537905U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 8518987022368391332U;
            aOrbiterD = RotL64((aOrbiterD * 4046763804695058779U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 7791883487780325967U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 12262991801139086177U;
            aOrbiterJ = RotL64((aOrbiterJ * 3409890579914160747U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterF, 60U);
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 19U));
            aIngress = aIngress + (RotL64(aOrbiterD, 29U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterJ, 21U));
            aIngress = aIngress + RotL64(aOrbiterI, 12U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aIngress, 50U) + RotL64(aOrbiterJ, 29U)) + aOrbiterD);
            aWandererB = aWandererB + (((RotL64(aCross, 47U) + aOrbiterH) + RotL64(aOrbiterC, 41U)) + RotL64(aCarry, 47U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 21U) + aOrbiterB) + RotL64(aOrbiterK, 57U));
            aWandererH = aWandererH + (((RotL64(aScatter, 11U) + RotL64(aOrbiterI, 3U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterK, 34U)) + aOrbiterA);
            aWandererF = aWandererF + ((((RotL64(aIngress, 41U) + aOrbiterB) + RotL64(aOrbiterC, 53U)) + aNonceWordE) + aPhaseEWandererUpdateSaltA[((aIndex + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 29U) + aOrbiterE) + RotL64(aOrbiterJ, 43U));
            aWandererJ = aWandererJ + ((RotL64(aScatter, 37U) + aOrbiterF) + RotL64(aOrbiterB, 21U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 44U) + aOrbiterK) + RotL64(aOrbiterF, 24U));
            aWandererI = aWandererI + (((RotL64(aIngress, 57U) + aOrbiterJ) + RotL64(aOrbiterK, 27U)) + aNonceWordM);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterG, 47U)) + aPhaseEWandererUpdateSaltD[((aIndex + 7U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererD, 39U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 56U) ^ aWandererH);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 27U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererE, 53U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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

void TwistExpander_Lacrosse_Arx::Seed_F(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseA(pNonce * 0xEF0F7823250DDB4BULL + 0x9BA9642C99D9E123ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseA(pNonce * 0xC17A8CEE03D21063ULL + 0xE33F10D535056980ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0x9651F0E36165515BULL + 0x83402FAD8FBE1BD1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xFA07A6F4D39499B7ULL + 0xF7650E31E7471944ULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseC(pNonce * 0xC6941B9EA31F30B1ULL + 0xD0120F10BB50CBC2ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0x830DF57358379C87ULL + 0x8113933E61875FD6ULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseA(pNonce * 0xD5F0D05E9D223BB7ULL + 0xC7688DE3547CFCA2ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseB(pNonce * 0xBCDDF65C93E95751ULL + 0xEDAD7238AFFB9129ULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0xC77B555D42066443ULL + 0xCEF512C8FEC4A3ACULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseC(pNonce * 0xBC15BE3DBF4B62E1ULL + 0xE9035CD769FFC52DULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xE43247AC89E6C457ULL + 0x8A2A554AF9BE5B91ULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseC(pNonce * 0xB9BCFBF53838D233ULL + 0x83A50B5BABC8F6EFULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseB(pNonce * 0xB70A74FAF2613AEFULL + 0xC45D65D88557E22BULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xF298E4898964EB49ULL + 0x9FDFC3AF36761A3CULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0x89C3F8871E929135ULL + 0xF6CC35F8D28CF7F0ULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0xC75DF0CABF34711DULL + 0xAD149F004E1695D9ULL);
    // GSeedRunSeed_F seed_loop_f (start)
    {
        // GSeedRunSeed_F seed_loop_f lane group
        // read from: aOperationLaneA, aOperationLaneB, aWorkLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneA, aSnowLaneC, aInvestLaneD, aWorkLaneD, aSnowLaneD, aInvestLaneB, aExpandLaneA, aInvestLaneC, aExpandLaneB, aSnowLaneA, aExpandLaneC, aSnowLaneB
        // write to: aSnowLaneC, aSnowLaneD, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_f loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aWorkLaneC
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aWorkLaneC forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aInvestLaneA
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aSnowLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 2591U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneB[((aIndex + 1539U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 4444U)) & S_BLOCK1], 21U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordN));
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1431U)) & S_BLOCK1], 39U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 1801U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 221U)) & S_BLOCK1], 11U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aIngress, 3U) ^ RotL64(aCarry, 41U)) ^ (RotL64(aPrevious, 54U) + RotL64(aCross, 19U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordC));
            //
            aOrbiterI = (((aWandererD + RotL64(aScatter, 13U)) + RotL64(aCarry, 51U)) + 17711946802293254150U) + aNonceWordJ;
            aOrbiterF = (aWandererE + RotL64(aCross, 23U)) + 16652362590489569378U;
            aOrbiterG = ((((aWandererC + RotL64(aPrevious, 41U)) + RotL64(aCarry, 13U)) + 6972810344198183097U) + aPhaseFOrbiterAssignSaltF[((aIndex + 27U)) & S_SALT1]) + aNonceWordK;
            aOrbiterA = (((aWandererF + RotL64(aIngress, 52U)) + RotL64(aCarry, 37U)) + 13117100889782940546U) + aNonceWordP;
            aOrbiterD = ((aWandererG + RotL64(aScatter, 19U)) + 13199305696782626591U) + aPhaseFOrbiterAssignSaltE[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 5U)) + 992156184392760945U;
            aOrbiterB = (aWandererK + RotL64(aCross, 47U)) + 13791265442074543880U;
            aOrbiterH = (aWandererI + RotL64(aPrevious, 34U)) + 17057087245252294859U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 57U)) + 13444195995883541046U) + aNonceWordA;
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6723678233676059420U;
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 7913379431208430475U;
            aOrbiterG = RotL64((aOrbiterG * 2295062944289127123U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 4481887195529300665U;
            aOrbiterI = (((aOrbiterI ^ aOrbiterA) ^ 11892724101424384078U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1]) ^ aNonceWordO;
            aOrbiterI = RotL64((aOrbiterI * 3468639499716604111U), 23U);
            //
            aOrbiterK = (((aOrbiterK + aOrbiterG) + 7700902083270424194U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 18U)) & S_SALT1]) + aNonceWordL;
            aOrbiterD = (((aOrbiterD ^ aOrbiterK) ^ 1888001433557140271U) ^ aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1]) ^ aNonceWordI;
            aOrbiterD = RotL64((aOrbiterD * 8975562955027025349U), 41U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 14996753906788986929U;
            aOrbiterH = (aOrbiterH ^ aOrbiterG) ^ 939004845422123765U;
            aOrbiterH = RotL64((aOrbiterH * 2507090308972292313U), 3U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 11922230289291941807U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterD) ^ 15681187459741147199U) ^ aNonceWordM;
            aOrbiterF = RotL64((aOrbiterF * 10124947739653819101U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 9119043713532718155U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 8327697433992362166U;
            aOrbiterB = RotL64((aOrbiterB * 11157657162184304567U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 13630755116592440359U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 771252613886022889U;
            aOrbiterE = RotL64((aOrbiterE * 2958918915223536519U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 8524239721467527770U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 17732617735422435572U;
            aOrbiterA = RotL64((aOrbiterA * 13992947983987668631U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterI) + 5265753270696005619U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 14456128349522985053U;
            aOrbiterK = RotL64((aOrbiterK * 5406509991740849617U), 53U);
            //
            aIngress = RotL64(aOrbiterK, 47U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterH, 30U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterG, 27U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aPrevious, 42U) + RotL64(aOrbiterG, 34U)) + aOrbiterK) + RotL64(aCarry, 23U)) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 5U) + RotL64(aOrbiterH, 11U)) + aOrbiterA);
            aWandererI = aWandererI + ((((RotL64(aIngress, 47U) + aOrbiterF) + RotL64(aOrbiterB, 39U)) + aNonceWordC) + aPhaseFWandererUpdateSaltA[((aIndex + 4U)) & S_SALT1]);
            aWandererF = aWandererF ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterD, 21U)) + aOrbiterK) + aNonceWordB);
            aWandererG = aWandererG + (((RotL64(aScatter, 10U) + RotL64(aOrbiterA, 57U)) + aOrbiterB) + RotL64(aCarry, 5U));
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 29U)) + aOrbiterD);
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterG) + RotL64(aOrbiterA, 44U));
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 53U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + RotL64(aOrbiterI, 51U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 53U) ^ aWandererG);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 47U));
            aCarry = aCarry + RotL64(aWandererK, 6U);
            aCarry = aCarry + RotL64(aIngress, 11U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aSnowLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 2
        // ingress from: aSnowLaneC, aOperationLaneC, aOperationLaneD, aInvestLaneD
        // ingress directions: aSnowLaneC forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aInvestLaneD forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aWorkLaneD
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aWorkLaneD backward/forward random
        // write to: aSnowLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneC[((aIndex + 5606U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneC[((aIndex + 7427U)) & S_BLOCK1], 3U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 8150U)) & S_BLOCK1], 36U) ^ RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 7955U)) & S_BLOCK1], 13U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordA));
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 10333U)) & S_BLOCK1], 37U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 9129U)) & S_BLOCK1], 3U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 10398U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordI));
            //
            aScatter = (RotL64(aCross, 21U) + RotL64(aIngress, 5U)) + (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 52U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterA = (aWandererB + RotL64(aIngress, 57U)) + 12029393034357490020U;
            aOrbiterK = ((aWandererF + RotL64(aScatter, 21U)) + 4526754731580694987U) + aPhaseFOrbiterAssignSaltC[((aIndex + 14U)) & S_SALT1];
            aOrbiterB = ((aWandererG + RotL64(aPrevious, 47U)) + RotL64(aCarry, 11U)) + 17060419646421271853U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 41U)) + 4128488893837059683U;
            aOrbiterD = ((aWandererD + RotL64(aIngress, 10U)) + 12706894827547160110U) + aPhaseFOrbiterAssignSaltB[((aIndex + 3U)) & S_SALT1];
            aOrbiterC = ((aWandererJ + RotL64(aScatter, 51U)) + 12506324593645825056U) + aNonceWordD;
            aOrbiterH = (aWandererE + RotL64(aPrevious, 37U)) + 12581344490649250025U;
            aOrbiterF = ((aWandererI + RotL64(aCross, 3U)) + RotL64(aCarry, 39U)) + 14357032418199130132U;
            aOrbiterI = (((aWandererK + RotL64(aIngress, 28U)) + RotL64(aCarry, 27U)) + 15341977701796331249U) + aNonceWordJ;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 7086602307544733241U) + aNonceWordP;
            aOrbiterB = ((aOrbiterB ^ aOrbiterA) ^ 12398300065276832486U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 18157408831225635333U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterD) + 2499745046076601988U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 7249361592814001829U;
            aOrbiterC = RotL64((aOrbiterC * 14597139848072319685U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterH) + 3254456186337366437U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 27U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterD) ^ 3472973415969046680U;
            aOrbiterA = RotL64((aOrbiterA * 14583566953969168353U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 7905718972111691591U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 15941413652144021522U;
            aOrbiterF = RotL64((aOrbiterF * 3473779492962783565U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10583964125960308762U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 13659925272340853715U) ^ aNonceWordO;
            aOrbiterJ = RotL64((aOrbiterJ * 16708294803316630743U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 9487054537489454887U;
            aOrbiterD = (aOrbiterD ^ aOrbiterI) ^ 13287757570441887517U;
            aOrbiterD = RotL64((aOrbiterD * 17351439045329892107U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 15279245465808571942U;
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 12424999114621745879U;
            aOrbiterK = RotL64((aOrbiterK * 2274918760256527137U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterA) + 13915392738892970475U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 10U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 13797668053788805126U;
            aOrbiterI = RotL64((aOrbiterI * 13752161103680525317U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 14344766585550401077U) + aNonceWordG;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 13727554194373146727U;
            aOrbiterH = RotL64((aOrbiterH * 17164450431362670223U), 23U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterD, 13U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 36U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 19U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterB, 3U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterI, 53U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 51U) + RotL64(aOrbiterI, 34U)) + aOrbiterF) + RotL64(aCarry, 57U)) + aNonceWordB);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 3U) + RotL64(aOrbiterC, 53U)) + aOrbiterI);
            aWandererI = aWandererI + ((((RotL64(aIngress, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterD) + aNonceWordK) + aPhaseFWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 46U) + RotL64(aOrbiterB, 47U)) + aOrbiterC);
            aWandererK = aWandererK + (((RotL64(aIngress, 11U) + aOrbiterK) + RotL64(aOrbiterH, 23U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 19U) + aOrbiterA) + RotL64(aOrbiterJ, 13U)) + aNonceWordC);
            aWandererB = aWandererB + ((RotL64(aPrevious, 39U) + aOrbiterH) + RotL64(aOrbiterD, 29U));
            aWandererG = aWandererG ^ ((RotL64(aCross, 35U) + aOrbiterF) + RotL64(aOrbiterA, 58U));
            aWandererF = aWandererF + (((RotL64(aIngress, 58U) + aOrbiterB) + RotL64(aOrbiterJ, 19U)) + RotL64(aCarry, 5U));
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererH, 53U));
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererJ);
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 50U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 3
        // ingress from: aSnowLaneD, aOperationLaneA, aInvestLaneB
        // ingress directions: aSnowLaneD forward forced, aOperationLaneA forward forced, aInvestLaneB forward/backward random
        // cross from: aSnowLaneC, aOperationLaneC
        // cross directions: aSnowLaneC backward forced, aOperationLaneC backward/forward random
        // write to: aExpandLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneD[((aIndex + 12889U)) & S_BLOCK1], 35U) ^ RotL64(aOperationLaneA[((aIndex + 10999U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 13521U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordO));
            //
            aCross = RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 15371U)) & S_BLOCK1], 43U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 12657U)) & S_BLOCK1], 5U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordK));
            //
            aScatter = (RotL64(aCarry, 27U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 10U) ^ RotL64(aCross, 41U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordA));
            //
            aOrbiterB = ((aWandererB + RotL64(aScatter, 13U)) + 16802219662864902427U) + aNonceWordP;
            aOrbiterC = ((aWandererA + RotL64(aPrevious, 23U)) + 14332033461409490629U) + aNonceWordB;
            aOrbiterI = ((aWandererH + RotL64(aIngress, 46U)) + RotL64(aCarry, 39U)) + 8781794298640286845U;
            aOrbiterA = (aWandererJ + RotL64(aCross, 5U)) + 8459933908074937264U;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 19U)) + 1883580287986004426U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aPrevious, 27U)) + RotL64(aCarry, 57U)) + 17500258188004626118U;
            aOrbiterD = (((aWandererI + RotL64(aCross, 41U)) + RotL64(aCarry, 23U)) + 7934811305150872870U) + aNonceWordF;
            aOrbiterG = (((aWandererF + RotL64(aIngress, 58U)) + 6380363892361098905U) + aPhaseFOrbiterAssignSaltD[((aIndex + 5U)) & S_SALT1]) + aNonceWordA;
            aOrbiterE = (aWandererD + RotL64(aScatter, 37U)) + 12623079132626676910U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 10455208121949202703U;
            aOrbiterI = (aOrbiterI ^ aOrbiterB) ^ 8805532707916767629U;
            aOrbiterI = RotL64((aOrbiterI * 666082374369701881U), 23U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 9161544391400377699U) + aPhaseFOrbiterUpdateSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterJ = (((aOrbiterJ ^ aOrbiterA) ^ 3501434325829663268U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1]) ^ aNonceWordL;
            aOrbiterJ = RotL64((aOrbiterJ * 7933545151293799637U), 5U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 651783304096081996U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 441505031509930622U;
            aOrbiterH = RotL64((aOrbiterH * 8045355432310956143U), 35U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 1771159983581326424U;
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 15227946417377695989U;
            aOrbiterG = RotL64((aOrbiterG * 1563141188972797601U), 47U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 4153717524193279095U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4404521756523902829U;
            aOrbiterC = RotL64((aOrbiterC * 1410342912973206203U), 39U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterI) + 6231945075461813285U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 3864780227164426690U;
            aOrbiterA = RotL64((aOrbiterA * 18031353247480673617U), 43U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 1509699687948576558U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterJ) ^ 17316114302489411191U) ^ aNonceWordM;
            aOrbiterE = RotL64((aOrbiterE * 15490661284980281585U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 2250572827340157410U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6403966113144372915U;
            aOrbiterD = RotL64((aOrbiterD * 726441947009132383U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 2329903609147403156U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 2486330017319455238U) ^ aNonceWordE;
            aOrbiterB = RotL64((aOrbiterB * 17427461345935191757U), 13U);
            //
            aIngress = RotL64(aOrbiterH, 23U) ^ aOrbiterI;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 60U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((((RotL64(aIngress, 35U) + aOrbiterC) + RotL64(aOrbiterI, 35U)) + aNonceWordD) + aPhaseFWandererUpdateSaltF[((aIndex + 23U)) & S_SALT1]);
            aWandererB = aWandererB + ((RotL64(aCross, 47U) + RotL64(aOrbiterJ, 56U)) + aOrbiterE);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterB, 29U)) + aOrbiterE);
            aWandererJ = aWandererJ + (((RotL64(aScatter, 24U) + aOrbiterJ) + RotL64(aOrbiterG, 23U)) + RotL64(aCarry, 37U));
            aWandererK = aWandererK ^ (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 43U)) + aOrbiterJ) + aNonceWordH);
            aWandererI = aWandererI + (((RotL64(aScatter, 51U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + aNonceWordJ);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 60U)) + aOrbiterG);
            aWandererE = aWandererE + (((RotL64(aCross, 29U) + RotL64(aOrbiterD, 11U)) + aOrbiterA) + RotL64(aCarry, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 18U) + RotL64(aOrbiterA, 51U)) + aOrbiterI) + aPhaseFWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererJ);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 51U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererI, 21U));
            aCarry = aCarry + RotL64(aWandererA, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 4
        // ingress from: aExpandLaneA, aSnowLaneC, aInvestLaneC
        // ingress directions: aExpandLaneA forward forced, aSnowLaneC forward forced, aInvestLaneC forward/backward random
        // cross from: aSnowLaneD, aOperationLaneD
        // cross directions: aSnowLaneD backward forced, aOperationLaneD backward/forward random
        // write to: aExpandLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 20484U)) & S_BLOCK1], 40U) ^ RotL64(aSnowLaneC[((aIndex + 18160U)) & S_BLOCK1], 23U));
            aIngress ^= RotL64(aInvestLaneC[((aIndex + 18440U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordF));
            //
            aCross = RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 17711U)) & S_BLOCK1], 29U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 16757U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseB(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordG));
            //
            aScatter = (RotL64(aCarry, 27U) ^ RotL64(aPrevious, 57U)) + (RotL64(aCross, 44U) + RotL64(aIngress, 11U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordK));
            //
            aOrbiterB = ((aWandererE + RotL64(aCross, 43U)) + RotL64(aCarry, 11U)) + 4384716820085860551U;
            aOrbiterJ = ((aWandererG + RotL64(aScatter, 4U)) + 9715780315942116888U) + aPhaseFOrbiterAssignSaltE[((aIndex + 23U)) & S_SALT1];
            aOrbiterA = ((aWandererD + RotL64(aPrevious, 39U)) + 15963520052789178632U) + aNonceWordD;
            aOrbiterE = ((aWandererC + RotL64(aIngress, 27U)) + RotL64(aCarry, 43U)) + 14346700690686392938U;
            aOrbiterD = ((aWandererH + RotL64(aCross, 23U)) + 6005518012489966643U) + aNonceWordC;
            aOrbiterH = (aWandererA + RotL64(aPrevious, 57U)) + 2506732930310252119U;
            aOrbiterC = (aWandererI + RotL64(aIngress, 34U)) + 16782163084851775826U;
            aOrbiterK = (((aWandererK + RotL64(aScatter, 47U)) + RotL64(aCarry, 3U)) + 823673076571076303U) + aPhaseFOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = (aWandererF + RotL64(aPrevious, 13U)) + 1634084509064077736U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 1288134975466877686U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 2998220403162908444U;
            aOrbiterA = RotL64((aOrbiterA * 4321412662318298283U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterD) + 220430672180734911U) + aNonceWordI;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 10223923547068528867U) ^ aNonceWordA;
            aOrbiterJ = RotL64((aOrbiterJ * 12577370238343872139U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 11696469696177647608U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 6545430420379636963U;
            aOrbiterC = RotL64((aOrbiterC * 8387163146257553773U), 37U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterK) + 79691451831797107U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 8971444023498649419U;
            aOrbiterG = RotL64((aOrbiterG * 7148919880477390009U), 11U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 5624403902454498793U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 9468064161002030997U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 12U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 8243560528100864595U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 4619361544913629805U) + aNonceWordJ;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 12682446273369750704U;
            aOrbiterK = RotL64((aOrbiterK * 10879074713156075641U), 5U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterG) + 8728730962617599223U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 9099675924074253030U;
            aOrbiterD = RotL64((aOrbiterD * 5525644236954497523U), 23U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 3298303921318288541U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 5953276499411658358U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 10565471305001292693U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 6725769507592688539U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 1057277456510215817U;
            aOrbiterB = RotL64((aOrbiterB * 8269412198279297075U), 43U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 26U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterE, 57U));
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 21U));
            aIngress = aIngress + (RotL64(aOrbiterG, 35U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterC, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 19U) + RotL64(aOrbiterG, 43U)) + aOrbiterA);
            aWandererE = aWandererE + (((RotL64(aIngress, 23U) + RotL64(aOrbiterE, 22U)) + aOrbiterC) + aNonceWordO);
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterB, 47U)) + aNonceWordH);
            aWandererG = aWandererG + (((RotL64(aCross, 56U) + RotL64(aOrbiterB, 5U)) + aOrbiterD) + aNonceWordB);
            aWandererD = aWandererD ^ (((RotL64(aIngress, 47U) + RotL64(aOrbiterC, 57U)) + aOrbiterB) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 51U) + aOrbiterH) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 53U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 37U) + RotL64(aOrbiterJ, 37U)) + aOrbiterK) + aNonceWordM);
            aWandererH = aWandererH + ((((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 53U)) + aOrbiterH) + RotL64(aCarry, 13U)) + aPhaseFWandererUpdateSaltA[((aIndex + 20U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 60U) + aOrbiterH) + RotL64(aOrbiterA, 13U));
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererD, 21U));
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererF, 34U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 5U));
            aCarry = aCarry + (RotL64(aWandererA, 57U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererH, 27U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aExpandLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // seed_loop_f loop 5
        // ingress from: aExpandLaneB, aSnowLaneD, aSnowLaneA
        // ingress directions: aExpandLaneB forward forced, aSnowLaneD forward forced, aSnowLaneA forward/backward random
        // cross from: aExpandLaneA, aSnowLaneC
        // cross directions: aExpandLaneA backward forced, aSnowLaneC backward/forward random
        // write to: aExpandLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneB[((aIndex + 26874U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneD[((aIndex + 25700U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 25489U)) & S_BLOCK1], 50U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25252U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 23082U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordB));
            //
            aScatter = (RotL64(aPrevious, 3U) + RotL64(aCross, 34U)) ^ (RotL64(aIngress, 51U) ^ RotL64(aCarry, 21U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordP));
            //
            aOrbiterF = (aWandererJ + RotL64(aIngress, 41U)) + 10881271196314989997U;
            aOrbiterG = ((aWandererF + RotL64(aScatter, 37U)) + 6406461249988567558U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = ((aWandererH + RotL64(aPrevious, 11U)) + RotL64(aCarry, 57U)) + 17255067918280095959U;
            aOrbiterJ = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 37U)) + 16690850682497718411U) + aNonceWordK;
            aOrbiterH = ((aWandererE + RotL64(aIngress, 26U)) + 5576201059361086866U) + aNonceWordF;
            aOrbiterD = ((aWandererI + RotL64(aPrevious, 47U)) + 11991259685693687554U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterC = (aWandererC + RotL64(aCross, 21U)) + 14652535244217836909U;
            aOrbiterA = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 13U)) + 1701789037170782122U;
            aOrbiterI = (aWandererB + RotL64(aIngress, 30U)) + 953429054903473833U;
            //
            aOrbiterF = ((aOrbiterF + aOrbiterG) + 12064513610469714211U) + aNonceWordA;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 7993881398822002424U;
            aOrbiterE = RotL64((aOrbiterE * 11572884842788918377U), 37U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterE) + 14421313768013320050U) + aPhaseFOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 11112386845630998889U;
            aOrbiterH = RotL64((aOrbiterH * 11771526352030371669U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 17069630896535699015U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterD) ^ 3308240081138623373U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 10449509484417835159U), 5U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterA) + 17615529807112933619U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterH) ^ 11782807146851563541U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12992075832343669221U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 14401645829607611983U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 6736397344219993532U;
            aOrbiterJ = RotL64((aOrbiterJ * 1667287547938175641U), 47U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterI) + 6446974060524700550U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterG) ^ 7840991992443308254U) ^ aNonceWordL;
            aOrbiterD = RotL64((aOrbiterD * 6891023544882740107U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 10362169906019794305U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 4503700997923168911U;
            aOrbiterA = RotL64((aOrbiterA * 15066164494038852559U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterC) + 13492041134973259041U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 14337899277551397976U;
            aOrbiterI = RotL64((aOrbiterI * 5966740718899290915U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 13693100781608180748U) + aPhaseFOrbiterUpdateSaltB[((aIndex + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 16177545026405910052U;
            aOrbiterF = RotL64((aOrbiterF * 6019231448444020563U), 27U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterI, 51U);
            aIngress = aIngress + (RotL64(aOrbiterA, 11U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterJ);
            aIngress = aIngress + (RotL64(aOrbiterC, 38U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterH, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aCross, 58U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            aWandererH = aWandererH + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterF);
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterI) + aNonceWordH);
            aWandererC = aWandererC + ((((RotL64(aIngress, 47U) + aOrbiterJ) + RotL64(aOrbiterG, 28U)) + RotL64(aCarry, 11U)) + aPhaseFWandererUpdateSaltE[((aIndex + 19U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + aOrbiterI) + RotL64(aOrbiterJ, 35U)) + aNonceWordE);
            aWandererB = aWandererB + ((RotL64(aPrevious, 23U) + RotL64(aOrbiterF, 53U)) + aOrbiterE);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 30U) + RotL64(aOrbiterA, 41U)) + aOrbiterH) + aPhaseFWandererUpdateSaltD[((aIndex + 23U)) & S_SALT1]);
            aWandererF = aWandererF + (((RotL64(aCross, 3U) + aOrbiterD) + RotL64(aOrbiterJ, 58U)) + RotL64(aCarry, 41U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterH, 11U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 5U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererE, 14U));
            aCarry = aCarry + (RotL64(aWandererC, 35U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererH, 51U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererF, 27U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_f loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aSnowLaneB
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aSnowLaneB forward/backward random
        // cross from: aExpandLaneB, aOperationLaneB
        // cross directions: aExpandLaneB backward forced, aOperationLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 29907U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneA[((aIndex + 29176U)) & S_BLOCK1], 28U));
            aIngress ^= RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 31859U)) & S_BLOCK1], 47U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseFDomainWordIngress) ^ aNonceWordM));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27503U)) & S_BLOCK1], 13U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 31672U)) & S_BLOCK1], 3U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseFDomainWordCross) ^ aNonceWordN));
            //
            aScatter = (RotL64(aCross, 23U) ^ RotL64(aIngress, 53U)) + (RotL64(aCarry, 38U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseFDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterG = ((aWandererF + RotL64(aIngress, 20U)) + 6916817163240024692U) + aNonceWordJ;
            aOrbiterD = (aWandererH + RotL64(aScatter, 47U)) + 14554930751292077817U;
            aOrbiterF = (aWandererG + RotL64(aPrevious, 51U)) + 1098305064484336101U;
            aOrbiterA = (((aWandererI + RotL64(aCross, 27U)) + 12192821172420471527U) + aPhaseFOrbiterAssignSaltA[(((31U - aIndex) + 28U)) & S_SALT1]) + aNonceWordL;
            aOrbiterC = (aWandererA + RotL64(aPrevious, 58U)) + 2435134991707318845U;
            aOrbiterI = ((aWandererD + RotL64(aScatter, 39U)) + RotL64(aCarry, 3U)) + 1896745368738512624U;
            aOrbiterB = (aWandererJ + RotL64(aIngress, 35U)) + 1114996424222923873U;
            aOrbiterK = ((aWandererE + RotL64(aCross, 5U)) + RotL64(aCarry, 39U)) + 9839135798371512656U;
            aOrbiterH = (((aWandererC + RotL64(aIngress, 11U)) + RotL64(aCarry, 47U)) + 8037967239603177043U) + aPhaseFOrbiterAssignSaltD[((aIndex + 24U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 15185468738487237432U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 4912098316394854543U) ^ aNonceWordH;
            aOrbiterF = RotL64((aOrbiterF * 3072785550384399929U), 53U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13142688607850380888U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 4507379759608945839U;
            aOrbiterC = RotL64((aOrbiterC * 2989332387754215967U), 23U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterG) + 7299006009652289342U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 5390655277207053627U;
            aOrbiterA = RotL64((aOrbiterA * 10973744708856143715U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 6744737023577785725U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 15539737698867067285U;
            aOrbiterG = RotL64((aOrbiterG * 4686092035261336911U), 47U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 13329866734681377952U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 13284937458969166257U;
            aOrbiterB = RotL64((aOrbiterB * 3965985432462699445U), 43U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterH) + 8695002088915702168U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterB) ^ 3858059421620839286U) ^ aNonceWordC;
            aOrbiterD = RotL64((aOrbiterD * 9559783727301092937U), 3U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 6609163873243179836U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 9416165620556710540U;
            aOrbiterK = RotL64((aOrbiterK * 240385043740268229U), 29U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterA) + 1578449067529000433U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterH = (((aOrbiterH ^ aOrbiterK) ^ 14309000104419489303U) ^ aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1]) ^ aNonceWordE;
            aOrbiterH = RotL64((aOrbiterH * 7599078306153684729U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 15785180680737461320U) + aPhaseFOrbiterUpdateSaltD[((aIndex + 5U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 10099222679918382021U;
            aOrbiterI = RotL64((aOrbiterI * 2012232597046182581U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterG, 26U);
            aIngress = aIngress + (RotL64(aOrbiterH, 21U) ^ aOrbiterF);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 47U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + RotL64(aOrbiterC, 35U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 3U) + aOrbiterH) + RotL64(aOrbiterA, 19U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 37U) + aOrbiterA) + RotL64(aOrbiterG, 39U)) + aNonceWordI);
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 10U) + aOrbiterC) + RotL64(aOrbiterF, 13U));
            aWandererI = aWandererI + ((((RotL64(aIngress, 57U) + aOrbiterI) + RotL64(aOrbiterG, 46U)) + aNonceWordF) + aPhaseFWandererUpdateSaltF[((aIndex + 25U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 27U) + RotL64(aOrbiterF, 35U)) + aOrbiterK);
            aWandererE = aWandererE + (((RotL64(aScatter, 41U) + aOrbiterK) + RotL64(aOrbiterI, 29U)) + RotL64(aCarry, 53U));
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 48U) + aOrbiterD) + RotL64(aOrbiterG, 5U));
            aWandererD = aWandererD + ((((RotL64(aIngress, 23U) + aOrbiterG) + RotL64(aOrbiterB, 51U)) + RotL64(aCarry, 27U)) + aNonceWordO);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 19U) + aOrbiterF) + RotL64(aOrbiterG, 56U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 54U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererJ, 41U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererA, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Lacrosse_Arx::Seed_G(TwistWorkSpace *pWorkSpace,
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
    std::uint64_t aNonceWordA = TwistMix64::DiffuseC(pNonce * 0xCA8749687C15E195ULL + 0x9F3D99EF8D418F56ULL);
    std::uint64_t aNonceWordB = TwistMix64::DiffuseC(pNonce * 0xF6E26EA72A340D69ULL + 0xF5FACA89BFA39C55ULL);
    std::uint64_t aNonceWordC = TwistMix64::DiffuseC(pNonce * 0xB0A5F6CA4D2A6723ULL + 0xF5F0F6397D9CD6A1ULL);
    std::uint64_t aNonceWordD = TwistMix64::DiffuseC(pNonce * 0xD434D610B96CF0F3ULL + 0xBE46F3182F2AE06BULL);
    std::uint64_t aNonceWordE = TwistMix64::DiffuseA(pNonce * 0xC788633A6DCDC0A3ULL + 0xABBD59397BF34F85ULL);
    std::uint64_t aNonceWordF = TwistMix64::DiffuseB(pNonce * 0xF777A36C472456CBULL + 0xF7282C1D5E61D8ABULL);
    std::uint64_t aNonceWordG = TwistMix64::DiffuseB(pNonce * 0xA78EAC3AEE1FAF85ULL + 0xABDBAB622AC326D7ULL);
    std::uint64_t aNonceWordH = TwistMix64::DiffuseA(pNonce * 0xAE01D859AAA9CCF3ULL + 0x82EA50895B90750CULL);
    std::uint64_t aNonceWordI = TwistMix64::DiffuseC(pNonce * 0x8134E9438E47CDC5ULL + 0xC9EB2D0E67AA1421ULL);
    std::uint64_t aNonceWordJ = TwistMix64::DiffuseB(pNonce * 0x823AD98D168CEA71ULL + 0xA7E80F7A6FBB03FFULL);
    std::uint64_t aNonceWordK = TwistMix64::DiffuseB(pNonce * 0xCFC1680FEF0B6433ULL + 0xFF386590A183895CULL);
    std::uint64_t aNonceWordL = TwistMix64::DiffuseB(pNonce * 0x892FCFED1E05824DULL + 0x91FB29C9D8497E48ULL);
    std::uint64_t aNonceWordM = TwistMix64::DiffuseC(pNonce * 0xFDE73EE908D4ED27ULL + 0x8FD4B7F368FDB567ULL);
    std::uint64_t aNonceWordN = TwistMix64::DiffuseB(pNonce * 0xCAE6EF93E2EFC9BDULL + 0x9887F174090B64ADULL);
    std::uint64_t aNonceWordO = TwistMix64::DiffuseC(pNonce * 0xDCDB38818473580BULL + 0xC78EC276DC08F43BULL);
    std::uint64_t aNonceWordP = TwistMix64::DiffuseB(pNonce * 0x9207DBFB1ADAD247ULL + 0xE57A4A633C5CC528ULL);
    // GSeedRunSeed_G seed_loop_h (start)
    {
        // GSeedRunSeed_G seed_loop_h lane group
        // read from: aSnowLaneA, aSnowLaneB, aInvestLaneD, aSnowLaneC, aSnowLaneD, aInvestLaneA, aWorkLaneA, aFireLaneB, aInvestLaneC, aWorkLaneB, aFireLaneC, aExpandLaneA, aInvestLaneB, aExpandLaneB, aFireLaneD, aExpandLaneC, aFireLaneA
        // write to: aWorkLaneA, aWorkLaneB, aExpandLaneA, aExpandLaneB, aExpandLaneC, aExpandLaneD
    
        // seed_loop_h loop 1
        // ingress from: aSnowLaneA, aSnowLaneB, aInvestLaneD
        // ingress directions: aSnowLaneA forward forced, aSnowLaneB forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneC, aSnowLaneD, aInvestLaneA
        // cross directions: aSnowLaneC backward forced, aSnowLaneD backward forced, aInvestLaneA backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 2967U)) & S_BLOCK1], 5U) ^ RotL64(aSnowLaneB[((aIndex + 3953U)) & S_BLOCK1], 50U));
            aIngress ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 686U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordK));
            //
            aCross = (RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 784U)) & S_BLOCK1], 12U) ^ RotL64(aSnowLaneD[((S_BLOCK1 - aIndex + 5397U)) & S_BLOCK1], 41U));
            aCross ^= RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 2989U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordC));
            //
            aScatter = (RotL64(aIngress, 53U) + RotL64(aCarry, 3U)) ^ (RotL64(aPrevious, 41U) ^ RotL64(aCross, 18U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterA = (aWandererA + RotL64(aIngress, 51U)) + 14499676118633326000U;
            aOrbiterH = ((aWandererC + RotL64(aCross, 35U)) + 17191273593018552288U) + aNonceWordE;
            aOrbiterJ = (((aWandererF + RotL64(aPrevious, 11U)) + RotL64(aCarry, 43U)) + 4085176294948097737U) + aNonceWordB;
            aOrbiterG = (((aWandererB + RotL64(aScatter, 5U)) + RotL64(aCarry, 23U)) + 11112671474158908186U) + aNonceWordG;
            aOrbiterI = (((aWandererD + RotL64(aPrevious, 43U)) + 8745787969012266485U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1]) + aNonceWordI;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 22U)) + RotL64(aCarry, 5U)) + 18074049663777707948U;
            aOrbiterC = ((aWandererE + RotL64(aCross, 29U)) + 2543758649719164688U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 24U)) & S_SALT1];
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 4659584749412700523U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 974639159259871273U;
            aOrbiterJ = RotL64((aOrbiterJ * 17918719351847605523U), 5U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterG) + 9211220687971081987U) + aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 8567024626862182714U;
            aOrbiterI = RotL64((aOrbiterI * 7755874089832496393U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 5803002132294840900U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterG) ^ 11968489432878148467U) ^ aNonceWordM;
            aOrbiterA = RotL64((aOrbiterA * 4501441062617123165U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 9470807228394903442U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterH = ((aOrbiterH ^ aOrbiterK) ^ 1692347973120388469U) ^ aNonceWordF;
            aOrbiterH = RotL64((aOrbiterH * 17433393164156231575U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterA) + 16510815732690193145U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 755159406833096510U;
            aOrbiterC = RotL64((aOrbiterC * 14091736464659561165U), 29U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 1518824876475937620U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 701225390867330446U) ^ aNonceWordN;
            aOrbiterK = RotL64((aOrbiterK * 12264618860580199927U), 53U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 8425976693733003889U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 7182176375442410367U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 8860605703761731859U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterJ, 29U);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterH, 51U));
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 22U));
            aIngress = aIngress + RotL64(aOrbiterG, 5U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aIngress, 11U) + RotL64(aOrbiterH, 44U)) + aOrbiterC) + RotL64(aCarry, 53U));
            aWandererB = aWandererB ^ (((RotL64(aScatter, 54U) + RotL64(aOrbiterC, 35U)) + aOrbiterG) + aNonceWordJ);
            aWandererE = aWandererE + ((RotL64(aCross, 35U) + RotL64(aOrbiterJ, 13U)) + aOrbiterI);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 57U));
            aWandererG = aWandererG + (((RotL64(aCross, 3U) + aOrbiterG) + RotL64(aOrbiterH, 29U)) + aNonceWordH);
            aWandererD = aWandererD ^ ((((RotL64(aScatter, 21U) + aOrbiterJ) + RotL64(aOrbiterC, 23U)) + aNonceWordO) + aPhaseHWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererA = aWandererA + ((((RotL64(aPrevious, 43U) + aOrbiterA) + RotL64(aOrbiterH, 51U)) + RotL64(aCarry, 37U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererA, 14U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 23U));
            aCarry = aCarry + RotL64(aWandererE, 43U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseA(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 2
        // ingress from: aWorkLaneA, aSnowLaneC, aSnowLaneD, aFireLaneB
        // ingress directions: aWorkLaneA forward forced, aSnowLaneC forward forced, aSnowLaneD forward forced, aFireLaneB forward/backward random
        // cross from: aSnowLaneA, aSnowLaneB, aInvestLaneC
        // cross directions: aSnowLaneA backward forced, aSnowLaneB backward forced, aInvestLaneC backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 8788U)) & S_BLOCK1], 57U) ^ RotL64(aSnowLaneC[((aIndex + 6334U)) & S_BLOCK1], 13U));
            aIngress ^= (RotL64(aSnowLaneD[((aIndex + 10921U)) & S_BLOCK1], 36U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 9290U)) & S_BLOCK1], 5U));
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = (RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 8601U)) & S_BLOCK1], 10U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 10343U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 7262U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aCross, 18U) ^ RotL64(aPrevious, 5U)) + (RotL64(aIngress, 57U) + RotL64(aCarry, 37U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 37U)) + RotL64(aCarry, 13U)) + 16922357079016918108U;
            aOrbiterF = (aWandererH + RotL64(aIngress, 43U)) + 11771749797137599131U;
            aOrbiterA = ((aWandererF + RotL64(aScatter, 51U)) + 4635668433708036077U) + aNonceWordD;
            aOrbiterE = (((aWandererG + RotL64(aPrevious, 6U)) + 15827952719230577008U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 9U)) & S_SALT1]) + aNonceWordM;
            aOrbiterJ = ((((aWandererB + RotL64(aIngress, 23U)) + RotL64(aCarry, 57U)) + 1495675306110023086U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 13U)) & S_SALT1]) + aNonceWordI;
            aOrbiterB = ((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 43U)) + 7294835466949728365U;
            aOrbiterD = ((aWandererC + RotL64(aPrevious, 29U)) + 179122461212041978U) + aNonceWordF;
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 545981421632236251U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 15338259639814630535U;
            aOrbiterA = RotL64((aOrbiterA * 14895421566334357871U), 35U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 12924313840290895215U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 17846785921286020610U;
            aOrbiterJ = RotL64((aOrbiterJ * 18309347016029917133U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 5721472794107057875U;
            aOrbiterE = (aOrbiterE ^ aOrbiterA) ^ 16359630793856870319U;
            aOrbiterE = RotL64((aOrbiterE * 14186771515526698907U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 10614102110239037308U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 16421992251278236531U) ^ aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2561232904676068089U), 27U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 8668149834861244963U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 26U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 12699331834360948734U;
            aOrbiterF = RotL64((aOrbiterF * 2249360824172616357U), 43U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterJ) + 4470693178142950471U) + aPhaseHOrbiterUpdateSaltF[((aIndex + 28U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterF) ^ 526000656022724741U) ^ aNonceWordH;
            aOrbiterB = RotL64((aOrbiterB * 16688501462334673493U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 6880246132270094141U;
            aOrbiterD = (((aOrbiterD ^ aOrbiterJ) ^ 7126466778855297013U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]) ^ aNonceWordP;
            aOrbiterD = RotL64((aOrbiterD * 5692237926830293205U), 21U);
            //
            aIngress = aOrbiterJ ^ RotL64(aOrbiterA, 13U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 37U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterH, 5U));
            aIngress = aIngress + RotL64(aOrbiterE, 60U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterA, 13U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 29U)) + aOrbiterH) + RotL64(aCarry, 35U));
            aWandererE = aWandererE ^ ((RotL64(aCross, 43U) + RotL64(aOrbiterF, 35U)) + aOrbiterB);
            aWandererB = aWandererB + ((((RotL64(aScatter, 21U) + RotL64(aOrbiterD, 47U)) + aOrbiterF) + RotL64(aCarry, 51U)) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 36U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererI = aWandererI + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterB, 53U)) + aOrbiterE) + aNonceWordG);
            aWandererF = aWandererF ^ ((((RotL64(aCross, 57U) + RotL64(aOrbiterF, 22U)) + aOrbiterJ) + aNonceWordB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 22U));
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererG, 29U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererF, 47U));
            aCarry = aCarry + RotL64(aWandererC, 5U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 14139U)) & S_BLOCK1], 21U) ^ RotL64(aSnowLaneA[((aIndex + 11281U)) & S_BLOCK1], 35U));
            aIngress ^= RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 15711U)) & S_BLOCK1], 56U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordP));
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12995U)) & S_BLOCK1], 11U) ^ RotL64(aSnowLaneC[((S_BLOCK1 - aIndex + 12718U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordH));
            //
            aScatter = (RotL64(aCross, 39U) ^ RotL64(aPrevious, 20U)) + (RotL64(aIngress, 5U) ^ RotL64(aCarry, 53U));
            aScatter = TwistMix64::DiffuseA(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordJ));
            //
            aOrbiterG = ((aWandererJ + RotL64(aCross, 23U)) + RotL64(aCarry, 29U)) + 785861751704720606U;
            aOrbiterF = (((aWandererE + RotL64(aIngress, 37U)) + RotL64(aCarry, 51U)) + 15968088718435606299U) + aNonceWordM;
            aOrbiterC = (((aWandererA + RotL64(aPrevious, 53U)) + 1393976526590347151U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 11U)) & S_SALT1]) + aNonceWordA;
            aOrbiterD = ((aWandererI + RotL64(aScatter, 29U)) + RotL64(aCarry, 5U)) + 17240750947292745884U;
            aOrbiterB = (aWandererC + RotL64(aCross, 5U)) + 4921576136163183137U;
            aOrbiterJ = ((aWandererB + RotL64(aIngress, 47U)) + 3334047873553153032U) + aPhaseHOrbiterAssignSaltC[((aIndex + 18U)) & S_SALT1];
            aOrbiterH = (aWandererF + RotL64(aPrevious, 60U)) + 15086509978458408698U;
            //
            aOrbiterG = ((aOrbiterG + aOrbiterF) + 892391205397581998U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2965686403183767521U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 19U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 709160942482770225U), 51U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterB) + 14632215393655706170U) + aNonceWordK;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterD) ^ 15740589515342377322U) ^ aNonceWordE;
            aOrbiterJ = RotL64((aOrbiterJ * 15677716942904794913U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 11131164813943086445U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6988080581278900960U;
            aOrbiterD = RotL64((aOrbiterD * 6412189142344044255U), 43U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 16021254613117657178U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterH) ^ 6183615599897921154U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 27U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 9976411093264211033U), 13U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12533992547026652747U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 3104325358982904219U;
            aOrbiterH = RotL64((aOrbiterH * 14977348108778147265U), 29U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 3878525937957474644U) + aNonceWordJ;
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 2120435259884368445U;
            aOrbiterG = RotL64((aOrbiterG * 15964718652193073177U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterG) + 14928658302694194856U) + aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 9121310461310309348U) ^ aNonceWordF;
            aOrbiterF = RotL64((aOrbiterF * 17304439784647477491U), 5U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterH, 47U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 4U));
            aIngress = aIngress + RotL64(aOrbiterJ, 41U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aIngress, 19U) + RotL64(aOrbiterF, 5U)) + aOrbiterC) + aNonceWordD);
            aWandererB = aWandererB + ((RotL64(aCross, 37U) + aOrbiterB) + RotL64(aOrbiterH, 11U));
            aWandererI = aWandererI ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterF, 43U)) + aOrbiterH) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererE = aWandererE + (((RotL64(aPrevious, 30U) + RotL64(aOrbiterC, 19U)) + aOrbiterD) + RotL64(aCarry, 21U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 51U) + RotL64(aOrbiterF, 51U)) + aOrbiterG);
            aWandererA = aWandererA + (((((RotL64(aIngress, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 27U)) + RotL64(aCarry, 51U)) + aNonceWordB) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 9U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 3U) + aOrbiterB) + RotL64(aOrbiterD, 34U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 6U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererJ, 47U) ^ aWandererB);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererA, 21U));
            aCarry = aCarry + RotL64(aWandererE, 41U);
            aCarry = aCarry + RotL64(aIngress, 60U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 16889U)) & S_BLOCK1], 23U) ^ RotL64(aWorkLaneA[((aIndex + 21792U)) & S_BLOCK1], 44U));
            aIngress ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 16599U)) & S_BLOCK1], 57U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordJ));
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 19194U)) & S_BLOCK1], 51U) ^ RotL64(aSnowLaneD[((aIndex + 16863U)) & S_BLOCK1], 22U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordL));
            //
            aScatter = (RotL64(aPrevious, 21U) ^ RotL64(aCross, 5U)) + (RotL64(aIngress, 43U) + RotL64(aCarry, 56U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordH));
            //
            aOrbiterC = ((aWandererD + RotL64(aIngress, 11U)) + 12980104182836602177U) + aNonceWordC;
            aOrbiterJ = (((aWandererF + RotL64(aScatter, 53U)) + 3172622203188863995U) + aPhaseHOrbiterAssignSaltE[((aIndex + 27U)) & S_SALT1]) + aNonceWordP;
            aOrbiterK = ((aWandererA + RotL64(aPrevious, 35U)) + RotL64(aCarry, 3U)) + 1170974132219980203U;
            aOrbiterI = (((aWandererG + RotL64(aCross, 3U)) + RotL64(aCarry, 21U)) + 6035201940965047490U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererB + RotL64(aIngress, 19U)) + RotL64(aCarry, 53U)) + 18033907118424996722U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 28U)) + 14604813424800580304U) + aNonceWordD;
            aOrbiterH = ((aWandererK + RotL64(aScatter, 41U)) + 13720232492851066035U) + aNonceWordO;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 3902659710585257448U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterC) ^ 8331560652661619868U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 3U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11418103770615560205U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 4485014147538689794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 168202636924512424U;
            aOrbiterB = RotL64((aOrbiterB * 13711020666131492091U), 43U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 16227825670092707848U;
            aOrbiterC = (((aOrbiterC ^ aOrbiterE) ^ 4792781933944671365U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]) ^ aNonceWordH;
            aOrbiterC = RotL64((aOrbiterC * 15859849676231455283U), 57U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 12636865372722601282U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 18198291399585556632U) ^ aNonceWordI;
            aOrbiterI = RotL64((aOrbiterI * 18155803890313399795U), 27U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3650053185419807206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterH) ^ 5897288963905408776U;
            aOrbiterJ = RotL64((aOrbiterJ * 3706949366974086151U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 9922308113622901726U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterB) ^ 13352279749091561510U) ^ aNonceWordM;
            aOrbiterH = RotL64((aOrbiterH * 4025213180483632557U), 19U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 14969461950939646117U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 10231661776135056651U;
            aOrbiterE = RotL64((aOrbiterE * 11284575051455238501U), 37U);
            //
            aIngress = RotL64(aOrbiterC, 3U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (RotL64(aOrbiterK, 51U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterB, 12U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 47U) + aOrbiterK) + RotL64(aOrbiterJ, 27U)) + aNonceWordE);
            aWandererI = aWandererI + (((RotL64(aCross, 11U) + RotL64(aOrbiterJ, 41U)) + aOrbiterI) + aPhaseHWandererUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1]);
            aWandererK = aWandererK ^ (((RotL64(aIngress, 35U) + aOrbiterH) + RotL64(aOrbiterC, 48U)) + aNonceWordB);
            aWandererD = aWandererD + (((RotL64(aScatter, 58U) + RotL64(aOrbiterK, 35U)) + aOrbiterB) + RotL64(aCarry, 27U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 41U) + RotL64(aOrbiterC, 3U)) + aOrbiterE);
            aWandererG = aWandererG + (((RotL64(aPrevious, 21U) + aOrbiterI) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 11U));
            aWandererA = aWandererA ^ ((((RotL64(aCross, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterE) + aNonceWordK) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 47U));
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererI, 3U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 60U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 21U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 23121U)) & S_BLOCK1], 13U) ^ RotL64(aWorkLaneB[((aIndex + 22764U)) & S_BLOCK1], 30U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 22127U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordA));
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 24947U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneA[((aIndex + 24684U)) & S_BLOCK1], 10U);
            aCross = TwistMix64::DiffuseA(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordO));
            //
            aScatter = (RotL64(aIngress, 47U) ^ RotL64(aCarry, 13U)) + (RotL64(aPrevious, 27U) ^ RotL64(aCross, 60U));
            aScatter = TwistMix64::DiffuseC(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordB));
            //
            aOrbiterE = ((((aWandererA + RotL64(aCross, 60U)) + RotL64(aCarry, 37U)) + 13915875634607599122U) + aPhaseHOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1]) + aNonceWordF;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 27U)) + 1695770381382411673U;
            aOrbiterC = (((aWandererE + RotL64(aScatter, 13U)) + RotL64(aCarry, 5U)) + 3709105579778295511U) + aPhaseHOrbiterAssignSaltD[(((31U - aIndex) + 10U)) & S_SALT1];
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 21U)) + RotL64(aCarry, 21U)) + 7673376335333251804U;
            aOrbiterF = ((aWandererC + RotL64(aCross, 41U)) + 8814147709738503518U) + aNonceWordP;
            aOrbiterK = (aWandererK + RotL64(aIngress, 51U)) + 13451412605350381172U;
            aOrbiterD = ((aWandererG + RotL64(aPrevious, 3U)) + 6447870234069609538U) + aNonceWordD;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 13419487997946496825U) + aNonceWordJ;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 5478309847615220345U;
            aOrbiterC = RotL64((aOrbiterC * 12953043149543448765U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 3635184969215610049U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 12527903812035294828U;
            aOrbiterE = RotL64((aOrbiterE * 12540800512035534967U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 1684685110885338814U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 12860354576326835090U;
            aOrbiterF = RotL64((aOrbiterF * 12743745087733307255U), 57U);
            //
            aOrbiterJ = (((aOrbiterJ + aOrbiterK) + 9081823570147481835U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1]) + aNonceWordH;
            aOrbiterI = ((aOrbiterI ^ aOrbiterJ) ^ 14369321778210049109U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 11U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 17865953349448767035U), 37U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 11518132079084873250U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 11893535026126957389U;
            aOrbiterJ = RotL64((aOrbiterJ * 15751374986135615095U), 13U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 7084079180579206226U) + aPhaseHOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 2999676609847603277U) ^ aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14602698397511266403U), 21U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17683445810614029153U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 11576460512964896969U;
            aOrbiterD = RotL64((aOrbiterD * 5243651036457051155U), 51U);
            //
            aIngress = RotL64(aOrbiterF, 27U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterC, 35U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterJ, 6U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterE, 51U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((((RotL64(aIngress, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterD) + RotL64(aCarry, 43U)) + aNonceWordB) + aPhaseHWandererUpdateSaltB[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererA = aWandererA ^ (((RotL64(aScatter, 29U) + RotL64(aOrbiterK, 30U)) + aOrbiterJ) + aNonceWordE);
            aWandererK = aWandererK + (((RotL64(aCross, 21U) + aOrbiterE) + RotL64(aOrbiterD, 3U)) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterF, 51U)) + aOrbiterI);
            aWandererE = aWandererE + (((RotL64(aScatter, 5U) + aOrbiterC) + RotL64(aOrbiterK, 11U)) + aNonceWordM);
            aWandererC = aWandererC ^ ((RotL64(aCross, 11U) + aOrbiterI) + RotL64(aOrbiterC, 57U));
            aWandererF = aWandererF + (((RotL64(aIngress, 38U) + aOrbiterD) + RotL64(aOrbiterC, 37U)) + aPhaseHWandererUpdateSaltF[((aIndex + 17U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + (RotL64(aWandererI, 20U) ^ aWandererG);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererA, 35U));
            aCarry = aCarry + RotL64(aWandererE, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aExpandLaneC[aIndex] = aIngress;
        }
    
        // seed_loop_h loop 6
        // ingress from: aExpandLaneC, aExpandLaneA, aFireLaneA
        // ingress directions: aExpandLaneC forward forced, aExpandLaneA forward forced, aFireLaneA forward/backward random
        // cross from: aExpandLaneB, aSnowLaneB
        // cross directions: aExpandLaneB backward forced, aSnowLaneB backward/forward random
        // write to: aExpandLaneD
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneC[((aIndex + 32013U)) & S_BLOCK1], 51U) ^ RotL64(aExpandLaneA[((aIndex + 28647U)) & S_BLOCK1], 11U));
            aIngress ^= RotL64(aFireLaneA[((aIndex + 31073U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(((aIngress ^ aPhaseHDomainWordIngress) ^ aNonceWordE));
            //
            aCross = RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 28847U)) & S_BLOCK1], 3U) ^ RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 30024U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseC(((aCross ^ aPhaseHDomainWordCross) ^ aNonceWordJ));
            //
            aScatter = (RotL64(aCarry, 21U) ^ RotL64(aPrevious, 37U)) + (RotL64(aCross, 51U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseB(((aScatter ^ aPhaseHDomainWordScatter) ^ aNonceWordG));
            //
            aOrbiterH = (((aWandererI + RotL64(aScatter, 41U)) + RotL64(aCarry, 23U)) + 5041131702736607991U) + aNonceWordF;
            aOrbiterJ = (((aWandererC + RotL64(aCross, 21U)) + RotL64(aCarry, 37U)) + 9295010428212681446U) + aNonceWordH;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 35U)) + 6235875895358766017U;
            aOrbiterF = (aWandererB + RotL64(aIngress, 57U)) + 2622227802531866918U;
            aOrbiterI = (aWandererD + RotL64(aScatter, 47U)) + 3888894734834524972U;
            aOrbiterK = ((((aWandererH + RotL64(aPrevious, 14U)) + RotL64(aCarry, 57U)) + 241682012014701753U) + aPhaseHOrbiterAssignSaltF[(((31U - aIndex) + 3U)) & S_SALT1]) + aNonceWordC;
            aOrbiterE = ((aWandererF + RotL64(aIngress, 29U)) + 15758000422451568079U) + aPhaseHOrbiterAssignSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 2061944548396976912U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 8177144990755754531U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 23U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 12702392689484397947U), 13U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterH) + 554978075608818497U) + aNonceWordP;
            aOrbiterI = (aOrbiterI ^ aOrbiterF) ^ 250408260560714933U;
            aOrbiterI = RotL64((aOrbiterI * 1295379390497107727U), 29U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 8700027645880997552U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 10026130047465480902U;
            aOrbiterH = RotL64((aOrbiterH * 12417270861933696623U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterI) + 9785843014096326696U) + aNonceWordB;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterE) ^ 9998582683258411251U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 22U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7197956237569462269U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 13817734599383455151U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 6647207154174092691U;
            aOrbiterE = RotL64((aOrbiterE * 1578528131687283531U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 4957715980509035719U;
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 4994885315786213197U;
            aOrbiterK = RotL64((aOrbiterK * 5676683798126497011U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 5072908311783966503U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterJ) ^ 5535039946192891515U) ^ aPhaseHOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 2989412783482309753U), 3U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterI, 38U);
            aIngress = aIngress + (aOrbiterK ^ RotL64(aOrbiterC, 13U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterH, 29U));
            aIngress = aIngress + RotL64(aOrbiterE, 57U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI + ((((RotL64(aPrevious, 27U) + RotL64(aOrbiterE, 53U)) + aOrbiterI) + RotL64(aCarry, 41U)) + aNonceWordL);
            aWandererC = aWandererC ^ ((((RotL64(aCross, 41U) + aOrbiterC) + RotL64(aOrbiterH, 29U)) + aNonceWordG) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 35U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererH = aWandererH ^ (((RotL64(aIngress, 21U) + aOrbiterF) + RotL64(aOrbiterJ, 19U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererG = aWandererG + ((RotL64(aScatter, 47U) + RotL64(aOrbiterK, 47U)) + aOrbiterI);
            aWandererF = aWandererF ^ (((RotL64(aPrevious, 3U) + aOrbiterF) + RotL64(aOrbiterH, 60U)) + aNonceWordK);
            aWandererB = aWandererB + ((RotL64(aIngress, 56U) + RotL64(aOrbiterK, 13U)) + aOrbiterJ);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 6U));
            aCarry = aCarry + (RotL64(aWandererB, 37U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererH, 23U);
            aCarry = aCarry + RotL64(aIngress, 29U);
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

void TwistExpander_Lacrosse_Arx::Twist_A(TwistWorkSpace *pWorkSpace,
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
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseAWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseASalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltB = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseBOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseBSalts.mOrbiterAssign.mSaltC;
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
    [[maybe_unused]] std::uint64_t *aPhaseCOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mOrbiterAssign.mSaltA;
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
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseCWandererUpdateSaltF = pWorkSpace->mDomainBundle.mPhaseCSalts.mWandererUpdate.mSaltF;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterAssignSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterAssign.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltA = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltA;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDOrbiterUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mOrbiterUpdate.mSaltE;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltB = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltB;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltC = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltC;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltD = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltD;
    [[maybe_unused]] std::uint64_t *aPhaseDWandererUpdateSaltE = pWorkSpace->mDomainBundle.mPhaseDSalts.mWandererUpdate.mSaltE;
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
            aIngress = RotL64(aKeyRowReadA[((aIndex + 196U)) & W_KEY1], 30U) ^ RotL64(aKeyRowReadB[((aIndex + 123U)) & W_KEY1], 5U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 1033U)) & W_KEY1], 5U) ^ RotL64(mSource[((aIndex + 2440U)) & S_BLOCK1], 58U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 53U)) + (RotL64(aCross, 27U) + RotL64(aIngress, 14U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = ((aWandererE + RotL64(aIngress, 60U)) + RotL64(aCarry, 13U)) + 3448371607470865612U;
            aOrbiterK = (aWandererA + RotL64(aPrevious, 23U)) + 3743742913651580573U;
            aOrbiterB = (aWandererF + RotL64(aScatter, 39U)) + 13069491287948807280U;
            aOrbiterJ = (aWandererK + RotL64(aCross, 35U)) + 16872779275586545632U;
            aOrbiterH = ((aWandererI + RotL64(aPrevious, 5U)) + 17945792656755062795U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = ((aWandererD + RotL64(aIngress, 53U)) + 18199747196793731853U) + aPhaseAOrbiterAssignSaltB[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterI = ((aWandererB + RotL64(aCross, 46U)) + RotL64(aCarry, 43U)) + 15953311878379809513U;
            aOrbiterF = ((aWandererC + RotL64(aScatter, 27U)) + RotL64(aCarry, 51U)) + 941268763494588338U;
            aOrbiterE = (aWandererJ + RotL64(aIngress, 11U)) + 10090221530365796809U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 8335698093307607001U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterD) ^ 6147498804734306100U) ^ aPhaseAOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 6904444049941211327U), 53U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 5980246079567570090U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 4152167624425912978U;
            aOrbiterG = RotL64((aOrbiterG * 10019421651535123573U), 27U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterI) + 14990418790239735916U) + aPhaseAOrbiterUpdateSaltA[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 3418668387496597219U;
            aOrbiterJ = RotL64((aOrbiterJ * 12814077238529863119U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 4206650904177199425U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 3905470780938996069U;
            aOrbiterE = RotL64((aOrbiterE * 16030122739273137005U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 9968672788233080924U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 602258075661864866U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 2615726693066300065U), 37U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17751667243048041383U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterK) ^ 2414054413585296027U) ^ aPhaseAOrbiterUpdateSaltC[((aIndex + 8U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1049512574773201893U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6523322402744047752U;
            aOrbiterH = (aOrbiterH ^ aOrbiterI) ^ 6729901917767398779U;
            aOrbiterH = RotL64((aOrbiterH * 8039939871405367139U), 3U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterD) + 11460169185076814539U;
            aOrbiterF = (aOrbiterF ^ aOrbiterG) ^ 7559640379553110573U;
            aOrbiterF = RotL64((aOrbiterF * 9864654321914036135U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 17271150091827475028U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 3541809324556914646U;
            aOrbiterD = RotL64((aOrbiterD * 12655168871428868639U), 43U);
            //
            aIngress = RotL64(aOrbiterG, 10U) ^ aOrbiterE;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 13U));
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterF, 27U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterI, 5U));
            aIngress = aIngress + RotL64(aOrbiterK, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 43U)) + aOrbiterG) + aPhaseAWandererUpdateSaltD[(((31U - aIndex) + 27U)) & S_SALT1]);
            aWandererK = aWandererK + (((RotL64(aPrevious, 30U) + aOrbiterG) + RotL64(aOrbiterE, 35U)) + RotL64(aCarry, 51U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 35U) + aOrbiterB) + RotL64(aOrbiterJ, 12U));
            aWandererD = aWandererD + (((RotL64(aIngress, 47U) + RotL64(aOrbiterD, 53U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterH, 39U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aScatter, 6U) + RotL64(aOrbiterH, 27U)) + aOrbiterI) + aPhaseAWandererUpdateSaltE[((aIndex + 4U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterB, 5U)) + aOrbiterH);
            aWandererF = aWandererF + ((RotL64(aIngress, 19U) + RotL64(aOrbiterD, 57U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aCross, 39U) + aOrbiterK) + RotL64(aOrbiterD, 18U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 22U) ^ aWandererI);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererE, 11U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 29U));
            aCarry = aCarry + RotL64(aWandererA, 40U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = RotL64(aWorkLaneA[((aIndex + 5341U)) & S_BLOCK1], 57U) ^ RotL64(aKeyRowReadA[((aIndex + 3260U)) & W_KEY1], 42U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aKeyRowReadB[(((2047U - aIndex) + 2875U)) & W_KEY1], 46U) ^ RotL64(mSource[((aIndex + 5101U)) & S_BLOCK1], 35U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 34U) + RotL64(aPrevious, 3U)) + (RotL64(aCarry, 21U) ^ RotL64(aIngress, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererE + RotL64(aCross, 51U)) + 15045917390223766480U;
            aOrbiterA = (aWandererG + RotL64(aIngress, 11U)) + 10763054007033668758U;
            aOrbiterJ = ((aWandererI + RotL64(aScatter, 37U)) + RotL64(aCarry, 53U)) + 13190170142593666607U;
            aOrbiterC = ((aWandererK + RotL64(aPrevious, 60U)) + RotL64(aCarry, 19U)) + 9657025731441167065U;
            aOrbiterB = (aWandererD + RotL64(aIngress, 27U)) + 11433367178975954211U;
            aOrbiterH = (aWandererJ + RotL64(aScatter, 23U)) + 17904920143996810366U;
            aOrbiterD = (((aWandererF + RotL64(aCross, 47U)) + RotL64(aCarry, 35U)) + 3244383020512113283U) + aPhaseAOrbiterAssignSaltE[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = ((aWandererH + RotL64(aPrevious, 56U)) + 6538815775171139091U) + aPhaseAOrbiterAssignSaltF[((aIndex + 23U)) & S_SALT1];
            aOrbiterE = (aWandererB + RotL64(aCross, 5U)) + 7195368312757976343U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 18134430713910279374U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 6571776588427107976U;
            aOrbiterJ = RotL64((aOrbiterJ * 11916502085252589161U), 29U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 11830778129647517758U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 9793702760907767365U;
            aOrbiterA = RotL64((aOrbiterA * 4096246227968677179U), 19U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 2287235876793192036U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 8951959188326141794U;
            aOrbiterB = RotL64((aOrbiterB * 9968356718110753845U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 7583061790273240157U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 3571364625022806085U;
            aOrbiterE = RotL64((aOrbiterE * 6238360922735480669U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 13869345563551689212U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 277480328952975002U;
            aOrbiterH = RotL64((aOrbiterH * 1057564597096163085U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 4983735092494677578U) + aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 9490022869381030928U;
            aOrbiterD = RotL64((aOrbiterD * 12926352917961703123U), 57U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterJ) + 7928039573014765566U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterD) ^ 6504190875809407084U) ^ aPhaseAOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14648214826494826711U), 11U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 2787985600176307413U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 16308785053443116826U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 17867565986311256691U), 3U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterC) + 12788128335006767824U) + aPhaseAOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 1187040019537798339U;
            aOrbiterG = RotL64((aOrbiterG * 10834905007658184183U), 41U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterJ, 43U);
            aIngress = aIngress + (RotL64(aOrbiterC, 20U) ^ aOrbiterD);
            aIngress = aIngress + (RotL64(aOrbiterK, 47U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterB, 11U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + aOrbiterG) + RotL64(aOrbiterJ, 20U));
            aWandererH = aWandererH + (((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterC, 5U)) + RotL64(aCarry, 43U));
            aWandererD = aWandererD ^ (((RotL64(aPrevious, 11U) + RotL64(aOrbiterB, 39U)) + aOrbiterE) + aPhaseAWandererUpdateSaltA[((aIndex + 19U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aScatter, 23U) + aOrbiterE) + RotL64(aOrbiterA, 47U));
            aWandererG = aWandererG ^ (((RotL64(aCross, 19U) + RotL64(aOrbiterG, 58U)) + aOrbiterA) + aPhaseAWandererUpdateSaltF[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterA) + RotL64(aOrbiterK, 51U));
            aWandererE = aWandererE + ((RotL64(aScatter, 40U) + aOrbiterK) + RotL64(aOrbiterD, 35U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterH, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererE, 24U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererD, 13U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererH, 21U) ^ aWandererJ);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererF, 53U));
            aCarry = aCarry + RotL64(aWandererK, 36U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = RotL64(aWorkLaneB[((aIndex + 5655U)) & S_BLOCK1], 14U) ^ RotL64(aKeyRowReadB[((aIndex + 8167U)) & W_KEY1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 7745U)) & W_KEY1], 35U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 6562U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 6810U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 53U) + RotL64(aIngress, 35U)) ^ (RotL64(aPrevious, 18U) ^ RotL64(aCarry, 5U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererC + RotL64(aIngress, 58U)) + RotL64(aCarry, 23U)) + 12380376990224645149U) + aPhaseAOrbiterAssignSaltE[((aIndex + 16U)) & S_SALT1];
            aOrbiterI = (aWandererA + RotL64(aPrevious, 5U)) + 18296928500297384014U;
            aOrbiterJ = (aWandererK + RotL64(aScatter, 35U)) + 3550626816361145100U;
            aOrbiterK = (aWandererG + RotL64(aCross, 19U)) + 2667792936946706027U;
            aOrbiterA = (aWandererJ + RotL64(aPrevious, 10U)) + 12020969779370926953U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 47U)) + RotL64(aCarry, 57U)) + 737340727886903447U;
            aOrbiterE = ((aWandererD + RotL64(aIngress, 41U)) + 1681797651799760502U) + aPhaseAOrbiterAssignSaltB[((aIndex + 7U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 51U)) + RotL64(aCarry, 39U)) + 2956186342689489064U;
            aOrbiterC = (aWandererH + RotL64(aPrevious, 27U)) + 1876852870402977177U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 6433205819353555071U) + aPhaseAOrbiterUpdateSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 9065076854974222998U;
            aOrbiterJ = RotL64((aOrbiterJ * 5459675878087242021U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 3254410578766789992U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 2005081975473815576U) ^ aPhaseAOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 9947701153722014085U), 51U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 15992999234834560419U) + aPhaseAOrbiterUpdateSaltC[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 3458344156815120948U;
            aOrbiterD = RotL64((aOrbiterD * 1668460113964608051U), 29U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 17069783053664877727U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 1260234710193913099U;
            aOrbiterC = RotL64((aOrbiterC * 4561226779897414381U), 41U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3825186451876061335U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 2905344294992827535U;
            aOrbiterK = RotL64((aOrbiterK * 2469896090698580795U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterA) + 18141402347899180617U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 8760129857609925066U;
            aOrbiterI = RotL64((aOrbiterI * 2507999156108123047U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 594052473780678210U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterI) ^ 13216719212966128379U) ^ aPhaseAOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 10691355329696722303U), 23U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 10029948739466316169U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 11912428807431992996U;
            aOrbiterE = RotL64((aOrbiterE * 85016510811938307U), 3U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 8735634019801417287U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 12785916159063273545U;
            aOrbiterB = RotL64((aOrbiterB * 1161917531260663357U), 47U);
            //
            aIngress = RotL64(aOrbiterG, 23U) ^ aOrbiterD;
            aIngress = aIngress + (RotL64(aOrbiterA, 54U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterK, 3U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterC, 51U) ^ aOrbiterI);
            aIngress = aIngress + RotL64(aOrbiterJ, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + (((RotL64(aScatter, 51U) + RotL64(aOrbiterA, 47U)) + aOrbiterK) + aPhaseAWandererUpdateSaltD[((aIndex + 11U)) & S_SALT1]);
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterE) + RotL64(aOrbiterK, 5U));
            aWandererH = aWandererH + ((RotL64(aCross, 34U) + RotL64(aOrbiterC, 57U)) + aOrbiterB);
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterB, 13U)) + aOrbiterD);
            aWandererD = aWandererD + ((((RotL64(aIngress, 57U) + RotL64(aOrbiterE, 24U)) + aOrbiterA) + RotL64(aCarry, 23U)) + aPhaseAWandererUpdateSaltB[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 43U) + aOrbiterD) + RotL64(aOrbiterJ, 53U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 5U) + RotL64(aOrbiterG, 29U)) + aOrbiterB);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 12U) + aOrbiterI) + RotL64(aOrbiterJ, 41U));
            aWandererI = aWandererI + (((RotL64(aScatter, 47U) + aOrbiterG) + RotL64(aOrbiterJ, 34U)) + RotL64(aCarry, 11U));
            //
            aCarry = aCarry + (RotL64(aWandererJ, 30U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererK, 47U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 13U));
            aCarry = aCarry + RotL64(aWandererD, 5U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aInvestLaneA[((aIndex + 9807U)) & S_BLOCK1], 11U) ^ RotL64(aKeyRowReadB[((aIndex + 9343U)) & W_KEY1], 60U));
            aIngress ^= (RotL64(mSource[((aIndex + 10621U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((aIndex + 9859U)) & S_BLOCK1], 51U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aKeyRowReadA[(((2047U - aIndex) + 9671U)) & W_KEY1], 29U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 10647U)) & S_BLOCK1], 50U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 23U) + RotL64(aIngress, 6U)) ^ (RotL64(aPrevious, 37U) ^ RotL64(aCross, 53U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererD + RotL64(aCross, 42U)) + RotL64(aCarry, 51U)) + 4739486756133131180U;
            aOrbiterE = ((aWandererK + RotL64(aScatter, 23U)) + RotL64(aCarry, 21U)) + 16089707555501328184U;
            aOrbiterH = (aWandererI + RotL64(aIngress, 3U)) + 15310047330238536453U;
            aOrbiterI = ((aWandererJ + RotL64(aPrevious, 47U)) + 7901411596386834955U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterD = ((aWandererC + RotL64(aScatter, 37U)) + 4357555491060982163U) + aPhaseBOrbiterAssignSaltF[((aIndex + 5U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aIngress, 28U)) + 15667085602825720102U;
            aOrbiterG = ((aWandererE + RotL64(aPrevious, 53U)) + RotL64(aCarry, 29U)) + 8520635334382269253U;
            aOrbiterJ = (aWandererB + RotL64(aCross, 57U)) + 1772509779231068315U;
            aOrbiterC = (aWandererG + RotL64(aPrevious, 13U)) + 15336170957886025677U;
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 8628770833489469980U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 15469234024247246228U;
            aOrbiterH = RotL64((aOrbiterH * 8905266995119987947U), 39U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 10796430900884288328U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 10660110397012853289U;
            aOrbiterB = RotL64((aOrbiterB * 9140007610912037461U), 27U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterB) + 11202284258711214794U) + aPhaseBOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterG) ^ 17509491802893182994U;
            aOrbiterA = RotL64((aOrbiterA * 9329107599972703671U), 57U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 16212572740740103554U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2190030203761579226U;
            aOrbiterD = RotL64((aOrbiterD * 3101886685668871045U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 12014337082293041909U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterC) ^ 3733531010807001506U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 5797362244066062299U), 5U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 7100994963061975529U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 17837541162838600258U;
            aOrbiterE = RotL64((aOrbiterE * 8745987361678166553U), 35U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3311518938023146951U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 7709505172646831553U;
            aOrbiterC = RotL64((aOrbiterC * 7121143171245765213U), 13U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 4979968094554018443U) + aPhaseBOrbiterUpdateSaltF[((aIndex + 20U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterH) ^ 16822214821463034107U;
            aOrbiterG = RotL64((aOrbiterG * 8618262120451291765U), 23U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterJ) + 8376124175020587079U) + aPhaseBOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 11084586282092424876U;
            aOrbiterI = RotL64((aOrbiterI * 5835632742522563537U), 47U);
            //
            aIngress = aOrbiterD ^ RotL64(aOrbiterE, 19U);
            aIngress = aIngress + (RotL64(aOrbiterJ, 44U) ^ aOrbiterB);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterG, 11U));
            aIngress = aIngress + RotL64(aOrbiterH, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK ^ ((RotL64(aCross, 42U) + RotL64(aOrbiterA, 39U)) + aOrbiterC);
            aWandererE = aWandererE + ((RotL64(aScatter, 3U) + aOrbiterJ) + RotL64(aOrbiterE, 12U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 51U) + RotL64(aOrbiterC, 27U)) + aOrbiterB);
            aWandererC = aWandererC + (((RotL64(aPrevious, 47U) + aOrbiterE) + RotL64(aOrbiterH, 5U)) + RotL64(aCarry, 53U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 34U) + aOrbiterD) + RotL64(aOrbiterI, 23U)) + aPhaseBWandererUpdateSaltC[((aIndex + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterI, 43U)) + aPhaseBWandererUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aCross, 21U) + RotL64(aOrbiterC, 47U)) + aOrbiterD);
            aWandererH = aWandererH + (((RotL64(aIngress, 11U) + aOrbiterD) + RotL64(aOrbiterG, 60U)) + RotL64(aCarry, 23U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 27U) + aOrbiterE) + RotL64(aOrbiterB, 35U));
            //
            aCarry = aCarry + (RotL64(aWandererB, 23U) ^ aWandererK);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererD, 27U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererC, 19U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererH, 42U));
            aCarry = aCarry + RotL64(aWandererJ, 13U);
            aCarry = aCarry + RotL64(aIngress, 47U);
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
            aIngress = (RotL64(aInvestLaneB[((aIndex + 11013U)) & S_BLOCK1], 18U) ^ RotL64(aKeyRowReadA[((aIndex + 11933U)) & W_KEY1], 29U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 13358U)) & W_KEY1], 51U) ^ RotL64(mSource[((aIndex + 13478U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13194U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 12885U)) & S_BLOCK1], 56U) ^ RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 12211U)) & S_BLOCK1], 37U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 18U) ^ RotL64(aCarry, 37U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = (aWandererB + RotL64(aIngress, 47U)) + 15383045568644941552U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 23U)) + 17452811657750910067U;
            aOrbiterF = (aWandererJ + RotL64(aCross, 27U)) + 15660117718455155603U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 18U)) + 10396441207743665753U;
            aOrbiterE = (((aWandererF + RotL64(aPrevious, 53U)) + RotL64(aCarry, 3U)) + 3708971058200841442U) + aPhaseBOrbiterAssignSaltF[((aIndex + 19U)) & S_SALT1];
            aOrbiterJ = ((aWandererA + RotL64(aCross, 35U)) + RotL64(aCarry, 35U)) + 7000673057768598750U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 5U)) + RotL64(aCarry, 19U)) + 9886354469011131596U;
            aOrbiterH = (aWandererE + RotL64(aScatter, 42U)) + 16018065329058043467U;
            aOrbiterI = ((aWandererI + RotL64(aPrevious, 13U)) + 5024756166109352320U) + aPhaseBOrbiterAssignSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 6587818720728886652U;
            aOrbiterF = (aOrbiterF ^ aOrbiterB) ^ 3652672354944162319U;
            aOrbiterF = RotL64((aOrbiterF * 10807121230791716109U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 6307315649915348048U) + aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterG) ^ 16405347331742979258U) ^ aPhaseBOrbiterUpdateSaltB[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 7183142442906743699U), 51U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterF) + 5427299664054601957U;
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 4983381733483185898U;
            aOrbiterH = RotL64((aOrbiterH * 14646556236306407673U), 19U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 10182995521328377487U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 8694282877540593550U;
            aOrbiterG = RotL64((aOrbiterG * 14614602561910403893U), 47U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 4085927978153269932U) + aPhaseBOrbiterUpdateSaltC[((aIndex + 4U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterJ) ^ 6176195962815240877U) ^ aPhaseBOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16792916528959579875U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 6966742100601433005U;
            aOrbiterB = (aOrbiterB ^ aOrbiterE) ^ 9920952446921247521U;
            aOrbiterB = RotL64((aOrbiterB * 1879821050131820933U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 11958734477518336014U;
            aOrbiterC = (aOrbiterC ^ aOrbiterH) ^ 2058335903640404380U;
            aOrbiterC = RotL64((aOrbiterC * 6986170159285417789U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 77366119537297816U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12072894199692855000U;
            aOrbiterI = RotL64((aOrbiterI * 9083781120514635987U), 57U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 11874297832446385377U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 13715562531763053196U;
            aOrbiterE = RotL64((aOrbiterE * 12822488258322963187U), 41U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterH, 6U);
            aIngress = aIngress + (RotL64(aOrbiterK, 35U) ^ aOrbiterC);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterJ, 3U));
            aIngress = aIngress + (RotL64(aOrbiterB, 13U) ^ aOrbiterF);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterE, 41U)) + aOrbiterH);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterC) + RotL64(aOrbiterK, 26U)) + RotL64(aCarry, 35U));
            aWandererD = aWandererD ^ ((RotL64(aIngress, 50U) + aOrbiterI) + RotL64(aOrbiterK, 57U));
            aWandererF = aWandererF + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterJ, 13U)) + RotL64(aCarry, 21U));
            aWandererG = aWandererG ^ ((RotL64(aScatter, 11U) + aOrbiterJ) + RotL64(aOrbiterB, 35U));
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + aOrbiterJ) + RotL64(aOrbiterG, 21U));
            aWandererB = aWandererB ^ (((RotL64(aPrevious, 46U) + aOrbiterE) + RotL64(aOrbiterC, 46U)) + aPhaseBWandererUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1]);
            aWandererC = aWandererC + ((RotL64(aIngress, 23U) + aOrbiterK) + RotL64(aOrbiterF, 53U));
            aWandererI = aWandererI ^ (((RotL64(aPrevious, 57U) + RotL64(aOrbiterG, 3U)) + aOrbiterC) + aPhaseBWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 38U));
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererE, 13U));
            aCarry = aCarry + (RotL64(aWandererB, 3U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererD, 23U) ^ aWandererJ);
            aCarry = aCarry + RotL64(aWandererG, 35U);
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
            aIngress = RotL64(aFireLaneA[((aIndex + 13951U)) & S_BLOCK1], 34U) ^ RotL64(aInvestLaneA[((aIndex + 14056U)) & S_BLOCK1], 51U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 14794U)) & W_KEY1], 13U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 16223U)) & W_KEY1], 29U));
            aCross ^= (RotL64(mSource[((S_BLOCK1 - aIndex + 15303U)) & S_BLOCK1], 37U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13944U)) & S_BLOCK1], 50U));
            aCross ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 14795U)) & S_BLOCK1], 21U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 41U) + RotL64(aCross, 4U)) + (RotL64(aCarry, 23U) ^ RotL64(aPrevious, 53U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterC = (aWandererI + RotL64(aPrevious, 6U)) + 3238389262925516513U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 19U)) + 12381787182611386995U) + aPhaseBOrbiterAssignSaltB[((aIndex + 10U)) & S_SALT1];
            aOrbiterG = ((aWandererG + RotL64(aCross, 35U)) + RotL64(aCarry, 3U)) + 7883885539305181549U;
            aOrbiterE = (aWandererD + RotL64(aIngress, 27U)) + 1185413044597727092U;
            aOrbiterA = (aWandererA + RotL64(aScatter, 46U)) + 15219353497204773135U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 57U)) + RotL64(aCarry, 37U)) + 7533774715626734082U;
            aOrbiterB = (((aWandererK + RotL64(aIngress, 39U)) + RotL64(aCarry, 23U)) + 2599930450937763464U) + aPhaseBOrbiterAssignSaltC[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = (aWandererH + RotL64(aCross, 23U)) + 16074720663961214284U;
            aOrbiterH = (aWandererE + RotL64(aIngress, 13U)) + 15483613196360051221U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterJ) + 9396557867081376268U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 9668459976852660245U;
            aOrbiterG = RotL64((aOrbiterG * 11748505665890567063U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 9037269914643207212U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16936742640861088240U;
            aOrbiterA = RotL64((aOrbiterA * 1040172193161012227U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 16481274825758546398U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterG) ^ 481851372837611166U) ^ aPhaseBOrbiterUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 2225030139210599207U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 13608921517203544108U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 16930740723286214636U;
            aOrbiterH = RotL64((aOrbiterH * 2605108503821980865U), 3U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 902242902582149908U) + aPhaseBOrbiterUpdateSaltB[((aIndex + 26U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 1510861213079342977U;
            aOrbiterJ = RotL64((aOrbiterJ * 3309753895727400707U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterE) + 7116243600304980310U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6631412278359709602U;
            aOrbiterF = RotL64((aOrbiterF * 11452627691392637463U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterH) + 9246698682265275165U) + aPhaseBOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 8594373032014031450U;
            aOrbiterK = RotL64((aOrbiterK * 2550138341089957033U), 27U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15912837963877821048U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 11404583513022627609U;
            aOrbiterC = RotL64((aOrbiterC * 17715204726760125357U), 23U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterC) + 17295214920690244319U) + aPhaseBOrbiterUpdateSaltA[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 18315664494984189344U;
            aOrbiterE = RotL64((aOrbiterE * 17398893532076312945U), 43U);
            //
            aIngress = RotL64(aOrbiterK, 5U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterH, 14U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterA, 47U));
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 21U));
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererD = aWandererD + (((RotL64(aScatter, 43U) + aOrbiterK) + RotL64(aOrbiterG, 48U)) + RotL64(aCarry, 57U));
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 27U) + aOrbiterF) + RotL64(aOrbiterB, 37U));
            aWandererA = aWandererA + ((RotL64(aCross, 54U) + aOrbiterC) + RotL64(aOrbiterE, 53U));
            aWandererH = aWandererH ^ ((RotL64(aIngress, 13U) + aOrbiterJ) + RotL64(aOrbiterA, 23U));
            aWandererK = aWandererK + (((RotL64(aCross, 47U) + RotL64(aOrbiterK, 27U)) + aOrbiterH) + aPhaseBWandererUpdateSaltD[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 23U) + aOrbiterE) + RotL64(aOrbiterF, 5U));
            aWandererI = aWandererI + ((RotL64(aPrevious, 38U) + RotL64(aOrbiterG, 43U)) + aOrbiterC);
            aWandererF = aWandererF ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 14U)) + aOrbiterJ) + aPhaseBWandererUpdateSaltB[((aIndex + 13U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 3U) + RotL64(aOrbiterH, 19U)) + aOrbiterC) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 18U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 23U) ^ aWandererD);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererB, 35U));
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererK, 39U));
            aCarry = aCarry + RotL64(aWandererH, 57U);
            aCarry = aCarry + RotL64(aIngress, 27U);
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
            aIngress = (RotL64(aFireLaneB[((aIndex + 17969U)) & S_BLOCK1], 39U) ^ RotL64(aKeyRowReadA[((aIndex + 16769U)) & W_KEY1], 47U));
            aIngress ^= (RotL64(mSource[((aIndex + 18259U)) & S_BLOCK1], 10U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 17951U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 17667U)) & W_KEY1], 50U) ^ RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 17006U)) & S_BLOCK1], 21U));
            aCross ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 18380U)) & S_BLOCK1], 13U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 12U) ^ RotL64(aCarry, 29U)) + (RotL64(aIngress, 57U) ^ RotL64(aCross, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aIngress, 29U)) + 5568146815535263910U;
            aOrbiterD = (aWandererF + RotL64(aPrevious, 46U)) + 7736084960873834666U;
            aOrbiterI = ((aWandererB + RotL64(aScatter, 3U)) + 1336413621817562093U) + aPhaseCOrbiterAssignSaltC[((aIndex + 11U)) & S_SALT1];
            aOrbiterH = ((aWandererA + RotL64(aCross, 13U)) + RotL64(aCarry, 43U)) + 5218462026934984692U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 41U)) + RotL64(aCarry, 21U)) + 7048890985969555935U;
            aOrbiterG = (((aWandererD + RotL64(aIngress, 19U)) + RotL64(aCarry, 3U)) + 13415955213864702118U) + aPhaseCOrbiterAssignSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterK = (aWandererC + RotL64(aCross, 35U)) + 5657023257021528548U;
            aOrbiterE = (aWandererE + RotL64(aScatter, 56U)) + 14338310943137497116U;
            aOrbiterB = (aWandererJ + RotL64(aCross, 51U)) + 12305161641833950473U;
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 14514226578370459131U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 12692904083266024340U;
            aOrbiterI = RotL64((aOrbiterI * 14800805065279908839U), 23U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11012959130001327964U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 7106471380403489078U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 515626559384817223U), 57U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterG) + 3718101961355280891U) + aPhaseCOrbiterUpdateSaltD[((aIndex + 16U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 13364192077222322664U;
            aOrbiterK = RotL64((aOrbiterK * 1411328915372590283U), 5U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 6720867800318913440U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 14497243926965866546U;
            aOrbiterD = RotL64((aOrbiterD * 13595058589060114653U), 41U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterB) + 5789056168233262435U) + aPhaseCOrbiterUpdateSaltC[((aIndex + 9U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 14438482587495779937U;
            aOrbiterH = RotL64((aOrbiterH * 10593535547917767263U), 13U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 313917798940179945U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 15241845511889502917U;
            aOrbiterB = RotL64((aOrbiterB * 16483477103771326107U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 3591957424821693032U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1559050939014453558U;
            aOrbiterE = RotL64((aOrbiterE * 17933346117866604725U), 51U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 15340590914441451383U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 5538037287390050110U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4082576643144951473U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 4151270491894969214U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 263593701314144898U;
            aOrbiterG = RotL64((aOrbiterG * 10372046955804512457U), 35U);
            //
            aIngress = RotL64(aOrbiterG, 19U) ^ aOrbiterB;
            aIngress = aIngress + (RotL64(aOrbiterD, 54U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterH, 5U) ^ aOrbiterC);
            aIngress = aIngress + (RotL64(aOrbiterE, 57U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterI, 51U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterI, 3U)) + aOrbiterB);
            aWandererB = aWandererB + (((RotL64(aScatter, 53U) + aOrbiterK) + RotL64(aOrbiterC, 60U)) + aPhaseCWandererUpdateSaltA[((aIndex + 25U)) & S_SALT1]);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 20U) + RotL64(aOrbiterE, 23U)) + aOrbiterF);
            aWandererC = aWandererC + (((RotL64(aPrevious, 57U) + aOrbiterB) + RotL64(aOrbiterF, 13U)) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 29U) + aOrbiterK) + RotL64(aOrbiterH, 51U));
            aWandererA = aWandererA + (((RotL64(aCross, 39U) + aOrbiterI) + RotL64(aOrbiterH, 35U)) + RotL64(aCarry, 13U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterD, 29U)) + aOrbiterE);
            aWandererD = aWandererD + ((RotL64(aScatter, 11U) + RotL64(aOrbiterF, 18U)) + aOrbiterI);
            aWandererJ = aWandererJ ^ (((RotL64(aIngress, 6U) + RotL64(aOrbiterF, 39U)) + aOrbiterG) + aPhaseCWandererUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererI, 60U));
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererK, 19U));
            aCarry = aCarry + (RotL64(aWandererB, 27U) ^ aWandererC);
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererE, 39U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aFireLaneC[((aIndex + 19226U)) & S_BLOCK1], 41U) ^ RotL64(mSource[((aIndex + 20999U)) & S_BLOCK1], 52U));
            aIngress ^= (RotL64(aFireLaneA[((aIndex + 20618U)) & S_BLOCK1], 27U) ^ RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 19821U)) & S_BLOCK1], 11U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 21403U)) & W_KEY1], 11U) ^ RotL64(aKeyRowReadB[(((2047U - aIndex) + 20626U)) & W_KEY1], 37U));
            aCross ^= (RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 21417U)) & S_BLOCK1], 54U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 21481U)) & S_BLOCK1], 27U));
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 39U) ^ RotL64(aPrevious, 51U)) + (RotL64(aIngress, 19U) + RotL64(aCross, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = ((aWandererI + RotL64(aCross, 39U)) + RotL64(aCarry, 21U)) + 1898718075389870739U;
            aOrbiterJ = (aWandererF + RotL64(aIngress, 58U)) + 5631794889237247403U;
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 23U)) + 18219714659484524607U) + aPhaseCOrbiterAssignSaltC[(((31U - aIndex) + 6U)) & S_SALT1];
            aOrbiterA = (aWandererD + RotL64(aScatter, 19U)) + 15419581386225732921U;
            aOrbiterE = (aWandererB + RotL64(aPrevious, 47U)) + 9125575431710198210U;
            aOrbiterI = (aWandererJ + RotL64(aCross, 27U)) + 12205871520544965505U;
            aOrbiterK = ((aWandererA + RotL64(aScatter, 35U)) + RotL64(aCarry, 53U)) + 7617534300497343422U;
            aOrbiterD = (((aWandererE + RotL64(aIngress, 5U)) + RotL64(aCarry, 37U)) + 18017579105368135814U) + aPhaseCOrbiterAssignSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = (aWandererH + RotL64(aCross, 10U)) + 10693882161946020042U;
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 11669615701700895306U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 11045110212889232165U) ^ aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 12U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5965171269273719849U), 51U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 18019107802806469913U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 12315940560472528716U;
            aOrbiterI = RotL64((aOrbiterI * 4505122470351404065U), 57U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 4899009736070044310U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 17412253404253730364U;
            aOrbiterK = RotL64((aOrbiterK * 10791901166391946485U), 23U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 4826286251927854181U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 4523455921321845084U) ^ aPhaseCOrbiterUpdateSaltF[((aIndex + 9U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 14534103906736598099U), 47U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 4132514462154182215U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterD) ^ 7164745605985109269U) ^ aPhaseCOrbiterUpdateSaltB[((aIndex + 14U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 14107325508977225261U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterH) + 6297434295807635654U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 8813887638672996646U;
            aOrbiterE = RotL64((aOrbiterE * 17495632530773158201U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 11086381278955626084U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 5660733992573928887U;
            aOrbiterJ = RotL64((aOrbiterJ * 11248164458720777889U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterD) + 14851044686208609882U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterI) ^ 12707776386060264479U) ^ aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 4470919091467313071U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 11508023384209716657U;
            aOrbiterA = (aOrbiterA ^ aOrbiterJ) ^ 11752973809740920034U;
            aOrbiterA = RotL64((aOrbiterA * 10212754472298834769U), 39U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterF, 41U);
            aIngress = aIngress + (RotL64(aOrbiterA, 24U) ^ aOrbiterK);
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterE, 29U));
            aIngress = aIngress + (RotL64(aOrbiterD, 57U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterC, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aCross, 11U) + aOrbiterD) + RotL64(aOrbiterF, 47U));
            aWandererD = aWandererD + ((RotL64(aIngress, 26U) + aOrbiterJ) + RotL64(aOrbiterC, 57U));
            aWandererE = aWandererE ^ ((RotL64(aScatter, 5U) + aOrbiterF) + RotL64(aOrbiterI, 28U));
            aWandererF = aWandererF + ((((RotL64(aPrevious, 19U) + aOrbiterE) + RotL64(aOrbiterD, 53U)) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltD[((aIndex + 26U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 35U) + RotL64(aOrbiterA, 11U)) + aOrbiterJ);
            aWandererB = aWandererB + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterJ, 35U)) + aPhaseCWandererUpdateSaltF[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 48U) + aOrbiterI) + RotL64(aOrbiterH, 43U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 57U) + RotL64(aOrbiterK, 39U)) + aOrbiterE) + RotL64(aCarry, 39U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterA) + RotL64(aOrbiterD, 22U));
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererI, 57U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererF, 18U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererJ, 13U));
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 51U);
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
            aIngress = (RotL64(aFireLaneD[((aIndex + 24501U)) & S_BLOCK1], 3U) ^ RotL64(aKeyRowReadA[((aIndex + 23066U)) & W_KEY1], 51U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 22687U)) & W_KEY1], 34U) ^ RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 23995U)) & S_BLOCK1], 21U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(mSource[((S_BLOCK1 - aIndex + 23064U)) & S_BLOCK1], 19U) ^ RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 24485U)) & S_BLOCK1], 5U));
            aCross ^= (RotL64(aInvestLaneA[((S_BLOCK1 - aIndex + 24376U)) & S_BLOCK1], 37U) ^ RotL64(aInvestLaneB[((aIndex + 22049U)) & S_BLOCK1], 56U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) + RotL64(aIngress, 22U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCross, 35U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterF = ((aWandererC + RotL64(aPrevious, 12U)) + RotL64(aCarry, 35U)) + 17912271996338180948U;
            aOrbiterB = ((aWandererB + RotL64(aCross, 47U)) + 13259276608841847058U) + aPhaseCOrbiterAssignSaltE[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aWandererF + RotL64(aIngress, 23U)) + 16225936008657276089U;
            aOrbiterJ = (aWandererE + RotL64(aScatter, 51U)) + 2243058962151834071U;
            aOrbiterK = (aWandererI + RotL64(aPrevious, 3U)) + 10637439274127347861U;
            aOrbiterC = (aWandererG + RotL64(aScatter, 19U)) + 15312219216405992627U;
            aOrbiterD = (aWandererD + RotL64(aIngress, 35U)) + 2393933972129878613U;
            aOrbiterG = ((aWandererH + RotL64(aCross, 41U)) + RotL64(aCarry, 53U)) + 4327069337247976513U;
            aOrbiterI = (((aWandererA + RotL64(aIngress, 58U)) + RotL64(aCarry, 43U)) + 8307656353434167837U) + aPhaseCOrbiterAssignSaltA[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterF = (aOrbiterF + aOrbiterB) + 17299145556933889336U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 14458100581172798164U;
            aOrbiterA = RotL64((aOrbiterA * 16543734663677070509U), 41U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterK) + 6410095654927998067U;
            aOrbiterC = (aOrbiterC ^ aOrbiterJ) ^ 6168964796264687686U;
            aOrbiterC = RotL64((aOrbiterC * 16218071040190475953U), 19U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterG) + 3667999465041020730U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 16021552859323602007U;
            aOrbiterF = RotL64((aOrbiterF * 6427266472526362663U), 11U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 12941668202330045095U) + aPhaseCOrbiterUpdateSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 4222032891850449934U;
            aOrbiterJ = RotL64((aOrbiterJ * 17292856787431308097U), 3U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterD) + 1346342592002730785U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 16860611785008118820U) ^ aPhaseCOrbiterUpdateSaltA[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 384963420804756607U), 37U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterJ) + 3193572711804730241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 5866881282680588589U;
            aOrbiterB = RotL64((aOrbiterB * 9226331800853634597U), 27U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterI) + 17180332731328479126U) + aPhaseCOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 10222097519535882241U;
            aOrbiterG = RotL64((aOrbiterG * 9422887302872778795U), 23U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 8863502179821584859U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 14872318155712512999U;
            aOrbiterD = RotL64((aOrbiterD * 11830641277356873233U), 53U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 16478790641892781150U) + aPhaseCOrbiterUpdateSaltD[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 8414944141232294781U;
            aOrbiterI = RotL64((aOrbiterI * 17443775794621154023U), 47U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterJ, 53U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterG, 6U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterA, 19U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterB, 57U));
            aIngress = aIngress + RotL64(aOrbiterI, 29U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererI = aWandererI ^ ((RotL64(aIngress, 3U) + aOrbiterK) + RotL64(aOrbiterF, 35U));
            aWandererB = aWandererB + (((RotL64(aCross, 57U) + RotL64(aOrbiterD, 11U)) + aOrbiterG) + RotL64(aCarry, 57U));
            aWandererH = aWandererH ^ (((RotL64(aPrevious, 23U) + RotL64(aOrbiterD, 39U)) + aOrbiterF) + aPhaseCWandererUpdateSaltA[((aIndex + 14U)) & S_SALT1]);
            aWandererG = aWandererG + ((((RotL64(aScatter, 44U) + RotL64(aOrbiterI, 22U)) + aOrbiterJ) + RotL64(aCarry, 5U)) + aPhaseCWandererUpdateSaltC[((aIndex + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 35U) + RotL64(aOrbiterB, 43U)) + aOrbiterC);
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + RotL64(aOrbiterA, 27U)) + aOrbiterF);
            aWandererE = aWandererE ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterJ, 53U)) + aOrbiterC);
            aWandererA = aWandererA + ((RotL64(aCross, 19U) + RotL64(aOrbiterB, 5U)) + aOrbiterF);
            aWandererC = aWandererC ^ ((RotL64(aScatter, 28U) + aOrbiterJ) + RotL64(aOrbiterA, 48U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererC);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererD, 50U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 43U));
            aCarry = aCarry + (RotL64(aWandererA, 53U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererB, 39U);
            aCarry = aCarry + RotL64(aIngress, 30U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 26976U)) & S_BLOCK1], 37U) ^ RotL64(aKeyRowReadA[((aIndex + 26740U)) & W_KEY1], 14U));
            aIngress ^= (RotL64(aFireLaneD[((aIndex + 24668U)) & S_BLOCK1], 51U) ^ RotL64(aFireLaneB[((S_BLOCK1 - aIndex + 26687U)) & S_BLOCK1], 29U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadB[(((2047U - aIndex) + 26806U)) & W_KEY1], 26U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 24915U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aFireLaneC[((S_BLOCK1 - aIndex + 26062U)) & S_BLOCK1], 47U) ^ RotL64(aInvestLaneB[((aIndex + 25506U)) & S_BLOCK1], 35U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 36U) ^ RotL64(aCarry, 51U)) + (RotL64(aCross, 23U) + RotL64(aPrevious, 11U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterK = ((aWandererG + RotL64(aIngress, 28U)) + RotL64(aCarry, 13U)) + 13854738573712660276U;
            aOrbiterH = (((aWandererB + RotL64(aScatter, 39U)) + RotL64(aCarry, 5U)) + 16835460633412286294U) + aPhaseDOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterE = (aWandererH + RotL64(aCross, 35U)) + 6785859293758091931U;
            aOrbiterC = ((aWandererC + RotL64(aPrevious, 11U)) + 126317283127992659U) + aPhaseDOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterJ = (aWandererK + RotL64(aIngress, 50U)) + 7568963536291415413U;
            aOrbiterD = (aWandererI + RotL64(aCross, 43U)) + 12294016745653004819U;
            aOrbiterB = ((aWandererE + RotL64(aPrevious, 57U)) + RotL64(aCarry, 41U)) + 18269588932920281147U;
            aOrbiterA = (aWandererJ + RotL64(aScatter, 19U)) + 5872406424994751026U;
            aOrbiterF = (aWandererA + RotL64(aCross, 23U)) + 7764434758831474129U;
            //
            aOrbiterK = ((aOrbiterK + aOrbiterH) + 4804168969415573371U) + aPhaseDOrbiterUpdateSaltD[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterK) ^ 959601763507651280U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 21U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4647396592804833217U), 41U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterC) + 9257644462479293048U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterE) ^ 14332699366894494579U;
            aOrbiterJ = RotL64((aOrbiterJ * 8829304078930625541U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 10487012596470786004U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 612729229562321440U;
            aOrbiterB = RotL64((aOrbiterB * 11380387280507726003U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterJ) + 7845523921295625315U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 12742115479740024747U;
            aOrbiterA = RotL64((aOrbiterA * 15578543510683986421U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 10294667720904610944U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 14369711143154904567U;
            aOrbiterH = RotL64((aOrbiterH * 13753005602288309379U), 23U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 10918344717497681894U;
            aOrbiterK = (aOrbiterK ^ aOrbiterJ) ^ 18136794828308636957U;
            aOrbiterK = RotL64((aOrbiterK * 17899418637978002409U), 19U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterK) + 14378638206724886404U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterA) ^ 7077588188450008059U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 485375960462924335U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 8941870012851971932U;
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 15242087859620352399U;
            aOrbiterF = RotL64((aOrbiterF * 4963002810455992839U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 10395280254030875387U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterH) ^ 6826595516076975980U) ^ aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 6198886240333178001U), 57U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterJ, 35U);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterC, 53U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterD, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterH);
            aIngress = aIngress + RotL64(aOrbiterK, 14U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((RotL64(aCross, 30U) + aOrbiterA) + RotL64(aOrbiterJ, 39U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 23U) + RotL64(aOrbiterD, 3U)) + aOrbiterE);
            aWandererB = aWandererB + (((RotL64(aIngress, 11U) + aOrbiterJ) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 21U));
            aWandererK = aWandererK ^ (((RotL64(aPrevious, 19U) + aOrbiterD) + RotL64(aOrbiterK, 20U)) + aPhaseDWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aCross, 57U) + RotL64(aOrbiterA, 13U)) + aOrbiterH) + RotL64(aCarry, 37U));
            aWandererA = aWandererA ^ ((RotL64(aScatter, 41U) + RotL64(aOrbiterD, 51U)) + aOrbiterH);
            aWandererG = aWandererG + ((RotL64(aIngress, 53U) + aOrbiterB) + RotL64(aOrbiterC, 35U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterF, 29U)) + aOrbiterB);
            aWandererH = aWandererH + (((RotL64(aIngress, 34U) + RotL64(aOrbiterH, 46U)) + aOrbiterF) + aPhaseDWandererUpdateSaltD[(((31U - aIndex) + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererA, 51U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererB, 3U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererC, 38U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererI, 23U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 28223U)) & S_BLOCK1], 5U) ^ RotL64(aFireLaneD[((aIndex + 29553U)) & S_BLOCK1], 47U));
            aIngress ^= (RotL64(aKeyRowReadB[((aIndex + 29290U)) & W_KEY1], 39U) ^ RotL64(aFireLaneC[((aIndex + 29552U)) & S_BLOCK1], 20U));
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aKeyRowReadA[(((2047U - aIndex) + 28688U)) & W_KEY1], 21U) ^ RotL64(mSource[((S_BLOCK1 - aIndex + 28223U)) & S_BLOCK1], 13U));
            aCross ^= (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 28268U)) & S_BLOCK1], 29U) ^ RotL64(aFireLaneB[((aIndex + 28724U)) & S_BLOCK1], 60U));
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 54U) + RotL64(aPrevious, 3U)) ^ (RotL64(aCross, 41U) ^ RotL64(aIngress, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterH = (((aWandererF + RotL64(aPrevious, 57U)) + RotL64(aCarry, 21U)) + 15920462086654025436U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = ((aWandererE + RotL64(aIngress, 21U)) + 487844076858004017U) + aPhaseDOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = ((aWandererI + RotL64(aScatter, 53U)) + RotL64(aCarry, 57U)) + 14502883786442630566U;
            aOrbiterI = (aWandererG + RotL64(aCross, 10U)) + 3787107318658233674U;
            aOrbiterE = ((aWandererH + RotL64(aIngress, 3U)) + RotL64(aCarry, 43U)) + 12548777544693755491U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 35U)) + 4907309444075181683U;
            aOrbiterK = (aWandererK + RotL64(aPrevious, 47U)) + 18342396700266492072U;
            aOrbiterC = (aWandererC + RotL64(aCross, 41U)) + 13503051997624242670U;
            aOrbiterB = (aWandererA + RotL64(aIngress, 26U)) + 17845742460521374571U;
            //
            aOrbiterH = ((aOrbiterH + aOrbiterJ) + 8640887211877858169U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterH) ^ 5273913123709097537U;
            aOrbiterF = RotL64((aOrbiterF * 1661149444148461791U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterH) + 17756844173695563883U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 6713055830729302951U;
            aOrbiterE = RotL64((aOrbiterE * 2832836748513174311U), 39U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5106468334224035972U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 10228769728713526172U;
            aOrbiterJ = RotL64((aOrbiterJ * 9760310686414358435U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 7687649520668883142U;
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 7757480627354711605U;
            aOrbiterD = RotL64((aOrbiterD * 7222553727737349209U), 19U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterE) + 10876291698508634557U;
            aOrbiterB = (aOrbiterB ^ aOrbiterC) ^ 8149278085586014186U;
            aOrbiterB = RotL64((aOrbiterB * 8577133863470695381U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 15592893988925610485U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterF) ^ 8639028256640537165U) ^ aPhaseDOrbiterUpdateSaltA[((aIndex + 24U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 1880655276432963955U), 35U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterI) + 475660347892196219U) + aPhaseDOrbiterUpdateSaltC[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterJ) ^ 1903736092401853832U) ^ aPhaseDOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 8486318978769094799U), 43U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 12463250192809450953U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 7253918448601703982U;
            aOrbiterH = RotL64((aOrbiterH * 3821034106528009129U), 47U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterB) + 5171661020093804486U;
            aOrbiterI = (aOrbiterI ^ aOrbiterK) ^ 11627344933828324146U;
            aOrbiterI = RotL64((aOrbiterI * 5388047063152043277U), 57U);
            //
            aIngress = RotL64(aOrbiterI, 39U) ^ aOrbiterK;
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 5U));
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterF, 23U));
            aIngress = aIngress + (RotL64(aOrbiterD, 47U) ^ aOrbiterJ);
            aIngress = aIngress + RotL64(aOrbiterH, 36U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererE = aWandererE + (((RotL64(aCross, 43U) + aOrbiterK) + RotL64(aOrbiterH, 41U)) + aPhaseDWandererUpdateSaltC[((aIndex + 22U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aIngress, 47U) + aOrbiterC) + RotL64(aOrbiterH, 3U));
            aWandererF = aWandererF + (((RotL64(aScatter, 28U) + aOrbiterE) + RotL64(aOrbiterD, 27U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 57U) + RotL64(aOrbiterC, 19U)) + aOrbiterF);
            aWandererJ = aWandererJ + (((RotL64(aIngress, 21U) + aOrbiterB) + RotL64(aOrbiterH, 12U)) + RotL64(aCarry, 29U));
            aWandererC = aWandererC ^ (((RotL64(aPrevious, 35U) + aOrbiterH) + RotL64(aOrbiterI, 51U)) + aPhaseDWandererUpdateSaltE[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererA = aWandererA + ((RotL64(aScatter, 13U) + RotL64(aOrbiterC, 47U)) + aOrbiterE);
            aWandererH = aWandererH ^ ((RotL64(aCross, 51U) + aOrbiterB) + RotL64(aOrbiterJ, 23U));
            aWandererI = aWandererI + ((RotL64(aIngress, 4U) + aOrbiterD) + RotL64(aOrbiterI, 60U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 50U));
            aCarry = aCarry + (RotL64(aWandererA, 35U) ^ aWandererE);
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererI, 57U));
            aCarry = aCarry + (RotL64(aWandererH, 23U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererC, 47U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseC(aCarry);
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
            aIngress = RotL64(aExpandLaneC[((aIndex + 30620U)) & S_BLOCK1], 43U) ^ RotL64(aKeyRowReadA[(((2047U - aIndex) + 32477U)) & W_KEY1], 30U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 32459U)) & S_BLOCK1], 13U) ^ RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 32064U)) & S_BLOCK1], 57U));
            aCross ^= (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 30348U)) & S_BLOCK1], 4U) ^ RotL64(aKeyRowReadB[((aIndex + 32696U)) & W_KEY1], 29U));
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 58U) + RotL64(aPrevious, 29U)) + (RotL64(aIngress, 41U) ^ RotL64(aCarry, 13U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterB = ((aWandererF + RotL64(aIngress, 3U)) + RotL64(aCarry, 53U)) + 2974056819475622600U;
            aOrbiterF = ((aWandererH + RotL64(aCross, 57U)) + RotL64(aCarry, 23U)) + 7345051759236356098U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 48U)) + 12738468816846628882U;
            aOrbiterC = ((aWandererG + RotL64(aScatter, 43U)) + 7694520596043297922U) + aPhaseDOrbiterAssignSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterE = (aWandererA + RotL64(aCross, 21U)) + 5530753590015084774U;
            aOrbiterG = (aWandererD + RotL64(aScatter, 35U)) + 3776309161718383105U;
            aOrbiterD = ((aWandererB + RotL64(aPrevious, 53U)) + RotL64(aCarry, 5U)) + 784780304358106404U;
            aOrbiterH = ((aWandererK + RotL64(aIngress, 10U)) + 8999942326995036509U) + aPhaseDOrbiterAssignSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterK = (aWandererI + RotL64(aScatter, 27U)) + 5194986506064092779U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 7920040007459652762U;
            aOrbiterA = (aOrbiterA ^ aOrbiterB) ^ 11311997270710107937U;
            aOrbiterA = RotL64((aOrbiterA * 6227571709361790209U), 53U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 5365231114813547251U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 8630110234623825263U;
            aOrbiterE = RotL64((aOrbiterE * 2735881715888325759U), 47U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterG) + 2358235238039571072U) + aPhaseDOrbiterUpdateSaltC[((aIndex + 7U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterE) ^ 18059414891616491807U;
            aOrbiterD = RotL64((aOrbiterD * 17150786106857185467U), 39U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterB) + 14526050556461782864U) + aPhaseDOrbiterUpdateSaltE[(((31U - aIndex) + 16U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6937282036603272474U;
            aOrbiterG = RotL64((aOrbiterG * 14954512365270028029U), 27U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterH) + 10105832250694931310U;
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 3884223553012098137U;
            aOrbiterC = RotL64((aOrbiterC * 16340956813003906195U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 10385284339549648087U;
            aOrbiterH = ((aOrbiterH ^ aOrbiterG) ^ 1257633893341505930U) ^ aPhaseDOrbiterUpdateSaltB[((aIndex + 6U)) & S_SALT1];
            aOrbiterH = RotL64((aOrbiterH * 2669950791270500977U), 35U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 5528890519572824318U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 15664241747527713256U) ^ aPhaseDOrbiterUpdateSaltA[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 16670884497088220497U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterK) + 14264122979415331887U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 17985061405540198036U;
            aOrbiterB = RotL64((aOrbiterB * 2729487440173395133U), 5U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterD) + 1663986734997903415U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 3706166884286400587U;
            aOrbiterF = RotL64((aOrbiterF * 10549736618301955745U), 21U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterH, 53U);
            aIngress = aIngress + (RotL64(aOrbiterD, 35U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterA, 27U) ^ aOrbiterE);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterC, 40U));
            aIngress = aIngress + RotL64(aOrbiterK, 43U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG ^ (((RotL64(aScatter, 11U) + aOrbiterG) + RotL64(aOrbiterH, 30U)) + aPhaseDWandererUpdateSaltC[(((31U - aIndex) + 17U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 23U) + aOrbiterK) + RotL64(aOrbiterA, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 37U) + RotL64(aOrbiterB, 23U)) + aOrbiterF);
            aWandererD = aWandererD + ((((RotL64(aCross, 28U) + aOrbiterH) + RotL64(aOrbiterB, 13U)) + RotL64(aCarry, 53U)) + aPhaseDWandererUpdateSaltB[((aIndex + 5U)) & S_SALT1]);
            aWandererA = aWandererA ^ ((RotL64(aScatter, 53U) + aOrbiterE) + RotL64(aOrbiterK, 35U));
            aWandererB = aWandererB + ((RotL64(aPrevious, 57U) + aOrbiterA) + RotL64(aOrbiterF, 53U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 47U) + aOrbiterC) + RotL64(aOrbiterF, 48U));
            aWandererH = aWandererH + (((RotL64(aIngress, 43U) + RotL64(aOrbiterD, 39U)) + aOrbiterH) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 4U) + RotL64(aOrbiterK, 19U)) + aOrbiterH);
            //
            aCarry = aCarry + (RotL64(aWandererF, 43U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererK, 47U) ^ aWandererC);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererD, 35U));
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererB, 57U));
            aCarry = aCarry + RotL64(aWandererI, 18U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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

void TwistExpander_Lacrosse_Arx::Twist_B(TwistWorkSpace *pWorkSpace,
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
        // read from: aExpandLaneA, aExpandLaneB, aFireLaneB, aExpandLaneC, aExpandLaneD, aInvestLaneC, aFireLaneC, aInvestLaneD, aFireLaneD, aOperationLaneA, aFireLaneA, aOperationLaneB, aOperationLaneC
        // write to: aInvestLaneC, aInvestLaneD, aOperationLaneA, aOperationLaneB, aOperationLaneC, aOperationLaneD
    
        // twist_loop_b loop 1
        // ingress from: aExpandLaneA, aExpandLaneB, aFireLaneB
        // ingress directions: aExpandLaneA forward forced, aExpandLaneB forward forced, aFireLaneB forward/backward random
        // cross from: aExpandLaneC, aExpandLaneD
        // cross directions: aExpandLaneC backward forced, aExpandLaneD backward/forward random
        // write to: aInvestLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aExpandLaneA[((aIndex + 3980U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((aIndex + 4262U)) & S_BLOCK1], 46U));
            aIngress ^= RotL64(aFireLaneB[((aIndex + 2299U)) & S_BLOCK1], 19U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 4970U)) & S_BLOCK1], 38U) ^ RotL64(aExpandLaneD[((aIndex + 3100U)) & S_BLOCK1], 57U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 48U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 23U) + RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (((aWandererF + RotL64(aIngress, 36U)) + RotL64(aCarry, 29U)) + 7896237440058555694U) + aPhaseEOrbiterAssignSaltB[((aIndex + 29U)) & S_SALT1];
            aOrbiterI = ((aWandererD + RotL64(aScatter, 19U)) + RotL64(aCarry, 11U)) + 11870529476037558635U;
            aOrbiterG = (aWandererE + RotL64(aPrevious, 11U)) + 9158983227801569448U;
            aOrbiterJ = (((aWandererA + RotL64(aCross, 47U)) + RotL64(aCarry, 57U)) + 4710172270996950329U) + aPhaseEOrbiterAssignSaltE[((aIndex + 5U)) & S_SALT1];
            aOrbiterF = (aWandererJ + RotL64(aIngress, 3U)) + 14634482800356647630U;
            aOrbiterA = (aWandererC + RotL64(aPrevious, 29U)) + 8822207952170610891U;
            aOrbiterB = (aWandererB + RotL64(aScatter, 57U)) + 13755891414028982553U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 4555293067488040719U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterD) ^ 2816805148093762081U) ^ aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 16838149138341713943U), 37U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterF) + 2122631477965135190U;
            aOrbiterI = (aOrbiterI ^ aOrbiterJ) ^ 4592922416380416071U;
            aOrbiterI = RotL64((aOrbiterI * 11644507904538573165U), 27U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 7102471666524164715U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterG) ^ 17274623547879474204U;
            aOrbiterJ = RotL64((aOrbiterJ * 5443572270546181789U), 19U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterB) + 938587316977094680U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 18258015823797023523U;
            aOrbiterA = RotL64((aOrbiterA * 6068819567674605919U), 47U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5809987756043471595U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5083075160112581620U;
            aOrbiterD = RotL64((aOrbiterD * 3313957222154937503U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterD) + 5960021727750946496U) + aPhaseEOrbiterUpdateSaltC[((aIndex + 19U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 5967477320950630150U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 21U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 330964768256424655U), 5U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterG) + 6578428711689296132U;
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 5601728218197771276U;
            aOrbiterB = RotL64((aOrbiterB * 9552559022315971847U), 57U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterG, 56U);
            aIngress = aIngress + (RotL64(aOrbiterF, 19U) ^ aOrbiterJ);
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 57U) + RotL64(aOrbiterD, 43U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterB, 57U)) + RotL64(aCarry, 47U)) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aPrevious, 43U) + aOrbiterD) + RotL64(aOrbiterA, 34U));
            aWandererA = aWandererA + (((RotL64(aScatter, 19U) + RotL64(aOrbiterD, 51U)) + aOrbiterB) + RotL64(aCarry, 29U));
            aWandererD = aWandererD ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + aPhaseEWandererUpdateSaltB[((aIndex + 20U)) & S_SALT1]);
            aWandererE = aWandererE + ((RotL64(aPrevious, 51U) + RotL64(aOrbiterG, 5U)) + aOrbiterJ);
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 34U) + RotL64(aOrbiterI, 13U)) + aOrbiterA);
            //
            aCarry = aCarry + (RotL64(aWandererJ, 14U) ^ aWandererE);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererF, 5U));
            aCarry = aCarry + (RotL64(aWandererB, 51U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 41U);
            aCarry = TwistMix64::DiffuseA(aCarry);
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
            aIngress = (RotL64(aInvestLaneC[((aIndex + 8123U)) & S_BLOCK1], 19U) ^ RotL64(aExpandLaneC[((aIndex + 5639U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aFireLaneC[((aIndex + 6110U)) & S_BLOCK1], 58U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 5704U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneD[((aIndex + 6081U)) & S_BLOCK1], 48U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 23U) ^ RotL64(aCarry, 40U)) + (RotL64(aCross, 53U) ^ RotL64(aIngress, 3U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aScatter, 3U)) + RotL64(aCarry, 35U)) + 3448371607470865612U;
            aOrbiterA = ((aWandererG + RotL64(aIngress, 35U)) + RotL64(aCarry, 11U)) + 3743742913651580573U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 47U)) + 13069491287948807280U;
            aOrbiterH = (aWandererB + RotL64(aCross, 41U)) + 16872779275586545632U;
            aOrbiterJ = ((aWandererA + RotL64(aPrevious, 21U)) + 17945792656755062795U) + aPhaseEOrbiterAssignSaltF[((aIndex + 7U)) & S_SALT1];
            aOrbiterK = ((aWandererK + RotL64(aIngress, 57U)) + 18199747196793731853U) + aPhaseEOrbiterAssignSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterI = ((aWandererH + RotL64(aCross, 10U)) + RotL64(aCarry, 47U)) + 15953311878379809513U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterA) + 941268763494588338U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 10090221530365796809U;
            aOrbiterB = RotL64((aOrbiterB * 14035236086292997613U), 11U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 8335698093307607001U) + aPhaseEOrbiterUpdateSaltB[((aIndex + 15U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterA) ^ 6147498804734306100U;
            aOrbiterJ = RotL64((aOrbiterJ * 6904444049941211327U), 41U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterJ) + 5980246079567570090U) + aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterB) ^ 4152167624425912978U) ^ aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 10019421651535123573U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterI) + 14990418790239735916U;
            aOrbiterG = (aOrbiterG ^ aOrbiterJ) ^ 3418668387496597219U;
            aOrbiterG = RotL64((aOrbiterG * 12814077238529863119U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterB) + 4206650904177199425U;
            aOrbiterI = (aOrbiterI ^ aOrbiterH) ^ 3905470780938996069U;
            aOrbiterI = RotL64((aOrbiterI * 16030122739273137005U), 51U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 9968672788233080924U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 602258075661864866U;
            aOrbiterA = RotL64((aOrbiterA * 2615726693066300065U), 57U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterG) + 17751667243048041383U) + aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterH = (aOrbiterH ^ aOrbiterK) ^ 2414054413585296027U;
            aOrbiterH = RotL64((aOrbiterH * 1049512574773201893U), 27U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterK, 13U);
            aIngress = aIngress + (RotL64(aOrbiterA, 5U) ^ aOrbiterI);
            aIngress = aIngress + (RotL64(aOrbiterG, 56U) ^ aOrbiterB);
            aIngress = aIngress + RotL64(aOrbiterJ, 29U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererB = aWandererB ^ (((RotL64(aScatter, 41U) + aOrbiterJ) + RotL64(aOrbiterG, 11U)) + aPhaseEWandererUpdateSaltC[((aIndex + 17U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 23U) + RotL64(aOrbiterI, 41U)) + aOrbiterK) + RotL64(aCarry, 29U));
            aWandererK = aWandererK ^ ((RotL64(aPrevious, 14U) + RotL64(aOrbiterK, 5U)) + aOrbiterH);
            aWandererG = aWandererG + (((RotL64(aIngress, 53U) + RotL64(aOrbiterJ, 35U)) + aOrbiterI) + RotL64(aCarry, 43U));
            aWandererA = aWandererA ^ ((RotL64(aCross, 35U) + aOrbiterI) + RotL64(aOrbiterA, 53U));
            aWandererI = aWandererI + (((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterA, 18U)) + aPhaseEWandererUpdateSaltD[((aIndex + 5U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 3U) + RotL64(aOrbiterJ, 47U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 40U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 47U) ^ aWandererI);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererK, 57U));
            aCarry = aCarry + RotL64(aWandererD, 51U);
            aCarry = aCarry + RotL64(aIngress, 30U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aInvestLaneD[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_b loop 3
        // ingress from: aInvestLaneD, aExpandLaneD, aFireLaneD
        // ingress directions: aInvestLaneD forward forced, aExpandLaneD forward forced, aFireLaneD forward/backward random
        // cross from: aInvestLaneC, aExpandLaneB, aExpandLaneA
        // cross directions: aInvestLaneC backward forced, aExpandLaneB backward forced, aExpandLaneA backward/forward random
        // write to: aOperationLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aInvestLaneD[((aIndex + 16038U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneD[((aIndex + 13948U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aFireLaneD[((S_BLOCK1 - aIndex + 12146U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 13216U)) & S_BLOCK1], 43U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 14950U)) & S_BLOCK1], 28U));
            aCross ^= RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 12364U)) & S_BLOCK1], 53U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aIngress, 41U) + RotL64(aCross, 29U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = (aWandererG + RotL64(aScatter, 29U)) + 1142447269198373880U;
            aOrbiterE = ((aWandererB + RotL64(aCross, 48U)) + RotL64(aCarry, 29U)) + 10581460640040336191U;
            aOrbiterB = (aWandererF + RotL64(aIngress, 11U)) + 14703062773878202900U;
            aOrbiterH = (((aWandererA + RotL64(aPrevious, 57U)) + RotL64(aCarry, 57U)) + 15737525756286914746U) + aPhaseEOrbiterAssignSaltD[((aIndex + 4U)) & S_SALT1];
            aOrbiterF = (((aWandererJ + RotL64(aScatter, 21U)) + RotL64(aCarry, 13U)) + 16178774478273186999U) + aPhaseEOrbiterAssignSaltC[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = (aWandererE + RotL64(aPrevious, 41U)) + 2514897053906809160U;
            aOrbiterA = (aWandererI + RotL64(aIngress, 3U)) + 13702496607592508464U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterE) + 18030885275418337965U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 5241783876161655984U;
            aOrbiterB = RotL64((aOrbiterB * 10970981186787227937U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 2807052676283587925U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 8022804576763271327U;
            aOrbiterH = RotL64((aOrbiterH * 11727096043219370577U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterD) + 15597099852232205860U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterF) ^ 1538435607932096400U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 7900752511710516981U), 57U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 11147868774413615365U;
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 9325213746830411568U;
            aOrbiterA = RotL64((aOrbiterA * 561819005818948769U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterF) + 13792300423550555634U;
            aOrbiterD = (aOrbiterD ^ aOrbiterA) ^ 3134856508983945719U;
            aOrbiterD = RotL64((aOrbiterD * 4271845067763664863U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 8654966018053784882U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterC) ^ 8937113935476779267U) ^ aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 7386875687217705855U), 3U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterH) + 4135676350355234788U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterB) ^ 11407912615743682678U) ^ aPhaseEOrbiterUpdateSaltD[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 2773506587480714695U), 21U);
            //
            aIngress = aOrbiterE ^ RotL64(aOrbiterC, 35U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterD, 57U));
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterF, 29U));
            aIngress = aIngress + RotL64(aOrbiterA, 43U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 13U) + RotL64(aOrbiterB, 19U)) + aOrbiterD);
            aWandererJ = aWandererJ + ((((RotL64(aScatter, 19U) + RotL64(aOrbiterH, 3U)) + aOrbiterA) + RotL64(aCarry, 39U)) + aPhaseEWandererUpdateSaltA[((aIndex + 11U)) & S_SALT1]);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterD, 57U)) + aOrbiterE) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererB = aWandererB + (((RotL64(aCross, 41U) + aOrbiterD) + RotL64(aOrbiterF, 29U)) + RotL64(aCarry, 19U));
            aWandererE = aWandererE ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterF, 11U)) + aOrbiterA);
            aWandererI = aWandererI + ((RotL64(aScatter, 29U) + aOrbiterB) + RotL64(aOrbiterC, 42U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 47U) + RotL64(aOrbiterE, 51U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererA, 3U) ^ aWandererJ);
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererG, 13U));
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 56U));
            aCarry = aCarry + RotL64(aWandererE, 35U);
            aCarry = aCarry + RotL64(aIngress, 47U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aOperationLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_b loop 4
        // ingress from: aOperationLaneA, aInvestLaneC, aFireLaneA
        // ingress directions: aOperationLaneA forward forced, aInvestLaneC forward forced, aFireLaneA forward/backward random
        // cross from: aInvestLaneD, aExpandLaneD, aExpandLaneC
        // cross directions: aInvestLaneD backward forced, aExpandLaneD backward forced, aExpandLaneC backward/forward random
        // write to: aOperationLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 16620U)) & S_BLOCK1], 35U) ^ RotL64(aInvestLaneC[((aIndex + 20004U)) & S_BLOCK1], 5U));
            aIngress ^= RotL64(aFireLaneA[((S_BLOCK1 - aIndex + 19780U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 17061U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 16853U)) & S_BLOCK1], 39U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 17646U)) & S_BLOCK1], 54U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 5U) ^ RotL64(aPrevious, 41U)) ^ (RotL64(aIngress, 22U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererH + RotL64(aScatter, 41U)) + 4751694786009671052U;
            aOrbiterI = ((aWandererC + RotL64(aPrevious, 29U)) + RotL64(aCarry, 35U)) + 16362725160370844224U;
            aOrbiterF = (aWandererK + RotL64(aCross, 57U)) + 6360885380915941057U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 11U)) + 5154536007972297036U) + aPhaseEOrbiterAssignSaltB[((aIndex + 5U)) & S_SALT1];
            aOrbiterA = (aWandererJ + RotL64(aCross, 35U)) + 9362540581874808253U;
            aOrbiterC = ((aWandererA + RotL64(aScatter, 18U)) + RotL64(aCarry, 5U)) + 13902493871525612934U;
            aOrbiterE = (((aWandererF + RotL64(aIngress, 51U)) + RotL64(aCarry, 53U)) + 10208452885367546542U) + aPhaseEOrbiterAssignSaltE[((aIndex + 7U)) & S_SALT1];
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 3117030377279160998U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 17286247690414027870U;
            aOrbiterF = RotL64((aOrbiterF * 4896931759653832095U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 3930314320040949141U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 7289525252391668404U;
            aOrbiterA = RotL64((aOrbiterA * 15452162299105112187U), 35U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 3434167955466809185U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 17852573095128575663U;
            aOrbiterI = RotL64((aOrbiterI * 1485660158767033425U), 19U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterA) + 6137259687928853253U;
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 13992510605237574698U;
            aOrbiterE = RotL64((aOrbiterE * 15346263295995333395U), 3U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterF) + 6470556523400123474U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterI) ^ 4333255670390099293U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 14U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 11089933812030082647U), 57U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 7700424876430257995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16920736951239453071U;
            aOrbiterC = RotL64((aOrbiterC * 8920407493132380497U), 27U);
            //
            aOrbiterE = ((aOrbiterE + aOrbiterC) + 1635071690430295730U) + aPhaseEOrbiterUpdateSaltE[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterD = ((aOrbiterD ^ aOrbiterE) ^ 9966700845966398620U) ^ aPhaseEOrbiterUpdateSaltC[((aIndex + 23U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17210048121896546867U), 13U);
            //
            aIngress = RotL64(aOrbiterK, 21U) ^ aOrbiterA;
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterC, 57U));
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterI, 50U));
            aIngress = aIngress + RotL64(aOrbiterE, 11U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aCross, 35U) + RotL64(aOrbiterA, 39U)) + aOrbiterE);
            aWandererA = aWandererA + (((RotL64(aIngress, 13U) + aOrbiterI) + RotL64(aOrbiterC, 51U)) + RotL64(aCarry, 21U));
            aWandererF = aWandererF ^ (((RotL64(aScatter, 23U) + aOrbiterK) + RotL64(aOrbiterF, 57U)) + aPhaseEWandererUpdateSaltB[((aIndex + 17U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 46U) + aOrbiterD) + RotL64(aOrbiterC, 29U)) + RotL64(aCarry, 3U));
            aWandererK = aWandererK ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterF, 23U)) + aOrbiterI) + aPhaseEWandererUpdateSaltF[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererH = aWandererH + ((RotL64(aPrevious, 57U) + aOrbiterF) + RotL64(aOrbiterA, 5U));
            aWandererJ = aWandererJ ^ ((RotL64(aCross, 29U) + RotL64(aOrbiterI, 12U)) + aOrbiterK);
            //
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 47U));
            aCarry = aCarry + (RotL64(aWandererK, 27U) ^ aWandererF);
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 58U));
            aCarry = aCarry + RotL64(aWandererC, 13U);
            aCarry = aCarry + RotL64(aIngress, 35U);
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
            aIngress = (RotL64(aOperationLaneB[((aIndex + 23193U)) & S_BLOCK1], 27U) ^ RotL64(aOperationLaneA[((aIndex + 23553U)) & S_BLOCK1], 19U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 23049U)) & S_BLOCK1], 36U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 26981U)) & S_BLOCK1], 26U) ^ RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 22779U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aInvestLaneD[((aIndex + 23328U)) & S_BLOCK1], 41U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 47U) + RotL64(aCross, 35U)) + (RotL64(aIngress, 23U) ^ RotL64(aCarry, 6U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterC = (aWandererD + RotL64(aScatter, 35U)) + 13278949403988203974U;
            aOrbiterF = ((aWandererJ + RotL64(aCross, 13U)) + RotL64(aCarry, 51U)) + 9213599924054673756U;
            aOrbiterI = (aWandererC + RotL64(aIngress, 29U)) + 1255746482932381798U;
            aOrbiterK = ((aWandererF + RotL64(aPrevious, 41U)) + RotL64(aCarry, 39U)) + 11575321997144516122U;
            aOrbiterB = ((aWandererE + RotL64(aIngress, 23U)) + 15881587525529432437U) + aPhaseEOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterD = (aWandererB + RotL64(aPrevious, 57U)) + 9846195809864862707U;
            aOrbiterJ = (((aWandererH + RotL64(aScatter, 50U)) + RotL64(aCarry, 5U)) + 12319815691858217670U) + aPhaseEOrbiterAssignSaltA[((aIndex + 13U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 16322617427294439587U;
            aOrbiterI = (aOrbiterI ^ aOrbiterC) ^ 16332130810525887437U;
            aOrbiterI = RotL64((aOrbiterI * 7588076439690559343U), 21U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4920951156015336794U;
            aOrbiterB = (aOrbiterB ^ aOrbiterI) ^ 16767126455124552329U;
            aOrbiterB = RotL64((aOrbiterB * 4440352337076842603U), 47U);
            //
            aOrbiterD = ((aOrbiterD + aOrbiterI) + 12553595911087945223U) + aPhaseEOrbiterUpdateSaltA[((aIndex + 29U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 1437522202135436142U;
            aOrbiterJ = RotL64((aOrbiterJ * 2001992794165550905U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 12313100454852227143U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 2761983020631055729U) ^ aPhaseEOrbiterUpdateSaltF[((aIndex + 24U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 3874839760378039509U), 29U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 17635303588421554367U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 788212489507463763U;
            aOrbiterD = RotL64((aOrbiterD * 17896475584538528059U), 53U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterD) + 5192552894670654434U) + aPhaseEOrbiterUpdateSaltB[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 6784748488807738811U;
            aOrbiterK = RotL64((aOrbiterK * 8077237651953896479U), 5U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterB) + 16113417046719114943U) + aPhaseEOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterJ) ^ 1096874945215225916U;
            aOrbiterF = RotL64((aOrbiterF * 17308604412622879833U), 35U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterK, 22U);
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterF, 13U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterB, 37U));
            aIngress = aIngress + RotL64(aOrbiterJ, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererC = aWandererC + ((RotL64(aPrevious, 47U) + RotL64(aOrbiterB, 48U)) + aOrbiterJ);
            aWandererD = aWandererD ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterK, 57U)) + aOrbiterF);
            aWandererB = aWandererB + (((RotL64(aCross, 35U) + aOrbiterK) + RotL64(aOrbiterI, 3U)) + RotL64(aCarry, 11U));
            aWandererJ = aWandererJ ^ (((RotL64(aScatter, 53U) + RotL64(aOrbiterD, 11U)) + aOrbiterB) + aPhaseEWandererUpdateSaltD[((aIndex + 28U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 60U) + aOrbiterI) + RotL64(aOrbiterD, 21U)) + RotL64(aCarry, 47U));
            aWandererE = aWandererE ^ (((RotL64(aScatter, 5U) + aOrbiterD) + RotL64(aOrbiterF, 39U)) + aPhaseEWandererUpdateSaltC[(((31U - aIndex) + 10U)) & S_SALT1]);
            aWandererF = aWandererF + ((RotL64(aPrevious, 41U) + RotL64(aOrbiterB, 29U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererJ, 22U) ^ aWandererE);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererF, 57U));
            aCarry = aCarry + RotL64(aWandererB, 29U);
            aCarry = aCarry + RotL64(aIngress, 13U);
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
            aIngress = (RotL64(aOperationLaneC[((aIndex + 32394U)) & S_BLOCK1], 29U) ^ RotL64(aExpandLaneA[((aIndex + 31975U)) & S_BLOCK1], 37U));
            aIngress ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 27520U)) & S_BLOCK1], 54U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 30962U)) & S_BLOCK1], 19U) ^ RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 28215U)) & S_BLOCK1], 40U));
            aCross ^= RotL64(aInvestLaneD[((S_BLOCK1 - aIndex + 28911U)) & S_BLOCK1], 27U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 5U)) + (RotL64(aPrevious, 36U) + RotL64(aCarry, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = (aWandererK + RotL64(aIngress, 3U)) + 6916817163240024692U;
            aOrbiterH = ((aWandererA + RotL64(aScatter, 29U)) + RotL64(aCarry, 47U)) + 14554930751292077817U;
            aOrbiterB = (aWandererD + RotL64(aPrevious, 50U)) + 1098305064484336101U;
            aOrbiterE = (aWandererG + RotL64(aCross, 11U)) + 12192821172420471527U;
            aOrbiterI = (((aWandererH + RotL64(aPrevious, 35U)) + RotL64(aCarry, 11U)) + 2435134991707318845U) + aPhaseEOrbiterAssignSaltC[((aIndex + 12U)) & S_SALT1];
            aOrbiterA = (((aWandererJ + RotL64(aCross, 21U)) + RotL64(aCarry, 29U)) + 1896745368738512624U) + aPhaseEOrbiterAssignSaltD[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererC + RotL64(aIngress, 57U)) + 1114996424222923873U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 9839135798371512656U;
            aOrbiterB = (aOrbiterB ^ aOrbiterG) ^ 8037967239603177043U;
            aOrbiterB = RotL64((aOrbiterB * 7848951103759663025U), 51U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 15185468738487237432U;
            aOrbiterI = (aOrbiterI ^ aOrbiterE) ^ 4912098316394854543U;
            aOrbiterI = RotL64((aOrbiterI * 3072785550384399929U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13142688607850380888U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterA) ^ 4507379759608945839U) ^ aPhaseEOrbiterUpdateSaltA[(((31U - aIndex) + 27U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 2989332387754215967U), 57U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 7299006009652289342U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterB) ^ 5390655277207053627U) ^ aPhaseEOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 10973744708856143715U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterE) + 6744737023577785725U;
            aOrbiterH = (aOrbiterH ^ aOrbiterF) ^ 15539737698867067285U;
            aOrbiterH = RotL64((aOrbiterH * 4686092035261336911U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterF) + 13329866734681377952U) + aPhaseEOrbiterUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterI) ^ 13284937458969166257U;
            aOrbiterG = RotL64((aOrbiterG * 3965985432462699445U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterI) + 8695002088915702168U) + aPhaseEOrbiterUpdateSaltC[(((31U - aIndex) + 15U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterH) ^ 3858059421620839286U;
            aOrbiterA = RotL64((aOrbiterA * 9559783727301092937U), 35U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterH, 29U);
            aIngress = aIngress + (RotL64(aOrbiterA, 23U) ^ aOrbiterB);
            aIngress = aIngress + (RotL64(aOrbiterE, 13U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 57U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aScatter, 11U) + RotL64(aOrbiterE, 26U)) + aOrbiterA);
            aWandererG = aWandererG ^ (((RotL64(aIngress, 27U) + RotL64(aOrbiterI, 13U)) + aOrbiterG) + aPhaseEWandererUpdateSaltA[((aIndex + 10U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aCross, 43U) + aOrbiterE) + RotL64(aOrbiterB, 41U)) + RotL64(aCarry, 51U));
            aWandererJ = aWandererJ ^ ((RotL64(aPrevious, 56U) + RotL64(aOrbiterH, 19U)) + aOrbiterI);
            aWandererC = aWandererC + ((RotL64(aCross, 35U) + RotL64(aOrbiterG, 47U)) + aOrbiterE);
            aWandererK = aWandererK ^ (((RotL64(aScatter, 19U) + RotL64(aOrbiterA, 35U)) + aOrbiterH) + aPhaseEWandererUpdateSaltE[(((31U - aIndex) + 26U)) & S_SALT1]);
            aWandererH = aWandererH + (((RotL64(aIngress, 3U) + aOrbiterF) + RotL64(aOrbiterI, 5U)) + RotL64(aCarry, 39U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererA, 19U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererC, 39U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererK, 24U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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

void TwistExpander_Lacrosse_Arx::Twist_C(TwistWorkSpace *pWorkSpace,
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
        // read from: aOperationLaneA, aOperationLaneB, aExpandLaneD, aOperationLaneC, aOperationLaneD, aExpandLaneB, aSnowLaneA, aExpandLaneA, aInvestLaneB, aSnowLaneB, aInvestLaneA, aWorkLaneA, aInvestLaneD, aWorkLaneB, aInvestLaneC, aWorkLaneC, aExpandLaneC
        // write to: aSnowLaneA, aSnowLaneB, aWorkLaneA, aWorkLaneB, aWorkLaneC, aWorkLaneD
    
        // twist_loop_c loop 1
        // ingress from: aOperationLaneA, aOperationLaneB, aExpandLaneD
        // ingress directions: aOperationLaneA forward forced, aOperationLaneB forward forced, aExpandLaneD forward/backward random
        // cross from: aOperationLaneC, aOperationLaneD, aExpandLaneB
        // cross directions: aOperationLaneC backward forced, aOperationLaneD backward forced, aExpandLaneB backward/forward random
        // write to: aSnowLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aOperationLaneA[((aIndex + 1207U)) & S_BLOCK1], 11U) ^ RotL64(aOperationLaneB[((aIndex + 1759U)) & S_BLOCK1], 53U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 2427U)) & S_BLOCK1], 24U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 1537U)) & S_BLOCK1], 3U) ^ RotL64(aOperationLaneD[((S_BLOCK1 - aIndex + 421U)) & S_BLOCK1], 19U));
            aCross ^= RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 4815U)) & S_BLOCK1], 36U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aIngress, 19U) ^ RotL64(aCross, 52U)) ^ (RotL64(aPrevious, 5U) + RotL64(aCarry, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterI = (aWandererF + RotL64(aPrevious, 39U)) + 2558105147674438050U;
            aOrbiterE = (aWandererI + RotL64(aScatter, 47U)) + 15856662514774702561U;
            aOrbiterC = ((aWandererG + RotL64(aIngress, 34U)) + RotL64(aCarry, 47U)) + 13346869226246584582U;
            aOrbiterG = (aWandererD + RotL64(aCross, 37U)) + 7632111846116243973U;
            aOrbiterA = (aWandererE + RotL64(aScatter, 53U)) + 2102101361626976279U;
            aOrbiterD = ((aWandererB + RotL64(aCross, 27U)) + 5605968705067851563U) + aPhaseFOrbiterAssignSaltF[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterF = ((aWandererJ + RotL64(aPrevious, 21U)) + RotL64(aCarry, 43U)) + 6842483186584326681U;
            aOrbiterH = (aWandererC + RotL64(aIngress, 57U)) + 5559797213819425064U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 23U)) + RotL64(aCarry, 3U)) + 12422313931331576759U;
            aOrbiterJ = (aWandererK + RotL64(aPrevious, 50U)) + 2751024420047872601U;
            aOrbiterB = ((aWandererH + RotL64(aScatter, 29U)) + 11031320239359798610U) + aPhaseFOrbiterAssignSaltD[(((31U - aIndex) + 8U)) & S_SALT1];
            //
            aOrbiterI = (aOrbiterI + aOrbiterE) + 14366375309473793217U;
            aOrbiterC = (aOrbiterC ^ aOrbiterI) ^ 11971479429768505316U;
            aOrbiterC = RotL64((aOrbiterC * 10063001532313098203U), 29U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterA) + 3947595951884469542U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 10U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterG) ^ 17882767922372770896U;
            aOrbiterD = RotL64((aOrbiterD * 3361906348965810211U), 23U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 513871456983509223U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 5951677013597794294U;
            aOrbiterF = RotL64((aOrbiterF * 8508629569649935293U), 43U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterH) + 437626309049021931U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterA) ^ 466674061172005705U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 1310502572084891157U), 51U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 12362602809233133718U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterF) ^ 10525852878882195702U) ^ aPhaseFOrbiterUpdateSaltD[((aIndex + 15U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 17755022180514914325U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 17927000184308583095U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 566723721423470052U;
            aOrbiterJ = RotL64((aOrbiterJ * 17710534355278632573U), 39U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 9504585484034413577U;
            aOrbiterK = (aOrbiterK ^ aOrbiterE) ^ 4614306037721859929U;
            aOrbiterK = RotL64((aOrbiterK * 170807293799483539U), 19U);
            //
            aOrbiterB = ((aOrbiterB + aOrbiterF) + 1463218357720031588U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 3U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterB) ^ 4036696102163560633U;
            aOrbiterG = RotL64((aOrbiterG * 15389914226155130065U), 21U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterD) + 9907678911300898726U;
            aOrbiterB = (aOrbiterB ^ aOrbiterJ) ^ 11804311892289601322U;
            aOrbiterB = RotL64((aOrbiterB * 13986106774841242253U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterJ) + 6514645538508331396U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 17246364354815744899U;
            aOrbiterE = RotL64((aOrbiterE * 12800661037742526999U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterK) + 6725706155285333764U;
            aOrbiterH = (aOrbiterH ^ aOrbiterC) ^ 2558105147674438050U;
            aOrbiterH = RotL64((aOrbiterH * 6752457079901154727U), 37U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterD, 58U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterK, 19U));
            aIngress = aIngress + (RotL64(aOrbiterF, 27U) ^ aOrbiterH);
            aIngress = aIngress + (RotL64(aOrbiterA, 21U) ^ aOrbiterE);
            aIngress = aIngress + (RotL64(aOrbiterI, 5U) ^ aOrbiterC);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE ^ ((RotL64(aScatter, 41U) + aOrbiterF) + RotL64(aOrbiterE, 37U));
            aWandererG = aWandererG + (((RotL64(aIngress, 44U) + RotL64(aOrbiterD, 10U)) + aOrbiterC) + RotL64(aCarry, 13U));
            aWandererB = aWandererB ^ ((RotL64(aCross, 19U) + RotL64(aOrbiterI, 51U)) + aOrbiterA);
            aWandererH = aWandererH + ((RotL64(aPrevious, 3U) + RotL64(aOrbiterC, 39U)) + aOrbiterG);
            aWandererI = aWandererI ^ ((RotL64(aIngress, 13U) + aOrbiterF) + RotL64(aOrbiterH, 57U));
            aWandererA = aWandererA + ((RotL64(aCross, 5U) + RotL64(aOrbiterE, 23U)) + aOrbiterH);
            aWandererK = aWandererK ^ ((RotL64(aScatter, 53U) + RotL64(aOrbiterK, 41U)) + aOrbiterC);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 57U) + aOrbiterJ) + RotL64(aOrbiterB, 18U)) + RotL64(aCarry, 23U));
            aWandererC = aWandererC ^ (((RotL64(aIngress, 50U) + aOrbiterJ) + RotL64(aOrbiterI, 47U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 6U)) & S_SALT1]);
            aWandererD = aWandererD + ((RotL64(aPrevious, 39U) + aOrbiterJ) + RotL64(aOrbiterD, 13U));
            aWandererF = aWandererF ^ (((RotL64(aCross, 35U) + RotL64(aOrbiterB, 27U)) + aOrbiterH) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 20U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererE, 19U) ^ aWandererB);
            aCarry = aCarry + (RotL64(aWandererA, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererD ^ RotL64(aWandererG, 60U));
            aCarry = aCarry + (RotL64(aWandererJ, 27U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererI, 35U) ^ aWandererK);
            aCarry = aCarry + RotL64(aWandererF, 57U);
            aCarry = aCarry + RotL64(aIngress, 14U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 2
        // ingress from: aSnowLaneA, aOperationLaneC, aOperationLaneD, aExpandLaneA
        // ingress directions: aSnowLaneA forward forced, aOperationLaneC forward forced, aOperationLaneD forward forced, aExpandLaneA forward/backward random
        // cross from: aOperationLaneA, aOperationLaneB, aInvestLaneB
        // cross directions: aOperationLaneA backward forced, aOperationLaneB backward forced, aInvestLaneB backward/forward random
        // write to: aSnowLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneA[((aIndex + 10734U)) & S_BLOCK1], 53U) ^ RotL64(aOperationLaneC[((aIndex + 10650U)) & S_BLOCK1], 34U));
            aIngress ^= (RotL64(aOperationLaneD[((aIndex + 10577U)) & S_BLOCK1], 5U) ^ RotL64(aExpandLaneA[((aIndex + 8353U)) & S_BLOCK1], 23U));
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aOperationLaneA[((S_BLOCK1 - aIndex + 8084U)) & S_BLOCK1], 60U) ^ RotL64(aOperationLaneB[((S_BLOCK1 - aIndex + 7379U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aInvestLaneB[((S_BLOCK1 - aIndex + 10836U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 11U) ^ RotL64(aCarry, 53U)) + (RotL64(aPrevious, 40U) + RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterE = ((aWandererE + RotL64(aPrevious, 39U)) + 2101601659597850213U) + aPhaseFOrbiterAssignSaltA[((aIndex + 4U)) & S_SALT1];
            aOrbiterA = (aWandererA + RotL64(aIngress, 21U)) + 2759794072560720121U;
            aOrbiterC = (aWandererG + RotL64(aCross, 18U)) + 9443562552411269339U;
            aOrbiterG = ((aWandererB + RotL64(aScatter, 57U)) + RotL64(aCarry, 19U)) + 10801360546699857975U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 41U)) + 8020716394829332019U;
            aOrbiterI = (aWandererI + RotL64(aIngress, 37U)) + 1021894212367773801U;
            aOrbiterK = (aWandererC + RotL64(aScatter, 3U)) + 13346855534622490176U;
            aOrbiterJ = (aWandererH + RotL64(aCross, 29U)) + 16359309548462953836U;
            aOrbiterB = ((aWandererD + RotL64(aIngress, 23U)) + RotL64(aCarry, 35U)) + 12642446944680783519U;
            aOrbiterF = ((aWandererK + RotL64(aScatter, 46U)) + 8197424982767553380U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterD = ((aWandererF + RotL64(aCross, 13U)) + RotL64(aCarry, 47U)) + 14346334610901859094U;
            //
            aOrbiterE = ((aOrbiterE + aOrbiterA) + 14171304260534233539U) + aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 334531601308283605U;
            aOrbiterC = RotL64((aOrbiterC * 5012968232749075075U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterH) + 10707856298471572695U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 18364775750091914766U;
            aOrbiterI = RotL64((aOrbiterI * 15735143943129143265U), 53U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterJ) + 8531394793118363836U;
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 15352876929406908882U;
            aOrbiterG = RotL64((aOrbiterG * 475199047053777179U), 51U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterB) + 567682016232278157U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterJ = (aOrbiterJ ^ aOrbiterI) ^ 2068146551757663119U;
            aOrbiterJ = RotL64((aOrbiterJ * 1557877740957797555U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterI) + 7776122587613256525U;
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 16430938890724272256U;
            aOrbiterK = RotL64((aOrbiterK * 4540270493783593257U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 11912000645055436094U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterC) ^ 16800749242578741498U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 17804584625034241737U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 5909199180260499150U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterD) ^ 5751089915336865588U) ^ aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 15376689503142397927U), 3U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterC) + 3478216857728853008U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 18007567146937338241U;
            aOrbiterB = RotL64((aOrbiterB * 6620498877303917855U), 13U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterE) + 17454259424163653490U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 6276120962018305311U;
            aOrbiterH = RotL64((aOrbiterH * 7560618224285018801U), 39U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 3839336239901666431U;
            aOrbiterE = (aOrbiterE ^ aOrbiterB) ^ 6230149015045237670U;
            aOrbiterE = RotL64((aOrbiterE * 1838983748994340883U), 47U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 17552095486612766544U;
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 2101601659597850213U;
            aOrbiterF = RotL64((aOrbiterF * 2915330118061857271U), 23U);
            //
            aIngress = aOrbiterI ^ RotL64(aOrbiterK, 51U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterJ, 28U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterB, 39U));
            aIngress = aIngress + (aOrbiterD ^ RotL64(aOrbiterH, 11U));
            aIngress = aIngress + (RotL64(aOrbiterA, 19U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterF, 37U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aCross, 27U) + aOrbiterB) + RotL64(aOrbiterK, 47U));
            aWandererK = aWandererK ^ ((RotL64(aIngress, 30U) + aOrbiterC) + RotL64(aOrbiterG, 37U));
            aWandererE = aWandererE + ((RotL64(aPrevious, 43U) + RotL64(aOrbiterG, 35U)) + aOrbiterA);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 39U) + RotL64(aOrbiterI, 54U)) + aOrbiterG);
            aWandererB = aWandererB + ((((RotL64(aPrevious, 41U) + aOrbiterG) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 19U)) + aPhaseFWandererUpdateSaltE[(((31U - aIndex) + 28U)) & S_SALT1]);
            aWandererH = aWandererH ^ (((RotL64(aIngress, 4U) + RotL64(aOrbiterK, 11U)) + aOrbiterD) + aPhaseFWandererUpdateSaltB[(((31U - aIndex) + 3U)) & S_SALT1]);
            aWandererI = aWandererI + ((RotL64(aScatter, 47U) + RotL64(aOrbiterF, 23U)) + aOrbiterH);
            aWandererD = aWandererD ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterG, 21U)) + aOrbiterH);
            aWandererC = aWandererC + (((RotL64(aScatter, 19U) + aOrbiterG) + RotL64(aOrbiterJ, 41U)) + RotL64(aCarry, 27U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 51U) + aOrbiterG) + RotL64(aOrbiterF, 39U));
            aWandererJ = aWandererJ + ((RotL64(aIngress, 53U) + aOrbiterJ) + RotL64(aOrbiterK, 50U));
            //
            aCarry = aCarry + (RotL64(aWandererA, 42U) ^ aWandererJ);
            aCarry = aCarry + (RotL64(aWandererF, 47U) ^ aWandererG);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererI, 5U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererK);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererD, 13U));
            aCarry = aCarry + RotL64(aWandererH, 44U);
            aCarry = aCarry + RotL64(aIngress, 39U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aSnowLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 3
        // ingress from: aSnowLaneB, aOperationLaneA, aInvestLaneA
        // ingress directions: aSnowLaneB forward forced, aOperationLaneA forward forced, aInvestLaneA forward/backward random
        // cross from: aSnowLaneA, aOperationLaneC
        // cross directions: aSnowLaneA backward forced, aOperationLaneC backward/forward random
        // write to: aWorkLaneA
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aSnowLaneB[((aIndex + 15815U)) & S_BLOCK1], 41U) ^ RotL64(aOperationLaneA[((aIndex + 13330U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aInvestLaneA[((aIndex + 12570U)) & S_BLOCK1], 12U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = RotL64(aSnowLaneA[((S_BLOCK1 - aIndex + 11595U)) & S_BLOCK1], 50U) ^ RotL64(aOperationLaneC[((S_BLOCK1 - aIndex + 13289U)) & S_BLOCK1], 19U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 29U) + RotL64(aCarry, 10U)) + (RotL64(aPrevious, 41U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterJ = (aWandererG + RotL64(aIngress, 37U)) + 18144572925667544139U;
            aOrbiterH = (aWandererD + RotL64(aCross, 43U)) + 5659758077574059728U;
            aOrbiterD = (aWandererI + RotL64(aScatter, 6U)) + 6343330616999166392U;
            aOrbiterE = (aWandererH + RotL64(aPrevious, 57U)) + 17754639838410839447U;
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 39U)) + RotL64(aCarry, 51U)) + 9451843819849581729U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterC = (((aWandererC + RotL64(aScatter, 11U)) + RotL64(aCarry, 29U)) + 7957854457197462212U) + aPhaseFOrbiterAssignSaltB[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = (aWandererA + RotL64(aCross, 53U)) + 1461994799722205010U;
            aOrbiterA = (aWandererF + RotL64(aPrevious, 35U)) + 18002214276252170177U;
            aOrbiterB = (aWandererE + RotL64(aCross, 23U)) + 14689869073147027164U;
            aOrbiterI = (aWandererK + RotL64(aIngress, 27U)) + 3978104368003440293U;
            aOrbiterK = ((aWandererB + RotL64(aPrevious, 60U)) + RotL64(aCarry, 47U)) + 8512135845221335386U;
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterH) + 1477533446382953439U;
            aOrbiterD = (aOrbiterD ^ aOrbiterJ) ^ 2166717790929947990U;
            aOrbiterD = RotL64((aOrbiterD * 6538884492418324461U), 21U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterG) + 8082437060686606995U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4363687722464700362U;
            aOrbiterC = RotL64((aOrbiterC * 7199165810993478887U), 23U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterA) + 15782763348014924206U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterF) ^ 8572509150015960728U;
            aOrbiterJ = RotL64((aOrbiterJ * 3340528604891897779U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 12248271773316742521U;
            aOrbiterH = (aOrbiterH ^ aOrbiterA) ^ 9602078627638561949U;
            aOrbiterH = RotL64((aOrbiterH * 1860631869877427405U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 17244849374768558859U;
            aOrbiterA = (aOrbiterA ^ aOrbiterC) ^ 1030743048280579012U;
            aOrbiterA = RotL64((aOrbiterA * 10858949914285817051U), 11U);
            //
            aOrbiterH = ((aOrbiterH + aOrbiterE) + 17722342363541914280U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterH) ^ 15667504059789880034U;
            aOrbiterK = RotL64((aOrbiterK * 15872269872168533709U), 37U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterK) + 12645332941998550794U;
            aOrbiterG = (aOrbiterG ^ aOrbiterD) ^ 9938135244509986497U;
            aOrbiterG = RotL64((aOrbiterG * 16548185968987392957U), 27U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 4024609904162105979U;
            aOrbiterF = (aOrbiterF ^ aOrbiterK) ^ 6732064218696157303U;
            aOrbiterF = RotL64((aOrbiterF * 3815409766145891393U), 43U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 14314117137220703583U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 8U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterI) ^ 15244765904057473814U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 4034571710808047959U), 19U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 17441241682018169245U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 11958974379114644873U;
            aOrbiterI = RotL64((aOrbiterI * 11315689206845170303U), 53U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterD) + 8310839846793796473U;
            aOrbiterE = ((aOrbiterE ^ aOrbiterB) ^ 18144572925667544139U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 11668203295511168011U), 35U);
            //
            aIngress = aOrbiterF ^ RotL64(aOrbiterB, 60U);
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterI, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterA, 3U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 39U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterH, 11U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA + ((RotL64(aPrevious, 6U) + aOrbiterJ) + RotL64(aOrbiterE, 41U));
            aWandererB = aWandererB ^ ((RotL64(aIngress, 11U) + RotL64(aOrbiterI, 21U)) + aOrbiterF);
            aWandererE = aWandererE + (((RotL64(aCross, 39U) + aOrbiterA) + RotL64(aOrbiterK, 35U)) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 15U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aScatter, 27U) + aOrbiterI) + RotL64(aOrbiterG, 19U));
            aWandererH = aWandererH + (((RotL64(aCross, 44U) + aOrbiterG) + RotL64(aOrbiterH, 30U)) + RotL64(aCarry, 29U));
            aWandererG = aWandererG ^ ((RotL64(aPrevious, 41U) + RotL64(aOrbiterJ, 37U)) + aOrbiterD);
            aWandererK = aWandererK + ((RotL64(aIngress, 21U) + aOrbiterC) + RotL64(aOrbiterI, 51U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 13U) + RotL64(aOrbiterB, 11U)) + aOrbiterD) + aPhaseFWandererUpdateSaltA[((aIndex + 18U)) & S_SALT1]);
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 29U) + aOrbiterJ) + RotL64(aOrbiterK, 47U)) + RotL64(aCarry, 41U));
            aWandererC = aWandererC ^ ((RotL64(aScatter, 53U) + aOrbiterB) + RotL64(aOrbiterF, 56U));
            aWandererI = aWandererI + ((RotL64(aIngress, 3U) + RotL64(aOrbiterD, 3U)) + aOrbiterG);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererH, 37U));
            aCarry = aCarry + (RotL64(aWandererF, 21U) ^ aWandererD);
            aCarry = aCarry + (RotL64(aWandererA, 23U) ^ aWandererK);
            aCarry = aCarry + (RotL64(aWandererC, 19U) ^ aWandererB);
            aCarry = aCarry + RotL64(aWandererE, 29U);
            aCarry = aCarry + RotL64(aIngress, 51U);
            aCarry = TwistMix64::DiffuseB(aCarry);
            //
            aWorkLaneA[aIndex] = aIngress;
        }
    
        // twist_loop_c loop 4
        // ingress from: aWorkLaneA, aSnowLaneA, aInvestLaneD
        // ingress directions: aWorkLaneA forward forced, aSnowLaneA forward forced, aInvestLaneD forward/backward random
        // cross from: aSnowLaneB, aOperationLaneD
        // cross directions: aSnowLaneB backward forced, aOperationLaneD backward/forward random
        // write to: aWorkLaneB
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneA[((aIndex + 17821U)) & S_BLOCK1], 60U) ^ RotL64(aSnowLaneA[((aIndex + 20656U)) & S_BLOCK1], 43U));
            aIngress ^= RotL64(aInvestLaneD[((aIndex + 19214U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aSnowLaneB[((S_BLOCK1 - aIndex + 21640U)) & S_BLOCK1], 22U) ^ RotL64(aOperationLaneD[((aIndex + 17217U)) & S_BLOCK1], 39U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 5U) + RotL64(aCross, 21U)) ^ (RotL64(aCarry, 43U) + RotL64(aIngress, 56U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterD = ((aWandererF + RotL64(aCross, 57U)) + 3238389262925516513U) + aPhaseFOrbiterAssignSaltD[((aIndex + 19U)) & S_SALT1];
            aOrbiterA = (aWandererC + RotL64(aPrevious, 3U)) + 12381787182611386995U;
            aOrbiterK = (aWandererB + RotL64(aIngress, 30U)) + 7883885539305181549U;
            aOrbiterB = ((aWandererJ + RotL64(aScatter, 13U)) + RotL64(aCarry, 29U)) + 1185413044597727092U;
            aOrbiterJ = (aWandererG + RotL64(aIngress, 47U)) + 15219353497204773135U;
            aOrbiterI = (aWandererA + RotL64(aScatter, 43U)) + 7533774715626734082U;
            aOrbiterE = ((aWandererI + RotL64(aPrevious, 5U)) + 2599930450937763464U) + aPhaseFOrbiterAssignSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterG = (aWandererK + RotL64(aCross, 35U)) + 16074720663961214284U;
            aOrbiterF = ((aWandererH + RotL64(aPrevious, 22U)) + RotL64(aCarry, 3U)) + 15483613196360051221U;
            aOrbiterH = ((aWandererE + RotL64(aCross, 19U)) + RotL64(aCarry, 39U)) + 9396557867081376268U;
            aOrbiterC = (aWandererD + RotL64(aIngress, 39U)) + 9668459976852660245U;
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 9037269914643207212U;
            aOrbiterK = (aOrbiterK ^ aOrbiterD) ^ 16936742640861088240U;
            aOrbiterK = RotL64((aOrbiterK * 1040172193161012227U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterK) + 16481274825758546398U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 481851372837611166U;
            aOrbiterJ = RotL64((aOrbiterJ * 2225030139210599207U), 41U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterJ) + 13608921517203544108U;
            aOrbiterE = (aOrbiterE ^ aOrbiterI) ^ 16930740723286214636U;
            aOrbiterE = RotL64((aOrbiterE * 2605108503821980865U), 57U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterE) + 902242902582149908U) + aPhaseFOrbiterUpdateSaltE[((aIndex + 28U)) & S_SALT1];
            aOrbiterF = ((aOrbiterF ^ aOrbiterG) ^ 1510861213079342977U) ^ aPhaseFOrbiterUpdateSaltC[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 3309753895727400707U), 53U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterF) + 7116243600304980310U;
            aOrbiterD = (aOrbiterD ^ aOrbiterH) ^ 6631412278359709602U;
            aOrbiterD = RotL64((aOrbiterD * 11452627691392637463U), 11U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 9246698682265275165U;
            aOrbiterA = (aOrbiterA ^ aOrbiterF) ^ 8594373032014031450U;
            aOrbiterA = RotL64((aOrbiterA * 2550138341089957033U), 13U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterB) + 15912837963877821048U;
            aOrbiterI = (aOrbiterI ^ aOrbiterA) ^ 11404583513022627609U;
            aOrbiterI = RotL64((aOrbiterI * 17715204726760125357U), 47U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterD) + 17295214920690244319U;
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 18315664494984189344U) ^ aPhaseFOrbiterUpdateSaltB[((aIndex + 4U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 17398893532076312945U), 29U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterH) + 2474825506593695564U;
            aOrbiterC = (aOrbiterC ^ aOrbiterE) ^ 4400473621592150441U;
            aOrbiterC = RotL64((aOrbiterC * 7098832854166953839U), 19U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterG) + 15270166373215060119U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 4331232225067306139U;
            aOrbiterH = RotL64((aOrbiterH * 2299883590703870703U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterI) + 2176207815544347316U) + aPhaseFOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterK) ^ 3238389262925516513U;
            aOrbiterG = RotL64((aOrbiterG * 13104597690682251231U), 23U);
            //
            aIngress = aOrbiterB ^ RotL64(aOrbiterA, 39U);
            aIngress = aIngress + (aOrbiterH ^ RotL64(aOrbiterI, 23U));
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterG, 13U));
            aIngress = aIngress + (RotL64(aOrbiterC, 30U) ^ aOrbiterF);
            aIngress = aIngress + (RotL64(aOrbiterK, 43U) ^ aOrbiterD);
            aIngress = aIngress + RotL64(aOrbiterJ, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aScatter, 52U) + aOrbiterK) + RotL64(aOrbiterB, 29U));
            aWandererH = aWandererH + (((RotL64(aIngress, 27U) + aOrbiterE) + RotL64(aOrbiterH, 43U)) + RotL64(aCarry, 35U));
            aWandererC = aWandererC ^ ((RotL64(aCross, 29U) + aOrbiterJ) + RotL64(aOrbiterD, 53U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 19U) + RotL64(aOrbiterK, 57U)) + aOrbiterC) + RotL64(aCarry, 23U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 6U) + aOrbiterJ) + RotL64(aOrbiterA, 19U));
            aWandererG = aWandererG + ((RotL64(aScatter, 11U) + aOrbiterC) + RotL64(aOrbiterD, 27U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 57U) + aOrbiterB) + RotL64(aOrbiterF, 60U));
            aWandererF = aWandererF + (((RotL64(aPrevious, 41U) + aOrbiterD) + RotL64(aOrbiterG, 51U)) + aPhaseFWandererUpdateSaltF[(((31U - aIndex) + 23U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aScatter, 43U) + aOrbiterI) + RotL64(aOrbiterH, 39U));
            aWandererI = aWandererI + (((RotL64(aIngress, 47U) + aOrbiterK) + RotL64(aOrbiterG, 3U)) + aPhaseFWandererUpdateSaltC[(((31U - aIndex) + 14U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 3U) + aOrbiterH) + RotL64(aOrbiterF, 6U));
            //
            aCarry = aCarry + (RotL64(aWandererF, 10U) ^ aWandererD);
            aCarry = aCarry + (aWandererB ^ RotL64(aWandererJ, 51U));
            aCarry = aCarry + (aWandererG ^ RotL64(aWandererH, 21U));
            aCarry = aCarry + (RotL64(aWandererK, 41U) ^ aWandererC);
            aCarry = aCarry + (aWandererE ^ RotL64(aWandererA, 23U));
            aCarry = aCarry + RotL64(aWandererI, 38U);
            aCarry = aCarry + RotL64(aIngress, 19U);
            aCarry = TwistMix64::DiffuseC(aCarry);
            //
            aWorkLaneB[S_BLOCK1 - aIndex] = aIngress;
        }
    
        // twist_loop_c loop 5
        // ingress from: aWorkLaneB, aSnowLaneB, aInvestLaneC
        // ingress directions: aWorkLaneB forward forced, aSnowLaneB forward forced, aInvestLaneC forward/backward random
        // cross from: aWorkLaneA, aSnowLaneA
        // cross directions: aWorkLaneA backward forced, aSnowLaneA backward/forward random
        // write to: aWorkLaneC
        for (std::size_t aIndex = 0U; aIndex < static_cast<std::size_t>(S_BLOCK); aIndex += 1U) {
            //
            aPrevious = aIngress;
            //
            aIngress = (RotL64(aWorkLaneB[((aIndex + 25497U)) & S_BLOCK1], 39U) ^ RotL64(aSnowLaneB[((aIndex + 23239U)) & S_BLOCK1], 51U));
            aIngress ^= RotL64(aInvestLaneC[((S_BLOCK1 - aIndex + 25796U)) & S_BLOCK1], 22U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 23796U)) & S_BLOCK1], 43U) ^ RotL64(aSnowLaneA[((aIndex + 26205U)) & S_BLOCK1], 14U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 53U) ^ RotL64(aIngress, 5U)) ^ (RotL64(aPrevious, 35U) + RotL64(aCross, 22U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterI = (aWandererK + RotL64(aIngress, 51U)) + 6024062041314952357U;
            aOrbiterJ = ((aWandererF + RotL64(aScatter, 23U)) + RotL64(aCarry, 43U)) + 18340757093658015585U;
            aOrbiterA = (aWandererD + RotL64(aCross, 47U)) + 11911120493880346751U;
            aOrbiterB = ((aWandererB + RotL64(aPrevious, 35U)) + 17428074353884654439U) + aPhaseFOrbiterAssignSaltC[(((31U - aIndex) + 24U)) & S_SALT1];
            aOrbiterK = (aWandererA + RotL64(aIngress, 6U)) + 12790849760814795936U;
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 19U)) + RotL64(aCarry, 21U)) + 12633397052172117800U) + aPhaseFOrbiterAssignSaltA[((aIndex + 5U)) & S_SALT1];
            aOrbiterE = (aWandererI + RotL64(aCross, 37U)) + 11946150433665237945U;
            aOrbiterC = (aWandererC + RotL64(aScatter, 27U)) + 16842157900909419285U;
            aOrbiterF = (aWandererE + RotL64(aPrevious, 13U)) + 14186235783224155962U;
            aOrbiterH = ((aWandererG + RotL64(aCross, 11U)) + RotL64(aCarry, 53U)) + 13284904542579767591U;
            aOrbiterD = (aWandererJ + RotL64(aScatter, 56U)) + 11609181965078844357U;
            //
            aOrbiterI = ((aOrbiterI + aOrbiterJ) + 9628562297095374984U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 7850281529011259759U;
            aOrbiterA = RotL64((aOrbiterA * 17611485102925470357U), 13U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterA) + 257458718073794527U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 10693404545773519306U;
            aOrbiterK = RotL64((aOrbiterK * 14821443722828498323U), 23U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterE) + 3430519236533871460U;
            aOrbiterC = (aOrbiterC ^ aOrbiterG) ^ 6183054506953198055U;
            aOrbiterC = RotL64((aOrbiterC * 6121082743789970911U), 39U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 2905610989884221654U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterF) ^ 4472163910775333862U) ^ aPhaseFOrbiterUpdateSaltE[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 7770678426310856745U), 35U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 16870142883133769663U;
            aOrbiterH = (aOrbiterH ^ aOrbiterJ) ^ 1403692060594816451U;
            aOrbiterH = RotL64((aOrbiterH * 9740854430251597879U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterI) + 16904169913507057108U;
            aOrbiterB = (aOrbiterB ^ aOrbiterD) ^ 4773518591580333357U;
            aOrbiterB = RotL64((aOrbiterB * 5306070307776061267U), 27U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 6528141733853494275U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 11254806909313951442U) ^ aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 6316669786405548827U), 11U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterD) + 6857506858448143407U;
            aOrbiterE = (aOrbiterE ^ aOrbiterH) ^ 2855763534355983644U;
            aOrbiterE = RotL64((aOrbiterE * 16881334940165182415U), 3U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterH) + 12328391751024624740U) + aPhaseFOrbiterUpdateSaltB[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterG = (aOrbiterG ^ aOrbiterA) ^ 16475072086109949522U;
            aOrbiterG = RotL64((aOrbiterG * 15218626930666825883U), 57U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterF) + 15505670341076785424U;
            aOrbiterD = (aOrbiterD ^ aOrbiterC) ^ 6972128419331939330U;
            aOrbiterD = RotL64((aOrbiterD * 12206069109180246067U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 7151546362283646210U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterK) ^ 6024062041314952357U;
            aOrbiterJ = RotL64((aOrbiterJ * 10243806128059850493U), 47U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterD, 19U);
            aIngress = aIngress + (RotL64(aOrbiterF, 13U) ^ aOrbiterA);
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterK, 3U));
            aIngress = aIngress + (aOrbiterI ^ RotL64(aOrbiterH, 57U));
            aIngress = aIngress + (aOrbiterJ ^ RotL64(aOrbiterG, 24U));
            aIngress = aIngress + RotL64(aOrbiterE, 47U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererH = aWandererH ^ ((RotL64(aCross, 3U) + aOrbiterJ) + RotL64(aOrbiterH, 47U));
            aWandererD = aWandererD + ((RotL64(aIngress, 13U) + RotL64(aOrbiterF, 53U)) + aOrbiterC);
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 10U) + aOrbiterG) + RotL64(aOrbiterI, 19U));
            aWandererE = aWandererE + ((RotL64(aScatter, 35U) + aOrbiterE) + RotL64(aOrbiterI, 13U));
            aWandererI = aWandererI ^ ((RotL64(aPrevious, 27U) + RotL64(aOrbiterD, 51U)) + aOrbiterK);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterC) + RotL64(aOrbiterI, 58U)) + aPhaseFWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererF = aWandererF ^ ((RotL64(aIngress, 60U) + aOrbiterA) + RotL64(aOrbiterE, 3U));
            aWandererG = aWandererG + ((((RotL64(aScatter, 57U) + RotL64(aOrbiterD, 11U)) + aOrbiterC) + RotL64(aCarry, 21U)) + aPhaseFWandererUpdateSaltB[((aIndex + 16U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 51U) + aOrbiterB) + RotL64(aOrbiterG, 21U));
            aWandererJ = aWandererJ + (((RotL64(aIngress, 37U) + aOrbiterJ) + RotL64(aOrbiterI, 26U)) + RotL64(aCarry, 35U));
            aWandererK = aWandererK ^ ((RotL64(aCross, 21U) + aOrbiterD) + RotL64(aOrbiterG, 29U));
            //
            aCarry = aCarry + (aWandererF ^ RotL64(aWandererD, 30U));
            aCarry = aCarry + (RotL64(aWandererG, 27U) ^ aWandererB);
            aCarry = aCarry + (aWandererA ^ RotL64(aWandererE, 5U));
            aCarry = aCarry + (RotL64(aWandererJ, 39U) ^ aWandererH);
            aCarry = aCarry + (aWandererC ^ RotL64(aWandererI, 19U));
            aCarry = aCarry + RotL64(aWandererK, 53U);
            aCarry = aCarry + RotL64(aIngress, 10U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 28376U)) & S_BLOCK1], 12U) ^ RotL64(aWorkLaneA[((aIndex + 32122U)) & S_BLOCK1], 3U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 32399U)) & S_BLOCK1], 29U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 28636U)) & S_BLOCK1], 14U) ^ RotL64(aOperationLaneB[((aIndex + 27663U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCarry, 5U) + RotL64(aIngress, 35U)) + (RotL64(aPrevious, 56U) ^ RotL64(aCross, 23U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = (aWandererK + RotL64(aCross, 5U)) + 7896237440058555694U;
            aOrbiterH = (aWandererJ + RotL64(aPrevious, 27U)) + 11870529476037558635U;
            aOrbiterF = (aWandererI + RotL64(aScatter, 12U)) + 9158983227801569448U;
            aOrbiterA = (aWandererA + RotL64(aIngress, 35U)) + 4710172270996950329U;
            aOrbiterE = (aWandererD + RotL64(aScatter, 3U)) + 14634482800356647630U;
            aOrbiterG = (aWandererB + RotL64(aCross, 21U)) + 8822207952170610891U;
            aOrbiterI = ((aWandererF + RotL64(aIngress, 10U)) + RotL64(aCarry, 21U)) + 13755891414028982553U;
            aOrbiterD = (((aWandererG + RotL64(aPrevious, 37U)) + RotL64(aCarry, 3U)) + 4555293067488040719U) + aPhaseFOrbiterAssignSaltB[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterJ = ((aWandererC + RotL64(aCross, 53U)) + 2816805148093762081U) + aPhaseFOrbiterAssignSaltE[((aIndex + 6U)) & S_SALT1];
            aOrbiterB = (aWandererH + RotL64(aPrevious, 29U)) + 2122631477965135190U;
            aOrbiterK = ((aWandererE + RotL64(aScatter, 23U)) + RotL64(aCarry, 39U)) + 4592922416380416071U;
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 7102471666524164715U) + aPhaseFOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterC) ^ 17274623547879474204U;
            aOrbiterF = RotL64((aOrbiterF * 5443572270546181789U), 5U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterE) + 938587316977094680U;
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 18258015823797023523U;
            aOrbiterC = RotL64((aOrbiterC * 6068819567674605919U), 11U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 5809987756043471595U;
            aOrbiterI = (aOrbiterI ^ aOrbiterG) ^ 5083075160112581620U;
            aOrbiterI = RotL64((aOrbiterI * 3313957222154937503U), 43U);
            //
            aOrbiterD = (aOrbiterD + aOrbiterA) + 5960021727750946496U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterD) ^ 5967477320950630150U;
            aOrbiterJ = RotL64((aOrbiterJ * 330964768256424655U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterI) + 6578428711689296132U;
            aOrbiterD = (aOrbiterD ^ aOrbiterB) ^ 5601728218197771276U;
            aOrbiterD = RotL64((aOrbiterD * 9552559022315971847U), 29U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterG) + 7923809409017855241U;
            aOrbiterB = (aOrbiterB ^ aOrbiterH) ^ 16479366540906497019U;
            aOrbiterB = RotL64((aOrbiterB * 7118578387798460919U), 39U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterD) + 17000467091738009736U) + aPhaseFOrbiterUpdateSaltF[((aIndex + 13U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterK) ^ 6801634573655508028U;
            aOrbiterE = RotL64((aOrbiterE * 10584635770060137089U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterJ) + 123668445682719574U;
            aOrbiterH = (aOrbiterH ^ aOrbiterE) ^ 14462802805503986316U;
            aOrbiterH = RotL64((aOrbiterH * 12398236364304875941U), 51U);
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterC) + 2433338393261685871U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 13869012262404991729U) ^ aPhaseFOrbiterUpdateSaltE[((aIndex + 11U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 12443261517483942937U), 13U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterK) + 4832421585086516998U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 11284414949564414958U;
            aOrbiterA = RotL64((aOrbiterA * 1586650935440790991U), 23U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterB) + 17872556812561387030U) + aPhaseFOrbiterUpdateSaltA[((aIndex + 18U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterF) ^ 7896237440058555694U;
            aOrbiterK = RotL64((aOrbiterK * 16784165278693056013U), 41U);
            //
            aIngress = RotL64(aOrbiterI, 24U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterB ^ RotL64(aOrbiterJ, 35U));
            aIngress = aIngress + (RotL64(aOrbiterC, 5U) ^ aOrbiterA);
            aIngress = aIngress + (RotL64(aOrbiterD, 39U) ^ aOrbiterH);
            aIngress = aIngress + (aOrbiterE ^ RotL64(aOrbiterK, 57U));
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF + (((RotL64(aPrevious, 47U) + RotL64(aOrbiterF, 51U)) + aOrbiterD) + aPhaseFWandererUpdateSaltD[(((31U - aIndex) + 7U)) & S_SALT1]);
            aWandererG = aWandererG ^ ((RotL64(aCross, 37U) + RotL64(aOrbiterD, 19U)) + aOrbiterA);
            aWandererK = aWandererK + (((RotL64(aScatter, 39U) + aOrbiterH) + RotL64(aOrbiterE, 29U)) + aPhaseFWandererUpdateSaltA[(((31U - aIndex) + 20U)) & S_SALT1]);
            aWandererE = aWandererE ^ ((RotL64(aIngress, 43U) + aOrbiterA) + RotL64(aOrbiterH, 58U));
            aWandererC = aWandererC + (((RotL64(aCross, 6U) + RotL64(aOrbiterK, 23U)) + aOrbiterI) + RotL64(aCarry, 29U));
            aWandererI = aWandererI ^ ((RotL64(aScatter, 11U) + RotL64(aOrbiterG, 13U)) + aOrbiterK);
            aWandererB = aWandererB + (((RotL64(aIngress, 19U) + RotL64(aOrbiterI, 39U)) + aOrbiterJ) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 53U) + aOrbiterC) + RotL64(aOrbiterI, 11U));
            aWandererA = aWandererA + ((RotL64(aScatter, 56U) + aOrbiterG) + RotL64(aOrbiterI, 27U));
            aWandererD = aWandererD ^ ((RotL64(aPrevious, 35U) + RotL64(aOrbiterC, 5U)) + aOrbiterF);
            aWandererJ = aWandererJ + ((RotL64(aCross, 29U) + aOrbiterB) + RotL64(aOrbiterC, 42U));
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererF, 39U));
            aCarry = aCarry + (RotL64(aWandererE, 3U) ^ aWandererH);
            aCarry = aCarry + (RotL64(aWandererG, 19U) ^ aWandererA);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 44U));
            aCarry = aCarry + (RotL64(aWandererB, 57U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 37U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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

void TwistExpander_Lacrosse_Arx::GROW_A(TwistWorkSpace *pWorkSpace,
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

    std::uint64_t aOrbiterA = 0; std::uint64_t aOrbiterB = 0; std::uint64_t aOrbiterC = 0; std::uint64_t aOrbiterF = 0;
    std::uint64_t aOrbiterG = 0; std::uint64_t aOrbiterI = 0; std::uint64_t aOrbiterJ = 0; std::uint64_t aOrbiterK = 0;

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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 767U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 4589U)) & S_BLOCK1], 29U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 8107U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 5749U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 1391U)) & S_BLOCK1], 35U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 2889U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aCarry, 6U) + RotL64(aPrevious, 57U)) ^ (RotL64(aCross, 19U) + RotL64(aIngress, 35U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterJ = ((aWandererD + RotL64(aIngress, 11U)) + RotL64(aCarry, 23U)) + 6733949564325516029U;
            aOrbiterA = ((aWandererC + RotL64(aCross, 57U)) + RotL64(aCarry, 57U)) + 7304098437143918796U;
            aOrbiterG = (aWandererF + RotL64(aPrevious, 43U)) + 3923949518391777800U;
            aOrbiterF = ((aWandererJ + RotL64(aScatter, 34U)) + 14243591003388927124U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterK = (((aWandererK + RotL64(aPrevious, 21U)) + RotL64(aCarry, 41U)) + 18329498724605410406U) + aPhaseGOrbiterAssignSaltB[((aIndex + 16U)) & S_SALT1];
            //
            aOrbiterJ = (aOrbiterJ + aOrbiterA) + 13118172167747037249U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 5272025143849174212U) ^ aPhaseGOrbiterUpdateSaltA[((aIndex + 27U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 9935990954321437743U), 29U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterF) + 16075917179214318424U;
            aOrbiterK = (aOrbiterK ^ aOrbiterG) ^ 15263590648674658399U;
            aOrbiterK = RotL64((aOrbiterK * 9918239923411740337U), 41U);
            //
            aOrbiterA = (aOrbiterA + aOrbiterG) + 13730046728289525921U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterA) ^ 7703141464499623408U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 8U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5886009900621521987U), 13U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterJ) + 1382279753822135359U) + aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterA = (aOrbiterA ^ aOrbiterK) ^ 2973369221699098292U;
            aOrbiterA = RotL64((aOrbiterA * 7440242040663550631U), 21U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 11578274119583013219U;
            aOrbiterJ = ((aOrbiterJ ^ aOrbiterF) ^ 3419411247737896674U) ^ aPhaseGOrbiterUpdateSaltE[((aIndex + 4U)) & S_SALT1];
            aOrbiterJ = RotL64((aOrbiterJ * 17814942652262802991U), 57U);
            //
            aIngress = RotL64(aOrbiterK, 13U) ^ aOrbiterJ;
            aIngress = aIngress + (aOrbiterG ^ RotL64(aOrbiterF, 41U));
            aIngress = aIngress + RotL64(aOrbiterA, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererK = aWandererK + ((((RotL64(aScatter, 53U) + RotL64(aOrbiterF, 5U)) + aOrbiterJ) + RotL64(aCarry, 51U)) + aPhaseGWandererUpdateSaltF[(((31U - aIndex) + 21U)) & S_SALT1]);
            aWandererC = aWandererC ^ ((RotL64(aPrevious, 11U) + RotL64(aOrbiterK, 39U)) + aOrbiterF);
            aWandererD = aWandererD + (((RotL64(aIngress, 29U) + RotL64(aOrbiterA, 57U)) + aOrbiterK) + RotL64(aCarry, 39U));
            aWandererF = aWandererF ^ ((RotL64(aCross, 21U) + aOrbiterG) + RotL64(aOrbiterK, 20U));
            aWandererJ = aWandererJ + (((RotL64(aPrevious, 42U) + RotL64(aOrbiterA, 47U)) + aOrbiterF) + aPhaseGWandererUpdateSaltB[(((31U - aIndex) + 15U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererJ ^ RotL64(aWandererD, 58U));
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererF);
            aCarry = aCarry + RotL64(aWandererK, 29U);
            aCarry = aCarry + RotL64(aIngress, 39U);
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 11428U)) & S_BLOCK1], 47U) ^ RotL64(aWorkLaneB[((aIndex + 15023U)) & S_BLOCK1], 14U));
            aIngress ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 13613U)) & S_BLOCK1], 35U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 13363U)) & S_BLOCK1], 21U) ^ RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 11947U)) & S_BLOCK1], 57U));
            aCross ^= RotL64(aWorkLaneD[((aIndex + 8487U)) & S_BLOCK1], 34U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCross, 5U)) + (RotL64(aCarry, 22U) + RotL64(aPrevious, 43U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterA = ((aWandererC + RotL64(aIngress, 57U)) + RotL64(aCarry, 11U)) + 4384716820085860551U;
            aOrbiterG = (((aWandererD + RotL64(aCross, 47U)) + RotL64(aCarry, 29U)) + 9715780315942116888U) + aPhaseGOrbiterAssignSaltA[(((31U - aIndex) + 29U)) & S_SALT1];
            aOrbiterC = (aWandererA + RotL64(aScatter, 13U)) + 15963520052789178632U;
            aOrbiterK = (((aWandererG + RotL64(aPrevious, 22U)) + RotL64(aCarry, 41U)) + 14346700690686392938U) + aPhaseGOrbiterAssignSaltE[(((31U - aIndex) + 25U)) & S_SALT1];
            aOrbiterI = (aWandererI + RotL64(aScatter, 39U)) + 6005518012489966643U;
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 2506732930310252119U) + aPhaseGOrbiterUpdateSaltD[((aIndex + 10U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterA) ^ 16782163084851775826U;
            aOrbiterC = RotL64((aOrbiterC * 1527050617428162663U), 13U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterC) + 823673076571076303U;
            aOrbiterA = ((aOrbiterA ^ aOrbiterK) ^ 1634084509064077736U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterA = RotL64((aOrbiterA * 1128407326773234517U), 5U);
            //
            aOrbiterI = ((aOrbiterI + aOrbiterA) + 1288134975466877686U) + aPhaseGOrbiterUpdateSaltB[((aIndex + 19U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterI) ^ 2998220403162908444U;
            aOrbiterK = RotL64((aOrbiterK * 4321412662318298283U), 35U);
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 220430672180734911U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 10223923547068528867U) ^ aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 26U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 12577370238343872139U), 51U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterI) + 11696469696177647608U;
            aOrbiterG = (aOrbiterG ^ aOrbiterC) ^ 6545430420379636963U;
            aOrbiterG = RotL64((aOrbiterG * 8387163146257553773U), 23U);
            //
            aIngress = aOrbiterA ^ RotL64(aOrbiterI, 30U);
            aIngress = aIngress + (aOrbiterC ^ RotL64(aOrbiterG, 3U));
            aIngress = aIngress + RotL64(aOrbiterK, 13U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ (((RotL64(aIngress, 29U) + aOrbiterC) + RotL64(aOrbiterI, 46U)) + aPhaseGWandererUpdateSaltE[((aIndex + 22U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 19U) + aOrbiterK) + RotL64(aOrbiterG, 57U)) + RotL64(aCarry, 5U));
            aWandererD = aWandererD ^ (((RotL64(aScatter, 3U) + RotL64(aOrbiterI, 11U)) + aOrbiterK) + aPhaseGWandererUpdateSaltA[(((31U - aIndex) + 12U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 41U) + aOrbiterA) + RotL64(aOrbiterG, 35U)) + RotL64(aCarry, 35U));
            aWandererG = aWandererG ^ ((RotL64(aIngress, 54U) + RotL64(aOrbiterK, 3U)) + aOrbiterC);
            //
            aCarry = aCarry + (RotL64(aWandererC, 3U) ^ aWandererG);
            aCarry = aCarry + (RotL64(aWandererI, 36U) ^ aWandererA);
            aCarry = aCarry + RotL64(aWandererD, 47U);
            aCarry = aCarry + RotL64(aIngress, 57U);
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
            aIngress = (RotL64(aExpandLaneB[((aIndex + 24047U)) & S_BLOCK1], 27U) ^ RotL64(aExpandLaneA[((aIndex + 16806U)) & S_BLOCK1], 18U));
            aIngress ^= RotL64(aWorkLaneD[((aIndex + 23742U)) & S_BLOCK1], 41U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 17807U)) & S_BLOCK1], 60U) ^ RotL64(aWorkLaneD[((S_BLOCK1 - aIndex + 20773U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 16669U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 43U) ^ RotL64(aCarry, 6U)) + (RotL64(aPrevious, 23U) ^ RotL64(aCross, 57U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterG = ((aWandererI + RotL64(aIngress, 58U)) + RotL64(aCarry, 51U)) + 12426357877879529292U;
            aOrbiterK = ((aWandererA + RotL64(aCross, 29U)) + RotL64(aCarry, 39U)) + 12604900366173639176U;
            aOrbiterI = ((aWandererC + RotL64(aScatter, 3U)) + 13511119007338929401U) + aPhaseGOrbiterAssignSaltC[(((31U - aIndex) + 11U)) & S_SALT1];
            aOrbiterC = (((aWandererD + RotL64(aPrevious, 13U)) + RotL64(aCarry, 13U)) + 9878720081166788060U) + aPhaseGOrbiterAssignSaltD[(((31U - aIndex) + 20U)) & S_SALT1];
            aOrbiterA = (aWandererK + RotL64(aScatter, 39U)) + 15463195409806395076U;
            //
            aOrbiterG = (aOrbiterG + aOrbiterK) + 6407922778852833423U;
            aOrbiterI = ((aOrbiterI ^ aOrbiterG) ^ 7690427254160734016U) ^ aPhaseGOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterI = RotL64((aOrbiterI * 11841396512731990295U), 3U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterI) + 18030974031722143619U;
            aOrbiterC = (aOrbiterC ^ aOrbiterK) ^ 17983938038322737041U;
            aOrbiterC = RotL64((aOrbiterC * 12479365337221685413U), 43U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterG) + 16605512170117753884U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 9U)) & S_SALT1];
            aOrbiterK = ((aOrbiterK ^ aOrbiterA) ^ 681802273302348322U) ^ aPhaseGOrbiterUpdateSaltF[((aIndex + 29U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 14608920184802647123U), 13U);
            //
            aOrbiterC = (aOrbiterC + aOrbiterA) + 15550312921312083819U;
            aOrbiterG = ((aOrbiterG ^ aOrbiterC) ^ 17824154101711884508U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 21U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 7358612830654795357U), 29U);
            //
            aOrbiterI = (aOrbiterI + aOrbiterC) + 1939207786756735430U;
            aOrbiterA = (aOrbiterA ^ aOrbiterI) ^ 3132864634777826569U;
            aOrbiterA = RotL64((aOrbiterA * 13606281919426730325U), 57U);
            //
            aIngress = aOrbiterK ^ RotL64(aOrbiterC, 57U);
            aIngress = aIngress + (RotL64(aOrbiterI, 36U) ^ aOrbiterA);
            aIngress = aIngress + RotL64(aOrbiterG, 47U);
            aIngress = TwistMix64::DiffuseB((aIngress + aScatter));
            //
            aWandererA = aWandererA ^ ((RotL64(aPrevious, 51U) + aOrbiterK) + RotL64(aOrbiterI, 3U));
            aWandererD = aWandererD + (((RotL64(aScatter, 21U) + RotL64(aOrbiterK, 41U)) + aOrbiterC) + RotL64(aCarry, 19U));
            aWandererI = aWandererI ^ ((RotL64(aCross, 13U) + RotL64(aOrbiterA, 27U)) + aOrbiterG);
            aWandererK = aWandererK + ((((RotL64(aIngress, 29U) + aOrbiterG) + RotL64(aOrbiterK, 54U)) + RotL64(aCarry, 41U)) + aPhaseGWandererUpdateSaltC[((aIndex + 3U)) & S_SALT1]);
            aWandererC = aWandererC ^ (((RotL64(aScatter, 4U) + aOrbiterC) + RotL64(aOrbiterA, 19U)) + aPhaseGWandererUpdateSaltD[((aIndex + 6U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererK, 3U));
            aCarry = aCarry + (RotL64(aWandererA, 39U) ^ aWandererD);
            aCarry = aCarry + RotL64(aWandererC, 21U);
            aCarry = aCarry + RotL64(aIngress, 11U);
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
            aIngress = (RotL64(aExpandLaneC[((aIndex + 26536U)) & S_BLOCK1], 30U) ^ RotL64(aExpandLaneB[((aIndex + 26637U)) & S_BLOCK1], 47U));
            aIngress ^= RotL64(aExpandLaneA[((aIndex + 30227U)) & S_BLOCK1], 3U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneA[((S_BLOCK1 - aIndex + 25371U)) & S_BLOCK1], 11U) ^ RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 31710U)) & S_BLOCK1], 29U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 31400U)) & S_BLOCK1], 38U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aCross, 35U) ^ RotL64(aPrevious, 5U)) + (RotL64(aCarry, 20U) + RotL64(aIngress, 51U));
            aScatter = TwistMix64::DiffuseB(aScatter);
            //
            aOrbiterG = (((aWandererJ + RotL64(aIngress, 13U)) + RotL64(aCarry, 13U)) + 1952750591494698524U) + aPhaseGOrbiterAssignSaltF[(((31U - aIndex) + 9U)) & S_SALT1];
            aOrbiterB = ((aWandererI + RotL64(aCross, 43U)) + RotL64(aCarry, 27U)) + 4488270851303332830U;
            aOrbiterC = (aWandererC + RotL64(aPrevious, 4U)) + 2738763375328927635U;
            aOrbiterJ = ((aWandererH + RotL64(aScatter, 35U)) + RotL64(aCarry, 47U)) + 6728843649480454340U;
            aOrbiterK = ((aWandererG + RotL64(aIngress, 23U)) + 10490717875258865358U) + aPhaseGOrbiterAssignSaltB[((aIndex + 26U)) & S_SALT1];
            //
            aOrbiterG = (aOrbiterG + aOrbiterB) + 1429288737812910205U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterG) ^ 2761375016998907636U) ^ aPhaseGOrbiterUpdateSaltC[(((31U - aIndex) + 4U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 16589197409983023283U), 19U);
            //
            aOrbiterJ = ((aOrbiterJ + aOrbiterK) + 1088988605204499835U) + aPhaseGOrbiterUpdateSaltF[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterG = ((aOrbiterG ^ aOrbiterJ) ^ 6829840407300289709U) ^ aPhaseGOrbiterUpdateSaltE[(((31U - aIndex) + 7U)) & S_SALT1];
            aOrbiterG = RotL64((aOrbiterG * 13101432880030791787U), 43U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 9267240337867690471U;
            aOrbiterB = (aOrbiterB ^ aOrbiterK) ^ 8120113021183975703U;
            aOrbiterB = RotL64((aOrbiterB * 14296504593187173107U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterJ) + 1340980511302566784U) + aPhaseGOrbiterUpdateSaltA[((aIndex + 6U)) & S_SALT1];
            aOrbiterK = (aOrbiterK ^ aOrbiterC) ^ 11874452169979878835U;
            aOrbiterK = RotL64((aOrbiterK * 8638486178860092537U), 35U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterC) + 1872314794140971426U;
            aOrbiterJ = (aOrbiterJ ^ aOrbiterB) ^ 6013952618696225751U;
            aOrbiterJ = RotL64((aOrbiterJ * 7994863587373565715U), 11U);
            //
            aIngress = RotL64(aOrbiterC, 57U) ^ aOrbiterK;
            aIngress = aIngress + (RotL64(aOrbiterB, 24U) ^ aOrbiterG);
            aIngress = aIngress + RotL64(aOrbiterJ, 39U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererG = aWandererG + (((RotL64(aPrevious, 23U) + aOrbiterG) + RotL64(aOrbiterJ, 11U)) + RotL64(aCarry, 37U));
            aWandererJ = aWandererJ ^ ((RotL64(aIngress, 14U) + aOrbiterJ) + RotL64(aOrbiterC, 56U));
            aWandererH = aWandererH + (((RotL64(aScatter, 3U) + RotL64(aOrbiterG, 41U)) + aOrbiterB) + RotL64(aCarry, 51U));
            aWandererC = aWandererC ^ (((RotL64(aCross, 57U) + RotL64(aOrbiterK, 19U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltB[((aIndex + 23U)) & S_SALT1]);
            aWandererI = aWandererI + (((RotL64(aPrevious, 39U) + RotL64(aOrbiterB, 27U)) + aOrbiterJ) + aPhaseGWandererUpdateSaltF[((aIndex + 3U)) & S_SALT1]);
            //
            aCarry = aCarry + (RotL64(aWandererC, 53U) ^ aWandererI);
            aCarry = aCarry + (RotL64(aWandererG, 13U) ^ aWandererH);
            aCarry = aCarry + RotL64(aWandererJ, 21U);
            aCarry = aCarry + RotL64(aIngress, 44U);
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

void TwistExpander_Lacrosse_Arx::GROW_B(TwistWorkSpace *pWorkSpace,
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
            aIngress = (RotL64(aExpandLaneA[((aIndex + 1970U)) & S_BLOCK1], 14U) ^ RotL64(aExpandLaneB[((aIndex + 1688U)) & S_BLOCK1], 57U));
            aIngress ^= RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 3902U)) & S_BLOCK1], 39U);
            aIngress = TwistMix64::DiffuseC(aIngress);
            //
            aCross = (RotL64(aExpandLaneB[((S_BLOCK1 - aIndex + 6122U)) & S_BLOCK1], 23U) ^ RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 1032U)) & S_BLOCK1], 34U));
            aCross ^= RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 3036U)) & S_BLOCK1], 51U);
            aCross = TwistMix64::DiffuseB(aCross);
            //
            aScatter = (RotL64(aPrevious, 27U) + RotL64(aCarry, 51U)) ^ (RotL64(aCross, 39U) ^ RotL64(aIngress, 10U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterC = ((aWandererC + RotL64(aCross, 23U)) + RotL64(aCarry, 23U)) + 7632760812370906911U;
            aOrbiterB = ((aWandererH + RotL64(aIngress, 13U)) + RotL64(aCarry, 11U)) + 6007174525479723089U;
            aOrbiterE = ((aWandererG + RotL64(aScatter, 5U)) + RotL64(aCarry, 53U)) + 3362829642521821048U;
            aOrbiterF = ((aWandererI + RotL64(aPrevious, 41U)) + 18009548556107978286U) + aPhaseHOrbiterAssignSaltF[((aIndex + 21U)) & S_SALT1];
            aOrbiterK = ((aWandererA + RotL64(aIngress, 50U)) + 17880909432272697327U) + aPhaseHOrbiterAssignSaltA[((aIndex + 22U)) & S_SALT1];
            //
            aOrbiterC = (aOrbiterC + aOrbiterB) + 15961567935420752568U;
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 10136559064656837921U;
            aOrbiterE = RotL64((aOrbiterE * 14473810261421912849U), 57U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterC) + 17622019364405410277U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 17U)) & S_SALT1];
            aOrbiterB = (aOrbiterB ^ aOrbiterF) ^ 6927494824421416306U;
            aOrbiterB = RotL64((aOrbiterB * 2686290883767829973U), 47U);
            //
            aOrbiterK = ((aOrbiterK + aOrbiterF) + 7125170407794874847U) + aPhaseHOrbiterUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1];
            aOrbiterC = ((aOrbiterC ^ aOrbiterK) ^ 12342273503071032250U) ^ aPhaseHOrbiterUpdateSaltF[(((31U - aIndex) + 28U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 867417849555857179U), 37U);
            //
            aOrbiterB = (aOrbiterB + aOrbiterE) + 14997696377476124836U;
            aOrbiterK = (aOrbiterK ^ aOrbiterB) ^ 14874498694181230698U;
            aOrbiterK = RotL64((aOrbiterK * 4026127545746010937U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterK) + 2549397729130885686U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterE) ^ 4217995818662767955U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 3U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 5525525344485251063U), 3U);
            //
            aIngress = aOrbiterC ^ RotL64(aOrbiterE, 29U);
            aIngress = aIngress + (RotL64(aOrbiterF, 41U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterB, 53U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererC = aWandererC ^ ((RotL64(aIngress, 3U) + aOrbiterC) + RotL64(aOrbiterK, 27U));
            aWandererA = aWandererA + ((((RotL64(aScatter, 14U) + aOrbiterE) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 5U)) + aPhaseHWandererUpdateSaltE[(((31U - aIndex) + 8U)) & S_SALT1]);
            aWandererI = aWandererI ^ (((RotL64(aCross, 27U) + RotL64(aOrbiterF, 37U)) + aOrbiterB) + aPhaseHWandererUpdateSaltC[((aIndex + 6U)) & S_SALT1]);
            aWandererG = aWandererG + (((RotL64(aPrevious, 37U) + RotL64(aOrbiterF, 51U)) + aOrbiterE) + RotL64(aCarry, 41U));
            aWandererH = aWandererH ^ ((RotL64(aCross, 53U) + RotL64(aOrbiterC, 60U)) + aOrbiterB);
            //
            aCarry = aCarry + (RotL64(aWandererG, 23U) ^ aWandererA);
            aCarry = aCarry + (RotL64(aWandererH, 13U) ^ aWandererI);
            aCarry = aCarry + RotL64(aWandererC, 57U);
            aCarry = aCarry + RotL64(aIngress, 34U);
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
            aIngress = (RotL64(aWorkLaneA[((aIndex + 14403U)) & S_BLOCK1], 6U) ^ RotL64(aExpandLaneB[((aIndex + 16103U)) & S_BLOCK1], 27U));
            aIngress ^= RotL64(aExpandLaneC[((aIndex + 11758U)) & S_BLOCK1], 43U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aExpandLaneC[((S_BLOCK1 - aIndex + 12349U)) & S_BLOCK1], 35U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 8353U)) & S_BLOCK1], 14U));
            aCross ^= RotL64(aWorkLaneA[((aIndex + 15523U)) & S_BLOCK1], 47U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aCross, 51U) ^ RotL64(aIngress, 19U)) ^ (RotL64(aCarry, 6U) + RotL64(aPrevious, 37U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterB = ((aWandererI + RotL64(aCross, 29U)) + 5906639480605353429U) + aPhaseHOrbiterAssignSaltE[(((31U - aIndex) + 18U)) & S_SALT1];
            aOrbiterF = ((aWandererK + RotL64(aScatter, 57U)) + RotL64(aCarry, 3U)) + 5293518570213287605U;
            aOrbiterH = ((aWandererG + RotL64(aPrevious, 11U)) + 15383185501428521377U) + aPhaseHOrbiterAssignSaltD[((aIndex + 3U)) & S_SALT1];
            aOrbiterE = ((aWandererE + RotL64(aIngress, 38U)) + RotL64(aCarry, 53U)) + 15364072512743978902U;
            aOrbiterC = ((aWandererH + RotL64(aCross, 19U)) + RotL64(aCarry, 41U)) + 4525473357144014271U;
            //
            aOrbiterB = (aOrbiterB + aOrbiterF) + 10400911938125603074U;
            aOrbiterH = (aOrbiterH ^ aOrbiterB) ^ 16417506293824627550U;
            aOrbiterH = RotL64((aOrbiterH * 8303380456072515611U), 41U);
            //
            aOrbiterH = (aOrbiterH + aOrbiterE) + 2419329331753341815U;
            aOrbiterF = ((aOrbiterF ^ aOrbiterH) ^ 14929222427923332069U) ^ aPhaseHOrbiterUpdateSaltE[((aIndex + 17U)) & S_SALT1];
            aOrbiterF = RotL64((aOrbiterF * 11596261802662514979U), 27U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterC) + 16771573504983922586U;
            aOrbiterE = (aOrbiterE ^ aOrbiterF) ^ 1863466450051787622U;
            aOrbiterE = RotL64((aOrbiterE * 2585626547126027053U), 57U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterH) + 12895350137096692415U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 11U)) & S_SALT1];
            aOrbiterB = ((aOrbiterB ^ aOrbiterC) ^ 3700979086526298327U) ^ aPhaseHOrbiterUpdateSaltB[((aIndex + 13U)) & S_SALT1];
            aOrbiterB = RotL64((aOrbiterB * 10279730254867618193U), 19U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterB) + 1977099106211282426U;
            aOrbiterC = ((aOrbiterC ^ aOrbiterE) ^ 6144698304096915742U) ^ aPhaseHOrbiterUpdateSaltA[(((31U - aIndex) + 22U)) & S_SALT1];
            aOrbiterC = RotL64((aOrbiterC * 5039822990560519609U), 3U);
            //
            aIngress = aOrbiterH ^ RotL64(aOrbiterE, 35U);
            aIngress = aIngress + (aOrbiterF ^ RotL64(aOrbiterB, 46U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseC((aIngress + aScatter));
            //
            aWandererE = aWandererE + ((((RotL64(aPrevious, 39U) + aOrbiterE) + RotL64(aOrbiterH, 23U)) + RotL64(aCarry, 3U)) + aPhaseHWandererUpdateSaltB[((aIndex + 25U)) & S_SALT1]);
            aWandererH = aWandererH ^ ((RotL64(aScatter, 13U) + aOrbiterB) + RotL64(aOrbiterF, 47U));
            aWandererK = aWandererK + ((RotL64(aCross, 21U) + aOrbiterH) + RotL64(aOrbiterC, 5U));
            aWandererI = aWandererI ^ ((RotL64(aIngress, 57U) + aOrbiterF) + RotL64(aOrbiterC, 60U));
            aWandererG = aWandererG + ((((RotL64(aCross, 48U) + aOrbiterE) + RotL64(aOrbiterB, 39U)) + RotL64(aCarry, 21U)) + aPhaseHWandererUpdateSaltD[(((31U - aIndex) + 12U)) & S_SALT1]);
            //
            aCarry = aCarry + (aWandererK ^ RotL64(aWandererG, 44U));
            aCarry = aCarry + (RotL64(aWandererH, 3U) ^ aWandererE);
            aCarry = aCarry + RotL64(aWandererI, 13U);
            aCarry = aCarry + RotL64(aIngress, 53U);
            aCarry = TwistMix64::DiffuseB(aCarry);
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
            aIngress = (RotL64(aWorkLaneB[((aIndex + 18005U)) & S_BLOCK1], 51U) ^ RotL64(aWorkLaneA[((aIndex + 16397U)) & S_BLOCK1], 13U));
            aIngress ^= RotL64(aExpandLaneD[((aIndex + 21949U)) & S_BLOCK1], 4U);
            aIngress = TwistMix64::DiffuseB(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 21959U)) & S_BLOCK1], 57U) ^ RotL64(aExpandLaneD[((S_BLOCK1 - aIndex + 21804U)) & S_BLOCK1], 27U));
            aCross ^= RotL64(aExpandLaneC[((aIndex + 16583U)) & S_BLOCK1], 46U);
            aCross = TwistMix64::DiffuseA(aCross);
            //
            aScatter = (RotL64(aIngress, 57U) ^ RotL64(aCarry, 40U)) + (RotL64(aCross, 27U) + RotL64(aPrevious, 5U));
            aScatter = TwistMix64::DiffuseA(aScatter);
            //
            aOrbiterD = (((aWandererJ + RotL64(aScatter, 58U)) + RotL64(aCarry, 53U)) + 7651355040951791298U) + aPhaseHOrbiterAssignSaltC[((aIndex + 17U)) & S_SALT1];
            aOrbiterA = (aWandererE + RotL64(aCross, 47U)) + 13988210277931659312U;
            aOrbiterC = ((aWandererI + RotL64(aPrevious, 37U)) + RotL64(aCarry, 11U)) + 9846849412579537783U;
            aOrbiterF = (((aWandererB + RotL64(aIngress, 21U)) + RotL64(aCarry, 39U)) + 12746719939495876158U) + aPhaseHOrbiterAssignSaltB[(((31U - aIndex) + 14U)) & S_SALT1];
            aOrbiterE = (aWandererD + RotL64(aCross, 11U)) + 11498066185182895284U;
            //
            aOrbiterD = ((aOrbiterD + aOrbiterA) + 11101058955193080232U) + aPhaseHOrbiterUpdateSaltA[((aIndex + 16U)) & S_SALT1];
            aOrbiterC = (aOrbiterC ^ aOrbiterD) ^ 15513734459555672046U;
            aOrbiterC = RotL64((aOrbiterC * 6974281215677538561U), 21U);
            //
            aOrbiterA = ((aOrbiterA + aOrbiterC) + 15711108675349394643U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 23U)) & S_SALT1];
            aOrbiterF = (aOrbiterF ^ aOrbiterA) ^ 4771231759949468556U;
            aOrbiterF = RotL64((aOrbiterF * 9806191054594333615U), 53U);
            //
            aOrbiterC = ((aOrbiterC + aOrbiterF) + 11449258010811305256U) + aPhaseHOrbiterUpdateSaltC[((aIndex + 27U)) & S_SALT1];
            aOrbiterE = (aOrbiterE ^ aOrbiterC) ^ 17036938391509986723U;
            aOrbiterE = RotL64((aOrbiterE * 7411466953205347639U), 3U);
            //
            aOrbiterF = ((aOrbiterF + aOrbiterE) + 6999245666776654250U) + aPhaseHOrbiterUpdateSaltD[((aIndex + 6U)) & S_SALT1];
            aOrbiterD = (aOrbiterD ^ aOrbiterF) ^ 2106819066263369528U;
            aOrbiterD = RotL64((aOrbiterD * 13005885810757743129U), 11U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterD) + 12716183358903477216U;
            aOrbiterA = (aOrbiterA ^ aOrbiterE) ^ 16752724547046059889U;
            aOrbiterA = RotL64((aOrbiterA * 11475905692393034141U), 43U);
            //
            aIngress = RotL64(aOrbiterE, 5U) ^ aOrbiterF;
            aIngress = aIngress + (aOrbiterA ^ RotL64(aOrbiterD, 51U));
            aIngress = aIngress + RotL64(aOrbiterC, 19U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererJ = aWandererJ + ((((RotL64(aIngress, 56U) + aOrbiterD) + RotL64(aOrbiterE, 57U)) + RotL64(aCarry, 57U)) + aPhaseHWandererUpdateSaltA[((aIndex + 13U)) & S_SALT1]);
            aWandererB = aWandererB ^ ((RotL64(aPrevious, 19U) + RotL64(aOrbiterF, 3U)) + aOrbiterA);
            aWandererI = aWandererI + (((RotL64(aScatter, 37U) + RotL64(aOrbiterE, 42U)) + aOrbiterF) + aPhaseHWandererUpdateSaltF[(((31U - aIndex) + 18U)) & S_SALT1]);
            aWandererD = aWandererD ^ ((RotL64(aCross, 47U) + aOrbiterF) + RotL64(aOrbiterC, 23U));
            aWandererE = aWandererE + (((RotL64(aPrevious, 5U) + aOrbiterA) + RotL64(aOrbiterC, 11U)) + RotL64(aCarry, 13U));
            //
            aCarry = aCarry + (RotL64(aWandererD, 56U) ^ aWandererE);
            aCarry = aCarry + (aWandererI ^ RotL64(aWandererB, 19U));
            aCarry = aCarry + RotL64(aWandererJ, 35U);
            aCarry = aCarry + RotL64(aIngress, 3U);
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
            aIngress = (RotL64(aWorkLaneC[((aIndex + 32365U)) & S_BLOCK1], 52U) ^ RotL64(aWorkLaneB[((aIndex + 28259U)) & S_BLOCK1], 39U));
            aIngress ^= RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 29692U)) & S_BLOCK1], 13U);
            aIngress = TwistMix64::DiffuseA(aIngress);
            //
            aCross = (RotL64(aWorkLaneA[((S_BLOCK1 - aIndex + 27046U)) & S_BLOCK1], 44U) ^ RotL64(aWorkLaneB[((S_BLOCK1 - aIndex + 30458U)) & S_BLOCK1], 53U));
            aCross ^= RotL64(aWorkLaneC[((S_BLOCK1 - aIndex + 29098U)) & S_BLOCK1], 23U);
            aCross = TwistMix64::DiffuseC(aCross);
            //
            aScatter = (RotL64(aPrevious, 19U) ^ RotL64(aCross, 35U)) + (RotL64(aCarry, 53U) ^ RotL64(aIngress, 4U));
            aScatter = TwistMix64::DiffuseC(aScatter);
            //
            aOrbiterD = (aWandererD + RotL64(aPrevious, 19U)) + 16189787374324972735U;
            aOrbiterE = ((aWandererG + RotL64(aIngress, 47U)) + RotL64(aCarry, 47U)) + 17563763730956242224U;
            aOrbiterF = (aWandererC + RotL64(aCross, 28U)) + 10572803498593789385U;
            aOrbiterK = (((aWandererF + RotL64(aScatter, 11U)) + RotL64(aCarry, 13U)) + 7713105232072974166U) + aPhaseHOrbiterAssignSaltF[((aIndex + 8U)) & S_SALT1];
            aOrbiterG = (((aWandererH + RotL64(aPrevious, 39U)) + RotL64(aCarry, 29U)) + 10760839534772718139U) + aPhaseHOrbiterAssignSaltA[((aIndex + 17U)) & S_SALT1];
            //
            aOrbiterD = (aOrbiterD + aOrbiterE) + 13397069448391230253U;
            aOrbiterF = (aOrbiterF ^ aOrbiterD) ^ 4569255679998375682U;
            aOrbiterF = RotL64((aOrbiterF * 15163488708398248639U), 29U);
            //
            aOrbiterF = (aOrbiterF + aOrbiterK) + 9888769350817876949U;
            aOrbiterG = (aOrbiterG ^ aOrbiterF) ^ 11351796060878856300U;
            aOrbiterG = RotL64((aOrbiterG * 13356749147334008399U), 3U);
            //
            aOrbiterE = (aOrbiterE + aOrbiterF) + 18153775071965707204U;
            aOrbiterK = ((aOrbiterK ^ aOrbiterE) ^ 1282846411145853435U) ^ aPhaseHOrbiterUpdateSaltD[(((31U - aIndex) + 5U)) & S_SALT1];
            aOrbiterK = RotL64((aOrbiterK * 12294455920906257823U), 11U);
            //
            aOrbiterG = ((aOrbiterG + aOrbiterD) + 16457743979262460660U) + aPhaseHOrbiterUpdateSaltB[(((31U - aIndex) + 13U)) & S_SALT1];
            aOrbiterE = ((aOrbiterE ^ aOrbiterG) ^ 173493260775251032U) ^ aPhaseHOrbiterUpdateSaltA[((aIndex + 28U)) & S_SALT1];
            aOrbiterE = RotL64((aOrbiterE * 4935807229040883505U), 41U);
            //
            aOrbiterK = (aOrbiterK + aOrbiterG) + 3927345926316409630U;
            aOrbiterD = ((aOrbiterD ^ aOrbiterK) ^ 5158769729850853623U) ^ aPhaseHOrbiterUpdateSaltF[((aIndex + 15U)) & S_SALT1];
            aOrbiterD = RotL64((aOrbiterD * 2446452358663812945U), 19U);
            //
            aIngress = RotL64(aOrbiterE, 13U) ^ aOrbiterG;
            aIngress = aIngress + (RotL64(aOrbiterF, 38U) ^ aOrbiterK);
            aIngress = aIngress + RotL64(aOrbiterD, 3U);
            aIngress = TwistMix64::DiffuseA((aIngress + aScatter));
            //
            aWandererF = aWandererF ^ (((RotL64(aScatter, 5U) + RotL64(aOrbiterK, 3U)) + aOrbiterG) + aPhaseHWandererUpdateSaltE[((aIndex + 21U)) & S_SALT1]);
            aWandererC = aWandererC + (((RotL64(aCross, 27U) + aOrbiterF) + RotL64(aOrbiterK, 11U)) + RotL64(aCarry, 19U));
            aWandererG = aWandererG ^ (((RotL64(aPrevious, 43U) + RotL64(aOrbiterF, 54U)) + aOrbiterE) + aPhaseHWandererUpdateSaltC[(((31U - aIndex) + 19U)) & S_SALT1]);
            aWandererD = aWandererD + (((RotL64(aIngress, 35U) + RotL64(aOrbiterD, 41U)) + aOrbiterG) + RotL64(aCarry, 47U));
            aWandererH = aWandererH ^ ((RotL64(aPrevious, 58U) + aOrbiterD) + RotL64(aOrbiterF, 19U));
            //
            aCarry = aCarry + (RotL64(aWandererG, 60U) ^ aWandererF);
            aCarry = aCarry + (aWandererH ^ RotL64(aWandererC, 29U));
            aCarry = aCarry + RotL64(aWandererD, 43U);
            aCarry = aCarry + RotL64(aIngress, 21U);
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
